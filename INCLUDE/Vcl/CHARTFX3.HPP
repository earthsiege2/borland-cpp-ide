// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Chartfx3.pas' rev: 6.00

#ifndef Chartfx3HPP
#define Chartfx3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <OleServer.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Chartfx3
{
//-- type declarations -------------------------------------------------------
typedef Activex::TOleEnum PointTypeConstants;

typedef Activex::TOleEnum SchemeConstants;

typedef Activex::TOleEnum StackedConstants;

typedef Activex::TOleEnum GridConstants;

typedef Activex::TOleEnum GalleryConstants;

typedef Activex::TOleEnum ConstTypeConstants;

typedef Activex::TOleEnum LegendStyleConstants;

typedef Activex::TOleEnum OpenDataConstants;

typedef Activex::TOleEnum ClickConstants;

typedef Activex::TOleEnum DialogConstants;

typedef Activex::TOleEnum AdmConstants;

typedef Activex::TOleEnum TitleConstants;

typedef Activex::TOleEnum FontConstants;

typedef Activex::TOleEnum ItemConstants;

typedef Activex::TOleEnum DecimalConstants;

__dispinterface _DChartfx;
typedef System::DelphiInterface<_DChartfx> _di__DChartfx;
typedef _DChartfx Chartfx;
;

typedef short *PSmallint1;

__dispinterface INTERFACE_UUID("{2DC488B0-D891-101B-8652-00AA003A5593}") _DChartfx  : public IDispatch 
{
	
};

__dispinterface _DChartfxEvents;
typedef System::DelphiInterface<_DChartfxEvents> _di__DChartfxEvents;
__dispinterface INTERFACE_UUID("{2DC488B1-D891-101B-8652-00AA003A5593}") _DChartfxEvents  : public IDispatch 
{
	
};

typedef void __fastcall (__closure *TChartfxLButtonDblClk)(System::TObject* Sender, short x, short y, short nSerie, int nPoint, short &nRes);

typedef void __fastcall (__closure *TChartfxRButtonDown)(System::TObject* Sender, short x, short y, short nSerie, int nPoint, short &nRes);

typedef void __fastcall (__closure *TChartfxChangeValue)(System::TObject* Sender, double dValue, short nSerie, int nPoint, short &nRes);

typedef void __fastcall (__closure *TChartfxChangeString)(System::TObject* Sender, short nType, int nIndex, short &nRes);

typedef void __fastcall (__closure *TChartfxChangeColor)(System::TObject* Sender, short nType, short nIndex, short &nRes);

typedef void __fastcall (__closure *TChartfxChangePalette)(System::TObject* Sender, short nIndex, short &nRes);

typedef void __fastcall (__closure *TChartfxChangeFont)(System::TObject* Sender, short nIndex, short &nRes);

typedef void __fastcall (__closure *TChartfxChangePattern)(System::TObject* Sender, short nType, short nIndex, short &nRes);

typedef void __fastcall (__closure *TChartfxChangePattPal)(System::TObject* Sender, short nIndex, short &nRes);

typedef void __fastcall (__closure *TChartfxMenu)(System::TObject* Sender, int wParam, short nSerie, int nPoint, short &nRes);

typedef void __fastcall (__closure *TChartfxChangeType)(System::TObject* Sender, short nType, short &nRes);

typedef void __fastcall (__closure *TChartfxUserScroll)(System::TObject* Sender, int wScrollMsg, int wScrollParam, short &nRes);

typedef void __fastcall (__closure *TChartfxGetLegend)(System::TObject* Sender, short nType, short &nRes);

class DELPHICLASS TChartfx;
class PASCALIMPLEMENTATION TChartfx : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TChartfxLButtonDblClk FOnLButtonDblClk;
	TChartfxRButtonDown FOnRButtonDown;
	TChartfxChangeValue FOnChangeValue;
	TChartfxChangeString FOnChangeString;
	TChartfxChangeColor FOnChangeColor;
	Classes::TNotifyEvent FOnDestroy;
	Classes::TNotifyEvent FOnReadFile;
	TChartfxChangePalette FOnChangePalette;
	TChartfxChangeFont FOnChangeFont;
	Classes::TNotifyEvent FOnReadTemplate;
	TChartfxChangePattern FOnChangePattern;
	TChartfxChangePattPal FOnChangePattPal;
	TChartfxMenu FOnMenu;
	TChartfxChangeType FOnChangeType;
	TChartfxUserScroll FOnUserScroll;
	TChartfxGetLegend FOnGetLegend;
	_di__DChartfx FIntf;
	_di__DChartfx __fastcall GetControlInterface();
	
protected:
	HIDESBASE void __fastcall CreateControl(void);
	virtual void __fastcall InitControlData(void);
	double __fastcall Get_Value(short index);
	void __fastcall Set_Value(short index, double Param2);
	double __fastcall Get_XValue(short index);
	void __fastcall Set_XValue(short index, double Param2);
	double __fastcall Get_IniValue(short index);
	void __fastcall Set_IniValue(short index, double Param2);
	double __fastcall Get_Const_(short index);
	void __fastcall Set_Const_(short index, double Param2);
	unsigned __fastcall Get_Color(short index);
	void __fastcall Set_Color(short index, unsigned Param2);
	unsigned __fastcall Get_BkColor(short index);
	void __fastcall Set_BkColor(short index, unsigned Param2);
	double __fastcall Get_Adm(short index);
	void __fastcall Set_Adm(short index, double Param2);
	short __fastcall Get_Pattern(short index);
	void __fastcall Set_Pattern(short index, short Param2);
	int __fastcall Get_Fonts(short index);
	void __fastcall Set_Fonts(short index, int Param2);
	WideString __fastcall Get_Title(short index);
	void __fastcall Set_Title(short index, const WideString Param2);
	WideString __fastcall Get_Legend(short index);
	void __fastcall Set_Legend(short index, const WideString Param2);
	WideString __fastcall Get_SerLeg(short index);
	void __fastcall Set_SerLeg(short index, const WideString Param2);
	WideString __fastcall Get_KeyLeg(short index);
	void __fastcall Set_KeyLeg(short index, const WideString Param2);
	WideString __fastcall Get_FixLeg(short index);
	void __fastcall Set_FixLeg(short index, const WideString Param2);
	WideString __fastcall Get_YLeg(short index);
	void __fastcall Set_YLeg(short index, const WideString Param2);
	WideString __fastcall Get_KeySer(short index);
	void __fastcall Set_KeySer(short index, const WideString Param2);
	WideString __fastcall Get_StatusText(short index);
	void __fastcall Set_StatusText(short index, const WideString Param2);
	unsigned __fastcall Get_RGBFont(short index);
	void __fastcall Set_RGBFont(short index, unsigned Param2);
	short __fastcall Get_HFont(short index);
	void __fastcall Set_HFont(short index, short Param2);
	short __fastcall Get_ItemWidth(short index);
	void __fastcall Set_ItemWidth(short index, short Param2);
	short __fastcall Get_ItemStyle(short index);
	void __fastcall Set_ItemStyle(short index, short Param2);
	unsigned __fastcall Get_ItemColor(short index);
	void __fastcall Set_ItemColor(short index, unsigned Param2);
	short __fastcall Get_DecimalsNum(short index);
	void __fastcall Set_DecimalsNum(short index, short Param2);
	
public:
	int __fastcall OpenDataEx(short nType, int n1, int n2);
	Word __fastcall CloseData(short nType);
	int __fastcall DblClk(short nType, int lExtra);
	int __fastcall RigClk(short nType, int lExtra);
	int __fastcall Status(short nItems, int lpStatus);
	int __fastcall ShowDialog(short nDialog, int lExtra);
	int __fastcall PrintIt(void);
	HIDESBASE int __fastcall Scroll(int wParam, int lParam);
	int __fastcall SetStatusItem(short index, Word bText, short nID, Word bFrame, short nWidth, short nMin, short nDesp, int dwStyle);
	int __fastcall Paint(int hDC, short nLeft, short nTop, short nRight, short nBottom, short wAction, int lps);
	int __fastcall SetStripe(short index, double dMin, double dMax, unsigned rgb);
	int __fastcall Language(const WideString sResource);
	int __fastcall ExportFile(const WideString lpszNewValue);
	int __fastcall ImportFile(const WideString lpszNewValue);
	int __fastcall WriteTemplate(const WideString lpszNewValue);
	int __fastcall ReadTemplate(const WideString lpszNewValue);
	int __fastcall CopyData(void);
	int __fastcall CopyBitmap(void);
	HIDESBASE void __fastcall Refresh(void);
	void __fastcall AboutBox(void);
	__property _di__DChartfx ControlInterface = {read=GetControlInterface};
	__property _di__DChartfx DefaultInterface = {read=GetControlInterface};
	__property double Value[short index] = {read=Get_Value, write=Set_Value};
	__property double XValue[short index] = {read=Get_XValue, write=Set_XValue};
	__property double IniValue[short index] = {read=Get_IniValue, write=Set_IniValue};
	__property double Const_[short index] = {read=Get_Const_, write=Set_Const_};
	__property unsigned Color[short index] = {read=Get_Color, write=Set_Color};
	__property unsigned BkColor[short index] = {read=Get_BkColor, write=Set_BkColor};
	__property double Adm[short index] = {read=Get_Adm, write=Set_Adm};
	__property short Pattern[short index] = {read=Get_Pattern, write=Set_Pattern};
	__property int Fonts[short index] = {read=Get_Fonts, write=Set_Fonts};
	__property WideString Title[short index] = {read=Get_Title, write=Set_Title};
	__property WideString Legend[short index] = {read=Get_Legend, write=Set_Legend};
	__property WideString SerLeg[short index] = {read=Get_SerLeg, write=Set_SerLeg};
	__property WideString KeyLeg[short index] = {read=Get_KeyLeg, write=Set_KeyLeg};
	__property WideString FixLeg[short index] = {read=Get_FixLeg, write=Set_FixLeg};
	__property WideString YLeg[short index] = {read=Get_YLeg, write=Set_YLeg};
	__property WideString KeySer[short index] = {read=Get_KeySer, write=Set_KeySer};
	__property WideString StatusText[short index] = {read=Get_StatusText, write=Set_StatusText};
	__property unsigned RGBFont[short index] = {read=Get_RGBFont, write=Set_RGBFont};
	__property short HFont[short index] = {read=Get_HFont, write=Set_HFont};
	__property short ItemWidth[short index] = {read=Get_ItemWidth, write=Set_ItemWidth};
	__property short ItemStyle[short index] = {read=Get_ItemStyle, write=Set_ItemStyle};
	__property unsigned ItemColor[short index] = {read=Get_ItemColor, write=Set_ItemColor};
	__property short DecimalsNum[short index] = {read=Get_DecimalsNum, write=Set_DecimalsNum};
	
__published:
	__property TabStop  = {default=1};
	__property Align  = {default=0};
	__property DragCursor  = {default=-12};
	__property DragMode  = {default=0};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property Visible  = {default=1};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
	__property short DesignDraw = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=4, nodefault};
	__property short ThisSerie = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=1, nodefault};
	__property short ThisPoint = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=2, nodefault};
	__property Word AutoInvalidate = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=3, nodefault};
	__property int Type_ = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=5, nodefault};
	__property int Style = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=6, nodefault};
	__property short NSeries = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=7, nodefault};
	__property short NValues = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=8, nodefault};
	__property Graphics::TColor ThisColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=9, nodefault};
	__property Graphics::TColor ThisBkColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=10, nodefault};
	__property short LeftGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=11, nodefault};
	__property short RightGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=12, nodefault};
	__property short TopGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=13, nodefault};
	__property short BottomGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=14, nodefault};
	__property short Decimals = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=15, nodefault};
	__property short PointType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=16, nodefault};
	__property short Scheme = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=17, nodefault};
	__property short Stacked = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=18, nodefault};
	__property short Grid = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=19, nodefault};
	__property short WallWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=20, nodefault};
	__property short BarHorzGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=21, nodefault};
	__property Word View3D = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=22, nodefault};
	__property int Angles3D = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=23, nodefault};
	__property short PixFactor = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=24, nodefault};
	__property short LineWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=25, nodefault};
	__property short LineStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=26, nodefault};
	__property Graphics::TColor LineColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=27, nodefault};
	__property Graphics::TColor LineBkColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=28, nodefault};
	__property short FixedWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=29, nodefault};
	__property short FixedStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30, nodefault};
	__property Graphics::TColor FixedColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=31, nodefault};
	__property Graphics::TColor FixedBkColor = {read=GetTColorProp, write=SetTColorProp, stored=false, index=32, nodefault};
	__property short FixedGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=33, nodefault};
	__property Graphics::TColor RGBBarHorz = {read=GetTColorProp, write=SetTColorProp, stored=false, index=34, nodefault};
	__property Graphics::TColor RGBBk = {read=GetTColorProp, write=SetTColorProp, stored=false, index=35, nodefault};
	__property Graphics::TColor RGB2DBk = {read=GetTColorProp, write=SetTColorProp, stored=false, index=36, nodefault};
	__property Graphics::TColor RGB3DBk = {read=GetTColorProp, write=SetTColorProp, stored=false, index=37, nodefault};
	__property Word ShowStatus = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=38, nodefault};
	__property WideString HText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=39};
	__property short ChartStatus = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=40, nodefault};
	__property short Edit = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=41, nodefault};
	__property short ChartType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=42, nodefault};
	__property Word Chart3D = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=43, nodefault};
	__property Word ToolBar = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=44, nodefault};
	__property Word PaletteBar = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=45, nodefault};
	__property Word PatternBar = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=46, nodefault};
	__property int CustTool = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=47, nodefault};
	__property int ReturnValue = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=48, nodefault};
	__property Word AutoIncrement = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=49, nodefault};
	__property double ThisValue = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=50};
	__property short VertGridGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=51, nodefault};
	__property short XLegType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=52, nodefault};
	__property short ConstType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=53, nodefault};
	__property Graphics::TFont* LeftFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=54};
	__property Graphics::TFont* RightFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=55};
	__property Graphics::TFont* TopFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=56};
	__property Graphics::TFont* BottomFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=57};
	__property Graphics::TFont* XLegFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=58};
	__property Graphics::TFont* YLegFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=59};
	__property Graphics::TFont* FixedFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=60};
	__property Graphics::TFont* LegendFont = {read=GetTFontProp, write=SetTFontProp, stored=false, index=61};
	__property short LegendWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=62, nodefault};
	__property Word Enabled = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=-514, nodefault};
	__property int hWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=-515, nodefault};
	__property short BorderStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-504, nodefault};
	__property int hCtlWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=63, nodefault};
	__property TChartfxLButtonDblClk OnLButtonDblClk = {read=FOnLButtonDblClk, write=FOnLButtonDblClk};
	__property TChartfxRButtonDown OnRButtonDown = {read=FOnRButtonDown, write=FOnRButtonDown};
	__property TChartfxChangeValue OnChangeValue = {read=FOnChangeValue, write=FOnChangeValue};
	__property TChartfxChangeString OnChangeString = {read=FOnChangeString, write=FOnChangeString};
	__property TChartfxChangeColor OnChangeColor = {read=FOnChangeColor, write=FOnChangeColor};
	__property Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property Classes::TNotifyEvent OnReadFile = {read=FOnReadFile, write=FOnReadFile};
	__property TChartfxChangePalette OnChangePalette = {read=FOnChangePalette, write=FOnChangePalette};
	__property TChartfxChangeFont OnChangeFont = {read=FOnChangeFont, write=FOnChangeFont};
	__property Classes::TNotifyEvent OnReadTemplate = {read=FOnReadTemplate, write=FOnReadTemplate};
	__property TChartfxChangePattern OnChangePattern = {read=FOnChangePattern, write=FOnChangePattern};
	__property TChartfxChangePattPal OnChangePattPal = {read=FOnChangePattPal, write=FOnChangePattPal};
	__property TChartfxMenu OnMenu = {read=FOnMenu, write=FOnMenu};
	__property TChartfxChangeType OnChangeType = {read=FOnChangeType, write=FOnChangeType};
	__property TChartfxUserScroll OnUserScroll = {read=FOnUserScroll, write=FOnUserScroll};
	__property TChartfxGetLegend OnGetLegend = {read=FOnGetLegend, write=FOnGetLegend};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TChartfx(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TChartfx(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartfx(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint ChartfxLibMajorVersion = 0x2;
static const Shortint ChartfxLibMinorVersion = 0x0;
extern PACKAGE GUID LIBID_ChartfxLib;
extern PACKAGE GUID DIID__DChartfx;
extern PACKAGE GUID DIID__DChartfxEvents;
extern PACKAGE GUID CLASS_Chartfx;
static const Shortint CHART_NONEMK = 0x0;
static const Shortint CHART_RECTMK = 0x1;
static const Shortint CHART_CIRCLEMK = 0x2;
static const Shortint CHART_TRIANGLEMK = 0x3;
static const Shortint CHART_MARBLEMK = 0x4;
static const Shortint CHART_CUBEMK = 0x5;
static const Shortint CHART_MANYMK = 0x6;
static const Shortint CHART_CSSOLID = 0x0;
static const Shortint CHART_CSBWPATTERN = 0x1;
static const Shortint CHART_CSPATTERN = 0x2;
static const Shortint CHART_NOSTACKED = 0x0;
static const Shortint CHART_STACKED = 0x1;
static const Shortint CHART_STACKED100 = 0x2;
static const Shortint CHART_NOGRID = 0x0;
static const Shortint CHART_HORZGRID = 0x1;
static const Shortint CHART_VERTGRID = 0x2;
static const Shortint CHART_BOTHGRID = 0x3;
static const Shortint CHART_GRIDY2 = 0x4;
static const Shortint LINES = 0x1;
static const Shortint BAR = 0x2;
static const Shortint SPLINE = 0x3;
static const Shortint MARK = 0x4;
static const Shortint PIE = 0x5;
static const Shortint AREA = 0x6;
static const Shortint PARETO = 0x7;
static const Shortint SCATTER = 0x8;
static const Shortint HILOW = 0x9;
static const Shortint CC_HIDETEXT = 0x1;
static const Shortint CC_HIDE = 0x2;
static const Shortint CL_NOTCLIPPED = 0x1;
static const Shortint CL_NOTCHANGECOLOR = 0x2;
static const Shortint CL_HIDE = 0x4;
static const Shortint CL_HIDEXLEG = 0x4;
static const Shortint CL_FORCESERLEG = 0x8;
static const Shortint CL_GETLEGEND = 0x10;
static const Shortint CL_HIDEYLEG = 0x20;
static const Shortint COD_VALUES = 0x1;
static const Shortint COD_CONSTANTS = 0x2;
static const Shortint COD_COLORS = 0x3;
static const Shortint COD_STRIPES = 0x4;
static const Shortint COD_INIVALUES = 0x5;
static const Shortint COD_XVALUES = 0x6;
static const Shortint COD_STATUSITEMS = 0x7;
static const unsigned COD_UNKNOWN = 0xffffffff;
static const Shortint COD_UNCHANGE = 0x0;
static const Shortint CHART_BALLOONCLK = 0x0;
static const Shortint CHART_DIALOGCLK = 0x1;
static const Shortint CHART_NONECLK = 0x2;
static const Shortint CHART_MENUCLK = 0x3;
static const Shortint CDIALOG_EXPORTFILE = 0xe;
static const Shortint CDIALOG_IMPORTFILE = 0xf;
static const Shortint CDIALOG_WRITETEMPLATE = 0x8;
static const Shortint CDIALOG_READTEMPLATE = 0x9;
static const Shortint CDIALOG_PAGESETUP = 0x4;
static const Shortint CDIALOG_ABOUT = 0xb;
static const Shortint CDIALOG_OPTIONS = 0xc;
static const Shortint CDIALOG_EDITTITLES = 0x23;
static const Shortint CDIALOG_FONTS = 0x27;
static const Shortint CDIALOG_ROTATE = 0x34;
static const Shortint CSA_MIN = 0x0;
static const Shortint CSA_MAX = 0x1;
static const Shortint CSA_GAP = 0x2;
static const Shortint CSA_SCALE = 0x3;
static const Shortint CSA_YLEGGAP = 0x4;
static const Shortint CSA_PIXXVALUE = 0x5;
static const Shortint CSA_XMIN = 0x6;
static const Shortint CSA_XMAX = 0x7;
static const Shortint CSA_XGAP = 0x8;
static const Shortint CSA_LOGBASE = 0x9;
static const Shortint CHART_LEFTTIT = 0x0;
static const Shortint CHART_RIGHTTIT = 0x1;
static const Shortint CHART_TOPTIT = 0x2;
static const Shortint CHART_BOTTOMTIT = 0x3;
static const Shortint CHART_LEFTFT = 0x0;
static const Shortint CHART_RIGHTFT = 0x1;
static const Shortint CHART_TOPFT = 0x2;
static const Shortint CHART_BOTTOMFT = 0x3;
static const Shortint CHART_XLEGFT = 0x4;
static const Shortint CHART_YLEGFT = 0x5;
static const Shortint CHART_FIXEDFT = 0x6;
static const Shortint CHART_LEGENDFT = 0x7;
static const Shortint CI_HORZGRID = 0x0;
static const Shortint CI_VERTGRID = 0x1;
static const Shortint CD_ALL = 0x0;
static const Shortint CD_VALUES = 0x1;
static const Shortint CD_YLEG = 0x2;
static const Shortint CD_XLEG = 0x3;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Chartfx3 */
using namespace Chartfx3;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Chartfx3
