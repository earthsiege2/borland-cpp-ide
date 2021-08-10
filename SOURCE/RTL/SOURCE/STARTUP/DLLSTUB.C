/*-----------------------------------------------------------------------*
 * filename - dllstub.c
 *
 * function(s)
 *
 *   __CRTL_DLL_Lock
 *   __CRTL_DLL_Unlock
 *
 *
 *   Both of these functions are stubbed out here.  The real ones are in
 *   dlllock.c
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_defs.h>

void _RTLENTRY __CRTL_DLL_Lock (void)   {}
void _RTLENTRY __CRTL_DLL_Unlock (void) {}
