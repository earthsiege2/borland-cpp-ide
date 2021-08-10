/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ostischr.cpp                                             |*/
/*|                                                              |*/
/*|     Class ostream                                            |*/
/*|          ostream& ostream::operator<< ( signed char )        |*/
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

ostream _FAR & _RTLENTRY _EXPFUNC32 ostream::operator<< (char c)
{
    if( opfx() )
        {
        int pad = width(0) - 1;

        // pad on left (right-adjust) if needed -- the default case
        if( ! (x_flags & (ios::left | ios::internal)))
            {
            while( --pad >= 0 )
                {
                if( bp->sputc(x_fill) == EOF )
                    {
                    setstate(ios::badbit);
                    break;
                    }
                }
            }

        // output the data
        if( ! fail() )
            if( bp->sputc(c) == EOF )
                setstate(ios::badbit);

        // pad on right (left-adjust) if needed
        if( ! fail()  &&  (x_flags & ios::left) )
            {
            while( --pad >= 0 )
                {
                if( bp->sputc(x_fill) == EOF )
                    {
                    setstate(ios::badbit);
                    break;
                    }
                }
            }
        }
    osfx();

    return *this;
}


