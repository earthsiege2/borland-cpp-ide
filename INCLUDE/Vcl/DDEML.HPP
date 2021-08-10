// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ddeml.pas' rev: 5.00

#ifndef DdemlHPP
#define DdemlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <ddeml.h>

namespace Ddeml
{
//-- type declarations -------------------------------------------------------
typedef int HConvList;

typedef int HConv;

typedef int HSz;

typedef int HDDEData;

typedef tagHSZPAIR *PHSZPair;

typedef tagHSZPAIR  THSZPair;

typedef tagCONVCONTEXT *PConvContext;

typedef tagCONVCONTEXT  TConvContext;

typedef tagCONVINFO *PConvInfo;

typedef tagCONVINFO  TConvInfo;

typedef int __stdcall (*TFNCallback)(unsigned CallType, unsigned Fmt, int Conv, int hsz1, int hsz2, 
	int Data, unsigned Data1, unsigned Data2);

typedef tagDDEML_MSG_HOOK_DATA  TDdemlMsgHookData;

typedef tagMONMSGSTRUCT  TMonMsgStruct;

typedef tagMONCBSTRUCT  TMonCBStruct;

typedef tagMONHSZSTRUCTA  TMonHSZStructA;

typedef tagMONHSZSTRUCTW  TMonHSZStructW;

typedef tagMONHSZSTRUCTA  TMonHSZStruct;

typedef tagMONERRSTRUCT *PMonErrStruct;

typedef tagMONERRSTRUCT  TMonErrStruct;

typedef tagMONLINKSTRUCT *PMonLinkStruct;

typedef tagMONLINKSTRUCT  TMonLinkStruct;

typedef tagMONCONVSTRUCT *PMonConvStruct;

typedef tagMONCONVSTRUCT  TMonConvStruct;

//-- var, const, procedure ---------------------------------------------------
#define ddelib "user32.dll"

}	/* namespace Ddeml */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ddeml;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Ddeml
