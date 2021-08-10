/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostfloat.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::operator<< ( long double )        |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1992 by Borland International
 *      All Rights Reserved.
 *
 */

#include <iostream.h>

extern "C"
{
#include <_printf.h>    // for __realcvt()
}

#if !defined(__FLAT__)
// Needs to be in same code segment as near function __realcvt()
  #ifdef DEBUG
  static void __debug(void){}
  #endif
#pragma codeseg _TEXT
#endif

ostream _FAR & ostream::operator<< (long double d)
{
    char buf[60];   // big enough for any floating result
    char format;

    if( flags() & ios::fixed )
        format = 'f';
    else if( flags() & ios::scientific )
        format = 'e';
    else
        format = 'g';

    char* prefix = 0;
    if( ! (d < 0.0)  &&  (flags() & ios::showpos) )
        prefix = "+";

    __realcvt(&d, precision(), buf, format, 0, F_10byteFloat);

    // now we have a formatted string for output, to be possibly padded
    outstr(buf, prefix);
    return *this;
}
