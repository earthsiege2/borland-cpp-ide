/*
*
*	_SETBLL.C
*
*	set/change the filename or pathname to 
*  the locale library
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
#include <string.h>
#include <rtldata.h>
#include <_ctype.h>
#include <_locale.h>

/*---------------------------------------------------------------------*
*
* _setlocalelib()
*
* find specified locale library and set global _LocaleLibName
* accordingly and return pointer to the name.
* if pFname is NULL return pointer to the current name.
* return NULL pointer if pFname could not be set.
*
*---------------------------------------------------------------------*/

char * _CType _FARFUNC _setlocalelib( char *pFname )

{
	_QRTLDataBlock;

	/*
		__find_localelib() changes global _LocaleLibName
		if file is found
	*/

	if ( pFname != NULL )
		if ( __find_localelib( pFname ) == OSFILE_ERROR )
			return( NULL );

	return( _QRTLInstanceData(_LocaleLibName) );
}
