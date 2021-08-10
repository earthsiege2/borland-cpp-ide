// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Exptintf.pas' rev: 5.00

#ifndef ExptintfHPP
#define ExptintfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ToolIntf.hpp>	// Pascal unit
#include <VirtIntf.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Exptintf
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TExpertStyle { esStandard, esForm, esProject, esAddIn };
#pragma option pop

#pragma option push -b-
enum Exptintf__1 { esEnabled, esChecked };
#pragma option pop

typedef Set<Exptintf__1, esEnabled, esChecked>  TExpertState;

class DELPHICLASS TIExpert;
class PASCALIMPLEMENTATION TIExpert : public Virtintf::TInterface 
{
	typedef Virtintf::TInterface inherited;
	
public:
	virtual AnsiString __stdcall GetName(void) = 0 ;
	virtual AnsiString __stdcall GetAuthor(void) = 0 ;
	virtual AnsiString __stdcall GetComment(void) = 0 ;
	virtual AnsiString __stdcall GetPage(void) = 0 ;
	virtual HICON __stdcall GetGlyph(void) = 0 ;
	virtual TExpertStyle __stdcall GetStyle(void) = 0 ;
	virtual TExpertState __stdcall GetState(void) = 0 ;
	virtual AnsiString __stdcall GetIDString(void) = 0 ;
	virtual AnsiString __stdcall GetMenuText(void) = 0 ;
	virtual void __stdcall Execute(void) = 0 ;
public:
	#pragma option push -w-inl
	/* TInterface.Create */ inline __fastcall TIExpert(void) : Virtintf::TInterface() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIExpert(void) { }
	#pragma option pop
	
};


typedef bool __fastcall (*TExpertRegisterProc)(TIExpert* Expert);

typedef void __fastcall (*TExpertTerminateProc)(void);

typedef bool __stdcall (*TExpertInitProc)(Toolintf::TIToolServices* ToolServices, TExpertRegisterProc 
	RegisterProc, TExpertTerminateProc &Terminate);

//-- var, const, procedure ---------------------------------------------------
#define isExperts "Experts"
#define ExpertEntryPoint "INITEXPERT0017"
static const Shortint ValidExpertVersion = 0x3;
extern PACKAGE TExpertRegisterProc LibraryExpertProc;
extern PACKAGE Toolintf::TIToolServices* ToolServices;
extern PACKAGE void __fastcall RegisterLibraryExpert(TIExpert* Expert);

}	/* namespace Exptintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Exptintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Exptintf
