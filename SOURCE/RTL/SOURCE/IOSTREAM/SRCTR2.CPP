/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srctr2.cpp                                               |*/
/*|                                                              |*/
/*|     Class strstreambase                                      |*/
/*|          strstreambase::strstreambase()                      |*/
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
#include <strstrea.h>

strstreambase::strstreambase() :
        buf()
{
    ios::init(&this->buf);
}


