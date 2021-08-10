/*-----------------------------------------------------------------------*
 * filename - kbhit.c
 *
 * function(s)
 *        kbhit - checks for recent keystrokes
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define INCL_CON
#define INCL_USER
#include <ntbc.h>

#include <conio.h>

#define MAX_INPUT_RECORDS 20

/* The following variables are used in getch.c */

unsigned char _cFlag = 0;       /* Flag presence of un-gotten char */
unsigned char _cChar = 0;       /* The ungotten char               */

extern int _cextend;            /* Used for the scan code of an extended key */
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
    static INPUT_RECORD pinp[MAX_INPUT_RECORDS];
    DWORD nread, nevents, j;
    HANDLE hin;

    if (_cFlag)             /* has a character been ungetch'd? */
        return (1);

    if (_cextend != -1)
        return (1);         /* last char was a 0 signifing that next one will
                               be the scan code of an extended key */

    hin = GetStdHandle(STD_INPUT_HANDLE);

    /* Get the number of pending input records */
    GetNumberOfConsoleInputEvents(hin, &nevents);

    /* Check for limit violations (if > max, return 0 and let the user
       call us again later for further checks)
    */
    if (nevents == 0 || nevents > MAX_INPUT_RECORDS)
        return 0;

    /* Read all the pending records */
    PeekConsoleInput(hin, pinp, nevents, &nread);

    /* Cycle through the records looking for valid key presses */
    for (j = 0;j<nevents;j++)
        if ((pinp[j].EventType & KEY_EVENT) != 0)
            if (pinp[j].Event.KeyEvent.bKeyDown != 0)
            {
                /* We must ignore <Shift>, <Ctrl>, and <Alt> key events when
                   announcing a pressed key, but leave them in the buffer so
                   they will be recoginized later when we pull them out with
                   getch()
                */
                if ((pinp[j].Event.KeyEvent.wVirtualKeyCode == VK_SHIFT)   ||
                    (pinp[j].Event.KeyEvent.wVirtualKeyCode == VK_CONTROL) ||
                    (pinp[j].Event.KeyEvent.wVirtualKeyCode == VK_MENU))
                      continue;
                else
                      return 1;
            }
    return 0;
}
