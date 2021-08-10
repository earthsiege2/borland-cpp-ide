/*-----------------------------------------------------------------------*
 * filename - cvtfak.c
 *
 * function(s)
 *        __realcvt - fake floating point conversion
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_io.h>
#include <string.h>

static void _fakecvt(void)
{
    _ErrorExit("printf : floating point formats not linked");
}

static void _fakescan(void)
{
    _ErrorExit("scanf : floating point formats not linked");
}


/* Pointers to the conversion and scanning functions.
 */
void (*_realcvtptr)(void) = _fakecvt;
void (*_nextrealptr)(void) = _fakecvt;
void (*_scantodptr)(void) = _fakescan;
void (*_scanrsltptr)(void) = _fakescan;
