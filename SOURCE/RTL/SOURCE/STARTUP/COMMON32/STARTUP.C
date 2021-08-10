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
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.8  $        */

#ifdef __OS2__
#include <os2bc.h>
#else
#define INCL_USER
#include <ntbc.h>
#endif
#include <_thread.h>	/* lock_t */
#include <_startup.h>
#include <stdlib.h>     /* exit() */
#include <float.h>      /* _control87(), _fpreset */
#ifdef _BUILDRTLDLL
#include <dos.h>        /* __emit__() */
#endif
#include <tchar.h>
#include <_tchar.h>
#include <winbase.h>

/*----------------------------------------------------------------------
 * Functions that are used to save the address of certain functions
 * and variables in the EXE, so that the DLL version of the RTL can
 * reference them.
 */
extern void _initmatherr(int (*matherr)(void *), int (*matherrl)(void *));
extern void _initfmode(int *fmodeptr);

/*----------------------------------------------------------------------
 * _ExcRegPtr contains the address of an exception registration
 * record in the startup code's local stack area.
 */
extern PEXCEPTIONREGISTRATIONRECORD  _ExcRegPtr;
/*----------------------------------------------------------------------
 * The following two variables are pointers into the environment data
 * passed to us by the loader.
 */
extern _TCHAR * _EXPDATA _tosenv;             /* pointer to raw OS environment data */
extern _TCHAR * _EXPDATA _toscmd;             /* pointer to raw OS command line */

#ifdef __OS2__
extern ULONG  _EXPDATA _os2hmod;    /* module handle */
#endif

/*----------------------------------------------------------------------
 * Function to initialize wildcard expansion if necessary
 */
void _tinitwild(void);

/*----------------------------------------------------------------------
 * Mutex Semaphore to lock access to the atexit table.
 */
#ifdef _MT
extern lock_t __exit_lock;
#endif

/*----------------------------------------------------------------------
 * The following variables are set up by the argument and environment
 * initialization functions, and are passed to main.
 */
extern int _C0argc;               /* argument count */
extern _TCHAR **_tC0argv;              /* array of arguments */
extern _TCHAR **_tC0environ;           /* array of environment strings */

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
#ifndef __OS2__
extern int _isWindows;
#endif


/*---------------------------------------------------------------------*

Name            _startup, _wstartup, _startupw, _wstartupw - startup
                 initialization for EXEs

Usage           void cdecl _startup(MODULE_DATA *mod_table,
			long modhandle, long zero,  { OS/2 only }
			char *env, char *cmd)       { OS/2 only }

Description     This function is called at startup time from C02.ASM or
		C0NT.ASM when an EXE is loaded.  It is passed a pointer
		to a MODULE_DATA structure, which contains addresses and
		flags unique to this DLL.  On OS/2, some additional
		parameters are passed to this function by the OS itself.

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

void cdecl _EXPFUNC _tstartup(

/* This parameter is passed by C0x.ASM.
 */
    MODULE_DATA *mod_table

/* These parameters are passed by OS/2.
 */
#ifdef __OS2__
,   /* don't remove this comma! */
    long modhandle,                     /* module handle (not used) */
    long zero,                          /* not used */
    char *env,                          /* pointer to environment */
    char *cmd                           /* pointer to command line */
#endif
)
{
    EXCEPTIONREGISTRATIONRECORD hand;
    VOIDFUNC func;
    MULTI_INIT *share_dll_table;        /* module tables for DLLs */
    int i;

#ifndef __OS2__
    /* Set the _isWindows flag if this is a Windows application.
     * This is used by _ErrorMessage to determine whether to put
     * up a dialog box or write to the console.
     */
    _isWindows  = mod_table->flags & MF_WINDOWS;
#endif

#ifdef __OS2__
    _os2hmod = modhandle;
#endif

    /* Disable precision, denormal, and underflow floating point exceptions,
     * enable all others.  Also set other control bits; see deflt87.c.
     */
    _fpreset();

#ifdef __OS2__
    _control87(CW_DEFAULT, MCW_EM | MCW_IC | MCW_RC | MCW_PC);
#endif

    /* Initialize pointers to _matherr and _matherrl, and _fmode.
     */
    _initmatherr(mod_table->matherr, mod_table->matherrl);
    _initfmode(mod_table->fmode);

    /* Make up a MULTI_INIT structure for this EXE.
     */
    _exe_table.ntables = 1;
    _exe_table.table[0] = mod_table;

#ifdef __OS2__
    /* Save base of stack for use by other library functions (e.g. alloca). */
    _stkbase = mod_table->stackbase;
#endif

    /* Save a pointer to the exception registration record in the stack.
     * If signal() is used, or stack checking is enabled, or threads
     * are created, except.c will be linked in and will use this pointer
     * to install an exception handler.
     */
    _ExcRegPtr = &hand;

    /* Hack to link in GP handler */
    _InitDefaultHander();

    /* Set up global variables pointing to the environment data
     * and command line, respectively.  These are used by INIT
     * functions to set up argc, argv, and _environ before main is called.
     * Also save the module handle for use by WINMAIN.
     */
#ifdef __OS2__
    _osenv = env;
    _oscmd = cmd;
#else
    _tosenv = GetEnvironmentStrings();
    _toscmd = GetCommandLine();
#endif

    /* Initialize wildcard expansion if necessary
     */
    _tinitwild();

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

	/* Call _INIT_ functions
	 */
	while ((func = _init_exit_proc(share_dll_table, 0)) != NULLFUNC)
	    func();

	/* Call _dllmain.
	 */
	for (i = 0; i < share_dll_table->ntables; i++)
#pragma warn -pro
	    share_dll_table->table[i]->main(0, share_dll_table->table[i]->hmod);
#pragma warn .pro
    }

    /* Call initialization functions for the EXE.
     */
    while ((func = _init_exit_proc(&_exe_table, 0)) != NULLFUNC)
	func();

#ifndef __OS2__
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
	exit(mod_table->main(GetModuleHandle(NULL), NULL, cmdline, SW_SHOWDEFAULT));
#pragma warn .pro
    }
    else
#endif
    {
	/* Call main, exit with its return code.
	 */
#pragma warn -pro
	exit(mod_table->main(_C0argc,_tC0argv,_tC0environ));
#pragma warn .pro
    }
}
