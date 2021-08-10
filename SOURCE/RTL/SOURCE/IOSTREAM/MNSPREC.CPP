/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     mnsprec.cpp                                              |*/
/*|                                                              |*/
/*|     Predefined manipulators                                  |*/
/*|         smanip_int setprecision( int )                       |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/


/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>
#include <iomanip.h>

// set the floating-point precision to n digits

static ios _FAR & sprec(ios _FAR & i, int n)
{
    i.precision(n);
    return i;
}

smanip<int> _RTLENTRY _EXPFUNC setprecision(int n)
{
    return smanip<int>(sprec, n);
}
