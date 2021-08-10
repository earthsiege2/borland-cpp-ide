/*-----------------------------------------------------------------------*
 * filename - initcvt.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1992, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

/* MSC generates an external reference to __fltused when floating point
 * is used.  BCC generates a reference to __turboFloat when the address
 * of a floating point number is taken.  In either case, this module is
 * forced to be linked in, which in turn causes the floating point
 * conversion and scanning initialization functions to be linked.
 */

#include <_defs.h>

#if 0
int _fltused = 0;                   /* satisfy MSC external reference */
#endif

int _turboFloat = 0;                /* satisfy BCC external reference */
int _floatconvert = 0;              /* satisfy #pragma extref _floatconvert */

extern void _cvt_init(void);        /* printf() floating point conversion */
extern void _scan_init(void);       /* scanf() floating point conversion */

#pragma startup _cvt_init  10       /* _cvt_init to be called at startup */
#pragma startup _scan_init 10       /* _scan_init to be called at startup */
