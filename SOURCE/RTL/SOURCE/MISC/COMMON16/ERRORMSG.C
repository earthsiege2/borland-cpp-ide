/*-----------------------------------------------------------------------*
 * filename - errormsg.c
 *
 * function(s)
 *        __ErrorMessage - display an error message
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#ifdef _Windows
#include <_win.h>
#else
#include <io.h>
#include <stdio.h>
#include <string.h>
#endif

void __ErrorMessage(const char *msg)
{
#ifdef _Windows
    _errorBox(msg);
#else
    _rtl_write(fileno(stderr), msg, strlen(msg));
#endif
}
