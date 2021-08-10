/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     srctr2.cpp                                               |*/
/*|                                                              |*/
/*|     Class strstreambase                                      |*/
/*|          strstreambase::strstreambase()                      |*/
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
#include <strstrea.h>

strstreambase::strstreambase() :
        buf()
{
    ios::init(&this->buf);
}


