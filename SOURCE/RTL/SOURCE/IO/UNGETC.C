/*-----------------------------------------------------------------------*
 * filename - ungetc.c
 *
 * function(s)
 *        ungetc - pushes a character back into input stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <stdio.h>
#include <_stdio.h>
#include <_tchar.h>

#undef  ungetc                /* remove macro version */

/*---------------------------------------------------------------------*

Name            _ungettc used as ungetc and ungetwc
                ungetc  - pushes a character back into input stream
                ungetwc - pushes a wide character back into input stream

Usage           #include <stdio.h>
                int ungetc(int c, FILE *stream);
                wint_t ungetwc(wint_t c, FILE *stream);

Prototype in    stdio.h

Description     pushes the character c back onto the named input stream.
                This character will be returned on the next call to getc
                or fread for that stream.  One character may be pushed
                back in all situations.  A second call to ungetc without
                a call to getc may force the previous character to be
                forgotten.  fseek erases all memory of a pushed-back
                character.

Return value    returns the character c if it is successful.  A value of
                EOF indicates an error.

*---------------------------------------------------------------------*/

_TINT _RTLENTRY _EXPFUNC _ungettc( _TINT c, FILE *fp )
{
    _lock_stream(fp);

    if( c != _TEOF && fp->level >= 0)
    {
        fp->flags &= ~_F_EOF;                   /* clear EOF flag */

        /* If we are pointing to hold already, replace hold value */
        if (fp->curp != (unsigned char*)&fp->hold)
        {
            /* We use hold if level was zero, otherwise the buffer */
            if( (fp->level+=sizeof(_TCHAR)) > sizeof(_TCHAR) )
            {
                fp->curp -= sizeof(_TCHAR);     /* store in file buffer */
                if (fp->curp < fp->buffer)      /* Did we fall off the edge */
                {
                  fp->curp += sizeof(_TCHAR);   /* Crawl back */
                  fp->level -= sizeof(_TCHAR);
                }
            }
            else
            {
                fp->curp = (unsigned char*)&fp->hold;/* buf was empty, use hold */
            }
        }
        *(_TCHAR*)(fp->curp) = c;
    }
    else
        c = _TEOF;            /* file not in input mode or EOF pushed back */

    _unlock_stream(fp);
    return (c);
}
