/*---------------------------------------------------------------------------
 * filename - cgets.c
 *
 * function(s)
 *        cgets - reads string from console
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#if 0
#define INCL_KBD
#include <os2bc.h>

#define KBD_ASC_MODE (KEYBOARD_ECHO_ON | KEYBOARD_ASCII_MODE)
#endif

#include <conio.h>

#if defined(_MBCS)
#include <mbctype.h>
#include <mbstring.h>
#endif

/*--------------------------------------------------------------------------*

Name            cgets - reads string from console

Usage           char *cgets(char *string);

Prototype in    conio.h

Description     cgets reads a string of characters from the console,
                storing the string (and the string length) in the
                location pointed to by string.

                cgets reads characters until it encounters a CR/LF or
                until the maximum allowable number of characters have
                been read.

                Before cgets is called, string[0] should be set to the
                maximum length of the string to be read.

Return value    string[1] is set to the number of characters actually
                read.
                &string[2], a pointer to the string of characters that
                were read.  There is no error return.

*---------------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC cgets(char *s)
{
#if 0
    KBDINFO     kinfo;
    STRINGINBUF string;
    int         changed_mode;
    USHORT      old_mask;

    /* Force the keyboard into ASCII mode so that a <CR> will 
     * terminate the string read.  Set keyboard to ECHO.
     */
    kinfo.cb = sizeof(kinfo);
    if (KbdGetStatus(&kinfo,0) == 0 && 
       (kinfo.fsMask & KBD_ASC_MODE) != KBD_ASC_MODE)
    {
        changed_mode = 1;
        old_mask = kinfo.fsMask;
        kinfo.fsMask = KBD_ASC_MODE;
        KbdSetStatus(&kinfo,0);
    }
    else
        changed_mode = 0;


    string.cb = (USHORT)(s[0] & 0xff);

    if (KbdStringIn(&s[2], &string, 0, 0) == 0)
    {
        s[1] = (char) string.cb;     /* Set return length    */
        s[string.cchIn + 2] = 0;     /* Null terminate string*/
    }
    else    /* failure */
        s[1] = s[2] = 0;             /* Zero length string   */

    /* If we changed the keyboard mode to binary mode earlier,
     * change it back to its original mode.
     */
    if (changed_mode)
    {
        kinfo.fsMask = old_mask;
        KbdSetStatus(&kinfo, 0);
    }

    return (s+2);
#else
    int c, len, maxlen;
    char *p = s + 2;
#if defined(_MBCS)
    char pending_dbcs_flag = 0;
#endif

    len = 0;
    maxlen = s[ 0 ] & 0xff;

    for (;;)
    {
        switch (c = getch())
        {
        case 0:     
            if( getch() != 75 )     /* keypad left arrow same as \b */
                break;

        case '\b':
            if( len )  
            {
#if defined(_MBCS)
                if ( pending_dbcs_flag == 0 && len >= 2 &&
                     _mbsbtype(s+2, (p-1)-(s+2)) == _MBC_TRAIL)
                {
                    putch( '\b' );
                    putch( ' ' );
                    putch( '\b' );
                    --len;
                    --p;
                }
                pending_dbcs_flag = 0;
#endif
                putch( '\b' );
                putch( ' ' );
                putch( '\b' );
                --len;
                --p;
            }
            break;

        case '\r':
            *p = '\0';
            s[ 1 ] = len;   
            return( s + 2 );

        default:
#if defined(_MBCS)
            if( pending_dbcs_flag )
            {
                /* DBCS character 2nd byte */
                pending_dbcs_flag = 0;
            }
            else if( _ismbblead( c ) )
            {
                /* DBCS character 1st byte */
                if( len + 2 >= maxlen )
                {
                    (void)getch();  /* drop 2nd byte */
                    break;          /* buffer full */
                }
                pending_dbcs_flag = 1;
            }
            else
            {
                /* SBCS */
                if( len + 1 >= maxlen )
                    break;          /* buffer full */
            }
            putch(c);
            *p++ = c;
            ++len;
            break;
#else
            if( len < maxlen - 1 )
            {
                putch(c);
                *p++ = c;
                ++len;
            }
#endif
        }
    }
#endif
}
