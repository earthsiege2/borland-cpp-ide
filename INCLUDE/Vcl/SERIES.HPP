// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Series.pas' rev: 6.00

#ifndef SeriesHPP
#define SeriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TeeProcs.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Series
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSeriesPointerStyle { psRectangle, psCircle, psTriangle, psDownTriangle, psCross, psDiagCross, psStar, psDiamond, psSmallDot };
#pragma option pop

typedef TSeriesPointerStyle __fastcall (__closure *TOnGetPointerStyle)(Teengine::TChartSeries* Sender, int ValueIndex);

class DELPHICLASS TSeriesPointer;
class PASCALIMPLEMENTATION TSeriesPointer : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FDark3D;
	bool FDraw3D;
	Chart::TChartBrush* FBrush;
	int FHorizSize;
	bool FInflateMargins;
	Teengine::TChartSeries* FOwner;
	Tecanvas::TChartPen* FPen;
	TSeriesPointerStyle FStyle;
	int FVertSize;
	bool FVisible;
	void __fastcall CheckPointerSize(int Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetDraw3D(bool Value);
	void __fastcall SetBrush(Chart::TChartBrush* Value);
	void __fastcall SetHorizSize(int Value);
	void __fastcall SetInflateMargins(bool Value);
	void __fastcall SetPen(Tecanvas::TChartPen* Value);
	void __fastcall SetStyle(TSeriesPointerStyle Value);
	void __fastcall SetVertSize(int Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	
public:
	bool AllowChangeSize;
	__fastcall TSeriesPointer(Teengine::TChartSeries* AOwner);
	__fastcall virtual ~TSeriesPointer(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	void __fastcall Change3D(bool Value);
	void __fastcall ChangeHorizSize(int NewSize);
	void __fastcall ChangeStyle(TSeriesPointerStyle NewStyle);
	void __fastcall ChangeVertSize(int NewSize);
	void __fastcall Draw(int px, int py, Graphics::TColor ColorValue, TSeriesPointerStyle AStyle);
	void __fastcall DrawLegendShape(Graphics::TColor AColor, const Types::TRect &Rect, bool DrawPen);
	void __fastcall DrawPointer(bool Is3D, int px, int py, int tmpHoriz, int tmpVert, Graphics::TColor ColorValue, TSeriesPointerStyle AStyle);
	void __fastcall PrepareCanvas(Graphics::TColor ColorValue);
	__property Teengine::TChartSeries* ParentSeries = {read=FOwner};
	
__published:
	__property Chart::TChartBrush* Brush = {read=FBrush, write=SetBrush};
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property bool Draw3D = {read=FDraw3D, write=SetDraw3D, default=1};
	__property int HorizSize = {read=FHorizSize, write=SetHorizSize, default=4};
	__property bool InflateMargins = {read=FInflateMargins, write=SetInflateMargins, nodefault};
	__property Tecanvas::TChartPen* Pen = {read=FPen, write=SetPen};
	__property TSeriesPointerStyle Style = {read=FStyle, write=SetStyle, nodefault};
	__property int VertSize = {read=FVertSize, write=SetVertSize, default=4};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
};


class DELPHICLASS TCustomSeries;
typedef void __fastcall (__closure *TSeriesClickPointerEvent)(TCustomSeries* Sender, int ValueIndex, int X, int Y);

class PASCALIMPLEMENTATION TCustomSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	Graphics::TBrushStyle FAreaBrush;
	Graphics::TColor FAreaColor;
	Tecanvas::TChartPen* FAreaLinesPen;
	bool FClickableLine;
	bool FDark3D;
	bool FDrawArea;
	bool FDrawLine;
	bool FInvertedStairs;
	Graphics::TBrushStyle FLineBrush;
	int FLineHeight;
	Tecanvas::TChartPen* FLinePen;
	TSeriesPointer* FPointer;
	bool FStairs;
	TSeriesClickPointerEvent FOnClickPointer;
	TOnGetPointerStyle FOnGetPointerStyle;
	int BottomPos;
	int OldBottomPos;
	int OldX;
	int OldY;
	Graphics::TColor OldColor;
	double tmpDark3DRatio;
	void __fastcall SetAreaBrush(Graphics::TBrushStyle Value);
	void __fastcall SetAreaColor(Graphics::TColor Value);
	void __fastcall SetAreaLinesPen(Tecanvas::TChartPen* Value);
	void __fastcall SetBrushProperty(Graphics::TBrushStyle &ABrush, Graphics::TBrushStyle Value);
	void __fastcall SetDark3D(bool Value);
	void __fastcall SetDrawArea(bool Value);
	void __fastcall SetInvertedStairs(bool Value);
	void __fastcall SetLineBrush(Graphics::TBrushStyle Value);
	void __fastcall SetLineHeight(int Value);
	void __fastcall SetLinePen(Tecanvas::TChartPen* Value);
	void __fastcall SetPointer(TSeriesPointer* Value);
	void __fastcall SetStairs(bool Value);
	
protected:
	virtual bool __fastcall ClickedPointer(int ValueIndex, int tmpX, int tmpY, int x, int y);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall DrawPointer(int AX, int AY, Graphics::TColor AColor, int ValueIndex);
	virtual void __fastcall DrawValue(int ValueIndex);
	Graphics::TColor __fastcall GetAreaBrushColor(Graphics::TColor AColor);
	void __fastcall LinePrepareCanvas(Tecanvas::TCanvas3D* tmpCanvas, Graphics::TColor tmpColor);
	
public:
	__fastcall virtual TCustomSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual int __fastcall Clicked(int x, int y);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual AnsiString __fastcall GetEditorClass();
	virtual int __fastcall GetOriginPos(int ValueIndex);
	__property Graphics::TBrushStyle AreaBrush = {read=FAreaBrush, write=SetAreaBrush, default=0};
	__property Graphics::TColor AreaColor = {read=FAreaColor, write=SetAreaColor, default=536870912};
	__property Tecanvas::TChartPen* AreaLinesPen = {read=FAreaLinesPen, write=SetAreaLinesPen};
	__property bool ClickableLine = {read=FClickableLine, write=FClickableLine, nodefault};
	__property bool Dark3D = {read=FDark3D, write=SetDark3D, default=1};
	__property bool DrawArea = {read=FDrawArea, write=SetDrawArea, default=0};
	__property bool InvertedStairs = {read=FInvertedStairs, write=SetInvertedStairs, default=0};
	__property Graphics::TBrushStyle LineBrush = {read=FLineBrush, write=SetLineBrush, default=0};
	__property int LineHeight = {read=FLineHeight, write=SetLineHeight, default=0};
	__property Tecanvas::TChartPen* LinePen = {read=FLinePen, write=SetLinePen};
	__property TSeriesClickPointerEvent OnClickPointer = {read=FOnClickPointer, write=FOnClickPointer};
	__property TSeriesPointer* Pointer = {read=FPointer, write=SetPointer};
	__property bool Stairs = {read=FStairs, write=SetStairs, default=0};
	
__published:
	__property TOnGetPointerStyle OnGetPointerStyle = {read=FOnGetPointerStyle, write=FOnGetPointerStyle};
};


class DELPHICLASS TLineSeries;
class PASCALIMPLEMENTATION TLineSeries : public TCustomSeries 
{
	typedef TCustomSeries inherited;
	
public:
	__fastcall virtual TLineSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	
__published:
	__property Dark3D  = {default=1};
	__property InvertedStairs  = {default=0};
	__property LineBrush  = {default=0};
	__property LineHeight  = {default=0};
	__property LinePen ;
	__property Pointer ;
	__property Stairs  = {default=0};
	__property XValues ;
	__property YValues ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TLineSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPointSeries;
class PASCALIMPLEMENTATION TPointSeries : public TCustomSeries 
{
	typedef TCustomSeries inherited;
	
protected:
	virtual void __fastcall SetColorEachPoint(bool Value);
	
public:
	__fastcall virtual TPointSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual AnsiString __fastcall GetEditorClass();
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	
__published:
	__property Pointer ;
	__property XValues ;
	__property YValues ;
	__property OnClickPointer ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TPointSeries(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMultiArea { maNone, maStacked, maStacked100 };
#pragma option pop

class DELPHICLASS TAreaSeries;
class PASCALIMPLEMENTATION TAreaSeries : public TCustomSeries 
{
	typedef TCustomSeries inherited;
	
private:
	TMultiArea FMultiArea;
	void __fastcall SetMultiArea(TMultiArea Value);
	int __fastcall InternalCalcStackedYPos(int ValueIndex, double Value);
	
public:
	__fastcall virtual TAreaSeries(Classes::TComponent* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall CalcZOrder(void);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual AnsiString __fastcall GetEditorClass();
	virtual int __fastcall GetOriginPos(int ValueIndex);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	
__published:
	__property AreaBrush  = {default=0};
	__property AreaColor  = {default=536870912};
	__property AreaLinesPen ;
	__property Dark3D  = {default=1};
	__property DrawArea  = {default=0};
	__property InvertedStairs  = {default=0};
	__property LinePen ;
	__property TMultiArea MultiArea = {read=FMultiArea, write=SetMultiArea, default=0};
	__property Pointer ;
	__property Stairs  = {default=0};
	__property XValues ;
	__property YValues ;
public:
	#pragma option push -w-inl
	/* TCustomSeries.Destroy */ inline __fastcall virtual ~TAreaSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS BarException;
class PASCALIMPLEMENTATION BarException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall BarException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall BarException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall BarException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall BarException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall BarException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall BarException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall BarException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall BarException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~BarException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TMultiBar { mbNone, mbSide, mbStacked, mbStacked100 };
#pragma option pop

#pragma option push -b-
enum TBarStyle { bsRectangle, bsPyramid, bsInvPyramid, bsCilinder, bsEllipse, bsArrow, bsRectGradient };
#pragma option pop

class DELPHICLASS TCustomBarSeries;
typedef void __fastcall (__closure *TGetBarStyleEvent)(TCustomBarSeries* Sender, int ValueIndex, TBarStyle &TheBarStyle);

class PASCALIMPLEMENTATION TCustomBarSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	bool FAutoBarSize;
	bool FAutoMarkPosition;
	Chart::TChartBrush* FBarBrush;
	Tecanvas::TChartPen* FBarPen;
	TBarStyle FBarStyle;
	int FBarWidthPercent;
	bool FDark3D;
	TMultiBar FMultiBar;
	int FOffsetPercent;
	bool FSideMargins;
	bool FUseOrigin;
	double FOrigin;
	TGetBarStyleEvent FOnGetBarStyle;
	#pragma pack(push, 1)
	Types::TRect FBarBounds;
	#pragma pack(pop)
	
	void __fastcall CalcBarWidth(void);
	virtual int __fastcall InternalCalcMarkLength(int ValueIndex) = 0 ;
	void __fastcall SetAutoBarSize(bool Value);
	void __fastcall SetAutoMarkPosition(bool Value);
	void __fastcall SetBarWidthPercent(int Value);
	void __fastcall SetOffsetPercent(int Value);
	void __fastcall SetBarStyle(TBarStyle Value);
	void __fastcall SetDark3d(bool Value);
	void __fastcall SetUseOrigin(bool Value);
	void __fastcall SetSideMargins(bool Value);
	void __fastcall SetBarPen(Tecanvas::TChartPen* Value);
	void __fastcall SetBarBrush(Chart::TChartBrush* Value);
	void __fastcall SetOrigin(const double Value);
	void __fastcall SetMultiBar(TMultiBar Value);
	void __fastcall SetOtherMultiBar(void);
	void __fastcall AdjustGradientRectPen(Types::TRect &R);
	int __fastcall BarOrderPos(void);
	int __fastcall BarSeriesCount(void);
	double __fastcall MaxMandatoryValue(const double Value, Teengine::TChartValueList* AList);
	double __fastcall MinMandatoryValue(const double Value);
	void __fastcall InternalApplyBarMargin(int &MarginA, int &MarginB);
	
protected:
	int FCustomBarSize;
	int IBarSize;
	virtual bool __fastcall InternalClicked(int ValueIndex, const Types::TPoint &APoint);
	int __fastcall InternalGetOriginPos(int ValueIndex, int DefaultOrigin);
	void __fastcall SetCustomBarSize(int Value);
	
public:
	Graphics::TColor NormalBarColor;
	__fastcall virtual TCustomBarSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomBarSeries(void);
	int __fastcall AddBar(const double AValue, const AnsiString ALabel, Graphics::TColor AColor);
	int __fastcall ApplyBarOffset(int Position);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall BarMargin(void);
	void __fastcall BarRectangle(Graphics::TColor BarColor, int ALeft, int ATop, int ARight, int ABottom);
	int __fastcall CalcMarkLength(int ValueIndex);
	virtual void __fastcall CalcZOrder(void);
	virtual int __fastcall Clicked(int x, int y);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	TBarStyle __fastcall GetBarStyle(int ValueIndex);
	virtual AnsiString __fastcall GetEditorClass();
	virtual int __fastcall NumSampleValues(void);
	virtual double __fastcall PointOrigin(int ValueIndex, bool SumAll);
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	void __fastcall SetPenBrushBar(Graphics::TColor BarColor);
	__property Types::TRect BarBounds = {read=FBarBounds};
	
__published:
	__property bool AutoBarSize = {read=FAutoBarSize, write=SetAutoBarSize, default=0};
	__property bool AutoMarkPosition = {read=FAutoMarkPosition, write=SetAutoMarkPosition, default=1};
	__property Chart::TChartBrush* BarBrush = {read=FBarBrush, write=SetBarBrush};
	__property Tecanvas::TChartPen* BarPen = {read=FBarPen, write=SetBarPen};
	__property TBarStyle BarStyle = {read=FBarStyle, write=SetBarStyle, default=0};
	__property int BarWidthPercent = {read=FBarWidthPercent, write=SetBarWidthPercent, default=70};
	__property bool Dark3D = {read=FDark3D, write=SetDark3d, default=1};
	__property TMultiBar MultiBar = {read=FMultiBar, write=SetMultiBar, default=1};
	__property int OffsetPercent = {read=FOffsetPercent, write=SetOffsetPercent, default=0};
	__property bool SideMargins = {read=FSideMargins, write=SetSideMargins, default=1};
	__property bool UseYOrigin = {read=FUseOrigin, write=SetUseOrigin, default=1};
	__property double YOrigin = {read=FOrigin, write=SetOrigin};
	__property XValues ;
	__property YValues ;
	__property TGetBarStyleEvent OnGetBarStyle = {read=FOnGetBarStyle, write=FOnGetBarStyle};
};


class DELPHICLASS TBarSeries;
class PASCALIMPLEMENTATION TBarSeries : public TCustomBarSeries 
{
	typedef TCustomBarSeries inherited;
	
private:
	virtual int __fastcall InternalCalcMarkLength(int ValueIndex);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	
public:
	virtual bool __fastcall InternalClicked(int ValueIndex, const Types::TPoint &APoint);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	virtual bool __fastcall DrawValuesForward(void);
	int __fastcall GetOriginPos(int ValueIndex);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	__property int BarWidth = {read=IBarSize, nodefault};
	
__published:
	__property int CustomBarWidth = {read=FCustomBarSize, write=SetCustomBarSize, default=0};
public:
	#pragma option push -w-inl
	/* TCustomBarSeries.Create */ inline __fastcall virtual TBarSeries(Classes::TComponent* AOwner) : TCustomBarSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomBarSeries.Destroy */ inline __fastcall virtual ~TBarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS THorizBarSeries;
class PASCALIMPLEMENTATION THorizBarSeries : public TCustomBarSeries 
{
	typedef TCustomBarSeries inherited;
	
private:
	virtual int __fastcall InternalCalcMarkLength(int ValueIndex);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	
public:
	virtual bool __fastcall InternalClicked(int ValueIndex, const Types::TPoint &APoint);
	virtual void __fastcall CalcHorizMargins(int &LeftMargin, int &RightMargin);
	virtual void __fastcall CalcVerticalMargins(int &TopMargin, int &BottomMargin);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall CalcYPos(int ValueIndex);
	virtual void __fastcall DrawBar(int BarIndex, int StartPos, int EndPos);
	virtual bool __fastcall DrawSeriesForward(int ValueIndex);
	virtual bool __fastcall DrawValuesForward(void);
	virtual void __fastcall FillSampleValues(int NumValues);
	int __fastcall GetOriginPos(int ValueIndex);
	virtual Teengine::TChartValueList* __fastcall MandatoryValueList(void);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	__property int BarHeight = {read=IBarSize, nodefault};
	
__published:
	__property int CustomBarHeight = {read=FCustomBarSize, write=SetCustomBarSize, default=0};
public:
	#pragma option push -w-inl
	/* TCustomBarSeries.Create */ inline __fastcall virtual THorizBarSeries(Classes::TComponent* AOwner) : TCustomBarSeries(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomBarSeries.Destroy */ inline __fastcall virtual ~THorizBarSeries(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCircledSeries;
class PASCALIMPLEMENTATION TCircledSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	bool FCircled;
	int FRotationAngle;
	int FCustomXRadius;
	int FCustomYRadius;
	int FXRadius;
	int FYRadius;
	Graphics::TColor FCircleBackColor;
	double IRotDegree;
	int FCircleWidth;
	int FCircleHeight;
	int FCircleXCenter;
	int FCircleYCenter;
	#pragma pack(push, 1)
	Types::TRect FCircleRect;
	#pragma pack(pop)
	
	void __fastcall SetCircleBackColor(Graphics::TColor Value);
	void __fastcall SetCustomXRadius(int Value);
	void __fastcall SetCustomYRadius(int Value);
	void __fastcall SetCircled(bool Value);
	void __fastcall SetOtherCustomRadius(bool IsXRadius, int Value);
	
protected:
	void __fastcall AdjustCircleRect(void);
	Graphics::TColor __fastcall CalcCircleBackColor(void);
	void __fastcall CalcRadius(void);
	virtual void __fastcall DoBeforeDrawValues(void);
	virtual void __fastcall SetActive(bool Value);
	virtual void __fastcall SetParentChart(Teengine::TCustomAxisPanel* Value);
	void __fastcall SetRotationAngle(int Value);
	
public:
	__fastcall virtual TCircledSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TCircledSeries(void);
	void __fastcall AngleToPos(const double Angle, const double AXRadius, const double AYRadius, int &X, int &Y);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual bool __fastcall AssociatedToAxis(Teengine::TCustomChartAxis* Axis);
	double __fastcall PointToAngle(int x, int y);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	void __fastcall Rotate(int Angle);
	virtual void __fastcall SetParentProperties(bool EnableParentProps);
	virtual bool __fastcall UseAxis(void);
	__property int XRadius = {read=FXRadius, nodefault};
	__property int YRadius = {read=FYRadius, nodefault};
	__property int CircleXCenter = {read=FCircleXCenter, nodefault};
	__property int CircleYCenter = {read=FCircleYCenter, nodefault};
	__property int CircleWidth = {read=FCircleWidth, nodefault};
	__property int CircleHeight = {read=FCircleHeight, nodefault};
	__property Types::TRect CircleRect = {read=FCircleRect};
	__property Graphics::TColor CircleBackColor = {read=FCircleBackColor, write=SetCircleBackColor, default=536870912};
	__property int RotationAngle = {read=FRotationAngle, write=SetRotationAngle, default=0};
	
__published:
	__property bool Circled = {read=FCircled, write=SetCircled, default=0};
	__property int CustomXRadius = {read=FCustomXRadius, write=SetCustomXRadius, default=0};
	__property int CustomYRadius = {read=FCustomYRadius, write=SetCustomYRadius, default=0};
};


class DELPHICLASS PieException;
class PASCALIMPLEMENTATION PieException : public Teeprocs::ChartException 
{
	typedef Teeprocs::ChartException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall PieException(const AnsiString Msg) : Teeprocs::ChartException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall PieException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Teeprocs::ChartException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall PieException(int Ident)/* overload */ : Teeprocs::ChartException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall PieException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Teeprocs::ChartException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall PieException(const AnsiString Msg, int AHelpContext) : Teeprocs::ChartException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall PieException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Teeprocs::ChartException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall PieException(int Ident, int AHelpContext)/* overload */ : Teeprocs::ChartException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall PieException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Teeprocs::ChartException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~PieException(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct TPieAngle
{
	double StartAngle;
	double MidAngle;
	double EndAngle;
} ;
#pragma pack(pop)

typedef DynamicArray<TPieAngle >  TPieAngles;

class DELPHICLASS TExplodedSlices;
class PASCALIMPLEMENTATION TExplodedSlices : public Classes::TList 
{
	typedef Classes::TList inherited;
	
public:
	int operator[](int Index) { return Value[Index]; }
	
private:
	void __fastcall SetValue(int Index, int Value);
	int __fastcall GetValue(int Index);
	
public:
	Teengine::TChartSeries* OwnerSeries;
	__property int Value[int Index] = {read=GetValue, write=SetValue/*, default*/};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TExplodedSlices(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TExplodedSlices(void) : Classes::TList() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPieOtherStyle { poNone, poBelowPercent, poBelowValue };
#pragma option pop

class DELPHICLASS TPieOtherSlice;
class PASCALIMPLEMENTATION TPieOtherSlice : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TPieOtherStyle FStyle;
	AnsiString FText;
	double FValue;
	Teengine::TChartSeries* FOwner;
	void __fastcall SetStyle(TPieOtherStyle Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetValue(const double Value);
	
public:
	__fastcall TPieOtherSlice(Teengine::TChartSeries* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TPieOtherStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property AnsiString Text = {read=FText, write=SetText};
	__property double Value = {read=FValue, write=SetValue};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TPieOtherSlice(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPieSeries;
class PASCALIMPLEMENTATION TPieSeries : public TCircledSeries 
{
	typedef TCircledSeries inherited;
	
private:
	bool FDark3d;
	TExplodedSlices* FExplodedSlice;
	int FExplodeBiggest;
	Tecanvas::TChartPen* FPiePen;
	TPieOtherSlice* FOtherSlice;
	bool FUsePatterns;
	void __fastcall DisableRotation(void);
	void __fastcall SetUsePatterns(bool Value);
	void __fastcall SetDark3d(bool Value);
	Teengine::TChartValueList* __fastcall GetPieValues(void);
	void __fastcall SetPieValues(Teengine::TChartValueList* Value);
	void __fastcall SetExplodeBiggest(int Value);
	void __fastcall SetPiePen(Tecanvas::TChartPen* Value);
	void __fastcall SetOtherSlice(TPieOtherSlice* Value);
	void __fastcall CalcExplodeBiggest(void);
	void __fastcall CalcExplodedOffset(int ValueIndex, int &OffsetX, int &OffsetY);
	
protected:
	DynamicArray<TPieAngle >  FAngles;
	int IniX;
	int IniY;
	int EndX;
	int EndY;
	bool IsExploded;
	void __fastcall CalcAngles(void);
	void __fastcall CalcExplodedRadius(int ValueIndex, int &AXRadius, int &AYRadius);
	virtual void __fastcall DoBeforeDrawChart(void);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall DrawPie(int ValueIndex);
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	virtual void __fastcall ClearLists(void);
	
public:
	__fastcall virtual TPieSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TPieSeries(void);
	int __fastcall AddPie(const double AValue, const AnsiString ALabel, Graphics::TColor AColor);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall BelongsToOtherSlice(int ValueIndex);
	int __fastcall CalcClickedPie(int x, int y);
	virtual int __fastcall CalcXPos(int ValueIndex);
	virtual int __fastcall Clicked(int x, int y);
	virtual int __fastcall CountLegendItems(void);
	virtual void __fastcall FillSampleValues(int NumValues);
	virtual void __fastcall GalleryChanged3D(bool Is3D);
	virtual AnsiString __fastcall GetEditorClass();
	virtual int __fastcall LegendToValueIndex(int LegendIndex);
	virtual double __fastcall MaxXValue(void);
	virtual double __fastcall MinXValue(void);
	virtual double __fastcall MaxYValue(void);
	virtual double __fastcall MinYValue(void);
	virtual int __fastcall NumSampleValues(void);
	virtual void __fastcall PrepareForGallery(bool IsEnabled);
	virtual void __fastcall PrepareLegendCanvas(int ValueIndex, Graphics::TColor &BackColor, Graphics::TBrushStyle &BrushStyle);
	virtual void __fastcall SwapValueIndex(int a, int b);
	__property TPieAngles Angles = {read=FAngles};
	__property TExplodedSlices* ExplodedSlice = {read=FExplodedSlice};
	
__published:
	__property CircleBackColor  = {default=536870912};
	__property ColorEachPoint  = {default=1};
	__property bool Dark3D = {read=FDark3d, write=SetDark3d, default=1};
	__property int ExplodeBiggest = {read=FExplodeBiggest, write=SetExplodeBiggest, default=0};
	__property TPieOtherSlice* OtherSlice = {read=FOtherSlice, write=SetOtherSlice};
	__property Tecanvas::TChartPen* PiePen = {read=FPiePen, write=SetPiePen};
	__property Teengine::TChartValueList* PieValues = {read=GetPieValues, write=SetPieValues};
	__property RotationAngle  = {default=0};
	__property bool UsePatterns = {read=FUsePatterns, write=SetUsePatterns, default=0};
};


class DELPHICLASS TFastLineSeries;
class PASCALIMPLEMENTATION TFastLineSeries : public Teengine::TChartSeries 
{
	typedef Teengine::TChartSeries inherited;
	
private:
	bool FAutoRepaint;
	Tecanvas::TChartPen* FLinePen;
	int OldX;
	int OldY;
	void __fastcall SetLinePen(Tecanvas::TChartPen* Value);
	
protected:
	virtual void __fastcall DrawValue(int ValueIndex);
	virtual void __fastcall DrawAllValues(void);
	virtual void __fastcall SetSeriesColor(Graphics::TColor AColor);
	void __fastcall PrepareCanvas(void);
	virtual void __fastcall DrawMark(int ValueIndex, const AnsiString St, Teengine::TSeriesMarkPosition* APosition);
	
public:
	__fastcall virtual TFastLineSeries(Classes::TComponent* AOwner);
	__fastcall virtual ~TFastLineSeries(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual int __fastcall Clicked(int x, int y);
	virtual void __fastcall DrawLegendShape(int ValueIndex, const Types::TRect &Rect);
	virtual AnsiString __fastcall GetEditorClass();
	virtual void __fastcall NotifyNewValue(Teengine::TChartSeries* Sender, int ValueIndex);
	
__published:
	__property bool AutoRepaint = {read=FAutoRepaint, write=FAutoRepaint, default=1};
	__property Tecanvas::TChartPen* LinePen = {read=FLinePen, write=SetLinePen};
	__property XValues ;
	__property YValues ;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE double TwoPi;
extern PACKAGE double HalfPi;
extern PACKAGE double PiDegree;

}	/* namespace Series */
using namespace Series;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Series
