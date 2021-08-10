/*------------------------------------------------------------------------
 * filename - noxx.cpp
 *
 *   The purpose of this file is to stub out the exception handling helper
 *   functions in order to reduce the overhead imposed by exceptions.
 *
 *-----------------------------------------------------------------------*/


/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1994, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $        */


#define __far

#define	DEF_XX_VARS
#include <xx.h>
#include <windows.h>

#undef __debuggerHookFunction
void    __cdecl   __debuggerHookFunction(void)
{

}

extern  "C"
{
	void    __fastcall __InitExceptBlock(void *)
	{
	}

	void    __fastcall __ExitExceptBlock(void __far *)
	{
	}

	void    __cdecl    _ExceptInit(void)
	{
	}

	void	__cdecl		_GetExceptDLLinfoInternal(void *)
	{
	}

	void _InitDefaultHander(void)
	{
	}

	void *_HandlerPtr;
}

void terminate(void)
{
}

void unexpected(void)
{
}


unsigned        __cdecl    __GetPolymorphicDTC(void __far *, unsigned)
{
	return 0;
}

extern "C" {
  extern void * _new_handler;
  static void set_NOXX_new_handler ()
  {
#pragma startup set_NOXX_new_handler 1 /* Initializes the NOXX stubs. */
                                       /* This must be a larger # than the */
                                       /* value set in MEMORY\SETNEW.CPP */

    _new_handler = 0;  // Prevent exceptions from being thrown from bad new calls
  }
} // extern "C"


extern "C" {

typedef ULONG APIENTRY (*LIBMAINPTR)(HANDLE, ULONG, LPVOID);

ULONG APIENTRY __CRTL_DLLEntryPointWrapper(LIBMAINPTR pfn, HANDLE mod_handle,
                                           ULONG reason, LPVOID reserved)
{
    return pfn(mod_handle, reason, reserved);
}

}