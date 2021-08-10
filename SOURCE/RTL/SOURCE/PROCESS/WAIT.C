/*------------------------------------------------------------------------
 * filename - wait.c
 *
 * function(s)
 *        wait - wait for termination of one or more child processes.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <process.h>
#include <_process.h>
#include <errno.h>
#include <windows.h>

/*------------------------------------------------------------------------*

Name            wait -  Halt parent process execution until one or more
                        children terminate.

Usage           int wait(int *stat_loc);

Prototype in    process.h

Description     If stat_loc isn't NULL then:

                    If no child processes exist then the integer
                    pointed to by stat_loc has an undefined value.

                If a child process terminates normally then the
                integer pointed to by stat_loc has the return code from the
                terminated child.

                If a child process terminates abnormally then the
                integer pointed to by stat_loc has the exception # in it.

Returns         If no child processes exist then -1, with errno set to ECHILD.
                If child died unexpectedly then -1, with errno set to EINTR.
                If child terminated normally then the terminating child's PID.


*--------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC wait (int *stat_loc)
{
    int ret;
    int errorcode;

    ret = _cwait(&errorcode, 0, WAIT_CHILD);

    if (ret == -1)
        return ret;

    /* Test for possible exception codes */
    switch (errorcode)
    {
        case STATUS_ACCESS_VIOLATION:
        case STATUS_IN_PAGE_ERROR:
        case STATUS_INVALID_HANDLE:
        case STATUS_NO_MEMORY:
        case STATUS_ILLEGAL_INSTRUCTION:
        case STATUS_NONCONTINUABLE_EXCEPTION:
        case STATUS_INVALID_DISPOSITION:
        case STATUS_ARRAY_BOUNDS_EXCEEDED:
        case STATUS_FLOAT_DENORMAL_OPERAND:
        case STATUS_FLOAT_DIVIDE_BY_ZERO:
        case STATUS_FLOAT_INEXACT_RESULT:
        case STATUS_FLOAT_INVALID_OPERATION:
        case STATUS_FLOAT_OVERFLOW:
        case STATUS_FLOAT_STACK_CHECK:
        case STATUS_FLOAT_UNDERFLOW:
        case STATUS_INTEGER_DIVIDE_BY_ZERO:
        case STATUS_INTEGER_OVERFLOW:
        case STATUS_PRIVILEGED_INSTRUCTION:
        case STATUS_STACK_OVERFLOW:
        case STATUS_CONTROL_C_EXIT:

            ret   = -1;
            errno = EINTR;
    }

    if (stat_loc)
        *stat_loc = errorcode;

    return ret;
}
