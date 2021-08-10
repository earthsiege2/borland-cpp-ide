/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     istebor.cpp                                              |*/
/*|                                                              |*/
/*|     Class istream                                            |*/
/*|          istream& istream::operator>> (bool &)               |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ioconfig.h>
#include <iostream.h>
#include <ctype.h>
#include <string.h>

/*
   Operator to handle extracting a bool from an istream.  If the
   boolalpha flag is set, then the ASCII strings "true" or "false" are
   looked for, if not set, then 0 or 1 is looked for.  Any non-valid
   characters immediately cause the fail bit to be set and the remaining
   junk in the stream is left alone.  If the fail bit is set, the bool
   returned is false.
*/

istream _FAR & _RTLENTRY istream::operator>> (bool _FAR &_b)
{
    int idx = 0, which;
    int value;
    int c;
    char Test[2][6]  = {{"TRUE\0"}, {"FALSE"}};

    _b = false;
    if (ipfx())
    {
        if (x_flags & boolalpha)
        {
            c = toupper (bp->sgetc());
            if (c == 'T')
                which = 0; // assume it's "true"
            else
            if (c == 'F')
                which = 1; // assume it's "false"
            else  // Error state;
            {
                clear(rdstate() | ios::failbit);
                return *this;
            }
            while (1)
            {
                if (Test[which][idx] && (c != Test[which][idx]))
                {
                    clear(rdstate() | ios::failbit);
                    break;
                }
                if (++idx > (which ? 5 : 4))  // end after 5 chars for "false"
                {                             //  or 4 chars for "true"
                    _b = which ? false : true;
                    break;
                }
                c = toupper (bp->snextc());
            }
        }
        else
        {
            *this >> value;
            if ((value != 0) && (value != 1))
                clear(rdstate() | ios::failbit);
            else
                _b = (bool) value;
        }
    }
    return  *this;
}
