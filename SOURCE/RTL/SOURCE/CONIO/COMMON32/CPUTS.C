/*------------------------------------------------------------------------
 * filename - cputs.c
 *
 * function(s)
 *        cputs - write a string to the console
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <conio.h>
#include <string.h>
#include <_video.h>

/*----------------------------------------------------------------------*

Name            cputs - writes a string to the console

Usage           int cputs(const char *string)

Prototype in    conio.h

Description     writes the null-terminated string string to the console;
                it does not append a newline character.

Return value    the last character printed

*-----------------------------------------------------------------------*/

int cputs(const char * s)
{
        return __cputn(s,strlen(s),0);
}
