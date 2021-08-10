/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbsetb.cpp                                              |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          void streambuf::setb( char *, char *, int )         |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include <iostream.h>

void streambuf::setb(char* b, char* eb, int a)
{
    if( alloc_  &&  base_  &&  base_ != b )
        delete[] base_;
    base_ = b;
    ebuf_ = ( b && eb && (eb >= b) ) ? eb : b;
    unbuf_ = ! b;
    alloc_ = a && b;
}


