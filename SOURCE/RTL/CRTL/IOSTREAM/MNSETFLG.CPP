/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     mnsetflg.cpp                                             |*/
/*|                                                              |*/
/*|     Predefined manipulators                                  |*/
/*|         smanip_long setiosflags( long )                      |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/


/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1992 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>
#include <iomanip.h>

// set the flags bitvector according to the bits set in b

static ios _FAR & sios(ios _FAR & i, long b)
{
    i.setf(b);
    return i;
}

smanip<long> _RTLENTRY _EXPFUNC setiosflags(long b)
{
    return smanip<long>(sios, b);
}


