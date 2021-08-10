/*------------------------------------------------------------------------
 * filename - deflt87.c
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1992, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


/* Default control word for the 387.  */

#include <float.h>

unsigned int _RTLENTRY _EXPDATA _default87 =
    RC_NEAR+PC_64+IC_AFFINE+EM_UNDERFLOW+EM_INEXACT+EM_DENORMAL;
