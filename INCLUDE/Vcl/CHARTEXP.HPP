// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ChartExp.pas' rev: 6.00

#ifndef ChartExpHPP
#define ChartExpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeConst.hpp>	// Pascal unit
#include <ExpForm.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <VirtIntf.hpp>	// Pascal unit
#include <ToolIntf.hpp>	// Pascal unit
#include <ExptIntf.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Chartexp
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TTeeChartWizard;
class PASCALIMPLEMENTATION TTeeChartWizard : public Exptintf::TIExpert 
{
	typedef Exptintf::TIExpert inherited;
	
public:
	virtual AnsiString __stdcall GetName();
	virtual AnsiString __stdcall GetAuthor();
	virtual AnsiString __stdcall GetComment();
	virtual HICON __stdcall GetGlyph(void);
	virtual Exptintf::TExpertStyle __stdcall GetStyle(void);
	virtual Exptintf::TExpertState __stdcall GetState(void);
	virtual AnsiString __stdcall GetIDString();
	virtual AnsiString __stdcall GetPage();
	virtual void __stdcall Execute(void);
	virtual AnsiString __stdcall GetMenuText();
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TTeeChartWizard(void) : Exptintf::TIExpert() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeChartWizard(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Chartexp */
using namespace Chartexp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ChartExp
