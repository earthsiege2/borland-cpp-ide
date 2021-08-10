/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

///////////////////////////////////////////////////////////////////////////////
//
// xxut.cpp - contains data and routines for the the C++ unexpected() and
//            terminate() family of routines
//
///////////////////////////////////////////////////////////////////////////////

#include <_defs.h>

#define USE_XX_VARS
#include "xx.h"

// These must be global (not __thread) and exported from the RTLDLL

FPFV _EXPDATA __terminatePTR = 0;
FPFV _EXPDATA __unexpectdPTR = 0;

///////////////////////////////////////////////////////////////////////////////

void _RTLENTRY _EXPFUNC _InitTermAndUnexPtrs(void)
{
    /* This function is called from _ExceptInit (xxv.cpp) which is called
       from the startup code.  Here we set the default addresses of the
       pointers for terminate() and unexpected().  Since these pointers are
       global to the entire process (as opposed to being specific for each
       module), we must make sure we don't overwrite them if they've already
       been set and we are being called from the load of a subsequent DLL.
    */

    if (!__terminatePTR)
        __terminatePTR = OUR_TERMINATE_ADDR;

    if (!__unexpectdPTR)
        __unexpectdPTR = OUR_UNEXPECTD_ADDR;
}

namespace std {

///////////////////////////////////////////////////////////////////////////////
//
//      Called when something's screwed up.
//
void _RTLENTRY _EXPFUNC terminate(void)
{
    if (__terminatePTR != OUR_TERMINATE_ADDR)
    {
        try
        {
            __terminatePTR();
        }
        catch (...)
        {
        }
    }

    abort();
}

PFV _RTLENTRY _EXPFUNC set_terminate(PFV ptr)
{

    PFV old = __terminatePTR;

    if (ptr)
        __terminatePTR = ptr;

    return old;
}


///////////////////////////////////////////////////////////////////////////////
//
//      Called when a function throws an exception it promised not to throw,
//      or when 'throw;' is used and there is nothing to be re-thrown.
//

void _RTLENTRY _EXPFUNC unexpected(void)
{
    // Officially we are done with the exception now.
    // See uncaught_exception.

    __exceptFlags &= ~XF_UNCAUGHT_EXCEPTION;

    if (__unexpectdPTR != OUR_UNEXPECTD_ADDR)
        __unexpectdPTR();

    __call_terminate();
}

PFV _RTLENTRY _EXPFUNC set_unexpected(PFV ptr)
{
    PFV old = __unexpectdPTR;

    if (ptr)
        __unexpectdPTR = ptr;

    return old;
}

} // std namespace
