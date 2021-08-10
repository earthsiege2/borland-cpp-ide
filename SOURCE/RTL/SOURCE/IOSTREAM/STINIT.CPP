/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stinit.cpp                                               |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          void ios::init( streambuf * )                       |*/
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

void ios::init(streambuf* sbp)
{
    nwords = 0;
    state = ospecial = 0;
    ispecial = skipping;
    x_flags = skipws;
    x_precision = 6;    // ANSI Draft Input/Output revision 6
    x_width = 0;
    x_fill = ' ';
    x_tie = 0;
    x_delbuf = 1;
    bp = sbp;
}


