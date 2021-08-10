/*------------------------------------------------------------------------
 * filename - ctrlbrk.c
 *
 * function(s)
 *        hentry  - hook to call user's control break handler
 *        ctrlbrk - sets control-break handler
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#define INCL_CON
#include <ntbc.h>
#include <dos.h>
#include <stdlib.h>

static  int     (*Hfunc)(void);

/*---------------------------------------------------------------------*

Name            hentry - hook to call user's control break handler

Usage           static  void interrupt far hentry();

Prototype in    local to this module

Description     interprets the return value from the ctrl break
                handler

Return value    nothing

*---------------------------------------------------------------------*/

static BOOL __stdcall hentry(DWORD dwCtrlType)
{
        switch  (dwCtrlType)
        {
        case CTRL_C_EVENT:
        case CTRL_BREAK_EVENT:
            if  (!(*Hfunc)())
                _exit(0);
            break;

        default:
            return FALSE;
        }

        return TRUE;
}


/*--------------------------------------------------------------------------*

Name            ctrlbrk - sets control-break handler

Usage           void ctrlbrk(int (*fptr)(void));

Prototype in    dos.h

Description     ctrlbrk sets  a new control-break handler  function pointed
                to by fptr.  

                The  named   function  is  not  called   directly.  ctrlbrk
                establishes a  control event  handler  that calls the  named
                function.

Return value    ctrlbrk returns nothing. The  handler function returns 0 to
                abort the current  program; any other value will  cause the
                program to resume execution.

*---------------------------------------------------------------------------*/
void    ctrlbrk(int (*fptr)())
{
        Hfunc = fptr;

        SetConsoleCtrlHandler(hentry, TRUE);
}
