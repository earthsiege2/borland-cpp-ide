/*------------------------------------------------------------------------*/
/*                                                                        */
/*  UPRLWR.CPP                                                            */
/*                                                                        */
/*  void string::to_lower();                                              */
/*  void string::to_upper();                                              */
/*                                                                        */
/*  string to_lower( const string& s );                                   */
/*  string to_upper( const string& s );                                   */
/*                                                                        */
/*  void TSubString::to_lower();                                          */
/*  void TSubString::to_upper();                                          */
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



#include <stdlib.h>
#include <cstring.h>

void string::to_lower()
{
    cow();
    strlwr((char _FAR *)c_str());
}

void string::to_upper()
{
    cow();
    strupr((char _FAR *)c_str());
}

string _Cdecl _FARFUNC to_lower( const string _FAR &s ) throw()
{
    string temp = s.copy();
    temp.to_lower();
    return temp;
}

string _Cdecl _FARFUNC to_upper( const string _FAR &s ) throw()
{
    string temp = s.copy();
    temp.to_upper();
    return temp;
}

void TSubString::to_lower() throw()
{
    if( begin != NPOS )         // Ignore null substrings
        {
        s->cow();
        char _FAR *p = s->p->array + begin;
        unsigned n = extent;
        while( n-- )
            {
            *p = char(tolower(*p));
            p++;
            }
        }
}

void TSubString::to_upper() throw()
{
    if( begin != NPOS )         // Ignore null substrings
        {
        s->cow();
        char _FAR *p = s->p->array + begin;
        unsigned n = extent;
        while( n-- )
            {
            *p = char(toupper(*p));
            p++;
            }
        }
}


