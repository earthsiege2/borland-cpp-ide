/*------------------------------------------------------------------------
 * filename - assertf.c
 *
 * function(s)
 *        __assertfail - (obsolete) prints error message and aborts
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <_io.h>

/* Obsolete interface.  See assert.c for new interface.
 */
void _RTLENTRY _EXPFUNC
__assertfail(char *msg, char *cond, char *file, int line)
{
    char *errMsg = malloc(strlen(msg) + strlen(cond) + strlen(file) + 10);
    if (errMsg == NULL)
        errMsg = "Assertion failed";
    else
        sprintf(errMsg, msg, cond, file, line);
    _ErrorMessage(errMsg);
    abort();
}
