// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeEngine.pas' rev: 6.00

#ifndef TeEngineHPP
#define TeEngineHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teengine
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSeriesMarksStyle { smsValue, smsPercent, smsLabel, smsLabelPercent, smsLabelValue, smsLegend, smsPercentTotal, smsLabelPercentTotal, smsXValue };
#pragma option pop

typedef double *PChartValue;

typedef double TChartValue;

#pragma option push -b-
enum TChartListOrder { loNone, loAscending, loDescending };
#pragma option pop

class DELPHICLASS TChartValueList;
class DELPHICLASS TChartSeries;
class DELPHICLASS TChartAxis;
class DELPHICLASS TCustomChartAxis;
class DELPHICLASS TChartAxisTitle;
class PASCALIMPLEMENTATION TChartAxisTitle : public Teeprocs::TChartFontObject 
{
	typedef Teeprocs::TChartFontObject inherited;
	
private:
	int FAngle;
	TCustomChartAxis* FAxis;
	AnsiString FCaption;
	bool __fastcall IsAngleStored(void);
	void __fastcall SetAngle(int Value);
	void __fastcall SetCaption(const AnsiString Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property int Angle = {read=FAngle, write=SetAngle, stored=IsAngleStored, nodefault};
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property Font ;
public:
	#pragma option push -w-inl
	/* TChartFontObject.Create */ inline __fastcall TChartAxisTitle(Teeprocs::TCustomTeePanel* AOwner) : Teeprocs::TChartFontObject(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TChartFontObject.Destroy */ inline __fastcall virtual ~TChartAxisTitle(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TAxisLabelStyle { talAuto, talNone, talValue, talMark, talText };
#pragma option pop

class DELPHICLASS TCustomAxisPanel;
class DELPHICLASS TChartSeriesList;
class PASCALIMPLEMENTATION TChartSeriesList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TChartSeries* operator[](int Index) { return Series[Index]; }
	
private:
	TCustomAxisPanel* FOwner;
	void __fastcall SetSeries(int Index, TChartSeries* Series);
	TChartSeries* __fastcall GetSeries(int Index);
	
public:
	int __fastcall CountActive(void);
	__property TCustomAxisPanel* Owner = {read=FOwner};
	__property TChartSeries* Series[int Index] = {read=GetSeries, write=SetSeries/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TChartSeriesList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartSeriesList(void) : Classes::TList() { }
	#pragma option pop
	
};


class DELPHICLASS TChartDepthAxis;
class PASCALIMPLEMENTATION TCustomChartAxis : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FAutomatic;
	bool FAutomaticMaximum;
	bool FAutomaticMinimum;
	double FDesiredIncrement;
	double FMaximumValue;
	double FMinimumValue;
	bool FLogarithmic;
	int FLogarithmicBase;
	Tecanvas::TChartAxisPen* FAxis;
	int FPosAxis;
	TChartAxisTitle* FAxisTitle;
	int FTitleSize;
	int FPosTitle;
	Tecanvas::TDottedGrayPen* FGrid;
	bool FGridCentered;
	bool FLabels;
	int FLabelsAngle;
	Graphics::TFont* FLabelsFont;
	bool FLabelsOnAxis;
	int FLabelsSeparation;
	int FLabelsSize;
	TAxisLabelStyle FLabelStyle;
	int FPosLabels;
	AnsiString FAxisValuesFormat;
	AnsiString FDateTimeFormat;
	bool FExactDateTime;
	bool FRoundFirstLabel;
	bool FLabelsMultiLine;
	Tecanvas::TChartHiddenPen* FMinorGrid;
	int FMinorTickCount;
	int FMinorTickLength;
	Tecanvas::TDarkGrayPen* FMinorTicks;
	Tecanvas::TDarkGrayPen* FTicks;
	Tecanvas::TDarkGrayPen* FTicksInner;
	int FTickInnerLength;
	int FTickLength;
	bool FTickOnLabelsOnly;
	bool FInverted;
	bool FHorizontal;
	bool FOtherSide;
	TCustomAxisPanel* FParentChart;
	bool FVisible;
	double FStartPosition;
	double FEndPosition;
	double FPositionPercent;
	double IMaximum;
	double IMinimum;
	double IRange;
	bool IAxisDateTime;
	int ICenterPos;
	int IDefaultTitleAngle;
	void __fastcall SetAutomatic(bool Value);
	void __fastcall SetAutomaticMinimum(bool Value);
	void __fastcall SetAutomaticMaximum(bool Value);
	void __fastcall SetAxis(Tecanvas::TChartAxisPen* Value);
	void __fastcall SetAxisTitle(TChartAxisTitle* Value);
	void __fastcall SetDateTimeFormat(const AnsiString Value);
	void __fastcall SetDesiredIncrement(const double Value);
	void __fastcall SetExactDateTime(bool Value);
	void __fastcall SetGrid(Tecanvas::TDottedGrayPen* Value);
	void __fastcall SetGridCentered(bool Value);
	void __fastcall SetInverted(bool Value);
	void __fastcall SetLabels(bool Value);
	void __fastcall SetLabelsFont(Graphics::TFont* Value);
	void __fastcall SetLabelStyle(TAxisLabelStyle Value);
	void __fastcall SetLabelsOnAxis(bool Value);
	void __fastcall SetLabelsAngle(int Value);
	void __fastcall SetLabelsMultiLine(bool Value);
	void __fastcall SetLabelsSeparation(int Value);
	void __fastcall SetLabelsSize(int Value);
	void __fastcall SetLogarithmic(bool Value);
	void __fastcall SetLogarithmicBase(int Value);
	void __fastcall SetMaximum(const double Value);
	void __fastcall SetMinimum(const double Value);
	void __fastcall SetMinorGrid(Tecanvas::TChartHiddenPen* Value);
	void __fastcall SetMinorTickCount(int Value);
	void __fastcall SetMinorTickLength(int Value);
	void __fastcall SetMinorTicks(Tecanvas::TDarkGrayPen* Value);
	void __fastcall SetStartPosition(const double Value);
	void __fastcall SetEndPosition(const double Value);
	void __fastcall SetPositionPercent(const double Value);
	void __fastcall SetRoundFirstLabel(bool Value);
	void __fastcall SetTickLength(int Value);
	void __fastcall SetTickInnerLength(int Value);
	void __fastcall SetTicks(Tecanvas::TDarkGrayPen* Value);
	void __fastcall SetTicksInner(Tecanvas::TDarkGrayPen* Value);
	void __fastcall SetTickOnLabelsOnly(bool Value);
	void __fastcall SetTitleSize(int Value);
	void __fastcall SetValuesFormat(const AnsiString Value);
	void __fastcall SetVisible(bool Value);
	int __fastcall ApplyPosition(int APos, const Types::TRect &R);
	double __fastcall CalcDateTimeIncrement(int MaxNumLabels);
	double __fastcall CalcLabelsIncrement(int MaxNumLabels);
	int __fastcall GetRectangleEdge(const Types::TRect &R);
	int __fastcall InternalCalcLogPosValue(bool IsX, const double Value);
	int __fastcall InternalCalcDepthPosValue(const double Value);
	double __fastcall InternalCalcLog(double &LogMax, double &LogMin);
	int __fastcall InternalCalcPosValue(const double Value, bool FromEnd);
	bool __fastcall IsAxisValuesFormatStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsMaxStored(void);
	bool __fastcall IsMinStored(void);
	bool __fastcall IsPosStored(void);
	bool __fastcall IsStartStored(void);
	bool __fastcall IsEndStored(void);
	
public:
	int IStartPos;
	int IEndPos;
	int IAxisSize;
	bool IsDepthAxis;
	void __fastcall InternalCalcPositions(void);
	int __fastcall InternalCalcSize(Graphics::TFont* tmpFont, int tmpAngle, const AnsiString tmpText, int tmpSize);
	void __fastcall InternalSetInverted(bool Value);
	void __fastcall CalcRect(Types::TRect &R, bool InflateChartRectangle);
	void __fastcall InternalSetMaximum(const double Value);
	void __fastcall InternalSetMinimum(const double Value);
	int __fastcall SizeTickAxis(void);
	int __fastcall SizeTitle(void);
	int __fastcall SizeLabels(void);
	void __fastcall RecalcSizeCenter(void);
	__fastcall TCustomChartAxis(TCustomAxisPanel* AOwner);
	__fastcall virtual ~TCustomChartAxis(void);
	int __fastcall MaxLabelsWidth(void);
	int __fastcall LabelWidth(const double Value);
	int __fastcall LabelHeight(const double Value);
	AnsiString __fastcall LabelValue(const double Value);
	TAxisLabelStyle __fastcall CalcLabelStyle(void);
	void __fastcall DrawTitle(int x, int y);
	void __fastcall DrawAxisLabel(int x, int y, int Angle, const AnsiString St);
	int __fastcall CalcPosValue(const double Value);
	int __fastcall CalcXPosValue(const double Value);
	int __fastcall CalcYPosValue(const double Value);
	int __fastcall CalcSizeValue(const double Value);
	double __fastcall CalcPosPoint(int Value);
	void __fastcall CustomDrawMinMax(int APosLabels, int APosTitle, int APosAxis, bool GridVisible, const double AMinimum, const double AMaximum, const double AIncrement);
	void __fastcall CustomDraw(int APosLabels, int APosTitle, int APosAxis, bool GridVisible);
	void __fastcall CustomDrawStartEnd(int APosLabels, int APosTitle, int APosAxis, bool GridVisible, int AStartPos, int AEndPos);
	void __fastcall CustomDrawMinMaxStartEnd(int APosLabels, int APosTitle, int APosAxis, bool GridVisible, const double AMinimum, const double AMaximum, const double AIncrement, int AStartPos, int AEndPos);
	void __fastcall Draw(bool CalcPosAxis);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall AdjustMaxMin(void);
	void __fastcall CalcMinMax(double &AMin, double &AMax);
	void __fastcall Scroll(const double Offset, bool CheckLimits);
	bool __fastcall Clicked(int x, int y);
	bool __fastcall IsDateTime(void);
	void __fastcall SetMinMax(double AMin, double AMax);
	double __fastcall CalcXYIncrement(int MaxLabelSize);
	double __fastcall CalcIncrement(void);
	void __fastcall AdjustMaxMinRect(const Types::TRect &Rect);
	void __fastcall IncDecDateTime(bool Increment, double &Value, const double AnIncrement, Teeprocs::TDateTimeStep tmpWhichDateTime);
	__property bool Horizontal = {read=FHorizontal, write=FHorizontal, nodefault};
	__property bool OtherSide = {read=FOtherSide, write=FOtherSide, nodefault};
	__property int PosAxis = {read=FPosAxis, nodefault};
	__property int PosLabels = {read=FPosLabels, nodefault};
	__property int PosTitle = {read=FPosTitle, nodefault};
	__property TCustomAxisPanel* ParentChart = {read=FParentChart};
	__property bool Automatic = {read=FAutomatic, write=SetAutomatic, default=1};
	__property bool AutomaticMaximum = {read=FAutomaticMaximum, write=SetAutomaticMaximum, default=1};
	__property bool AutomaticMinimum = {read=FAutomaticMinimum, write=SetAutomaticMinimum, default=1};
	__property Tecanvas::TChartAxisPen* Axis = {read=FAxis, write=SetAxis};
	__property AnsiString AxisValuesFormat = {read=FAxisValuesFormat, write=SetValuesFormat, stored=IsAxisValuesFormatStored};
	__property AnsiString DateTimeFormat = {read=FDateTimeFormat, write=SetDateTimeFormat};
	__property bool ExactDateTime = {read=FExactDateTime, write=SetExactDateTime, default=1};
	__property Tecanvas::TDottedGrayPen* Grid = {read=FGrid, write=SetGrid};
	__property bool GridCentered = {read=FGridCentered, write=SetGridCentered, default=0};
	__property double Increment = {read=FDesiredIncrement, write=SetDesiredIncrement};
	__property bool Inverted = {read=FInverted, write=SetInverted, default=0};
	__property bool Labels = {read=FLabels, write=SetLabels, default=1};
	__property int LabelsAngle = {read=FLabelsAngle, write=SetLabelsAngle, default=0};
	__property Graphics::TFont* LabelsFont = {read=FLabelsFont, write=SetLabelsFont, stored=IsFontStored};
	__property bool LabelsMultiLine = {read=FLabelsMultiLine, write=SetLabelsMultiLine, default=0};
	__property bool LabelsOnAxis = {read=FLabelsOnAxis, write=SetLabelsOnAxis, default=1};
	__property int LabelsSeparation = {read=FLabelsSeparation, write=SetLabelsSeparation, default=10};
	__property int LabelsSize = {read=FLabelsSize, write=SetLabelsSize, default=0};
	__property TAxisLabelStyle LabelStyle = {read=FLabelStyle, write=SetLabelStyle, default=0};
	__property bool Logarithmic = {read=FLogarithmic, write=SetLogarithmic, default=0};
	__property int LogarithmicBase = {read=FLogarithmicBase, write=SetLogarithmicBase, default=10};
	__property double Maximum = {read=FMaximumValue, write=SetMaximum, stored=IsMaxStored};
	__property double Minimum = {read=FMinimumValue, write=SetMinimum, stored=IsMinStored};
	__property Tecanvas::TChartHiddenPen* MinorGrid = {read=FMinorGrid, write=SetMinorGrid};
	__property int MinorTickCount = {read=FMinorTickCount, write=SetMinorTickCount, default=3};
	__property int MinorTickLength = {read=FMinorTickLength, write=SetMinorTickLength, default=2};
	__property Tecanvas::TDarkGrayPen* MinorTicks = {read=FMinorTicks, write=SetMinorTicks};
	__property double StartPosition = {read=FStartPosition, write=SetStartPosition, stored=IsStartStored};
	__property double EndPosition = {read=FEndPosition, write=SetEndPosition, stored=IsEndStored};
	__property double PositionPercent = {read=FPositionPercent, write=SetPositionPercent, stored=IsPosStored};
	__property bool RoundFirstLabel = {read=FRoundFirstLabel, write=SetRoundFirstLabel, default=1};
	__property int TickInnerLength = {read=FTickInnerLength, write=SetTickInnerLength, default=0};
	__property int TickLength = {read=FTickLength, write=SetTickLength, default=4};
	__property Tecanvas::TDarkGrayPen* Ticks = {read=FTicks, write=SetTicks};
	__property Tecanvas::TDarkGrayPen* TicksInner = {read=FTicksInner, write=SetTicksInner};
	__property bool TickOnLabelsOnly = {read=FTickOnLabelsOnly, write=SetTickOnLabelsOnly, default=1};
	__property TChartAxisTitle* Title = {read=FAxisTitle, write=SetAxisTitle};
	__property int TitleSize = {read=FTitleSize, write=SetTitleSize, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


class PASCALIMPLEMENTATION TChartDepthAxis : public TCustomChartAxis 
{
	typedef TCustomChartAxis inherited;
	
__published:
	__property Automatic  = {default=1};
	__property AutomaticMaximum  = {default=1};
	__property AutomaticMinimum  = {default=1};
	__property Axis ;
	__property AxisValuesFormat ;
	__property DateTimeFormat ;
	__property ExactDateTime  = {default=1};
	__property Grid ;
	__property Increment ;
	__property Inverted  = {default=0};
	__property Labels  = {default=1};
	__property LabelsAngle  = {default=0};
	__property LabelsFont ;
	__property LabelsMultiLine  = {default=0};
	__property LabelsOnAxis  = {default=1};
	__property LabelsSeparation  = {default=10};
	__property LabelsSize  = {default=0};
	__property LabelStyle  = {default=0};
	__property Logarithmic  = {default=0};
	__property LogarithmicBase  = {default=10};
	__property Maximum ;
	__property Minimum ;
	__property MinorGrid ;
	__property MinorTickCount  = {default=3};
	__property MinorTickLength  = {default=2};
	__property MinorTicks ;
	__property RoundFirstLabel  = {default=1};
	__property TickInnerLength  = {default=0};
	__property TickLength  = {default=4};
	__property TickOnLabelsOnly  = {default=1};
	__property Ticks ;
	__property TicksInner ;
	__property Title ;
	__property TitleSize  = {default=0};
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomChartAxis.Create */ inline __fastcall TChartDepthAxis(TCustomAxisPanel* AOwner) : TCustomChartAxis(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartAxis.Destroy */ inline __fastcall virtual ~TChartDepthAxis(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TAxisOnGetLabel)(TChartAxis* Sender, TChartSeries* Series, int ValueIndex, AnsiString &LabelText);

typedef void __fastcall (__closure *TAxisOnGetNextLabel)(TChartAxis* Sender, int LabelIndex, double &LabelValue, bool &Stop);

class PASCALIMPLEMENTATION TCustomAxisPanel : public Teeprocs::TCustomTeePanelExtended 
{
	typedef Teeprocs::TCustomTeePanelExtended inherited;
	
public:
	TChartSeries* operator[](int Index) { return Series[Index]; }
	
private:
	TChartSeriesList* FSeriesList;
	TChartDepthAxis* FDepthAxis;
	TChartAxis* FTopAxis;
	TChartAxis* FBottomAxis;
	TChartAxis* FLeftAxis;
	TChartAxis* FRightAxis;
	bool FView3DWalls;
	bool FClipPoints;
	bool FAxisVisible;
	TAxisOnGetLabel FOnGetAxisLabel;
	TAxisOnGetNextLabel FOnGetNextAxisLabel;
	Classes::TNotifyEvent FOnPageChange;
	Classes::TNotifyEvent FOnBeforeDrawAxes;
	Classes::TNotifyEvent FOnBeforeDrawSeries;
	int FPage;
	int FMaxPointsPerPage;
	bool FScaleLastPage;
	int FMaxZOrder;
	int FSeriesWidth3D;
	int FSeriesHeight3D;
	void __fastcall CheckOtherSeries(TChartSeries* Dest, TChartSeries* Source);
	TChartSeries* __fastcall GetSeries(int Index);
	void __fastcall InternalAddSeries(TChartSeries* ASeries);
	double __fastcall InternalMinMax(TCustomChartAxis* AAxis, bool IsMin, bool IsX);
	bool __fastcall NoActiveSeries(TCustomChartAxis* AAxis);
	void __fastcall SetAxisVisible(bool Value);
	void __fastcall SetBottomAxis(TChartAxis* Value);
	void __fastcall SetClipPoints(bool Value);
	void __fastcall SetDepthAxis(TChartDepthAxis* Value);
	void __fastcall SetLeftAxis(TChartAxis* Value);
	void __fastcall SetMaxPointsPerPage(int Value);
	void __fastcall SetRightAxis(TChartAxis* Value);
	void __fastcall SetScaleLastPage(bool Value);
	void __fastcall SetTopAxis(TChartAxis* Value);
	void __fastcall SetView3DWalls(bool Value);
	
protected:
	Classes::TList* FAxes;
	virtual void __fastcall CalcAxisRect(void) = 0 ;
	virtual void __fastcall CalcSeriesRect(void) = 0 ;
	virtual int __fastcall CalcWallSize(TCustomChartAxis* Axis) = 0 ;
	virtual void __fastcall DrawTitlesAndLegend(void) = 0 ;
	virtual void __fastcall DrawWalls(void) = 0 ;
	bool __fastcall IsAxisVisible(TCustomChartAxis* Axis);
	DYNAMIC void __fastcall RemovedDataSource(TChartSeries* ASeries, Classes::TComponent* AComponent);
	virtual void __fastcall SetPage(int Value);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	
public:
	Graphics::TColor LegendColor;
	__fastcall virtual TCustomAxisPanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAxisPanel(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TChartSeries* __fastcall ActiveSeriesLegend(int ItemIndex);
	void __fastcall AddSeries(TChartSeries* ASeries);
	void __fastcall CalcSize3DWalls(void);
	virtual void __fastcall CheckDatasource(TChartSeries* ASeries);
	virtual AnsiString __fastcall FormattedValueLegend(TChartSeries* ASeries, int ValueIndex);
	void __fastcall FreeAllSeries(void);
	TChartSeries* __fastcall GetAxisSeries(TCustomChartAxis* Axis);
	Graphics::TColor __fastcall GetFreeSeriesColor(bool CheckBackground);
	int __fastcall GetMaxValuesCount(void);
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
	virtual bool __fastcall IsFreeSeriesColor(Graphics::TColor AColor, bool CheckBackground) = 0 ;
	virtual bool __fastcall IsValidDataSource(TChartSeries* ASeries, Classes::TComponent* AComponent);
	double __fastcall MaxXValue(TChartAxis* AAxis);
	double __fastcall MaxYValue(TChartAxis* AAxis);
	double __fastcall MinXValue(TChartAxis* AAxis);
	double __fastcall MinYValue(TChartAxis* AAxis);
	int __fastcall MaxMarkWidth(void);
	int __fastcall MaxTextWidth(void);
	DYNAMIC int __fastcall NumPages(void);
	void __fastcall RemoveSeries(TChartSeries* ASeries);
	__property TChartSeries* Series[int Index] = {read=GetSeries/*, default*/};
	int __fastcall SeriesCount(void);
	AnsiString __fastcall SeriesTitleLegend(int SeriesIndex);
	__property Classes::TList* AxesList = {read=FAxes};
	__property int MaxZOrder = {read=FMaxZOrder, write=FMaxZOrder, nodefault};
	__property int SeriesWidth3D = {read=FSeriesWidth3D, nodefault};
	__property int SeriesHeight3D = {read=FSeriesHeight3D, nodefault};
	__property bool AxisVisible = {read=FAxisVisible, write=SetAxisVisible, default=1};
	__property TChartAxis* BottomAxis = {read=FBottomAxis, write=SetBottomAxis};
	__property bool ClipPoints = {read=FClipPoints, write=SetClipPoints, default=1};
	__property Color  = {default=-2147483633};
	__property TChartDepthAxis* DepthAxis = {read=FDepthAxis, write=SetDepthAxis};
	__property TChartAxis* LeftAxis = {read=FLeftAxis, write=SetLeftAxis};
	__property int MaxPointsPerPage = {read=FMaxPointsPerPage, write=SetMaxPointsPerPage, default=0};
	__property int Page = {read=FPage, write=SetPage, default=1};
	__property TChartAxis* RightAxis = {read=FRightAxis, write=SetRightAxis};
	__property bool ScaleLastPage = {read=FScaleLastPage, write=SetScaleLastPage, default=1};
	__property TChartSeriesList* SeriesList = {read=FSeriesList};
	__property TChartAxis* TopAxis = {read=FTopAxis, write=SetTopAxis};
	__property bool View3DWalls = {read=FView3DWalls, write=SetView3DWalls, default=1};
	__property Classes::TNotifyEvent OnBeforeDrawAxes = {read=FOnBeforeDrawAxes, write=FOnBeforeDrawAxes};
	__property Classes::TNotifyEvent OnBeforeDrawSeries = {read=FOnBeforeDrawSeries, write=FOnBeforeDrawSeries};
	__property TAxisOnGetLabel OnGetAxisLabel = {read=FOnGetAxisLabel, write=FOnGetAxisLabel};
	__property TAxisOnGetNextLabel OnGetNextAxisLabel = {read=FOnGetNextAxisLabel, write=FOnGetNextAxisLabel};
	__property Classes::TNotifyEvent OnPageChange = {read=FOnPageChange, write=FOnPageChange};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomAxisPanel(HWND ParentWindow) : Teeprocs::TCustomTeePanelExtended(ParentWindow) { }
	#pragma option pop
	
};



class PASCALIMPLEMENTATION TChartAxis : public TCustomChartAxis 
{
	typedef TCustomChartAxis inherited;
	
__published:
	__property Automatic  = {default=1};
	__property AutomaticMaximum  = {default=1};
	__property AutomaticMinimum  = {default=1};
	__property Axis ;
	__property AxisValuesFormat ;
	__property DateTimeFormat ;
	__property ExactDateTime  = {default=1};
	__property Grid ;
	__property GridCentered  = {default=0};
	__property Increment ;
	__property Inverted  = {default=0};
	__property Labels  = {default=1};
	__property LabelsAngle  = {default=0};
	__property LabelsFont ;
	__property LabelsMultiLine  = {default=0};
	__property LabelsOnAxis  = {default=1};
	__property LabelsSeparation  = {default=10};
	__property LabelsSize  = {default=0};
	__property LabelStyle  = {default=0};
	__property Logarithmic  = {default=0};
	__property LogarithmicBase  = {default=10};
	__property Maximum ;
	__property Minimum ;
	__property MinorGrid ;
	__property MinorTickCount  = {default=3};
	__property MinorTickLength  = {default=2};
	__property MinorTicks ;
	__property StartPosition ;
	__property EndPosition ;
	__property PositionPercent ;
	__property RoundFirstLabel  = {default=1};
	__property TickInnerLength  = {default=0};
	__property TickLength  = {default=4};
	__property TickOnLabelsOnly  = {default=1};
	__property Ticks ;
	__property TicksInner ;
	__property Title ;
	__property TitleSize  = {default=0};
	__property Visible  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomChartAxis.Create */ inline __fastcall TChartAxis(TCustomAxisPanel* AOwner) : TCustomChartAxis(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomChartAxis.Destroy */ inline __fastcall virtual ~TChartAxis(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSeriesMarks;
class DELPHICLASS TSeriesMarksPositions;
class DELPHICLASS TSeriesMarkPosition;
class PASCALIMPLEMENTATION TSeriesMarksPositions : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TSeriesMarkPosition* operator[](int Index) { return Position[Index]; }
	
private:
	void __fastcall SetPosition(int Index, TSeriesMarkPosition* APosition);
	TSeriesMarkPosition* __fastcall GetPosition(int Index);
	
public:
	void __fastcall Automatic(int Index);
	__property TSeriesMarkPosition* Position[int Index] = {read=GetPosition, write=SetPosition/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TSeriesMarksPositions(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSeriesMarksPositions(void) : Classes::TList() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TSeriesMarks : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Tecanvas::TChartArrowPen* FArrow;
	int FArrowLength;
	Graphics::TColor FBackColor;
	bool FBackTransparent;
	bool FClip;
	Tecanvas::TChartPen* FFrame;
	Graphics::TFont* FFont;
	TSeriesMarksStyle FMarkerStyle;
	TChartSeries* FParent;
	TSeriesMarksPositions* FPositions;
	bool FVisible;
	int FZPosition;
	void __fastcall SetStyle(TSeriesMarksStyle Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall SetClip(bool Value);
	void __fastcall SetFrame(Tecanvas::TChartPen* Value);
	void __fastcall SetArrow(Tecanvas::TChartArrowPen* Value);
	void __fastcall SetArrowLength(int Value);
	bool __fastcall IsFontStored(void);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetBackColor(Graphics::TColor Value);
	void __fastcall SetBackTransparent(bool Value);
	
protected:
	void __fastcall ClearPositions(void);
	void __fastcall UsePosition(int Index, TSeriesMarkPosition* &MarkPosition);
	
public:
	__fastcall TSeriesMarks(TChartSeries* AOwner);
	__fastcall virtual ~TSeriesMarks(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall Clicked(int X, int Y);
	void __fastcall Draw(int Index, Graphics::TColor AColor, const AnsiString St, TSeriesMarkPosition* APosition);
	__property TChartSeries* ParentSeries = {read=FParent};
	__property TSeriesMarksPositions* Positions = {read=FPositions};
	__property int ZPosition = {read=FZPosition, write=FZPosition, nodefault};
	
__published:
	__property Tecanvas::TChartArrowPen* Arrow = {read=FArrow, write=SetArrow};
	__property int ArrowLength = {read=FArrowLength, write=SetArrowLength, nodefault};
	__property Graphics::TColor BackColor = {read=FBackColor, write=SetBackColor, default=8454143};
	__property bool Clip = {read=FClip, write=SetClip, default=0};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property Tecanvas::TChartPen* Frame = {read=FFrame, write=SetFrame};
	__property TSeriesMarksStyle Style = {read=FMarkerStyle, write=SetStyle, default=2};
	__property bool Transparent = {read=FBackTransparent, write=SetBackTransparent, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
};


class DELPHICLASS TChartValueLists;
class PASCALIMPLEMENTATION TChartValueLists : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	TChartValueList* operator[](int Index) { return ValueList[Index]; }
	
private:
	TChartValueList* __fastcall GetValueList(int Index);
	
public:
	__property TChartValueList* ValueList[int Index] = {read=GetValueList/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TChartValueLists(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChartValueLists(void) : Classes::TList() { }
	#pragma option pop
	
};


#pragma option push -b-
enum THorizAxis { aTopAxis, aBottomAxis, aBothHorizAxis, aCustomHorizAxis };
#pragma option pop

#pragma option push -b-
enum TVertAxis { aLeftAxis, aRightAxis, aBothVertAxis, aCustomVertAxis };
#pragma option pop

#pragma option push -b-
enum TeEngine__21 { rOnDelete, rOnModify, rOnInsert, rOnClear };
#pragma option pop

typedef Set<TeEngine__21, rOnDelete, rOnClear>  TSeriesRecalcOptions;

class DELPHICLASS TTeeFunction;
#pragma option push -b-
enum TFunctionPeriodStyle { psNumPoints, psRange };
#pragma option pop

#pragma option push -b-
enum TFunctionPeriodAlign { paFirst, paCenter, paLast };
#pragma option pop

class PASCALIMPLEMENTATION TTeeFunction : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	double FPeriod;
	TFunctionPeriodStyle FPeriodStyle;
	TFunctionPeriodAlign FPeriodAlign;
	TChartSeries* FParent;
	bool FUpdating;
	void __fastcall SetPeriod(const double Value);
	void __fastcall SetParentSeries(TChartSeries* AParent);
	void __fastcall SetPeriodAlign(TFunctionPeriodAlign Value);
	void __fastcall SetPeriodStyle(TFunctionPeriodStyle Value);
	
protected:
	bool CanUsePeriod;
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
	void __fastcall InternalSetPeriod(const double APeriod);
	void __fastcall AddFunctionXY(bool YMandatorySource, double tmpX, double tmpY);
	virtual void __fastcall CalculatePeriod(TChartSeries* Source, const double tmpX, int FirstIndex, int LastIndex);
	virtual void __fastcall CalculateAllPoints(TChartSeries* Source, TChartValueList* NotMandatorySource);
	virtual void __fastcall CalculateByPeriod(TChartSeries* Source, TChartValueList* NotMandatorySource);
	TChartValueList* __fastcall ValueList(TChartSeries* ASeries);
	
public:
	bool MovingFunction;
	__fastcall virtual TTeeFunction(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall ReCalculate(void);
	virtual double __fastcall Calculate(TChartSeries* Series, int First, int Last);
	virtual double __fastcall CalculateMany(Classes::TList* SeriesList, int ValueIndex);
	virtual void __fastcall AddPoints(TChartSeries* Source);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	__property TChartSeries* ParentSeries = {read=FParent, write=SetParentSeries};
	
__published:
	__property double Period = {read=FPeriod, write=SetPeriod};
	__property TFunctionPeriodAlign PeriodAlign = {read=FPeriodAlign, write=SetPeriodAlign, default=1};
	__property TFunctionPeriodStyle PeriodStyle = {read=FPeriodStyle, write=SetPeriodStyle, default=0};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TTeeFunction(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TeEngine__51 { tssIsTemplate, tssDenyChangeType, tssDenyDelete, tssDenyClone, tssIsPersistent, tssHideDataSource };
#pragma option pop

typedef Set<TeEngine__51, tssIsTemplate, tssHideDataSource>  TChartSeriesStyle;

typedef void __fastcall (__closure *TSeriesOnAfterAdd)(TChartSeries* Sender, int ValueIndex);

typedef bool __fastcall (__closure *TSeriesOnBeforeAdd)(TChartSeries* Sender);

typedef void __fastcall (__closure *TSeriesOnClear)(TChartSeries* Sender);

typedef void __fastcall (__closure *TSeriesClick)(TChartSeries* Sender, int ValueIndex, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TSeriesOnGetMarkText)(TChartSeries* Sender, int ValueIndex, AnsiString &MarkText);

#pragma option push -b-
enum TValueEvent { veClear, veAdd, veDelete, veRefresh, veModify };
#pragma option pop

#pragma option push -b-
enum TLegendTextStyle { ltsPlain, ltsLeftValue, ltsRightValue, ltsLeftPercent, ltsRightPercent, ltsXValue };
#pragma option pop

class PASCALIMPLEMENTATION TChartSeries : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FActive;
	Graphics::TColor FColor;
	bool FColorEachPoint;
	Classes::TList* FColors;
	AnsiString FColorSource;
	Controls::TCursor FCursor;
	Classes::TList* FDataSources;
	int FFirstVisibleIndex;
	TChartAxis* FGetHorizAxis;
	TChartAxis* FGetVertAxis;
	AnsiString FLabelsSource;
	int FLastVisibleIndex;
	Classes::TList* FLinkedSeries;
	TSeriesMarks* FMarks;
	TCustomAxisPanel* FParent;
	AnsiString FPercentFormat;
	bool FShowInLegend;
	Classes::TStringList* FTempDataSources;
	AnsiString FTitle;
	AnsiString FValueFormat;
	TChartValueLists* FValuesList;
	TChartValueList* FX;
	Classes::TList* FXLabels;
	TChartValueList* FY;
	THorizAxis FHorizAxis;
	TChartAxis* FCustomHorizAxis;
	TChartAxis* FCustomVertAxis;
	int FZOrder;
	TVertAxis FVertAxis;
	TSeriesRecalcOptions FRecalcOptions;
	TTeeFunction* FTeeFunction;
	TChartSeriesStyle FStyle;
	Classes::TNotifyEvent FAfterDrawValues;
	Classes::TNotifyEvent FBeforeDrawValues;
	TSeriesOnAfterAdd FOnAfterAdd;
	TSeriesOnBeforeAdd FOnBeforeAdd;
	TSeriesOnClear FOnClearValues;
	TSeriesClick FOnClick;
	TSeriesClick FOnDblClick;
	TSeriesOnGetMarkText FOnGetMarkText;
	AnsiString FIdentifier;
	void __fastcall InsertLabel(int ValueIndex, const AnsiString ALabel);
	char * __fastcall GetMemLabel(const AnsiString ALabel);
	void __fastcall FreeXLabel(int ValueIndex);
	double __fastcall GetValue(bool IsX, int ValueIndex);
	void __fastcall ReadData(Classes::TReader* Reader);
	void __fastcall WriteData(Classes::TWriter* Writer);
	void __fastcall ReadIdentifier(Classes::TReader* Reader);
	void __fastcall WriteIdentifier(Classes::TWriter* Writer);
	void __fastcall ReadStyle(Classes::TReader* Reader);
	void __fastcall WriteStyle(Classes::TWriter* Writer);
	void __fastcall InternalAddDataSource(Classes::TComponent* Value);
	void __fastcall RemoveAllLinkedSeries(void);
	void __fastcall SetTitle(AnsiString Value);
	void __fastcall SetValueFormat(const AnsiString Value);
	void __fastcall SetPercentFormat(const AnsiString Value);
	bool __fastcall IsValueFormatStored(void);
	bool __fastcall IsPercentFormatStored(void);
	void __fastcall SetHorizAxis(THorizAxis Value);
	void __fastcall SetVertAxis(TVertAxis Value);
	void __fastcall SetColorSource(const AnsiString Value);
	void __fastcall SetLabelsSource(const AnsiString Value);
	void __fastcall SetShowInLegend(bool Value);
	void __fastcall SetCustomHorizAxis(TChartAxis* Value);
	void __fastcall SetCustomVertAxis(TChartAxis* Value);
	int __fastcall GetZOrder(void);
	void __fastcall SetZOrder(int Value);
	void __fastcall RecalcGetAxis(void);
	
protected:
	int IZOrder;
	virtual int __fastcall AddChartValue(TChartSeries* Source, int ValueIndex);
	virtual void __fastcall AddedValue(TChartSeries* Source, int ValueIndex);
	virtual void __fastcall AddValues(TChartSeries* Source);
	virtual void __fastcall ClearLists(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DeletedValue(TChartSeries* Source, int ValueIndex);
	virtual void __fastcall DoAfterDrawValues(void);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, TSeriesMarkPosition* APosition);
	void __fastcall DrawMarks(void);
	virtual void __fastcall DrawValue(int ValueIndex);
	bool __fastcall FirstInZOrder(void);
	Classes::TComponent* __fastcall GetDataSource(void);
	AnsiString __fastcall GetMarkText(int ValueIndex);
	virtual Graphics::TColor __fastcall GetValueColor(int ValueIndex);
	virtual AnsiString __fastcall GetXLabel(int Index);
	virtual double __fastcall GetxValue(int Index);
	virtual double __fastcall GetyValue(int Index);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall NotifyNewValue(TChartSeries* Sender, int ValueIndex);
	void __fastcall NotifyValue(TValueEvent ValueEvent, int ValueIndex);
	virtual bool __fastcall MoreSameZOrder(void);
	virtual void __fastcall SetActive(bool Value);
	void __fastcall SetChartValueList(TChartValueList* &AValueList, TChartValueList* Value);
	virtual void __fastcall SetColorEachPoint(bool Value);
	void __fastcall SetDataSource(Classes::TComponent* Value);
	void __fastcall SetMarks(TSeriesMarks* Value);
	virtual void __fastcall SetParentChart(TCustomAxisPanel* Value);
	void __fastcall SetRecalcOptions(TSeriesRecalcOptions Value);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	void __fastcall SetValueColor(int ValueIndex, Graphics::TColor AColor);
	void __fastcall SetXLabel(int Index, const AnsiString AXLabel);
	void __fastcall SetXValue(int Index, const double Value);
	void __fastcall SetYValue(int Index, const double Value);
	void __fastcall SetXValues(TChartValueList* Value);
	void __fastcall SetYValues(TChartValueList* Value);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	
public:
	bool CalcVisiblePoints;
	bool DrawBetweenPoints;
	bool AllowSinglePoint;
	bool HasZValues;
	int StartZ;
	int MiddleZ;
	int EndZ;
	__fastcall virtual TChartSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TChartSeries(void);
	virtual int __fastcall Add(const double AValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	int __fastcall AddArray(const double * Values, const int Values_Size);
	void __fastcall AddLinkedSeries(TChartSeries* ASeries);
	virtual int __fastcall AddNull(const AnsiString ALabel = "");
	virtual int __fastcall AddNullXY(const double X, const double Y, const AnsiString ALabel);
	int __fastcall AddX(const double AXValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual int __fastcall AddXY(const double AXValue, const double AYValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	int __fastcall AddY(const double AYValue, const AnsiString ALabel = "", Graphics::TColor AColor = (Graphics::TColor)(0x20000000));
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall AssociatedToAxis(TCustomChartAxis* Axis);
	void __fastcall CalcRandomBounds(int NumValues, double &tmpX, double &StepX, double &tmpY, double &MinY, double &DifY);
	virtual void __fastcall Clear(void);
	int __fastcall Count(void);
	virtual int __fastcall CountLegendItems(void);
	virtual void __fastcall Delete(int ValueIndex);
	virtual void __fastcall FillSampleValues(int NumValues);
	virtual void __fastcall GalleryChanged3D(bool Is3D);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	bool __fastcall IsNull(int ValueIndex);
	virtual bool __fastcall IsValidSourceOf(TChartSeries* Value);
	virtual bool __fastcall IsValidSeriesSource(TChartSeries* Value);
	virtual int __fastcall LegendToValueIndex(int LegendIndex);
	virtual Graphics::TColor __fastcall LegendItemColor(int LegendIndex);
	virtual AnsiString __fastcall LegendString(int LegendIndex, TLegendTextStyle LegendTextStyle);
	__property Classes::TList* LinkedSeries = {read=FLinkedSeries};
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MaxZValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MinYValue(void);
	virtual double __fastcall MinZValue(void);
	virtual int __fastcall NumSampleValues(void);
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	void __fastcall RemoveDataSource(Classes::TComponent* Value);
	void __fastcall RemoveLinkedSeries(TChartSeries* ASeries);
	void __fastcall Repaint(void);
	int __fastcall VisibleCount(void);
	__property TChartValueLists* ValuesLists = {read=FValuesList};
	__property double XValue[int Index] = {read=GetxValue, write=SetXValue};
	__property double YValue[int Index] = {read=GetyValue, write=SetYValue};
	__property int ZOrder = {read=GetZOrder, write=SetZOrder, default=-1};
	int __fastcall MaxMarkWidth(void);
	virtual AnsiString __fastcall GetEditorClass();
	virtual int __fastcall CalcXPos(int ValueIndex);
	int __fastcall CalcXPosValue(const double Value);
	int __fastcall CalcXSizeValue(const double Value);
	virtual int __fastcall CalcYPos(int ValueIndex);
	int __fastcall CalcYPosValue(const double Value);
	int __fastcall CalcYSizeValue(const double Value);
	int __fastcall CalcPosValue(const double Value);
	double __fastcall XScreenToValue(int ScreenPos);
	double __fastcall YScreenToValue(int ScreenPos);
	AnsiString __fastcall XValueToText(const double AValue);
	AnsiString __fastcall YValueToText(const double AValue);
	void __fastcall ColorRange(TChartValueList* AValueList, const double FromValue, const double ToValue, Graphics::TColor AColor);
	void __fastcall CheckDataSource(void);
	virtual void __fastcall AddValue(int ValueIndex);
	__property Classes::TList* Labels = {read=FXLabels};
	__property AnsiString XLabel[int Index] = {read=GetXLabel, write=SetXLabel};
	__property AnsiString ValueMarkText[int Index] = {read=GetMarkText};
	__property Graphics::TColor ValueColor[int Index] = {read=GetValueColor, write=SetValueColor};
	__property TChartValueList* XValues = {read=FX, write=SetXValues};
	__property TChartValueList* YValues = {read=FY, write=SetYValues};
	virtual TChartValueList* __fastcall GetYValueList(AnsiString AListName);
	__property TChartAxis* GetVertAxis = {read=FGetVertAxis};
	__property TChartAxis* GetHorizAxis = {read=FGetHorizAxis};
	AnsiString __fastcall MarkPercent(int ValueIndex, bool AddTotal);
	virtual int __fastcall Clicked(int x, int y);
	void __fastcall RefreshSeries(void);
	__property int FirstValueIndex = {read=FFirstVisibleIndex, nodefault};
	__property int LastValueIndex = {read=FLastVisibleIndex, nodefault};
	virtual double __fastcall GetOriginValue(int ValueIndex);
	virtual double __fastcall GetMarkValue(int ValueIndex);
	void __fastcall AssignValues(TChartSeries* Source);
	bool __fastcall SameClass(TChartSeries* tmpSeries);
	virtual double __fastcall PointOrigin(int ValueIndex, bool SumAll);
	bool __fastcall YMandatory(void);
	virtual TChartValueList* __fastcall MandatoryValueList(void);
	virtual bool __fastcall DrawValuesForward(void);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	virtual void __fastcall SwapValueIndex(int a, int b);
	__property TSeriesRecalcOptions RecalcOptions = {read=FRecalcOptions, write=SetRecalcOptions, default=15};
	virtual void __fastcall CalcZOrder(void);
	virtual void __fastcall DoSeriesMouseMove(Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall DoSeriesClick(TChartSeries* Sender, int ValueIndex, Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoSeriesMouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	int __fastcall GetCursorValueIndex(void);
	void __fastcall GetCursorValues(double &x, double &y);
	virtual void __fastcall ClearTempValue(TChartValueList* ValueList);
	virtual void __fastcall DrawLegend(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual bool __fastcall UseAxis(void);
	virtual void __fastcall SetFunction(TTeeFunction* AFunction);
	void __fastcall CalcFirstLastVisibleIndex(void);
	Tecanvas::TChartPen* __fastcall CreateChartPen(void);
	virtual void __fastcall CanvasChanged(System::TObject* Sender);
	__property Classes::TList* DataSources = {read=FDataSources};
	__property TTeeFunction* FunctionType = {read=FTeeFunction};
	void __fastcall SetLongintProperty(int &Variable, int Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	void __fastcall SetStringProperty(AnsiString &Variable, const AnsiString Value);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetColorProperty(Graphics::TColor &Variable, Graphics::TColor Value);
	void __fastcall SetDoubleProperty(double &Variable, const double Value);
	void __fastcall CheckOtherSeries(TChartSeries* Source);
	virtual void __fastcall GetBitmapEditor(Graphics::TBitmap* ABitmap);
	void __fastcall ReplaceList(TChartValueList* OldList, TChartValueList* NewList);
	__property AnsiString Identifier = {read=FIdentifier, write=FIdentifier};
	__property TChartSeriesStyle Style = {read=FStyle, write=FStyle, default=0};
	__property TChartAxis* CustomHorizAxis = {read=FCustomHorizAxis, write=SetCustomHorizAxis};
	__property TChartAxis* CustomVertAxis = {read=FCustomVertAxis, write=SetCustomVertAxis};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=1};
	__property bool ColorEachPoint = {read=FColorEachPoint, write=SetColorEachPoint, default=0};
	__property AnsiString ColorSource = {read=FColorSource, write=SetColorSource};
	__property Controls::TCursor Cursor = {read=FCursor, write=FCursor, default=0};
	__property THorizAxis HorizAxis = {read=FHorizAxis, write=SetHorizAxis, default=1};
	__property TSeriesMarks* Marks = {read=FMarks, write=SetMarks};
	__property TCustomAxisPanel* ParentChart = {read=FParent, write=SetParentChart, stored=false};
	__property Classes::TComponent* DataSource = {read=GetDataSource, write=SetDataSource};
	__property AnsiString PercentFormat = {read=FPercentFormat, write=SetPercentFormat, stored=IsPercentFormatStored};
	__property Graphics::TColor SeriesColor = {read=FColor, write=SetSeriesColor, default=536870912};
	__property bool ShowInLegend = {read=FShowInLegend, write=SetShowInLegend, default=1};
	__property AnsiString Title = {read=FTitle, write=SetTitle};
	__property AnsiString ValueFormat = {read=FValueFormat, write=SetValueFormat, stored=IsValueFormatStored};
	__property TVertAxis VertAxis = {read=FVertAxis, write=SetVertAxis, default=0};
	__property AnsiString XLabelsSource = {read=FLabelsSource, write=SetLabelsSource};
	__property Classes::TNotifyEvent AfterDrawValues = {read=FAfterDrawValues, write=FAfterDrawValues};
	__property Classes::TNotifyEvent BeforeDrawValues = {read=FBeforeDrawValues, write=FBeforeDrawValues};
	__property TSeriesOnAfterAdd OnAfterAdd = {read=FOnAfterAdd, write=FOnAfterAdd};
	__property TSeriesOnBeforeAdd OnBeforeAdd = {read=FOnBeforeAdd, write=FOnBeforeAdd};
	__property TSeriesOnClear OnClearValues = {read=FOnClearValues, write=FOnClearValues};
	__property TSeriesClick OnClick = {read=FOnClick, write=FOnClick};
	__property TSeriesClick OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property TSeriesOnGetMarkText OnGetMarkText = {read=FOnGetMarkText, write=FOnGetMarkText};
};


class PASCALIMPLEMENTATION TChartValueList : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	double operator[](int Index) { return Value[Index]; }
	
private:
	bool FDateTime;
	Classes::TList* FList;
	double FMaxValue;
	double FMinValue;
	double FMultiplier;
	AnsiString FName;
	TChartListOrder FOrder;
	TChartSeries* FOwner;
	double FTempValue;
	double FTotal;
	double FTotalABS;
	AnsiString FValueSource;
	double __fastcall GetMaxValue(void);
	double __fastcall GetMinValue(void);
	double __fastcall GetTotal(void);
	double __fastcall GetTotalABS(void);
	void __fastcall SetDateTime(bool Value);
	void __fastcall SetMultiplier(const double Value);
	void __fastcall SetValueSource(const AnsiString Value);
	
protected:
	bool IDirtyStats;
	virtual double __fastcall GetValue(int ValueIndex);
	virtual void __fastcall SetValue(int ValueIndex, const double AValue);
	virtual void __fastcall ClearValues(void);
	void __fastcall RecalcStats(void);
	virtual int __fastcall AddChartValue(const double Value);
	virtual void __fastcall InsertChartValue(int ValueIndex, const double Value);
	
public:
	__fastcall virtual TChartValueList(TChartSeries* AOwner, const AnsiString AName);
	__fastcall virtual ~TChartValueList(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Count(void);
	virtual void __fastcall Delete(int ValueIndex);
	void __fastcall FillSequence(void);
	double __fastcall First(void);
	double __fastcall Last(void);
	int __fastcall Locate(const double Value);
	virtual void __fastcall Scroll(void);
	void __fastcall Sort(void);
	__property double MaxValue = {read=GetMaxValue};
	__property double MinValue = {read=GetMinValue};
	__property TChartSeries* Owner = {read=FOwner};
	__property double TempValue = {read=FTempValue, write=FTempValue};
	__property double Total = {read=GetTotal};
	__property double TotalABS = {read=GetTotalABS, write=FTotalABS};
	__property double Value[int Index] = {read=GetValue, write=SetValue/*, default*/};
	
__published:
	__property bool DateTime = {read=FDateTime, write=SetDateTime, nodefault};
	__property AnsiString Name = {read=FName, write=FName};
	__property double Multiplier = {read=FMultiplier, write=SetMultiplier};
	__property TChartListOrder Order = {read=FOrder, write=FOrder, nodefault};
	__property AnsiString ValueSource = {read=FValueSource, write=SetValueSource};
};


class DELPHICLASS AxisException;
class PASCALIMPLEMENTATION AxisException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall AxisException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall AxisException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall AxisException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall AxisException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall AxisException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall AxisException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall AxisException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall AxisException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~AxisException(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TSeriesMouseMove)(TChartSeries* Sender, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TSeriesDblClick)(TChartSeries* Sender, int ValueIndex);

#pragma option push -b-
enum TChartClickedPartStyle { cpNone, cpLegend, cpAxis, cpSeries, cpTitle, cpFoot, cpChartRect };
#pragma option pop

#pragma pack(push, 1)
struct TChartClickedPart
{
	TChartClickedPartStyle Part;
	int PointIndex;
	TChartSeries* ASeries;
	TCustomChartAxis* AAxis;
} ;
#pragma pack(pop)

class PASCALIMPLEMENTATION TSeriesMarkPosition : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma pack(push, 1)
	Types::TPoint ArrowFrom;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint ArrowTo;
	#pragma pack(pop)
	
	bool Custom;
	int Height;
	#pragma pack(push, 1)
	Types::TPoint LeftTop;
	#pragma pack(pop)
	
	int Width;
	void __fastcall Assign(TSeriesMarkPosition* Source);
	Types::TRect __fastcall Bounds();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSeriesMarkPosition(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSeriesMarkPosition(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TChartSeriesClass;

typedef TMetaClass*TTeeFunctionClass;

//-- var, const, procedure ---------------------------------------------------
static const int ChartMarkColor = 0x80ffff;
static const Shortint TeeAllValues = 0xffffffff;
static const int clTeeColor = 0x20000000;
static const Word ChartSamplesMax = 0x3e8;
static const Shortint TeeAutoZOrder = 0xffffffff;
static const Shortint TeeNoPointClicked = 0xffffffff;
static const Word TeeMaxAxisTicks = 0x7d0;
extern PACKAGE bool TeeDrawAxisBeforeSeries;
extern PACKAGE bool TeeCheckMarkArrowColor;
extern PACKAGE int TeeAxisClickGap;
extern PACKAGE int TeeDefaultCapacity;

}	/* namespace Teengine */
using namespace Teengine;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeEngine
