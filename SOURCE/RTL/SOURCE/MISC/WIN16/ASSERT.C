/*------------------------------------------------------------------------
 * filename - assert.c
 *
 * function(s)
 *        __assertfail - prints error message and aborts
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <alloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <_win.h>

void _FARFUNC __assertfail( char _FAR *msg, char _FAR *cond, char _FAR *file, int line )
{
    char *errMsg = malloc( strlen( msg ) + strlen( cond )
                           + strlen( file ) + 6 );
    if( errMsg == 0 )
        errMsg = "Assertion failed";
    else
        sprintf( errMsg, msg, cond, file, line );
    _errorBox( errMsg );
    abort();
}

