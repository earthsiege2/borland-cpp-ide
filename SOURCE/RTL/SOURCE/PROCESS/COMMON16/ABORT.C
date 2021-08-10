/*------------------------------------------------------------------------
 * filename - abort.c
 *
 * function(s)
 *        abort - raise the SIGABRT signal
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdlib.h>
#include <signal.h>
#include <_process.h>

void abort(void)
{
    raise(SIGABRT);
    _abort();       // If handler returns then not handled so default action
}

