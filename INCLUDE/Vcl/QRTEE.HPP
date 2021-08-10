// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRTEE.pas' rev: 6.00

#ifndef QRTEEHPP
#define QRTEEHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DbChart.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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
	virtual Types::TRect __fastcall GetRectangle();
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Paint(void);
	
__published:
	__property ShowGlassCursor  = {default=1};
	__property OnProcessRecord ;
	__property BackImage ;
	__property BackImageInside  = {default=0};
	__property BackImageMode  = {default=0};
	__property BackWall ;
	__property BottomWall ;
	__property Foot ;
	__property Gradient ;
	__property LeftWall ;
	__property MarginBottom  = {index=3, default=4};
	__property MarginLeft  = {index=0, default=3};
	__property MarginRight  = {index=2, default=3};
	__property MarginTop  = {index=1, default=4};
	__property Title ;
	__property OnGetLegendPos ;
	__property OnGetLegendRect ;
	__property AxisVisible  = {default=1};
	__property BackColor  = {default=536870912};
	__property BottomAxis ;
	__property Chart3DPercent  = {default=15};
	__property ClipPoints  = {default=1};
	__property DepthAxis ;
	__property Frame ;
	__property LeftAxis ;
	__property Legend ;
	__property MaxPointsPerPage  = {default=0};
	__property Page  = {default=1};
	__property RightAxis ;
	__property ScaleLastPage  = {default=1};
	__property SeriesList ;
	__property TopAxis ;
	__property View3D  = {default=1};
	__property View3DOptions ;
	__property View3DWalls  = {default=1};
	__property OnAfterDraw ;
	__property OnBeforeDrawAxes ;
	__property OnBeforeDrawSeries ;
	__property OnGetAxisLabel ;
	__property OnGetLegendText ;
	__property OnGetNextAxisLabel ;
	__property OnPageChange ;
	__property BevelInner  = {default=0};
	__property BevelWidth  = {default=1};
	__property BevelOuter  = {default=0};
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
	__property Color  = {default=16777215};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
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
	/* TWinControl.CreateParented */ inline __fastcall TQRDBChart(HWND ParentWindow) : Dbchart::TCustomDBChart(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRChart;
typedef void __fastcall (__closure *TPrintChartEvent)(TQRChart* Sender, Types::TRect &PaperRect, Types::TRect &ChartRect);

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
	__property TTeeQuickMethod TeePrintMethod = {read=FTeePrintMethod, write=SetPrintMethod, default=1};
	__property TPrintChartEvent OnPrint = {read=FOnPrint, write=FOnPrint};
public:
	#pragma option push -w-inl
	/* TQRPrintable.Destroy */ inline __fastcall virtual ~TQRChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRChart(HWND ParentWindow) : Quickrpt::TQRPrintable(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrtee */
using namespace Qrtee;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRTEE
