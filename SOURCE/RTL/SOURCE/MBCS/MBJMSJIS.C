/*-----------------------------------------------------------------------*
 * filename - mbjmsjis.c
 *
 * function(s)
 *        _mbcjmstojis - Converts a character form Shift-JIS code
 *                       to JIS code.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


#pragma inline
#include <mbstring.h>

extern int _mbcsCodePage;

/*---------------------------------------------------------------------*

Name            _mbcjmstojis - Converts a character form Shift-JIS code
                               to JIS code.

Usage           unsigned int _mbcjmstojis(unsigned int c);

Prototype in    mbstring.h

Desctiption     _mbcjmstojis converts c from Shift-JIS code to JIS code.

Return value    Returns converted code.Returns 0 if it can not be
                converted.

*---------------------------------------------------------------------*/

#if defined(__FLAT__)
unsigned int _RTLENTRY _EXPFUNC _mbcjmstojis(unsigned int c)
{
    register int c1, c2;

    if (_mbcsCodePage  != _KANJI_CP)
        return (c);

#if defined(__FLAT__)
    if (c & 0xFFFF0000)
        return 0;
#endif
    c2 = (unsigned char)c;
    c1 = (unsigned char)(c >> 8);

    /* * Note that 1st byte is grater than 0xef (GAIJI area), */
    /*   it's not translatable JIS code from Shift JIS */

    if (c1 < 0xf0 && _ismbblead(c1) && _ismbbtrail(c2))
    {
        if (c1 >= 0xe0)
            c1 -= 0x40;

        c1 -= 0x70;
        c1 <<= 1;

        if (c2 < 0x9f)
        {
            c1--;
            c2 -= 0x1f;
            if (c2 >= (0x80-0x1f))
                c2--;
        }
        else
            c2 -= 0x7e;

        return ((c1 << 8) | c2);
    }

    return 0;
}
#else
unsigned int _RTLENTRY _EXPFUNC _mbcjmstojis(unsigned int c)
{
#ifdef __FLAT__
asm     mov     eax, c
asm     test    eax, 0FFFF0000H
asm     jnz     _invalid_jis
#else
asm     mov     ax, c
#endif
asm     cmp     ah, 081h
asm     jc      _invalid_jms
asm     cmp     ah, 0a0h
asm     jc      _ok_H
asm     cmp     ah, 0e0h
asm     jc      _invalid_jms
asm     cmp     ah, 0f0h
asm     jnc     _invalid_jms
_ok_H:
asm     cmp     al, 040h
asm     jc      _invalid_jms
asm     cmp     al, 0fdh
asm     jnc     _invalid_jms
asm     cmp     al, 07fh
asm     jz      _invalid_jms

                                /*81..9f,e0..ef,f0..fc  40..7e,80..9e,9f..fc */
asm     cmp     al, 080h        /*                      ==CY==,------nc----- */
asm     adc     al, 061h        /*                      a2..e0,e1..ff,00..5d */
asm     jc      _1              /*                      -----nc------,==CY== */
asm     sub     al, 0a2h        /*                      00..3e,3f..5d        */
_1:                             /*                      --nc--,--nc--,==CY== */
asm     rcl     ah, 1           /*02..3f,c0..df,e0..f9  */
asm     and     ah, 07fh        /*02..3f,40..5f,60..79  */
asm     add     ax, 01f21h      /*21..5e,5f..7e,7f..98  21.........7e */

asm     jmp     short _rts

_invalid_jms:
#ifdef __FLAT__
asm     xor     eax, eax
#else
asm     xor     ax, ax
#endif

_rts:
#ifdef __FLAT__
        return (_EAX);
#else
        return (_AX);
#endif
}
#endif
