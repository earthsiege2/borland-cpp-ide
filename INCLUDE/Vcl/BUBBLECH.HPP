// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BubbleCh.pas' rev: 5.00

#ifndef BubbleChHPP
#define BubbleChHPP

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

namespace Bubblech
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TBubbleSeries;
class PASCALIMPLEMENTATION TBubbleSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TChartValueList* FRadiusValues;
	bool FSquared;
	void __fastcall SetSquared(bool Value);
	void __fastcall SetRadiusValues(Teengine::TChartValueList* Value);
	double __fastcall ApplyRadius(const double Value, Teengine::TChartValueList* AList, bool Increment)
		;
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	
public:
	__fastcall virtual TBubbleSeries(Classes::TComponent* AOwner);
	int __fastcall AddBubble(const double AX, const double AY, const double ARadius, const AnsiString AXLabel
		, Graphics::TColor AColor);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Windows::TRect &Rect);
	virtual void __fastcall FillSampleValues(int NumValues);
	virtual int __fastcall NumSampleValues(void);
	virtual bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinZValue(void);
	
__published:
	__property ColorEachPoint ;
	__property Teengine::TChartValueList* RadiusValues = {read=FRadiusValues, write=SetRadiusValues};
	__property bool Squared = {read=FSquared, write=SetSquared, default=1};
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TBubbleSeries(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Bubblech */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Bubblech;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BubbleCh
