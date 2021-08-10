//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.38  $
//
// Base window class TWindow definition, including HWND encapsulation.
//----------------------------------------------------------------------------
#if !defined(OWL_WINDOW_H)
#define OWL_WINDOW_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(WINSYS_WSYSCLS_H)
# include <winsys/wsyscls.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif
#if !defined(OWL_CLIPBOAR_H)
# include <owl/clipboar.h>
#endif
#if !defined(OWL_WINDOWEV_H)
# include <owl/windowev.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif
#include <owl/window.rh>

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TApplication;
class _OWLCLASS TModule;
class _OWLCLASS TScroller;
class _OWLCLASS TRegion;
class _OWLCLASS TWindow;
class _OWLCLASS TDC;
class _OWLCLASS TNotify;
class _OWLCLASS_RTL TXWindow;


//
// enum TWindowFlag
// ~~~~ ~~~~~~~~~~~
enum TWindowFlag {
  wfAlias           = 0x0001, // TWindow is an alias to a preexisting HWND
  wfAutoCreate      = 0x0002, // Create the HWND when our parent is created
  wfFromResource    = 0x0004, // Handle comes from HWND created from resource
  wfShrinkToClient  = 0x0008, // Shrink a frame window to its client's size
  wfMainWindow      = 0x0010, // This frame window is the main window
  wfFullyCreated    = 0x0020, // Window is fully created & not being destroyed
  wfStreamTop       = 0x0040, // This window is the topmost one to stream
  wfPredefinedClass = 0x0080, // Window class used was not defined by Owl
  wfTransfer        = 0x0100, // Transfer enabled
  wfUnHidden        = 0x0200, // Used temporarily when destroying MDI child
  wfUnDisabled      = 0x0400, // Used temporarily when destroying MDI child
  wfDeleteOnClose   = 0x0800, // Window is condemned on EvClose
  wfPropagateIdle   = 0x1000, // Pass down IdleAction
  wfModalWindow     = 0x2000, // Was created via TWindow::Execute
  wfDetached        = 0x4000, // Window handle has been detached
  wfInsertAtEdge    = 0x8000  // (Decoration) Window to be inserted against frame's edge
};

//
// enum TTransferDirection
// ~~~~ ~~~~~~~~~~~~~~~~~~
// Transfer function flags
//
enum TTransferDirection {
  tdGetData,    // Get data from the window into the buffer
  tdSetData,    // Set data from the buffer into the window
  tdSizeData    // Just query the window data size in bytes
};

//
// enum TEventStatus
// ~~~~ ~~~~~~~~~~~~
// Mixin window event implementation return status
//
enum TEventStatus {
  esPartial,    // Additional handlers may be invoked
  esComplete    // No additional handlers are needed
};

//
// Special background color flags for EvEraseBkgnd processing
//
#define NoColor TColor::None        // let DefWindowProc erase
#define NoErase TColor::Transparent // don't erase, wait for Paint

//
// Windows 3.1 windowsx.h name confict with TWindows::GetFirstChild()
//
#if defined(GetFirstChild)
# undef GetFirstChild(hwnd)
#endif

//----------------------------------------------------------------------------

//
// Member and non-member action and conditional function types used with
// ForEach and FirstThat.
//
typedef void (*TActionFunc)(TWindow* win, void* param);
typedef bool (*TCondFunc)(TWindow* win, void* param);

#if defined(BI_COMP_MSC)
# pragma pointers_to_members(full_generality, virtual_inheritance)
#endif

typedef void (TWindow::*TActionMemFunc)(TWindow* win, void* param);
typedef bool (TWindow::*TCondMemFunc)(TWindow* win, void* param);

typedef TResult (CALLBACK *TThunkProc)(HWND, uint, TParam1, TParam2);

//----------------------------------------------------------------------------

//
// class TCommandEnabler
// ~~~~~ ~~~~~~~~~~~~~~~
// Base class for an extensible interface for auto enabling/disabling of
// commands (menu items, tool bar buttons, ...)
//
#if defined(BI_NO_RTTI)
class _OWLCLASS TCommandEnabler : public TStreamableBase {
#else
class _OWLCLASS TCommandEnabler {
#endif
  public:
    TCommandEnabler(uint id, HWND hWndReceiver = 0);

    uint GetId() const;

    virtual void  Enable(bool enable = true);        // Also sets Handled
    virtual void  SetText(const char far* text) = 0;

    // Enumeration describing the 3-states or availability of a command
    //
    enum TCommandState {
      Unchecked,          // Command is not enabled
      Checked,            // Command is enabled
      Indeterminate       // Command is unavaiable
    };

    virtual void  SetCheck(int check) = 0;           // Pass one of above enum

    bool        SendsCommand() const;

    bool        GetHandled();

    bool        IsReceiver(HWND hReceiver);
    HWND        GetReceiver() const;
    void        SetReceiver(HWND hReceiver);

  protected:
    void        SetHandled();

  public_data:
    const uint  Id;

  protected_data:
    HWND  HWndReceiver;

    // Enumeration describing whether the associated command has been
    // enabled or disabled, and whether the command generates WM_COMMAND
    // messages.
    //
    enum TCommandStatus {
      WasHandled = 1,       // Command was enabled or disabled
      NonSender = 2         // Command does not generate WM_COMMAND messages
    };

    union {
#if defined(OWL2_COMPAT)
      uint        Handled; // Old name
#endif
      uint        Flags;   // New name
    };

  DECLARE_CASTABLE;
};

//
// struct TWindowsAttr
// ~~~~~~ ~~~~~~~~~~~~
// Window *Creation* attributes. Don't rely on these to track once Handle
// has been created, use member functions to access information.
//
struct TWindowAttr {
    uint32     Style;
    uint32     ExStyle;
    int        X;
    int        Y;
    int        W;
    int        H;
    TResId     Menu;        // Menu resource id
    int        Id;          // Child identifier
    char far*  Param;
    TResId     AccelTable;  // Accelerator table resource id
};

//
// class TWindow
// ~~~~~ ~~~~~~~
class _OWLCLASS TWindow : virtual public TEventHandler,
                          virtual public TStreamableBase {
  public:
    // Class scoped types
    //
    typedef HWND THandle;  // TWindow encapsulates an HWND

    // Constructors and destructor for TWindow
    //
    TWindow(TWindow* parent, const char far* title = 0, TModule* module = 0);
    TWindow(HWND handle, TModule* module = 0);

    virtual ~TWindow();

    // Two iterators that take function pointers
    //
    TWindow*          FirstThat(TCondFunc test, void* paramList = 0) const;
    void              ForEach(TActionFunc action, void* paramList = 0);

    // Two iterators that take pointers to member functions
    //
    TWindow*          FirstThat(TCondMemFunc test, void* paramList = 0);
    void              ForEach(TActionMemFunc action, void* paramList = 0);

    // Other functions for iteration
    //
    TWindow*          Next();
    void              SetNext(TWindow* next);
    TWindow*          GetFirstChild();
    TWindow*          GetLastChild();
    TWindow*          Previous();
    uint              NumChildren() const;   // Number of child windows

    // Query and set the Owl window flags. Accepts TWindowFlag args, possibly
    // or'd together.
    //
    void              SetFlag(uint mask);
    void              ClearFlag(uint mask);
    bool              IsFlagSet(uint mask);

    // Sets/clears flag which indicates that the TWindow should be
    // created if a create is sent while in the parent's child list
    //
    void              EnableAutoCreate();
    void              DisableAutoCreate();

    // Sets/clears flag which indicates that the TWindow can/will transfer data
    // via the transfer mechanism
    //
    void              EnableTransfer();
    void              DisableTransfer();

    // Window's default module access functions
    //
    TModule*          GetModule() const;
    void              SetModule(TModule* module);

    TApplication*     GetApplication() const;
    WNDPROC           GetThunk() const;
    virtual bool      Register();

    TScroller*        GetScroller();
    void              SetScroller(TScroller* scroller);

    // Create/destroy an native window to be associated with this window
    //
    virtual bool      Create();
    virtual void      PerformCreate(int menuOrId);
    bool              CreateChildren();
    virtual void      Destroy(int retVal = 0);

    // Create a modal window, and perform actual modal execute call
    //
    virtual int       Execute();
    virtual int       DoExecute();

    // Request this window to close itself
    //
    virtual void      CloseWindow(int retVal = 0);

    // Unconditionally shut down a given window. Destroy() is called to
    // destroy the Handle, & then the window is deleted. Non-static version
    // is safe as long as it is inline and not called on itself
    //
    static void       ShutDownWindow(TWindow* win, int retVal = 0);
    void              ShutDownWindow(int retVal = 0);

    // Attach or detach a window handle to a TWindow object.  Used when
    // a child re-creates itself.
    //
    void              AttachHandle(HWND handle);
    void              DetachHandle();

#if defined(BI_MULTI_THREAD_RTL)
    // Override TEventHandler::Dispatch() to handle multi-thread
    // synchronization
    //
    virtual TResult  Dispatch(TEventInfo& info, TParam1 wp, TParam2 lp = 0);
#endif

    // Called from TApplication::ProcessAppMsg() to give the window an
    // opportunity to perform preprocessing of the Windows message
    //
    virtual bool      PreProcessMsg(MSG& msg);
    virtual bool      IdleAction(long idleCount);
    virtual bool      HoldFocusHWnd(HWND hLose, HWND hGain);

    // Child and parenting
    //
    int               GetId() const;
    TWindow*          ChildWithId(int id) const;

    // Get this window's parent. Either the handle of native window, or a
    // pointer to the OWL object. May return different objects in some cases.
    // Use H & O varieties to avoid change across version
    //
    HWND           GetParentH() const; // Native handle version
    TWindow*          GetParentO() const; // OWL object version
#if defined(OWL2_COMPAT)
    HWND           GetParent() const;  // Old version -- returns handle
#else
    TWindow*          GetParent();        // New version -- returns object
#endif

    virtual void      SetParent(TWindow* newParent);

    // Other attributes
    //
    virtual bool      SetDocTitle(const char far* docname, int index);
    void              SetCaption(const char far* title);
    bool              SetCursor(TModule* module, TResId resId);
    void              SetBkgndColor(const TColor& color);
    void              SetAcceleratorTable(TResId resId);

    // Can close virtual tests whether all children and this window are ready
    // and able to close
    //
    virtual bool      CanClose();

    // Forwards the current event to "handle" using either PostMessage() or
    // SendMessage(). Owl window version calls directly to window proc on send.
    //
    TResult           ForwardMessage(HWND handle, bool send = true);
    TResult           ForwardMessage(bool send = true);

    // Send message to all children
    //
    void              ChildBroadcastMessage(uint msg, TParam1 wParam=0, TParam2 lParam=0);

    // Notify a window (parent usually) of a child action.
    //
    void              SendNotification(int id, int notifyCode, HWND hCtl,
                                       uint msg = WM_COMMAND);
    void              SendNotification(HWND receiver, int id,
                                       int notifyCode, HWND hCtl,
                                       uint msg = WM_COMMAND);
    uint32            SendNotification(int id, NMHDR& nmhdr,
                                       uint msg = WM_NOTIFY);
    uint32            SendNotification(HWND receiver, uint id,
                                       NMHDR& nmhdr, uint msg = WM_NOTIFY);

    // Called from StdWndProc to allow exceptions to be caught and suspended.
    // Calls HandleMessage from within try block. Catches and suspends all
    // exceptions before returning to Windows (Windows is not exception safe).
    //
    TResult           ReceiveMessage(uint msg, TParam1 p1 = 0, TParam2 p2 = 0);

    // Call a Window's window proc to handle a message. Similar to SendMessage
    // but goes directly to Owl window, bypassing windows.
    //
    TResult           HandleMessage(uint msg, TParam1 p1 = 0, TParam2 p2 = 0);

    // Virtual functions called to handle a message, and to deal with an
    // unhandled message in a default way.
    //
    virtual TResult   WindowProc(uint msg, TParam1 p1, TParam2 p2);
    virtual TResult   DefWindowProc(uint msg, TParam1 p1, TParam2 p2);

    // Called by WindowProc() to handle WM_COMMANDs
    //
    virtual TResult   EvCommand(uint id, HWND hWndCtl, uint notifyCode);

    // Called by WindowProc() to handle WM_NOTIFYs
    //
    virtual TResult   EvNotify(uint id, TNotify far& notifyInfo);

    // Called by WindowProc() to handle WM_COMMAND_ENABLE, & helper function
    //
    virtual void      EvCommandEnable(TCommandEnabler& ce);
    void              RouteCommandEnable(HWND hInitCmdTarget, TCommandEnabler& ce);

    // Default processing, deals with special cases or calls DefWindowProc
    //
    TResult           DefaultProcessing();

    // Paint function called by base classes when responding to WM_PAINT
    //
    virtual void      Paint(TDC& dc, bool erase, TRect& rect);

    // Transfer buffer functionality
    //
    void              SetTransferBuffer(void* transferBuffer);
    virtual uint      Transfer(void* buffer, TTransferDirection direction);
    virtual void      TransferData(TTransferDirection direction);

    // Installs the thunk as the window function and saves the previous window
    // function in "DefaultProc"
    //
    void              SubclassWindowFunction();

    //-----------------------------------
    // Encapsulated native HWND functions inline
    //

    // Allow a TWindow& to be used as an HWND in Windows API calls
    //
    HWND           GetHandle() const;
    operator          HWND() const;
    bool              IsWindow() const;

    // Messages
    //
    TResult           SendMessage(uint msg, TParam1 p1 = 0, TParam2 p2 = 0);
    TResult           SendDlgItemMessage(int childId, uint msg, TParam1 p1 = 0,
                                         TParam2 p2 = 0);
    bool              PostMessage(uint msg, TParam1 p1 = 0, TParam2 p2 = 0);
    static HWND    GetCapture();
    HWND           SetCapture();
    static void       ReleaseCapture();
    static HWND    GetFocus();
    HWND           SetFocus();
    bool              IsWindowEnabled() const;
    virtual bool      EnableWindow(bool enable);
    void              SetRedraw(bool redraw);

    // Window coordinates, dimensions...
    //
    void              ScreenToClient(TPoint& point) const;
    void              MapWindowPoints(HWND hWndTo, TPoint* pts, int count) const;
    void              GetClientRect(TRect& rect) const;
    TRect             GetClientRect() const;
    static HWND    WindowFromPoint(const TPoint& point);
    HWND           ChildWindowFromPoint(const TPoint& point) const;
    void              ClientToScreen(TPoint& point) const;
    void              GetWindowRect(TRect& rect) const;
    TRect             GetWindowRect() const;
    static void       AdjustWindowRect(TRect& rect, uint32 style, bool menu);
    static void       AdjustWindowRectEx(TRect& rect, uint32 style,
                                         bool  menu,  uint32 exStyle);

    // Window and class Words and Longs, window properties
    //
    long              GetClassName(char far* className, int maxCount) const;
    long              GetClassLong(int index) const;
    long              SetClassLong(int index, long newLong);
    uint16            GetClassWord(int index) const;
    uint16            SetClassWord(int index, uint16 newWord);
    long              GetWindowLong(int index) const;
    long              SetWindowLong(int index, long newLong);
    uint16            GetWindowWord(int index) const;
    uint16            SetWindowWord(int index, uint16 newWord);
    WNDPROC           GetWindowProc() const;
    WNDPROC           SetWindowProc(WNDPROC wndProc);
    int               EnumProps(PROPENUMPROC proc);
    HANDLE            GetProp(uint16 atom) const;
    HANDLE            RemoveProp(uint16 atom) const;
    bool              SetProp(uint16 atom, HANDLE data) const;
    HANDLE            GetProp(const char far* str) const;
    HANDLE            RemoveProp(const char far* str) const;
    bool              SetProp(const char far* str, HANDLE data) const;

    // Dual mode accessors. Work with Attr and other members as well as the
    // underlying window information
    //
    uint32            GetStyle() const;
    uint32            SetStyle(uint32 style);
    uint32            GetExStyle() const;
    uint32            SetExStyle(uint32 style);
    bool              ModifyStyle(uint32 offBits, uint32 onBits,
                                  uint swpFlags = 0);
    bool              ModifyExStyle(uint32 offBits, uint32 onBits,
                                    uint swpFlags = 0);

    // Window placement(X,Y) and display
    //
    bool              MoveWindow(int x, int y, int w, int h, bool repaint = false);
    bool              MoveWindow(const TRect& rect, bool repaint = false);
    virtual bool      ShowWindow(int cmdShow);
    void              ShowOwnedPopups(bool show);
    bool              IsWindowVisible() const;
    bool              IsZoomed() const;
    bool              IsIconic() const;
    int               GetWindowTextLength() const;
    int               GetWindowText(char far* str, int maxCount) const;
    void              SetWindowText(const char far* str);
    bool              GetWindowPlacement(WINDOWPLACEMENT* place) const;
    bool              SetWindowPlacement(const WINDOWPLACEMENT* place);

    // Window positioning(Z), sibling relationships
    //
    void              BringWindowToTop();
    static HWND    GetActiveWindow();
    HWND           SetActiveWindow();
    static HWND    GetDesktopWindow();
#if defined(BI_PLAT_WIN16)
    static HWND    GetSysModalWindow();
    HWND           SetSysModalWindow();
#endif
    HWND           GetLastActivePopup() const;
    HWND           GetNextWindow(uint dirFlag) const;
    HWND           GetTopWindow() const;
    HWND           GetWindow(uint cmd) const;
    bool              SetWindowPos(HWND      hWndInsertAfter,
                                   const TRect& rect,
                                   uint         flags);
    bool              SetWindowPos(HWND      hWndInsertAfter,
                                   int x, int y, int w, int h,
                                   uint         flags);

    // Window painting: invalidating, validating & updating
    //
    void              Invalidate(bool erase = true);
    void              InvalidateRect(const TRect& rect, bool erase = true);
    void              InvalidateRgn(HRGN hRgn, bool erase = true);
    void              Validate();
    void              ValidateRect(const TRect& rect);
    void              ValidateRgn(HRGN hRgn);
    void              UpdateWindow();
    bool              FlashWindow(bool invert);
    bool              GetUpdateRect(TRect& rect, bool erase = true) const;
    bool              GetUpdateRgn(TRegion& rgn, bool erase = true) const;
    bool              LockWindowUpdate();
    bool              RedrawWindow(TRect* update,
                                   HRGN   hUpdateRgn,
                                   uint   redrawFlags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

    // Scrolling and scrollbars
    //
    int               GetScrollPos(int bar) const;
    int               SetScrollPos(int bar, int pos, bool redraw = true);
    void              GetScrollRange(int bar, int& minPos, int& maxPos) const;
    void              SetScrollRange(int  bar,
                                     int  minPos,
                                     int  maxPos,
                                     bool redraw = true);
    void              SetScrollPage(int bar, int page, bool redraw = true);
    int               GetScrollPage(int bar) const;
    bool              EnableScrollBar(uint sbFlags=SB_BOTH,
                                      uint arrowFlags=ESB_ENABLE_BOTH);
    void              ShowScrollBar(int bar, bool show = true);
    void              ScrollWindow(int              dx,
                                   int              dy,
                                   const TRect far* scroll = 0,
                                   const TRect far* clip = 0);
    void              ScrollWindowEx(int              dx,
                                     int              dy,
                                     const TRect far* scroll = 0,
                                     const TRect far* clip = 0,
                                     HRGN             hUpdateRgn = 0,
                                     TRect far*       update = 0,
                                     uint             flags = 0);
#if defined(BI_PLAT_WIN32)
    void              SetScrollInfo(int bar, SCROLLINFO* scrollInfo,
                                    bool redraw = true);
    void              GetScrollInfo(int bar, SCROLLINFO* scrollInfo) const;
#endif

    // Parent/child with Ids
    //
    int               GetDlgCtrlID() const;
    HWND           GetDlgItem(int childId) const;
    uint              GetDlgItemInt(int   childId,
                                    bool* translated = 0,
                                    bool  isSigned = true) const;
    void              SetDlgItemInt(int  childId,
                                    uint value,
                                    bool isSigned = true) const;
    int               GetDlgItemText(int       childId,
                                     char far* text,
                                     int       max) const;
    void              SetDlgItemText(int childId, const char far* text) const;
    uint              IsDlgButtonChecked(int buttonId) const;
    bool              IsChild(HWND hWnd) const;
    HWND           GetNextDlgGroupItem(HWND hWndCtrl,
                                          bool previous = false) const;
    HWND           GetNextDlgTabItem(HWND hWndCtrl,
                                        bool previous = false) const;
    void              CheckDlgButton(int buttonId, uint check);
    void              CheckRadioButton(int firstButtonId,
                                       int lastButtonId,
                                       int checkButtonId);

    // Menus and menubar
    //
    HMENU             GetMenu() const;
    HMENU             GetSystemMenu(bool revert = false) const;
    bool              SetMenu(HMENU hMenu);
    bool              HiliteMenuItem(HMENU hMenu, uint idItem, uint hilite);
    void              DrawMenuBar();

    // Timer
    //
    bool              KillTimer(uint timerId);
    uint              SetTimer(uint timerId, uint timeout, TIMERPROC proc = 0);

    // Caret, cursor, font
    //
    void              CreateCaret(HBITMAP hBitmap);
    void              CreateCaret(bool isGray, int width, int height);
    static uint       GetCaretBlinkTime();
    static void       GetCaretPos(TPoint& point);
    void              HideCaret();
    static void       SetCaretBlinkTime(uint16 milliSecs);
    static void       SetCaretPos(int x, int y);
    static void       SetCaretPos(const TPoint& pos);
    void              ShowCaret();
    static void       DestroyCaret();
    static void       GetCursorPos(TPoint& pos);
    void              SetWindowFont(HFONT font, bool redraw);
    HFONT             GetWindowFont();

    // Hot keys
    //
#if defined(BI_PLAT_WIN32)
    bool              RegisterHotKey(int idHotKey, uint modifiers, uint virtKey);
    bool              UnregisterHotKey(int idHotKey);
#endif

    // Misc
    //
    bool              WinHelp(const char far* helpFile,
                              uint            command,
                              uint32          data);
    void              AssignContextMenu(TPopupMenu* menu);
    TPopupMenu*       GetContextMenu() const;
    int               MessageBox(const char far* text,
                                 const char far* caption = 0,
                                 uint            type = MB_OK);
    HTASK             GetWindowTask() const;
    void              DragAcceptFiles(bool accept);

    TCurrentEvent&    GetCurrentEvent();

  protected:
    // These events are processed by TWindow
    //
    void              EvClose();
    int               EvCreate(CREATESTRUCT far& createStruct);
    void              EvDestroy();
    TResult           EvCompareItem(uint ctrlId, COMPAREITEMSTRUCT far& compareInfo);
    void              EvDeleteItem(uint ctrlId, DELETEITEMSTRUCT far& deleteInfo);
    void              EvDrawItem(uint ctrlId, DRAWITEMSTRUCT far& drawInfo);
    void              EvMeasureItem(uint ctrlId, MEASUREITEMSTRUCT far& measureInfo);
    void              EvHScroll(uint scrollCode, uint thumbPos, HWND hWndCtl);
    void              EvVScroll(uint scrollCode, uint thumbPos, HWND hWndCtl);
    void              EvMove(TPoint& clientOrigin);
    void              EvNCDestroy();
    bool              EvQueryEndSession();
    void              EvSize(uint sizeType, TSize& size);
    void              EvLButtonDown(uint modKeys, TPoint& point);
    bool              EvEraseBkgnd(HDC);
    void              EvPaint();
    void              EvSysColorChange();
    TResult           EvWin32CtlColor(TParam1, TParam2);

    // Input validation message handler
    //
    void              EvChildInvalid(HWND hWnd);

    // System messages
    //
    void              EvCommNotify(uint commId, uint status);
    void              EvCompacting(uint compactRatio);
    void              EvDevModeChange(char far* devName);
    void              EvEnable(bool enabled);
    void              EvEndSession(bool endSession, bool logOff /* used only by Win95 */);
    void              EvFontChange();
    int               EvPower(uint powerEvent);
    void              EvSysCommand(uint cmdType, TPoint& point);
    void              EvSystemError(uint error);
    void              EvTimeChange();
    void              EvTimer(uint timerId);
    void              EvWinIniChange(char far* section);

    // Window manager messages
    //
    void              EvActivate(uint active,
                                 bool minimized,
                                 HWND hWndOther /* may be 0 */);
    void              EvActivateApp(bool active, HTASK hTask);
    void              EvCancelMode();
    void              EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
    void              EvGetText(uint buffSize, char far* buff);
    uint              EvGetTextLength();
    void              EvIconEraseBkgnd(HDC hDC);
    void              EvKillFocus(HWND hWndGetFocus /* may be 0 */);
    uint              EvMouseActivate(HWND hTopLevel, uint hitCode, uint msg);

    // The following are called under Win32 only
    //
    void              EvInputFocus(bool gainingFocus);
    void              EvOtherWindowCreated(HWND hWndOther);
    void              EvOtherWindowDestroyed(HWND hWndOther);
    void              EvPaintIcon();
    void              EvHotKey(int idHotKey);
#if defined(BI_PLAT_WIN32)
    void              EvCopyData(HWND hwnd, COPYDATASTRUCT* dataStruct);
#endif

    void              EvNextDlgCtl(uint hctlOrDir, uint isHCtl);
    void              EvParentNotify(uint event,
                                     uint childHandleOrX,
                                     uint childIDOrY);
    HANDLE            EvQueryDragIcon();
    bool              EvQueryOpen();
    void              EvQueueSync();
    bool              EvSetCursor(HWND hWndCursor,
                                  uint hitTest,
                                  uint mouseMsg);
    void              EvSetFocus(HWND hWndLostFocus /* may be 0 */);
    HFONT             EvGetFont();
    void              EvSetFont(HFONT hFont, bool redraw);
    void              EvSetRedraw(bool redraw);
    void              EvSetText(const char far* text);
    void              EvShowWindow(bool show, uint status);
    void              EvWindowPosChanged(WINDOWPOS far& windowPos);
    void              EvWindowPosChanging(WINDOWPOS far& windowPos);

    // Controls
    //
    HBRUSH            EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType);

    // Keyboard input
    //
    void              EvChar(uint key, uint repeatCount, uint flags);
    void              EvDeadChar(uint deadKey, uint repeatCount, uint flags);
    void              EvKeyDown(uint key, uint repeatCount, uint flags);
    void              EvKeyUp(uint key, uint repeatCount, uint flags);
    void              EvSysChar(uint key, uint repeatCount, uint flags);
    void              EvSysDeadChar(uint key, uint repeatCount, uint flags);
    void              EvSysKeyDown(uint key, uint repeatCount, uint flags);
    void              EvSysKeyUp(uint key, uint repeatCount, uint flags);

    // Mouse input
    //
    void              EvLButtonDblClk(uint modKeys, TPoint& point);
    void              EvLButtonUp(uint modKeys, TPoint& point);
    void              EvMButtonDblClk(uint modKeys, TPoint& point);
    void              EvMButtonDown(uint modKeys, TPoint& point);
    void              EvMButtonUp(uint modKeys, TPoint& point);
    void              EvMouseMove(uint modKeys, TPoint& point);
    void              EvRButtonDblClk(uint modKeys, TPoint& point);
    void              EvRButtonDown(uint modKeys, TPoint& point);
    void              EvRButtonUp(uint modKeys, TPoint& point);

    // Menu related messages
    //
    void              EvInitMenu(HMENU hMenu);
    void              EvInitMenuPopup(HMENU hPopupMenu,
                                      uint  index,
                                      bool  sysMenu);
    int32             EvMenuChar(uint nChar, uint menuType, HMENU hMenu);
    void              EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu);
    void              EvContextMenu(HWND childHwnd, int x, int y);

    // Dialog [Menu] messages
    //
    uint              EvGetDlgCode(MSG far* msg);
    void              EvEnterIdle(uint source, HWND hWndDlg);

    // Print manager messages
    //
    void              EvSpoolerStatus(uint jobStatus, uint jobsLeft);

    // Clipboard messages
    //
    void              EvAskCBFormatName(uint bufLen, char far* buffer);
    void              EvChangeCBChain(HWND hWndRemoved, HWND hWndNext);
    void              EvDrawClipboard();
    void              EvDestroyClipboard();
    void              EvHScrollClipboard(HWND hCBViewer, uint scrollCode, uint pos);
    void              EvPaintClipboard(HWND hWnd, HANDLE hPaintStruct);
    void              EvRenderAllFormats();
    void              EvRenderFormat(uint dataFormat);
    void              EvSizeClipboard(HWND hWndViewer, HANDLE hRect);
    void              EvVScrollClipboard(HWND hCBViewer, uint scrollCode, uint pos);

    // Palette manager messages
    //
    void              EvPaletteChanged(HWND hWndPalChg);
    void              EvPaletteIsChanging(HWND hWndPalChg);
    bool              EvQueryNewPalette();

    // Drag-n-drop messages
    //
    void              EvDropFiles(TDropInfo dropInfo);

    // List box messages
    //
    int               EvCharToItem(uint key, HWND hWndListBox, uint caretPos);
    int               EvVKeyToItem(uint key, HWND hWndListBox, uint caretPos);

    // Non-client messages
    //
    bool              EvNCActivate(bool active);
    uint              EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far& params);
    bool              EvNCCreate(CREATESTRUCT far& createStruct);
    uint              EvNCHitTest(TPoint& point);
    void              EvNCLButtonDblClk(uint hitTest, TPoint& point);
    void              EvNCLButtonDown(uint hitTest, TPoint& point);
    void              EvNCLButtonUp(uint hitTest, TPoint& point);
    void              EvNCMButtonDblClk(uint hitTest, TPoint& point);
    void              EvNCMButtonDown(uint hitTest, TPoint& point);
    void              EvNCMButtonUp(uint hitTest, TPoint& point);
    void              EvNCMouseMove(uint hitTest, TPoint& point);
    void              EvNCRButtonDblClk(uint hitTest, TPoint& point);
    void              EvNCRButtonDown(uint hitTest, TPoint& point);
    void              EvNCRButtonUp(uint hitTest, TPoint& point);

    // WM_NCPAINT now passes an HRGN under Win32.
    //
#if defined(BI_PLAT_WIN32)
    void              EvNCPaint(HRGN);
#else
    void              EvNCPaint();
#endif

    // Icon messages
    //
    HICON             EvGetIcon(bool largeIcon);
    HICON             EvSetIcon(bool largeIcon, HICON icon);

    // Callback procs for hooking TWindow to native window
    //
    static TResult CALLBACK InitWndProc(HWND, uint, TParam1, TParam2);
    static TResult CALLBACK StdWndProc(HWND, uint, TParam1, TParam2);

  protected:
    // Constructor & subsequent initializer for use with virtual derivations
    // Immediate derivitives must call Init() before constructions are done.
    //
    TWindow();
    void              Init(TWindow* parent, const char far* title, TModule* module);
    void              Init(HWND hWnd, TModule* module);

    // Set the window handle in a derived class. Used by derived classes that
    // create their window handle in a class specific way.
    //
    void              SetHandle(HWND handle);

    // Resynching state
    //
    void              GetHWndState(bool forceStyleSync = false);
    void              GetWindowTextTitle();

    virtual void      GetWindowClass(WNDCLASS& wndClass);
    virtual char far* GetClassName();

    virtual void      SetupWindow();
    virtual void      CleanupWindow();

    void              DispatchScroll(uint scrollCode, uint thumbPos, HWND hWndCtrl);

    void              LoadAcceleratorTable();
    virtual void      RemoveChild(TWindow* child);

    TWindow*          GetWindowPtr(HWND hWnd) const;

    // Member data  
    //
  public_data:
    union {
#if defined(OWL2_COMPAT)
      HWND         HWindow;  // Old obsolete name
#endif
      HWND         Handle;   // Handle to associated MS-Windows window
    };
    char far*         Title;    // Logical title. Usually the same as window text
    TWindow*          Parent;   // Owl parent, use GetParentO(), SetParent()
    TWindowAttr       Attr;     // Creation attributes
    WNDPROC           DefaultProc; // Default proc to call if msg not handled
    TScroller*        Scroller; // Scrolling helper object

  protected_data:
    void*             TransferBuffer;
    union {
#if defined(OWL2_COMPAT)
      HACCEL          hAccel;
#endif
      HACCEL          HAccel;
    };
    TModule*          CursorModule;
    TResId            CursorResId;
    HCURSOR           HCursor;
    TColor            BkgndColor;
    TPopupMenu*       ContextPopupMenu;   // Popup menu used for right click

  private:
    WNDPROC           Thunk;        // Thunk that loads 'this' into registers
    TApplication*     Application;  // Application that this window belongs to
    TModule*          Module;       // Default module used for getting resources
    uint32            Flags;
    uint16            ZOrder;
    TWindow*          ChildList;
    TWindow*          SiblingList;
    uint32            UniqueId;

    static uint32     LastUniqueId;

    void              Init(TWindow* parent, TModule* module);
    bool              OrderIsI(TWindow* win, void* position);
    void              AssignZOrder();
    void              AddChild(TWindow* child);
    int               IndexOf(TWindow* child) const;
    TWindow*          At(int position);

    void              SetUniqueId();

    // Hidden to prevent accidental copying or assignment
    //
    TWindow(const TWindow&);
    TWindow& operator =(const TWindow&);

#if defined(OWL2_COMPAT)
  // Obsolete members for Owl 2.x compatibility
  //
  public:
    void              Show(int cmdShow);  // Use ShowWindow()

    // Obsolete way to open the global clipboard object. The recomended way is
    // to construct a TClipboard using the TClipboard(HWND) ctor
    //
    TClipboard&       OpenClipboard();
    typedef ::TXWindow TXWindow;        // Exceptions moved to global scope
#endif
#if defined(OWL1_COMPAT)
    TStatus        Status;              // Obsolete, use exceptions
#endif

  DECLARE_RESPONSE_TABLE(TWindow);
  DECLARE_STREAMABLE(_OWLCLASS, TWindow, 3);

};  // class TWindow

//
// class TXWindow
// ~~~~~ ~~~~~~~~
// Basic Window exception.
//
class _OWLCLASS_RTL TXWindow : public TXOwl {
  public:
    TXWindow(TWindow* win = 0, uint resourceId = IDS_INVALIDWINDOW);

    TXWindow(const TXWindow& src);
    int Unhandled(TModule* app, uint promptResId);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXWindow* Clone();
#endif
    void Throw();

    static void Raise(TWindow* win = 0, uint resourceId = IDS_INVALIDWINDOW);

#if defined(OWL2_COMPAT)
    static string Msg(TWindow* win, uint resourceid);
#endif

  public_data:
    TWindow*      Window;
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------

//
// A TActionFunc defined in window.cpp
//
void DoEnableAutoCreate(TWindow* win, void*);

//
// Raw function to retrieve a TWindow pointer given an HWND from the a given
// app, or any app (app==0). Use the TWindow or TApplication member versions
// in new code for more protection.
//
TWindow* _OWLFUNC GetWindowPtr(HWND hWnd, const TApplication* app = 0);
#if defined(OWL1_COMPAT)
inline TWindow* GetObjectPtr(HWND hWnd)
# if defined(BI_NAMESPACE)
    {return OWL::GetWindowPtr(hWnd);}
# else
    {return ::GetWindowPtr(hWnd);}
# endif
#endif

#if defined(__TRACE) || defined(__WARN)
  ostream& operator <<(ostream& os, const TWindow& w);
#endif

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Retrieve the id of the command.
//
inline uint TCommandEnabler::GetId() const
{
  return Id;
}

//
// Return true if this command enabler sends a command message.
//
inline bool TCommandEnabler::SendsCommand() const
{
  return !(Flags & NonSender);
}

//
// Return true if the command enabler has been handled.
//
inline bool TCommandEnabler::GetHandled()
{
  return Flags & WasHandled;
}

//
// Return true if the window is the receiver.
//
inline bool TCommandEnabler::IsReceiver(HWND hReceiver)
{
  return hReceiver == HWndReceiver;
}

//
// Return the handle of the window that this enabler was destined for.
//
inline HWND TCommandEnabler::GetReceiver() const
{
  return HWndReceiver;
}

//
// Set the receiver for the enabler.
//
inline void TCommandEnabler::SetReceiver(HWND hReceiver)
{
  HWndReceiver = hReceiver;
}

//
// Mark that the enabler has been handled.
//
inline void TCommandEnabler::SetHandled()
{
  Flags |= WasHandled;
}

//----------------------------------------------------------------------------
// TWindow inlines
//

//
inline TWindow* TWindow::Next()
{
  return SiblingList;
}

//
inline void TWindow::SetNext(TWindow* next)
{
  SiblingList = next;
}

//
inline TWindow* TWindow::GetFirstChild()
{
  return ChildList ? ChildList->SiblingList : 0;
}

//
inline TWindow* TWindow::GetLastChild()
{
  return ChildList;
}

//
inline void TWindow::SetFlag(uint mask)
{
  Flags |= uint32(mask);
}

//
inline void TWindow::ClearFlag(uint mask)
{
  Flags &= uint32(~mask);
}

//
inline bool TWindow::IsFlagSet(uint mask)
{
  return (Flags & mask) ? true : false;
}

//
inline void TWindow::EnableAutoCreate()
{
  SetFlag(wfAutoCreate);
}

//
inline void TWindow::DisableAutoCreate()
{
  ClearFlag(wfAutoCreate);
}

//
inline void TWindow::EnableTransfer()
{
  SetFlag(wfTransfer);
}

//
inline void TWindow::DisableTransfer()
{
  ClearFlag(wfTransfer);
}

//
inline TModule* TWindow::GetModule() const
{
  return Module;
}

//
inline void TWindow::SetModule(TModule* module)
{
  Module = module;
}

//
inline TApplication* TWindow::GetApplication() const
{
  return Application;
}

//
inline WNDPROC TWindow::GetThunk() const
{
  return Thunk;
}

//
// Return the associated scroller object for this window.
//
inline TScroller* TWindow::GetScroller()
{
  return Scroller;
}

//
inline void TWindow::ShutDownWindow(int retVal)
{
  ShutDownWindow(this, retVal);
}

//
inline int TWindow::GetId() const
{
  return Attr.Id;
}

//
inline void TWindow::SetBkgndColor(const TColor& color)
{
  BkgndColor = color;
}

//
inline void TWindow::SetTransferBuffer(void* transferBuffer)
{
  TransferBuffer = transferBuffer;
}

//----------------------------------------------------------------------------
// HWND wrappers
//

//
// Return the handle of the parent.
//
inline HWND TWindow::GetParentH() const
{
  return GetHandle() ? ::GetParent(GetHandle()) : 0;
}

//
// Return the OWL's parent for this window.
//
inline TWindow* TWindow::GetParentO() const
{
  return Parent;
}

#if defined(OWL2_COMPAT)
//
// For OWL 2 compatability, GetParent returns the handle.
//
inline HWND TWindow::GetParent() const
{
  return GetParentH();
}
#else
//
// In the future, GetParent returns the OWL object.
//
inline TWindow* TWindow::GetParent()
{
  return GetParentO();
}
#endif

//
// Return the handle of the window.
//
inline HWND TWindow::GetHandle() const
{
  return Handle;
}

//
inline TWindow::operator HWND() const
{
  return GetHandle();
}

//
inline void TWindow::SetHandle(HWND handle)
{
  Handle = handle;
}

//
inline bool TWindow::IsWindow() const
{
  return ::IsWindow(GetHandle());
}

//
// Return the current event to be processed in the message queue.
//
inline TCurrentEvent& TWindow::GetCurrentEvent()
{
  return GetApplication()->GetCurrentEvent();
}

//
inline void
TWindow::SendNotification(int id, int notifyCode, HWND hCtl, uint msg)
{
#if defined(BI_PLAT_WIN32)
  SendMessage(msg, MkParam1(id, notifyCode), TParam2(hCtl));
#else
  SendMessage(msg, id, MkParam2(uint16(hCtl), notifyCode));
#endif
}

//
inline void
TWindow::SendNotification(HWND receiver, int id, int notifyCode,
                          HWND hCtl, uint msg)
{
  PRECONDITION(receiver && ::IsWindow(receiver));
#if defined(BI_PLAT_WIN32)
  ::SendMessage(receiver, msg, MkParam1(id, notifyCode), TParam2(hCtl));
#else
  ::SendMessage(receiver, msg, id, MkParam2(uint16(hCtl), notifyCode));
#endif
}

//
inline uint32
TWindow::SendNotification(int id, NMHDR& nmhdr, uint msg)
{
  return SendMessage(msg, TParam1(id), TParam2(&nmhdr));
}

//
//
inline uint32
TWindow::SendNotification(HWND receiver, uint id, NMHDR& nmhdr, uint msg)
{
  return ::SendMessage(receiver, msg, TParam1(id), TParam2(&nmhdr));
}

//
// Wrapper for Windows API.
//
inline TResult
TWindow::SendDlgItemMessage(int childId, uint msg, TParam1 p1, TParam2 p2)

{
  PRECONDITION(GetHandle());
  return ::SendDlgItemMessage(GetHandle(), childId, msg, p1, p2);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::PostMessage(uint msg, TParam1 p1, TParam2 p2)
{
  PRECONDITION(GetHandle());
  return ::PostMessage(GetHandle(), msg, p1, p2);
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetCapture()
{
  return ::GetCapture();
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::SetCapture()
{
  PRECONDITION(GetHandle());
  return ::SetCapture(GetHandle());
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ReleaseCapture()
{
  ::ReleaseCapture();
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetFocus()
{
  return ::GetFocus();
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::SetFocus()
{
  PRECONDITION(GetHandle());
  return ::SetFocus(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::IsWindowEnabled() const
{
  PRECONDITION(GetHandle());
  return ::IsWindowEnabled(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::EnableWindow(bool enable)
{
  PRECONDITION(GetHandle());
  return ::EnableWindow(GetHandle(), enable);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetRedraw(bool redraw)
{
  PRECONDITION(GetHandle());
  SendMessage(WM_SETREDRAW, redraw);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ScreenToClient(TPoint& point) const
{
  PRECONDITION(GetHandle());
  ::ScreenToClient(GetHandle(), &point);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::MapWindowPoints(HWND hWndTo, TPoint* points, int count) const
{
  PRECONDITION(GetHandle());
  ::MapWindowPoints(GetHandle(), hWndTo, points, count);
}

//
// Wrapper for Windows API.
//
inline TRect
TWindow::GetClientRect() const
{
  TRect  rect;
  GetClientRect(rect);
  return rect;
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::WindowFromPoint(const TPoint& point)
{
  return ::WindowFromPoint(point);
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::ChildWindowFromPoint(const TPoint& point) const
{
  PRECONDITION(GetHandle());
  return ::ChildWindowFromPoint(GetHandle(), point);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ClientToScreen(TPoint& point) const
{
  PRECONDITION(GetHandle());
  ::ClientToScreen(GetHandle(), &point);
}

//
// Wrapper for Windows API.
//
inline TRect
TWindow::GetWindowRect() const
{
  TRect  rect;
  GetWindowRect(rect);
  return rect;
}

//
// Wrapper for Windows API.
//
inline void
TWindow::AdjustWindowRect(TRect& rect, uint32 style, bool menu)
{
  ::AdjustWindowRect(&rect, style, menu);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::AdjustWindowRectEx(TRect& rect, uint32 style, bool menu, uint32 exStyle)
{
  ::AdjustWindowRectEx(&rect, style, menu, exStyle);
}

//
// Window and class Words and Longs, window properties
//
//
inline long
TWindow::GetClassName(char far* className, int maxCount) const
{
  PRECONDITION(GetHandle());
  return ::GetClassName(GetHandle(), className, maxCount);
}

//
inline long
TWindow::GetClassLong(int index) const
{
  PRECONDITION(GetHandle());
  return ::GetClassLong(GetHandle(), index);
}

//
inline long
TWindow::SetClassLong(int index, long newLong)
{
  PRECONDITION(GetHandle());
  return ::SetClassLong(GetHandle(), index, newLong);
}

//
inline uint16
TWindow::GetClassWord(int index) const
{
  PRECONDITION(GetHandle());
  return ::GetClassWord(GetHandle(), index);
}

//
inline uint16
TWindow::SetClassWord(int index, uint16 newWord)
{
  PRECONDITION(GetHandle());
  return ::SetClassWord(GetHandle(), index, newWord);
}

//
inline long
TWindow::GetWindowLong(int index) const
{
  PRECONDITION(GetHandle());
  return ::GetWindowLong(GetHandle(), index);
}

//
inline long
TWindow::SetWindowLong(int index, long newLong)
{
  PRECONDITION(GetHandle());
  return ::SetWindowLong(GetHandle(), index, newLong);
}

//
inline uint16
TWindow::GetWindowWord(int index) const
{
  PRECONDITION(GetHandle());
  return ::GetWindowWord(GetHandle(), index);
}

//
inline uint16
TWindow::SetWindowWord(int index, uint16 newWord)
{
  PRECONDITION(GetHandle());
  return ::SetWindowWord(GetHandle(), index, newWord);
}

//
inline WNDPROC
TWindow::GetWindowProc() const
{
  PRECONDITION(GetHandle());
  return WNDPROC(GetWindowLong(GWL_WNDPROC));
}

//
inline WNDPROC
TWindow::SetWindowProc(WNDPROC wndProc)
{
  PRECONDITION(GetHandle());
  return WNDPROC(SetWindowLong(GWL_WNDPROC, long(wndProc)));
}

//
// Wrapper for Windows API.
//
inline int
TWindow::EnumProps(PROPENUMPROC proc)
{
  PRECONDITION(GetHandle());
  return ::EnumProps(GetHandle(), proc);
}

//
// Wrapper for Windows API.
//
inline HANDLE
TWindow::GetProp(uint16 atom) const
{
  PRECONDITION(GetHandle());
  return :: GetProp(GetHandle(), (LPCSTR)(uint32)atom);
}

//
// Wrapper for Windows API.
//
inline HANDLE
TWindow::RemoveProp(uint16 atom) const
{
  PRECONDITION(GetHandle());
  return :: RemoveProp(GetHandle(), (LPCSTR)(uint32)atom);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::SetProp(uint16 atom, HANDLE data) const
{
  PRECONDITION(GetHandle());
  return :: SetProp(GetHandle(), (LPCSTR)(uint32)atom, data);
}

//
// Wrapper for Windows API.
//
inline HANDLE
TWindow::GetProp(const char far* str) const
{
  PRECONDITION(GetHandle());
  return ::GetProp(GetHandle(), str);
}

//
// Wrapper for Windows API.
//
inline HANDLE
TWindow::RemoveProp(const char far* str) const
{
  PRECONDITION(GetHandle());
  return ::RemoveProp(GetHandle(), str);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::SetProp(const char far* str, HANDLE data) const
{
  PRECONDITION(GetHandle());
  return ::SetProp(GetHandle(), str, data);
}

//
// MoveWindow calls thru TWindow::SetWindowPos to allow moving before creation
//
inline bool
TWindow::MoveWindow(int x, int y, int w, int h, bool repaint)
{
  return SetWindowPos(0, x, y, w, h,
                      SWP_NOZORDER | SWP_NOOWNERZORDER | SWP_NOACTIVATE |
                      (repaint ? 0 : SWP_NOREDRAW));
}

//
inline bool
TWindow::MoveWindow(const TRect& rect, bool repaint)
{
  return MoveWindow(rect.left, rect.top, rect.Width(), rect.Height(), repaint);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ShowOwnedPopups(bool show)
{
  PRECONDITION(GetHandle());
  ::ShowOwnedPopups(GetHandle(), show);
}


//
// Wrapper for Windows API.
//
inline bool
TWindow::IsWindowVisible() const
{
  PRECONDITION(GetHandle());
  return ::IsWindowVisible(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::IsZoomed() const
{
  PRECONDITION(GetHandle());
  return ::IsZoomed(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::IsIconic() const
{
  PRECONDITION(GetHandle());
  return ::IsIconic(GetHandle());
}

//
// Wrapper for Windows API.
//
inline int
TWindow::GetWindowTextLength() const
{
  PRECONDITION(GetHandle());
  return ::GetWindowTextLength(GetHandle());
}

//
// Wrapper for Windows API.
//
inline int
TWindow::GetWindowText(char far* str, int maxCount) const
{
  PRECONDITION(GetHandle());
  return ::GetWindowText(GetHandle(), str, maxCount);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetWindowText(const char far* str)
{
  PRECONDITION(GetHandle());
  ::SetWindowText(GetHandle(), str);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::GetWindowPlacement(WINDOWPLACEMENT* place) const
{
  PRECONDITION(GetHandle());
  return ::GetWindowPlacement(GetHandle(), place);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::SetWindowPlacement(const WINDOWPLACEMENT* place)
{
  PRECONDITION(GetHandle());
  return ::SetWindowPlacement(GetHandle(), place);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::BringWindowToTop()
{
  PRECONDITION(GetHandle());
  ::BringWindowToTop(GetHandle());
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetActiveWindow()
{
  return ::GetActiveWindow();
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::SetActiveWindow()
{
  PRECONDITION(GetHandle());
  return ::SetActiveWindow(GetHandle());
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetDesktopWindow()
{
  return ::GetDesktopWindow();
}

#if defined(BI_PLAT_WIN16)
//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetSysModalWindow()
{
  return ::GetSysModalWindow();
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::SetSysModalWindow()
{
  PRECONDITION(GetHandle());
  return ::SetSysModalWindow(GetHandle());
}
#endif

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetNextWindow(uint flag) const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN32)
  return ::GetWindow(GetHandle(), flag);
#else
  return ::GetNextWindow(GetHandle(), flag);
#endif
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetLastActivePopup() const
{
  PRECONDITION(GetHandle());
  return ::GetLastActivePopup(GetHandle());
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetWindow(uint flag) const
{
//  PRECONDITION(GetHandle());
  return ::GetWindow(GetHandle(), flag);
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetTopWindow() const
{
  PRECONDITION(GetHandle());
  return ::GetTopWindow(GetHandle());
}

//
inline bool
TWindow::SetWindowPos(HWND hWndInsertAfter, const TRect& rect, uint flags)
{
  return SetWindowPos(hWndInsertAfter,
                      rect.left, rect.top, rect.Width(), rect.Height(), flags);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::Invalidate(bool erase)
{
  PRECONDITION(GetHandle());
  ::InvalidateRect(GetHandle(), 0, erase);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::InvalidateRect(const TRect& rect, bool erase)
{
  PRECONDITION(GetHandle());
  ::InvalidateRect(GetHandle(), &rect, erase);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::InvalidateRgn(HRGN hRgn, bool erase)
{
  PRECONDITION(GetHandle());
  ::InvalidateRgn(GetHandle(), hRgn, erase);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::Validate()
{
  PRECONDITION(GetHandle());
  ::ValidateRect(GetHandle(), 0);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ValidateRect(const TRect& rect)
{
  PRECONDITION(GetHandle());
  ::ValidateRect(GetHandle(), &rect);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ValidateRgn(HRGN hRgn)
{
  PRECONDITION(GetHandle());
  ::ValidateRgn(GetHandle(), hRgn);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::UpdateWindow()
{
  PRECONDITION(GetHandle());
  ::UpdateWindow(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::FlashWindow(bool invert)
{
  PRECONDITION(GetHandle());
  return ::FlashWindow(GetHandle(), invert);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::GetUpdateRect(TRect& rect, bool erase) const
{
  PRECONDITION(GetHandle());
  return ::GetUpdateRect(GetHandle(), &rect, erase);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::LockWindowUpdate()
{
  PRECONDITION(GetHandle());
  return ::LockWindowUpdate(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::RedrawWindow(TRect* update, HRGN hUpdateRgn, uint redraw)
{
  PRECONDITION(GetHandle());
  return ::RedrawWindow(GetHandle(), update, hUpdateRgn, redraw);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::EnableScrollBar(uint sbFlags, uint arrowFlags)
{
  PRECONDITION(GetHandle());
  return ::EnableScrollBar(GetHandle(), sbFlags, arrowFlags);
}

//
// Wrapper for Windows API.
//
inline void TWindow::ShowScrollBar(int bar, bool show)
{
  PRECONDITION(GetHandle());
  ::ShowScrollBar(GetHandle(), bar, show);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ScrollWindow(int              dx,
                      int              dy,
                      const TRect far* scroll,
                      const TRect far* clip)
{
  PRECONDITION(GetHandle());
  ::ScrollWindow(GetHandle(), dx, dy, scroll, clip);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ScrollWindowEx(int              dx,
                        int              dy,
                        const TRect far* scroll,
                        const TRect far* clip,
                        HRGN             hUpdateRgn,
                        TRect far*       update,
                        uint             flags)
{
  PRECONDITION(GetHandle());
  ::ScrollWindowEx(GetHandle(), dx, dy, scroll, clip, hUpdateRgn, update, flags);
}

//
// Wrapper for Windows API.
//
inline int
TWindow::GetDlgCtrlID() const
{
  PRECONDITION(GetHandle());
  return ::GetDlgCtrlID(GetHandle());
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetDlgItem(int childId) const
{
  PRECONDITION(GetHandle());
  return ::GetDlgItem(GetHandle(), childId);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetDlgItemInt(int childId, uint value, bool isSigned) const
{
  PRECONDITION(GetHandle());
  ::SetDlgItemInt(GetHandle(), childId, value, isSigned);
}

//
// Wrapper for Windows API.
//
inline int
TWindow::GetDlgItemText(int childId, char far* text, int max) const
{
  PRECONDITION(GetHandle());
  return ::GetDlgItemText(GetHandle(), childId, text, max);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetDlgItemText(int childId, const char far* text) const
{
  PRECONDITION(GetHandle());
  ::SetDlgItemText(GetHandle(), childId, text);
}

//
// Wrapper for Windows API.
//
inline uint
TWindow::IsDlgButtonChecked(int buttonId) const
{
  PRECONDITION(GetHandle());
  return ::IsDlgButtonChecked(GetHandle(), buttonId);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::IsChild(HWND hWnd) const
{
  PRECONDITION(GetHandle());
  return ::IsChild(GetHandle(), hWnd);
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetNextDlgGroupItem(HWND hWndCtrl, bool previous) const
{
  PRECONDITION(GetHandle());
  return ::GetNextDlgGroupItem(GetHandle(), hWndCtrl, previous);
}

//
// Wrapper for Windows API.
//
inline HWND
TWindow::GetNextDlgTabItem(HWND hWndCtrl, bool previous) const
{
  PRECONDITION(GetHandle());
  return ::GetNextDlgTabItem(GetHandle(), hWndCtrl, previous);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::CheckDlgButton(int buttonId, uint check)
{
  PRECONDITION(GetHandle());
  ::CheckDlgButton(GetHandle(), buttonId, check);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::CheckRadioButton(int firstButtonId, int lastButtonId, int checkButtonId)
{
  PRECONDITION(GetHandle());
  ::CheckRadioButton(GetHandle(), firstButtonId, lastButtonId, checkButtonId);
}

//
// Wrapper for Windows API.
//
inline HMENU
TWindow::GetMenu() const
{
  PRECONDITION(GetHandle());
  return ::GetMenu(GetHandle());
}

//
// Wrapper for Windows API.
//
inline HMENU
TWindow::GetSystemMenu(bool revert) const
{
  PRECONDITION(GetHandle());
  return ::GetSystemMenu(GetHandle(), revert);
}

//
// Return the associated popup menu used by the window.
//
inline TPopupMenu*
TWindow::GetContextMenu() const
{
  return ContextPopupMenu;
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::SetMenu(HMENU hMenu)
{
  PRECONDITION(GetHandle());
  return ::SetMenu(GetHandle(), hMenu);
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::HiliteMenuItem(HMENU hMenu, uint idItem, uint hilite)
{
  PRECONDITION(GetHandle());
  return ::HiliteMenuItem(GetHandle(), hMenu, idItem, hilite);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::DrawMenuBar()
{
  PRECONDITION(GetHandle());
  ::DrawMenuBar(GetHandle());
}

//
// Wrapper for Windows API.
//
inline bool
TWindow::KillTimer(uint timerId)
{
  return ::KillTimer(GetHandle(), timerId);
}

//
// Wrapper for Windows API.
//
inline uint
TWindow::SetTimer(uint timerId, uint timeout, TIMERPROC proc)
{
  return ::SetTimer(GetHandle(), timerId, timeout, proc);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::CreateCaret(HBITMAP hBitmap)
{
  PRECONDITION(GetHandle());
  ::CreateCaret(GetHandle(), hBitmap, 0, 0);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::CreateCaret(bool isGray, int width, int height)
{
  PRECONDITION(GetHandle());
  ::CreateCaret(GetHandle(), (HBITMAP)(isGray ? 1 : 0), width, height);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::DestroyCaret()
{
  ::DestroyCaret();
}

//
// Wrapper for Windows API.
//
inline uint
TWindow::GetCaretBlinkTime()
{
  return ::GetCaretBlinkTime();
}

//
// Wrapper for Windows API.
//
inline void
TWindow::GetCaretPos(TPoint& point)
{
  ::GetCaretPos(&point);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::HideCaret()
{
  PRECONDITION(GetHandle());
  ::HideCaret(GetHandle());
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetCaretBlinkTime(uint16 milliSecs)
{
  ::SetCaretBlinkTime(milliSecs);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetCaretPos(int x, int y)
{
  ::SetCaretPos(x, y);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetCaretPos(const TPoint& pos)
{
  ::SetCaretPos(pos.x, pos.y);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::ShowCaret()
{
  PRECONDITION(GetHandle());
  ::ShowCaret(GetHandle());
}

//
// Wrapper for Windows API.
//
inline void
TWindow::GetCursorPos(TPoint& pos)
{
  ::GetCursorPos(&pos);
}

//
// Wrapper for Windows API.
//
inline void
TWindow::SetWindowFont(HFONT font, bool redraw)
{
  PRECONDITION(GetHandle());
  SendMessage(WM_SETFONT, TParam1(font), redraw);
}

//
// Wrapper for Windows API.
//
inline HFONT
TWindow::GetWindowFont()
{
  PRECONDITION(GetHandle());
  return (HFONT)SendMessage(WM_GETFONT);
}

#if defined(BI_PLAT_WIN32)
//
inline bool
TWindow::RegisterHotKey(int idHotKey, uint modifiers, uint virtKey)
{
  PRECONDITION(GetHandle());
  return ::RegisterHotKey(GetHandle(), idHotKey, modifiers, virtKey);
}

//
inline bool
TWindow::UnregisterHotKey(int idHotKey)
{
  PRECONDITION(GetHandle());
  return ::UnregisterHotKey(GetHandle(), idHotKey);
}
#endif

//
// Wrapper for Windows API.
//
inline bool
TWindow::WinHelp(const char far* helpFile, uint command, uint32 data)
{
  PRECONDITION(GetHandle());
  return ::WinHelp(GetHandle(), helpFile, command, data);
}

//
inline int
TWindow::MessageBox(const char far* text,
                    const char far* caption,
                    uint            type)
{
  PRECONDITION(GetApplication());
  PRECONDITION(GetHandle());
  return GetApplication()->MessageBox(*this, text, caption, type);
}

//
// Wrapper for Windows API.
//
inline HTASK
TWindow::GetWindowTask() const
{
  PRECONDITION(GetHandle());
#if defined(BI_PLAT_WIN32)
  return (HANDLE)::GetWindowThreadProcessId(GetHandle(), 0);
#else
  return ::GetWindowTask(GetHandle());
#endif
}

//
// Wrapper for Windows API.
//
inline void
TWindow::DragAcceptFiles(bool accept)
{
  PRECONDITION(GetHandle());
  ::DragAcceptFiles(GetHandle(), accept);
}

//
inline TWindow* TWindow::GetWindowPtr(HWND hWnd) const
{
#if defined(BI_NAMESPACE)
  return OWL::GetWindowPtr(hWnd, GetApplication());
#else
  return ::GetWindowPtr(hWnd, GetApplication());
#endif
}

//
// Inline member functions that call DefWindowProc()
//

//
inline void TWindow::EvActivate(uint /*active*/,
                                bool /*minimized*/,
                                HWND /*hWndOther*//*may be 0*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvActivateApp(bool /*active*/, HTASK /*hTask or threadId*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvAskCBFormatName(uint /*bufLen*/, char far* /*buffer*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvCancelMode()
{
  DefaultProcessing();
}

//
inline void TWindow::EvChangeCBChain(HWND /*hWndRemoved*/, HWND /*hWndNext*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvChar(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline int TWindow::EvCharToItem(uint /*key*/, HWND /*hWndListBox*/, uint /*caretPos*/)
{
  return (int)DefaultProcessing();
}

//
inline int TWindow::EvVKeyToItem(uint /*key*/, HWND /*hWndListBox*/, uint /*caretPos*/)
{
  return (int)DefaultProcessing();
}

//
inline void TWindow::EvCommNotify(uint /*commId*/, uint /*status*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvCompacting(uint /*compactRatio*/)
{
  DefaultProcessing();
}

#if defined(BI_PLAT_WIN32)
//
inline void TWindow::EvCopyData(HWND /*hwnd*/, COPYDATASTRUCT* /*dataStruct*/)
{
  DefaultProcessing();
}
#endif


//
inline void TWindow::EvDeadChar(uint /*deadKey*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvDestroyClipboard()
{
  DefaultProcessing();
}

//
inline void TWindow::EvDevModeChange(char far* /*device*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvDropFiles(TDropInfo)
{
  DefaultProcessing();
}

//
inline void TWindow::EvDrawClipboard()
{
  DefaultProcessing();
}

//
inline void TWindow::EvEnable(bool /*enabled*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvFontChange()
{
  DefaultProcessing();
}

//
inline uint TWindow::EvGetDlgCode(MSG far*)
{
  return (uint)DefaultProcessing();
}

//
inline HFONT   TWindow::EvGetFont()
{
  return (HFONT)DefaultProcessing();
}

//
inline void TWindow::EvGetMinMaxInfo(MINMAXINFO far& /*info*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvGetText(uint /*buffSize*/, char far* /*buff*/)
{
  DefaultProcessing();
}

//
inline uint TWindow::EvGetTextLength()
{
  return (uint)DefaultProcessing();
}

//
inline void TWindow::EvHotKey(int /*idHotKey*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvInputFocus(bool /*gainingFocus*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvHScrollClipboard(HWND /*hWndCBViewer*/,
                                           uint /*scrollCode*/,
                                           uint /*pos*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvIconEraseBkgnd(HDC /*dc*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvInitMenu(HMENU /*menu*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvKeyDown(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvKeyUp(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvLButtonDblClk(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvLButtonUp(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvMButtonDblClk(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvMButtonDown(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvMButtonUp(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline int32   TWindow::EvMenuChar(uint /*nChar*/, uint /*menuType*/, HMENU /*hMenu*/)
{
  return (uint)DefaultProcessing();
}

//
inline void TWindow::EvMenuSelect(uint /*menuItemId*/, uint /*flags*/, HMENU /*hMenu*/)
{
  DefaultProcessing();
}

//
inline uint TWindow::EvMouseActivate(HWND /*hWndTopLevel*/, uint /*hitTestCode*/, uint /*msg*/)
{
  return (uint)DefaultProcessing();
}

//
inline void TWindow::EvMouseMove(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline bool TWindow::EvNCActivate(bool /*active*/)
{
  return (bool)DefaultProcessing();
}

//
inline uint TWindow::EvNCCalcSize(bool /*calcValidRects*/, NCCALCSIZE_PARAMS far&)
{
  return (uint)DefaultProcessing();
}

//
inline bool TWindow::EvNCCreate(CREATESTRUCT far&)
{
  return (bool)DefaultProcessing();
}

//
inline uint TWindow::EvNCHitTest(TPoint&)
{
  return (uint)DefaultProcessing();
}

//
inline void TWindow::EvNCLButtonDblClk(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCLButtonDown(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCLButtonUp(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCMButtonDblClk(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCMButtonDown(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCMButtonUp(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCMouseMove(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

#if defined(BI_PLAT_WIN32)
//
inline void TWindow::EvNCPaint(HRGN /*region*/)
{
  DefaultProcessing();
}
#else
//
inline void TWindow::EvNCPaint()
{
  DefaultProcessing();
}
#endif //BI_PLAT_WIN32

//
inline void TWindow::EvNCRButtonDblClk(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCRButtonDown(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNCRButtonUp(uint /*hitTest*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvNextDlgCtl(uint /*hctlOrDir*/, uint /*isHCtl*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvOtherWindowCreated(HWND /*hWndOther*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvOtherWindowDestroyed(HWND /*hWndOther*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvPaintIcon()
{
  DefaultProcessing();
}

//
inline void TWindow::EvPaintClipboard(HWND, HANDLE /*hPaintStruct*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvPaletteChanged(HWND /*hWndPalChg*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvPaletteIsChanging(HWND /*hWndPalChg*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvParentNotify(uint /*event*/, uint /*hChildOrX*/, uint /*childIDOrY*/)
{
  DefaultProcessing();
}

//
inline int  TWindow::EvPower(uint)
{
  return (int)DefaultProcessing();
}

//
inline void TWindow::EvSysCommand(uint /*cmdType*/, TPoint&)
{
  DefaultProcessing();
}

//
inline HANDLE  TWindow::EvQueryDragIcon()
{
  return (HANDLE)DefaultProcessing();
}

//
inline bool TWindow::EvQueryNewPalette()
{
  return (bool)DefaultProcessing();
}

//
inline bool TWindow::EvQueryOpen()
{
  return (bool)DefaultProcessing();
}

//
inline void TWindow::EvQueueSync()
{
  DefaultProcessing();
}

//
inline void TWindow::EvRenderAllFormats()
{
  DefaultProcessing();
}

//
inline void TWindow::EvRenderFormat(uint /*dataFormat*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvRButtonDblClk(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvRButtonDown(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvRButtonUp(uint /*modKeys*/, TPoint&)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSetFocus(HWND /*hWndLostFocus*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSetFont(HFONT, bool)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSetRedraw(bool)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSetText(const char far*)
{
  DefaultProcessing();
}

//
inline void TWindow::EvShowWindow(bool /*show*/, uint /*status*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSizeClipboard(HWND /*hWndViewer*/, HANDLE /*hRect*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSpoolerStatus(uint /*jobStatus*/, uint /*jobsLeft*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSysChar(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSysDeadChar(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSysKeyDown(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSysKeyUp(uint /*key*/, uint /*repeatCount*/, uint /*flags*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvSystemError(uint /*error*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvTimeChange()
{
  DefaultProcessing();
}

//
inline void TWindow::EvTimer(uint /*timerId*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvWinIniChange(char far* /*section*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvVScrollClipboard(HWND /*hWndCBViewer*/,
                                           uint /*scrollCode*/,
                                           uint /*pos*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvWindowPosChanged(WINDOWPOS far& /*windowPos*/)
{
  DefaultProcessing();
}

//
inline void TWindow::EvWindowPosChanging(WINDOWPOS far& /*windowPos*/)
{
  DefaultProcessing();
}

#if defined(OWL2_COMPAT)
//
// Show() is just a synonym for ShowWindow() for OWL 1 compatibility
//
inline void
TWindow::Show(int cmdShow)
{
  ShowWindow(cmdShow);
}

//
inline TClipboard&
TWindow::OpenClipboard()
{
  PRECONDITION(GetHandle());

  TClipboard& clip = TClipboard::GetClipboard();

  clip.OpenClipboard(GetHandle());
  return clip;
}
#endif

#endif  // OWL_WINDOW_H
