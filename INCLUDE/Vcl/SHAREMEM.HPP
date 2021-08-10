// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ShareMem.pas' rev: 6.00

#ifndef ShareMemHPP
#define ShareMemHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sharemem
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void * __fastcall SysGetMem(int Size);
extern PACKAGE int __fastcall SysFreeMem(void * P);
extern PACKAGE void * __fastcall SysReallocMem(void * P, int Size);
extern "C" System::THeapStatus __fastcall GetHeapStatus(void);
extern "C" int __fastcall GetAllocMemCount(void);
extern "C" int __fastcall GetAllocMemSize(void);
extern "C" void __fastcall DumpBlocks(void);
#pragma option push -w-inl
inline void * __fastcall SysGetMem(int Size)
{
	return SysGetMem(Size);
}
#pragma option pop


#pragma option push -w-inl
inline int __fastcall SysFreeMem(void * P)
{
	return SysFreeMem(P);
}
#pragma option pop


#pragma option push -w-inl
inline void * __fastcall SysReallocMem(void * P, int Size)
{
	return SysReallocMem(P, Size);
}
#pragma option pop



}	/* namespace Sharemem */
using namespace Sharemem;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ShareMem
