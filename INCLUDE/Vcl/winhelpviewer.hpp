// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WinHelpViewer.pas' rev: 6.00

#ifndef WinHelpViewerHPP
#define WinHelpViewerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Winhelpviewer
{
//-- type declarations -------------------------------------------------------
__interface IWinHelpTester;
typedef System::DelphiInterface<IWinHelpTester> _di_IWinHelpTester;
__interface INTERFACE_UUID("{B0FC9354-5F0E-11D3-A3B9-00C04F79AD3A}") IWinHelpTester  : public IInterface 
{
	
public:
	virtual bool __fastcall CanShowALink(const AnsiString ALink, const AnsiString FileName) = 0 ;
	virtual bool __fastcall CanShowTopic(const AnsiString Topic, const AnsiString FileName) = 0 ;
	virtual bool __fastcall CanShowContext(const int Context, const AnsiString FileName) = 0 ;
	virtual Classes::TStringList* __fastcall GetHelpStrings(const AnsiString ALink) = 0 ;
	virtual AnsiString __fastcall GetHelpPath(void) = 0 ;
	virtual AnsiString __fastcall GetDefaultHelpFile(void) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IWinHelpTester WinHelpTester;
extern PACKAGE AnsiString ViewerName;

}	/* namespace Winhelpviewer */
using namespace Winhelpviewer;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WinHelpViewer
