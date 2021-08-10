// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'chartreg.pas' rev: 6.00

#ifndef chartregHPP
#define chartregHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <PropertyCategories.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Chartreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChartClassProperty;
class PASCALIMPLEMENTATION TChartClassProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
protected:
	void __fastcall InternalEditPage(Chart::TCustomChart* AChart, int APage);
	void __fastcall InternalEditSeries(Teengine::TChartSeries* ASeries);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartClassProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartClassProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartCompEditor;
class PASCALIMPLEMENTATION TChartCompEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
protected:
	void __fastcall ChartExecuteVerb(int Index, Chart::TCustomChart* AChart);
	
public:
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual AnsiString __fastcall GetVerb(int Index);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TChartCompEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
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
	/* TComponentEditor.Create */ inline __fastcall virtual TDBChartCompEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TChartCompEditor(AComponent, ADesigner) { }
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartPenProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TChartClassProperty(ADesigner, APropCount) { }
	#pragma option pop
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TChartBrushProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TChartClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TChartBrushProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall EditChartDesign(Chart::TCustomChart* AChart, Designintf::_di_IDesigner ADesigner);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Chartreg */
using namespace Chartreg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// chartreg
