/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stbsetp.cpp                                              |*/
/*|                                                              |*/
/*|     Class streambuf                                          |*/
/*|          void streambuf::setp( char *, char * )              |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <iostream.h>

void streambuf::setp(char* p, char* ep)
{
    pbase_ = pptr_ = p;
    epptr_ = (p && ep && (ep >= p)) ? ep : p;
}


