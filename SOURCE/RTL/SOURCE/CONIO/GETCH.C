/*---------------------------------------------------------------------------
 * filename - getch.c
 *
 * function(s)
 *        getch   - gets character from console
 *        ungetch - ungets character to console
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $        */

#include <stdio.h>      /* EOF definition */
#include <malloc.h>
#include <_keys.h>

int _cextend = -1;                /* Used for the scan code of an extended key */

/*----------------------------------------------------------------------
 * The following table maps NT virtual keycodes to PC BIOS keyboard
 * values.  For each virtual keycode there are four possible BIOS
 * values: normal, shift, Ctrl, and ALT.  Key combinations that have
 * no BIOS equivalent have a value of -1, and are ignored.  Extended
 * (non-ASCII) key values have bit 8 set to 1 using the EXT macro
 * (in _keys.h).
 */

static struct kbd kbdtab [] =
{
/*    Virtual key   Normal      Shift       Control     Alt */

    { VK_BACK,      0x08,       0x08,       0x7f,       EXT(14)  },
    { VK_TAB,       0x09,       EXT(15),    EXT(148),   EXT(165) },
    { VK_RETURN,    0x0d,       0x0d,       0x0a,       EXT(166) },
    { VK_ESCAPE,    0x1b,       0x1b,       0x1b,       EXT(1)   },
    { VK_SPACE,     0x20,       0x20,       EXT(3),     0x20,    },
    { '0',          '0',        ')',        -1,         EXT(129) },
    { '1',          '1',        '!',        -1,         EXT(120) },
    { '2',          '2',        '@',        EXT(3),     EXT(121) },
    { '3',          '3',        '#',        -1,         EXT(122) },
    { '4',          '4',        '$',        -1,         EXT(123) },
    { '5',          '5',        '%',        -1,         EXT(124) },
    { '6',          '6',        '^',        0x1e,       EXT(125) },
    { '7',          '7',        '&',        -1,         EXT(126) },
    { '8',          '8',        '*',        -1,         EXT(127) },
    { '9',          '9',        '(',        -1,         EXT(128) },

    { 'A',          'a',        'A',        0x01,       EXT(30)  },
    { 'B',          'b',        'B',        0x02,       EXT(48)  },
    { 'C',          'c',        'C',        0x03,       EXT(46)  },
    { 'D',          'd',        'D',        0x04,       EXT(32)  },
    { 'E',          'e',        'E',        0x05,       EXT(18)  },
    { 'F',          'f',        'F',        0x06,       EXT(33)  },
    { 'G',          'g',        'G',        0x07,       EXT(34)  },
    { 'H',          'h',        'H',        0x08,       EXT(35)  },
    { 'I',          'i',        'I',        0x09,       EXT(23)  },
    { 'J',          'j',        'J',        0x0a,       EXT(36)  },
    { 'K',          'k',        'K',        0x0b,       EXT(37)  },
    { 'L',          'l',        'L',        0x0c,       EXT(38)  },
    { 'M',          'm',        'M',        0x0d,       EXT(50)  },
    { 'N',          'n',        'N',        0x0e,       EXT(49)  },
    { 'O',          'o',        'O',        0x0f,       EXT(24)  },
    { 'P',          'p',        'P',        0x10,       EXT(25)  },
    { 'Q',          'q',        'Q',        0x11,       EXT(16)  },
    { 'R',          'r',        'R',        0x12,       EXT(19)  },
    { 'S',          's',        'S',        0x13,       EXT(31)  },
    { 'T',          't',        'T',        0x14,       EXT(20)  },
    { 'U',          'u',        'U',        0x15,       EXT(22)  },
    { 'V',          'v',        'V',        0x16,       EXT(47)  },
    { 'W',          'w',        'W',        0x17,       EXT(17)  },
    { 'X',          'x',        'X',        0x18,       EXT(45)  },
    { 'Y',          'y',        'Y',        0x19,       EXT(21)  },
    { 'Z',          'z',        'Z',        0x1a,       EXT(44)  },

    { VK_PRIOR,     EXT(73),    EXT(73),    EXT(132),   EXT(153) },
    { VK_NEXT,      EXT(81),    EXT(81),    EXT(118),   EXT(161) },
    { VK_END,       EXT(79),    EXT(79),    EXT(117),   EXT(159) },
    { VK_HOME,      EXT(71),    EXT(71),    EXT(119),   EXT(151) },
    { VK_LEFT,      EXT(75),    EXT(75),    EXT(115),   EXT(155) },
    { VK_UP,        EXT(72),    EXT(72),    EXT(141),   EXT(152) },
    { VK_RIGHT,     EXT(77),    EXT(77),    EXT(116),   EXT(157) },
    { VK_DOWN,      EXT(80),    EXT(80),    EXT(145),   EXT(160) },
    { VK_INSERT,    EXT(82),    EXT(82),    EXT(146),   EXT(162) },
    { VK_DELETE,    EXT(83),    EXT(83),    EXT(147),   EXT(163) },
    { VK_NUMPAD0,   '0',        EXT(82),    EXT(146),   -1       },
    { VK_NUMPAD1,   '1',        EXT(79),    EXT(117),   -1       },
    { VK_NUMPAD2,   '2',        EXT(80),    EXT(145),   -1       },
    { VK_NUMPAD3,   '3',        EXT(81),    EXT(118),   -1       },
    { VK_NUMPAD4,   '4',        EXT(75),    EXT(115),   -1       },
    { VK_NUMPAD5,   '5',        EXT(76),    EXT(143),   -1       },
    { VK_NUMPAD6,   '6',        EXT(77),    EXT(116),   -1       },
    { VK_NUMPAD7,   '7',        EXT(71),    EXT(119),   -1       },
    { VK_NUMPAD8,   '8',        EXT(72),    EXT(141),   -1       },
    { VK_NUMPAD9,   '9',        EXT(73),    EXT(132),   -1       },
    { VK_MULTIPLY,  '*',        '*',        EXT(150),   EXT(55)  },
    { VK_ADD,       '+',        '+',        EXT(144),   EXT(78)  },
    { VK_SUBTRACT,  '-',        '-',        EXT(142),   EXT(74)  },
    { VK_DECIMAL,   '.',        '.',        EXT(83),    EXT(147) },
    { VK_DIVIDE,    '/',        '/',        EXT(149),   EXT(164) },
    { VK_F1,        EXT(59),    EXT(84),    EXT(94),    EXT(104) },
    { VK_F2,        EXT(60),    EXT(85),    EXT(95),    EXT(105) },
    { VK_F3,        EXT(61),    EXT(86),    EXT(96),    EXT(106) },
    { VK_F4,        EXT(62),    EXT(87),    EXT(97),    EXT(107) },
    { VK_F5,        EXT(63),    EXT(88),    EXT(98),    EXT(108) },
    { VK_F6,        EXT(64),    EXT(89),    EXT(99),    EXT(109) },
    { VK_F7,        EXT(65),    EXT(90),    EXT(100),   EXT(110) },
    { VK_F8,        EXT(66),    EXT(91),    EXT(101),   EXT(111) },
    { VK_F9,        EXT(67),    EXT(92),    EXT(102),   EXT(112) },
    { VK_F10,       EXT(68),    EXT(93),    EXT(103),   EXT(113) },
    { VK_F11,       EXT(133),   EXT(135),   EXT(137),   EXT(139) },
    { VK_F12,       EXT(134),   EXT(136),   EXT(138),   EXT(140) },
    { 0xdc,         '\\',       '|',        0x1c,       EXT(43)  },
    { 0xbf,         '/',        '?',        -1,         EXT(53)  },
    { 0xbd,         '-',        '_',        0x1f,       EXT(130) },
    { 0xbb,         '=',        '+',        -1,         EXT(131) },
    { 0xdb,         '[',        '{',        0x1b,       EXT(26)  },
    { 0xdd,         ']',        '}',        0x1d,       EXT(27)  },
    { 0xba,         ';',        ':',        -1,         EXT(39)  },
    { 0xde,         '\'',       '"',        -1,         EXT(40)  },
    { 0xbc,         ',',        '<',        -1,         EXT(51)  },
    { 0xbe,         '.',        '>',        -1,         EXT(52)  },
    { 0xc0,         '`',        '~',        -1,         EXT(41)  },

    { -1,           -1,         -1,         -1,         -1       }  /** END **/
};

/*--------------------------------------------------------------------------*

Name            __lookup_key - checks for a valid scancode

Usage           struct kbd *__lookup_key (int keycode);

Prototype in    _keys.h

Returns         NULL if keycode is not in the table,
                else the located kbd structure.

Notes:          This is an internal helper function.  It is used externally
                from KBHIT.C

*---------------------------------------------------------------------------*/

struct kbd * _RTLENTRY __lookup_key (int keycode)
{
    struct kbd *k;

    /* Look up the virtual keycode in the table.  Ignore
     * unrecognized keys.
     */
    for (k = &kbdtab[0]; keycode != k->keycode && k->keycode != -1; k++)
        ;

    if (k->keycode == -1)       /* value not in table */
        return NULL;

    return k;
}

int _RTLENTRY __xlat_key (INPUT_RECORD *inp, struct kbd *k)
{
    int c;
    int state, keycode;

    keycode = inp->Event.KeyEvent.wVirtualKeyCode;
    state   = inp->Event.KeyEvent.dwControlKeyState;

    /* Check the state of the shift keys.  ALT has highest
     * priority, followed by Control, followed by Shift.
     * Select the appropriate table entry based on shift state.
     */
    if (state & (RIGHT_ALT_PRESSED | LEFT_ALT_PRESSED))
        c = k->alt;
    else if (state & (RIGHT_CTRL_PRESSED | LEFT_CTRL_PRESSED))
        c = k->ctrl;
    else if (state & SHIFT_PRESSED)
        c = k->shift;
    else
    {
        /* If it is a letter key, use the ASCII value supplied
         * by NT to take into account the CapsLock state.
         */
        if (keycode >= 'A' && keycode <= 'Z')
            c = inp->Event.KeyEvent.uChar.AsciiChar;
        else
            c = k->normal;
    }

    return c;
}

int _RTLENTRY _EXPFUNC __flush_win95_keyup_events (void)
{
    INPUT_RECORD *pinp, *poutp;
    DWORD nread, nevents, j, k, total = 0;

    /* Get the number of pending input records */
    GetNumberOfConsoleInputEvents(_hin, &nevents);

    if (nevents == 0)
        return total;

    pinp  = alloca (sizeof (INPUT_RECORD) * nevents);
    poutp = alloca (sizeof (INPUT_RECORD) * nevents);

    /* Read all the pending records */
    ReadConsoleInput(_hin, pinp, nevents, &nread);

    /* Cycle through the records looking for invalid Win95 key presses */
    for (k=0, j = 0;j<nevents;j++)
    {
        if ((pinp[j].EventType & KEY_EVENT) != 0)
            if (pinp[j].Event.KeyEvent.bKeyDown == 0)  /* Key up */
            {
                total++;
                continue;  /* Don't copy this record into the output array */
            }

        poutp[k++] = pinp[j];
    }
    FlushConsoleInputBuffer (_hin);  /* Just to be sure it's empty */
    if (k)
    {
        WriteConsoleInput (_hin, poutp, k, &nevents);
    }
    return total;
}

/*--------------------------------------------------------------------------*

Name            getch - gets character from console

Usage           int getch(void);

Prototype in    conio.h

Description     getch is a function that reads a single character directly
                from the console, without echoing.

Return value    getch and getche return the character read. There is no
                error return for these two functions.

*---------------------------------------------------------------------------*/
int _RTLENTRY _EXPFUNC getch(void)
{
    INPUT_RECORD inp;
    DWORD nread, nevents;
    DWORD kbdmode;
    struct kbd *k;
    int keycode, state, c;

    /* If a previous ungetch() call has been performed, return
     * the key that it saved.
     */
    if (_cFlag)                     /* Previous ungetch? */
    {
        _cFlag = 0;                 /* Reset the flag   */
        return (_cChar & 0xff);     /* Get the un-got char  */
    }

    /* If a previous call returned an extended code, return
     * the scan code for the key.
     */
    if (_cextend != -1)
    {
        c = _cextend;
        _cextend = -1;                /* Reset the flag */
        return c;                   /* Return the extended scancode */
    }

    /* Get the keyboard mode, then set it to binary mode.
     * This is done to prevent NT from handling control keys
     * like Control-C and Control-S.
     */
    if (GetConsoleMode(_hin, &kbdmode) != TRUE)
    {
        return -1;
    }

    if (SetConsoleMode(_hin, 0 ) != TRUE)
    {
        return -1;
    }

    /* Get keyboard events until a recognizable one appears.
     */
    for (;;)
    {
        if (ReadConsoleInput(_hin, &inp, 1, &nread) != TRUE)
        {
            c = -1;
            break;
        }
        else if ((inp.EventType==KEY_EVENT) && inp.Event.KeyEvent.bKeyDown)
        {
            keycode = inp.Event.KeyEvent.wVirtualKeyCode;
            state   = inp.Event.KeyEvent.dwControlKeyState;

            if (inp.Event.KeyEvent.uChar.AsciiChar)
            {
                c = inp.Event.KeyEvent.uChar.AsciiChar;
                break;
            }

            /* Look up the virtual keycode in the table.  Ignore
             * unrecognized keys.
             */
            k = __lookup_key (keycode);

            if (!k)       /* value not in table */
                continue;

            c = __xlat_key (&inp, k);  /* translate into the proper char */

            if (c == -1)
                continue;               /* no BIOS equivalent */

            /* If it is an extended key, save the key value and
             * return 0.  The next time we're called, we'll return
             * the key value.
             */
            if (ISEXT(c))
            {
                _cextend = EXTVAL(c);
                c = 0;
            }
            break;
        }
    }

    /* Change the keyboard back to its original mode.
     */
    if (SetConsoleMode(_hin, kbdmode) != TRUE)
    {
        return -1;
    }

#if 0  /* Don't flush now since the keyup event may not even be in the queue
          yet.  This function can be called by the user later if needed.
        */
    __flush_win95_keyup_events ();
#endif

    return c;
}

/*--------------------------------------------------------------------------*

Name            ungetch - ungets character to console

Usage           int ungetch(int c);

Prototype in    conio.h

Description     ungetch pushes the character c back to the console,
                causing c to be the next character read. The ungetch
                function fails if it is called more than once before
                the next read.

Return value    ungetch returns the character c if it is successful.
                return value of EOF indicates an error.

*---------------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC ungetch(int c)
{
    if (_cFlag)
        return(EOF);

    _cFlag = 1;
    return ((_cChar = c) & 0xff);
}
