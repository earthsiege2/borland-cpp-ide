/*------------------------------------------------------------------------*/
/*                                                                        */
/*  HASH.CPP                                                              */
/*                                                                        */
/*  unsigned string::hash() const;                                        */
/*  unsigned string::hash_case() const;                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992, 1993 by Borland International
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

union TCharMask
{
    unsigned in[sizeof(unsigned)];
    char ch[sizeof(unsigned)*sizeof(unsigned)];
    TCharMask();
};

TCharMask::TCharMask()
{
    for( unsigned i=0; i<sizeof(unsigned); i++ )
        for( unsigned j=0; j<sizeof(unsigned); j++ )
            ch[sizeof(unsigned)*i+j] = j<i ? char(0xff) : char(0);
}

const union TCharMask Mask;

unsigned string::hash() const
{
    if( get_case_sensitive_flag() )
        return hash_case();
    else
        return ::to_upper(*this).hash_case();
}

unsigned string::hash_case() const
{
    unsigned i, h;
    const unsigned _FAR *c;

    h = length();                 // Mix in the string length.
    i = h/sizeof(unsigned);       // Could do "<<" here, but less portable.
    c = (const unsigned _FAR *)c_str();

    while( i-- )
        h ^= *c++;        // XOR in the characters.

    // If there are any remaining characters,
    // then XOR in the rest, using a mask:
    if( (i = length()%sizeof(unsigned)) != 0 )
        {
        h ^= *c & Mask.in[i];
        }
    return h;
}

