/*------------------------------------------------------------------------*
 * filename - 8087.c
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */


#include <_defs.h>

/* The OS provides an 80387 emulator, so we can pretend that we have a
 * coprocessor. 
 *
 * This variable is not used by the RTL, and is provided only for
 * compatibility with existing DOS programs. 
 */
int _RTLENTRY _EXPDATA  _8087 = 3;

