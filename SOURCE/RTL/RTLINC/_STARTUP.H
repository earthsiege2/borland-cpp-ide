/*------------------------------------------------------------------------
 * filename - _startup.h
 *
 *      definitions used by startup code for EXEs and DLLs
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.8.2.1 $ */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#include <_setargv.h>  /* for _PFN_ADDARG */

/*----------------------------------------------------------------------
 * Structure of records in the _INIT_ segment.
 */
typedef void (*VOIDFUNC)(void);     /* pointer to void function */

#pragma pack(2)

typedef struct init
{
    char reserved;                  /* reserved, must be zero */
    unsigned char priority;         /* 0 = high, ff = low */
    VOIDFUNC func;                  /* init function */
}   INIT;

#pragma pack()

/*----------------------------------------------------------------------
 * Structure containing an individual module's initialization
 * and cleanup information.  The actual structure is located
 * in the startup module C02 or C02D.  The startup module passes
 * a pointer to the structure to _startup() (EXE) and _startupd() (DLL).
 */
typedef struct module_data
{
    /* address of start of a module's _INIT_ segment */
    INIT *init_start;

    /* address of end of a module's _INIT_ segment */
    INIT *init_end;

    /* address of start of a module's _EXIT_ segment */
    INIT *exit_start;

    /* address of end of a module's _EXIT_ segment */
    INIT *exit_end;

    /* flags (see below) */
    int  flags;

    /* module handle */
    int  hmod;

    /* address of main/WinMain/_dllmain function */
    int  (*main)();

    /* address of (EXE only) _matherr function */
    int  (*matherr)(void *);

    /* address of (EXE only) _matherrl function */
    int  (*matherrl)(void *);

    /* (EXE only) base of stack */
    long stackbase;

    /* address of (EXE only) address of _fmode variable */
    int  *fmode;

    /* address of ptr to function that will expand wild args */
    void (**wild_func)(char *, _PFN_ADDARG);

    /* address of ptr to function that will expand wchar_t wild args */
    void (**wwild_func)(wchar_t *, _PFN_ADDARG);

    /* address of function that will process cmdline and create argv array */
    int (*setargv_func)(char *, char *, _PFN_ADDARG);

    /* address of function to clean up after setargv_func */
    void (*exitargv_func)(void);

    /* address of function that will process cmdline and create wargv array */
    int (*wsetargv_func)(wchar_t *,wchar_t *, _PFN_ADDARG);

    /* address of function to clean up after wsetargv_func */
    void (*wexitargv_func)(void);

    /* Address of _fileinfo variable that the user can define. Linking with
       fileinfo.obj changes this. */
    int  *pfileinfo;

} MODULE_DATA;


#ifndef _UNICODE
void cdecl  _EXPFUNC _startup(MODULE_DATA *mod_table);
#else	//UNICODE
void cdecl  _EXPFUNC _wstartup(MODULE_DATA *mod_table);
#endif


/* MODULE_DATA flags.
 */
#define MF_WINDOWS  1           /* this is a Windows application */

/*----------------------------------------------------------------------
 * Structure of multiple _INIT_ tables.  In a multi-dll application,
 * this will be located in a shared memory region, and will contain
 * pointers to each DLL's module data structure.
 */
typedef struct multi_init
{
    int             ntables;        /* actual number of entries in table[] */
    MODULE_DATA    *table[1];       /* pointer(s) to module table */
} MULTI_INIT;

/*----------------------------------------------------------------------
 * External variables in startup.c.
 */
extern MULTI_INIT _dll_table;               /* DLL's init table */

/*----------------------------------------------------------------------
 * _multidll is a flag that says whether this is a DLL that is part
 * of a multiple-DLL application.  If the flag is set, the DLL startup
 * code does not call the _INIT_ functions, but simply saves a pointer
 * the _INIT_ segment in shared memory region.  Later on, the EXE
 * using the DLLs will call the initialization functions.
 */
extern int _multidll;

/*----------------------------------------------------------------------
 * External functions in initexit.c
 */
#ifdef __cplusplus
extern "C" {
#endif

void            _init_exit_proc (MULTI_INIT *init_table, int __is_exit);
MULTI_INIT *    _create_shmem   (void);

#ifdef __cplusplus
}
#endif
