/*------------------------------------------------------------------------
 * filename - fmodeptr.c
 *
 * function(s)
 *        _fmodeptr  - pointer to user-definable _fmode variable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4 $        */

#include <fcntl.h>
#include <_io.h>

/* This variable points to the _fmode variable.  The RTL uses this pointer
 * instead of referring to _fmode directly, because if the RTL is in a DLL,
 * it cannot directly address data in an EXE.  The pointer is initialized
 * by the EXE's startup code when it calls _initfmode below.
 */
int  *_fmodeptr = &_fmode;

/*------------------------------------------------------------------------*

Name            _initfmode - initialize pointers to math error handlers

Usage           void _initfmode(int *fmodeptr);

Prototype in    none

Description     This function initializes _fmodeptr to point to the user
                EXE's _fmode variable. The startup code in an EXE calls
                this function directly, rather than using an _INIT_
                entry, because an address in the user's EXE must be passed.

Return value    none

*-------------------------------------------------------------------------*/

void _RTLENTRY _initfmode(int *fmodeptr)
{
    _fmodeptr  = fmodeptr;
}

void _RTLENTRY _initfileinfo(int *pfileinfo)
{
    if (pfileinfo)
        _fileinfo = *pfileinfo;
}