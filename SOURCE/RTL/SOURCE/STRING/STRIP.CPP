/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STRIP.CPP                                                             */
/*                                                                        */
/*  TSubString string::strip( string::StripType st, char c );             */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1992, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

TSubString string::strip( string::StripType st, char c )
{
    size_t start = 0;                        // index of first character
    size_t end = length()-1;                 // index of last character
    const char _FAR *direct = p->array;

    if( st==Leading || st==Both )
        {
        for( ; start<=end; start++)
            {
            if( direct[start] != c )
                goto nonNull;
            }
        return TSubString( this, NPOS, 0 ); // Null substring
    }

nonNull:

    if(st==Trailing || st==Both)
        {
        for( ; end >= start; end--)
            if( direct[end] != c )
                break;
        }
    return TSubString(this, start, end-start+1);
}

