/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.35.2.1 $ */

///////////////////////////////////////////////////////////////////////////////

#pragma inline

/* This file MUST be compiled WITHOUT comdefs (-V?-) since #pragma codestring
   is used here.
*/
#pragma option -V?-

	#define NEWXX                   // Local dtor count
#if defined(MAGIC)
	#define PRONTO                  // Delphi ctor/dtor support
	#define DELPHI_EXCEPTIONS       // OS exception support
#endif

//      #define NDEBUG

///////////////////////////////////////////////////////////////////////////////

#include <_defs.h>

#include <assert.h>
#include <string.h>
#include <typeinfo.h>
#include <float.h>
#include <_malloc.h>   // for __org_malloc and __org_free
using namespace std;

///////////////////////////////////////////////////////////////////////////////

	#define BACK_END_PSEUDOREG_BUG_HACK

//      #define __DONT_USE_OS_EXCEPTIONS__

///////////////////////////////////////////////////////////////////////////////

//      #define DEBUG
////////#define DEBUG_INIT

///////////////////////////////////////////////////////////////////////////////

//      #define DISP_TYPE_ID

//      #define DEBUG_THROW

///////////////////////////////////////////////////////////////////////////////

#ifdef  DEBUG
#define DPRINTF(x)      printf x
#else
#define DPRINTF(x)
#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef  DELPHI_EXCEPTIONS
#include "delphixx.h"
#endif

#define USE_XX_VARS
#include "xx.h"

#ifdef near
#undef near
#endif

#pragma option  -xd

#ifdef  NEWXX
static  int     __fakeDtorCount;

#define _DestructorCount __fakeDtorCount
#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef  PRONTODEBUGGER
/*
	Extremely important that this variable land in the data segment,
	or the Pronto debugger will fail because the startup code will
	initialize the BSS segment to zero.  Hence the = 0.
*/

/*
	This has been moved to the startup code, since we don't want to have
	a copy of it in DLLs.
*/
//__declspec(dllexport) int     __CPPdebugHook = 0;
extern  int             __CPPdebugHook;
extern  unsigned char   __isDLL;

int     *               __pCPPdebugHook;
#endif

///////////////////////////////////////////////////////////////////////////////

/*      The following two flags help to destroy delphi objects correctly.
	Here is the general idea we are implementing:
	Consider the following class hierarchy:
	pascal1
	pascal2 : pascal1
	pascal3 : pascal2
	cpp1 : pascal3
	cpp2 : cpp1
	cpp3 : cpp2
	1) throw exception in any of the pascal classes.  The cpp1 constructor
	   exception frame will catch the exception.
	   If the pascal3 class did not complete, the PARENT_CTOR_NOT_COMPLETED
	   flag is set, and the pascal3 destructor is called with a special
	   flag set. This will take care of the pascal classes.
	   Next the local_unwind will try to clean up cpp2. It determines that
	   cpp1 never completed, it sets the PARENT_CTOR_NOT_COMPLETED flag
	   and calls cpp1 destructor with a special flag set.
	   Similar to cpp3.
	2) throw exception in cpp1. The cpp1 constructor exception frame will
	   catch this. The PARENT_CTOR_COMPLETED flag is set and the pascal
	   destructors called.  Then cpp2 and cpp3 are cleaned up similar to
	   above 1).
	3) throws in cpp2 and cpp3 are handled similar to cpp1.
 */
	
#ifdef  NEWXX
#define PARENT_CTOR_COMPLETED             0x0001
#define PARENT_CTOR_NOT_COMPLETED         0x0002
#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef  DEBUG
static  void    dumpFSChain(void)
{
	unsigned long * fsZero;

	asm     mov     eax, fs:[0]
	fsZero = (unsigned long *)_EAX;
	printf("ERR chain at FS:0: ");
	while   (fsZero != (unsigned long *)0xffffffff)
	{
		printf("%08x ", fsZero);
		fsZero = (unsigned long *)*fsZero;
	}
	printf("\n");
}
#else
#define dumpFSChain()
#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef  PRONTODEBUGGER
static  void    initCPPdebugHook(void)
{
	__pCPPdebugHook = (int *)GetProcAddress(GetModuleHandleA(0), "___CPPdebugHook");

	if      (!__pCPPdebugHook)
		__pCPPdebugHook = &__CPPdebugHook;
}
#pragma startup initCPPdebugHook 0 /* Initializes the IDE debugger hook */
#endif

///////////////////////////////////////////////////////////////////////////////

#define xdObject(x)     ((void *)((x)->xdArgBuff ? (void __far *)(x)->xdValue \
				       : (void __far *)(x)->xdArgAddr))

extern  int     STDCC   invokeHnd();

extern  "C"
void    __cdecl __JumpToCatch__(void)
{
	__emit__(0x8B); __emit__(0xE3); /* mov esp, ebx */
	__emit__(0x8B); __emit__(0xE9); /* mov ebp, ecx */
	__emit__(0xFF); __emit__(0xE0); /* jmp eax      */
}

int     __cdecl _EXPDATA        __debuggerDisableTerminateCallback = 0;

#ifdef  DELPHI_EXCEPTIONS
/*
	This code is drawn primarily from the Delphi system unit for exception
	handling.  The behaviour is intended to parallel that of Delphi.
*/
static  unsigned char   mapException(EXCEPTION_RECORD *P)
{
	switch  (P->ExceptionCode)
	{
	case    STATUS_INTEGER_DIVIDE_BY_ZERO:  return 3;
	case    STATUS_ARRAY_BOUNDS_EXCEEDED:   return 4;
	case    STATUS_INTEGER_OVERFLOW:        return 5;

	case    STATUS_FLOAT_INEXACT_RESULT:
	case    STATUS_FLOAT_INVALID_OPERATION:
	case    STATUS_FLOAT_STACK_CHECK:       return 6;

	case    STATUS_FLOAT_DIVIDE_BY_ZERO:    return 7;
	case    STATUS_FLOAT_OVERFLOW:          return 8;

	case    STATUS_FLOAT_UNDERFLOW:
	case    STATUS_FLOAT_DENORMAL_OPERAND:  return 9;

	case    STATUS_ACCESS_VIOLATION:        return 11;
	case    STATUS_PRIVILEGED_INSTRUCTION:  return 12;
	case    STATUS_CONTROL_C_EXIT:          return 13;
	case    STATUS_STACK_OVERFLOW:          return 14;
	default:                                return 21;
	}
}

static  excDscPtr       allocExceptMem(unsigned size);
static  void            freeExceptMem(excDscPtr xdp);

typedef struct  OSExceptionTypeID
{
	tpidPtr         OSETid;
	unsigned char   OSETexceptionNum;
}       OSExceptionTypeID;

static  OSExceptionTypeID       OSExceptionTypeIDs[] =
	{
		{ 0,                                    0 },
		{ 0,                                    1 },
		{ 0,                                    2 },
		{ typeid(EDivByZero       &).tpp,       3 },
		{ typeid(ERangeError      &).tpp,       4 },
		{ typeid(EIntOverflow     &).tpp,       5 },
		{ typeid(EInvalidOp       &).tpp,       6 },
		{ typeid(EZeroDivide      &).tpp,       7 },
		{ typeid(EOverflow        &).tpp,       8 },
		{ typeid(EUnderflow       &).tpp,       9 },
//              { typeid(EInvalidCast     *).tpp,       10 },
		{ 0,                                    10 },
		{ typeid(EAccessViolation &).tpp,       11 },
		{ typeid(EPrivilege       &).tpp,       12 },
		{ typeid(EControlC        &).tpp,       13 },
		{ typeid(EStackOverflow   &).tpp,       14 },
	};

static  excDscPtr       getExceptionObject(EXCEPTION_RECORD *P, unsigned long osEsp, unsigned long osERR, PCONTEXT ctx)
{
	int             ErrorCode;
	excDscPtr       xdp;
	tpidPtr         typeID;
	tpidPtr         baseID;
	Exception *     excObj;
	unsigned short  mask;

	ErrorCode = mapException(P);

	if      (ErrorCode < 3 || ErrorCode > sizeof(OSExceptionTypeIDs) / sizeof(OSExceptionTypeIDs[0]))
		return 0;

	typeID = OSExceptionTypeIDs[ErrorCode].OSETid;

	switch  (ErrorCode)
	{
	case    3:      excObj = new EDivByZero("EDivByZero")           ; break;
	case    4:      excObj = new ERangeError("ERangeError")         ; break;
	case    5:      excObj = new EIntOverflow("EIntOverflow")       ; break;
	case    6:      excObj = new EInvalidOp("EInvalidOp")           ; break;
	case    7:      excObj = new EZeroDivide("EZeroDivide")         ; break;
	case    8:      excObj = new EOverflow("EOverflow")             ; break;
	case    9:      excObj = new EUnderflow("EUnderflow")           ; break;
//      case    10:     excObj = new EInvalidCast("EInvalidCast")       ; break;
	case    11:     excObj = new EAccessViolation("EAccessViolation"); break;
	case    12:     excObj = new EPrivilege("EPrivilege")           ; break;
	case    13:     excObj = new EControlC("EControlC")             ; break;
	case    14:     excObj = new EStackOverflow("EStackOverflow")   ; break;

	default:
		assert(!"Bad exception number");
		break;
	}

	mask = typeID->tpMask;
	assert(mask & TM_IS_REF);
	baseID = typeID->tpPtr.tppBaseType;

	xdp = allocExceptMem(sizeof(*xdp) + sizeof(Exception *));

	/* Fill in the 'throw descriptor' */

	xdp->xdPrevious	  = 0;
	xdp->xdTypeID     = typeID;
	xdp->xdFlags      = XDF_OSEXCEPTION;
	xdp->xdSize       = sizeof(Exception *);
	xdp->xdMask       = mask;
	xdp->xdCflg       = 0;
	xdp->xdBase       = baseID;
	xdp->xdFriendList = (tpidPtr TPDST *)0;
	xdp->xdERRaddr    = 0;
	xdp->xdHtabAdr    = 0;

	xdp->xdFreeFunc   = freeExceptMem;

	xdp->xdThrowLine  = 0;
	xdp->xdThrowFile  = 0;

	xdp->xdCCaddr     = 0;
	xdp->xdCCmask     = 0;

	xdp->xdArgCopy    = 0;
	xdp->xdArgBuff    = 1;
	xdp->xdOSESP      = osEsp;
	xdp->xdOSERR      = osERR;
	xdp->xdOSContext  = ctx;

	memcpy(xdp->xdValue, &excObj, sizeof(Exception *));

	return xdp;
}
#endif  // DELPHI_EXCEPTIONS

///////////////////////////////////////////////////////////////////////////////

#undef  __ExceptStaticXbuff

static  excDscPtr       allocExceptMem(unsigned size)
{
	void    *       p =        __org_malloc(size);

	if      (p == 0)
	{
		/* Out of memory: can we use the small static buffer? */

		if      (size > sizeof(__ExceptStaticXbuff) || (__exceptFlags & XF_STATIC_BUFF_USED))
			abort();

		__exceptFlags |= XF_STATIC_BUFF_USED;

		return  (excDscPtr)__exceptStaticBuffP;
	}

//      printf("XX: block at %p allocated (%u bytes).\n", p, size);

	return  (excDscPtr)p;
}

static  void            freeExceptMem(excDscPtr xdp)
{
//      printf("XX: block at %p freed up.\n", xdp);

	/* Is this our static buffer? */

	if      ((void *)xdp == (void *)__exceptStaticBuffP)
	{
		__exceptFlags &= ~XF_STATIC_BUFF_USED;
		return;
	}

	__org_free((void*)xdp);
}

///////////////////////////////////////////////////////////////////////////////
//
//      Determine whether the type 'srcid' can be caught by a handler
//      with the type 'dstid'. The 'flist' argument is the 'friend list'
//      for the thrown value.
//
//      If the 'fspec' argument is non-zero, we are verifying that a
//      a function is not throwing an exception not in its 'exception
//      specification' (its 'throw list'). Slightly different rules
//      seem to apply to that case.
//
//      Note that for handler matching we have to worry about standard
//      pointer conversions:
//
//         -    the value '0' can be converted to any pointer type
//
//         -    pointer to 'CV1 XXX *' can be converted to 'CV2 void *',
//              where 'CV2' is equal to or more CV-qualified than 'CV1'
//

static  int     __near  typeIDcaught(tpidPtr            srcid,
				     tpidPtr    TPDST * flist,
				     tpidPtr            dstid,
				     unsigned           flags,
				     int                fspec)
{
	unsigned        srcmask;
	unsigned        dstmask;

	/* If the types match, we're done */

	if      (__isCompatTypeID(srcid, dstid, 0, flist))
		return  1;

	/* Get the source and target masks */

	srcmask = srcid->tpMask;
	dstmask = dstid->tpMask;

#ifdef  DELPHI_EXCEPTIONS
	if      (flags & XDF_OSEXCEPTION && dstmask & TM_IS_REF)
	{
		/* Better have been thrown as a reference */
		assert(srcmask & TM_IS_REF);

		/* Allow [const] (Exception)& to catch (Execption)& */
		if      (__isCompatTypeID(srcid->tpPtr.tppBaseType, dstid->tpPtr.tppBaseType, 1, flist))
			return 1;
	}
#endif

	/* Is the target a reference? */

	if      (dstmask & TM_IS_REF)
	{
		/* Allow '[const] T&' to catch 'T' */

		if      (__isCompatTypeID(srcid, dstid->tpPtr.tppBaseType, 1, flist))
			return  1;

		/* Allow standard pointer conversions */

		dstid   = dstid->tpPtr.tppBaseType;
		dstmask = dstid->tpMask;

		/* Target must be a reference to a pointer type */

		if      (!(dstmask & TM_IS_PTR))
			return  0;

		/* Are the pointer types identical? */

		if      (__isCompatTypeID(srcid, dstid, 0, flist))
			return  1;

#ifndef __FLAT__

		/* Both pointers must have the same size */

		if      ((srcmask & (TM_IS_NEARPTR|TM_IS_FAR_PTR)) !=
			 (dstmask & (TM_IS_NEARPTR|TM_IS_FAR_PTR)))
		{
			return  0;
		}

#endif

		/* Fall trough to try special pointer type matches */
	}

	/* Is the target a pointer type? */

	if      (dstmask & TM_IS_PTR)
	{
		/* The value '0' can be caught by any pointer type */

		if      (flags & 0x0001)
			return  1;

		/* The source better be a pointer as well */

		if      (!(srcmask & TM_IS_PTR))
			return  0;

#ifndef __FLAT__

		/* Destination pointer may not be smaller */

		if      ((srcmask & TM_IS_FAR_PTR) && !(dstmask & TM_IS_FAR_PTR))
			return  0;

#endif

		/* Is the target 'void *' ? */

		if      (dstmask & TM_IS_VOIDPTR)
		{
			/*  Dst should be equal to or more cv-qualified than src */

			if      ((dstmask & TM_IS_CONST) || !(srcmask & TM_IS_CONST))
			{
				if      ((dstmask & TM_IS_VOLATILE) || !(srcmask & TM_IS_VOLATILE))
					return 1;
			}
		}
	}

	return  0;
}

///////////////////////////////////////////////////////////////////////////////
//
//      The following are used for the ctor/dtor 'mask':
//
//              far      function       0x0001
//
//              far      'this' pointer 0x0004
//
//              pascal   function       0x0002
//              fastcall function       0x0020
//
//              fastthis function       0x0080
//              thislast function       0x0100
//

static  void    __near  callCopyConstr(void     __far * dst,
				       void     __far * src,
				       void     __far * ctorAddr,
				       unsigned         ctorMask)
{
	DPRINTF(("\t\tCopying class from  %Fp to %Fp\n", src, dst));

	assert((ctorMask & 0x0100) != 0 ||
	       (ctorMask & 0x0020) == 0);       // thisfirst (-Vp) not supported with fastcall

	assert((ctorMask & 0x0080) == 0);       // fastthis  (-po) not supported

	if      (ctorMask & 0x1000)
	{
		/* Class has    virtual bases */

		switch  (ctorMask & 7)
		{
		case    1:      // __cdecl
			typedef void (__cdecl    *fp1)(void *, int, void *);
			((fp1)ctorAddr)(dst, 0, src);
			break;

		case    2:      // __pascal
			typedef void (__pascal   *fp2)(int, void *, void *);
			((fp2)ctorAddr)(0, src, dst);
			break;

		case    3:      // __fastcall
			typedef void (__fastcall *fp3)(void *, int, void *);
			((fp3)ctorAddr)(dst, 0, src);
			break;

#if     0
		case    4:      // __fortran
			typedef void (__fortran  *fp4)(int, void *, void *);
			((fp4)ctorAddr)(0, src, dst);
			break;
#endif

		case    5:      // __stdcall
			typedef void (__stdcall  *fp5)(void *, int, void *);
			((fp5)ctorAddr)(dst, 0, src);
			break;

#ifdef  __OS2__
		case    6:      // __syscall
			typedef void (__syscall  *fp6)(int, void *, void *);
			((fp6)ctorAddr)(0, src, dst);
			break;
#endif

		default:
			assert(!"what?");
		}
	}
	else
	{
		/* Class has no virtual bases */

		switch  (ctorMask & 7)
		{
		case    1:      // __cdecl
			typedef void (__cdecl    *fp1)(void *, void *);
			((fp1)ctorAddr)(dst, src);
			break;

		case    2:      // __pascal
			typedef void (__pascal   *fp2)(void *, void *);
			((fp2)ctorAddr)(dst, src);
			break;

		case    3:      // __fastcall
			typedef void (__fastcall *fp3)(void *, void *);
			((fp3)ctorAddr)(dst, src);
			break;

#if     0
		case    4:      // __fortran
			typedef void (__fortran  *fp4)(void *, void *);
			((fp4)ctorAddr)(dst, src);
			break;
#endif

		case    5:      // __stdcall
			typedef void (__stdcall  *fp5)(void *, void *);
			((fp5)ctorAddr)(dst, src);
			break;

#ifdef  __OS2__
		case    6:      // __syscall
			typedef void (__syscall  *fp6)(void *, void *);
			((fp6)ctorAddr)(dst, src);
			break;
#endif

		default:
			assert(!"what?");
		}
	}
}

#ifdef  PRONTODEBUGGER
static  int     typeIDnameLength(const char *name)
{
	int     res;

	res = 0;

	if      (name)
		while   (*(name++))
			res++;

	return res;
}

extern "C"      void __cdecl _EXPFUNC __raiseDebuggerException(XXdebuggerNotification kind,
							       int argCount, ...)
{
	asm     {
		lea     eax, kind
		push    eax                         //ptr to args
		mov     eax, argCount
		inc     eax
		inc     eax
		push    eax                         //number of arguments
		push    0                           //flags
		push    _DELPHI_DEBUGGER_XCPT_CODE  //code
		call    RaiseException
	}
}
#endif

static  void    __near  callDestructor(void     __far * dst,
				       void     __far * dstType,
#ifdef  NEWXX
				       unsigned         dstFlags,
#endif
				       void     __far * dtorAddr,
				       unsigned         dtorMask,
				       int              dtVbases)
{
	unsigned        flags = dtVbases ? 2 : 0;

	DPRINTF(("\t\tDestroying class at %Fp\n", dst));

#ifdef  NEWXX
	/*
		If the PARENT_CTOR_NOT_COMPLETED flag is set, it means two things.
		First, this is a delphiclass.  Second, the base classes did not
		complete their operations.  We have to pass a special flag to
		the dtor in this case.  There, a compiler generated test will
		make the correct things happen to the hierarchy for C++ and
		DELPHI native generated dtors, respectively.
	*/
	if      (dstFlags & PARENT_CTOR_NOT_COMPLETED)
		flags |= 0x80;
#endif

#ifdef DIABLO

	if      (__debuggerWatching)
	{
		__lockDebuggerData();
		__debuggerHookDataP->kind = DebuggerData::EventDestructor;
		__debuggerHookDataP->addr = (unsigned long) dtorAddr;
		__debuggerHookDataP->name = __typeIDname((tpidPtr)dstType);

		// Compute the length of the name
		
		__debuggerHookDataP->name_len = 0;
	
		char * the_name = __debuggerHookDataP->name;

		while ( the_name && * (the_name++) )
		    __debuggerHookDataP->name_len++;
		
		__debuggerHookDataP->objectAddr = dst;
		__debuggerHookFunction();
		__unlockDebuggerData();
	}
	
#endif

#ifdef  PRONTODEBUGGER
	/*
		N.B. ilink32 exported data, in memory image bug:
		This test used to read *__pCPPdebugHook only.  The incremental
		linker turned out to have a bug with exported data found in
		gamma that forced us to finesse the problem in the RTL.  When
		the incremental linker bug is fixed for exported data, then
		this code should reverted back to the clean version.
	*/
//      if      (*__pCPPdebugHook)
	if      ((*__pCPPdebugHook) == 2)
	{
		char *  name;

		name = __typeIDname((tpidPtr)dstType);
		__raiseDebuggerException(XXDNdtor,
					 3,
					 dtorAddr,
					 name,
					 typeIDnameLength(name)
					 );
	}
#endif

	assert((dtorMask & 0x0080) == 0);       // fastthis  (-po) not supported

	switch  (dtorMask & 7)
	{
	case    1:      // __cdecl
		typedef void (__cdecl    *fp1)(void *, int);
		((fp1)dtorAddr)(dst, flags);
		break;

	case    2:      // __pascal
		typedef void (__pascal   *fp2)(int, void *);
		((fp2)dtorAddr)(flags, dst);
		break;

	case    3:      // __fastcall
		typedef void (__fastcall *fp3)(void *, int);
		((fp3)dtorAddr)(dst, flags);
		break;

#if     0
	case    4:      // __fortran
		typedef void (__fortran  *fp4)(int, void *);
		((fp4)dtorAddr)(flags, dst);
		break;
#endif

	case    5:      // __stdcall
		typedef void (__stdcall  *fp5)(void *, int);
		((fp5)dtorAddr)(dst, flags);
		break;

#ifdef  __OS2__
	case    6:      // __syscall
		typedef void (__syscall  *fp6)(int, void *);
		((fp6)dtorAddr)(flags, dst);
		break;
#endif

	default:
		assert(!"what?");
	}
}

static  void    __near  callMemberFunc(void     __far * thisVal,
				       void     __far * mfnAddr,
				       unsigned         mfnMask)
{
	assert((mfnMask & 0x0080) == 0);        // fastthis  (-po) should not occur here

	switch  (mfnMask & 7)
	{
	case    1:      // __cdecl
		typedef void (__cdecl    *fp1)(void *);
		((fp1)mfnAddr)(thisVal);
		break;

	case    2:      // __pascal
		typedef void (__pascal   *fp2)(void *);
		((fp2)mfnAddr)(thisVal);
		break;

	case    3:      // __fastcall
		typedef void (__fastcall *fp3)(void *);
		((fp3)mfnAddr)(thisVal);
		break;

#if     0
	case    4:      // __fortran
		typedef void (__fortran  *fp4)(void *);
		((fp4)mfnAddr)(thisVal);
		break;
#endif

	case    5:      // __stdcall
		typedef void (__stdcall  *fp5)(void *);
		((fp5)mfnAddr)(thisVal);
		break;

#ifdef  __OS2__
	case    6:      // __syscall
		typedef void (__syscall  *fp6)(void *);
		((fp6)mfnAddr)(thisVal);
		break;
#endif

	default:
		assert(!"what?");
	}
}

///////////////////////////////////////////////////////////////////////////////

#if     !defined(__WIN32__)

void    RAISECC RaiseException(unsigned long            dwExceptionCode,
			       unsigned long            dwExceptionFlags,
			       unsigned long            nNumberOfArguments,
			       unsigned long    __far * lpArguments);

#endif

///////////////////////////////////////////////////////////////////////////////
//
//      Called to throw/re-throw an exception.
//

static  void    __cdecl tossAnException(void    __far * tpid,
				void    __far * throwAddr,
				void    __far * friendList,
				void    __far * cctrAddr,
				unsigned        cctrMask,
				unsigned        flags,
				unsigned        throwLine,
				unsigned char * throwFile,
				unsigned long   throwPC,
				int             reThrow,
				PREGREC_BC      errPtr
#ifdef  PRONTODEBUGGER
				, unsigned long * userRegisters
#endif
				)
{
	tpidPtr         typeID = (tpidPtr)tpid;
	tpidPtr         baseID;
	unsigned        size;
	unsigned        mask;
	unsigned        cflg;

	excDscPtr       xdp;

	unsigned long   argTable[3];

	/* We are officially working on an exception.
	   See uncaught_exception in xxv.cpp */

	__exceptFlags |= XF_UNCAUGHT_EXCEPTION;

#ifdef  __OS2__
//      printf("Debugger info pointer   value: 0x%08X\n", __DebuggerInfoPtr);
//      printf("Debugger info signature value: 0x%08X\n", __DebuggerInfoPtr->DTsignature);
#endif

#ifdef  DEBUG_INIT
	printf("Address of __CPPexceptionList: 0x%08X\n", &__CPPexceptionList);
	printf("Address of __exception_irec  : 0x%08X\n", &__exception_irec  );
	printf("Address of __exception_code  : 0x%08X\n", &__exception_code  );
	printf("Address of __exception_irecMT: 0x%08X\n", &__exception_irecMT);
	printf("Address of __exception_codeMT: 0x%08X\n", &__exception_codeMT);
	printf("Address of __exception_infoMT: 0x%08X\n", &__exception_infoMT);
	printf("Address of _DestructorCountMT: 0x%08X\n", &_DestructorCountMT);
#endif

	/* Set global variables */

	__throwExceptionName = typeID ? (tpchPtr)typeID + typeID->tpName : NULL;

	__throwLineNumber =         throwLine;
	__throwFileName   = (char *)throwFile;

#ifdef  PRONTO
	/*
		The only way that we could get here with a NULL typeID is if we are
		rethrowing an exception that was issued from Delphi code, and caught
		by a ... handler.  In this case, we have to permit the NULL typeID,
		and simply reissue the exception.
	*/
	assert(typeID || (reThrow && (flags & XDF_ISDELPHIEXCEPTION)));

	/*
		If this is a delphiclass object that we're tossing around,
		then we want to rethrow it as a Pascal exception, not a C++
		exception.  That will keep the world as close to consistent
		as we can come.
	*/
	if      ((typeID && (typeID->tpMask & TM_IS_CLASS) && (typeID->tpClass.tpcFlags & CF_DELPHICLASS)) ||
			 (flags & XDF_ISDELPHIEXCEPTION))
	{
		baseID = typeID;
		if	(typeID && typeID->tpMask & (TM_IS_PTR|TM_IS_REF))
			baseID = baseID->tpPtr.tppBaseType;
		/*
			The following code losely based on code in SYSTEM.PAS:
			
			!!!!!  IMPORTANT !!!!!!!!
			
			The pascal implementation only throws 7 arguments, but
			we need one more argument on the C++ side so we can
			include the actual type of the thrown object.
			In initCatchArgPascal, we use this type to set the
			type in the throw descriptor
			The way we discern between an exception record created
			by the Pascal RTL, and one created by us, is the number
			of pushed arguments, we have 8, pascal has 7.
			
			!!!!!!!!!!!!!!!!!!!!!!!!!
			If you change this code, please consult the engineer
			responsible for system.pas, and look at the code in
			procedure _RaiseExcept.
			!!!!!!!!!!!!!!!!!!!!!!!!!
		*/
		throwPC -= 4;           // Delphi debugger will subtract 1!
					// See John Kline!
		asm     {
#if 0
			push    esp
			push    ebp
			push    edi
			push    esi
			push    ebx
			push    throwAddr
			push    0
#endif
			push	baseID		 /* type of thrown object */
			push    userRegisters[6] /* esp */
			push    userRegisters[5] /* ebp */
			push    userRegisters[3] /* edi */
			push    userRegisters[4] /* esi */
			push    userRegisters[1] /* ebx */
			push    throwAddr        /* object addr */
			push    throwPC          /* user EIP - 4! */
			push    esp
			push    8
			push    0xC0000025
			push    PAS_EXCEPT_CODE
			call    RaiseException
		}
	}
#endif

	/* Find the size, mask, and the 'base type' of the exception */

	baseID = typeID;

	size = typeID->tpSize;
	mask = typeID->tpMask;
	cflg = IS_CLASS(mask) ? typeID->tpClass.tpcFlags : 0;

	/* Get the 'base type' if this is a pointer or reference */

	if      (mask & (TM_IS_PTR|TM_IS_REF))
		baseID = baseID->tpPtr.tppBaseType;

#ifdef  DEBUG_THROW

	printf("ThrowException:\n");

	printf("\t\tThrow line number    = %u  \n", throwLine);
	printf("\t\tThrow file name      = '%s'\n", throwLine ? (char *)throwFile : "<none>");

	printf("\t\tException type       = '%s'\n", __typeIDname(typeID));
	printf("\t\tException size       = %04X\n", size);
	printf("\t\tException mask       = %04X\n", mask);
	printf("\t\tException base type  = '%s'\n", __typeIDname(baseID));
	printf("\t\tException zero value = %c  \n", (flags & XDF_ZEROPOINTER) ? 'Y' : 'N');
	printf("\t\tException throw addr = %Fp \n", throwAddr);
	printf("\t\tException cctr  addr = %Fp \n", cctrAddr);
	printf("\t\tException cctr  mask = %Fp \n", cctrAddr);
	printf("\t\tFriend list          = ");

	if      (friendList)
	{
		tpidPtr TPDST * fls;

		printf("\n");

		for     (fls = (tpidPtr TPDST *)friendList; *fls; fls++)
		{
			printf("\t\t\t\tClass '%s'\n", __typeIDname(*fls));
		}
	}
	else
	{
		printf("NONE\n");
	}

#endif

	DPRINTF(("ThrowException('%s')\n", __typeIDname(typeID)));

	/*
		Allocate memory for the 'throw descriptor'
		structure, and hook it into the list.
	 */

	xdp = allocExceptMem(sizeof(*xdp) + size);

	/* Fill in the 'throw descriptor' */

	xdp->xdPrevious	  = 0;
	xdp->xdTypeID     = typeID;
	xdp->xdFlags      = flags;
	xdp->xdSize       = size;
	xdp->xdMask       = mask;
	xdp->xdCflg       = cflg;
	xdp->xdBase       = baseID;
	xdp->xdFriendList = (tpidPtr TPDST *)friendList;
	xdp->xdERRaddr    = 0;
	xdp->xdHtabAdr    = 0;

	xdp->xdFreeFunc   = freeExceptMem;

	xdp->xdThrowLine  = throwLine;
	xdp->xdThrowFile  = (unsigned char __far *)throwFile;

	xdp->xdCCaddr     = cctrAddr;
	xdp->xdCCmask     = cctrMask;

	xdp->xdArgCopy    = 0;
	xdp->xdArgBuff    = 1;

	memcpy(xdp->xdValue, throwAddr, size);

#ifdef DIABLO

	if      (__debuggerWatching)
	{
		if      (!reThrow)
		{
			__lockDebuggerData();
			__debuggerHookDataP->msg = 0;
			__debuggerHookDataP->msg_len = 0;
			__debuggerHookDataP->kind = DebuggerData::EventThrow;
			__debuggerHookDataP->addr = (unsigned long)throwPC;
			__debuggerHookDataP->cookie = (unsigned long)xdp;
			__debuggerHookDataP->name = __typeIDname(typeID);
			__debuggerHookDataP->objectAddr = xdObject(xdp);
			
			// Compute the length of the name

			__debuggerHookDataP->name_len = 0;

			char * the_name = __debuggerHookDataP->name;

			while ( the_name && * (the_name++) )
			    __debuggerHookDataP->name_len++;

			__debuggerHookFunction();
			__unlockDebuggerData();
		}
	}

#endif

#ifdef  PRONTODEBUGGER
	/*
		See 'N.B. ilink32 exported data, in memory image bug:' above.
	*/
//      if      (*__pCPPdebugHook)
	if      ((*__pCPPdebugHook) == 1 || (*__pCPPdebugHook) == 2)
	{
		char *  name;

		name = __typeIDname(typeID);
		__raiseDebuggerException(XXDNthrow,
					 11,
					 throwPC - 5,
					 name,
					 typeIDnameLength(name),
					 xdObject(xdp),
					 userRegisters[0],
					 userRegisters[1],
					 userRegisters[2],
					 userRegisters[3],
					 userRegisters[4],
					 userRegisters[5],
					 userRegisters[6]
					 );
	}
#endif

	/* Copy-construct the allocated object from the caller's copy */

	if      (cflg & CF_HAS_CTOR)
	{
		dtorCntType     saveDtorCount;

		assert(cctrAddr);

		saveDtorCount    = _DestructorCount;

		try
		{
			callCopyConstr(xdp->xdValue,
				       throwAddr,
				       cctrAddr,
				       cctrMask);
		}
		catch(...)
		{
			__call_terminate();
		}

		_DestructorCount = saveDtorCount;
	}

#ifdef  DEBUG_THROW
	printf("\n");
#endif

	argTable[0] = (unsigned long)(void __far *)__throwExceptionName;
	argTable[1] = (unsigned long)(void __far *)throwPC;
	argTable[2] = (unsigned long)(void __far *)xdp;

	/* Call the OS to throw the exception */

	RaiseException(CPP_EXCEPT_CODE,                 // exception code
		       EXCEPTION_NONCONTINUABLE,        // exception flags
		       3,                               // number of arguments
#ifdef DELPHI_EXCEPTIONS
		       argTable);                  // &arguments
#else
		       argTable);                       // &arguments
#endif
}

///////////////////////////////////////////////////////////////////////////////
//
//      The following macro is used to get the caller's register contents.
//

	/* Get the return address from the stack */

#ifdef  USE_INLINE_ASM

#define getCallersPC(throwPC,r) asm     mov     eax, [ebp+4+4*r]\
				asm     mov     throwPC, eax

#else

#define getCallersPC(throwPC,r) {                                       \
					unsigned _ss *  PCptr;          \
					typedef void    (*fptr)();      \
									\
					PCptr   = (unsigned     *)_EBP; \
									\
					throwPC = (unsigned long)(void (__far*)())*(fptr *)(PCptr + 1 + r);     \
				}
#endif

///////////////////////////////////////////////////////////////////////////////
//
//      Called by the compiler to throw an exception.
//
#ifdef  PRONTODEBUGGER
#ifndef NEWXX
#error Can't do PRONTODEBUGGER without NEWXX
#endif
#endif

#ifndef NEWXX
void    DEFCC   _ThrowException(void    __far * tpid,
				void    __far * throwAddr,
				void    __far * friendList,
				void    __far * cctrAddr,
				unsigned        cctrMask,
				unsigned        flags,
				unsigned        throwLine,
				unsigned char * throwFile)
#else
#ifdef  PRONTODEBUGGER
__declspec(naked) void    DEFCC   _ThrowExceptionLDTC(void    __far * tpid,
#else
void    DEFCC   _ThrowExceptionLDTC(void    __far * tpid,
#endif
				void    __far * throwAddr,
				void    __far * friendList,
				void    __far * cctrAddr,
				unsigned        cctrMask,
				unsigned        flags,
				unsigned        throwLine,
				unsigned char * throwFile,
				void          * errPtr)
#endif
{
#ifdef  PRONTODEBUGGER
	asm     {
	mov     ecx, esp
	add     ecx, 4
	push    ecx                     // Caller's ESP
	push    ebp                     // Other caller registers, excluding ECX
	push    esi
	push    edi
	push    edx
	push    ebx
	push    eax
	push    esp                     // Pointer to caller's registers
	// ECX points to all the arguments
	push    dword ptr [ecx + 32]    // errPtr
	push    0                       // for tossAnException
	push    dword ptr [ecx - 4]     // throwPC
	push    dword ptr [ecx + 28]    // throwFile
	push    dword ptr [ecx + 24]    // throwLine
	push    dword ptr [ecx + 20]    // flags
	push    dword ptr [ecx + 16]    // cctrMask
	push    dword ptr [ecx + 12]    // cctrAddr
	push    dword ptr [ecx + 8]     // friendList
	push    dword ptr [ecx + 4]     // throwAddr
	push    dword ptr [ecx]         // tpid
	call    near ptr tossAnException
	add     esp, 19*4
	ret
	}
#else
	unsigned long   throwPC; getCallersPC(throwPC, 0);

	tossAnException(tpid,
			throwAddr,
			friendList,
			cctrAddr,
			cctrMask,
			flags,
			throwLine,
			throwFile,
			throwPC,
			0
#ifdef  NEWXX
			,(PREGREC_BC)errPtr
#else
			,0
#endif
			);
#endif
}


///////////////////////////////////////////////////////////////////////////////
//
//      Called by the compiler to re-throw the current exception.
//

void    DEFCC   _ReThrowException(unsigned              throwLine,
				  unsigned char *       throwFile)
{
	void *  value;

#ifdef  PRONTODEBUGGER
	unsigned long * userRegisters;
	asm     {
	mov     ecx, ebp
	add     ecx, 8
	push    ecx                     // Caller's ESP
	push    dword ptr [ebp]         // Other caller registers, excluding ECX
	push    esi
	push    edi
	push    edx
	push    ebx
	push    eax
	mov     userRegisters, esp      // Pointer to caller's registers
	}
#endif

	unsigned long   throwPC; getCallersPC(throwPC, 0);

	excDscPtr       xdp;

	xdp = __CPPexceptionList;

	if      (xdp == 0)
	{
		/* Re-throw when no exception was being handled! */

		__call_terminate();
	}

	/* The following code does NOT work correctly. Specifically when
	   you look at the asm code, you'll see fs:[0] moved into eax
	   and then [eax] into eax, but the code that moves eax back into
	   fs:[0] is missing.  The net effect of this should have been to
	   take the current exception frame out of the chain.
	   Also, the osESP which is moved into esp is much LOWER on the
	   stack than the current esp, which means you are going to a place
	   on the stack long abandoned.
	   So for now this code is disabled again, till we figure out a better
	   way to do this
	 */
#if	0
#ifdef  DELPHI_EXCEPTIONS
	/*
		OS exceptions are handled specially on rethrows.  Since there
		may be foreign exception handling frames intervening between
		the current frame and the next C++ frame, we need to let the
		OS dispatch the exception in its original beauty.  This can be
		done because we haven't thrown away the stack frame for the
		main OS exception handler yet.  Hence we can still 'return'
		from that handler.  Before we do that, we have to make sure
		that there are no additional C++ catch frames local to this
		stack frame that would be interested in the exception.  Once
		that is done, we can remove the current exception record from
		the list, and return to the OS.
	*/
	if      (xdp->xdFlags & XDF_OSEXCEPTION)
	{
		unsigned long           osESP;
		unsigned long           currERR;
		PREGISTRATION_RECORD    osERR;

		asm     mov     eax, fs:[0]
		currERR = _EAX;
		if      (currERR == (unsigned long)xdp->xdERRaddr)
		{
DPRINTF(("_ReThrowException: restarting OS exception %08x\n", xdp));

			osESP = xdp->xdOSESP;

			osERR = (PREGISTRATION_RECORD)xdp->xdOSERR;
			assert(osERR->ERRnext != (void *)0xffffffff);
			osERR->ERRnext = *(void **)(osERR->ERRnext);
			__CPPexceptionList = xdp->xdPrevious;
			xdp->xdFreeFunc(xdp);
			asm     {
				mov     eax, fs:[0]
				mov     eax, [eax]
				mov     esp, osESP
				pop     ebp
				pop     esi
				pop     edi
				pop     ebx
				mov     eax, 1
				ret
			}
		}
		else
		{
#if 0
#pragma message Take this out before we ship
			printf("Note: Rethrowing an OS exception from other than its catch clause.\n"
			       "      The exception will be thrown as a C++ exception, rather than\n"
			       "      as a normal OS exception.\n");
#endif
		}
	}
#endif	// DELPHI_EXCEPTIONS
#endif	// 0

	/*
		Simply throw the current exception again.  Note that we do not
		pull the exception record off the __CPPexceptionList yet.  This
		will be done when we unwind past this exception handler as we
		rethrow.  The information in the exception record may be needed
		at that time.
	*/
#ifdef  PRONTO
	if      (xdp->xdFlags & XDF_ISDELPHIEXCEPTION)
	{
		assert(xdp->xdArgBuff);
		value = *(void __far **)xdp->xdValue;
	}
	else
#endif
	{
		value = xdp->xdArgBuff ? (void __far *)xdp->xdValue
				       : (void __far *)xdp->xdArgAddr;
	}

#ifdef  PRONTO
	/* Mark this as being rethrown so we can special case some things */
	xdp->xdFlags |= XDF_RETHROWN;
#endif

	tossAnException(xdp->xdTypeID,
			value,
			xdp->xdFriendList,
			xdp->xdCCaddr,
			xdp->xdCCmask,
			xdp->xdFlags,
			throwLine,
			throwFile,
			throwPC,
			1,
			0
#ifdef  PRONTODEBUGGER
			, userRegisters
#endif
			);
}

///////////////////////////////////////////////////////////////////////////////

extern  "C"     void    __cdecl __doGlobalUnwind(void);

extern "C"      void    DEFCC   _Global_unwind(PREGISTRATION_RECORD     target,
					       PEXCEPTION_RECORD        excPtr)
{
	EXCEPTION_RECORD        excRec;

	/* Create an unwind exception descriptor if not supplied by caller */

	if      (excPtr == 0)
	{
		/* Create an exception record for the unwind */

		excRec.ExceptionCode    = XCPT_UNWIND;
		excRec.ExceptionFlags   = UNWINDING;
		excRec.NumberParameters = 0;

#ifdef  DEBUG
		memset(excRec.ExceptionInformation, 0, sizeof(excRec.ExceptionInformation));
#endif

		excPtr = &excRec;
	}

	/* Be sure to let them know that we're unwinding */

	excPtr->ExceptionFlags |= UNWINDING;

	DPRINTF(("Performing doGlobalUnwind() - target = %08X\n", target));
	dumpFSChain();

#ifdef  BACK_END_PSEUDOREG_BUG_HACK
	_EAX = 123;
	_EDX = 123;
#endif
	_EAX = (int)target;
	_EDX = (int)excPtr;

	__doGlobalUnwind();

	DPRINTF(("Back from doGlobalUnwind().\n"));

#ifdef  DELPHI_EXCEPTIONS
	/*
		Clear the unwinding flag so that we don't confuse the OS on
		rethrows of OS exceptions.
	*/
	excPtr->ExceptionFlags ^= UNWINDING;
#endif

#ifdef  DEBUG
	PREGREC_BC      temp = (PREGREC_BC)_Exception_list;
	DPRINTF(("Target was %08lX; OS unwound to %08lX (prev = %08lX)\n", (long)target, (long)temp, (long)temp->ERRcNext));
#endif

}

///////////////////////////////////////////////////////////////////////////////
//
//      When a thrown value is no longer needed, it might need to be
//      destroyed if it is a class thrown by value. Given the address
//      of a thrown object and its destructor (plus its mask), this
//      function performs the necessary cleanup.
//

static  void    __near  destThrownValue(void    __far * objAddr,
					void    __far * objType,
					void    __far * dtorAddr,
					unsigned        dtorMask)
{
	assert(dtorAddr);

	try
	{
		callDestructor(objAddr, objType, 0, dtorAddr, dtorMask, 1);
	}
	catch(...)
	{
		__call_terminate();
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      A catch block is being exited or unwound; if the original thrown
//      value and/or the catch argument need destruction, we call their
//      destructor(s).
//

static  void    __near  exceptionHandled(excDscPtr xdp)
{
	/* Is the thrown value still present in the descriptor? */

	if      (xdp->xdArgBuff)
	{
		/* Destroy the thrown value if necessary */

		if      (xdp->xdCflg & CF_HAS_DTOR)
		{
			dtorCntType     saveDtorCount;
			tpidPtr         tpid;
			void *          obj;

			tpid = xdp->xdBase;

			saveDtorCount    = _DestructorCount;

			obj = xdp->xdValue;
#ifdef  PRONTO
			/* All delphi class objects are thrown by pointer, sort of */
			if      (tpid->tpClass.tpcFlags & CF_DELPHICLASS)
				obj = *(void **)obj;

			/*
				Don't destroy it if it's a delphi class and
				it's being rethrown.
			*/
			if      ((xdp->xdFlags & (XDF_ISDELPHIEXCEPTION | XDF_RETHROWN)) !=
				 (XDF_ISDELPHIEXCEPTION | XDF_RETHROWN))
#endif
			{
				destThrownValue(obj,
						tpid,
						tpid->tpClass.tpcDtorAddr,
						tpid->tpClass.tpcDtorMask);
			}

			_DestructorCount = saveDtorCount;
		}

		/* Mark the fact that the arg is gone */

		xdp->xdArgBuff = 0;
	}

	/* Did we make a copy of the argument? */

	if      (xdp->xdArgCopy)
	{
		tpidPtr         argType = xdp->xdArgType; assert(argType);

		/* Destroy the thrown value if necessary */

		if      (IS_CLASS(argType->tpMask) && (argType->tpClass.tpcFlags & CF_HAS_DTOR))
		{
			destThrownValue(xdp->xdArgAddr,
					argType,
					argType->tpClass.tpcDtorAddr,
					argType->tpClass.tpcDtorMask);
		}

		/* Mark the fact that the arg is gone */

		xdp->xdArgCopy = 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      Called by the compiler upon exit from a catch block. Deallocates
//      the memory allocated for the caught exception, and modifies the
//      current context to be the enclosing context.
//

void    DEFCC   _CatchCleanup(void)
{
	excDscPtr       xdrPtr;
	PREGREC_BC      errPtr;
	unsigned long   savedEBX;
	unsigned long   savedEDI;
	unsigned long   savedESI;

	savedEBX = _EBX;
	savedEDI = _EDI;
	savedESI = _ESI;

#ifdef  DELPHI_EXCEPTIONS
	int             isOSexceptionFrame;
	PCONTEXT        osContext;
	unsigned long   osESP;
#endif

	assert(__CPPexceptionList);

	/* Remove the current entry from the C++ exception list */

	xdrPtr = __CPPexceptionList;
		 __CPPexceptionList = xdrPtr->xdPrevious;

	/* Get the 'ERR' pointer from the exception descriptor */

	errPtr = xdrPtr->xdERRaddr;

#ifndef NDEBUG
	void    _ss *   xl = _Exception_list;

	assert(xl);
	assert(xdrPtr->xdERRaddr == xl);
//      assert(errPtr->ERRcCatcher == _ExceptionHandler);
#endif

	/* Set context to the enclosing context */

	errPtr->ERRcCCtx = *(unsigned short TPDST *)((char TPDST *)errPtr->ERRcXtab + errPtr->ERRcCCtx);

	/* Perform cleanup for this catch block */

	exceptionHandled(xdrPtr);

#ifdef  DELPHI_EXCEPTIONS
	isOSexceptionFrame = xdrPtr->xdFlags & XDF_OSEXCEPTION;
	if	(isOSexceptionFrame)
	{
		osESP = xdrPtr->xdOSESP;
		osContext = xdrPtr->xdOSContext;
	}
#endif
	/* Free the memory taken up by the exception descriptor */

	xdrPtr->xdFreeFunc(xdrPtr);

#ifdef  DELPHI_EXCEPTIONS
	/*
		In the case of OS exceptions, we can't just diddle the stack frame.
		We have to return through the OS in order to keep it from having
		a cow for fatal exceptions.
	*/
	if      (isOSexceptionFrame)
	{
		unsigned long   savedESP;

#ifdef  PRONTODEBUGGER
		/*
			The debugger signals us with __CPPdebugHook > 1 if
			it wants us to report where we're returning to once
			we finish cleaning up.
		*/
		/*
			See 'N.B. ilink32 exported data, in memory image bug:' above.
		*/
//              if      (*__pCPPdebugHook > 1)
		if      (*__pCPPdebugHook == 2)
		{
			__raiseDebuggerException(XXDNcatchTerminate,
						 1,
						 *(((unsigned long *)_EBP) + 1));
		}
#endif
		savedESP = errPtr->ERRcSPsv;
		_EBX = savedEBX;
		_EDI = savedEDI;
		_ESI = savedESI;
		asm     {
			mov     edx, savedESP
			mov     esp, ebp
			pop     ebp
			pop     eax
			mov     esp, edx
			push    eax
			ret
		}
	}
#endif

#ifdef  PRONTODEBUGGER
	/*
		The debugger signals us with __CPPdebugHook > 1 if
		it wants us to report where we're returning to once
		we finish cleaning up.
	*/
	/*
		See 'N.B. ilink32 exported data, in memory image bug:' above.
	*/
//      if      (*__pCPPdebugHook > 1)
	if      (*__pCPPdebugHook == 2)
	{
		__raiseDebuggerException(XXDNcatchTerminate,
					 1,
					 *(((unsigned long *)_EBP) + 1));
	}
#endif
	/*
		Finally, restore the ESP to that of the original function, and
		return.
	*/
	_EBX = savedEBX;
	_EDI = savedEDI;
	_ESI = savedESI;
	asm     {
		mov     eax, ebp
		mov     eax, dword ptr [ebp + 4]
		mov     edx, errPtr
		mov     edx, [edx + 12]
		mov     ebp, dword ptr [ebp]
		mov     esp, edx
		push    eax
		ret
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      We've found a matching catch block for Pascal exception, and we need
//      to initialize the catch argument with the thrown value.
//
#ifdef  PRONTO
static  void    __near  initCatchArgPascal(HD         TPDST * hdtPtr,
					   PREGREC_BC         errPtr,
					   PEXCEPTION_RECORD  excPtr,
					   HTD        TPDST * htdPtr,
					   unsigned           newBP,
					   unsigned             cctx)
{
	tpidPtr         tpid;
	excDscPtr       xdp;
	void    *       valAddr;
	tpidPtr         thrownTpid;

	tpid = hdtPtr->HDtypeID;
	assert(!tpid || tpid->tpMask & (TM_IS_PTR | TM_IS_REF));

	/*
		Allocate memory for the 'throw descriptor'
		structure, and hook it into the list.
	 */

	xdp = allocExceptMem(sizeof(*xdp) + sizeof(void *));

	/* Do this here only for Pascal exceptions - they're special */
	xdp->xdPrevious   = __CPPexceptionList;
			    __CPPexceptionList = xdp;

	/*
		IMPORTANT
		We first want to check if this is an exception re-thrown
		by us, or an exception created on the Pascal side.
		If it's one we created, we can find the true type of
		the thrown object.  If it's one from Pascal, that information
		is lost.
		This code depends on code in tossAnException, and code in
		system.pas in the pascal RTL.
	 */

	if	(excPtr->NumberParameters == 8)
	{
		/* It's one we threw in tossAnException */

		thrownTpid  = (tpidPtr)excPtr->ExceptionInformation[7];
		xdp->xdBase = thrownTpid;
		xdp->xdCflg = thrownTpid ? thrownTpid->tpClass.tpcFlags : 0;
	}
	else
	{
		thrownTpid = tpid;
		xdp->xdBase = tpid ? tpid->tpPtr.tppBaseType : 0;
		xdp->xdCflg = tpid ? tpid->tpPtr.tppBaseType->tpClass.tpcFlags : 0;
	}

	/* Fill in the 'throw descriptor' */

	xdp->xdTypeID     = thrownTpid;
	xdp->xdFlags      = XDF_ISDELPHIEXCEPTION;
	xdp->xdSize       = sizeof(void *);
	xdp->xdMask       = thrownTpid ? thrownTpid->tpMask : 0;
	xdp->xdFriendList = 0;
	xdp->xdERRaddr    = errPtr;
	xdp->xdHtabAdr    = hdtPtr;

	xdp->xdFreeFunc   = freeExceptMem;

	xdp->xdThrowLine  = 0;
	xdp->xdThrowFile  = (unsigned char __far *)0;

	xdp->xdCCaddr     = 0;
	xdp->xdCCmask     = 0;

	xdp->xdArgCopy    = 0;
	xdp->xdArgBuff    = 1;
	xdp->xdArgType    = tpid;
	xdp->xdContext    = cctx;

	*(void **)&xdp->xdValue[0] = (void *)excPtr->ExceptionInformation[1];

	/* Don't initialize the catch arg if this is a '...' handler */

	if      (!tpid)
		return;

	/* Don't initialize the catch arg if it is unnamed */

	if      (hdtPtr->HDflags & CHF_ARG_UNNAMED)
		return;

	/* Get the address of the thrown value */

	valAddr = xdp->xdValue;

	/* Remember that we made a copy of the thrown value */

	xdp->xdArgCopy = 1;

	/* Figure out the address of the catch arg */

	xdp->xdArgAddr = (void _ss *)(newBP + htdPtr->HTDargAddr);
	*(void **)xdp->xdArgAddr = *(void **)valAddr;
}
#endif

///////////////////////////////////////////////////////////////////////////////
//
//      We've found a matching catch block for an exception, and we need
//      to initialize the catch argument with the thrown value.
//

static  void    __near  initCatchArg(HD         TPDST * hdtPtr,
				     PREGREC_BC         errPtr,
				     excDscPtr          dscPtr,
				     HTD        TPDST * htdPtr,
				     unsigned           newBP)
{
	tpidPtr         hndTpid;
	tpidPtr         tpid;

	unsigned        size;
	unsigned        mask;
	unsigned        base;

	void    __far * valAddr;

	int             keepOldArg;

	assert(dscPtr->xdERRaddr == errPtr);
	assert(dscPtr->xdHtabAdr == hdtPtr);

	assert(dscPtr->xdArgCopy == 0);

	dscPtr->xdArgType = hndTpid = hdtPtr->HDtypeID;

	/* Don't initialize the catch arg if this is a '...' handler */

	if      (!hndTpid)
		return;

	/* Don't initialize the catch arg if it is unnamed */

	if      (hdtPtr->HDflags & CHF_ARG_UNNAMED)
		return;

	/*
		The best guess at this point is that we won't need to keep
		a copy of the original thrown object if the catch argument
		is 'const'.
	 */

	keepOldArg = !(hdtPtr->HDflags & CHF_ARG_CONST);

	/* Get the address of the thrown value */

	valAddr = dscPtr->xdValue;

	/* Remember that we made a copy of the thrown value */

	dscPtr->xdArgCopy = 1;

	/* Figure out the address of the catch arg */

	dscPtr->xdArgAddr = (void _ss *)(newBP + htdPtr->HTDargAddr);

	/*
		The special cases are:

		    -   integer '0' caught by a pointer

		    -   class pointer caught by another class pointer

		    -   class caught by value

		    -   class caught by reference

		    -   other caught by reference
	 */

	tpid = hndTpid;

	/* Get and skip the handler type size and mask */

	size = tpid->tpSize;
	mask = tpid->tpMask;

	/* Is the handler a pointer or reference? */

	base = mask;

	if      (mask & (TM_IS_PTR|TM_IS_REF))
	{
		/* Get the 'referred-to' type id */

		tpid = tpid->tpPtr.tppBaseType;

		/* Get the base type's mask */

		base = tpid->tpMask;
	}

	/* Are we catching the value '0' with a pointer handler? */

	if      ((mask & TM_IS_PTR) && (dscPtr->xdFlags & XDF_ZEROPOINTER))
	{
		/* Set the catch argument to NULL pointer */

		memset(dscPtr->xdArgAddr, 0, size);

		/* Keep the original argument, to be safe */

		keepOldArg = 1;

		goto DONE_ARG;
	}

	/* Is the handler type a pointer or reference to class? */

	if      (IS_STRUC(base) && (mask & (TM_IS_PTR|TM_IS_REF)))
	{
		/* Figure out the address of the thrown object */

		if      (mask & TM_IS_REF)
		{
			assert((dscPtr->xdMask & TM_IS_PTR) == 0);

			/* Handler is a reference, object is a class */

			keepOldArg = 1;

			/*
				Address of object already in 'valAddr', unless
				it's an OS exception.
			*/
#ifdef  DELPHI_EXCEPTIONS
			if      (dscPtr->xdFlags & XDF_OSEXCEPTION)
				valAddr = *(void __far * __far *)valAddr;
#endif
		}
		else
		{
			/* Both handler and object are pointers */

			assert(          mask & TM_IS_PTR);
			assert(dscPtr->xdMask & TM_IS_PTR);

			/* Address of object is the value thrown */

			valAddr = *(void __far * __far *)valAddr;
		}

		/* Adjust the class address if necessary */

		if      (!__isSameTypeID(dscPtr->xdBase, tpid))
		{
			void    __far * oldAddr = valAddr;

			valAddr = __adjustClassAdr(valAddr, dscPtr->xdBase, tpid);

			/* If pointer value changed, keep old arg */

			if      (valAddr != oldAddr)
				keepOldArg = 1;
		}

		/* Initialize catch arg with the adjusted address */

		memcpy(dscPtr->xdArgAddr, &valAddr, size);

		goto DONE_ARG;
	}

	/* Are we catching a class by value? */

	if      (IS_STRUC(dscPtr->xdMask))
	{
		assert(dscPtr->xdTypeID == dscPtr->xdBase);

		/* Does the handler type match the thrown value exactly? */

		if      (!__isSameTypeID(dscPtr->xdBase, tpid))
		{
			/*
				Adjust the address of the object, so that we
				use the correct object address for the copy.
			 */

			valAddr = __adjustClassAdr(valAddr, dscPtr->xdBase, tpid);

			/*
				We'll have to keep the original thrown object
				(even if it is 'const'), since the copy might
				change the value.
			 */

			keepOldArg = 1;
		}

		/* Now initialize the catch arg */

		if      (tpid->tpClass.tpcFlags & CF_HAS_CTOR)
		{
			assert(hdtPtr->HDcctrAddr);

			/* Init the arg via its copy-constructor */

			callCopyConstr(dscPtr->xdArgAddr,
				       valAddr,
				       hdtPtr->HDcctrAddr,
				       hdtPtr->HDcctrMask);

			/* Probably safer to keep original thrown value (?) */

			keepOldArg = 1;
		}
		else
		{
			/* Init the argument by bitwise copy */

			memcpy(dscPtr->xdArgAddr, valAddr, size);
		}

		goto DONE_ARG;
	}

	/* Is the handler arg a reference (to non-class) ? */

	if      (mask & TM_IS_REF)
	{
		/* Make the arg point at the thrown value */

		memcpy(dscPtr->xdArgAddr, &valAddr, size);

		/* Keep the original argument */

		keepOldArg = 1;

		goto DONE_ARG;
	}

	/* No adjustment to arg needed: do a bitwise copy */

	assert(dscPtr->xdSize == size);

	memcpy(dscPtr->xdArgAddr, valAddr, size);

DONE_ARG:

	/* Get rid of the thrown value if we have an exact copy */

	if      (!keepOldArg && (base & (TM_IS_STRUCT | TM_IS_CLASS))) /* Eli's fix */
	{
		/* Destroy original thrown value; no longer needed */

		if      (tpid->tpClass.tpcFlags & CF_HAS_DTOR)
		{
			destThrownValue(valAddr,
					tpid,
					tpid->tpClass.tpcDtorAddr,
					tpid->tpClass.tpcDtorMask);
		}

		/* Mark the fact that the arg is gone */

		dscPtr->xdArgBuff = 0;
	}
}

static  int     __near  dtorCleanup(DTT TPDST * dttPtr,
				    dtorCntType dtcMin,
				    PREGREC_BC  errPtr,
				    unsigned    newBP);

///////////////////////////////////////////////////////////////////////////////
//
//      This function is used to perform a 'within function' (local blocks
//      only) unwind to the given exception context.
//
//      Note:   one might naively expect the current exception list (at FS:0)
//              to be always equal to the 'ERR' pointer passed to a handler
//              when the stack is being unwound, but this is not the case.
//              Under OS/2 the value at FS:0 is the address of the next ERR
//              when a handler is called to unwind, and under NT it might be
//              a handler inserted by rtlUnwind(). To get around that, we
//              pass the current 'ERR' address to local_unwind explicitly.
//

static  void    __near  local_unwind(PREGREC_BC errPtr, unsigned target)
{
	EXCTABPTR       xctPtr;

#ifdef  DEBUG
	PREGREC_BC      excLst = (PREGREC_BC)_Exception_list;
#endif

	unsigned        context;
	unsigned        outer = 0;      /* Init to shut up warning */

	unsigned        newBP;

	int             dtcAdj = 0;

#ifdef  DEBUG
#ifdef  __FLAT__
	&excLst;
#endif
DPRINTF(("local_unwind: _ExcLst = %08lX, ERR = %08lX, target = %08X)\n", (long)excLst, (long)errPtr, target));
#endif

	/* Get the address of the try context table */

	xctPtr = errPtr->ERRcXtab;

DPRINTF(("local_unwind: context table is at 0x%08lX\n", (long)xctPtr));

	/* Compute the BP value needed for this function */

	newBP = (unsigned)(char __near *)errPtr - xctPtr->xtBPoffs;

	/* Now unwind the blocks until the target is reached */

	for     (context = errPtr->ERRcCCtx;
		 context && context != target;
		 context = outer)
	{
		excBlockKind    kind;

		unsigned        cctx = context;

DPRINTF(("local_unwind: current context = 0x%08X\n", context));

		/* Get the 'outer' context and save it for later */

		outer = *(unsigned short TPDST *)((char TPDST *)xctPtr + cctx);

		cctx += sizeof(short);

DPRINTF(("local_unwind: outer   context = 0x%08X\n", outer));

		/* Now get the 'kind' field */

		kind  = (excBlockKind)*(unsigned short TPDST *)((char TPDST *)xctPtr + cctx);

		cctx += sizeof(short);

DPRINTF(("local_unwind: table at %08lX, context = %04X [kind = %d , outer = %04X]\n", (long)xctPtr, context, kind, outer));

		/* Update the 'current context' value */

		errPtr->ERRcCCtx = outer;

		/* Now see what kind of a block we have here */

		switch  (kind)
		{
			excDscPtr       xdrPtr;
			excDscPtr __far*xdrLPP;

#ifdef  EXCEPT_C
		static  codePtr         finBody;
#endif

			signed int      dtcMin;
			DTT     TPDST * dttAdr;

		case    XB_TRYCPP:              /* try                (C++) */
#ifdef  EXCEPT_C
		case    XB_EXCEXP:              /* try/except(expr )  ("C") */
		case    XB_EXCCNS:              /* try/except(const)  ("C") */
#endif

			/* Ignore C++ try and try/except blocks when unwinding */

			break;

#ifdef  EXCEPT_C
		case    XB_FINALLY:             /* try/finally        ("C") */

			/* Get the 'finally' block address */

			finBody = *(codePtr TPDST *)((char TPDST *)xctPtr + cctx + sizeof(codePtr));

DPRINTF(("Unwinding '__finally' block: handler at %08lX\n", (long)finBody));

			/* Set the 'unwinding' flag to non-zero */

			errPtr->ERRcInfo.ERRcUnwind = 1;

			/* Now call the 'finally' block */

			__emit__(0x53);         /* push ebx */
			__emit__(0x55);         /* push ebp */
			__emit__(0x56);         /* push esi */
			__emit__(0x57);         /* push edi */

#ifdef  BACK_END_PSEUDOREG_BUG_HACK
			_ECX = 123;
			_EBX = 123;
#endif

			_ECX = newBP;
			_EBX = (int)&finBody;

			invokeHnd();

			__emit__(0x5F);         /* pop  edi */
			__emit__(0x5E);         /* pop  esi */
			__emit__(0x5D);         /* pop  ebp */
			__emit__(0x5B);         /* pop  ebx */

			/* Reset the 'unwinding' flag to zero and continue */

			errPtr->ERRcInfo.ERRcUnwind = 0;

			break;
#endif

		case    XB_CATCH:               /* catch              (C++) */

			/* Skip the 'handler table' field to find the 'catch' */

			cctx += sizeof(void TPDST *);

			/* First find the exception descriptor for the catch */
			
			for     ( xdrLPP = &__CPPexceptionList;
				 (xdrPtr = *xdrLPP) != 0;
				  xdrLPP = &xdrPtr->xdPrevious)
			{
				if      (xdrPtr->xdERRaddr == errPtr &&
					 xdrPtr->xdContext == context)
				{
					break;
				}
			}

			assert(xdrPtr && xdrPtr == *xdrLPP);

			/* Remove the exception entry from the list */

			*xdrLPP = xdrPtr->xdPrevious;

			/* Perform cleanup for this catch block */

			exceptionHandled(xdrPtr);

			/* Free the memory taken up by the exception descriptor */

			xdrPtr->xdFreeFunc(xdrPtr);
			break;

		case    XB_DEST:                /* destructor cleanup (C++) */

			/* Get the 'min dtor count' field */

			dtcMin = *(unsigned TPDST *)((char TPDST *)xctPtr + cctx);

			cctx  += sizeof(unsigned);

			/* Get the address of the dtor cleanup table */

			dttAdr = *(DTT __near * TPDST *)((char TPDST *)xctPtr + cctx);

			cctx  += sizeof(DTT __near *);

			/* Now we're ready to perform the cleanup */

#ifdef  NEWXX
			/*
				If this is a this pointer, dtcAdj better be 0, since there
				could not have been anything else to be destroyed already.
			*/
//                      assert(((dttPtr->dttFlags & DTCVF_THISCTX) && (dtcAdj == 0)) ||
//                             !(dttPtr->dttFlags & DTCVF_THISCTX));
#endif
			
			dtcAdj = dtorCleanup(dttAdr,
					     dtcMin + dtcAdj,
					     errPtr,
					     newBP);
			break;

		default:
			assert(!"bogus context in Local_unwind()");
			break;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      This function is used by the compiler to perform a 'within function'
//      unwind to the given exception context.
//
//      Under OS/2 and Win32/NT the current FS:0 may not always point to
//      the function's ERR, and so we have to pass its address explicitly
//      as an argument.
//

extern  "C"
void    DEFCC   _Local_unwind(void *errPtr, unsigned target)
{
	local_unwind((PREGREC_BC)errPtr, target);
}

///////////////////////////////////////////////////////////////////////////////
//
//      This function is used by the compiler for 'return' statements out
//      of exception handlers: it calls _Local_unwind() to clean up all
//      currently active blocks, and removes the current function's ERR
//      entry from the system's exception list.
//
//      Under OS/2 and Win32/NT the current FS:0 may not always point to
//      the function's ERR, and so we have to pass its address explicitly
//      as an argument.
//

extern  "C"
void    DEFCC   _Return_unwind(void * errPtr)
{
	local_unwind((PREGREC_BC)errPtr, 0);

	_Exception_list = ((PREGREC_BC)errPtr)->ERRcNext;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Given the address of a 'catch' handler table, and an exception
//      registration record for a Pascal exception, see if the table contains
//      a handler that can catch the given exception. Return its handler
//      table entry address if found, otherwise return 0.
//

#ifdef  PRONTO
static  HD      TPDST * __near  findMatchingHandlerPascal(HTD TPDST *           htdPtr,
							  PEXCEPTION_RECORD     excPtr)
{
	HD      TPDST * hdtPtr;

	/* Search the handler table for a matching handler */

	for     (hdtPtr = htdPtr->HTDtable; hdtPtr->HDhndPtr; hdtPtr++)
	{
		unsigned char   nameBuff[256];
		int             nameLen;
		char *          pName;
		char *          tmp;
		void *          pVTable;
		tpidPtr         tpid = hdtPtr->HDtypeID;

		/* If this is a '...' handler, it matches for sure */

		if      (tpid == 0)
		{
			return  hdtPtr;
		}

		/*
			Pascal exceptions are all pointers.  They can be caught
			by pointer or by reference.  Not by value.
		*/
		if      (!(tpid->tpMask & (TM_IS_PTR | TM_IS_REF)))
			continue;

		pName = __typeIDname(tpid);

		/*	Strip off any const and/or volatile qualifiers */
	
		do
		{
			tmp = pName;
			if	(0 == strncmp(tmp, "const ", 6))
			{
				pName += 6;
				continue;
			}
			if	(0 == strncmp(tmp, "volatile ", 9))
			{
				pName += 9;
				continue;
			}
		}
		while	(tmp != pName);

		/*
			Strip off any possible namespace qualifiers.  This is
			to work around an issue with Pascal created objects
			not having namespace qualifiers on their names.  This
			was done as a workaround for FT2.
		*/
		while   (*tmp)
		{
			if      (*tmp == ':')
				pName = tmp;
			tmp++;
		}
		if      (*pName == ':')
			pName++;
		nameLen = strlen(pName) - 2;

		/*
			If the length is > 255, can't be a catcher for a
			Pascal exception, since Pascal object names are
			limited to 255 chars.
		*/
		if      (nameLen > 255)
			continue;

		memcpy(nameBuff + 1, pName, nameLen);
		nameBuff[0] = (unsigned char)nameLen;

		DPRINTF(("Matching against handler type '%s'\n", pName));

		/* Get the Pascal vtable ptr */
#define vtParent(x)     *(((void **)(x)) - 9)
#define vtClassName(x)  *(((char **)(x)) - 11)
		pVTable = *(void **)excPtr->ExceptionInformation[1];
		while   (1)
		{
			if      (!memcmp(nameBuff, vtClassName(pVTable), *nameBuff + 1))
				break;
			pVTable = vtParent(pVTable);
			if      (pVTable == 0)
				break;
			pVTable = *(void **)pVTable;
		}

		if      (pVTable)
			return hdtPtr;
	}

	/* No luck with this exception handler, keep looking */

	return  0;
}
#endif

///////////////////////////////////////////////////////////////////////////////
//
//      Given the address of a 'catch' handler table, and an exception
//      description record for a C++ exception, see if the table contains
//      a handler that can catch the given exception. Return its handler
//      table entry address if found, otherwise return 0.
//

static  HD      TPDST * __near  findMatchingHandler(HTD TPDST * htdPtr,
						    excDscPtr   dscPtr)
{
	HD      TPDST * hdtPtr;

	/* Search the handler table for a matching handler */

	for     (hdtPtr = htdPtr->HTDtable; hdtPtr->HDhndPtr; hdtPtr++)
	{
		tpidPtr         tpid = hdtPtr->HDtypeID;

		/* If this is a '...' handler, it matches for sure */

		if      (tpid == 0)
		{
			return  hdtPtr;
		}

		DPRINTF(("Matching against handler type '%s'\n", __typeIDname(tpid)));

		if      (typeIDcaught(dscPtr->xdTypeID,
				      dscPtr->xdFriendList,
				      tpid,
				      dscPtr->xdFlags,
				      0))
		{
			return  hdtPtr;
		}
	}

	/* No luck with this exception handler, keep looking */

	return  0;
}

#ifdef  DELPHI_EXCEPTIONS
#define OS_EXCEPTION_FLAG       0x80000000L
#define isOSException(x)        ((x)->ExceptionCode & OS_EXCEPTION_FLAG)
#endif

///////////////////////////////////////////////////////////////////////////////
//
//      This is the OS exception handler used for try/catch frames; if we
//      are not unwinding at this point, it searches the handler list of
//      the try/catch block for a matching handler. If such a handler is
//      found, we initialize its catch argument as appropriate, unwind
//      all descendant stack frames, and jump to the handler body.
//

int     _RTLENTRY _EXPFUNC  ___ExceptionHandler(PEXCEPTION_RECORD excPtr,
						PREGREC_BC        errPtr,
						PCONTEXT          ctxPtr,
						void *            _dspPtr,
						unsigned long     OSEsp,
						unsigned long     /*OSEbp*/,
						unsigned long     /*OSEsi*/,
						unsigned long     /*OSEdi*/,
						unsigned long     /*OSEbx*/,
						unsigned long     flags)
{
	excDscPtr               dscPtr = (excDscPtr)excPtr->ExceptionInformation[2];

	EXCTABPTR               xctPtr;
	unsigned                context;
	unsigned                outer = 0;      /* Init to shut up warning */

	unsigned                newBP;
	unsigned                newSP;

	DPRINTF(("Exception chain at __ExceptionHandler:\n"));
	dumpFSChain();

	/* Get the address of the try context table */

	xctPtr = errPtr->ERRcXtab;

	/* Compute the BP and SP values needed for this function */

	newBP   = (unsigned)(char __near *)errPtr - xctPtr->xtBPoffs;
	newSP   = errPtr->ERRcSPsv;

#ifdef  PRONTODEBUGGER
	/*
		If this is a debugger exception, then we want to continue
		execution, since we must be in the middle of handling some
		exception.
	*/
	if      (excPtr->ExceptionCode == _DELPHI_DEBUGGER_XCPT_CODE)
		return CONTINUE_EXECUTION;
#endif

	/* Reset the floating point unit so we clear any exceptions */

	_fpreset();

	/* Are we unwinding? */

#ifdef  DEBUG
{
int     esp = _ESP;
DPRINTF(("_ExceptionHandler(excPtr at 0x%08lX, code = 0x%08lX, ESP = 0x%08lX) .... %s unwinding.\n", (long)excPtr, (long)excPtr->ExceptionCode, (long)esp, (excPtr->ExceptionFlags & UNWIND_IN_PROGRESS) ? (char*)"   " : (char *)"not"));
}
#endif

	if      (excPtr->ExceptionFlags & UNWIND_IN_PROGRESS)
	{
		/* We're unwinding --> perform cleanup via '_Local_unwind' */

#ifdef  DEBUG
PREGREC_BC      fooPtr = (PREGREC_BC)_Exception_list;
DPRINTF(("Unwind: _ExcLst = %08X, _ExcLst->prev = %08X, errPtr = %08X\n", fooPtr, fooPtr->ERRcNext, errPtr));
#endif

#ifdef  DEBUG
{
int     esp = _ESP;
DPRINTF(("Calling   local_unwind [ESP = 0x%08X]\n", esp));
}
#endif
		local_unwind(errPtr, 0);
#ifdef  DEBUG
{
int     esp = _ESP;
DPRINTF(("Back from local_unwind [ESP = 0x%08X]\n", esp));
}
#endif

		/* Is this is a C++ exception? */

		if      (excPtr->ExceptionCode == CPP_EXCEPT_CODE)
		{
			tpidPtr TPDST * throwList;

			DPRINTF(("Throw list is at 0x%08X.\n", xctPtr->xtThrowLst));

			/* Does this function have a 'throw-list' ? */

			throwList = xctPtr->xtThrowLst;
			if      (throwList)
			{
				/* Make sure the exception is permissible */

				while   (*throwList)
				{
					DPRINTF(("Throw list type '%s'.\n", __typeIDname(*throwList)));

					if      (typeIDcaught(dscPtr->xdTypeID,
							      dscPtr->xdFriendList,
							      *throwList,
							      dscPtr->xdFlags,
							      1))
					{
						goto THROW_OK;
					}

					throwList++;
				}

				DPRINTF(("A C++ function threw an unexpected exception!\n"));

				/* We have to preserve the exception chain */

				void    _ss *   saveExcList;

				saveExcList = _Exception_list;

				/* Remove the function's ERR from the chain */

				_Exception_list = errPtr->ERRcNext;

				__call_unexpected();

				/* Restore the exception chain */

				_Exception_list = saveExcList;
			}
		}

	THROW_OK:

		return  CONTINUE_SEARCH;
	}

#ifdef DIABLO
	if      (excPtr->ExceptionCode != CPP_EXCEPT_CODE)
	{
		if      (__debuggerWatching)
		{
			__lockDebuggerData();
			__debuggerHookDataP->kind = DebuggerData::EventRawExceptionStart;
			__debuggerHookDataP->addr = (unsigned long) 0;
			__debuggerHookDataP->cookie = (unsigned long) _errPtr;
			__debuggerHookDataP->exception_num = (unsigned long) excPtr->ExceptionCode;
			__debuggerHookFunction();
			__unlockDebuggerData();
		}
	}
#endif
	
	/* Now process the currently active exception handling blocks */

	for     (context = errPtr->ERRcCCtx; context; context = outer)
	{
		excBlockKind    kind;

		unsigned        cctx = context;

		/* Get the 'outer' context and save it for later */

		outer = *(unsigned short TPDST *)((char TPDST *)xctPtr + cctx);

		cctx += sizeof(short);

		/* Now get the 'kind' field */

		kind  = (excBlockKind)*(unsigned short TPDST *)((char TPDST *)xctPtr + cctx);

		cctx += sizeof(short);

DPRINTF(("Searching exception handling context at %04X: kind = %d (outer = %04X)\n", context, kind, outer));

		/* Now see what kind of a block we have here */

		switch  (kind)
		{
			HD      TPDST * hdtPtr;
			HTD     TPDST * htdPtr;

			codePtr         hanAdr;

			unsigned        newctx;
			unsigned        tgtctx;

#ifdef  EXCEPT_C

			EXCEPTION_PTRS  exception_irec;

		static  codePtr         filterExpr;
			int             filter;

#endif

		case    XB_TRYCPP:              /* try                (C++) */

#ifdef  DELPHI_EXCEPTIONS
			/*
				If this is an OS exception, we have to decode it and see
				if there is a handler that would be interested in it at
				this frame.  A handler that would be interested in it
				would be written to catch one of several predefined classes
				for handling OS exceptions.  These class names are hardcoded
				here, and cannot be changed in the RTL.  The classes
				match the Delphi32 exeption classes.
			*/
			if      (isOSException(excPtr) && (flags & XPF_CATCHOS))
			{
                                unsigned long   osERR;

				asm     mov     eax, fs:[0]
				asm     mov     osERR, eax
				dscPtr = getExceptionObject(excPtr, OSEsp, osERR, ctxPtr);
				if      (!dscPtr)
					break;
			}
			else
#endif
			{
                                /*
                                   If we're not processing a C++ exception
                                   (or it is not a Pascal exception and
                                   Pascal handling is enabled), then
                                   continue searching for a handler.
                                 */

                                switch  (excPtr->ExceptionCode)
                                {
                                case    CPP_EXCEPT_CODE: break;
#ifdef PRONTO
                                case    PAS_EXCEPT_CODE: if (flags & XPF_CATCHPAS) break;
#endif
                                default:                 continue; 
                                }
			}

			/* Get the body/table field */
	
			htdPtr = *(HTD TPDST * TPDST *)((char TPDST *)xctPtr + cctx);

			cctx  += sizeof(HTD TPDST *);


			/* Look for a matching handler */

#ifdef  PRONTO
			if      (excPtr->ExceptionCode == PAS_EXCEPT_CODE)
			{
//                              DPRINTF(("Matching catch handlers against Delphi type '%s'\n", char *));
				hdtPtr = findMatchingHandlerPascal(htdPtr, excPtr);
			}
			else
#endif
			{
				DPRINTF(("Matching catch handlers against type '%s'\n", __typeIDname(dscPtr->xdTypeID)));

				hdtPtr = findMatchingHandler(htdPtr, dscPtr);
			}

			/* If no match found, forget it */

			if      (!hdtPtr)
			{
#ifdef  DELPHI_EXCEPTIONS
				/*
					If nobody wanted this exception at this point,
					and the exception was an OS exception, we
					have to clean up the memory we allocated
					for the descriptor.
				*/
				if      (isOSException(excPtr))
				{
					__CPPexceptionList = dscPtr->xdPrevious;
					delete(*(Exception **)dscPtr->xdValue);
					(dscPtr->xdFreeFunc)(dscPtr);
				}
#endif
				break;
			}

#ifdef  PRONTODEBUGGER
			/*
				See 'N.B. ilink32 exported data, in memory image bug:' above.
			*/
//                      if      (*__pCPPdebugHook && (excPtr->ExceptionCode < 0xeedface || excPtr->ExceptionCode > 0xeefface))
			if      (((*__pCPPdebugHook) == 1 || (*__pCPPdebugHook) == 2) &&
				 (excPtr->ExceptionCode < 0xeedface || excPtr->ExceptionCode > 0xeefface))
			{
				__raiseDebuggerException(XXDNrawException,
							 3,
							 errPtr,
							 excPtr,
							 ctxPtr
							 );
			}
#endif
			DPRINTF(("Handler matched:\n"));

			DPRINTF(("hdtPtr           = %p\n", hdtPtr));
			DPRINTF(("hdtPtr->HDhndPtr = %p\n", hdtPtr->HDhndPtr));
			DPRINTF(("hdtPtr->HDtypeID = %p"  , hdtPtr->HDtypeID));
			DPRINTF((" ('%s')", hdtPtr->HDtypeID ?
					   __typeIDname(hdtPtr->HDtypeID) :
					   "no name"));
			DPRINTF(("\n"));

			/* Found a handler; remember the matching handler, etc. */

#ifdef  PRONTO
			if      (excPtr->ExceptionCode != PAS_EXCEPT_CODE)
#endif
			{
				/* Hook the exception into our exception list */
				dscPtr->xdPrevious = __CPPexceptionList;
						     __CPPexceptionList = dscPtr;

				dscPtr->xdERRaddr = errPtr;     /* 'ERR' address    */
				dscPtr->xdHtabAdr = hdtPtr;     /* matching handler */
				dscPtr->xdContext = cctx;       /* matching context */
			}

			/* Set the 'target' and 'new' context values */

			tgtctx = context;
			newctx = cctx;

			/* Get the handler address */

			hanAdr = hdtPtr->HDhndPtr;

		JUMP_HAND:

			/* Unwind up to this stack frame */

#if     0
			{
			unsigned        sp, bp; sp = _SP; bp = _BP;
			printf("About to perform '_Global_unwind': BP = %08X, SP = %08X\n", bp, sp);
			}
#endif

			_Global_unwind((PREGISTRATION_RECORD)errPtr, excPtr);

#if     0
			{
			unsigned        sp, bp; sp = _SP; bp = _BP;
			printf("Back from        '_Global_unwind': BP = %08X, SP = %08X\n", bp, sp);
			}
#endif

			/* Now unwind local blocks up to the desired target */

			local_unwind(errPtr, tgtctx);

			/* Set the new 'current' context */

			errPtr->ERRcCCtx = newctx;

			/* Initialize the catch argument, if appropriate */

			if      (kind == XB_TRYCPP)
			{
#ifdef  PRONTO
				if      (excPtr->ExceptionCode == PAS_EXCEPT_CODE)
					initCatchArgPascal(hdtPtr, errPtr, excPtr, htdPtr, newBP, cctx);
				else
#endif
					initCatchArg(hdtPtr, errPtr, dscPtr, htdPtr, newBP);
			}

			/* Seems we have officially caught the exception,
			   see uncaught_exception in xxv.cpp */

			__exceptFlags &= ~XF_UNCAUGHT_EXCEPTION;

			DPRINTF(("Transferring to exception handler body:\n"));

			DPRINTF(("\t\t\t\tBody starts at %08X\n", hanAdr));
			DPRINTF(("\t\t\t\tSaved 'EBP' is %08X\n", newBP));
			DPRINTF(("\t\t\t\tSaved 'ESP' is %08X\n", newSP));

#ifdef  DIABLO

			if      (__debuggerWatching)
			{
				__lockDebuggerData();
				__debuggerHookDataP->kind = DebuggerData::EventCatch;
				__debuggerHookDataP->addr = (unsigned long)hanAdr;
				__debuggerHookDataP->name = __typeIDname(dscPtr->xdTypeID);
				__debuggerHookDataP->objectAddr = xdObject(dscPtr);
				__debuggerHookFunction();
				__unlockDebuggerData();
			}

#endif

#ifdef  PRONTODEBUGGER
			/*
				See 'N.B. ilink32 exported data, in memory image bug:' above.
			*/
//                      if      (*__pCPPdebugHook && kind == XB_TRYCPP)
			if      ((*__pCPPdebugHook == 2) && kind == XB_TRYCPP)
			{
#ifdef  PRONTO
				char    pascalName[256];
#endif
				char *  name;

#ifdef  PRONTO
				if      (excPtr->ExceptionCode == PAS_EXCEPT_CODE)
				{
					void *  pVTable;

					pVTable = *(void **)excPtr->ExceptionInformation[1];
					name = vtClassName(pVTable);
					strncpy(pascalName, name + 1, *name);
					pascalName[*name] = 0;
					name = pascalName;
				}
				else
#endif
					name = __typeIDname(dscPtr->xdTypeID);

				__raiseDebuggerException(XXDNcatch,
							 5,
							 hanAdr,
							 name,
							 typeIDnameLength(name),
#ifdef  PRONTO
							 excPtr->ExceptionCode == PAS_EXCEPT_CODE       ?
								(void *)excPtr->ExceptionInformation[1] :
#endif
								xdObject(dscPtr)
							 );
			}
#endif

			/* Set BP, SP, and jump to handler body */

#ifdef  BACK_END_PSEUDOREG_BUG_HACK
			_EAX = 123;
			_EBX = 123;
			_ECX = 123;
#endif
			_EAX = (unsigned)hanAdr;
			_EBX = (unsigned)newSP;
			_ECX = (unsigned)newBP;

			__JumpToCatch__();

			break;

#ifdef  EXCEPT_C

		case    XB_EXCEXP:              /* try/except(expr )  ("C") */


#ifndef CATCH_CPP_XXS_IN_C
                        /* Should we remove this 'if' and allow __except blocks
                           to get called for C++ exceptions? --jjp 10/28/99 */

			/* Ignore it if it's a C++ exception */

			if      (excPtr->ExceptionCode == CPP_EXCEPT_CODE)
				break;
#endif
			/* Set the 'exception_code/info' variables */

			exception_irec.ExceptionRecord = excPtr;
			exception_irec.ContextRecord   = ctxPtr;

			errPtr->ERRcInfo.ERRcExcCode   = excPtr->ExceptionCode;
			errPtr->ERRcInfo.ERRcExcInfo   = &exception_irec;

DPRINTF(("Evaluating filter expression, exception code = 0x%08X\n", excPtr->ExceptionCode));

			/* Evaluate the filter expression */

			filterExpr = *(codePtr TPDST *)((char TPDST *)xctPtr + cctx);

			__emit__(0x53);         /* push ebx */
			__emit__(0x55);         /* push ebp */
			__emit__(0x56);         /* push esi */
			__emit__(0x57);         /* push edi */

#ifdef  BACK_END_PSEUDOREG_BUG_HACK
			_ECX = 123;
			_EBX = 123;
#endif
			_ECX = newBP;
			_EBX = (int)&filterExpr;

			filter = invokeHnd();

			__emit__(0x5F);         /* pop  edi */
			__emit__(0x5E);         /* pop  esi */
			__emit__(0x5D);         /* pop  ebp */
			__emit__(0x5B);         /* pop  ebx */

			goto GOT_FILTER;

		case    XB_EXCCNS:              /* try/except(const)  ("C") */

			/* Ignore it if it's a C++ exception */

			if      (excPtr->ExceptionCode == CPP_EXCEPT_CODE)
				break;

			/* Set the 'exception_code' variable */

			errPtr->ERRcInfo.ERRcExcCode = excPtr->ExceptionCode;

			/* Get the filter expression value from the table */

			filter = *(int TPDST *)((char TPDST *)xctPtr + cctx);

		GOT_FILTER:

			/* Test the value of the filter expression */

			if      (filter <  0)
			{
				/* Filter expression is negative */

				if      (excPtr->ExceptionFlags & EXCEPTION_NONCONTINUABLE)
					errPtr->ERRcCCtx = outer;

				return  CONTINUE_EXECUTION;
			}

			if      (filter == 0)
			{
				/* Filter expression is zero - keep looking */

				break;
			}

			/* Exception info no longer available */

			errPtr->ERRcInfo.ERRcExcInfo = 0;

			/* Skip the filter expr/val field */

			cctx  += sizeof(codePtr);

			/* Set the 'target' and 'new' context values */

			tgtctx =
			newctx = outer;
		
#ifdef DIABLO
			if      (__debuggerWatching)
			{
				__lockDebuggerData();
				__debuggerHookDataP->kind = DebuggerData::EventRawExceptionFinish;
				__debuggerHookDataP->addr = (unsigned long) 0;
				__debuggerHookDataP->cookie = (unsigned long) _errPtr;
				__debuggerHookDataP->exception_num = (unsigned long) excPtr->ExceptionCode;
				__debuggerHookFunction();
				__unlockDebuggerData();
			}
#endif
		
			/* Get the handler address */

			hanAdr = *(codePtr TPDST *)((char TPDST *)xctPtr + cctx);

			/* Go unwind and jump to the handler */

			goto JUMP_HAND;

		case    XB_FINALLY:             /* try/finally        ("C") */
#endif
		case    XB_CATCH:               /* catch              (C++) */
		case    XB_DEST:                /* destructor cleanup (C++) */

			/* Ignore 'finally/catch/destr' blocks when searching */

			break;

		default:
			assert(!"bogus context in _ExceptionHandler()");
			break;
		}
	}

DPRINTF(("Not interested in catching right now, continuing search ....\n"));

	/* No interesting exception handlers found, forget it */
	return  CONTINUE_SEARCH;
}


///////////////////////////////////////////////////////////////////////////////
//
//      Given an object address and its type descpriptor address, destroy
//      that object by invoking its destructor. Of course, should that
//      destructor bomb with an exception, we call terminate() and give
//      up.
//

static  void    destroyOneObject(void   __far * varAddr,
				 tpidPtr        varType,
#ifdef  NEWXX
				 unsigned       flags,
#endif
				 int            vbFlag,
				 PREGREC_BC     errPtr)
{
	assert(varType->tpClass.tpcFlags & CF_HAS_DTOR);
	assert(varType->tpClass.tpcDtorAddr);

	try
	{
#ifndef NEWXX
		DPRINTF(("Global dtcnt before= %lu.\n", (long)_DestructorCount));
#endif

		try
		{
#ifdef  NEWXX
			assert((errPtr->ERRcInitDtc >= varType->tpClass.tpcDtorCount) || flags);
			/*
				If we blew up in the middle of a base class
				ctor of a delphiclass, we really don't want
				to tweek with our local dtor count.  That
				would really screw up the destruction of
				parameters passed by value.
			*/
			if      (!(flags & PARENT_CTOR_NOT_COMPLETED))
				errPtr->ERRcInitDtc -= vbFlag ? varType->tpClass.tpcDtorCount
							      : varType->tpClass.tpcNVdtCount;
#endif
			callDestructor(varAddr,
				       varType,
#ifdef  NEWXX
				       flags,
#endif
				       varType->tpClass.tpcDtorAddr,
				       varType->tpClass.tpcDtorMask,
				       vbFlag);
		}
		catch(...)
		{
			__call_terminate();
		}

#ifndef NEWXX
		DPRINTF(("Global dtcnt after = %lu.\n", (long)_DestructorCount));
#endif
	}
	catch(...)
	{
		__call_terminate();
	}
}

///////////////////////////////////////////////////////////////////////////////

static  void    destroyVariable(void    __far * varAddr,
				tpidPtr         varType,
#ifdef  NEWXX
				unsigned        flags,
#endif
				dtorCntType     dtorCnt,
				int             vbFlag,
				unsigned        newBP,
				PREGREC_BC      errPtr);

static  void    destroyArray   (void    __far * varAddr,
				tpidPtr         varType,
				dtorCntType     dtrCount,
				unsigned        newBP,
				PREGREC_BC      errPtr);

///////////////////////////////////////////////////////////////////////////////
//
//      Destroys a list of base classes, given the address of the object,
//      and the range of base classes to destroy; the 'count' parameter,
//      if non-zero, specifies 'how much' to destroy of the first base
//      being destroyed.
//

static  void    destroyBases(void       __far * varAddr,
#ifdef  NEWXX
			     unsigned           flags,
#endif
			     baseListPtr        nblLast,
			     baseListPtr        nblFirst,
			     unsigned           count,
			     int                isVirt,
			     unsigned           newBP,
			     PREGREC_BC         errPtr)
{
	while   (--nblLast >= nblFirst)
	{
		void    __far * baseAddr;
		tpidPtr         baseType;

		/* Figure out the address of this base class */
		
		baseAddr = (char __far *)varAddr + nblLast->blOffs;

		/* Indirect through the vbase pointer if appropriate */

		if      (isVirt)
		{
			/* Dereference the vbase pointer */

			baseAddr = *(char **)baseAddr;
		}

		/* Does this base class have a destructor? */

		baseType = nblLast->blType;
		if      (!(baseType->tpClass.tpcFlags & CF_HAS_DTOR))
			continue;

		/* Now destroy the base class */

#ifdef  NEWXX
		destroyVariable(baseAddr, baseType, flags, count, 0, newBP, errPtr);
#else
		destroyVariable(baseAddr, baseType, count, 0, newBP, errPtr);
#endif

		/* The rest of the bases are completely constructed */

		count = 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      Destroy a variable, given its address, type, and a destructor count.
//
//      Note that the variable might be only partially constructed, in which
//      case we must carefully destroy only those parts of it that have been
//      successfully constructed.
//

static  void    destroyVariable(void    __far * varAddr,
				tpidPtr         varType,
#ifdef  NEWXX
				unsigned        flags,
#endif
				dtorCntType     dtorCnt,
				int             vbFlag,
				unsigned        newBP,
				PREGREC_BC      errPtr)
{
	baseListPtr     nblFirst, nblLast;
	baseListPtr     vblFirst, vblLast;
	dMemListPtr     dmtFirst, dmtLast;

	dtorCntType     varCount;
	unsigned           count;

DPRINTF(("Destroy variable at 0x%08lX (type = '%s')\n", (long)varAddr, __typeIDname(varType)));

	assert(varType->tpClass.tpcFlags & CF_HAS_DTOR);

	/* Has the variable been partially or completely constructed? */

	varCount = vbFlag ? varType->tpClass.tpcDtorCount
			  : varType->tpClass.tpcNVdtCount;

	if      (dtorCnt == 0 || dtorCnt >= varCount)
	{
#ifdef  PRONTO
		/*
			If this is a partially constructed delphi class object,
			we want to call base class destructors with the special
			flag.
			The dtorCnt can be zero in two cases:
			- the current variable to clean up is not the first variable
			  to clean up. Remember that the dtorCnt is set to zero after
			  the first variable is cleaned up.
			- nothing has been created yet, this is the first variable
			  to come in.
		*/
		if      (dtorCnt == 0 && (flags & PARENT_CTOR_NOT_COMPLETED))
		{
			baseListPtr     bl;
			tpidPtr         baseType;

			if      (varType->tpClass.tpcBaseList)
			{
				bl = (baseListPtr)((tpchPtr)varType + varType->tpClass.tpcBaseList);
				assert(bl);
				baseType = bl->blType;
				if      (baseType->tpClass.tpcFlags & CF_HAS_DTOR)
				{
					assert(bl->blOffs == 0);
					destroyOneObject(varAddr,
							 baseType,
							 flags,
							 0,
							 errPtr);
				}
			}
		}
		else
		{
#endif
#ifdef  NEWXX
			destroyOneObject(varAddr, varType, flags, vbFlag, errPtr);
#else
			destroyOneObject(varAddr, varType, vbFlag, errPtr);
#endif
#ifdef  PRONTO
		}
#endif
		return;
	}

	/* This is the hard case - a partially constructed variable */

	assert(dtorCnt < varCount);

	/*
		The order of destruction is as follows:

			members

			non-virtual bases

			virtual bases

		All of these are destroyed in reverse order of declaration;
		therefore, we visit the base/member lists in their order of
		construction, and we stop when our running count indicates
		that we've reached the construction stage of the object.

		Then, we walk the base/member lists backward, destructing
		the appropriate sub-objects as we go.
	 */

	varCount = dtorCnt;

	/* Walk the list of virtual base classes */

	vblFirst =
	vblLast  = (baseListPtr)((tpchPtr)varType + varType->tpClass.tpcVbasList);

	/* Skip virtual bases if this is desired */

	if      (!vbFlag)
		goto DONE_VB;

DPRINTF(("Virtual base table:\n"));

	for     (;;vblLast++)
	{
		tpidPtr         blType = vblLast->blType;

		if      (!blType)
			break;

DPRINTF(("\tBase   offset = %08X, flags = %04X, type = '%s'\n", vblLast->blOffs, vblLast->blFlags, __typeIDname(blType)));

		assert(IS_STRUC(blType->tpMask));

		if      (!(blType->tpClass.tpcFlags & CF_HAS_DTOR))
			continue;

		count = blType->tpClass.tpcNVdtCount;
		if      (count >= varCount)
		{
			/* Found the last constructed base */

#ifdef  NEWXX
			destroyBases(varAddr, flags, vblLast+1, vblFirst, (unsigned)varCount, 1, newBP, errPtr);
#else
			destroyBases(varAddr, vblLast+1, vblFirst, (unsigned)varCount, 1, newBP, errPtr);
#endif
			return;
		}

		varCount -= count;
	}

DONE_VB:

	/* Walk the list of non-virtual base classes */

	nblFirst =
	nblLast  = (baseListPtr)((tpchPtr)varType + varType->tpClass.tpcBaseList);

DPRINTF(("Non-virtual base table:\n"));

	for     (;;nblLast++)
	{
		tpidPtr         blType = nblLast->blType;

		if      (!blType)
			break;

DPRINTF(("\tBase   offset = %08X, flags = %04X, type = '%s'\n", nblLast->blOffs, nblLast->blFlags, __typeIDname(blType)));

		assert(IS_STRUC(blType->tpMask));

		if      (!(blType->tpClass.tpcFlags & CF_HAS_DTOR))
			continue;

		count = blType->tpClass.tpcNVdtCount;
		if      (count >= varCount)
		{
			/* Found the last constructed base */

#ifdef  NEWXX
			destroyBases(varAddr, flags, nblLast+1, nblFirst, (unsigned)varCount, 0, newBP, errPtr);
			if      (vbFlag)
			destroyBases(varAddr, flags, vblLast  , vblFirst,                     0, 1, newBP, errPtr);
#else
			destroyBases(varAddr, nblLast+1, nblFirst, (unsigned)varCount, 0, newBP, errPtr);
			if      (vbFlag)
			destroyBases(varAddr, vblLast  , vblFirst,                     0, 1, newBP, errPtr);
#endif
			return;
		}

		varCount -= count;
	}

	/* Walk the list of members */

	dmtFirst =
	dmtLast  = (dMemListPtr)((tpchPtr)varType + varType->tpClass.tpcDtMembers);

DPRINTF(("Destruct member table:\n"));

	for     (;;dmtLast++)
	{
		unsigned        elements;

		tpidPtr         memType = dmtLast->dmType;

		assert(memType);

DPRINTF(("\tMember offset = %08X, type = '%s'\n", dmtLast->dmOffs, __typeIDname(memType)));

		/* Is the element an array? */

		elements = 1;

		if      (memType->tpMask & TM_IS_ARRAY)
		{
			elements = memType->tpArr.tpaElemCount;
			memType  = memType->tpArr.tpaElemType;
		}

		assert(memType->tpClass.tpcFlags & CF_HAS_DTOR);

		count = elements * memType->tpClass.tpcDtorCount;
		if      (count < varCount)
		{
			varCount -= count;
			continue;
		}

		/* Found the last constructed member */

		do
		{
			void    __far * memAddr;
			tpidPtr         memType;

			/* Ready to destroy the next member */

			memAddr = (char __far *)varAddr + dmtLast->dmOffs;
			memType = dmtLast->dmType;

			/* Is the element an array? */
	
			elements = 1;
	
			if      (memType->tpMask & TM_IS_ARRAY)
			{
				elements = memType->tpArr.tpaElemCount;
				memType  = memType->tpArr.tpaElemType;
			}
	
			if      (elements > 1)
			{
				destroyArray   (memAddr,
						dmtLast->dmType,
						varCount,
						newBP,
						errPtr);
			}
			else
			{
				destroyVariable(memAddr,
						memType,
#ifdef  NEWXX
						0,
#endif
						varCount,
						1,
						newBP,
						errPtr);
			}

			/* All previous members are completely constructed */

			varCount = 0;
		}
		while   (--dmtLast >= dmtFirst);

#ifdef  NEWXX
		destroyBases(varAddr, flags, nblLast, nblFirst, 0, 0, newBP, errPtr);
		if      (vbFlag)
		destroyBases(varAddr, flags, vblLast, vblFirst, 0, 1, newBP, errPtr);
#else
		destroyBases(varAddr, nblLast, nblFirst, 0, 0, newBP, errPtr);
		if      (vbFlag)
		destroyBases(varAddr, vblLast, vblFirst, 0, 1, newBP, errPtr);
#endif
		return;
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      Destroy an array, given its base address, type, and the destructor
//      count (note that the array might be only partially constructed).
//

static  void    destroyArray   (void    __far * varAddr,
				tpidPtr         varType,
				dtorCntType     dtrCount,
				unsigned        newBP,
				PREGREC_BC      errPtr)
{
	tpidPtr         elemType;
	unsigned        elemCount;

	dtorCntType      vdtCount;
	dtorCntType      etdCount;

	assert(varType->tpMask                              & TM_IS_ARRAY);
	assert(varType->tpArr.tpaElemType->tpClass.tpcFlags & CF_HAS_DTOR);

	/* Get the number of elements and their dtor count */

	elemType  = varType;

	elemCount = elemType->tpArr.tpaElemCount;
	elemType  = elemType->tpArr.tpaElemType;

	 vdtCount = elemType->tpClass.tpcDtorCount; assert(vdtCount);

	/* If 0 is passed as 'dtorCount', destroy the whole thing */

	if      (!dtrCount)
		dtrCount = vdtCount * elemCount;

	/* Figure out how many 'complete' elements to destroy */

	 etdCount = dtrCount / vdtCount; assert(etdCount <= elemCount || elemCount == 0);
	 dtrCount-= etdCount * vdtCount; assert(dtrCount <=  vdtCount);

	/* Compute address of the element 1 past the last 'complete' one */

	varAddr = (char __far *)varAddr + etdCount * elemType->tpSize;

	/* Is there an incomplete element at the end? */

	if      (dtrCount)
	{
#ifdef  NEWXX
		destroyVariable(varAddr, elemType, 0, dtrCount, 1, newBP, errPtr);
#else
		destroyVariable(varAddr, elemType, dtrCount, 1, newBP, errPtr);
#endif
	}

	/* Now destroy all of the 'complete' elements (in reverse order) */

	while   (etdCount--)
	{
		varAddr = (char __far *)varAddr - elemType->tpSize;

#ifdef  NEWXX
		destroyVariable(varAddr, elemType, 0, vdtCount, 1, newBP, errPtr);
#else
		destroyVariable(varAddr, elemType, vdtCount, 1, newBP, errPtr);
#endif
	}
}

///////////////////////////////////////////////////////////////////////////////
//
//      Given the address and type of a variable with a virtual destructor,
//      find its 'true' type and address.
//      If vtableAddress is zero, we assume we have to extract it from
//      the object.
//

static  void    __far * findTrueTypeAndAddr(void        __far * varAddr,
					    tpidPtr       _ss * varTypePtr,
					    void        __far * vtableAddress)
{
	tpidPtr         varType = *varTypePtr;

	void    __far * vftAddr;

	DPRINTF(("\tType   (original) = '%s'\n", __typeIDname(varType)));

	/* Base type of variable must be 'class' */

	assert(IS_CLASS(varType->tpMask));

	/* Does the class have an RTTI-style vtable? */

	if      (((CF_HAS_VTABPTR|CF_HAS_RTTI) & varType->tpClass.tpcFlags) !=
		  (CF_HAS_VTABPTR|CF_HAS_RTTI))
	{
		return  varAddr;
	}

	/* Make sure we have a vtable pointer */

	if      (varType->tpClass.tpcVptrOffs == (unsigned int)-1)
		return  varAddr;

	/* Extract the vtable address from the object, if no vtableAddress came in */

	if      (vtableAddress == 0)
	{
		vftAddr = (char __far *)varAddr + varType->tpClass.tpcVptrOffs;

		vftAddr = *(void __near * __far *)vftAddr;
	}
	else
	{
		vftAddr = vtableAddress;
	}

//      printf("Vtable address for object = 0x%08lX\n", (long)vftAddr);

	/* Find the real type and address of the object */

	varAddr = (char __far *)varAddr - ((unsigned __far *)vftAddr)[-2];
	vftAddr = (char __far *)vftAddr - ((unsigned __far *)vftAddr)[-1];

	DPRINTF(("\tVtable (adjusted) = %p  \n", vftAddr));
	DPRINTF(("\tObjptr (adjusted) = %p  \n", varAddr));

	assert(((unsigned __far *)vftAddr)[-1] == 0);
//      assert(((unsigned __far *)vftAddr)[-2] == 0);

	*varTypePtr = *((tpidPtr TPDST *)((unsigned __far *)vftAddr - 2) - 1);

	DPRINTF(("\tType   (adjusted) = '%s'\n", __typeIDname(*varTypePtr)));
	DPRINTF(("\n"));

	return  varAddr;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Given the address of a dtor cleanup table, the 'minimum dtor count'
//      for a cleanup context, the address of an ERR record, and a 'new BP'
//      value, perform whatever necessary cleanup for that cleanup context.
//

static  int     __near  dtorCleanup(DTT TPDST * dttPtr,
				    dtorCntType dtcMin,
				    PREGREC_BC  errPtr,
				    unsigned    newBP)
{
	dtorCntType     initDtr;
	dtorCntType     dtorCnt;
	DTT     TPDST * dtvtPtr;

	int             freePtr = 0;

	/* Ignore this region if it's empty */

	if      (dttPtr == 0)
		return  0;

	DPRINTF(("Cleanup variable table addr = %Fp   \n", (void __far *)dttPtr));
	DPRINTF(("Cleanup min. dtor count     = %ld   \n", (unsigned long)dtcMin));
	DPRINTF(("Cleanup init dtor count     = %ld   \n", (unsigned long)errPtr->ERRcInitDtc));

	/* Compute relative destructor count */

	initDtr = errPtr->ERRcInitDtc;
#ifndef NEWXX
	dtorCnt = _DestructorCount - initDtr;
#else
	dtorCnt = initDtr;
#endif

	DPRINTF(("Cleanup relative dtor count = %ld\n", (unsigned long)dtorCnt));

	/* Compute relative dtor count for this context */

	dtorCnt -= dtcMin;

	/*
		Special case: if this region is a special 'return' region,
		we need to destroy the return value even if the dtor count
		is 'too low'. We do this by adjusting the dtor count up so
		that the return value definitely gets destroyed.
	 */

#ifdef  NEWXX
	if      (dttPtr->dttFlags & DTCVF_RETCTX)
	{
		assert(dttPtr->dttFlags & (DTCVF_PTRVAL|DTCVF_RETVAL));

		/* Variable must be a pointer to class with a dtor */

		assert(dttPtr->dttType->tpMask & TM_IS_PTR);
		assert(dttPtr->dttType->tpPtr.tppBaseType->tpClass.tpcFlags & CF_HAS_DTOR);

		dtorCnt = dttPtr->dttType->tpPtr.tppBaseType->tpClass.tpcDtorCount;

#ifdef  NEWXX
//              errPtr->ERRcInitDtc += dtorCnt;
#endif
	}
#endif

	/* Another special case: a DTC adjustment region */

	if      (dttPtr->dttFlags & DTCVF_DTCADJ)
	{
		assert(IS_CLASS(dttPtr->dttType->tpMask) && (dttPtr->dttType->tpClass.tpcFlags & CF_HAS_DTOR));

		return  dttPtr->dttType->tpClass.tpcNVdtCount;
	}

	/* Return if cleanup is done */

	if      ((dtorCntTypeSigned)dtorCnt <= 0
#ifdef  NEWXX
		 && !(dttPtr->dttFlags & DTCVF_THISCTX)
#endif
		)
	{
		/*
			Special case: if this region is a 'new' expression,
			we need to deallocate the memory (but nothing else
			since the constructor has not been completed yet).
		 */

		if      ((dttPtr->dttFlags & (DTCVF_PTRVAL|DTCVF_DELPTR)) ==
					     (DTCVF_PTRVAL|DTCVF_DELPTR))
		{
			dtvtPtr = dttPtr;
			freePtr++;
			goto DO_DST;
		}

		DPRINTF(("Cleanup done.\n"));

		return  0;
	}

	/* Find an entry for the next variable to be destructed */

	for     (dtvtPtr = dttPtr; 1; dtvtPtr++)
	{
		tpidPtr          varType;
		tpidPtr         elemType;

		unsigned        count;

		/* Check for end of the table */

		if      (!dtvtPtr->dttType)
		{
			dtvtPtr--;
			break;
		}

		DPRINTF(("Cleanup variable type  = '%s'\n", __typeIDname(dtvtPtr->dttType)));
		DPRINTF(("Cleanup variable flags = %04X\n", dtvtPtr->dttFlags));

#ifdef  DEBUG
		if      (dtvtPtr->dttFlags & DTCVF_STACKVAR)
		{
			DPRINTF(("Cleanup variable is at [EBP"));
			if      ((int)dtvtPtr->dttFrameOffs > 0)
				DPRINTF(("+%04X]\n",  dtvtPtr->dttFrameOffs));
			else
				DPRINTF(("-%04X]\n", -dtvtPtr->dttFrameOffs));
		}
		else
		{
			DPRINTF(("Cleanup variable addr  = %Fp\n", (void _ss *)dtvtPtr->dttAddress));
		}

#endif

		/* Check for special case of delete expression with virtual destructors,
		   in which case we have a 'fake' array of pointers. The elemtype of
		   the array is the type of the pointer we're deleting.  The first
		   entry of the array is the pointer to be deleted.  The second entry
		   is the vtable pointer. */

		if      (dtvtPtr->dttFlags & DTCVF_WITHVT)
		{
			assert(dtvtPtr->dttType->tpMask & TM_IS_ARRAY);
			varType  =
			elemType = dtvtPtr->dttType->tpArr.tpaElemType;
		}
		else
		{
			/* Get the element type and total dtor count */

			varType  =
			elemType = dtvtPtr->dttType;
		}

		count = 1;

		if      (varType->tpMask & TM_IS_PTR)
		{
			 varType =
			elemType = varType->tpPtr.tppBaseType;

			/*
				Are we deleting a pointer to a class
				with a virtual destructor?
			 */

			if      (IS_CLASS(varType->tpMask) &&
				 (varType->tpClass.tpcFlags & CF_HAS_VIRTDT) &&
				 (dtvtPtr->dttFlags & DTCVF_DELETE))
			{
				void    __far * varAddr;
				void    __far * ptrAddr;
				void    __far * vtableAddress = 0;

				assert(varType->tpClass.tpcFlags & CF_HAS_DTOR);

				/* Compute the address of the pointer variable */

				if      (dtvtPtr->dttFlags & DTCVF_STACKVAR)
					varAddr = (char _ss *)newBP + dtvtPtr->dttFrameOffs;
				else
					varAddr = dtvtPtr->dttAddress;

				/* Dereference the pointer variable */

				ptrAddr = varAddr;

				varAddr = *(void **)ptrAddr;

				/* Extract the vtable pointer if supplied */

				if      (dtvtPtr->dttFlags & DTCVF_WITHVT)
				{
					vtableAddress = *((void **)ptrAddr + 1);
				}

				/* Adjust the pointer value, if needed */

				if      (dtvtPtr->dttFlags & DTCVF_VECCNT)
					*(unsigned*)&varAddr += 4;

//                              printf("Polyptr variable at 0x%08lX\n", (long)ptrAddr);
//                              printf("Polyptr points   to 0x%08lX\n", (long)varAddr);

				/* Now find the actual type of the object */

				varAddr  = findTrueTypeAndAddr(varAddr, &varType, vtableAddress);
				elemType = varType;
			}
		}

		if      (varType->tpMask & TM_IS_ARRAY)
		{
			count    = elemType->tpArr.tpaElemCount;
			elemType = elemType->tpArr.tpaElemType;
		}

		assert(elemType->tpClass.tpcFlags & CF_HAS_DTOR);

		count *= elemType->tpClass.tpcDtorCount;

		/* Have we found the next variable to be cleaned up? */

		if      (count >= dtorCnt)
			break;

		/* Not there yet, continue looking */

		dtorCnt -= count;
	}

DO_DST:

	DPRINTF(("Global  dtor count = %lu\n", (long)_DestructorCount));
	DPRINTF(("Initial dtor count = %lu\n", (long)initDtr));
	DPRINTF(("Minimal dtor count = %lu\n", (long)dtcMin));

	do
	{
		tpidPtr         varType  = dtvtPtr->dttType;
		unsigned        varFlags = dtvtPtr->dttFlags;

		void    __far * varAddr;
		void    __far * ptrAddr;
		void    __far * blkAddr;

		/* Compute the address of the variable */

		if      (varFlags & DTCVF_STACKVAR)
		{
			varAddr = (char _ss *)newBP + dtvtPtr->dttFrameOffs;

			DPRINTF(("Variable address   = 0x%08lX [EBP-%04X]\n", (long)varAddr, -dtvtPtr->dttFrameOffs));
		}
		else
		{
			varAddr = dtvtPtr->dttAddress;

			DPRINTF(("Variable address   = 0x%08lX\n", (long)varAddr));
		}

		/* See comment about DTCVF_WITHVT above */

		if      (varFlags & DTCVF_WITHVT)
		{
			assert(varType->tpMask & TM_IS_ARRAY);
			varType = varType->tpArr.tpaElemType;
		}

		/* If this is 'new' or 'return', dereference the pointer */

		if      (varFlags & (DTCVF_PTRVAL|DTCVF_RETVAL))
		{
			void    __far* vtableAddress = 0;

			assert(varType->tpMask & TM_IS_PTR);

			varType = varType->tpPtr.tppBaseType;

			ptrAddr = varAddr;

			varAddr = *(void **)ptrAddr;

			/* Extract the vtable pointer if supplied */

			if      (varFlags & DTCVF_WITHVT)
			{
				vtableAddress = *((void **)ptrAddr + 1);
			}

			/* Adjust the pointer value, if needed */

			blkAddr = varAddr;

			if      ((varFlags & (DTCVF_DELETE|DTCVF_VECCNT)) == DTCVF_VECCNT)
				*(unsigned*)&varAddr += 4;

			/*
				Are we deleting a pointer to a class
				with a virtual destructor?
			 */

			if      (IS_CLASS(varType->tpMask) &&
				 (varType->tpClass.tpcFlags & CF_HAS_VIRTDT) &&
				 (varFlags & DTCVF_DELETE))
			{
				varAddr = findTrueTypeAndAddr(varAddr, &varType, vtableAddress);
				blkAddr = varAddr;
			}
		}

		if      (!freePtr)
		{
#ifdef  NEWXX
			unsigned        flags;

			if      (varFlags & DTCVF_THISCTX)
			{
				baseListPtr             bl;
				tpidPtr                 baseType;
				dtorCntTypeSigned       parentCount;

				/* We get here for delphi class objects.
				   We want to find out if the parent class completed
				   its construction */

				if      (varType->tpClass.tpcBaseList)
				{
					bl = (baseListPtr)((tpchPtr)varType + varType->tpClass.tpcBaseList);
					assert(bl);
					baseType = bl->blType;
					parentCount = baseType->tpClass.tpcDtorCount;
				}
				else
				{
					parentCount = 0;
				}
				if      (dtorCnt >= parentCount)
					flags = PARENT_CTOR_COMPLETED;
				else
					flags = PARENT_CTOR_NOT_COMPLETED;
			}
			else
				flags = 0;
#endif
			/* Is this an array? */

			if      (varType->tpMask & TM_IS_ARRAY)
				destroyArray   (varAddr, varType, dtorCnt,    newBP, errPtr);
			else
#ifdef  NEWXX
				destroyVariable(varAddr, varType, flags, dtorCnt, 1, newBP, errPtr);
#else
				destroyVariable(varAddr, varType, dtorCnt, 1, newBP, errPtr);
#endif

#ifdef  NEWXX
			/*
				If this is the 'this' pointer, we need to
				delete the memory for the object if the
				compiler said to.  This will only happen
				for delphiclass constructors.  Note that
				-1 is used by the Pascal compiler to signify
				something special.  See Peter Sollich for
				details.
			*/
			if      (varFlags & DTCVF_THISCTX                       &&
					 errPtr->ERRflags & EF_DELETETHIS       &&
					 errPtr->ERRflags != 0xff)
			{
				typedef void (__fastcall *FreeInstanceProc)(void *);
				void **                 pVTable;
				FreeInstanceProc        p;

				pVTable = *(void ***)varAddr;
				p = (FreeInstanceProc)*(pVTable - 2);
				(p)(varAddr);
			}
#endif
		}

		/* Is this 'new' where the pointer must be deleted? */

		if      ((varFlags & (DTCVF_PTRVAL|DTCVF_DELPTR)) ==
				     (DTCVF_PTRVAL|DTCVF_DELPTR))
		{
			/* Adjust the pointer value, if needed */

			if      ((varFlags & (DTCVF_DELETE|DTCVF_VECCNT)) ==
					     (DTCVF_DELETE|DTCVF_VECCNT))
			{
				*(unsigned*)&blkAddr -= 4;
			}

			/* Are we deleting an array? */

			if      (varType->tpMask & TM_IS_ARRAY)
			{
				/* It's an array: get the element type */

				varType = varType->tpArr.tpaElemType;

				/* Is there a class::operator delete[] ? */

				if      (varType->tpClass.tpcDaOpAddr)
				{
					callMemberFunc(blkAddr,
						       varType->tpClass.tpcDaOpAddr,
						       varType->tpClass.tpcDaOpMask);
				}
				else
				{
					delete[](char *)blkAddr;
				}
			}
			else
			{
				/* Not an array: is there a class::delete? */

				if      (varType->tpClass.tpcDlOpAddr)
				{
					callMemberFunc(blkAddr,
						       varType->tpClass.tpcDlOpAddr,
						       varType->tpClass.tpcDlOpMask);
				}
				else
				{
					delete  blkAddr;
				}
			}
		}

		DPRINTF(("Global  dtor count = %lu\n", (long)_DestructorCount));
		DPRINTF(("Initial dtor count = %lu\n", (long)initDtr));
		DPRINTF(("Minimal dtor count = %lu\n", (long)dtcMin));

		/* The preceding variables are definitely fully constructed */

		dtorCnt = 0;
	}
	while   (dtvtPtr-- > dttPtr);

	return  0;
}

///////////////////////////////////////////////////////////////////////////////
//
//      Given the address of an exception registation record, return
//      the current context number (or -1 if the exception handler
//      isn't ours).
//

extern  "C"
int     DEFCC   _CurrExcContext(void _ss* _errPtr)
{
	PREGREC_BC      errPtr = (PREGREC_BC)_errPtr;
	char    __far * hanPtr;

	if      (errPtr == (PREGREC_BC)END_OF_CHAIN)
		return  -1;

	/* Check if we are pointing at a jump table (imported entry for example) */
	if      (*(unsigned short *)errPtr->ERRcCatcher == 0x25FF)
	{
		hanPtr = (char *)(void *)errPtr->ERRcCatcher;
		hanPtr += 2;  /* Skip jump instruction */
		hanPtr = (char *)(void *)(**(unsigned **)hanPtr) - sizeof(XX_SIGNATURE) + 1;
	}
	else
		hanPtr = (char __far *)(void __far *)errPtr->ERRcCatcher - sizeof(XX_SIGNATURE) + 1;

	if      (memcmp(hanPtr, XX_SIGNATURE, sizeof(XX_SIGNATURE) - 1))
		return  -1;

	return  errPtr->ERRcCCtx;
}

