/*---------------------------------------------------------------------------
 * filename - getch.c
 *
 * function(s)
 *        getche  - gets character from console with echo
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <conio.h>

/* The following two variables are located in kbhit.c. */

extern unsigned char _cFlag;    /* Flag presence of un-gotten char */
extern unsigned char _cChar;    /* The ungotten char               */

/*--------------------------------------------------------------------------*

Name            getche - gets character from console with echo

Usage           int getche(void);

Prototype in    conio.h

Description     getche is a function that reads and echoes a single
                character from the console.

Return value    getch and getche return the character read. There is no
                error return for these two functions.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC getche(void)
{
    int ch;

    if (_cFlag)         /* Prevent possible double echoing */
        ch = getch();
    else
        putch(ch = getch());

    return ch;
}
