/*-----------------------------------------------------------------------*
 * filename - usebormm.c (which makes usebormm.lib)
 *
 *   Include this lib file into your project to force the RTL
 *   (either static or dynamic) to use the "Borland" memory manager DLL.
 *   The hooking and usage of the memory DLL is done inside the RTL when
 *   the memory DLL is detected to be in memory already.
 *
 *   This lib will force the loader to load the DLL when the app starts
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <_hrdir.h>

/* This function is a stub and will satisfy an external call
 * from the startup code.
 */

#pragma comment(lib, "memmgr.lib")    /* Bring in the import lib for the DLL */

void _RTLENTRY _EXPFUNC __CRTL_MEM_UseBorMM (void)
{
    void __stdcall GetAllocMemCount (void); /* Proto for a function in the DLL */
    _EAX = (unsigned int)GetAllocMemCount;  /* Hack to force the linker to use it */
}

void _RTLENTRY _EXPFUNC __CRTL_MEM_PullInUseBorMMLib (void) /* Gets touched by usebormm.h */
{
}