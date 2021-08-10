/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsblkmt.cpp                                              |*/
/*|                                                              |*/
/*|     Class filebuf                                            |*/
/*|          void filebuf::lock()                                |*/
/*|          void filebuf::unlock()                              |*/
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

/* This is the multi-thread version of the filebuf locking and
 * unlocking functions.The single-thread version is fsblkst.cpp.
 */

#define _MT /* enable multi-thread features */

#include <ioconfig.h>
#include <fstream.h>
#include "_io.h"

// lock the file handle associated with the filebuf

void filebuf::lock()
{
    _lock_handle(xfd);
}


// unlock the file handle associated with the filebuf

void filebuf::unlock()
{
    _unlock_handle(xfd);
}
