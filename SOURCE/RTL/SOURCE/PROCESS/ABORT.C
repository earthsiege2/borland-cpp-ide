/*-----------------------------------------------------------------------*
 * filename - abort.c
 *
 * function(s)
 *        abort - abnormally terminate program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

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
