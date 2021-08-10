/*
*
*	_SETXFRM.C
*
*	set/change the collation function strxfrm()
*
*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <_string.h>
#include <_ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*
*
* _setstrxfrm()
*
*---------------------------------------------------------------------*/

void _RTLENTRYF _EXPFUNC _setstrxfrm
(
    size_t _RTLENTRYF _EXPFUNC (*ptransform) ( char *, const char *, size_t )
)

{

    size_t _RTLENTRYF _EXPFUNC (*ptransformfunc)
    (
    char *, const char *, size_t
    )
    = ptransform;

    /* if NULL reset original function */
    if ( !ptransform )
    {
        /* if 'C' locale */
        if ( strcmp(
            _pLocale->CollationCat.Header.CategoryName,
            C_LOCALE_SHORT_STR ) == 0 )

            ptransformfunc = strxfrm;
	    else
            ptransformfunc = _strxfrm;

	}

    /* lock global locale */
    _lock_locale();

     /* set collation functions */
    _pLocale->ptransform = ptransformfunc;

    /* unlock before leaving */
    _unlock_locale();
}
