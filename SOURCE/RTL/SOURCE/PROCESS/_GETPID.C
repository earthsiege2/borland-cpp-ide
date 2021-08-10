/*-----------------------------------------------------------------------*
 * filename - _getpid.c
 *
 * function(s)
 *        getpid - gets the process ID of a program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <ntbc.h>

#include <process.h>

/*-----------------------------------------------------------------------*

Name            getpid - gets the process ID of a program

Usage           unsigned getpid(void);

Prototype in    process.h

Description     A process ID uniquely identifies a program. The concept
                is borrowed from multitasking operating systems like UNIX,
                where each process is associated with a unique process
                number.

                Note: this function is named _getpid for use within
                the library.  The user-visible entry point is getpid,
                and is found in getpid.asm.

Return value    if success it returns the value of process ID. 
                Otherwise it returns -1.
*------------------------------------------------------------------------*/

int _RTLENTRY _getpid(void)
{
    return (int)GetCurrentProcessId();
}
