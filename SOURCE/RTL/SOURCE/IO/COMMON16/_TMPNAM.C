/*-----------------------------------------------------------------------*
 * filename - _tmpname.c
 *
 * function(s)
 *        __tmpnam - builds a unique file name
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
#include <dos.h>
#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            __tmpnam - builds a unique file name

Usage           char *__tmpnam(char *s,unsigned *numP);

Prototype in    stdio.h

Description     __tmpnam generates a temporary filename that does not
                conflict with any existing files.  The name is stored
                in the buffer pointed by s.  If s is null, the name
                is stored in an internal static buffer.  If s is not
                NULL, it must point to a buffer of at least L__tmpnam
                bytes (L__tmpnam is defined in stdio.h).  Up to TMP_MAX
                unique filenames can be generated before names will
                be reused.

                The filename generated has the form TMPXXXXX.$$$,
                where XXXXX is the ASCII decimal equivalent of
                the file's "serial number".  NumP points to this
                serial number; this number can be passed to __mkname
                to reconstruct the filename.

                The function returns when it generates a filename
                that does not exist or cannot be accessed.

Return value    If successful, a pointer to the generated name.
                If a unique filename cannot be generated, NULL is
                returned.

*---------------------------------------------------------------------*/
char * pascal near __tmpnam(char *s, unsigned *numP)
{
    unsigned attr;

    do
        s = __mkname(s, (char *) NULL, *numP += (*numP == -1U) ? 2 : 1);
    while (_dos_getfileattr(s, &attr) == 0);

    return (s);
}
