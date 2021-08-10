/*[]----------------------------------------------------------------[]*/
/*|                                                                  |*/
/*|     srbctr4.cpp                                                  |*/
/*|                                                                  |*/
/*|     Class strstreambuf                                           |*/
/*|     strstreambuf::strstreambuf( signed char*, int, signed char* )|*/
/*|                                                                  |*/
/*[]----------------------------------------------------------------[]*/

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

strstreambuf::strstreambuf(signed char* ptr, int n, signed char* pstart)
{
    init((char *)ptr, n, (char *)pstart);
}


