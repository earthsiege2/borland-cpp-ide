/*-----------------------------------------------------------------------*
 * filename - startupd.c
 *
 * function(s)
 *      _startupd       - initialization and termination for DLLs
 *      _wstartupd      - wide-character initialization and termination for DLLs
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.8  $        */

#define INCL_USER
#include <ntbc.h>

#include <_defs.h>
#include <_startup.h>
#include <stdio.h>
#include <_stdio.h>
#include <_thread.h>
#include <tchar.h>
#include <_tchar.h>
#include <winbase.h>

#if defined(__MT__)
void _cleanup_handle_locks(void);
void _cleanup_stream_locks(void);
#endif

extern void (*__pCallAtExitProcs) (void);
extern void _RTLENTRY _initfileinfo(int *pfileinfo);

/*---------------------------------------------------------------------*

Name            _startupd, _wstartupd - initialization and termination for DLLs

Usage           ULONG cdecl _startupd(MODULE_DATA *mod_table,
                        long modhandle, long hPDLL);

Description     This function is called at startup time from C0NT.ASM
                when a DLL is initialized or terminated.  It is
                passed a pointer to a MODULE_DATA structure, which contains
                addresses and flags unique to this DLL.

                The MODULE_DATA structure contains a pointer to the _INIT_
                and _EXIT_ segments, which contain lists of the init
                and exit procedures, respectively, for this DLL.  If this
                is a multi-DLL application, as indicated by the _multidll
                external variable having a non-zero value, these addresses
                are saved in a shared memory segment, so that the EXE
                that invoked this DLL can call the init and exit
                procedures itself.  This is done because the OS doesn't
                guarantee a particular DLL initialization order when
                loading multiple DLLs.

                If this is not a multi-DLL application, the init or exit
                procedures are called directly by this function.

Return value    1 (success)

*---------------------------------------------------------------------*/

typedef ULONG   (APIENTRY * LIBMAINPTR)(HANDLE, ULONG, LPVOID);

ULONG APIENTRY __CRTL_DLLEntryPointWrapper(LIBMAINPTR pfn, HANDLE mod_handle,
                                           ULONG reason, LPVOID reserved);

extern HINSTANCE _hInstance;

#if defined(_BUILDRTLDLL)
typedef void __pascal (* _CGCALL)(HMODULE, int);
static _CGCALL _pfnCG;
static HMODULE _hCG;
static HMODULE _hCGModHandle;
#endif

extern _TCHAR * _EXPDATA _tosenv;             /* pointer to raw OS environment data */

#if !defined(_BUILDRTLDLL)
static int usecount;
#endif

#pragma argsused
ULONG cdecl _EXPFUNC _tstartupd
(
    MODULE_DATA *mod_table,
    ULONG   retaddr,                    /* return address into NT */
    HANDLE  mod_handle,                 /* module handle */
    ULONG   reason,                     /* reason being called */
    LPVOID  reserved
)
{
    MULTI_INIT *share__dll_table;
    MULTI_INIT _dll_table;
    ULONG retval;

    /* Save a pointer to this DLL's module table.
    */
    _dll_table.ntables  = 1;
    _dll_table.table[0] = mod_table;

    /*
        In order to be compatible with the way Microsoft's RTL calls
        DllMain and RawDllMain, we must preform the operations in the
        following order:

                           RawDllMain  DllMain  InitProcs  ExitProcs
                           -----------------------------------------
        Process Attach         1          3         2

        Thread  Attach         1          2

        Process Detatch        3          1                    2

        Thread  Detatch        2          1

        -------------------------------------------------------------

        RawDllMain is handled in C0NT before (or after) the call to
        _tstartupd.

    */

    if (reason == DLL_PROCESS_ATTACH)   /* initializing */
    {
#if !defined(_BUILDRTLDLL)
        if (!usecount++)    // if not previously initialized
        {                   // Note: always true for nonshared data
#else
            /* Hack for Codeguard */
            if (!_hCG && GetModuleHandleA("CG32.DLL") != NULL)
            {
                _hCG = LoadLibrary(_TEXT("CG32.DLL"));
                _pfnCG = (_CGCALL) GetProcAddress(_hCG, "_CG_RTLDLLINIT");
                _pfnCG(mod_handle, 1);
                _hCGModHandle = mod_handle;
            }
#endif
            _tosenv = GetEnvironmentStrings();
            _hInstance = mod_handle;

            /* Initialize pointer to _fileinfo.
             */
            _initfileinfo(mod_table->pfileinfo);


            /* Call initialization functions for the DLL (not the application).
             * The app's init functions will be called later by startup().
             * However, if this is a multi-dll application, don't call
             * the init functions -- just put pointers to them in a shared
             * memory region.
             */
            if (_multidll && (share__dll_table = _create_shmem()) != NULL &&
              share__dll_table->table[share__dll_table->ntables] != (MODULE_DATA *)-1)
            {
                share__dll_table->table[share__dll_table->ntables++] = mod_table;
            }
            else
            {
                _multidll = 0;      /* set a flag that will force the
                                       termination routine to call all of
                                       the exit procs.
                                     */

                /* Call all of the _INIT_ functions.
                 */
                _init_exit_proc(&_dll_table, 0);
            }
#if !defined(_BUILDRTLDLL)
        }  // !usecount
#endif
    }

#pragma warn -pro
    /* Call LibMain() via a wrapper that will handle exceptions
     */
    retval = __CRTL_DLLEntryPointWrapper((LIBMAINPTR)(mod_table->main), mod_handle, reason, reserved);

    if (reason == DLL_PROCESS_DETACH)  /* terminating */
    {
#if !defined(_BUILDRTLDLL)
        if (reason == DLL_PROCESS_DETACH && --usecount == 0 && _tosenv)
        {
            FreeEnvironmentStrings (_tosenv);
            _tosenv = 0;
        }

        if (!usecount)    // If last client terminating
        {                 // Note: always true for nonshared data

#endif /* !_BUILDRTLDLL */
            /* The following loop calls the DLL's exit procedures.
             * This is also done by _cleanup(), if the application exits
             * with exit(); in that case, we won't do anything here, because
             * all the exit procedures will be marked as "called".  But if the
             * application exits some other way, we must call the exit
             * procedures here.
             */
            if (!_multidll)
            {

                /* First call all entries in the atexit table for this DLL.
                 */
                 if (__pCallAtExitProcs)
                     __pCallAtExitProcs();

                /* Then call all of the _EXIT_ functions.
                 */
                _init_exit_proc(&_dll_table, 1);

#if defined(__MT__)
#if 0            /* Adding these two lines fixes a rare CG RTL memory leak.
                    It's commented out since it seems to adversly affect
                    other parts of the stream locking system.
                 */
                 _cleanup_handle_locks();
                 _cleanup_stream_locks();
#endif /* 0 */
#endif /* __MT__ */

            }
#if !defined(_BUILDRTLDLL)
        }  // !usecount
#endif
    }
#if defined(_BUILDRTLDLL)
    if (_hCGModHandle == mod_handle && _hCG && reason == DLL_PROCESS_DETACH)
    {
        _pfnCG(mod_handle, 0);
        FreeLibrary(_hCG);
    }
#endif
    return retval;
#pragma warn .pro
}
