/*---------------------------------------------------------------------------
 * filename - is.c
 *
 * function(s)     - replacements for macros in ctype.h
 *    isalnum
 *    isascii
 *    isalpha
 *    iscntrl
 *    isdigit
 *    isgraph
 *    islower
 *    isprint
 *    ispunct
 *    isspace
 *    isupper
 *    isxdigit
 *    iswalnum
 *    iswascii
 *    iswalpha
 *    iswcntrl
 *    iswdigit
 *    iswgraph
 *    iswlower
 *    iswprint
 *    iswpunct
 *    iswspace
 *    iswupper
 *    iswxdigit
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_locale.h>
#include <_tchar.h>
#include <ctype.h>
#include <_ctype.h>

int (_RTLENTRY _EXPFUNC _istalnum)( _TINT c )
{
    return( __isttype( c, _IS_ALNUM ) );
}

int (_RTLENTRY _EXPFUNC _istascii)( _TINT c )
{
    return( _istascii( c ) );
}

int (_RTLENTRY _EXPFUNC _istalpha)( _TINT c )
{
    return( __isttype( c, _IS_ALPHA ) );
}

int (_RTLENTRY _EXPFUNC _istcntrl)( _TINT c )
{
    return( __isttype( c, _IS_CTL ) );
}

int (_RTLENTRY _EXPFUNC _istdigit)( _TINT c )
{
    return( __isttype( c, _IS_DIG ) );
}

int (_RTLENTRY _EXPFUNC _istgraph)( _TINT c )
{
    return( __isttype( c, _IS_GRAPH ) );
}

int (_RTLENTRY _EXPFUNC _istlower)( _TINT c )
{
    return( __isttype( c, _IS_LOW ) );
}

int (_RTLENTRY _EXPFUNC _istprint)( _TINT c )
{
    return( __isttype( c, (_IS_GRAPH | _IS_BLK) ));
}

int (_RTLENTRY _EXPFUNC _istpunct)( _TINT c )
{
    return( __isttype( c, _IS_PUN ) );
}

int (_RTLENTRY _EXPFUNC _istspace)( _TINT c )
{
    return( __isttype( c, _IS_SP ) );
}

int (_RTLENTRY _EXPFUNC _istupper)( _TINT c )
{
    return( __isttype( c, _IS_UPP ) );
}

int (_RTLENTRY _EXPFUNC _istxdigit)( _TINT c )
{
    return( __isttype( c, _IS_HEX ) );
}
