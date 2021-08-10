/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostopfx.cpp                                              |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          int ostream::do_opfx()                              |*/
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


