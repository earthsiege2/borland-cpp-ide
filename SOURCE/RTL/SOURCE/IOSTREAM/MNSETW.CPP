/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     mnsetw.cpp                                               |*/
/*|                                                              |*/
/*|     Predefined manipulators                                  |*/
/*|         smanip_int setw( int )                               |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/


/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>
#include <iomanip.h>

// set the field width to n

static ios _FAR & swidth(ios _FAR & i, int n)
{
    i.width(n);
    return i;
}

smanip<int> _RTLENTRY _EXPFUNC setw(int n)
{
    return smanip<int>(swidth, n);
}
