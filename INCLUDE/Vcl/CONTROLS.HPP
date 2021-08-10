// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Controls.pas' rev: 6.00

#ifndef ControlsHPP
#define ControlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Imm.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <MultiMon.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Controls
{
#pragma option -b-
  enum TCursor {crMin=-32768, crMax=32767};
#pragma option -b.
}
namespace Controls
{
    typedef System::TDateTime TDate;
    typedef System::TDateTime TTime;
}

namespace Controls
{
//-- type declarations -------------------------------------------------------
typedef int TModalResult;

typedef TMetaClass*TWinControlClass;

typedef Messages::TWMNoParams  TCMActivate;

typedef Messages::TWMNoParams  TCMDeactivate;

typedef Messages::TWMNoParams  TCMGotFocus;

typedef Messages::TWMNoParams  TCMLostFocus;

typedef Messages::TWMKey  TCMDialogKey;

typedef Messages::TWMKey  TCMDialogChar;

typedef Messages::TWMNCHitTest  TCMHitTest;

typedef Messages::TWMNoParams  TCMEnter;

typedef Messages::TWMNoParams  TCMExit;

typedef Messages::TWMMouse  TCMDesignHitTest;

typedef Messages::TWMKey  TCMWantSpecialKey;

#pragma pack(push, 4)
struct TCMMouseWheel
{
	unsigned Msg;
	Classes::TShiftState ShiftState;
	Byte Unused;
	short WheelDelta;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

class DELPHICLASS TControl;
class DELPHICLASS TWinControl;
#pragma option push -b-
enum Controls__11 { csAcceptsControls, csCaptureMouse, csDesignInteractive, csClickEvents, csFramed, csSetCaption, csOpaque, csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible, csReplicatable, csNoStdEvents, csDisplayDragImage, csReflector, csActionClient, csMenuEvents };
#pragma option pop

typedef Set<Controls__11, csAcceptsControls, csMenuEvents>  TControlStyle;

#pragma option push -b-
enum Controls__01 { csLButtonDown, csClicked, csPalette, csReadingState, csAlignmentNeeded, csFocusing, csCreating, csPaintCopy, csCustomPaint, csDestroyingHandle, csDocking };
#pragma option pop

typedef Set<Controls__01, csLButtonDown, csDocking>  TControlState;

#pragma option push -b-
enum TAlign { alNone, alTop, alBottom, alLeft, alRight, alClient, alCustom };
#pragma option pop

#pragma option push -b-
enum TDragMode { dmManual, dmAutomatic };
#pragma option pop

#pragma option push -b-
enum TAnchorKind { akLeft, akTop, akRight, akBottom };
#pragma option pop

typedef Set<TAnchorKind, akLeft, akBottom>  TAnchors;

class DELPHICLASS TControlActionLink;
class PASCALIMPLEMENTATION TControlActionLink : public Actnlist::TActionLink 
{
	typedef Actnlist::TActionLink inherited;
	
protected:
	TControl* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHelpLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual bool __fastcall DoShowHint(AnsiString &HintStr);
	virtual void __fastcall SetCaption(const AnsiString Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHint(const AnsiString Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall SetHelpType(Classes::THelpType Value);
	virtual void __fastcall SetVisible(bool Value);
	virtual void __fastcall SetOnExecute(Classes::TNotifyEvent Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TControlActionLink(System::TObject* AClient) : Actnlist::TActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TControlActionLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSizeConstraints;
typedef int TConstraintSize;

class PASCALIMPLEMENTATION TSizeConstraints : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TControl* FControl;
	TConstraintSize FMaxHeight;
	TConstraintSize FMaxWidth;
	TConstraintSize FMinHeight;
	TConstraintSize FMinWidth;
	Classes::TNotifyEvent FOnChange;
	void __fastcall SetConstraints(int Index, TConstraintSize Value);
	
protected:
	virtual void __fastcall Change(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	__property TControl* Control = {read=FControl};
	
public:
	__fastcall virtual TSizeConstraints(TControl* Control);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property TConstraintSize MaxHeight = {read=FMaxHeight, write=SetConstraints, index=0, default=0};
	__property TConstraintSize MaxWidth = {read=FMaxWidth, write=SetConstraints, index=1, default=0};
	__property TConstraintSize MinHeight = {read=FMinHeight, write=SetConstraints, index=2, default=0};
	__property TConstraintSize MinWidth = {read=FMinWidth, write=SetConstraints, index=3, default=0};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TSizeConstraints(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum Controls__21 { sfLeft, sfTop, sfWidth, sfHeight, sfFont, sfDesignSize };
#pragma option pop

typedef Set<Controls__21, sfLeft, sfDesignSize>  TScalingFlags;

#pragma option push -b-
enum TDragKind { dkDrag, dkDock };
#pragma option pop

#pragma option push -b-
enum TDockOrientation { doNoOrient, doHorizontal, doVertical };
#pragma option pop

typedef void __fastcall (__closure *TCanResizeEvent)(System::TObject* Sender, int &NewWidth, int &NewHeight, bool &Resize);

typedef void __fastcall (__closure *TConstrainedResizeEvent)(System::TObject* Sender, int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);

#pragma option push -b-
enum TMouseButton { mbLeft, mbRight, mbMiddle };
#pragma option pop

typedef void __fastcall (__closure *TMouseEvent)(System::TObject* Sender, TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TMouseMoveEvent)(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TDragDropEvent)(System::TObject* Sender, System::TObject* Source, int X, int Y);

#pragma option push -b-
enum TDragState { dsDragEnter, dsDragLeave, dsDragMove };
#pragma option pop

typedef void __fastcall (__closure *TDragOverEvent)(System::TObject* Sender, System::TObject* Source, int X, int Y, TDragState State, bool &Accept);

class DELPHICLASS TDragDockObject;
typedef void __fastcall (__closure *TStartDockEvent)(System::TObject* Sender, TDragDockObject* &DragObject);

typedef void __fastcall (__closure *TEndDragEvent)(System::TObject* Sender, System::TObject* Target, int X, int Y);

class DELPHICLASS TDragObject;
typedef void __fastcall (__closure *TStartDragEvent)(System::TObject* Sender, TDragObject* &DragObject);

typedef void __fastcall (__closure *TContextPopupEvent)(System::TObject* Sender, const Types::TPoint &MousePos, bool &Handled);

typedef void __fastcall (__closure *TMouseWheelEvent)(System::TObject* Sender, Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos, bool &Handled);

typedef void __fastcall (__closure *TMouseWheelUpDownEvent)(System::TObject* Sender, Classes::TShiftState Shift, const Types::TPoint &MousePos, bool &Handled);

struct TCMDrag;
typedef AnsiString TCaption;

struct TCMFloat;
typedef TMetaClass*TControlActionLinkClass;

class DELPHICLASS TDragImageList;
class PASCALIMPLEMENTATION TControl : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWinControl* FParent;
	Classes::TWndMethod FWindowProc;
	int FLeft;
	int FTop;
	int FWidth;
	int FHeight;
	TControlStyle FControlStyle;
	TControlState FControlState;
	bool FDesktopFont;
	bool FVisible;
	bool FEnabled;
	bool FParentFont;
	bool FParentColor;
	TAlign FAlign;
	bool FAutoSize;
	TDragMode FDragMode;
	bool FIsControl;
	Classes::TBiDiMode FBiDiMode;
	bool FParentBiDiMode;
	TAnchors FAnchors;
	bool FAnchorMove;
	char *FText;
	Graphics::TFont* FFont;
	TControlActionLink* FActionLink;
	Graphics::TColor FColor;
	TSizeConstraints* FConstraints;
	TCursor FCursor;
	TCursor FDragCursor;
	Menus::TPopupMenu* FPopupMenu;
	AnsiString FHint;
	int FFontHeight;
	#pragma pack(push, 1)
	Types::TPoint FAnchorRules;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FOriginalParentSize;
	#pragma pack(pop)
	
	TScalingFlags FScalingFlags;
	bool FShowHint;
	bool FParentShowHint;
	TDragKind FDragKind;
	TDockOrientation FDockOrientation;
	TWinControl* FHostDockSite;
	int FWheelAccumulator;
	int FUndockWidth;
	int FUndockHeight;
	int FLRDockWidth;
	int FTBDockHeight;
	TMetaClass*FFloatingDockSiteClass;
	TCanResizeEvent FOnCanResize;
	TConstrainedResizeEvent FOnConstrainedResize;
	TMouseEvent FOnMouseDown;
	TMouseMoveEvent FOnMouseMove;
	TMouseEvent FOnMouseUp;
	TDragDropEvent FOnDragDrop;
	TDragOverEvent FOnDragOver;
	Classes::TNotifyEvent FOnResize;
	TStartDockEvent FOnStartDock;
	TEndDragEvent FOnEndDock;
	TStartDragEvent FOnStartDrag;
	TEndDragEvent FOnEndDrag;
	Classes::TNotifyEvent FOnClick;
	Classes::TNotifyEvent FOnDblClick;
	TContextPopupEvent FOnContextPopup;
	TMouseWheelEvent FOnMouseWheel;
	TMouseWheelUpDownEvent FOnMouseWheelDown;
	TMouseWheelUpDownEvent FOnMouseWheelUp;
	Classes::THelpType FHelpType;
	AnsiString FHelpKeyword;
	Classes::THelpContext FHelpContext;
	void __fastcall CalcDockSizes(void);
	bool __fastcall CheckNewSize(int &NewWidth, int &NewHeight);
	TWinControl* __fastcall CreateFloatingDockSite(const Types::TRect &Bounds);
	void __fastcall DoActionChange(System::TObject* Sender);
	bool __fastcall DoCanAutoSize(int &NewWidth, int &NewHeight);
	bool __fastcall DoCanResize(int &NewWidth, int &NewHeight);
	void __fastcall DoConstraintsChange(System::TObject* Sender);
	void __fastcall DoConstrainedResize(int &NewWidth, int &NewHeight);
	void __fastcall DoDragMsg(TCMDrag &DragMsg);
	void __fastcall DoMouseDown(Messages::TWMMouse &Message, TMouseButton Button, Classes::TShiftState Shift);
	void __fastcall DoMouseUp(Messages::TWMMouse &Message, TMouseButton Button);
	void __fastcall FontChanged(System::TObject* Sender);
	Types::TRect __fastcall GetBoundsRect();
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	int __fastcall GetLRDockWidth(void);
	bool __fastcall GetMouseCapture(void);
	AnsiString __fastcall GetText();
	int __fastcall GetTBDockHeight(void);
	int __fastcall GetUndockWidth(void);
	int __fastcall GetUndockHeight(void);
	void __fastcall InvalidateControl(bool IsVisible, bool IsOpaque);
	bool __fastcall IsAnchorsStored(void);
	bool __fastcall IsBiDiModeStored(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsHelpContextStored(void);
	bool __fastcall IsOnClickStored(void);
	bool __fastcall IsShowHintStored(void);
	bool __fastcall IsVisibleStored(void);
	void __fastcall ReadIsControl(Classes::TReader* Reader);
	void __fastcall SetAnchors(TAnchors Value);
	void __fastcall SetAction(Classes::TBasicAction* Value);
	void __fastcall SetAlign(TAlign Value);
	void __fastcall SetBoundsRect(const Types::TRect &Rect);
	void __fastcall SetClientHeight(int Value);
	void __fastcall SetClientSize(const Types::TPoint &Value);
	void __fastcall SetClientWidth(int Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetCursor(TCursor Value);
	void __fastcall SetDesktopFont(bool Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetHelpContext(const Classes::THelpContext Value);
	void __fastcall SetHelpKeyword(const AnsiString Value);
	void __fastcall SetHostDockSite(TWinControl* Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetMouseCapture(bool Value);
	void __fastcall SetParentColor(bool Value);
	void __fastcall SetParentFont(bool Value);
	void __fastcall SetShowHint(bool Value);
	void __fastcall SetParentShowHint(bool Value);
	void __fastcall SetPopupMenu(Menus::TPopupMenu* Value);
	void __fastcall SetText(const AnsiString Value);
	void __fastcall SetTop(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(int Value);
	void __fastcall SetZOrderPosition(int Position);
	void __fastcall UpdateAnchorRules(void);
	void __fastcall WriteIsControl(Classes::TWriter* Writer);
	MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMNCLButtonDown(Messages::TWMNCHitMessage &Message);
	MESSAGE void __fastcall WMRButtonDown(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMMButtonDown(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMRButtonDblClk(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMMButtonDblClk(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMMouseMove(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMLButtonUp(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMRButtonUp(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMMButtonUp(Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMMouseWheel(Messages::TWMMouseWheel &Message);
	MESSAGE void __fastcall WMCancelMode(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMSysFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentShowHintChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMHintShow(Messages::TMessage &Message);
	MESSAGE void __fastcall CMHitTest(Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	MESSAGE void __fastcall CMFloat(TCMFloat &Message);
	MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentBiDiModeChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMMouseWheel(TCMMouseWheel &Message);
	MESSAGE void __fastcall WMContextMenu(Messages::TWMContextMenu &Message);
	void __fastcall SetConstraints(const TSizeConstraints* Value);
	
protected:
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	DYNAMIC void __fastcall AdjustSize(void);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	DYNAMIC void __fastcall BeginAutoDrag(void);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	void __fastcall Changed(void);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall ConstrainedResize(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
	Types::TPoint __fastcall CalcCursorPos();
	DYNAMIC bool __fastcall DesignWndProc(Messages::TMessage &Message);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DefaultDockImage(TDragDockObject* DragDockObject, bool Erase);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall DockTrackNoTarget(TDragDockObject* Source, int X, int Y);
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	DYNAMIC void __fastcall DoEndDock(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoDock(TWinControl* NewDockSite, Types::TRect &ARect);
	DYNAMIC void __fastcall DoStartDock(TDragObject* &DragObject);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC void __fastcall DragCanceled(void);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, TDragState State, bool &Accept);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(TDragObject* &DragObject);
	DYNAMIC void __fastcall DrawDragDockImage(TDragDockObject* DragDockObject);
	DYNAMIC void __fastcall EraseDragDockImage(TDragDockObject* DragDockObject);
	virtual Classes::TBasicAction* __fastcall GetAction(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual Types::TRect __fastcall GetClientRect();
	virtual HDC __fastcall GetDeviceContext(HWND &WindowHandle);
	DYNAMIC TAlign __fastcall GetDockEdge(const Types::TPoint &MousePos);
	virtual TDragImageList* __fastcall GetDragImages(void);
	virtual bool __fastcall GetEnabled(void);
	virtual bool __fastcall GetFloating(void);
	virtual TMetaClass* __fastcall GetFloatingDockSiteClass(void);
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	DYNAMIC Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall PositionDockRect(TDragDockObject* DragDockObject);
	DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall Resize(void);
	void __fastcall SendCancelMode(TControl* Sender);
	void __fastcall SendDockNotification(unsigned Msg, int WParam, int LParam);
	virtual void __fastcall SetAutoSize(bool Value);
	virtual void __fastcall SetDragMode(TDragMode Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetName(const AnsiString Value);
	virtual void __fastcall SetParent(TWinControl* AParent);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
	virtual void __fastcall SetParentBiDiMode(bool Value);
	virtual void __fastcall SetBiDiMode(Classes::TBiDiMode Value);
	DYNAMIC void __fastcall SetZOrder(bool TopMost);
	void __fastcall UpdateBoundsRect(const Types::TRect &R);
	DYNAMIC void __fastcall VisibleChanging(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property TControlActionLink* ActionLink = {read=FActionLink, write=FActionLink};
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property AnsiString Caption = {read=GetText, write=SetText, stored=IsCaptionStored};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, default=-2147483643};
	__property bool DesktopFont = {read=FDesktopFont, write=SetDesktopFont, default=0};
	__property TDragKind DragKind = {read=FDragKind, write=FDragKind, default=0};
	__property TCursor DragCursor = {read=FDragCursor, write=FDragCursor, default=-12};
	__property TDragMode DragMode = {read=FDragMode, write=SetDragMode, default=0};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property bool IsControl = {read=FIsControl, write=FIsControl, nodefault};
	__property bool MouseCapture = {read=GetMouseCapture, write=SetMouseCapture, nodefault};
	__property bool ParentBiDiMode = {read=FParentBiDiMode, write=SetParentBiDiMode, default=1};
	__property bool ParentColor = {read=FParentColor, write=SetParentColor, default=1};
	__property bool ParentFont = {read=FParentFont, write=SetParentFont, default=1};
	__property bool ParentShowHint = {read=FParentShowHint, write=SetParentShowHint, default=1};
	__property Menus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property TScalingFlags ScalingFlags = {read=FScalingFlags, write=FScalingFlags, nodefault};
	__property AnsiString Text = {read=GetText, write=SetText};
	__property int WheelAccumulator = {read=FWheelAccumulator, write=FWheelAccumulator, nodefault};
	__property char * WindowText = {read=FText, write=FText};
	__property TCanResizeEvent OnCanResize = {read=FOnCanResize, write=FOnCanResize};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
	__property TConstrainedResizeEvent OnConstrainedResize = {read=FOnConstrainedResize, write=FOnConstrainedResize};
	__property TContextPopupEvent OnContextPopup = {read=FOnContextPopup, write=FOnContextPopup};
	__property Classes::TNotifyEvent OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property TDragDropEvent OnDragDrop = {read=FOnDragDrop, write=FOnDragDrop};
	__property TDragOverEvent OnDragOver = {read=FOnDragOver, write=FOnDragOver};
	__property TEndDragEvent OnEndDock = {read=FOnEndDock, write=FOnEndDock};
	__property TEndDragEvent OnEndDrag = {read=FOnEndDrag, write=FOnEndDrag};
	__property TMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property TMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
	__property TMouseWheelEvent OnMouseWheel = {read=FOnMouseWheel, write=FOnMouseWheel};
	__property TMouseWheelUpDownEvent OnMouseWheelDown = {read=FOnMouseWheelDown, write=FOnMouseWheelDown};
	__property TMouseWheelUpDownEvent OnMouseWheelUp = {read=FOnMouseWheelUp, write=FOnMouseWheelUp};
	__property Classes::TNotifyEvent OnResize = {read=FOnResize, write=FOnResize};
	__property TStartDockEvent OnStartDock = {read=FOnStartDock, write=FOnStartDock};
	__property TStartDragEvent OnStartDrag = {read=FOnStartDrag, write=FOnStartDrag};
	
public:
	__fastcall virtual TControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TControl(void);
	void __fastcall BeginDrag(bool Immediate, int Threshold = 0xffffffff);
	void __fastcall BringToFront(void);
	Types::TPoint __fastcall ClientToScreen(const Types::TPoint &Point);
	Types::TPoint __fastcall ClientToParent(const Types::TPoint &Point, TWinControl* AParent = (TWinControl*)(0x0));
	DYNAMIC void __fastcall Dock(TWinControl* NewDockSite, const Types::TRect &ARect);
	virtual void __fastcall DefaultHandler(void *Message);
	bool __fastcall Dragging(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	int __fastcall DrawTextBiDiModeFlags(int Flags);
	int __fastcall DrawTextBiDiModeFlagsReadingOnly(void);
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	void __fastcall EndDrag(bool Drop);
	DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	int __fastcall GetTextBuf(char * Buffer, int BufSize);
	int __fastcall GetTextLen(void);
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall Hide(void);
	virtual void __fastcall InitiateAction(void);
	virtual void __fastcall Invalidate(void);
	DYNAMIC void __fastcall MouseWheelHandler(Messages::TMessage &Message);
	bool __fastcall IsRightToLeft(void);
	bool __fastcall ManualDock(TWinControl* NewDockSite, TControl* DropControl = (TControl*)(0x0), TAlign ControlSide = (TAlign)(0x0));
	bool __fastcall ManualFloat(const Types::TRect &ScreenPos);
	int __fastcall Perform(unsigned Msg, int WParam, int LParam);
	void __fastcall Refresh(void);
	virtual void __fastcall Repaint(void);
	bool __fastcall ReplaceDockedControl(TControl* Control, TWinControl* NewDockSite, TControl* DropControl, TAlign ControlSide);
	Types::TPoint __fastcall ScreenToClient(const Types::TPoint &Point);
	Types::TPoint __fastcall ParentToClient(const Types::TPoint &Point, TWinControl* AParent = (TWinControl*)(0x0));
	void __fastcall SendToBack(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall SetTextBuf(char * Buffer);
	void __fastcall Show(void);
	virtual void __fastcall Update(void);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	bool __fastcall UseRightToLeftReading(void);
	bool __fastcall UseRightToLeftScrollBar(void);
	__property Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property TAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property TAnchors Anchors = {read=FAnchors, write=SetAnchors, stored=IsAnchorsStored, default=3};
	__property Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored, nodefault};
	__property Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property int ClientHeight = {read=GetClientHeight, write=SetClientHeight, stored=false, nodefault};
	__property Types::TPoint ClientOrigin = {read=GetClientOrigin};
	__property Types::TRect ClientRect = {read=GetClientRect};
	__property int ClientWidth = {read=GetClientWidth, write=SetClientWidth, stored=false, nodefault};
	__property TSizeConstraints* Constraints = {read=FConstraints, write=SetConstraints};
	__property TControlState ControlState = {read=FControlState, write=FControlState, nodefault};
	__property TControlStyle ControlStyle = {read=FControlStyle, write=FControlStyle, nodefault};
	__property TDockOrientation DockOrientation = {read=FDockOrientation, write=FDockOrientation, nodefault};
	__property bool Floating = {read=GetFloating, nodefault};
	__property TMetaClass* FloatingDockSiteClass = {read=GetFloatingDockSiteClass, write=FFloatingDockSiteClass};
	__property TWinControl* HostDockSite = {read=FHostDockSite, write=SetHostDockSite};
	__property int LRDockWidth = {read=GetLRDockWidth, write=FLRDockWidth, nodefault};
	__property TWinControl* Parent = {read=FParent, write=SetParent};
	__property bool ShowHint = {read=FShowHint, write=SetShowHint, stored=IsShowHintStored, nodefault};
	__property int TBDockHeight = {read=GetTBDockHeight, write=FTBDockHeight, nodefault};
	__property int UndockHeight = {read=GetUndockHeight, write=FUndockHeight, nodefault};
	__property int UndockWidth = {read=GetUndockWidth, write=FUndockWidth, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property Classes::TWndMethod WindowProc = {read=FWindowProc, write=FWindowProc};
	
__published:
	__property int Left = {read=FLeft, write=SetLeft, nodefault};
	__property int Top = {read=FTop, write=SetTop, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property TCursor Cursor = {read=FCursor, write=SetCursor, default=0};
	__property AnsiString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property Classes::THelpType HelpType = {read=FHelpType, write=FHelpType, default=1};
	__property AnsiString HelpKeyword = {read=FHelpKeyword, write=SetHelpKeyword, stored=IsHelpContextStored};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, stored=IsHelpContextStored, default=0};
};


#pragma option push -b-
enum TBevelEdge { beLeft, beTop, beRight, beBottom };
#pragma option pop

typedef Set<TBevelEdge, beLeft, beBottom>  TBevelEdges;

#pragma option push -b-
enum TBevelCut { bvNone, bvLowered, bvRaised, bvSpace };
#pragma option pop

#pragma option push -b-
enum TBevelKind { bkNone, bkTile, bkSoft, bkFlat };
#pragma option pop

typedef int TBevelWidth;

typedef int TBorderWidth;

__interface IDockManager;
typedef System::DelphiInterface<IDockManager> _di_IDockManager;
__interface INTERFACE_UUID("{8619FD79-C281-11D1-AA60-00C04FA370E8}") IDockManager  : public IInterface 
{
	
public:
	virtual void __fastcall BeginUpdate(void) = 0 ;
	virtual void __fastcall EndUpdate(void) = 0 ;
	virtual void __fastcall GetControlBounds(TControl* Control, /* out */ Types::TRect &CtlBounds) = 0 ;
	virtual void __fastcall InsertControl(TControl* Control, TAlign InsertAt, TControl* DropCtl) = 0 ;
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall PaintSite(HDC DC) = 0 ;
	virtual void __fastcall PositionDockRect(TControl* Client, TControl* DropCtl, TAlign DropAlign, Types::TRect &DockRect) = 0 ;
	virtual void __fastcall RemoveControl(TControl* Control) = 0 ;
	virtual void __fastcall ResetBounds(bool Force) = 0 ;
	virtual void __fastcall SaveToStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall SetReplacingControl(TControl* Control) = 0 ;
};

#pragma option push -b-
enum TImeMode { imDisable, imClose, imOpen, imDontCare, imSAlpha, imAlpha, imHira, imSKata, imKata, imChinese, imSHanguel, imHanguel };
#pragma option pop

typedef AnsiString TImeName;

typedef void __fastcall (__closure *TDockDropEvent)(System::TObject* Sender, TDragDockObject* Source, int X, int Y);

typedef void __fastcall (__closure *TDockOverEvent)(System::TObject* Sender, TDragDockObject* Source, int X, int Y, TDragState State, bool &Accept);

typedef void __fastcall (__closure *TGetSiteInfoEvent)(System::TObject* Sender, TControl* DockClient, Types::TRect &InfluenceRect, const Types::TPoint &MousePos, bool &CanDock);

typedef void __fastcall (__closure *TKeyEvent)(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);

typedef void __fastcall (__closure *TKeyPressEvent)(System::TObject* Sender, char &Key);

typedef void __fastcall (__closure *TUnDockEvent)(System::TObject* Sender, TControl* Client, TWinControl* NewTarget, bool &Allow);

typedef short TTabOrder;

struct TCMFocusChanged;
struct TCMDockClient;
struct TCMUnDockClient;
struct TCreateParams;
struct TAlignInfo;
class PASCALIMPLEMENTATION TWinControl : public TControl 
{
	typedef TControl inherited;
	
private:
	Word FAlignLevel;
	TBevelEdges FBevelEdges;
	TBevelCut FBevelInner;
	TBevelCut FBevelOuter;
	TBevelKind FBevelKind;
	TBevelWidth FBevelWidth;
	TBorderWidth FBorderWidth;
	Graphics::TBrush* FBrush;
	void *FDefWndProc;
	Classes::TList* FDockClients;
	_di_IDockManager FDockManager;
	HWND FHandle;
	TImeMode FImeMode;
	AnsiString FImeName;
	void *FObjectInstance;
	HWND FParentWindow;
	Classes::TList* FTabList;
	Classes::TList* FControls;
	Classes::TList* FWinControls;
	int FTabOrder;
	bool FTabStop;
	bool FCtl3D;
	bool FShowing;
	bool FUseDockManager;
	bool FDockSite;
	bool FParentCtl3D;
	TDockDropEvent FOnDockDrop;
	TDockOverEvent FOnDockOver;
	Classes::TNotifyEvent FOnEnter;
	Classes::TNotifyEvent FOnExit;
	TGetSiteInfoEvent FOnGetSiteInfo;
	TKeyEvent FOnKeyDown;
	TKeyPressEvent FOnKeyPress;
	TKeyEvent FOnKeyUp;
	TUnDockEvent FOnUnDock;
	void __fastcall AlignControl(TControl* AControl);
	void __fastcall CalcConstraints(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
	bool __fastcall GetAlignDisabled(void);
	TControl* __fastcall GetControl(int Index);
	int __fastcall GetControlCount(void);
	int __fastcall GetDockClientCount(void);
	TControl* __fastcall GetDockClients(int Index);
	HWND __fastcall GetHandle(void);
	TTabOrder __fastcall GetTabOrder(void);
	int __fastcall GetVisibleDockClientCount(void);
	HIDESBASE void __fastcall Insert(TControl* AControl);
	void __fastcall InvalidateFrame(void);
	void __fastcall InvokeHelp(void);
	bool __fastcall IsCtl3DStored(void);
	HWND __fastcall PrecedingWindow(TWinControl* Control);
	void __fastcall ReadDesignSize(Classes::TReader* Reader);
	HIDESBASE void __fastcall Remove(TControl* AControl);
	void __fastcall RemoveFocus(bool Removing);
	void __fastcall SetBevelCut(int Index, const TBevelCut Value);
	void __fastcall SetBevelEdges(const TBevelEdges Value);
	void __fastcall SetBevelKind(const TBevelKind Value);
	void __fastcall SetBevelWidth(const TBevelWidth Value);
	void __fastcall SetBorderWidth(TBorderWidth Value);
	void __fastcall SetCtl3D(bool Value);
	void __fastcall SetDockSite(bool Value);
	void __fastcall SetParentCtl3D(bool Value);
	void __fastcall SetParentWindow(HWND Value);
	void __fastcall SetTabOrder(TTabOrder Value);
	void __fastcall SetTabStop(bool Value);
	void __fastcall SetUseDockManager(bool Value);
	HIDESBASE void __fastcall SetZOrderPosition(int Position);
	void __fastcall UpdateTabOrder(TTabOrder Value);
	void __fastcall UpdateBounds(void);
	void __fastcall UpdateShowing(void);
	void __fastcall WriteDesignSize(Classes::TWriter* Writer);
	bool __fastcall IsMenuKey(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	MESSAGE void __fastcall WMCommand(Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMNotify(Messages::TWMNotify &Message);
	MESSAGE void __fastcall WMSysColorChange(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMHScroll(Messages::TWMScroll &Message);
	MESSAGE void __fastcall WMVScroll(Messages::TWMScroll &Message);
	MESSAGE void __fastcall WMCompareItem(Messages::TWMCompareItem &Message);
	MESSAGE void __fastcall WMDeleteItem(Messages::TWMDeleteItem &Message);
	MESSAGE void __fastcall WMDrawItem(Messages::TWMDrawItem &Message);
	MESSAGE void __fastcall WMMeasureItem(Messages::TWMMeasureItem &Message);
	MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall WMWindowPosChanging(Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	MESSAGE void __fastcall WMMove(Messages::TWMMove &Message);
	MESSAGE void __fastcall WMSetCursor(Messages::TWMSetCursor &Message);
	MESSAGE void __fastcall WMKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMSysKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMKeyUp(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMSysKeyUp(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall WMSysCommand(Messages::TWMSysCommand &Message);
	MESSAGE void __fastcall WMCharToItem(Messages::TWMCharToItem &Message);
	MESSAGE void __fastcall WMParentNotify(Messages::TWMParentNotify &Message);
	MESSAGE void __fastcall WMVKeyToItem(Messages::TWMCharToItem &Message);
	MESSAGE void __fastcall WMDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMNCCalcSize(Messages::TWMNCCalcSize &Message);
	MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall WMNCPaint(Messages::TMessage &Message);
	MESSAGE void __fastcall WMQueryNewPalette(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPaletteChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall WMWinIniChange(Messages::TMessage &Message);
	MESSAGE void __fastcall WMFontChange(Messages::TMessage &Message);
	MESSAGE void __fastcall WMTimeChange(Messages::TMessage &Message);
	MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMKillFocus(Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMIMEStartComp(Messages::TMessage &Message);
	MESSAGE void __fastcall WMIMEEndComp(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMContextMenu(Messages::TWMContextMenu &Message);
	MESSAGE void __fastcall CMChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMChildKey(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDialogKey(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMFocusChanged(TCMFocusChanged &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMBorderChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMCursorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentCtl3DChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowHintChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMWinIniChange(Messages::TWMWinIniChange &Message);
	MESSAGE void __fastcall CMFontChange(Messages::TMessage &Message);
	MESSAGE void __fastcall CMTimeChange(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDrag(TCMDrag &Message);
	MESSAGE void __fastcall CNKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNKeyUp(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNSysKeyDown(Messages::TWMKey &Message);
	MESSAGE void __fastcall CNSysChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMControlListChange(Messages::TMessage &Message);
	MESSAGE void __fastcall CMRecreateWnd(Messages::TMessage &Message);
	MESSAGE void __fastcall CMInvalidate(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDockClient(TCMDockClient &Message);
	MESSAGE void __fastcall CMUnDockClient(TCMUnDockClient &Message);
	HIDESBASE MESSAGE void __fastcall CMFloat(TCMFloat &Message);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Messages::TMessage &Message);
	
protected:
	bool FDoubleBuffered;
	bool FInImeComposition;
	#pragma pack(push, 1)
	Types::TPoint FDesignSize;
	#pragma pack(pop)
	
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	void __fastcall AddBiDiModeExStyle(unsigned &ExStyle);
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	DYNAMIC void __fastcall AdjustSize(void);
	virtual void __fastcall AlignControls(TControl* AControl, Types::TRect &Rect);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall ConstrainedResize(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
	DYNAMIC void __fastcall ControlsAligned(void);
	DYNAMIC _di_IDockManager __fastcall CreateDockManager();
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(TCreateParams &Params);
	void __fastcall CreateSubClass(TCreateParams &Params, char * ControlClassName);
	virtual void __fastcall CreateWindowHandle(const TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall CustomAlignInsertBefore(TControl* C1, TControl* C2);
	virtual void __fastcall CustomAlignPosition(TControl* Control, int &NewLeft, int &NewTop, int &NewWidth, int &NewHeight, Types::TRect &AlignRect, const TAlignInfo &AlignInfo);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall DestroyHandle(void);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DoAddDockClient(TControl* Client, const Types::TRect &ARect);
	DYNAMIC void __fastcall DockOver(TDragDockObject* Source, int X, int Y, TDragState State, bool &Accept);
	DYNAMIC void __fastcall DoDockOver(TDragDockObject* Source, int X, int Y, TDragState State, bool &Accept);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall DoFlipChildren(void);
	bool __fastcall DoKeyDown(Messages::TWMKey &Message);
	bool __fastcall DoKeyPress(Messages::TWMKey &Message);
	bool __fastcall DoKeyUp(Messages::TWMKey &Message);
	DYNAMIC void __fastcall DoRemoveDockClient(TControl* Client);
	DYNAMIC bool __fastcall DoUnDock(TWinControl* NewTarget, TControl* Client);
	TWinControl* __fastcall FindNextControl(TWinControl* CurControl, bool GoForward, bool CheckTabStop, bool CheckParent);
	void __fastcall FixupTabList(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual Types::TRect __fastcall GetClientRect();
	virtual Types::TRect __fastcall GetControlExtents();
	virtual HDC __fastcall GetDeviceContext(HWND &WindowHandle);
	HWND __fastcall GetParentHandle(void);
	DYNAMIC void __fastcall GetSiteInfo(TControl* Client, Types::TRect &InfluenceRect, const Types::TPoint &MousePos, bool &CanDock);
	HWND __fastcall GetTopParentHandle(void);
	bool __fastcall IsControlMouseMsg(Messages::TWMMouse &Message);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	void __fastcall MainWndProc(Messages::TMessage &Message);
	void __fastcall NotifyControls(Word Msg);
	void __fastcall PaintControls(HDC DC, TControl* First);
	void __fastcall PaintHandler(Messages::TWMPaint &Message);
	virtual void __fastcall PaintWindow(HDC DC);
	DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	void __fastcall RecreateWnd(void);
	DYNAMIC void __fastcall ReloadDockedControl(const AnsiString AControlName, TControl* &AControl);
	void __fastcall ResetIme(void);
	bool __fastcall ResetImeComposition(unsigned Action);
	void __fastcall ScaleControls(int M, int D);
	void __fastcall SelectFirst(void);
	void __fastcall SelectNext(TWinControl* CurControl, bool GoForward, bool CheckTabStop);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	void __fastcall SetIme(void);
	bool __fastcall SetImeCompositionWindow(Graphics::TFont* Font, int XPos, int YPos);
	DYNAMIC void __fastcall SetZOrder(bool TopMost);
	virtual void __fastcall ShowControl(TControl* AControl);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property TBevelEdges BevelEdges = {read=FBevelEdges, write=SetBevelEdges, default=15};
	__property TBevelCut BevelInner = {read=FBevelInner, write=SetBevelCut, index=0, default=2};
	__property TBevelCut BevelOuter = {read=FBevelOuter, write=SetBevelCut, index=1, default=1};
	__property TBevelKind BevelKind = {read=FBevelKind, write=SetBevelKind, default=0};
	__property TBevelWidth BevelWidth = {read=FBevelWidth, write=SetBevelWidth, default=1};
	__property TBorderWidth BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property bool Ctl3D = {read=FCtl3D, write=SetCtl3D, stored=IsCtl3DStored, nodefault};
	__property void * DefWndProc = {read=FDefWndProc, write=FDefWndProc};
	__property bool DockSite = {read=FDockSite, write=SetDockSite, default=0};
	__property _di_IDockManager DockManager = {read=FDockManager, write=FDockManager};
	__property TImeMode ImeMode = {read=FImeMode, write=FImeMode, default=3};
	__property AnsiString ImeName = {read=FImeName, write=FImeName};
	__property bool ParentCtl3D = {read=FParentCtl3D, write=SetParentCtl3D, default=1};
	__property bool UseDockManager = {read=FUseDockManager, write=SetUseDockManager, default=0};
	__property HWND WindowHandle = {read=FHandle, write=FHandle, nodefault};
	__property TDockDropEvent OnDockDrop = {read=FOnDockDrop, write=FOnDockDrop};
	__property TDockOverEvent OnDockOver = {read=FOnDockOver, write=FOnDockOver};
	__property Classes::TNotifyEvent OnEnter = {read=FOnEnter, write=FOnEnter};
	__property Classes::TNotifyEvent OnExit = {read=FOnExit, write=FOnExit};
	__property TGetSiteInfoEvent OnGetSiteInfo = {read=FOnGetSiteInfo, write=FOnGetSiteInfo};
	__property TKeyEvent OnKeyDown = {read=FOnKeyDown, write=FOnKeyDown};
	__property TKeyPressEvent OnKeyPress = {read=FOnKeyPress, write=FOnKeyPress};
	__property TKeyEvent OnKeyUp = {read=FOnKeyUp, write=FOnKeyUp};
	__property TUnDockEvent OnUnDock = {read=FOnUnDock, write=FOnUnDock};
	
public:
	__fastcall virtual TWinControl(Classes::TComponent* AOwner);
	__fastcall TWinControl(HWND ParentWindow);
	/*         class method */ static TWinControl* __fastcall CreateParentedControl(TMetaClass* vmt, HWND ParentWindow);
	__fastcall virtual ~TWinControl(void);
	void __fastcall Broadcast(void *Message);
	DYNAMIC bool __fastcall CanFocus(void);
	bool __fastcall ContainsControl(TControl* Control);
	TControl* __fastcall ControlAtPos(const Types::TPoint &Pos, bool AllowDisabled, bool AllowWinControls = false);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall DisableAlign(void);
	__property int DockClientCount = {read=GetDockClientCount, nodefault};
	__property TControl* DockClients[int Index] = {read=GetDockClients};
	DYNAMIC void __fastcall DockDrop(TDragDockObject* Source, int X, int Y);
	__property bool DoubleBuffered = {read=FDoubleBuffered, write=FDoubleBuffered, nodefault};
	void __fastcall EnableAlign(void);
	TControl* __fastcall FindChildControl(const AnsiString ControlName);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	DYNAMIC bool __fastcall Focused(void);
	DYNAMIC void __fastcall GetTabOrderList(Classes::TList* List);
	bool __fastcall HandleAllocated(void);
	void __fastcall HandleNeeded(void);
	void __fastcall InsertControl(TControl* AControl);
	virtual void __fastcall Invalidate(void);
	void __fastcall PaintTo(HDC DC, int X, int Y)/* overload */;
	void __fastcall PaintTo(Graphics::TCanvas* Canvas, int X, int Y)/* overload */;
	void __fastcall RemoveControl(TControl* AControl);
	void __fastcall Realign(void);
	virtual void __fastcall Repaint(void);
	void __fastcall ScaleBy(int M, int D);
	void __fastcall ScrollBy(int DeltaX, int DeltaY);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall Update(void);
	void __fastcall UpdateControlState(void);
	__property bool AlignDisabled = {read=GetAlignDisabled, nodefault};
	__property int VisibleDockClientCount = {read=GetVisibleDockClientCount, nodefault};
	__property Graphics::TBrush* Brush = {read=FBrush};
	__property TControl* Controls[int Index] = {read=GetControl};
	__property int ControlCount = {read=GetControlCount, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property HWND ParentWindow = {read=FParentWindow, write=SetParentWindow, nodefault};
	__property bool Showing = {read=FShowing, nodefault};
	__property TTabOrder TabOrder = {read=GetTabOrder, write=SetTabOrder, default=-1};
	__property bool TabStop = {read=FTabStop, write=SetTabStop, default=0};
};



#pragma pack(push, 4)
struct TCMCancelMode
{
	unsigned Msg;
	int Unused;
	TControl* Sender;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMFocusChanged
{
	unsigned Msg;
	int Unused;
	TWinControl* Sender;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMControlListChange
{
	unsigned Msg;
	TControl* Control;
	BOOL Inserting;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMChildKey
{
	unsigned Msg;
	Word CharCode;
	Word Unused;
	TWinControl* Sender;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMControlChange
{
	unsigned Msg;
	TControl* Control;
	BOOL Inserting;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMChanged
{
	unsigned Msg;
	int Unused;
	TControl* Child;
	int Result;
} ;
#pragma pack(pop)

#pragma option push -b-
enum TDragMessage { dmDragEnter, dmDragLeave, dmDragMove, dmDragDrop, dmDragCancel, dmFindTarget };
#pragma option pop

struct TDragRec;
typedef TDragRec *PDragRec;

#pragma pack(push, 4)
struct TDragRec
{
	Types::TPoint Pos;
	TDragObject* Source;
	void *Target;
	bool Docking;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TCMDrag
{
	unsigned Msg;
	TDragMessage DragMessage;
	Byte Reserved1;
	Word Reserved2;
	TDragRec *DragRec;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TCMDockClient
{
	unsigned Msg;
	TDragDockObject* DockSource;
	Types::TSmallPoint MousePos;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TCMUnDockClient
{
	unsigned Msg;
	TControl* NewTarget;
	TControl* Client;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TCMFloat
{
	unsigned Msg;
	int Reserved;
	TDragDockObject* DockSource;
	int Result;
} ;
#pragma pack(pop)

struct TDockNotifyRec;
typedef TDockNotifyRec *PDockNotifyRec;

#pragma pack(push, 4)
struct TDockNotifyRec
{
	unsigned ClientMsg;
	int MsgWParam;
	int MsgLParam;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TCMDockNotification
{
	unsigned Msg;
	TControl* Client;
	TDockNotifyRec *NotifyRec;
	int Result;
} ;
#pragma pack(pop)

typedef Set<TAlign, alNone, alCustom>  TAlignSet;

class PASCALIMPLEMENTATION TDragObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FDragTarget;
	HWND FDragHandle;
	#pragma pack(push, 1)
	Types::TPoint FDragPos;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FDragTargetPos;
	#pragma pack(pop)
	
	bool FDropped;
	double FMouseDeltaX;
	double FMouseDeltaY;
	bool FCancelling;
	HWND __fastcall Capture(void);
	void __fastcall ReleaseCapture(HWND Handle);
	
protected:
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	virtual TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual TDragImageList* __fastcall GetDragImages(void);
	virtual void __fastcall WndProc(Messages::TMessage &Msg);
	void __fastcall MainWndProc(Messages::TMessage &Message);
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall Assign(TDragObject* Source);
	virtual void __fastcall BeforeDestruction(void);
	virtual AnsiString __fastcall GetName();
	virtual void __fastcall HideDragImage(void);
	virtual unsigned __fastcall Instance(void);
	virtual void __fastcall ShowDragImage(void);
	__property bool Cancelling = {read=FCancelling, write=FCancelling, nodefault};
	__property HWND DragHandle = {read=FDragHandle, write=FDragHandle, nodefault};
	__property Types::TPoint DragPos = {read=FDragPos, write=FDragPos};
	__property Types::TPoint DragTargetPos = {read=FDragTargetPos, write=FDragTargetPos};
	__property void * DragTarget = {read=FDragTarget, write=FDragTarget};
	__property bool Dropped = {read=FDropped, nodefault};
	__property double MouseDeltaX = {read=FMouseDeltaX};
	__property double MouseDeltaY = {read=FMouseDeltaY};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDragObject(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragObject(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TDragObjectClass;

class DELPHICLASS TDragObjectEx;
class PASCALIMPLEMENTATION TDragObjectEx : public TDragObject 
{
	typedef TDragObject inherited;
	
public:
	virtual void __fastcall BeforeDestruction(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TDragObjectEx(void) : TDragObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragObjectEx(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBaseDragControlObject;
class PASCALIMPLEMENTATION TBaseDragControlObject : public TDragObject 
{
	typedef TDragObject inherited;
	
private:
	TControl* FControl;
	
protected:
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	
public:
	__fastcall virtual TBaseDragControlObject(TControl* AControl);
	virtual void __fastcall Assign(TDragObject* Source);
	__property TControl* Control = {read=FControl, write=FControl};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseDragControlObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDragControlObject;
class PASCALIMPLEMENTATION TDragControlObject : public TBaseDragControlObject 
{
	typedef TBaseDragControlObject inherited;
	
protected:
	virtual TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual TDragImageList* __fastcall GetDragImages(void);
	
public:
	virtual void __fastcall HideDragImage(void);
	virtual void __fastcall ShowDragImage(void);
public:
	#pragma option push -w-inl
	/* TBaseDragControlObject.Create */ inline __fastcall virtual TDragControlObject(TControl* AControl) : TBaseDragControlObject(AControl) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragControlObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDragControlObjectEx;
class PASCALIMPLEMENTATION TDragControlObjectEx : public TDragControlObject 
{
	typedef TDragControlObject inherited;
	
public:
	virtual void __fastcall BeforeDestruction(void);
public:
	#pragma option push -w-inl
	/* TBaseDragControlObject.Create */ inline __fastcall virtual TDragControlObjectEx(TControl* AControl) : TDragControlObject(AControl) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDragControlObjectEx(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDragDockObject : public TBaseDragControlObject 
{
	typedef TBaseDragControlObject inherited;
	
private:
	Graphics::TBrush* FBrush;
	#pragma pack(push, 1)
	Types::TRect FDockRect;
	#pragma pack(pop)
	
	TAlign FDropAlign;
	TControl* FDropOnControl;
	#pragma pack(push, 1)
	Types::TRect FEraseDockRect;
	#pragma pack(pop)
	
	bool FFloating;
	void __fastcall SetBrush(Graphics::TBrush* Value);
	
protected:
	virtual void __fastcall AdjustDockRect(const Types::TRect &ARect);
	virtual void __fastcall DrawDragDockImage(void);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall EraseDragDockImage(void);
	virtual TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual int __fastcall GetFrameWidth(void);
	
public:
	__fastcall virtual TDragDockObject(TControl* AControl);
	__fastcall virtual ~TDragDockObject(void);
	virtual void __fastcall Assign(TDragObject* Source);
	__property Graphics::TBrush* Brush = {read=FBrush, write=SetBrush};
	__property Types::TRect DockRect = {read=FDockRect, write=FDockRect};
	__property TAlign DropAlign = {read=FDropAlign, nodefault};
	__property TControl* DropOnControl = {read=FDropOnControl};
	__property bool Floating = {read=FFloating, write=FFloating, nodefault};
	__property int FrameWidth = {read=GetFrameWidth, nodefault};
};


class DELPHICLASS TDragDockObjectEx;
class PASCALIMPLEMENTATION TDragDockObjectEx : public TDragDockObject 
{
	typedef TDragDockObject inherited;
	
public:
	virtual void __fastcall BeforeDestruction(void);
public:
	#pragma option push -w-inl
	/* TDragDockObject.Create */ inline __fastcall virtual TDragDockObjectEx(TControl* AControl) : TDragDockObject(AControl) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDragDockObject.Destroy */ inline __fastcall virtual ~TDragDockObjectEx(void) { }
	#pragma option pop
	
};


class DELPHICLASS TControlCanvas;
class PASCALIMPLEMENTATION TControlCanvas : public Graphics::TCanvas 
{
	typedef Graphics::TCanvas inherited;
	
private:
	TControl* FControl;
	HDC FDeviceContext;
	HWND FWindowHandle;
	void __fastcall SetControl(TControl* AControl);
	
protected:
	virtual void __fastcall CreateHandle(void);
	
public:
	__fastcall virtual ~TControlCanvas(void);
	void __fastcall FreeHandle(void);
	void __fastcall UpdateTextFlags(void);
	__property TControl* Control = {read=FControl, write=SetControl};
public:
	#pragma option push -w-inl
	/* TCanvas.Create */ inline __fastcall TControlCanvas(void) : Graphics::TCanvas() { }
	#pragma option pop
	
};


typedef TMetaClass*TControlClass;

#pragma pack(push, 4)
struct TCreateParams
{
	char *Caption;
	unsigned Style;
	unsigned ExStyle;
	int X;
	int Y;
	int Width;
	int Height;
	HWND WndParent;
	void *Param;
	tagWNDCLASSA WindowClass;
	char WinClassName[64];
} ;
#pragma pack(pop)

class DELPHICLASS TWinControlActionLink;
class PASCALIMPLEMENTATION TWinControlActionLink : public TControlActionLink 
{
	typedef TControlActionLink inherited;
	
protected:
	TWinControl* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsHelpContextLinked(void);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TWinControlActionLink(System::TObject* AClient) : TControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TWinControlActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TWinControlActionLinkClass;

#pragma pack(push, 4)
struct TAlignInfo
{
	Classes::TList* AlignList;
	int ControlIndex;
	TAlign Align;
	int Scratch;
} ;
#pragma pack(pop)

class DELPHICLASS TGraphicControl;
class PASCALIMPLEMENTATION TGraphicControl : public TControl 
{
	typedef TControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall Paint(void);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	
public:
	__fastcall virtual TGraphicControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TGraphicControl(void);
};


class DELPHICLASS TCustomControl;
class PASCALIMPLEMENTATION TCustomControl : public TWinControl 
{
	typedef TWinControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintWindow(HDC DC);
	__property Graphics::TCanvas* Canvas = {read=FCanvas};
	
public:
	__fastcall virtual TCustomControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomControl(void);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomControl(HWND ParentWindow) : TWinControl(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS THintWindow;
class PASCALIMPLEMENTATION THintWindow : public TCustomControl 
{
	typedef TCustomControl inherited;
	
private:
	bool FActivating;
	unsigned FLastActive;
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Messages::TMessage &Message);
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(TCreateParams &Params);
	virtual void __fastcall NCPaint(HDC DC);
	virtual void __fastcall Paint(void);
	MESSAGE void __fastcall WMPrint(Messages::TMessage &Message);
	
public:
	__fastcall virtual THintWindow(Classes::TComponent* AOwner);
	virtual void __fastcall ActivateHint(const Types::TRect &Rect, const AnsiString AHint);
	virtual void __fastcall ActivateHintData(const Types::TRect &Rect, const AnsiString AHint, void * AData);
	virtual Types::TRect __fastcall CalcHintRect(int MaxWidth, const AnsiString AHint, void * AData);
	virtual bool __fastcall IsHintMsg(tagMSG &Msg);
	void __fastcall ReleaseHandle(void);
	__property BiDiMode ;
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property Canvas ;
	__property Font ;
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~THintWindow(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall THintWindow(HWND ParentWindow) : TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*THintWindowClass;

class PASCALIMPLEMENTATION TDragImageList : public Imglist::TCustomImageList 
{
	typedef Imglist::TCustomImageList inherited;
	
private:
	TCursor FDragCursor;
	bool FDragging;
	HWND FDragHandle;
	#pragma pack(push, 1)
	Types::TPoint FDragHotspot;
	#pragma pack(pop)
	
	int FDragIndex;
	void __fastcall CombineDragCursor(void);
	void __fastcall SetDragCursor(TCursor Value);
	
protected:
	virtual void __fastcall Initialize(void);
	
public:
	bool __fastcall BeginDrag(HWND Window, int X, int Y);
	bool __fastcall DragLock(HWND Window, int XPos, int YPos);
	bool __fastcall DragMove(int X, int Y);
	void __fastcall DragUnlock(void);
	bool __fastcall EndDrag(void);
	virtual Types::TPoint __fastcall GetHotSpot();
	void __fastcall HideDragImage(void);
	bool __fastcall SetDragImage(int Index, int HotSpotX, int HotSpotY);
	void __fastcall ShowDragImage(void);
	__property TCursor DragCursor = {read=FDragCursor, write=SetDragCursor, nodefault};
	__property bool Dragging = {read=FDragging, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomImageList.Create */ inline __fastcall virtual TDragImageList(Classes::TComponent* AOwner) : Imglist::TCustomImageList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomImageList.CreateSize */ inline __fastcall TDragImageList(int AWidth, int AHeight) : Imglist::TCustomImageList(AWidth, AHeight) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TDragImageList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TImageList;
class PASCALIMPLEMENTATION TImageList : public TDragImageList 
{
	typedef TDragImageList inherited;
	
__published:
	__property BlendColor  = {default=536870911};
	__property BkColor  = {default=536870911};
	__property AllocBy  = {default=4};
	__property DrawingStyle  = {default=2};
	__property Height  = {default=16};
	__property ImageType  = {default=0};
	__property Masked  = {default=1};
	__property OnChange ;
	__property ShareImages  = {default=0};
	__property Width  = {default=16};
public:
	#pragma option push -w-inl
	/* TCustomImageList.Create */ inline __fastcall virtual TImageList(Classes::TComponent* AOwner) : TDragImageList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomImageList.CreateSize */ inline __fastcall TImageList(int AWidth, int AHeight) : TDragImageList(AWidth, AHeight) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TImageList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDockZone;
class DELPHICLASS TDockTree;
typedef void __fastcall (__closure *TForEachZoneProc)(TDockZone* Zone);

class PASCALIMPLEMENTATION TDockTree : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	int FBorderWidth;
	Graphics::TBrush* FBrush;
	TWinControl* FDockSite;
	int FGrabberSize;
	bool FGrabbersOnTop;
	#pragma pack(push, 1)
	Types::TRect FOldRect;
	#pragma pack(pop)
	
	Classes::TWndMethod FOldWndProc;
	TDockZone* FReplacementZone;
	double FScaleBy;
	TDockOrientation FShiftScaleOrient;
	int FShiftBy;
	#pragma pack(push, 1)
	Types::TPoint FSizePos;
	#pragma pack(pop)
	
	HDC FSizingDC;
	HWND FSizingWnd;
	TDockZone* FSizingZone;
	TDockZone* FTopZone;
	int FTopXYLimit;
	int FUpdateCount;
	int FVersion;
	void __fastcall ControlVisibilityChanged(TControl* Control, bool Visible);
	void __fastcall DrawSizeSplitter(void);
	TDockZone* __fastcall FindControlZone(TControl* Control);
	void __fastcall ForEachAt(TDockZone* Zone, TForEachZoneProc Proc);
	int __fastcall GetNextLimit(TDockZone* AZone);
	void __fastcall InsertNewParent(TDockZone* NewZone, TDockZone* SiblingZone, TDockOrientation ParentOrientation, bool InsertLast);
	void __fastcall InsertSibling(TDockZone* NewZone, TDockZone* SiblingZone, bool InsertLast);
	TDockZone* __fastcall InternalHitTest(const Types::TPoint &MousePos, /* out */ int &HTFlag);
	void __fastcall PruneZone(TDockZone* Zone);
	void __fastcall RemoveZone(TDockZone* Zone);
	void __fastcall ScaleZone(TDockZone* Zone);
	void __fastcall SetNewBounds(TDockZone* Zone);
	void __fastcall ShiftZone(TDockZone* Zone);
	void __fastcall SplitterMouseDown(TDockZone* OnZone, const Types::TPoint &MousePos);
	void __fastcall SplitterMouseUp(void);
	void __fastcall UpdateZone(TDockZone* Zone);
	void __fastcall WindowProc(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AdjustDockRect(TControl* Control, Types::TRect &ARect);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall GetControlBounds(TControl* Control, /* out */ Types::TRect &CtlBounds);
	virtual TControl* __fastcall HitTest(const Types::TPoint &MousePos, /* out */ int &HTFlag);
	virtual void __fastcall InsertControl(TControl* Control, TAlign InsertAt, TControl* DropCtl);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall PaintDockFrame(Graphics::TCanvas* Canvas, TControl* Control, const Types::TRect &ARect);
	virtual void __fastcall PositionDockRect(TControl* Client, TControl* DropCtl, TAlign DropAlign, Types::TRect &DockRect);
	virtual void __fastcall RemoveControl(TControl* Control);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall SetReplacingControl(TControl* Control);
	virtual void __fastcall ResetBounds(bool Force);
	void __fastcall UpdateAll(void);
	__property TWinControl* DockSite = {read=FDockSite, write=FDockSite};
	
public:
	__fastcall virtual TDockTree(TWinControl* DockSite);
	__fastcall virtual ~TDockTree(void);
	virtual void __fastcall PaintSite(HDC DC);
private:
	void *__IDockManager;	/* Controls::IDockManager */
	
public:
	operator IDockManager*(void) { return (IDockManager*)&__IDockManager; }
	
};


class PASCALIMPLEMENTATION TDockZone : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TControl* FChildControl;
	TDockZone* FChildZones;
	TDockZone* FNextSibling;
	TDockOrientation FOrientation;
	TDockZone* FParentZone;
	TDockZone* FPrevSibling;
	TDockTree* FTree;
	int FZoneLimit;
	int FOldSize;
	int __fastcall GetChildCount(void);
	AnsiString __fastcall GetControlName();
	int __fastcall GetLimitBegin(void);
	int __fastcall GetLimitSize(void);
	int __fastcall GetTopLeft(int Orient);
	int __fastcall GetHeightWidth(int Orient);
	bool __fastcall GetVisible(void);
	int __fastcall GetVisibleChildCount(void);
	int __fastcall GetZoneLimit(void);
	bool __fastcall SetControlName(const AnsiString Value);
	void __fastcall SetZoneLimit(const int Value);
	
public:
	__fastcall TDockZone(TDockTree* Tree);
	void __fastcall ExpandZoneLimit(int NewLimit);
	TDockZone* __fastcall FirstVisibleChild(void);
	TDockZone* __fastcall NextVisible(void);
	TDockZone* __fastcall PrevVisible(void);
	void __fastcall ResetChildren(void);
	void __fastcall ResetZoneLimits(void);
	void __fastcall Update(void);
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property int Height = {read=GetHeightWidth, index=1, nodefault};
	__property int Left = {read=GetTopLeft, index=2, nodefault};
	__property int LimitBegin = {read=GetLimitBegin, nodefault};
	__property int LimitSize = {read=GetLimitSize, nodefault};
	__property int Top = {read=GetTopLeft, index=1, nodefault};
	__property bool Visible = {read=GetVisible, nodefault};
	__property int VisibleChildCount = {read=GetVisibleChildCount, nodefault};
	__property int Width = {read=GetHeightWidth, index=2, nodefault};
	__property int ZoneLimit = {read=GetZoneLimit, write=SetZoneLimit, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TDockZone(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TDockTreeClass;

class DELPHICLASS TMouse;
class PASCALIMPLEMENTATION TMouse : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FDragImmediate;
	int FDragThreshold;
	bool FMousePresent;
	bool FNativeWheelSupport;
	int FScrollLines;
	unsigned FScrollLinesMessage;
	HWND FWheelHwnd;
	unsigned FWheelMessage;
	bool FWheelPresent;
	unsigned FWheelSupportMessage;
	void __fastcall GetMouseData(void);
	void __fastcall GetNativeData(void);
	void __fastcall GetRegisteredData(void);
	Types::TPoint __fastcall GetCursorPos();
	void __fastcall SetCursorPos(const Types::TPoint &Value);
	HWND __fastcall GetCapture(void);
	void __fastcall SetCapture(const HWND Value);
	bool __fastcall GetIsDragging(void);
	
public:
	__fastcall TMouse(void);
	__fastcall virtual ~TMouse(void);
	void __fastcall SettingChanged(int Setting);
	__property HWND Capture = {read=GetCapture, write=SetCapture, nodefault};
	__property Types::TPoint CursorPos = {read=GetCursorPos, write=SetCursorPos};
	__property bool DragImmediate = {read=FDragImmediate, write=FDragImmediate, default=1};
	__property int DragThreshold = {read=FDragThreshold, write=FDragThreshold, default=5};
	__property bool MousePresent = {read=FMousePresent, nodefault};
	__property bool IsDragging = {read=GetIsDragging, nodefault};
	__property unsigned RegWheelMessage = {read=FWheelMessage, nodefault};
	__property bool WheelPresent = {read=FWheelPresent, nodefault};
	__property int WheelScrollLines = {read=FScrollLines, nodefault};
};


class DELPHICLASS TCustomListControl;
class PASCALIMPLEMENTATION TCustomListControl : public TWinControl 
{
	typedef TWinControl inherited;
	
protected:
	virtual int __fastcall GetCount(void) = 0 ;
	virtual int __fastcall GetItemIndex(void) = 0 ;
	virtual void __fastcall SetItemIndex(const int Value) = 0 /* overload */;
	
public:
	virtual void __fastcall AddItem(AnsiString Item, System::TObject* AObject) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual void __fastcall ClearSelection(void) = 0 ;
	virtual void __fastcall CopySelection(TCustomListControl* Destination) = 0 ;
	virtual void __fastcall DeleteSelected(void) = 0 ;
	virtual void __fastcall MoveSelection(TCustomListControl* Destination);
	virtual void __fastcall SelectAll(void) = 0 ;
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.Create */ inline __fastcall virtual TCustomListControl(Classes::TComponent* AOwner) : TWinControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomListControl(HWND ParentWindow) : TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomListControl(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomMultiSelectListControl;
class PASCALIMPLEMENTATION TCustomMultiSelectListControl : public TCustomListControl 
{
	typedef TCustomListControl inherited;
	
protected:
	bool FMultiSelect;
	virtual int __fastcall GetSelCount(void) = 0 ;
	virtual void __fastcall SetMultiSelect(bool Value) = 0 ;
	
public:
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=0};
	__property int SelCount = {read=GetSelCount, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.Create */ inline __fastcall virtual TCustomMultiSelectListControl(Classes::TComponent* AOwner) : TCustomListControl(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomMultiSelectListControl(HWND ParentWindow) : TCustomListControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TCustomMultiSelectListControl(void) { }
	#pragma option pop
	
};


typedef BOOL __stdcall (*TAnimateWindowProc)(HWND hWnd, unsigned dwTime, unsigned dwFlags);

//-- var, const, procedure ---------------------------------------------------
static const Word CM_BASE = 0xb000;
static const Word CM_ACTIVATE = 0xb000;
static const Word CM_DEACTIVATE = 0xb001;
static const Word CM_GOTFOCUS = 0xb002;
static const Word CM_LOSTFOCUS = 0xb003;
static const Word CM_CANCELMODE = 0xb004;
static const Word CM_DIALOGKEY = 0xb005;
static const Word CM_DIALOGCHAR = 0xb006;
static const Word CM_FOCUSCHANGED = 0xb007;
static const Word CM_PARENTFONTCHANGED = 0xb008;
static const Word CM_PARENTCOLORCHANGED = 0xb009;
static const Word CM_HITTEST = 0xb00a;
static const Word CM_VISIBLECHANGED = 0xb00b;
static const Word CM_ENABLEDCHANGED = 0xb00c;
static const Word CM_COLORCHANGED = 0xb00d;
static const Word CM_FONTCHANGED = 0xb00e;
static const Word CM_CURSORCHANGED = 0xb00f;
static const Word CM_CTL3DCHANGED = 0xb010;
static const Word CM_PARENTCTL3DCHANGED = 0xb011;
static const Word CM_TEXTCHANGED = 0xb012;
static const Word CM_MOUSEENTER = 0xb013;
static const Word CM_MOUSELEAVE = 0xb014;
static const Word CM_MENUCHANGED = 0xb015;
static const Word CM_APPKEYDOWN = 0xb016;
static const Word CM_APPSYSCOMMAND = 0xb017;
static const Word CM_BUTTONPRESSED = 0xb018;
static const Word CM_SHOWINGCHANGED = 0xb019;
static const Word CM_ENTER = 0xb01a;
static const Word CM_EXIT = 0xb01b;
static const Word CM_DESIGNHITTEST = 0xb01c;
static const Word CM_ICONCHANGED = 0xb01d;
static const Word CM_WANTSPECIALKEY = 0xb01e;
static const Word CM_INVOKEHELP = 0xb01f;
static const Word CM_WINDOWHOOK = 0xb020;
static const Word CM_RELEASE = 0xb021;
static const Word CM_SHOWHINTCHANGED = 0xb022;
static const Word CM_PARENTSHOWHINTCHANGED = 0xb023;
static const Word CM_SYSCOLORCHANGE = 0xb024;
static const Word CM_WININICHANGE = 0xb025;
static const Word CM_FONTCHANGE = 0xb026;
static const Word CM_TIMECHANGE = 0xb027;
static const Word CM_TABSTOPCHANGED = 0xb028;
static const Word CM_UIACTIVATE = 0xb029;
static const Word CM_UIDEACTIVATE = 0xb02a;
static const Word CM_DOCWINDOWACTIVATE = 0xb02b;
static const Word CM_CONTROLLISTCHANGE = 0xb02c;
static const Word CM_GETDATALINK = 0xb02d;
static const Word CM_CHILDKEY = 0xb02e;
static const Word CM_DRAG = 0xb02f;
static const Word CM_HINTSHOW = 0xb030;
static const Word CM_DIALOGHANDLE = 0xb031;
static const Word CM_ISTOOLCONTROL = 0xb032;
static const Word CM_RECREATEWND = 0xb033;
static const Word CM_INVALIDATE = 0xb034;
static const Word CM_SYSFONTCHANGED = 0xb035;
static const Word CM_CONTROLCHANGE = 0xb036;
static const Word CM_CHANGED = 0xb037;
static const Word CM_DOCKCLIENT = 0xb038;
static const Word CM_UNDOCKCLIENT = 0xb039;
static const Word CM_FLOAT = 0xb03a;
static const Word CM_BORDERCHANGED = 0xb03b;
static const Word CM_BIDIMODECHANGED = 0xb03c;
static const Word CM_PARENTBIDIMODECHANGED = 0xb03d;
static const Word CM_ALLCHILDRENFLIPPED = 0xb03e;
static const Word CM_ACTIONUPDATE = 0xb03f;
static const Word CM_ACTIONEXECUTE = 0xb040;
static const Word CM_HINTSHOWPAUSE = 0xb041;
static const Word CM_DOCKNOTIFICATION = 0xb042;
static const Word CM_MOUSEWHEEL = 0xb043;
static const Word CM_ISSHORTCUT = 0xb044;
static const Word CN_BASE = 0xbc00;
static const Word CN_CHARTOITEM = 0xbc2f;
static const Word CN_COMMAND = 0xbd11;
static const Word CN_COMPAREITEM = 0xbc39;
static const Word CN_CTLCOLORBTN = 0xbd35;
static const Word CN_CTLCOLORDLG = 0xbd36;
static const Word CN_CTLCOLOREDIT = 0xbd33;
static const Word CN_CTLCOLORLISTBOX = 0xbd34;
static const Word CN_CTLCOLORMSGBOX = 0xbd32;
static const Word CN_CTLCOLORSCROLLBAR = 0xbd37;
static const Word CN_CTLCOLORSTATIC = 0xbd38;
static const Word CN_DELETEITEM = 0xbc2d;
static const Word CN_DRAWITEM = 0xbc2b;
static const Word CN_HSCROLL = 0xbd14;
static const Word CN_MEASUREITEM = 0xbc2c;
static const Word CN_PARENTNOTIFY = 0xbe10;
static const Word CN_VKEYTOITEM = 0xbc2e;
static const Word CN_VSCROLL = 0xbd15;
static const Word CN_KEYDOWN = 0xbd00;
static const Word CN_KEYUP = 0xbd01;
static const Word CN_CHAR = 0xbd02;
static const Word CN_SYSKEYDOWN = 0xbd04;
static const Word CN_SYSCHAR = 0xbd06;
static const Word CN_NOTIFY = 0xbc4e;
static const Shortint mrNone = 0x0;
static const Shortint mrOk = 0x1;
static const Shortint mrCancel = 0x2;
static const Shortint mrAbort = 0x3;
static const Shortint mrRetry = 0x4;
static const Shortint mrIgnore = 0x5;
static const Shortint mrYes = 0x6;
static const Shortint mrNo = 0x7;
static const Shortint mrAll = 0x8;
static const Shortint mrNoToAll = 0x9;
static const Shortint mrYesToAll = 0xa;
static const TCursor crDefault = 0x0;
static const TCursor crNone = 0xffffffff;
static const TCursor crArrow = 0xfffffffe;
static const TCursor crCross = 0xfffffffd;
static const TCursor crIBeam = 0xfffffffc;
static const TCursor crSize = 0xffffffea;
static const TCursor crSizeNESW = 0xfffffffa;
static const TCursor crSizeNS = 0xfffffff9;
static const TCursor crSizeNWSE = 0xfffffff8;
static const TCursor crSizeWE = 0xfffffff7;
static const TCursor crUpArrow = 0xfffffff6;
static const TCursor crHourGlass = 0xfffffff5;
static const TCursor crDrag = 0xfffffff4;
static const TCursor crNoDrop = 0xfffffff3;
static const TCursor crHSplit = 0xfffffff2;
static const TCursor crVSplit = 0xfffffff1;
static const TCursor crMultiDrag = 0xfffffff0;
static const TCursor crSQLWait = 0xffffffef;
static const TCursor crNo = 0xffffffee;
static const TCursor crAppStart = 0xffffffed;
static const TCursor crHelp = 0xffffffec;
static const TCursor crHandPoint = 0xffffffeb;
static const TCursor crSizeAll = 0xffffffea;
extern PACKAGE TMouse* Mouse;
extern PACKAGE TAnimateWindowProc AnimateWindowProc;
extern PACKAGE TWinControl* CreationControl;
extern PACKAGE TMetaClass*DefaultDockTreeClass;
static const Word CTL3D_ALL = 0xffff;
extern const TWinControl* NullDockSite;
extern PACKAGE TAnchors AnchorAlign[7];
extern PACKAGE bool NewStyleControls;
extern PACKAGE void __fastcall ChangeBiDiModeAlignment(Classes::TAlignment &Alignment);
extern PACKAGE int __stdcall InitWndProc(HWND HWindow, int Message, int WParam, int LParam);
extern PACKAGE TWinControl* __fastcall FindControl(HWND Handle);
extern PACKAGE int __fastcall SendAppMessage(unsigned Msg, int WParam, int LParam);
extern PACKAGE AnsiString __fastcall CursorToString(TCursor Cursor);
extern PACKAGE TCursor __fastcall StringToCursor(const AnsiString S);
extern PACKAGE void __fastcall GetCursorValues(Classes::TGetStrProc Proc);
extern PACKAGE bool __fastcall CursorToIdent(int Cursor, AnsiString &Ident);
extern PACKAGE bool __fastcall IdentToCursor(const AnsiString Ident, int &Cursor);
extern PACKAGE AnsiString __fastcall GetShortHint(const AnsiString Hint);
extern PACKAGE AnsiString __fastcall GetLongHint(const AnsiString Hint);
extern PACKAGE TControl* __fastcall GetCaptureControl(void);
extern PACKAGE void __fastcall SetCaptureControl(TControl* Control);
extern PACKAGE bool __fastcall IsDragObject(System::TObject* Sender);
extern PACKAGE void __fastcall DragDone(bool Drop);
extern PACKAGE void __fastcall CancelDrag(void);
extern PACKAGE TWinControl* __fastcall FindVCLWindow(const Types::TPoint &Pos);
extern PACKAGE TControl* __fastcall FindDragTarget(const Types::TPoint &Pos, bool AllowDisabled);
extern PACKAGE void __fastcall MoveWindowOrg(HDC DC, int DX, int DY);
extern PACKAGE bool __fastcall Win32NLSEnableIME(HWND hWnd, bool Enable);
extern PACKAGE void __fastcall SetImeMode(HWND hWnd, TImeMode Mode);
extern PACKAGE void __fastcall SetImeName(AnsiString Name);
extern PACKAGE int __fastcall Imm32GetContext(HWND hWnd);
extern PACKAGE bool __fastcall Imm32ReleaseContext(HWND hWnd, int hImc);
extern PACKAGE bool __fastcall Imm32GetConversionStatus(int hImc, unsigned &Conversion, unsigned &Sentence);
extern PACKAGE bool __fastcall Imm32SetConversionStatus(int hImc, unsigned Conversion, unsigned Sentence);
extern PACKAGE bool __fastcall Imm32SetOpenStatus(int hImc, bool fOpen);
extern PACKAGE bool __fastcall Imm32SetCompositionWindow(int hImc, Imm::PCompositionForm lpCompForm);
extern PACKAGE bool __fastcall Imm32SetCompositionFont(int hImc, Windows::PLogFontA lpLogfont);
extern PACKAGE int __fastcall Imm32GetCompositionString(int hImc, unsigned dWord1, void * lpBuf, unsigned dwBufLen);
extern PACKAGE bool __fastcall Imm32IsIME(HKL hKl);
extern PACKAGE bool __fastcall Imm32NotifyIME(int hImc, unsigned dwAction, unsigned dwIndex, unsigned dwValue);
extern PACKAGE bool __fastcall IsPositiveResult(const TModalResult AModalResult);
extern PACKAGE bool __fastcall IsNegativeResult(const TModalResult AModalResult);
extern PACKAGE bool __fastcall IsAbortResult(const TModalResult AModalResult);
extern PACKAGE bool __fastcall IsAnAllResult(const TModalResult AModalResult);
extern PACKAGE TModalResult __fastcall StripAllFromResult(const TModalResult AModalResult);

}	/* namespace Controls */
using namespace Controls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Controls
