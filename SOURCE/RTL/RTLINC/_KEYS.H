/*------------------------------------------------------------------------
 * filename - _keys.h
 *
 *    Helper definitions and prototypes for the getch & kbhit routines
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__CONIO_H)
#include <conio.h>
#endif

#define INCL_CON
#define INCL_USER
#include <ntbc.h>

extern HANDLE _hin;  /* From CRTINIT.C for console input */

/* The following two variables are located in kbhit.c. */

extern unsigned char _cFlag;    /* Flag presence of un-gotten char */
extern unsigned char _cChar;    /* The ungotten char               */
extern int _cextend;            /* Used for the scan code of an extended key */


struct kbd
{
    short keycode;            /* virtual keycode */
    short normal;             /* BIOS keycode - normal */
    short shift;              /* BIOS keycode - Shift- */
    short ctrl;               /* BIOS keycode - Ctrl- */
    short alt;                /* BIOS keycode - Alt- */
};


#define EXT(key)    ((key)+0x100)
#define ISEXT(val)  ((val)&0x100)
#define EXTVAL(val) ((val)&0xff)

struct kbd * _RTLENTRY __lookup_key (int keycode);
int _RTLENTRY __xlat_key (INPUT_RECORD *inp, struct kbd *k);
