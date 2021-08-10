/*------------------------------------------------------------------------
 * filename - _startup.h
 *
 *      definitions used by startup code for EXEs and DLLs
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $ */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

/*----------------------------------------------------------------------
 * Structure of records in the _INIT_ segment.
 */
typedef void (*VOIDFUNC)(void);     /* pointer to void function */

#define NULLFUNC ((VOIDFUNC)0)

#pragma pack(2)

typedef struct init
{
    char reserved;                  /* reserved, must be zero */
    unsigned char priority;         /* 0 = high, ff = low */
    VOIDFUNC func;                  /* init function */
#ifdef MSLINK
    char filler[10];                /* NT linker aligns on 16-byte boundaries */
#endif
} INIT;

#pragma pack()

/*----------------------------------------------------------------------
 * Structure containing an individual module's initialization
 * and cleanup information.  The actual structure is located
 * in the startup module C02 or C02D.  The startup module passes
 * a pointer to the structure to _startup() (EXE) and _startupd() (DLL).
 */
typedef struct module_data
{
    INIT *init_start;           /* start of a module's _INIT_ segment */
    INIT *init_end;             /* end of a module's _INIT_ segment */
    INIT *exit_start;           /* start of a module's _EXIT_ segment */
    INIT *exit_end;             /* end of a module's _EXIT_ segment */
    int  flags;                 /* flags (see below) */
    int  hmod;                  /* module handle */
    int  (*main)();             /* main/WinMain/_dllmain function */
    int  (*matherr)(void *);    /* (EXE only) _matherr function */
    int  (*matherrl)(void *);   /* (EXE only) _matherrl function */
    long stackbase;             /* (EXE only) base of stack */
    int  *fmode;                /* (EXE only) address of _fmode variable */
} MODULE_DATA;




#ifndef _UNICODE
void                 _initwild(void);
void cdecl  _EXPFUNC _startup(MODULE_DATA *mod_table);
void        _EXPFUNC _setargv(void);
#else	//UNICODE
void                 _winitwild(void);
void cdecl  _EXPFUNC _wstartup(MODULE_DATA *mod_table);
void        _EXPFUNC _wsetargv(void);
#endif




/* MODULE_DATA flags.
 */
#define MF_WINDOWS  1           /* this is a Windows application */

/*----------------------------------------------------------------------
 * Structure of a multiple _INIT_ table.  In a multi-dll application,
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
 * External functions in startup.c
 */
#ifdef __cplusplus
extern "C" {
#endif

VOIDFUNC        _init_exit_proc (MULTI_INIT *init_table, int __is_exit);
MULTI_INIT *    _create_shmem   (void);

#ifdef __cplusplus
}
#endif
