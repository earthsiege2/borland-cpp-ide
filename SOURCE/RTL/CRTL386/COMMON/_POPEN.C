/*-----------------------------------------------------------------------*
 * filename - _popen.c
 *
 * function(s)
 *        _popen    - create a pipe and executes a command
 *        _pclose   - wait for child command and close a pipe
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>
#include <errno.h>
#include <_process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------*

Name            _popen - create a pipe and executes a command

Usage           #include <process.h>
                FILE *_popen(char *command, char *mode);

Prototype in    stdio.h

Description     _popen creates a pipe and executes asynchronously a child
                copy of the command processor with the passed parameter
                string command. The mode parameter specifies the requested
                access.

                The mode parameter can take the following values:

                "rt"  - Read child command's standard output (text)
                "rb"  - Read child command's standard output (binary)
                "wt"  - Write to child command's standard input (text)
                "wb"  - Write to child command's standard input (binary)

                The terminating "t" or "b" is optional; if missing,
                the default translation mode (_fmode) is used.
                
Return value    On successful completion, _popen returns pointer to
                a FILE. Otherwise it returns NULL.

*------------------------------------------------------------------------*/

#define  STDOUT 1
#define  STDIN  0

FILE * _RTLENTRY _EXPFUNC _popen (const char *command, const char *mode)
{
    int stdfile, oldstdio, parentpipe, childpipe, textmode, pid, usepath;
    int hpipe[2];
    char *argv[4];
    char *comspec;

    /* Set up file handle numbers depending on whether this is a read or write.
     */
    if (mode[0] == 'w')
    {
        stdfile = STDIN;
        parentpipe = 1;
        childpipe = 0;
    }
    else if (mode[0] == 'r')
    {
        stdfile = STDOUT;
        parentpipe = 0;
        childpipe = 1;
    }
    else
        return NULL;

    /* Determine whether to open the pipe in text or binary mode.
     * If the mode string contains a 'b', use binary.  If it contains
     * a 't', use text.  If it contains neither, use _fmode.
     */
    if (strchr(mode,'b') != NULL)
        textmode = O_BINARY;
    else if (strchr(mode,'t') != NULL)
        textmode = O_TEXT;
    else
        textmode = _FMODE & (O_TEXT | O_BINARY);

    /* On NT, don't allow the handles to be inherited.  Instead,
     * only the duplicated stdin/out handle will be inherited.
     * We have to set the no-inheritance flag when the pipe is opened
     * because there's no way to do afterwards, as on OS/2.
     */
#ifdef __WIN32__
    textmode |= O_NOINHERIT;
#endif

    /* Create the pipe.
     */
    if (_pipe( hpipe, 512, textmode) == -1)
        return NULL;

    /* Save the standard output/input file that we're going to change later.
     */
    if ((oldstdio = __dup(stdfile)) == -1)
        goto error;

    /* Map the child's end of the pipe onto the appropriate standard
     * input/output handle.
     */
    if (__dup2(hpipe[childpipe], stdfile) == -1)
        goto error;

    /* Close the end of the pipe we don't need, and set the other
     * end so that it won't be inherited by the child process.
     * Also set the saved stdio handle so that it won't be inherited.
     */
    __close(hpipe[childpipe]);
#ifdef __OS2__
    _noinherit(hpipe[parentpipe]);
    _noinherit(oldstdio);
#endif

    /* Get the name of the command processor from COMSPEC environment
     * variable.  If not defined, search the path for cmd.exe.
     */
    if ((comspec = getenv("COMSPEC")) == NULL)
    {
        comspec = "cmd.exe";
        usepath = 1;
    }
    else
        usepath = 0;

    /* Start the command processor as an asynchronous child process.
     * Save its process ID so that _pclose can wait for its completion.
     */
    argv[0] = comspec;
    argv[1] = "/c";
    argv[2] = (char *)command;
    argv[3] = NULL;
    if ((pid = _LoadProg(P_NOWAIT, comspec, (const char * const *)argv,
                         NULL, usepath)) == -1)
        goto error;

    /* Restore the standard I/O file we temporarily changed, then
     * convert the parent's end of the pipe to a file stream.
     */
    if (__dup2(oldstdio, stdfile) == -1)
        goto error;
    __close(oldstdio);
    _pidtab[hpipe[parentpipe]] = pid;
    return (fdopen(hpipe[parentpipe], (char *)mode));

    /* Come here for error handling.  Close both pipe handles, and
     * restore the standard input/output handle to its original state.
     * Some of these operations might fail, but no harm is done.
     */
error:
    __close(hpipe[0]);
    __close(hpipe[1]);
    if (oldstdio != -1)
    {
        __dup2(oldstdio, stdfile);
        __close(oldstdio);
    }
    return (NULL);
}

/*-----------------------------------------------------------------------*

Name            _pclose - wait for child command and close a pipe

Usage           #include <process.h>
                int _pclose(FILE * stream);

Prototype in    stdio.h

Description     _pclose closes a pipe stream created by a previous call
                to _popen.  It closes the pipe stream and waits for the
                child command to complete.
                
Return value    If successful, _pclose returns the termination status of
                the child command.  This is the same value as the
                termination status returned by cwait(), except that
                the high and low order bytes of the low word are swapped.
                If _pclose is unsuccessful, it returns -1.

*------------------------------------------------------------------------*/

int _pclose (FILE *stream)
{
    int         fd, pid, termstat;

    /* Get the process ID associated with this pipe.
     */
    if ((unsigned)(fd = (int)stream->fd) >= _nfile)
        return __IOerror(-EBADF);
    if ((pid = _pidtab[fd]) == 0)
        return __IOerror(-EBADF);

    /* Close the pipe and file stream, and zero the pid in the table.
     */
    fclose(stream);
    _pidtab[fd] = 0;

    /* Wait for the child to complete.  Return the same value
     * that cwait would have returned, but with the low two bytes swapped.
     */
    if (_cwait(&termstat, pid, WAIT_CHILD) == -1)
        return (-1);
    return (((termstat >> 8) & 0xff) | ((termstat << 8) & 0xff00));
}
