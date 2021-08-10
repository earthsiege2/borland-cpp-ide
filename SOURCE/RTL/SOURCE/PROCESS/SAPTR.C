/*-----------------------------------------------------------------------*
 * filename - saptr.c
 *
 * Holds the variables that are pointers to the routines that are called
 * to create and free the argv array.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#include <_setargv.h>

int _RTLENTRY (* _RTLENTRY _EXPDATA _tsetargv_ptr)(_TCHAR *_argv0 ,_TCHAR *_cmdline, _PFN_ADDARG _pfn_addarg) = _thandle_setargv;

void _RTLENTRY (* _RTLENTRY _EXPDATA _texitargv_ptr)(void) = _thandle_exitargv;

