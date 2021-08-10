/*-----------------------------------------------------------------------*
 * filename - bcd2.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1990, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6 $        */

#ifndef __cplusplus
#error Must use C++ for the type bcd.
#endif

#include <bcd.h>
#include <iostream>


// Stream I/O function definitions

std::ostream & _RTLENTRY _EXPFUNC operator<<(std::ostream & s, const bcd & a)
{
    return s << real(a);
}

std::istream & _RTLENTRY _EXPFUNC operator>>(std::istream & s, bcd & a)
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
