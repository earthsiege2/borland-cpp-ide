/*-----------------------------------------------------------------------*
 * filename - startup.c
 *
 * function(s)
 *      _startup        - startup initialization for EXEs
 *      _wstartup       - wide-character startup initialization for EXEs
 *      _startupw       - Windows startup initialization for EXEs
 *      _wstartupw      - Windows wide-character startup initialization for EXEs
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.6  $        */

#define INCL_USER
#include <ntbc.h>
#include <_thread.h>	/* lock_t */
#include <_startup.h>
#include <_io.h>
#include <stdlib.h>     /* exit() */
#include <float.h>      /* _control87(), _fpreset */
#ifdef _BUILDRTLDLL
#include <dos.h>        /* __emit__() */
#endif
#include <tchar.h>
#include <_tchar.h>
#include <winbase.h>
#include <_setargv.h>

/*----------------------------------------------------------------------
 * Functions that are used to save the address of certain functions
 * and variables in the EXE, so that the DLL version of the RTL can
 * reference them.
 */
extern void _RTLENTRY _initmatherr(int (*matherr)(void *), int (*matherrl)(void *));
extern void _RTLENTRY _initfmode(int *fmodeptr);
extern void _RTLENTRY _initfileinfo(int *pfileinfo);

static int GetSWFlag(void);
/*----------------------------------------------------------------------
 * _ExcRegPtr contains the address of an exception registration
 * record in the startup code's local stack area.
 */
extern PEXCEPTIONREGISTRATIONRECORD  _ExcRegPtr;

/*----------------------------------------------------------------------
 * Mutex Semaphore to lock access to the atexit table.
 */
#ifdef _MT
extern lock_t __exit_lock;
#endif

/*----------------------------------------------------------------------
 * The following tables each contain a pointer to the module table
 * for this program (either an EXE or DLL).  See _startup.h and c02.asm
 * for the table layout.
 */
extern MULTI_INIT _dll_table;       /* DLL's init table */
extern MULTI_INIT _exe_table;       /* EXE's init table */
/*----------------------------------------------------------------------
 * The following variable gives the starting address of stack.
 * It is used by alloca() to check for stack overflow.
 */
extern ULONG _EXPDATA _stkbase;

/*----------------------------------------------------------------------
 * The following variable is non-zero if this is a Windows application
 */
extern int _isWindows;

/*---------------------------------------------------------------------*

Name            _startup, _wstartup, _startupw, _wstartupw - startup
                 initialization for EXEs

Usage           void cdecl _startup(MODULE_DATA *mod_table)

Description     This function is called at startup time from C0NT.ASM when
                an EXE is loaded.  It is passed a pointer to a MODULE_DATA
                structure, which contains addresses and flags unique to this
                DLL.

		This function saves pointers to the environment strings and
		command line in public variables.  It then calls
		all functions that appear in 'init' records
		in the _INIT_ segment; these functions are responsible
		for setting up argc and argv, initializing the heap,
		etc.  Finally the user's main() or WinMain() function is
		called, and its return value is passed to exit().

Return value    None.

*---------------------------------------------------------------------*/

/* Hack to link in GP handler */
extern void _InitDefaultHander(void);

#pragma argsused

void cdecl _EXPFUNC _tstartup(MODULE_DATA *mod_table)
{
    EXCEPTIONREGISTRATIONRECORD hand;
    MULTI_INIT *share_dll_table;        /* module tables for DLLs */
    int i;

    /* Set the _isWindows flag if this is a Windows application.
     * This is used by _ErrorMessage to determine whether to put
     * up a dialog box or write to the console.
     */
    _isWindows  = mod_table->flags & MF_WINDOWS;

    /* Disable precision, denormal, and underflow floating point exceptions,
     * enable all others.  Also set other control bits; see deflt87.c.
     */
    _fpreset();

    /* Initialize pointers to _matherr and _matherrl, _fmode, and _fileinfo
     */
    _initmatherr(mod_table->matherr, mod_table->matherrl);
    _initfmode(mod_table->fmode);
    _initfileinfo(mod_table->pfileinfo);


    /* Make up a MULTI_INIT structure for this EXE.
     */
    _exe_table.ntables = 1;
    _exe_table.table[0] = mod_table;

    /* Save a pointer to the exception registration record in the stack.
     * If signal() is used, or stack checking is enabled, or threads
     * are created, except.c will be linked in and will use this pointer
     * to install an exception handler.
     */
    _ExcRegPtr = &hand;

    /* Hack to link in GP handler */
    _InitDefaultHander();

    /* Set up global variables pointing to the environment data
     * and command line, respectively.  These are used by _INIT_
     * functions to set up argc, argv, and _environ before main is called.
     * Also save the module handle for use by WINMAIN.
     */
    _tosenv = GetEnvironmentStrings();
    _toscmd = GetCommandLine();

    /* Initialize wildcard expansion if necessary
     */
    _init_wild_handlers(mod_table->wild_func, mod_table->wwild_func);


    /* Initialize pointers to the routines that will handle the argv
       processing.
     */
    _init_setargv_handlers(
                           mod_table->setargv_func,
                           mod_table->exitargv_func,
                           mod_table->wsetargv_func,
                           mod_table->wexitargv_func
                          );

    /* Call initialization functions for any DLLs that might have
     * been loaded.  Then call each DLL's pseudo-entry point,
     * which simply calls that DLL's _dllmain().
     */
    if ((share_dll_table = _create_shmem()) != NULL)
    {
	/* Put a -1 marker at the end of the list of DLL module tables.
	 * This forces any DLLs that are loaded dynamically later to
	 * call their initialization functions themselves.
	 */
	share_dll_table->table[share_dll_table->ntables] = (MODULE_DATA *)-1;

	/* Call all the _INIT_ functions
	 */
	_init_exit_proc(share_dll_table, 0);

	/* Call _dllmain.
	 */
	for (i = 0; i < share_dll_table->ntables; i++)
#pragma warn -pro
	    share_dll_table->table[i]->main(0, share_dll_table->table[i]->hmod);
#pragma warn .pro
    }

    /* Call all the initialization functions for the EXE.
     */
    _init_exit_proc(&_exe_table, 0);

    if (mod_table->flags & MF_WINDOWS)
    {
	_TCHAR *cmdline, termchar;

	/* Skip past leading whitespace in command line.
	 */
	for (cmdline = _toscmd; *cmdline == _TEXT(' ') || *cmdline == _TEXT('\t'); cmdline++)
	    ;

	/* Check whether EXE name is quoted, if so then we need to search for
		 * the terminating quote.
	 */
		if (*cmdline == _TEXT('"'))
			{
			termchar = _TEXT('"');
			cmdline++;
			}
		else
			termchar = _TEXT(' ');

	/* Skip past program name.
	 */
	while (*cmdline && *cmdline != termchar && *cmdline != _TEXT('\t'))
			cmdline++;

	/* If we ended up on terminating quote then skip it.
	 */
		if (*cmdline == _TEXT('"'))
			cmdline++;

	/* Skip past leading whitespace in command line.
	 */
	while (*cmdline && *cmdline == _TEXT(' ') || *cmdline == _TEXT('\t'))
			cmdline++;

	/* Call WinMain, exit with its return code.
	 */
#pragma warn -pro
	exit(mod_table->main(GetModuleHandle(NULL), NULL, cmdline, GetSWFlag()));
#pragma warn .pro
    }
    else
    {
	/* Call main, exit with its return code.
	 */
#pragma warn -pro
	exit(mod_table->main(_C0argc,_tC0argv,_tC0environ));
#pragma warn .pro
    }
}

/*--------------------------------------------------------------------------*
 * GetSWFlag() returns the current SW_xxx value for the process.  This is   *
 * used to pass into WinMain                                                *
 *--------------------------------------------------------------------------*/
static int GetSWFlag(void)
{
    STARTUPINFO si;
    GetStartupInfo (&si);

    /*
       Check the STARTF_USESHOWWINDOW bit to ensure a proper startup flag.
       This is needed since the JPSoftware folks don't pass us a valid
       wShowWindow value when 4NT.EXE launches an .EXE

    */
    return ((si.dwFlags & STARTF_USESHOWWINDOW) ?
             si.wShowWindow : SW_SHOWDEFAULT);
}
