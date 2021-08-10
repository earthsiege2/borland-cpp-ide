/*-----------------------------------------------------------------------*
 * filename - setargv.c
 *
 * function(s)
 *        _setargv  - set up argv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

/* Set up argv[] from the command line.  If wildargs.obj is included, wildcard
 * filenames are expanded; see wild.c for more information.
 */

#include <dir.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>

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
#if defined(__DPMI16__)
extern int    _C0argc;
extern char **_C0argv;
#endif

extern char *   _argv0;
extern unsigned _pszCmdline;

/*----------------------------------------------------------------------
 * Argument vector and count.
 */
int     _argc;        /* number of arguments */
char ** _argv;        /* argument vector */

/*----------------------------------------------------------------------
 * Local variables
 */
static int argmax;          /* maximum size of _argv[] */
static char *cmdLineCopy;

/*----------------------------------------------------------------------
 * Forward declarations
 */
void        _addarg(char *, int);
void        _errorExitBox(const char *msg, int code);
static void copychar(char **, char **);


/*----------------------------------------------------------------------
 * Pointer to wildcard expansion function.  Normally it points to a
 * function that simply adds an argument without expansion, but if
 * wildargs.obj is included, it is set to point to a real expansion
 * function.
 */
#if defined(__DPMI16__)
void (* _EXPDATA _expandptr)(char *);
#endif

/*----------------------------------------------------------------------
 * is_space - check for space or tab character
 *
 * This macro is defined locally in order to avoid using ctype.h.
 */
#define is_space(p) ((p) ==' ' || (p) =='\t')


/*----------------------------------------------------------------------
 * no. of elemements added to _argv[] each time it is grown
 */
#define ARGVCHUNK 16

/*----------------------------------------------------------------------
 * maximum length of commandline
 */
#define MAXCMDLINE 128

/*----------------------------------------------------------------------
 * _setargv  - set up _argc and _argv
 *
 * This function is called by the startup code before main() is called.
 * It parses the command line into tokens, storing pointers to the
 * tokens in _argv[].  Tokens that aren't quoted and contain wild-card
 * characters are expanded to all matching files (only if WILDARGX.OBJ
 * has been included, causing _expandptr to be modified).
 */
void _setargv(void)
{
    char *src = 0;
    char *dst, *arg;
    char _oscmd[MAXCMDLINE];    /* Store a copy of the command line. */
    char far *_oscmdline;       /* Points to the real command line.  */

    if  (*(_oscmdline = MK_FP(_psp, _pszCmdline)) != 0)
    {
        src = _oscmd;
        while  (*_oscmdline != '\r' && *_oscmdline != '\0')
            *src++ = *_oscmdline++;
        *src = 0;
    }

    _argc = argmax = 0;
    _argv = NULL;

    /* Note that we never allocate a new block for argv[0], we rely on this behavior
     * to free memory at exit.  If you change this then fix the cleanup code in SETARGV0.C
     */
    _addarg(_argv0, 0);

    if  (src)
    {
        src = _oscmd;

        while (is_space(*src))          /* skip leading white space */
            src++;

        /* Allocate space for a copy of the command line.  We could modify
         * the command line in place, but some programs might want to look
         * at it unmodified.
         */
        if ((cmdLineCopy = dst = malloc(strlen(src)+1)) == NULL)
            _errorExitBox("No space for copy of command line", 3);

        /* Add each argument from the command line to the argument list.
         */
        while (*src != '\0')
        {
    #if defined(__DPMI16__)
            int do_expand = 0;
    #endif

            while (is_space(*src))      /* ignore spaces between arguments */
                src++;
            if (*src == '\0')           /* quit at end of line */
                break;

            /* An argument consists of all text up to the
             * next whitespace character.
             */
            arg = dst;                  /* save start of argument */
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
    #if defined(__DPMI16__)
                    if (*src == '*' || *src == '?')
                        do_expand = 1;          /* wildcard character seen */
    #endif
                    copychar(&dst, &src);       /* copy until next whitespace */
                }
            }
            *dst++ = '\0';              /* terminate the string */

    #if defined(__DPMI16__)
            if  (do_expand && _expandptr)
                (*_expandptr)(arg);
            else
    #endif
                _addarg(arg, 0);
            if (*src == '\0')           /* quit at end of line */
                break;
            src++;                      /* skip token terminator */
        }
    }

    _addarg(NULL, 0);                   /* add a dummy NULL argument */
    _argc--;                            /* but don't count it */

#if defined(__DPMI16__)
    _C0argc = _argc;                    /* startup code expects args */
    _C0argv = _argv;                    /*  in these variables */
#endif
}

#pragma startup _setargv 10   // NOTE:  Must be executed after _setenv (8)


/*
 *  Release _argv
 */
static void _rlsargv(void)
{
    if (_argv)
	free(_argv);
    if (cmdLineCopy)
	free(cmdLineCopy);
}

#pragma exit _rlsargv 10


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
            _errorExitBox("No space for command line argument vector", 3);
    }

    /* If the makecopy flag is non-zero, allocate space for the new argument
     * and copy it.  Then add the argument to the end of _argv[].
     */
    if (makecopy)
    {
        if ((save = malloc(strlen(arg)+1)) == NULL)
            _errorExitBox("No space for command line argument", 3);
        strcpy(save,arg);
    }
    else
        save = arg;
    _argv[_argc++] = save;
}

