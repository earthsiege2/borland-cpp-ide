// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GanttCh.pas' rev: 5.00

#ifndef GanttChHPP
#define GanttChHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeCanvas.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ganttch
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGanttSeries;
class PASCALIMPLEMENTATION TGanttSeries : public Series::TPointSeries 
{
	typedef Series::TPointSeries inherited;
	
private:
	Teengine::TChartValueList* FEndValues;
	Teengine::TChartValueList* FNextTask;
	Tecanvas::TChartPen* FConnectingPen;
	void __fastcall SetConnectingPen(Tecanvas::TChartPen* Value);
	void __fastcall SetEndValues(Teengine::TChartValueList* Value);
	void __fastcall SetStartValues(Teengine::TChartValueList* Value);
	void __fastcall SetNextTask(Teengine::TChartValueList* Value);
	Teengine::TChartValueList* __fastcall GetStartValues(void);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* 
		APosition);
	virtual bool __fastcall ClickedPointer(int ValueIndex, int tmpX, int tmpY, int x, int y);
	
public:
	__fastcall virtual TGanttSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TGanttSeries(void);
	int __fastcall AddGantt(const double AStart, const double AEnd, const double AY, const AnsiString AXLabel
		);
	int __fastcall AddGanttColor(const double AStart, const double AEnd, const double AY, const AnsiString 
		AXLabel, Graphics::TColor AColor);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall ClearTempValue(Teengine::TChartValueList* ValueList);
	virtual void __fastcall FillSampleValues(int NumValues);
	virtual AnsiString __fastcall GetEditorClass();
	virtual bool __fastcall IsValidSourceOf(Teengine::TChartSeries* Value);
	virtual Teengine::TChartValueList* __fastcall MandatoryValueList(void);
	virtual double __fastcall MaxXValue(void);
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	
__published:
	__property Tecanvas::TChartPen* ConnectingPen = {read=FConnectingPen, write=SetConnectingPen};
	__property Teengine::TChartValueList* StartValues = {read=GetStartValues, write=SetStartValues};
	__property Teengine::TChartValueList* EndValues = {read=FEndValues, write=SetEndValues};
	__property Teengine::TChartValueList* NextTask = {read=FNextTask, write=SetNextTask};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Ganttch */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ganttch;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GanttCh
