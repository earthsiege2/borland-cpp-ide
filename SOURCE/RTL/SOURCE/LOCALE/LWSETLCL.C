/*-----------------------------------------------------------------------*
 * filename - lwsetlcl.c
 *
 * function(s)
 *      _lwsetlocale   - set the locale for wide-character  applications
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <_locale.h>

wchar_t * _RTLENTRY _EXPFUNC _lwsetlocale( int category, const wchar_t *locale )
{
    wchar_t *setlocale_result;

    /* first lock the global locale */
    _lock_locale();

    setlocale_result = _setLocale32W( category, locale );

    /* unlock locale before leaving */
    _unlock_locale();

    return( setlocale_result );
}

