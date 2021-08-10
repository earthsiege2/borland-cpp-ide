/*-----------------------------------------------------------------------*
 * filename - loadprog.c
 *
 * function(s)
 *        _LoadProg -- Load and Execute a program
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_process.h>
#include <process.h>
#include <stdlib.h>
#include <_io.h>
#include <errno.h>
#include <string.h>


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
    #define MAX_CMD 127

    char name[MAX_CMD + 1];

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
        return (_access(name,4) == 0); /* do we have read access? */
    }
}

/*-----------------------------------------------------------------------*

Name            _LoadProg -- Load and Execute a program

Usage           #include <_process.h>
                int _LoadProg(int (* Func)(char *, char *, char *),
                              char *pathP,
                              char *argP[],
                              char *envV[],
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
                returns  the exit  code of   the child  process. On  error,
                _LoadProg  returns  -1,  and  errno  is  set  to one of the
                following:
                        E2BIG   Argument list too long
                        EACCES  Permission denied
                        EMFILE  Too many open files
                        ENOENT  Path or file name not found
                        ENOEXEC Exec format error
                        ENOMEM  Not enough core

*------------------------------------------------------------------------*/
int near _LoadProg(int cdecl near (*Func)(char *, char *, char *), char *pathP,
                        char *argP[], char *envV[], int UsePath)
{
    char        fullname[MAX_CMD + 1];
    char        *comspec, *cmdP, *envP, *ext;
    void        *envSave;
    int         rc;
    unsigned    found, c, batch;

    /* If the program name contains a drive specifier or directory separators,
     * don't search the path.
     */
    if ((c = pathP[0]) >= 'a')
        c -= 'a' - 'A';
    if ((c >= 'A' && c <= 'Z' && pathP[1] == ':') ||
        strchr(pathP,'/') != NULL || strchr(pathP,'\\') != NULL)
        UsePath = 0;

    /* Check if the program exists.  If no extension is given,
     * try .COM and then .EXE and then .BAT.
     */
    batch = 0;
    if ((ext = strrchr(pathP,'.')) != NULL) /* file has an extension */
    {
        if ((found = search(pathP, fullname, "", UsePath)) != 0)
            if (stricmp(ext, ".BAT") == 0)   /* is it a batch file? */
                batch = 1;
    }
    else                                    /* file has no extension */
    {
        if ((found = search(pathP, fullname, ".COM", UsePath)) == 0)
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
        cmdP = __DOScmd(comspec, "/c", argP);
    else
        cmdP = __DOScmd(fullname, NULL, &argP[1]);

    if (cmdP == NULL)
    {
        errno = ENOMEM;
        return -1;
    }

    /* Then, ensure that the length of the file plus its argument list is
     * under the DOS limit.
     */
    if (strlen(cmdP) > MAX_CMD)
    {
        errno = E2BIG;
        return -1;
    }

    /*  Then, concatenate environment strings           */
    if (envV == NULL)
        envV = _environ;

    if ((envP = __DOSenv(envV, batch ? comspec : fullname, &envSave)) == NULL)
    {
        errno = ENOMEM;
        free(cmdP);
        return -1;
    }

    /*      Flush all byte streams          */
    (*_exitbuf)();

    /*      Now, call the low level _exec/_spawn function   */
    rc = (*Func)(batch ? comspec : fullname, cmdP, envP);

    /*      Release all working buffers     */
    free(envSave);
    free(cmdP);
    return rc;
}
