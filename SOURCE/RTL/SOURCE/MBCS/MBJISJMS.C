/*-----------------------------------------------------------------------*
 * filename - mbjisjms.c
 *
 * function(s)
 *        _mbcjistojms - Converts a character from JIS code to Shift-JIS
 *                       code.
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

Name            _mbcjistojms - Converts a character from JIS code to
                               Shift-JIS code.

Usage           unsigned int _mbcjistojms(unsigned int c);

Prototype in    mbstring.h

Desctiption     _mbcjistojms converts c from JIS code to Shift-JIS code.

Return value    Returns converted code.Returns 0 if it can not be
                converted.

*---------------------------------------------------------------------*/

#if defined(__FLAT__)
unsigned int _RTLENTRY _EXPFUNC _mbcjistojms(unsigned int c)
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

    if (c1 >= 0x21 && c1 <= 0x7e && c2 >= 0x21 && c2 <= 0x7e)
    {
        if (c1 & 0x01)
        {
            c2 += 0x1f;
            if (c2 >= 0x7f)
                c2++;
        }
        else
            c2 += 0x7e;

        c1 += 0xe1;
        c1 >>= 1;

        if (c1 >= 0xa0)
            c1 += 0x40;

        return ((c1 << 8) | c2);
    }

    return 0;
}
#else
unsigned int _RTLENTRY _EXPFUNC _mbcjistojms(unsigned int c)
{
#ifdef __FLAT__
asm     mov     eax, c
asm     test    eax, 0FFFF0000H
asm     jnz     _invalid_jis
#else
asm     mov     ax, c
#endif
asm     cmp     ah, 021h
asm     jc      _invalid_jis
asm     cmp     ah, 07fh
asm     jnc     _invalid_jis
asm     cmp     al, 021h
asm     jc      _invalid_jis
asm     cmp     al, 07fh
asm     jnc     _invalid_jis

                                /* 21..5E,5F..7E,7F..98  21....5F,60....7E */
asm     sub     ax, 0de82h      /* 42..7F,80..9F,A0..B9  9F....DD,DE....FC */
                                /* =========CY=========                    */
asm     rcr     ah,1            /* A1..BF,C0..CF,D0..DC                    */
asm     jc      _1              /*                       9F....DD,DE....FC */
asm     cmp     al, 0deh        /*                       ===CY===,---NC--- */
asm     sbb     al, 05eh        /*                       40....7E,80....9E */
_1:                             /*                                         */
asm     xor     ah, 020h        /* 81..9F,E0..EF,F0..FC                    */
asm     jmp     short _rts

_invalid_jis:
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
