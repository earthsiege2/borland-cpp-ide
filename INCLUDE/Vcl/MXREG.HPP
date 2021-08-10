// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXReg.pas' rev: 5.00

#ifndef MXRegHPP
#define MXRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Chart.hpp>	// Pascal unit
#include <ChartReg.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDSSChartCompEditor;
class PASCALIMPLEMENTATION TDSSChartCompEditor : public Chartreg::TChartCompEditor 
{
	typedef Chartreg::TChartCompEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TDSSChartCompEditor(Classes::TComponent* AComponent
		, Dsgnintf::_di_IFormDesigner ADesigner) : Chartreg::TChartCompEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDSSChartCompEditor(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Mxreg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxreg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXReg
