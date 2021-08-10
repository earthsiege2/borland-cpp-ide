/*-----------------------------------------------------------------------*
 * filename - initcvt.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1992, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4 $        */

/* MSC generates an external reference to __fltused when floating point
 * is used.  BCC generates a reference to __turboFloat when the address
 * of a floating point number is taken.  In either case, this module is
 * forced to be linked in, which in turn causes the floating point
 * conversion and scanning initialization functions to be linked.
 */

#include <ntbc.h>
#include <_defs.h>

#if 0
int _fltused = 0;                   /* satisfy MSC external reference */
#endif

int _turboFloat = 0;                /* satisfy BCC external reference */
int _floatconvert = 0;              /* satisfy #pragma extref _floatconvert */

extern void _cvt_init(void);        /* printf() floating point conversion */
extern void _scan_init(void);       /* scanf() floating point conversion */

extern void _cvt_initw(void);       /* printf() floating point conversion */
extern void _scan_initw(void);      /* scanf() floating point conversion */

/*
   Since the user is allowed to call both wide and narrow versions of the
   printf/scanf series of functions at the same time, we must init both of
   the converters to avoid the "printf floating point formats not linked..."
   error message.
*/
#pragma startup _cvt_init   10      /* Initializes the printf fp converter */
#pragma startup _scan_init  10      /* Initializes the scanf fp converter */
#pragma startup _cvt_initw  10      /* Initializes the wprintf fp converter */
#pragma startup _scan_initw 10      /* Initializes the wscanf fp converter */
