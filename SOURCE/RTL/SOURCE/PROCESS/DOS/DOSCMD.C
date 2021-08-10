/*------------------------------------------------------------------------
 * filename - doscmd.c
 *
 * function(s)
 *        __DOScmd - Prepare Spawn/Exec command line
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_process.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------*

Name            __DOScmd -- Build a DOS command line from argv array

Usage           char * pascal __DOScmd(char *arg0, char *arg1, char **argP);

Prototype in    _process.h

Description     This function allocates  a buffer and fill it  with all the
		argument  strings one  after the  others. The  command line
		starts  with  the  command  length  and  terminates  with a
		carriage return + null charater which are not included in
		the count.

Return value    __DOScmd  returns  a pointer  to  command  string buffer if
		successful, and NULL on error.

*------------------------------------------------------------------------*/
char    * pascal near __DOScmd(char *arg0, char *arg1, char **argP)
{
    int  len;
    char **argv;
    char *buf;
    char *p;

    /* Compute the required allocation size, then allocate the buffer.
     */
    len = 3;                            /* length byte + lead space + terminating null */
    if (arg1 != NULL)
	len += strlen(arg1) + 1;        /* length of second optional arg */

    for (argv = argP; *argv != NULL; argv++)
	len += strlen(*argv) + 1;       /* length of each argument */
    
    if ((buf = malloc(len)) == NULL)
	return (NULL);

    p = buf + 1;
    *p++ = ' ';
    
    /* Concatenate the optional prefix argument.
     */
    if (arg1 != NULL)
    {
	p = _stpcpy(p,arg1);
	*p++ = ' ';
    }

    /* Concatenate the arguments, separated by spaces.
     */
    if (arg0 != NULL)
    {
	for (argv = argP; *argv != NULL; argv++)
	{
	    p = _stpcpy(p,*argv);
	    *p++ = ' ';
	}
    }
    *(p-1) = '\r';              /* command line terminated by a carriage return */
    *p = '\0';                  /* terminated by null character */
    *buf = (char)(p - buf - 2); /* Place length into length byte */

    return (buf);
}


