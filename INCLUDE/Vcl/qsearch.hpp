// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QSearch.pas' rev: 6.00

#ifndef QSearchHPP
#define QSearchHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QDialogs.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qsearch
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TSearchRec
{
	Qdialogs::TFindOptions Options;
	int BMTable[256];
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Set<char, 0, 255>  WordDelimiters;
extern PACKAGE TSearchRec __fastcall PrepareSearch(const WideString SearchString, Qdialogs::TFindOptions Options);
extern PACKAGE int __fastcall Search(const WideString Text, int SelStart, int SelLength, const WideString SearchString, const TSearchRec &SearchRec)/* overload */;
extern PACKAGE int __fastcall Search(const WideString Text, int SelStart, int SelLength, const WideString SearchString, Qdialogs::TFindOptions Options)/* overload */;
extern PACKAGE bool __fastcall Search(Qstdctrls::TCustomEdit* EditControl, const WideString SearchString, const TSearchRec &SearchRec)/* overload */;
extern PACKAGE bool __fastcall Search(Qstdctrls::TCustomEdit* EditControl, const WideString SearchString, Qdialogs::TFindOptions Options)/* overload */;
extern PACKAGE bool __fastcall Search(Qstdctrls::TCustomMemo* MemoControl, const WideString SearchString, const TSearchRec &SearchRec)/* overload */;
extern PACKAGE bool __fastcall Search(Qstdctrls::TCustomMemo* MemoControl, const WideString SearchString, Qdialogs::TFindOptions Options)/* overload */;

}	/* namespace Qsearch */
using namespace Qsearch;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QSearch
