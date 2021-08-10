// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QForms.pas' rev: 6.00

#ifndef QFormsHPP
#define QFormsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HelpIntfs.hpp>	// Pascal unit
#include <QStyle.hpp>	// Pascal unit
#include <QActnList.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qforms
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TScrollBarKind { sbHorizontal, sbVertical };
#pragma option pop

typedef Word TScrollBarInc;

class DELPHICLASS TControlScrollBar;
class DELPHICLASS TScrollingWidget;
class PASCALIMPLEMENTATION TScrollingWidget : public Qcontrols::TFrameControl 
{
	typedef Qcontrols::TFrameControl inherited;
	
private:
	TControlScrollBar* FHorzScrollBar;
	TControlScrollBar* FVertScrollBar;
	bool FAutoScroll;
	bool FIgnoreMoves;
	int FAutoRangeCount;
	#pragma pack(push, 1)
	tagSIZE FOldScrollPos;
	#pragma pack(pop)
	
	bool FUpdatingScrollBars;
	Qt::QWidgetH* FViewportHandle;
	Qt::QWidget_hookH* FViewportHook;
	tagSIZE __fastcall CalcAutoRange();
	void __cdecl ContentsMovingHook(int x, int y);
	void __fastcall ScaleScrollBars(int MV, int DV, int MH, int DH);
	void __cdecl ScrollBarGeometryHook(Qt::QScrollBarH* sb, int &x, int &y, int &w, int &h);
	void __fastcall SetAutoScroll(const bool Value);
	void __fastcall SetHorzScrollBar(const TControlScrollBar* Value);
	void __fastcall SetVertScrollBar(const TControlScrollBar* Value);
	void __fastcall UpdateScrollBars(void);
	HIDESBASE Qt::QOpenScrollViewH* __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall AdjustScrollRange(TScrollBarKind Kind, int &ARange);
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	virtual void __fastcall AlignControls(Qcontrols::TControl* AControl, Types::TRect &ARect);
	virtual bool __fastcall AutoScrollEnabled(void);
	virtual void __fastcall AutoScrollInView(Qcontrols::TControl* AControl);
	DYNAMIC void __fastcall ChangeScale(int MV, int DV, int MH, int DH);
	DYNAMIC void __fastcall ColorChanged(void);
	DYNAMIC void __fastcall ControlsListChanging(Qcontrols::TControl* Control, bool Inserting);
	virtual void __fastcall CreateWidget(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual Qt::QPaintDeviceH* __fastcall GetAlignedPaintDevice(void);
	virtual Qt::QWidgetH* __fastcall GetChildHandle(void);
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual Types::TRect __fastcall GetClientRect();
	virtual Qt::QPaintDeviceH* __fastcall GetPaintDevice(void);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall PaletteChanged(System::TObject* Sender);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall ScrollBarSize(TControlScrollBar* ScrollBar, int &Position, int &Extent);
	virtual void __fastcall ScrollBarVisibleChanged(TControlScrollBar* Sender);
	Qt::QWidgetH* __fastcall ViewportHandle(void);
	virtual Types::TRect __fastcall ViewportRect();
	DYNAMIC void __fastcall WidgetDestroyed(void);
	virtual int __fastcall WidgetFlags(void);
	__property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, default=1};
	
public:
	__fastcall virtual TScrollingWidget(Classes::TComponent* AOwner);
	__fastcall virtual ~TScrollingWidget(void);
	void __fastcall DisableAutoRange(void);
	void __fastcall EnableAutoRange(void);
	virtual void __fastcall ScrollBy(int DeltaX, int DeltaY);
	void __fastcall ScrollInView(Qcontrols::TControl* AControl);
	__property BorderStyle  = {default=4};
	__property Qt::QOpenScrollViewH* Handle = {read=GetHandle};
	
__published:
	__property TControlScrollBar* VertScrollBar = {read=FVertScrollBar, write=SetVertScrollBar};
	__property TControlScrollBar* HorzScrollBar = {read=FHorzScrollBar, write=SetHorzScrollBar};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TScrollingWidget(Qt::QWidgetH* ParentWidget) : Qcontrols::TFrameControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TControlScrollBar : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TScrollingWidget* FControl;
	TScrollBarInc FIncrement;
	TScrollBarInc FPageIncrement;
	int FPosition;
	int FRange;
	TScrollBarKind FKind;
	Word FMargin;
	bool FVisible;
	bool FTracking;
	bool FScaled;
	Qgraphics::TColor FColor;
	bool FParentColor;
	bool FUpdateNeeded;
	Qt::QScrollBarH* FHandle;
	Qt::QScrollBar_hookH* FHooks;
	__fastcall TControlScrollBar(TScrollingWidget* AControl, TScrollBarKind AKind);
	int __fastcall CalcAutoRange(void);
	void __fastcall DoSetRange(int Value);
	int __fastcall GetScrollPos(void);
	bool __fastcall HandleAllocated(void);
	void __fastcall SetColor(Qgraphics::TColor Value);
	void __fastcall SetParentColor(bool Value);
	void __fastcall SetPosition(const int Value);
	void __fastcall SetRange(const int Value);
	void __fastcall SetVisible(const bool Value);
	bool __fastcall IsRangeStored(void);
	void __fastcall Update(void);
	void __fastcall SetIncrement(const TScrollBarInc Value);
	void __fastcall SetMargin(const Word Value);
	void __fastcall SetHandle(const Qt::QScrollBarH* Value);
	void __fastcall SetTracking(const bool Value);
	
protected:
	bool __cdecl EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall IsScrollBarVisible(void);
	__property TScrollBarKind Kind = {read=FKind, nodefault};
	__property Qt::QScrollBarH* Handle = {read=FHandle, write=SetHandle};
	__property int ScrollPos = {read=GetScrollPos, nodefault};
	
__published:
	__property Qgraphics::TColor Color = {read=FColor, write=SetColor, default=-10};
	__property TScrollBarInc Increment = {read=FIncrement, write=SetIncrement, default=8};
	__property Word Margin = {read=FMargin, write=SetMargin, default=0};
	__property bool ParentColor = {read=FParentColor, write=SetParentColor, default=1};
	__property int Range = {read=FRange, write=SetRange, stored=IsRangeStored, default=0};
	__property int Position = {read=FPosition, write=SetPosition, default=0};
	__property bool Tracking = {read=FTracking, write=SetTracking, default=1};
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


typedef TScrollingWidget TScrollingWinControl;
;

class DELPHICLASS TScrollBox;
class PASCALIMPLEMENTATION TScrollBox : public TScrollingWidget 
{
	typedef TScrollingWidget inherited;
	
public:
	__fastcall virtual TScrollBox(Classes::TComponent* AOwner);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property AutoScroll  = {default=1};
	__property BorderStyle  = {default=6};
	__property Color ;
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TScrollingWidget.Destroy */ inline __fastcall virtual ~TScrollBox(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TScrollBox(Qt::QWidgetH* ParentWidget) : TScrollingWidget(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomFrame;
class PASCALIMPLEMENTATION TCustomFrame : public TScrollingWidget 
{
	typedef TScrollingWidget inherited;
	
private:
	void __fastcall AddActionList(Qactnlist::TCustomActionList* ActionList);
	void __fastcall RemoveActionList(Qactnlist::TCustomActionList* ActionList);
	
protected:
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property BorderStyle  = {default=0};
	
public:
	__fastcall virtual TCustomFrame(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TScrollingWidget.Destroy */ inline __fastcall virtual ~TCustomFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomFrame(Qt::QWidgetH* ParentWidget) : TScrollingWidget(ParentWidget) { }
	#pragma option pop
	
};


typedef TMetaClass*TCustomFrameClass;

class DELPHICLASS TFrame;
class PASCALIMPLEMENTATION TFrame : public TCustomFrame 
{
	typedef TCustomFrame inherited;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property AutoScroll  = {default=1};
	__property BorderStyle  = {default=0};
	__property Color ;
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomFrame.Create */ inline __fastcall virtual TFrame(Classes::TComponent* AOwner) : TCustomFrame(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScrollingWidget.Destroy */ inline __fastcall virtual ~TFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TFrame(Qt::QWidgetH* ParentWidget) : TCustomFrame(ParentWidget) { }
	#pragma option pop
	
};


__interface IDesignerHook;
typedef System::DelphiInterface<IDesignerHook> _di_IDesignerHook;
class DELPHICLASS TCustomForm;
__interface INTERFACE_UUID("{ABBE7256-5495-11D1-9FB5-0020AF3D82DA}") IDesignerHook  : public IDesignerNotify 
{
	
public:
	virtual Classes::TComponent* __fastcall GetRoot(void) = 0 ;
	virtual TCustomForm* __fastcall GetCustomForm(void) = 0 ;
	virtual bool __fastcall IsDesignEvent(Qcontrols::TWidgetControl* Sender, Qt::QObjectH* SenderHandle, Qt::QEventH* Event) = 0 ;
	virtual void __fastcall ControlPaintRequest(Qcontrols::TControl* Control) = 0 ;
	virtual void __fastcall PaintGrid(void) = 0 ;
	virtual void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName) = 0 ;
	virtual AnsiString __fastcall UniqueName(const AnsiString BaseName) = 0 ;
	__property TCustomForm* Form = {read=GetCustomForm};
	__property Classes::TComponent* Root = {read=GetRoot};
};

#pragma option push -b-
enum TBorderIcon { biSystemMenu, biMinimize, biMaximize, biHelp };
#pragma option pop

typedef Set<TBorderIcon, biSystemMenu, biHelp>  TBorderIcons;

#pragma option push -b-
enum TFormBorderStyle { fbsNone, fbsSingle, fbsSizeable, fbsDialog, fbsToolWindow, fbsSizeToolWin };
#pragma option pop

#pragma option push -b-
enum TFormStyle { fsNormal, fsMDIChild, fsMDIForm, fsStayOnTop };
#pragma option pop

#pragma option push -b-
enum TPosition { poDesigned, poDefault, poDefaultPosOnly, poDefaultSizeOnly, poScreenCenter, poDesktopCenter, poMainFormCenter, poOwnerFormCenter };
#pragma option pop

#pragma option push -b-
enum TWindowState { wsNormal, wsMinimized, wsMaximized };
#pragma option pop

#pragma option push -b-
enum TCloseAction { caNone, caHide, caFree, caMinimize };
#pragma option pop

#pragma option push -b-
enum TShowAction { saIgnore, saRestore, saMinimize, saMaximize };
#pragma option pop

typedef void __fastcall (__closure *TCloseEvent)(System::TObject* Sender, TCloseAction &Action);

typedef void __fastcall (__closure *TCloseQueryEvent)(System::TObject* Sender, bool &CanClose);

typedef int TModalResult;

#pragma option push -b-
enum QForms__6 { fsCreating, fsVisible, fsShowing, fsModal, fsActivated };
#pragma option pop

typedef Set<QForms__6, fsCreating, fsActivated>  TFormState;

typedef void __fastcall (__closure *TShortCutEvent)(int Key, Classes::TShiftState Shift, bool &Handled);

typedef bool __fastcall (__closure *THelpEvent)(Classes::THelpType HelpType, Classes::THelpContext HelpContext, const AnsiString HelpKeyword, const AnsiString HelpFile, bool &Handled);

class DELPHICLASS TForm;
class PASCALIMPLEMENTATION TCustomForm : public TScrollingWidget 
{
	typedef TScrollingWidget inherited;
	
private:
	Qcontrols::TWidgetControl* FActiveControl;
	Qcontrols::TWidgetControl* FFocusedControl;
	TBorderIcons FBorderIcons;
	bool FActive;
	bool FKeyPreview;
	bool FDropTarget;
	bool FShown;
	_di_IDesignerHook FDesignerHook;
	Qmenus::TMainMenu* FMenu;
	TModalResult FModalResult;
	TFormBorderStyle FBorderStyle;
	Qcontrols::TControlCanvas* FCanvas;
	int FClientHeight;
	int FClientWidth;
	int FPixelsPerInch;
	int FTextHeight;
	int FTextWidth;
	TCloseEvent FOnClose;
	TCloseQueryEvent FOnCloseQuery;
	THelpEvent FOnHelp;
	Classes::TNotifyEvent FOnCreate;
	Classes::TNotifyEvent FOnLoaded;
	Classes::TNotifyEvent FOnPaint;
	Classes::TNotifyEvent FOnActivate;
	TShortCutEvent FOnShortCut;
	Classes::TNotifyEvent FOnShow;
	Classes::TNotifyEvent FOnDeactivate;
	Classes::TNotifyEvent FOnHide;
	Classes::TNotifyEvent FOnDestroy;
	TFormStyle FFormStyle;
	TPosition FPosition;
	TWindowState FWindowState;
	bool FSizeGrip;
	Qt::QSizeGripH* FGripper;
	int FMenuHeight;
	Qt::QWorkspaceH* FClientHandle;
	Qt::QWorkspace_hookH* FClientHooks;
	TForm* FMDIParent;
	Classes::TList* FMDIChildList;
	Qgraphics::TIcon* FIcon;
	void __fastcall CheckGripper(void);
	Qgraphics::TCanvas* __fastcall GetCanvas(void);
	int __fastcall GetPixelsPerInch(void);
	bool __fastcall GetScaled(void);
	bool __fastcall IsClientSizeStored(void);
	bool __fastcall IsFormSizeStored(void);
	void __fastcall SetActiveControl(const Qcontrols::TWidgetControl* Control);
	HIDESBASE void __fastcall SetClientHeight(int Value);
	HIDESBASE void __fastcall SetClientWidth(int Value);
	void __fastcall SetDesignerHook(const _di_IDesignerHook Value);
	void __fastcall SetMenu(const Qmenus::TMainMenu* Value);
	void __fastcall SetPixelsPerInch(const int Value);
	void __fastcall SetScaled(const bool Value);
	HIDESBASE void __fastcall SetVisible(bool Value);
	void __fastcall SetWidgetFocus(void);
	bool __fastcall IsForm(void);
	HIDESBASE void __fastcall SetBorderStyle(const TFormBorderStyle Value);
	void __fastcall SetBorderIcons(const TBorderIcons Value);
	void __fastcall SetFormStyle(const TFormStyle Value);
	void __fastcall IgnoreIdent(Classes::TReader* Reader);
	void __fastcall SetPosition(const TPosition Value);
	void __fastcall SetModalResult(const TModalResult Value);
	void __fastcall SetWindowState(const TWindowState Value);
	void __fastcall ShowWindowState(void);
	void __fastcall SetMDIParent(const TForm* Value);
	Classes::TList* __fastcall MDIChildList(void);
	void __fastcall WorkspaceNeeded(void);
	int __fastcall GetMDIChildCount(void);
	TForm* __fastcall GetMDIChildren(int I);
	void __fastcall RemoveMDIChild(TCustomForm* AForm);
	void __fastcall AppendMDIChild(TCustomForm* AForm);
	Qt::QWorkspaceH* __fastcall GetClientHandle(void);
	TForm* __fastcall GetActiveMDIChild(void);
	void __fastcall SetIcon(const Qgraphics::TIcon* Value);
	void __fastcall MergeMenu(bool MergeState);
	int __fastcall GetTextHeight(void);
	int __fastcall GetTextWidth(void);
	void __fastcall ReadTextHeight(Classes::TReader* Reader);
	void __fastcall ReadTextWidth(Classes::TReader* Reader);
	void __fastcall WriteTextHeight(Classes::TWriter* Writer);
	void __fastcall WriteTextWidth(Classes::TWriter* Writer);
	void __fastcall WritePixelsPerInch(Classes::TWriter* Writer);
	void __cdecl MDIChildActivated(Qt::QWidgetH* w);
	
protected:
	Classes::TList* FActionLists;
	TFormState FFormState;
	DYNAMIC bool __fastcall ActionExecute(Classes::TBasicAction* &BasicAction);
	DYNAMIC bool __fastcall ActionUpdate(Classes::TBasicAction* &BasicAction);
	DYNAMIC void __fastcall Activate(void);
	DYNAMIC void __fastcall ActiveChanged(void);
	virtual void __fastcall AlignControls(Qcontrols::TControl* AControl, Types::TRect &Rect);
	DYNAMIC void __fastcall BeginAutoDrag(void);
	DYNAMIC void __fastcall ChangeScale(int MV, int DV, int MH, int DH);
	DYNAMIC void __fastcall ColorChanged(void);
	DYNAMIC void __fastcall ControlsListChanging(Qcontrols::TControl* Control, bool Inserting);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall Deactivate(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoClose(TCloseAction &Action);
	virtual void __fastcall DoCreate(void);
	virtual void __fastcall DoDestroy(void);
	DYNAMIC void __fastcall DoHide(void);
	DYNAMIC void __fastcall DoLoaded(void);
	DYNAMIC void __fastcall DoShow(void);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual Types::TRect __fastcall GetClientRect();
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual Qt::QPaintDeviceH* __fastcall GetPaintDevice(void);
	virtual Qt::QWidgetH* __fastcall GetParentWidget(void);
	DYNAMIC bool __fastcall HandleCreateException(void);
	virtual void __fastcall IconChanged(System::TObject* Sender);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Loaded(void);
	int __fastcall MDIChildTop(void);
	int __fastcall MDIChildLeft(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Painting(Qt::QObjectH* Sender, Qt::QRegionH* EventRegion);
	DYNAMIC void __fastcall Paint(void);
	DYNAMIC void __fastcall ParentFontChanged(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall Resize(void);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	virtual void __fastcall SetInitialBounds(void);
	virtual void __fastcall SetParent(const Qcontrols::TWidgetControl* AParent);
	DYNAMIC void __fastcall ShowingChanged(void);
	virtual void __fastcall UpdateActions(void);
	virtual void __fastcall ValidateRename(Classes::TComponent* AComponent, const AnsiString CurName, const AnsiString NewName);
	virtual Types::TRect __fastcall ViewportRect();
	DYNAMIC void __fastcall VisibleChanging(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	virtual int __fastcall WidgetFlags(void);
	__property TForm* ActiveMDIChild = {read=GetActiveMDIChild};
	__property TBorderIcons BorderIcons = {read=FBorderIcons, write=SetBorderIcons, stored=IsForm, default=7};
	__property TFormBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, stored=IsForm, default=2};
	__property Qt::QWorkspaceH* ClientHandle = {read=GetClientHandle};
	__property ClientHeight  = {write=SetClientHeight, stored=IsClientSizeStored};
	__property ClientWidth  = {write=SetClientWidth, stored=IsClientSizeStored};
	__property TFormStyle FormStyle = {read=FFormStyle, write=SetFormStyle, stored=IsForm, default=0};
	__property Height  = {stored=IsFormSizeStored};
	__property Qgraphics::TIcon* Icon = {read=FIcon, write=SetIcon};
	__property int MDIChildCount = {read=GetMDIChildCount, nodefault};
	__property TForm* MDIChildren[int I] = {read=GetMDIChildren};
	__property TForm* MDIParent = {read=FMDIParent, write=SetMDIParent};
	__property int PixelsPerInch = {read=GetPixelsPerInch, write=SetPixelsPerInch, stored=false, nodefault};
	__property TPosition Position = {read=FPosition, write=SetPosition, default=0};
	__property bool Scaled = {read=GetScaled, write=SetScaled, default=1};
	__property bool SizeGrip = {read=FSizeGrip, write=FSizeGrip, default=1};
	__property Visible  = {write=SetVisible, default=0};
	__property Width  = {stored=IsFormSizeStored};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property TCloseEvent OnClose = {read=FOnClose, write=FOnClose};
	__property TCloseQueryEvent OnCloseQuery = {read=FOnCloseQuery, write=FOnCloseQuery};
	__property Classes::TNotifyEvent OnCreate = {read=FOnCreate, write=FOnCreate};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
	__property THelpEvent OnHelp = {read=FOnHelp, write=FOnHelp};
	__property Classes::TNotifyEvent OnHide = {read=FOnHide, write=FOnHide};
	__property Classes::TNotifyEvent OnLoaded = {read=FOnLoaded, write=FOnLoaded};
	__property Classes::TNotifyEvent OnPaint = {read=FOnPaint, write=FOnPaint};
	__property TShortCutEvent OnShortCut = {read=FOnShortCut, write=FOnShortCut};
	__property Classes::TNotifyEvent OnShow = {read=FOnShow, write=FOnShow};
	
public:
	__fastcall virtual TCustomForm(Classes::TComponent* AOwner);
	__fastcall virtual TCustomForm(Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TCustomForm(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	void __fastcall Close(void);
	virtual bool __fastcall CloseQuery(void);
	void __fastcall DefocusControl(Qcontrols::TWidgetControl* Control, bool Removing);
	void __fastcall FocusControl(Qcontrols::TWidgetControl* Control);
	HIDESBASE void __fastcall Hide(void);
	virtual void __fastcall InvokeHelp(void);
	DYNAMIC bool __fastcall IsShortCut(int Key, Classes::TShiftState Shift, const WideString KeyText);
	void __fastcall Release(void);
	virtual void __fastcall SetFocus(void);
	virtual bool __fastcall SetFocusedControl(Qcontrols::TWidgetControl* Control);
	HIDESBASE void __fastcall Show(void);
	virtual int __fastcall ShowModal(void);
	__property Action ;
	__property bool Active = {read=FActive, default=1};
	__property Qcontrols::TWidgetControl* ActiveControl = {read=FActiveControl, write=SetActiveControl};
	__property Qgraphics::TCanvas* Canvas = {read=GetCanvas};
	__property Caption ;
	__property Color ;
	__property _di_IDesignerHook DesignerHook = {read=FDesignerHook, write=SetDesignerHook};
	__property bool DropTarget = {read=FDropTarget, write=FDropTarget, nodefault};
	__property Qcontrols::TWidgetControl* FocusedControl = {read=FFocusedControl};
	__property Font ;
	__property TFormState FormState = {read=FFormState, nodefault};
	__property HelpFile ;
	__property bool KeyPreview = {read=FKeyPreview, write=FKeyPreview, default=0};
	__property Qmenus::TMainMenu* Menu = {read=FMenu, write=SetMenu};
	__property TModalResult ModalResult = {read=FModalResult, write=SetModalResult, nodefault};
	__property TWindowState WindowState = {read=FWindowState, write=SetWindowState, stored=IsForm, default=0};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomForm(Qt::QWidgetH* ParentWidget) : TScrollingWidget(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TForm : public TCustomForm 
{
	typedef TCustomForm inherited;
	
public:
	void __fastcall Cascade(void);
	void __fastcall Next(void);
	void __fastcall Previous(void);
	void __fastcall Tile(void);
	__property ActiveMDIChild ;
	__property ClientHandle ;
	__property MDIChildCount ;
	__property MDIChildren ;
	
__published:
	__property Action ;
	__property ActiveControl ;
	__property Anchors  = {default=3};
	__property AutoScroll  = {default=1};
	__property Bitmap ;
	__property BorderIcons  = {default=7};
	__property BorderStyle  = {default=2};
	__property Caption ;
	__property ClientHeight ;
	__property ClientWidth ;
	__property Color ;
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property FormStyle  = {default=0};
	__property Height ;
	__property HelpFile ;
	__property HelpKeyword ;
	__property HorzScrollBar ;
	__property Icon ;
	__property KeyPreview  = {default=0};
	__property Menu ;
	__property ParentFont  = {default=1};
	__property PixelsPerInch ;
	__property PopupMenu ;
	__property Position  = {default=0};
	__property Scaled  = {default=1};
	__property ShowHint ;
	__property VertScrollBar ;
	__property Visible  = {default=0};
	__property Width ;
	__property WindowState  = {default=0};
	__property OnActivate ;
	__property OnClick ;
	__property OnClose ;
	__property OnCloseQuery ;
	__property OnConstrainedResize ;
	__property OnContextPopup ;
	__property OnCreate ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDeactivate ;
	__property OnDestroy ;
	__property OnHelp ;
	__property OnHide ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnLoaded ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheel ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnPaint ;
	__property OnResize ;
	__property OnShow ;
	__property OnShortCut ;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TForm(Classes::TComponent* AOwner) : TCustomForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TForm(Classes::TComponent* AOwner, int Dummy) : TCustomForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TForm(Qt::QWidgetH* ParentWidget) : TCustomForm(ParentWidget) { }
	#pragma option pop
	
};



typedef TMetaClass*TCustomFormClass;

typedef TMetaClass*TFormClass;

struct TCursorRec;
typedef TCursorRec *PCursorRec;

#pragma pack(push, 4)
struct TCursorRec
{
	TCursorRec *Next;
	int Index;
	Qt::QCursorH* Handle;
} ;
#pragma pack(pop)

class DELPHICLASS TScreen;
class PASCALIMPLEMENTATION TScreen : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TCursorRec *FCursorList;
	int FPixelsPerInch;
	Qcontrols::TCursor FCursor;
	int FCursorCount;
	Classes::TNotifyEvent FOnActiveControlChange;
	Classes::TNotifyEvent FOnActiveFormChange;
	Qcontrols::TWidgetControl* FActiveControl;
	Classes::TList* FSaveFocusedList;
	Classes::TList* FForms;
	Classes::TList* FCustomForms;
	Classes::TList* FDataModules;
	TCustomForm* FActiveCustomForm;
	TForm* FActiveForm;
	Qcontrols::TWidgetControl* FLastActiveControl;
	TCustomForm* FLastActiveCustomForm;
	TCustomForm* FFocusedForm;
	Qgraphics::TFont* FHintFont;
	Qt::QCursorH* FDefaultCursor;
	Classes::TStrings* FFonts;
	void __fastcall AddDataModule(Classes::TDataModule* DataModule);
	void __fastcall AddForm(TCustomForm* AForm);
	void __fastcall CreateCursors(void);
	void __fastcall DeleteCursor(int Index);
	Qt::QCursorH* __fastcall GetCursors(int Index);
	int __fastcall GetCustomFormCount(void);
	TCustomForm* __fastcall GetCustomForms(int Index);
	Classes::TDataModule* __fastcall GetDataModule(int Index);
	int __fastcall GetDataModuleCount(void);
	Classes::TStrings* __fastcall GetFonts(void);
	TForm* __fastcall GetForm(int Index);
	int __fastcall GetFormCount(void);
	int __fastcall GetPixelsPerInch(void);
	Qgraphics::TFont* __fastcall GetHintFont(void);
	void __fastcall InternalHintFontChanged(System::TObject* Sender);
	void __fastcall InsertCursor(int Index, Qt::QCursorH* Handle);
	void __fastcall RemoveDataModule(Classes::TDataModule* DataModule);
	void __fastcall RemoveForm(TCustomForm* AForm);
	void __fastcall SetCursor(const Qcontrols::TCursor Value);
	void __fastcall SetCursors(int Index, const Qt::QCursorH* Value);
	void __fastcall SetHintFont(Qgraphics::TFont* Value);
	void __fastcall UpdateLastActive(void);
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	Qt::QWidgetH* __fastcall GetActiveWidget(void);
	
public:
	__fastcall virtual TScreen(Classes::TComponent* AOwner);
	__fastcall virtual ~TScreen(void);
	__property Qcontrols::TWidgetControl* ActiveControl = {read=FActiveControl};
	__property TCustomForm* ActiveCustomForm = {read=FActiveCustomForm};
	__property TForm* ActiveForm = {read=FActiveForm};
	__property Qt::QWidgetH* ActiveWidget = {read=GetActiveWidget};
	__property Qcontrols::TCursor Cursor = {read=FCursor, write=SetCursor, nodefault};
	__property Qt::QCursorH* Cursors[int Index] = {read=GetCursors, write=SetCursors};
	__property int CustomFormCount = {read=GetCustomFormCount, nodefault};
	__property TCustomForm* CustomForms[int Index] = {read=GetCustomForms};
	__property int DataModuleCount = {read=GetDataModuleCount, nodefault};
	__property Classes::TDataModule* DataModules[int Index] = {read=GetDataModule};
	__property Classes::TStrings* Fonts = {read=GetFonts};
	__property int FormCount = {read=GetFormCount, nodefault};
	__property TForm* Forms[int Index] = {read=GetForm};
	__property int Height = {read=GetHeight, nodefault};
	__property Qgraphics::TFont* HintFont = {read=GetHintFont, write=SetHintFont};
	__property int PixelsPerInch = {read=GetPixelsPerInch, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	__property Classes::TNotifyEvent OnActiveControlChange = {read=FOnActiveControlChange, write=FOnActiveControlChange};
	__property Classes::TNotifyEvent OnActiveFormChange = {read=FOnActiveFormChange, write=FOnActiveFormChange};
};


#pragma option push -b-
enum TTimerMode { tmShow, tmHide };
#pragma option pop

typedef void __fastcall (__closure *TEventEvent)(Qt::QObjectH* Sender, Qt::QEventH* Event, bool &Handled);

typedef void __fastcall (__closure *TExceptionEvent)(System::TObject* Sender, Sysutils::Exception* E);

typedef void __fastcall (__closure *TIdleEvent)(System::TObject* Sender, bool &Done);

#pragma option push -b-
enum TMessageButton { smbOK, smbCancel, smbYes, smbNo, smbAbort, smbRetry, smbIgnore };
#pragma option pop

typedef Set<TMessageButton, smbOK, smbIgnore>  TMessageButtons;

#pragma option push -b-
enum TMessageStyle { smsInformation, smsWarning, smsCritical };
#pragma option pop

typedef void __fastcall (__closure *TOnHelpEvent)(System::TObject* Sender);

class DELPHICLASS TApplication;
class PASCALIMPLEMENTATION TApplication : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Helpintfs::_di_IHelpSystem FHelpSystem;
	char * *FArgv;
	bool FTerminated;
	bool FActive;
	bool FShowMainForm;
	Qt::QApplicationH* FHandle;
	bool FHintShortCuts;
	Qt::QObject_hookH* FHooks;
	TExceptionEvent FOnException;
	TCustomForm* FMainForm;
	Qt::QWidgetH* FAppWidget;
	bool FQtAccels;
	WideString FTitle;
	WideString FHint;
	Qgraphics::TColor FHintColor;
	Qcontrols::TControl* FHintControl;
	#pragma pack(push, 1)
	Types::TRect FHintCursorRect;
	#pragma pack(pop)
	
	int FHintHidePause;
	int FHintPause;
	int FHintShortPause;
	Classes::TComponent* FHintTimer;
	TTimerMode FTimerMode;
	Qcontrols::THintWindow* FHintWindow;
	Classes::TComponent* FIdleTimer;
	Qcontrols::TControl* FMouseControl;
	Qgraphics::TPalette* FPalette;
	Qstyle::TApplicationStyle* FStyle;
	Qgraphics::TFont* FFont;
	TIdleEvent FOnIdle;
	Classes::TNotifyEvent FOnHint;
	Classes::TNotifyEvent FOnDeactivate;
	Classes::TNotifyEvent FOnActivate;
	TEventEvent FOnEvent;
	Qactnlist::TActionEvent FOnActionExecute;
	Qactnlist::TActionEvent FOnActionUpdate;
	TShortCutEvent FOnShortCut;
	Qcontrols::TShowHintEvent FOnShowHint;
	Classes::TNotifyEvent FOnModalBegin;
	Classes::TNotifyEvent FOnModalEnd;
	Qcontrols::TCursor FOldCursor;
	AnsiString FHelpFile;
	int FHelpKey;
	AnsiString FHelpKeyword;
	Classes::THelpContext FHelpContext;
	Classes::THelpType FHelpType;
	THelpEvent FOnHelp;
	Classes::TNotifyEvent FOnMinimize;
	Classes::TNotifyEvent FOnRestore;
	Classes::TList* FTopMostList;
	Qgraphics::TIcon* FIcon;
	int FTopMostLevel;
	int FModalLevel;
	bool FHintActive;
	bool FShowHint;
	bool FMinimized;
	bool FMainFormSet;
	Classes::TShiftState FKeyState;
	bool __fastcall ExecuteActionNotification(Classes::TBasicAction* Action);
	bool __fastcall UpdateActionNotification(Classes::TBasicAction* Action);
	Qcontrols::TControl* __fastcall DoMouseIdle(void);
	void __fastcall DoActionIdle(void);
	void __fastcall DoDeactivate(void);
	void __fastcall DoActivate(void);
	void __fastcall StyleChanged(System::TObject* Sender);
	void __fastcall PaletteChanged(System::TObject* Sender);
	void __fastcall SetHandle(const Qt::QApplicationH* Value);
	bool __cdecl EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	Qt::QWidgetH* __fastcall GetDesktop(void);
	Qgraphics::TFont* __fastcall GetFont(void);
	void __fastcall SetFont(Qgraphics::TFont* Value);
	void __fastcall InternalFontChanged(System::TObject* Sender);
	void __fastcall HintTimerExpired(void);
	void __fastcall LoadTranslator(void);
	void __fastcall SetTitle(const WideString Value);
	void __fastcall SetHint(const WideString Value);
	void __fastcall SetHintColor(Qgraphics::TColor Value);
	void __fastcall SetShowHint(bool Value);
	void __fastcall StartHintTimer(int Value, TTimerMode TimerMode);
	void __fastcall StopHintTimer(void);
	void __fastcall HintTimerProc(System::TObject* Sender);
	Qstyle::TApplicationStyle* __fastcall GetStyle(void);
	void __fastcall SetStyle(const Qstyle::TApplicationStyle* Value);
	void __fastcall Quit(void);
	void __fastcall UpdateVisible(void);
	AnsiString __fastcall GetCurrentHelpFile();
	AnsiString __fastcall GetExeName();
	void __fastcall SetIcon(const Qgraphics::TIcon* Value);
	Classes::TList* __fastcall GetTopMostList(void);
	bool __fastcall GetActiveState(void);
	Qt::QWidgetH* __fastcall GetAppWidget(void);
	void __fastcall WakeMainThread(System::TObject* Sender);
	
protected:
	__property Qt::QWidgetH* AppWidget = {read=GetAppWidget};
	void __fastcall CreateHandle(void);
	__property Qt::QObject_hookH* Hooks = {read=FHooks};
	virtual void __fastcall IconChanged(System::TObject* Sender);
	DYNAMIC void __fastcall Idle(System::TObject* Sender);
	void __fastcall SetHelpContext(const Classes::THelpContext Value);
	void __fastcall SetHelpKeyword(const AnsiString Value);
	bool __fastcall ValidateHelpSystem(void);
	__property Classes::TList* TopMostList = {read=GetTopMostList};
	
public:
	__fastcall virtual TApplication(Classes::TComponent* AOwner);
	__fastcall virtual ~TApplication(void);
	void __fastcall ActivateHint(const Types::TPoint &CursorPos);
	void __fastcall BringToFront(void);
	void __fastcall CancelHint(void);
	void __fastcall ControlDestroyed(Qcontrols::TControl* Control);
	void __fastcall CreateForm(TMetaClass* InstanceClass, void *Reference);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	void __fastcall HandleException(System::TObject* Sender);
	void __fastcall HandleMessage(void);
	void __fastcall HideHint(void);
	void __fastcall HintMouseMessage(Qcontrols::TControl* Control, Classes::TShiftState Shift, int X, int Y);
	void __fastcall HookSynchronizeWakeup(void);
	void __fastcall Initialize(void);
	bool __fastcall IsShortCut(int Key, Classes::TShiftState Shift, const WideString KeyText);
	void __fastcall InvokeHelp(void);
	bool __fastcall ContextHelp(const Classes::THelpContext HelpContext);
	bool __fastcall KeywordHelp(const AnsiString HelpKeyword);
	TMessageButton __fastcall MessageBox(const WideString Text, const WideString Caption = L"", TMessageButtons Buttons = (System::Set<TMessageButton, smbOK, smbIgnore> () << TMessageButton(0) ), TMessageStyle Style = (TMessageStyle)(0x0), TMessageButton Default = (TMessageButton)(0x0), TMessageButton Escape = (TMessageButton)(0x1));
	void __fastcall Minimize(void);
	void __fastcall ModalStarted(System::TObject* Sender);
	void __fastcall ModalFinished(System::TObject* Sender);
	void __fastcall NormalizeTopMosts(void);
	void __fastcall ProcessMessages(void);
	void __fastcall Restore(void);
	void __fastcall RestoreTopMosts(void);
	void __fastcall Run(void);
	void __fastcall ShowException(Sysutils::Exception* E);
	void __fastcall Terminate(void);
	void __fastcall UnhookSynchronizeWakeup(void);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property bool Active = {read=FActive, nodefault};
	__property AnsiString CurrentHelpFile = {read=GetCurrentHelpFile};
	__property Qt::QWidgetH* Desktop = {read=GetDesktop};
	__property bool EnableQtAccelerators = {read=FQtAccels, write=FQtAccels, nodefault};
	__property AnsiString ExeName = {read=GetExeName};
	__property Qgraphics::TFont* Font = {read=GetFont, write=SetFont};
	__property Qt::QApplicationH* Handle = {read=FHandle, write=SetHandle};
	__property AnsiString HelpFile = {read=FHelpFile, write=FHelpFile};
	__property int HelpKey = {read=FHelpKey, write=FHelpKey, default=4144};
	__property Helpintfs::_di_IHelpSystem HelpSystem = {read=FHelpSystem};
	__property AnsiString HelpWord = {read=FHelpKeyword, write=SetHelpKeyword};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, nodefault};
	__property Classes::THelpType HelpType = {read=FHelpType, write=FHelpType, nodefault};
	__property WideString Hint = {read=FHint, write=SetHint};
	__property Qgraphics::TColor HintColor = {read=FHintColor, write=SetHintColor, nodefault};
	__property int HintHidePause = {read=FHintHidePause, write=FHintHidePause, nodefault};
	__property int HintPause = {read=FHintPause, write=FHintPause, nodefault};
	__property bool HintShortCuts = {read=FHintShortCuts, write=FHintShortCuts, nodefault};
	__property int HintShortPause = {read=FHintShortPause, write=FHintShortPause, nodefault};
	__property Qgraphics::TIcon* Icon = {read=FIcon, write=SetIcon};
	__property Classes::TShiftState KeyState = {read=FKeyState, nodefault};
	__property TCustomForm* MainForm = {read=FMainForm};
	__property Qgraphics::TPalette* Palette = {read=FPalette};
	__property bool ShowHint = {read=FShowHint, write=SetShowHint, default=1};
	__property bool ShowMainForm = {read=FShowMainForm, write=FShowMainForm, nodefault};
	__property Qstyle::TApplicationStyle* Style = {read=GetStyle, write=SetStyle};
	__property bool Terminated = {read=FTerminated, nodefault};
	__property WideString Title = {read=FTitle, write=SetTitle};
	__property Qactnlist::TActionEvent OnActionExecute = {read=FOnActionExecute, write=FOnActionExecute};
	__property Qactnlist::TActionEvent OnActionUpdate = {read=FOnActionUpdate, write=FOnActionUpdate};
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property TEventEvent OnEvent = {read=FOnEvent, write=FOnEvent};
	__property TExceptionEvent OnException = {read=FOnException, write=FOnException};
	__property THelpEvent OnHelp = {read=FOnHelp, write=FOnHelp};
	__property Classes::TNotifyEvent OnHint = {read=FOnHint, write=FOnHint};
	__property TIdleEvent OnIdle = {read=FOnIdle, write=FOnIdle};
	__property Classes::TNotifyEvent OnMinimize = {read=FOnMinimize, write=FOnMinimize};
	__property Classes::TNotifyEvent OnModalBegin = {read=FOnModalBegin, write=FOnModalBegin};
	__property Classes::TNotifyEvent OnModalEnd = {read=FOnModalEnd, write=FOnModalEnd};
	__property Classes::TNotifyEvent OnRestore = {read=FOnRestore, write=FOnRestore};
	__property Qcontrols::TShowHintEvent OnShowHint = {read=FOnShowHint, write=FOnShowHint};
	__property TShortCutEvent OnShortCut = {read=FOnShortCut, write=FOnShortCut};
};


typedef void __fastcall (*TFormWidgetCreatedHook)(TCustomForm* Form);

//-- var, const, procedure ---------------------------------------------------
#define QEventType_CMDestroyWidget (Qt::QEventType)(1001)
#define QEventType_CMQuit (Qt::QEventType)(1002)
#define QEventType_CMRelease (Qt::QEventType)(1003)
#define QEventType_CMScrolled (Qt::QEventType)(1004)
extern PACKAGE TApplication* Application;
extern PACKAGE TScreen* Screen;
extern PACKAGE Qcontrols::TMouse* Mouse;
extern PACKAGE TMetaClass*HintWindowClass;
extern PACKAGE TFormWidgetCreatedHook FormWidgetCreatedHook;
extern PACKAGE TCustomForm* __fastcall GetParentForm(Qcontrols::TControl* Control);
extern PACKAGE TCustomForm* __fastcall ValidParentForm(Qcontrols::TControl* Control);
extern PACKAGE bool __fastcall IsAccel(Word VK, const WideString Str);

}	/* namespace Qforms */
using namespace Qforms;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QForms
