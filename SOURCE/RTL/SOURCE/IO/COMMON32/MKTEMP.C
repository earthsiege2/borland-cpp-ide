/*-----------------------------------------------------------------------*
 * filename - mktemp.c
 *
 * function(s)
 *        _mktemp - makes a unique file name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */

#include <string.h>
#include <io.h>
#include <_io.h>
#include <_process.h>
#include <_tchar.h>

#pragma intrinsic -strcmp       /* don't use the unsafe version */

/*---------------------------------------------------------------------*

Name            _tmktemp used as _mktemp and _wmktemp
                _mktemp   - makes a unique file name
                _wmktemp - makes a unique file name

Usage           char *_mktemp(char *template);
                wchar_t *_wmktemp(wchar_t *template);

Prototype in    dir.h

Description     _tmktemp replaces template by a unique file name
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

Return value    If template is well-formed, _tmktemp returns the
                address of the template string. Otherwise, it does not create
                or open the file.

*---------------------------------------------------------------------*/

_TCHAR * _RTLENTRY _EXPFUNC _tmktemp(_TCHAR *temp)
{
    register _TCHAR   *cp;
    int     len;
    int     i, c;
    int     pid;

    /* Verify that the template is of the proper form.
     * Point cp at the start of the XXXXXX.
     */
    len = _tcslen(temp);
    if (len < 6)
        return(0);
    cp = temp + len - 6;
    if (_tcscmp(cp, _TEXT("XXXXXX")) != 0)
        return(0);

    /* The XXXXXX is converted to the following format:
     *      dpp.pp
     * Where pppp is the low 20 bits of the process ID in mangled form
     * (ASCII base 32, backwards), and d is '0' or a lower-case letter.
     */
    pid = _getpid();
    cp[2] = _TEXT('.');
    for (i = 1; i < 6; i++)
    {
        if (i == 2)         /* skip the '.' */
            i = 3;
        c = pid & 0x1f;     /* convert low 5 bits to ASCII */
        cp[i] = c + (c < 10 ? _TEXT('0') : _TEXT('a') - 10);
        pid >>= 5;          /* shift to get next 5 bits */
    }

    /* Try varying the first "letter", starting with '0', then
     * using the lowercase letters, until we find a file that doesn't
     * exist, or exhaust all the letters.
     */
    for (i = _TEXT('a')-1; i <= (_TEXT('z')); i++)
    {
        cp[0] = i == _TEXT('a')-1 ? '0' : i;
        if (_taccess(temp, 0) == -1)
            return(temp);
    }
    return (NULL);
}
