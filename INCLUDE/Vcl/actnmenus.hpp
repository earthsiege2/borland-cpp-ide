// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ActnMenus.pas' rev: 6.00

#ifndef ActnMenusHPP
#define ActnMenusHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ActnCtrls.hpp>	// Pascal unit
#include <ActnMan.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "dclact.lib"

namespace Actnmenus
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMenuStack;
class DELPHICLASS TCustomActionMenuBar;
class PASCALIMPLEMENTATION TMenuStack : public Contnrs::TStack 
{
	typedef Contnrs::TStack inherited;
	
private:
	TCustomActionMenuBar* __fastcall GetBars(const int Index);
	
protected:
	__property TCustomActionMenuBar* Bars[int Index] = {read=GetBars};
	
public:
	HIDESBASE void __fastcall Push(TCustomActionMenuBar* Container);
	HIDESBASE TCustomActionMenuBar* __fastcall Pop(void);
	HIDESBASE TCustomActionMenuBar* __fastcall Peek(void);
public:
	#pragma option push -w-inl
	/* TOrderedList.Create */ inline __fastcall TMenuStack(void) : Contnrs::TStack() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOrderedList.Destroy */ inline __fastcall virtual ~TMenuStack(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TAnimationStyle { asNone, asDefault, asUnFold, asSlide, asFade };
#pragma option pop

typedef void __fastcall (__closure *TMenuPopupEvent)(System::TObject* Sender, Actnman::TCustomActionControl* Item);

typedef TMetaClass*TCustomPopupClass;

typedef void __fastcall (*TGetPopupClassEvent)(System::TObject* Sender, TMetaClass* &PopupClass);

class DELPHICLASS TCustomActionPopupMenu;
class PASCALIMPLEMENTATION TCustomActionMenuBar : public Actnctrls::TCustomActionDockBar 
{
	typedef Actnctrls::TCustomActionDockBar inherited;
	
private:
	bool FAnimatePopups;
	TAnimationStyle FAnimationStyle;
	AnsiString FCommandSound;
	Actnman::TCustomActionControl* FDelayItem;
	Actnman::TCustomActionControl* FDragItem;
	bool FExpandable;
	bool FExpanded;
	bool FInMenuLoop;
	bool FItemKeyed;
	TCustomActionMenuBar* FParentMenu;
	Actnman::TCustomActionControl* FParentControl;
	TMenuStack* FPopupStack;
	Registry::TRegistry* FRegistry;
	TMenuPopupEvent FOnPopup;
	int FExpandDelay;
	AnsiString FPopupSound;
	TCustomActionMenuBar* FRootMenu;
	bool FDefaultFont;
	TGetPopupClassEvent FOnGetPopupClass;
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMEnterMenuLoop(Messages::TMessage &Message);
	MESSAGE void __fastcall CMItemClicked(Actnman::TCMItemMsg &Message);
	MESSAGE void __fastcall WMMouseActivate(Messages::TWMMouseActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMSysKeyDown(Messages::TWMKey &Message);
	void __fastcall SetParentMenu(const TCustomActionMenuBar* Value);
	MESSAGE void __fastcall CMItemKeyed(Actnman::TCMItemMsg &Message);
	
protected:
	TCustomActionMenuBar* FChildMenu;
	Extctrls::TTimer* FExpandTimer;
	Extctrls::TTimer* FPopupTimer;
	void __fastcall Animate(bool Show = true);
	void __fastcall ClearSubMenus(void);
	void __fastcall CleanupStack(void);
	virtual Actnman::TCustomActionControl* __fastcall CreateControl(Actnman::TActionClientItem* AnItem);
	virtual TCustomActionPopupMenu* __fastcall CreatePopup(TCustomActionMenuBar* AOwner, Actnman::TCustomActionControl* Item);
	void __fastcall DoItemSelected(Actnman::TCustomActionControl* AnItem);
	DYNAMIC TMetaClass* __fastcall DoGetPopupClass(void);
	virtual Actnman::TActionClientItem* __fastcall DoItemClicked(Actnman::TCustomActionControl* AnItem);
	virtual Actnman::TActionClientItem* __fastcall DoItemKeyed(Actnman::TCustomActionControl* AnItem);
	void __fastcall DoMenuDelay(System::TObject* Sender);
	virtual void __fastcall DoneMenuLoop(void);
	virtual void __fastcall ExecAction(Actnlist::TContainedAction* Action);
	virtual void __fastcall Expand(bool Full);
	void __fastcall ExpandTimer(System::TObject* Sender);
	void __fastcall GetDefaultSounds(void);
	virtual bool __fastcall GetDesignMode(void);
	virtual TMetaClass* __fastcall GetControlClass(Actnman::TActionClientItem* AnItem);
	TMetaClass* __fastcall GetPopupClass(void);
	Actnman::TCustomActionControl* __fastcall GetMouseHoverItem(const tagMSG &Msg);
	Actnman::TActionClientItem* __fastcall GetSelected(void);
	void __fastcall InitMenuLoop(void);
	bool __fastcall IsDesignMsg(tagMSG &Msg);
	virtual TCustomActionPopupMenu* __fastcall NewPopup(void);
	__property TMenuStack* PopupStack = {read=FPopupStack};
	virtual Actnman::TActionClientItem* __fastcall ProcessMenuLoop(void);
	virtual void __fastcall ProcessMouseMsg(tagMSG &Msg);
	void __fastcall SelectItem(Actnman::TCustomActionControl* AnItem);
	void __fastcall Select(const bool Forward);
	virtual void __fastcall SetDesignMode(const bool Value);
	virtual void __fastcall SetPersistentHotkeys(const bool Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property Actnman::TCustomActionControl* DelayItem = {read=FDelayItem, write=FDelayItem};
	__property bool Expandable = {read=FExpandable, write=FExpandable, nodefault};
	__property bool Expanded = {read=FExpanded, write=FExpanded, nodefault};
	__property TCustomActionMenuBar* ParentMenu = {read=FParentMenu, write=SetParentMenu};
	__property Actnman::TActionClientItem* Selected = {read=GetSelected};
	
public:
	__fastcall virtual TCustomActionMenuBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionMenuBar(void);
	virtual void __fastcall CloseMenu(void);
	virtual void __fastcall TrackMenu(void);
	__property TAnimationStyle AnimationStyle = {read=FAnimationStyle, write=FAnimationStyle, nodefault};
	__property int ExpandDelay = {read=FExpandDelay, write=FExpandDelay, nodefault};
	__property bool InMenuLoop = {read=FInMenuLoop, write=FInMenuLoop, nodefault};
	__property Actnman::TCustomActionControl* ParentControl = {read=FParentControl, write=FParentControl};
	__property TCustomActionMenuBar* RootMenu = {read=FRootMenu, write=FRootMenu};
	__property TGetPopupClassEvent OnGetPopupClass = {read=FOnGetPopupClass, write=FOnGetPopupClass};
	__property TMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionMenuBar(HWND ParentWindow) : Actnctrls::TCustomActionDockBar(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomMenuExpandBtn;
class PASCALIMPLEMENTATION TCustomMenuExpandBtn : public Actnctrls::TCustomUtilityButton 
{
	typedef Actnctrls::TCustomUtilityButton inherited;
	
protected:
	virtual void __fastcall DrawBackground(Types::TRect &PaintRect);
	virtual void __fastcall DrawFrame(const Types::TRect &ARect, bool Down);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
public:
	#pragma option push -w-inl
	/* TCustomUtilityButton.Create */ inline __fastcall virtual TCustomMenuExpandBtn(Classes::TComponent* AOwner) : Actnctrls::TCustomUtilityButton(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomUtilityButton.Destroy */ inline __fastcall virtual ~TCustomMenuExpandBtn(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomMenuItem;
class PASCALIMPLEMENTATION TCustomActionPopupMenu : public TCustomActionMenuBar 
{
	typedef TCustomActionMenuBar inherited;
	
private:
	TCustomMenuExpandBtn* FExpandBtn;
	#pragma pack(push, 1)
	Types::TPoint FExpandedSize;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FMenuSize;
	#pragma pack(pop)
	
	
protected:
	virtual void __fastcall AddEdges(TCustomMenuItem* AnItem);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	virtual Actnman::TCustomActionControl* __fastcall CreateControl(Actnman::TActionClientItem* AnItem);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC bool __fastcall DesignWndProc(Messages::TMessage &Message);
	virtual void __fastcall ExecAction(Actnlist::TContainedAction* Action);
	void __fastcall ExpandClick(System::TObject* Sender);
	virtual int __fastcall GetBarHeight(void);
	virtual TMetaClass* __fastcall GetControlClass(Actnman::TActionClientItem* AnItem);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall PositionPopup(Actnman::TCustomActionBar* AnOwner, Actnman::TCustomActionControl* ParentItem);
	virtual void __fastcall SetActionClient(const Actnman::TActionClient* Value);
	void __fastcall SetupExpandBtn(void);
	virtual void __fastcall SetOrientation(const Actnman::TBarOrientation Value);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMPrint(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPrintClient(Messages::TMessage &Message);
	DYNAMIC void __fastcall VisibleChanging(void);
	
public:
	__fastcall virtual TCustomActionPopupMenu(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionPopupMenu(void);
	virtual void __fastcall CloseMenu(void);
	virtual void __fastcall Expand(bool Full);
	void __fastcall Popup(int X, int Y);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TCustomMenuExpandBtn* ExpandBtn = {read=FExpandBtn, write=FExpandBtn};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionPopupMenu(HWND ParentWindow) : TCustomActionMenuBar(ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TCustomizeActionToolBarClass;

class DELPHICLASS TCustomizeActionToolBar;
class PASCALIMPLEMENTATION TCustomizeActionToolBar : public TCustomActionPopupMenu 
{
	typedef TCustomActionPopupMenu inherited;
	
private:
	Actnctrls::TCustomActionToolBar* FActionBar;
	Actnman::TActionClientItem* FAddlItem;
	Actnlist::TCustomAction* FResetAction;
	Actnman::TActionClientItem* FResetItem;
	MESSAGE void __fastcall CMItemSelected(Actnman::TCMItemMsg &Message);
	
protected:
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual void __fastcall Clear(void);
	virtual Actnman::TActionClientItem* __fastcall DoItemClicked(Actnman::TCustomActionControl* AnItem);
	virtual Actnman::TCustomActionControl* __fastcall GetActionControl(const int Index);
	virtual TMetaClass* __fastcall GetControlClass(Actnman::TActionClientItem* AnItem);
	void __fastcall GetSubMenuControlClass(Actnman::TCustomActionBar* Sender, Actnman::TActionClient* AnItem, TMetaClass* &ControlClass);
	DYNAMIC TMetaClass* __fastcall DoGetPopupClass(void);
	virtual TCustomActionPopupMenu* __fastcall NewPopup(void);
	virtual void __fastcall SetActionClient(const Actnman::TActionClient* Value);
	
public:
	__fastcall virtual TCustomizeActionToolBar(Classes::TComponent* AOwner);
	virtual void __fastcall CloseMenu(void);
	virtual int __fastcall ItemCount(void);
	__fastcall virtual ~TCustomizeActionToolBar(void);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomizeActionToolBar(HWND ParentWindow) : TCustomActionPopupMenu(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomizeActionLink;
class PASCALIMPLEMENTATION TCustomizeActionLink : public Actnman::TActionClientLink 
{
	typedef Actnman::TActionClientLink inherited;
	
protected:
	virtual void __fastcall SetEnabled(bool Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TCustomizeActionLink(System::TObject* AClient) : Actnman::TActionClientLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TCustomizeActionLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomizeActionClientItem;
class PASCALIMPLEMENTATION TCustomizeActionClientItem : public Actnman::TActionClientItem 
{
	typedef Actnman::TActionClientItem inherited;
	
protected:
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
public:
	#pragma option push -w-inl
	/* TActionClientItem.Create */ inline __fastcall virtual TCustomizeActionClientItem(Classes::TCollection* Collection) : Actnman::TActionClientItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TActionClientItem.Destroy */ inline __fastcall virtual ~TCustomizeActionClientItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomActionMainMenuBar;
class PASCALIMPLEMENTATION TCustomActionMainMenuBar : public TCustomActionMenuBar 
{
	typedef TCustomActionMenuBar inherited;
	
private:
	bool FInActive;
	void __fastcall SetInActive(const bool Value);
	
protected:
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Types::TRect &Rect);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual Actnman::TCustomActionControl* __fastcall CreateControl(Actnman::TActionClientItem* AnItem);
	DYNAMIC bool __fastcall DesignWndProc(Messages::TMessage &Message);
	virtual void __fastcall DoneMenuLoop(void);
	virtual TMetaClass* __fastcall GetControlClass(Actnman::TActionClientItem* AnItem);
	virtual void __fastcall ProcessMouseMsg(tagMSG &Msg);
	virtual void __fastcall SetDesignMode(const bool Value);
	HIDESBASE MESSAGE void __fastcall CMWininichange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	
public:
	__fastcall virtual TCustomActionMainMenuBar(Classes::TComponent* AOwner);
	virtual void __fastcall CloseMenu(void);
	__property bool Inactive = {read=FInActive, write=SetInActive, nodefault};
	__property PersistentHotKeys ;
public:
	#pragma option push -w-inl
	/* TCustomActionMenuBar.Destroy */ inline __fastcall virtual ~TCustomActionMainMenuBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomActionMainMenuBar(HWND ParentWindow) : TCustomActionMenuBar(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TActionMainMenuBar;
class PASCALIMPLEMENTATION TActionMainMenuBar : public TCustomActionMainMenuBar 
{
	typedef TCustomActionMainMenuBar inherited;
	
__published:
	__property ActionManager ;
	__property Align  = {default=1};
	__property AllowHiding  = {default=0};
	__property Anchors  = {default=3};
	__property AnimationStyle  = {default=1};
	__property BiDiMode  = {default=0};
	__property Caption ;
	__property Color  = {default=-2147483644};
	__property Constraints ;
	__property EdgeBorders  = {default=2};
	__property EdgeInner  = {default=1};
	__property EdgeOuter  = {default=2};
	__property Enabled  = {default=1};
	__property ExpandDelay  = {default=4000};
	__property Font ;
	__property HorzMargin  = {default=1};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property ShowHint ;
	__property Spacing ;
	__property VertMargin  = {default=1};
	__property Visible  = {default=1};
	__property OnCanResize ;
	__property OnClick ;
	__property OnControlCreated ;
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
	/* TCustomActionMainMenuBar.Create */ inline __fastcall virtual TActionMainMenuBar(Classes::TComponent* AOwner) : TCustomActionMainMenuBar(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomActionMenuBar.Destroy */ inline __fastcall virtual ~TActionMainMenuBar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TActionMainMenuBar(HWND ParentWindow) : TCustomActionMainMenuBar(ParentWindow) { }
	#pragma option pop
	
};


typedef Set<Toolwin::TEdgeBorder, ebLeft, ebBottom>  TMenuEdges;

class PASCALIMPLEMENTATION TCustomMenuItem : public Actnman::TCustomActionControl 
{
	typedef Actnman::TCustomActionControl inherited;
	
private:
	TMenuEdges FEdges;
	TCustomActionMenuBar* FMenu;
	bool FMouseSelected;
	#pragma pack(push, 1)
	Types::TRect FShortCutBounds;
	#pragma pack(pop)
	
	void __fastcall SetEdges(const TMenuEdges Value);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextchanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CalcLayout(void);
	virtual void __fastcall DoDragDrop(System::TObject* DragObject, int X, int Y);
	virtual void __fastcall DrawDesignFocus(Types::TRect &PaintRect);
	virtual void __fastcall DrawEdge(TMenuEdges Edges);
	virtual void __fastcall DrawSubMenuGlyph(void);
	virtual void __fastcall DrawUnusedEdges(void);
	virtual Types::TPoint __fastcall GetImageSize();
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PositionChanged(void);
	virtual void __fastcall SetSelected(bool Value);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	__property TCustomActionMenuBar* Menu = {read=FMenu};
	__property bool MouseSelected = {read=FMouseSelected, nodefault};
	__property Types::TRect ShortCutBounds = {read=FShortCutBounds, write=FShortCutBounds};
	
public:
	__fastcall virtual TCustomMenuItem(Classes::TComponent* AOwner);
	virtual void __fastcall CalcBounds(void);
	DYNAMIC void __fastcall Click(void);
	__fastcall virtual ~TCustomMenuItem(void);
	virtual void __fastcall Keyed(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	__property TMenuEdges Edges = {read=FEdges, write=SetEdges, nodefault};
};


class DELPHICLASS TCustomMenuButton;
class PASCALIMPLEMENTATION TCustomMenuButton : public Actnctrls::TCustomButtonControl 
{
	typedef Actnctrls::TCustomButtonControl inherited;
	
protected:
	DYNAMIC void __fastcall BeginAutoDrag(void);
	virtual void __fastcall DoDragDrop(System::TObject* DragObject, int X, int Y);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	virtual void __fastcall DrawText(Types::TRect &ARect, unsigned &Flags, AnsiString Text);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual ~TCustomMenuButton(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall Keyed(void);
public:
	#pragma option push -w-inl
	/* TCustomButtonControl.Create */ inline __fastcall virtual TCustomMenuButton(Classes::TComponent* AOwner) : Actnctrls::TCustomButtonControl(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomAddRemoveItem;
class PASCALIMPLEMENTATION TCustomAddRemoveItem : public TCustomMenuItem 
{
	typedef TCustomMenuItem inherited;
	
protected:
	bool __fastcall IsActionVisible(void);
	virtual void __fastcall SetEnabled(bool Value);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	
public:
	virtual void __fastcall CalcBounds(void);
public:
	#pragma option push -w-inl
	/* TCustomMenuItem.Create */ inline __fastcall virtual TCustomAddRemoveItem(Classes::TComponent* AOwner) : TCustomMenuItem(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomMenuItem.Destroy */ inline __fastcall virtual ~TCustomAddRemoveItem(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TMenuItemControlClass;

typedef TMetaClass*TAddRemoveItemClass;

typedef TMetaClass*TMenuButtonControlClass;

typedef void __fastcall (*TUpdateActnMenusProc)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TMetaClass*MenuItemControlClass;
extern PACKAGE TMetaClass*MenuAddRemoveItemClass;
extern PACKAGE TMetaClass*MenuButtonControlClass;
extern PACKAGE TMetaClass*MenuPopupClass;
extern PACKAGE TMetaClass*MenuCustomizePopupClass;
extern PACKAGE TUpdateActnMenusProc UpdateActnMenusProc;

}	/* namespace Actnmenus */
using namespace Actnmenus;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActnMenus
