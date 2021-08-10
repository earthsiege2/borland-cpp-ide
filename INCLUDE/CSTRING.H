/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CSTRING.H                                                             */
/*                                                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for CSTRING.H
#endif

#ifndef __CSTRING_H
#define __CSTRING_H

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  This class uses a technique called "copy-on-write".                   */
/*  Multiple instances of a string can refer to the same piece of data    */
/*  so long as it is in a "readonly" situation.  If a string writes to    */
/*  the data, then a copy is automatically made if more than one string   */
/*  is referring to it.                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#define STRICT

#if !defined(__STRING_H)
#include <string.h>
#endif

#if !defined(__REF_H)
#include <ref.h>
#endif

#if !defined(__CTYPE_H)
#include <ctype.h>
#endif

#if !defined(__STDDEF_H)
#include <stddef.h>
#endif

#if !defined(__EXCEPT_H)
#include <except.h>
#endif

#if defined(_Windows) && !defined(__WINDOWS_H)
#include <windows.h>
#endif


#if !defined(RC_INVOKED)

#pragma pack(push, 1)

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-     // disable Object data calling convention
#endif
#endif

#if !defined(__TINY__)
#pragma option -RT
#endif

#pragma option -Vo-     // set standard C++ options

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


class _EXPCLASS string;
class _EXPCLASS TRegexp;
class _EXPCLASS TSubString;
class _EXPCLASS TStringRef;
class _EXPCLASS istream;
class _EXPCLASS ostream;

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Since inline functions that use throw specifiers                      */
/*  currently end up rather large, we don't use throw                     */
/*  specifiers on them unless you #define USE_THROW_SPECIFIERS.           */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if defined( USE_THROW_SPECIFIERS )
#define THROW_NONE                  throw()
#define THROW_XALLOC                throw(xalloc)
#define THROW_OUTOFRANGE            throw( string::outofrange )
#define THROW_XALLOC_LENGTHERROR    throw( xalloc, string::lengtherror )
#define THROW_XALLOC_OUTOFRANGE     throw( xalloc, string::outofrange )
#define THROW_XALLOC_RANGE_LENGTH   \
        throw( xalloc, string::lengtherror, string::outofrange )
#else
#define THROW_NONE
#define THROW_XALLOC
#define THROW_OUTOFRANGE
#define THROW_XALLOC_LENGTHERROR
#define THROW_XALLOC_OUTOFRANGE
#define THROW_XALLOC_RANGE_LENGTH
#endif


/*------------------------------------------------------------------------*/
/*                                                                        */
/*  string                                                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

const size_t NPOS = size_t(-1);

class _EXPCLASS string
{

public:

    //
    // Exceptions
    //
    class outofrange : public xmsg
    {
    public:
        _RTLENTRY outofrange();
    };

    class lengtherror : public xmsg
    {
    public:
        _RTLENTRY lengtherror();
    };

    //
    // Constructors
    //

    _RTLENTRY string() throw( xalloc );

    _RTLENTRY string( const string _FAR &s ) throw( xalloc );
    _RTLENTRY string( const string _FAR &s, size_t orig, size_t n = NPOS )
        throw( xalloc );

    _RTLENTRY string( const char _FAR *cp ) throw( xalloc, lengtherror );
    _RTLENTRY string( const char _FAR *cp, size_t orig, size_t n = NPOS )
        throw( xalloc, lengtherror );

    _RTLENTRY string( char c ) throw (xalloc, string::lengtherror);
    _RTLENTRY string( char c, size_t n ) throw (xalloc, string::lengtherror);

    _RTLENTRY string( signed char c ) throw (xalloc, string::lengtherror);
    _RTLENTRY string( signed char c, size_t n ) throw (xalloc, string::lengtherror);

    _RTLENTRY string( unsigned char c ) throw (xalloc, string::lengtherror);
    _RTLENTRY string( unsigned char c, size_t n ) throw (xalloc, string::lengtherror);

    // non-standard constructors
    _RTLENTRY string( const TSubString _FAR &ss ) throw( xalloc );

    // Special far string ctors for small & medium model
    #if (defined( __TINY__ ) || defined( __SMALL__ ) || defined( __MEDIUM__ )) && !defined( __DLL__ )
    _RTLENTRY string( const char __far *cp ) throw (xalloc, string::lengtherror);
    _RTLENTRY string( const char __far *cp, size_t orig, size_t n = NPOS )
        throw( xalloc, lengtherror );
    #endif

    // Ctor to make a string from a resource
    #if defined( _Windows )
    _RTLENTRY string( HINSTANCE instance, UINT id, int len = 255 )
        throw( xalloc, lengtherror );
    #endif

    //
    // Destructor
    //
    _RTLENTRY ~string() throw();

    //
    // Assignment
    //
    string _FAR & _RTLENTRY operator = ( const string _FAR &s ) THROW_XALLOC;
    string _FAR & _RTLENTRY assign( const string _FAR &s ) THROW_XALLOC;
    string _FAR & _RTLENTRY assign( const string _FAR &s,
                                    size_t orig,
                                    size_t n = NPOS ) throw( xalloc );

    //
    // Concatenation
    //
    string _FAR & _RTLENTRY operator += ( const string _FAR &s )
        THROW_XALLOC_LENGTHERROR;
    string _FAR & _RTLENTRY append( const string _FAR &s )
        THROW_XALLOC_LENGTHERROR;
    string _FAR & _RTLENTRY append( const string _FAR &s,
                                    size_t orig,
                                    size_t n = NPOS ) throw( xalloc, lengtherror );

    string _FAR & _RTLENTRY operator += ( const char _FAR *cp )
        THROW_XALLOC_LENGTHERROR;
    friend string _RTLENTRY _FARFUNC operator + ( const string _FAR &s,
                                               const char _FAR *cp )
        THROW_XALLOC_LENGTHERROR;
    string _FAR & _RTLENTRY append( const char _FAR *cp )
        throw( xalloc, lengtherror );
    string _FAR & _RTLENTRY append( const char _FAR *cp,
                                    size_t orig,
                                    size_t n = NPOS ) throw( xalloc, lengtherror );

    string _FAR & _RTLENTRY prepend( const string _FAR &s )
        THROW_XALLOC_LENGTHERROR;
    string _FAR & _RTLENTRY prepend( const string _FAR &s,
                                     size_t orig,
                                     size_t n = NPOS ) THROW_XALLOC_LENGTHERROR;
    string _FAR & _RTLENTRY prepend( const char _FAR *cp )
        THROW_XALLOC_LENGTHERROR;
    string _FAR & _RTLENTRY prepend( const char _FAR *cp,
                                     size_t orig,
                                     size_t n = NPOS ) throw( xalloc, lengtherror );

    //
    // Comparison
    //
    int _RTLENTRY compare(const string _FAR &s) const throw();
    int _RTLENTRY compare(const string _FAR &s,
                          size_t orig,
                          size_t n = NPOS ) const throw();

    friend int _RTLENTRY operator == ( const string _FAR &s1, const string _FAR &s2 )
        THROW_NONE;

    friend int _RTLENTRY operator != ( const string _FAR &s1, const string _FAR &s2 )
        THROW_NONE;

    friend int _RTLENTRY operator == ( const string _FAR &s, const char _FAR *cp )
        THROW_NONE;
    friend int _RTLENTRY operator == ( const char _FAR *cp, const string _FAR &s )
        THROW_NONE;

    friend int _RTLENTRY operator != ( const string _FAR &s, const char _FAR *cp )
        THROW_NONE;
    friend int _RTLENTRY operator != ( const char _FAR *cp, const string _FAR &s )
        THROW_NONE;

    friend int _RTLENTRY operator <  ( const string _FAR &s1, const string _FAR &s2 )
        THROW_NONE;
    friend int _RTLENTRY operator <  ( const string _FAR &s, const char _FAR *cp )
        THROW_NONE;
    friend int _RTLENTRY operator <  ( const char _FAR *cp, const string _FAR &s )
        THROW_NONE;

    friend int _RTLENTRY operator <= ( const string _FAR &s1, const string _FAR &s2 )
        THROW_NONE;
    friend int _RTLENTRY operator <= ( const string _FAR &s, const char _FAR *cp )
        THROW_NONE;
    friend int _RTLENTRY operator <= ( const char _FAR *cp, const string _FAR &s )
        THROW_NONE;

    friend int _RTLENTRY operator >  ( const string _FAR &s1, const string _FAR &s2 )
        THROW_NONE;
    friend int _RTLENTRY operator >  ( const string _FAR &s, const char _FAR *cp )
        THROW_NONE;
    friend int _RTLENTRY operator >  ( const char _FAR *cp, const string _FAR &s )
        THROW_NONE;

    friend int _RTLENTRY operator >= ( const string _FAR &s1, const string _FAR &s2 )
        THROW_NONE;
    friend int _RTLENTRY operator >= ( const string _FAR &s, const char _FAR *cp )
        THROW_NONE;
    friend int _RTLENTRY operator >= ( const char _FAR *cp, const string _FAR &s )
        THROW_NONE;

    //
    // Insertion at some position
    //
    string _FAR & _RTLENTRY insert( size_t pos, const string _FAR &s )
        throw( xalloc, outofrange, lengtherror );
    string _FAR & _RTLENTRY insert( size_t pos,
                                    const string _FAR &s,
                                    size_t orig,
                                    size_t n = NPOS ) throw( xalloc, outofrange, lengtherror );

    //
    // Removal
    //
    string _FAR & _RTLENTRY remove( size_t pos ) THROW_XALLOC_OUTOFRANGE;
    string _FAR & _RTLENTRY remove( size_t pos, size_t n )
        throw( xalloc, outofrange );

    //
    // Replacement at some position
    //
    string _FAR & _RTLENTRY replace( size_t pos, size_t n, const string _FAR &s )
        THROW_XALLOC_RANGE_LENGTH;
    string _FAR & _RTLENTRY replace( size_t pos,
                                     size_t n1,
                                     const string _FAR &s,
                                     size_t orig,
                                     size_t n2 = NPOS ) throw( xalloc, outofrange, lengtherror );

    //
    // Subscripting
    //
    char _RTLENTRY get_at( size_t pos ) const THROW_OUTOFRANGE;
    void _RTLENTRY put_at( size_t pos, char c ) THROW_OUTOFRANGE;

    char _FAR & _RTLENTRY operator[]( size_t pos ) THROW_OUTOFRANGE;
    char _FAR & _RTLENTRY operator()( size_t pos ) throw( outofrange );
    TSubString _RTLENTRY operator()( size_t start, size_t len ) THROW_NONE;
    TSubString _RTLENTRY operator()( const TRegexp _FAR &re ) THROW_NONE;
    TSubString _RTLENTRY operator()( const TRegexp _FAR &re, size_t start ) throw();

    char _RTLENTRY operator[]( size_t pos ) const THROW_OUTOFRANGE;
    char _RTLENTRY operator()( size_t pos ) const THROW_OUTOFRANGE;
    const TSubString _RTLENTRY operator()( size_t start, size_t len ) const throw();
    const TSubString _RTLENTRY operator()( const TRegexp _FAR &pat ) const THROW_NONE;
    const TSubString _RTLENTRY operator()( const TRegexp _FAR &pat, size_t start )
        const throw();

    //
    // Searching
    //
    size_t _RTLENTRY find( const string _FAR &s ) const THROW_NONE;
    size_t _RTLENTRY find( const string _FAR &s, size_t pos ) const throw();
    size_t _RTLENTRY rfind( const string _FAR &s ) const THROW_NONE;
    size_t _RTLENTRY rfind( const string _FAR &s, size_t pos ) const throw();

    int _RTLENTRY contains( const char _FAR *pat ) const throw();
    int _RTLENTRY contains(const string _FAR &s) const THROW_NONE;
    size_t _RTLENTRY find( const TRegexp _FAR &pat, size_t i = 0 ) const throw();
    size_t _RTLENTRY find( const TRegexp _FAR &pat, size_t _FAR *ext, size_t i = 0 )
        const throw();

    //
    // Substring
    //
    string _RTLENTRY substr( size_t pos ) const
        throw( xalloc, outofrange );
    string _RTLENTRY substr( size_t pos, size_t n ) const
        throw( xalloc, outofrange );

    TSubString _RTLENTRY substring( const char _FAR *cp ) THROW_NONE;
    const TSubString _RTLENTRY substring( const char _FAR *cp )
        const THROW_NONE;
    TSubString _RTLENTRY substring( const char _FAR *cp, size_t start ) throw();
    const TSubString _RTLENTRY substring( const char _FAR *cp, size_t start )
        const throw();

    //
    // Character set searching
    //
    size_t _RTLENTRY find_first_of( const string _FAR &s ) const THROW_NONE;
    size_t _RTLENTRY find_first_of( const string _FAR &s, size_t pos ) const throw();
    size_t _RTLENTRY find_first_not_of( const string _FAR &s ) const THROW_NONE;
    size_t _RTLENTRY find_first_not_of( const string _FAR &s, size_t pos )
        const throw();
    size_t _RTLENTRY find_last_of( const string _FAR &s ) const THROW_NONE;
    size_t _RTLENTRY find_last_of( const string _FAR &s, size_t pos ) const throw();
    size_t _RTLENTRY find_last_not_of( const string _FAR &s ) const THROW_NONE;
    size_t _RTLENTRY find_last_not_of( const string _FAR &s, size_t pos )
        const throw();

    //
    // Miscellaneous
    //
    size_t _RTLENTRY length() const THROW_NONE;
    size_t _RTLENTRY copy( char _FAR *cb, size_t n ) throw( outofrange );
    size_t _RTLENTRY copy( char _FAR *cb, size_t n, size_t pos ) throw( outofrange );
    const char _FAR * _RTLENTRY c_str() const THROW_NONE;
    size_t _RTLENTRY reserve() const THROW_NONE;
    void _RTLENTRY reserve( size_t ic ) throw( xalloc, outofrange );

    string _RTLENTRY copy() const throw( xalloc );    // Distinct copy of self.


    // Static member functions:
    static int _RTLENTRY set_case_sensitive( int tf = 1 );
    static int _RTLENTRY set_paranoid_check( int ck = 1 );
    static int _RTLENTRY skip_whitespace( int sk = 1 );
    static size_t _RTLENTRY initial_capacity( size_t ic = 63 );
    static size_t _RTLENTRY resize_increment( size_t ri = 64 );
    static size_t _RTLENTRY max_waste( size_t mw = 63 );

    static int _RTLENTRY get_case_sensitive_flag();
    static int _RTLENTRY get_paranoid_check_flag();
    static int _RTLENTRY get_skip_whitespace_flag();
    static size_t _RTLENTRY get_initial_capacity();
    static size_t _RTLENTRY get_resize_increment();
    static size_t _RTLENTRY get_max_waste();

    enum StripType { Leading, Trailing, Both };

    // Non-static member functions:
    unsigned _RTLENTRY hash() const;
    int      _RTLENTRY is_null() const;
    istream _FAR & _RTLENTRY read_file( istream _FAR &is );
    istream _FAR & _RTLENTRY read_string( istream _FAR &is );
    istream _FAR & _RTLENTRY read_line( istream _FAR &is );
    istream _FAR & _RTLENTRY read_to_delim( istream _FAR &is, char delim = '\n' );
    istream _FAR & _RTLENTRY read_token( istream _FAR &is );
    void       _RTLENTRY resize( size_t m );
    TSubString _RTLENTRY strip( StripType s = Trailing, char c = ' ' );
    void       _RTLENTRY to_lower();
    void       _RTLENTRY to_upper();

    #if defined( _Windows )
    void _RTLENTRY ansi_to_oem() THROW_NONE;
    void _RTLENTRY oem_to_ansi() THROW_NONE;
    #endif

protected:

    int  _RTLENTRY valid_element( size_t pos ) const THROW_NONE;
    int  _RTLENTRY valid_index( size_t pos ) const THROW_NONE;

    void _RTLENTRY assert_element( size_t pos ) const throw( outofrange );
    void _RTLENTRY assert_index( size_t pos ) const throw( outofrange );

    _RTLENTRY string( const string _FAR &s, const char _FAR *cb );
    void _RTLENTRY cow();

private:

    TStringRef _FAR *p;

    static int case_sensitive;
    static int paranoid_check;
    static int skip_white;
    static size_t initial_capac;
    static size_t resize_inc;
    static size_t freeboard;

private:

    friend class _EXPCLASS TSubString;
    friend class _EXPCLASS TStringRef;

    void _RTLENTRY clone();
    size_t _RTLENTRY find_case_index( const char _FAR *cb,
                            size_t start,
                            size_t _FAR &patl) const;
    size_t _RTLENTRY rfind_case_index( const char _FAR *cb,
                             size_t start,
                             size_t _FAR &patl) const;
    size_t _RTLENTRY find_index(const char _FAR *,
                      size_t start,
                      size_t _FAR & patl) const;
    size_t _RTLENTRY rfind_index(const char _FAR *,
                       size_t start,
                       size_t _FAR & patl) const;
    unsigned _RTLENTRY hash_case() const;

};

#if defined( BI_OLDNAMES )
#define BI_String string
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Related global functions                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

istream _FAR &
_RTLENTRY _FARFUNC operator >> ( istream _FAR &is, string _FAR &s );

ostream _FAR &
_RTLENTRY _FARFUNC operator << ( ostream _FAR &os, const string _FAR &s );

istream _FAR &
_RTLENTRY _FARFUNC getline( istream _FAR &is, string _FAR &s );

istream _FAR &
_RTLENTRY _FARFUNC getline( istream _FAR &is, string _FAR &s, char c );

string _RTLENTRY _FARFUNC to_lower( const string _FAR &s ) throw();
string _RTLENTRY _FARFUNC to_upper( const string _FAR &s ) throw();
string _RTLENTRY _FARFUNC operator + ( const char _FAR *cp,
                                    const string _FAR & s)
                                    throw( xalloc, string::lengtherror );
string _RTLENTRY _FARFUNC operator + ( const string _FAR &s1,
                                    const string _FAR &s2 )
                                    THROW_XALLOC_LENGTHERROR;

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TStringRef                                                            */
/*                                                                        */
/*  This is the dynamically allocated part of a string.                   */
/*  It maintains a reference count.                                       */
/*  There are no public member functions.                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _EXPCLASS TStringRef : public TReference
{

    friend class _EXPCLASS string;
    friend class _EXPCLASS TSubString;

    //
    // Data
    //
    char _FAR *array;
    size_t nchars;
    size_t capacity;

    //
    // State flags
    //
    enum {
        MemReserved = 1     // indicates that reserve() has been
                            // called on this string
        };
    unsigned flags;

    //
    // Constructors
    //
    _RTLENTRY TStringRef( char c, size_t n );
    _RTLENTRY TStringRef( const char _FAR *str1, size_t count1,
                const char _FAR *str2, size_t count2,
                size_t extra );

    // Special far TStringRef ctor for small data models
    #if (defined( __TINY__ ) || defined( __SMALL__ ) || defined( __MEDIUM__ )) && !defined( __DLL__ )
    _RTLENTRY TStringRef( const char __far*, size_t n = NPOS );
    #endif

    //
    // Ctor to make a TStringRef from a resource
    //
    #if defined( _Windows )
    _RTLENTRY TStringRef( HINSTANCE instance, UINT id, int len = 255 )
         throw( xalloc, string::lengtherror );
    #endif

    //
    // Destructor
    //
    _RTLENTRY ~TStringRef() throw();

    //
    // Miscellaneous
    //
    void _RTLENTRY reserve( size_t ic ) throw( xalloc, string::outofrange );
    void _RTLENTRY check_freeboard() throw();
    void _RTLENTRY grow_to( size_t n ) throw( xalloc, string::lengtherror );
    void _RTLENTRY read_to_delim( istream _FAR &is, char delim ) throw( xalloc );
    void _RTLENTRY read_token( istream _FAR &is ) throw( xalloc );
    static size_t _RTLENTRY round_capacity( size_t cap ) throw();
    void _RTLENTRY splice( size_t start, size_t extent,
                 const char _FAR *cp, size_t n )
        throw( xalloc, string::lengtherror );

};

#if defined( BI_OLDNAMES )
#define BI_StringRef TStringRef
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TSubString                                                            */
/*                                                                        */
/*  The TSubString class allows selected elements to be addressed.        */
/*  There are no public constructors.                                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _EXPCLASS TSubString
{

public:

    //
    // Assignment
    //
    TSubString _FAR & _RTLENTRY operator = ( const string _FAR &s ) throw();

    //
    // Comparison
    //
    int _RTLENTRY operator == ( const char _FAR *cp ) const throw();
    int _RTLENTRY operator == ( const string _FAR &s ) const THROW_NONE;
    int _RTLENTRY operator != ( const char _FAR *cp ) const THROW_NONE;
    int _RTLENTRY operator != ( const string _FAR & str ) const THROW_NONE;

    //
    // Subscripting
    //
    char _RTLENTRY get_at( size_t pos ) const THROW_OUTOFRANGE;
    void _RTLENTRY put_at( size_t pos, char c ) THROW_OUTOFRANGE;

    char _FAR & _RTLENTRY operator[]( size_t pos ) THROW_OUTOFRANGE;
    char _FAR & _RTLENTRY operator()( size_t pos ) throw( string::outofrange );
    char _RTLENTRY operator[]( size_t pos ) const THROW_OUTOFRANGE;
    char _RTLENTRY operator()( size_t pos ) const THROW_OUTOFRANGE;
    size_t _RTLENTRY length() const THROW_NONE;
    int _RTLENTRY start() const THROW_NONE;
    void _RTLENTRY to_lower() throw();
    void _RTLENTRY to_upper() throw();

    //
    // Detecting empty strings
    //
    int _RTLENTRY is_null() const THROW_NONE;
    int _RTLENTRY operator!() const THROW_NONE;

protected:

    void _RTLENTRY assert_element( size_t pos ) const throw( string::outofrange );
    int _RTLENTRY valid_element( size_t pos ) const;

private:

    friend class _EXPCLASS string;

    //
    // Data
    //
    string _FAR *s;
    size_t begin;
    size_t extent;

    //
    // Constructor
    //
    _RTLENTRY TSubString( const string _FAR *cp, size_t start, size_t len );

};

#if defined( BI_OLDNAMES )
#define BI_SubString TSubString
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  string inlines                                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

inline _RTLENTRY string::outofrange::outofrange() :
    xmsg( "String reference out of range" )
{
}

inline _RTLENTRY string::lengtherror::lengtherror() :
    xmsg( "String length error" )
{
}

inline string _FAR & _RTLENTRY string::operator = ( const string _FAR &s )
    THROW_NONE
{
    return assign( s, 0, NPOS );
}

inline string _FAR & _RTLENTRY string::assign( const string _FAR &s )
    THROW_NONE
{
    return assign( s, 0, NPOS );
}

inline string _FAR & _RTLENTRY string::operator += ( const string _FAR &s )
    THROW_XALLOC_LENGTHERROR
{
    return append( s, 0, NPOS );
}

inline string _FAR & _RTLENTRY string::append( const string _FAR &s )
    THROW_XALLOC_LENGTHERROR
{
    return append(s, 0, NPOS);
}

inline string _FAR & _RTLENTRY string::prepend( const char _FAR *cp )
    THROW_XALLOC_LENGTHERROR
{
    return prepend( cp, 0, strlen(cp) );
}

inline int _RTLENTRY operator == ( const string _FAR &s1, const string _FAR &s2 )
    THROW_NONE
{
    return s1.compare( s2 ) == 0;
}

inline int _RTLENTRY operator != ( const string _FAR &s1, const string _FAR &s2 )
    THROW_NONE
{
    return !(s1==s2);
}

inline string _FAR & _RTLENTRY string::remove( size_t pos )
    THROW_XALLOC_OUTOFRANGE
{
    return remove( pos, length() );
}

inline string _FAR & _RTLENTRY string::replace( size_t pos,
                                     size_t n,
                                     const string _FAR &s )
    THROW_XALLOC_RANGE_LENGTH
{
    return replace( pos, n, s, 0, NPOS );
}

inline char _RTLENTRY string::get_at( size_t pos ) const THROW_OUTOFRANGE
{
    return (*this)[pos];
}

inline void _RTLENTRY string::put_at( size_t pos, char c ) THROW_OUTOFRANGE
{
    (*this)[pos] = c;
}

inline char _FAR & _RTLENTRY string::operator[]( size_t pos ) THROW_OUTOFRANGE
{
    return (*this)(pos);    // use operator()
}

inline TSubString _RTLENTRY string::operator()( size_t start, size_t len ) THROW_NONE
{
    return TSubString( this, start, len );
}

inline size_t _RTLENTRY string::find( const string _FAR &s ) const THROW_NONE
{
    return find( s, 0 );
}

inline size_t _RTLENTRY string::rfind( const string _FAR &s ) const THROW_NONE
{
    return rfind( s, length() );
}

inline size_t _RTLENTRY string::length() const THROW_NONE
{
    return p->nchars;
}

inline const char _FAR * _RTLENTRY string::c_str() const THROW_NONE
{
    return p->array;
}

inline size_t _RTLENTRY string::reserve() const THROW_NONE
{
    return p->capacity;
}

inline void _RTLENTRY string::cow()
{
    if( p->References() > 1 )
        clone();
}

inline string _FAR & _RTLENTRY string::operator += ( const char _FAR *cp )
    THROW_XALLOC_LENGTHERROR
{
    return append( cp, 0, strlen(cp) );
}

inline string _FAR & _RTLENTRY string::prepend( const string _FAR &s )
    THROW_XALLOC_LENGTHERROR
{
    return prepend( s.c_str() );
}

inline string _FAR & _RTLENTRY string::prepend( const string _FAR &s,
                                                size_t orig,
                                                size_t n ) THROW_XALLOC_LENGTHERROR
{
    return prepend( s.c_str(), orig, n );
}

inline int _RTLENTRY operator == ( const string _FAR &s1, const char _FAR *s2 ) THROW_NONE
{
    return s1.compare(s2) == 0;
}

inline int _RTLENTRY operator == ( const char _FAR *cp, const string _FAR &s ) THROW_NONE
{
    return string(cp).compare(s) == 0;
}

inline int _RTLENTRY operator != ( const string _FAR &s, const char _FAR *cp ) THROW_NONE
{
    return !(s==cp);
}

inline int _RTLENTRY operator != ( const char _FAR *cp, const string _FAR &s ) THROW_NONE
{
    return !(cp==s);
}

inline int _RTLENTRY operator <  ( const string _FAR &s1, const string _FAR &s2 )
    THROW_NONE
{
    return s1.compare(s2) < 0;
}

inline int _RTLENTRY operator <  ( const string _FAR &s1, const char _FAR *s2 ) THROW_NONE
{
    return s1.compare(s2) < 0;
}

inline int _RTLENTRY operator <  ( const char _FAR *cp, const string _FAR &s ) THROW_NONE
{
    return string(cp).compare(s) < 0;
}

inline int _RTLENTRY operator <= ( const string _FAR &s1, const string _FAR &s2 )
    THROW_NONE
{
    return s1.compare(s2) <= 0;
}

inline int _RTLENTRY operator <= ( const string _FAR &s, const char _FAR *cp ) THROW_NONE
{
    return s.compare(string(cp)) <= 0;
}

inline int _RTLENTRY operator <= ( const char _FAR *cp, const string _FAR &s ) THROW_NONE
{
    return string(cp).compare(s) <= 0;
}

inline int _RTLENTRY operator >  ( const string _FAR &s1, const string _FAR &s2 )
    THROW_NONE
{
    return s1.compare(s2) > 0;
}

inline int _RTLENTRY operator >  ( const string _FAR &s, const char _FAR *cp ) THROW_NONE
{
    return s.compare(cp) > 0;
}

inline int _RTLENTRY operator >  ( const char _FAR *cp, const string _FAR &s ) THROW_NONE
{
    return string(cp).compare(s) > 0;
}

inline int _RTLENTRY operator >= ( const string _FAR &s1, const string _FAR &s2 )
    THROW_NONE
{
    return s1.compare(s2) >= 0;
}

inline int _RTLENTRY operator >= ( const string _FAR &s, const char _FAR *cp ) THROW_NONE
{
    return s.compare(cp) >= 0;
}

inline int _RTLENTRY operator >= ( const char _FAR *cp, const string _FAR &s ) THROW_NONE
{
    return string(cp).compare(s) >= 0;
}

inline char _RTLENTRY string::operator[]( size_t pos ) const THROW_OUTOFRANGE
{
    assert_element(pos);
    return p->array[pos];
}

inline char _RTLENTRY string::operator()( size_t pos ) const THROW_OUTOFRANGE
{
#if defined( BOUNDS_CHECK )
    assert_element(pos);
#endif
    return p->array[pos];
}

inline int _RTLENTRY string::contains( const string _FAR &s ) const THROW_NONE
{
    return contains( s.c_str() );
}

inline TSubString _RTLENTRY string::substring( const char _FAR *cp ) THROW_NONE
{
    return substring( cp, 0 );
}

inline const TSubString _RTLENTRY string::substring( const char _FAR *cp ) const
    THROW_NONE
{
    return substring( cp, 0 );
}

inline size_t _RTLENTRY string::find_first_of( const string _FAR &s ) const THROW_NONE
{
    return find_first_of( s, 0 );
}

inline size_t _RTLENTRY string::find_first_not_of( const string _FAR &s ) const THROW_NONE
{
    return find_first_not_of( s, 0 );
}

inline size_t _RTLENTRY string::find_last_of( const string _FAR &s ) const THROW_NONE
{
    return find_last_of( s, NPOS );
}

inline size_t _RTLENTRY string::find_last_not_of( const string _FAR &s ) const THROW_NONE
{
    return find_last_not_of( s, NPOS );
}

inline int _RTLENTRY string::get_case_sensitive_flag()
{
    return case_sensitive;
}

inline int _RTLENTRY string::get_paranoid_check_flag()
{
    return paranoid_check;
}

inline int _RTLENTRY string::get_skip_whitespace_flag()
{
    return skip_white;
}

inline size_t _RTLENTRY string::get_initial_capacity()
{
    return initial_capac;
}

inline size_t _RTLENTRY string::get_resize_increment()
{
    return resize_inc;
}

inline size_t _RTLENTRY string::get_max_waste()
{
    return freeboard;
}

inline int _RTLENTRY string::is_null() const
{
    return *p->array==0;
}

#if defined( _Windows )
inline void _RTLENTRY string::ansi_to_oem() THROW_NONE
{
    ::AnsiToOem( p->array, p->array );
}

inline void _RTLENTRY string::oem_to_ansi() THROW_NONE
{
    ::OemToAnsi( p->array, p->array );
}
#endif

// Check to make sure a string index refers to a valid element
inline int _RTLENTRY string::valid_element( size_t n ) const THROW_NONE
{
    return n < length();
}

// Check to make sure a string index is in range
inline int _RTLENTRY string::valid_index( size_t n ) const THROW_NONE
{
    return n <= length();
}

// Constructor for internal use only
inline _RTLENTRY string::string( const string _FAR &s, const char _FAR *cp )
{
    p = new TStringRef( s.c_str(), s.length(), cp, cp?strlen(cp):0, 0 );
}

inline string _RTLENTRY operator + ( const string _FAR &s,
                                  const char _FAR *cp )
    THROW_XALLOC_LENGTHERROR
{
    return string(s,cp);
}

inline string _RTLENTRY operator + ( const string _FAR &s1,
                                  const string _FAR &s2 )
    THROW_XALLOC_LENGTHERROR
{
    return s1 + s2.c_str();
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TSubString inlines                                                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

inline int _RTLENTRY TSubString::operator == ( const string _FAR &s ) const THROW_NONE
{
    return operator==(s.c_str());
}

inline int _RTLENTRY TSubString::operator != ( const char _FAR *cp ) const THROW_NONE
{
    return !operator==(cp);
}

inline int _RTLENTRY TSubString::operator != ( const string _FAR &s ) const THROW_NONE
{
    return !operator==(s.c_str());
}

inline char _RTLENTRY TSubString::get_at( size_t pos ) const THROW_OUTOFRANGE
{
    return (*this)[pos];
}

inline void _RTLENTRY TSubString::put_at( size_t pos, char c ) THROW_OUTOFRANGE
{
    (*this)[pos] = c;
}

inline char _FAR & _RTLENTRY TSubString::operator[]( size_t pos ) THROW_OUTOFRANGE
{
    return (*this)(pos);    // use operator()
}

inline char _RTLENTRY TSubString::operator[]( size_t pos ) const
    THROW_OUTOFRANGE
{
    assert_element(pos);
    return s->p->array[begin+pos];
}

inline char _RTLENTRY TSubString::operator()( size_t pos ) const
    THROW_OUTOFRANGE
{
#if defined( BOUNDS_CHECK )
    assert_element(pos);
#endif
    return s->p->array[begin+pos];
}

inline size_t _RTLENTRY TSubString::length() const THROW_NONE
{
    return extent;
}

inline int _RTLENTRY TSubString::start() const THROW_NONE
{
    return begin;
}

inline int _RTLENTRY TSubString::is_null() const THROW_NONE
{
    return begin == NPOS;
}

inline int _RTLENTRY TSubString::operator!() const THROW_NONE
{
    return begin == NPOS;
}

inline int _RTLENTRY TSubString::valid_element( size_t n ) const THROW_NONE
{
    return n < length();
}

// Private constructor
inline _RTLENTRY TSubString::TSubString(const string _FAR *sp,
                              size_t start,
                              size_t len ) :
    begin(start),
    extent(len),
    s((string _FAR *)sp)
{
}

inline TSubString _RTLENTRY string::operator()( const TRegexp _FAR & r ) THROW_NONE
{
    return (*this)(r,0);
}

inline const TSubString _RTLENTRY string::operator()( const TRegexp _FAR &r ) const THROW_NONE
{
    return (*this)(r,0);
}


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#pragma option -Vo.     // restore user C++ options

#if !defined(__TINY__)
#pragma option -RT.
#endif

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po.     // restore Object data calling convention
#endif
#endif

/* restore default packing */
#pragma pack(pop)

#endif  /* !RC_INVOKED */


#endif  // __CSTRING_H

