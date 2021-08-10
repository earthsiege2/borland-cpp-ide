// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ComCtrls.pas' rev: 5.00

#ifndef ComCtrlsHPP
#define ComCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <RichEdit.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Commctrl.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Comctrls
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum THitTest { htAbove, htBelow, htNowhere, htOnItem, htOnButton, htOnIcon, htOnIndent, htOnLabel, 
	htOnRight, htOnStateIcon, htToLeft, htToRight };
#pragma option pop

typedef Set<THitTest, htAbove, htToRight>  THitTests;

typedef void __fastcall (__closure *TTabChangingEvent)(System::TObject* Sender, bool &AllowChange);

#pragma option push -b-
enum TTabPosition { tpTop, tpBottom, tpLeft, tpRight };
#pragma option pop

#pragma option push -b-
enum TTabStyle { tsTabs, tsButtons, tsFlatButtons };
#pragma option pop

class DELPHICLASS TCustomTabControl;
typedef void __fastcall (__closure *TDrawTabEvent)(TCustomTabControl* Control, int TabIndex, const Windows::TRect 
	&Rect, bool Active);

typedef void __fastcall (__closure *TTabGetImageEvent)(System::TObject* Sender, int TabIndex, int &ImageIndex
	);

class PASCALIMPLEMENTATION TCustomTabControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	bool FHotTrack;
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FImages;
	bool FMultiLine;
	bool FMultiSelect;
	bool FOwnerDraw;
	bool FRaggedRight;
	int FSaveTabIndex;
	Classes::TStringList* FSaveTabs;
	bool FScrollOpposite;
	TTabStyle FStyle;
	TTabPosition FTabPosition;
	Classes::TStrings* FTabs;
	#pragma pack(push, 1)
	Windows::TSmallPoint FTabSize;
	#pragma pack(pop)
	
	bool FUpdating;
	Classes::TNotifyEvent FOnChange;
	TTabChangingEvent FOnChanging;
	TDrawTabEvent FOnDrawTab;
	TTabGetImageEvent FOnGetImageIndex;
	Windows::TRect __fastcall GetDisplayRect();
	int __fastcall GetTabIndex(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	bool __fastcall InternalSetMultiLine(bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetImages(Imglist::TCustomImageList* Value);
	void __fastcall SetMultiLine(bool Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetOwnerDraw(bool Value);
	void __fastcall SetRaggedRight(bool Value);
	void __fastcall SetScrollOpposite(bool Value);
	void __fastcall SetStyle(TTabStyle Value);
	void __fastcall SetTabHeight(short Value);
	void __fastcall SetTabIndex(int Value);
	void __fastcall SetTabPosition(TTabPosition Value);
	void __fastcall SetTabs(Classes::TStrings* Value);
	void __fastcall SetTabWidth(short Value);
	void __fastcall TabsChanged(void);
	void __fastcall UpdateTabSize(void);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(void *Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	MESSAGE void __fastcall CMTabStopChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNDrawItem(Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMNotifyFormat(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(Windows::TRect &Rect);
	DYNAMIC bool __fastcall CanChange(void);
	virtual bool __fastcall CanShowTab(int TabIndex);
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DrawTab(int TabIndex, const Windows::TRect &Rect, bool Active);
	virtual int __fastcall GetImageIndex(int TabIndex);
	virtual void __fastcall Loaded(void);
	void __fastcall UpdateTabImages(void);
	__property Windows::TRect DisplayRect = {read=GetDisplayRect};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool MultiLine = {read=FMultiLine, write=SetMultiLine, default=0};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	__property bool OwnerDraw = {read=FOwnerDraw, write=SetOwnerDraw, default=0};
	__property bool RaggedRight = {read=FRaggedRight, write=SetRaggedRight, default=0};
	__property bool ScrollOpposite = {read=FScrollOpposite, write=SetScrollOpposite, default=0};
	__property TTabStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property short TabHeight = {read=FTabSize.y, write=SetTabHeight, default=0};
	__property int TabIndex = {read=GetTabIndex, write=SetTabIndex, default=-1};
	__property TTabPosition TabPosition = {read=FTabPosition, write=SetTabPosition, default=0};
	__property Classes::TStrings* Tabs = {read=FTabs, write=SetTabs};
	__property short TabWidth = {read=FTabSize.x, write=SetTabWidth, default=0};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TTabChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TDrawTabEvent OnDrawTab = {read=FOnDrawTab, write=FOnDrawTab};
	__property TTabGetImageEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	
public:
	__fastcall virtual TCustomTabControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTabControl(void);
	int __fastcall IndexOfTabAt(int X, int Y);
	THitTests __fastcall GetHitTestInfoAt(int X, int Y);
	Windows::TRect __fastcall TabRect(int Index);
	int __fastcall RowCount(void);
	void __fastcall ScrollTabs(int Delta);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property TabStop ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTabControl(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTabControl;
class PASCALIMPLEMENTATION TTabControl : public TCustomTabControl 
{
	typedef TCustomTabControl inherited;
	
public:
	__property DisplayRect ;
	
__published:
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property Constraints ;
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HotTrack ;
	__property Images ;
	__property MultiLine ;
	__property MultiSelect ;
	__property OwnerDraw ;
	__property ParentBiDiMode ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property RaggedRight ;
	__property ScrollOpposite ;
	__property ShowHint ;
	__property Style ;
	__property TabHeight ;
	__property TabOrder ;
	__property TabPosition ;
	__property Tabs ;
	__property TabIndex ;
	__property TabStop ;
	__property TabWidth ;
	__property Visible ;
	__property OnChange ;
	__property OnChanging ;
	__property OnContextPopup ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawTab ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetImageIndex ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TCustomTabControl.Create */ inline __fastcall virtual TTabControl(Classes::TComponent* AOwner) : 
		TCustomTabControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTabControl.Destroy */ inline __fastcall virtual ~TTabControl(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTabControl(HWND ParentWindow) : TCustomTabControl(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TTabSheet;
class DELPHICLASS TPageControl;
class PASCALIMPLEMENTATION TPageControl : public TCustomTabControl 
{
	typedef TCustomTabControl inherited;
	
private:
	Classes::TList* FPages;
	TTabSheet* FActivePage;
	TTabSheet* FNewDockSheet;
	TTabSheet* FUndockingPage;
	void __fastcall ChangeActivePage(TTabSheet* Page);
	void __fastcall DeleteTab(TTabSheet* Page, int Index);
	int __fastcall GetActivePageIndex(void);
	Controls::TControl* __fastcall GetDockClientFromMousePos(const Windows::TPoint &MousePos);
	TTabSheet* __fastcall GetPage(int Index);
	int __fastcall GetPageCount(void);
	void __fastcall InsertPage(TTabSheet* Page);
	void __fastcall InsertTab(TTabSheet* Page);
	void __fastcall MoveTab(int CurIndex, int NewIndex);
	void __fastcall RemovePage(TTabSheet* Page);
	void __fastcall SetActivePage(TTabSheet* Page);
	void __fastcall SetActivePageIndex(const int Value);
	void __fastcall UpdateTab(TTabSheet* Page);
	void __fastcall UpdateTabHighlights(void);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMDockClient(Controls::TCMDockClient &Message);
	MESSAGE void __fastcall CMDockNotification(Controls::TCMDockNotification &Message);
	HIDESBASE MESSAGE void __fastcall CMUnDockClient(Controls::TCMUnDockClient &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	
protected:
	virtual bool __fastcall CanShowTab(int TabIndex);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall DoAddDockClient(Controls::TControl* Client, const Windows::TRect &ARect);
	DYNAMIC void __fastcall DockOver(Controls::TDragDockObject* Source, int X, int Y, Controls::TDragState 
		State, bool &Accept);
	DYNAMIC void __fastcall DoRemoveDockClient(Controls::TControl* Client);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual int __fastcall GetImageIndex(int TabIndex);
	TTabSheet* __fastcall GetPageFromDockClient(Controls::TControl* Client);
	DYNAMIC void __fastcall GetSiteInfo(Controls::TControl* Client, Windows::TRect &InfluenceRect, const 
		Windows::TPoint &MousePos, bool &CanDock);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	virtual void __fastcall ShowControl(Controls::TControl* AControl);
	virtual void __fastcall UpdateActivePage(void);
	
public:
	__fastcall virtual TPageControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TPageControl(void);
	TTabSheet* __fastcall FindNextPage(TTabSheet* CurPage, bool GoForward, bool CheckTabVisible);
	void __fastcall SelectNextPage(bool GoForward);
	__property int ActivePageIndex = {read=GetActivePageIndex, write=SetActivePageIndex, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TTabSheet* Pages[int Index] = {read=GetPage};
	
__published:
	__property TTabSheet* ActivePage = {read=FActivePage, write=SetActivePage};
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property Constraints ;
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HotTrack ;
	__property Images ;
	__property MultiLine ;
	__property OwnerDraw ;
	__property ParentBiDiMode ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property RaggedRight ;
	__property ScrollOpposite ;
	__property ShowHint ;
	__property Style ;
	__property TabHeight ;
	__property TabOrder ;
	__property TabPosition ;
	__property TabStop ;
	__property TabWidth ;
	__property Visible ;
	__property OnChange ;
	__property OnChanging ;
	__property OnContextPopup ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawTab ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetImageIndex ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPageControl(HWND ParentWindow) : TCustomTabControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTabSheet : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Imglist::TImageIndex FImageIndex;
	TPageControl* FPageControl;
	bool FTabVisible;
	bool FTabShowing;
	bool FHighlighted;
	Classes::TNotifyEvent FOnHide;
	Classes::TNotifyEvent FOnShow;
	int __fastcall GetPageIndex(void);
	int __fastcall GetTabIndex(void);
	void __fastcall SetHighlighted(bool Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetPageControl(TPageControl* APageControl);
	void __fastcall SetPageIndex(int Value);
	void __fastcall SetTabShowing(bool Value);
	void __fastcall SetTabVisible(bool Value);
	void __fastcall UpdateTabShowing(void);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	
public:
	__fastcall virtual TTabSheet(Classes::TComponent* AOwner);
	__fastcall virtual ~TTabSheet(void);
	__property TPageControl* PageControl = {read=FPageControl, write=SetPageControl};
	__property int TabIndex = {read=GetTabIndex, nodefault};
	
__published:
	__property BorderWidth ;
	__property Caption ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property Height  = {stored=false};
	__property bool Highlighted = {read=FHighlighted, write=SetHighlighted, default=0};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=0};
	__property Left  = {stored=false};
	__property Constraints ;
	__property int PageIndex = {read=GetPageIndex, write=SetPageIndex, stored=false, nodefault};
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property bool TabVisible = {read=FTabVisible, write=SetTabVisible, default=1};
	__property Top  = {stored=false};
	__property Visible  = {stored=false, default=1};
	__property Width  = {stored=false};
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property Classes::TNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTabSheet(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TStatusPanelStyle { psText, psOwnerDraw };
#pragma option pop

#pragma option push -b-
enum TStatusPanelBevel { pbNone, pbLowered, pbRaised };
#pragma option pop

class DELPHICLASS TStatusPanel;
class PASCALIMPLEMENTATION TStatusPanel : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FText;
	int FWidth;
	Classes::TAlignment FAlignment;
	TStatusPanelBevel FBevel;
	Classes::TBiDiMode FBiDiMode;
	bool FParentBiDiMode;
	TStatusPanelStyle FStyle;
	bool FUpdateNeeded;
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetBevel(TStatusPanelBevel Value);
	void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
	void __fastcall SetParentBiDiMode(bool Value);
	void __fastcall SetStyle(TStatusPanelStyle Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetWidth(int Value);
	bool __fastcall IsBiDiModeStored(void);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TStatusPanel(Classes::TCollection* Collection);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall ParentBiDiModeChanged(void);
	bool __fastcall UseRightToLeftAlignment(void);
	bool __fastcall UseRightToLeftReading(void);
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property TStatusPanelBevel Bevel = {read=FBevel, write=SetBevel, default=1};
	__property Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored
		, nodefault};
	__property bool ParentBiDiMode = {read=FParentBiDiMode, write=SetParentBiDiMode, default=1};
	__property TStatusPanelStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property AnsiString Text = {read=FText, write=SetText};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TStatusPanel(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStatusPanels;
class DELPHICLASS TStatusBar;
typedef void __fastcall (__closure *TDrawPanelEvent)(TStatusBar* StatusBar, TStatusPanel* Panel, const 
	Windows::TRect &Rect);

class PASCALIMPLEMENTATION TStatusBar : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TStatusPanels* FPanels;
	Graphics::TCanvas* FCanvas;
	AnsiString FSimpleText;
	bool FSimplePanel;
	bool FSizeGrip;
	bool FUseSystemFont;
	bool FAutoHint;
	TDrawPanelEvent FOnDrawPanel;
	Classes::TNotifyEvent FOnHint;
	void __fastcall DoRightToLeftAlignment(AnsiString &Str, Classes::TAlignment AAlignment, bool ARTLAlignment
		);
	HIDESBASE bool __fastcall IsFontStored(void);
	void __fastcall SetPanels(TStatusPanels* Value);
	void __fastcall SetSimplePanel(bool Value);
	void __fastcall UpdateSimpleText(void);
	void __fastcall SetSimpleText(const AnsiString Value);
	void __fastcall SetSizeGrip(bool Value);
	void __fastcall SyncToSystemFont(void);
	void __fastcall UpdatePanel(int Index, bool Repaint);
	void __fastcall UpdatePanels(bool UpdateRects, bool UpdateText);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMWinIniChange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void __fastcall WMGetTextLength(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	void __fastcall SetUseSystemFont(const bool Value);
	
protected:
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall DoHint(void);
	DYNAMIC void __fastcall DrawPanel(TStatusPanel* Panel, const Windows::TRect &Rect);
	
public:
	__fastcall virtual TStatusBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TStatusBar(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	
__published:
	__property Action ;
	__property bool AutoHint = {read=FAutoHint, write=FAutoHint, default=0};
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property BorderWidth ;
	__property Color ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font  = {stored=IsFontStored};
	__property Constraints ;
	__property TStatusPanels* Panels = {read=FPanels, write=SetPanels};
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property bool SimplePanel = {read=FSimplePanel, write=SetSimplePanel, nodefault};
	__property AnsiString SimpleText = {read=FSimpleText, write=SetSimpleText};
	__property bool SizeGrip = {read=FSizeGrip, write=SetSizeGrip, default=1};
	__property bool UseSystemFont = {read=FUseSystemFont, write=SetUseSystemFont, default=1};
	__property Visible ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property Classes::TNotifyEvent OnHint = {read=FOnHint, write=FOnHint};
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TDrawPanelEvent OnDrawPanel = {read=FOnDrawPanel, write=FOnDrawPanel};
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStatusBar(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TStatusPanels : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	TStatusBar* FStatusBar;
	HIDESBASE TStatusPanel* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TStatusPanel* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall TStatusPanels(TStatusBar* StatusBar);
	HIDESBASE TStatusPanel* __fastcall Add(void);
	__property TStatusPanel* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TStatusPanels(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCustomDrawTarget { dtControl, dtItem, dtSubItem };
#pragma option pop

#pragma option push -b-
enum TCustomDrawStage { cdPrePaint, cdPostPaint, cdPreErase, cdPostErase };
#pragma option pop

#pragma option push -b-
enum ComCtrls__8 { cdsSelected, cdsGrayed, cdsDisabled, cdsChecked, cdsFocused, cdsDefault, cdsHot, 
	cdsMarked, cdsIndeterminate };
#pragma option pop

typedef Set<ComCtrls__8, cdsSelected, cdsIndeterminate>  TCustomDrawState;

#pragma option push -b-
enum THeaderSectionStyle { hsText, hsOwnerDraw };
#pragma option pop

class DELPHICLASS THeaderSection;
class PASCALIMPLEMENTATION THeaderSection : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FText;
	int FWidth;
	int FMinWidth;
	int FMaxWidth;
	Classes::TAlignment FAlignment;
	THeaderSectionStyle FStyle;
	bool FAllowClick;
	bool FAutoSize;
	Imglist::TImageIndex FImageIndex;
	Classes::TBiDiMode FBiDiMode;
	bool FParentBiDiMode;
	int __fastcall GetLeft(void);
	int __fastcall GetRight(void);
	bool __fastcall IsBiDiModeStored(void);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetAutoSize(bool Value);
	void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
	void __fastcall SetMaxWidth(int Value);
	void __fastcall SetMinWidth(int Value);
	void __fastcall SetParentBiDiMode(bool Value);
	void __fastcall SetStyle(THeaderSectionStyle Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetWidth(int Value);
	void __fastcall SetImageIndex(const Imglist::TImageIndex Value);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	
public:
	__fastcall virtual THeaderSection(Classes::TCollection* Collection);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall ParentBiDiModeChanged(void);
	bool __fastcall UseRightToLeftAlignment(void);
	bool __fastcall UseRightToLeftReading(void);
	__property int Left = {read=GetLeft, nodefault};
	__property int Right = {read=GetRight, nodefault};
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AllowClick = {read=FAllowClick, write=FAllowClick, default=1};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored
		, nodefault};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int MaxWidth = {read=FMaxWidth, write=SetMaxWidth, default=10000};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=0};
	__property bool ParentBiDiMode = {read=FParentBiDiMode, write=SetParentBiDiMode, default=1};
	__property THeaderSectionStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property AnsiString Text = {read=FText, write=SetText};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~THeaderSection(void) { }
	#pragma option pop
	
};


class DELPHICLASS THeaderSections;
class DELPHICLASS THeaderControl;
#pragma option push -b-
enum THeaderStyle { hsButtons, hsFlat };
#pragma option pop

typedef void __fastcall (__closure *TDrawSectionEvent)(THeaderControl* HeaderControl, THeaderSection* 
	Section, const Windows::TRect &Rect, bool Pressed);

typedef void __fastcall (__closure *TSectionNotifyEvent)(THeaderControl* HeaderControl, THeaderSection* 
	Section);

#pragma option push -b-
enum TSectionTrackState { tsTrackBegin, tsTrackMove, tsTrackEnd };
#pragma option pop

typedef void __fastcall (__closure *TSectionTrackEvent)(THeaderControl* HeaderControl, THeaderSection* 
	Section, int Width, TSectionTrackState State);

typedef void __fastcall (__closure *TSectionDragEvent)(System::TObject* Sender, THeaderSection* FromSection
	, THeaderSection* ToSection, bool &AllowDrag);

class PASCALIMPLEMENTATION THeaderControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	THeaderSections* FSections;
	Classes::TMemoryStream* FSectionStream;
	bool FUpdatingSectionOrder;
	bool FSectionDragged;
	Graphics::TCanvas* FCanvas;
	int FFromIndex;
	int FToIndex;
	bool FFullDrag;
	bool FHotTrack;
	bool FDragReorder;
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FImages;
	THeaderStyle FStyle;
	THeaderSection* FTrackSection;
	int FTrackWidth;
	Windows::TPoint FTrackPos;
	TDrawSectionEvent FOnDrawSection;
	TSectionNotifyEvent FOnSectionClick;
	TSectionNotifyEvent FOnSectionResize;
	TSectionTrackEvent FOnSectionTrack;
	TSectionDragEvent FOnSectionDrag;
	Classes::TNotifyEvent FOnSectionEndDrag;
	bool __fastcall DoSectionDrag(THeaderSection* FromSection, THeaderSection* ToSection);
	void __fastcall DoSectionEndDrag(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetDragReorder(const bool Value);
	void __fastcall SetFullDrag(bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetSections(THeaderSections* Value);
	void __fastcall SetStyle(THeaderStyle Value);
	void __fastcall UpdateItem(int Message, int Index);
	void __fastcall UpdateSection(int Index);
	void __fastcall UpdateSections(void);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DrawSection(THeaderSection* Section, const Windows::TRect &Rect, bool Pressed
		);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	DYNAMIC void __fastcall SectionClick(THeaderSection* Section);
	DYNAMIC void __fastcall SectionDrag(THeaderSection* FromSection, THeaderSection* ToSection, bool &AllowDrag
		);
	DYNAMIC void __fastcall SectionEndDrag(void);
	DYNAMIC void __fastcall SectionResize(THeaderSection* Section);
	DYNAMIC void __fastcall SectionTrack(THeaderSection* Section, int Width, TSectionTrackState State);
		
	virtual void __fastcall SetImages(Imglist::TCustomImageList* Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	
public:
	__fastcall virtual THeaderControl(Classes::TComponent* AOwner);
	__fastcall virtual ~THeaderControl(void);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	
__published:
	__property Align ;
	__property Anchors ;
	__property BiDiMode ;
	__property BorderWidth ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property bool DragReorder = {read=FDragReorder, write=SetDragReorder, nodefault};
	__property Enabled ;
	__property Font ;
	__property bool FullDrag = {read=FFullDrag, write=SetFullDrag, default=1};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property Constraints ;
	__property THeaderSections* Sections = {read=FSections, write=SetSections};
	__property ShowHint ;
	__property THeaderStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property ParentBiDiMode ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property Visible ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property TDrawSectionEvent OnDrawSection = {read=FOnDrawSection, write=FOnDrawSection};
	__property OnResize ;
	__property TSectionNotifyEvent OnSectionClick = {read=FOnSectionClick, write=FOnSectionClick};
	__property TSectionDragEvent OnSectionDrag = {read=FOnSectionDrag, write=FOnSectionDrag};
	__property Classes::TNotifyEvent OnSectionEndDrag = {read=FOnSectionEndDrag, write=FOnSectionEndDrag
		};
	__property TSectionNotifyEvent OnSectionResize = {read=FOnSectionResize, write=FOnSectionResize};
	__property TSectionTrackEvent OnSectionTrack = {read=FOnSectionTrack, write=FOnSectionTrack};
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THeaderControl(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION THeaderSections : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	THeaderControl* FHeaderControl;
	HIDESBASE THeaderSection* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, THeaderSection* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall THeaderSections(THeaderControl* HeaderControl);
	HIDESBASE THeaderSection* __fastcall Add(void);
	__property THeaderSection* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~THeaderSections(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TNodeState { nsCut, nsDropHilited, nsFocused, nsSelected, nsExpanded };
#pragma option pop

#pragma option push -b-
enum TNodeAttachMode { naAdd, naAddFirst, naAddChild, naAddChildFirst, naInsert };
#pragma option pop

#pragma option push -b-
enum TAddMode { taAddFirst, taAdd, taInsert };
#pragma option pop

struct TNodeInfo;
typedef TNodeInfo *PNodeInfo;

#pragma pack(push, 1)
struct TNodeInfo
{
	int ImageIndex;
	int SelectedIndex;
	int StateIndex;
	int OverlayIndex;
	void *Data;
	int Count;
	System::SmallString<255>  Text;
} ;
#pragma pack(pop)

class DELPHICLASS TTreeNode;
class DELPHICLASS TTreeNodes;
class DELPHICLASS TCustomTreeView;
#pragma option push -b-
enum TSortType { stNone, stData, stText, stBoth };
#pragma option pop

typedef void __fastcall (__closure *TTVAdvancedCustomDrawEvent)(TCustomTreeView* Sender, const Windows::TRect 
	&ARect, TCustomDrawStage Stage, bool &DefaultDraw);

typedef void __fastcall (__closure *TTVAdvancedCustomDrawItemEvent)(TCustomTreeView* Sender, TTreeNode* 
	Node, TCustomDrawState State, TCustomDrawStage Stage, bool &PaintImages, bool &DefaultDraw);

typedef void __fastcall (__closure *TTVChangedEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVChangingEvent)(System::TObject* Sender, TTreeNode* Node, bool 
	&AllowChange);

typedef void __fastcall (__closure *TTVExpandedEvent)(System::TObject* Sender, TTreeNode* Node);

typedef void __fastcall (__closure *TTVCollapsingEvent)(System::TObject* Sender, TTreeNode* Node, bool 
	&AllowCollapse);

typedef void __fastcall (__closure *TTVCompareEvent)(System::TObject* Sender, TTreeNode* Node1, TTreeNode* 
	Node2, int Data, int &Compare);

typedef void __fastcall (__closure *TTVCustomDrawEvent)(TCustomTreeView* Sender, const Windows::TRect 
	&ARect, bool &DefaultDraw);

typedef void __fastcall (__closure *TTVCustomDrawItemEvent)(TCustomTreeView* Sender, TTreeNode* Node
	, TCustomDrawState State, bool &DefaultDraw);

typedef void __fastcall (__closure *TTVEditingEvent)(System::TObject* Sender, TTreeNode* Node, bool 
	&AllowEdit);

typedef void __fastcall (__closure *TTVEditedEvent)(System::TObject* Sender, TTreeNode* Node, AnsiString 
	&S);

typedef void __fastcall (__closure *TTVExpandingEvent)(System::TObject* Sender, TTreeNode* Node, bool 
	&AllowExpansion);

class PASCALIMPLEMENTATION TCustomTreeView : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FAutoExpand;
	Forms::TFormBorderStyle FBorderStyle;
	Graphics::TCanvas* FCanvas;
	bool FCanvasChanged;
	void *FDefEditProc;
	bool FDragged;
	Controls::TDragImageList* FDragImage;
	TTreeNode* FDragNode;
	HWND FEditHandle;
	void *FEditInstance;
	bool FHideSelection;
	bool FHotTrack;
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FImages;
	TTreeNode* FLastDropTarget;
	Classes::TMemoryStream* FMemStream;
	TTreeNode* FRClickNode;
	bool FRightClickSelect;
	bool FManualNotify;
	bool FReadOnly;
	bool FRowSelect;
	int FSaveIndex;
	int FSaveIndent;
	Classes::TStringList* FSaveItems;
	int FSaveTopIndex;
	bool FShowButtons;
	bool FShowLines;
	bool FShowRoot;
	TSortType FSortType;
	bool FStateChanging;
	Imglist::TCustomImageList* FStateImages;
	Imglist::TChangeLink* FStateChangeLink;
	bool FToolTips;
	TTreeNodes* FTreeNodes;
	WideString FWideText;
	TTVAdvancedCustomDrawEvent FOnAdvancedCustomDraw;
	TTVAdvancedCustomDrawItemEvent FOnAdvancedCustomDrawItem;
	TTVChangedEvent FOnChange;
	TTVChangingEvent FOnChanging;
	TTVExpandedEvent FOnCollapsed;
	TTVCollapsingEvent FOnCollapsing;
	TTVCompareEvent FOnCompare;
	TTVCustomDrawEvent FOnCustomDraw;
	TTVCustomDrawItemEvent FOnCustomDrawItem;
	TTVExpandedEvent FOnDeletion;
	TTVEditingEvent FOnEditing;
	TTVEditedEvent FOnEdited;
	TTVExpandedEvent FOnExpanded;
	TTVExpandingEvent FOnExpanding;
	TTVExpandedEvent FOnGetImageIndex;
	TTVExpandedEvent FOnGetSelectedIndex;
	void __fastcall CanvasChanged(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDrag(Controls::TCMDrag &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	void __fastcall EditWndProc(Messages::TMessage &Message);
	void __fastcall DoDragOver(Controls::TDragObject* Source, int X, int Y, bool CanDrop);
	int __fastcall GetChangeDelay(void);
	TTreeNode* __fastcall GetDropTarget(void);
	int __fastcall GetIndent(void);
	TTreeNode* __fastcall GetNodeFromItem(const tagTVITEMA &Item);
	TTreeNode* __fastcall GetSelection(void);
	TTreeNode* __fastcall GetTopItem(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetAutoExpand(bool Value);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetButtonStyle(bool Value);
	void __fastcall SetChangeDelay(int Value);
	void __fastcall SetDropTarget(TTreeNode* Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetImageList(unsigned Value, int Flags);
	void __fastcall SetIndent(int Value);
	void __fastcall SetImages(Imglist::TCustomImageList* Value);
	void __fastcall SetLineStyle(bool Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetRootStyle(bool Value);
	void __fastcall SetRowSelect(bool Value);
	void __fastcall SetSelection(TTreeNode* Value);
	void __fastcall SetSortType(TSortType Value);
	void __fastcall SetStateImages(Imglist::TCustomImageList* Value);
	void __fastcall SetToolTips(bool Value);
	void __fastcall SetTreeNodes(TTreeNodes* Value);
	void __fastcall SetTopItem(TTreeNode* Value);
	void __fastcall OnChangeTimer(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNotify(Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Messages::TWMContextMenu &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	
protected:
	Extctrls::TTimer* FChangeTimer;
	DYNAMIC bool __fastcall CanEdit(TTreeNode* Node);
	DYNAMIC bool __fastcall CanChange(TTreeNode* Node);
	DYNAMIC bool __fastcall CanCollapse(TTreeNode* Node);
	DYNAMIC bool __fastcall CanExpand(TTreeNode* Node);
	DYNAMIC void __fastcall Change(TTreeNode* Node);
	DYNAMIC void __fastcall Collapse(TTreeNode* Node);
	virtual TTreeNode* __fastcall CreateNode(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall CustomDraw(const Windows::TRect &ARect, TCustomDrawStage Stage);
	virtual bool __fastcall CustomDrawItem(TTreeNode* Node, TCustomDrawState State, TCustomDrawStage Stage
		, bool &PaintImages);
	DYNAMIC void __fastcall Delete(TTreeNode* Node);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall Edit(const tagTVITEMA &Item);
	DYNAMIC void __fastcall Expand(TTreeNode* Node);
	virtual Controls::TDragImageList* __fastcall GetDragImages(void);
	virtual void __fastcall GetImageIndex(TTreeNode* Node);
	virtual void __fastcall GetSelectedIndex(TTreeNode* Node);
	bool __fastcall IsCustomDrawn(TCustomDrawTarget Target, TCustomDrawStage Stage);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall SetDragMode(Controls::TDragMode Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property bool AutoExpand = {read=FAutoExpand, write=SetAutoExpand, default=0};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int ChangeDelay = {read=GetChangeDelay, write=SetChangeDelay, default=0};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property int Indent = {read=GetIndent, write=SetIndent, nodefault};
	__property TTreeNodes* Items = {read=FTreeNodes, write=SetTreeNodes};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property bool RightClickSelect = {read=FRightClickSelect, write=FRightClickSelect, default=0};
	__property bool RowSelect = {read=FRowSelect, write=SetRowSelect, default=0};
	__property bool ShowButtons = {read=FShowButtons, write=SetButtonStyle, default=1};
	__property bool ShowLines = {read=FShowLines, write=SetLineStyle, default=1};
	__property bool ShowRoot = {read=FShowRoot, write=SetRootStyle, default=1};
	__property TSortType SortType = {read=FSortType, write=SetSortType, default=0};
	__property Imglist::TCustomImageList* StateImages = {read=FStateImages, write=SetStateImages};
	__property bool ToolTips = {read=FToolTips, write=SetToolTips, default=1};
	__property TTVAdvancedCustomDrawEvent OnAdvancedCustomDraw = {read=FOnAdvancedCustomDraw, write=FOnAdvancedCustomDraw
		};
	__property TTVAdvancedCustomDrawItemEvent OnAdvancedCustomDrawItem = {read=FOnAdvancedCustomDrawItem
		, write=FOnAdvancedCustomDrawItem};
	__property TTVChangedEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TTVChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TTVExpandedEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property TTVCollapsingEvent OnCollapsing = {read=FOnCollapsing, write=FOnCollapsing};
	__property TTVCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property TTVCustomDrawEvent OnCustomDraw = {read=FOnCustomDraw, write=FOnCustomDraw};
	__property TTVCustomDrawItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=FOnCustomDrawItem
		};
	__property TTVExpandedEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TTVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TTVEditedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TTVExpandingEvent OnExpanding = {read=FOnExpanding, write=FOnExpanding};
	__property TTVExpandedEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property TTVExpandedEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property TTVExpandedEvent OnGetSelectedIndex = {read=FOnGetSelectedIndex, write=FOnGetSelectedIndex
		};
	
public:
	__fastcall virtual TCustomTreeView(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomTreeView(void);
	bool __fastcall AlphaSort(void);
	bool __fastcall CustomSort(PFNTVCOMPARE SortProc, int Data);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	THitTests __fastcall GetHitTestInfoAt(int X, int Y);
	TTreeNode* __fastcall GetNodeAt(int X, int Y);
	bool __fastcall IsEditing(void);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property TTreeNode* DropTarget = {read=GetDropTarget, write=SetDropTarget};
	__property TTreeNode* Selected = {read=GetSelection, write=SetSelection};
	__property TTreeNode* TopItem = {read=GetTopItem, write=SetTopItem};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomTreeView(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


struct TNodeCache
{
	TTreeNode* CacheNode;
	int CacheIndex;
} ;

class PASCALIMPLEMENTATION TTreeNodes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomTreeView* FOwner;
	int FUpdateCount;
	TNodeCache FNodeCache;
	void __fastcall AddedNode(TTreeNode* Value);
	HWND __fastcall GetHandle(void);
	TTreeNode* __fastcall GetNodeFromIndex(int Index);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall Repaint(TTreeNode* Node);
	void __fastcall WriteData(Classes::TStream* Stream);
	void __fastcall ClearCache(void);
	void __fastcall WriteExpandedState(Classes::TStream* Stream);
	void __fastcall ReadExpandedState(Classes::TStream* Stream);
	
protected:
	HTREEITEM __fastcall AddItem(HTREEITEM Parent, HTREEITEM Target, const tagTVITEMA &Item, TAddMode AddMode
		);
	TTreeNode* __fastcall InternalAddObject(TTreeNode* Node, const AnsiString S, void * Ptr, TAddMode AddMode
		);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	tagTVITEMA __fastcall CreateItem(TTreeNode* Node);
	int __fastcall GetCount(void);
	void __fastcall SetItem(int Index, TTreeNode* Value);
	void __fastcall SetUpdateState(bool Updating);
	
public:
	__fastcall TTreeNodes(TCustomTreeView* AOwner);
	__fastcall virtual ~TTreeNodes(void);
	TTreeNode* __fastcall AddChildFirst(TTreeNode* Node, const AnsiString S);
	TTreeNode* __fastcall AddChild(TTreeNode* Node, const AnsiString S);
	TTreeNode* __fastcall AddChildObjectFirst(TTreeNode* Node, const AnsiString S, void * Ptr);
	TTreeNode* __fastcall AddChildObject(TTreeNode* Node, const AnsiString S, void * Ptr);
	TTreeNode* __fastcall AddFirst(TTreeNode* Node, const AnsiString S);
	TTreeNode* __fastcall Add(TTreeNode* Node, const AnsiString S);
	TTreeNode* __fastcall AddObjectFirst(TTreeNode* Node, const AnsiString S, void * Ptr);
	TTreeNode* __fastcall AddObject(TTreeNode* Node, const AnsiString S, void * Ptr);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall Delete(TTreeNode* Node);
	void __fastcall EndUpdate(void);
	TTreeNode* __fastcall GetFirstNode(void);
	TTreeNode* __fastcall GetNode(HTREEITEM ItemId);
	TTreeNode* __fastcall Insert(TTreeNode* Node, const AnsiString S);
	TTreeNode* __fastcall InsertObject(TTreeNode* Node, const AnsiString S, void * Ptr);
	__property int Count = {read=GetCount, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property TTreeNode* Item[int Index] = {read=GetNodeFromIndex/*, default*/};
	__property TCustomTreeView* Owner = {read=FOwner};
};


class PASCALIMPLEMENTATION TTreeNode : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TTreeNodes* FOwner;
	AnsiString FText;
	void *FData;
	_TREEITEM *FItemId;
	Imglist::TImageIndex FImageIndex;
	int FSelectedIndex;
	int FOverlayIndex;
	int FStateIndex;
	bool FDeleting;
	bool FInTree;
	bool __fastcall CompareCount(int CompareMe);
	bool __fastcall DoCanExpand(bool Expand);
	void __fastcall DoExpand(bool Expand);
	void __fastcall ExpandItem(bool Expand, bool Recurse);
	int __fastcall GetAbsoluteIndex(void);
	bool __fastcall GetExpanded(void);
	int __fastcall GetLevel(void);
	TTreeNode* __fastcall GetParent(void);
	bool __fastcall GetChildren(void);
	bool __fastcall GetCut(void);
	bool __fastcall GetDropTarget(void);
	bool __fastcall GetFocused(void);
	int __fastcall GetIndex(void);
	TTreeNode* __fastcall GetItem(int Index);
	bool __fastcall GetSelected(void);
	bool __fastcall GetState(TNodeState NodeState);
	int __fastcall GetCount(void);
	TCustomTreeView* __fastcall GetTreeView(void);
	void __fastcall InternalMove(TTreeNode* ParentNode, TTreeNode* Node, HTREEITEM HItem, TAddMode AddMode
		);
	bool __fastcall IsEqual(TTreeNode* Node);
	bool __fastcall IsNodeVisible(void);
	void __fastcall ReadData(Classes::TStream* Stream, PNodeInfo Info);
	void __fastcall SetChildren(bool Value);
	void __fastcall SetCut(bool Value);
	void __fastcall SetData(void * Value);
	void __fastcall SetDropTarget(bool Value);
	void __fastcall SetItem(int Index, TTreeNode* Value);
	void __fastcall SetExpanded(bool Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetOverlayIndex(int Value);
	void __fastcall SetSelectedIndex(int Value);
	void __fastcall SetSelected(bool Value);
	void __fastcall SetStateIndex(int Value);
	void __fastcall SetText(const AnsiString S);
	void __fastcall WriteData(Classes::TStream* Stream, PNodeInfo Info);
	
public:
	__fastcall TTreeNode(TTreeNodes* AOwner);
	__fastcall virtual ~TTreeNode(void);
	bool __fastcall AlphaSort(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Collapse(bool Recurse);
	bool __fastcall CustomSort(PFNTVCOMPARE SortProc, int Data);
	void __fastcall Delete(void);
	void __fastcall DeleteChildren(void);
	Windows::TRect __fastcall DisplayRect(bool TextOnly);
	bool __fastcall EditText(void);
	void __fastcall EndEdit(bool Cancel);
	void __fastcall Expand(bool Recurse);
	TTreeNode* __fastcall getFirstChild(void);
	HWND __fastcall GetHandle(void);
	TTreeNode* __fastcall GetLastChild(void);
	TTreeNode* __fastcall GetNext(void);
	TTreeNode* __fastcall GetNextChild(TTreeNode* Value);
	TTreeNode* __fastcall getNextSibling(void);
	TTreeNode* __fastcall GetNextVisible(void);
	TTreeNode* __fastcall GetPrev(void);
	TTreeNode* __fastcall GetPrevChild(TTreeNode* Value);
	TTreeNode* __fastcall getPrevSibling(void);
	TTreeNode* __fastcall GetPrevVisible(void);
	bool __fastcall HasAsParent(TTreeNode* Value);
	int __fastcall IndexOf(TTreeNode* Value);
	void __fastcall MakeVisible(void);
	virtual void __fastcall MoveTo(TTreeNode* Destination, TNodeAttachMode Mode);
	__property int AbsoluteIndex = {read=GetAbsoluteIndex, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property bool Cut = {read=GetCut, write=SetCut, nodefault};
	__property void * Data = {read=FData, write=SetData};
	__property bool Deleting = {read=FDeleting, nodefault};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property bool DropTarget = {read=GetDropTarget, write=SetDropTarget, nodefault};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property bool HasChildren = {read=GetChildren, write=SetChildren, nodefault};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsVisible = {read=IsNodeVisible, nodefault};
	__property TTreeNode* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property HTREEITEM ItemId = {read=FItemId};
	__property int Level = {read=GetLevel, nodefault};
	__property int OverlayIndex = {read=FOverlayIndex, write=SetOverlayIndex, nodefault};
	__property TTreeNodes* Owner = {read=FOwner};
	__property TTreeNode* Parent = {read=GetParent};
	__property int SelectedIndex = {read=FSelectedIndex, write=SetSelectedIndex, nodefault};
	__property int StateIndex = {read=FStateIndex, write=SetStateIndex, nodefault};
	__property AnsiString Text = {read=FText, write=SetText};
	__property TCustomTreeView* TreeView = {read=GetTreeView};
};


typedef TNodeCache *PNodeCache;

class DELPHICLASS ETreeViewError;
class PASCALIMPLEMENTATION ETreeViewError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ETreeViewError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ETreeViewError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ETreeViewError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ETreeViewError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ETreeViewError(const AnsiString Msg, int AHelpContext)
		 : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ETreeViewError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ETreeViewError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ETreeViewError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ETreeViewError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTreeView;
class PASCALIMPLEMENTATION TTreeView : public TCustomTreeView 
{
	typedef TCustomTreeView inherited;
	
__published:
	__property Align ;
	__property Anchors ;
	__property AutoExpand ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property BorderWidth ;
	__property ChangeDelay ;
	__property Color ;
	__property Ctl3D ;
	__property Constraints ;
	__property DragKind ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HideSelection ;
	__property HotTrack ;
	__property Images ;
	__property Indent ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ReadOnly ;
	__property RightClickSelect ;
	__property RowSelect ;
	__property ShowButtons ;
	__property ShowHint ;
	__property ShowLines ;
	__property ShowRoot ;
	__property SortType ;
	__property StateImages ;
	__property TabOrder ;
	__property TabStop ;
	__property ToolTips ;
	__property Visible ;
	__property OnAdvancedCustomDraw ;
	__property OnAdvancedCustomDrawItem ;
	__property OnChange ;
	__property OnChanging ;
	__property OnClick ;
	__property OnCollapsed ;
	__property OnCollapsing ;
	__property OnCompare ;
	__property OnContextPopup ;
	__property OnCustomDraw ;
	__property OnCustomDrawItem ;
	__property OnDblClick ;
	__property OnDeletion ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEdited ;
	__property OnEditing ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnExpanding ;
	__property OnExpanded ;
	__property OnGetImageIndex ;
	__property OnGetSelectedIndex ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property Items ;
public:
	#pragma option push -w-inl
	/* TCustomTreeView.Create */ inline __fastcall virtual TTreeView(Classes::TComponent* AOwner) : TCustomTreeView(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomTreeView.Destroy */ inline __fastcall virtual ~TTreeView(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTreeView(HWND ParentWindow) : TCustomTreeView(ParentWindow
		) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTrackBarOrientation { trHorizontal, trVertical };
#pragma option pop

#pragma option push -b-
enum TTickMark { tmBottomRight, tmTopLeft, tmBoth };
#pragma option pop

#pragma option push -b-
enum TTickStyle { tsNone, tsAuto, tsManual };
#pragma option pop

class DELPHICLASS TTrackBar;
class PASCALIMPLEMENTATION TTrackBar : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TTrackBarOrientation FOrientation;
	TTickMark FTickMarks;
	TTickStyle FTickStyle;
	int FLineSize;
	int FPageSize;
	int FThumbLength;
	bool FSliderVisible;
	int FMin;
	int FMax;
	int FFrequency;
	int FPosition;
	int FSelStart;
	int FSelEnd;
	Classes::TNotifyEvent FOnChange;
	int __fastcall GetThumbLength(void);
	void __fastcall SetOrientation(TTrackBarOrientation Value);
	void __fastcall SetParams(int APosition, int AMin, int AMax);
	void __fastcall SetPosition(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetFrequency(int Value);
	void __fastcall SetTickStyle(TTickStyle Value);
	void __fastcall SetTickMarks(TTickMark Value);
	void __fastcall SetLineSize(int Value);
	void __fastcall SetPageSize(int Value);
	void __fastcall SetThumbLength(int Value);
	void __fastcall SetSliderVisible(bool Value);
	void __fastcall SetSelStart(int Value);
	void __fastcall SetSelEnd(int Value);
	void __fastcall UpdateSelection(void);
	MESSAGE void __fastcall CNHScroll(Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNVScroll(Messages::TWMScroll &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	HIDESBASEDYNAMIC void __fastcall Changed(void);
	
public:
	__fastcall virtual TTrackBar(Classes::TComponent* AOwner);
	void __fastcall SetTick(int Value);
	
__published:
	__property Align ;
	__property Anchors ;
	__property BorderWidth ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Constraints ;
	__property int LineSize = {read=FLineSize, write=SetLineSize, default=1};
	__property int Max = {read=FMax, write=SetMax, default=10};
	__property int Min = {read=FMin, write=SetMin, default=0};
	__property TTrackBarOrientation Orientation = {read=FOrientation, write=SetOrientation, nodefault};
		
	__property ParentCtl3D ;
	__property ParentShowHint ;
	__property int PageSize = {read=FPageSize, write=SetPageSize, default=2};
	__property PopupMenu ;
	__property int Frequency = {read=FFrequency, write=SetFrequency, nodefault};
	__property int Position = {read=FPosition, write=SetPosition, nodefault};
	__property bool SliderVisible = {read=FSliderVisible, write=SetSliderVisible, default=1};
	__property int SelEnd = {read=FSelEnd, write=SetSelEnd, nodefault};
	__property int SelStart = {read=FSelStart, write=SetSelStart, nodefault};
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property int ThumbLength = {read=GetThumbLength, write=SetThumbLength, default=20};
	__property TTickMark TickMarks = {read=FTickMarks, write=SetTickMarks, nodefault};
	__property TTickStyle TickStyle = {read=FTickStyle, write=SetTickStyle, nodefault};
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
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTrackBar(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TTrackBar(void) { }
	#pragma option pop
	
};


typedef int TProgressRange;

#pragma option push -b-
enum TProgressBarOrientation { pbHorizontal, pbVertical };
#pragma option pop

class DELPHICLASS TProgressBar;
class PASCALIMPLEMENTATION TProgressBar : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool F32BitMode;
	int FMin;
	int FMax;
	int FPosition;
	int FStep;
	TProgressBarOrientation FOrientation;
	bool FSmooth;
	int __fastcall GetMin(void);
	int __fastcall GetMax(void);
	int __fastcall GetPosition(void);
	void __fastcall SetParams(int AMin, int AMax);
	void __fastcall SetMin(int Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetStep(int Value);
	void __fastcall SetOrientation(TProgressBarOrientation Value);
	void __fastcall SetSmooth(bool Value);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	
public:
	__fastcall virtual TProgressBar(Classes::TComponent* AOwner);
	void __fastcall StepIt(void);
	void __fastcall StepBy(int Delta);
	
__published:
	__property Align ;
	__property Anchors ;
	__property BorderWidth ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Hint ;
	__property Constraints ;
	__property int Min = {read=GetMin, write=SetMin, nodefault};
	__property int Max = {read=GetMax, write=SetMax, nodefault};
	__property TProgressBarOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0
		};
	__property ParentShowHint ;
	__property PopupMenu ;
	__property int Position = {read=GetPosition, write=SetPosition, default=0};
	__property bool Smooth = {read=FSmooth, write=SetSmooth, default=0};
	__property int Step = {read=FStep, write=SetStep, default=10};
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TProgressBar(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TProgressBar(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TAttributeType { atSelected, atDefaultText };
#pragma option pop

#pragma option push -b-
enum TConsistentAttribute { caBold, caColor, caFace, caItalic, caSize, caStrikeOut, caUnderline, caProtected 
	};
#pragma option pop

typedef Set<TConsistentAttribute, caBold, caProtected>  TConsistentAttributes;

class DELPHICLASS TTextAttributes;
class DELPHICLASS TCustomRichEdit;
class DELPHICLASS TParaAttributes;
#pragma option push -b-
enum TNumberingStyle { nsNone, nsBullet };
#pragma option pop

class PASCALIMPLEMENTATION TParaAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomRichEdit* RichEdit;
	void __fastcall GetAttributes(_paraformat &Paragraph);
	Classes::TAlignment __fastcall GetAlignment(void);
	int __fastcall GetFirstIndent(void);
	int __fastcall GetLeftIndent(void);
	int __fastcall GetRightIndent(void);
	TNumberingStyle __fastcall GetNumbering(void);
	int __fastcall GetTab(Byte Index);
	int __fastcall GetTabCount(void);
	void __fastcall InitPara(_paraformat &Paragraph);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetAttributes(_paraformat &Paragraph);
	void __fastcall SetFirstIndent(int Value);
	void __fastcall SetLeftIndent(int Value);
	void __fastcall SetRightIndent(int Value);
	void __fastcall SetNumbering(TNumberingStyle Value);
	void __fastcall SetTab(Byte Index, int Value);
	void __fastcall SetTabCount(int Value);
	
public:
	__fastcall TParaAttributes(TCustomRichEdit* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, nodefault};
	__property int FirstIndent = {read=GetFirstIndent, write=SetFirstIndent, nodefault};
	__property int LeftIndent = {read=GetLeftIndent, write=SetLeftIndent, nodefault};
	__property TNumberingStyle Numbering = {read=GetNumbering, write=SetNumbering, nodefault};
	__property int RightIndent = {read=GetRightIndent, write=SetRightIndent, nodefault};
	__property int Tab[Byte Index] = {read=GetTab, write=SetTab};
	__property int TabCount = {read=GetTabCount, write=SetTabCount, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TParaAttributes(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TConversionClass;

typedef void __fastcall (__closure *TRichEditResizeEvent)(System::TObject* Sender, const Windows::TRect 
	&Rect);

typedef void __fastcall (__closure *TRichEditProtectChange)(System::TObject* Sender, int StartPos, int 
	EndPos, bool &AllowChange);

typedef void __fastcall (__closure *TRichEditSaveClipboard)(System::TObject* Sender, int NumObjects, 
	int NumChars, bool &SaveClipboard);

#pragma option push -b-
enum TSearchType { stWholeWord, stMatchCase };
#pragma option pop

typedef Set<TSearchType, stWholeWord, stMatchCase>  TSearchTypes;

class PASCALIMPLEMENTATION TCustomRichEdit : public Stdctrls::TCustomMemo 
{
	typedef Stdctrls::TCustomMemo inherited;
	
private:
	bool FHideScrollBars;
	TTextAttributes* FSelAttributes;
	TTextAttributes* FDefAttributes;
	TParaAttributes* FParagraph;
	Classes::TAlignment FOldParaAlignment;
	int FScreenLogPixels;
	Classes::TStrings* FRichEditStrings;
	Classes::TMemoryStream* FMemStream;
	Classes::TNotifyEvent FOnSelChange;
	bool FHideSelection;
	bool FModified;
	TMetaClass*FDefaultConverter;
	TRichEditResizeEvent FOnResizeRequest;
	TRichEditProtectChange FOnProtectChange;
	TRichEditSaveClipboard FOnSaveClipboard;
	Windows::TRect FPageRect;
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	bool __fastcall GetPlainText(void);
	bool __fastcall ProtectChange(int StartPos, int EndPos);
	bool __fastcall SaveClipboard(int NumObj, int NumChars);
	void __fastcall SetHideScrollBars(bool Value);
	HIDESBASE void __fastcall SetHideSelection(bool Value);
	void __fastcall SetPlainText(bool Value);
	void __fastcall SetRichEditStrings(Classes::TStrings* Value);
	void __fastcall SetDefAttributes(TTextAttributes* Value);
	void __fastcall SetSelAttributes(TTextAttributes* Value);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFont(Messages::TWMSetFont &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonUp(Messages::TWMMouse &Message);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall RequestSize(const Windows::TRect &Rect);
	DYNAMIC void __fastcall SelectionChange(void);
	virtual void __fastcall DoSetMaxLength(int Value);
	virtual Windows::TPoint __fastcall GetCaretPos();
	virtual int __fastcall GetSelLength(void);
	virtual int __fastcall GetSelStart(void);
	virtual AnsiString __fastcall GetSelText();
	virtual void __fastcall SetSelLength(int Value);
	virtual void __fastcall SetSelStart(int Value);
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property bool HideScrollBars = {read=FHideScrollBars, write=SetHideScrollBars, default=1};
	__property Classes::TStrings* Lines = {read=FRichEditStrings, write=SetRichEditStrings};
	__property TRichEditSaveClipboard OnSaveClipboard = {read=FOnSaveClipboard, write=FOnSaveClipboard}
		;
	__property Classes::TNotifyEvent OnSelectionChange = {read=FOnSelChange, write=FOnSelChange};
	__property TRichEditProtectChange OnProtectChange = {read=FOnProtectChange, write=FOnProtectChange}
		;
	__property TRichEditResizeEvent OnResizeRequest = {read=FOnResizeRequest, write=FOnResizeRequest};
	__property bool PlainText = {read=GetPlainText, write=SetPlainText, default=0};
	
public:
	__fastcall virtual TCustomRichEdit(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomRichEdit(void);
	virtual void __fastcall Clear(void);
	int __fastcall FindText(const AnsiString SearchStr, int StartPos, int Length, TSearchTypes Options)
		;
	virtual int __fastcall GetSelTextBuf(char * Buffer, int BufSize);
	virtual void __fastcall Print(const AnsiString Caption);
	/*         class method */ static void __fastcall RegisterConversionFormat(TMetaClass* vmt, const AnsiString 
		AExtension, TMetaClass* AConversionClass);
	__property TMetaClass* DefaultConverter = {read=FDefaultConverter, write=FDefaultConverter};
	__property TTextAttributes* DefAttributes = {read=FDefAttributes, write=SetDefAttributes};
	__property TTextAttributes* SelAttributes = {read=FSelAttributes, write=SetSelAttributes};
	__property Windows::TRect PageRect = {read=FPageRect, write=FPageRect};
	__property TParaAttributes* Paragraph = {read=FParagraph};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomRichEdit(HWND ParentWindow) : Stdctrls::TCustomMemo(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TTextAttributes : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomRichEdit* RichEdit;
	TAttributeType FType;
	void __fastcall GetAttributes(Richedit::TCharFormatA &Format);
	Graphics::TFontCharset __fastcall GetCharset(void);
	Graphics::TColor __fastcall GetColor(void);
	TConsistentAttributes __fastcall GetConsistentAttributes(void);
	int __fastcall GetHeight(void);
	AnsiString __fastcall GetName();
	Graphics::TFontPitch __fastcall GetPitch(void);
	bool __fastcall GetProtected(void);
	int __fastcall GetSize(void);
	Graphics::TFontStyles __fastcall GetStyle(void);
	void __fastcall SetAttributes(Richedit::TCharFormatA &Format);
	void __fastcall SetCharset(Graphics::TFontCharset Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetName(AnsiString Value);
	void __fastcall SetPitch(Graphics::TFontPitch Value);
	void __fastcall SetProtected(bool Value);
	void __fastcall SetSize(int Value);
	void __fastcall SetStyle(Graphics::TFontStyles Value);
	
protected:
	void __fastcall InitFormat(Richedit::TCharFormatA &Format);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall TTextAttributes(TCustomRichEdit* AOwner, TAttributeType AttributeType);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Graphics::TFontCharset Charset = {read=GetCharset, write=SetCharset, nodefault};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property TConsistentAttributes ConsistentAttributes = {read=GetConsistentAttributes, nodefault};
	__property AnsiString Name = {read=GetName, write=SetName};
	__property Graphics::TFontPitch Pitch = {read=GetPitch, write=SetPitch, nodefault};
	__property bool Protected = {read=GetProtected, write=SetProtected, nodefault};
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	__property Graphics::TFontStyles Style = {read=GetStyle, write=SetStyle, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TTextAttributes(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConversion;
class PASCALIMPLEMENTATION TConversion : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual int __fastcall ConvertReadStream(Classes::TStream* Stream, char * Buffer, int BufSize);
	virtual int __fastcall ConvertWriteStream(Classes::TStream* Stream, char * Buffer, int BufSize);
public:
		
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TConversion(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TConversion(void) { }
	#pragma option pop
	
};


struct TConversionFormat;
typedef TConversionFormat *PConversionFormat;

struct TConversionFormat
{
	TMetaClass*ConversionClass;
	AnsiString Extension;
	TConversionFormat *Next;
} ;

struct TRichEditStreamInfo
{
	TConversion* Converter;
	Classes::TStream* Stream;
} ;

typedef TRichEditStreamInfo *PRichEditStreamInfo;

class DELPHICLASS TRichEdit;
class PASCALIMPLEMENTATION TRichEdit : public TCustomRichEdit 
{
	typedef TCustomRichEdit inherited;
	
__published:
	__property Align ;
	__property Alignment ;
	__property Anchors ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property BorderWidth ;
	__property Color ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property HideSelection ;
	__property HideScrollBars ;
	__property ImeMode ;
	__property ImeName ;
	__property Constraints ;
	__property Lines ;
	__property MaxLength ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PlainText ;
	__property PopupMenu ;
	__property ReadOnly ;
	__property ScrollBars ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property WantTabs ;
	__property WantReturns ;
	__property WordWrap ;
	__property OnChange ;
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
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnProtectChange ;
	__property OnResizeRequest ;
	__property OnSaveClipboard ;
	__property OnSelectionChange ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomRichEdit.Create */ inline __fastcall virtual TRichEdit(Classes::TComponent* AOwner) : TCustomRichEdit(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomRichEdit.Destroy */ inline __fastcall virtual ~TRichEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TRichEdit(HWND ParentWindow) : TCustomRichEdit(ParentWindow
		) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TUDAlignButton { udLeft, udRight };
#pragma option pop

#pragma option push -b-
enum TUDOrientation { udHorizontal, udVertical };
#pragma option pop

#pragma option push -b-
enum TUDBtnType { btNext, btPrev };
#pragma option pop

#pragma option push -b-
enum TUpDownDirection { updNone, updUp, updDown };
#pragma option pop

typedef void __fastcall (__closure *TUDClickEvent)(System::TObject* Sender, TUDBtnType Button);

typedef void __fastcall (__closure *TUDChangingEvent)(System::TObject* Sender, bool &AllowChange);

typedef void __fastcall (__closure *TUDChangingEventEx)(System::TObject* Sender, bool &AllowChange, 
	short NewValue, TUpDownDirection Direction);

class DELPHICLASS TCustomUpDown;
class PASCALIMPLEMENTATION TCustomUpDown : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FArrowKeys;
	Controls::TWinControl* FAssociate;
	short FMin;
	short FMax;
	int FIncrement;
	short FNewValue;
	short FNewValueDelta;
	short FPosition;
	bool FThousands;
	bool FWrap;
	TUDClickEvent FOnClick;
	TUDAlignButton FAlignButton;
	TUDOrientation FOrientation;
	TUDChangingEvent FOnChanging;
	TUDChangingEventEx FOnChangingEx;
	void __fastcall UndoAutoResizing(Controls::TWinControl* Value);
	void __fastcall SetAssociate(Controls::TWinControl* Value);
	short __fastcall GetPosition(void);
	void __fastcall SetMin(short Value);
	void __fastcall SetMax(short Value);
	void __fastcall SetIncrement(int Value);
	void __fastcall SetPosition(short Value);
	void __fastcall SetAlignButton(TUDAlignButton Value);
	void __fastcall SetOrientation(TUDOrientation Value);
	void __fastcall SetArrowKeys(bool Value);
	void __fastcall SetThousands(bool Value);
	void __fastcall SetWrap(bool Value);
	MESSAGE void __fastcall CMAllChildrenFlipped(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Message);
	
protected:
	bool __fastcall DoCanChange(short NewVal, short Delta);
	DYNAMIC bool __fastcall CanChange(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	HIDESBASEDYNAMIC void __fastcall Click(TUDBtnType Button);
	__property TUDAlignButton AlignButton = {read=FAlignButton, write=SetAlignButton, default=1};
	__property bool ArrowKeys = {read=FArrowKeys, write=SetArrowKeys, default=1};
	__property Controls::TWinControl* Associate = {read=FAssociate, write=SetAssociate};
	__property short Min = {read=FMin, write=SetMin, nodefault};
	__property short Max = {read=FMax, write=SetMax, default=100};
	__property int Increment = {read=FIncrement, write=SetIncrement, default=1};
	__property TUDOrientation Orientation = {read=FOrientation, write=SetOrientation, default=1};
	__property short Position = {read=GetPosition, write=SetPosition, nodefault};
	__property bool Thousands = {read=FThousands, write=SetThousands, default=1};
	__property bool Wrap = {read=FWrap, write=SetWrap, nodefault};
	__property TUDChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TUDChangingEventEx OnChangingEx = {read=FOnChangingEx, write=FOnChangingEx};
	__property TUDClickEvent OnClick = {read=FOnClick, write=FOnClick};
	
public:
	__fastcall virtual TCustomUpDown(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomUpDown(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomUpDown(void) { }
	#pragma option pop
	
};


class DELPHICLASS TUpDown;
class PASCALIMPLEMENTATION TUpDown : public TCustomUpDown 
{
	typedef TCustomUpDown inherited;
	
__published:
	__property AlignButton ;
	__property Anchors ;
	__property Associate ;
	__property ArrowKeys ;
	__property Enabled ;
	__property Hint ;
	__property Min ;
	__property Max ;
	__property Increment ;
	__property Constraints ;
	__property Orientation ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property Position ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Thousands ;
	__property Visible ;
	__property Wrap ;
	__property OnChanging ;
	__property OnChangingEx ;
	__property OnContextPopup ;
	__property OnClick ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
public:
	#pragma option push -w-inl
	/* TCustomUpDown.Create */ inline __fastcall virtual TUpDown(Classes::TComponent* AOwner) : TCustomUpDown(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TUpDown(HWND ParentWindow) : TCustomUpDown(ParentWindow
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TUpDown(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum THKModifier { hkShift, hkCtrl, hkAlt, hkExt };
#pragma option pop

typedef Set<THKModifier, hkShift, hkExt>  THKModifiers;

#pragma option push -b-
enum THKInvalidKey { hcNone, hcShift, hcCtrl, hcAlt, hcShiftCtrl, hcShiftAlt, hcCtrlAlt, hcShiftCtrlAlt 
	};
#pragma option pop

typedef Set<THKInvalidKey, hcNone, hcShiftCtrlAlt>  THKInvalidKeys;

class DELPHICLASS TCustomHotKey;
class PASCALIMPLEMENTATION TCustomHotKey : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FAutoSize;
	THKModifiers FModifiers;
	THKInvalidKeys FInvalidKeys;
	Word FHotKey;
	void __fastcall AdjustHeight(void);
	HIDESBASE void __fastcall SetAutoSize(bool Value);
	void __fastcall SetInvalidKeys(THKInvalidKeys Value);
	void __fastcall SetModifiers(THKModifiers Value);
	void __fastcall UpdateHeight(void);
	Classes::TShortCut __fastcall GetHotKey(void);
	void __fastcall SetHotKey(Classes::TShortCut Value);
	void __fastcall ShortCutToHotKey(Classes::TShortCut Value);
	Classes::TShortCut __fastcall HotKeyToShortCut(int Value);
	
protected:
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=1};
	__property THKInvalidKeys InvalidKeys = {read=FInvalidKeys, write=SetInvalidKeys, nodefault};
	__property THKModifiers Modifiers = {read=FModifiers, write=SetModifiers, nodefault};
	__property Classes::TShortCut HotKey = {read=GetHotKey, write=SetHotKey, nodefault};
	__property TabStop ;
	
public:
	__fastcall virtual TCustomHotKey(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomHotKey(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomHotKey(void) { }
	#pragma option pop
	
};


class DELPHICLASS THotKey;
class PASCALIMPLEMENTATION THotKey : public TCustomHotKey 
{
	typedef TCustomHotKey inherited;
	
__published:
	__property Anchors ;
	__property AutoSize ;
	__property BiDiMode ;
	__property Constraints ;
	__property Enabled ;
	__property Hint ;
	__property HotKey ;
	__property InvalidKeys ;
	__property Modifiers ;
	__property ParentBiDiMode ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnContextPopup ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
public:
	#pragma option push -w-inl
	/* TCustomHotKey.Create */ inline __fastcall virtual THotKey(Classes::TComponent* AOwner) : TCustomHotKey(
		AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THotKey(HWND ParentWindow) : TCustomHotKey(ParentWindow
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~THotKey(void) { }
	#pragma option pop
	
};


typedef int TWidth;

class DELPHICLASS TListColumn;
class PASCALIMPLEMENTATION TListColumn : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Classes::TAlignment FAlignment;
	bool FAutoSize;
	AnsiString FCaption;
	TWidth FMaxWidth;
	TWidth FMinWidth;
	Imglist::TImageIndex FImageIndex;
	TWidth FPrivateWidth;
	TWidth FWidth;
	int FOrderTag;
	int FTag;
	void __fastcall DoChange(void);
	TWidth __fastcall GetWidth(void);
	bool __fastcall IsWidthStored(void);
	void __fastcall ReadData(Classes::TReader* Reader);
	void __fastcall SetAlignment(Classes::TAlignment Value);
	void __fastcall SetAutoSize(bool Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetMaxWidth(TWidth Value);
	void __fastcall SetMinWidth(TWidth Value);
	void __fastcall SetWidth(TWidth Value);
	void __fastcall WriteData(Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual AnsiString __fastcall GetDisplayName();
	virtual void __fastcall SetIndex(int Value);
	
public:
	__fastcall virtual TListColumn(Classes::TCollection* Collection);
	__fastcall virtual ~TListColumn(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TWidth WidthType = {read=FWidth, nodefault};
	
__published:
	__property Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property TWidth MaxWidth = {read=FMaxWidth, write=SetMaxWidth, default=0};
	__property TWidth MinWidth = {read=FMinWidth, write=SetMinWidth, default=0};
	__property int Tag = {read=FTag, write=FTag, default=0};
	__property TWidth Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, default=50};
};


class DELPHICLASS TListColumns;
class DELPHICLASS TCustomListView;
#pragma option push -b-
enum TViewStyle { vsIcon, vsSmallIcon, vsList, vsReport };
#pragma option pop

class DELPHICLASS TListItems;
class DELPHICLASS TListItem;
class PASCALIMPLEMENTATION TListItems : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomListView* FOwner;
	int FUpdateCount;
	bool FNoRedraw;
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall WriteData(Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	tagLVITEMA __fastcall CreateItem(int Index, TListItem* ListItem);
	int __fastcall GetCount(void);
	HWND __fastcall GetHandle(void);
	TListItem* __fastcall GetItem(int Index);
	void __fastcall SetCount(int Value);
	void __fastcall SetItem(int Index, TListItem* Value);
	void __fastcall SetUpdateState(bool Updating);
	
public:
	__fastcall TListItems(TCustomListView* AOwner);
	__fastcall virtual ~TListItems(void);
	TListItem* __fastcall Add(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall EndUpdate(void);
	int __fastcall IndexOf(TListItem* Value);
	TListItem* __fastcall Insert(int Index);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property TListItem* Item[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TCustomListView* Owner = {read=FOwner};
};


class DELPHICLASS TIconOptions;
#pragma option push -b-
enum TIconArrangement { iaTop, iaLeft };
#pragma option pop

class PASCALIMPLEMENTATION TIconOptions : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCustomListView* FListView;
	TIconArrangement FArrangement;
	bool FAutoArrange;
	bool FWrapText;
	void __fastcall SetArrangement(TIconArrangement Value);
	void __fastcall SetAutoArrange(bool Value);
	void __fastcall SetWrapText(bool Value);
	
public:
	__fastcall TIconOptions(TCustomListView* AOwner);
	
__published:
	__property TIconArrangement Arrangement = {read=FArrangement, write=SetArrangement, default=0};
	__property bool AutoArrange = {read=FAutoArrange, write=SetAutoArrange, default=0};
	__property bool WrapText = {read=FWrapText, write=SetWrapText, default=1};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIconOptions(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TListHotTrackStyle { htHandPoint, htUnderlineCold, htUnderlineHot };
#pragma option pop

typedef Set<TListHotTrackStyle, htHandPoint, htUnderlineHot>  TListHotTrackStyles;

class DELPHICLASS TWorkAreas;
class DELPHICLASS TWorkArea;
class PASCALIMPLEMENTATION TWorkAreas : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
private:
	HIDESBASE TWorkArea* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TWorkArea* Value);
	
protected:
	HIDESBASE void __fastcall Changed(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	HIDESBASE TWorkArea* __fastcall Add(void);
	HIDESBASE void __fastcall Delete(int Index);
	HIDESBASE TWorkArea* __fastcall Insert(int Index);
	__property TWorkArea* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TOwnedCollection.Create */ inline __fastcall TWorkAreas(Classes::TPersistent* AOwner, TMetaClass* 
		ItemClass) : Classes::TOwnedCollection(AOwner, ItemClass) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TWorkAreas(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TLVAdvancedCustomDrawEvent)(TCustomListView* Sender, const Windows::TRect 
	&ARect, TCustomDrawStage Stage, bool &DefaultDraw);

typedef void __fastcall (__closure *TLVAdvancedCustomDrawItemEvent)(TCustomListView* Sender, TListItem* 
	Item, TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw);

typedef void __fastcall (__closure *TLVAdvancedCustomDrawSubItemEvent)(TCustomListView* Sender, TListItem* 
	Item, int SubItem, TCustomDrawState State, TCustomDrawStage Stage, bool &DefaultDraw);

#pragma option push -b-
enum TItemChange { ctText, ctImage, ctState };
#pragma option pop

typedef void __fastcall (__closure *TLVChangeEvent)(System::TObject* Sender, TListItem* Item, TItemChange 
	Change);

typedef void __fastcall (__closure *TLVChangingEvent)(System::TObject* Sender, TListItem* Item, TItemChange 
	Change, bool &AllowChange);

typedef void __fastcall (__closure *TLVColumnClickEvent)(System::TObject* Sender, TListColumn* Column
	);

typedef void __fastcall (__closure *TLVColumnRClickEvent)(System::TObject* Sender, TListColumn* Column
	, const Windows::TPoint &Point);

typedef void __fastcall (__closure *TLVCompareEvent)(System::TObject* Sender, TListItem* Item1, TListItem* 
	Item2, int Data, int &Compare);

typedef void __fastcall (__closure *TLVCustomDrawEvent)(TCustomListView* Sender, const Windows::TRect 
	&ARect, bool &DefaultDraw);

typedef void __fastcall (__closure *TLVCustomDrawItemEvent)(TCustomListView* Sender, TListItem* Item
	, TCustomDrawState State, bool &DefaultDraw);

typedef void __fastcall (__closure *TLVCustomDrawSubItemEvent)(TCustomListView* Sender, TListItem* Item
	, int SubItem, TCustomDrawState State, bool &DefaultDraw);

typedef void __fastcall (__closure *TLVOwnerDataEvent)(System::TObject* Sender, TListItem* Item);

#pragma option push -b-
enum TItemFind { ifData, ifPartialString, ifExactString, ifNearest };
#pragma option pop

#pragma option push -b-
enum TSearchDirection { sdLeft, sdRight, sdAbove, sdBelow, sdAll };
#pragma option pop

typedef void __fastcall (__closure *TLVOwnerDataFindEvent)(System::TObject* Sender, TItemFind Find, 
	const AnsiString FindString, const Windows::TPoint &FindPosition, void * FindData, int StartIndex, 
	TSearchDirection Direction, bool Wrap, int &Index);

typedef void __fastcall (__closure *TLVOwnerDataHintEvent)(System::TObject* Sender, int StartIndex, 
	int EndIndex);

#pragma option push -b-
enum TItemState { isNone, isCut, isDropHilited, isFocused, isSelected, isActivating };
#pragma option pop

typedef Set<TItemState, isNone, isActivating>  TItemStates;

typedef void __fastcall (__closure *TLVOwnerDataStateChangeEvent)(System::TObject* Sender, int StartIndex
	, int EndIndex, TItemStates OldState, TItemStates NewState);

typedef void __fastcall (__closure *TLVDeletedEvent)(System::TObject* Sender, TListItem* Item);

typedef void __fastcall (__closure *TLVDrawItemEvent)(TCustomListView* Sender, TListItem* Item, const 
	Windows::TRect &Rect, Windows::TOwnerDrawState State);

typedef void __fastcall (__closure *TLVEditedEvent)(System::TObject* Sender, TListItem* Item, AnsiString 
	&S);

typedef void __fastcall (__closure *TLVEditingEvent)(System::TObject* Sender, TListItem* Item, bool 
	&AllowEdit);

typedef void __fastcall (__closure *TLVNotifyEvent)(System::TObject* Sender, TListItem* Item);

typedef void __fastcall (__closure *TLVSubItemImageEvent)(System::TObject* Sender, TListItem* Item, 
	int SubItem, int &ImageIndex);

typedef void __fastcall (__closure *TLVInfoTipEvent)(System::TObject* Sender, TListItem* Item, AnsiString 
	&InfoTip);

typedef void __fastcall (__closure *TLVSelectItemEvent)(System::TObject* Sender, TListItem* Item, bool 
	Selected);

#pragma option push -b-
enum TItemRequests { irText, irImage, irParam, irState, irIndent };
#pragma option pop

typedef Set<TItemRequests, irText, irIndent>  TItemRequest;

#pragma option push -b-
enum TListArrangement { arAlignBottom, arAlignLeft, arAlignRight, arAlignTop, arDefault, arSnapToGrid 
	};
#pragma option pop

class PASCALIMPLEMENTATION TCustomListView : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	Forms::TFormBorderStyle FBorderStyle;
	TViewStyle FViewStyle;
	bool FReadOnly;
	Imglist::TCustomImageList* FLargeImages;
	Imglist::TCustomImageList* FSmallImages;
	Imglist::TCustomImageList* FStateImages;
	Controls::TDragImageList* FDragImage;
	bool FMultiSelect;
	TSortType FSortType;
	bool FColumnClick;
	bool FShowColumnHeaders;
	TListItems* FListItems;
	bool FClicked;
	bool FRClicked;
	TIconOptions* FIconOptions;
	bool FHideSelection;
	TListColumns* FListColumns;
	Classes::TMemoryStream* FMemStream;
	bool FOwnerData;
	bool FOwnerDraw;
	Classes::TMemoryStream* FColStream;
	Classes::TMemoryStream* FCheckStream;
	void *FEditInstance;
	void *FDefEditProc;
	HWND FEditHandle;
	void *FHeaderInstance;
	void *FDefHeaderProc;
	HWND FHeaderHandle;
	int FAllocBy;
	int FDragIndex;
	TListItem* FLastDropTarget;
	bool FCheckboxes;
	bool FFlatScrollBars;
	bool FFullDrag;
	bool FGridLines;
	bool FHotTrack;
	TListHotTrackStyles FHotTrackStyles;
	bool FRowSelect;
	Imglist::TChangeLink* FLargeChangeLink;
	Imglist::TChangeLink* FSmallChangeLink;
	Imglist::TChangeLink* FStateChangeLink;
	TSortType FSavedSort;
	bool FReading;
	bool FCanvasChanged;
	TListItem* FTempItem;
	TWorkAreas* FWorkAreas;
	bool FShowWorkAreas;
	bool FUpdatingColumnOrder;
	int FOwnerDataCount;
	TLVAdvancedCustomDrawEvent FOnAdvancedCustomDraw;
	TLVAdvancedCustomDrawItemEvent FOnAdvancedCustomDrawItem;
	TLVAdvancedCustomDrawSubItemEvent FOnAdvancedCustomDrawSubItem;
	TLVChangeEvent FOnChange;
	TLVChangingEvent FOnChanging;
	TLVColumnClickEvent FOnColumnClick;
	Classes::TNotifyEvent FOnColumnDragged;
	TLVColumnRClickEvent FOnColumnRightClick;
	TLVCompareEvent FOnCompare;
	TLVCustomDrawEvent FOnCustomDraw;
	TLVCustomDrawItemEvent FOnCustomDrawItem;
	TLVCustomDrawSubItemEvent FOnCustomDrawSubItem;
	TLVOwnerDataEvent FOnData;
	TLVOwnerDataFindEvent FOnDataFind;
	TLVOwnerDataHintEvent FOnDataHint;
	TLVOwnerDataStateChangeEvent FOnDataStateChange;
	TLVDeletedEvent FOnDeletion;
	TLVDrawItemEvent FOnDrawItem;
	TLVEditedEvent FOnEdited;
	TLVEditingEvent FOnEditing;
	TLVNotifyEvent FOnGetImageIndex;
	TLVSubItemImageEvent FOnGetSubItemImage;
	TLVInfoTipEvent FOnInfoTip;
	TLVDeletedEvent FOnInsert;
	TLVSelectItemEvent FOnSelectItem;
	bool __fastcall AreItemsStored(void);
	void __fastcall CanvasChanged(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDrag(Controls::TCMDrag &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	void __fastcall DoAutoSize(void);
	void __fastcall DoDragOver(Controls::TDragObject* Source, int X, int Y, bool CanDrop);
	void __fastcall DrawWorkAreas(void);
	void __fastcall EditWndProc(Messages::TMessage &Message);
	Windows::TRect __fastcall GetBoundingRect();
	TListColumn* __fastcall GetColumnFromIndex(int Index);
	TListColumn* __fastcall GetColumnFromTag(int Tag);
	TListItem* __fastcall GetDropTarget(void);
	TListItem* __fastcall GetFocused(void);
	void __fastcall GetImageIndex(TListItem* Item);
	void __fastcall GetSubItemImage(TListItem* Item, int SubItem, int &ImageIndex);
	TListItem* __fastcall GetItem(const tagLVITEMA &Value);
	int __fastcall GetSelCount(void);
	TListItem* __fastcall GetSelection(void);
	TListItem* __fastcall GetTopItem(void);
	Windows::TPoint __fastcall GetViewOrigin();
	int __fastcall GetVisibleRowCount(void);
	int __fastcall GetHoverTime(void);
	void __fastcall HeaderWndProc(Messages::TMessage &Message);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall RestoreChecks(void);
	void __fastcall SaveChecks(void);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetColumnClick(bool Value);
	void __fastcall SetColumnHeaders(bool Value);
	void __fastcall SetDropTarget(TListItem* Value);
	void __fastcall SetFocused(TListItem* Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetIconOptions(TIconOptions* Value);
	void __fastcall SetImageList(unsigned Value, int Flags);
	void __fastcall SetLargeImages(Imglist::TCustomImageList* Value);
	void __fastcall SetAllocBy(int Value);
	void __fastcall SetItems(TListItems* Value);
	void __fastcall SetListColumns(TListColumns* Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetOwnerData(bool Value);
	void __fastcall SetOwnerDraw(bool Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetShowWorkAreas(const bool Value);
	void __fastcall SetSmallImages(Imglist::TCustomImageList* Value);
	void __fastcall SetSortType(TSortType Value);
	void __fastcall SetSelection(TListItem* Value);
	void __fastcall SetStateImages(Imglist::TCustomImageList* Value);
	void __fastcall SetTextBkColor(Graphics::TColor Value);
	void __fastcall SetTextColor(Graphics::TColor Value);
	void __fastcall SetViewStyle(TViewStyle Value);
	void __fastcall SetCheckboxes(bool Value);
	void __fastcall SetFlatScrollBars(bool Value);
	void __fastcall SetFullDrag(bool Value);
	void __fastcall SetGridLines(bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetHotTrackStyles(TListHotTrackStyles Value);
	void __fastcall SetRowSelect(bool Value);
	void __fastcall SetHoverTime(int Value);
	void __fastcall ResetExStyles(void);
	bool __fastcall ValidHeaderHandle(void);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNotify(Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMParentNotify(Messages::TWMParentNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall CNDrawItem(Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Messages::TWMContextMenu &Message);
	
protected:
	DYNAMIC bool __fastcall CanChange(TListItem* Item, int Change);
	DYNAMIC bool __fastcall CanEdit(TListItem* Item);
	DYNAMIC void __fastcall Change(TListItem* Item, int Change);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	DYNAMIC void __fastcall ColClick(TListColumn* Column);
	DYNAMIC void __fastcall ColRightClick(TListColumn* Column, const Windows::TPoint &Point);
	bool __fastcall ColumnsShowing(void);
	virtual TListItem* __fastcall CreateListItem(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall CustomDraw(const Windows::TRect &ARect, TCustomDrawStage Stage);
	virtual bool __fastcall CustomDrawItem(TListItem* Item, TCustomDrawState State, TCustomDrawStage Stage
		);
	virtual bool __fastcall CustomDrawSubItem(TListItem* Item, int SubItem, TCustomDrawState State, TCustomDrawStage 
		Stage);
	DYNAMIC void __fastcall Delete(TListItem* Item);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Controls::TDragObject* &DragObject);
	virtual void __fastcall DoInfoTip(TListItem* Item, AnsiString &InfoTip);
	virtual void __fastcall DrawItem(TListItem* Item, const Windows::TRect &Rect, Windows::TOwnerDrawState 
		State);
	DYNAMIC void __fastcall Edit(const tagLVITEMA &Item);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	virtual bool __fastcall OwnerDataFetch(TListItem* Item, TItemRequest Request);
	virtual int __fastcall OwnerDataFind(TItemFind Find, const AnsiString FindString, const Windows::TPoint 
		&FindPosition, void * FindData, int StartIndex, TSearchDirection Direction, bool Wrap);
	virtual bool __fastcall OwnerDataHint(int StartIndex, int EndIndex);
	virtual bool __fastcall OwnerDataStateChange(int StartIndex, int EndIndex, TItemStates OldState, TItemStates 
		NewState);
	virtual Controls::TDragImageList* __fastcall GetDragImages(void);
	int __fastcall GetItemIndex(TListItem* Value);
	DYNAMIC void __fastcall InsertItem(TListItem* Item);
	bool __fastcall IsCustomDrawn(TCustomDrawTarget Target, TCustomDrawStage Stage);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall UpdateColumn(int AnIndex);
	void __fastcall UpdateColumns(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property TListColumns* Columns = {read=FListColumns, write=SetListColumns};
	__property bool ColumnClick = {read=FColumnClick, write=SetColumnClick, default=1};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, nodefault};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property TIconOptions* IconOptions = {read=FIconOptions, write=SetIconOptions};
	__property TListItems* Items = {read=FListItems, write=SetItems, stored=AreItemsStored};
	__property int AllocBy = {read=FAllocBy, write=SetAllocBy, default=0};
	__property int HoverTime = {read=GetHoverTime, write=SetHoverTime, default=-1};
	__property Imglist::TCustomImageList* LargeImages = {read=FLargeImages, write=SetLargeImages};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	__property bool OwnerData = {read=FOwnerData, write=SetOwnerData, default=0};
	__property bool OwnerDraw = {read=FOwnerDraw, write=SetOwnerDraw, default=0};
	__property TLVAdvancedCustomDrawEvent OnAdvancedCustomDraw = {read=FOnAdvancedCustomDraw, write=FOnAdvancedCustomDraw
		};
	__property TLVAdvancedCustomDrawItemEvent OnAdvancedCustomDrawItem = {read=FOnAdvancedCustomDrawItem
		, write=FOnAdvancedCustomDrawItem};
	__property TLVAdvancedCustomDrawSubItemEvent OnAdvancedCustomDrawSubItem = {read=FOnAdvancedCustomDrawSubItem
		, write=FOnAdvancedCustomDrawSubItem};
	__property TLVChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TLVChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property TLVColumnClickEvent OnColumnClick = {read=FOnColumnClick, write=FOnColumnClick};
	__property Classes::TNotifyEvent OnColumnDragged = {read=FOnColumnDragged, write=FOnColumnDragged};
		
	__property TLVColumnRClickEvent OnColumnRightClick = {read=FOnColumnRightClick, write=FOnColumnRightClick
		};
	__property TLVCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property TLVCustomDrawEvent OnCustomDraw = {read=FOnCustomDraw, write=FOnCustomDraw};
	__property TLVCustomDrawItemEvent OnCustomDrawItem = {read=FOnCustomDrawItem, write=FOnCustomDrawItem
		};
	__property TLVCustomDrawSubItemEvent OnCustomDrawSubItem = {read=FOnCustomDrawSubItem, write=FOnCustomDrawSubItem
		};
	__property TLVOwnerDataEvent OnData = {read=FOnData, write=FOnData};
	__property TLVOwnerDataFindEvent OnDataFind = {read=FOnDataFind, write=FOnDataFind};
	__property TLVOwnerDataHintEvent OnDataHint = {read=FOnDataHint, write=FOnDataHint};
	__property TLVOwnerDataStateChangeEvent OnDataStateChange = {read=FOnDataStateChange, write=FOnDataStateChange
		};
	__property TLVDeletedEvent OnDeletion = {read=FOnDeletion, write=FOnDeletion};
	__property TLVDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property TLVEditedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property TLVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property TLVInfoTipEvent OnInfoTip = {read=FOnInfoTip, write=FOnInfoTip};
	__property TLVDeletedEvent OnInsert = {read=FOnInsert, write=FOnInsert};
	__property TLVNotifyEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property TLVSubItemImageEvent OnGetSubItemImage = {read=FOnGetSubItemImage, write=FOnGetSubItemImage
		};
	__property TLVSelectItemEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
	__property bool ShowColumnHeaders = {read=FShowColumnHeaders, write=SetColumnHeaders, default=1};
	__property bool ShowWorkAreas = {read=FShowWorkAreas, write=SetShowWorkAreas, default=0};
	__property Imglist::TCustomImageList* SmallImages = {read=FSmallImages, write=SetSmallImages};
	__property TSortType SortType = {read=FSortType, write=SetSortType, default=0};
	__property Imglist::TCustomImageList* StateImages = {read=FStateImages, write=SetStateImages};
	__property TViewStyle ViewStyle = {read=FViewStyle, write=SetViewStyle, default=0};
	
public:
	__fastcall virtual TCustomListView(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomListView(void);
	bool __fastcall AlphaSort(void);
	void __fastcall Arrange(TListArrangement Code);
	TListItem* __fastcall FindCaption(int StartIndex, AnsiString Value, bool Partial, bool Inclusive, bool 
		Wrap);
	TListItem* __fastcall FindData(int StartIndex, void * Value, bool Inclusive, bool Wrap);
	THitTests __fastcall GetHitTestInfoAt(int X, int Y);
	TListItem* __fastcall GetItemAt(int X, int Y);
	TListItem* __fastcall GetNearestItem(const Windows::TPoint &Point, TSearchDirection Direction);
	TListItem* __fastcall GetNextItem(TListItem* StartItem, TSearchDirection Direction, TItemStates States
		);
	AnsiString __fastcall GetSearchString();
	bool __fastcall IsEditing(void);
	void __fastcall Scroll(int DX, int DY);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property bool Checkboxes = {read=FCheckboxes, write=SetCheckboxes, default=0};
	__property TListColumn* Column[int Index] = {read=GetColumnFromIndex};
	__property TListItem* DropTarget = {read=GetDropTarget, write=SetDropTarget};
	__property bool FlatScrollBars = {read=FFlatScrollBars, write=SetFlatScrollBars, default=0};
	__property bool FullDrag = {read=FFullDrag, write=SetFullDrag, default=0};
	__property bool GridLines = {read=FGridLines, write=SetGridLines, default=0};
	__property bool HotTrack = {read=FHotTrack, write=SetHotTrack, default=0};
	__property TListHotTrackStyles HotTrackStyles = {read=FHotTrackStyles, write=SetHotTrackStyles, default=0
		};
	__property TListItem* ItemFocused = {read=GetFocused, write=SetFocused};
	__property bool RowSelect = {read=FRowSelect, write=SetRowSelect, default=0};
	__property int SelCount = {read=GetSelCount, nodefault};
	__property TListItem* Selected = {read=GetSelection, write=SetSelection};
	bool __fastcall CustomSort(PFNLVCOMPARE SortProc, int lParam);
	int __fastcall StringWidth(AnsiString S);
	void __fastcall UpdateItems(int FirstIndex, int LastIndex);
	__property TListItem* TopItem = {read=GetTopItem};
	__property Windows::TPoint ViewOrigin = {read=GetViewOrigin};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property Windows::TRect BoundingRect = {read=GetBoundingRect};
	__property TWorkAreas* WorkAreas = {read=FWorkAreas};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomListView(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TListColumns : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	TCustomListView* FOwner;
	HIDESBASE TListColumn* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TListColumn* Value);
	void __fastcall UpdateCols(void);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	__fastcall TListColumns(TCustomListView* AOwner);
	HIDESBASE TListColumn* __fastcall Add(void);
	__property TCustomListView* Owner = {read=FOwner};
	__property TListColumn* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TListColumns(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDisplayCode { drBounds, drIcon, drLabel, drSelectBounds };
#pragma option pop

class PASCALIMPLEMENTATION TListItem : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TListItems* FOwner;
	Classes::TStrings* FSubItems;
	void *FData;
	Imglist::TImageIndex FImageIndex;
	int FIndent;
	int FIndex;
	Imglist::TImageIndex FOverlayIndex;
	Imglist::TImageIndex FStateIndex;
	AnsiString FCaption;
	bool FDeleting;
	bool FProcessedDeleting;
	bool FChecked;
	bool __fastcall GetChecked(void);
	HWND __fastcall GetHandle(void);
	int __fastcall GetIndex(void);
	TCustomListView* __fastcall GetListView(void);
	int __fastcall GetLeft(void);
	bool __fastcall GetState(int Index);
	int __fastcall GetTop(void);
	bool __fastcall IsEqual(TListItem* Item);
	void __fastcall SetChecked(bool Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetData(void * Value);
	void __fastcall SetImage(int Index, Imglist::TImageIndex Value);
	void __fastcall SetIndent(int Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetState(int Index, bool State);
	void __fastcall SetSubItems(Classes::TStrings* Value);
	void __fastcall SetTop(int Value);
	int __fastcall GetSubItemImage(int Index);
	void __fastcall SetSubItemImage(int Index, const int Value);
	
public:
	__fastcall TListItem(TListItems* AOwner);
	__fastcall virtual ~TListItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall CancelEdit(void);
	void __fastcall Delete(void);
	Windows::TRect __fastcall DisplayRect(TDisplayCode Code);
	bool __fastcall EditCaption(void);
	Windows::TPoint __fastcall GetPosition();
	void __fastcall MakeVisible(bool PartialOK);
	void __fastcall Update(void);
	void __fastcall SetPosition(const Windows::TPoint &Value);
	int __fastcall WorkArea(void);
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property bool Checked = {read=GetChecked, write=SetChecked, nodefault};
	__property bool Cut = {read=GetState, write=SetState, index=0, nodefault};
	__property void * Data = {read=FData, write=SetData};
	__property bool DropTarget = {read=GetState, write=SetState, index=1, nodefault};
	__property bool Focused = {read=GetState, write=SetState, index=2, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImage, index=0, nodefault}
		;
	__property int Indent = {read=FIndent, write=SetIndent, default=0};
	__property int Index = {read=GetIndex, nodefault};
	__property int Left = {read=GetLeft, write=SetLeft, nodefault};
	__property TCustomListView* ListView = {read=GetListView};
	__property TListItems* Owner = {read=FOwner};
	__property Imglist::TImageIndex OverlayIndex = {read=FOverlayIndex, write=SetImage, index=1, nodefault
		};
	__property Windows::TPoint Position = {read=GetPosition, write=SetPosition};
	__property bool Selected = {read=GetState, write=SetState, index=3, nodefault};
	__property Imglist::TImageIndex StateIndex = {read=FStateIndex, write=SetImage, index=2, nodefault}
		;
	__property Classes::TStrings* SubItems = {read=FSubItems, write=SetSubItems};
	__property int SubItemImages[int Index] = {read=GetSubItemImage, write=SetSubItemImage};
	__property int Top = {read=GetTop, write=SetTop, nodefault};
};


class PASCALIMPLEMENTATION TWorkArea : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Windows::TRect FRect;
	AnsiString FDisplayName;
	Graphics::TColor FColor;
	void __fastcall SetRect(const Windows::TRect &Value);
	void __fastcall SetColor(const Graphics::TColor Value);
	
public:
	__fastcall virtual TWorkArea(Classes::TCollection* Collection);
	virtual void __fastcall SetDisplayName(const AnsiString Value);
	virtual AnsiString __fastcall GetDisplayName();
	__property Windows::TRect Rect = {read=FRect, write=SetRect};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TWorkArea(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListView;
class PASCALIMPLEMENTATION TListView : public TCustomListView 
{
	typedef TCustomListView inherited;
	
__published:
	__property Align ;
	__property AllocBy ;
	__property Anchors ;
	__property BiDiMode ;
	__property BorderStyle ;
	__property BorderWidth ;
	__property Checkboxes ;
	__property Color ;
	__property Columns ;
	__property ColumnClick ;
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property FlatScrollBars ;
	__property FullDrag ;
	__property GridLines ;
	__property HideSelection ;
	__property HotTrack ;
	__property HotTrackStyles ;
	__property HoverTime ;
	__property IconOptions ;
	__property Items ;
	__property LargeImages ;
	__property MultiSelect ;
	__property OwnerData ;
	__property OwnerDraw ;
	__property ReadOnly ;
	__property RowSelect ;
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowColumnHeaders ;
	__property ShowWorkAreas ;
	__property ShowHint ;
	__property SmallImages ;
	__property SortType ;
	__property StateImages ;
	__property TabOrder ;
	__property TabStop ;
	__property ViewStyle ;
	__property Visible ;
	__property OnAdvancedCustomDraw ;
	__property OnAdvancedCustomDrawItem ;
	__property OnAdvancedCustomDrawSubItem ;
	__property OnChange ;
	__property OnChanging ;
	__property OnClick ;
	__property OnColumnClick ;
	__property OnColumnDragged ;
	__property OnColumnRightClick ;
	__property OnCompare ;
	__property OnContextPopup ;
	__property OnCustomDraw ;
	__property OnCustomDrawItem ;
	__property OnCustomDrawSubItem ;
	__property OnData ;
	__property OnDataFind ;
	__property OnDataHint ;
	__property OnDataStateChange ;
	__property OnDblClick ;
	__property OnDeletion ;
	__property OnDrawItem ;
	__property OnEdited ;
	__property OnEditing ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetImageIndex ;
	__property OnGetSubItemImage ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnInfoTip ;
	__property OnInsert ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnSelectItem ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomListView.Create */ inline __fastcall virtual TListView(Classes::TComponent* AOwner) : TCustomListView(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomListView.Destroy */ inline __fastcall virtual ~TListView(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TListView(HWND ParentWindow) : TCustomListView(ParentWindow
		) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCommonAVI { aviNone, aviFindFolder, aviFindFile, aviFindComputer, aviCopyFiles, aviCopyFile, aviRecycleFile, 
	aviEmptyRecycle, aviDeleteFile };
#pragma option pop

class DELPHICLASS TAnimate;
class PASCALIMPLEMENTATION TAnimate : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FActive;
	AnsiString FFileName;
	bool FCenter;
	TCommonAVI FCommonAVI;
	int FFrameCount;
	int FFrameHeight;
	int FFrameWidth;
	bool FOpen;
	bool FRecreateNeeded;
	int FRepetitions;
	unsigned FResHandle;
	int FResId;
	AnsiString FResName;
	bool FStreamedActive;
	bool FTimers;
	bool FTransparent;
	short FStartFrame;
	short FStopFrame;
	int FStopCount;
	Classes::TNotifyEvent FOnOpen;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnStart;
	Classes::TNotifyEvent FOnStop;
	void __fastcall CheckOpen(void);
	bool __fastcall InternalClose(void);
	bool __fastcall InternalOpen(void);
	void __fastcall GetAnimateParams(void *Params);
	unsigned __fastcall GetActualResHandle(void);
	int __fastcall GetActualResId(void);
	void __fastcall GetFrameInfo(void);
	void __fastcall SetAnimateParams(const void *Params);
	void __fastcall SetActive(bool Value);
	void __fastcall SetFileName(AnsiString Value);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetCommonAVI(TCommonAVI Value);
	void __fastcall SetOpen(bool Value);
	void __fastcall SetRepetitions(int Value);
	void __fastcall SetResHandle(unsigned Value);
	void __fastcall SetResId(int Value);
	void __fastcall SetResName(AnsiString Value);
	void __fastcall SetTimers(bool Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetStartFrame(short Value);
	void __fastcall SetStopFrame(short Value);
	void __fastcall UpdateActiveState(void);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNCommand(Messages::TWMCommand &Message);
	
protected:
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall DoOpen(void);
	virtual void __fastcall DoClose(void);
	virtual void __fastcall DoStart(void);
	virtual void __fastcall DoStop(void);
	virtual void __fastcall Loaded(void);
	
public:
	__fastcall virtual TAnimate(Classes::TComponent* AOwner);
	__property int FrameCount = {read=FFrameCount, nodefault};
	__property int FrameHeight = {read=FFrameHeight, nodefault};
	__property int FrameWidth = {read=FFrameWidth, nodefault};
	__property bool Open = {read=FOpen, write=SetOpen, nodefault};
	void __fastcall Play(Word FromFrame, Word ToFrame, int Count);
	void __fastcall Reset(void);
	void __fastcall Seek(short Frame);
	void __fastcall Stop(void);
	__property unsigned ResHandle = {read=FResHandle, write=SetResHandle, nodefault};
	__property int ResId = {read=FResId, write=SetResId, nodefault};
	__property AnsiString ResName = {read=FResName, write=SetResName};
	
__published:
	__property Align ;
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property Anchors ;
	__property AutoSize ;
	__property BorderWidth ;
	__property bool Center = {read=FCenter, write=SetCenter, default=1};
	__property Color ;
	__property TCommonAVI CommonAVI = {read=FCommonAVI, write=SetCommonAVI, default=0};
	__property Constraints ;
	__property AnsiString FileName = {read=FFileName, write=SetFileName};
	__property ParentColor ;
	__property ParentShowHint ;
	__property int Repetitions = {read=FRepetitions, write=SetRepetitions, default=0};
	__property ShowHint ;
	__property short StartFrame = {read=FStartFrame, write=SetStartFrame, default=1};
	__property short StopFrame = {read=FStopFrame, write=SetStopFrame, default=0};
	__property bool Timers = {read=FTimers, write=SetTimers, default=0};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=1};
	__property Visible ;
	__property Classes::TNotifyEvent OnOpen = {read=FOnOpen, write=FOnOpen};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnStart = {read=FOnStart, write=FOnStart};
	__property Classes::TNotifyEvent OnStop = {read=FOnStop, write=FOnStop};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAnimate(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TAnimate(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TToolButtonStyle { tbsButton, tbsCheck, tbsDropDown, tbsSeparator, tbsDivider };
#pragma option pop

#pragma option push -b-
enum TToolButtonState { tbsChecked, tbsPressed, tbsEnabled, tbsHidden, tbsIndeterminate, tbsWrap, tbsEllipses, 
	tbsMarked };
#pragma option pop

class DELPHICLASS TToolButtonActionLink;
class DELPHICLASS TToolButton;
class DELPHICLASS TToolBar;
typedef void __fastcall (__closure *TTBAdvancedCustomDrawEvent)(TToolBar* Sender, const Windows::TRect 
	&ARect, TCustomDrawStage Stage, bool &DefaultDraw);

#pragma option push -b-
enum ComCtrls__04 { tbNoEdges, tbHiliteHotTrack, tbNoOffset, tbNoMark, tbNoEtchedEffect };
#pragma option pop

typedef Set<ComCtrls__04, tbNoEdges, tbNoEtchedEffect>  TTBCustomDrawFlags;

typedef void __fastcall (__closure *TTBAdvancedCustomDrawBtnEvent)(TToolBar* Sender, TToolButton* Button
	, TCustomDrawState State, TCustomDrawStage Stage, TTBCustomDrawFlags &Flags, bool &DefaultDraw);

typedef void __fastcall (__closure *TTBCustomDrawEvent)(TToolBar* Sender, const Windows::TRect &ARect
	, bool &DefaultDraw);

typedef void __fastcall (__closure *TTBCustomDrawBtnEvent)(TToolBar* Sender, TToolButton* Button, TCustomDrawState 
	State, bool &DefaultDraw);

class PASCALIMPLEMENTATION TToolBar : public Toolwin::TToolWindow 
{
	typedef Toolwin::TToolWindow inherited;
	
private:
	int FButtonWidth;
	int FButtonHeight;
	Classes::TList* FButtons;
	AnsiString FCaption;
	Graphics::TCanvas* FCanvas;
	bool FCanvasChanged;
	bool FShowCaptions;
	bool FList;
	bool FFlat;
	bool FTransparent;
	bool FWrapable;
	Imglist::TCustomImageList* FImages;
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FDisabledImages;
	Imglist::TChangeLink* FDisabledImageChangeLink;
	Imglist::TCustomImageList* FHotImages;
	Imglist::TChangeLink* FHotImageChangeLink;
	int FIndent;
	bool FNewStyle;
	Graphics::TBitmap* FNullBitmap;
	HBITMAP FOldHandle;
	int FUpdateCount;
	int FHeightMargin;
	TTBAdvancedCustomDrawEvent FOnAdvancedCustomDraw;
	TTBAdvancedCustomDrawBtnEvent FOnAdvancedCustomDrawButton;
	TTBCustomDrawEvent FOnCustomDraw;
	TTBCustomDrawBtnEvent FOnCustomDrawButton;
	bool FCaptureChangeCancels;
	bool FInMenuLoop;
	Menus::TPopupMenu* FTempMenu;
	Menus::TMenuItem* FButtonMenu;
	TToolButton* FMenuButton;
	bool FMenuResult;
	bool FMenuDropped;
	int __fastcall ButtonIndex(int OldIndex, int ALeft, int ATop);
	void __fastcall CanvasChanged(System::TObject* Sender);
	void __fastcall LoadImages(Imglist::TCustomImageList* AImages);
	TToolButton* __fastcall GetButton(int Index);
	int __fastcall GetButtonCount(void);
	void __fastcall GetButtonSize(int &AWidth, int &AHeight);
	int __fastcall GetRowCount(void);
	void __fastcall SetList(bool Value);
	void __fastcall SetShowCaptions(bool Value);
	void __fastcall SetFlat(bool Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall SetWrapable(bool Value);
	void __fastcall InsertButton(Controls::TControl* Control);
	void __fastcall RemoveButton(Controls::TControl* Control);
	bool __fastcall RefreshButton(int Index);
	void __fastcall UpdateButton(int Index);
	void __fastcall UpdateButtons(void);
	void __fastcall UpdateButtonState(int Index);
	void __fastcall UpdateButtonStates(void);
	bool __fastcall UpdateItem(int Message, int FromIndex, int ToIndex);
	bool __fastcall UpdateItem2(int Message, int FromIndex, int ToIndex);
	void __fastcall ClearTempMenu(void);
	void __fastcall CreateButtons(int NewWidth, int NewHeight);
	void __fastcall SetButtonWidth(int Value);
	void __fastcall SetButtonHeight(int Value);
	void __fastcall UpdateImages(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetImageList(unsigned Value);
	void __fastcall SetImages(Imglist::TCustomImageList* Value);
	void __fastcall DisabledImageListChange(System::TObject* Sender);
	void __fastcall SetDisabledImageList(unsigned Value);
	void __fastcall SetDisabledImages(Imglist::TCustomImageList* Value);
	void __fastcall HotImageListChange(System::TObject* Sender);
	void __fastcall SetHotImageList(unsigned Value);
	void __fastcall SetHotImages(Imglist::TCustomImageList* Value);
	void __fastcall SetIndent(int Value);
	void __fastcall AdjustControl(Controls::TControl* Control);
	void __fastcall RecreateButtons(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall ResizeButtons(void);
	int __fastcall InternalButtonCount(void);
	int __fastcall ReorderButton(int OldIndex, int ALeft, int ATop);
	MESSAGE void __fastcall WMCaptureChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetText(Messages::TWMGetText &Message);
	MESSAGE void __fastcall WMGetTextLength(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMNotifyFormat(Messages::TMessage &Message);
	MESSAGE void __fastcall WMSetText(Messages::TWMSetText &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	MESSAGE void __fastcall WMSysChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Messages::TWMSysCommand &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMControlChange(Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(void *Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNChar(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CNSysKeyDown(Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall CMSysFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNDropDownClosed(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	
protected:
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Windows::TRect &Rect);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	DYNAMIC void __fastcall CancelMenu(void);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	DYNAMIC bool __fastcall CheckMenuDropdown(TToolButton* Button);
	DYNAMIC void __fastcall ClickButton(TToolButton* Button);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall CustomDraw(const Windows::TRect &ARect, TCustomDrawStage Stage);
	virtual bool __fastcall CustomDrawButton(TToolButton* Button, TCustomDrawState State, TCustomDrawStage 
		Stage, TTBCustomDrawFlags &Flags);
	TToolButton* __fastcall FindButtonFromAccel(Word Accel);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	DYNAMIC void __fastcall InitMenu(TToolButton* Button);
	bool __fastcall IsCustomDrawn(TCustomDrawTarget Target, TCustomDrawStage Stage);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	void __fastcall RepositionButton(int Index);
	void __fastcall RepositionButtons(int Index);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	bool __fastcall WrapButtons(int &NewWidth, int &NewHeight);
	
public:
	__fastcall virtual TToolBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TToolBar(void);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	DYNAMIC bool __fastcall TrackMenu(TToolButton* Button);
	__property int ButtonCount = {read=GetButtonCount, nodefault};
	__property TToolButton* Buttons[int Index] = {read=GetButton};
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	__property int RowCount = {read=GetRowCount, nodefault};
	
__published:
	__property Align ;
	__property Anchors ;
	__property AutoSize ;
	__property BorderWidth ;
	__property int ButtonHeight = {read=FButtonHeight, write=SetButtonHeight, default=22};
	__property int ButtonWidth = {read=FButtonWidth, write=SetButtonWidth, default=23};
	__property Caption ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property Imglist::TCustomImageList* DisabledImages = {read=FDisabledImages, write=SetDisabledImages
		};
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property EdgeBorders ;
	__property EdgeInner ;
	__property EdgeOuter ;
	__property Enabled ;
	__property bool Flat = {read=FFlat, write=SetFlat, default=0};
	__property Font ;
	__property Height ;
	__property Imglist::TCustomImageList* HotImages = {read=FHotImages, write=SetHotImages};
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property int Indent = {read=FIndent, write=SetIndent, default=0};
	__property bool List = {read=FList, write=SetList, default=0};
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property bool ShowCaptions = {read=FShowCaptions, write=SetShowCaptions, default=0};
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property Visible ;
	__property bool Wrapable = {read=FWrapable, write=SetWrapable, default=1};
	__property TTBAdvancedCustomDrawEvent OnAdvancedCustomDraw = {read=FOnAdvancedCustomDraw, write=FOnAdvancedCustomDraw
		};
	__property TTBAdvancedCustomDrawBtnEvent OnAdvancedCustomDrawButton = {read=FOnAdvancedCustomDrawButton
		, write=FOnAdvancedCustomDrawButton};
	__property OnClick ;
	__property OnContextPopup ;
	__property TTBCustomDrawEvent OnCustomDraw = {read=FOnCustomDraw, write=FOnCustomDraw};
	__property TTBCustomDrawBtnEvent OnCustomDrawButton = {read=FOnCustomDrawButton, write=FOnCustomDrawButton
		};
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
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TToolBar(HWND ParentWindow) : Toolwin::TToolWindow(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TToolButton : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	bool FAllowAllUp;
	bool FAutoSize;
	bool FDown;
	bool FGrouped;
	Imglist::TImageIndex FImageIndex;
	bool FIndeterminate;
	bool FMarked;
	Menus::TMenuItem* FMenuItem;
	Menus::TPopupMenu* FDropdownMenu;
	bool FWrap;
	TToolButtonStyle FStyle;
	int FUpdateCount;
	Byte __fastcall GetButtonState(void);
	int __fastcall GetIndex(void);
	bool __fastcall IsCheckedStored(void);
	bool __fastcall IsImageIndexStored(void);
	bool __fastcall IsWidthStored(void);
	HIDESBASE void __fastcall SetAutoSize(bool Value);
	void __fastcall SetButtonState(Byte State);
	void __fastcall SetDown(bool Value);
	void __fastcall SetDropdownMenu(Menus::TPopupMenu* Value);
	void __fastcall SetGrouped(bool Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetIndeterminate(bool Value);
	void __fastcall SetMarked(bool Value);
	void __fastcall SetMenuItem(Menus::TMenuItem* Value);
	void __fastcall SetStyle(TToolButtonStyle Value);
	void __fastcall SetWrap(bool Value);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMHitTest(Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	
protected:
	TToolBar* FToolBar;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EndUpdate(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int 
		Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall Paint(void);
	virtual void __fastcall RefreshControl(void);
	void __fastcall SetToolBar(TToolBar* AToolBar);
	virtual void __fastcall UpdateControl(void);
	DYNAMIC void __fastcall ValidateContainer(Classes::TComponent* AComponent);
	
public:
	__fastcall virtual TToolButton(Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall CheckMenuDropdown(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property int Index = {read=GetIndex, nodefault};
	
__published:
	__property Action ;
	__property bool AllowAllUp = {read=FAllowAllUp, write=FAllowAllUp, default=0};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property Caption ;
	__property bool Down = {read=FDown, write=SetDown, stored=IsCheckedStored, default=0};
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Menus::TPopupMenu* DropdownMenu = {read=FDropdownMenu, write=SetDropdownMenu};
	__property Enabled ;
	__property bool Grouped = {read=FGrouped, write=SetGrouped, default=0};
	__property Height  = {stored=false};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, stored=IsImageIndexStored
		, default=-1};
	__property bool Indeterminate = {read=FIndeterminate, write=SetIndeterminate, default=0};
	__property bool Marked = {read=FMarked, write=SetMarked, default=0};
	__property Menus::TMenuItem* MenuItem = {read=FMenuItem, write=SetMenuItem};
	__property ParentShowHint ;
	__property PopupMenu ;
	__property bool Wrap = {read=FWrap, write=SetWrap, default=0};
	__property ShowHint ;
	__property TToolButtonStyle Style = {read=FStyle, write=SetStyle, default=0};
	__property Visible ;
	__property Width  = {stored=IsWidthStored};
	__property OnClick ;
	__property OnContextPopup ;
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
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TToolButton(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TToolButtonActionLink : public Controls::TControlActionLink 
{
	typedef Controls::TControlActionLink inherited;
	
protected:
	TToolButton* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetImageIndex(int Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TToolButtonActionLink(System::TObject* AClient
		) : Controls::TControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TToolButtonActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TToolButtonActionLinkClass;

class DELPHICLASS TToolBarDockObject;
class PASCALIMPLEMENTATION TToolBarDockObject : public Controls::TDragDockObject 
{
	typedef Controls::TDragDockObject inherited;
	
private:
	Windows::TRect FEraseDockRect;
	bool FErase;
	
protected:
	virtual void __fastcall AdjustDockRect(const Windows::TRect &ARect);
	virtual void __fastcall DrawDragDockImage(void);
	virtual void __fastcall EraseDragDockImage(void);
	virtual Controls::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual bool __fastcall ToolDockImage(bool Erase);
public:
	#pragma option push -w-inl
	/* TDragDockObject.Create */ inline __fastcall virtual TToolBarDockObject(Controls::TControl* AControl
		) : Controls::TDragDockObject(AControl) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDragDockObject.Destroy */ inline __fastcall virtual ~TToolBarDockObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCoolBand;
class DELPHICLASS TCoolBar;
class PASCALIMPLEMENTATION TCoolBand : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	Forms::TFormBorderStyle FBorderStyle;
	bool FBreak;
	bool FFixedSize;
	bool FVisible;
	bool FHorizontalOnly;
	Imglist::TImageIndex FImageIndex;
	bool FFixedBackground;
	int FMinHeight;
	int FMinWidth;
	Graphics::TColor FColor;
	Controls::TWinControl* FControl;
	bool FParentColor;
	bool FParentBitmap;
	Graphics::TBitmap* FBitmap;
	AnsiString FText;
	int FWidth;
	Graphics::TBitmap* FDDB;
	int FID;
	TCoolBar* __fastcall CoolBar(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsBitmapStored(void);
	void __fastcall BitmapChanged(System::TObject* Sender);
	int __fastcall GetHeight(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetBreak(bool Value);
	void __fastcall SetFixedSize(bool Value);
	void __fastcall SetMinHeight(int Value);
	void __fastcall SetMinWidth(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetHorizontalOnly(bool Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetFixedBackground(bool Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetControl(Controls::TWinControl* Value);
	void __fastcall SetParentColor(bool Value);
	void __fastcall SetParentBitmap(bool Value);
	void __fastcall SetBitmap(Graphics::TBitmap* Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	DYNAMIC void __fastcall ParentColorChanged(void);
	DYNAMIC void __fastcall ParentBitmapChanged(void);
	
public:
	__fastcall virtual TCoolBand(Classes::TCollection* Collection);
	__fastcall virtual ~TCoolBand(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property int Height = {read=GetHeight, nodefault};
	
__published:
	__property Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap, stored=IsBitmapStored};
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property bool Break = {read=FBreak, write=SetBreak, default=1};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, default=-2147483633
		};
	__property Controls::TWinControl* Control = {read=FControl, write=SetControl};
	__property bool FixedBackground = {read=FFixedBackground, write=SetFixedBackground, default=1};
	__property bool FixedSize = {read=FFixedSize, write=SetFixedSize, default=0};
	__property bool HorizontalOnly = {read=FHorizontalOnly, write=SetHorizontalOnly, default=0};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int MinHeight = {read=FMinHeight, write=SetMinHeight, default=25};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=0};
	__property bool ParentColor = {read=FParentColor, write=SetParentColor, default=1};
	__property bool ParentBitmap = {read=FParentBitmap, write=SetParentBitmap, default=1};
	__property AnsiString Text = {read=FText, write=SetText};
	__property bool Visible = {read=GetVisible, write=SetVisible, default=1};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
};


class DELPHICLASS TCoolBands;
class PASCALIMPLEMENTATION TCoolBands : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	TCoolBar* FCoolBar;
	unsigned FVisibleCount;
	HIDESBASE TCoolBand* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TCoolBand* Value);
	
protected:
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	bool __fastcall HaveGraphic(void);
	
public:
	__fastcall TCoolBands(TCoolBar* CoolBar);
	HIDESBASE TCoolBand* __fastcall Add(void);
	TCoolBand* __fastcall FindBand(Controls::TControl* AControl);
	__property TCoolBar* CoolBar = {read=FCoolBar};
	__property TCoolBand* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TCoolBands(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCoolBandMaximize { bmNone, bmClick, bmDblClick };
#pragma option pop

class PASCALIMPLEMENTATION TCoolBar : public Toolwin::TToolWindow 
{
	typedef Toolwin::TToolWindow inherited;
	
private:
	TCoolBands* FBands;
	Forms::TFormBorderStyle FBandBorderStyle;
	TCoolBandMaximize FBandMaximize;
	Graphics::TBitmap* FBitmap;
	Graphics::TFont* FCaptionFont;
	int FCaptionFontHeight;
	Graphics::TBitmap* FDDB;
	bool FFixedSize;
	bool FFixedOrder;
	Imglist::TCustomImageList* FImages;
	Imglist::TChangeLink* FImageChangeLink;
	bool FShowText;
	bool FVertical;
	#pragma pack(push, 1)
	Windows::TSmallPoint FTrackDrag;
	#pragma pack(pop)
	
	int FUpdateCount;
	Classes::TNotifyEvent FOnChange;
	void __fastcall BeginUpdate(void);
	void __fastcall BitmapChanged(System::TObject* Sender);
	void __fastcall EndUpdate(void);
	bool __fastcall IsAutoSized(void);
	bool __fastcall IsBackgroundDirty(void);
	Controls::TAlign __fastcall GetAlign(void);
	HFONT __fastcall GetCaptionFont(void);
	int __fastcall GetCaptionFontHeight(void);
	int __fastcall GetCaptionSize(TCoolBand* Band);
	int __fastcall GetRowHeight(int Index);
	void __fastcall RefreshControl(TCoolBand* Band);
	HIDESBASE void __fastcall SetAlign(Controls::TAlign Value);
	void __fastcall SetBands(TCoolBands* Value);
	void __fastcall SetBandBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetBandMaximize(TCoolBandMaximize Value);
	void __fastcall SetBitmap(Graphics::TBitmap* Value);
	void __fastcall SetFixedSize(bool Value);
	void __fastcall SetFixedOrder(bool Value);
	void __fastcall SetImageList(unsigned Value);
	void __fastcall SetImages(Imglist::TCustomImageList* Value);
	void __fastcall SetShowText(bool Value);
	void __fastcall SetVertical(bool Value);
	void __fastcall ImageListChange(System::TObject* Sender);
	int __fastcall PtInGripRect(const Windows::TPoint &Pos, TCoolBand* &Band);
	bool __fastcall ReadBands(void);
	bool __fastcall UpdateItem(int Message, int FromIndex, int ToIndex);
	void __fastcall UpdateBand(int Index);
	void __fastcall UpdateBands(void);
	MESSAGE void __fastcall WMCaptureChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMNotifyFormat(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMControlChange(Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	MESSAGE void __fastcall CNBandChange(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMWinIniChange(Messages::TWMWinIniChange &Message);
	
protected:
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Windows::TRect &Rect);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	TCoolBand* __fastcall HitTest(const Windows::TPoint &Pos);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual void __fastcall PaintWindow(HDC DC);
	
public:
	__fastcall virtual TCoolBar(Classes::TComponent* AOwner);
	__fastcall virtual ~TCoolBar(void);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	
__published:
	__property Align  = {read=GetAlign, write=SetAlign, default=1};
	__property Anchors ;
	__property AutoSize ;
	__property Forms::TBorderStyle BandBorderStyle = {read=FBandBorderStyle, write=SetBandBorderStyle, 
		default=1};
	__property TCoolBandMaximize BandMaximize = {read=FBandMaximize, write=SetBandMaximize, default=1};
		
	__property TCoolBands* Bands = {read=FBands, write=SetBands};
	__property BorderWidth ;
	__property Color ;
	__property Constraints ;
	__property Ctl3D ;
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property EdgeBorders ;
	__property EdgeInner ;
	__property EdgeOuter ;
	__property Enabled ;
	__property bool FixedSize = {read=FFixedSize, write=SetFixedSize, default=0};
	__property bool FixedOrder = {read=FFixedOrder, write=SetFixedOrder, default=0};
	__property Font ;
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property Graphics::TBitmap* Bitmap = {read=FBitmap, write=SetBitmap};
	__property PopupMenu ;
	__property ShowHint ;
	__property bool ShowText = {read=FShowText, write=SetShowText, default=1};
	__property bool Vertical = {read=FVertical, write=SetVertical, default=0};
	__property Visible ;
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDockDrop ;
	__property OnDockOver ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnGetSiteInfo ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnResize ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnUnDock ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCoolBar(HWND ParentWindow) : Toolwin::TToolWindow(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS ECommonCalendarError;
class PASCALIMPLEMENTATION ECommonCalendarError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ECommonCalendarError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECommonCalendarError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECommonCalendarError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECommonCalendarError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECommonCalendarError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECommonCalendarError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECommonCalendarError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECommonCalendarError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECommonCalendarError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMonthCalColors;
class DELPHICLASS TCommonCalendar;
#pragma option push -b-
enum TCalDayOfWeek { dowMonday, dowTuesday, dowWednesday, dowThursday, dowFriday, dowSaturday, dowSunday, 
	dowLocaleDefault };
#pragma option pop

typedef void __fastcall (__closure *TOnGetMonthInfoEvent)(System::TObject* Sender, unsigned Month, unsigned 
	&MonthBoldInfo);

class PASCALIMPLEMENTATION TCommonCalendar : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TMonthCalColors* FCalColors;
	TMetaClass*FCalExceptionClass;
	System::TDateTime FDateTime;
	TDate FEndDate;
	TCalDayOfWeek FFirstDayOfWeek;
	TDate FMaxDate;
	int FMaxSelectRange;
	TDate FMinDate;
	int FMonthDelta;
	bool FMultiSelect;
	bool FShowToday;
	bool FShowTodayCircle;
	bool FWeekNumbers;
	TOnGetMonthInfoEvent FOnGetMonthInfo;
	bool __fastcall DoStoreEndDate(void);
	bool __fastcall DoStoreMaxDate(void);
	bool __fastcall DoStoreMinDate(void);
	TDate __fastcall GetDate(void);
	void __fastcall SetCalColors(TMonthCalColors* Value);
	void __fastcall SetDate(TDate Value);
	void __fastcall SetDateTime(System::TDateTime Value);
	void __fastcall SetEndDate(TDate Value);
	void __fastcall SetFirstDayOfWeek(TCalDayOfWeek Value);
	void __fastcall SetMaxDate(TDate Value);
	void __fastcall SetMaxSelectRange(int Value);
	void __fastcall SetMinDate(TDate Value);
	void __fastcall SetMonthDelta(int Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetRange(TDate MinVal, TDate MaxVal);
	void __fastcall SetSelectedRange(TDate Date, TDate EndDate);
	void __fastcall SetShowToday(bool Value);
	void __fastcall SetShowTodayCircle(bool Value);
	void __fastcall SetWeekNumbers(bool Value);
	
protected:
	virtual void __fastcall CheckEmptyDate(void);
	virtual void __fastcall CheckValidDate(TDate Value);
	virtual void __fastcall CreateWnd(void);
	virtual HWND __fastcall GetCalendarHandle(void) = 0 ;
	virtual unsigned __fastcall GetCalStyles(void);
	virtual bool __fastcall MsgSetCalColors(int ColorIndex, Graphics::TColor ColorValue) = 0 ;
	virtual bool __fastcall MsgSetDateTime(const _SYSTEMTIME &Value) = 0 ;
	virtual bool __fastcall MsgSetRange(int Flags, Windows::PSystemTime SysTime) = 0 ;
	__property TMonthCalColors* CalColors = {read=FCalColors, write=SetCalColors};
	__property HWND CalendarHandle = {read=GetCalendarHandle, nodefault};
	__property TMetaClass* CalExceptionClass = {read=FCalExceptionClass, write=FCalExceptionClass};
	__property TDate Date = {read=GetDate, write=SetDate};
	__property System::TDateTime DateTime = {read=FDateTime, write=SetDateTime};
	__property TDate EndDate = {read=FEndDate, write=SetEndDate, stored=DoStoreEndDate};
	__property TCalDayOfWeek FirstDayOfWeek = {read=FFirstDayOfWeek, write=SetFirstDayOfWeek, default=7
		};
	__property TDate MaxDate = {read=FMaxDate, write=SetMaxDate, stored=DoStoreMaxDate};
	__property int MaxSelectRange = {read=FMaxSelectRange, write=SetMaxSelectRange, default=31};
	__property TDate MinDate = {read=FMinDate, write=SetMinDate, stored=DoStoreMinDate};
	__property int MonthDelta = {read=FMonthDelta, write=SetMonthDelta, default=1};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	__property bool ShowToday = {read=FShowToday, write=SetShowToday, default=1};
	__property bool ShowTodayCircle = {read=FShowTodayCircle, write=SetShowTodayCircle, default=1};
	__property bool WeekNumbers = {read=FWeekNumbers, write=SetWeekNumbers, default=0};
	__property TOnGetMonthInfoEvent OnGetMonthInfo = {read=FOnGetMonthInfo, write=FOnGetMonthInfo};
	
public:
	__fastcall virtual TCommonCalendar(Classes::TComponent* AOwner);
	__fastcall virtual ~TCommonCalendar(void);
	void __fastcall BoldDays(const unsigned * Days, const int Days_Size, unsigned &MonthBoldInfo);
public:
		
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCommonCalendar(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TMonthCalColors : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TCommonCalendar* Owner;
	Graphics::TColor FBackColor;
	Graphics::TColor FTextColor;
	Graphics::TColor FTitleBackColor;
	Graphics::TColor FTitleTextColor;
	Graphics::TColor FMonthBackColor;
	Graphics::TColor FTrailingTextColor;
	void __fastcall SetColor(int Index, Graphics::TColor Value);
	void __fastcall SetAllColors(void);
	
public:
	__fastcall TMonthCalColors(TCommonCalendar* AOwner);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property Graphics::TColor BackColor = {read=FBackColor, write=SetColor, index=0, default=-2147483643
		};
	__property Graphics::TColor TextColor = {read=FTextColor, write=SetColor, index=1, default=-2147483640
		};
	__property Graphics::TColor TitleBackColor = {read=FTitleBackColor, write=SetColor, index=2, default=-2147483646
		};
	__property Graphics::TColor TitleTextColor = {read=FTitleTextColor, write=SetColor, index=3, default=16777215
		};
	__property Graphics::TColor MonthBackColor = {read=FMonthBackColor, write=SetColor, index=4, default=16777215
		};
	__property Graphics::TColor TrailingTextColor = {read=FTrailingTextColor, write=SetColor, index=5, 
		default=-2147483629};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TMonthCalColors(void) { }
	#pragma option pop
	
};


class DELPHICLASS EMonthCalError;
class PASCALIMPLEMENTATION EMonthCalError : public ECommonCalendarError 
{
	typedef ECommonCalendarError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMonthCalError(const AnsiString Msg) : ECommonCalendarError(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMonthCalError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : ECommonCalendarError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMonthCalError(int Ident)/* overload */ : ECommonCalendarError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMonthCalError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : ECommonCalendarError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMonthCalError(const AnsiString Msg, int AHelpContext)
		 : ECommonCalendarError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMonthCalError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : ECommonCalendarError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMonthCalError(int Ident, int AHelpContext)/* overload */
		 : ECommonCalendarError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMonthCalError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : ECommonCalendarError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMonthCalError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMonthCalendar;
class PASCALIMPLEMENTATION TMonthCalendar : public TCommonCalendar 
{
	typedef TCommonCalendar inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	
protected:
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual void __fastcall ConstrainedResize(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight
		);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual HWND __fastcall GetCalendarHandle(void);
	virtual bool __fastcall MsgSetCalColors(int ColorIndex, Graphics::TColor ColorValue);
	virtual bool __fastcall MsgSetDateTime(const _SYSTEMTIME &Value);
	virtual bool __fastcall MsgSetRange(int Flags, Windows::PSystemTime SysTime);
	
public:
	__fastcall virtual TMonthCalendar(Classes::TComponent* AOwner);
	
__published:
	__property Align ;
	__property Anchors ;
	__property AutoSize ;
	__property BorderWidth ;
	__property BiDiMode ;
	__property CalColors ;
	__property Constraints ;
	__property MultiSelect ;
	__property Date ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property EndDate ;
	__property FirstDayOfWeek ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property MaxDate ;
	__property MaxSelectRange ;
	__property MinDate ;
	__property ParentBiDiMode ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property ShowToday ;
	__property ShowTodayCircle ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property WeekNumbers ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetMonthInfo ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCommonCalendar.Destroy */ inline __fastcall virtual ~TMonthCalendar(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMonthCalendar(HWND ParentWindow) : TCommonCalendar(
		ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS EDateTimeError;
class PASCALIMPLEMENTATION EDateTimeError : public ECommonCalendarError 
{
	typedef ECommonCalendarError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDateTimeError(const AnsiString Msg) : ECommonCalendarError(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDateTimeError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : ECommonCalendarError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDateTimeError(int Ident)/* overload */ : ECommonCalendarError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDateTimeError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : ECommonCalendarError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDateTimeError(const AnsiString Msg, int AHelpContext)
		 : ECommonCalendarError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDateTimeError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : ECommonCalendarError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDateTimeError(int Ident, int AHelpContext)/* overload */
		 : ECommonCalendarError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDateTimeError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : ECommonCalendarError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDateTimeError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDateTimeKind { dtkDate, dtkTime };
#pragma option pop

#pragma option push -b-
enum TDTDateMode { dmComboBox, dmUpDown };
#pragma option pop

#pragma option push -b-
enum TDTDateFormat { dfShort, dfLong };
#pragma option pop

#pragma option push -b-
enum TDTCalAlignment { dtaLeft, dtaRight };
#pragma option pop

typedef void __fastcall (__closure *TDTParseInputEvent)(System::TObject* Sender, const AnsiString UserString
	, System::TDateTime &DateAndTime, bool &AllowChange);

typedef TMonthCalColors TDateTimeColors;
;

class DELPHICLASS TDateTimePicker;
class PASCALIMPLEMENTATION TDateTimePicker : public TCommonCalendar 
{
	typedef TCommonCalendar inherited;
	
private:
	TDTCalAlignment FCalAlignment;
	bool FChanging;
	bool FChecked;
	TDTDateFormat FDateFormat;
	TDTDateMode FDateMode;
	bool FDroppedDown;
	TDateTimeKind FKind;
	_SYSTEMTIME FLastChange;
	bool FParseInput;
	bool FShowCheckbox;
	TDTParseInputEvent FOnUserInput;
	Classes::TNotifyEvent FOnCloseUp;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnDropDown;
	void __fastcall AdjustHeight(void);
	TTime __fastcall GetTime(void);
	void __fastcall SetCalAlignment(TDTCalAlignment Value);
	void __fastcall SetChecked(bool Value);
	void __fastcall SetDateMode(TDTDateMode Value);
	void __fastcall SetDateFormat(TDTDateFormat Value);
	void __fastcall SetKind(TDateTimeKind Value);
	void __fastcall SetParseInput(bool Value);
	void __fastcall SetShowCheckbox(bool Value);
	void __fastcall SetTime(TTime Value);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	
protected:
	virtual void __fastcall CheckEmptyDate(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall Change(void);
	virtual HWND __fastcall GetCalendarHandle(void);
	virtual bool __fastcall MsgSetCalColors(int ColorIndex, Graphics::TColor ColorValue);
	virtual bool __fastcall MsgSetDateTime(const _SYSTEMTIME &Value);
	virtual bool __fastcall MsgSetRange(int Flags, Windows::PSystemTime SysTime);
	
public:
	__fastcall virtual TDateTimePicker(Classes::TComponent* AOwner);
	__property DateTime ;
	__property bool DroppedDown = {read=FDroppedDown, nodefault};
	
__published:
	__property Anchors ;
	__property BiDiMode ;
	__property TDTCalAlignment CalAlignment = {read=FCalAlignment, write=SetCalAlignment, nodefault};
	__property CalColors ;
	__property Constraints ;
	__property Date ;
	__property TTime Time = {read=GetTime, write=SetTime};
	__property bool ShowCheckbox = {read=FShowCheckbox, write=SetShowCheckbox, default=0};
	__property bool Checked = {read=FChecked, write=SetChecked, default=1};
	__property Color  = {stored=true, default=-2147483643};
	__property TDTDateFormat DateFormat = {read=FDateFormat, write=SetDateFormat, nodefault};
	__property TDTDateMode DateMode = {read=FDateMode, write=SetDateMode, nodefault};
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property Enabled ;
	__property Font ;
	__property ImeMode ;
	__property ImeName ;
	__property TDateTimeKind Kind = {read=FKind, write=SetKind, nodefault};
	__property MaxDate ;
	__property MinDate ;
	__property bool ParseInput = {read=FParseInput, write=SetParseInput, nodefault};
	__property ParentBiDiMode ;
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property OnClick ;
	__property Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnContextPopup ;
	__property Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
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
	__property OnStartDock ;
	__property OnStartDrag ;
	__property TDTParseInputEvent OnUserInput = {read=FOnUserInput, write=FOnUserInput};
public:
	#pragma option push -w-inl
	/* TCommonCalendar.Destroy */ inline __fastcall virtual ~TDateTimePicker(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDateTimePicker(HWND ParentWindow) : TCommonCalendar(
		ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPageScrollerOrientation { soHorizontal, soVertical };
#pragma option pop

#pragma option push -b-
enum TPageScrollerButton { sbFirst, sbLast };
#pragma option pop

#pragma option push -b-
enum TPageScrollerButtonState { bsNormal, bsInvisible, bsGrayed, bsDepressed, bsHot };
#pragma option pop

typedef void __fastcall (__closure *TPageScrollEvent)(System::TObject* Sender, Classes::TShiftState 
	Shift, int X, int Y, TPageScrollerOrientation Orientation, int &Delta);

class DELPHICLASS TPageScroller;
class PASCALIMPLEMENTATION TPageScroller : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	bool FAutoScroll;
	int FButtonSize;
	Controls::TWinControl* FControl;
	bool FDragScroll;
	int FMargin;
	TPageScrollerOrientation FOrientation;
	int FPosition;
	int FPreferredSize;
	TPageScrollEvent FOnScroll;
	MESSAGE void __fastcall CNNotify(Messages::TWMNotify &Message);
	void __fastcall DoSetControl(Controls::TWinControl* Value);
	void __fastcall SetAutoScroll(bool Value);
	void __fastcall SetButtonSize(int Value);
	void __fastcall SetControl(Controls::TWinControl* Value);
	void __fastcall SetDragScroll(bool Value);
	void __fastcall SetMargin(int Value);
	void __fastcall SetOrientation(TPageScrollerOrientation Value);
	void __fastcall SetPosition(int Value);
	void __fastcall UpdatePreferredSize(void);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall CMControlChange(Controls::TCMControlChange &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AlignControls(Controls::TControl* AControl, Windows::TRect &Rect);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	DYNAMIC void __fastcall Scroll(Classes::TShiftState Shift, int X, int Y, TPageScrollerOrientation Orientation
		, int &Delta);
	
public:
	__fastcall virtual TPageScroller(Classes::TComponent* AOwner);
	TPageScrollerButtonState __fastcall GetButtonState(TPageScrollerButton Button);
	
__published:
	__property Align ;
	__property Anchors ;
	__property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, nodefault};
	__property BorderWidth ;
	__property int ButtonSize = {read=FButtonSize, write=SetButtonSize, default=12};
	__property Color ;
	__property Constraints ;
	__property Controls::TWinControl* Control = {read=FControl, write=SetControl};
	__property DockSite ;
	__property DragCursor ;
	__property DragKind ;
	__property DragMode ;
	__property bool DragScroll = {read=FDragScroll, write=SetDragScroll, default=1};
	__property Enabled ;
	__property Font ;
	__property int Margin = {read=FMargin, write=SetMargin, default=0};
	__property TPageScrollerOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0
		};
	__property ParentColor ;
	__property ParentFont ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property int Position = {read=FPosition, write=SetPosition, default=0};
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
	__property OnMouseWheel ;
	__property OnResize ;
	__property TPageScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPageScroller(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TPageScroller(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint ColumnHeaderWidth = 0xfffffffe;
static const Shortint ColumnTextWidth = 0xffffffff;
static const Word CN_DROPDOWNCLOSED = 0x1400;
static const Word CN_BANDCHANGE = 0x1400;
static const int ComCtlVersionIE3 = 0x40046;
static const int ComCtlVersionIE4 = 0x40047;
static const int ComCtlVersionIE401 = 0x40048;
static const int ComCtlVersionIE5 = 0x50050;
extern PACKAGE bool __fastcall InitCommonControl(int CC);
extern PACKAGE void __fastcall CheckCommonControl(int CC);
extern PACKAGE int __fastcall GetComCtlVersion(void);
extern PACKAGE void __fastcall CheckToolMenuDropdown(TToolButton* ToolButton);

}	/* namespace Comctrls */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Comctrls;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ComCtrls
