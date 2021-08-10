/*[]----------------------------------------------------------------[]*/
/*|                                                                  |*/
/*|     srbctr4.cpp                                                  |*/
/*|                                                                  |*/
/*|     Class strstreambuf                                           |*/
/*|     strstreambuf::strstreambuf( signed char*, int, signed char* )|*/
/*|                                                                  |*/
/*[]----------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <strstrea.h>

strstreambuf::strstreambuf(signed char* ptr, int n, signed char* pstart)
{
    init((char *)ptr, n, (char *)pstart);
}


