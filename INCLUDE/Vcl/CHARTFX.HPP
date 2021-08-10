// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Chartfx.pas' rev: 6.00

#ifndef ChartfxHPP
#define ChartfxHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
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

namespace Chartfx
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TChartFXLButtonDblClk)(System::TObject* Sender, short &X, short &Y, short &nSerie, short &nPoint, short &nRes);

typedef void __fastcall (__closure *TChartFXRButtonDown)(System::TObject* Sender, short &X, short &Y, short &nSerie, short &nPoint, short &nRes);

typedef void __fastcall (__closure *TChartFXChangeValue)(System::TObject* Sender, double &dValue, short &nSerie, short &nPoint, short &nRes);

typedef void __fastcall (__closure *TChartFXChangeString)(System::TObject* Sender, short &nType, short &nIndex, short &nRes);

typedef void __fastcall (__closure *TChartFXChangeColor)(System::TObject* Sender, short &nType, short &nIndex, short &nRes);

typedef void __fastcall (__closure *TChartFXChangePalette)(System::TObject* Sender, short &nIndex, short &nRes);

typedef void __fastcall (__closure *TChartFXChangeFont)(System::TObject* Sender, short &nIndex, short &nRes);

typedef void __fastcall (__closure *TChartFXChangePattern)(System::TObject* Sender, short &nType, short &nIndex, short &nRes);

typedef void __fastcall (__closure *TChartFXChangePattPal)(System::TObject* Sender, short &nIndex, short &nRes);

typedef void __fastcall (__closure *TChartFXMenu)(System::TObject* Sender, short &wParam, short &nSerie, short &nPoint, short &nRes);

typedef void __fastcall (__closure *TChartFXChangeType)(System::TObject* Sender, short &nType, short &nRes);

typedef void __fastcall (__closure *TChartFXUserScroll)(System::TObject* Sender, int wScrollMsg, int wScrollParam, short &nRes);

typedef void __fastcall (__closure *TChartFXGetLegend)(System::TObject* Sender, short nType, short &nRes);

class DELPHICLASS TChartFX;
class PASCALIMPLEMENTATION TChartFX : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TChartFXLButtonDblClk FOnLButtonDblClk;
	TChartFXRButtonDown FOnRButtonDown;
	TChartFXChangeValue FOnChangeValue;
	TChartFXChangeString FOnChangeString;
	TChartFXChangeColor FOnChangeColor;
	Classes::TNotifyEvent FOnDestroy;
	Classes::TNotifyEvent FOnReadFile;
	TChartFXChangePalette FOnChangePalette;
	TChartFXChangeFont FOnChangeFont;
	Classes::TNotifyEvent FOnReadTemplate;
	TChartFXChangePattern FOnChangePattern;
	TChartFXChangePattPal FOnChangePattPal;
	TChartFXMenu FOnMenu;
	TChartFXChangeType FOnChangeType;
	TChartFXUserScroll FOnUserScroll;
	TChartFXGetLegend FOnGetLegend;
	double __stdcall Get_Value(short index);
	void __stdcall Set_Value(short index, double Value);
	double __stdcall Get_XValue(short index);
	void __stdcall Set_XValue(short index, double Value);
	double __stdcall Get_IniValue(short index);
	void __stdcall Set_IniValue(short index, double Value);
	double __stdcall Get_Const_(short index);
	void __stdcall Set_Const_(short index, double Value);
	Graphics::TColor __stdcall Get_Color(short index);
	void __stdcall Set_Color(short index, Graphics::TColor Value);
	Graphics::TColor __stdcall Get_BkColor(short index);
	void __stdcall Set_BkColor(short index, Graphics::TColor Value);
	double __stdcall Get_Adm(short index);
	void __stdcall Set_Adm(short index, double Value);
	short __stdcall Get_Pattern(short index);
	void __stdcall Set_Pattern(short index, short Value);
	int __stdcall Get_Fonts(short index);
	void __stdcall Set_Fonts(short index, int Value);
	AnsiString __stdcall Get_Title(short index);
	void __stdcall Set_Title(short index, const AnsiString Value);
	AnsiString __stdcall Get_Legend(short index);
	void __stdcall Set_Legend(short index, const AnsiString Value);
	AnsiString __stdcall Get_SerLeg(short index);
	void __stdcall Set_SerLeg(short index, const AnsiString Value);
	AnsiString __stdcall Get_KeyLeg(short index);
	void __stdcall Set_KeyLeg(short index, const AnsiString Value);
	AnsiString __stdcall Get_FixLeg(short index);
	void __stdcall Set_FixLeg(short index, const AnsiString Value);
	AnsiString __stdcall Get_YLeg(short index);
	void __stdcall Set_YLeg(short index, const AnsiString Value);
	AnsiString __stdcall Get_KeySer(short index);
	void __stdcall Set_KeySer(short index, const AnsiString Value);
	AnsiString __stdcall Get_StatusText(short index);
	void __stdcall Set_StatusText(short index, const AnsiString Value);
	Graphics::TColor __stdcall Get_RGBFont(short index);
	void __stdcall Set_RGBFont(short index, Graphics::TColor Value);
	short __stdcall Get_HFont(short index);
	void __stdcall Set_HFont(short index, short Value);
	short __stdcall Get_ItemWidth(short index);
	void __stdcall Set_ItemWidth(short index, short Value);
	short __stdcall Get_ItemStyle(short index);
	void __stdcall Set_ItemStyle(short index, short Value);
	Graphics::TColor __stdcall Get_ItemColor(short index);
	void __stdcall Set_ItemColor(short index, Graphics::TColor Value);
	short __stdcall Get_DecimalsNum(short index);
	void __stdcall Set_DecimalsNum(short index, short Value);
	
protected:
	virtual void __fastcall InitControlData(void);
	
public:
	int __stdcall OpenDataEx(short nType, int n1, int n2);
	Word __stdcall CloseData(short nType);
	int __stdcall DblClk(short nType, int lExtra);
	int __stdcall RigClk(short nType, int lExtra);
	int __stdcall Status(short nItems, int lpStatus);
	int __stdcall ShowDialog(short nDialog, int lExtra);
	int __stdcall PrintIt(void);
	HIDESBASE int __stdcall Scroll(int wParam, int lParam);
	int __stdcall SetStatusItem(short index, Word bText, short nID, Word bFrame, short nWidth, short nMin, short nDesp, int dwStyle);
	int __stdcall Paint(int hDC, short nLeft, short nTop, short nRight, short nBottom, short wAction, int lps);
	int __stdcall SetStripe(short index, double dMin, double dMax, Graphics::TColor rgb);
	int __stdcall Language(const AnsiString sResource);
	int __stdcall ExportFile(const AnsiString lpszNewValue);
	int __stdcall ImportFile(const AnsiString lpszNewValue);
	int __stdcall WriteTemplate(const AnsiString lpszNewValue);
	int __stdcall ReadTemplate(const AnsiString lpszNewValue);
	int __stdcall CopyData(void);
	int __stdcall CopyBitmap(void);
	HIDESBASE void __stdcall Refresh(void);
	void __stdcall AboutBox(void);
	__property double Value[short index] = {read=Get_Value, write=Set_Value};
	__property double XValue[short index] = {read=Get_XValue, write=Set_XValue};
	__property double IniValue[short index] = {read=Get_IniValue, write=Set_IniValue};
	__property double Const_[short index] = {read=Get_Const_, write=Set_Const_};
	__property Graphics::TColor Color[short index] = {read=Get_Color, write=Set_Color};
	__property Graphics::TColor BkColor[short index] = {read=Get_BkColor, write=Set_BkColor};
	__property double Adm[short index] = {read=Get_Adm, write=Set_Adm};
	__property short Pattern[short index] = {read=Get_Pattern, write=Set_Pattern};
	__property int Fonts[short index] = {read=Get_Fonts, write=Set_Fonts};
	__property AnsiString Title[short index] = {read=Get_Title, write=Set_Title};
	__property AnsiString Legend[short index] = {read=Get_Legend, write=Set_Legend};
	__property AnsiString SerLeg[short index] = {read=Get_SerLeg, write=Set_SerLeg};
	__property AnsiString KeyLeg[short index] = {read=Get_KeyLeg, write=Set_KeyLeg};
	__property AnsiString FixLeg[short index] = {read=Get_FixLeg, write=Set_FixLeg};
	__property AnsiString YLeg[short index] = {read=Get_YLeg, write=Set_YLeg};
	__property AnsiString KeySer[short index] = {read=Get_KeySer, write=Set_KeySer};
	__property AnsiString StatusText[short index] = {read=Get_StatusText, write=Set_StatusText};
	__property Graphics::TColor RGBFont[short index] = {read=Get_RGBFont, write=Set_RGBFont};
	__property short HFont[short index] = {read=Get_HFont, write=Set_HFont};
	__property short ItemWidth[short index] = {read=Get_ItemWidth, write=Set_ItemWidth};
	__property short ItemStyle[short index] = {read=Get_ItemStyle, write=Set_ItemStyle};
	__property Graphics::TColor ItemColor[short index] = {read=Get_ItemColor, write=Set_ItemColor};
	__property short DecimalsNum[short index] = {read=Get_DecimalsNum, write=Set_DecimalsNum};
	
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
	__property short DesignDraw = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=4, nodefault};
	__property short ThisSerie = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=1, nodefault};
	__property short ThisPoint = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=2, nodefault};
	__property Word AutoInvalidate = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=3, nodefault};
	__property int Type_ = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=5, nodefault};
	__property int Style = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=6, nodefault};
	__property short NSeries = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=7, nodefault};
	__property short NValues = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=8, nodefault};
	__property Graphics::TColor ThisColor = {read=GetColorProp, write=SetColorProp, stored=false, index=9, nodefault};
	__property Graphics::TColor ThisBkColor = {read=GetColorProp, write=SetColorProp, stored=false, index=10, nodefault};
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
	__property Word View3D = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=22, nodefault};
	__property int Angles3D = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=23, nodefault};
	__property short PixFactor = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=24, nodefault};
	__property short LineWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=25, nodefault};
	__property short LineStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=26, nodefault};
	__property Graphics::TColor LineColor = {read=GetColorProp, write=SetColorProp, stored=false, index=27, nodefault};
	__property Graphics::TColor LineBkColor = {read=GetColorProp, write=SetColorProp, stored=false, index=28, nodefault};
	__property short FixedWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=29, nodefault};
	__property short FixedStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=30, nodefault};
	__property Graphics::TColor FixedColor = {read=GetColorProp, write=SetColorProp, stored=false, index=31, nodefault};
	__property Graphics::TColor FixedBkColor = {read=GetColorProp, write=SetColorProp, stored=false, index=32, nodefault};
	__property short FixedGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=33, nodefault};
	__property Graphics::TColor RGBBarHorz = {read=GetColorProp, write=SetColorProp, stored=false, index=34, nodefault};
	__property Graphics::TColor RGBBk = {read=GetColorProp, write=SetColorProp, stored=false, index=35, nodefault};
	__property Graphics::TColor RGB2DBk = {read=GetColorProp, write=SetColorProp, stored=false, index=36, nodefault};
	__property Graphics::TColor RGB3DBk = {read=GetColorProp, write=SetColorProp, stored=false, index=37, nodefault};
	__property Word ShowStatus = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=38, nodefault};
	__property AnsiString HText = {read=GetStringProp, write=SetStringProp, stored=false, index=39};
	__property short ChartStatus = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=40, nodefault};
	__property short Edit = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=41, nodefault};
	__property short ChartType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=42, nodefault};
	__property Word Chart3D = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=43, nodefault};
	__property Word ToolBar = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=44, nodefault};
	__property Word PaletteBar = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=45, nodefault};
	__property Word PatternBar = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=46, nodefault};
	__property int CustTool = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=47, nodefault};
	__property int ReturnValue = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=48, nodefault};
	__property Word AutoIncrement = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=49, nodefault};
	__property double ThisValue = {read=GetDoubleProp, write=SetDoubleProp, stored=false, index=50};
	__property short VertGridGap = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=51, nodefault};
	__property short XLegType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=52, nodefault};
	__property short ConstType = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=53, nodefault};
	__property Variant LeftFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=54};
	__property Variant RightFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=55};
	__property Variant TopFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=56};
	__property Variant BottomFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=57};
	__property Variant XLegFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=58};
	__property Variant YLegFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=59};
	__property Variant FixedFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=60};
	__property Variant LegendFont = {read=GetVariantProp, write=SetVariantProp, stored=false, index=61};
	__property short LegendWidth = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=62, nodefault};
	__property Word Enabled = {read=GetOleBoolProp, write=SetOleBoolProp, stored=false, index=-514, nodefault};
	__property int hWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=-515, nodefault};
	__property short BorderStyle = {read=GetSmallintProp, write=SetSmallintProp, stored=false, index=-504, nodefault};
	__property int hCtlWnd = {read=GetIntegerProp, write=SetIntegerProp, stored=false, index=63, nodefault};
	__property TChartFXLButtonDblClk OnLButtonDblClk = {read=FOnLButtonDblClk, write=FOnLButtonDblClk};
	__property TChartFXRButtonDown OnRButtonDown = {read=FOnRButtonDown, write=FOnRButtonDown};
	__property TChartFXChangeValue OnChangeValue = {read=FOnChangeValue, write=FOnChangeValue};
	__property TChartFXChangeString OnChangeString = {read=FOnChangeString, write=FOnChangeString};
	__property TChartFXChangeColor OnChangeColor = {read=FOnChangeColor, write=FOnChangeColor};
	__property Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property Classes::TNotifyEvent OnReadFile = {read=FOnReadFile, write=FOnReadFile};
	__property TChartFXChangePalette OnChangePalette = {read=FOnChangePalette, write=FOnChangePalette};
	__property TChartFXChangeFont OnChangeFont = {read=FOnChangeFont, write=FOnChangeFont};
	__property Classes::TNotifyEvent OnReadTemplate = {read=FOnReadTemplate, write=FOnReadTemplate};
	__property TChartFXChangePattern OnChangePattern = {read=FOnChangePattern, write=FOnChangePattern};
	__property TChartFXChangePattPal OnChangePattPal = {read=FOnChangePattPal, write=FOnChangePattPal};
	__property TChartFXMenu OnMenu = {read=FOnMenu, write=FOnMenu};
	__property TChartFXChangeType OnChangeType = {read=FOnChangeType, write=FOnChangeType};
	__property TChartFXUserScroll OnUserScroll = {read=FOnUserScroll, write=FOnUserScroll};
	__property TChartFXGetLegend OnGetLegend = {read=FOnGetLegend, write=FOnGetLegend};
public:
	#pragma option push -w-inl
	/* TOleControl.Create */ inline __fastcall virtual TChartFX(Classes::TComponent* AOwner) : Olectrls::TOleControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOleControl.Destroy */ inline __fastcall virtual ~TChartFX(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TChartFX(HWND ParentWindow) : Olectrls::TOleControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Chartfx */
using namespace Chartfx;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Chartfx
