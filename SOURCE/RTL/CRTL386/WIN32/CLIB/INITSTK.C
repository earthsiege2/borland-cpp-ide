/*-----------------------------------------------------------------------*
 * filename - initstk.c
 *
 * function(s)
 *      _initstk     - initialize stack at startup
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_defs.h>

extern int _stkchk;

/*---------------------------------------------------------------------*

Name            _initstk - initialize stack at startup

Usage           void _initstk(void);

Description     This function is called at startup time if stack
                checking is enabled (see chkstk.asm).  It merely
                sets a flag that causes the exception handler
                to print a message and exit if a stack overflow
                exception occurs.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _initstk(void)
{
    /* Set flag to let exception handler in startup.c know that
     * stack overflow checking is enabled.  We don't need to fill
     * the stack with guard pages, because NT does that automatically.
     */
    _stkchk = 1;
}
