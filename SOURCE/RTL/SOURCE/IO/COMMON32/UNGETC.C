/*-----------------------------------------------------------------------*
 * filename - ungetc.c
 *
 * function(s)
 *        ungetc - pushes a character back into input stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_stdio.h>

#undef  ungetc                /* remove macro version */

/*---------------------------------------------------------------------*

Name            ungetc - pushes a character back into input stream

Usage           #include <stdio.h>
                int ungetc(int c, FILE *stream);

Prototype in    stdio.h

Description     pushes the character c back onto the named input stream.
                This character will be returned on the next call to getc
                or fread for that stream.  One character may be pushed
                back in all situations.  A second call to ungetc without
                a call to getc will force the previous character to be
                forgotten.  fseek erases all memory of a pushed-back
                character.

Return value    returns the character c if it is successful.  A value of
                EOF indicates an error.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC ungetc( int c, FILE *fp )
{
    _lock_stream(fp);

    if( c != EOF && fp->level >= 0)
    {
        fp->flags &= ~_F_EOF;                   /* clear EOF flag */

        if( ++(fp->level) > 1 )                
            --fp->curp;                         /* store in file buffer */
        else
            fp->curp = &fp->hold;               /* buf was empty, use hold */
        *fp->curp = c;
    }
    else
        c = EOF;            /* file not in input mode or EOF pushed back */

    _unlock_stream(fp);
    return (c);
}
