// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ArrowCha.pas' rev: 5.00

#ifndef ArrowChaHPP
#define ArrowChaHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Arrowcha
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TArrowSeries;
class PASCALIMPLEMENTATION TArrowSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TChartValueList* FEndXValues;
	Teengine::TChartValueList* FEndYValues;
	void __fastcall SetEndXValues(Teengine::TChartValueList* Value);
	void __fastcall SetEndYValues(Teengine::TChartValueList* Value);
	int __fastcall GetArrowHeight(void);
	void __fastcall SetArrowHeight(int Value);
	int __fastcall GetArrowWidth(void);
	void __fastcall SetArrowWidth(int Value);
	Teengine::TChartValueList* __fastcall GetStartXValues(void);
	void __fastcall SetStartXValues(Teengine::TChartValueList* Value);
	Teengine::TChartValueList* __fastcall GetStartYValues(void);
	void __fastcall SetStartYValues(Teengine::TChartValueList* Value);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	
public:
	__fastcall virtual TArrowSeries(Classes::TComponent* AOwner);
	int __fastcall AddArrow(const double X0, const double Y0, const double X1, const double Y1, const AnsiString 
		ALabel, Graphics::TColor AColor);
	virtual void __fastcall FillSampleValues(int NumValues);
	virtual AnsiString __fastcall GetEditorClass();
	virtual bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	
__published:
	__property int ArrowHeight = {read=GetArrowHeight, write=SetArrowHeight, stored=false, nodefault};
	__property int ArrowWidth = {read=GetArrowWidth, write=SetArrowWidth, stored=false, nodefault};
	__property Teengine::TChartValueList* EndXValues = {read=FEndXValues, write=SetEndXValues};
	__property Teengine::TChartValueList* EndYValues = {read=FEndYValues, write=SetEndYValues};
	__property Teengine::TChartValueList* StartXValues = {read=GetStartXValues, write=SetStartXValues};
		
	__property Teengine::TChartValueList* StartYValues = {read=GetStartYValues, write=SetStartYValues};
		
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TArrowSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Arrowcha */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Arrowcha;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ArrowCha
