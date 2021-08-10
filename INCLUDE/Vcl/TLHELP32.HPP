// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TLHelp32.pas' rev: 5.00

#ifndef TLHelp32HPP
#define TLHelp32HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <tlhelp32.h>

namespace Tlhelp32
{
//-- type declarations -------------------------------------------------------
typedef unsigned __stdcall (*TCreateToolhelp32Snapshot)(unsigned dwFlags, unsigned th32ProcessID);

typedef tagHEAPLIST32  THeapList32;

typedef BOOL __stdcall (*THeap32ListFirst)(unsigned hSnapshot, tagHEAPLIST32 &lphl);

typedef BOOL __stdcall (*THeap32ListNext)(unsigned hSnapshot, tagHEAPLIST32 &lphl);

typedef tagHEAPENTRY32  THeapEntry32;

typedef BOOL __stdcall (*THeap32First)(tagHEAPENTRY32 &lphe, unsigned th32ProcessID, unsigned th32HeapID
	);

typedef BOOL __stdcall (*THeap32Next)(tagHEAPENTRY32 &lphe);

typedef BOOL __stdcall (*TToolhelp32ReadProcessMemory)(unsigned th32ProcessID, void * lpBaseAddress, 
	void *lpBuffer, unsigned cbRead, unsigned &lpNumberOfBytesRead);

typedef tagPROCESSENTRY32W  TProcessEntry32W;

typedef BOOL __stdcall (*TProcess32FirstW)(unsigned hSnapshot, tagPROCESSENTRY32W &lppe);

typedef BOOL __stdcall (*TProcess32NextW)(unsigned hSnapshot, tagPROCESSENTRY32W &lppe);

typedef tagPROCESSENTRY32  TProcessEntry32;

typedef BOOL __stdcall (*TProcess32First)(unsigned hSnapshot, tagPROCESSENTRY32 &lppe);

typedef BOOL __stdcall (*TProcess32Next)(unsigned hSnapshot, tagPROCESSENTRY32 &lppe);

typedef tagTHREADENTRY32  TThreadEntry32;

typedef BOOL __stdcall (*TThread32First)(unsigned hSnapshot, tagTHREADENTRY32 &lpte);

typedef BOOL __stdcall (*TThread32Next)(unsigned hSnapshot, tagTHREADENTRY32 &lpte);

typedef tagMODULEENTRY32  TModuleEntry32;

typedef BOOL __stdcall (*TModule32First)(unsigned hSnapshot, tagMODULEENTRY32 &lpme);

typedef BOOL __stdcall (*TModule32Next)(unsigned hSnapshot, tagMODULEENTRY32 &lpme);

typedef tagMODULEENTRY32W  MODULEENTRY32W;

typedef tagMODULEENTRY32W *PMODULEENTRY32W;

typedef tagMODULEENTRY32W *LPMODULEENTRY32W;

typedef tagMODULEENTRY32W  TModuleEntry32W;

typedef BOOL __stdcall (*TModule32FirstW)(unsigned hSnapshot, tagMODULEENTRY32W &lpme);

typedef BOOL __stdcall (*TModule32NextW)(unsigned hSnapshot, tagMODULEENTRY32W &lpme);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Tlhelp32 */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Tlhelp32;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TLHelp32
