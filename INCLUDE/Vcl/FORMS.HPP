// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Forms.pas' rev: 5.00

#ifndef FormsHPP
#define FormsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <MultiMon.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Imm.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Forms
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollBarKind { sbHorizontal, sbVertical };
#pragma option pop

typedef Word TScrollBarInc;

#pragma option push -b-
enum TScrollBarStyle { ssRegular, ssFlat, ssHotTrack };
#pragma option pop

class DELPHICLASS TControlScrollBar;
class DELPHICLASS TScrollingWinControl;
#pragma option push -b-
enum TWindowState { wsNormal, wsMinimized, wsMaximized };
#pragma option pop

class PASCALIMPLEMENTATION TScrollingWinControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TControlScrollBar* FHorzScrollBar;
	TControlScrollBar* FVertScrollBar;
	bool FAutoScroll;
	int FAutoRangeCount;
	bool FUpdatingScrollBars;
	void __fastcall CalcAutoRange(void);
	void __fastcall ScaleScrollBars(int M, int D);
	void __fastcall SetAutoScroll(bool Value);
	void __fastcall SetHorzScrollBar(TControlScrollBar* Value);
	void __fastcall SetVertScrollBar(TControlScrollBar* Value);
	void __fastcall UpdateScrollBars(void);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(Windows::TRect &Rect);
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Windows::TRect &ARect);
	virtual bool __fastcall AutoScrollEnabled(void);
	virtual void __fastcall AutoScrollInView(Controls::TControl* AControl);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoFlipChildren(void);
	__property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, default=1};
	virtual void __fastcall Resizing(TWindowState State);
	
public:
	__fastcall virtual TScrollingWinControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TScrollingWinControl(void);
	void __fastcall DisableAutoRange(void);
	void __fastcall EnableAutoRange(void);
	void __fastcall ScrollInView(Controls::TControl* AControl);
	
__published:
	__property TControlScrollBar* HorzScrollBar = {read=FHorzScrollBar, write=SetHorzScrollBar};
	__property TControlScrollBar* VertScrollBar = {read=FVertScrollBar, write=SetVertScrollBar};
public:
		
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TScrollingWinControl(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TControlScrollBar : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TScrollingWinControl* FControl;
	TScrollBarInc FIncrement;
	TScrollBarInc FPageIncrement;
	int FPosition;
	int FRange;
	int FCalcRange;
	TScrollBarKind FKind;
	Word FMargin;
	bool FVisible;
	bool FTracking;
	bool FScaled;
	bool FSmooth;
	int FDelay;
	int FButtonSize;
	Graphics::TColor FColor;
	bool FParentColor;
	int FSize;
	TScrollBarStyle FStyle;
	int FThumbSize;
	int FPageDiv;
	int FLineDiv;
	bool FUpdateNeeded;
	__fastcall TControlScrollBar(TScrollingWinControl* AControl, TScrollBarKind AKind);
	void __fastcall CalcAutoRange(void);
	int __fastcall ControlSize(bool ControlSB, bool AssumeSB);
	void __fastcall DoSetRange(int Value);
	int __fastcall GetScrollPos(void);
	bool __fastcall NeedsScrollBarVisible(void);
	bool __fastcall IsIncrementStored(void);
	void __fastcall ScrollMessage(Messages::TWMScroll &Msg);
	void __fastcall SetButtonSize(int Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetParentColor(bool Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetRange(int Value);
	void __fastcall SetSize(int Value);
	void __fastcall SetStyle(TScrollBarStyle Value);
	void __fastcall SetThumbSize(int Value);
	void __fastcall SetVisible(bool Value);
	bool __fastcall IsRangeStored(void);
	void __fastcall Update(bool ControlSB, bool AssumeSB);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall ChangeBiDiPosition(void);
	__property TScrollBarKind Kind = {read=FKind, nodefault};
	bool __fastcall IsScrollBarVisible(void);
	__property int ScrollPos = {read=GetScrollPos, nodefault};
	
__published:
	__property int ButtonSize = {read=FButtonSize, write=SetButtonSize, default=0};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, default=-2147483628};
	__property TScrollBarInc Increment = {read=FIncrement, write=FIncrement, stored=IsIncrementStored, 
		default=8};
	__property Word Margin = {read=FMargin, write=FMargin, default=0};
	__property bool ParentColor = {read=FParentColor, write=SetParentColor, default=1};
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property int Range = {read=FRange, write=SetRange, stored=IsRangeStored, default=0};
	__property bool Smooth = {read=FSmooth, write=FSmooth, default=0};
	__property int Size = {read=FSize, write=SetSize, default=0};
	__property TScrollBarStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property int ThumbSize = {read=FThumbSize, write=SetThumbSize, default=0};
	__property bool Tracking = {read=FTracking, write=FTracking, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TControlScrollBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TControlScrollBar(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFormBorderStyle { bsNone, bsSingle, bsSizeable, bsDialog, bsToolWindow, bsSizeToolWin };
#pragma option pop

typedef TFormBorderStyle TBorderStyle;

class DELPHICLASS TScrollBox;
class PASCALIMPLEMENTATION TScrollBox : public TScrollingWinControl 
{
	typedef TScrollingWinControl inherited;
	
private:
	TFormBorderStyle FBorderStyle;
	void __fastcall SetBorderStyle(TBorderStyle Value);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	
public:
	__fastcall virtual TScrollBox(Classes::TComponent* AOwner);
	
__published:
	__property Align ;
	__property Anchors ;
	__property AutoScroll ;
	__property AutoSize ;
	__property BiDiMode ;
	__property TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property Constraints ;
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Color ;
	__property Ctl3D ;
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
	__property OnCanResize ;
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TScrollBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TScrollBox(HWND ParentWindow) : TScrollingWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomFrame;
class PASCALIMPLEMENTATION TCustomFrame : public TScrollingWinControl 
{
	typedef TScrollingWinControl inherited;
	
private:
	void __fastcall AddActionList(Actnlist::TCustomActionList* ActionList);
	void __fastcall RemoveActionList(Actnlist::TCustomActionList* ActionList);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	
public:
	__fastcall virtual TCustomFrame(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TCustomFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomFrame(HWND ParentWindow) : TScrollingWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TCustomFrameClass;

class DELPHICLASS TFrame;
class PASCALIMPLEMENTATION TFrame : public TCustomFrame 
{
	typedef TCustomFrame inherited;
	
__published:
	__property Align ;
	__property Anchors ;
	__property AutoScroll ;
	__property AutoSize ;
	__property BiDiMode ;
	__property Constraints ;
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Color ;
	__property Ctl3D ;
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
	__property OnCanResize ;
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomFrame.Create */ inline __fastcall virtual TFrame(Classes::TComponent* AOwner) : TCustomFrame(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFrame(HWND ParentWindow) : TCustomFrame(ParentWindow
		) { }
	#pragma option pop
	
};


__interface IDesigner;
typedef System::DelphiInterface<IDesigner> _di_IDesigner;
class DELPHICLASS TCustomForm;
__interface INTERFACE_UUID("{ABBE7256-5495-11D1-9FB5-0020AF3D82DA}") IDesigner  : public IDesignerNotify 
	
{
	
public:
	virtual TCustomForm* __fastcall GetCustomForm(void) = 0 ;
	virtual void __fastcall SetCustomForm(TCustomForm* Value) = 0 ;
	virtual bool __fastcall GetIsControl(void) = 0 ;
	virtual void __fastcall SetIsControl(bool Value) = 0 ;
	virtual bool __fastcall IsDesignMsg(Controls::TControl* Sender, Messages::TMessage &Message) = 0 ;
	virtual void __fastcall PaintGrid(void) = 0 ;
	virtual void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const 
		AnsiString NewName) = 0 ;
	virtual AnsiString __fastcall UniqueName(const AnsiString BaseName) = 0 ;
	virtual Classes::TComponent* __fastcall GetRoot(void) = 0 ;
	__property bool IsControl = {read=GetIsControl, write=SetIsControl};
	__property TCustomForm* Form = {read=GetCustomForm, write=SetCustomForm};
};

__interface IOleForm;
typedef System::DelphiInterface<IOleForm> _di_IOleForm;
__interface INTERFACE_UUID("{CD02E1C1-52DA-11D0-9EA6-0020AF3D82DA}") IOleForm  : public IUnknown 
{
	
public:
	virtual void __fastcall OnDestroy(void) = 0 ;
	virtual void __fastcall OnResize(void) = 0 ;
};

#pragma option push -b-
enum TFormStyle { fsNormal, fsMDIChild, fsMDIForm, fsStayOnTop };
#pragma option pop

#pragma option push -b-
enum TBorderIcon { biSystemMenu, biMinimize, biMaximize, biHelp };
#pragma option pop

typedef Set<TBorderIcon, biSystemMenu, biHelp>  TBorderIcons;

#pragma option push -b-
enum TPosition { poDesigned, poDefault, poDefaultPosOnly, poDefaultSizeOnly, poScreenCenter, poDesktopCenter, 
	poMainFormCenter, poOwnerFormCenter };
#pragma option pop

#pragma option push -b-
enum TDefaultMonitor { dmDesktop, dmPrimary, dmMainForm, dmActiveForm };
#pragma option pop

#pragma option push -b-
enum TPrintScale { poNone, poProportional, poPrintToFit };
#pragma option pop

#pragma option push -b-
enum TShowAction { saIgnore, saRestore, saMinimize, saMaximize };
#pragma option pop

#pragma option push -b-
enum TTileMode { tbHorizontal, tbVertical };
#pragma option pop

typedef int TModalResult;

#pragma option push -b-
enum TCloseAction { caNone, caHide, caFree, caMinimize };
#pragma option pop

typedef void __fastcall (__closure *TCloseEvent)(System::TObject* Sender, TCloseAction &Action);

typedef void __fastcall (__closure *TCloseQueryEvent)(System::TObject* Sender, bool &CanClose);

#pragma option push -b-
enum Forms__6 { fsCreating, fsVisible, fsShowing, fsModal, fsCreatedMDIChild, fsActivated };
#pragma option pop

typedef Set<Forms__6, fsCreating, fsActivated>  TFormState;

typedef void __fastcall (__closure *TShortCutEvent)(Messages::TWMKey &Msg, bool &Handled);

class DELPHICLASS TForm;
class DELPHICLASS TMonitor;
class PASCALIMPLEMENTATION TCustomForm : public TScrollingWinControl 
{
	typedef TScrollingWinControl inherited;
	
private:
	Controls::TWinControl* FActiveControl;
	Controls::TWinControl* FFocusedControl;
	TBorderIcons FBorderIcons;
	TFormBorderStyle FBorderStyle;
	bool FSizeChanging;
	TWindowState FWindowState;
	TShowAction FShowAction;
	bool FKeyPreview;
	bool FActive;
	TFormStyle FFormStyle;
	TPosition FPosition;
	TDefaultMonitor FDefaultMonitor;
	TTileMode FTileMode;
	bool FDropTarget;
	bool FOldCreateOrder;
	TPrintScale FPrintScale;
	Controls::TControlCanvas* FCanvas;
	AnsiString FHelpFile;
	Graphics::TIcon* FIcon;
	bool FInCMParentBiDiModeChanged;
	Menus::TMainMenu* FMenu;
	TModalResult FModalResult;
	_di_IDesigner FDesigner;
	HWND FClientHandle;
	Menus::TMenuItem* FWindowMenu;
	int FPixelsPerInch;
	Menus::TMenuItem* FObjectMenuItem;
	_di_IOleForm FOleForm;
	int FClientWidth;
	int FClientHeight;
	int FTextHeight;
	void *FDefClientProc;
	void *FClientInstance;
	Controls::TWinControl* FActiveOleControl;
	TFormBorderStyle FSavedBorderStyle;
	Classes::TNotifyEvent FOnActivate;
	TCloseEvent FOnClose;
	TCloseQueryEvent FOnCloseQuery;
	Classes::TNotifyEvent FOnDeactivate;
	Classes::THelpEvent FOnHelp;
	Classes::TNotifyEvent FOnHide;
	Classes::TNotifyEvent FOnPaint;
	TShortCutEvent FOnShortCut;
	Classes::TNotifyEvent FOnShow;
	Classes::TNotifyEvent FOnCreate;
	Classes::TNotifyEvent FOnDestroy;
	void __fastcall RefreshMDIMenu(void);
	void __fastcall ClientWndProc(Messages::TMessage &Message);
	void __fastcall CloseModal(void);
	TForm* __fastcall GetActiveMDIChild(void);
	Graphics::TCanvas* __fastcall GetCanvas(void);
	HICON __fastcall GetIconHandle(void);
	int __fastcall GetMDIChildCount(void);
	TForm* __fastcall GetMDIChildren(int I);
	TMonitor* __fastcall GetMonitor(void);
	int __fastcall GetPixelsPerInch(void);
	bool __fastcall GetScaled(void);
	int __fastcall GetTextHeight(void);
	void __fastcall IconChanged(System::TObject* Sender);
	bool __fastcall IsAutoScrollStored(void);
	bool __fastcall IsClientSizeStored(void);
	bool __fastcall IsForm(void);
	bool __fastcall IsFormSizeStored(void);
	bool __fastcall IsIconStored(void);
	void __fastcall MergeMenu(bool MergeState);
	void __fastcall ReadIgnoreFontProperty(Classes::TReader* Reader);
	void __fastcall ReadTextHeight(Classes::TReader* Reader);
	void __fastcall SetActive(bool Value);
	void __fastcall SetActiveControl(Controls::TWinControl* Control);
	void __fastcall SetBorderIcons(TBorderIcons Value);
	void __fastcall SetBorderStyle(TFormBorderStyle Value);
	HIDESBASE void __fastcall SetClientHeight(int Value);
	HIDESBASE void __fastcall SetClientWidth(int Value);
	void __fastcall SetDesigner(_di_IDesigner ADesigner);
	void __fastcall SetFormStyle(TFormStyle Value);
	void __fastcall SetIcon(Graphics::TIcon* Value);
	void __fastcall SetMenu(Menus::TMainMenu* Value);
	void __fastcall SetPixelsPerInch(int Value);
	void __fastcall SetPosition(TPosition Value);
	void __fastcall SetScaled(bool Value);
	HIDESBASE void __fastcall SetVisible(bool Value);
	void __fastcall SetWindowFocus(void);
	void __fastcall SetWindowMenu(Menus::TMenuItem* Value);
	void __fastcall SetObjectMenuItem(Menus::TMenuItem* Value);
	void __fastcall SetWindowState(TWindowState Value);
	void __fastcall SetWindowToMonitor(void);
	void __fastcall WritePixelsPerInch(Classes::TWriter* Writer);
	void __fastcall WriteTextHeight(Classes::TWriter* Writer);
	Graphics::TColor __fastcall NormalColor(void);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMIconEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMQueryDragIcon(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMNCCreate(Messages::TWMNCCreate &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMInitMenuPopup(Messages::TWMInitMenuPopup &Message);
	MESSAGE void __fastcall WMMenuChar(Messages::TWMMenuChar &Message);
	MESSAGE void __fastcall WMMenuSelect(Messages::TWMMenuSelect &Message);
	MESSAGE void __fastcall WMActivate(Messages::TWMActivate &Message);
	MESSAGE void __fastcall WMClose(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMQueryEndSession(Messages::TWMQueryEndSession &Message);
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Messages::TWMSysCommand &Message);
	MESSAGE void __fastcall WMShowWindow(Messages::TWMShowWindow &Message);
	MESSAGE void __fastcall WMMDIActivate(Messages::TWMMDIActivate &Message);
	MESSAGE void __fastcall WMNextDlgCtl(Messages::TWMNextDlgCtl &Message);
	MESSAGE void __fastcall WMEnterMenuLoop(Messages::TMessage &Message);
	MESSAGE void __fastcall WMHelp(Messages::TWMHelp &Message);
	MESSAGE void __fastcall WMGetMinMaxInfo(Messages::TWMGetMinMaxInfo &Message);
	MESSAGE void __fastcall WMSettingChange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall CMActionExecute(Messages::TMessage &Message);
	MESSAGE void __fastcall CMActionUpdate(Messages::TMessage &Message);
	MESSAGE void __fastcall CMActivate(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMAppSysCommand(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDeactivate(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMMenuChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMIconChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMRelease(Messages::TMessage &Message);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMUIActivate(void *Message);
	HIDESBASE MESSAGE void __fastcall CMParentBiDiModeChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentFontChanged(Messages::TMessage &Message);
	
protected:
	Classes::TList* FActionLists;
	TFormState FFormState;
	DYNAMIC void __fastcall Activate(void);
	DYNAMIC void __fastcall ActiveChanged(void);
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Windows::TRect &Rect);
	DYNAMIC void __fastcall BeginAutoDrag(void);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall Deactivate(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DestroyWindowHandle(void);
	DYNAMIC void __fastcall DoClose(TCloseAction &Action);
	virtual void __fastcall DoCreate(void);
	virtual void __fastcall DoDestroy(void);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual Windows::TRect __fastcall GetClientRect();
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual bool __fastcall GetFloating(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	DYNAMIC void __fastcall Paint(void);
	virtual void __fastcall PaintWindow(HDC DC);
	DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	virtual void __fastcall SetParentBiDiMode(bool Value);
	DYNAMIC void __fastcall DoDock(Controls::TWinControl* NewDockSite, Windows::TRect &ARect);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	virtual void __fastcall UpdateActions(void);
	void __fastcall UpdateWindowState(void);
	virtual void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const 
		AnsiString NewName);
	DYNAMIC void __fastcall VisibleChanging(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual void __fastcall Resizing(TWindowState State);
	__property TForm* ActiveMDIChild = {read=GetActiveMDIChild};
	__property TBorderIcons BorderIcons = {read=FBorderIcons, write=SetBorderIcons, stored=IsForm, default=7
		};
	__property AutoScroll  = {stored=IsAutoScrollStored, default=1};
	__property HWND ClientHandle = {read=FClientHandle, nodefault};
	__property ClientHeight  = {write=SetClientHeight, stored=IsClientSizeStored};
	__property ClientWidth  = {write=SetClientWidth, stored=IsClientSizeStored};
	__property Ctl3D ;
	__property TDefaultMonitor DefaultMonitor = {read=FDefaultMonitor, write=FDefaultMonitor, stored=IsForm
		, default=3};
	__property TFormStyle FormStyle = {read=FFormStyle, write=SetFormStyle, stored=IsForm, default=0};
	__property Height  = {stored=IsFormSizeStored};
	__property HorzScrollBar  = {stored=IsForm};
	__property Graphics::TIcon* Icon = {read=FIcon, write=SetIcon, stored=IsIconStored};
	__property int MDIChildCount = {read=GetMDIChildCount, nodefault};
	__property TForm* MDIChildren[int I] = {read=GetMDIChildren};
	__property bool OldCreateOrder = {read=FOldCreateOrder, write=FOldCreateOrder, nodefault};
	__property Menus::TMenuItem* ObjectMenuItem = {read=FObjectMenuItem, write=SetObjectMenuItem, stored=
		IsForm};
	__property int PixelsPerInch = {read=GetPixelsPerInch, write=SetPixelsPerInch, stored=false, nodefault
		};
	__property ParentFont ;
	__property PopupMenu  = {stored=IsForm};
	__property TPosition Position = {read=FPosition, write=SetPosition, stored=IsForm, default=0};
	__property TPrintScale PrintScale = {read=FPrintScale, write=FPrintScale, stored=IsForm, default=1}
		;
	__property bool Scaled = {read=GetScaled, write=SetScaled, stored=IsForm, default=1};
	__property TTileMode TileMode = {read=FTileMode, write=FTileMode, default=0};
	__property VertScrollBar  = {stored=IsForm};
	__property Visible  = {write=SetVisible, default=0};
	__property Width  = {stored=IsFormSizeStored};
	__property Menus::TMenuItem* WindowMenu = {read=FWindowMenu, write=SetWindowMenu, stored=IsForm};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate, stored=IsForm};
		
	__property OnCanResize  = {stored=IsForm};
	__property OnClick  = {stored=IsForm};
	__property TCloseEvent OnClose = {read=FOnClose, write=FOnClose, stored=IsForm};
	__property TCloseQueryEvent OnCloseQuery = {read=FOnCloseQuery, write=FOnCloseQuery, stored=IsForm}
		;
	__property Classes::TNotifyEvent OnCreate = {read=FOnCreate, write=FOnCreate, stored=IsForm};
	__property OnDblClick  = {stored=IsForm};
	__property Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy, stored=IsForm};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate, stored=IsForm
		};
	__property OnDragDrop  = {stored=IsForm};
	__property OnDragOver  = {stored=IsForm};
	__property Classes::THelpEvent OnHelp = {read=FOnHelp, write=FOnHelp};
	__property Classes::TNotifyEvent OnHide = {read=FOnHide, write=FOnHide, stored=IsForm};
	__property OnKeyDown  = {stored=IsForm};
	__property OnKeyPress  = {stored=IsForm};
	__property OnKeyUp  = {stored=IsForm};
	__property OnMouseDown  = {stored=IsForm};
	__property OnMouseMove  = {stored=IsForm};
	__property OnMouseUp  = {stored=IsForm};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint, stored=IsForm};
	__property OnResize  = {stored=IsForm};
	__property TShortCutEvent OnShortCut = {read=FOnShortCut, write=FOnShortCut};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow, stored=IsForm};
	
public:
	__fastcall virtual TCustomForm(Classes::TComponent* AOwner);
	__fastcall virtual TCustomForm(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomForm(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall Close(void);
	virtual bool __fastcall CloseQuery(void);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall DefocusControl(Controls::TWinControl* Control, bool Removing);
	DYNAMIC void __fastcall Dock(Controls::TWinControl* NewDockSite, const Windows::TRect &ARect);
	void __fastcall FocusControl(Controls::TWinControl* Control);
	Graphics::TBitmap* __fastcall GetFormImage(void);
	HIDESBASE void __fastcall Hide(void);
	DYNAMIC bool __fastcall IsShortCut(Messages::TWMKey &Message);
	DYNAMIC void __fastcall MouseWheelHandler(Messages::TMessage &Message);
	void __fastcall Print(void);
	void __fastcall Release(void);
	HIDESBASE void __fastcall SendCancelMode(Controls::TControl* Sender);
	virtual void __fastcall SetFocus(void);
	virtual bool __fastcall SetFocusedControl(Controls::TWinControl* Control);
	HIDESBASE void __fastcall Show(void);
	virtual int __fastcall ShowModal(void);
	virtual bool __fastcall WantChildKey(Controls::TControl* Child, Messages::TMessage &Message);
	__property bool Active = {read=FActive, nodefault};
	__property Controls::TWinControl* ActiveControl = {read=FActiveControl, write=SetActiveControl, stored=
		IsForm};
	__property Action ;
	__property Controls::TWinControl* ActiveOleControl = {read=FActiveOleControl, write=FActiveOleControl
		};
	__property TFormBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, stored=IsForm, 
		default=2};
	__property Graphics::TCanvas* Canvas = {read=GetCanvas};
	__property Caption  = {stored=IsForm};
	__property Color ;
	__property _di_IDesigner Designer = {read=FDesigner, write=SetDesigner};
	__property bool DropTarget = {read=FDropTarget, write=FDropTarget, nodefault};
	__property Font ;
	__property TFormState FormState = {read=FFormState, nodefault};
	__property AnsiString HelpFile = {read=FHelpFile, write=FHelpFile};
	__property bool KeyPreview = {read=FKeyPreview, write=FKeyPreview, stored=IsForm, default=0};
	__property Menus::TMainMenu* Menu = {read=FMenu, write=SetMenu, stored=IsForm};
	__property TModalResult ModalResult = {read=FModalResult, write=FModalResult, nodefault};
	__property TMonitor* Monitor = {read=GetMonitor};
	__property _di_IOleForm OleFormObject = {read=FOleForm, write=FOleForm};
	__property TWindowState WindowState = {read=FWindowState, write=SetWindowState, stored=IsForm, default=0
		};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomForm(HWND ParentWindow) : TScrollingWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TCustomFormClass;

#pragma option push -b-
enum TActiveFormBorderStyle { afbNone, afbSingle, afbSunken, afbRaised };
#pragma option pop

class DELPHICLASS TCustomActiveForm;
class PASCALIMPLEMENTATION TCustomActiveForm : public TCustomForm 
{
	typedef TCustomForm inherited;
	
private:
	TActiveFormBorderStyle FAxBorderStyle;
	void __fastcall SetAxBorderStyle(TActiveFormBorderStyle Value);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	
public:
	__fastcall virtual TCustomActiveForm(Classes::TComponent* AOwner);
	virtual bool __fastcall WantChildKey(Controls::TControl* Child, Messages::TMessage &Message);
	__property Visible ;
	
__published:
	__property ActiveControl ;
	__property Anchors ;
	__property AutoScroll ;
	__property AutoSize ;
	__property TActiveFormBorderStyle AxBorderStyle = {read=FAxBorderStyle, write=SetAxBorderStyle, default=1
		};
	__property BorderWidth ;
	__property Caption  = {stored=true};
	__property Color ;
	__property Constraints ;
	__property Font ;
	__property Height  = {stored=true};
	__property HorzScrollBar ;
	__property KeyPreview ;
	__property OldCreateOrder ;
	__property PixelsPerInch ;
	__property PopupMenu ;
	__property PrintScale ;
	__property Scaled ;
	__property ShowHint ;
	__property VertScrollBar ;
	__property Width  = {stored=true};
	__property OnActivate ;
	__property OnClick ;
	__property OnCreate ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDestroy ;
	__property OnDeactivate ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnPaint ;
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomActiveForm(Classes::TComponent* AOwner
		, int Dummy) : TCustomForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomActiveForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActiveForm(HWND ParentWindow) : TCustomForm(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TForm : public TCustomForm 
{
	typedef TCustomForm inherited;
	
public:
	void __fastcall ArrangeIcons(void);
	void __fastcall Cascade(void);
	void __fastcall Next(void);
	void __fastcall Previous(void);
	void __fastcall Tile(void);
	__property ActiveMDIChild ;
	__property ClientHandle ;
	__property DockManager ;
	__property MDIChildCount ;
	__property MDIChildren ;
	__property TileMode ;
	
__published:
	__property Action ;
	__property ActiveControl ;
	__property Align ;
	__property Anchors ;
	__property AutoScroll ;
	__property AutoSize ;
	__property BiDiMode ;
	__property BorderIcons ;
	__property BorderStyle ;
	__property BorderWidth ;
	__property Caption ;
	__property ClientHeight ;
	__property ClientWidth ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property UseDockManager ;
	__property DefaultMonitor ;
	__property DockSite ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property ParentFont ;
	__property Font ;
	__property FormStyle ;
	__property Height ;
	__property HelpFile ;
	__property HorzScrollBar ;
	__property Icon ;
	__property KeyPreview ;
	__property Menu ;
	__property OldCreateOrder ;
	__property ObjectMenuItem ;
	__property ParentBiDiMode ;
	__property PixelsPerInch ;
	__property PopupMenu ;
	__property Position ;
	__property PrintScale ;
	__property Scaled ;
	__property ShowHint ;
	__property VertScrollBar ;
	__property Visible ;
	__property Width ;
	__property WindowState ;
	__property WindowMenu ;
	__property OnActivate ;
	__property OnCanResize ;
	__property OnClick ;
	__property OnClose ;
	__property OnCloseQuery ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnCreate ;
	__property OnDblClick ;
	__property OnDestroy ;
	__property OnDeactivate ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnGetSiteInfo ;
	__property OnHide ;
	__property OnHelp ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnPaint ;
	__property OnResize ;
	__property OnShortCut ;
	__property OnShow ;
	__property OnStartDock ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TForm(Classes::TComponent* AOwner) : TCustomForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TForm(Classes::TComponent* AOwner, int Dummy)
		 : TCustomForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TForm(HWND ParentWindow) : TCustomForm(ParentWindow
		) { }
	#pragma option pop
	
};


typedef TMetaClass*TFormClass;

class DELPHICLASS TCustomDockForm;
class PASCALIMPLEMENTATION TCustomDockForm : public TCustomForm 
{
	typedef TCustomForm inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMControlListChange(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDockNotification(Controls::TCMDockNotification &Message);
	HIDESBASE MESSAGE void __fastcall CMUnDockClient(Controls::TCMUnDockClient &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall DoAddDockClient(Controls::TControl* Client, const Windows::TRect &ARect);
	DYNAMIC void __fastcall DoRemoveDockClient(Controls::TControl* Client);
	DYNAMIC void __fastcall GetSiteInfo(Controls::TControl* Client, Windows::TRect &InfluenceRect, const 
		Windows::TPoint &MousePos, bool &CanDock);
	virtual void __fastcall Loaded(void);
	
public:
	__fastcall virtual TCustomDockForm(Classes::TComponent* AOwner);
	__property AutoScroll ;
	__property BorderStyle ;
	__property FormStyle ;
	
__published:
	__property PixelsPerInch ;
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCustomDockForm(Classes::TComponent* AOwner, 
		int Dummy) : TCustomForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TCustomDockForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomDockForm(HWND ParentWindow) : TCustomForm(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TDataModule;
class PASCALIMPLEMENTATION TDataModule : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Windows::TPoint FDesignSize;
	Windows::TPoint FDesignOffset;
	Classes::TNotifyEvent FOnCreate;
	Classes::TNotifyEvent FOnDestroy;
	bool FOldCreateOrder;
	void __fastcall ReadHeight(Classes::TReader* Reader);
	void __fastcall ReadHorizontalOffset(Classes::TReader* Reader);
	void __fastcall ReadVerticalOffset(Classes::TReader* Reader);
	void __fastcall ReadWidth(Classes::TReader* Reader);
	void __fastcall WriteWidth(Classes::TWriter* Writer);
	void __fastcall WriteHorizontalOffset(Classes::TWriter* Writer);
	void __fastcall WriteVerticalOffset(Classes::TWriter* Writer);
	void __fastcall WriteHeight(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DoCreate(void);
	virtual void __fastcall DoDestroy(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	
public:
	__fastcall virtual TDataModule(Classes::TComponent* AOwner);
	__fastcall virtual TDataModule(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TDataModule(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	__property Windows::TPoint DesignOffset = {read=FDesignOffset, write=FDesignOffset};
	__property Windows::TPoint DesignSize = {read=FDesignSize, write=FDesignSize};
	
__published:
	__property bool OldCreateOrder = {read=FOldCreateOrder, write=FOldCreateOrder, nodefault};
	__property Classes::TNotifyEvent OnCreate = {read=FOnCreate, write=FOnCreate};
	__property Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
};


class PASCALIMPLEMENTATION TMonitor : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	HMONITOR FHandle;
	int FMonitorNum;
	int __fastcall GetLeft(void);
	int __fastcall GetHeight(void);
	int __fastcall GetTop(void);
	int __fastcall GetWidth(void);
	
public:
	__property HMONITOR Handle = {read=FHandle, nodefault};
	__property int MonitorNum = {read=FMonitorNum, nodefault};
	__property int Left = {read=GetLeft, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int Top = {read=GetTop, nodefault};
	__property int Width = {read=GetWidth, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMonitor(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TMonitor(void) { }
	#pragma option pop
	
};


struct TCursorRec;
typedef TCursorRec *PCursorRec;

struct TCursorRec
{
	TCursorRec *Next;
	int Index;
	HICON Handle;
} ;

class DELPHICLASS TScreen;
class PASCALIMPLEMENTATION TScreen : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TStrings* FFonts;
	Classes::TStrings* FImes;
	AnsiString FDefaultIme;
	HKL FDefaultKbLayout;
	int FPixelsPerInch;
	Controls::TCursor FCursor;
	int FCursorCount;
	Classes::TList* FForms;
	Classes::TList* FCustomForms;
	Classes::TList* FDataModules;
	Classes::TList* FMonitors;
	TCursorRec *FCursorList;
	HICON FDefaultCursor;
	Controls::TWinControl* FActiveControl;
	TCustomForm* FActiveCustomForm;
	TForm* FActiveForm;
	Controls::TWinControl* FLastActiveControl;
	TCustomForm* FLastActiveCustomForm;
	TCustomForm* FFocusedForm;
	Classes::TList* FSaveFocusedList;
	Graphics::TFont* FHintFont;
	Graphics::TFont* FIconFont;
	Graphics::TFont* FMenuFont;
	Word FAlignLevel;
	Controls::TControlState FControlState;
	Classes::TNotifyEvent FOnActiveControlChange;
	Classes::TNotifyEvent FOnActiveFormChange;
	void __fastcall AlignForm(TCustomForm* AForm);
	void __fastcall AlignForms(TCustomForm* AForm, Windows::TRect &Rect);
	void __fastcall AddDataModule(TDataModule* DataModule);
	void __fastcall AddForm(TCustomForm* AForm);
	void __fastcall CreateCursors(void);
	void __fastcall DeleteCursor(int Index);
	void __fastcall DestroyCursors(void);
	void __fastcall IconFontChanged(System::TObject* Sender);
	int __fastcall GetCustomFormCount(void);
	TCustomForm* __fastcall GetCustomForms(int Index);
	HICON __fastcall GetCursors(int Index);
	TDataModule* __fastcall GetDataModule(int Index);
	int __fastcall GetDataModuleCount(void);
	AnsiString __fastcall GetDefaultIME();
	int __fastcall GetDesktopTop(void);
	int __fastcall GetDesktopLeft(void);
	int __fastcall GetDesktopHeight(void);
	int __fastcall GetDesktopWidth(void);
	Classes::TStrings* __fastcall GetImes(void);
	int __fastcall GetHeight(void);
	TMonitor* __fastcall GetMonitor(int Index);
	int __fastcall GetMonitorCount(void);
	Classes::TStrings* __fastcall GetFonts(void);
	TForm* __fastcall GetForm(int Index);
	int __fastcall GetFormCount(void);
	void __fastcall GetMetricSettings(void);
	int __fastcall GetWidth(void);
	void __fastcall InsertCursor(int Index, HICON Handle);
	void __fastcall RemoveDataModule(TDataModule* DataModule);
	void __fastcall RemoveForm(TCustomForm* AForm);
	void __fastcall SetCursors(int Index, HICON Handle);
	void __fastcall SetCursor(Controls::TCursor Value);
	void __fastcall SetHintFont(Graphics::TFont* Value);
	void __fastcall SetIconFont(Graphics::TFont* Value);
	void __fastcall SetMenuFont(Graphics::TFont* Value);
	void __fastcall UpdateLastActive(void);
	
public:
	__fastcall virtual TScreen(Classes::TComponent* AOwner);
	__fastcall virtual ~TScreen(void);
	void __fastcall DisableAlign(void);
	void __fastcall EnableAlign(void);
	void __fastcall Realign(void);
	void __fastcall ResetFonts(void);
	__property Controls::TWinControl* ActiveControl = {read=FActiveControl};
	__property TCustomForm* ActiveCustomForm = {read=FActiveCustomForm};
	__property TForm* ActiveForm = {read=FActiveForm};
	__property int CustomFormCount = {read=GetCustomFormCount, nodefault};
	__property TCustomForm* CustomForms[int Index] = {read=GetCustomForms};
	__property Controls::TCursor Cursor = {read=FCursor, write=SetCursor, nodefault};
	__property HICON Cursors[int Index] = {read=GetCursors, write=SetCursors};
	__property TDataModule* DataModules[int Index] = {read=GetDataModule};
	__property int DataModuleCount = {read=GetDataModuleCount, nodefault};
	__property int MonitorCount = {read=GetMonitorCount, nodefault};
	__property TMonitor* Monitors[int Index] = {read=GetMonitor};
	__property int DesktopHeight = {read=GetDesktopHeight, nodefault};
	__property int DesktopLeft = {read=GetDesktopLeft, nodefault};
	__property int DesktopTop = {read=GetDesktopTop, nodefault};
	__property int DesktopWidth = {read=GetDesktopWidth, nodefault};
	__property Graphics::TFont* HintFont = {read=FHintFont, write=SetHintFont};
	__property Graphics::TFont* IconFont = {read=FIconFont, write=SetIconFont};
	__property Graphics::TFont* MenuFont = {read=FMenuFont, write=SetMenuFont};
	__property Classes::TStrings* Fonts = {read=GetFonts};
	__property int FormCount = {read=GetFormCount, nodefault};
	__property TForm* Forms[int Index] = {read=GetForm};
	__property Classes::TStrings* Imes = {read=GetImes};
	__property AnsiString DefaultIme = {read=GetDefaultIME};
	__property HKL DefaultKbLayout = {read=FDefaultKbLayout, nodefault};
	__property int Height = {read=GetHeight, nodefault};
	__property int PixelsPerInch = {read=FPixelsPerInch, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	__property Classes::TNotifyEvent OnActiveControlChange = {read=FOnActiveControlChange, write=FOnActiveControlChange
		};
	__property Classes::TNotifyEvent OnActiveFormChange = {read=FOnActiveFormChange, write=FOnActiveFormChange
		};
};


#pragma option push -b-
enum TTimerMode { tmShow, tmHide };
#pragma option pop

struct THintInfo;
typedef THintInfo *PHintInfo;

struct THintInfo
{
	Controls::TControl* HintControl;
	TMetaClass*HintWindowClass;
	Windows::TPoint HintPos;
	int HintMaxWidth;
	Graphics::TColor HintColor;
	Windows::TRect CursorRect;
	Windows::TPoint CursorPos;
	int ReshowTimeout;
	int HideTimeout;
	AnsiString HintStr;
	void *HintData;
} ;

struct TCMHintShow
{
	unsigned Msg;
	int Reserved;
	THintInfo *HintInfo;
	int Result;
} ;

struct TCMHintShowPause
{
	unsigned Msg;
	int WasActive;
	int *Pause;
	int Result;
} ;

typedef void __fastcall (__closure *TMessageEvent)(tagMSG &Msg, bool &Handled);

typedef void __fastcall (__closure *TExceptionEvent)(System::TObject* Sender, Sysutils::Exception* E
	);

typedef void __fastcall (__closure *TIdleEvent)(System::TObject* Sender, bool &Done);

typedef void __fastcall (__closure *TShowHintEvent)(AnsiString &HintStr, bool &CanShow, THintInfo &HintInfo
	);

typedef bool __fastcall (__closure *TWindowHook)(Messages::TMessage &Message);

class DELPHICLASS TApplication;
class PASCALIMPLEMENTATION TApplication : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	HWND FHandle;
	Classes::TBiDiMode FBiDiMode;
	AnsiString FBiDiKeyboard;
	AnsiString FNonBiDiKeyboard;
	void *FObjectInstance;
	TForm* FMainForm;
	Controls::TControl* FMouseControl;
	AnsiString FHelpFile;
	AnsiString FHint;
	bool FHintActive;
	bool FUpdateFormatSettings;
	bool FUpdateMetricSettings;
	bool FShowMainForm;
	Graphics::TColor FHintColor;
	Controls::TControl* FHintControl;
	Windows::TRect FHintCursorRect;
	int FHintHidePause;
	int FHintPause;
	bool FHintShortCuts;
	int FHintShortPause;
	Controls::THintWindow* FHintWindow;
	bool FShowHint;
	TTimerMode FTimerMode;
	Word FTimerHandle;
	AnsiString FTitle;
	Classes::TList* FTopMostList;
	int FTopMostLevel;
	Graphics::TIcon* FIcon;
	bool FTerminate;
	bool FActive;
	bool FAllowTesting;
	unsigned FTestLib;
	bool FHandleCreated;
	bool FRunning;
	Classes::TList* FWindowHooks;
	void *FWindowList;
	HWND FDialogHandle;
	Actnlist::TActionEvent FOnActionExecute;
	Actnlist::TActionEvent FOnActionUpdate;
	TExceptionEvent FOnException;
	TMessageEvent FOnMessage;
	Classes::THelpEvent FOnHelp;
	Classes::TNotifyEvent FOnHint;
	TIdleEvent FOnIdle;
	Classes::TNotifyEvent FOnDeactivate;
	Classes::TNotifyEvent FOnActivate;
	Classes::TNotifyEvent FOnMinimize;
	Classes::TNotifyEvent FOnRestore;
	TShortCutEvent FOnShortCut;
	TShowHintEvent FOnShowHint;
	bool __fastcall CheckIniChange(Messages::TMessage &Message);
	bool __fastcall DispatchAction(int Msg, Classes::TBasicAction* Action);
	void __fastcall DoActionIdle(void);
	Controls::TControl* __fastcall DoMouseIdle(void);
	void __fastcall DoNormalizeTopMosts(bool IncludeMain);
	AnsiString __fastcall GetCurrentHelpFile();
	HWND __fastcall GetDialogHandle(void);
	AnsiString __fastcall GetExeName();
	HICON __fastcall GetIconHandle(void);
	AnsiString __fastcall GetTitle();
	void __fastcall HintTimerExpired(void);
	void __fastcall IconChanged(System::TObject* Sender);
	void __fastcall Idle(const tagMSG &Msg);
	bool __fastcall InvokeHelp(Word Command, int Data);
	bool __fastcall IsDlgMsg(tagMSG &Msg);
	bool __fastcall IsHintMsg(tagMSG &Msg);
	bool __fastcall IsKeyMsg(tagMSG &Msg);
	bool __fastcall IsMDIMsg(tagMSG &Msg);
	bool __fastcall IsShortCut(Messages::TWMKey &Message);
	void __fastcall NotifyForms(Word Msg);
	bool __fastcall ProcessMessage(tagMSG &Msg);
	void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
	void __fastcall SetDialogHandle(HWND Value);
	void __fastcall SetHandle(HWND Value);
	void __fastcall SetHint(const AnsiString Value);
	void __fastcall SetHintColor(Graphics::TColor Value);
	void __fastcall SetIcon(Graphics::TIcon* Value);
	void __fastcall SetShowHint(bool Value);
	void __fastcall SetTitle(const AnsiString Value);
	void __fastcall StartHintTimer(int Value, TTimerMode TimerMode);
	void __fastcall StopHintTimer(void);
	void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall UpdateVisible(void);
	
public:
	__fastcall virtual TApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TApplication(void);
	void __fastcall ActivateHint(const Windows::TPoint &CursorPos);
	void __fastcall BringToFront(void);
	void __fastcall ControlDestroyed(Controls::TControl* Control);
	void __fastcall CancelHint(void);
	void __fastcall CreateForm(TMetaClass* InstanceClass, void *Reference);
	void __fastcall CreateHandle(void);
	HIDESBASE bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	void __fastcall HandleException(System::TObject* Sender);
	void __fastcall HandleMessage(void);
	bool __fastcall HelpCommand(int Command, int Data);
	bool __fastcall HelpContext(Classes::THelpContext Context);
	bool __fastcall HelpJump(const AnsiString JumpID);
	void __fastcall HideHint(void);
	void __fastcall HintMouseMessage(Controls::TControl* Control, Messages::TMessage &Message);
	void __fastcall HookMainWindow(TWindowHook Hook);
	void __fastcall Initialize(void);
	bool __fastcall IsRightToLeft(void);
	int __fastcall MessageBox(const char * Text, const char * Caption, int Flags);
	void __fastcall Minimize(void);
	void __fastcall NormalizeAllTopMosts(void);
	void __fastcall NormalizeTopMosts(void);
	void __fastcall ProcessMessages(void);
	void __fastcall Restore(void);
	void __fastcall RestoreTopMosts(void);
	void __fastcall Run(void);
	void __fastcall ShowException(Sysutils::Exception* E);
	void __fastcall Terminate(void);
	void __fastcall UnhookMainWindow(TWindowHook Hook);
	HIDESBASE bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	bool __fastcall UseRightToLeftAlignment(void);
	bool __fastcall UseRightToLeftReading(void);
	bool __fastcall UseRightToLeftScrollBar(void);
	__property bool Active = {read=FActive, nodefault};
	__property bool AllowTesting = {read=FAllowTesting, write=FAllowTesting, nodefault};
	__property AnsiString CurrentHelpFile = {read=GetCurrentHelpFile};
	__property HWND DialogHandle = {read=GetDialogHandle, write=SetDialogHandle, nodefault};
	__property AnsiString ExeName = {read=GetExeName};
	__property HWND Handle = {read=FHandle, write=SetHandle, nodefault};
	__property AnsiString HelpFile = {read=FHelpFile, write=FHelpFile};
	__property AnsiString Hint = {read=FHint, write=SetHint};
	__property Graphics::TColor HintColor = {read=FHintColor, write=SetHintColor, nodefault};
	__property int HintHidePause = {read=FHintHidePause, write=FHintHidePause, nodefault};
	__property int HintPause = {read=FHintPause, write=FHintPause, nodefault};
	__property bool HintShortCuts = {read=FHintShortCuts, write=FHintShortCuts, nodefault};
	__property int HintShortPause = {read=FHintShortPause, write=FHintShortPause, nodefault};
	__property Graphics::TIcon* Icon = {read=FIcon, write=SetIcon};
	__property TForm* MainForm = {read=FMainForm};
	__property Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, default=0};
	__property AnsiString BiDiKeyboard = {read=FBiDiKeyboard, write=FBiDiKeyboard};
	__property AnsiString NonBiDiKeyboard = {read=FNonBiDiKeyboard, write=FNonBiDiKeyboard};
	__property bool ShowHint = {read=FShowHint, write=SetShowHint, nodefault};
	__property bool ShowMainForm = {read=FShowMainForm, write=FShowMainForm, nodefault};
	__property bool Terminated = {read=FTerminate, nodefault};
	__property AnsiString Title = {read=GetTitle, write=SetTitle};
	__property bool UpdateFormatSettings = {read=FUpdateFormatSettings, write=FUpdateFormatSettings, nodefault
		};
	__property bool UpdateMetricSettings = {read=FUpdateMetricSettings, write=FUpdateMetricSettings, nodefault
		};
	__property Actnlist::TActionEvent OnActionExecute = {read=FOnActionExecute, write=FOnActionExecute}
		;
	__property Actnlist::TActionEvent OnActionUpdate = {read=FOnActionUpdate, write=FOnActionUpdate};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property TExceptionEvent OnException = {read=FOnException, write=FOnException};
	__property TIdleEvent OnIdle = {read=FOnIdle, write=FOnIdle};
	__property Classes::THelpEvent OnHelp = {read=FOnHelp, write=FOnHelp};
	__property Classes::TNotifyEvent OnHint = {read=FOnHint, write=FOnHint};
	__property TMessageEvent OnMessage = {read=FOnMessage, write=FOnMessage};
	__property Classes::TNotifyEvent OnMinimize = {read=FOnMinimize, write=FOnMinimize};
	__property Classes::TNotifyEvent OnRestore = {read=FOnRestore, write=FOnRestore};
	__property TShowHintEvent OnShowHint = {read=FOnShowHint, write=FOnShowHint};
	__property TShortCutEvent OnShortCut = {read=FOnShortCut, write=FOnShortCut};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TApplication* Application;
extern PACKAGE TScreen* Screen;
extern PACKAGE void *Ctl3DBtnWndProc;
extern PACKAGE int __stdcall (*Ctl3DDlgFramePaint)(HWND Window, int Msg, int wParam, int lParam);
extern PACKAGE int __stdcall (*Ctl3DCtlColorEx)(HWND Window, int Msg, int wParam, int lParam);
extern PACKAGE TMetaClass*HintWindowClass;
extern PACKAGE void * __fastcall DisableTaskWindows(HWND ActiveWindow);
extern PACKAGE void __fastcall EnableTaskWindows(void * WindowList);
extern PACKAGE bool __fastcall ForegroundTask(void);
extern PACKAGE void __fastcall InitCtl3D(void);
extern PACKAGE void __fastcall DoneCtl3D(void);
extern PACKAGE bool __fastcall Subclass3DWnd(HWND Wnd);
extern PACKAGE void __fastcall Subclass3DDlg(HWND Wnd, Word Flags);
extern PACKAGE void __fastcall SetAutoSubClass(bool Enable);
extern PACKAGE void * __fastcall MakeObjectInstance(Controls::TWndMethod Method);
extern PACKAGE void __fastcall FreeObjectInstance(void * ObjectInstance);
extern PACKAGE HWND __fastcall AllocateHWnd(Controls::TWndMethod Method);
extern PACKAGE void __fastcall DeallocateHWnd(HWND Wnd);
extern PACKAGE Classes::TShiftState __fastcall KeysToShiftState(Word Keys);
extern PACKAGE Classes::TShiftState __fastcall KeyDataToShiftState(int KeyData);
extern PACKAGE Classes::TShiftState __fastcall KeyboardStateToShiftState(const Byte * KeyboardState)
	;
extern PACKAGE bool __fastcall IsAccel(Word VK, const AnsiString Str);
extern PACKAGE TCustomForm* __fastcall GetParentForm(Controls::TControl* Control);
extern PACKAGE TCustomForm* __fastcall ValidParentForm(Controls::TControl* Control);

}	/* namespace Forms */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Forms;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Forms
