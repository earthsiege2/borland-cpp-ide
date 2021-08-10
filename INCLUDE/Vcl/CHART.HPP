// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Chart.pas' rev: 5.00

#ifndef ChartHPP
#define ChartHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <TeeFunci.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Chart
{
//-- type declarations -------------------------------------------------------
typedef char TeeString[256];

typedef SmallString<20>  TeeGalleryString;

class DELPHICLASS TChartBrush;
class PASCALIMPLEMENTATION TChartBrush : public Graphics::TBrush 
{
	typedef Graphics::TBrush inherited;
	
public:
	__fastcall TChartBrush(Classes::TNotifyEvent OnChangeEvent);
	
__published:
	__property Color ;
public:
	#pragma option push -w-inl
	/* TBrush.Destroy */ inline __fastcall virtual ~TChartBrush(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomChartWall;
class DELPHICLASS TCustomChart;
class DELPHICLASS TChartWall;
class PASCALIMPLEMENTATION TCustomChartWall : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Graphics::TColor FColor;
	TChartBrush* FBrush;
	bool FDark3D;
	Tecanvas::TChartPen* FPen;
	int FSize;
	TCustomChart* FParentChart;
	void __fastcall SetBrush(TChartBrush* Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetPen(Tecanvas::TChartPen* Value);
	void __fastcall SetSize(int Value);
	bool __fastcall IsColorStored(void);
	bool __fastcall ApplyDark3D(void);
	
protected:
	Graphics::TColor DefaultColor;
	
public:
	__fastcall TCustomChartWall(TCustomChart* AOwner);
	__fastcall virtual ~TCustomChartWall(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TCustomChart* ParentChart = {read=FParentChart};
	__property TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, nodefault};
		
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property int Size = {read=FSize, write=SetSize, default=0};
};


class PASCALIMPLEMENTATION TChartWall : public TCustomChartWall 
{
	typedef TCustomChartWall inherited;
	
__published:
	__property ParentChart ;
	__property Brush ;
	__property Color ;
	__property Dark3D ;
	__property Pen ;
	__property Size ;
public:
	#pragma option push -w-inl
	/* TCustomChartWall.Create */ inline __fastcall TChartWall(TCustomChart* AOwner) : TCustomChartWall(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartWall.Destroy */ inline __fastcall virtual ~TChartWall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartTitle;
class PASCALIMPLEMENTATION TChartTitle : public Teeprocs::TChartFontObject 
{
	typedef Teeprocs::TChartFontObject inherited;
	
private:
	bool FAdjustFrame;
	Classes::TAlignment FAlignment;
	TChartBrush* FBrush;
	Graphics::TColor FColor;
	Tecanvas::TChartHiddenPen* FFrame;
	Classes::TStrings* FText;
	Windows::TRect FTitleRect;
	bool FVisible;
	HIDESBASE bool __fastcall IsFontStored(void);
	void __fastcall SetAdjustFrame(bool Value);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetBrush(TChartBrush* Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetFrame(Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetText(Classes::TStrings* Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	Graphics::TColor DefaultFontColor;
	Graphics::TFontStyles DefaultFontStyle;
	
public:
	__fastcall TChartTitle(TCustomChart* AOwner);
	__fastcall virtual ~TChartTitle(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall Clicked(int x, int y);
	void __fastcall Draw(bool OnTop);
	__property Windows::TRect TitleRect = {read=FTitleRect};
	
__published:
	__property bool AdjustFrame = {read=FAdjustFrame, write=SetAdjustFrame, default=1};
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=2};
	__property TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, nodefault};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property Tecanvas::TChartHiddenPen* Frame = {read=FFrame, write=SetFrame};
	__property Classes::TStrings* Text = {read=FText, write=SetText};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


class DELPHICLASS TChartLegend;
class DELPHICLASS TCustomChartLegend;
#pragma option push -b-
enum TLegendAlignment { laLeft, laRight, laTop, laBottom };
#pragma option pop

#pragma option push -b-
enum TLegendStyle { lsAuto, lsSeries, lsValues, lsLastValues };
#pragma option pop

class PASCALIMPLEMENTATION TCustomChartLegend : public Teeprocs::TChartFontObject 
{
	typedef Teeprocs::TChartFontObject inherited;
	
private:
	TLegendAlignment FAlignment;
	TChartBrush* FBrush;
	Graphics::TColor FColor;
	int FColorWidth;
	Tecanvas::TChartHiddenPen* FDividingLines;
	int FFirstValue;
	Tecanvas::TChartPen* FFrame;
	int FHorizMargin;
	bool FInverted;
	TLegendStyle FLegendStyle;
	int FMaxNumRows;
	Windows::TRect FRectLegend;
	bool FResizeChart;
	Graphics::TColor FShadowColor;
	int FShadowSize;
	Teengine::TLegendTextStyle FTextStyle;
	int FTopLeftPos;
	int FVertMargin;
	bool FVisible;
	int IColorWidth;
	TLegendStyle ILegendStyle;
	MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	TCustomChart* __fastcall GetParentChart(void);
	bool __fastcall GetVertical(void);
	void __fastcall SetAlignment(TLegendAlignment Value);
	void __fastcall SetBrush(TChartBrush* Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetColorWidth(int Value);
	void __fastcall SetDividingLines(Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetFirstValue(int Value);
	void __fastcall SetFrame(Tecanvas::TChartPen* Value);
	void __fastcall SetHorizMargin(int Value);
	void __fastcall SetInverted(bool Value);
	void __fastcall SetLegendStyle(TLegendStyle Value);
	void __fastcall SetMaxNumRows(int Value);
	void __fastcall SetResizeChart(bool Value);
	void __fastcall SetShadowColor(Graphics::TColor Value);
	void __fastcall SetShadowSize(int Value);
	void __fastcall SetTextStyle(Teengine::TLegendTextStyle Value);
	void __fastcall SetTopLeftPos(int Value);
	void __fastcall SetVertMargin(int Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	void __fastcall CalcLegendStyle(void);
	__property TLegendStyle InternalLegendStyle = {read=ILegendStyle, nodefault};
	virtual int __fastcall MaxLegendValues(int YLegend, int ItemHeight);
	
public:
	int NumCols;
	int NumRows;
	__fastcall TCustomChartLegend(TCustomChart* AOwner);
	__fastcall virtual ~TCustomChartLegend(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	AnsiString __fastcall FormattedValue(Teengine::TChartSeries* ASeries, int ValueIndex);
	AnsiString __fastcall FormattedLegend(int SeriesOrValueIndex);
	__property TCustomChart* ParentChart = {read=GetParentChart};
	virtual void __fastcall Draw(void);
	Windows::TRect __fastcall GetColorRect(int X1, int Y0, int Y1);
	int __fastcall TotalLegendItems(void);
	int __fastcall MaxLegendWidth(int NumLegendValues);
	int __fastcall Clicked(int x, int y);
	__property Windows::TRect RectLegend = {read=FRectLegend, write=FRectLegend};
	__property TLegendAlignment Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property int ColorWidth = {read=FColorWidth, write=SetColorWidth, default=12};
	__property Tecanvas::TChartHiddenPen* DividingLines = {read=FDividingLines, write=SetDividingLines}
		;
	__property int FirstValue = {read=FFirstValue, write=SetFirstValue, default=0};
	__property Font ;
	__property Tecanvas::TChartPen* Frame = {read=FFrame, write=SetFrame};
	__property int HorizMargin = {read=FHorizMargin, write=SetHorizMargin, default=0};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=0};
	__property TLegendStyle LegendStyle = {read=FLegendStyle, write=SetLegendStyle, default=0};
	__property int MaxNumRows = {read=FMaxNumRows, write=SetMaxNumRows, default=10};
	__property bool ResizeChart = {read=FResizeChart, write=SetResizeChart, default=1};
	__property Graphics::TColor ShadowColor = {read=FShadowColor, write=SetShadowColor, default=0};
	__property int ShadowSize = {read=FShadowSize, write=SetShadowSize, default=3};
	__property Teengine::TLegendTextStyle TextStyle = {read=FTextStyle, write=SetTextStyle, default=1};
		
	__property int TopPos = {read=FTopLeftPos, write=SetTopLeftPos, default=10};
	__property bool Vertical = {read=GetVertical, nodefault};
	__property int VertMargin = {read=FVertMargin, write=SetVertMargin, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


class PASCALIMPLEMENTATION TChartLegend : public TCustomChartLegend 
{
	typedef TCustomChartLegend inherited;
	
__published:
	__property Alignment ;
	__property Brush ;
	__property Color ;
	__property ColorWidth ;
	__property DividingLines ;
	__property FirstValue ;
	__property Font ;
	__property Frame ;
	__property HorizMargin ;
	__property Inverted ;
	__property LegendStyle ;
	__property MaxNumRows ;
	__property ResizeChart ;
	__property ShadowColor ;
	__property ShadowSize ;
	__property TextStyle ;
	__property TopPos ;
	__property VertMargin ;
	__property Visible ;
public:
	#pragma option push -w-inl
	/* TCustomChartLegend.Create */ inline __fastcall TChartLegend(TCustomChart* AOwner) : TCustomChartLegend(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartLegend.Destroy */ inline __fastcall virtual ~TChartLegend(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TAxisSavedScales
{
	bool Auto;
	bool AutoMin;
	bool AutoMax;
	double Min;
	double Max;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TAllAxisSavedScales
{
	TAxisSavedScales Top;
	TAxisSavedScales Left;
	TAxisSavedScales Right;
	TAxisSavedScales Bottom;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TChartAllowScrollEvent)(Teengine::TChartAxis* Sender, double &AMin
	, double &AMax, bool &AllowScroll);

typedef void __fastcall (__closure *TChartClickAxis)(TCustomChart* Sender, Teengine::TChartAxis* Axis
	, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TChartClick)(TCustomChart* Sender, Controls::TMouseButton Button
	, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TChartClickSeries)(TCustomChart* Sender, Teengine::TChartSeries* 
	Series, int ValueIndex, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TOnGetLegendPos)(TCustomChart* Sender, int Index, int &X, int &Y
	, int &XColor);

typedef void __fastcall (__closure *TOnGetLegendRect)(TCustomChart* Sender, Windows::TRect &Rect);

typedef void __fastcall (__closure *TOnGetLegendText)(Teengine::TCustomAxisPanel* Sender, TLegendStyle 
	LegendStyle, int Index, AnsiString &LegendText);

class PASCALIMPLEMENTATION TCustomChart : public Teengine::TCustomAxisPanel 
{
	typedef Teengine::TCustomAxisPanel inherited;
	
private:
	bool FBackImageInside;
	TChartWall* FBackWall;
	TChartWall* FBottomWall;
	TChartTitle* FFoot;
	TChartWall* FLeftWall;
	TChartLegend* FLegend;
	bool FRestoredAxisScales;
	#pragma pack(push, 1)
	TAllAxisSavedScales FSavedScales;
	#pragma pack(pop)
	
	TChartTitle* FTitle;
	TChartAllowScrollEvent FOnAllowScroll;
	TChartClickAxis FOnClickAxis;
	TChartClick FOnClickBackGround;
	TChartClick FOnClickLegend;
	TChartClickSeries FOnClickSeries;
	TOnGetLegendPos FOnGetLegendPos;
	TOnGetLegendRect FOnGetLegendRect;
	TOnGetLegendText FOnGetLegendText;
	Graphics::TColor __fastcall GetBackColor(void);
	Tecanvas::TChartPen* __fastcall GetFrame(void);
	void __fastcall RestoreScales(const TAllAxisSavedScales &Saved);
	TAllAxisSavedScales __fastcall SaveScales();
	void __fastcall SetBackColor(Graphics::TColor Value);
	void __fastcall SetBackImageInside(bool Value);
	void __fastcall SetBackWall(TChartWall* Value);
	void __fastcall SetBottomWall(TChartWall* Value);
	void __fastcall SetFoot(TChartTitle* Value);
	void __fastcall SetFrame(Tecanvas::TChartPen* Value);
	void __fastcall SetLeftWall(TChartWall* Value);
	void __fastcall SetLegend(TChartLegend* Value);
	void __fastcall SetTitle(TChartTitle* Value);
	void __fastcall ScrollVerticalAxes(bool Up);
	
protected:
	virtual void __fastcall CalcAxisRect(void);
	virtual void __fastcall CalcSeriesRect(void);
	virtual int __fastcall CalcWallSize(Teengine::TCustomChartAxis* Axis);
	virtual void __fastcall CalcZoomPoints(void);
	void __fastcall DoZoom(const double TopI, const double TopF, const double BotI, const double BotF, 
		const double LefI, const double LefF, const double RigI, const double RigF);
	virtual void __fastcall DrawImage(const Windows::TRect &R);
	virtual void __fastcall DrawTitlesAndLegend(void);
	virtual void __fastcall DrawWalls(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Windows::TPoint 
		&MousePos);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Windows::TPoint &MousePos
		);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Windows::TPoint &MousePos)
		;
	
public:
	__fastcall virtual TCustomChart(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomChart(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	AnsiString __fastcall AxisTitleOrName(Teengine::TCustomChartAxis* Axis);
	void __fastcall CalcClickedPart(const Windows::TPoint &Pos, Teengine::TChartClickedPart &Part);
	void __fastcall ExchangeSeries(int Series1, int Series2);
	virtual void __fastcall FillSeriesSourceItems(Teengine::TChartSeries* ASeries, Classes::TGetStrProc 
		Proc);
	virtual void __fastcall FillValueSourceItems(Teengine::TChartValueList* ValueList, Classes::TGetStrProc 
		Proc);
	Teengine::TChartSeries* __fastcall GetASeries(void);
	virtual bool __fastcall IsFreeSeriesColor(Graphics::TColor AColor, bool CheckBackground);
	void __fastcall NextPage(void);
	void __fastcall PreviousPage(void);
	void __fastcall RemoveAllSeries(void);
	void __fastcall SeriesDown(Teengine::TChartSeries* ASeries);
	void __fastcall SeriesUp(Teengine::TChartSeries* ASeries);
	DYNAMIC void __fastcall UndoZoom(void);
	void __fastcall ZoomPercent(const double PercentZoom);
	void __fastcall ZoomRect(const Windows::TRect &Rect);
	virtual AnsiString __fastcall FormattedValueLegend(Teengine::TChartSeries* ASeries, int ValueIndex)
		;
	AnsiString __fastcall FormattedLegend(int SeriesOrValueIndex);
	__property bool BackImageInside = {read=FBackImageInside, write=SetBackImageInside, default=0};
	__property Graphics::TColor BackColor = {read=GetBackColor, write=SetBackColor, nodefault};
	__property TChartWall* BackWall = {read=FBackWall, write=SetBackWall};
	__property Tecanvas::TChartPen* Frame = {read=GetFrame, write=SetFrame};
	__property TChartWall* BottomWall = {read=FBottomWall, write=SetBottomWall};
	__property TChartTitle* Foot = {read=FFoot, write=SetFoot};
	__property TChartWall* LeftWall = {read=FLeftWall, write=SetLeftWall};
	__property TChartLegend* Legend = {read=FLegend, write=SetLegend};
	__property TChartTitle* Title = {read=FTitle, write=SetTitle};
	__property TChartAllowScrollEvent OnAllowScroll = {read=FOnAllowScroll, write=FOnAllowScroll};
	__property TChartClickAxis OnClickAxis = {read=FOnClickAxis, write=FOnClickAxis};
	__property TChartClick OnClickLegend = {read=FOnClickLegend, write=FOnClickLegend};
	__property TChartClickSeries OnClickSeries = {read=FOnClickSeries, write=FOnClickSeries};
	__property TChartClick OnClickBackground = {read=FOnClickBackGround, write=FOnClickBackGround};
	__property TOnGetLegendPos OnGetLegendPos = {read=FOnGetLegendPos, write=FOnGetLegendPos};
	__property TOnGetLegendRect OnGetLegendRect = {read=FOnGetLegendRect, write=FOnGetLegendRect};
	__property TOnGetLegendText OnGetLegendText = {read=FOnGetLegendText, write=FOnGetLegendText};
	__property Align ;
	__property Anchors ;
	__property BevelInner ;
	__property BevelOuter ;
	__property BevelWidth ;
	__property BorderWidth ;
	__property BorderStyle ;
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
	__property AutoSize ;
	__property Constraints ;
	__property DragKind ;
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
	/* TWinControl.CreateParented */ inline __fastcall TCustomChart(HWND ParentWindow) : Teengine::TCustomAxisPanel(
		ParentWindow) { }
	#pragma option pop
	
};



class DELPHICLASS LegendException;
class PASCALIMPLEMENTATION LegendException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall LegendException(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall LegendException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall LegendException(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall LegendException(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall LegendException(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall LegendException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall LegendException(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall LegendException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~LegendException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChart;
class PASCALIMPLEMENTATION TChart : public TCustomChart 
{
	typedef TCustomChart inherited;
	
public:
	__property DockManager ;
	
__published:
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
	__property UseDockManager ;
	__property DockSite ;
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
	__property OnResize ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
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
	/* TCustomChart.Create */ inline __fastcall virtual TChart(Classes::TComponent* AOwner) : TCustomChart(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChart.Destroy */ inline __fastcall virtual ~TChart(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChart(HWND ParentWindow) : TCustomChart(ParentWindow
		) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeSeriesType;
class PASCALIMPLEMENTATION TTeeSeriesType : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TMetaClass*SeriesClass;
	TMetaClass*FunctionClass;
	TeeGalleryString Description;
	TeeGalleryString GalleryPage;
	int NumGallerySeries;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeSeriesType(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeSeriesType(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTeeSeriesTypes;
class PASCALIMPLEMENTATION TTeeSeriesTypes : public Classes::TList 
{
	typedef Classes::TList inherited;
	
private:
	TTeeSeriesType* __fastcall GetSeriesType(int Index);
	
public:
	TTeeSeriesType* __fastcall FindSeriesClass(TMetaClass* ASeriesClass);
	__property TTeeSeriesType* SeriesType[int Index] = {read=GetSeriesType/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TTeeSeriesTypes(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TTeeSeriesTypes(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TTeeDragObject;
class PASCALIMPLEMENTATION TTeeDragObject : public Controls::TDragObject 
{
	typedef Controls::TDragObject inherited;
	
private:
	#pragma pack(push, 1)
	Teengine::TChartClickedPart FPart;
	#pragma pack(pop)
	
	
protected:
	virtual Controls::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	
public:
	__fastcall TTeeDragObject(const Teengine::TChartClickedPart &APart);
	__property Teengine::TChartClickedPart Part = {read=FPart};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTeeDragObject(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
#define TeeMsg_DefaultFunctionName "TeeFunction"
#define TeeMsg_DefaultSeriesName "Series"
#define ChartComponentPalette "TeeChart"
extern PACKAGE double AnimatedZoomFactor;
extern PACKAGE Controls::TMouseButton TeeZoomMouseButton;
extern PACKAGE Controls::TMouseButton TeeScrollMouseButton;
extern PACKAGE Classes::TShiftState TeeZoomKeyShift;
extern PACKAGE Classes::TShiftState TeeScrollKeyShift;
extern PACKAGE int TeeTitleFootDistance;
extern PACKAGE TTeeSeriesTypes* TeeSeriesTypes;
extern PACKAGE Graphics::TBrushStyle __fastcall GetDefaultPattern(int PatternIndex);
extern PACKAGE void __fastcall AssignSeries(Teengine::TChartSeries* &OldSeries, Teengine::TChartSeries* 
	&NewSeries);
extern PACKAGE Teengine::TTeeFunction* __fastcall CreateNewTeeFunction(Teengine::TChartSeries* ASeries
	, TMetaClass* AClass);
extern PACKAGE Teengine::TChartSeries* __fastcall CreateNewSeries(Classes::TComponent* AOwner, Teengine::TCustomAxisPanel* 
	AChart, TMetaClass* AClass, TMetaClass* AFunctionClass);
extern PACKAGE Teengine::TChartSeries* __fastcall CloneChartSeries(Teengine::TChartSeries* ASeries);
	
extern PACKAGE void __fastcall ChangeSeriesType(Teengine::TChartSeries* &ASeries, TMetaClass* NewType
	);
extern PACKAGE void __fastcall ChangeAllSeriesType(TCustomChart* AChart, TMetaClass* AClass);
extern PACKAGE void __fastcall RegisterTeeSeriesFunction(TMetaClass* ASeriesClass, TMetaClass* AFunctionClass
	, const AnsiString ADescription, const AnsiString AGalleryPage, int ANumGallerySeries);
extern PACKAGE void __fastcall RegisterTeeSeries(TMetaClass* ASeriesClass, const AnsiString ADescription
	, const AnsiString AGalleryPage, int ANumGallerySeries);
extern PACKAGE void __fastcall RegisterTeeFunction(TMetaClass* AFunctionClass, const AnsiString ADescription
	, const AnsiString AGalleryPage, int ANumGallerySeries);
extern PACKAGE void __fastcall RegisterTeeBasicFunction(TMetaClass* AFunctionClass, const AnsiString 
	ADescription);
extern PACKAGE AnsiString __fastcall GetTeeFunctionDescription(TMetaClass* AFunctionClass);
extern PACKAGE void __fastcall UnRegisterTeeSeries(TMetaClass* const * ASeriesList, const int ASeriesList_Size
	);
extern PACKAGE void __fastcall UnRegisterTeeFunctions(TMetaClass* const * AFunctionList, const int AFunctionList_Size
	);

}	/* namespace Chart */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Chart;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Chart
