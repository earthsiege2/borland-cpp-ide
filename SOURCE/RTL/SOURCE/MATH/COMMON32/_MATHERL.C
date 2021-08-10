/*------------------------------------------------------------------------
 * filename - _matherl.c
 *
 * function(s)
 *        __matherrl - long double floating-point error handling routine
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <_io.h>
#include <_math.h>

/*-------------------------------------------------------------------------*

Name            __matherrl - long double floating-point error handling routine

Usage           #include<math.h>
                long double  __matherrl (_mexcep why,
                                   char    *fun,
                                   long double  *arg1p,
                                   long double  *arg2p,
                                   long double  retval);


Prototype in    math.h

Description     __matherrl serves as a focal  point for error handling in all
                long double math library functions; it  calls _matherrl and
                processes the return value from _matherrl.  __matherrl should
                never be called directly by user programs.

                Whenever  an  error  occurs  in  one  of  the  math library
                routines __matherrl is called with several arguments.

                __matherrl does four things :
                        . It  uses its arguments  to fill out  an exception
                          structure.

                        . It  calls _matherrl  with  e,  a  pointer  to the
                          _exceptionl  structure,  to see if _matherrl can
                          resolve the error.

                        . It  examines  the  return  value from  _matherrl as
                          follows:
                                If _matherrl  returns 0, (indicating  that it
                                was not able to resolve the error) __matherrl
                                sets errno and prints an error message

                                If  _matherrl  returns  non-zero, (indicating
                                that  it  was  able  to  resolve the error)
                                __matherrl is  silent; it does not  set errno
                                or print any messages.

                        . It returns e->retval to the original caller. Note
                          that  _matherrl might  modify e->retval  to specify
                          the  value  it  wants   propagated  back  to  the
                          original caller.

                When  __matherrl sets  errno  (based  on  a  0  return  from
                _matherrl), it maps the kind of error that occurred (from the
                type field in the exception  structure) onto an errno value
                of either EDOM or ERANGE.

Return value    __matherrl returns the value, e->retval.

*-------------------------------------------------------------------------*/

long double _RTLENTRY _EXPFUNC
__matherrl(_mexcep why,
           char    *fun,
           long double     *arg1p,
           long double     *arg2p,
           long double     retval)
{
    struct _exceptionl e;

    e.type = why;
    e.name = fun;
    e.arg1 = (NULL == arg1p) ? 0.0L : *arg1p;
    e.arg2 = (NULL == arg2p) ? 0.0L : *arg2p;
    e.retval = retval;

    if (_pmatherrl (& e) == 0)
    {
        char errMsg[ 80 ];

#ifdef  UNIX__matherrl
        sprintf (errMsg, "%s (%8Lg,%8Lg): %s",
             fun, *arg1p, *arg2p, _mathwhy [why - 1]);
#else
        sprintf (errMsg, "%s: %s error", fun, _mathwhy [why - 1]);
#endif
        switch (why)
        {
        case OVERFLOW:
        case UNDERFLOW:
        case SING:
            errno = ERANGE;
            break;
        default:
            errno = EDOM;
            break;
        }
        _ErrorMessage(errMsg);
    }
    return  e.retval;
}
