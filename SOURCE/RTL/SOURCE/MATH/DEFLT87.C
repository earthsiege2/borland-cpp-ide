/*------------------------------------------------------------------------
 * filename - deflt87.c
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


/* Default control word for the 387.  */

#include <float.h>

unsigned int _RTLENTRY _EXPDATA _default87 =
    RC_NEAR+PC_64+IC_AFFINE+EM_UNDERFLOW+EM_INEXACT+EM_DENORMAL;
