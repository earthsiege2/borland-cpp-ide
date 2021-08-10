/*------------------------------------------------------------------------
 * filename - mathptr.c
 *
 * function(s)
 *        _pmatherr  - pointer to user-modifiable math error handler
 *        _pmatherrl - pointer to user-modifiable long double error handler
 *        _initmatherr - initialize pointers to math error handlers
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <math.h>
#include <_math.h>

/* These variables point to the _matherr and _matherrl functions.  The
 * math functions call through these pointers instead of calling _matherr
 * and _matherrl directly.  The pointers are reinitialized by the EXE's
 * startup code.  This ensures that if an EXE uses C2.DLL, the EXE's
 * _matherr and _matherrl will be used instead of those in the DLL.
 */
matherrptr  _pmatherr  = _matherr;
matherrptrl _pmatherrl = _matherrl;

/*------------------------------------------------------------------------*

Name            _initmatherr - initialize pointers to math error handlers

Usage           void _initmatherr(matherrptr matherr, matherrptr matherrl);

Prototype in    none

Description     This function initializes the _pmatherr and _pmatherrl
                pointers to point to the user EXE's _matherr and _matherrl
                error handling routines.  The startup code in an EXE calls
                this function directly, rather than using an _INIT_
                entry, because addresses in the user's EXE must be passed.

Return value    none

*-------------------------------------------------------------------------*/

void _initmatherr(matherrptr matherr, matherrptrl matherrl)
{
    _pmatherr  = matherr;
    _pmatherrl = matherrl;
}
