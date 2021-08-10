/*------------------------------------------------------------------------
 * filename - abort.c
 *
 * function(s)
 *        abort - raise the SIGABRT signal
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
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

