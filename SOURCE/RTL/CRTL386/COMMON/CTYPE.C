/*------------------------------------------------------------------------
 * filename - ctype.c
 *
 * the "C" locale ctype array.
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef __OS2__

/*------------------------------------------------------------------------*

Name            _ctype

Usage           char    _ctype[257];

Prototype in    ctype.h

Description     _ctype is an array of  257 characters used by the character
                classification  and character   conversion macros  (such as
                isalpha and toascii).

*------------------------------------------------------------------------*/

#include <ctype.h>

char _RTLENTRY _EXPDATA _ctype[257] = {
        0,

        _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL,_IS_CTL,
        _IS_CTL, _IS_CTL|_IS_SP,
                          _IS_SP|_IS_CTL,
                                   _IS_SP|_IS_CTL,
                                            _IS_SP|_IS_CTL,
                                                     _IS_SP|_IS_CTL,
                                                              _IS_CTL,_IS_CTL,
        _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL,_IS_CTL,
        _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL, _IS_CTL,_IS_CTL,

        _IS_SP,  _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN,_IS_PUN,
        _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN,_IS_PUN,
        _IS_DIG, _IS_DIG, _IS_DIG, _IS_DIG, _IS_DIG, _IS_DIG, _IS_DIG,_IS_DIG,
        _IS_DIG, _IS_DIG, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN,_IS_PUN,

        _IS_PUN, _IS_UPP|_IS_HEX,
                          _IS_HEX|_IS_UPP,
                                   _IS_UPP|_IS_HEX,
                                            _IS_UPP|_IS_HEX,
                                                     _IS_UPP|_IS_HEX,
                                                              _IS_UPP|_IS_HEX,
                                                                      _IS_UPP,
        _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP,_IS_UPP,
        _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP, _IS_UPP,_IS_UPP,
        _IS_UPP, _IS_UPP, _IS_UPP, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN,_IS_PUN,

        _IS_PUN, _IS_LOW|_IS_HEX,
                          _IS_HEX|_IS_LOW,
                                   _IS_LOW|_IS_HEX,
                                            _IS_LOW|_IS_HEX,
                                                     _IS_LOW|_IS_HEX,
                                                              _IS_LOW|_IS_HEX,
                                                                      _IS_LOW,
        _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW,_IS_LOW,
        _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW, _IS_LOW,_IS_LOW,
        _IS_LOW, _IS_LOW, _IS_LOW, _IS_PUN, _IS_PUN, _IS_PUN, _IS_PUN,_IS_CTL
};
#else

#include <ctype.h>
#include <_locale.h>

/*
 * The "C" locale ctype array
*/

unsigned char _Cdecl _ctype[ SBCS_CTYPE_TSIZE ] =

{
    0x00,                                /* 0xffff (-1) EOF */
    _IS_CTL,                             /* 0x00 */
    _IS_CTL,                             /* 0x01 */
    _IS_CTL,                             /* 0x02 */
    _IS_CTL,                             /* 0x03 */
    _IS_CTL,                             /* 0x04 */
    _IS_CTL,                             /* 0x05 */
    _IS_CTL,                             /* 0x06 */
    _IS_CTL,                             /* 0x07 */
    _IS_CTL,                             /* 0x08 */
    _IS_SP | _IS_CTL,                    /* 0x09 */
    _IS_SP | _IS_CTL,                    /* 0x0a */
    _IS_SP | _IS_CTL,                    /* 0x0b */
    _IS_SP | _IS_CTL,                    /* 0x0c */
    _IS_SP | _IS_CTL,                    /* 0x0d */
    _IS_CTL,                             /* 0x0e */
    _IS_CTL,                             /* 0x0f */
    _IS_CTL,                             /* 0x10 */
    _IS_CTL,                             /* 0x11 */
    _IS_CTL,                             /* 0x12 */
    _IS_CTL,                             /* 0x13 */
    _IS_CTL,                             /* 0x14 */
    _IS_CTL,                             /* 0x15 */
    _IS_CTL,                             /* 0x16 */
    _IS_CTL,                             /* 0x17 */
    _IS_CTL,                             /* 0x18 */
    _IS_CTL,                             /* 0x19 */
    _IS_CTL,                             /* 0x1a */
    _IS_CTL,                             /* 0x1b */
    _IS_CTL,                             /* 0x1c */
    _IS_CTL,                             /* 0x1d */
    _IS_CTL,                             /* 0x1e */
    _IS_CTL,                             /* 0x1f */
    _IS_SP | _IS_BLK,                    /* 0x20 */
    _IS_PUN,                             /* 0x21 */
    _IS_PUN,                             /* 0x22 */
    _IS_PUN,                             /* 0x23 */
    _IS_PUN,                             /* 0x24 */
    _IS_PUN,                             /* 0x25 */
    _IS_PUN,                             /* 0x26 */
    _IS_PUN,                             /* 0x27 */
    _IS_PUN,                             /* 0x28 */
    _IS_PUN,                             /* 0x29 */
    _IS_PUN,                             /* 0x2a */
    _IS_PUN,                             /* 0x2b */
    _IS_PUN,                             /* 0x2c */
    _IS_PUN,                             /* 0x2d */
    _IS_PUN,                             /* 0x2e */
    _IS_PUN,                             /* 0x2f */
    _IS_DIG | _IS_HEX,                   /* 0x30 */
    _IS_DIG | _IS_HEX,                   /* 0x31 */
    _IS_DIG | _IS_HEX,                   /* 0x32 */
    _IS_DIG | _IS_HEX,                   /* 0x33 */
    _IS_DIG | _IS_HEX,                   /* 0x34 */
    _IS_DIG | _IS_HEX,                   /* 0x35 */
    _IS_DIG | _IS_HEX,                   /* 0x36 */
    _IS_DIG | _IS_HEX,                   /* 0x37 */
    _IS_DIG | _IS_HEX,                   /* 0x38 */
    _IS_DIG | _IS_HEX,                   /* 0x39 */
    _IS_PUN,                             /* 0x3a */
    _IS_PUN,                             /* 0x3b */
    _IS_PUN,                             /* 0x3c */
    _IS_PUN,                             /* 0x3d */
    _IS_PUN,                             /* 0x3e */
    _IS_PUN,                             /* 0x3f */
    _IS_PUN,                             /* 0x40 */
    _IS_UPP | _IS_HEX,                   /* 0x41 */
    _IS_UPP | _IS_HEX,                   /* 0x42 */
    _IS_UPP | _IS_HEX,                   /* 0x43 */
    _IS_UPP | _IS_HEX,                   /* 0x44 */
    _IS_UPP | _IS_HEX,                   /* 0x45 */
    _IS_UPP | _IS_HEX,                   /* 0x46 */
    _IS_UPP,                             /* 0x47 */
    _IS_UPP,                             /* 0x48 */
    _IS_UPP,                             /* 0x49 */
    _IS_UPP,                             /* 0x4a */
    _IS_UPP,                             /* 0x4b */
    _IS_UPP,                             /* 0x4c */
    _IS_UPP,                             /* 0x4d */
    _IS_UPP,                             /* 0x4e */
    _IS_UPP,                             /* 0x4f */
    _IS_UPP,                             /* 0x50 */
    _IS_UPP,                             /* 0x51 */
    _IS_UPP,                             /* 0x52 */
    _IS_UPP,                             /* 0x53 */
    _IS_UPP,                             /* 0x54 */
    _IS_UPP,                             /* 0x55 */
    _IS_UPP,                             /* 0x56 */
    _IS_UPP,                             /* 0x57 */
    _IS_UPP,                             /* 0x58 */
    _IS_UPP,                             /* 0x59 */
    _IS_UPP,                             /* 0x5a */
    _IS_PUN,                             /* 0x5b */
    _IS_PUN,                             /* 0x5c */
    _IS_PUN,                             /* 0x5d */
    _IS_PUN,                             /* 0x5e */
    _IS_PUN,                             /* 0x5f */
    _IS_PUN,                             /* 0x60 */
    _IS_LOW | _IS_HEX,                   /* 0x61 */
    _IS_LOW | _IS_HEX,                   /* 0x62 */
    _IS_LOW | _IS_HEX,                   /* 0x63 */
    _IS_LOW | _IS_HEX,                   /* 0x64 */
    _IS_LOW | _IS_HEX,                   /* 0x65 */
    _IS_LOW | _IS_HEX,                   /* 0x66 */
    _IS_LOW,                             /* 0x67 */
    _IS_LOW,                             /* 0x68 */
    _IS_LOW,                             /* 0x69 */
    _IS_LOW,                             /* 0x6a */
    _IS_LOW,                             /* 0x6b */
    _IS_LOW,                             /* 0x6c */
    _IS_LOW,                             /* 0x6d */
    _IS_LOW,                             /* 0x6e */
    _IS_LOW,                             /* 0x6f */
    _IS_LOW,                             /* 0x70 */
    _IS_LOW,                             /* 0x71 */
    _IS_LOW,                             /* 0x72 */
    _IS_LOW,                             /* 0x73 */
    _IS_LOW,                             /* 0x74 */
    _IS_LOW,                             /* 0x75 */
    _IS_LOW,                             /* 0x76 */
    _IS_LOW,                             /* 0x77 */
    _IS_LOW,                             /* 0x78 */
    _IS_LOW,                             /* 0x79 */
    _IS_LOW,                             /* 0x7a */
    _IS_PUN,                             /* 0x7b */
    _IS_PUN,                             /* 0x7c */
    _IS_PUN,                             /* 0x7d */
    _IS_PUN,                             /* 0x7e */
    _IS_CTL,                             /* 0x7f */
    0x00,                                /* 0x80 */
    0x00,                                /* 0x81 */
    0x00,                                /* 0x82 */
    0x00,                                /* 0x83 */
    0x00,                                /* 0x84 */
    0x00,                                /* 0x85 */
    0x00,                                /* 0x86 */
    0x00,                                /* 0x87 */
    0x00,                                /* 0x88 */
    0x00,                                /* 0x89 */
    0x00,                                /* 0x8a */
    0x00,                                /* 0x8b */
    0x00,                                /* 0x8c */
    0x00,                                /* 0x8d */
    0x00,                                /* 0x8e */
    0x00,                                /* 0x8f */
    0x00,                                /* 0x90 */
    0x00,                                /* 0x91 */
    0x00,                                /* 0x92 */
    0x00,                                /* 0x93 */
    0x00,                                /* 0x94 */
    0x00,                                /* 0x95 */
    0x00,                                /* 0x96 */
    0x00,                                /* 0x97 */
    0x00,                                /* 0x98 */
    0x00,                                /* 0x99 */
    0x00,                                /* 0x9a */
    0x00,                                /* 0x9b */
    0x00,                                /* 0x9c */
    0x00,                                /* 0x9d */
    0x00,                                /* 0x9e */
    0x00,                                /* 0x9f */
    0x00,                                /* 0xa0 */
    0x00,                                /* 0xa1 */
    0x00,                                /* 0xa2 */
    0x00,                                /* 0xa3 */
    0x00,                                /* 0xa4 */
    0x00,                                /* 0xa5 */
    0x00,                                /* 0xa6 */
    0x00,                                /* 0xa7 */
    0x00,                                /* 0xa8 */
    0x00,                                /* 0xa9 */
    0x00,                                /* 0xaa */
    0x00,                                /* 0xab */
    0x00,                                /* 0xac */
    0x00,                                /* 0xad */
    0x00,                                /* 0xae */
    0x00,                                /* 0xaf */
    0x00,                                /* 0xb0 */
    0x00,                                /* 0xb1 */
    0x00,                                /* 0xb2 */
    0x00,                                /* 0xb3 */
    0x00,                                /* 0xb4 */
    0x00,                                /* 0xb5 */
    0x00,                                /* 0xb6 */
    0x00,                                /* 0xb7 */
    0x00,                                /* 0xb8 */
    0x00,                                /* 0xb9 */
    0x00,                                /* 0xba */
    0x00,                                /* 0xbb */
    0x00,                                /* 0xbc */
    0x00,                                /* 0xbd */
    0x00,                                /* 0xbe */
    0x00,                                /* 0xbf */
    0x00,                                /* 0xc0 */
    0x00,                                /* 0xc1 */
    0x00,                                /* 0xc2 */
    0x00,                                /* 0xc3 */
    0x00,                                /* 0xc4 */
    0x00,                                /* 0xc5 */
    0x00,                                /* 0xc6 */
    0x00,                                /* 0xc7 */
    0x00,                                /* 0xc8 */
    0x00,                                /* 0xc9 */
    0x00,                                /* 0xca */
    0x00,                                /* 0xcb */
    0x00,                                /* 0xcc */
    0x00,                                /* 0xcd */
    0x00,                                /* 0xce */
    0x00,                                /* 0xcf */
    0x00,                                /* 0xd0 */
    0x00,                                /* 0xd1 */
    0x00,                                /* 0xd2 */
    0x00,                                /* 0xd3 */
    0x00,                                /* 0xd4 */
    0x00,                                /* 0xd5 */
    0x00,                                /* 0xd6 */
    0x00,                                /* 0xd7 */
    0x00,                                /* 0xd8 */
    0x00,                                /* 0xd9 */
    0x00,                                /* 0xda */
    0x00,                                /* 0xdb */
    0x00,                                /* 0xdc */
    0x00,                                /* 0xdd */
    0x00,                                /* 0xde */
    0x00,                                /* 0xdf */
    0x00,                                /* 0xe0 */
    0x00,                                /* 0xe1 */
    0x00,                                /* 0xe2 */
    0x00,                                /* 0xe3 */
    0x00,                                /* 0xe4 */
    0x00,                                /* 0xe5 */
    0x00,                                /* 0xe6 */
    0x00,                                /* 0xe7 */
    0x00,                                /* 0xe8 */
    0x00,                                /* 0xe9 */
    0x00,                                /* 0xea */
    0x00,                                /* 0xeb */
    0x00,                                /* 0xec */
    0x00,                                /* 0xed */
    0x00,                                /* 0xee */
    0x00,                                /* 0xef */
    0x00,                                /* 0xf0 */
    0x00,                                /* 0xf1 */
    0x00,                                /* 0xf2 */
    0x00,                                /* 0xf3 */
    0x00,                                /* 0xf4 */
    0x00,                                /* 0xf5 */
    0x00,                                /* 0xf6 */
    0x00,                                /* 0xf7 */
    0x00,                                /* 0xf8 */
    0x00,                                /* 0xf9 */
    0x00,                                /* 0xfa */
    0x00,                                /* 0xfb */
    0x00,                                /* 0xfc */
    0x00,                                /* 0xfd */
    0x00,                                /* 0xfe */
    0x00                                 /* 0xff */
};

#endif
