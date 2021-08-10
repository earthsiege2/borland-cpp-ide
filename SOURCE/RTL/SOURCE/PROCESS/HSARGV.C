/*-----------------------------------------------------------------------*
 * filename - hsargv.c
 *
 * The default handler for setting the argv array
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.6.2.1 $        */

#include <_setargv.h>
#include <_io.h>
#include <alloc.h>

static _TCHAR *_tcmdsave;

static void _tcopychar(_TCHAR **, _TCHAR**);

/*----------------------------------------------------------------------
 * _cmdline_escapes is a global variable that determines whether or not
 * double backslashes at the command line are treated as escapes yielding
 * only a single backslash. (Note: backslash quote is already special-cased)
 */
#if !defined(_UNICODE)
int _RTLENTRY _EXPDATA _cmdline_escapes = 0;
#else
extern int _RTLENTRY _EXPDATA _cmdline_escapes;
#endif

/*----------------------------------------------------------------------
 * is_space - check for space or tab character
 *
 * This macro is defined locally in order to avoid using ctype.h.
 */
#define is_wspace(p) ((p) ==_TEXT(' ') || (p) ==_TEXT('\t'))

/*----------------------------------------------------------------------
 * _thandle_setargv - Process the entire commandline (cmdline), calling
 *                      pfn_addarg to chain each one on to the list.
 */

int _RTLENTRY _EXPFUNC _thandle_setargv(_TCHAR *_argv0, _TCHAR *_cmdline, _PFN_ADDARG _pfn_addarg)
{
    _TCHAR *src = _cmdline, *dst, *arg;

    _pfn_addarg(_argv0, 0);                /* Add in the exe name */

    while (is_wspace(*src))                /* skip leading white space */
        src++;
    if (*src == _TEXT('"'))                /* check for quoted program name */
    {
        ++src;                             /* skip leading quote */
        while (*src != _TEXT('"') && *src != _TEXT('\0'))
            src++;                         /* skip the part in quotes */
        if (*src == _TEXT('"'))            /* skip trailing quote */
            ++src;
    }
    else
        while (!is_wspace(*src) && *src != _TEXT('\0')) /* skip program name */
            src++;

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

        while (is_wspace(*src))            /* ignore spaces between args */
            src++;
        if (*src == _TEXT('\0'))           /* quit at end of line */
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
            _targv_expand_ptr(arg, _pfn_addarg); /* call thru ptr to expand it */
        else
            _pfn_addarg(arg, 0);         /* don't expand it, just add it to the array */
        if (*src == _TEXT('\0'))        /* quit at end of line */
            break;
        src++;                          /* skip token terminator */
    }
    return 1;  /* Signal success to the caller */
}

/*----------------------------------------------------------------------
 * _thandle_exitargv - Perform any memory clean up as needed.
 */
void _RTLENTRY _EXPFUNC _thandle_exitargv(void)
{
    if (_tcmdsave)
    {
        free(_tcmdsave);
        _tcmdsave = NULL;
    }
}

/*----------------------------------------------------------------------
 * copychar -  copy next character from command line
 * wcopychar - copy next wide-character from command line
 *
 * Read the character pointed to by **src, store it at **dst.
 * Handle escaped quote (\") by skipping the backslash.
 * Handle escaped backslash (\\) by skipping the first backslash.
 * Advance *src and *dst to point to the next character.
 */
static void _tcopychar(_TCHAR **dst, _TCHAR **src)
{
    if ((*src)[0] == _TEXT('\\') && (*src)[1] == _TEXT('"'))
    {
        **dst = _TEXT('"');
        *src += 2;
    }
    else
    if ((_cmdline_escapes) &&
        ((*src)[0] == _TEXT('\\') && (*src)[1] == _TEXT('\\')))
    {
        **dst = _TEXT('\\');
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
