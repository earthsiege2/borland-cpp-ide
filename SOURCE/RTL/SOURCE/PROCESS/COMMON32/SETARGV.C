/*-----------------------------------------------------------------------*
 * filename - setargv.c
 *
 * function(s)
 *        _setargv  - set up argv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.9  $        */

/* Set up argv[] from the command line.  If wildargs.obj is included, wildcard
 * filenames are expanded; see expndarg.c for more information.
 */

#pragma inline

#ifdef __OS2__
#include <os2bc.h>
#else
#include <ntbc.h>
#endif

#include <_io.h>        /* _ErrorExit */

#define ARGVCHUNK 16                /* no. of elemements added to _argv[] */
                                    /*   each time it is grown */

#define DEBUG 0

#if DEBUG
#include <stdio.h>
#endif

#include <string.h>
#include <stdlib.h>
#include <dir.h>
#include <tchar.h>
#include <_tchar.h>

/*----------------------------------------------------------------------
 * BCC generates an external reference to __setargv__/__wsetargv__when it
 * compiles a main() function that takes argc and argv parameters.  The following
 * declaration satisfies that reference and forces this module to be linked.
 */
#if !defined(_BUILDRTLDLL)
int _tsetargv__ = 0;
#endif

/*----------------------------------------------------------------------
 * The startup code passes the following variables to main().
 * They contain copies of _argc and _argv.
 */
extern int      _C0argc;
extern _TCHAR **_tC0argv;
extern ULONG    _os2hmod;    /* module handle */

extern _TCHAR  *_targv0;

/*----------------------------------------------------------------------
 * The following variables points to the command line, and is
 * set up by the startup code.
 */
extern _TCHAR *_toscmd;

/*----------------------------------------------------------------------
 * Argument vector and count.  Argument count (_argc) is located in globals.c
 */
extern int _EXPDATA _argc;        /* number of arguments */
_TCHAR ** _EXPDATA _targv;       /* argument vector */

/*----------------------------------------------------------------------
 * Local variables
 */
static int   argmax;          /* maximum size of _argv[] */
static _TCHAR *_tcmdsave;
/*----------------------------------------------------------------------
 * Forward declarations
 */
void _taddarg(_TCHAR *, int);
static void _tcopychar(_TCHAR **, _TCHAR**);
static void _texpand(_TCHAR *);

/*----------------------------------------------------------------------
 * Pointer to wildcard expansion function.  Normally it points to a
 * function that simply adds an argument without expansion, but if
 * wildargs.obj is included, it is set to point to a real expansion
 * function.
 */
void (* _EXPDATA _texpandptr)(_TCHAR *) = _texpand;

/*----------------------------------------------------------------------
 * is_space - check for space or tab character
 *
 * This macro is defined locally in order to avoid using ctype.h.
 */
#define is_wspace(p) ((p) ==_TEXT(' ') || (p) ==_TEXT('\t'))

/*----------------------------------------------------------------------
 * _setargv  - set up _argc and _argv
 * _wsetargv  - set up _argc and _wargv
 *
 * This function is called by the startup code before main() is called.
 * It parses the command line into tokens, storing pointers to the
 * tokens in _argv[].  Tokens that aren't quoted and contain wild-card
 * characters are expanded to all matching files (only if WILDARGS.OBJ
 * has been included, causing _expandptr to be modified).
 */
void _EXPFUNC _tsetargv(void)
{
#if !defined(_BUILDRTLDLL)
#if !defined(_UNICODE)
#pragma startup _setargv 3      /* force _setargv to be called at startup */
#else
#pragma startup _wsetargv 3      /* force wide-character _setargv to be called at startup */
#endif
#endif

    _TCHAR *src, *dst, *arg;
#ifdef __OS2__
    _TCHAR buffer[MAXPATH];
#endif

    /* If this is a DLL, there is no command line, so return now.
     */
    if (_toscmd == NULL)
        return;

    /* Initialize variables used by _addarg().  On OS/2, the command
     * line is composed of two consecutive strings: the command name,
     * followed by the command tail.  On WIN32, the command name and tail
     * are merged into one string.
     */
    _argc = argmax = 0;
    _targv = NULL;
    src = _toscmd;

#ifdef __OS2__
    DosQueryModuleName(_os2hmod, MAXPATH, buffer);
    _addarg(buffer, 1);             /* add program name and path */
    src += strlen(_toscmd) + 1;      /* program name is first argument, skip */
#endif
#ifdef __WIN32__

    // Note: _exitargv0 (in setargv0.c) cleans up the original _argv0
    //       Here, we make a copy for _argv[0], and clean it up in _exitargv

    _taddarg(_targv0, 1);
    while (is_wspace(*src))                  /* skip leading white space */
        src++;
    if (*src == _TEXT('"'))                /* check for quoted program name */
    {
        ++src;                      /* skip leading quote */
        while (*src != _TEXT('"') && *src != _TEXT('\0'))
            src++;                  /* skip the part in quotes */
        if (*src == _TEXT('"'))            /* skip trailing quote */
            ++src;
    }
    else
        while (!is_wspace(*src) && *src != _TEXT('\0')) /* skip program name */
            src++;
#endif

    /* Allocate space for a copy of the command line.  We could modify
     * the command line in place, but some programs might want to look
     * at it unmodified.
     */
    if ((_tcmdsave = dst = malloc((_tcslen(src)+1)*sizeof(_TCHAR))) == NULL)
        _ErrorExit("No space for copy of command line");

    /* Add each argument from the command line to the argument list.
     */
    while (*src != _TEXT('\0'))
    {
        int do_expand = 0;

        while (is_wspace(*src))          /* ignore spaces between arguments */
            src++;
        if (*src == _TEXT('\0'))               /* quit at end of line */
            break;

        /* An argument consists of all text up to the
         * next whitespace character.
         */
        arg = dst;                      /* save start of argument */
        while (!is_wspace(*src) && *src != _TEXT('\0'))
        {
            if (*src == _TEXT('"'))
            {
                /* Text surrounded by double quotes is copied verbatim.
                 */
                ++src;                      /* skip leading quote */
                while (*src != _TEXT('"') && *src != _TEXT('\0'))
                    _tcopychar(&dst, &src);   /* copy the part in quotes */
                if (*src == _TEXT('"'))            /* skip trailing quote */
                    ++src;
            }
            else
            {
                /* A non-quote character is copied verbatim.
                 */
                if (*src == _TEXT('*') || *src == _TEXT('?'))
                    do_expand = 1;      /* wildcard character seen */
                _tcopychar(&dst, &src);   /* copy until next whitespace */
            }
        }
        *dst++ = _TEXT('\0');           /* terminate the string */
        if (do_expand)                  /* wildcard filename? */
            (*_texpandptr)(arg);        /* expand it */
        else
            _taddarg(arg, 0);           /* don't expand it */
        if (*src == _TEXT('\0'))        /* quit at end of line */
            break;
        src++;                          /* skip token terminator */
    }

    _taddarg(NULL, 0);                  /* add a dummy NULL argument */
    _argc--;                            /* but don't count it */

    _C0argc = _argc;                    /* startup code expects args */
    _tC0argv = _targv;                 /*  in these variables */
}

/*----------------------------------------------------------------------
 * _exitargv  - clean up _argc and _argv
 * _wexitargv - clean up wide-character _wargv and _argc
 *
 * Cleans up the allocated memory.
 *
 */
void _EXPFUNC _texitargv(void)
{
#if !defined(_BUILDRTLDLL)
#if !defined(_UNICODE)
#pragma exit _exitargv 3      /* force _exitargv to be called at cleanup */
#else
#pragma exit _wexitargv 3      /* force _exitargv to be called at cleanup */
#endif
#endif

    /* If we allocated _argv, _argv[0], and cmdsave clean them up (we won't
       set them up in a DLL).
       Note: Wildargs needs support later
     */
    if (_targv)
    {
	free(_targv[0]);
	free(_targv);
	free(_tcmdsave);

        /* Protect against accidental double free*/
        _targv = NULL;
        _tcmdsave = NULL;
    }
}

/*----------------------------------------------------------------------
 * copychar -  copy next character from command line
 * wcopychar - copy next wide-character from command line
 *
 * Read the character pointed to by **src, store it at **dst.
 * Handle escaped quote (\") by skipping the backslash.  Advance
 * *src and *dst to point to the next character.
 */
static void _tcopychar(_TCHAR **dst, _TCHAR **src)
{
    if ((*src)[0] == _TEXT('\\') && (*src)[1] == _TEXT('"'))
    {
        **dst = _TEXT('"');
        *src += 2;
    }
    else
    {
#if defined(_MBCS)
        if (_istlead((*src)[0]) && (*src)[1])
        {
            **dst = **src;
            *src += 1;
            *dst += 1;
        }
#endif
        **dst = **src;
        *src += 1;
    }
    *dst += 1;
}

/*----------------------------------------------------------------------
 * _addarg -  add one argument to _argv list
 * _waddarg - add one wide-character argument to _argv list
 */
void _taddarg(_TCHAR *arg, int makecopy)
{
    _TCHAR *save;

    /* If _argv[] is full, grow it by another ARGVCHUNK elements.
     */
    if (_argc == argmax)
    {
        argmax += ARGVCHUNK;
        if ((_targv = realloc(_targv,argmax * sizeof(_TCHAR *))) == NULL)
            _ErrorExit("No space for command line argument vector");
    }

    /* If the makecopy flag is non-zero, allocate space for the new argument
     * and copy it.  Then add the argument to the end of _argv[].
     */
    if (makecopy)
    {
        if ((save = (_TCHAR *)malloc((_tcslen(arg)+1)*sizeof(_TCHAR))) == NULL)
            _ErrorExit("No space for command line argument");
        _tcscpy(save,arg);
    }
    else
        save = arg;
    _targv[_argc++] = save;
}

/*----------------------------------------------------------------------
 * expand - dummy wildcard expansion routine
 */
void _texpand(_TCHAR *arg)
{
    _taddarg(arg, 0);        /* add argument without making a copy */
}
