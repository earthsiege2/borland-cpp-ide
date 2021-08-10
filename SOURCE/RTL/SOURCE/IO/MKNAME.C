/*-----------------------------------------------------------------------*
 * filename - mkname.c
 *
 * function(s)
 *        __mkname - builds a file name of the form TMPXXXXX.$$$
 *        __tmpnam - builds a unique file name
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <io.h>
#include <_io.h>
#ifdef _MT
#include <_thread.h>
#endif
#include <_printf.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <_tchar.h>

#ifndef _UNICODE
unsigned short _tmpnum;       /* used by tmpnam.c, tmpfile.c, createmp.c */
#else
extern unsigned short _tmpnum;
#endif

/* "static" template buffer used if caller specifies NULL buffer.
   The multithreaded one is big enough for normal or wide chars.
 */
#ifdef _MT

#define template (_TCHAR *)THREAD_BUF(template,L_tmpnam*sizeof(wchar_t))

#else

static _TCHAR template[L_tmpnam];

#endif


/*---------------------------------------------------------------------*

Name            __tmkname used as __mkname and __wmkname
                __mkname  - builds a file name of the form TMPXXXXX.$$$
                __wmkname - builds a wide file name of the form TMPXXXXX.$$$

Usage           char * __mkname(char *s, char *prefix, unsigned short num);
                wchar_t * __wmkname(wchar_t *s, wchar_t *prefix, unsigned short num);

Prototype in    _stdio.h

Description     __tmkname constructs a file name of the form pfxXXXXX.$$$.
                The prefix can be a string of up to 3 characters; if NULL,
                "TMP" is used.  The XXXXX is the ASCII decimal equivalent
                of the 'num' serial number.  The filename is stored
                at s, or in an internal static buffer if s is NULL.

Return value    A pointer to the constructed filename.

*---------------------------------------------------------------------*/

_TCHAR * __tmkname(_TCHAR *s, _TCHAR *prefix, unsigned short num)
{
    /* If no buffer provided, use internal template buffer.  One
     * such buffer is allocated for each thread.
     */
    if (s == NULL)
        s = template;

    /* A temporary name is build as follows: pfxXXXXX.$$$
     * where pfx is the prefix (up to three characters),
     * and XXXXX is the ASCII decimal equivalent of num.
     */
    _ultot((unsigned long)num, _tcspcpy(s, prefix == NULL ? _TEXT("TMP") : prefix), 10);
    _tcscat(s, _TEXT(".$$$"));
    return (s);
}

/*---------------------------------------------------------------------*

Name            __ttmpnam used as __tmpname and __wtmpnam
                __tmpnam  - builds a unique file name
                __wtmpnam - builds a unique wide file name

Usage           char *__tmpnam(char *s, unsigned short *numP);
                wchar *__wtmpnam(wchar_t *s, unsigned short *numP);

Prototype in    _stdio.h

Description     __ttmpnam generates a temporary filename that does not
                conflict with any existing files.  The name is stored
                in the buffer pointed by s.  If s is null, the name
                is stored in an internal static buffer.  If s is not
                NULL, it must point to a buffer of at least L__tmpnam
                characters (L__tmpnam is defined in stdio.h).  Up to TMP_MAX
                unique filenames can be generated before names will
                be reused.

                The filename generated has the form TMPXXXXX.$$$,
                where XXXXX is the ASCII decimal equivalent of
                the file's "serial number".  NumP points to this
                serial number; this number can be passed to __tmkname
                to reconstruct the filename.

                The function returns when it generates a filename
                that does not exist or cannot be accessed.

Return value    If successful, a pointer to the generated name.
                If a unique filename cannot be generated, NULL is
                returned.

*---------------------------------------------------------------------*/

_TCHAR * __ttmpnam(_TCHAR *s, unsigned short *numP)
{
    do
    {
        if (++(*numP) == 0)
            *numP = 1;
        s = __tmkname(s, NULL, *numP);
    } while (_taccess(s,0) == 0);

    return (s);
}
