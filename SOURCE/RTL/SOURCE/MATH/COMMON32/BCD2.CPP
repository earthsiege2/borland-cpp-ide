/*-----------------------------------------------------------------------*
 * filename - bcd2.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the type bcd.
#endif

#include "bcd.h"

// Stream I/O function definitions

ostream & _RTLENTRY _EXPFUNC operator<<(ostream & s, bcd & a)
{
    return s << real(a);
}

istream & _RTLENTRY _EXPFUNC operator>>(istream & s, bcd & a)
{
    long double x;
    s >> x;
    a = bcd(x);
    return s;
}

/*
These don't work, unless the bcd rep is unique.

inline int operator==(bcd & a, bcd & b)
{
    return a.mantissa[0] == b.mantissa[0]
        && a.mantissa[1] == b.mantissa[1] && a.expo == b.expo;
}

inline int operator!=(bcd & a, bcd & b)
{
    return a.mantissa[0] != b.mantissa[0]
        || a.mantissa[1] != b.mantissa[1] || a.expo != b.expo;
}
*/
