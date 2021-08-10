/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbtalc.cpp                                              |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          long ios::bitalloc()                                |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

// supply a new flags bit
long ios::bitalloc()
{
    if( nextbit >= 31 )
        return 0;
    else
        return (1L << (unsigned)++nextbit);
}


