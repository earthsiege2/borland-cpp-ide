/*-----------------------------------------------------------------------*
 * filename - dllx.c
 *
 * function(s)
 *
 *      __CRTL_DLLEntryPointWrapper - exception wrapper for DllEntrypoint
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

#include <_defs.h>
#include <_io.h>
#include <windows.h>

#define _CONTINUE_SEARCH        1
#define _CONTINUE_EXECUTION     0
#define _EXECUTE_HANDLER       -1

static HANDLE hdll;

typedef ULONG (APIENTRY * LIBMAINPTR)(HANDLE, ULONG, LPVOID);

typedef	struct _EXCEPT_REPORT_RECORD_	*PEXCEPT_REPORT_RECORD;
typedef	struct _EXCEPT_REPORT_RECORD_
{
	unsigned long	ExceptionNum;
	unsigned long	ExceptionFlags;
	void	*	NestedExceptionReportRecord;
	void	*	ExceptionAddress;
	unsigned long	ExceptionParamCount;
	unsigned long	ExceptionInfo[];
} EXCEPT_REPORT_RECORD;
typedef	int	(__stdcall*catchPtrTP)(PEXCEPT_REPORT_RECORD, void *, void *        );
typedef	struct	_REGISTRATION_RECORD_	*	PREGISTRATION_RECORD;
typedef	struct	_REGISTRATION_RECORD_
{
	void	*	ERRnext;	// next registration record in chain
	catchPtrTP	ERRcatcher;	// address of handler
} REGISTRATION_RECORD;

static int expecting = 0;

static int __stdcall GenericExceptHandler(PEXCEPT_REPORT_RECORD repPtr,
			   void        *               errPtr,
			   void        *               ctxPtr)
{
    unsigned        code = repPtr->ExceptionNum;
    char buf[256*2];
    char dllname[256] = "";

    if (expecting)
    {
        expecting = 0;
        GetModuleFileName(hdll, dllname, sizeof(dllname));
        wsprintf(buf, "An exception (%08X) occurred during DllEntryPoint or DllMain in module:\n"
                      "%s", code, dllname);

        _ErrorMessage(buf);
    }

    return  _CONTINUE_SEARCH;
}

static void unchainExceptionHandler(REGISTRATION_RECORD *ERR)
{
  /* mov eax, ERR.ERRprev, eax */
  /* mov fs:[0], eax */
  _EAX = (long)ERR->ERRnext;
  __emit__(0x64); __emit__(0x67); __emit__(0xA3); __emit__(0); __emit__(0);
}

#define MAIN_X_PREP		REGISTRATION_RECORD __ERR
#define MAIN_X_BEGIN   {                                    \
                        /* push eax */                      \
                        /* push ecx */                      \
                        __emit__(0x50); __emit__(0x51);     \
                                                            \
                        __ERR.ERRcatcher = (catchPtrTP)GenericExceptHandler; \
                        _ECX = (unsigned long)&__ERR;       \
                        /* mov eax, fs:[0] */               \
                        /* mov [ecx], eax  */               \
                        /* mov fs:[0], ecx */               \
                        /* pop ecx */                       \
                        /* pop eax */                       \
                        __emit__(0x64); __emit__(0x67); __emit__(0xA1); __emit__(0); __emit__(0); \
                        __emit__(0x89); __emit__(0x01); \
                        __emit__(0x64); __emit__(0x89); __emit__(0x0D); __emit__(0); __emit__(0); __emit__(0); __emit__(0); \
                        __emit__(0x59); __emit__(0x58); \
                       }

#define MAIN_X_END	unchainExceptionHandler(&__ERR);


ULONG APIENTRY __CRTL_DLLEntryPointWrapper(LIBMAINPTR pfn, HANDLE mod_handle,
                                           ULONG reason, LPVOID reserved)
{
    ULONG ret = 0;
    MAIN_X_PREP;

    hdll = mod_handle;

    MAIN_X_BEGIN;

    expecting = 1;
    ret = pfn(mod_handle, reason, reserved);
    expecting = 1;

    MAIN_X_END;

    return ret;
}
