// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QControls.pas' rev: 6.00

#ifndef QControlsHPP
#define QControlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QImgList.hpp>	// Pascal unit
#include <QStyle.hpp>	// Pascal unit
#include <QActnList.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Qcontrols
{
#pragma option -b-
  enum TCursor {crMin=-32768, crMax=32767};
#pragma option -b.
}

namespace Qcontrols
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EWidgetControlException;
class PASCALIMPLEMENTATION EWidgetControlException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWidgetControlException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWidgetControlException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWidgetControlException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWidgetControlException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWidgetControlException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWidgetControlException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWidgetControlException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWidgetControlException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWidgetControlException(void) { }
	#pragma option pop
	
};


class DELPHICLASS ECanvasException;
class PASCALIMPLEMENTATION ECanvasException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ECanvasException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECanvasException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECanvasException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECanvasException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECanvasException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECanvasException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECanvasException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECanvasException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECanvasException(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBevelCut { bvNone, bvLowered, bvRaised };
#pragma option pop

#pragma option push -b-
enum TBevelEdge { beLeft, beTop, beRight, beBottom };
#pragma option pop

typedef Set<TBevelEdge, beLeft, beBottom>  TBevelEdges;

struct TMessage;
typedef TMessage *PMessage;

#pragma pack(push, 4)
struct TMessage
{
	unsigned Msg;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TBroadcastMessage
{
	unsigned Msg;
	bool Handled;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TCMKeyDown
{
	unsigned Msg;
	bool Handled;
	int Key;
	WideString KeyText;
	Classes::TShiftState Shift;
} ;
#pragma pack(pop)

typedef TMetaClass*THintWindowClass;

struct THintInfo;
typedef THintInfo *PHintInfo;

class DELPHICLASS TControl;
#pragma option push -b-
enum TAlign { alNone, alTop, alBottom, alLeft, alRight, alClient, alCustom };
#pragma option pop

#pragma option push -b-
enum QControls__11 { csLButtonDown, csClicked, csPalette, csReadingState, csAlignmentNeeded, csFocusing, csCreating, csPaintCopy, csCustomPaint, csDestroyingHandle, csRecreating, csWidgetPainting, csAlignDisabled };
#pragma option pop

typedef Set<QControls__11, csLButtonDown, csAlignDisabled>  TControlState;

#pragma option push -b-
enum QControls__21 { csAcceptsControls, csCaptureMouse, csDesignInteractive, csClickEvents, csFramed, csSetCaption, csOpaque, csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible, csReplicatable, csNoStdEvents, csDisplayDragImage, csActionClient, csMenuEvents, csNoFocus };
#pragma option pop

typedef Set<QControls__21, csAcceptsControls, csNoFocus>  TControlStyle;

class DELPHICLASS TWidgetControl;
class DELPHICLASS TControlActionLink;
class PASCALIMPLEMENTATION TControlActionLink : public Qactnlist::TActionLink 
{
	typedef Qactnlist::TActionLink inherited;
	
protected:
	TControl* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHelpLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual bool __fastcall IsOnExecuteLinked(void);
	virtual bool __fastcall DoShowHint(WideString &HintStr);
	virtual void __fastcall SetCaption(const WideString Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall SetHelpType(Classes::THelpType Value);
	virtual void __fastcall SetHint(const WideString Value);
	virtual void __fastcall SetVisible(bool Value);
	virtual void __fastcall SetOnExecute(Classes::TNotifyEvent Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TControlActionLink(System::TObject* AClient) : Qactnlist::TActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TControlActionLink(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum QControls__9 { sfLeft, sfTop, sfWidth, sfHeight, sfFont };
#pragma option pop

typedef Set<QControls__9, sfLeft, sfFont>  TScalingFlags;

#pragma option push -b-
enum TMouseButton { mbLeft, mbRight, mbMiddle };
#pragma option pop

typedef void __fastcall (__closure *TMouseEvent)(System::TObject* Sender, TMouseButton Button, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TMouseMoveEvent)(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);

typedef void __fastcall (__closure *TMouseWheelEvent)(System::TObject* Sender, Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos, bool &Handled);

typedef void __fastcall (__closure *TMouseWheelUpDownEvent)(System::TObject* Sender, Classes::TShiftState Shift, const Types::TPoint &MousePos, bool &Handled);

typedef void __fastcall (__closure *TDragDropEvent)(System::TObject* Sender, System::TObject* Source, int X, int Y);

#pragma option push -b-
enum TDragState { dsDragEnter, dsDragLeave, dsDragMove };
#pragma option pop

typedef void __fastcall (__closure *TDragOverEvent)(System::TObject* Sender, System::TObject* Source, int X, int Y, TDragState State, bool &Accept);

typedef void __fastcall (__closure *TEndDragEvent)(System::TObject* Sender, System::TObject* Target, int X, int Y);

class DELPHICLASS TDragObject;
typedef void __fastcall (__closure *TStartDragEvent)(System::TObject* Sender, TDragObject* &DragObject);

#pragma option push -b-
enum TDragMode { dmManual, dmAutomatic };
#pragma option pop

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
	DYNAMIC void __fastcall Change(void);
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


typedef void __fastcall (__closure *TConstrainedResizeEvent)(System::TObject* Sender, int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);

#pragma option push -b-
enum TAnchorKind { akLeft, akTop, akRight, akBottom };
#pragma option pop

typedef Set<TAnchorKind, akLeft, akBottom>  TAnchors;

typedef void __fastcall (__closure *TContextPopupEvent)(System::TObject* Sender, const Types::TPoint &MousePos, bool &Handled);

typedef TMetaClass*TControlActionLinkClass;

class PASCALIMPLEMENTATION TControl : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	bool FVisible;
	WideString FHint;
	TAlign FAlign;
	TControlState FControlState;
	TControlStyle FControlStyle;
	TCursor FCursor;
	TWidgetControl* FParent;
	bool FEnabled;
	bool FParentColor;
	Qgraphics::TColor FColor;
	TControlActionLink* FActionLink;
	Qgraphics::TFont* FFont;
	int FFontHeight;
	bool FParentShowHint;
	Qmenus::TPopupMenu* FPopupMenu;
	TScalingFlags FScalingFlags;
	TScalingFlags FSizedFlags;
	bool FShowHint;
	TMouseEvent FOnMouseDown;
	TMouseEvent FOnMouseUp;
	TMouseMoveEvent FOnMouseMove;
	TMouseWheelEvent FOnMouseWheel;
	TMouseWheelUpDownEvent FOnMouseWheelDown;
	TMouseWheelUpDownEvent FOnMouseWheelUp;
	Classes::TNotifyEvent FOnResize;
	Classes::TNotifyEvent FOnDblClick;
	Classes::TNotifyEvent FOnClick;
	TDragDropEvent FOnDragDrop;
	TDragOverEvent FOnDragOver;
	TEndDragEvent FOnEndDrag;
	TStartDragEvent FOnStartDrag;
	TDragMode FDragMode;
	TSizeConstraints* FConstraints;
	TConstrainedResizeEvent FOnConstrainedResize;
	TAnchors FAnchors;
	bool FAnchorMove;
	#pragma pack(push, 1)
	Types::TPoint FAnchorRules;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	Types::TPoint FOriginalParentSize;
	#pragma pack(pop)
	
	TContextPopupEvent FOnContextPopup;
	Classes::THelpContext FHelpContext;
	AnsiString FHelpFile;
	AnsiString FHelpKeyword;
	Classes::THelpType FHelpType;
	TDragObject* FDragObject;
	MESSAGE void __fastcall CMParentColorChanged(TMessage &Message);
	MESSAGE void __fastcall CMParentFontChanged(TMessage &Message);
	void __fastcall DoActionChange(System::TObject* Sender);
	void __fastcall DoConstraintsChange(System::TObject* Sender);
	void __fastcall DoConstrainedResize(int &NewWidth, int &NewHeight);
	Types::TRect __fastcall GetBoundsRect();
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	void __fastcall InternalFontChanged(System::TObject* Sender);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsVisibleStored(void);
	void __fastcall InvalidateControl(bool IsVisible, bool IsOpaque);
	bool __fastcall DoMouseDown(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	bool __fastcall DoMouseUp(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall SetAlign(const TAlign Value);
	void __fastcall SetBoundsRect(const Types::TRect &Value);
	void __fastcall SetClientHeight(const int Value);
	void __fastcall SetClientSize(const Types::TPoint &Value);
	void __fastcall SetClientWidth(const int Value);
	void __fastcall SetCursor(const TCursor Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetLeft(const int Value);
	void __fastcall SetTop(const int Value);
	void __fastcall SetVisible(const bool Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall SetZOrderPosition(int Position);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsShowHintStored(void);
	bool __fastcall IsOnClickStored(void);
	void __fastcall SetFont(const Qgraphics::TFont* Value);
	void __fastcall SetParentColor(const bool Value);
	void __fastcall SetParentFont(const bool Value);
	void __fastcall SetPopupMenu(const Qmenus::TPopupMenu* Value);
	void __fastcall SetDragMode(const TDragMode Value);
	void __fastcall UpdateAnchorRules(void);
	Qgraphics::TColor __fastcall GetColor(void);
	void __fastcall SetConstraints(const TSizeConstraints* Value);
	bool __fastcall AreAnchorsStored(void);
	void __fastcall SetAnchors(const TAnchors Value);
	void __fastcall SetMouseCapture(const bool Value);
	bool __fastcall GetMouseCapture(void);
	
protected:
	int FWidth;
	int FLeft;
	int FTop;
	int FHeight;
	bool FParentFont;
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AdjustPainter(Qt::QPainterH* Painter);
	DYNAMIC void __fastcall AdjustSize(void);
	DYNAMIC void __fastcall BeginAutoDrag(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall ChangeBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC void __fastcall ChangeScale(int MV, int DV, int MH, int DH);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall ColorChanged(void);
	DYNAMIC void __fastcall ControlsAligned(void);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual void __fastcall ConstrainedResize(int &MinWidth, int &MinHeight, int &MaxWidth, int &MaxHeight);
	DYNAMIC void __fastcall DoContextPopup(const Types::TPoint &MousePos, bool &Handled);
	DYNAMIC bool __fastcall DoMouseWheel(Classes::TShiftState Shift, int WheelDelta, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelDown(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(Classes::TShiftState Shift, const Types::TPoint &MousePos);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(TDragObject* &DragObject);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, TDragState State, bool &Accept);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DragCanceled(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	Classes::TBasicAction* __fastcall GetAction(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual Qt::QPaintDeviceH* __fastcall GetAlignedPaintDevice(void);
	virtual Types::TRect __fastcall GetClientRect();
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual int __fastcall GetDragImageIndex(void);
	virtual Types::TPoint __fastcall GetDragImageHotSpot();
	virtual bool __fastcall GetEnabled(void);
	virtual Qt::QPaintDeviceH* __fastcall GetPaintDevice(void);
	DYNAMIC Qmenus::TPopupMenu* __fastcall GetPopupMenu(void);
	virtual WideString __fastcall GetText();
	DYNAMIC bool __fastcall HintShow(THintInfo &HintInfo);
	DYNAMIC void __fastcall HintShowPause(bool &WasActive, int &Pause);
	DYNAMIC bool __fastcall HitTest(int X, int Y);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(TControl* AControl);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall ParentColorChanged(void);
	DYNAMIC void __fastcall ParentFontChanged(void);
	DYNAMIC void __fastcall ParentShowHintChanged(void);
	DYNAMIC void __fastcall PaintRequest(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall RequestAlign(void);
	DYNAMIC void __fastcall Resize(void);
	void __fastcall SetAction(Classes::TBasicAction* Value);
	void __fastcall SetColor(const Qgraphics::TColor Value);
	virtual void __fastcall SetEnabled(const bool Value);
	void __fastcall SetHelpContext(const Classes::THelpContext Value);
	void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall SetName(const AnsiString Value);
	void __fastcall SetShowHint(bool Value);
	virtual void __fastcall SetParent(const TWidgetControl* Value);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* Value);
	void __fastcall SetParentShowHint(bool Value);
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall SetZOrder(bool TopMost);
	DYNAMIC void __fastcall ShowHintChanged(void);
	DYNAMIC void __fastcall SiblingsFlipped(void);
	DYNAMIC void __fastcall TextChanged(void);
	void __fastcall UpdateBoundsRect(const Types::TRect &R);
	DYNAMIC void __fastcall VisibleChanging(void);
	DYNAMIC void __fastcall VisibleChanged(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	MESSAGE void __fastcall CMParentShowHintChanged(TMessage &Message);
	__property TControlActionLink* ActionLink = {read=FActionLink, write=FActionLink};
	__property WideString Caption = {read=GetText, write=SetText};
	__property Qgraphics::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, default=-10};
	__property TDragMode DragMode = {read=FDragMode, write=SetDragMode, default=0};
	__property TDragObject* DragObject = {read=FDragObject};
	__property Qgraphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property bool MouseCapture = {read=GetMouseCapture, write=SetMouseCapture, nodefault};
	__property bool ParentColor = {read=FParentColor, write=SetParentColor, default=1};
	__property bool ParentFont = {read=FParentFont, write=SetParentFont, default=1};
	__property bool ParentShowHint = {read=FParentShowHint, write=SetParentShowHint, default=1};
	__property Qmenus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property TScalingFlags ScalingFlags = {read=FScalingFlags, write=FScalingFlags, nodefault};
	__property WideString Text = {read=GetText, write=SetText};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick, stored=IsOnClickStored};
	__property TConstrainedResizeEvent OnConstrainedResize = {read=FOnConstrainedResize, write=FOnConstrainedResize};
	__property TContextPopupEvent OnContextPopup = {read=FOnContextPopup, write=FOnContextPopup};
	__property Classes::TNotifyEvent OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property TDragDropEvent OnDragDrop = {read=FOnDragDrop, write=FOnDragDrop};
	__property TDragOverEvent OnDragOver = {read=FOnDragOver, write=FOnDragOver};
	__property TEndDragEvent OnEndDrag = {read=FOnEndDrag, write=FOnEndDrag};
	__property TMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property TMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
	__property TMouseWheelEvent OnMouseWheel = {read=FOnMouseWheel, write=FOnMouseWheel};
	__property TMouseWheelUpDownEvent OnMouseWheelDown = {read=FOnMouseWheelDown, write=FOnMouseWheelDown};
	__property TMouseWheelUpDownEvent OnMouseWheelUp = {read=FOnMouseWheelUp, write=FOnMouseWheelUp};
	__property Classes::TNotifyEvent OnResize = {read=FOnResize, write=FOnResize};
	__property TStartDragEvent OnStartDrag = {read=FOnStartDrag, write=FOnStartDrag};
	__property AnsiString HelpFile = {read=FHelpFile, write=FHelpFile};
	
public:
	__fastcall virtual TControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TControl(void);
	virtual void __fastcall AfterConstruction(void);
	void __fastcall BeginDrag(bool Immediate, int Threshold = 0xffffffff);
	Types::TPoint __fastcall ClientToParent(const Types::TPoint &Point, TWidgetControl* AParent = (TWidgetControl*)(0x0));
	void __fastcall BringToFront(void);
	Types::TPoint __fastcall ClientToScreen(const Types::TPoint &Point);
	bool __fastcall Dragging(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, stored=IsEnabledStored, default=1};
	void __fastcall EndDrag(bool Drop);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	void __fastcall Hide(void);
	virtual void __fastcall InitiateAction(void);
	virtual void __fastcall Invalidate(void);
	void __fastcall Refresh(void);
	virtual void __fastcall Repaint(void);
	Types::TPoint __fastcall ScreenToClient(const Types::TPoint &Point);
	Types::TPoint __fastcall ParentToClient(const Types::TPoint &Point, TWidgetControl* AParent = (TWidgetControl*)(0x0));
	void __fastcall SendToBack(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall Show(void);
	virtual void __fastcall Update(void);
	__property Classes::TBasicAction* Action = {read=GetAction, write=SetAction};
	__property TAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property TAnchors Anchors = {read=FAnchors, write=SetAnchors, stored=AreAnchorsStored, default=3};
	__property Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property int ClientHeight = {read=GetClientHeight, write=SetClientHeight, stored=false, nodefault};
	__property Types::TPoint ClientOrigin = {read=GetClientOrigin};
	__property Types::TRect ClientRect = {read=GetClientRect};
	__property int ClientWidth = {read=GetClientWidth, write=SetClientWidth, stored=false, nodefault};
	__property TSizeConstraints* Constraints = {read=FConstraints, write=SetConstraints};
	__property TControlState ControlState = {read=FControlState, write=FControlState, nodefault};
	__property TControlStyle ControlStyle = {read=FControlStyle, write=FControlStyle, nodefault};
	__property TWidgetControl* Parent = {read=FParent, write=SetParent};
	__property bool ShowHint = {read=FShowHint, write=SetShowHint, stored=IsShowHintStored, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	
__published:
	__property Classes::THelpType HelpType = {read=FHelpType, write=FHelpType, default=0};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, default=0};
	__property AnsiString HelpKeyword = {read=FHelpKeyword, write=SetHelpKeyword};
	__property int Left = {read=FLeft, write=SetLeft, nodefault};
	__property int Top = {read=FTop, write=SetTop, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property TCursor Cursor = {read=FCursor, write=SetCursor, default=0};
	__property WideString Hint = {read=FHint, write=FHint, stored=IsHintStored};
};


typedef void __fastcall (__closure *TKeyEvent)(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);

typedef void __fastcall (__closure *TKeyPressEvent)(System::TObject* Sender, char &Key);

typedef void __fastcall (__closure *TKeyStringEvent)(System::TObject* Sender, WideString &S, bool &Handled);

#pragma option push -b-
enum TInputKey { ikAll, ikArrows, ikChars, ikReturns, ikTabs, ikEdit, ikNav, ikEsc };
#pragma option pop

typedef Set<TInputKey, ikAll, ikEsc>  TInputKeys;

typedef short TTabOrder;

class PASCALIMPLEMENTATION TWidgetControl : public TControl 
{
	typedef TControl inherited;
	
private:
	Qt::QWidgetH* FParentWidget;
	Word FAlignLevel;
	bool FShowing;
	bool FTabStop;
	Qgraphics::TBrush* FBrush;
	Classes::TList* FControls;
	Qstyle::TWidgetStyle* FStyle;
	Qgraphics::TWidgetPalette* FPalette;
	Classes::TList* FWidgets;
	Classes::TList* FTabList;
	int FTabOrder;
	Qt::QWidget_hookH* FHooks;
	TKeyEvent FOnKeyDown;
	TKeyEvent FOnKeyUp;
	TKeyPressEvent FOnKeyPress;
	TKeyStringEvent FOnKeyString;
	Classes::TNotifyEvent FOnExit;
	Classes::TNotifyEvent FOnEnter;
	bool FMasked;
	TInputKeys FInputKeys;
	void __fastcall AlignControl(TControl* AControl);
	void __cdecl DestroyedHook(void);
	void __fastcall DoFlipChildren(void);
	bool __fastcall CheckInputKeys(int Key, Classes::TShiftState Shift, const WideString KeyText);
	TControl* __fastcall GetControl(int Index);
	int __fastcall GetControlCount(void);
	Qt::QWidgetH* __fastcall GetHandle(void);
	Qt::QWidget_hookH* __fastcall GetHooks(void);
	TTabOrder __fastcall GetTabOrder(void);
	HIDESBASE void __fastcall Insert(TControl* AControl);
	bool __fastcall IsMenuKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	HIDESBASE void __fastcall Remove(TControl* AControl);
	void __fastcall RemoveFocus(bool Removing);
	void __fastcall SetInitialSize(void);
	void __fastcall SetParentWidget(const Qt::QWidgetH* Value);
	void __fastcall SetTabOrder(const TTabOrder Value);
	void __fastcall SetTabStop(const bool Value);
	void __fastcall UpdateBounds(void);
	void __fastcall UpdateShowing(void);
	void __fastcall UpdateTabOrder(TTabOrder Value);
	Qstyle::TWidgetStyle* __fastcall GetStyle(void);
	void __fastcall SetStyle(const Qstyle::TWidgetStyle* Value);
	Qgraphics::TBitmap* __fastcall GetBitmap(void);
	void __fastcall SetMasked(const bool Value);
	MESSAGE void __fastcall CMKeyDown(TCMKeyDown &Msg);
	void __fastcall SetBrush(const Qgraphics::TBrush* Value);
	bool __fastcall IsBitmapStored(void);
	
protected:
	Qt::QWidgetH* FHandle;
	void __fastcall AdjustForFrame(int &ALeft, int &ATop, int &AWidth, int &AHeight, bool ToQt);
	virtual void __fastcall SetBitmap(const Qgraphics::TBitmap* Value);
	DYNAMIC void __fastcall ActionChange(System::TObject* Sender, bool CheckDefaults);
	virtual void __fastcall AdjustClientRect(Types::TRect &Rect);
	virtual void __fastcall AdjustPainter(Qt::QPainterH* Painter);
	virtual Qt::QWidgetH* __fastcall GetChildHandle(void);
	virtual bool __fastcall CustomAlignInsertBefore(TControl* C1, TControl* C2);
	virtual void __fastcall CustomAlignPosition(TControl* Control, int &NewLeft, int &NewTop, int &NewWidth, int &NewHeight, Types::TRect &AlignRect);
	virtual void __fastcall AlignControls(TControl* AControl, Types::TRect &Rect);
	virtual void __fastcall ChangeBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC void __fastcall ChangeScale(int MV, int DV, int MH, int DH);
	DYNAMIC void __fastcall ColorChanged(void);
	DYNAMIC void __fastcall ControlsListChanging(TControl* Control, bool Inserting);
	DYNAMIC void __fastcall ControlsListChanged(TControl* Control, bool Inserting);
	void __fastcall CreateHandle(void);
	virtual void __fastcall Painting(Qt::QObjectH* Sender, Qt::QRegionH* EventRegion);
	DYNAMIC void __fastcall EnabledChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual Qt::QPaintDeviceH* __fastcall GetAlignedPaintDevice(void);
	virtual Qt::QPaintDeviceH* __fastcall GetPaintDevice(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall CursorChanged(void);
	void __fastcall DestroyHandle(void);
	virtual void __fastcall DestroyWidget(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC bool __fastcall DesignEventQuery(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	bool __cdecl MainEventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	TWidgetControl* __fastcall FindNextControl(TWidgetControl* CurControl, bool GoForward, bool CheckTabStop, bool CheckParent);
	void __fastcall FixupTabList(void);
	DYNAMIC TMetaClass* __fastcall GetActionLinkClass(void);
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual Types::TRect __fastcall GetClientRect();
	virtual bool __fastcall GetEnabled(void);
	virtual Qt::QWidgetH* __fastcall GetParentWidget(void);
	virtual WideString __fastcall GetText();
	virtual void __fastcall HookEvents(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall KeyString(WideString &S, bool &Handled);
	DYNAMIC void __fastcall MaskChanged(void);
	DYNAMIC bool __fastcall NeedKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	void __fastcall NotifyControls(Word Msg);
	DYNAMIC void __fastcall PaletteChanged(System::TObject* Sender);
	void __fastcall RecreateWidget(void);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	virtual void __fastcall ResetEvents(void);
	void __fastcall ReSubmitFlags(void);
	virtual void __fastcall RestoreWidgetState(void);
	virtual void __fastcall SaveWidgetState(void);
	void __fastcall ScaleControls(int MV, int DV, int MH = 0x0, int DH = 0x0);
	void __fastcall ScrollControls(int DeltaX, int DeltaY, bool IsVisible);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	void __fastcall SelectFirst(void);
	bool __fastcall SelectNext(TWidgetControl* CurControl, bool GoForward, bool CheckTabStop);
	virtual void __fastcall SetInitialBounds(void);
	virtual void __fastcall SetParent(const TWidgetControl* Value);
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall SetZOrder(bool TopMost);
	HIDESBASE void __fastcall SetZOrderPosition(int Position);
	DYNAMIC void __fastcall ShowingChanged(void);
	virtual void __fastcall ShowControl(TControl* AControl);
	DYNAMIC void __fastcall ShowHintChanged(void);
	DYNAMIC void __fastcall StyleChanged(System::TObject* Sender);
	DYNAMIC void __fastcall TabStopChanged(void);
	DYNAMIC void __fastcall UpdateWidgetShowing(void);
	virtual Types::TRect __fastcall ViewportRect();
	DYNAMIC void __fastcall VisibleChanged(void);
	DYNAMIC bool __fastcall WantKey(int Key, Classes::TShiftState Shift, const WideString KeyText);
	virtual int __fastcall WidgetFlags(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	__property Qgraphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap, stored=IsBitmapStored};
	__property Qt::QWidget_hookH* Hooks = {read=GetHooks, write=FHooks};
	__property TInputKeys InputKeys = {read=FInputKeys, write=FInputKeys, nodefault};
	__property bool Masked = {read=FMasked, write=SetMasked, default=0};
	__property Qgraphics::TWidgetPalette* Palette = {read=FPalette};
	__property Qstyle::TWidgetStyle* Style = {read=GetStyle, write=SetStyle};
	__property Classes::TNotifyEvent OnEnter = {read=FOnEnter, write=FOnEnter};
	__property Classes::TNotifyEvent OnExit = {read=FOnExit, write=FOnExit};
	__property TKeyEvent OnKeyDown = {read=FOnKeyDown, write=FOnKeyDown};
	__property TKeyPressEvent OnKeyPress = {read=FOnKeyPress, write=FOnKeyPress};
	__property TKeyStringEvent OnKeyString = {read=FOnKeyString, write=FOnKeyString};
	__property TKeyEvent OnKeyUp = {read=FOnKeyUp, write=FOnKeyUp};
	
public:
	__fastcall virtual TWidgetControl(Classes::TComponent* AOwner);
	__fastcall TWidgetControl(Qt::QWidgetH* ParentWidget);
	/*         class method */ static TWidgetControl* __fastcall CreateParentedControl(TMetaClass* vmt, Qt::QWidgetH* ParentWidget);
	__fastcall virtual ~TWidgetControl(void);
	void __fastcall Broadcast(void *Message);
	DYNAMIC bool __fastcall CanFocus(void);
	bool __fastcall ContainsControl(TControl* Control);
	TControl* __fastcall ControlAtPos(const Types::TPoint &Pos, bool AllowDisabled, bool AllowWidgets = false);
	void __fastcall DisableAlign(void);
	void __fastcall EnableAlign(void);
	TControl* __fastcall FindChildControl(const AnsiString ControlName);
	DYNAMIC void __fastcall FlipChildren(bool AllLevels);
	DYNAMIC bool __fastcall Focused(void);
	DYNAMIC void __fastcall GetTabOrderList(Classes::TList* List);
	bool __fastcall HandleAllocated(void);
	void __fastcall HandleNeeded(void);
	void __fastcall InsertControl(TControl* AControl);
	virtual void __fastcall Invalidate(void);
	void __fastcall InvalidateRect(const Types::TRect &Rect, bool EraseBackground);
	virtual void __fastcall InvokeHelp(void);
	void __fastcall RemoveControl(TControl* AControl);
	void __fastcall Realign(void);
	virtual void __fastcall Repaint(void);
	void __fastcall ScaleBy(int MV, int DV, int MH = 0x0, int DH = 0x0);
	virtual void __fastcall ScrollBy(int DeltaX, int DeltaY);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall Update(void);
	void __fastcall UpdateControlState(void);
	__property Qgraphics::TBrush* Brush = {read=FBrush, write=SetBrush};
	__property TControl* Controls[int Index] = {read=GetControl};
	__property int ControlCount = {read=GetControlCount, nodefault};
	__property Qt::QWidgetH* Handle = {read=GetHandle};
	__property Qt::QWidgetH* ChildHandle = {read=GetChildHandle};
	__property Qt::QWidgetH* ParentWidget = {read=GetParentWidget, write=SetParentWidget};
	__property bool Showing = {read=FShowing, nodefault};
	__property TTabOrder TabOrder = {read=GetTabOrder, write=SetTabOrder, default=-1};
	__property bool TabStop = {read=FTabStop, write=SetTabStop, default=0};
};



#pragma pack(push, 4)
struct THintInfo
{
	TControl* HintControl;
	TMetaClass*HintWindowClass;
	Types::TPoint HintPos;
	int HintMaxWidth;
	Qgraphics::TColor HintColor;
	Types::TRect CursorRect;
	Types::TPoint CursorPos;
	int ReshowTimeout;
	int HideTimeout;
	WideString HintStr;
	void *HintData;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TShowHintEvent)(WideString &HintStr, bool &CanShow, THintInfo &HintInfo);

class PASCALIMPLEMENTATION TDragObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	#pragma pack(push, 1)
	Types::TPoint FDragTargetPos;
	#pragma pack(pop)
	
	bool __fastcall GetIsInterApp(void);
	
protected:
	void __fastcall SetDragImage(void);
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	virtual int __fastcall GetDragImageIndex(void);
	virtual Types::TPoint __fastcall GetDragImageHotSpot();
	Classes::TShiftState __fastcall GetKeyState(void);
	
public:
	__fastcall TDragObject(void);
	__fastcall virtual ~TDragObject(void);
	virtual void __fastcall Assign(TDragObject* Source);
	virtual void __fastcall HideDragImage(void);
	virtual void __fastcall ShowDragImage(void);
	__property Types::TPoint DragTargetPos = {read=FDragTargetPos, write=FDragTargetPos};
	__property bool IsInterAppDrag = {read=GetIsInterApp, nodefault};
	__property Classes::TShiftState KeyState = {read=GetKeyState, nodefault};
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
	__fastcall virtual ~TBaseDragControlObject(void);
	virtual void __fastcall Assign(TDragObject* Source);
	__property TControl* Control = {read=FControl, write=FControl};
};


class DELPHICLASS TDragControlObject;
class PASCALIMPLEMENTATION TDragControlObject : public TBaseDragControlObject 
{
	typedef TBaseDragControlObject inherited;
	
protected:
	virtual Types::TPoint __fastcall GetDragImageHotSpot();
	virtual int __fastcall GetDragImageIndex(void);
	
public:
	virtual void __fastcall HideDragImage(void);
	virtual void __fastcall ShowDragImage(void);
public:
	#pragma option push -w-inl
	/* TBaseDragControlObject.Create */ inline __fastcall virtual TDragControlObject(TControl* AControl) : TBaseDragControlObject(AControl) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBaseDragControlObject.Destroy */ inline __fastcall virtual ~TDragControlObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TControlCanvas;
class PASCALIMPLEMENTATION TControlCanvas : public Qgraphics::TCanvas 
{
	typedef Qgraphics::TCanvas inherited;
	
private:
	TControl* FControl;
	bool FClipped;
	void __fastcall SetControl(TControl* AControl);
	void __fastcall SetClipped(const bool Value);
	
protected:
	virtual void __fastcall BeginPainting(void);
	virtual void __fastcall CreateHandle(void);
	
public:
	__fastcall virtual ~TControlCanvas(void);
	void __fastcall FreeHandle(void);
	void __fastcall StartPaint(void);
	void __fastcall StopPaint(void);
	__property TControl* Control = {read=FControl, write=SetControl};
	__property bool Clipped = {read=FClipped, write=SetClipped, nodefault};
public:
	#pragma option push -w-inl
	/* TCanvas.Create */ inline __fastcall TControlCanvas(void) : Qgraphics::TCanvas() { }
	#pragma option pop
	
};


class DELPHICLASS TQtCanvas;
class PASCALIMPLEMENTATION TQtCanvas : public Qgraphics::TCanvas 
{
	typedef Qgraphics::TCanvas inherited;
	
private:
	Qt::QWidgetH* FQtHandle;
	bool FClipped;
	void __fastcall SetQtHandle(Qt::QWidgetH* AQtHandle);
	void __fastcall SetClipped(const bool Value);
	
protected:
	virtual void __fastcall BeginPainting(void);
	virtual void __fastcall CreateHandle(void);
	
public:
	__fastcall virtual ~TQtCanvas(void);
	void __fastcall FreeHandle(void);
	void __fastcall StartPaint(void);
	void __fastcall StopPaint(void);
	__property Qt::QWidgetH* QtHandle = {read=FQtHandle, write=SetQtHandle};
	__property bool Clipped = {read=FClipped, write=SetClipped, nodefault};
public:
	#pragma option push -w-inl
	/* TCanvas.Create */ inline __fastcall TQtCanvas(void) : Qgraphics::TCanvas() { }
	#pragma option pop
	
};


class DELPHICLASS TWidgetControlActionLink;
class PASCALIMPLEMENTATION TWidgetControlActionLink : public TControlActionLink 
{
	typedef TControlActionLink inherited;
	
protected:
	TWidgetControl* FClient;
	virtual void __fastcall AssignClient(System::TObject* AClient);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TWidgetControlActionLink(System::TObject* AClient) : TControlActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TWidgetControlActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TWidgetControlActionLinkClass;

typedef bool __cdecl (__closure *TEventFilterMethod)(Qt::QObjectH* Sender, Qt::QEventH* Event);

typedef TWidgetControl TWinControl;
;

class DELPHICLASS TGraphicControl;
class PASCALIMPLEMENTATION TGraphicControl : public TControl 
{
	typedef TControl inherited;
	
private:
	Qgraphics::TCanvas* FCanvas;
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall PaintRequest(void);
	__property Qgraphics::TCanvas* Canvas = {read=FCanvas};
	
public:
	__fastcall virtual TGraphicControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TGraphicControl(void);
};


class DELPHICLASS TCustomControl;
class PASCALIMPLEMENTATION TCustomControl : public TWidgetControl 
{
	typedef TWidgetControl inherited;
	
private:
	Qgraphics::TCanvas* FCanvas;
	void __fastcall UpdateMask(void);
	
protected:
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall CreateWidget(void);
	virtual void __fastcall Painting(Qt::QObjectH* Sender, Qt::QRegionH* EventRegion);
	virtual bool __fastcall EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall MaskChanged(void);
	virtual void __fastcall DrawMask(Qgraphics::TCanvas* Canvas);
	__property Qgraphics::TCanvas* Canvas = {read=FCanvas};
	
public:
	__fastcall virtual TCustomControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomControl(void);
	virtual void __fastcall Invalidate(void);
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomControl(Qt::QWidgetH* ParentWidget) : TWidgetControl(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS THintWindow;
class PASCALIMPLEMENTATION THintWindow : public TCustomControl 
{
	typedef TCustomControl inherited;
	
private:
	bool FActivating;
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall TextChanged(void);
	virtual int __fastcall WidgetFlags(void);
	
public:
	__fastcall virtual THintWindow(Classes::TComponent* AOwner);
	virtual void __fastcall ActivateHint(const Types::TRect &Rect, const WideString AHint);
	virtual void __fastcall ActivateHintData(const Types::TRect &Rect, const WideString AHint, void * AData);
	virtual Types::TRect __fastcall CalcHintRect(int MaxWidth, const WideString AHint, void * AData);
	DYNAMIC void __fastcall FontChanged(void);
	void __fastcall ReleaseHandle(void);
	__property Color  = {default=-10};
public:
	#pragma option push -w-inl
	/* TCustomControl.Destroy */ inline __fastcall virtual ~THintWindow(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall THintWindow(Qt::QWidgetH* ParentWidget) : TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TBorderStyle { bsNone, bsSingle, bsDouble, bsRaisedPanel, bsSunkenPanel, bsRaised3d, bsSunken3d, bsEtched, bsEmbossed };
#pragma option pop

typedef TBorderStyle TControlBorderStyle;

class DELPHICLASS TFrameControl;
class PASCALIMPLEMENTATION TFrameControl : public TWidgetControl 
{
	typedef TWidgetControl inherited;
	
private:
	TBorderStyle FBorderStyle;
	Types::TRect __fastcall GetFrameRect();
	HIDESBASE Qt::QFrameH* __fastcall GetHandle(void);
	int __fastcall GetLineWidth(void);
	int __fastcall GetMargin(void);
	int __fastcall GetMidLineWidth(void);
	void __fastcall SetFrameRect(const Types::TRect &Value);
	void __fastcall SetLineWidth(const int Value);
	void __fastcall SetMargin(const int Value);
	void __fastcall SetMidLineWidth(const int Value);
	void __fastcall SetBorderStyle(const TBorderStyle Value);
	
protected:
	virtual void __fastcall CreateWidget(void);
	virtual Types::TPoint __fastcall GetClientOrigin();
	virtual void __fastcall InitWidget(void);
	__property TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property Types::TRect FrameRect = {read=GetFrameRect, write=SetFrameRect};
	__property int LineWidth = {read=GetLineWidth, write=SetLineWidth, nodefault};
	__property int Margin = {read=GetMargin, write=SetMargin, nodefault};
	__property int MidLineWidth = {read=GetMidLineWidth, write=SetMidLineWidth, nodefault};
	
public:
	__fastcall virtual TFrameControl(Classes::TComponent* AOwner);
	Types::TRect __fastcall ContentsRect();
	__property Qt::QFrameH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TFrameControl(Qt::QWidgetH* ParentWidget) : TWidgetControl(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TFrameControl(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMouse;
class PASCALIMPLEMENTATION TMouse : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FDragImmediate;
	int FDragThreshold;
	TControl* __fastcall GetCapture(void);
	Types::TPoint __fastcall GetCursorPos();
	void __fastcall SetCapture(const TControl* Value);
	void __fastcall SetCursorPos(const Types::TPoint &Value);
	
public:
	__fastcall TMouse(void);
	__fastcall virtual ~TMouse(void);
	__property TControl* Capture = {read=GetCapture, write=SetCapture};
	__property Types::TPoint CursorPos = {read=GetCursorPos, write=SetCursorPos};
	__property bool DragImmediate = {read=FDragImmediate, write=FDragImmediate, nodefault};
	__property int DragThreshold = {read=FDragThreshold, write=FDragThreshold, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const Word CM_BASE = 0xb000;
static const Word CM_PARENTSHOWHINTCHANGED = 0xb001;
static const Word CM_PARENTCOLORCHANGED = 0xb002;
static const Word CM_PARENTFONTCHANGED = 0xb003;
static const Word CM_RECREATEWINDOW = 0xb004;
static const Word CM_KEYDOWN = 0xb005;
static const Word CM_WANTKEY = 0xb006;
static const Shortint mrNone = 0x0;
static const Shortint mrOk = 0x1;
static const Shortint mrCancel = 0x2;
static const Shortint mrYes = 0x3;
static const Shortint mrNo = 0x4;
static const Shortint mrAbort = 0x5;
static const Shortint mrRetry = 0x6;
static const Shortint mrIgnore = 0x7;
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
static const Shortint DrawStage_Pre = 0x0;
static const Shortint DrawStage_Post = 0x1;
static const Shortint DrawStage_DefaultDraw = 0x2;
static const Word Key_Word_Lower = 0x1000;
static const Word Key_Word_Upper = 0x1058;
extern PACKAGE TAnchors AnchorAlign[7];
extern PACKAGE void __fastcall Beep(void);
extern PACKAGE WideString __fastcall GetShortHint(const WideString Hint);
extern PACKAGE WideString __fastcall GetLongHint(const WideString Hint);
extern PACKAGE AnsiString __fastcall CursorToString(TCursor Cursor);
extern PACKAGE TCursor __fastcall StringToCursor(const AnsiString S);
extern PACKAGE void __fastcall GetCursorValues(Classes::TGetStrProc Proc);
extern PACKAGE bool __fastcall CursorToIdent(int Cursor, AnsiString &Ident);
extern PACKAGE bool __fastcall IdentToCursor(const AnsiString Ident, int &Cursor);
extern PACKAGE TWidgetControl* __fastcall FindControl(Qt::QWidgetH* Handle)/* overload */;
extern PACKAGE System::TObject* __fastcall FindObject(Qt::QObjectH* Handle);
extern PACKAGE TWidgetControl* __fastcall FindControl(const Types::TPoint &Pos)/* overload */;
extern PACKAGE void __fastcall AdjustForFrame(Qt::QWidgetH* Widget, int &ALeft, int &ATop, int &AWidth, int &AHeight, bool ToQt);
extern PACKAGE TControl* __fastcall FindDragTarget(const Types::TPoint &Pos, bool AllowDisabled);
extern PACKAGE void __fastcall AdjustForClient(Types::TRect &ARect);
extern PACKAGE Classes::TShiftState __fastcall ButtonStateToShiftState(Qt::ButtonState ButtonState);
extern PACKAGE TControl* __fastcall GetMouseGrabControl(void);
extern PACKAGE TControl* __fastcall GetCaptureControl(void);
extern PACKAGE void __fastcall SetMouseGrabControl(TControl* Control);
extern PACKAGE void __fastcall SetCaptureControl(TControl* Control);
extern PACKAGE void __fastcall GetCursorPos(Types::TPoint &P);
extern PACKAGE Qimglist::TImageList* __fastcall DragImageList(void);
extern PACKAGE bool __fastcall SaveDragDataToStream(Classes::TStream* Stream, const AnsiString Format);
extern PACKAGE void __fastcall SupportedDragFormats(Classes::TStrings* List);
extern PACKAGE bool __fastcall AddDragFormat(const AnsiString Format, Classes::TStream* Stream);
extern PACKAGE bool __fastcall InDragDropOperation(void);

}	/* namespace Qcontrols */
using namespace Qcontrols;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QControls
