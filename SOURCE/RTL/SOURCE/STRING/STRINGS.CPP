/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STRINGS.CPP                                                           */
/*                                                                        */
/*  Definitions for core string functions                                 */
/*                                                                        */
/*  string::~string();                                                    */
/*  void string::assert_element( size_t pos ) const;                      */
/*  void string::assert_index( size_t pos ) const;                        */
/*  int string::set_case_sensitive( int tf );                             */
/*  int string::set_paranoid_check( int ck );                             */
/*  int string::skip_whitespace( int sk );                                */
/*  size_t string::initial_capacity( size_t ic );                         */
/*  size_t string::resize_increment( size_t ri );                         */
/*  size_t string::max_waste( size_t mw );                                */
/*                                                                        */
/*  void TSubString::assert_index( size_t pos ) const;                    */
/*                                                                        */
/*  TStringRef::TStringRef( const char *str1, size_t count1,              */
/*                          const char *str2, size_t count2,              */
/*                          size_t extra );                               */
/*  TStringRef::~TStringRef();                                            */
/*  void TStringRef::reserve( size_t ic );                                */
/*  void TStringRef::check_freeboard();                                   */
/*  void TStringRef::grow_to( size_t n )                                  */
/*  size_t TStringRef::round_capacity( size_t nc );                       */
/*  void TStringRef::splice( size_t start, size_t extent,                 */
/*                           const char *dat, size_t n );                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

extern xalloc __xalloc;

string::~string() throw()
{
    if( p->RemoveReference() == 0 )
        delete p;
}

void string::assert_element( size_t pos ) const throw( string::outofrange )
{
    if( !valid_element(pos) )
        throw outofrange();
}

void string::assert_index( size_t pos ) const throw( string::outofrange )
{
    if( !valid_index(pos) )
        throw outofrange();
}

void TSubString::assert_element( size_t n ) const throw( string::outofrange )
{
    if( !valid_element(n) )
        throw string::outofrange();
}

TStringRef::TStringRef( const char _FAR *str1,
                        size_t count1,
                        const char _FAR *str2,
                        size_t count2,
                        size_t extra ) : TReference(1), flags(0)
{
    nchars = count1+count2;
    capacity = round_capacity(nchars+extra);
    array = (char _FAR *)malloc(capacity+1);
    if( array == 0 )
        __xalloc.raise();
    memcpy( array, str1, count1 );
    memcpy( array+count1, str2, count2 );
    array[count1+count2] = '\0';
}

TStringRef::~TStringRef() throw()
{
    free(array);
}

void TStringRef::reserve( size_t ic ) throw( xalloc, string::outofrange )
{
    flags |= MemReserved;
    size_t newCapac = round_capacity(ic+1);
    if( capacity - newCapac > string::get_max_waste() )
        {
        array = (char _FAR *)realloc( array, newCapac+1 );
        capacity = newCapac;
        }
}

void TStringRef::check_freeboard() throw()
{
    size_t newCapac = round_capacity(nchars);
    if( capacity - newCapac > string::get_max_waste() )
        {
        array = (char _FAR *)realloc( array, newCapac+1 );
        capacity = newCapac;
        }
}

void TStringRef::grow_to( size_t n )
    throw( xalloc, string::lengtherror )
{
    capacity = n;
    array = (char _FAR *)realloc(array, capacity+1); // NB: realloc() is used
    if( array == 0 )
        __xalloc.raise();
}

size_t TStringRef::round_capacity( size_t nc ) throw()
{
    size_t ic = string::get_initial_capacity();
    size_t rs = string::get_resize_increment();
    return (nc - ic + rs - 1) / rs * rs + ic;
}

void TStringRef::splice( size_t start, size_t extent,
                         const char _FAR *dat, size_t n )
        throw( xalloc, string::lengtherror )
{
    char _FAR *destarray;         // Will point to final destination array

    // Final length:
    size_t tot = nchars + n - extent;
    // Final capacity:
    size_t newCapac = round_capacity(tot);

    // Resize if necessary:
    if( newCapac > capacity)
        {
        grow_to(newCapac);  // Grew
        destarray = array;  // Record what will be the final
                            // destination array
        }
    else if( capacity-newCapac > string::get_max_waste() &&
             (flags & MemReserved) == 0 )
        {
        // Shrunk.  destarray will point to brand new memory
        destarray = (char _FAR *)malloc(newCapac+1);
        if( array == 0 )
            __xalloc.raise();
        if( start )
            memcpy( destarray, array, start ); // Copy beginning of string.
        capacity = newCapac;
        }
    else
        destarray = array;  // string capacity stayed the same.  Reuse old array.

    //
    // Copy the end of the string. This will be necessary if new memory is
    // involved, or if the size of the replacing substring does not match
    // the original extent.
    //
    if( destarray!=array || n!=extent )
        memmove(destarray+start+n, array+start+extent, nchars-start-extent);

    // Copy middle of string:
    if( n )
        {
        if( dat )
            memmove(destarray+start, dat, n);  /* NB: memmove() necessary */
        else
            memset(destarray+start, ' ', n);
        }

    nchars = tot;
    destarray[nchars] = '\0';

    if(destarray != array)
        {
        free(array);
        array = destarray;
        }
}

int       string::case_sensitive    = 1;
int       string::paranoid_check    = 0;
int       string::skip_white        = 1;
size_t    string::initial_capac     = 63;
size_t    string::resize_inc        = 64;
size_t    string::freeboard         = 63;

int string::set_case_sensitive( int tf )
{
    int ret = case_sensitive;
    case_sensitive = tf;
    return ret;
}

int string::set_paranoid_check( int ck )
{
    int ret = paranoid_check;
    paranoid_check = ck;
    return ret;
}

int string::skip_whitespace( int sk )
{
    int ret = skip_white;
    skip_white = sk;
    return ret;
}

size_t string::initial_capacity( size_t ic )
{
    size_t ret = initial_capac;
    initial_capac = ic;
    return ret;
}

size_t string::resize_increment( size_t ri )
{
    size_t ret = resize_inc;
    resize_inc = ri;
    if( resize_inc == 0 )
        resize_inc = 1;
    return ret;
}

size_t string::max_waste( size_t mw )
{
    size_t ret = freeboard;
    freeboard = mw;
    return ret;
}

