/*-----------------------------------------------------------------------*
 * filename - usebormm.h
 *
 *   Include this header file into one source file to force the RTL
 *   (either static or dynamic) to use the "Borland" memory manager DLL.
 *   The hooking and usage of the memory DLL is done inside the RTL when
 *   the memory DLL is detected to be in memory already.
 *
 *   This header will force the loader to load the DLL when the app starts
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

#ifndef __USEBORMM_H
#define __USEBORMM_H

#ifdef __cplusplus
extern "C" {
#endif

#pragma option push -V?- -w-use -w-aus

#pragma comment(lib, "usebormm.lib")  /* Bring in the helper lib */

static void __dummy_function_for_usebormm (void)
{
#   pragma startup __dummy_function_for_usebormm 64
    void _RTLENTRY __CRTL_MEM_PullInUseBorMMLib (void);

    __CRTL_MEM_PullInUseBorMMLib();
}

#pragma option pop

#ifdef __cplusplus
}
#endif


#endif /* __USEBORMM_H */