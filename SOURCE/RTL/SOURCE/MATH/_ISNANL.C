/*------------------------------------------------------------------------
 * filename - _isnanl.c
 *
 * function(s)
 *
 *   _isnanl    - long double version
 *
 * These functions return non-zero if the value passed in is +-NAN, else 0.
 * More specifically, the non-zero return value = _FPCLASS_SNAN if the NAN
 * is of the signaling type, or _FPCLASS_QNAN if the NAN is of the quiet type.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#include <float.h>
#include <_float.h>


int _RTLENTRY _EXPFUNC _isnanl (long double _ld)
{
    _rtl_ldouble_t *p = (_rtl_ldouble_t *) &_ld;
    if ((p->i16.value & 0x7FFF) == 0x7FFF)
        if (p->i64.value != 0x8000000000000000)
        {
            if (p->i64.value & 0x4000000000000000 == 0)
                return _FPCLASS_SNAN; /* Signaling NAN returns 1 */
            else
                return _FPCLASS_QNAN; /* Quiet NAN returns 2 */
        }

    return 0;
}

