/*[]--------------------------------------------------------------------[]*/
/*|                                                                      |*/
/*|     srbctr5.cpp                                                      |*/
/*|                                                                      |*/
/*|     Class strstreambuf                                               |*/
/*|     strstreambuf::strstreambuf( unsigned char*, int, unsigned char* )|*/
/*|                                                                      |*/
/*[]--------------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <strstrea.h>

strstreambuf::strstreambuf(unsigned char* ptr, int n, unsigned char* pstart)
{
    init((char*)ptr, n, (char*)pstart);
}


