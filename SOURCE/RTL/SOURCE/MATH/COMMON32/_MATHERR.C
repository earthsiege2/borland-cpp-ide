/*------------------------------------------------------------------------
 * filename - _matherr.c
 *
 * function(s)
 *        __matherr - floating-point error handling routine
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

Name            __matherr - floating-point error handling routine

Usage           #include<math.h>
                double   __matherr (_mexcep why,
                                   char    *fun,
                                   double  *arg1p,
                                   double  *arg2p,
                                   double  retval);


Prototype in    math.h

Description     __matherr serves as a focal  point for error handling in all
                math library functions; it  calls matherr and processes the
                return value from matherr.  __matherr should never be called
                directly by user programs.

                Whenever  an  error  occurs  in  one  of  the  math library
                routines __matherr is called with several arguments.

                __matherr does four things :
                        . It  uses its arguments  to fill out  an exception
                          structure.

                        . It  calls   matherr  with  e,  a  pointer  to the
                          exception  structure,  to   see  if  matherr  can
                          resolve the error.

                        . It  examines  the  return  value from  matherr as
                          follows:
                                If matherr  returns 0, (indicating  that it
                                was not able to resolve the error) __matherr
                                sets errno and prints an error message

                                If  matherr  returns  non-zero, (indicating
                                that  it  was  able  to  resolve the error)
                                __matherr is  silent; it does not  set errno
                                or print any messages.

                        . It returns e->retval to the original caller. Note
                          that  matherr might  modify e->retval  to specify
                          the  value  it  wants   propagated  back  to  the
                          original caller.

                When  __matherr  sets  errno  (based  on  a  0  return  from
                matherr), it maps the kind of error that occurred (from the
                type field in the exception  structure) onto an errno value
                of either EDOM or ERANGE.

Return value    __matherr returns the value, e->retval.

*-------------------------------------------------------------------------*/

double _RTLENTRY _EXPFUNC
__matherr(_mexcep why, char *fun, double *arg1p, double *arg2p, double  retval)
{
    struct exception e;

    e.type = why;
    e.name = fun;
    e.arg1 = (NULL == arg1p) ? 0.0 : *arg1p;
    e.arg2 = (NULL == arg2p) ? 0.0 : *arg2p;
    e.retval = retval;

    if (_pmatherr (& e) == 0)
    {
        char errMsg[ 80 ];

#ifdef UNIX_matherr
        sprintf (errMsg, "%s (%8g,%8g): %s",
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
    return e.retval;
}
