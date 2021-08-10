/*[]----------------------------------------------------------------[]*/
/*|                                                                  |*/
/*|     srbctr6.cpp                                                  |*/
/*|                                                                  |*/
/*|     Class strstreambuf                                           |*/
/*|     strstreambuf::strstreambuf(char*, int, char*)                |*/
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

strstreambuf::strstreambuf(char* ptr, int n, char* pstart)
{
    init(ptr, n, pstart);
}


