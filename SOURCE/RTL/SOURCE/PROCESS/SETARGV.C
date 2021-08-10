/*-----------------------------------------------------------------------*
 * filename - setargv.c
 *
 * function(s)
 *        _setargv  - set up argv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.6  $        */

/* Set up argv[] from the command line.  If wildargs.obj is included, wildcard
 * filenames are expanded; see expndarg.c for more information.
 */

#include <ntbc.h>

#include <_io.h>                    /* _ErrorExit */

#define ARGVCHUNK 16                /* no. of elemements added to _argv[] */
                                    /*   each time it is grown */

#include <string.h>
#include <alloc.h>
#include <_setargv.h>

/*----------------------------------------------------------------------
 * The startup code generates an external reference to either __setargv__
 * or __wsetargv__ (depending on whether or not it's a UNICODE program).
 * The following declaration satisfies that reference and forces this
 * module to be linked.
 */
#if !defined(_BUILDRTLDLL)
int _tsetargv__ = 0;
#endif

static void _RTLENTRY _taddarg(_TCHAR *_arg, int _makecopy);


/*----------------------------------------------------------------------
 * Local variables
 */
static int         argmax;          /* maximum size of _argv[] */

_TCHAR ** _EXPDATA _targv;          /* argument vector */

static _TCHAR *    _save_argv0;     /* local copy of the argv[0] string */

/*----------------------------------------------------------------------
 * _setargv  - set up _argc and _argv
 * _wsetargv  - set up _argc and _wargv
 *
 *
 * This function is called via an INIT proc from the startup code before
 * main() is called. It sets up some globals in preparation for calling
 * _tsetargv_ptr which, by default points to _thandle_setargv (in hsargv.c).
 * This default routine (which can be over-ridden by the user to allow for
 * non-standard commandline processing and globbing) parses the command line
 * into tokens, storing pointers to these tokens in _argv[].  The function
 * _taddarg() is called to add tokens into the array.
 */

void _EXPFUNC _tsetargv(void)
{
#if !defined(_BUILDRTLDLL)
#if !defined(_UNICODE)
#pragma startup _setargv 3      /* Initialize the argv processing routines */
#else
#pragma startup _wsetargv 3     /* Initialize the wide argv processing routines */
#endif
#endif

    /* If this is a DLL, or if for some other reason there is no command
       line, then there's nothing to process, so return now.
     */
    if (_toscmd == NULL)
        return;

    /* Initialize variables used by _addarg(). The command name and tail
     * are merged into one string.
     */
    _argc = argmax = 0;
    _targv = NULL;

    /* Note: _exitargv0 (in setargv0.c) cleans up the original _argv0
     *       Here, we make a copy for _argv[0], and clean it up in _exitargv
     */

    _save_argv0 = _tcsdup(_targv0);

    /* Call out to a function that will do the work of building the
     * argv[] list.  This can be set by the user to provide non-standard
     * globbing.  _taddarg() is passed so that this function can call it
     * to add tokens to the _argv[] array.
     */
    if (_tsetargv_ptr(_save_argv0, _toscmd, (_PFN_ADDARG)_taddarg))
    {
        /* argv processing was successful */

        _taddarg(NULL, 0);              /* add a dummy NULL argument to
                                           the end of the argv array */
        _argc--;                        /* but don't count it */
    }
    else
    {
      /* argv processing failed */

      _targv = NULL;
      _argc = 0;
    }

    _C0argc = _argc;                    /* startup code expects args */
    _tC0argv = _targv;                  /*  in these variables */
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
#pragma exit _exitargv 3      /* Finalize the argv processing routines */
#else
#pragma exit _wexitargv 3     /* Finalize the wide argv processing routines */
#endif
#endif


    /* Call out to the user's clean up handler */

    _texitargv_ptr();

    /* If we allocated _argv and _argv[0] clean them up (we won't
       set them up in a DLL).
     */
    if (_targv)
    {
	free(_save_argv0);
	free(_targv);

        /* Protect against accidental double free*/
        _targv = NULL;
    }

}

/*----------------------------------------------------------------------
 * _addarg -  add one argument to _argv list
 * _waddarg - add one wide-character argument to _argv list
 */
static void _RTLENTRY _taddarg(_TCHAR *arg, int makecopy)
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
