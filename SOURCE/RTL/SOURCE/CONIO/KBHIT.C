/*-----------------------------------------------------------------------*
 * filename - kbhit.c
 *
 * function(s)
 *        kbhit - checks for recent keystrokes
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <_keys.h>
#include <malloc.h>

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
    INPUT_RECORD *pinp;
    DWORD keycode, nread, nevents, j;
    struct kbd *k;
    int c;

    if (_cFlag)             /* has a character been ungetch'd? */
        return (1);

    if (_cextend != -1)
        return (1);         /* last char was a 0 signifing that next one will
                               be the scan code of an extended key */

    /* Get the number of pending input records */
    GetNumberOfConsoleInputEvents(_hin, &nevents);

    if (nevents == 0)
        return 0;

    pinp = alloca (sizeof (INPUT_RECORD) * nevents);

    /* Read all the pending records */
    PeekConsoleInput(_hin, pinp, nevents, &nread);

    /* Cycle through the records looking for valid key presses */
    for (j = 0;j<nevents;j++)
        if ((pinp[j].EventType & KEY_EVENT) != 0)
            if (pinp[j].Event.KeyEvent.bKeyDown != 0)
            {
                keycode = pinp[j].Event.KeyEvent.wVirtualKeyCode;

                /* We must ignore <Shift>, <Ctrl>, and <Alt> key events when
                   announcing a pressed key, but leave them in the buffer so
                   they will be recoginized later when we pull them out with
                   getch()
                */
                if ((keycode == VK_SHIFT)   ||
                    (keycode == VK_CONTROL) ||
                    (keycode == VK_MENU))
                      continue;
                else
                {
                    if ((k = __lookup_key (keycode)) != NULL)
                    {
                        if (__xlat_key (&pinp[j], k) != -1)
                            return 1;
                    }
                }
            }

    return 0;
}
