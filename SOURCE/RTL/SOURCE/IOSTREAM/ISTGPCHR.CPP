/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     filename - istgpchr.cpp                                  |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::get(char&)                        |*/
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

istream _FAR & istream::get(char _FAR & c)
{
    if (ipfx1())
        {
        if(bp->in_avail())
            {
            gcount_ = 1;
            c = bp->sbumpc();
            }
        else
            c = do_get();
        }
    else
        setstate(ios::failbit);

    return *this;
}


