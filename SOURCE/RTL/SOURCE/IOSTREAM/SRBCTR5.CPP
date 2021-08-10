/*[]--------------------------------------------------------------------[]*/
/*|                                                                      |*/
/*|     srbctr5.cpp                                                      |*/
/*|                                                                      |*/
/*|     Class strstreambuf                                               |*/
/*|     strstreambuf::strstreambuf( unsigned char*, int, unsigned char* )|*/
/*|                                                                      |*/
/*[]--------------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include <strstrea.h>

strstreambuf::strstreambuf(unsigned char* ptr, int n, unsigned char* pstart)
{
    init((char*)ptr, n, (char*)pstart);
}


