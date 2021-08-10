/*-----------------------------------------------------------------------*
 * filename - initexit.c
 *
 * function(s)
 *      _init_exit_proc - return address of next _INIT_ proc
 *      _cleanup        - call _EXIT_ routines
 *      _terminate      - terminate the program
 *      _lock_exit      - lock the atexit lock
 *      _unlock_exit    - unlock the atexit lock
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.0  $        */

#ifdef __OS2__
#include <os2bc.h>
#else
#define INCL_USER
#include <ntbc.h>
#endif
#include <_defs.h>
#include <_io.h>
#include <_thread.h>
#include <_process.h>   /* _getpid() */
#include <_startup.h>
#include <stdlib.h>     /* exit() */
#include <string.h>     /* strchr() */
#ifdef __OS2__
#include <float.h>      /* _control87() */
#endif
#ifdef _BUILDRTLDLL
#include <dos.h>        /* __emit__() */
#endif
#include <tchar.h>

/*----------------------------------------------------------------------
 * The following tables each contain a pointer to the module table
 * for this program (either an EXE or DLL).  See _startup.h and c02.asm
 * for the table layout.
 */
extern  MULTI_INIT _dll_table;       /* DLL's init table */
extern  MULTI_INIT _exe_table;       /* EXE's init table */

/*----------------------------------------------------------------------
 * Mutex Semaphore to lock access to the atexit table.
 */
#ifdef _MT
extern lock_t __exit_lock;
#endif


/*---------------------------------------------------------------------*

Name            _terminate - terminate the program

Usage           void _terminate(int code);

Description     This function is called by exit() to terminate the
		current process and return an error code to the
		parent process.  All threads are terminated as well.

Return value    None.

*---------------------------------------------------------------------*/

void _terminate(int code)
{
#ifdef __OS2__
#ifdef _BUILDRTLDLL
    _asm mov fs:[0], 0ffffffffh
//  __emit__(0x64, 0x67, 0xC7, 0x06, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
#endif
    DosExit(EXIT_PROCESS,code);     /* terminate all threads */
#else
    ExitProcess(code);              /* terminate all threads */
#endif
}

/*---------------------------------------------------------------------*

Name            make_shname - construct name of shared memory region

Usage           char *make_shname(void);

Description     This function modifies sharename[] so that it contains
		a unique name for a shared memory region.  This is
		done by overwriting the eight 'x' character with a
		mangled process ID.

Return value    The address of the name of the shared memory region.

*---------------------------------------------------------------------*/

#ifdef __OS2__
static char *make_shname(void)
{
    static char sharename[] = "\\SHAREMEM\\xxxxxxxx.c2i";

#define x_offset 10     /* offset of the first 'x' in sharename[] */

    static int  modified = 0;
    int pid, i;

    if (!modified)
    {
	pid = _getpid();
	for (i = x_offset; i < x_offset + 8; i++)
	{
	    sharename[i] = (pid & 0x0f) + 'A';
	    pid >>= 4;
	}
	modified = 1;
    }
    return sharename;
}
#endif

/*---------------------------------------------------------------------*

Name            _create_shmem - create shared memory region

Usage           static MULTI_INIT *_create_shmem(void);

Description     This function creates or opens the shared memory region
		used to store the addresses of _INIT_ and
		_EXIT_ segments for each DLL.  If the region already
		exists, it is not created.

Return value    The address of the shared memory region, or NULL if
		it cannot be created.

*---------------------------------------------------------------------*/

MULTI_INIT *_create_shmem(void)
{
#ifdef __OS2__
    MULTI_INIT *base;
    PSZ sharename;

    /* If the shared memory region already exists, return its address.
     */
    sharename = (PSZ)make_shname();
    if (DosGetNamedSharedMem((PPVOID)&base, sharename,
			     PAG_READ|PAG_WRITE) == 0)
	return base;

    /* Create the shared memory region, and zero it.  One page
     * should be plenty, since that can hold information for
     * hundreds of DLLs.
     */
    if (DosAllocSharedMem((PPVOID)&base, sharename, 4096,
			  PAG_READ|PAG_WRITE|PAG_COMMIT) != 0)
	return (NULL);
    memset(base, 0, 4096);
    return base;
#else
    return NULL;
#endif
}

/*---------------------------------------------------------------------*

Name            open_shmem - return address of shared memory region

Usage           static MULTI_INIT *open_shmem(void);

Description     This function returns the address of the shared memory
		region used to store the addresses of _INIT_ and
		_EXIT_ segments for each DLL.

Return value    The address of the shared memory region, or NULL if
		it does not exist.

*---------------------------------------------------------------------*/

static MULTI_INIT *open_shmem(void)
{
#ifdef __OS2__
    MULTI_INIT *base;

    if (DosGetNamedSharedMem((PPVOID)&base, (PSZ)make_shname(),
			     PAG_READ|PAG_WRITE) != 0)
	return NULL;
    else
	return base;
#else
    return NULL;
#endif
}

/*---------------------------------------------------------------------*

Name            _init_exit_proc - return address of next _INIT_ function

Usage           VOIDFUNC _init_exit_proc(MULTI_INIT *init_table, int is_exit);

Description     This function returns the address of the next function
		to call in the _INIT_ segments listed in the MULTI_INIT
		table pointed to by init_table.

		The is_exit flag is zero if this a startup table, and 1
		if this is an exit table. this affects whether the _INIT_
		functions are to be called in high-to-low or
		low-to-high priority order.

Return value    The address of the next function to call, or NULL if
		all INIT functions have been called.

*---------------------------------------------------------------------*/

VOIDFUNC _init_exit_proc(MULTI_INIT *init_table, int is_exit)
{
    INIT *init_start, *init_end, *ip, *save;
    MODULE_DATA *modtable;
    unsigned short prior;
    int i;

    prior = is_exit ? 0 : 0xffff;
    save = NULL;
    for (i = 0; i < init_table->ntables; i++)       /* for each _INIT_ table */
    {
	modtable = init_table->table[i];
	init_start = is_exit ? modtable->exit_start : modtable->init_start;
	init_end   = is_exit ? modtable->exit_end   : modtable->init_end;

	/* Scan through one table, looking in priority order for the next
	 * entry that hasn't been called yet.  Priority 0 is highest.
	 * If this is an INIT table, start with highest priority entries.
	 * If this is an EXIT table, start with lowest priority entries.
	 * The reserved field in each init record is used as the 'called'
	 * flag.
	 */
	for (ip = init_start; ip < init_end && ip->func != NULLFUNC; ip++)
	{
	    if (ip->reserved == 0 && is_exit == (ip->priority >= prior))
	    {
		prior = ip->priority;
		save = ip;
	    }
	}
    }

    /* If we scanned through all tables without finding an
     * un-called record, return NULL.
     */
    if (save == NULL)
	return (NULL);

    /* Mark the highest priority function as called and return
     * its address.  The caller should call this function immediately.
     */
    save->reserved = 1;
    return (save->func);
}



/*---------------------------------------------------------------------*

Name            _cleanup - call _EXIT_ routines

Usage           void _cleanup(void);

Description     This function is called by exit() to  call all routines
		that have 'init' records in the _EXIT_ segment.  If
		this is the DLL version of the RTL, call the _EXIT_
		routines for the DLL as well.

Return value    None.

*---------------------------------------------------------------------*/

void _cleanup(void)
{
    VOIDFUNC func;
    MULTI_INIT *share_dll_table;
    int i;

    /* Run the EXE's exit procedures.
     */
    while ((func = _init_exit_proc(&_exe_table, 1)) != NULLFUNC)
	func();

    /* The following call runs the DLL's exit procedures.
     * This is also done in _startupd, if the DLL is marked as
     * "terminstance".  But if the user forgets to mark the DLL as
     * terminstance, we must call the exit procs here.
     */
    while ((func = _init_exit_proc(&_dll_table, 1)) != NULLFUNC)
	func();

    /* Call exit functions for any other DLLs that might have
     * been loaded.  Then call each DLL's pseudo-entry point,
     * which simply calls that DLL's _dllmain().
     */
    if ((share_dll_table = open_shmem()) != NULL)
    {
	/* Call the exit functions for each DLL.
	 */
	while ((func = _init_exit_proc(share_dll_table, 1)) != NULLFUNC)
	    func();

	/* Call _dllmain for each DLL.
	 */
	for (i = 0; i < share_dll_table->ntables; i++)
#pragma warn -pro
	    share_dll_table->table[i]->main(1, share_dll_table->table[i]->hmod);
#pragma warn .pro

    }
}

/*---------------------------------------------------------------------*

Name            _lock_exit - lock the atexit lock

Usage           void _lock_exit(void);

Prototype in    _stdio.h

Related
functions usage void _unlock_exit(void);

Description     This function locks the global lock that governs
		access to the atexit table.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _MT
void _lock_exit(void)
{
    _lock(__exit_lock,"locking atexit table");
}
#endif

/*---------------------------------------------------------------------*

Name            _unlock_exit - unlock the atexit lock

Usage           void _unlock_exit(void);

Prototype in    _stdio.h

Related
functions usage void _lock_exit(void);

Description     This function unlocks the global lock that governs
		access to the atexit table.

Return value    None.

*---------------------------------------------------------------------*/

#ifdef _MT
void _unlock_exit(void)
{
    _unlock(__exit_lock,"unlocking atexit lock");
}
#endif


#ifdef _MT
static void _RTLENTRY _init_exit()
{
#pragma startup _init_exit 6

    /* Create the lock used to govern access to the atexit table.
     */
    _create_lock(&__exit_lock,"creating atexit lock");
}
#endif

