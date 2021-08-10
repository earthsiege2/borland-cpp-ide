/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostfloat.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::operator<< ( double )             |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <iostream.h>

extern "C"
{
#include <_printf.h>    // for __realcvt()
}

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
// Needs to be in same code segment as near function __realcvt()
#pragma codeseg _TEXT
#endif
#endif

ostream _FAR & ostream::operator<< (double d)
{
    char buf[60];   // big enough for any floating result
    char format;

    if( flags() & ios::fixed )
        format = 'f';
    else if( flags() & ios::scientific )
        format = 'e';
    else
        format = 'g';

    __realcvt(&d, precision(), buf, format, (flags() & ios::showpoint) ? 1 : 0, F_8byteFloat);

    char* prefix = 0;
    if (buf[0] != '-' && (flags() & ios::showpos))
	prefix = "+";


    // now we have a formatted string for output, to be possibly padded
    outstr(buf, prefix);
    return *this;
}
