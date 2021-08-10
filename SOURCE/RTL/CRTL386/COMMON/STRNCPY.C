/*-----------------------------------------------------------------------*
 * filename - strncpy.c
 *
 * function(s)
 *        strncpy - copy string src to string dest
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>
#include <mem.h>

/*-----------------------------------------------------------------------*

Name            strncpy - copy string src to string dest

Usage           char *strncpy (char *dest, const char *src, size_t maxlen);

Prototype in    string.h

Description     Copy the ASCIIZ string *src to  the buffer *dest. It is the
                callers responsibility  to ensure that  the dest buffer  is
                large enough  to contain the  string, and to  guard against
                supplying NULL arguments.

                The  length of  source copied   will be  trimmed to  maxlen
                bytes,  including  terminator.  If  *src  is  shorter  than
                maxlen, then  the target buffer   is zero filled  up to the
                maxlen.

                If the source needs to be  truncated then the target is NOT
                zero terminated.

Return value    strncpy returns dest.

*------------------------------------------------------------------------*/

#ifdef strncpy
#  undef strncpy
#  define INTRINSIC
#endif

char * _RTLENTRYF _EXPFUNC strncpy(char *dest, const char *src, size_t maxlen)
{
#ifdef INTRINSIC
    return __strncpy__(dest, src, maxlen);
#else
    size_t len;

    len = strlen(src);
    if (len > maxlen)
        memcpy(dest,src,maxlen);
    else
    {
        memcpy(dest,src,len);
        memset(dest+len,0,maxlen-len);
    }
    return (dest);
#endif
}
