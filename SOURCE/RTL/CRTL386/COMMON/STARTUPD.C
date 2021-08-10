/*-----------------------------------------------------------------------*
 * filename - startupd.c
 *
 * function(s)
 *      _startupd       - initialization and termination for DLLs
 *-----------------------------------------------------------------------*/

/* $Copyright: 1991$ */

#ifdef __OS2__
#include <os2bc.h>
#else
#define INCL_USER
#include <ntbc.h>
#endif

#include <_defs.h>
#include <_startup.h>
#include <stdio.h>
#include <_stdio.h>
#include <_thread.h>

/*----------------------------------------------------------------------
 * Mutex Semaphore to lock access to the atexit table.
 */
#ifdef _MT
extern lock_t __exit_lock;
#endif

/*---------------------------------------------------------------------*

Name            _startupd - initialization and termination for DLLs

Usage           ULONG cdecl _startupd(MODULE_DATA *mod_table,
                        long modhandle, long hPDLL);

Description     This function is called at startup time from C02.ASM or
                C0NT.ASM when a DLL is initialized or terminated.  It is
                passed a pointer to a MODULE_DATA structure, which contains
                addresses and flags unique to this DLL.  On OS/2,
                some additional parameters are passed to this function
                by the OS itself.

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

#ifdef __WIN32__
#pragma argsused
typedef INT APIENTRY (*LIBMAINPTR)(HANDLE, ULONG, LPVOID);
#endif

extern char * _EXPDATA _osenv;             /* pointer to raw OS environment data */

#if defined(__WIN32__) && !defined(_BUILDRTLDLL)
static int usecount;
#endif

ULONG cdecl _EXPFUNC _startupd
(
/* This parameter is passed by C02.ASM.
 */
    MODULE_DATA *mod_table,

#ifdef __OS2__

/* These parameters are passed by OS/2.
 */
    HMODULE mod_handle,                 /* module handle */
    ULONG   termflag                    /* 0 => init, 1 => termination */
#endif

#ifdef __WIN32__
/* These parameters are passed by WIN NT.
 */
    ULONG   retaddr,                    /* return address into NT */
    HANDLE  mod_handle,                 /* module handle */
    ULONG   reason,                     /* reason being called */
    LPVOID  reserved
#endif
)
{
    VOIDFUNC func;
    MULTI_INIT *share__dll_table;
    MULTI_INIT _dll_table;

    /* Save a pointer to this DLL's module table.
    */
    _dll_table.ntables  = 1;
    _dll_table.table[0] = mod_table;

#ifdef __OS2__
    if (!termflag)      /* initializing */
#endif
#ifdef __WIN32__
    if (reason == DLL_PROCESS_ATTACH)   /* initializing */
#endif
    {
#if defined(__WIN32__) && !defined(_BUILDRTLDLL)
        if (!usecount++)    // if not previously initialized
            {               // Note: always true for nonshared data
#endif

#ifdef __WIN32__
        _osenv = GetEnvironmentStrings();
#endif
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
            _multidll = 0;      /* force termination to call exit procs */

            /* Call all _INIT_ functions.
             */
            while ((func = _init_exit_proc(&_dll_table, 0)) != NULLFUNC)
                func();

            /* Create the lock used to govern access to the atexit table.
             */
            _create_lock(&__exit_lock,"creating atexit lock");

            /* Call _dllmain on OS/2.
             */
#ifdef __OS2__
#pragma warn -pro
            return mod_table->main(0, mod_handle);  /* call _dllmain */
#pragma warn .pro
#endif
        }
#if defined(__WIN32__) && !defined(_BUILDRTLDLL)
    }  // !usecount
#endif
    }
#ifdef __OS2__
    else                /* terminating */
#endif
#ifdef __WIN32__
    else if (reason == DLL_PROCESS_DETACH)  /* terminating */
#endif
    {
#if defined(__WIN32__) && !defined(_BUILDRTLDLL)
        if (!--usecount)    // If last client terminating
            {               // Note: always true for nonshared data
#endif
        /* The following loop calls the DLL's exit procedures.
         * This is also done by _cleanup(), if the application exits
         * with exit(); in that case, we won't do anything here, because
         * all the exit procedures will be marked as "called".  But if the
         * application exits some other way, we must call the exit
         * procedures here.
         */
        if (!_multidll)
        {
            /* Call all _EXIT_ functions.
             */
            while ((func = _init_exit_proc(&_dll_table, 1)) != NULLFUNC)
                func();

            /* Call _dllmain on OS/2.
             */
#ifdef __OS2__
#pragma warn -pro
            return mod_table->main(1, mod_handle);  /* call _dllmain */
#pragma warn .pro
#endif
        }
#if defined(__WIN32__) && !defined(_BUILDRTLDLL)
    }  // !usecount
#endif
    }
#ifdef __WIN32__
#pragma warn -pro
    /* Call LibMain().
     */
    return (*(LIBMAINPTR)(mod_table->main))(mod_handle, reason, reserved);
#pragma warn .pro
#else
    return 1;
#endif
}
