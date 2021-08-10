/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

///////////////////////////////////////////////////////////////////////////////

#pragma option -xv
#pragma option -V?-

///////////////////////////////////////////////////////////////////////////////

#pragma inline

///////////////////////////////////////////////////////////////////////////////

#define NDEBUG

///////////////////////////////////////////////////////////////////////////////

#include <_defs.h>

#ifndef __NON_STD_ASSERT__
#include <assert.h>
#endif

///////////////////////////////////////////////////////////////////////////////

#define USE_XX_VARS
#include "xx.h"

///////////////////////////////////////////////////////////////////////////////

#pragma option  -r
#pragma option  -k-

///////////////////////////////////////////////////////////////////////////////

extern  "C"
void    __fastcall __InitExceptBlockLDTC(void __far * xtable)
{
	// Compute the address of the ERR into EBX

	asm     mov     ebx, ebp
	asm     add     ebx, [eax].xtBPoffs

	// Store the address of the exception table in the ERR

	asm     mov     [ebx].ERRcXtab, eax

	// Now compute the caller's stack pointer value by adding the size
	// of the return address to the current stack pointer value.

	asm     lea     eax, [esp+8]

	// Save the caller's SP value in the ERR

	asm     mov     [ebx].ERRcSPsv, eax

	// Point at our exception handler

	asm     mov     dword ptr [ebx].ERRcCatcher, large offset _ExceptionHandler

	// Set the current context to 0

	asm     mov     word ptr [ebx].ERRcCCtx, 0

	// Set the 'unwinding' flag to 0

	asm     mov     word ptr [ebx].ERRcInfo.ERRcUnwind, 0

	// Copy the current DestructorCount value

	asm     mov     dword ptr [ebx].ERRcInitDtc, 0

	// Finally, hook the ERR into the chain

	asm     mov     eax, fs:[0]
	asm     mov     [ebx].ERRcNext, eax
	asm     mov     fs:[0], ebx
}

extern  "C"
void    __fastcall __ExitExceptBlock(void __far * xtable)
{
	asm	mov	fs:[0], eax
}


//#define EXTRN_BUG
#ifdef EXTRN_BUG

// attempted to extrn ___ExceptionHandler is leading to the wrong code
// gen below.  The function below accomplishes the same thing.
static bool  extrn___ExceptionHandler()
{
    typedef void (*fp_t)();
    static fp_t fp = (fp_t) ___ExceptionHandler;
    return fp;
}
#endif // EXTRN_BUG

// this signature must precede the exception handler, and it must not be
// smart-linked out.
#pragma codestring  "**BCCxh1"  // precedes our exception handler
#pragma warn -rvl
extern  "C"
__declspec(naked) int EXHCC _ExceptionHandler(void *_excPtr, void *_errPtr,
                                              void *_ctxPtr, void *_dspPtr)
{
	asm
	{
		// before doing anything, we want to grab our return address.
		// this is passed below as "OSEsp"
		mov	eax, esp
		push	__xxPersonality                // flags
		push    ebx                            // OSEbx
		push    edi                            // OSEdi
		push    esi                            // OSEsi
		push    ebp                            // OSEbp
		push    eax                            // OSEsp
		push    _dspPtr                        // _dspPtr
		push    _ctxPtr                        // ctxPtr
		push    _errPtr                        // errPtr
		push    _excPtr                        // excPtr
#ifndef EXTRN_BUG
#undef  near
		extrn	____ExceptionHandler:near
#endif
		call    ____ExceptionHandler
		add     esp, 20
		pop     ebp
		pop     esi
		pop     edi
		pop     ebx
		add	esp, 4
		ret
	}
}

///////////////////////////////////////////////////////////////////////////////
