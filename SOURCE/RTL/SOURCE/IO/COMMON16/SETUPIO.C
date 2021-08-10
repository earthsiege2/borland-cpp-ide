/*-----------------------------------------------------------------------*
 * filename - setupio.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#pragma inline

#include <stdio.h>
#include <_stdio.h>
#include <io.h>
#include <_io.h>

void near _setupio( void )
{
#if !defined( _RTLDLL )

    int i;

    for (i=5; i<_nfile; i++)
        {
        _openfd[i] = 0;
        _streams[i].fd = -1;
        _streams[i].token = (short) (i + _streams);
        }

    if( !isatty( stdin->fd ) )
        stdin->flags &= ~_F_TERM;
    setvbuf( stdin, NULL, (stdin->flags & _F_TERM) ? _IOLBF : _IOFBF, BUFSIZ );
    if( !isatty( stdout->fd ) )
        stdout->flags &= ~_F_TERM;
    setvbuf( stdout, NULL, (stdout->flags & _F_TERM) ? _IONBF : _IOFBF, BUFSIZ );

#endif  // _RTLDLL
}

/* #pragma startup _setupio 2 */

#pragma warn -asm
asm _INIT_      SEGMENT WORD PUBLIC 'INITDATA'
asm         db      0
asm         db      2
asm         dw      offset _setupio
asm         dw      0
asm _INIT_  ENDS
#pragma warn .asm


void near _freeio( void )
{
#if !defined( _RTLDLL )
    if (stdin->flags & _F_BUF)
    {
	fflush(stdin);
    free(stdin->buffer);
	stdin->level = 0;
	stdin->bsize = 0;
    }
    if (stdout->flags & _F_BUF)
    {
	fflush(stdout);
	free(stdout->buffer);
	stdout->level = 0;
	stdout->bsize = 0;
    }

    if (stdprn->flags & _F_BUF)
    {
	fflush(stdprn);
    free(stdprn->buffer);
	stdprn->level = 0;
	stdprn->bsize = 0;
    }
    if (stderr->flags & _F_BUF)
    {
	fflush(stderr);
	free(stderr->buffer);
	stderr->level = 0;
	stderr->bsize = 0;
    }
#endif  // _RTLDLL
}

/* #pragma exit _freeio 2 */

#pragma warn -asm
asm _EXIT_      SEGMENT WORD PUBLIC 'EXITDATA'
asm         db      0
asm         db      2
asm         dw      offset _freeio
asm         dw      0
asm _EXIT_  ENDS
#pragma warn .asm

