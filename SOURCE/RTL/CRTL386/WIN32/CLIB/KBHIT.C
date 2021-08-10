/*-----------------------------------------------------------------------*
 * filename - kbhit.c
 *
 * function(s)
 *        kbhit - checks for recent keystrokes
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_CON
#define INCL_USER
#include <ntbc.h>

#include <conio.h>

/* The following variables are used in getch.c */

unsigned char _cFlag = 0;       /* Flag presence of un-gotten char */
unsigned char _cChar = 0;       /* The ungotten char               */

/*-----------------------------------------------------------------------*

Name            kbhit - checks for recent keystrokes

Usage           int kbhit(void);

Prototype in    conio.h

Description     kbhit checks to see if a keystroke is currently
                available. Any available keystrokes can be retrieved with
                getch or getche.

Return value    If a keystroke is available, kbhit returns a
                non-zero integer. If not, it returns 0.

*------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC kbhit(void)
{
    INPUT_RECORD inp;
    DWORD nread, nevents;
    HANDLE hin;

    if (_cFlag)             /* has a character been ungetch'd? */
        return (1);

    hin = GetStdHandle(STD_INPUT_HANDLE);

    /* Discard console events until we come to a keydown event,
     * or the event queue is empty.
     */
    while (GetNumberOfConsoleInputEvents(hin, &nevents) == TRUE && nevents > 0)
    {
        /* Take a look at the first input event in the queue.
         * If we can't peek at it, something bad happened.
         */
        if (PeekConsoleInput(hin, &inp, 1, &nread) != TRUE)
            break;

        /* If the event is a key-down, a key has been hit.
         */
        if ((inp.EventType & KEY_EVENT) != 0 &&
             inp.Event.KeyEvent.bKeyDown != 0)
            return (1);

        /* It's not a key-down event, discard it.
         * NOTE: this discards all other console input events, including
         * mouse events!  Thus, kbhit() should not be used in programs
         * that track the mouse or window resizing.
         */
        if (ReadConsoleInput(hin, &inp, 1, &nread) != TRUE)
            break;
    }
    return (0);
}
