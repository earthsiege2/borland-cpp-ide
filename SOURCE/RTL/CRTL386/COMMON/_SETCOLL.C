/*
*
*	_SETCOLL.C
*
*	set/change the collation function strcoll()
*
*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __OS2__

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <_string.h>
#include <_ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*
*
* _setstrcoll()
*
*---------------------------------------------------------------------*/

void _RTLENTRYF _EXPFUNC _setstrcoll
(
    int _RTLENTRYF _EXPFUNC (*pcollate) ( const char *, const char * )
)

{

    int _RTLENTRYF _EXPFUNC (*pcollatefunc) ( const char *, const char * );

    /* if NULL reset original function */
    if ( !pcollate )
    {
        /* if 'C' locale */
        if ( strcmp(
            _pLocale->CollationCat.Header.CategoryName,
            C_LOCALE_SHORT_STR ) == 0 )

            pcollatefunc = strcmp;
	    else
            pcollatefunc = _strcoll;

	}
    else
    {
         pcollatefunc = pcollate;
    }

    /* lock global locale */
    _lock_locale();

     /* set collation functions */
    _pLocale->pcollate = pcollatefunc;

    /* unlock before leaving */
    _unlock_locale();

}

#endif

