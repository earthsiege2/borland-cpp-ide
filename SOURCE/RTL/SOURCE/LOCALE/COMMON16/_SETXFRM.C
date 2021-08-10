/*
*
*	_SETXFRM.C
*
*	set/change the collation function strxfrm()
*
*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
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
* _setstrxfrm()
*
*---------------------------------------------------------------------*/

void _CType _FARFUNC _setstrxfrm
(
    size_t _CType _FARFUNC (*ptransform) ( char _FAR *, const char _FAR *, size_t )
)

{

    size_t _CType _FARFUNC (*ptransformfunc)
    (
    char _FAR *, const char _FAR *, size_t
    )
    = ptransform;

	_QRTLDataBlock;

    /* if NULL reset original function */
    if ( ptransform == NULL )
    {
        /* if 'C' locale */
        if ( strcmp(
            _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName,
            C_LOCALE_SHORT_STR ) == 0 )

            ptransformfunc = strxfrm;
	    else
            ptransformfunc = _strxfrm;

	}

     /* set collation functions */
    _QRTLInstanceData(_pLocale)->ptransform = ptransformfunc;
}
