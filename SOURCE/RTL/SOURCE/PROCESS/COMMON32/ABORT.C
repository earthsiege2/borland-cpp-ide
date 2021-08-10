/*-----------------------------------------------------------------------*
 * filename - abort.c
 *
 * function(s)
 *        abort - abnormally terminate program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <signal.h>
#include <process.h>
#include <_io.h>

void _abort(void)
{
    _ErrorMessage("Abnormal program termination");
    _exit(3);
}

void _RTLENTRY _EXPFUNC abort(void)
{
    raise(SIGABRT);
    _abort();
}
