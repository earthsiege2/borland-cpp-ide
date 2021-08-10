// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxgraph.pas' rev: 5.00

#ifndef mxgraphHPP
#define mxgraphHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <mxgrid.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Series.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <mxDB.hpp>	// Pascal unit
#include <mxConsts.hpp>	// Pascal unit
#include <mxbutton.hpp>	// Pascal unit
#include <mxstore.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
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
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__property Mxdb::TDecisionSource* DecisionSource = {read=GetDecisionSource, write=SetDecisionSource
		};
	__fastcall virtual TCustomDecisionGraph(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDecisionGraph(void);
	DYNAMIC void __fastcall Updated(void);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDecisionGraph(HWND ParentWindow) : Chart::TCustomChart(
		ParentWindow) { }
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
	__property AllowPanning ;
	__property AllowZoom ;
	__property AnimatedZoom ;
	__property AnimatedZoomSteps ;
	__property BackImage ;
	__property BackImageInside ;
	__property BackImageMode ;
	__property BottomWall ;
	__property Foot ;
	__property Gradient ;
	__property LeftWall ;
	__property MarginBottom ;
	__property MarginLeft ;
	__property MarginRight ;
	__property MarginTop ;
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
	__property AxisVisible ;
	__property BackColor ;
	__property BottomAxis ;
	__property Chart3DPercent ;
	__property ClipPoints ;
	__property Frame ;
	__property LeftAxis ;
	__property Legend ;
	__property MaxPointsPerPage ;
	__property Monochrome ;
	__property Page ;
	__property RightAxis ;
	__property ScaleLastPage ;
	__property SeriesList ;
	__property TopAxis ;
	__property View3D ;
	__property View3DWalls ;
	__property OnAfterDraw ;
	__property OnGetAxisLabel ;
	__property OnGetLegendText ;
	__property OnGetNextAxisLabel ;
	__property OnPageChange ;
	__property Align ;
	__property Anchors ;
	__property AutoSize ;
	__property BevelInner ;
	__property BevelOuter ;
	__property BevelWidth ;
	__property BorderWidth ;
	__property BorderStyle ;
	__property Color ;
	__property Constraints ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property ParentColor ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
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
	/* TCustomDecisionGraph.Create */ inline __fastcall virtual TDecisionGraph(Classes::TComponent* AOwner
		) : TCustomDecisionGraph(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDecisionGraph.Destroy */ inline __fastcall virtual ~TDecisionGraph(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDecisionGraph(HWND ParentWindow) : TCustomDecisionGraph(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mxgraph */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxgraph;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxgraph
