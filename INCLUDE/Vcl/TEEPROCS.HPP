// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'TeeProcs.pas' rev: 6.00

#ifndef TeeProcsHPP
#define TeeProcsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Clipbrd.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <TeCanvas.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Teeprocs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ChartException;
class PASCALIMPLEMENTATION ChartException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ChartException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ChartException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ChartException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ChartException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ChartException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ChartException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ChartException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ChartException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ChartException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDateTimeStep { dtOneSecond, dtFiveSeconds, dtTenSeconds, dtFifteenSeconds, dtThirtySeconds, dtOneMinute, dtFiveMinutes, dtTenMinutes, dtFifteenMinutes, dtThirtyMinutes, dtOneHour, dtTwoHours, dtSixHours, dtTwelveHours, dtOneDay, dtTwoDays, dtThreeDays, dtOneWeek, dtHalfMonth, dtOneMonth, dtTwoMonths, dtThreeMonths, dtFourMonths, dtSixMonths, dtOneYear, dtNone };
#pragma option pop

class DELPHICLASS TZoomPanningRecord;
class PASCALIMPLEMENTATION TZoomPanningRecord : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	bool Active;
	int X0;
	int Y0;
	int X1;
	int Y1;
	void __fastcall Check(void);
	void __fastcall Activate(int x, int y);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TZoomPanningRecord(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TZoomPanningRecord(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTeeBackImageMode { pbmStretch, pbmTile, pbmCenter };
#pragma option pop

class DELPHICLASS TCustomTeePanel;
class PASCALIMPLEMENTATION TCustomTeePanel : public Extctrls::TCustomPanel 
{
	typedef Extctrls::TCustomPanel inherited;
	
private:
	int F3DPercent;
	bool FApplyZOrder;
	#pragma pack(push, 1)
	Types::TRect FChartBounds;
	#pragma pack(pop)
	
	int FChartWidth;
	int FChartHeight;
	int FChartXCenter;
	int FChartYCenter;
	Graphics::TCanvas* FDelphiCanvas;
	int FHeight3D;
	#pragma pack(push, 1)
	Types::TRect FMargins;
	#pragma pack(pop)
	
	Controls::TCursor FOriginalCursor;
	TZoomPanningRecord* FPanning;
	bool FPrinting;
	bool FPrintProportional;
	int FPrintResolution;
	bool FView3D;
	Tecanvas::TView3DOptions* FView3DOptions;
	int FWidth3D;
	TZoomPanningRecord* FZoom;
	int __fastcall GetMargin(int Index);
	bool __fastcall GetBufferedDisplay(void);
	void __fastcall SetBufferedDisplay(bool Value);
	void __fastcall SetView3D(bool Value);
	void __fastcall SetView3DOptions(Tecanvas::TView3DOptions* Value);
	bool __fastcall GetMonochrome(void);
	void __fastcall SetMonochrome(bool Value);
	void __fastcall Set3DPercent(int Value);
	
protected:
	Tecanvas::TCanvas3D* InternalCanvas;
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	int __fastcall MultiLineTextWidth(AnsiString S, int &NumLines);
	void __fastcall SetMargin(int Index, int Value);
	virtual void __fastcall Loaded(void);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle) = 0 ;
	virtual void __fastcall Paint(void);
	
public:
	bool AutoRepaint;
	bool CancelMouse;
	#pragma pack(push, 1)
	Types::TRect ChartRect;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TRect PrintMargins;
	#pragma pack(pop)
	
	__fastcall virtual TCustomTeePanel(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTeePanel(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall CalcMetaBounds(Types::TRect &R, const Types::TRect &AChartRect, int &WinWidth, int &WinHeight, int &ViewWidth, int &ViewHeight);
	Types::TRect __fastcall CalcProportionalMargins();
	bool __fastcall CanClip(void);
	virtual void __fastcall CanvasChanged(System::TObject* Sender);
	Types::TRect __fastcall ChartPrintRect();
	void __fastcall CheckPenWidth(Graphics::TPen* APen);
	void __fastcall CopyToClipboardBitmap(void);
	void __fastcall CopyToClipboardMetafile(bool Enhanced);
	Graphics::TBitmap* __fastcall TeeCreateBitmap(Graphics::TColor ABackColor, const Types::TRect &Rect);
	virtual void __fastcall Draw(Graphics::TCanvas* UserCanvas, const Types::TRect &UserRect);
	virtual void __fastcall DrawPanelBevels(const Types::TRect &Rect);
	void __fastcall DrawToMetaCanvas(Graphics::TCanvas* ACanvas, const Types::TRect &Rect);
	void __fastcall DrawZoomRectangle(void);
	virtual void __fastcall FontCanvas(Graphics::TFont* SourceFont);
	Types::TPoint __fastcall GetCursorPos();
	virtual Types::TRect __fastcall GetRectangle();
	virtual void __fastcall Invalidate(void);
	bool __fastcall IsScreenHighColor(void);
	void __fastcall Print(void);
	void __fastcall PrintLandscape(void);
	void __fastcall PrintOrientation(Printers::TPrinterOrientation AOrientation);
	void __fastcall PrintPartial(const Types::TRect &PrinterRect);
	void __fastcall PrintPartialCanvas(Graphics::TCanvas* PrintCanvas, const Types::TRect &PrinterRect);
	void __fastcall PrintPortrait(void);
	void __fastcall PrintRect(const Types::TRect &R);
	void __fastcall SaveToBitmapFile(const AnsiString FileName);
	void __fastcall SaveToMetafile(const AnsiString FileName);
	void __fastcall SaveToMetafileEnh(const AnsiString FileName);
	void __fastcall SaveToMetafileRect(bool Enhanced, const AnsiString FileName, const Types::TRect &Rect);
	void __fastcall SetBooleanProperty(bool &Variable, bool Value);
	void __fastcall SetBrushCanvas(Graphics::TColor AColor, Graphics::TBrushStyle APattern, Graphics::TColor ABackColor);
	void __fastcall SetColorProperty(Graphics::TColor &Variable, Graphics::TColor Value);
	void __fastcall SetDoubleProperty(double &Variable, const double Value);
	void __fastcall SetLongintProperty(int &Variable, int Value);
	void __fastcall SetIntegerProperty(int &Variable, int Value);
	void __fastcall SetInternalCanvas(Tecanvas::TCanvas3D* NewCanvas);
	void __fastcall SetStringProperty(AnsiString &Variable, const AnsiString Value);
	void __fastcall ReCalcWidthHeight(void);
	Graphics::TMetafile* __fastcall TeeCreateMetafile(bool Enhanced, const Types::TRect &Rect);
	__property bool ApplyZOrder = {read=FApplyZOrder, write=FApplyZOrder, nodefault};
	__property bool BufferedDisplay = {read=GetBufferedDisplay, write=SetBufferedDisplay, nodefault};
	__property Tecanvas::TCanvas3D* Canvas = {read=InternalCanvas, write=SetInternalCanvas};
	__property Types::TRect ChartBounds = {read=FChartBounds};
	__property int ChartHeight = {read=FChartHeight, nodefault};
	__property int ChartWidth = {read=FChartWidth, nodefault};
	__property int ChartXCenter = {read=FChartXCenter, nodefault};
	__property int ChartYCenter = {read=FChartYCenter, nodefault};
	__property Graphics::TCanvas* DelphiCanvas = {read=FDelphiCanvas};
	__property int Height3D = {read=FHeight3D, write=FHeight3D, nodefault};
	__property TZoomPanningRecord* IPanning = {read=FPanning};
	__property TZoomPanningRecord* IZoom = {read=FZoom};
	__property Controls::TCursor OriginalCursor = {read=FOriginalCursor, write=FOriginalCursor, nodefault};
	__property bool Printing = {read=FPrinting, write=FPrinting, nodefault};
	__property int Width3D = {read=FWidth3D, write=FWidth3D, nodefault};
	__property int PrintResolution = {read=FPrintResolution, write=FPrintResolution, default=0};
	__property int Chart3DPercent = {read=F3DPercent, write=Set3DPercent, default=15};
	__property int MarginLeft = {read=GetMargin, write=SetMargin, index=0, default=3};
	__property int MarginTop = {read=GetMargin, write=SetMargin, index=1, default=4};
	__property int MarginRight = {read=GetMargin, write=SetMargin, index=2, default=3};
	__property int MarginBottom = {read=GetMargin, write=SetMargin, index=3, default=4};
	__property bool Monochrome = {read=GetMonochrome, write=SetMonochrome, default=0};
	__property bool PrintProportional = {read=FPrintProportional, write=FPrintProportional, default=1};
	__property bool View3D = {read=FView3D, write=SetView3D, default=1};
	__property Tecanvas::TView3DOptions* View3DOptions = {read=FView3DOptions, write=SetView3DOptions};
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
	__property Color  = {default=-2147483633};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTeePanel(HWND ParentWindow) : Extctrls::TCustomPanel(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPanningMode { pmNone, pmHorizontal, pmVertical, pmBoth };
#pragma option pop

class DELPHICLASS TCustomTeeGradient;
class PASCALIMPLEMENTATION TCustomTeeGradient : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Tecanvas::TGradientDirection FDirection;
	Graphics::TColor FEndColor;
	TCustomTeePanel* FOwner;
	Graphics::TColor FStartColor;
	bool FVisible;
	void __fastcall SetDirection(Tecanvas::TGradientDirection Value);
	void __fastcall SetEndColor(Graphics::TColor Value);
	void __fastcall SetStartColor(Graphics::TColor Value);
	void __fastcall SetVisible(bool Value);
	
public:
	__fastcall TCustomTeeGradient(TCustomTeePanel* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TCustomTeePanel* Owner = {read=FOwner, write=FOwner};
	__property Tecanvas::TGradientDirection Direction = {read=FDirection, write=SetDirection, default=0};
	__property Graphics::TColor EndColor = {read=FEndColor, write=SetEndColor, default=65535};
	__property Graphics::TColor StartColor = {read=FStartColor, write=SetStartColor, default=16777215};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TCustomTeeGradient(void) { }
	#pragma option pop
	
};


class DELPHICLASS TChartGradient;
class PASCALIMPLEMENTATION TChartGradient : public TCustomTeeGradient 
{
	typedef TCustomTeeGradient inherited;
	
__published:
	__property Direction  = {default=0};
	__property EndColor  = {default=65535};
	__property StartColor  = {default=16777215};
	__property Visible  = {default=0};
public:
	#pragma option push -w-inl
	/* TCustomTeeGradient.Create */ inline __fastcall TChartGradient(TCustomTeePanel* AOwner) : TCustomTeeGradient(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TChartGradient(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomTeePanelExtended;
class PASCALIMPLEMENTATION TCustomTeePanelExtended : public TCustomTeePanel 
{
	typedef TCustomTeePanel inherited;
	
private:
	int FAnimatedZoomSteps;
	bool FAnimatedZoom;
	bool FAllowZoom;
	TPanningMode FAllowPanning;
	Graphics::TPicture* FBackImage;
	TTeeBackImageMode FBackImageMode;
	TChartGradient* FGradient;
	bool FZoomed;
	void __fastcall SetAnimatedZoom(bool Value);
	void __fastcall SetAnimatedZoomSteps(int Value);
	void __fastcall SetBackImage(Graphics::TPicture* Value);
	void __fastcall SetBackImageMode(TTeeBackImageMode Value);
	void __fastcall SetGradient(TChartGradient* Value);
	
protected:
	Classes::TNotifyEvent FOnAfterDraw;
	Classes::TNotifyEvent FOnScroll;
	Classes::TNotifyEvent FOnUndoZoom;
	Classes::TNotifyEvent FOnZoom;
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	void __fastcall DrawBitmap(const Types::TRect &Rect, int Z);
	virtual void __fastcall DrawImage(const Types::TRect &R);
	virtual void __fastcall FillPanelRect(const Types::TRect &Rect);
	virtual void __fastcall PanelPaint(const Types::TRect &UserRect);
	
public:
	__fastcall virtual TCustomTeePanelExtended(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTeePanelExtended(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	DYNAMIC void __fastcall UndoZoom(void);
	__property bool Zoomed = {read=FZoomed, write=FZoomed, nodefault};
	__property TPanningMode AllowPanning = {read=FAllowPanning, write=FAllowPanning, default=3};
	__property bool AllowZoom = {read=FAllowZoom, write=FAllowZoom, default=1};
	__property bool AnimatedZoom = {read=FAnimatedZoom, write=SetAnimatedZoom, default=0};
	__property int AnimatedZoomSteps = {read=FAnimatedZoomSteps, write=SetAnimatedZoomSteps, default=8};
	__property Graphics::TPicture* BackImage = {read=FBackImage, write=SetBackImage};
	__property TTeeBackImageMode BackImageMode = {read=FBackImageMode, write=SetBackImageMode, default=0};
	__property TChartGradient* Gradient = {read=FGradient, write=SetGradient};
	__property Classes::TNotifyEvent OnAfterDraw = {read=FOnAfterDraw, write=FOnAfterDraw};
	__property Classes::TNotifyEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property Classes::TNotifyEvent OnUndoZoom = {read=FOnUndoZoom, write=FOnUndoZoom};
	__property Classes::TNotifyEvent OnZoom = {read=FOnZoom, write=FOnZoom};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTeePanelExtended(HWND ParentWindow) : TCustomTeePanel(ParentWindow) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TDraw3DPaintEvent)(System::TObject* Sender, const Types::TRect &ARect);

class DELPHICLASS TDraw3D;
class PASCALIMPLEMENTATION TDraw3D : public TCustomTeePanelExtended 
{
	typedef TCustomTeePanelExtended inherited;
	
private:
	TDraw3DPaintEvent FOnPaint;
	
protected:
	virtual void __fastcall InternalDraw(const Types::TRect &UserRectangle);
	
__published:
	__property BackImage ;
	__property BackImageMode  = {default=0};
	__property Gradient ;
	__property OnAfterDraw ;
	__property BufferedDisplay ;
	__property MarginLeft  = {index=0, default=3};
	__property MarginTop  = {index=1, default=4};
	__property MarginRight  = {index=2, default=3};
	__property MarginBottom  = {index=3, default=4};
	__property Monochrome  = {default=0};
	__property PrintProportional  = {default=1};
	__property PrintResolution  = {default=0};
	__property View3D  = {default=1};
	__property View3DOptions ;
	__property TDraw3DPaintEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property Align  = {default=0};
	__property BevelInner  = {default=0};
	__property BevelOuter  = {default=2};
	__property BevelWidth  = {default=1};
	__property BorderWidth  = {default=0};
	__property BorderStyle  = {default=0};
	__property Color  = {default=-2147483633};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=0};
	__property Constraints ;
	__property DragKind  = {default=0};
	__property Locked  = {default=0};
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
	/* TCustomTeePanelExtended.Create */ inline __fastcall virtual TDraw3D(Classes::TComponent* AOwner) : TCustomTeePanelExtended(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTeePanelExtended.Destroy */ inline __fastcall virtual ~TDraw3D(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDraw3D(HWND ParentWindow) : TCustomTeePanelExtended(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TChartFontObject;
class PASCALIMPLEMENTATION TChartFontObject : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomTeePanel* FParentChart;
	
protected:
	Graphics::TFont* FFont;
	void __fastcall SetFont(Graphics::TFont* Value);
	bool __fastcall IsFontStored(void);
	
public:
	__fastcall TChartFontObject(TCustomTeePanel* AOwner);
	__fastcall virtual ~TChartFontObject(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Repaint(void);
	__property Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property TCustomTeePanel* ParentChart = {read=FParentChart};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxDefaultColors = 0x10;
extern PACKAGE Graphics::TColor ColorPalette[16];
static const Shortint TeeDefVerticalMargin = 0x4;
static const Shortint TeeDefHorizMargin = 0x3;
#define TeeMsg_ExportChartName "Chart."
static const Word crTeeHand = 0x7e4;
#define TeeMsg_TeeHand "crTeeHand"
extern PACKAGE char TeeLineSeparator;
static const Shortint TeeDefault_PrintMargin = 0xf;
static const Shortint TeeNormalPrintDetail = 0x0;
static const Shortint TeeHighPrintDetail = 0xffffff9c;
static const Shortint TeeDef3DPercent = 0xf;
extern PACKAGE bool TeeClipWhenPrinting;
extern PACKAGE bool TeeClipWhenMetafiling;
extern PACKAGE bool TeeEraseBack;
extern PACKAGE bool PrintTeePanel;
extern PACKAGE double DateTimeStep[26];
extern PACKAGE Word __fastcall DaysInMonth(Word Year, Word Month);
extern PACKAGE AnsiString __fastcall DateTimeDefaultFormat(const double AStep);
extern PACKAGE double __fastcall NextDateTimeStep(const double AStep);
extern PACKAGE TDateTimeStep __fastcall FindDateTimeStep(const double StepValue);
extern PACKAGE int __fastcall GetScreenLogPixels(void);
extern PACKAGE void __fastcall CheckJapaneseFontSize(int &ASize);
extern PACKAGE int __fastcall GetDefaultFontSize(void);
extern PACKAGE AnsiString __fastcall GetDefaultFontName();
extern PACKAGE bool __fastcall IsDefaultFont(Graphics::TFont* AFont);
extern PACKAGE Graphics::TFont* __fastcall CreateDefaultFont(Classes::TNotifyEvent ChangedEvent);
extern PACKAGE Graphics::TColor __fastcall GetDefaultColor(int t);
extern PACKAGE void __fastcall TeeCheckAngle(int Value, const AnsiString Description);
extern PACKAGE AnsiString __fastcall TeeGetImageExtension(int Index);
extern PACKAGE bool __fastcall TeeIdentToCursor(const AnsiString AName, int &ACursor);
extern PACKAGE bool __fastcall TeeCursorToIdent(int ACursor, AnsiString &AName);
extern PACKAGE bool __fastcall PointInLineTolerance(const Types::TPoint &P, int px, int py, int qx, int qy, int TolerancePixels);
extern PACKAGE bool __fastcall PointInLine(const Types::TPoint &P, int px, int py, int qx, int qy);
extern PACKAGE bool __fastcall PointInPolygon(const Types::TPoint &P, const Types::TPoint * Poly, const int Poly_Size);
extern PACKAGE bool __fastcall PointInTriangle(const Types::TPoint &P, int X0, int X1, int Y0, int Y1);
extern PACKAGE bool __fastcall PointInHorizTriangle(const Types::TPoint &P, int Y0, int Y1, int X0, int X1);
extern PACKAGE bool __fastcall PointInEllipse(const Types::TPoint &P, const Types::TRect &Rect);
extern PACKAGE void __fastcall TeeSplitInLines(AnsiString &St, const AnsiString Separator);
extern PACKAGE int __fastcall TeeNumTextLines(AnsiString St);
extern PACKAGE AnsiString __fastcall DelphiToLocalFormat(const AnsiString Format);
extern PACKAGE AnsiString __fastcall LocalToDelphiFormat(const AnsiString Format);
extern PACKAGE void __fastcall EnableControls(bool Enable, const Controls::TControl* * ControlArray, const int ControlArray_Size);
extern PACKAGE System::TDateTime __fastcall TeeRoundDate(const System::TDateTime ADate, TDateTimeStep AStep);
extern PACKAGE void __fastcall TeeDateTimeIncrement(bool IsDateTime, bool Increment, double &Value, const double AnIncrement, TDateTimeStep tmpWhichDateTime);
extern PACKAGE double __fastcall TeeNextStep(const double OldStep);
extern PACKAGE void __fastcall TeeGetClassNameBitmap(Classes::TComponent* AClass, Graphics::TBitmap* ABitmap);
extern PACKAGE int __fastcall TeeNumFields(AnsiString St);
extern PACKAGE AnsiString __fastcall TeeExtractField(AnsiString St, int Index);
extern PACKAGE AnsiString __fastcall TeeGetUniqueName(Classes::TComponent* AOwner, const AnsiString AStartName);

}	/* namespace Teeprocs */
using namespace Teeprocs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// TeeProcs
