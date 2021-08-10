/*---------------------------------------------------------------------------
 * filename - isctype.c
 *
 * function(s)
 *    isctype
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1996, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $        */

#include <ctype.h>
#include <_ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <_locale.h>
#include <tchar.h>
#include <_tchar.h>

extern unsigned short __cdecl _chartype[ 257 ];

int _RTLENTRY _EXPFUNC __isctype( int c, int type )
{
    if ( (unsigned int) c >255 )
        return( 0 );

#if 0
    if (__locale->ctype == NULL)
    {
        SetLastError(ERROR_CATEGORY_NOTOPEN);
        return -1;
    }
#endif
    if (__locale->isCLocale)
        return (_chartype[(short) (c)+1] & type);
    else
        return (__locale->ctype->cType[ c+1 ] & type);
}





