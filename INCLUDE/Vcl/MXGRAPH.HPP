// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MXGRAPH.pas' rev: 6.00

#ifndef MXGRAPHHPP
#define MXGRAPHHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <MXGRID.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <MXDB.hpp>	// Pascal unit
#include <Mxconsts.hpp>	// Pascal unit
#include <MXBUTTON.hpp>	// Pascal unit
#include <Mxstore.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxgraph
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TDimEvent)(System::TObject* Sender, int iDim);

#pragma option push -b-
enum TSeriesType { stNormal, stTemplate, st1D };
#pragma option pop

class DELPHICLASS TDecisionGraphDataLink;
class DELPHICLASS TCustomDecisionGraph;
class PASCALIMPLEMENTATION TCustomDecisionGraph : public Chart::TCustomChart 
{
	typedef Chart::TCustomChart inherited;
	
private:
	bool FActive;
	TDecisionGraphDataLink* FDataLink;
	Classes::TComponent* FOwner;
	Graphics::TColor FColors[16];
	AnsiString FGraphName;
	void __fastcall NewDataStructure(void);
	void __fastcall NewGraphLayout(void);
	Teengine::TChartSeries* __fastcall MakeNewSeries(int iDim, int index, TSeriesType sType);
	AnsiString __fastcall GetCleanDimName(int iDim);
	AnsiString __fastcall GetLabel(int iDim, int ValueIndex);
	Mxdb::TDecisionSource* __fastcall GetDecisionSource(void);
	void __fastcall SetDecisionSource(Mxdb::TDecisionSource* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__property Mxdb::TDecisionSource* DecisionSource = {read=GetDecisionSource, write=SetDecisionSource};
	__fastcall virtual TCustomDecisionGraph(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDecisionGraph(void);
	DYNAMIC void __fastcall Updated(void);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDecisionGraph(HWND ParentWindow) : Chart::TCustomChart(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDecisionGraphDataLink : public Mxdb::TDecisionDataLink 
{
	typedef Mxdb::TDecisionDataLink inherited;
	
private:
	TCustomDecisionGraph* FGraph;
	
protected:
	virtual void __fastcall DecisionDataEvent(Mxdb::TDecisionDataEvent Event);
	
public:
	__fastcall TDecisionGraphDataLink(TCustomDecisionGraph* AGraph);
	__fastcall virtual ~TDecisionGraphDataLink(void);
};


class DELPHICLASS TDecisionGraph;
class PASCALIMPLEMENTATION TDecisionGraph : public TCustomDecisionGraph 
{
	typedef TCustomDecisionGraph inherited;
	
__published:
	__property DecisionSource ;
	__property AllowPanning  = {default=3};
	__property AllowZoom  = {default=1};
	__property AnimatedZoom  = {default=0};
	__property AnimatedZoomSteps  = {default=8};
	__property BackImage ;
	__property BackImageInside  = {default=0};
	__property BackImageMode  = {default=0};
	__property BottomWall ;
	__property Foot ;
	__property Gradient ;
	__property LeftWall ;
	__property MarginBottom  = {index=3, default=4};
	__property MarginLeft  = {index=0, default=3};
	__property MarginRight  = {index=2, default=3};
	__property MarginTop  = {index=1, default=4};
	__property Title ;
	__property OnAllowScroll ;
	__property OnClickAxis ;
	__property OnClickLegend ;
	__property OnClickSeries ;
	__property OnClickBackground ;
	__property OnGetLegendPos ;
	__property OnGetLegendRect ;
	__property OnScroll ;
	__property OnUndoZoom ;
	__property OnZoom ;
	__property AxisVisible  = {default=1};
	__property BackColor  = {default=536870912};
	__property BottomAxis ;
	__property Chart3DPercent  = {default=15};
	__property ClipPoints  = {default=1};
	__property Frame ;
	__property LeftAxis ;
	__property Legend ;
	__property MaxPointsPerPage  = {default=0};
	__property Monochrome  = {default=0};
	__property Page  = {default=1};
	__property RightAxis ;
	__property ScaleLastPage  = {default=1};
	__property SeriesList ;
	__property TopAxis ;
	__property View3D  = {default=1};
	__property View3DWalls  = {default=1};
	__property OnAfterDraw ;
	__property OnGetAxisLabel ;
	__property OnGetLegendText ;
	__property OnGetNextAxisLabel ;
	__property OnPageChange ;
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
	__property Color  = {default=-2147483633};
	__property Constraints ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnCanResize ;
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnDblClick ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomDecisionGraph.Create */ inline __fastcall virtual TDecisionGraph(Classes::TComponent* AOwner) : TCustomDecisionGraph(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDecisionGraph.Destroy */ inline __fastcall virtual ~TDecisionGraph(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDecisionGraph(HWND ParentWindow) : TCustomDecisionGraph(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mxgraph */
using namespace Mxgraph;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MXGRAPH
