/*------------------------------------------------------------------------
 * filename - exit.c
 *
 * function(s)
 *      __exit  - handle the four flavors of exit
 *      exit    - terminate program
 *      _exit   - quick termination
 *      _cexit  - perform exit cleanup without termination
 *      _c_exit - perform quick exit cleanup without termination
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

#include <stdlib.h>
#include <stdio.h>
#include <_stdio.h>
#include <_malloc.h>    /* _virt_release() */

extern void _terminate( int );          /* terminate program */
extern void _cleanup( void );           /* call #pragma exit routines */

static  void    dummy(void) {}

void    (*_exitbuf)(void)   = dummy;
void    (*_exitfopen)(void) = dummy;
void    (*_exitopen)(void)  = dummy;
extern  void (*__pCallAtExitProcs) (void); /* Handled in atexit.c now */

#if defined(__MT__)
void _cleanup_handle_locks(void);
void _cleanup_stream_locks(void);
#endif

/*---------------------------------------------------------------------------*

Name            __exit - perform cleanup and optionally terminate the program

Usage           void __exit(int quick, int dontexit, int errcode);

Prototype in    local

Description     __exit is an internal routine used by the various flavors
                of exit.  If the "quick" flag is false, buffered output
                (waiting to be output) is written to files, any registered
                "exit functions"  (posted with atexit) are called, and
                #pragma exit functions are called.

                In all cases, interrupt vectors taken by the RTL are
                restored, and in small and medium models, stray NULL pointers
                are checked for by seeing if the copyright message
                got zapped.

                Finally, if the "dontexit" flag is false, all files
                are closed, and the program is terminated with the
                error code "errcode".

Return value    If dontexit is false, __exit never returns; otherwise
                it returns no value.

*----------------------------------------------------------------------------*/

static void __exit(int quick, int dontexit, int errcode)
{
    _lock_exit();
    if (!quick)
    {
        /* Execute "atexit" functions
         */
         if (__pCallAtExitProcs)
             __pCallAtExitProcs();

        /* First run #pragma exit routines...
         */
        _cleanup();

        /* ... Then Flush files.
         */
        (*_exitbuf)();

    }
    else
    {
        /* Unhook the atexit handler function.  Since quick was specified, we
           don't want any atexit procs called now, or later if we're using the
           RTLDLL.
        */
        __pCallAtExitProcs = NULL;
    }

    if (!dontexit)
    {
        if (!quick)
        {
            (*_exitfopen)();    /* close stream files */
            (*_exitopen)();     /* close handle files */
        }
        _unlock_exit();
        /* Optionally release virtual memory here
	 */
#if defined(__MT__)
        /*
          These functions free the memory for the locks so the CG doesn't
          complain.
        */
        _cleanup_handle_locks();
        _cleanup_stream_locks();
#endif
        _terminate(errcode);    /* terminate program */
    }
    _unlock_exit();
}

/*---------------------------------------------------------------------------*

Name            exit - terminates program

Usage           void exit(int status);

Prototype in    process.h and stdlib.h

Related
functions usage void _exit(int status);
                void _cexit(void);
                void _c_exit(void);

Description     exit  terminates the  calling process.  Before exiting, all
                files are closed, buffered output (waiting to be output) is
                written, interrupt vectors taken by the startup code are
                restored, and  any registered "exit functions"  (posted with
                atexit) are called.

                status is provided for the  calling process as the the exit
                status of  the process. Typically a  value of 0 is  used to
                indicate a normal exit, and a non-zero value indicates some
                error.

                _exit is "quick" version of exit.  It does everything
                that exit does, except that it doesn't flush files or
                call atexit or #pragma exit routines.

                _cexit is a non-terminating version of exit().  It does
                everything that exit does, except that it doesn't
                close files or terminate the program.

                _c_exit is a non-terminating version of _exit().  It
                does no cleanup and does not terminate the program.

Return value    exit and _exit never return.  _cexit and _c_exit do
                not return a value.

*----------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC exit(int c)
{
    __exit(0,0,c);
}

void _RTLENTRY _EXPFUNC _exit(int c)
{
    __exit(1,0,c);
}

void _RTLENTRY _EXPFUNC _cexit(void)
{
    __exit(0,1,0);
}

void _RTLENTRY _EXPFUNC _c_exit(void)
{
    __exit(1,1,0);
}
