/*-----------------------------------------------------------------------*
 * filename - loadprog.c
 *
 * function(s)
 *    _LoadProg -- Load and Execute a program
 *    _wLoadProg -- Load and Execute a program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

#define INCL_USER
#define INCL_ERROR_H
#include <ntbc.h>

#include <io.h>
#include <_io.h>
#include <_process.h>
#include <errno.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <_tchar.h>
#include <_malloc.h>
#include <winbase.h>

/*-----------------------------------------------------------------------
 * _add_pid_ptr - pointer to function to add process to table
 *
 * Initially this points to a dummy function, but if cwait() is used
 * it will be set to point to a function that actually adds the process
 * to a table that maps process IDs to process handles.  See _cwait.c
 * for more details.
 */

#pragma argsused
#ifndef _UNICODE	//we only need one copy of this and rather than move it...
int _dummy_add_pid(DWORD pid, HANDLE handle)
{
    return (int)pid;
}
int (*_add_pid_ptr)(DWORD, HANDLE) = _dummy_add_pid;
#else
extern int (*_add_pid_ptr)(DWORD, HANDLE);
#endif

/*-----------------------------------------------------------------------*

Name            search, _wsearch -- search for an executable program

Usage           int search(const char *pathP, char *fullname, const char *ext,
			   int usepath);
                int _wsearch(const wchar_t *pathP, wchar_t *fullname,
		           const wchar_t *ext, int usepath);

Prototype in    local

Description     search searches for the program pathP, and copies
                the full pathname of the found program to the buffer fullname.
                If usepath is non-zero, the directories in the PATH
                are searched after the current directory.  ext specifies
                an extension that is appended to the full name before
                the search takes place.

Return value    If the program is found, 1 is returned; otherwise 0.

*------------------------------------------------------------------------*/

static int _tsearch(const _TCHAR *pathP, _TCHAR *fullname, const _TCHAR *ext,
                  int UsePath)
{
    _TCHAR name[_MAX_PATH];

    _tcscpy(name,pathP);                 /* make a copy of program name */
    _tcscat(name,ext);                   /* append the extension */
    if (UsePath)                        /* search the PATH */
    {
        _tsearchenv(name,_TEXT("PATH"),fullname);
        return (fullname[0] != _TEXT('\0'));   /* is the full name non-empty? */
    }
    else                                /* assume it's a relative path */
    {
        _tcscpy(fullname,name);
        return (_taccess(name,4) == 0); /* do we have read access? */
    }

}

/*-----------------------------------------------------------------------*

Name            make_cmdline, _wmake_cmdline -- construct argument strings

Usage           char *make_cmdline(const char *arg0, const char *arg1,
                             const char *argP[]);
                wchar_t *_wmake_cmdline(const wchar_t *arg0, const wchar_t *arg1,
                             const wchar_t *argP[]);

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

static _TCHAR *_tmake_cmdline(const _TCHAR *arg0, const _TCHAR *arg1,
                          const _TCHAR * const *argP)
{
    int len;
    const _TCHAR * const * argv;
    _TCHAR *buf;
    _TCHAR *p;
    _TCHAR sfn[_MAX_PATH];

    if (arg0 && GetShortPathName(arg0, sfn, _MAX_PATH))
        arg0 = sfn;

    /* Compute the required allocation size, then allocate the buffer.
     */
    len = 0;
    if (arg0 != NULL)
        len += _tcslen(arg0) + 1;        /* length of arg0 */

    if (arg1 != NULL)
        len += _tcslen(arg1) + 1;        /* length of second optional arg */

    for (argv = argP; *argv != NULL; argv++)
        len += _tcslen(*argv) + 1;       /* length of each argument */
    if ((buf = malloc(len*sizeof(_TCHAR))) == NULL)
        return (NULL);

    /* Copy arg0 (typically the program name) to the buffer.
     */
    p = buf;
    if (arg0 != NULL)
    {
        p = _tcspcpy(p,arg0);
        *p++ = _TEXT(' ');
    }

    /* Concatenate the optional prefix argument.
     */
    if (arg1 != NULL)
    {
        p = _tcspcpy(p,arg1);
        *p++ = _TEXT(' ');
    }

    /* Concatenate the arguments, separated by spaces.
     */
    if (arg0 != NULL)
    {
        for (argv = argP; *argv != NULL; argv++)
        {
            p = _tcspcpy(p,*argv);
            *p++ = _TEXT(' ');
        }
    }
    *(p-1) = _TEXT('\0');      /* last token terminated by nul character */
    return (buf);
}

/*-----------------------------------------------------------------------*

Name            make_env, _wmake_env -- construct environment block

Usage           char *make_env(const char * const * envV);
                wchar_t *wmake_env(const wchar_t * const * envV);

Prototype in    local

Description     make_env constructs a buffer containing all of the
                environment strings in envV.  The buffer is allocated
                using malloc.  The last string in the buffer is
                followed by a null character.

Return value    If successful, a pointer to the environment buffer, which
                must be freed when no longer needed.  If unsuccessful,
                a NULL pointer.

*------------------------------------------------------------------------*/

static _TCHAR *_tmake_env(const _TCHAR * const * envV)
{
    int len;
    const _TCHAR * const * envp;
    _TCHAR *buf;
    _TCHAR *p;

    /* Compute the required allocation size, then allocate the buffer.
     * The length includes space for each environment string and
     * its null terminator, and the null that follows the last string.
     */
    for (len = 1, envp = envV; *envp != NULL; envp++)
        len += _tcslen(*envp) + 1;

    if ((buf = malloc(len*sizeof(_TCHAR))) == NULL)
        return (NULL);

    /* Copy each environment string into the buffer.  If file info
     * is enabled, the last string is _C_FILE_INFO.
     */
    for (envp = envV, p = buf; *envp != NULL; envp++)
        p = _tcspcpy(p,*envp) + sizeof(_TCHAR);
    *p = _TEXT('\0');
    return (buf);
}

/*-----------------------------------------------------------------------*

Name            _LoadProg, _wLoadProg -- Load and Execute a program

Usage           #include <_process.h>
                int _LoadProg(int mode,
                        const char *pathP,
                        const char * const *argP,
                        const char * const *envV,
                        int UsePath)

		int _wLoadProg(int mode,
                        const wchar_t *pathP,
                        const wchar_t * const *argP,
                        const wchar_t * const *envV,
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

int _tLoadProg(int mode, const _TCHAR *pathP, const _TCHAR * const *argP,
              const _TCHAR * const *envV, int UsePath)
{
    _TCHAR              fullname[_MAX_PATH];
    SECURITY_ATTRIBUTES sec;
    STARTUPINFO         start;
    PROCESS_INFORMATION pinfo;
    DWORD               exitcode;
    _TCHAR              *cmdP, *envP, *comspec, *ext, *lslash;
    int                 rc;
    unsigned            found, c, batch;
    DWORD               create_flags;

    /* If the program name contains a drive specifier or directory separators,
     * don't search the path.
     */
    if ((c = pathP[0]) >= _TEXT('a'))
        c -= _TEXT('a') - _TEXT('A');
    if ((c >= _TEXT('A') && c <= _TEXT('Z') && pathP[1] == _TEXT(':')) ||
            _tcschr(pathP,_TEXT('/')) != NULL || _tcschr(pathP,_TEXT('\\')) != NULL)
        UsePath = 0;

    /* Check if the program exists.  If no extension is given,
     * try .EXE and then .BAT, and finally .CMD.
     */
    batch = 0;
    if ((lslash = _tcsrchr(pathP,_TEXT('\\'))) != NULL) /* Find last slash in string */
        lslash++; /* skip past this last slash */
    else
        lslash = (_TCHAR *)pathP;  /* no slashes, so use the whole string */

    if ((ext = _tcsrchr(lslash,_TEXT('.'))) != NULL) /* file has an extension */
    {
        if ((found = _tsearch(pathP, fullname, _TEXT(""), UsePath)) != 0)
            /* is it a batch file? */
            if ((_tcsicmp(ext,_TEXT(".BAT")) == 0) || (_tcsicmp(ext,_TEXT(".CMD")) == 0))
                batch = 1;
    }
    else                                    /* file has no extension */
    {
        if ((found = _tsearch(pathP, fullname, _TEXT(".EXE"), UsePath)) == 0)
            if ((batch=found = _tsearch(pathP, fullname, _TEXT(".BAT"), UsePath)) == 0)
                batch=found = _tsearch(pathP, fullname, _TEXT(".CMD"), UsePath);
                /* use shell to run .BAT
                 * or .CMD files
                 */
    }
    if (!found || (batch && (comspec = _tgetenv(_TEXT("COMSPEC"))) == NULL))
    {
        errno = ENOENT;
        return -1;
    }

    /* Concatenate arguments to make the command line.
     */
    if (batch)
        cmdP = _tmake_cmdline(comspec,_TEXT("/c"),argP);
    else
        cmdP = _tmake_cmdline(argP[0],NULL,&argP[1]);

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
    else if ((envP = _tmake_env(envV)) == NULL)
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

        /* Because this block of memory is used in the called .EXE's
           startup code, we can't really free it here, since the .EXE
           could still be running when we exit.  Therefore we allocate
           it using the internal malloc name: __org_malloc, which
           codeguard does not track.  This way no one knows that we
           haven't freed it.  (fear not, the OS will free it for us)
        */
        if ((start.lpReserved2 =
#if defined(_BUILDRTLDLL)
        malloc
#else
        __org_malloc
#endif

        ((int)start.cbReserved2)) == NULL)
            goto memerr;
        (*_cfinfo_get)((char *)start.lpReserved2);      /* copy file info (byte)*/
    }

    sec.nLength = sizeof(sec);
    sec.lpSecurityDescriptor = NULL;
    sec.bInheritHandle = TRUE;

    /* Test for the _P_xxx modifier flags */

    create_flags = 0;

#ifdef _UNICODE
    create_flags |= CREATE_UNICODE_ENVIRONMENT;
#endif

    /* CREATE_NEW_CONSOLE and DETACHED_PROCESS are mutually exclusive */

    if (mode & _P_NEWCONSOLE)
        create_flags |= CREATE_NEW_CONSOLE;
    else if (mode & _P_DETACH)
        create_flags |= DETACHED_PROCESS;

    if (mode & _P_NEWPROCGROUP)
        create_flags |= CREATE_NEW_PROCESS_GROUP;

    if (mode & _P_SUSPENDED)
        create_flags |= CREATE_SUSPENDED;

    /* CREATE_SEPARATE_WOW_VDM and CREATE_SHARED_WOW_VDM are mutually
       exclusive */

    if (mode & _P_NEWWIN16)
        create_flags |= CREATE_SEPARATE_WOW_VDM;
    else if (mode & _P_SHAREDWIN16)
        create_flags |= CREATE_SHARED_WOW_VDM;

    if (mode & _P_DEFERRORMODE)
        create_flags |= CREATE_DEFAULT_ERROR_MODE;

    /* The four PRIORITY_CLASS flags are all mutually exclusive */

    if (mode & _P_PRIO_NORM)
        create_flags |= NORMAL_PRIORITY_CLASS;
    else if (mode & _P_PRIO_IDLE)
        create_flags |= IDLE_PRIORITY_CLASS;
    else if (mode & _P_PRIO_HIGH)
        create_flags |= HIGH_PRIORITY_CLASS;
    else if (mode & _P_PRIO_REAL)
        create_flags |= REALTIME_PRIORITY_CLASS;

    /* Now, call the low level _exec/_spawn function.
     * We can't do an overlay style 'exec' in NT. The 'exec' functions
     * do spawn/exit sequences to simulate an exec. If *we* get called
     * with an overlay request, like from spawnxx(P_OVERLAY...) then we'll
     * just do a synchronous exec and then an _exit(0) to sort of fake it.
     */
    if (CreateProcess(
        batch ? comspec : fullname,             /* program name */
        cmdP,                                   /* command line */
        &sec,                                   /* process attributes */
        &sec,                                   /* thread attributes */
        TRUE,                                   /* inherit handles flag */
        create_flags,                           /* creation flags */
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

        if (mode == _P_DETACH)
        {
            /* handle the case where the user specified only the or'able
               version of P_DETACH (called _P_DETACH) because it is the name
               that MSC programs would use. In this case we map it over to
               the base P_DETACH value */

            mode = P_DETACH;
        }

        switch (mode & _P_MASK)
        {
            case P_WAIT :
                WaitForSingleObject(pinfo.hProcess, -1);
                GetExitCodeProcess(pinfo.hProcess, &exitcode);
                if (!(mode & _P_NOCLOSE))
                    CloseHandle(pinfo.hProcess);
                rc = exitcode;
                break;

            case P_DETACH :
            case P_NOWAITO:
                if (!(mode & _P_NOCLOSE))
                    CloseHandle(pinfo.hProcess);
                /* drop into P_NOWAIT */

            case P_NOWAIT :
                /* Return the process ID.  This can be used as a
                 * parameter to cwait().
                 */
                rc = _add_pid_ptr(pinfo.dwProcessId, pinfo.hProcess);
                break;

            case P_OVERLAY :
                free(envP);   /* free this stuff so codeguard is happy */
                free(cmdP);
                exit(0);      /* exit() will call all start/exit routines
                                 and close all streams and handles, so that
                                 codeguard is happy. */

            default :
                rc = -1;
                break;
        }
        if (! (mode & _P_SUSPENDED) && !(mode & _P_NOCLOSE))
            CloseHandle(pinfo.hThread);
    }

    /* Release all working buffers before returning the result code.
     */
    free(envP);
    free(cmdP);
    return (rc);
}
