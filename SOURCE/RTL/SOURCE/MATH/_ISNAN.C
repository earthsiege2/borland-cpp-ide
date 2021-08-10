/*------------------------------------------------------------------------
 * filename - _isnan.c
 *
 * function(s)
 *
 *   _isnan     - double version
 *
 * These functions return non-zero if the value passed in is +-NAN, else 0.
 * More specifically, the non-zero return value = _FPCLASS_SNAN if the NAN
 * is of the signaling type, or _FPCLASS_QNAN if the NAN is of the quiet type.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <float.h>
#include <_float.h>


int _RTLENTRY _EXPFUNC _isnan (double _d)
{
    _rtl_double_t *p = (_rtl_double_t *) &_d;

    if ((p->i64.s.high32.value & 0x7FF00000) == 0x7FF00000)
        if (((p->i64.s.high32.value & 0x000FFFFF) == 0) &&
            (p->i64.s.low32.value == 0))
            return 0;
        else
        {
            if ((p->i64.s.high32.value & 0x00080000) == 0)
                return _FPCLASS_SNAN; /* Signaling NAN returns 1 */
            else
                return _FPCLASS_QNAN; /* Quiet NAN returns 2 */
        }

    return 0;
}
