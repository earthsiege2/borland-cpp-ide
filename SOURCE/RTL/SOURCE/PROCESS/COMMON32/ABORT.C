/*-----------------------------------------------------------------------*
 * filename - abort.c
 *
 * function(s)
 *        abort - abnormally terminate program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

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
