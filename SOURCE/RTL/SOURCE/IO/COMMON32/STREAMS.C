/*-----------------------------------------------------------------------*
 * filename - streams.c
 *
 * function(s)
 *      _init_streams       - initialize file stream table and lock
 *      _lock_all_streams   - lock the global file stream lock
 *      _unlock_all_streams - unlock the global file stream lock
 *      _lock_stream        - lock a file stream
 *      _unlock_stream      - unlock a file stream
 *      _cleanup_stream_locks - free the global file stream lock
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <_thread.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <_stdio.h>

/*----------------------------------------------------------------------
 * Semaphores used to lock access to the file stream table,
 * and to the streams themselves.
 */
#ifdef _MT
static lock_t _stream_lock;         /* global stream lock */
static lock_t *strm_locks;          /* table of per-stream locks */
static int _selffree = 0;           /* used to determine whether
                                       _unlock_stream() should free the
                                       lock or leave it allocated */
#endif

/*---------------------------------------------------------------------*

Name            _init_streams - initialize file stream table and lock

Usage           void _init_streams(void);

Description     This function initializes the file stream table, and
                creates the the global lock that governs access to the
                file stream table and the stream lock table.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _init_streams(void)
{
    int i;

    /* Create the lock used to govern access to the lock table.
     */
    _create_lock(&_stream_lock,"creating global stream lock");

    /* Initialize the stream table.  It is assumed that the handle
     * initialization function has a higher priority and has already
     * set the _openfd[] flags for the standard files.
     */
    for (i = 0; i < 3; i++)
        _streams[i].token = (short) (i + _streams);

    for (i = 3; i < _nfile; i++)
    {
        _streams[i].fd = -1;
        _streams[i].token = (short) (i + _streams);
    }

    if ((_openfd[stdin->fd] & O_DEVICE) == 0)
        stdin->flags &= ~_F_TERM;
    _allocbuf(stdin, NULL, (stdin->flags & _F_TERM) ? _IOLBF : _IOFBF, BUFSIZ);

    if ((_openfd[stdout->fd] & O_DEVICE) == 0)
        stdout->flags &= ~_F_TERM;
    _allocbuf(stdout, NULL, (stdout->flags & _F_TERM) ? _IONBF : _IOFBF, BUFSIZ);
}


/*---------------------------------------------------------------------*

Name            _exit_streams - cleanup file stream table and lock

Usage           void _exit_streams(void);

Description     This function cleans up the file stream table and
                the global lock that governs access to the file stream
                table and the stream lock table.

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _exit_streams(void)
{
#pragma exit _exit_streams 0

    _lock_all_streams();


    if (stdin->flags & _F_BUF)
    {
        fflush (stdin);
        free(stdin->buffer);
        stdin->bsize = 0;       /* Mark this buffer as freed */
        stdin->level = 0;
    }
    if (stdout->flags & _F_BUF)
    {
        fflush (stdout);
        free(stdout->buffer);
        stdout->bsize = 0;      /* Mark this buffer as freed */
        stdout->level = 0;
    }

    _unlock_all_streams();
}

#ifdef _MT

/*---------------------------------------------------------------------*

Name            _lock_all_streams - lock the global file stream lock

Usage           void _lock_all_streams(void);

Prototype in    _stdio.h

Related
functions usage void _unlock_all_streams(void);

Description     This function locks the global lock that governs
                access to the file stream table and the lock table
                in slock.c

Return value    None.

*---------------------------------------------------------------------*/

void _lock_all_streams(void)
{
    _lock(_stream_lock,"locking global stream lock");
}

/*---------------------------------------------------------------------*

Name            _unlock_all_streams - unlock the global file stream lock

Usage           void _unlock_all_streams(void);

Prototype in    _stdio.h

Related
functions usage void _unlock_all_streams(void);

Description     This function unlocks the global lock that governs
                access to the file stream table and the lock table
                in slock.c

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_all_streams(void)
{
    _unlock(_stream_lock,"unlocking global stream lock");
}

/*---------------------------------------------------------------------*

Name            _lock_stream - lock a file stream

Usage           void _lock_stream(FILE *stream);

Prototype in    _io.h

Related
functions usage void _unlock_stream(FILE *stream);

Description     This function locks a file stream to prevent other
                threads from using that stream.  The stream must
                refer to a valid open file, and is not checked.
                A matching _unlock_stream call must be made to
                unlock the stream.  Nested locks can be be performed
                on a single stream, as long as they are matched
                by an equal number of unlock operations.

Return value    None.

*---------------------------------------------------------------------*/

void _lock_stream(FILE *stream)
{
    int index = stream - _streams;

    /* If the lock for this stream has never been created, create it.
     */
    if (strm_locks == NULL || strm_locks[index] == 0)
    {
        _lock_all_streams();

        /* Create the stream lock array.
         */
        if (strm_locks == NULL)
        {
            size_t size;

            size = sizeof(lock_t) * _nfile;
            if ((strm_locks = malloc(size)) == NULL)
                _lock_error("allocating stream lock table");
            memset(strm_locks,0,size);
        }

        /* Create this particular stream lock.
         */
        if (strm_locks[index] == 0)
            _create_lock(&strm_locks[index],"creating stream lock");
        _unlock_all_streams();
    }

    _lock(strm_locks[index],"locking stream");
}


/*---------------------------------------------------------------------*

Name            _cleanup_stream_locks - free the global file stream lock

Usage           void _cleanup_stream_locks(void);

Description     This function frees the global lock that governs
                access to the file stream table.

Notes           This function also sets the _selffree flag to 1.  This
                is in case a dll (like CG32) forces some cleanup calls
                back into the EXE's RTL, and the stream locks are
                needed again.  _lock_stream() will automatically re-
                allocate the lock blocks again, and with this flag set
                _unlock_stream() will also free it.

Return value    None.

*---------------------------------------------------------------------*/

void _cleanup_stream_locks(void)
{
    if (strm_locks)
    {
        free (strm_locks);
        strm_locks = 0;
    }
    _selffree = 1;
}

/*---------------------------------------------------------------------*

Name            _unlock_stream - lock a file stream

Usage           void _unlock_stream(int stream);

Prototype in    _io.h

Related
functions usage void _unlock_stream(int stream);

Description     This function locks a file stream to prevent other
                threads from using that stream.  The stream must
                refer to a valid open file, and is not checked.
                A matching _unlock_stream call must be made to
                unlock the stream.  Nested locks can be be performed
                on a single stream, as long as they are matched
                by an equal number of unlock operations.

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_stream(FILE *stream)
{
    _unlock(strm_locks[stream - _streams],"unlocking stream");
    if (_selffree)
        _cleanup_stream_locks();
}

#endif  /* _MT */
