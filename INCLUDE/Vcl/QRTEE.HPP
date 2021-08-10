// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QrTee.pas' rev: 5.00

#ifndef QrTeeHPP
#define QrTeeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <DBChart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrtee
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTeeQuickMethod { qtmBitmap, qtmMetafile };
#pragma option pop

class DELPHICLASS TQRDBChart;
class PASCALIMPLEMENTATION TQRDBChart : public Dbchart::TCustomDBChart 
{
	typedef Dbchart::TCustomDBChart inherited;
	
public:
	__fastcall virtual TQRDBChart(Classes::TComponent* AOwner);
	virtual Windows::TRect __fastcall GetRectangle();
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Paint(void);
	
__published:
	__property ShowGlassCursor ;
	__property OnProcessRecord ;
	__property BackImage ;
	__property BackImageInside ;
	__property BackImageMode ;
	__property BackWall ;
	__property BottomWall ;
	__property Foot ;
	__property Gradient ;
	__property LeftWall ;
	__property MarginBottom ;
	__property MarginLeft ;
	__property MarginRight ;
	__property MarginTop ;
	__property Title ;
	__property OnGetLegendPos ;
	__property OnGetLegendRect ;
	__property AxisVisible ;
	__property BackColor ;
	__property BottomAxis ;
	__property Chart3DPercent ;
	__property ClipPoints ;
	__property DepthAxis ;
	__property Frame ;
	__property LeftAxis ;
	__property Legend ;
	__property MaxPointsPerPage ;
	__property Page ;
	__property RightAxis ;
	__property ScaleLastPage ;
	__property SeriesList ;
	__property TopAxis ;
	__property View3D ;
	__property View3DOptions ;
	__property View3DWalls ;
	__property OnAfterDraw ;
	__property OnBeforeDrawAxes ;
	__property OnBeforeDrawSeries ;
	__property OnGetAxisLabel ;
	__property OnGetLegendText ;
	__property OnGetNextAxisLabel ;
	__property OnPageChange ;
	__property BevelInner ;
	__property BevelWidth ;
	__property BevelOuter ;
	__property BorderWidth ;
	__property BorderStyle ;
	__property Color ;
	__property DragCursor ;
	__property DragMode ;
	__property ParentColor ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomDBChart.Destroy */ inline __fastcall virtual ~TQRDBChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRDBChart(HWND ParentWindow) : Dbchart::TCustomDBChart(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRChart;
typedef void __fastcall (__closure *TPrintChartEvent)(TQRChart* Sender, Windows::TRect &PaperRect, Windows::TRect 
	&ChartRect);

class PASCALIMPLEMENTATION TQRChart : public Quickrpt::TQRPrintable 
{
	typedef Quickrpt::TQRPrintable inherited;
	
private:
	TPrintChartEvent FOnPrint;
	TTeeQuickMethod FTeePrintMethod;
	TQRDBChart* __fastcall GetChart(void);
	void __fastcall SetPrintMethod(TTeeQuickMethod Value);
	
protected:
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	
public:
	__fastcall virtual TQRChart(Classes::TComponent* AOwner);
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall Paint(void);
	
__published:
	__property TQRDBChart* Chart = {read=GetChart};
	__property TTeeQuickMethod TeePrintMethod = {read=FTeePrintMethod, write=SetPrintMethod, default=1}
		;
	__property TPrintChartEvent OnPrint = {read=FOnPrint, write=FOnPrint};
public:
	#pragma option push -w-inl
	/* TQRPrintable.Destroy */ inline __fastcall virtual ~TQRChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRChart(HWND ParentWindow) : Quickrpt::TQRPrintable(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrtee */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrtee;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QrTee
