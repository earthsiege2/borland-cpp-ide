/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     stxalc.cpp                                               |*/
/*|                                                              |*/
/*|     Class ios                                                |*/
/*|          int ios::xalloc()                                   |*/
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
#include "user.h"

// supply a new word index for derived class use

int ios::xalloc()
{
    return ++usercount;
}


