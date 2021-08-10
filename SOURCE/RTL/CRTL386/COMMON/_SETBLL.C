/*
*
*	_SETBLL.C
*
*	set/change the filename or pathname to 
*  the locale library
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
#include <string.h>
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

char * _RTLENTRYF _EXPFUNC  _setlocalelib( char *pFname )

{

    /* lock locale library global filename */
    _lock_locale();

	/*
		_find_localelib() changes global _LocaleLibName
		if file is found
	*/

	if ( pFname != NULL )
        if ( __find_localelib( pFname ) == OSFILE_ERROR )
        {
            /* unlock before leaving */
            _unlock_locale();
		   return( NULL );
        }

    /* unlock before leaving */
    _unlock_locale();

	return( _LocaleLibName );
}

#endif
