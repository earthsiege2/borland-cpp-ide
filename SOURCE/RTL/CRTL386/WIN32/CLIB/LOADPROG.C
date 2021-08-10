/*-----------------------------------------------------------------------*
 * filename - loadprog.c
 *
 * function(s)
 *    _LoadProg -- Load and Execute a program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_USER
#define INCL_ERROR_H
#include <ntbc.h>

#include <_io.h>
#include <_process.h>
#include <errno.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------------------------------------------
 * _add_pid_ptr - pointer to function to add process to table
 *
 * Initially this points to a dummy function, but if cwait() is used
 * it will be set to point to a function that actually adds the process
 * to a table that maps process IDs to process handles.  See _cwait.c
 * for more details.
 */

#pragma argsused
int _dummy_add_pid(DWORD pid, HANDLE handle)
{
    return (int)pid;
}

int (*_add_pid_ptr)(DWORD, HANDLE) = _dummy_add_pid;

/*-----------------------------------------------------------------------*

Name            search -- search for an executable program

Usage           int search(const char *pathP, char *fullname, const char *ext,
                           int usepath);

Prototype in    local

Description     search searches for the program pathP, and copies
                the full pathname of the found program to the buffer fullname.
                If usepath is non-zero, the directories in the PATH
                are searched after the current directory.  ext specifies
                an extension that is appended to the full name before
                the search takes place.

Return value    If the program is found, 1 is returned; otherwise 0.

*------------------------------------------------------------------------*/

static int search(const char *pathP, char *fullname, const char *ext,
                  int UsePath)
{
    char name[_MAX_PATH];

    strcpy(name,pathP);                 /* make a copy of program name */
    strcat(name,ext);                   /* append the extension */
    if (UsePath)                        /* search the PATH */
    {
        _searchenv(name,"PATH",fullname);
        return (fullname[0] != '\0');   /* is the full name non-empty? */
    }
    else                                /* assume it's a relative path */
    {
        strcpy(fullname,name);
        return (__access(name,4) == 0); /* do we have read access? */
    }

}

/*-----------------------------------------------------------------------*

Name            make_cmdline -- construct argument strings

Usage           char *make_cmdline(const char *arg0, const char *arg1,
                             const char *argP[]);

Prototype in    local

Description     make_cmdline constructs the command line required by
                CreateProcess.  The command line is simply the concatentation
                of the strings arg0, arg1, and argP[...].  The strings
                are separated by spaces, and the last string is followed
                by a null character.  Arg0 and arg1 are optional, and
                should be NULL if not used.  If arg0 is NULL, all following
                arguments must also be NULL.  A buffer large enough to
                hold the strings is allocated using malloc.  The list
                of arguments in argP must be terminated by a NULL pointer.

                The resulting buffer has this form:
                    arg0 arg1 argP[0] argP[1]...\0

Return value    If successful, a pointer to the argument buffer, which
                must be freed when no longer needed.  If unsuccessful,
                a NULL pointer.

*------------------------------------------------------------------------*/

static char *make_cmdline(const char *arg0, const char *arg1,
                          const char * const *argP)
{
    int len;
    const char * const * argv;
    char *buf;
    char *p;

    /* Compute the required allocation size, then allocate the buffer.
     */
    len = 0;
    if (arg0 != NULL)
        len += strlen(arg0) + 1;        /* length of arg0 */

    if (arg1 != NULL)
        len += strlen(arg1) + 1;        /* length of second optional arg */

    for (argv = argP; *argv != NULL; argv++)
        len += strlen(*argv) + 1;       /* length of each argument */
    if ((buf = malloc(len)) == NULL)
        return (NULL);

    /* Copy arg0 (typically the program name) to the buffer.
     */
    p = buf;
    if (arg0 != NULL)
    {
        p = _stpcpy(p,arg0);
        *p++ = ' ';
    }

    /* Concatenate the optional prefix argument.
     */
    if (arg1 != NULL)
    {
        p = _stpcpy(p,arg1);
        *p++ = ' ';
    }

    /* Concatenate the arguments, separated by spaces.
     */
    if (arg0 != NULL)
    {
        for (argv = argP; *argv != NULL; argv++)
        {
            p = _stpcpy(p,*argv);
            *p++ = ' ';
        }
    }
    *(p-1) = '\0';      /* last token terminated by nul character */
    return (buf);
}

/*-----------------------------------------------------------------------*

Name            make_env -- construct environment block

Usage           char *make_env(const char * const * envV);

Prototype in    local

Description     make_env constructs a buffer containing all of the
                environment strings in envV.  The buffer is allocated
                using malloc.  The last string in the buffer is
                followed by a null character.

Return value    If successful, a pointer to the environment buffer, which
                must be freed when no longer needed.  If unsuccessful,
                a NULL pointer.

*------------------------------------------------------------------------*/

static char *make_env(const char * const * envV)
{
    int len;
    const char * const * envp;
    char *buf;
    char *p;

    /* Compute the required allocation size, then allocate the buffer.
     * The length includes space for each environment string and
     * its null terminator, and the null that follows the last string.
     */
    for (len = 1, envp = envV; *envp != NULL; envp++)
        len += strlen(*envp) + 1;

    if ((buf = malloc(len)) == NULL)
        return (NULL);

    /* Copy each environment string into the buffer.  If file info
     * is enabled, the last string is _C_FILE_INFO.
     */
    for (envp = envV, p = buf; *envp != NULL; envp++)
        p = _stpcpy(p,*envp) + 1;
    *p = '\0';
    return (buf);
}

/*-----------------------------------------------------------------------*

Name            _LoadProg -- Load and Execute a program

Usage           #include <_process.h>
                int _LoadProg(int mode,
                        const char *pathP,
                        const char * const *argP,
                        const char * const *envV,
                        int UsePath)

Prototype in    _process.h

Description     _Loadprog loads  and runs another  program, known as  child
                process.

                The child process overlays the  current program if _exec is
                passed  as  Func  argument,  otherwise  the  calling parent
                process regains  control after program execution  if _spawn
                is passed as Func argument.

                *pathP  is  the  file  name  of  the  called child process.
                _LoadProg searches  for pathname using the  standard MS-DOS
                search algorithm:

                . no  extension or no period - search  for exact file
                  name;  if  not  successful,  add .EXE and search
                  again

                . extension given - search only for exact file name

                . period  given - search only for file name with no
                  extension

                UsePath, if  true, specifies that the  function will search
                for  the child  in those  directories specified  by the DOS
                PATH  environment   variable.  If  false,   _LoadProg  only
                searches the root and current working directory.

                At   execution  time,   the  child   process  receives  two
                arguments:
                    - a command string built from argP
                    - an environment built from envV.

Return value    A successful _exec does not return, and a successful _spawn
                returns  the exit  code of   the child  process for
                synchronous calls, or the child process ID for asynchronous
                calls. On  error, _LoadProg  returns  -1,  and  errno
                is  set  to one of the following:
                    E2BIG   Argument list too long
                    EACCES  Permission denied
                    EMFILE  Too many open files
                    ENOENT  Path or file name not found
                    ENOEXEC Exec format error
                    ENOMEM  Not enough core

*------------------------------------------------------------------------*/

int _LoadProg(int mode, const char *pathP, const char * const *argP,
              const char * const *envV, int UsePath)
{
    char                fullname[_MAX_PATH];
    SECURITY_ATTRIBUTES sec;
    STARTUPINFO         start;
    PROCESS_INFORMATION pinfo;
    DWORD               exitcode;
    char                *cmdP, *envP, *comspec, *ext;
    int                 rc;
    unsigned            found, c, batch;

#if 0
    /* Currently we don't support P_DETACH on NT.
     */
    if (mode == P_DETACH)
    {
        errno = EINVAL;
        return -1;
    }
#endif

    /* If the program name contains a drive specifier or directory separators,
     * don't search the path.
     */
    if ((c = pathP[0]) >= 'a')
        c -= 'a' - 'A';
    if ((c >= 'A' && c <= 'Z' && pathP[1] == ':') ||
            strchr(pathP,'/') != NULL || strchr(pathP,'\\') != NULL)
        UsePath = 0;

    /* Check if the program exists.  If no extension is given,
     * try .EXE and then .BAT.
     */
    batch = 0;
    if ((ext = strrchr(pathP,'.')) != NULL) /* file has an extension */
    {
        if ((found = search(pathP, fullname, "", UsePath)) != 0)
            if (stricmp(ext,".BAT") == 0)   /* is it a batch file? */
                batch = 1;
    }
    else                                    /* file has no extension */
    {
        if ((found = search(pathP, fullname, ".EXE", UsePath)) == 0)
            if ((found = search(pathP, fullname, ".BAT", UsePath)) != 0)
                batch = 1;                  /* use shell to run .BAT */
    }
    if (!found || (batch && (comspec = getenv("COMSPEC")) == NULL))
    {
        errno = ENOENT;
        return -1;
    }

    /* Concatenate arguments to make the command line.
     */
    if (batch)
        cmdP = make_cmdline(comspec,"/c",argP);
    else
        cmdP = make_cmdline(argP[0],NULL,&argP[1]);

    if (cmdP == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    /* Concatenate environment strings.  If NULL is specified,
     * use the current process's environment strings.
     */
    if (envV == NULL)
        envP = NULL;
    else if ((envP = make_env(envV)) == NULL)
    {
memerr:
        errno = ENOMEM;
        free(cmdP);
        return -1;
    }

    /* Flush all byte streams.
     */
    (*_exitbuf)();

    /* Set up the start info structure.  If _fileinfo is non-zero,
     * this includes a pointer to a file information table that contains
     * the flags and handles for all open files.
     */
    memset(&start,0,sizeof(start));
    start.cb = sizeof(start);
    start.wShowWindow = SW_SHOWDEFAULT;
    if (_fileinfo)                      /* file info passing enabled? */
    {
        start.cbReserved2 = (*_cfinfo_get)(NULL);       /* get length */
        if ((start.lpReserved2 = malloc((int)start.cbReserved2)) == NULL)
            goto memerr;
        (*_cfinfo_get)((char *)start.lpReserved2);      /* copy file info */
    }

    sec.nLength = sizeof(sec);
    sec.lpSecurityDescriptor = NULL;
    sec.bInheritHandle = TRUE;

    /* Now, call the low level _exec/_spawn function.
     * We can't do an overlay style 'exec' in NT. The 'exec' functions
     * do spawn/exit sequences to simulate an exec. If *we* get called
     * with an overlay request, like from spawnxx(P_OVERLAY...) then we'll
     * just do a synchronous exec and then an _exit(0) to sort of fake it.
     */
    if (CreateProcess(
        batch ? (PSZ)comspec : (PSZ)fullname,   /* program name */
        cmdP,                                   /* command line */
        &sec,                                   /* process attributes */
        &sec,                                   /* thread attributes */
        TRUE,                                   /* inherit handles flag */
        (mode == P_DETACH ? DETACHED_PROCESS : 0), /* creation flags */
        envP,                                   /* environment strings */
        NULL,                                   /* current directory */
        &start,                                 /* startup info */
        &pinfo)                                 /* process info */
         != TRUE)

    {
        int err;

        switch (GetLastError() & 0xffffL)
        {
            case ERROR_NO_PROC_SLOTS :
                err = EAGAIN;
                break;

            case ERROR_INVALID_FUNCTION :
                err = EINVAL;
                break;

            case ERROR_NOT_ENOUGH_MEMORY :
                err = ENOMEM;
                break;

            default :
                err = ENOEXEC;
                break;
        }
        errno = err;
        rc = -1;
    }
    else
    {
        switch (mode)
        {
            case P_WAIT :
                WaitForSingleObject(pinfo.hProcess, -1);
                GetExitCodeProcess(pinfo.hProcess, &exitcode);
                CloseHandle(pinfo.hProcess);
                rc = exitcode;
                break;

            case P_DETACH :
            case P_NOWAITO:
                CloseHandle(pinfo.hProcess);
                /* drop into P_NOWAIT */

            case P_NOWAIT :
                /* Return the process ID.  This can be used as a
                 * parameter to cwait().
                 */
                rc = _add_pid_ptr(pinfo.dwProcessId, pinfo.hProcess);
                break;

            case P_OVERLAY :
                _exit(0);

            default :
                rc = -1;
                break;
        }
        CloseHandle(pinfo.hThread);
    }

    /* Release all working buffers before returning the result code.
     */
    free(envP);
    free(cmdP);
    return (rc);
}
