/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1993, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */
#define NDEBUG
#define DIABLO

#include <windows.h>

#include <_defs.h>
#ifndef __NON_STD_ASSERT__
#include <assert.h>
#endif

///////////////////////////////////////////////////////////////////////////////

static	CRITICAL_SECTION	dbgDataCS;
static	int			dbgCSInitialized;

///////////////////////////////////////////////////////////////////////////////

#ifdef	DIABLO

#ifdef  __NON_STD_ASSERT__

#ifdef  NDEBUG

#define assert(p)

#else

static  void    __near  assertAbort(char *reason, char *file, unsigned line)
{
	printf("Assertion failed: %s at %s(%d)\n", reason, file, line);

	exit(4);
}

#define assert(p) ((p) ? (void)0 : (assertAbort(#p, __FILE__, __LINE__)))

#endif

#endif

///////////////////////////////////////////////////////////////////////////////

void	  __export	__lockDebuggerData(void)
{
	if	(!dbgCSInitialized)
	{
		dbgCSInitialized = 1;
		InitializeCriticalSection(&dbgDataCS);
	}
	EnterCriticalSection(&dbgDataCS);
}

void	__export	__unlockDebuggerData(void)
{
	assert(dbgCSInitialized);
	LeaveCriticalSection(&dbgDataCS);
}

#endif

