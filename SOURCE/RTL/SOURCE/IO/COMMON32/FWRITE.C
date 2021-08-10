/*-----------------------------------------------------------------------*
 * filename - fwrite.c
 *
 * function(s)
 *        fwrite  - writes data to a stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdio.h>
#include <_stdio.h>

/*---------------------------------------------------------------------*

Name            fwrite - writes data to a stream

Usage           #include <stdio.h>
                size_t fwrite(void *ptr, size_t size, size_t nitems,
                              FILE *stream);

Related
functions usage size_t fread(void *ptr, size_t size, size_t nitems,
                             FILE *stream);

Prototype in    stdio.h

Description     fread reads nitems of data, each of length size
                bytes, from the named input stream into a block pointed to by
                ptr.

                fwrite appends nitems of data, each of length size bytes, to
                the named output stream. The data appended begins at ptr.

                For both functions, the total number of bytes read is (nitems
                * size).

                ptr in the declarations is a pointer to any object.
                size is the size of the object ptr points to. The
                expression sizeof *ptr will produce the proper value.

Return value    On successful completion, each function returns the
                number of items (not bytes) actually read or written. fread
                returns a short count (possibly 0) on end-of-file or error.
                fwrite returns a short count on error.

*---------------------------------------------------------------------*/

size_t _RTLENTRY _EXPFUNC fwrite( const void *ptr, size_t psize, size_t nitems,
                              FILE *fp )
{
    size_t ret;

    if (psize == 0)
        return( nitems );
    else
    {
        _lock_stream(fp);
        ret = __fputn(ptr, psize * nitems, fp) / psize;
        _unlock_stream(fp);
        return (ret);
    }
}
