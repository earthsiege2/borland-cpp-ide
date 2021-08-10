/*
*
*	_SETUDEF.C
*
*	set/change a buffer for user defined locale data
*
*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

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
* _setlocalebuff()
*
* set caller defined buffer address for loading LC_userdef info from
* a locale via setlocale(). A NULL is a valid localebuff pointer but
* will prevent the locale info from being loaded.
*
*---------------------------------------------------------------------*/

void _CType _FARFUNC _setlocalebuff( void _FAR *localebuff )

{
	_QRTLDataBlock;

    _QRTLInstanceData(_pLocale)->UserCat.UserInfo = localebuff;
}
