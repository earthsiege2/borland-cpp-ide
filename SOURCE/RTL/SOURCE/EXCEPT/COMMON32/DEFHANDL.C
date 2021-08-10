/*-----------------------------------------------------------------------*
 * filename - defhandl.c
 *
 * function(s)
 *    __DefHandler - default RTL Exception handler.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#ifdef __OS2__
#include <os2bc.h>
#else
#define INCL_USER
#include <ntbc.h>
#endif

/*---------------------------------------------------------------------*

Name            __DefHandler - default Exception handler

Usage           ULONG __EHCC __DefHandler(
                             PEXCEPTIONREPORTRECORD p,
                             PEXCEPTIONREGISTRATIONRECORD q,
                             PCONTEXTRECORD r,
                             PVOID s);

Description     This function is called indirectly by the RTL's internal
                exception handler if signal() is not used.  Its parameters
                are the normal exception handling parameters.
                The function performs no action except to return a code
                indicating that the exception was not handled.

Return value    The function returns XCPT_CONTINUE_SEARCH.

*---------------------------------------------------------------------*/
#pragma argsused
ULONG __EHCC __DefHandler(PEXCEPTIONREPORTRECORD p,
                          PEXCEPTIONREGISTRATIONRECORD q,
                          PCONTEXTRECORD r,
                          PVOID s)
{
#if defined(__OS2__)
    #define CPP_EXCEPT_CODE 0x0EEFFACE
    extern void __call_terminate(void);
    
    if (p->ExceptionNum == CPP_EXCEPT_CODE)
        __call_terminate();
#endif
    return (XCPT_CONTINUE_SEARCH);
}
