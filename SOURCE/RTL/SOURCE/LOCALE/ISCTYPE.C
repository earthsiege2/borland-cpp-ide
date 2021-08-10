/*---------------------------------------------------------------------------
 * filename - isctype.c
 *
 * function(s)
 *    isctype
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

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

    if (__locale->isCLocale || (__locale->ctype == NULL))
        return (_chartype[(short) (c)+1] & type);
    else
        return (__locale->ctype->cType[ c+1 ] & type);
}





