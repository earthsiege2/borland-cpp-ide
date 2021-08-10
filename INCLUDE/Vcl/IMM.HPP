// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Imm.pas' rev: 6.00

#ifndef ImmHPP
#define ImmHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Imm
{
//-- type declarations -------------------------------------------------------
typedef tagCOMPOSITIONFORM *PCompositionForm;

typedef tagCOMPOSITIONFORM  TCompositionForm;

typedef tagCANDIDATEFORM *PCandidateForm;

typedef tagCANDIDATEFORM  TCandidateForm;

typedef tagCANDIDATELIST *PCandidateList;

typedef tagCANDIDATELIST  TCandidateList;

typedef tagREGISTERWORDA *PRegisterWordA;

typedef tagREGISTERWORDW *PRegisterWordW;

typedef tagREGISTERWORDA *PRegisterWord;

typedef tagREGISTERWORDA  TRegisterWordA;

typedef tagREGISTERWORDW  TRegisterWordW;

typedef tagREGISTERWORDA  TRegisterWord;

typedef tagSTYLEBUFA *PStyleBufA;

typedef tagSTYLEBUFW *PStyleBufW;

typedef tagSTYLEBUFA *PStyleBuf;

typedef tagSTYLEBUFA  TStyleBufA;

typedef tagSTYLEBUFW  TStyleBufW;

typedef tagSTYLEBUFA  TStyleBuf;

typedef int __fastcall (*RegisterWordEnumProc)(char * lpReading, unsigned dwStyle, char * lpszString, void * lpData);

//-- var, const, procedure ---------------------------------------------------
static const Shortint CFS_SCREEN = 0x4;
#define imm32 "imm32.dll"

}	/* namespace Imm */
using namespace Imm;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Imm
