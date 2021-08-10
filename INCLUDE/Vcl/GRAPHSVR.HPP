// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GraphSvr.pas' rev: 6.00

#ifndef GraphSvrHPP
#define GraphSvrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <OleCtl.hpp>	// Pascal unit
#include <Ole2.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Graphsvr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TGraphicsServer;
class PASCALIMPLEMENTATION TGraphicsServer : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	short __stdcall Get_Color(short index);
	void __stdcall Set_Color(short index, short Value);
	float __stdcall Get_Data(short index);
	void __stdcall Set_Data(short index, float Value);
	short __stdcall Get_Extra(short index);
	void __stdcall Set_Extra(short index, short Value);
	short __stdcall Get_FFamily(short index);
	void __stdcall Set_FFamily(short index, short Value);
	short __stdcall Get_FSize(short index);
	void __stdcall Set_FSize(short index, short Value);
	short __stdcall Get_FStyle(short index);
	void __stdcall Set_FStyle(short index, short Value);
	AnsiString __stdcall Get_Label_(short index);
	void __stdcall Set_Label_(short index, const AnsiString Value);
	AnsiString __stdcall Get_Legend(short index);
	void __stdcall Set_Legend(short index, const AnsiString Value);
	short __stdcall Get_Pattern(short index);
	void __stdcall Set_Pattern(short index, short Value);
	short __stdcall Get_Symbol(short index);
	void __stdcall Set_Symbol(short index, short Value);
	float __stdcall Get_XPos(short index);
	void __stdcall Set_XPos(short index, float Value);
	
protected:
	virtual void __fastcall InitControlData(void);
	
public:
	HIDESBASE void __stdcall Refresh(void);
	void __stdcall AboutBox(void);
	__property Variant Picture = {read=GetVariantProp, write=SetVariantProp, index=35};
	__property AnsiString QuickData = {read=GetStringProp, write=SetStringProp, index=37};
	__property short SeeThru = {read=GetSmallintProp, write=SetSmallintProp, index=39, nodefault};
	__property short Color[short index] = {read=Get_Color, write=Set_Color};
	__property float Data[short index] = {read=Get_Data, write=Set_Data};
	__property short Extra[short index] = {read=Get_Extra, write=Set_Extra};
	__property short FFamily[short index] = {read=Get_FFamily, write=Set_FFamily};
	__property short FSize[short index] = {read=Get_FSize, write=Set_FSize};
	__property short FStyle[short index] = {read=Get_FStyle, write=Set_FStyle};
	__property AnsiString Label_[short index] = {read=Get_Label_, write=Set_Label_};
	__property AnsiString Legend[short index] = {read=Get_Legend, write=Set_Legend};
	__property short Pattern[short index] = {read=Get_Pattern, write=Set_Pattern};
	__property short Symbol[short index] = {read=Get_Symbol, write=Set_Symbol};
	__property float XPos[short index] = {read=Get_XPos, write=Set_XPos};
	
__published:
	__property TabStop  = {default=1};
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
	__property OnClick ;
	__property OnDblClick ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property Activex::TOleEnum AutoInc = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=1, nodefault};
	__property Activex::TOleEnum Background = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=2, nodefault};
	__property AnsiString BottomTitle = {read=GetStringProp, write=SetStringProp, stored=false, index=3};
	__property Activex::TOleEnum ColorData = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=4, nodefault};
	__property AnsiString CtlVersion = {read=GetStringProp, write=SetStringProp, stored=false, index=5};
	__property Activex::TOleEnum DataReset = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=6, nodefault};
	__property Activex::TOleEnum DrawMode = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=7, nodefault};
	__property Activex::TOleEnum DrawStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=8, nodefault};
	__property short ExtraData = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=9, nodefault};
	__property Activex::TOleEnum FontFamily = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=10, nodefault};
	__property short FontSize = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=11, nodefault};
	__property Activex::TOleEnum FontStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=12, nodefault};
	__property Activex::TOleEnum FontUse = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=13, nodefault};
	__property Activex::TOleEnum Foreground = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=14, nodefault};
	__property AnsiString GraphCaption = {read=GetStringProp, write=SetStringProp, stored=false, index=15};
	__property float GraphData = {read=GetSingleProp, write=SetSingleProp, stored=false, index=16};
	__property short GraphStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=17, nodefault};
	__property AnsiString GraphTitle = {read=GetStringProp, write=SetStringProp, stored=false, index=18};
	__property Activex::TOleEnum GraphType = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=19, nodefault};
	__property Activex::TOleEnum GridStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=20, nodefault};
	__property AnsiString ImageFile = {read=GetStringProp, write=SetStringProp, stored=false, index=21};
	__property Activex::TOleEnum IndexStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=22, nodefault};
	__property short LabelEvery = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=23, nodefault};
	__property Activex::TOleEnum Labels = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=24, nodefault};
	__property AnsiString LabelText = {read=GetStringProp, write=SetStringProp, stored=false, index=25};
	__property AnsiString LeftTitle = {read=GetStringProp, write=SetStringProp, stored=false, index=26};
	__property Activex::TOleEnum LegendStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=27, nodefault};
	__property AnsiString LegendText = {read=GetStringProp, write=SetStringProp, stored=false, index=28};
	__property Activex::TOleEnum LineStats = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=29, nodefault};
	__property short NumPoints = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30, nodefault};
	__property short NumSets = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=31, nodefault};
	__property Activex::TOleEnum Palette = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=32, nodefault};
	__property short PatternData = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=33, nodefault};
	__property Activex::TOleEnum PatternedLines = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=34, nodefault};
	__property Activex::TOleEnum PrintStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=36, nodefault};
	__property Activex::TOleEnum RandomData = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=38, nodefault};
	__property Activex::TOleEnum SymbolData = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=40, nodefault};
	__property Activex::TOleEnum ThickLines = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=41, nodefault};
	__property short ThisPoint = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=42, nodefault};
	__property short ThisSet = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=43, nodefault};
	__property short TickEvery = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=44, nodefault};
	__property Activex::TOleEnum Ticks = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=45, nodefault};
	__property float XPosData = {read=GetSingleProp, write=SetSingleProp, stored=false, index=46};
	__property float YAxisMax = {read=GetSingleProp, write=SetSingleProp, stored=false, index=47};
	__property float YAxisMin = {read=GetSingleProp, write=SetSingleProp, stored=false, index=48};
	__property Activex::TOleEnum YAxisPos = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=49, nodefault};
	__property Activex::TOleEnum YAxisStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=50, nodefault};
	__property short YAxisTicks = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=51, nodefault};
	__property Word Enabled = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=-514, nodefault};
	__property Activex::TOleEnum BorderStyle = {read=GetOleEnumProp, write=SetOleEnumProp, stored=false, index=-504, nodefault};
	__property int hWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=-515, nodefault};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TGraphicsServer(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TGraphicsServer(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGraphicsServer(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint gphOff = 0x0;
static const Shortint gphOn = 0x1;
static const Shortint gphBlack = 0x0;
static const Shortint gphBlue = 0x1;
static const Shortint gphGreen = 0x2;
static const Shortint gphCyan = 0x3;
static const Shortint gphRed = 0x4;
static const Shortint gphMagenta = 0x5;
static const Shortint gphBrown = 0x6;
static const Shortint gphLightGray = 0x7;
static const Shortint gphDarkGray = 0x8;
static const Shortint gphLightBlue = 0x9;
static const Shortint gphLightGreen = 0xa;
static const Shortint gphLightCyan = 0xb;
static const Shortint gphLightRed = 0xc;
static const Shortint gphLightMagenta = 0xd;
static const Shortint gphYellow = 0xe;
static const Shortint gphWhite = 0xf;
static const Shortint gphNone = 0x0;
static const Shortint gphGraphData = 0x1;
static const Shortint gphColorData = 0x2;
static const Shortint gphExtraData = 0x3;
static const Shortint gphLabelText = 0x4;
static const Shortint gphLegendText = 0x5;
static const Shortint gphPatternData = 0x6;
static const Shortint gphSymbolData = 0x7;
static const Shortint gphXPosData = 0x8;
static const Shortint gphAllData = 0x9;
static const Shortint gphFontInfo = 0xa;
static const Shortint gphNoAction = 0x0;
static const Shortint gphClear = 0x1;
static const Shortint gphDraw = 0x2;
static const Shortint gphBlit = 0x3;
static const Shortint gphCopy = 0x4;
static const Shortint gphPrint = 0x5;
static const Shortint gphWrite = 0x6;
static const Shortint gphMonochrome = 0x0;
static const Shortint gphColor = 0x1;
static const Shortint gphRoman = 0x0;
static const Shortint gphSwiss = 0x1;
static const Shortint gphModern = 0x2;
static const Shortint gphDefault = 0x0;
static const Shortint gphItalic = 0x1;
static const Shortint gphBold = 0x2;
static const Shortint gphBoldItalic = 0x3;
static const Shortint gphUnderlined = 0x4;
static const Shortint gphUnderlinedItalic = 0x5;
static const Shortint gphUnderlinedBold = 0x6;
static const Shortint gphUnderlinedBoldItalic = 0x7;
static const Shortint gphGraphTitle = 0x0;
static const Shortint gphOtherTitles = 0x1;
static const Shortint gphLabels = 0x2;
static const Shortint gphLegend = 0x3;
static const Shortint gphAllText = 0x4;
static const Shortint gphAutoBlackWhite = 0x10;
static const Shortint gphPie2D = 0x1;
static const Shortint gphPie3D = 0x2;
static const Shortint gphBar2D = 0x3;
static const Shortint gphBar3D = 0x4;
static const Shortint gphGantt = 0x5;
static const Shortint gphLine = 0x6;
static const Shortint gphLogLin = 0x7;
static const Shortint gphArea = 0x8;
static const Shortint gphScatter = 0x9;
static const Shortint gphPolar = 0xa;
static const Shortint gphHLC = 0xb;
static const Shortint gphHorizontal = 0x1;
static const Shortint gphVertical = 0x2;
static const Shortint gphBoth = 0x3;
static const Shortint gphStandard = 0x0;
static const Shortint gphEnhanced = 0x1;
static const Shortint gphXAxisLabelsOnly = 0x2;
static const Shortint gphYAxisLabelsOnly = 0x3;
static const Shortint gphMean = 0x1;
static const Shortint gphMinmax = 0x2;
static const Shortint gphMeanMinmax = 0x3;
static const Shortint gphStddev = 0x4;
static const Shortint gphStddevMean = 0x5;
static const Shortint gphStddevMinmax = 0x6;
static const Shortint gphStddevMinmaxMean = 0x7;
static const Shortint gphBestfit = 0x8;
static const Shortint gphBestfitMean = 0x9;
static const Shortint gphBestfitMinmax = 0xa;
static const Shortint gphBestfitMinmaxMean = 0xb;
static const Shortint gphBestfitStddev = 0xc;
static const Shortint gphBestfitStddevMean = 0xd;
static const Shortint gphBestfitStddevMinmax = 0xe;
static const Shortint gphAll = 0xf;
static const Shortint gphPastel = 0x1;
static const Shortint gphGrayscale = 0x2;
static const Shortint gphPatternOff = 0x0;
static const Shortint gphPatternOn = 0x1;
static const Shortint gphMonochromeWithBorder = 0x2;
static const Shortint gphColorWithBorder = 0x3;
static const Shortint gphCrossPlus = 0x0;
static const Shortint gphCrossTimes = 0x1;
static const Shortint gphTriangleUp = 0x2;
static const Shortint gphSolidTriangleUp = 0x3;
static const Shortint gphTriangleDown = 0x4;
static const Shortint gphSolidTriangleDown = 0x5;
static const Shortint gphSquare = 0x6;
static const Shortint gphSolidSquare = 0x7;
static const Shortint gphDiamond = 0x8;
static const Shortint gphSolidDiamond = 0x9;
static const Shortint gphLinesOff = 0x0;
static const Shortint gphLinesOn = 0x1;
static const Shortint gphTicksOff = 0x0;
static const Shortint gphTicksOn = 0x1;
static const Shortint gphXAxisTicksOnly = 0x2;
static const Shortint gphYAxisTicksOnly = 0x3;
static const Shortint gphAlignLeft = 0x1;
static const Shortint gphAlignRight = 0x2;
static const Shortint gphVariableOrigin = 0x1;
static const Shortint gphUserDefined = 0x2;
static const Shortint gphFixedSingle = 0x1;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Graphsvr */
using namespace Graphsvr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GraphSvr
