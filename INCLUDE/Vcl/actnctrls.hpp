// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ActnCtrls.pas' rev: 6.00

#ifndef ActnCtrlsHPP
#define ActnCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <GraphUtil.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ActnMan.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "dclact.lib"

namespace Actnctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomButtonControl;
class PASCALIMPLEMENTATION TCustomButtonControl : public Actnman::TCustomActionControl 
{
	typedef Actnman::TCustomActionControl inherited;
	
private:
	bool FAllowAllUp;
	bool FDown;
	bool FDragging;
	bool FMouseInControl;
	Controls::TMouseButton FTrackButton;
	void __fastcall SetDown(bool Value);
	void __fastcall SetAllowAllUp(bool Value);
	void __fastcall UpdateTracking(void);
	void __fastcall SetFlat(const bool Value);
	void __fastcall SetState(const Buttons::TButtonState Value);
	
protected:
	bool FFlat;
	Buttons::TButtonState FState;
	virtual void __fastcall DrawBackground(Types::TRect &PaintRect);
	virtual void __fastcall DrawDesignFocus(Types::TRect &PaintRect);
	virtual void __fastcall DrawFrame(const Types::TRect &ARect, bool Down);
	virtual void __fastcall DrawGlyph(const Types::TPoint &Location);
	virtual void __fastcall DrawText(Types::TRect &ARect, unsigned &Flags, AnsiString Text);
	virtual AnsiString __fastcall GetLabelText();
	virtual bool __fastcall GetShowShortCut(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetActionClient(Actnman::TActionClientItem* Value);
	virtual void __fastcall SetSelected(bool Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	__property bool MouseInControl = {read=FMouseInControl, nodefault};
	
public:
	__fastcall virtual TCustomButtonControl(Classes::TComponent* AOwner);
	virtual void __fastcall CalcBounds(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property bool AllowAllUp = {read=FAllowAllUp, write=SetAllowAllUp, nodefault};
	__property Caption ;
	__property bool Down = {read=FDown, write=SetDown, nodefault};
	__property bool Flat = {read=FFlat, write=SetFlat, nodefault};
	__property ShowCaption ;
	__property ShowShortCut ;
	__property Buttons::TButtonState State = {read=FState, write=SetState, nodefault};
	__property Controls::TMouseButton TrackButton = {read=FTrackButton, write=FTrackButton, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomActionControl.Destroy */ inline __fastcall virtual ~TCustomButtonControl(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomUtilityButton;
class PASCALIMPLEMENTATION TCustomUtilityButton : public TCustomButtonControl 
{
	typedef TCustomButtonControl inherited;
	
private:
	int FArrowSize;
	Graphutil::TScrollDirection FDirection;
	Extctrls::TTimer* FScrollTimer;
	Classes::TNotifyEvent FOnClick;
	int FRepeatRate;
	bool FAutoScroll;
	Graphutil::TArrowType FArrowType;
	void __fastcall SetArrowSize(const int Value);
	void __fastcall SetArrowType(const Graphutil::TArrowType Value);
	void __fastcall SetDirection(const Graphutil::TScrollDirection Value);
	
protected:
	virtual void __fastcall DrawArrows(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall OnDelay(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TCustomUtilityButton(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomUtilityButton(void);
	DYNAMIC void __fastcall Click(void);
	__property bool AutoScroll = {read=FAutoScroll, write=FAutoScroll, nodefault};
	__property int ArrowSize = {read=FArrowSize, write=SetArrowSize, nodefault};
	__property Graphutil::TArrowType ArrowType = {read=FArrowType, write=SetArrowType, nodefault};
	__property Color  = {default=-2147483643};
	__property Graphutil::TScrollDirection Direction = {read=FDirection, write=SetDirection, nodefault};
	__property int RepeatRate = {read=FRepeatRate, write=FRepeatRate, nodefault};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
};


class DELPHICLASS TCustomToolScrollBtn;
class PASCALIMPLEMENTATION TCustomToolScrollBtn : public TCustomUtilityButton 
{
	typedef TCustomUtilityButton inherited;
	
protected:
	virtual void __fastcall DrawArrows(void);
	virtual void __fastcall DrawBackground(Types::TRect &PaintRect);
public:
	#pragma option push -w-inl
	/* TCustomUtilityButton.Create */ inline __fastcall virtual TCustomToolScrollBtn(Classes::TComponent* AOwner) : TCustomUtilityButton(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomUtilityButton.Destroy */ inline __fastcall virtual ~TCustomToolScrollBtn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomDropDownButton;
class PASCALIMPLEMENTATION TCustomDropDownButton : public TCustomButtonControl 
{
	typedef TCustomButtonControl inherited;
	
private:
	bool FDroppedDown;
	HIDESBASE MESSAGE void __fastcall CMMouseleave(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall DrawFrame(const Types::TRect &ARect, bool Down);
	__property bool DroppedDown = {read=FDroppedDown, nodefault};
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	bool __fastcall MouseOverDropDown(void);
	virtual void __fastcall Paint(void);
	
public:
	virtual void __fastcall CalcBounds(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall DropDownClick(void);
public:
	#pragma option push -w-inl
	/* TCustomButtonControl.Create */ inline __fastcall virtual TCustomDropDownButton(Classes::TComponent* AOwner) : TCustomButtonControl(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomActionControl.Destroy */ inline __fastcall virtual ~TCustomDropDownButton(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomActionCombo;
class DELPHICLASS TCustomComboControl;
class PASCALIMPLEMENTATION TCustomComboControl : public Actnman::TCustomActionControl 
{
	typedef Actnman::TCustomActionControl inherited;
	
private:
	TCustomActionCombo* FComboBox;
	
protected:
	void __fastcall ComboClick(System::TObject* Sender);
	virtual void __fastcall DrawText(Types::TRect &ARect, unsigned &Flags, AnsiString Text);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	virtual void __fastcall SetActionClient(Actnman::TActionClientItem* Value);
	virtual void __fastcall SetDragMode(Controls::TDragMode Value);
	DYNAMIC void __fastcall VisibleChanging(void);
	HIDESBASE MESSAGE void __fastcall CMVisiblechanged(Messages::TMessage &Message);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TCustomComboControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomComboControl(void);
	virtual void __fastcall CalcBounds(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TCustomActionCombo* ComboBox = {read=FComboBox};
};


class PASCALIMPLEMENTATION TCustomActionCombo : public Comctrls::TCustomComboBoxEx 
{
	typedef Comctrls::TCustomComboBoxEx inherited;
	
private:
	TCustomComboControl* FComboControl;
	
protected:
	DYNAMIC void __fastcall BeginAutoDrag(void);
	DYNAMIC bool __fastcall DesignWndProc(Messages::TMessage &Message);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	virtual void __fastcall ComboWndProc(Messages::TMessage &Message, HWND ComboWnd, void * ComboProc);
	
public:
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
public:
	#pragma option push -w-inl
	/* TCustomComboBoxEx.Create */ inline __fastcall virtual TCustomActionCombo(Classes::TComponent* AOwner) : Comctrls::TCustomComboBoxEx(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomComboBoxEx.Destroy */ inline __fastcall virtual ~TCustomActionCombo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionCombo(HWND ParentWindow) : Comctrls::TCustomComboBoxEx(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomActionDockBar;
class PASCALIMPLEMENTATION TCustomActionDockBar : public Actnman::TCustomActionBar 
{
	typedef Actnman::TCustomActionBar inherited;
	
private:
	Controls::TDragDockObject* FDragObject;
	
protected:
	DYNAMIC void __fastcall DoEndDock(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDock(Controls::TDragObject* &DragObject);
	virtual TMetaClass* __fastcall GetFloatingDockSiteClass(void);
	DYNAMIC void __fastcall GetSiteInfo(Controls::TControl* Client, Types::TRect &InfluenceRect, const Types::TPoint &MousePos, bool &CanDock);
	virtual void __fastcall Loaded(void);
	
public:
	__fastcall virtual TCustomActionDockBar(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall Dock(Controls::TWinControl* NewDockSite, const Types::TRect &ARect);
public:
	#pragma option push -w-inl
	/* TCustomActionBar.Destroy */ inline __fastcall virtual ~TCustomActionDockBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionDockBar(HWND ParentWindow) : Actnman::TCustomActionBar(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomActionToolBar;
class PASCALIMPLEMENTATION TCustomActionToolBar : public TCustomActionDockBar 
{
	typedef TCustomActionDockBar inherited;
	
private:
	Contnrs::TStack* FHiddenItems;
	int FHideLevel;
	Actnman::TCustomActionBar* FPopupBar;
	TCustomToolScrollBtn* FScrollBtn;
	Graphics::TColor FShadowClr;
	Graphics::TColor FHighlightClr;
	int __fastcall GetHiddenCount(void);
	
protected:
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	virtual void __fastcall AutoSizingChanged(void);
	int __fastcall CalcButtonWidth(void);
	virtual Actnman::TCustomActionControl* __fastcall CreateControl(Actnman::TActionClientItem* AnItem);
	void __fastcall DisableHiding(void);
	virtual void __fastcall DoDropCategory(Actnman::TCategoryDragObject* Source, const int X, const int Y);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawSeparator(const int Pos, const int Offset);
	void __fastcall EnableHiding(void);
	virtual TMetaClass* __fastcall GetControlClass(Actnman::TActionClientItem* AnItem);
	void __fastcall HideUnusedItems(void);
	virtual void __fastcall Reset(void);
	void __fastcall ScrollBtnClick(System::TObject* Sender);
	virtual void __fastcall SetOrientation(const Actnman::TBarOrientation Value);
	void __fastcall SetupDropDownBtn(void);
	HIDESBASE MESSAGE void __fastcall CMColorchanged(Messages::TMessage &Message);
	
public:
	__fastcall virtual TCustomActionToolBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionToolBar(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property int HiddenCount = {read=GetHiddenCount, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionToolBar(HWND ParentWindow) : TCustomActionDockBar(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TActionToolBar;
class PASCALIMPLEMENTATION TActionToolBar : public TCustomActionToolBar 
{
	typedef TCustomActionToolBar inherited;
	
__published:
	__property ActionManager ;
	__property Align  = {default=1};
	__property AllowHiding ;
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Cursor  = {default=0};
	__property EdgeBorders  = {default=0};
	__property EdgeInner  = {default=1};
	__property EdgeOuter  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property HorzMargin  = {default=1};
	__property HorzSeparator ;
	__property Orientation ;
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PersistentHotKeys ;
	__property PopupMenu ;
	__property ShowHint ;
	__property Spacing ;
	__property VertMargin  = {default=1};
	__property Visible  = {default=1};
	__property OnControlCreated ;
	__property OnCanResize ;
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetControlClass ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnPaint ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomActionToolBar.Create */ inline __fastcall virtual TActionToolBar(Classes::TComponent* AOwner) : TCustomActionToolBar(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomActionToolBar.Destroy */ inline __fastcall virtual ~TActionToolBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TActionToolBar(HWND ParentWindow) : TCustomActionToolBar(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Actnctrls */
using namespace Actnctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActnCtrls
