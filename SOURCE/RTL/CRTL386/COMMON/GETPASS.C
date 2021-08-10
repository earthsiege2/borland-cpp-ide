/*-----------------------------------------------------------------------*
 * filename - getpass.c
 *
 * function(s)
 *        _KbdFlush - flushes the keyboard buffer
 *        getpass   - reads a password
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef _MT
#include <_thread.h>
#endif
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------------*

Name            _KbdFlush - flushes the keyboard buffer

Usage           static void _KbdFlush(void);

Description     flushes the keyboard buffer

Return value    nothing

*---------------------------------------------------------------------*/

static void _KbdFlush(void)
{
    while (kbhit())
        getch();
}


/*---------------------------------------------------------------------*

Name            _passbuf - returns address of "static" char array

Usage           static char *_passbuf(void);

Prototype in    local to this module

Description     returns the address of a "static" char array of size
                PASS_MAX+1 that can be used by getpass().
                This array was formerly a static data structure, but
                is now allocated on a per-thread basis.

Return value    a pointer to the buffer

*---------------------------------------------------------------------*/

#ifdef _MT

#define passbuf (char *)THREAD_BUF(passbuf,PASS_MAX+1)

#else

static char passbuf[PASS_MAX+1];

#endif  /* _MT */

/*---------------------------------------------------------------------*

Name            getpass - reads a password

Usage           char *getpass(const char *prompt);

Prototype in    conio.h

Description     getpass reads a password from the system console after
                prompting with the null-terminated string prompt and disabling
                the echo. A pointer is returned to a null-terminated string
                of up to eight characters at most (not counting the
                null-terminator).

Return value    The return value is a pointer to a static string
                which is overwritten with each call.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC getpass(const char *prompt)
{
    char   *cp;
    int    i, c;

    /* Print the prompt message.
     */
    for (cp = (char *)prompt; *cp; cp++)
        putch(*cp);

    /* Flush the keyboard buffer
     */
    _KbdFlush();

    /* Read the password from keyboard without echo
     */
    cp = passbuf;
    i = 0;
    for (;;)
    {
        if ((c = getch()) == '\r')
            break;
        if (c == '\b' || c == 0x7f)     /* control-H or backspace */
        {
            if (i == 0)                 /* already at start of line */
                putch('\a');            /* ring bell */
            else
                i--;                    /* back up current position */
        }
        else                            /* normal character */
        {
            if (i < PASS_MAX)
                cp[i] = c;
            i++;
        }
    }
                
    cp[i > PASS_MAX ? PASS_MAX : i] = '\0'; /* Password is null terminated */
    putch('\r');                        /* Display a new line */
    putch('\n');

    /* Discard any remaining characters.
     */     
    _KbdFlush();
    return(cp);
}
