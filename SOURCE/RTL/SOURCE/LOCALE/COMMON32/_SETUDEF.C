/*
*
*	_SETUDEF.C
*
*	set/change a buffer for user defined locale data
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
* _setlocalebuff()
*
* set caller defined buffer address for loading LC_userdef info from
* a locale via setlocale(). A NULL is a valid localebuff pointer but
* will prevent the locale info from being loaded.
*
*---------------------------------------------------------------------*/

void _RTLENTRYF _EXPFUNC _setlocalebuff( void *localebuff )

{
    /* lock global locale */
    _lock_locale();

    _pLocale->UserCat.UserInfo = localebuff;

    /* unlock before leaving */
    _unlock_locale();
}
