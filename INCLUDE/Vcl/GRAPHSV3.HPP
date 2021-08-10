// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'GraphSv3.pas' rev: 6.00

#ifndef GraphSv3HPP
#define GraphSv3HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Graphsv3
{
//-- type declarations -------------------------------------------------------
__dispinterface _DGraph;
typedef System::DelphiInterface<_DGraph> _di__DGraph;
typedef _DGraph Graph;
;

typedef Activex::TOleEnum AutoIncConstants;

typedef Activex::TOleEnum BackgroundConstants;

typedef Activex::TOleEnum ColorDataConstants;

typedef Activex::TOleEnum DataResetConstants;

typedef Activex::TOleEnum DrawModeConstants;

typedef Activex::TOleEnum DrawStyleConstants;

typedef Activex::TOleEnum FontFamilyConstants;

typedef Activex::TOleEnum FontStyleConstants;

typedef Activex::TOleEnum FontUseConstants;

typedef Activex::TOleEnum ForegroundConstants;

typedef Activex::TOleEnum GraphTypeConstants;

typedef Activex::TOleEnum GridStyleConstants;

typedef Activex::TOleEnum IndexStyleConstants;

typedef Activex::TOleEnum LabelsConstants;

typedef Activex::TOleEnum LegendStyleConstants;

typedef Activex::TOleEnum LineStatsConstants;

typedef Activex::TOleEnum PaletteConstants;

typedef Activex::TOleEnum PatternedLinesConstants;

typedef Activex::TOleEnum PrintStyleConstants;

typedef Activex::TOleEnum RandomDataConstants;

typedef Activex::TOleEnum SymbolDataConstants;

typedef Activex::TOleEnum ThickLinesConstants;

typedef Activex::TOleEnum TicksConstants;

typedef Activex::TOleEnum YAxisPosConstants;

typedef Activex::TOleEnum YAxisStyleConstants;

typedef Activex::TOleEnum BorderStyleConstants;

__dispinterface INTERFACE_UUID("{0842D101-1E19-101B-9AAF-1A1626551E7C}") _DGraph  : public IDispatch 
{
	
};

__dispinterface _DGraphEvents;
typedef System::DelphiInterface<_DGraphEvents> _di__DGraphEvents;
__dispinterface INTERFACE_UUID("{0842D102-1E19-101B-9AAF-1A1626551E7C}") _DGraphEvents  : public IDispatch 
{
	
};

class DELPHICLASS TGraph;
class PASCALIMPLEMENTATION TGraph : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	_di__DGraph FIntf;
	unsigned __fastcall Get_hWnd(void);
	void __fastcall Set_hWnd(const unsigned Value);
	short __fastcall Get_Color(short index);
	void __fastcall Set_Color(short index, short Value);
	float __fastcall Get_Data(short index);
	void __fastcall Set_Data(short index, float Value);
	short __fastcall Get_Extra(short index);
	void __fastcall Set_Extra(short index, short Value);
	short __fastcall Get_FFamily(short index);
	void __fastcall Set_FFamily(short index, short Value);
	short __fastcall Get_FSize(short index);
	void __fastcall Set_FSize(short index, short Value);
	short __fastcall Get_FStyle(short index);
	void __fastcall Set_FStyle(short index, short Value);
	WideString __fastcall Get_Label_(short index);
	void __fastcall Set_Label_(short index, const WideString Value);
	WideString __fastcall Get_Legend(short index);
	void __fastcall Set_Legend(short index, const WideString Value);
	short __fastcall Get_Pattern(short index);
	void __fastcall Set_Pattern(short index, short Value);
	short __fastcall Get_Symbol(short index);
	void __fastcall Set_Symbol(short index, short Value);
	float __fastcall Get_XPos(short index);
	void __fastcall Set_XPos(short index, float Value);
	
protected:
	virtual void __fastcall InitControlData(void);
	virtual void __fastcall InitControlInterface(const System::_di_IInterface Obj);
	
public:
	HIDESBASE void __fastcall Refresh(void);
	void __fastcall AboutBox(void);
	__property _di__DGraph ControlInterface = {read=FIntf};
	__property Graphics::TPicture* Picture = {read=GetTPictureProp, write=SetTPictureProp, index=35};
	__property WideString QuickData = {read=GetWideStringProp, write=SetWideStringProp, index=37};
	__property short SeeThru = {read=GetSmallintProp, write=SetSmallintProp, index=39, nodefault};
	__property WideString _QuickData = {read=GetWideStringProp, write=SetWideStringProp, index=0};
	__property short Color[short index] = {read=Get_Color, write=Set_Color};
	__property float Data[short index] = {read=Get_Data, write=Set_Data};
	__property short Extra[short index] = {read=Get_Extra, write=Set_Extra};
	__property short FFamily[short index] = {read=Get_FFamily, write=Set_FFamily};
	__property short FSize[short index] = {read=Get_FSize, write=Set_FSize};
	__property short FStyle[short index] = {read=Get_FStyle, write=Set_FStyle};
	__property WideString Label_[short index] = {read=Get_Label_, write=Set_Label_};
	__property WideString Legend[short index] = {read=Get_Legend, write=Set_Legend};
	__property short Pattern[short index] = {read=Get_Pattern, write=Set_Pattern};
	__property short Symbol[short index] = {read=Get_Symbol, write=Set_Symbol};
	__property float XPos[short index] = {read=Get_XPos, write=Set_XPos};
	
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
	__property OnMouseUp ;
	__property OnMouseMove ;
	__property OnMouseDown ;
	__property OnKeyUp ;
	__property OnKeyPress ;
	__property OnKeyDown ;
	__property OnDblClick ;
	__property OnClick ;
	__property Activex::TOleEnum AutoInc = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=1, nodefault};
	__property Activex::TOleEnum Background = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=2, nodefault};
	__property WideString BottomTitle = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=3};
	__property Activex::TOleEnum ColorData = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=4, nodefault};
	__property WideString CtlVersion = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=5};
	__property Activex::TOleEnum DataReset = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=6, nodefault};
	__property Activex::TOleEnum DrawMode = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=7, nodefault};
	__property Activex::TOleEnum DrawStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=8, nodefault};
	__property short ExtraData = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=9, nodefault};
	__property Activex::TOleEnum FontFamily = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=10, nodefault};
	__property short FontSize = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=11, nodefault};
	__property Activex::TOleEnum FontStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=12, nodefault};
	__property Activex::TOleEnum FontUse = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=13, nodefault};
	__property Activex::TOleEnum Foreground = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=14, nodefault};
	__property WideString GraphCaption = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=15};
	__property float GraphData = {read=GetSingleProp, write=SetSingleProp, stored=false, index=16};
	__property short GraphStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=17, nodefault};
	__property WideString GraphTitle = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=18};
	__property Activex::TOleEnum GraphType = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=19, nodefault};
	__property Activex::TOleEnum GridStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=20, nodefault};
	__property WideString ImageFile = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=21};
	__property Activex::TOleEnum IndexStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=22, nodefault};
	__property short LabelEvery = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=23, nodefault};
	__property Activex::TOleEnum Labels = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=24, nodefault};
	__property WideString LabelText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=25};
	__property WideString LeftTitle = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=26};
	__property Activex::TOleEnum LegendStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=27, nodefault};
	__property WideString LegendText = {read=GetWideStringProp, write=SetWideStringProp, stored=false, index=28};
	__property Activex::TOleEnum LineStats = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=29, nodefault};
	__property short NumPoints = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30, nodefault};
	__property short NumSets = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=31, nodefault};
	__property Activex::TOleEnum Palette = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=32, nodefault};
	__property short PatternData = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=33, nodefault};
	__property Activex::TOleEnum PatternedLines = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=34, nodefault};
	__property Activex::TOleEnum PrintStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=36, nodefault};
	__property Activex::TOleEnum RandomData = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=38, nodefault};
	__property Activex::TOleEnum SymbolData = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=40, nodefault};
	__property Activex::TOleEnum ThickLines = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=41, nodefault};
	__property short ThisPoint = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=42, nodefault};
	__property short ThisSet = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=43, nodefault};
	__property short TickEvery = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=44, nodefault};
	__property Activex::TOleEnum Ticks = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=45, nodefault};
	__property float XPosData = {read=GetSingleProp, write=SetSingleProp, stored=false, index=46};
	__property float YAxisMax = {read=GetSingleProp, write=SetSingleProp, stored=false, index=47};
	__property float YAxisMin = {read=GetSingleProp, write=SetSingleProp, stored=false, index=48};
	__property Activex::TOleEnum YAxisPos = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=49, nodefault};
	__property Activex::TOleEnum YAxisStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=50, nodefault};
	__property short YAxisTicks = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=51, nodefault};
	__property Word Enabled = {read=GetWordBoolProp, write=SetWordBoolProp, stored=false, index=-514, nodefault};
	__property Activex::TOleEnum BorderStyle = {read=GetTOleEnumProp, write=SetTOleEnumProp, stored=false, index=-504, nodefault};
	__property unsigned hWnd = {read=Get_hWnd, write=Set_hWnd, stored=false, nodefault};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TGraph(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TGraph(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGraph(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID LIBID_GraphLib;
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
extern PACKAGE GUID Class_Graph;
extern PACKAGE void __fastcall Register(void);

}	/* namespace Graphsv3 */
using namespace Graphsv3;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// GraphSv3
