/*------------------------------------------------------------------------
 * filename - _scalb.c
 *
 * function(s)
 *
 *   _scalb    Scales argument by a power of 2
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#pragma inline
#include <errno.h>
#include <math.h>
#include <float.h>

#pragma argsused
#pragma warn -rvl
double _RTLENTRY _EXPFUNC _scalb(double __d, long __exp)
{
    unsigned short ctrl;
    ctrl = _control87 (MCW_EM, MCW_EM);
    asm {
      fild    [__exp]
      fld     [__d]
      fscale
      fstp    [__d]
      ffree   ST(0)
      fincstp
    }
    _control87(MCW_EM, ctrl);

    if (!_finite (__d))
    {
      errno = ERANGE;
      __d = _copysign (HUGE_VAL, __d);
    }
    return __d;
}
