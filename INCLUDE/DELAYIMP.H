/****************************************************************************
 * filename - DelayImp.h
 *
 *   structures and prototypes necessary for delay loading of imports.
 *   Delay loading of DLL imports is selected when building a module by
 *
 *
 *  This technology supports delayed loading of DLLs for arbitrary images.
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
 *          load DLL.  There is no way for us to guard against that, so
 *          the user has to be aware of the possibility.
 *
 *  Notes:
 *      TLS support works for delayed load DLLs with Borland tools, as we
 *      have worked around the OS restrictions of handling TLS variables in
 *      dynamically loaded DLLs.
 *
 ****************************************************************************/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $ */

#ifndef __DELAYIMP_H
#define __DELAYIMP_H

#include <windows.h>

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct ImgDelayDescr
{
    DWORD               grAttrs;        /* attributes                        */
    LPCSTR              szName;         /* pointer to dll name               */
    HMODULE             hmod;           /* address of module handle          */
    IMAGE_THUNK_DATA *  pIAT;           /* address of the IAT                */
    IMAGE_THUNK_DATA *  pINT;           /* address of the INT                */
    IMAGE_THUNK_DATA *  pBoundIAT;      /* address of the optional bound IAT */
    IMAGE_THUNK_DATA *  pUnloadIAT;     /* address of optional copy of
                                           original IAT                      */
    DWORD               dwTimeStamp;    /* 0 if not bound,                   */
                                        /* O.W. date/time stamp of DLL bound
                                           to (Old BIND)                     */
}   ImgDelayDescr;

/* Delay load import hook notifications */

typedef enum
{
    dliNoteStartProcessing,        /* used to bypass or note helper only     */
    dliNotePreLoadLibrary,         /* called just before LoadLibrary, can    */
                                   /*  override w/ new HMODULE return val    */
    dliNotePreGetProcAddress,      /* called just before GetProcAddress, can */
                                   /*  override w/ new FARPROC return value  */
    dliFailLoadLibrary,            /* failed to load library, fix it by      */
                                   /*  returning a valid HMODULE             */
    dliFailGetProcAddress,         /* failed to get proc address, fix it by  */
                                   /*  returning a valid FARPROC             */
    dliNoteEndProcessing,          /* called after all processing is done,   */
                                   /*  no bypass possible at this point      */
                                   /*  except by longjmp(), throw(), or
                                       RaiseException.                       */
} dliNotification;

typedef struct DelayLoadProc
{
    BOOL                fImportByName;
    union
    {
        LPCSTR          szProcName;
        DWORD           dwOrdinal;
    };
} DelayLoadProc;

typedef struct DelayLoadInfo
{
    DWORD                   cb;         /* size of structure                 */
    const ImgDelayDescr *   pidd;       /* raw form of data (everything is
                                           there)                            */
    FARPROC *               ppfn;       /* points to address of function to
                                           load                              */
    LPCSTR                  szDll;      /* name of dll                       */
    DelayLoadProc           dlp;        /* name or ordinal of procedure      */
    HMODULE                 hmodCur;    /* the hInstance of the library we
                                           have loaded                       */
    FARPROC                 pfnCur;     /* the actual function that will be
                                           called                            */
    DWORD                   dwLastError;/* error received (if an error
                                           notification)                     */
} DelayLoadInfo, *PDelayLoadInfo;

typedef FARPROC (WINAPI *DelayedLoadHook)(
    dliNotification dliNotify,
    DelayLoadInfo * pdli
);

/* Unload support */

/* routine definition; takes a pointer to a name to unload, or NULL to
   unload all the delay load dlls in the list.
 */

BOOL WINAPI __FUnloadDelayLoadedDLL(LPCSTR szDll);

/* Hook pointers */

/* The "notify hook" gets called for every call to the
   delay load helper.  This allows a user to hook every call and
   skip the delay load helper entirely.

   dliNotify ==
   {
       dliNoteStartProcessing   |
       dliNotePreLoadLibrary    |
       dliNotePreGetProcAddress |
       dliNoteEndProcessing
   }

   on this call.
 */
extern DelayedLoadHook _EXPDATA __pfnDliNotifyHook;

/* This is the failure hook,

   dliNotify ==
   {
       dliFailLoadLibrary       |
       dliFailGetProcAddress
   }
*/
extern DelayedLoadHook _EXPDATA __pfnDliFailureHook;

#ifdef  __cplusplus
}
#endif

#endif /* __DELAYIMP_H */

