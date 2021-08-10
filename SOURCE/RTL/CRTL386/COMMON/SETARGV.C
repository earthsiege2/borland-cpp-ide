/*-----------------------------------------------------------------------*
 * filename - setargv.c
 *
 * function(s)
 *        _setargv  - set up argv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

/* Set up argv[] from the command line.  If wildargs.obj is included, wildcard
 * filenames are expanded; see expndarg.c for more information.
 */

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

/*----------------------------------------------------------------------
 * BCC generates an external reference to __setargv__ when it compiles
 * a main() function that takes argc and argv parameters.  The following
 * declaration satisfies that reference and forces this module to be linked.
 */
#if !defined(_BUILDRTLDLL)
int _setargv__ = 0;
#endif

/*----------------------------------------------------------------------
 * The startup code passes the following variables to main().
 * They contain copies of _argc and _argv.
 */
extern int    _C0argc;
extern char **_C0argv;
extern ULONG  _os2hmod;    /* module handle */

/*----------------------------------------------------------------------
 * The following variables points to the command line, and is
 * set up by the startup code.
 */
extern char *_oscmd;

/*----------------------------------------------------------------------
 * Argument vector and count.
 */
int     _EXPDATA _argc;        /* number of arguments */
char ** _EXPDATA _argv;        /* argument vector */

/*----------------------------------------------------------------------
 * Local variables
 */
static int argmax;          /* maximum size of _argv[] */

/*----------------------------------------------------------------------
 * Forward declarations
 */
void _addarg(char *, int);
static void copychar(char **, char**);
static void expand(char *);

/*----------------------------------------------------------------------
 * Pointer to wildcard expansion function.  Normally it points to a
 * function that simply adds an argument without expansion, but if
 * wildargs.obj is included, it is set to point to a real expansion
 * function.
 */
void (* _EXPDATA _expandptr)(char *) = expand;

/*----------------------------------------------------------------------
 * is_space - check for space or tab character
 *
 * This macro is defined locally in order to avoid using ctype.h.
 */
#define is_space(p) ((p) ==' ' || (p) =='\t')

/*----------------------------------------------------------------------
 * _setargv  - set up _argc and _argv
 *
 * This function is called by the startup code before main() is called.
 * It parses the command line into tokens, storing pointers to the
 * tokens in _argv[].  Tokens that aren't quoted and contain wild-card
 * characters are expanded to all matching files (only if WILDARGS.OBJ
 * has been included, causing _expandptr to be modified).
 */
void _EXPFUNC _setargv(void)
{
    char *src, *dst, *arg;
    char buffer[MAXPATH];

    /* If this is a DLL, there is no command line, so return now.
     */
    if (_oscmd == NULL)
        return;

    /* Initialize variables used by _addarg().  On OS/2, the command
     * line is composed of two consecutive strings: the command name,
     * followed by the command tail.  On WIN32, the command name and tail
     * are merged into one string.
     */
    _argc = argmax = 0;
    _argv = NULL;
    src = _oscmd;

#ifdef __OS2__
    DosQueryModuleName(_os2hmod, MAXPATH, buffer);
    _addarg(buffer, 1);             /* add program name and path */
    src += strlen(_oscmd) + 1;      /* program name is first argument, skip */
#endif
#ifdef __WIN32__
    GetModuleFileName(NULL, buffer, sizeof(buffer));
    _addarg(buffer, 1);
    while (is_space(*src))                  /* skip leading white space */
        src++;
    while (!is_space(*src) && *src != '\0') /* skip program name */
        src++;
#endif

    /* Allocate space for a copy of the command line.  We could modify
     * the command line in place, but some programs might want to look
     * at it unmodified.
     */
    if ((dst = malloc(strlen(src)+1)) == NULL)
        _ErrorExit("No space for copy of command line");

    /* Add each argument from the command line to the argument list.
     */
    while (*src != '\0')
    {
        int do_expand = 0;

        while (is_space(*src))          /* ignore spaces between arguments */
            src++;
        if (*src == '\0')               /* quit at end of line */
            break;

        /* An argument consists of all text up to the
         * next whitespace character.
         */
        arg = dst;                      /* save start of argument */
        while (!is_space(*src) && *src != '\0')
        {
            if (*src == '"')
            {
                /* Text surrounded by double quotes is copied verbatim.
                 */
                ++src;                      /* skip leading quote */
                while (*src != '"' && *src != '\0')
                    copychar(&dst, &src);   /* copy the part in quotes */
                if (*src == '"')            /* skip trailing quote */
                    ++src;
            }
            else
            {
                /* A non-quote character is copied verbatim.
                 */
                if (*src == '*' || *src == '?')
                    do_expand = 1;      /* wildcard character seen */
                copychar(&dst, &src);   /* copy until next whitespace */
            }
        }
        *dst++ = '\0';                  /* terminate the string */
        if (do_expand)                  /* wildcard filename? */
            (*_expandptr)(arg);         /* expand it */
        else
            _addarg(arg, 0);            /* don't expand it */
        if (*src == '\0')               /* quit at end of line */
            break;
        src++;                          /* skip token terminator */
    }

    _addarg(NULL, 0);                   /* add a dummy NULL argument */
    _argc--;                            /* but don't count it */

    _C0argc = _argc;                    /* startup code expects args */
    _C0argv = _argv;                    /*  in these variables */
}

#if !defined(_BUILDRTLDLL)
#pragma startup _setargv 3      /* force _setargv to be called at startup */
#endif

/*----------------------------------------------------------------------
 * copychar - copy next character from command line
 *
 * Read the character pointed to by **src, store it at **dst.
 * Handle escaped quote (\") by skipping the backslash.  Advance
 * *src and *dst to point to the next character.
 */
static void copychar(char **dst, char **src)
{
    if ((*src)[0] == '\\' && (*src)[1] == '"')
    {
        **dst = '"';
        *src += 2;
    }
    else
    {
        **dst = **src;
        *src += 1;
    }
    *dst += 1;
}

/*----------------------------------------------------------------------
 * _addarg - add one argument to _argv list
 */
void _addarg(char *arg, int makecopy)
{
    char *save;

    /* If _argv[] is full, grow it by another ARGVCHUNK elements.
     */
    if (_argc == argmax)
    {
        argmax += ARGVCHUNK;
        if ((_argv = realloc(_argv,argmax * sizeof(char *))) == NULL)
            _ErrorExit("No space for command line argument vector");
    }

    /* If the makecopy flag is non-zero, allocate space for the new argument
     * and copy it.  Then add the argument to the end of _argv[].
     */
    if (makecopy)
    {
        if ((save = malloc(strlen(arg)+1)) == NULL)
            _ErrorExit("No space for command line argument");
        strcpy(save,arg);
    }
    else
        save = arg;
    _argv[_argc++] = save;
}

/*----------------------------------------------------------------------
 * expand - dummy wildcard expansion routine
 */
void expand(char *arg)
{
    _addarg(arg, 0);        /* add argument without making a copy */
}
