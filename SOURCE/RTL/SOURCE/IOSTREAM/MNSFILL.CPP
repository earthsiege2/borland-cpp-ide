/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     mnsfill.cpp                                              |*/
/*|                                                              |*/
/*|     Predefined manipulators                                  |*/
/*|         smanip_int setfill( int )                            |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/


/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include <iostream.h>
#include <iomanip.h>

// set fill character for padding a field

static ios _FAR & sfill(ios _FAR & i, int f)
{
    i.fill(f);
    return i;
}

smanip<int> _RTLENTRY _EXPFUNC setfill(int f)
{
    return smanip<int>(sfill, f);
}
