// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ChartReg.pas' rev: 5.00

#ifndef ChartRegHPP
#define ChartRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Chartreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartClassProperty;
class PASCALIMPLEMENTATION TChartClassProperty : public Dsgnintf::TClassProperty 
{
	typedef Dsgnintf::TClassProperty inherited;
	
protected:
	void __fastcall InternalEditPage(Chart::TCustomChart* AChart, int APage);
	void __fastcall InternalEditSeries(Teengine::TChartSeries* ASeries);
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartClassProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartClassProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartCompEditor;
class PASCALIMPLEMENTATION TChartCompEditor : public Dsgnintf::TComponentEditor 
{
	typedef Dsgnintf::TComponentEditor inherited;
	
protected:
	void __fastcall ChartExecuteVerb(int Index, Chart::TCustomChart* AChart);
	
public:
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual AnsiString __fastcall GetVerb(int Index);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TChartCompEditor(Classes::TComponent* AComponent
		, Dsgnintf::_di_IFormDesigner ADesigner) : Dsgnintf::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TChartCompEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDBChartCompEditor;
class PASCALIMPLEMENTATION TDBChartCompEditor : public TChartCompEditor 
{
	typedef TChartCompEditor inherited;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TDBChartCompEditor(Classes::TComponent* AComponent
		, Dsgnintf::_di_IFormDesigner ADesigner) : TChartCompEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDBChartCompEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartPenProperty;
class PASCALIMPLEMENTATION TChartPenProperty : public TChartClassProperty 
{
	typedef TChartClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartPenProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : TChartClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartPenProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartBrushProperty;
class PASCALIMPLEMENTATION TChartBrushProperty : public TChartClassProperty 
{
	typedef TChartClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartBrushProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : TChartClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartBrushProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartAxesCategory;
class PASCALIMPLEMENTATION TChartAxesCategory : public Dsgnintf::TPropertyCategory 
{
	typedef Dsgnintf::TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TChartAxesCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TChartAxesCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TChartAxesCategory(void) : Dsgnintf::TPropertyCategory(
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TChartAxesCategory(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartWallsCategory;
class PASCALIMPLEMENTATION TChartWallsCategory : public Dsgnintf::TPropertyCategory 
{
	typedef Dsgnintf::TPropertyCategory inherited;
	
public:
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Name() { return Name(__classid(TChartWallsCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Name(TMetaClass* vmt);
	#pragma option push -w-inl
	/* virtual class method */ virtual AnsiString __fastcall Description() { return Description(__classid(TChartWallsCategory)
		); }
	#pragma option pop
	/*         class method */ static AnsiString __fastcall Description(TMetaClass* vmt);
public:
	#pragma option push -w-inl
	/* TPropertyCategory.Create */ inline __fastcall TChartWallsCategory(void) : Dsgnintf::TPropertyCategory(
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyCategory.Destroy */ inline __fastcall virtual ~TChartWallsCategory(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall EditChartDesign(Chart::TCustomChart* AChart);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Chartreg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Chartreg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ChartReg
