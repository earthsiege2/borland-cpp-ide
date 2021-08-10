/*[]--------------------------------------------------------------------[]*/
/*|                                                                      |*/
/*|     srbctr5.cpp                                                      |*/
/*|                                                                      |*/
/*|     Class strstreambuf                                               |*/
/*|     strstreambuf::strstreambuf(char*, int, char*)                    |*/
/*|                                                                      |*/
/*[]--------------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <strstrea.h>

strstreambuf::strstreambuf(char* ptr, int n, char* pstart)
{
    init(ptr, n, pstart);
}


