/***
*iswctype.c - support isw* wctype functions/macros for wide characters
*
*       Copyright (c) 1991-1993, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines iswctype - support isw* wctype functions/macros for
*       wide characters (esp. > 255).
*
*******************************************************************************/
/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#define _UNICODE
#include <ntbc.h>
#include <ctype.h>
#include <stdio.h>
#include <locale.h>
#include <_locale.h>
#include <tchar.h>
#include <winbase.h>
#include <winnls.h>
#include <winnt.h>


/*
 *  iswctype - support isw* wctype functions/macros.
 *
 *  Purpose:
 *
 *  Entry:
 *       wchar_t c    - the wide character whose type is to be tested
 *       wchar_t mask - the mask used by the isw* functions/macros
 *                       corresponding to each character class property
 *
 *  Exit:
 *       Returns non-zero if c is of the character class.
 *       Returns 0 if c is not of the character class.
 *
 *  Exceptions:
 *       Returns 0 on any error.
 *
 ********************************************************************************/

extern unsigned short _Cdecl _chartype[ 257 ];

int _RTLENTRY _EXPFUNC __iswctype( int c, int type )
{
        wchar_t d;

        if (c == WEOF)
            return 0;

	if ((__locale->isCLocale) && (c < 256))
	    return (_chartype[(short) c + 1] & type);

	GetStringTypeW(CT_CTYPE1, (LPCWSTR)&c, 1, &d);
	return (int)(d & type);
}


