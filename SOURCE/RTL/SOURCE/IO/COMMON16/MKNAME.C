/*-----------------------------------------------------------------------*
 * filename - mkname.c
 *
 * function(s)
 *        __mkname - builds a file name of the form TMPXXXXX.$$$
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */


#include <_printf.h>
#include <stdio.h>
#include <string.h>
#include <RtlData.h>

#if !defined( _RTLDLL )
static char    _template[L_tmpnam];
#endif

/*---------------------------------------------------------------------*

Name            __mkname - builds a file name of the form TMPXXXXX.$$$

Usage           char * pascal __mkname(char *s, char *prefix, unsigned num);

Prototype in    _stdio.h

Description     __mkname constructs a file name of the form pfxXXXXX.$$$.
                The prefix can be a string of up to 3 characters; if NULL,
                "TMP" is used.  The XXXXX is the ASCII decimal equivalent
                of the 'num' serial number.  The filename is stored
                at s, or in an internal static buffer if s is NULL.

Return value    A pointer to the constructed filename.

*---------------------------------------------------------------------*/
char * pascal near __mkname(char *s, char *prefix, unsigned num)
{
        /* If no buffer provided, use internal template (static buffer)
         */
        if (s == NULL)
                s = _RTLInstanceData(_template);

        /* A temporary name is build as follows: pfxXXXXX.$$$
         * where pfx is the prefix (up to three characters),
         * and XXXXX is the ASCII decimal equivalent of num.
         */
        __utoa(num, _stpcpy(s, prefix == NULL ? "TMP" : prefix));
        strcat(s, ".$$$");
        return (s);
}
