/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STRINGIO.CPP                                                          */
/*                                                                        */
/*  Definitions for string Input/Output functions                         */
/*                                                                        */
/*  istream& string::read_file( istream& strm );                          */
/*  istream& string::read_string( istream& strm );                        */
/*  istream& string::read_line( istream& strm );                          */
/*  istream& string::read_to_delim( istream& strm, char delim );          */
/*  istream& string::read_token( istream& strm );                         */
/*  istream& operator >> ( istream& strm, string& s );                    */
/*  ostream& operator << ( ostream& os, const string& s );                */
/*  istream& getline( istream& is, string& s );                           */
/*  istream& getline( istream& is, string& s, char c );                   */
/*  void TStringRef::read_to_delim( istream& strm, char delim );          */
/*  void TStringRef::read_token( istream& strm );                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1992, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <cstring.h>
#include <stdio.h>
#include <iomanip.h>


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  string I/O                                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/


// Read to EOF, or null terminator, whichever comes first:
istream _FAR & string::read_file( istream _FAR & strm )
{
    cow();
    p->read_to_delim(strm, '\0');
    return strm;
}

// Identical to above:
istream _FAR & string::read_string( istream _FAR & strm )
{
    cow();
    p->read_to_delim(strm, '\0');
    return strm;
}

istream _FAR & string::read_line( istream _FAR & strm )
{
    char ch;

    // If the skipWhite flag has been set, then skip any leading whitespace
    if(get_skip_whitespace_flag())
        {
        do  {
            strm.get(ch);
            } while(strm.good() && isspace(ch));
        strm.putback(ch);
        }
    cow();
    p->read_to_delim(strm, '\n');
    return strm;
}

// Read to EOF or delimitor.
istream _FAR & string::read_to_delim( istream _FAR & strm, char delim )
{
    cow();
    p->read_to_delim(strm, delim);
    return strm;
}

istream _FAR & string::read_token( istream _FAR & strm )
{
    cow();
    p->read_token(strm);
    return strm;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  string global functions                                               */
/*                                                                        */
/*------------------------------------------------------------------------*/

istream _FAR & _Cdecl _FARFUNC operator>>( istream _FAR & strm,
                                           string _FAR & s )
{
    return s.read_token(strm);
}

ostream _FAR & _Cdecl _FARFUNC operator<<( ostream _FAR & os,
                                           const string _FAR & s )
{
    return os << s.c_str();
}

istream _FAR & _Cdecl _FARFUNC getline( istream _FAR & is, string _FAR & s )
{
    return s.read_line( is );
}

istream _FAR & _Cdecl _FARFUNC getline( istream _FAR & is, string _FAR &s, char c )
{
    return s.read_to_delim( is, c );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TStringRef I/O                                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Read up to an EOF, or a delimiting character, whichever comes         */
/*  first.  The delimiter is not stored in the string,                    */
/*  but is removed from the input stream.                                 */
/*                                                                        */
/*  Because we don't know how big a string to expect, we first read       */
/*  as much as we can and then, if the EOF or null hasn't been            */
/*  encountered, do a resize and keep reading.                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

void TStringRef::read_to_delim( istream _FAR & strm, char delim )
    throw( xalloc )
{
    char ch;
    nchars = 0;

    while ( 1 )
        {

        // Read as many characters as we can, up to the delimitor:
        strm.get( array+nchars, capacity-nchars+1, delim );

        // This is the new string length:
        nchars += strlen( array+nchars );

        // What stopped us?  An EOF?
        if( !strm.good() )
            break;          // EOF encountered (or worse!)

        // Nope.  Was it the delimiter?
        strm.get(ch);
        if(ch==delim)
            break;  // Yup. We're done.  Don't put it back on the stream.
        else
        strm.putback(ch);   // Nope, Put it back and keep going.

        // If we got here, the read must have stopped because the buffer
        // was going to overflow.  Resize and keep going.
        grow_to( round_capacity(nchars + string::get_resize_increment()) );
        }

    check_freeboard();
}

//
// Read a token, delimited by whitespace, from the input stream.
//

void TStringRef::read_token( istream _FAR & strm ) throw( xalloc )
{
    nchars = 0;

    while(1)
    {
	// Extractor will always store null byte
	strm >> setw(capacity-nchars+1) >> (array+nchars);
        nchars += strlen( array+nchars );
        if( !strm.good() || isspace(strm.peek()) )
            break; // Was complete token read?
        grow_to( round_capacity(nchars + string::get_resize_increment()) );
    }

    check_freeboard();
}

