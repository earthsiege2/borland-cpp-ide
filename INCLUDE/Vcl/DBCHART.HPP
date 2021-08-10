// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBChart.pas' rev: 5.00

#ifndef DBChartHPP
#define DBChartHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeEngine.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbchart
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS DBChartException;
class PASCALIMPLEMENTATION DBChartException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall DBChartException(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall DBChartException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall DBChartException(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall DBChartException(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall DBChartException(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall DBChartException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall DBChartException(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall DBChartException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~DBChartException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListOfDataSources;
class PASCALIMPLEMENTATION TListOfDataSources : public Classes::TList 
{
	typedef Classes::TList inherited;
	
private:
	void __fastcall SetDataSource(int Index, Db::TDataSource* DataSource);
	Db::TDataSource* __fastcall GetDataSource(int Index);
	
public:
	__property Db::TDataSource* DataSource[int Index] = {read=GetDataSource, write=SetDataSource/*, default
		*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TListOfDataSources(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TListOfDataSources(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDBChart;
typedef void __fastcall (__closure *TProcessRecordEvent)(TCustomDBChart* Sender, Db::TDataSet* DataSet
	);

class PASCALIMPLEMENTATION TCustomDBChart : public Chart::TCustomChart 
{
	typedef Chart::TCustomChart inherited;
	
private:
	bool FAutoRefresh;
	int FRefreshInterval;
	bool FShowGlassCursor;
	TProcessRecordEvent FOnProcessRecord;
	bool IUpdating;
	Extctrls::TTimer* ITimer;
	TListOfDataSources* IDataSources;
	void __fastcall CheckDataSet(Db::TDataSet* ADataSet, Teengine::TChartSeries* ASeries);
	void __fastcall CheckNewDataSource(Db::TDataSet* ADataSet, bool SingleRow);
	void __fastcall DataSourceRowChange(System::TObject* Sender, Db::TField* Field);
	void __fastcall DataSourceStateChange(System::TObject* Sender);
	void __fastcall DataSourceUpdateData(System::TObject* Sender);
	void __fastcall SetRefreshInterval(int Value);
	void __fastcall CheckTimer(void);
	void __fastcall OnRefreshTimer(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall RemovedDataSource(Teengine::TChartSeries* ASeries, Classes::TComponent* AComponent
		);
	
public:
	__fastcall virtual TCustomDBChart(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomDBChart(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall CheckDatasource(Teengine::TChartSeries* ASeries);
	virtual bool __fastcall IsValidDataSource(Teengine::TChartSeries* ASeries, Classes::TComponent* AComponent
		);
	virtual void __fastcall FillValueSourceItems(Teengine::TChartValueList* AValueList, Classes::TGetStrProc 
		Proc);
	virtual void __fastcall FillSeriesSourceItems(Teengine::TChartSeries* ASeries, Classes::TGetStrProc 
		Proc);
	void __fastcall RefreshDataSet(Db::TDataSet* ADataSet, Teengine::TChartSeries* ASeries);
	void __fastcall RefreshData(void);
	__property bool AutoRefresh = {read=FAutoRefresh, write=FAutoRefresh, default=1};
	__property int RefreshInterval = {read=FRefreshInterval, write=SetRefreshInterval, default=0};
	__property bool ShowGlassCursor = {read=FShowGlassCursor, write=FShowGlassCursor, default=1};
	__property TProcessRecordEvent OnProcessRecord = {read=FOnProcessRecord, write=FOnProcessRecord};
public:
		
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDBChart(HWND ParentWindow) : Chart::TCustomChart(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TDBChart;
class PASCALIMPLEMENTATION TDBChart : public TCustomDBChart 
{
	typedef TCustomDBChart inherited;
	
__published:
	__property AutoRefresh ;
	__property RefreshInterval ;
	__property ShowGlassCursor ;
	__property OnProcessRecord ;
	__property AllowPanning ;
	__property AllowZoom ;
	__property AnimatedZoom ;
	__property AnimatedZoomSteps ;
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
	__property PrintProportional ;
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
	__property DepthAxis ;
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
	__property View3DOptions ;
	__property View3DWalls ;
	__property OnAfterDraw ;
	__property OnBeforeDrawAxes ;
	__property OnBeforeDrawSeries ;
	__property OnGetAxisLabel ;
	__property OnGetLegendText ;
	__property OnGetNextAxisLabel ;
	__property OnPageChange ;
	__property Align ;
	__property BevelInner ;
	__property BevelOuter ;
	__property BevelWidth ;
	__property BorderWidth ;
	__property BorderStyle ;
	__property Color ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property ParentColor ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property Anchors ;
	__property AutoSize ;
	__property Constraints ;
	__property DragKind ;
	__property Locked ;
	__property OnClick ;
	__property OnContextPopup ;
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
	__property OnCanResize ;
	__property OnConstrainedResize ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnEndDock ;
	__property OnGetSiteInfo ;
	__property OnStartDock ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomDBChart.Create */ inline __fastcall virtual TDBChart(Classes::TComponent* AOwner) : TCustomDBChart(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomDBChart.Destroy */ inline __fastcall virtual ~TDBChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBChart(HWND ParentWindow) : TCustomDBChart(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbchart */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbchart;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBChart
