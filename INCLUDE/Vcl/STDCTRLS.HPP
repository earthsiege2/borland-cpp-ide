// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StdCtrls.pas' rev: 5.00

#ifndef StdCtrlsHPP
#define StdCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stdctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomGroupBox;
class PASCALIMPLEMENTATION TCustomGroupBox : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(Windows::TRect &Rect);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TCustomGroupBox(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TCustomGroupBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomGroupBox(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TGroupBox;
class PASCALIMPLEMENTATION TGroupBox : public TCustomGroupBox 
{
	typedef TCustomGroupBox inherited;
	
__published:
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property Caption ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomGroupBox.Create */ inline __fastcall virtual TGroupBox(Classes::TComponent* AOwner) : TCustomGroupBox(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TGroupBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TGroupBox(HWND ParentWindow) : TCustomGroupBox(ParentWindow
		) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTextLayout { tlTop, tlCenter, tlBottom };
#pragma option pop

class DELPHICLASS TCustomLabel;
class PASCALIMPLEMENTATION TCustomLabel : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	Controls::TWinControl* FFocusControl;
	Classes::TAlignment FAlignment;
	bool FAutoSize;
	TTextLayout FLayout;
	bool FWordWrap;
	bool FShowAccelChar;
	bool __fastcall GetTransparent(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetFocusControl(Controls::TWinControl* Value);
	void __fastcall SetShowAccelChar(bool Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetLayout(TTextLayout Value);
	void __fastcall SetWordWrap(bool Value);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	
protected:
	DYNAMIC void __fastcall AdjustBounds(void);
	DYNAMIC void __fastcall DoDrawText(Windows::TRect &Rect, int Flags);
	virtual AnsiString __fastcall GetLabelText();
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall Paint(void);
	HIDESBASE virtual void __fastcall SetAutoSize(bool Value);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property Controls::TWinControl* FocusControl = {read=FFocusControl, write=SetFocusControl};
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, default=0};
	__property TTextLayout Layout = {read=FLayout, write=SetLayout, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=0};
	
public:
	__fastcall virtual TCustomLabel(Classes::TComponent* AOwner);
	__property Canvas ;
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TCustomLabel(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLabel;
class PASCALIMPLEMENTATION TLabel : public TCustomLabel 
{
	typedef TCustomLabel inherited;
	
__published:
	__property Align ;
	__property Alignment ;
	__property Anchors ;
	__property AutoSize ;
	__property BiDiMode ;
	__property Caption ;
	__property Color ;
	__property Constraints ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property FocusControl ;
	__property Font ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowAccelChar ;
	__property ShowHint ;
	__property Transparent ;
	__property Layout ;
	__property Visible ;
	__property WordWrap ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomLabel.Create */ inline __fastcall virtual TLabel(Classes::TComponent* AOwner) : TCustomLabel(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TLabel(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TEditCharCase { ecNormal, ecUpperCase, ecLowerCase };
#pragma option pop

class DELPHICLASS TCustomEdit;
class PASCALIMPLEMENTATION TCustomEdit : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	int FMaxLength;
	Forms::TFormBorderStyle FBorderStyle;
	char FPasswordChar;
	bool FReadOnly;
	bool FAutoSize;
	bool FAutoSelect;
	bool FHideSelection;
	bool FOEMConvert;
	TEditCharCase FCharCase;
	bool FCreating;
	bool FModified;
	Classes::TNotifyEvent FOnChange;
	void __fastcall AdjustHeight(void);
	bool __fastcall GetModified(void);
	bool __fastcall GetCanUndo(void);
	HIDESBASE void __fastcall SetAutoSize(bool Value);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetCharCase(TEditCharCase Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetMaxLength(int Value);
	void __fastcall SetModified(bool Value);
	void __fastcall SetOEMConvert(bool Value);
	void __fastcall SetPasswordChar(char Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSelText(const AnsiString Value);
	void __fastcall UpdateHeight(void);
	MESSAGE void __fastcall WMSetFont(Messages::TWMSetFont &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall DoSetMaxLength(int Value);
	virtual int __fastcall GetSelLength(void);
	virtual int __fastcall GetSelStart(void);
	virtual AnsiString __fastcall GetSelText();
	virtual void __fastcall SetSelLength(int Value);
	virtual void __fastcall SetSelStart(int Value);
	__property bool AutoSelect = {read=FAutoSelect, write=FAutoSelect, default=1};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property TEditCharCase CharCase = {read=FCharCase, write=SetCharCase, default=0};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=0};
	__property bool OEMConvert = {read=FOEMConvert, write=SetOEMConvert, default=0};
	__property char PasswordChar = {read=FPasswordChar, write=SetPasswordChar, default=0};
	__property ParentColor ;
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TCustomEdit(Classes::TComponent* AOwner);
	virtual void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall CutToClipboard(void);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall PasteFromClipboard(void);
	void __fastcall Undo(void);
	void __fastcall ClearUndo(void);
	virtual int __fastcall GetSelTextBuf(char * Buffer, int BufSize);
	void __fastcall SelectAll(void);
	void __fastcall SetSelTextBuf(char * Buffer);
	__property bool CanUndo = {read=GetCanUndo, nodefault};
	__property bool Modified = {read=GetModified, write=SetModified, nodefault};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property AnsiString SelText = {read=GetSelText, write=SetSelText};
	__property Text ;
	
__published:
	__property TabStop ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomEdit(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEdit;
class PASCALIMPLEMENTATION TEdit : public TCustomEdit 
{
	typedef TCustomEdit inherited;
	
__published:
	__property Anchors ;
	__property AutoSelect ;
	__property AutoSize ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property CharCase ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HideSelection ;
	__property ImeMode ;
	__property ImeName ;
	__property MaxLength ;
	__property OEMConvert ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PasswordChar ;
	__property PopupMenu ;
	__property ReadOnly ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Text ;
	__property Visible ;
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomEdit.Create */ inline __fastcall virtual TEdit(Classes::TComponent* AOwner) : TCustomEdit(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TEdit(HWND ParentWindow) : TCustomEdit(ParentWindow
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TEdit(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TScrollStyle { ssNone, ssHorizontal, ssVertical, ssBoth };
#pragma option pop

class DELPHICLASS TCustomMemo;
class PASCALIMPLEMENTATION TCustomMemo : public TCustomEdit 
{
	typedef TCustomEdit inherited;
	
private:
	Classes::TStrings* FLines;
	Classes::TAlignment FAlignment;
	TScrollStyle FScrollBars;
	bool FWordWrap;
	bool FWantReturns;
	bool FWantTabs;
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	
protected:
	virtual Windows::TPoint __fastcall GetCaretPos();
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Controls::TCreateParams &Params);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Loaded(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetLines(Classes::TStrings* Value);
	void __fastcall SetScrollBars(TScrollStyle Value);
	void __fastcall SetWordWrap(bool Value);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=0};
	__property bool WantReturns = {read=FWantReturns, write=FWantReturns, default=1};
	__property bool WantTabs = {read=FWantTabs, write=FWantTabs, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=1};
	
public:
	__fastcall virtual TCustomMemo(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomMemo(void);
	DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
	__property Windows::TPoint CaretPos = {read=GetCaretPos};
	__property Classes::TStrings* Lines = {read=FLines, write=SetLines};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomMemo(HWND ParentWindow) : TCustomEdit(ParentWindow
		) { }
	#pragma option pop
	
};


class DELPHICLASS TMemo;
class PASCALIMPLEMENTATION TMemo : public TCustomMemo 
{
	typedef TCustomMemo inherited;
	
__published:
	__property Align ;
	__property Alignment ;
	__property Anchors ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HideSelection ;
	__property ImeMode ;
	__property ImeName ;
	__property Lines ;
	__property MaxLength ;
	__property OEMConvert ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ReadOnly ;
	__property ScrollBars ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property WantReturns ;
	__property WantTabs ;
	__property WordWrap ;
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomMemo.Create */ inline __fastcall virtual TMemo(Classes::TComponent* AOwner) : TCustomMemo(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMemo.Destroy */ inline __fastcall virtual ~TMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMemo(HWND ParentWindow) : TCustomMemo(ParentWindow
		) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TComboBoxStyle { csDropDown, csSimple, csDropDownList, csOwnerDrawFixed, csOwnerDrawVariable };
	
#pragma option pop

typedef void __fastcall (__closure *TDrawItemEvent)(Controls::TWinControl* Control, int Index, const 
	Windows::TRect &Rect, Windows::TOwnerDrawState State);

typedef void __fastcall (__closure *TMeasureItemEvent)(Controls::TWinControl* Control, int Index, int 
	&Height);

class DELPHICLASS TCustomComboBox;
class PASCALIMPLEMENTATION TCustomComboBox : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Classes::TStrings* FItems;
	Graphics::TCanvas* FCanvas;
	TEditCharCase FCharCase;
	bool FSorted;
	TComboBoxStyle FStyle;
	int FItemHeight;
	int FMaxLength;
	int FDropDownCount;
	HWND FEditHandle;
	HWND FListHandle;
	void *FEditInstance;
	void *FListInstance;
	void *FDefEditProc;
	void *FDefListProc;
	bool FIsFocused;
	bool FFocusChanged;
	Classes::TStringList* FSaveItems;
	int FSaveIndex;
	bool FDroppingDown;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnDropDown;
	TDrawItemEvent FOnDrawItem;
	TMeasureItemEvent FOnMeasureItem;
	void __fastcall AdjustDropDown(void);
	void __fastcall EditWndProc(Messages::TMessage &Message);
	bool __fastcall GetDroppedDown(void);
	int __fastcall GetItemIndex(void);
	int __fastcall GetSelLength(void);
	int __fastcall GetSelStart(void);
	AnsiString __fastcall GetSelText();
	void __fastcall ListWndProc(Messages::TMessage &Message);
	void __fastcall SetCharCase(TEditCharCase Value);
	void __fastcall SetDroppedDown(bool Value);
	void __fastcall SetItems(Classes::TStrings* Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetSelLength(int Value);
	void __fastcall SetSelStart(int Value);
	void __fastcall SetSelText(const AnsiString Value);
	void __fastcall SetSorted(bool Value);
	int __fastcall GetItemHeight(void);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetMaxLength(int Value);
	MESSAGE void __fastcall WMCreate(Messages::TWMCreate &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall CMCancelMode(Controls::TCMCancelMode &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall CNDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void __fastcall CNMeasureItem(Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMDrawItem(Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall WMMeasureItem(Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void __fastcall WMDeleteItem(Messages::TWMDeleteItem &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	
protected:
	virtual void __fastcall ComboWndProc(Messages::TMessage &Message, HWND ComboWnd, void * ComboProc);
		
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall DrawItem(int Index, const Windows::TRect &Rect, Windows::TOwnerDrawState State
		);
	virtual HWND __fastcall GetComboControl(void);
	virtual void __fastcall MeasureItem(int Index, int &Height);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall DropDown(void);
	virtual void __fastcall SetStyle(TComboBoxStyle Value);
	__property int DropDownCount = {read=FDropDownCount, write=FDropDownCount, default=8};
	__property HWND EditHandle = {read=FEditHandle, nodefault};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, nodefault};
	__property HWND ListHandle = {read=FListHandle, nodefault};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, default=0};
	__property ParentColor ;
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	__property TComboBoxStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
	__property TDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
	
public:
	__fastcall virtual TCustomComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomComboBox(void);
	void __fastcall Clear(void);
	DYNAMIC bool __fastcall Focused(void);
	void __fastcall SelectAll(void);
	__property TEditCharCase CharCase = {read=FCharCase, write=SetCharCase, default=0};
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property bool DroppedDown = {read=GetDroppedDown, write=SetDroppedDown, nodefault};
	__property Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property AnsiString SelText = {read=GetSelText, write=SetSelText};
	
__published:
	__property TabStop ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomComboBox(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TComboBox;
class PASCALIMPLEMENTATION TComboBox : public TCustomComboBox 
{
	typedef TCustomComboBox inherited;
	
__published:
	__property Style ;
	__property Anchors ;
	__property BiDiMode ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property DropDownCount ;
	__property Enabled ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property ItemHeight ;
	__property MaxLength ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property Sorted ;
	__property TabOrder ;
	__property TabStop ;
	__property Text ;
	__property Visible ;
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnDropDown ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property Items ;
public:
	#pragma option push -w-inl
	/* TCustomComboBox.Create */ inline __fastcall virtual TComboBox(Classes::TComponent* AOwner) : TCustomComboBox(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomComboBox.Destroy */ inline __fastcall virtual ~TComboBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TComboBox(HWND ParentWindow) : TCustomComboBox(ParentWindow
		) { }
	#pragma option pop
	
};


class DELPHICLASS TButtonActionLink;
class DELPHICLASS TButtonControl;
class PASCALIMPLEMENTATION TButtonControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FClicksDisabled;
	bool __fastcall IsCheckedStored(void);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual bool __fastcall GetChecked(void);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property bool Checked = {read=GetChecked, write=SetChecked, stored=IsCheckedStored, default=0};
	__property bool ClicksDisabled = {read=FClicksDisabled, write=FClicksDisabled, nodefault};
	
public:
	__fastcall virtual TButtonControl(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TButtonControl(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TButtonControl(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TButtonActionLink : public Controls::TWinControlActionLink 
{
	typedef Controls::TWinControlActionLink inherited;
	
protected:
	TButtonControl* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual void __fastcall SetChecked(bool Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TButtonActionLink(System::TObject* AClient)
		 : Controls::TWinControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TButtonActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TButtonActionLinkClass;

class DELPHICLASS TButton;
class PASCALIMPLEMENTATION TButton : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	bool FDefault;
	bool FCancel;
	bool FActive;
	Forms::TModalResult FModalResult;
	void __fastcall SetDefault(bool Value);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMFocusChanged(Controls::TCMFocusChanged &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall SetButtonStyle(bool ADefault);
	
public:
	__fastcall virtual TButton(Classes::TComponent* AOwner);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	
__published:
	__property Action ;
	__property Anchors ;
	__property BiDiMode ;
	__property bool Cancel = {read=FCancel, write=FCancel, default=0};
	__property Caption ;
	__property Constraints ;
	__property bool Default = {read=FDefault, write=SetDefault, default=0};
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property Forms::TModalResult ModalResult = {read=FModalResult, write=FModalResult, default=0};
	__property ParentBiDiMode ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TButton(HWND ParentWindow) : TButtonControl(ParentWindow
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCheckBoxState { cbUnchecked, cbChecked, cbGrayed };
#pragma option pop

class DELPHICLASS TCustomCheckBox;
class PASCALIMPLEMENTATION TCustomCheckBox : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FAllowGrayed;
	TCheckBoxState FState;
	void __fastcall SetAlignment(Classes::TLeftRight Value);
	void __fastcall SetState(TCheckBoxState Value);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	
protected:
	virtual void __fastcall Toggle(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall GetChecked(void);
	virtual void __fastcall SetChecked(bool Value);
	__property Classes::TLeftRight Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property bool AllowGrayed = {read=FAllowGrayed, write=FAllowGrayed, default=0};
	__property TCheckBoxState State = {read=FState, write=SetState, default=0};
	
public:
	__fastcall virtual TCustomCheckBox(Classes::TComponent* AOwner);
	DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
	
__published:
	__property TabStop ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomCheckBox(HWND ParentWindow) : TButtonControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomCheckBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCheckBox;
class PASCALIMPLEMENTATION TCheckBox : public TCustomCheckBox 
{
	typedef TCustomCheckBox inherited;
	
__published:
	__property Action ;
	__property Alignment ;
	__property AllowGrayed ;
	__property Anchors ;
	__property BiDiMode ;
	__property Caption ;
	__property Checked ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property State ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomCheckBox.Create */ inline __fastcall virtual TCheckBox(Classes::TComponent* AOwner) : TCustomCheckBox(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCheckBox(HWND ParentWindow) : TCustomCheckBox(ParentWindow
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCheckBox(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRadioButton;
class PASCALIMPLEMENTATION TRadioButton : public TButtonControl 
{
	typedef TButtonControl inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FChecked;
	void __fastcall SetAlignment(Classes::TLeftRight Value);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	
protected:
	virtual bool __fastcall GetChecked(void);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	
public:
	__fastcall virtual TRadioButton(Classes::TComponent* AOwner);
	DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
	
__published:
	__property Action ;
	__property Classes::TLeftRight Alignment = {read=FAlignment, write=SetAlignment, default=1};
	__property Anchors ;
	__property BiDiMode ;
	__property Caption ;
	__property Checked ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TRadioButton(HWND ParentWindow) : TButtonControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TRadioButton(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TListBoxStyle { lbStandard, lbOwnerDrawFixed, lbOwnerDrawVariable };
#pragma option pop

class DELPHICLASS TCustomListBox;
class PASCALIMPLEMENTATION TCustomListBox : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Classes::TStrings* FItems;
	Forms::TFormBorderStyle FBorderStyle;
	Graphics::TCanvas* FCanvas;
	int FColumns;
	int FItemHeight;
	TListBoxStyle FStyle;
	bool FIntegralHeight;
	bool FMultiSelect;
	bool FSorted;
	bool FExtendedSelect;
	int FTabWidth;
	Classes::TStringList* FSaveItems;
	int FSaveTopIndex;
	int FSaveItemIndex;
	TDrawItemEvent FOnDrawItem;
	TMeasureItemEvent FOnMeasureItem;
	int __fastcall GetItemHeight(void);
	int __fastcall GetItemIndex(void);
	int __fastcall GetSelCount(void);
	bool __fastcall GetSelected(int Index);
	int __fastcall GetTopIndex(void);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetColumnWidth(void);
	void __fastcall SetColumns(int Value);
	void __fastcall SetExtendedSelect(bool Value);
	void __fastcall SetIntegralHeight(bool Value);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetItems(Classes::TStrings* Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetSelected(int Index, bool Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetStyle(TListBoxStyle Value);
	void __fastcall SetTabWidth(int Value);
	void __fastcall SetTopIndex(int Value);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall CNDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void __fastcall CNMeasureItem(Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	
protected:
	bool FMoving;
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	DYNAMIC void __fastcall DragCanceled(void);
	virtual void __fastcall DrawItem(int Index, const Windows::TRect &Rect, Windows::TOwnerDrawState State
		);
	virtual void __fastcall MeasureItem(int Index, int &Height);
	DYNAMIC int __fastcall InternalGetItemData(int Index);
	DYNAMIC void __fastcall InternalSetItemData(int Index, int AData);
	DYNAMIC int __fastcall GetItemData(int Index);
	DYNAMIC void __fastcall SetItemData(int Index, int AData);
	DYNAMIC void __fastcall ResetContent(void);
	DYNAMIC void __fastcall DeleteString(int Index);
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int Columns = {read=FColumns, write=SetColumns, default=0};
	__property bool ExtendedSelect = {read=FExtendedSelect, write=SetExtendedSelect, default=1};
	__property bool IntegralHeight = {read=FIntegralHeight, write=SetIntegralHeight, default=0};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, nodefault};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	__property ParentColor ;
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	__property TListBoxStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property int TabWidth = {read=FTabWidth, write=SetTabWidth, default=0};
	__property TDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
	
public:
	__fastcall virtual TCustomListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomListBox(void);
	void __fastcall Clear(void);
	int __fastcall ItemAtPos(const Windows::TPoint &Pos, bool Existing);
	Windows::TRect __fastcall ItemRect(int Index);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property Classes::TStrings* Items = {read=FItems, write=SetItems};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property int SelCount = {read=GetSelCount, nodefault};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	
__published:
	__property TabStop ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomListBox(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TListBox;
class PASCALIMPLEMENTATION TListBox : public TCustomListBox 
{
	typedef TCustomListBox inherited;
	
__published:
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property Color ;
	__property Columns ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property ExtendedSelect ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property IntegralHeight ;
	__property ItemHeight ;
	__property Items ;
	__property MultiSelect ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property Sorted ;
	__property Style ;
	__property TabOrder ;
	__property TabStop ;
	__property TabWidth ;
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomListBox.Create */ inline __fastcall virtual TListBox(Classes::TComponent* AOwner) : TCustomListBox(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomListBox.Destroy */ inline __fastcall virtual ~TListBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TListBox(HWND ParentWindow) : TCustomListBox(ParentWindow
		) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TScrollCode { scLineUp, scLineDown, scPageUp, scPageDown, scPosition, scTrack, scTop, scBottom, 
	scEndScroll };
#pragma option pop

typedef void __fastcall (__closure *TScrollEvent)(System::TObject* Sender, TScrollCode ScrollCode, int 
	&ScrollPos);

class DELPHICLASS TScrollBar;
class PASCALIMPLEMENTATION TScrollBar : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Forms::TScrollBarKind FKind;
	int FPosition;
	int FMin;
	int FMax;
	int FPageSize;
	int FRTLFactor;
	Forms::TScrollBarInc FSmallChange;
	Forms::TScrollBarInc FLargeChange;
	Classes::TNotifyEvent FOnChange;
	TScrollEvent FOnScroll;
	void __fastcall DoScroll(Messages::TWMScroll &Message);
	bool __fastcall NotRightToLeft(void);
	void __fastcall SetKind(Forms::TScrollBarKind Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetPageSize(int Value);
	MESSAGE void __fastcall CNHScroll(Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNVScroll(Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNCtlColorScrollBar(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Scroll(TScrollCode ScrollCode, int &ScrollPos);
	
public:
	__fastcall virtual TScrollBar(Classes::TComponent* AOwner);
	void __fastcall SetParams(int APosition, int AMin, int AMax);
	
__published:
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Forms::TScrollBarKind Kind = {read=FKind, write=SetKind, default=0};
	__property Forms::TScrollBarInc LargeChange = {read=FLargeChange, write=FLargeChange, default=1};
	__property int Max = {read=FMax, write=SetMax, default=100};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property int PageSize = {read=FPageSize, write=SetPageSize, nodefault};
	__property ParentBiDiMode ;
	__property ParentCtl3D ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property ShowHint ;
	__property Forms::TScrollBarInc SmallChange = {read=FSmallChange, write=FSmallChange, default=1};
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnContextPopup ;
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TScrollBar(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TScrollBar(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TStaticBorderStyle { sbsNone, sbsSingle, sbsSunken };
#pragma option pop

class DELPHICLASS TCustomStaticText;
class PASCALIMPLEMENTATION TCustomStaticText : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FAutoSize;
	TStaticBorderStyle FBorderStyle;
	Controls::TWinControl* FFocusControl;
	bool FShowAccelChar;
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	void __fastcall AdjustBounds(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	HIDESBASE void __fastcall SetAutoSize(bool Value);
	void __fastcall SetBorderStyle(TStaticBorderStyle Value);
	void __fastcall SetFocusControl(Controls::TWinControl* Value);
	void __fastcall SetShowAccelChar(bool Value);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property TStaticBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property Controls::TWinControl* FocusControl = {read=FFocusControl, write=SetFocusControl};
	__property bool ShowAccelChar = {read=FShowAccelChar, write=SetShowAccelChar, default=1};
	
public:
	__fastcall virtual TCustomStaticText(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomStaticText(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomStaticText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStaticText;
class PASCALIMPLEMENTATION TStaticText : public TCustomStaticText 
{
	typedef TCustomStaticText inherited;
	
__published:
	__property Align ;
	__property Alignment ;
	__property Anchors ;
	__property AutoSize ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property Caption ;
	__property Color ;
	__property Constraints ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property FocusControl ;
	__property Font ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowAccelChar ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomStaticText.Create */ inline __fastcall virtual TStaticText(Classes::TComponent* AOwner) : 
		TCustomStaticText(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStaticText(HWND ParentWindow) : TCustomStaticText(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TStaticText(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Stdctrls */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Stdctrls;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdCtrls
