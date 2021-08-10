/*------------------------------------------------------------------------
 * filename - lockdll.c
 *
 * function(s)
 *        _LockDLL - Locks and returns a handle to RTLDLL if applicable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#if defined(__LARGE__)

#include <windows.h>
#include <stdlib.h>

extern HINSTANCE _hInstance;

HANDLE _EXPFUNC _LockDLL(void)
{
#if !defined(_BUILDRTLDLL)
    return 0;
#else
	char modName[_MAX_PATH];
	HANDLE ret;
			
	if (!GetModuleFileName(_hInstance, modName, sizeof(modName)))
		return 0;
	ret = LoadLibrary(modName);
	if (ret < HINSTANCE_ERROR)
		return 0;
	return ret;
#endif	
}
#endif