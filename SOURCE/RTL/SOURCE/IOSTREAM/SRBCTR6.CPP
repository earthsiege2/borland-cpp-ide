/*[]----------------------------------------------------------------[]*/
/*|                                                                  |*/
/*|     srbctr6.cpp                                                  |*/
/*|                                                                  |*/
/*|     Class strstreambuf                                           |*/
/*|     strstreambuf::strstreambuf(char*, int, char*)                |*/
/*|                                                                  |*/
/*[]----------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <strstrea.h>

strstreambuf::strstreambuf(char* ptr, int n, char* pstart)
{
    init(ptr, n, pstart);
}


