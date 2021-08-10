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

#if defined( _RTLDLL )
#pragma option -zC_TEXTA
#endif

#ifdef _Windows
#include <windows.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <_string.h>
#include <rtldata.h>
#include <_ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*
*
* _setstrcoll()
*
*---------------------------------------------------------------------*/

void _CType _FARFUNC _setstrcoll
(
    int _CType _FARFUNC (*pcollate) ( const char _FAR *, const char _FAR * )
)

{

    int _CType _FARFUNC (*pcollatefunc) ( const char _FAR *, const char _FAR * );
	_QRTLDataBlock;

    /* if NULL reset original function */
    if ( pcollate == NULL )
    {
        /* if 'C' locale */
        if ( strcmp(
            _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName,
            C_LOCALE_SHORT_STR ) == 0 )

            pcollatefunc = strcmp;
	    else
            pcollatefunc = _strcoll;

	}
    else
    {
         pcollatefunc = pcollate;
    }

     /* set collation functions */
     _QRTLInstanceData(_pLocale)->pcollate = pcollatefunc;

}
