/*-----------------------------------------------------------------------*
 * filename - mktemp.c
 *
 * function(s)
 *        mktemp - makes a unique file name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <_io.h>
#include <_process.h>

#pragma intrinsic -strcmp       /* don't use the unsafe version */

/*---------------------------------------------------------------------*

Name            mktemp - makes a unique file name

Usage           char *mktemp(char *template);

Prototype in    dir.h

Description     mktemp replaces template by a unique file name
                and returns the address of template.

                The template should be a null-terminated string
                with six trailing X's. These X's are replaced with a unique
                collection of letters plus a dot, so that there are two letters,
                a dot, and three suffix letters in the new file name.

                The first letter is variable: it can be '0' or 'a' to 'z'.
                The remaining four letters are replaced with an ASCII
                base-32 represention of the process ID.  The function
                runs through all possible values for the first letter until
                it finds a name that doesn't correspond to an existing file.

Return value    If template is well-formed, mktemp returns the
                address of the template string. Otherwise, it does not create
                or open the file.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC mktemp(char *temp)
{
    register char   *cp;
    int     len;
    int     i, c;
    int     pid;

    /* Verify that the template is of the proper form.
     * Point cp at the start of the XXXXXX.
     */
    len = strlen(temp);
    if (len < 6)
        return(0);
    cp = temp + len - 6;
    if (strcmp(cp, "XXXXXX") != 0)
        return(0);
    
    /* The XXXXXX is converted to the following format:
     *      dpp.pp
     * Where pppp is the low 20 bits of the process ID in mangled form
     * (ASCII base 32, backwards), and d is '0' or a lower-case letter.
     */
    pid = _getpid();
    cp[2] = '.';
    for (i = 1; i < 6; i++)
    {
        if (i == 2)         /* skip the '.' */
            i = 3;
        c = pid & 0x1f;     /* convert low 5 bits to ASCII */
        cp[i] = c + (c < 10 ? '0' : 'a' - 10);
        pid >>= 5;          /* shift to get next 5 bits */
    }

    /* Try varying the first "letter", starting with '0', then
     * using the lowercase letters, until we find a file that doesn't
     * exist, or exhaust all the letters.
     */
    for (i = 'a'-1; i <= 'z'; i++)
    {
        cp[0] = i == 'a'-1 ? '0' : i;
        if (__access(temp, 0) == -1)
            return(temp);
    }
    return (NULL);
}
