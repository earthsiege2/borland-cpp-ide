/*------------------------------------------------------------------------
 * filename - delayhlp.c
 *
 *   Implementation of ruotines for delay loading of imports
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.11.2.1 $ */

/****************************************************************************
 *
 *  This module supports delayed loading of DLLs for arbitrary images.
 *
 *  Restrictions:
 *      You cannot delay loading of a reference to imported data.
 *      You cannot delay loading of KERNEL32.DLL.
 *      You cannot delay loading of the RTLDLL (since these routines need
 *        to be present to support delayed loading).
 *      You must be very careful with using __FUnloadDelayLoadedDLL in a
 *          multithreaded environment.  It is possible to cause problems
 *          if one thread gets a delay loaded function address from this
 *          module, at the same time as another thread unloads the delayed
 *          load DLL.  There is no way for this module to guard against that,
 *          so the user has to be aware of the possibility.
 *
 *  Notes:
 *      TLS support works for delayed load DLLs with Borland tools, as we
 *      have worked around the OS restrictions of handling TLS variables in
 *      dynamically loaded DLLs.
 *
 ****************************************************************************/

#include <_defs.h>
#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#pragma hdrstop

#include "delayImp.h"

//
// Exception information
//
#define FACILITY_BORLANDCPP  ((LONG)0xfb)
#define BCPPException(sev,err)  ((sev) | (FACILITY_BORLANDCPP<<16) | err)

typedef struct UnloadInfo   UnloadInfo;
typedef struct UnloadInfo
{
    UnloadInfo *            puiNext;
    ImgDelayDescr *         pidd;
}   UnloadInfo;

static  UnloadInfo *        __puiHead = 0;
static  CRITICAL_SECTION    UnloadInfoCS;

DelayedLoadHook _EXPDATA __pfnDliFailureHook = 0;
DelayedLoadHook _EXPDATA __pfnDliNotifyHook = 0;

static  void AddToUnloadList(ImgDelayDescr *pidd)
{
    UnloadInfo *    uli;

    uli = LocalAlloc(LPTR, sizeof(*uli));
    if  (!uli)
    {
        RaiseException(
            BCPPException(ERROR_SEVERITY_ERROR, ERROR_NOT_ENOUGH_MEMORY),
            0,
            1,
            (PDWORD)pidd
            );
    }
    uli->pidd = pidd;
    uli->puiNext = __puiHead;
                   __puiHead = uli;
}

static  void RemoveFromUnloadList(UnloadInfo *uli)
{
    UnloadInfo **   ppui = &__puiHead;

    while (*ppui && *ppui != uli)
    {
        ppui = &((*ppui)->puiNext);
    }

    if (*ppui == uli)
    {
        *ppui = uli->puiNext;
    }

    LocalFree(uli);
}

// utility function for calculating the index of the current import
// for all the tables (INT, BIAT, UIAT, and IAT).
static  unsigned IndexFromPImgThunkData(
    const IMAGE_THUNK_DATA *    pitdCur,
    const IMAGE_THUNK_DATA *    pitdBase)
{
    return pitdCur - pitdBase;
}

// utility function for calculating the count of imports given the base
// of the IAT.  NB: this only works on a valid IAT!
static  unsigned CountOfImports(const IMAGE_THUNK_DATA *pitdBase)
{
    unsigned        cRet = 0;

    while (pitdBase->u1.Function)
    {
        pitdBase++;
        cRet++;
    }

    return cRet;
}

static  PIMAGE_NT_HEADERS WINAPI PinhFromImageBase(HMODULE hmod)
{
    return (PIMAGE_NT_HEADERS)((PCHAR)hmod + ((PIMAGE_DOS_HEADER)hmod)->e_lfanew);
}

static  void WINAPI OverlayIAT(IMAGE_THUNK_DATA *pitdDst, const IMAGE_THUNK_DATA *pitdSrc)
{
    memcpy(pitdDst, pitdSrc, CountOfImports(pitdDst) * sizeof (IMAGE_THUNK_DATA));
}

static  DWORD WINAPI TimeStampOfImage(PIMAGE_NT_HEADERS pinh)
{
    return pinh->FileHeader.TimeDateStamp;
}

static  BOOL WINAPI FLoadedAtPreferredAddress(PIMAGE_NT_HEADERS pinh, HMODULE hmod)
{
    if  ((DWORD)(hmod) == pinh->OptionalHeader.ImageBase)
        return TRUE;
    else
        return FALSE;
}

FARPROC WINAPI _EXPFUNC __delayLoadHelper(ImgDelayDescr *pidd, FARPROC *ppfnIATEntry)
{
    HMODULE                     hmod;
    unsigned                    iINT;
    FARPROC                     pfnRet;
    const IMAGE_THUNK_DATA *    pitd;

    // Set up some data we use for the hook procs but also useful for
    // our own use
    //
    DelayLoadInfo   dli;

    memset(&dli, 0, sizeof(dli));
    dli.cb = sizeof (DelayLoadInfo);
    dli.pidd = pidd;
    dli.ppfn = ppfnIATEntry;
    dli.szDll = pidd->szName;

    hmod = pidd->hmod;

    // Calculate the index for the name in the import name table.
    // N.B. it is ordered the same as the IAT entries so the calculation
    // comes from the IAT side.
    //
    iINT = IndexFromPImgThunkData((const IMAGE_THUNK_DATA *)ppfnIATEntry, pidd->pIAT);

    pitd = &((pidd->pINT)[iINT]);

    if ((dli.dlp.fImportByName = ((pitd->u1.Ordinal & IMAGE_ORDINAL_FLAG) == 0)) != 0)
    {
        dli.dlp.szProcName = (LPCSTR)((IMAGE_IMPORT_BY_NAME*)pitd->u1.AddressOfData)->Name;
    }
    else
    {
        dli.dlp.dwOrdinal = IMAGE_ORDINAL(pitd->u1.Ordinal);
    }

    // Call the initial hook.  If it exists and returns a function pointer,
    // abort the rest of the processing and just return it for the call.
    //
    pfnRet = NULL;

    if (__pfnDliNotifyHook)
    {
        if ((pfnRet = (*__pfnDliNotifyHook)(dliNoteStartProcessing, &dli)) != 0)
        {
            goto HookBypass;
        }
    }

    if (hmod == 0)
    {
        if (__pfnDliNotifyHook)
        {
            hmod = (HMODULE)(*__pfnDliNotifyHook)(dliNotePreLoadLibrary, &dli);
        }

        if (hmod == 0)
        {
            hmod = LoadLibrary(dli.szDll);
        }

        if (hmod == 0)
        {
            dli.dwLastError = GetLastError();
            if (__pfnDliFailureHook)
            {
                // when the hook is called on LoadLibrary failure, it will
                // return 0 for failure and an hmod for the lib if it fixed
                // the problem.
                //
                hmod = (HMODULE)(*__pfnDliFailureHook)(dliFailLoadLibrary, &dli);
            }

            if (hmod == 0)
            {
                DelayLoadInfo *  pdli = &dli;

                RaiseException(
                    BCPPException(ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND),
                    0,
                    1,
                    (PDWORD)&pdli
                    );

                // If we get to here, we blindly assume that the handler of the exception
                // has magically fixed everything up and left the function pointer in
                // dli.pfnCur.
                //
                return dli.pfnCur;
            }
        }

        // Store the library handle.  If it is already there, we infer
        // that another thread got there first, and we need to do a
        // FreeLibrary() to reduce the refcount
        //
        EnterCriticalSection(&UnloadInfoCS);

        if (!pidd->hmod)
        {
            AddToUnloadList(pidd);
            pidd->hmod = hmod;
        }
        else
        {
            FreeLibrary(hmod);
            hmod = pidd->hmod;
        }

        LeaveCriticalSection(&UnloadInfoCS);
    }

    // Go for the procedure now.
    dli.hmodCur = hmod;

    if (__pfnDliNotifyHook)
    {
        pfnRet = (*__pfnDliNotifyHook)(dliNotePreGetProcAddress, &dli);
    }

    if (pfnRet == 0)
    {
        if (pidd->pBoundIAT && pidd->dwTimeStamp)
        {
            // bound imports exist...check the timestamp from the target image
            PIMAGE_NT_HEADERS   pinh = PinhFromImageBase(hmod);

            if (pinh->Signature == IMAGE_NT_SIGNATURE &&
                TimeStampOfImage(pinh) == pidd->dwTimeStamp &&
                FLoadedAtPreferredAddress(pinh, hmod))
            {

                OverlayIAT(pidd->pIAT, pidd->pBoundIAT);
                pfnRet = (FARPROC)pidd->pIAT[iINT].u1.Function;
                goto HookBypass;
            }
        }

        pfnRet = GetProcAddress(hmod, dli.dlp.szProcName);
    }

    if (pfnRet == 0)
    {
        dli.dwLastError = GetLastError();

        if (__pfnDliFailureHook)
        {
            // when the hook is called on GetProcAddress failure, it will
            // return 0 on failure and a valid proc address on success
            //
            pfnRet = (*__pfnDliFailureHook)(dliFailGetProcAddress, &dli);
        }

        if (pfnRet == 0)
        {
            DelayLoadInfo * pdli = &dli;

            RaiseException(
                BCPPException(ERROR_SEVERITY_ERROR, ERROR_PROC_NOT_FOUND),
                0,
                1,
                (PDWORD)&pdli
                );

            // If we get to here, we blindly assume that the handler of the exception
            // has magically fixed everything up and left the function pointer in
            // dli.pfnCur.
            //
            pfnRet = dli.pfnCur;
        }
    }

    *ppfnIATEntry = pfnRet;

HookBypass:
    if (__pfnDliNotifyHook)
    {
        dli.dwLastError = 0;
        dli.hmodCur = hmod;
        dli.pfnCur = pfnRet;
        (*__pfnDliNotifyHook)(dliNoteEndProcessing, &dli);
    }

    return pfnRet;
}

static  BOOL    UnloadOneDLL(UnloadInfo *pui)
{
    if (pui && pui->pidd->pUnloadIAT)
    {
        ImgDelayDescr * pidd = pui->pidd;
        HMODULE         hmod = pidd->hmod;

#if 0
{
    char    Buff[128];
    sprintf(Buff, "%08x: %s", UnloadOneDLL, pui->pidd->szName);
    MessageBox(NULL, Buff, "UnloadOneDLL", MB_OK);
}
#endif

        OverlayIAT(pidd->pIAT, pidd->pUnloadIAT);
        FreeLibrary(hmod);
        pidd->hmod = NULL;

        RemoveFromUnloadList(pui);

        return TRUE;
    }

    return FALSE;
}

BOOL WINAPI _EXPFUNC __FUnloadDelayLoadedDLL(LPCSTR szDll)
{
    BOOL            fRet;
    UnloadInfo *    pui;

    EnterCriticalSection(&UnloadInfoCS);

    if  (szDll)
    {
        for (pui = __puiHead; pui; pui = pui->puiNext)
        {
            if (!lstrcmpi(szDll, pui->pidd->szName))
            {
                break;
            }
        }
        fRet = UnloadOneDLL(pui);
    }
    else
    {
        while   (__puiHead)
            UnloadOneDLL(__puiHead);
        fRet = TRUE;
    }

    LeaveCriticalSection(&UnloadInfoCS);

    return fRet;
}

static  void InitDelayHelp(void)
{
#pragma startup InitDelayHelp 0 /* Initializes the DLL delay load helper routines */

    /*
        Make it as thread safe as we can.
    */
    InitializeCriticalSection(&UnloadInfoCS);
}

static  void ShutdownDelayHelp(void)
{
#pragma exit    ShutdownDelayHelp 0 /* Finalizes the DLL delay load helper routines */

    /*
        Unload all delay loaded DLLs so that we don't leak, and
        ditch the critical section.
    */
    __FUnloadDelayLoadedDLL(NULL);
    DeleteCriticalSection(&UnloadInfoCS);
}


