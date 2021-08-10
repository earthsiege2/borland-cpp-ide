/*------------------------------------------------------------------------
 * filename - atexit.c
 *
 * function(s)
 *        atexit - registers termination function
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdlib.h>
#include <stdio.h>
#include <_stdio.h>

/* WARNING: if you change MAX_ATEXIT here, be sure change it in exit.c!
 */
#define MAX_ATEXIT      32

extern int      _atexitcnt;         /* count of atexit functions */
extern atexit_t _atexittbl[MAX_ATEXIT]; /* array of atexit function pointers */


/*-------------------------------------------------------------------------*

Name            atexit - registers termination function

Usage           #include <stdlib.h>
                int atexit(atexit_t func);

Prototype in    stdlib.h

Description     atexit registers provided to by func as an "exit function".
                Upon normal  termination of the  program, exit calls  *func
                (without  args)  just  before  returning  to  the operating
                system.

                Each call to atexit registers  another exit function; up to
                32  functions can  be registered  and they  are executed on
                last in, first out basis.

Return value    atexit returns 0 on success and non-zero on failure(no space
                left to register the function)

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC atexit(atexit_t func)
{
    _lock_exit();
    if (_atexitcnt == MAX_ATEXIT)
    {
        _unlock_exit();
        return(1);
    }
    _atexittbl[_atexitcnt++] = func;
    _unlock_exit();
    return(0);
}
