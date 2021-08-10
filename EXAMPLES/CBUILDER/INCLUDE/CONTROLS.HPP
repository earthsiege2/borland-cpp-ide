//----------------------------------------------------------------------------
// Controls.hpp - bcbdcc32 generated hdr (DO NOT EDIT) rev: 0
// From: Controls.pas
//----------------------------------------------------------------------------
#ifndef ControlsHPP
#define ControlsHPP
//----------------------------------------------------------------------------
#include <Imm.hpp>
#include <CommCtrl.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <Messages.hpp>
#include <System.hpp>
#include <ctl3d.h>

#pragma warn -par
#pragma warn -hid 
#pragma warn -inl

namespace Controls
{
//-- type declarations -------------------------------------------------------
enum TCursor {crMin=-0x7FFF-1, crMax=0x7FFF};

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

class __declspec(delphiclass) TControl;
class __declspec(delphiclass) TWinControl;
typedef void __fastcall (__closure *TWndMethod)(Messages::TMessage &Message);

enum Controls_7 { csAcceptsControls, csCaptureMouse, csDesignInteractive, csClickEvents, csFramed, csSetCaption, 
	csOpaque, csDoubleClicks, csFixedWidth, csFixedHeight, csNoDesignVisible, csReplicatable, csNoStdEvents, 
	csDisplayDragImage };

typedef Set<Controls_7, csAcceptsControls, csDisplayDragImage>  TControlStyle;

enum Controls_6 { csLButtonDown, csClicked, csPalette, csReadingState, csAlignmentNeeded, csFocusing, 
	csCreating, csPaintCopy };

typedef Set<Controls_6, csLButtonDown, csPaintCopy>  TControlState;

enum TAlign { alNone, alTop, alBottom, alLeft, alRight, alClient };

enum TDragMode { dmManual, dmAutomatic };

enum Controls_8 { sfLeft, sfTop, sfWidth, sfHeight, sfFont };

typedef Set<Controls_8, sfLeft, sfFont>  TScalingFlags;

enum TMouseButton { mbLeft, mbRight, mbMiddle };

typedef void __fastcall (__closure *TMouseEvent)(System::TObject* Sender, TMouseButton Button, Classes::TShiftState 
	Shift, int X, int Y);

typedef void __fastcall (__closure *TMouseMoveEvent)(System::TObject* Sender, Classes::TShiftState Shift
	, int X, int Y);

typedef void __fastcall (__closure *TDragDropEvent)(System::TObject* Sender, System::TObject* Source
	, int X, int Y);

enum TDragState { dsDragEnter, dsDragLeave, dsDragMove };

typedef void __fastcall (__closure *TDragOverEvent)(System::TObject* Sender, System::TObject* Source
	, int X, int Y, TDragState State, bool &Accept);

class __declspec(delphiclass) TDragObject;
typedef void __fastcall (__closure *TStartDragEvent)(System::TObject* Sender, TDragObject* &DragObject
	);

typedef void __fastcall (__closure *TEndDragEvent)(System::TObject* Sender, System::TObject* Target, 
	int X, int Y);

struct TCMDrag;
typedef System::AnsiString TCaption;

class __declspec(delphiclass) TCustomImageList;
class __declspec(pascalimplementation) TControl : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
private:
	TWinControl* FParent;
	TWndMethod FWindowProc;
	int FLeft;
	int FTop;
	int FWidth;
	int FHeight;
	TControlStyle FControlStyle;
	TControlState FControlState;
	bool FVisible;
	bool FEnabled;
	bool FParentFont;
	bool FParentColor;
	TAlign FAlign;
	TDragMode FDragMode;
	bool FIsControl;
	char *FText;
	Graphics::TFont* FFont;
	Graphics::TColor FColor;
	TCursor FCursor;
	TCursor FDragCursor;
	Menus::TPopupMenu* FPopupMenu;
	System::AnsiString FHint;
	int FFontHeight;
	TScalingFlags FScalingFlags;
	bool FShowHint;
	bool FParentShowHint;
	TMouseEvent FOnMouseDown;
	TMouseMoveEvent FOnMouseMove;
	TMouseEvent FOnMouseUp;
	TDragDropEvent FOnDragDrop;
	TDragOverEvent FOnDragOver;
	TStartDragEvent FOnStartDrag;
	TEndDragEvent FOnEndDrag;
	Classes::TNotifyEvent FOnClick;
	Classes::TNotifyEvent FOnDblClick;
	void __fastcall CheckMenuPopup(const Windows::TSmallPoint Pos);
	void __fastcall DoDragMsg(TCMDrag &DragMsg);
	void __fastcall DoMouseDown(Messages::TWMMouse &Message, TMouseButton Button, Classes::TShiftState 
		Shift);
	void __fastcall DoMouseUp(Messages::TWMMouse &Message, TMouseButton Button);
	void __fastcall FontChanged(System::TObject* Sender);
	Windows::TRect __fastcall GetBoundsRect(void);
	int __fastcall GetClientHeight(void);
	int __fastcall GetClientWidth(void);
	bool __fastcall GetMouseCapture(void);
	System::AnsiString __fastcall GetText(void);
	void __fastcall InvalidateControl(bool IsVisible, bool IsOpaque);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsShowHintStored(void);
	void __fastcall ReadIsControl(Classes::TReader* Reader);
	void __fastcall RequestAlign(void);
	void __fastcall SetAlign(TAlign Value);
	void __fastcall SetBoundsRect(const Windows::TRect &Rect);
	void __fastcall SetClientHeight(int Value);
	void __fastcall SetClientSize(const POINT &Value);
	void __fastcall SetClientWidth(int Value);
	void __fastcall SetColor(Graphics::TColor Value);
	void __fastcall SetCursor(TCursor Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetLeft(int Value);
	void __fastcall SetMouseCapture(bool Value);
	void __fastcall SetParentColor(bool Value);
	void __fastcall SetParentFont(bool Value);
	void __fastcall SetShowHint(bool Value);
	void __fastcall SetParentShowHint(bool Value);
	void __fastcall SetPopupMenu(Menus::TPopupMenu* Value);
	void __fastcall SetText(const System::AnsiString Value);
	void __fastcall SetTop(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(int Value);
	void __fastcall SetZOrderPosition(int Position);
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
	MESSAGE void __fastcall WMCancelMode(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentColorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentShowHintChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMHitTest(Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall CMMouseEnter(Messages::TMessage &Message);
	MESSAGE void __fastcall CMMouseLeave(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	
protected:
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall Click(void);
	virtual void __fastcall DblClick(void);
	virtual void __fastcall DefaultHandler(void *Message);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DragCanceled(void);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, TDragState State, bool &Accept
		);
	virtual void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall DoStartDrag(TDragObject* &DragObject);
	virtual POINT __fastcall GetClientOrigin(void);
	virtual Windows::TRect __fastcall GetClientRect(void);
	virtual HDC __fastcall GetDeviceContext(HWND &WindowHandle);
	virtual TCustomImageList* __fastcall GetDragImages(void);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual Classes::TComponent* __fastcall GetParentComponent(void);
	virtual Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	virtual bool __fastcall HasParent(void);
	virtual void __fastcall MouseDown(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual bool __fastcall PaletteChanged(bool Foreground);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	void __fastcall SendCancelMode(TControl* Sender);
	virtual void __fastcall SetDragMode(TDragMode Value);
	virtual void __fastcall SetParent(TWinControl* AParent);
	virtual void __fastcall SetParentComponent(Classes::TComponent* Value);
	virtual void __fastcall SetName(const System::AnsiString Value);
	virtual void __fastcall SetZOrder(bool TopMost);
	void __fastcall UpdateBoundsRect(const Windows::TRect &R);
	virtual void __fastcall VisibleChanging(void);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property System::AnsiString Caption = {read=GetText, write=SetText, nodefault};
	__property Graphics::TColor Color = {read=FColor, write=SetColor, stored=IsColorStored, default=-2147483643
		};
	__property TCursor DragCursor = {read=FDragCursor, write=FDragCursor, default=-12};
	__property TDragMode DragMode = {read=FDragMode, write=SetDragMode, default=0};
	__property Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored, nodefault};
	__property bool IsControl = {read=FIsControl, write=FIsControl, nodefault};
	__property bool MouseCapture = {read=GetMouseCapture, write=SetMouseCapture, nodefault};
	__property bool ParentColor = {read=FParentColor, write=SetParentColor, default=1};
	__property bool ParentFont = {read=FParentFont, write=SetParentFont, default=1};
	__property bool ParentShowHint = {read=FParentShowHint, write=SetParentShowHint, default=1};
	__property Menus::TPopupMenu* PopupMenu = {read=FPopupMenu, write=SetPopupMenu, nodefault};
	__property TScalingFlags ScalingFlags = {read=FScalingFlags, write=FScalingFlags, nodefault};
	__property System::AnsiString Text = {read=GetText, write=SetText, nodefault};
	__property char * WindowText = {read=FText, write=FText, nodefault};
	__property Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property Classes::TNotifyEvent OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property TDragDropEvent OnDragDrop = {read=FOnDragDrop, write=FOnDragDrop};
	__property TDragOverEvent OnDragOver = {read=FOnDragOver, write=FOnDragOver};
	__property TEndDragEvent OnEndDrag = {read=FOnEndDrag, write=FOnEndDrag};
	__property TMouseEvent OnMouseDown = {read=FOnMouseDown, write=FOnMouseDown};
	__property TMouseMoveEvent OnMouseMove = {read=FOnMouseMove, write=FOnMouseMove};
	__property TMouseEvent OnMouseUp = {read=FOnMouseUp, write=FOnMouseUp};
	__property TStartDragEvent OnStartDrag = {read=FOnStartDrag, write=FOnStartDrag};
	
public:
	__fastcall virtual TControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TControl(void);
	void __fastcall BeginDrag(bool Immediate);
	void __fastcall BringToFront(void);
	POINT __fastcall ClientToScreen(const POINT &Point);
	bool __fastcall Dragging(void);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	void __fastcall EndDrag(bool Drop);
	int __fastcall GetTextBuf(char * Buffer, int BufSize);
	int __fastcall GetTextLen(void);
	void __fastcall Hide(void);
	virtual void __fastcall Invalidate(void);
	long __fastcall Perform(Cardinal Msg, long WParam, long LParam);
	void __fastcall Refresh(void);
	virtual void __fastcall Repaint(void);
	POINT __fastcall ScreenToClient(const POINT &Point);
	void __fastcall SendToBack(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall SetTextBuf(char * Buffer);
	void __fastcall Show(void);
	virtual void __fastcall Update(void);
	__property TAlign Align = {read=FAlign, write=SetAlign, default=0};
	__property Windows::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property int ClientHeight = {read=GetClientHeight, write=SetClientHeight, stored=false, nodefault
		};
	__property POINT ClientOrigin = {read=GetClientOrigin};
	__property Windows::TRect ClientRect = {read=GetClientRect};
	__property int ClientWidth = {read=GetClientWidth, write=SetClientWidth, stored=false, nodefault};
	__property TControlState ControlState = {read=FControlState, write=FControlState, nodefault};
	__property TControlStyle ControlStyle = {read=FControlStyle, write=FControlStyle, nodefault};
	__property TWinControl* Parent = {read=FParent, write=SetParent, nodefault};
	__property bool ShowHint = {read=FShowHint, write=SetShowHint, stored=IsShowHintStored, nodefault};
		
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property TWndMethod WindowProc = {read=FWindowProc, write=FWindowProc};
	
__published:
	__property int Left = {read=FLeft, write=SetLeft, nodefault};
	__property int Top = {read=FTop, write=SetTop, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property TCursor Cursor = {read=FCursor, write=SetCursor, default=0};
	__property System::AnsiString Hint = {read=FHint, write=FHint, nodefault};
};

enum TImeMode { imDisable, imClose, imOpen, imDontCare, imSAlpha, imAlpha, imHira, imSKata, imKata, 
	imChinese, imSHanguel, imHanguel };

typedef System::AnsiString TImeName;

typedef void __fastcall (__closure *TKeyEvent)(System::TObject* Sender, Word &Key, Classes::TShiftState 
	Shift);

typedef void __fastcall (__closure *TKeyPressEvent)(System::TObject* Sender, char &Key);

typedef short TTabOrder;

struct TCMFocusChanged;
struct TCreateParams;
class __declspec(pascalimplementation) TWinControl : public TControl
{
	typedef TControl inherited;
	
private:
	void *FObjectInstance;
	void *FDefWndProc;
	Classes::TList* FControls;
	Classes::TList* FWinControls;
	Classes::TList* FTabList;
	Graphics::TBrush* FBrush;
	HWND FHandle;
	HWND FParentWindow;
	bool FTabStop;
	bool FCtl3D;
	bool FParentCtl3D;
	bool FShowing;
	int FTabOrder;
	Word FAlignLevel;
	Classes::THelpContext FHelpContext;
	TImeMode FImeMode;
	System::AnsiString FImeName;
	TKeyEvent FOnKeyDown;
	TKeyPressEvent FOnKeyPress;
	TKeyEvent FOnKeyUp;
	Classes::TNotifyEvent FOnEnter;
	Classes::TNotifyEvent FOnExit;
	void __fastcall AlignControl(TControl* AControl);
	TControl* __fastcall GetControl(int Index);
	int __fastcall GetControlCount(void);
	HWND __fastcall GetHandle(void);
	TTabOrder __fastcall GetTabOrder(void);
	HIDESBASE void __fastcall Insert(TControl* AControl);
	void __fastcall InvalidateFrame(void);
	bool __fastcall IsCtl3DStored(void);
	HWND __fastcall PrecedingWindow(TWinControl* Control);
	HIDESBASE void __fastcall Remove(TControl* AControl);
	void __fastcall RemoveFocus(bool Removing);
	void __fastcall SetCtl3D(bool Value);
	void __fastcall SetParentCtl3D(bool Value);
	void __fastcall SetParentWindow(HWND Value);
	void __fastcall SetTabOrder(TTabOrder Value);
	void __fastcall SetTabStop(bool Value);
	HIDESBASE void __fastcall SetZOrderPosition(int Position);
	void __fastcall UpdateTabOrder(TTabOrder Value);
	void __fastcall UpdateBounds(void);
	void __fastcall UpdateShowing(void);
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
	MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
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
	MESSAGE void __fastcall WMNCDestroy(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall WMQueryNewPalette(Messages::TMessage &Message);
	MESSAGE void __fastcall WMPaletteChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall WMWinIniChange(Messages::TMessage &Message);
	MESSAGE void __fastcall WMFontChange(Messages::TMessage &Message);
	MESSAGE void __fastcall WMTimeChange(Messages::TMessage &Message);
	MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMKillFocus(Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMIMEStartComp(Messages::TMessage &Message);
	MESSAGE void __fastcall WMIMEEndComp(Messages::TMessage &Message);
	MESSAGE void __fastcall CMChildKey(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDialogKey(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMDialogChar(Messages::TWMKey &Message);
	MESSAGE void __fastcall CMFocusChanged(TCMFocusChanged &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMCursorChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMParentCtl3DChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowHintChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMEnter(Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMExit(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Messages::TWMMouse &Message);
	MESSAGE void __fastcall CMSysColorChange(Messages::TMessage &Message);
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
	
protected:
	bool FInImeComposition;
	virtual void __fastcall AlignControls(TControl* AControl, Windows::TRect &Rect);
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(TCreateParams &Params);
	void __fastcall CreateSubClass(TCreateParams &Params, char * ControlClassName);
	virtual void __fastcall CreateWindowHandle(const TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall DestroyHandle(void);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall DoEnter(void);
	virtual void __fastcall DoExit(void);
	bool __fastcall DoKeyDown(Messages::TWMKey &Message);
	bool __fastcall DoKeyPress(Messages::TWMKey &Message);
	bool __fastcall DoKeyUp(Messages::TWMKey &Message);
	TWinControl* __fastcall FindNextControl(TWinControl* CurControl, bool GoForward, bool CheckTabStop, 
		bool CheckParent);
	void __fastcall FixupTabList(void);
	virtual void __fastcall GetChildren(Classes::TGetChildProc Proc);
	virtual POINT __fastcall GetClientOrigin(void);
	virtual Windows::TRect __fastcall GetClientRect(void);
	virtual HDC __fastcall GetDeviceContext(HWND &WindowHandle);
	bool __fastcall IsControlMouseMsg(Messages::TWMMouse &Message);
	virtual void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(char &Key);
	void __fastcall MainWndProc(Messages::TMessage &Message);
	void __fastcall NotifyControls(Word Msg);
	void __fastcall PaintControls(HDC DC, TControl* First);
	void __fastcall PaintHandler(Messages::TWMPaint &Message);
	virtual void __fastcall PaintWindow(HDC DC);
	virtual bool __fastcall PaletteChanged(bool Foreground);
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	void __fastcall RecreateWnd(void);
	void __fastcall ResetIme(void);
	bool __fastcall ResetImeComposition(int Action);
	void __fastcall ScaleControls(int M, int D);
	void __fastcall SelectFirst(void);
	void __fastcall SelectNext(TWinControl* CurControl, bool GoForward, bool CheckTabStop);
	virtual void __fastcall SetChildOrder(Classes::TComponent* Child, int Order);
	void __fastcall SetIme(void);
	bool __fastcall SetImeCompositionWindow(HWND hWnd, Graphics::TFont* Font, int XPos, int YPos);
	virtual void __fastcall SetZOrder(bool TopMost);
	virtual void __fastcall ShowControl(TControl* AControl);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	__property bool Ctl3D = {read=FCtl3D, write=SetCtl3D, stored=IsCtl3DStored, nodefault};
	__property void * DefWndProc = {read=FDefWndProc, write=FDefWndProc, nodefault};
	__property TImeMode ImeMode = {read=FImeMode, write=FImeMode, default=3};
	__property System::AnsiString ImeName = {read=FImeName, write=FImeName, nodefault};
	__property bool ParentCtl3D = {read=FParentCtl3D, write=SetParentCtl3D, default=1};
	__property HWND WindowHandle = {read=FHandle, write=FHandle, nodefault};
	__property Classes::TNotifyEvent OnEnter = {read=FOnEnter, write=FOnEnter};
	__property Classes::TNotifyEvent OnExit = {read=FOnExit, write=FOnExit};
	__property TKeyEvent OnKeyDown = {read=FOnKeyDown, write=FOnKeyDown};
	__property TKeyPressEvent OnKeyPress = {read=FOnKeyPress, write=FOnKeyPress};
	__property TKeyEvent OnKeyUp = {read=FOnKeyUp, write=FOnKeyUp};
	
public:
	__fastcall virtual TWinControl(Classes::TComponent* AOwner);
	__fastcall TWinControl(HWND ParentWindow);
	__fastcall virtual ~TWinControl(void);
	void __fastcall Broadcast(void *Message);
	bool __fastcall CanFocus(void);
	bool __fastcall ContainsControl(TControl* Control);
	TControl* __fastcall ControlAtPos(const POINT &Pos, bool AllowDisabled);
	void __fastcall DisableAlign(void);
	void __fastcall EnableAlign(void);
	bool __fastcall Focused(void);
	virtual void __fastcall GetTabOrderList(Classes::TList* List);
	bool __fastcall HandleAllocated(void);
	void __fastcall HandleNeeded(void);
	void __fastcall InsertControl(TControl* AControl);
	virtual void __fastcall Invalidate(void);
	void __fastcall PaintTo(HDC DC, int X, int Y);
	void __fastcall RemoveControl(TControl* AControl);
	void __fastcall Realign(void);
	virtual void __fastcall Repaint(void);
	void __fastcall ScaleBy(int M, int D);
	void __fastcall ScrollBy(int DeltaX, int DeltaY);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall Update(void);
	void __fastcall UpdateControlState(void);
	__property Graphics::TBrush* Brush = {read=FBrush, nodefault};
	__property TControl* Controls[int Index] = {read=GetControl};
	__property int ControlCount = {read=GetControlCount, nodefault};
	__property HWND Handle = {read=GetHandle, nodefault};
	__property HWND ParentWindow = {read=FParentWindow, write=SetParentWindow, nodefault};
	__property bool Showing = {read=FShowing, nodefault};
	__property TTabOrder TabOrder = {read=GetTabOrder, write=SetTabOrder, default=-1};
	__property bool TabStop = {read=FTabStop, write=SetTabStop, default=0};
	
__published:
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=FHelpContext, default=0};
};

struct TCMCancelMode
{
	Cardinal Msg;
	int Unused;
	TControl* Sender;
	long Result;
} ;

struct TCMFocusChanged
{
	Cardinal Msg;
	int Unused;
	TWinControl* Sender;
	long Result;
} ;

struct TCMControlListChange
{
	Cardinal Msg;
	TControl* Control;
	DWord Inserting;
	long Result;
} ;

struct TCMChildKey
{
	Cardinal Msg;
	Word CharCode;
	Word Unused;
	TWinControl* Sender;
	long Result;
} ;

enum TDragMessage { dmDragEnter, dmDragLeave, dmDragMove, dmDragDrop, dmDragCancel, dmFindTarget };

struct TDragRec;
typedef TDragRec *PDragRec;

struct TDragRec
{
	POINT Pos;
	TDragObject* Source;
	void *Target;
} ;

#pragma pack(push, 1)
struct TCMDrag
{
	Cardinal Msg;
	TDragMessage DragMessage;
	Byte Reserved1;
	Word Reserved2;
	TDragRec *DragRec;
	long Result;
} ;
#pragma pack(pop)

class __declspec(delphiclass) EOutOfResources;
class __declspec(pascalimplementation) EOutOfResources : public Sysutils::EOutOfMemory
{
	typedef Sysutils::EOutOfMemory inherited;
	
public:
	/* EOutOfMemory.Destroy */ __fastcall virtual ~EOutOfResources(void) { }
	
public:
	/* Exception.Create */ __fastcall EOutOfResources(const System::AnsiString Msg) : Sysutils::EOutOfMemory(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EOutOfResources(const System::AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::EOutOfMemory(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EOutOfResources(int Ident) : Sysutils::EOutOfMemory(Ident) { }
		
	/* Exception.CreateResFmt */ __fastcall EOutOfResources(int Ident, const System::TVarRec * Args, const 
		int Args_Size) : Sysutils::EOutOfMemory(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EOutOfResources(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::EOutOfMemory(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EOutOfResources(const System::AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::EOutOfMemory(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EOutOfResources(int Ident, int AHelpContext) : Sysutils::EOutOfMemory(
		Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EOutOfResources(int Ident, const System::TVarRec * Args
		, const int Args_Size, int AHelpContext) : Sysutils::EOutOfMemory(Ident, Args, Args_Size, AHelpContext
		) { }
	
};

class __declspec(delphiclass) EInvalidOperation;
class __declspec(pascalimplementation) EInvalidOperation : public Sysutils::Exception
{
	typedef Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ __fastcall EInvalidOperation(const System::AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	/* Exception.CreateFmt */ __fastcall EInvalidOperation(const System::AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ __fastcall EInvalidOperation(int Ident) : Sysutils::Exception(Ident) { }
	/* Exception.CreateResFmt */ __fastcall EInvalidOperation(int Ident, const System::TVarRec * Args, 
		const int Args_Size) : Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateHelp */ __fastcall EInvalidOperation(const System::AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ __fastcall EInvalidOperation(const System::AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	/* Exception.CreateResHelp */ __fastcall EInvalidOperation(int Ident, int AHelpContext) : Sysutils::
		Exception(Ident, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ __fastcall EInvalidOperation(int Ident, const System::TVarRec * Args
		, const int Args_Size, int AHelpContext) : Sysutils::Exception(Ident, Args, Args_Size, AHelpContext
		) { }
	
public:
	/* TObject.Destroy */ __fastcall virtual ~EInvalidOperation(void) { }
	
};

class __declspec(pascalimplementation) TDragObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	void __fastcall MouseMsg(Messages::TMessage &Msg);
	HWND __fastcall Capture(void);
	void __fastcall ReleaseCapture(HWND Handle);
	
protected:
	virtual TCustomImageList* __fastcall GetDragImages(void);
	virtual TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	
public:
	virtual int __fastcall Instance(void);
	virtual System::AnsiString __fastcall GetName(void);
	virtual void __fastcall HideDragImage(void);
	virtual void __fastcall ShowDragImage(void);
public:
	/* TObject.Create */ __fastcall TDragObject(void) : System::TObject() { }
	/* TObject.Destroy */ __fastcall virtual ~TDragObject(void) { }
	
};

class __declspec(delphiclass) TDragControlObject;
class __declspec(pascalimplementation) TDragControlObject : public TDragObject
{
	typedef TDragObject inherited;
	
private:
	TControl* FControl;
	
public:
	virtual TCustomImageList* __fastcall GetDragImages(void);
	virtual TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	
protected:
	__fastcall TDragControlObject(TControl* AControl);
	__property TControl* Control = {read=FControl, nodefault};
	virtual void __fastcall HideDragImage(void);
	virtual void __fastcall ShowDragImage(void);
public:
	/* TObject.Destroy */ __fastcall virtual ~TDragControlObject(void) { }
	
};

class __declspec(delphiclass) TControlCanvas;
class __declspec(pascalimplementation) TControlCanvas : public Graphics::TCanvas
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
	__property TControl* Control = {read=FControl, write=SetControl, nodefault};
public:
	/* TCanvas.Create */ __fastcall TControlCanvas(void) : Graphics::TCanvas() { }
	
};

typedef System::TMetaClass*TControlClass;

struct TCreateParams
{
	char *Caption;
	long Style;
	long ExStyle;
	int X;
	int Y;
	int Width;
	int Height;
	HWND WndParent;
	void *Param;
	WNDCLASSA WindowClass;
	char WinClassName[64];
} ;

class __declspec(delphiclass) TGraphicControl;
class __declspec(pascalimplementation) TGraphicControl : public TControl
{
	typedef TControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall Paint(void);
	__property Graphics::TCanvas* Canvas = {read=FCanvas, nodefault};
	
public:
	__fastcall virtual TGraphicControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TGraphicControl(void);
};

class __declspec(delphiclass) TCustomControl;
class __declspec(pascalimplementation) TCustomControl : public TWinControl
{
	typedef TWinControl inherited;
	
private:
	Graphics::TCanvas* FCanvas;
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall Paint(void);
	virtual void __fastcall PaintWindow(HDC DC);
	__property Graphics::TCanvas* Canvas = {read=FCanvas, nodefault};
	
public:
	__fastcall virtual TCustomControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomControl(void);
public:
	/* TWinControl.CreateParented */ __fastcall TCustomControl(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	
};

class __declspec(delphiclass) THintWindow;
class __declspec(pascalimplementation) THintWindow : public TCustomControl
{
	typedef TCustomControl inherited;
	
private:
	MESSAGE void __fastcall CMTextChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(TCreateParams &Params);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual THintWindow(Classes::TComponent* AOwner);
	virtual void __fastcall ActivateHint(const Windows::TRect &Rect, const System::AnsiString AHint);
	virtual bool __fastcall IsHintMsg(MSG &Msg);
	void __fastcall ReleaseHandle(void);
	__property Caption ;
	__property Color ;
	__property Canvas ;
public:
	/* TCustomControl.Destroy */ __fastcall virtual ~THintWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ __fastcall THintWindow(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	
};

typedef System::TMetaClass*THintWindowClass;

class __declspec(delphiclass) TChangeLink;
class __declspec(pascalimplementation) TChangeLink : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TCustomImageList* FSender;
	Classes::TNotifyEvent FOnChange;
	
public:
	__fastcall virtual ~TChangeLink(void);
	virtual void __fastcall Change(void);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TCustomImageList* Sender = {read=FSender, write=FSender, nodefault};
public:
	/* TObject.Create */ __fastcall TChangeLink(void) : System::TObject() { }
	
};

enum TDrawingStyle { dsFocus, dsSelected, dsNormal, dsTransparent };

enum TImageType { itImage, itMask };

enum TResType { rtBitmap, rtCursor, rtIcon };

typedef Shortint TOverlay;

enum TLoadResource { lrDefaultColor, lrDefaultSize, lrFromFile, lrMap3DColors, lrTransparent, lrMonoChrome 
	};

typedef Set<TLoadResource, lrDefaultColor, lrMonoChrome>  TLoadResources;

class __declspec(pascalimplementation) TCustomImageList : public Classes::TComponent
{
	typedef Classes::TComponent inherited;
	
private:
	int FHeight;
	int FWidth;
	int FAllocBy;
	int FHandle;
	TDrawingStyle FDrawingStyle;
	bool FMasked;
	bool FShareImages;
	TImageType FImageType;
	Graphics::TColor FBkColor;
	Graphics::TColor FBlendColor;
	Classes::TList* FClients;
	HWND FDragHandle;
	bool FDragging;
	TCursor FDragCursor;
	Graphics::TBitmap* FBitmap;
	Classes::TNotifyEvent FOnChange;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall InitBitmap(void);
	void __fastcall CheckImage(Graphics::TGraphic* Image);
	void __fastcall CombineDragCursor(void);
	void __fastcall CopyImages(int Value);
	void __fastcall CreateImageList(void);
	void __fastcall FreeHandle(void);
	int __fastcall GetCount(void);
	Graphics::TColor __fastcall GetBkColor(void);
	int __fastcall GetHandle(void);
	HBITMAP __fastcall GetImageHandle(Graphics::TBitmap* Image);
	void __fastcall InsertImage(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask, Graphics::TColor 
		MaskColor);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall SetBkColor(Graphics::TColor Value);
	void __fastcall SetDragCursor(TCursor Value);
	void __fastcall SetHandle(int Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetNewDimensions(int Value);
	void __fastcall SetWidth(int Value);
	void __fastcall WriteData(Classes::TStream* Stream);
	
protected:
	virtual void __fastcall Change(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall GetImages(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void __fastcall HandleNeeded(void);
	void __fastcall Initialize(void);
	__property Graphics::TColor BlendColor = {read=FBlendColor, write=FBlendColor, default=536870911};
	__property Graphics::TColor BkColor = {read=GetBkColor, write=SetBkColor, default=536870911};
	__property int AllocBy = {read=FAllocBy, write=FAllocBy, default=4};
	__property TDrawingStyle DrawingStyle = {read=FDrawingStyle, write=FDrawingStyle, default=2};
	__property int Height = {read=FHeight, write=SetHeight, default=16};
	__property TImageType ImageType = {read=FImageType, write=FImageType, default=0};
	__property bool Masked = {read=FMasked, write=FMasked, default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property bool ShareImages = {read=FShareImages, write=FShareImages, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=16};
	
public:
	__fastcall virtual TCustomImageList(Classes::TComponent* AOwner);
	__fastcall TCustomImageList(int AWidth, int AHeight);
	__fastcall virtual ~TCustomImageList(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall Add(Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	int __fastcall AddIcon(Graphics::TIcon* Image);
	void __fastcall AddImages(TCustomImageList* Value);
	int __fastcall AddMasked(Graphics::TBitmap* Image, Graphics::TColor MaskColor);
	bool __fastcall BeginDrag(HWND Window, int X, int Y);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	bool __fastcall DragLock(HWND Window, int XPos, int YPos);
	bool __fastcall DragMove(int X, int Y);
	void __fastcall DragUnlock(void);
	void __fastcall Draw(Graphics::TCanvas* Canvas, int X, int Y, int Index);
	void __fastcall DrawOverlay(Graphics::TCanvas* Canvas, int X, int Y, int ImageIndex, TOverlay Overlay
		);
	bool __fastcall EndDrag(void);
	bool __fastcall FileLoad(TResType ResType,  System::AnsiString Name, Graphics::TColor MaskColor);
	void __fastcall GetBitmap(int Index, Graphics::TBitmap* Image);
	POINT __fastcall GetHotSpot(void);
	void __fastcall GetIcon(int Index, Graphics::TIcon* Image);
	HBITMAP __fastcall GetImageBitmap(void);
	HBITMAP __fastcall GetMaskBitmap(void);
	bool __fastcall GetResource(TResType ResType,  System::AnsiString Name, int Width, TLoadResources LoadFlags
		, Graphics::TColor MaskColor);
	bool __fastcall HandleAllocated(void);
	void __fastcall HideDragImage(void);
	HIDESBASE void __fastcall Insert(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void __fastcall InsertIcon(int Index, Graphics::TIcon* Image);
	void __fastcall InsertMasked(int Index, Graphics::TBitmap* Image, Graphics::TColor MaskColor);
	void __fastcall Move(int CurIndex, int NewIndex);
	bool __fastcall Overlay(int ImageIndex, TOverlay Overlay);
	void __fastcall RegisterChanges(TChangeLink* Value);
	bool __fastcall ResourceLoad(TResType ResType,  System::AnsiString Name, Graphics::TColor MaskColor
		);
	void __fastcall Replace(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void __fastcall ReplaceIcon(int Index, Graphics::TIcon* Image);
	void __fastcall ReplaceMasked(int Index, Graphics::TBitmap* NewImage, Graphics::TColor MaskColor);
	bool __fastcall SetDragImage(int Index, int HotSpotX, int HotSpotY);
	void __fastcall ShowDragImage(void);
	void __fastcall UnRegisterChanges(TChangeLink* Value);
	__property int Count = {read=GetCount, nodefault};
	__property TCursor DragCursor = {read=FDragCursor, write=SetDragCursor, nodefault};
	__property bool Dragging = {read=FDragging, nodefault};
	__property int Handle = {read=GetHandle, write=SetHandle, nodefault};
};

class __declspec(delphiclass) TImageList;
class __declspec(pascalimplementation) TImageList : public TCustomImageList
{
	typedef TCustomImageList inherited;
	
__published:
	__property BlendColor ;
	__property BkColor ;
	__property AllocBy ;
	__property DrawingStyle ;
	__property Height ;
	__property ImageType ;
	__property Masked ;
	__property OnChange ;
	__property ShareImages ;
	__property Width ;
public:
	/* TCustomImageList.Create */ __fastcall virtual TImageList(Classes::TComponent* AOwner) : Controls::
		TCustomImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ __fastcall TImageList(int AWidth, int AHeight) : Controls::TCustomImageList(
		AWidth, AHeight) { }
	/* TCustomImageList.Destroy */ __fastcall virtual ~TImageList(void) { }
	
};

//-- var, const, procedure ---------------------------------------------------
#define CM_BASE (int)(45056)
#define CM_ACTIVATE (int)(45056)
#define CM_DEACTIVATE (int)(45057)
#define CM_GOTFOCUS (int)(45058)
#define CM_LOSTFOCUS (int)(45059)
#define CM_CANCELMODE (int)(45060)
#define CM_DIALOGKEY (int)(45061)
#define CM_DIALOGCHAR (int)(45062)
#define CM_FOCUSCHANGED (int)(45063)
#define CM_PARENTFONTCHANGED (int)(45064)
#define CM_PARENTCOLORCHANGED (int)(45065)
#define CM_HITTEST (int)(45066)
#define CM_VISIBLECHANGED (int)(45067)
#define CM_ENABLEDCHANGED (int)(45068)
#define CM_COLORCHANGED (int)(45069)
#define CM_FONTCHANGED (int)(45070)
#define CM_CURSORCHANGED (int)(45071)
#define CM_CTL3DCHANGED (int)(45072)
#define CM_PARENTCTL3DCHANGED (int)(45073)
#define CM_TEXTCHANGED (int)(45074)
#define CM_MOUSEENTER (int)(45075)
#define CM_MOUSELEAVE (int)(45076)
#define CM_MENUCHANGED (int)(45077)
#define CM_APPKEYDOWN (int)(45078)
#define CM_APPSYSCOMMAND (int)(45079)
#define CM_BUTTONPRESSED (int)(45080)
#define CM_SHOWINGCHANGED (int)(45081)
#define CM_ENTER (int)(45082)
#ifndef CM_EXIT
#define CM_EXIT (int)(45083)
#endif
#define CM_DESIGNHITTEST (int)(45084)
#define CM_ICONCHANGED (int)(45085)
#define CM_WANTSPECIALKEY (int)(45086)
#define CM_INVOKEHELP (int)(45087)
#define CM_WINDOWHOOK (int)(45088)
#define CM_RELEASE (int)(45089)
#define CM_SHOWHINTCHANGED (int)(45090)
#define CM_PARENTSHOWHINTCHANGED (int)(45091)
#define CM_SYSCOLORCHANGE (int)(45092)
#define CM_WININICHANGE (int)(45093)
#define CM_FONTCHANGE (int)(45094)
#define CM_TIMECHANGE (int)(45095)
#define CM_TABSTOPCHANGED (int)(45096)
#define CM_UIACTIVATE (int)(45097)
#define CM_UIDEACTIVATE (int)(45098)
#define CM_DOCWINDOWACTIVATE (int)(45099)
#define CM_CONTROLLISTCHANGE (int)(45100)
#define CM_GETDATALINK (int)(45101)
#define CM_CHILDKEY (int)(45102)
#define CM_DRAG (int)(45103)
#define CM_HINTSHOW (int)(45104)
#define CM_DIALOGHANDLE (int)(45105)
#define CM_ISTOOLCONTROL (int)(45106)
#define CM_RECREATEWND (int)(45107)
#define CM_INVALIDATE (int)(45108)
#define CN_BASE (int)(48128)
#define CN_CHARTOITEM (int)(48175)

#ifndef CN_COMMAND
#define CN_COMMAND (int)(48401)
#endif

#define CN_COMPAREITEM (int)(48185)
#define CN_CTLCOLORBTN (int)(48437)
#define CN_CTLCOLORDLG (int)(48438)
#define CN_CTLCOLOREDIT (int)(48435)
#define CN_CTLCOLORLISTBOX (int)(48436)
#define CN_CTLCOLORMSGBOX (int)(48434)
#define CN_CTLCOLORSCROLLBAR (int)(48439)
#define CN_CTLCOLORSTATIC (int)(48440)
#define CN_DELETEITEM (int)(48173)
#define CN_DRAWITEM (int)(48171)
#define CN_HSCROLL (int)(48404)
#define CN_MEASUREITEM (int)(48172)
#define CN_PARENTNOTIFY (int)(48656)
#define CN_VKEYTOITEM (int)(48174)
#define CN_VSCROLL (int)(48405)
#define CN_KEYDOWN (int)(48384)
#define CN_KEYUP (int)(48385)
#define CN_CHAR (int)(48386)
#define CN_SYSKEYDOWN (int)(48388)
#define CN_SYSCHAR (int)(48390)
#define CN_NOTIFY (int)(48206)
#define mrNone (Byte)(0)
#define mrOk (Byte)(1)
#define mrCancel (Byte)(2)
#define mrAbort (Byte)(3)
#define mrRetry (Byte)(4)
#define mrIgnore (Byte)(5)
#define mrYes (Byte)(6)
#define mrNo (Byte)(7)
#define mrAll (Byte)(8)
#define crDefault (TCursor)(0)
#define crNone (TCursor)(-1)
#define crArrow (TCursor)(-2)
#define crCross (TCursor)(-3)
#define crIBeam (TCursor)(-4)
#define crSize (TCursor)(-5)
#define crSizeNESW (TCursor)(-6)
#define crSizeNS (TCursor)(-7)
#define crSizeNWSE (TCursor)(-8)
#define crSizeWE (TCursor)(-9)
#define crUpArrow (TCursor)(-10)
#define crHourGlass (TCursor)(-11)
#define crDrag (TCursor)(-12)
#define crNoDrop (TCursor)(-13)
#define crHSplit (TCursor)(-14)
#define crVSplit (TCursor)(-15)
#define crMultiDrag (TCursor)(-16)
#define crSQLWait (TCursor)(-17)
#define crNo (TCursor)(-18)
#define crAppStart (TCursor)(-19)
#define crHelp (TCursor)(-20)
extern TWinControl* CreationControl;
extern bool NewStyleControls;
extern long __stdcall InitWndProc(HWND HWindow, long Message, long WParam, long LParam);
extern TWinControl* __fastcall FindControl(HWND Handle);
extern long __fastcall SendAppMessage(Cardinal Msg, long WParam, long LParam);
extern System::AnsiString __fastcall CursorToString(TCursor Cursor);
extern TCursor __fastcall StringToCursor(const System::AnsiString S);
extern void __fastcall GetCursorValues(Classes::TGetStrProc Proc);
extern bool __fastcall CursorToIdent(long Cursor,  System::AnsiString &Ident);
extern bool __fastcall IdentToCursor(const System::AnsiString Ident, long &Cursor);
extern System::AnsiString __fastcall GetShortHint(const System::AnsiString Hint);
extern System::AnsiString __fastcall GetLongHint(const System::AnsiString Hint);
extern TControl* __fastcall GetCaptureControl(void);
extern void __fastcall SetCaptureControl(TControl* Control);
extern bool __fastcall IsDragObject(System::TObject* Sender);
extern void __fastcall CancelDrag(void);
extern TWinControl* __fastcall FindVCLWindow(const POINT &Pos);
extern TControl* __fastcall FindDragTarget(const POINT &Pos, bool AllowDisabled);
extern void __fastcall MoveWindowOrg(HDC DC, int DX, int DY);
extern bool __fastcall Win32NLSEnableIME(HWND Handle, bool Enable);
extern void __fastcall SetImeMode(HWND Handle, TImeMode Mode);
extern int __fastcall Imm32GetContext(HWND hWnd);
extern bool __fastcall Imm32ReleaseContext(HWND hWnd, int hImc);
extern bool __fastcall Imm32GetConversionStatus(int hImc, int &Conversion, int &Sentence);
extern bool __fastcall Imm32SetConversionStatus(int hImc, int Conversion, int Sentence);
extern bool __fastcall Imm32SetOpenStatus(int hImc, bool fOpen);
extern bool __fastcall Imm32SetCompositionWindow(int hImc, Imm::PCompositionForm lpCompForm);
extern bool __fastcall Imm32SetCompositionFont(int hImc, Windows::PLogFontA lpLogfont);
extern long __fastcall Imm32GetCompositionString(int hImc, int dWord1, void * lpBuf, int dwBufLen);
extern bool __fastcall Imm32IsIME(HKL hKl);
extern bool __fastcall Imm32NotifyIME(int hImc, int dwAction, int dwIndex, int dwValue);
//-- template instantiations -------------------------------------------------
template class TLoadResources ;
template class TScalingFlags ;
template class TControlState ;
template class TControlStyle ;

}	/* namespace Controls */

#pragma warn .par
#pragma warn .hid 
#pragma warn .inl

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Controls;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// Controls
