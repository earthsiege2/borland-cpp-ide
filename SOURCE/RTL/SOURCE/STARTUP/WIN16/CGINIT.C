/*-----------------------------------------------------------------------*
 * filename - cginit.c
 *
 * function(s)
 *        __cg_init -
 *        __cg_exit -
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1995, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#if defined(_Windows) && defined(_BUILDRTLDLL)

#include <windows.h>

typedef int __pascal (* _CGCALL)(HMODULE, int);
static _CGCALL _pfnCG;
static HMODULE _hCG;
static HMODULE _hCGModHandle;

extern HMODULE _hInstance;

//
// Returns
//	0 No error
//	1 Error encountered
//
int __cg_init(void)
{
    int retval = 0;
    if (!_hCG && GetModuleHandle("CG16.DLL") != NULL)
	{
	_hCG = LoadLibrary("CG16.DLL");
	_pfnCG = (_CGCALL) GetProcAddress(_hCG, "_CG_RTLDLLINIT");
	retval = _pfnCG(_hInstance, 1);
	_hCGModHandle = _hInstance;
	}
    return retval;
}


void __cg_exit(void)
{
    if (_hCGModHandle == _hInstance && _hCG)
	{
        _pfnCG(_hInstance, 0);
        FreeLibrary(_hCG);
	}
}

#endif
