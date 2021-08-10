/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     fsblkst.cpp                                              |*/
/*|                                                              |*/
/*|     Class filebuf                                            |*/
/*|          void filebuf::lock()                                |*/
/*|          void filebuf::unlock()                              |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

/* This is the single-thread version of the filebuf locking and
 * unlocking functions.The multi-thread version is fsblkmt.cpp.
 */

#include <ioconfig.h>
#include <fstream.h>
#include "_io.h"

// lock the file handle associated with the filebuf

void filebuf::lock()
{
}


// unlock the file handle associated with the filebuf

void filebuf::unlock()
{
}
