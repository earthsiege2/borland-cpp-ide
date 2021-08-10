// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QButtons.pas' rev: 6.00

#ifndef QButtonsHPP
#define QButtonsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QMenus.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qbuttons
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TCMButtonPressed
{
	unsigned Msg;
	Qcontrols::TControl* Control;
	int Index;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TButtonLayout { blGlyphLeft, blGlyphRight, blGlyphTop, blGlyphBottom };
#pragma option pop

#pragma option push -b-
enum TButtonState { bsUp, bsDisabled, bsDown, bsExclusive };
#pragma option pop

typedef Shortint TNumGlyphs;

class DELPHICLASS TSpeedButton;
class PASCALIMPLEMENTATION TSpeedButton : public Qcontrols::TGraphicControl 
{
	typedef Qcontrols::TGraphicControl inherited;
	
private:
	int FGroupIndex;
	void *FGlyph;
	bool FDown;
	bool FDragging;
	bool FAllowAllUp;
	TButtonLayout FLayout;
	int FSpacing;
	bool FTransparent;
	int FMargin;
	bool FFlat;
	bool FMouseInControl;
	WideString FCaption;
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall UpdateExclusive(void);
	Qgraphics::TBitmap* __fastcall GetGlyph(void);
	void __fastcall SetGlyph(Qgraphics::TBitmap* Value);
	TNumGlyphs __fastcall GetNumGlyphs(void);
	void __fastcall SetNumGlyphs(TNumGlyphs Value);
	void __fastcall SetDown(bool Value);
	void __fastcall SetFlat(bool Value);
	void __fastcall SetAllowAllUp(bool Value);
	void __fastcall SetGroupIndex(int Value);
	void __fastcall SetLayout(TButtonLayout Value);
	void __fastcall SetSpacing(int Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetMargin(int Value);
	bool __fastcall IsGlyphStored(void);
	
protected:
	TButtonState FState;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	void __fastcall ButtonPressed(TSpeedButton* Sender, int GroupIndex);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	virtual WideString __fastcall GetText();
	DYNAMIC void __fastcall FontChanged(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Qcontrols::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Qcontrols::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetText(const WideString Value);
	DYNAMIC void __fastcall TextChanged(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	
public:
	__fastcall virtual TSpeedButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TSpeedButton(void);
	DYNAMIC void __fastcall Click(void);
	
__published:
	__property Action ;
	__property Anchors  = {default=3};
	__property bool AllowAllUp = {read=FAllowAllUp, write=SetAllowAllUp, default=0};
	__property Constraints ;
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property bool Down = {read=FDown, write=SetDown, default=0};
	__property DragMode  = {default=0};
	__property Caption ;
	__property Enabled  = {default=1};
	__property bool Flat = {read=FFlat, write=SetFlat, default=0};
	__property Font ;
	__property Qgraphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph, stored=IsGlyphStored};
	__property TButtonLayout Layout = {read=FLayout, write=SetLayout, default=0};
	__property int Margin = {read=FMargin, write=SetMargin, default=-1};
	__property TNumGlyphs NumGlyphs = {read=GetNumGlyphs, write=SetNumGlyphs, default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=4};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
};


#pragma option push -b-
enum TBitBtnKind { bkCustom, bkOK, bkCancel, bkHelp, bkYes, bkNo, bkClose, bkAbort, bkRetry, bkIgnore, bkAll };
#pragma option pop

class DELPHICLASS TBitBtn;
class PASCALIMPLEMENTATION TBitBtn : public Qstdctrls::TButton 
{
	typedef Qstdctrls::TButton inherited;
	
private:
	Qgraphics::TCanvas* FCanvas;
	void *FGlyph;
	TBitBtnKind FKind;
	TButtonLayout FLayout;
	int FSpacing;
	int FMargin;
	bool FModifiedGlyph;
	void __fastcall SetGlyph(Qgraphics::TBitmap* Value);
	Qgraphics::TBitmap* __fastcall GetGlyph(void);
	TNumGlyphs __fastcall GetNumGlyphs(void);
	void __fastcall SetNumGlyphs(TNumGlyphs Value);
	void __fastcall GlyphChanged(System::TObject* Sender);
	bool __fastcall IsCustom(void);
	bool __fastcall IsCustomCaption(void);
	void __fastcall SetKind(TBitBtnKind Value);
	TBitBtnKind __fastcall GetKind(void);
	void __cdecl PaintHook(Qt::QPainterH* p, Types::PRect R);
	void __fastcall SetLayout(TButtonLayout Value);
	void __fastcall SetSpacing(int Value);
	void __fastcall SetMargin(int Value);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	
public:
	__fastcall virtual TBitBtn(Classes::TComponent* AOwner);
	__fastcall virtual ~TBitBtn(void);
	DYNAMIC void __fastcall Click(void);
	
__published:
	__property Action ;
	__property Anchors  = {default=3};
	__property Cancel  = {stored=IsCustom, default=0};
	__property Caption  = {stored=IsCustomCaption};
	__property Constraints ;
	__property Default  = {stored=IsCustom, default=0};
	__property Enabled  = {default=1};
	__property Qgraphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph, stored=IsCustom};
	__property TBitBtnKind Kind = {read=GetKind, write=SetKind, default=0};
	__property TButtonLayout Layout = {read=FLayout, write=SetLayout, default=0};
	__property int Margin = {read=FMargin, write=SetMargin, default=-1};
	__property ModalResult  = {stored=IsCustom, default=0};
	__property TNumGlyphs NumGlyphs = {read=GetNumGlyphs, write=SetNumGlyphs, stored=IsCustom, default=1};
	__property ParentShowHint  = {default=1};
	__property ShowHint  = {default=0};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=4};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnEnter ;
	__property OnExit ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TBitBtn(Qt::QWidgetH* ParentWidget) : Qstdctrls::TButton(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word CM_BUTTONPRESSED = 0xb064;
extern PACKAGE Types::TRect __fastcall DrawButtonFace(Qgraphics::TCanvas* Canvas, const Types::TRect &Client, int BevelWidth, bool IsDown, bool IsFocused, bool Flat = false, Qgraphics::TColor FillColor = (Qgraphics::TColor)(0xfffffffe), Qgraphics::TBrushStyle FillStyle = (Qgraphics::TBrushStyle)(0x0));

}	/* namespace Qbuttons */
using namespace Qbuttons;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QButtons
