/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1993, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.15.2.1 $        */

///////////////////////////////////////////////////////////////////////////////
//
//      List of global variables in XX:
//
//              __terminatePTR
//              __unexpectedPTR
//
//              __CPPexceptionList
//
//              ___throwExceptionName
//              ___throwFileName
//              ___throwLineNumber
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//
//
//      Compile with the following switches:
//
//              BCC32  -DRTTI -c -I.      -x -xp -RT -O- XX.CPP
//
///////////////////////////////////////////////////////////////////////////////

#include <_defs.h>

///////////////////////////////////////////////////////////////////////////////

	#define NDEBUG
///////////////////////////////////////////////////////////////////////////////

#ifndef __NON_STD_ASSERT__
#include <assert.h>
#endif

#define DEF_XX_VARS
#include "xx.h"

#ifdef  XX_MEMMGR
#include "xxmem.h"
#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef  GUIDO

// Because the default unexpected handler uses the default terminate handler,
// it must disable the usual callback from the latter.

static  int     disable_terminate_callback;

#endif

///////////////////////////////////////////////////////////////////////////////

extern	unsigned char 	__isDLL;

#ifdef	PRONTODEBUGGER

extern	int		__CPPdebugHook;

static	int *		__pCPPdebugHook;

extern	"C"     void	__cdecl __raiseDebuggerException(XXdebuggerNotification kind,
                				         int			argCount,
        						 ...);
#endif

#ifdef	PRONTODEBUGGER
static	void	initCPPdebugHook(void)
{
	__pCPPdebugHook = (int *)GetProcAddress(GetModuleHandleA(0), "___CPPdebugHook");

	if	(!__pCPPdebugHook)
		__pCPPdebugHook = &__CPPdebugHook;
}
#pragma startup initCPPdebugHook 0 /* Initializes the IDE debugger hook */
#endif

///////////////////////////////////////////////////////////////////////////////

/*
	This variable is declared here as a TLS variable.  It holds all of the
	per thread information needed for exception handling maintenance.  The
	variable is initialized to zero because if this file is compiled via
	assembly, and there is no initialization, the compiler will emit no
	explicit data for the initialization, and the assembler will put out
	no LEDATA records for the initialization.  If this is the only TLS
	variable in the program (very common), the linker will emit a TLS
	section to the image which has no physical data, which will cause
	NT to fail the load of the image.  That part is a linker bug, but it's
	perfectly safe to work around the issue here.  The moral is - don't
	remove that obviously superfluous initialization unless you really
	know what you're doing.
*/
__declspec(thread)	exceptVarRec	__xxInfo = {0};

namespace std {

bool    STDCC   uncaught_exception (void)
{
        // Ansi 18.6 says we need this.
	// Returns TRUE if we are inbetween the end of evaluating a
	// throw expression and the end of initializing the exception
	// declaration in the matching handler.  I interpret this as
	// the window between throwing an exception and entering the
	// catch handler.
	// Otherwise it returns FALSE.

        return ((__exceptFlags & XF_UNCAUGHT_EXCEPTION) != 0);
}

} // std

// extern  "C"     int     __cdecl _flushall(void);

extern  "C"     void    __call_terminate(void)
{
#ifdef  DEBUG
	printf("Calling terminate().\n");
#endif

	// Officially we are done with the exception now.
	// See uncaught_exception.

	__exceptFlags &= ~XF_UNCAUGHT_EXCEPTION;

#ifdef  GUIDO

	if      (tell_debugger_terminate && disable_terminate_callback == 0)
	{
		(*tell_debugger_terminate)((__terminatePTR == OUR_TERMINATE_ADDR) ? 0UL :
			(unsigned long) __terminatePTR);
	}

	disable_terminate_callback = 0;

#endif

#ifdef  DIABLO

	if      (__debuggerWatching && ! __debuggerDisableTerminateCallback)
	{
		__lockDebuggerData();
		__debuggerHookDataP->kind = DebuggerData::EventTerminated;
		__debuggerHookDataP->addr = (unsigned long) __terminatePTR;

		__debuggerHookFunction();
		__unlockDebuggerData();

		__debuggerDisableTerminateCallback = 0;
	}


#endif

#ifdef	PRONTODEBUGGER
	/*
		See 'N.B. ilink32 exported data, in memory image bug:' above.
	*/
//	if	(*__pCPPdebugHook)
	if	((*__pCPPdebugHook) == 2)
		__raiseDebuggerException(XXDNterminated, 1, __terminatePTR);
#endif

	_flushall();

	PFV     terminatePTR = __terminatePTR;

	try
	{
		terminatePTR();

	}
	catch(...)
	{

	}

	abort();
}


extern  "C"     void    __call_unexpected(void)
{
#ifdef  DEBUG
	printf("Calling unexpected().\n");
#endif

	// Officially we are done with the exception now.
	// See uncaught_exception.

	__exceptFlags &= ~XF_UNCAUGHT_EXCEPTION;

#ifdef  GUIDO
	if      (tell_debugger_unexpected)
	{
		if      (__unexpectdPTR == OUR_UNEXPECTD_ADDR)
		{
			disable_terminate_callback = 1;
			(*tell_debugger_unexpected)(0UL);
		}
		else
		{
			(*tell_debugger_unexpected)((unsigned long)__unexpectdPTR);
		}
	}
#endif

#ifdef DIABLO

	if      (__debuggerWatching)
	{
		__lockDebuggerData();
		__debuggerHookDataP->kind = DebuggerData::EventUnexpected;
		__debuggerHookDataP->addr = (unsigned long) __unexpectdPTR;

		__debuggerDisableTerminateCallback = 1;

		__debuggerHookFunction();
		__unlockDebuggerData();
	}

#endif

#ifdef	PRONTODEBUGGER
	/*
		See 'N.B. ilink32 exported data, in memory image bug:' above.
	*/
//	if	(*__pCPPdebugHook)
	if	((*__pCPPdebugHook) == 2)
		__raiseDebuggerException(XXDNunexpected, 1, __unexpectdPTR);
#endif

	PFV     unexpectedPTR = __unexpectdPTR;

	unexpectedPTR();

	/*
		According to the current ANSI working paper (92-0060),
		unexpected() is not supposed to return (it might throw
		an exception, of course). So, we have no other option
		here than to abort the program.
	 */

	abort();
}

///////////////////////////////////////////////////////////////////////////////
//
//      A compiler-called routine that returns the 'real' destructor count
//      for the true type of the given object.
//

unsigned        STDCC   __GetPolymorphicDTC(void        __far * objectPtr,
					    unsigned            vptrOffset)
{
	void    __far * vtablePtr;

	tpidPtr         Typeid;

	/* First check for NULL */

	if      (!objectPtr)
		return  0;

#if     defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)

	/* Check for 'near 0' cast to a far pointer */

	if      (objectPtr == MK_FP(_DS,0))
		return  0;

#endif

	/* Now get the vtable pointer from the object */

	vtablePtr = *(void __near * __far *)((char __far *)objectPtr + vptrOffset);

	/* Locate the true bottom of the object and its type */

	objectPtr = (char __far *)objectPtr - ((unsigned __far *)vtablePtr)[-2];
	vtablePtr = (char __far *)vtablePtr - ((unsigned __far *)vtablePtr)[-1];

	assert(((unsigned __far *)vtablePtr)[-1] == 0);
//      assert(((unsigned __far *)vtablePtr)[-2] == 0);

	/* Extract the 'most derived type id' address from the vtable */

	Typeid = *((tpidPtr TPDST *)((unsigned __far *)vtablePtr - 2) - 1); assert(IS_CLASS(Typeid->tpMask));

	/* Return the destructor count */

	return  Typeid->tpClass.tpcDtorCount;
}

///////////////////////////////////////////////////////////////////////////////

extern  "C"     unsigned                _ExceptVarsSize = sizeof(exceptVarRec);

///////////////////////////////////////////////////////////////////////////////

#define DLLEXC_VER      0x82727349

typedef struct
{
	unsigned        version;
	exceptVarPtr    varAddr;
}
	excDLLinfoRec,
       *excDLLinfoPtr;

extern  "C"     void    __cdecl         _GetExceptDLLinfoInternal(excDLLinfoPtr infoPtr);


extern  "C"     void    __cdecl         _ErrorMessage(const char *);


///////////////////////////////////////////////////////////////////////////////
//
//      This function is called with 0 whenever an EXE is initialized or
//      when a process attaches to a DLL. It is also called with the
//      address of a (per-thread) storage area for exception variables
//      whenever a new thread is created.
//

extern  "C"
void    __cdecl         _ExceptInit(exceptVarPtr exceptVarsPtr)
{
	int     threadStart = (exceptVarsPtr != 0);

#ifdef DEBUG
	char            buff[128];
	wsprintf(buff, "ExceptInit(0x%08X) in %s\n", exceptVarsPtr, __isDLL ? "DLL" : "EXE");
	_ErrorMessage(buff);
#endif  /* DEBUG */

//      __emit__(0xCC);

	/* Do we need to get the address of the exception variables? */

	if      (exceptVarsPtr)
	{
		/* This is beginThread -- merely do static initialization */

                // Nothing to do anymore
	}
	else
	{
		/* We're either starting an EXE, or attaching a DLL */

		excDLLinfoRec   info;

#if 0
		/* Is this a DLL? */

		if      (__isDLL)
		{
			procPtr         EXEptr;
			void    *       EXEhan;

			/* Assume the worst */

			EXEptr = 0;



			/* Get the module handle of our EXE */

			EXEhan = GetModuleHandleA(0);

			if      (EXEhan)
			{
				/* Get the address of the 'info' function in the EXE */

				EXEptr = GetProcAddress(EXEhan, "__GetExceptDLLinfo");
			}

			if      (EXEptr)
			{

				/* Call the 'info' function */

				((void (__cdecl*)(excDLLinfoPtr))EXEptr)(&info);

				/* Ignore info if wrong version */

				if      (info.version >= DLLEXC_VER &&
					 info.version <= DLLEXC_VER + 0x10)
				{
					exceptVarsPtr = info.varAddr;
				}
			}
		}
#endif /* 0 */
		/* Point to our own variables if necessary */

		if      (!exceptVarsPtr)
		{
			_GetExceptDLLinfoInternal(&info);
			exceptVarsPtr = info.varAddr;
		}
	}

	/* Now initialize the variable pointer on the stack */

        /* Can't do this anymore.
	   // getXVarPtr() = exceptVarsPtr;
           must do this now:
        */
        memcpy (getXVarPtr(), exceptVarsPtr, sizeof (*exceptVarsPtr));

#ifdef  DIABLO
	if (threadStart)
	{
		__debuggerWatchingP = &_DebuggerHookData.debugger_watching;
		__debuggerHookDataP = &_DebuggerHookData;
	}
#endif /* DIABLO */


#if 0
	/* Point to the destructor count on the stack and set it to 0 */
	if      (!threadStart)
		_DestructorCountPtr = &getDTCount();

	getDTCount() = 0;
#endif /* 0 */

#ifdef  XX_MEMMGR

	/* Initialize memory allocation stuff */

	__exceptMemAllocVars = 0; __Chunk_Alloc(__Chunk_MinimumSize);

#endif /* XX_MEMMGR */

//	__exceptFlags        = 0;

        _InitTermAndUnexPtrs();
}

///////////////////////////////////////////////////////////////////////////////
//
//      Provide call-back that will be used by any DLL loaded by this
//      program to gain access to the main program's global variables
//      used for exception handling.
//

#undef  __exceptFlags
#undef  __terminatePTR
#undef  __unexpectdPTR
#undef  __throwFileName
#undef  __throwLineNumber
#undef  __CPPexceptionList
#undef  __exceptStaticBuffP
#undef  __throwExceptionName
#undef  __exceptMemAllocVars

#ifdef  DIABLO
#undef  __debuggerWatching
#undef  __debuggerWatchingP
#undef  __debuggerHookDataP
#undef  __debuggerHookFunction
#endif

#ifdef  DIABLO

static void    STDCC    __debuggerHookFunction(void)
{
}

DebuggerData    STDCC   __export        _DebuggerHookData =
	{
		0xe91d8bb4,
		0x0,
		0x1d3c71ff,
		__debuggerHookFunction,
		0,
		DebuggerData::EventNull, 0, 0, 0, 0, 0, 0
	};

#endif

extern  "C"
void     __cdecl        _GetExceptDLLinfoInternal(excDLLinfoPtr infoPtr)
{
	/* Can't do the following initialization statically */

	__exceptStaticBuffP = __ExceptStaticXbuff;

#ifdef  DIABLO
	__debuggerWatchingP = &_DebuggerHookData.debugger_watching;
	__debuggerHookDataP = &_DebuggerHookData;
#endif

	/* Fill in the info structure */

	infoPtr->version = DLLEXC_VER;
	infoPtr->varAddr = (exceptVarPtr)&__CPPexceptionList;

	/* Make sure the variable offsets are correct */

#define X0P     ((exceptVarPtr)0)

	assert(((char *  )&      __CPPexceptionList   - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrCPPexceptionList));


#ifdef  DIABLO

	assert(((char *  )&      __debuggerWatchingP  - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrDebuggerWatchingP));

	assert(((char *  )&      __debuggerHookDataP  - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrDebuggerHookDataP));

	assert(((char *  )&      __debuggerHookFN     - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrDebuggerHookFN));

#endif

	assert(((char *  )&      __exceptFlags        - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrExceptFlags));

	assert(((char *  )&      __throwFileName      - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrThrowFileName));

	assert(((char *  )&      __throwLineNumber    - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrThrowLineNumber));

	assert(((char *  )&      __throwExceptionName - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrThrowExceptionName));

	assert(((char *  )&      __exceptStaticBuffP  - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrExceptStaticBuffP));

	assert(((char *  )&      __exceptMemAllocVars - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrExceptMemAllocVars));

	assert(((char *  )&      __terminatePTR       - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrTerminatePTR));

	assert(((char *  )&      __unexpectdPTR       - (char *)infoPtr->varAddr) ==
	       ((unsigned)&X0P->xvrUnexpectdPTR));
}

///////////////////////////////////////////////////////////////////////////////
