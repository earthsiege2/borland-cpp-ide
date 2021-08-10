/*------------------------------------------------------------------------
 * filename - _scalbl.c
 *
 * function(s)
 *
 *   _scalbl   Scales argument by a power of 2 (long double version)
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#pragma inline
#include <errno.h>
#include <math.h>
#include <float.h>

#pragma argsused
#pragma warn -rvl
long double _RTLENTRY _EXPFUNC _scalbl(long double __ld, long __exp)
{
    unsigned short ctrl;
    ctrl = _control87 (MCW_EM, MCW_EM);
    asm {
      fild    [__exp]
      fld     [__ld]
      fscale
      fstp    [__ld]
      ffree   ST(0)
      fincstp
    }
    _control87(MCW_EM, ctrl);

    if (!_finitel (__ld))
    {
      errno = ERANGE;
      __ld = _copysignl (HUGE_VAL, __ld);
    }
    return __ld;
}
