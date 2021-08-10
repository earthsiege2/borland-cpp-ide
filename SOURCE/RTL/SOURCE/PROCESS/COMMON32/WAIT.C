/*------------------------------------------------------------------------
 * filename - wait.c
 *
 * function(s)
 *        wait - wait for termination of one or more child processes.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <process.h>
#include <_process.h>

/*------------------------------------------------------------------------*

Name            wait -  Halt parent process execution until one or more
                        children terminate.

Usage           int wait(int *stat_loc);

Prototype in    process.h

Description     If stat_loc isn't NULL then:

                    If no child processes exist then the integer
                    pointed to by stat_loc has an undefined value. 
        
                If a child process terminates normally then the
                integer pointed to by stat_loc has the following
                format:

                    Low order byte is set to 0.
                    High order byte is low order byte of the return code from
                        the terminated child.

                If a child process terminates abnormally then the
                integer pointed to by stat_loc has the following
                format:

                    High order byte is set to 0.
                    Low order byte is return-status code from the OS.

Returns         If no child processes exist then -1, with errno set to ECHILD.
                If child died unexpectedly then -1, with errno set to EINTR.
                If child terminated normally then the terminating child's PID.

    
*--------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC wait (int *stat_loc)
{
    return (_cwait(stat_loc, 0, WAIT_CHILD));
}
