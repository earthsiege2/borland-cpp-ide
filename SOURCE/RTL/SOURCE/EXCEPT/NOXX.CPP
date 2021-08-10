/*------------------------------------------------------------------------
 * filename - noxx.cpp
 *
 *   The purpose of this file is to stub out the exception handling helper
 *   functions in order to reduce the overhead imposed by exceptions.
 *        
 *-----------------------------------------------------------------------*/


/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */


unsigned long   __far *    __RefDestructorCount(void)
{
	static unsigned long dummy = 0;

	return  &dummy;
}


void            __far *    __RefExceptionList(void)
{
	static unsigned long dummy = 0;

	return &dummy;
}


extern  "C"
{
	void    __cdecl    __InitExceptBlocks(void)
	{
	}

	void    __pascal   __ExitExceptBlocks(void __ss *)
	{
	}

	void    __cdecl    __InitExceptBlock(void)
	{
	}

	void    __cdecl    _ExceptInit(void)
	{
	}
}


unsigned        __cdecl    __GetPolymorphicDTC(void __far *, unsigned)
{
	return 0;
}


unsigned        __cdecl    __GetPolymorphicDTCfar(void __far *, unsigned)
{
	return 0;
}
