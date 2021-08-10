/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostopfx.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          int ostream::do_opfx()                              |*/
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

// implementation of opfx -- output prefix operations
int ostream::do_opfx()
{
    if( ! fail() )
        {
        if( x_tie )
            x_tie->flush();
        return 1;
        }

    return 0;
}


