//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Base window class definition, including HWND encapsulation.
//----------------------------------------------------------------------------
#if !defined(OWL_WINDOW_H)
#define OWL_WINDOW_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
#if !defined(OSL_GEOMETRY_H)
# include <osl/geometry.h>
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
#if defined(BI_MULTI_THREAD) && !defined(CLASSLIB_THREAD_H)
# include <classlib/thread.h>
#endif
#include <owl/window.rh>

class _OWLCLASS TApplication;
class _OWLCLASS TModule;
class _OWLCLASS TScroller;
class _OWLCLASS TRegion;
class _OWLCLASS TWindow;
class _OWLCLASS TDC;

//
//  enum TWindowFlag
//  ---- -----------
//
enum TWindowFlag {
  wfAlias           = 0x0001,  // TWindow is an alias to a preexisting HWND
  wfAutoCreate      = 0x0002,  // Create the HWindow when our parent is created
  wfFromResource    = 0x0004,  // HWindow comes from HWND created from resource
  wfShrinkToClient  = 0x0008,  // Shrink a frame window to its client's size
  wfMainWindow      = 0x0010,  // This frame window is the main window
  wfFullyCreated    = 0x0020,  // Window is fully created & not being destroyed
  wfStreamTop       = 0x0040,  // This window is the topmost one to stream
  wfPredefinedClass = 0x0080,  // Window class used was not defined by Owl
  wfTransfer        = 0x0100,  // Transfer enabled
  wfUnHidden        = 0x0200,  // Used temporarily when destroying MDI child
  wfUnDisabled      = 0x0400,  // Used temporarily when destroying MDI child
  wfDeleteOnClose   = 0x0800   // Window is condemned on EvClose
};

//
// Transfer function flags
//
enum TTransferDirection {
  tdGetData,    // Get data from the window into the buffer
  tdSetData,    // Set data from the buffer into the window
  tdSizeData    // Just query the window data size in bytes
};

//
// Mixin window event implementation return status
//
enum TEventStatus {
  esPartial,    // Additional handlers may be invoked
  esComplete    // No additional handlers are needed
};

//
// special background color flags for EvEraseBkgnd processing
//
const uint32 NoColor = 0xFF000000l;  // let DefWindowProc erase
const uint32 NoErase = 0xFE000000l;  // don't erase, wait for Paint

//
//  windows 3.1 windowsx.h name confict with TWindows::GetFirstChild()
//
#if defined(GetFirstChild)
# undef GetFirstChild(hwnd)
#endif

//
// Member and non-member action and conditional function types used with
// ForEach and FirstThat.
//
typedef void (*TActionFunc)(TWindow* win, void* param);
typedef bool (*TCondFunc)(TWindow* win, void* param);

typedef void (TWindow::*TActionMemFunc)(TWindow* win, void* param);
typedef bool (TWindow::*TCondMemFunc)(TWindow* win, void* param);

//
//  class TCommandEnabler
//  ----- ---------------
//
//  base class for an extensible interface for auto enabling/disabling of
//  commands (menu items, tool bar buttons, ...)
//
class _OWLCLASS TCommandEnabler {
  public:
    const uint  Id;

    TCommandEnabler(uint id, HWND hWndReceiver = 0);

    virtual void  Enable(bool enable = true);  // sets "Handled" to true
    virtual void  SetText(const char far* text) = 0;
    enum {Unchecked, Checked, Indeterminate};
    virtual void  SetCheck(int check) = 0;  // Unchecked, Checked, or Indeterminate

    bool        GetHandled() {return Handled;}
    bool        IsReceiver(HWND hReceiver) {return hReceiver==HWndReceiver;}

  protected:
    const HWND  HWndReceiver;
    bool        Handled;
};

//
//  struct TWindowsAttr
//  ------ ------------
//
//  Window *Creation* attributes. Don't rely on these to track once HWindow
//  has been created, use member functions to access information.
//
struct TWindowAttr {
    uint32     Style;
    uint32     ExStyle;
    int        X, Y, W, H;
    TResId     Menu;        // Menu resource id
    int        Id;          // Child identifier
    char far*  Param;
    TResId     AccelTable;  // Accelerator table resource id
};

//
//  class TWindow
//  ----- -------
//
class _OWLCLASS TWindow : virtual public TEventHandler,
                          virtual public TStreamableBase {
  public:
    class _OWLCLASS_RTL TXWindow : public TXOwl {
      public:
        TXWindow(TWindow* win = 0, uint resourceId = IDS_INVALIDWINDOW);
        TXWindow(const TXWindow& src);
        int Unhandled(TModule* app, unsigned promptResId);
        TXOwl* Clone();
        void Throw() {throw *this;}
        TWindow*      Window;
        static string Msg(TWindow* wnd, uint resourceid);
    };

    TStatus        Status;
    HWND           HWindow;  // handle to associated MS-Windows window
    char far*      Title;
    TWindow*       Parent;
    TWindowAttr    Attr;
    WNDPROC        DefaultProc;
    TScroller*     Scroller;

    TWindow(TWindow*        parent,
            const char far* title = 0,
            TModule*        module = 0);

    TWindow(HWND hWnd, TModule* module = 0);

    virtual ~TWindow();

    //
    // two iterators that take function pointers
    //
    TWindow*          FirstThat(TCondFunc test, void* paramList = 0);
    void              ForEach(TActionFunc action, void* paramList = 0);

    //
    // two iterators that take pointers to member functions
    //
    TWindow*          FirstThat(TCondMemFunc test, void* paramList = 0);
    void              ForEach(TActionMemFunc action, void* paramList = 0);

    //
    // other functions for iteration
    //
    TWindow*          Next() {return SiblingList;}
    void              SetNext(TWindow* next) {SiblingList = next;}
    TWindow*          GetFirstChild()
                          {return ChildList ? ChildList->SiblingList : 0;}
    TWindow*          GetLastChild() {return ChildList;}
    TWindow*          Previous();
    unsigned          NumChildren();  // number of child windows

    //
    // query and set the flags
    //
    void              SetFlag(TWindowFlag mask) {Flags |= uint32(mask);}
    void              ClearFlag(TWindowFlag mask) {Flags &= uint32(~mask);}
    bool              IsFlagSet(TWindowFlag mask) {return (Flags & mask) ? 1 : 0;}

    //
    // sets/clears flag which indicates that the TWindow should be
    // created if a create is sent while in the parent's child list
    //
    void              EnableAutoCreate() {SetFlag(wfAutoCreate);}
    void              DisableAutoCreate() {ClearFlag(wfAutoCreate);}

    //
    // sets flag which indicates that the TWindow can/will transfer data
    // via the transfer mechanism
    //
    void              EnableTransfer() {SetFlag(wfTransfer);}
    void              DisableTransfer() {ClearFlag(wfTransfer);}

    //
    // Window's default module access functions
    //
    TModule*          GetModule() const {return Module;}
    void              SetModule(TModule* module) {Module = module;}

    TApplication*     GetApplication() const {return Application;}
    WNDPROC           GetThunk() const {return Thunk;}
    virtual bool      Register();

    //
    // create/destroy an MS_Windows element to be associated with an OWL window
    //
    virtual bool      Create();
    virtual void      PerformCreate(int menuOrId);
    bool              CreateChildren();
    virtual void      Destroy(int retVal = 0);

    //
    // suggest an Owl window to close itself
    //
    virtual void      CloseWindow(int retVal = 0);

    //
    // Unconditionally shut down a given window. Destroy() is called to
    // destroy the HWindow, & then the window is deleted. Non-static version
    // is safe as long as it is inline and not called on itself
    //
    static void       ShutDownWindow(TWindow* win, int retVal = 0);
    void              ShutDownWindow(int retVal = 0)
                          {ShutDownWindow(this, retVal);}

#if defined(BI_MULTI_THREAD)
    //
    // override TEventHandler::Dispatch() to handle multi-thread
    // synchronization
    //
    virtual LRESULT  Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp = 0);
#endif

    //
    // called from TApplication::ProcessAppMsg() to give the window an
    // opportunity to perform preprocessing of the Windows message
    //
    // if you return true, further processing of the message is halted
    //
    // if you override this method in a derived class, make sure to call this
    // routine because it handles translation of accelerators...
    //
    virtual bool      PreProcessMsg(MSG& msg);
    virtual bool      IdleAction(long idleCount);
    virtual bool      HoldFocusHWnd(HWND hWndLose, HWND hWndGain);

    int               GetId() const {return Attr.Id;}
    TWindow*          ChildWithId(int id) const;

    virtual void      SetParent(TWindow* newParent);
    virtual bool      SetDocTitle(const char far* docname, int index);

    void              Show(int cmdShow);
    void              SetCaption(const char far* title);
    void              GetWindowTextTitle();
    void              GetHWndState();
    bool              SetCursor(TModule* module, TResId resId);
    void              SetBkgndColor(uint32 color) {BkgndColor = color;}

    virtual bool      CanClose();

    //
    // forwards the current event to "hWnd" using either PostMessage() or
    // SendMessage(). Owl window version calls directly to window proc on send.
    //
    LRESULT           ForwardMessage(HWND hWnd, bool send = true);
    LRESULT           ForwardMessage(bool send = true);

    //
    // send message to all children
    //
    void              ChildBroadcastMessage(uint msg, WPARAM wParam=0, LPARAM lParam=0);

    //
    // Notify a window (parent usually) of a child action.
    //
    void              SendNotification(int id, int notifyCode, HWND hCtl,
                                       uint msg = WM_COMMAND);

    //
    // Called from StdWndProc to allow exceptions to be caught and suspended.
    // Calls HandleMessage from within try block. Catches and suspends all
    // exceptions before returning to Windows (Windows is not exception safe).
    //
    LRESULT           ReceiveMessage(uint   msg,
                                     WPARAM wParam = 0,
                                     LPARAM lParam = 0);

    //
    // Call a Window's window proc to handle a message. Similar to SendMessage
    // but more direct.
    //
    LRESULT           HandleMessage(uint   msg,
                                    WPARAM wParam = 0,
                                    LPARAM lParam = 0);

    //
    // virtual functions called to handle a message, and to deal with an
    // unhandled message in a default way.
    //
    virtual LRESULT   WindowProc(uint msg, WPARAM wParam, LPARAM lParam);
    virtual LRESULT   DefWindowProc(uint msg, WPARAM wParam, LPARAM lParam);

    //
    // called by WindowProc() to handle WM_COMMANDs
    //
    // "id"         - specifies the identifier of the menu item or control
    //
    // "hWndCtl"    - specifies the control sending the message if the message
    //                is from a control; otherwise it is 0
    //
    // "notifyCode" - specifies the notification message if the message is from
    //                a control. if the message is from an accelerator, it is 1.
    //                if the message is from a menu, it is 0
    //
    virtual LRESULT   EvCommand(uint id, HWND hWndCtl, uint notifyCode);

    //
    // called by WindowProc() to handle WM_COMMAND_ENABLE, & helper function
    //
    virtual void      EvCommandEnable(TCommandEnabler& ce);
    void              RouteCommandEnable(HWND hInitCmdTarget, TCommandEnabler& ce);
    

    //
    // default processing, deals with special cases or calling DefWindowProc
    //
    LRESULT           DefaultProcessing();

    //
    // Paint function called by base classes when responding to WM_PAINT
    //
    virtual void      Paint(TDC& dc, bool erase, TRect& rect);

    //
    // transfer buffer
    //
    void              SetTransferBuffer(void* transferBuffer)
                          {TransferBuffer = transferBuffer;}
    virtual uint      Transfer(void* buffer, TTransferDirection direction);
    virtual void      TransferData(TTransferDirection direction);

    //
    // installs the thunk as the window function and saves the previous window
    // function in "DefaultProc"
    //
    void              SubclassWindowFunction();

    //
    // Encapsulated HWND functions inline
    //

    //
    // allow a TWindow& to be used as an HWND in Windows API calls
    //
    operator          HWND() const {return HWindow;}
    bool              IsWindow() const {return ::IsWindow(HWindow);}

    //
    // messages
    //
    LRESULT           SendMessage(uint   msg,
                                  WPARAM wParam = 0,
                                  LPARAM lParam = 0);
    LRESULT           SendDlgItemMessage(int    childId,
                                         uint   msg,
                                         WPARAM wParam = 0,
                                         LPARAM lParam = 0);
    bool              PostMessage(uint   msg,
                                  WPARAM wParam = 0,
                                  LPARAM lParam = 0);
    static HWND       GetCapture();
    HWND              SetCapture();
    static void       ReleaseCapture();
    static HWND       GetFocus();
    HWND              SetFocus();
    bool              IsWindowEnabled() const;
    virtual bool      EnableWindow(bool enable);
    void              SetRedraw(bool redraw);

    //
    // window coordinates, dimensions...
    //
    void              ScreenToClient(TPoint& point) const;
    void              MapWindowPoints(HWND    hWndTo,
                                      TPoint* points,
                                      int     count) const;
    void              GetClientRect(TRect& rect) const;
    TRect             GetClientRect() const;
    static HWND       WindowFromPoint(const TPoint& point);
    HWND              ChildWindowFromPoint(const TPoint& point) const;
    void              ClientToScreen(TPoint& point) const;
    void              GetWindowRect(TRect& rect) const;
    TRect             GetWindowRect() const;
    static void       AdjustWindowRect(TRect& rect, uint32 style, bool menu);
    static void       AdjustWindowRectEx(TRect& rect, uint32 style,
                                         bool  menu,  uint32 exStyle);

    //
    // window and class Words and Longs, window properties
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
    int               EnumProps(PROPENUMPROC proc);
    HANDLE            GetProp(uint16 atom) const;
    HANDLE            RemoveProp(uint16 atom) const;
    bool              SetProp(uint16 atom, HANDLE data) const;
    HANDLE            GetProp(const char far* str) const;
    HANDLE            RemoveProp(const char far* str) const;
    bool              SetProp(const char far* str, HANDLE data) const;

    //
    // window placement(X,Y) and display
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

    //
    // window positioning(Z), sibling relationships
    //
    void              BringWindowToTop();
    static HWND       GetActiveWindow();
    HWND              SetActiveWindow();
    static HWND       GetDesktopWindow();
#if defined(BI_PLAT_WIN16)
    static HWND       GetSysModalWindow();
    HWND              SetSysModalWindow();
#endif
    HWND              GetLastActivePopup() const;
    HWND              GetNextWindow(uint dirFlag) const;
    HWND              GetTopWindow() const;
    HWND              GetWindow(uint cmd) const;
    bool              SetWindowPos(HWND         hWndInsertAfter,
                                   const TRect& rect,
                                   uint         flags);
    bool              SetWindowPos(HWND hWndInsertAfter,
                                   int x, int y, int w, int h,
                                   uint flags);

    //
    // window painting: invalidating, validating & updating
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

    //
    // scrolling and scrollbars
    //
    int               GetScrollPos(int bar) const;
    int               SetScrollPos(int bar, int pos, bool redraw = true);
    void              GetScrollRange(int bar, int& minPos, int& maxPos) const;
    void              SetScrollRange(int  bar,
                                     int  minPos,
                                     int  maxPos,
                                     bool redraw = true);
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

    //
    // parent/child with Ids
    //
    int               GetDlgCtrlID() const;
    HWND              GetDlgItem(int childId) const;
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
    HWND              GetParent() const;
    bool              IsChild(HWND) const;
    HWND              GetNextDlgGroupItem(HWND hWndCtrl,
                                          bool previous = false) const;
    HWND              GetNextDlgTabItem(HWND HWndCtrl,
                                        bool previous = false) const;
    void              CheckDlgButton(int buttonId, uint check);
    void              CheckRadioButton(int firstButtonId,
                                       int lastButtonId,
                                       int checkButtonId);

    //
    // menus and menubar
    //
    HMENU             GetMenu() const;
    HMENU             GetSystemMenu(bool revert = false) const;
    bool              SetMenu(HMENU hMenu);
    bool              HiliteMenuItem(HMENU hMenu, uint idItem, uint hilite);
    void              DrawMenuBar();

    //
    // obsolete way to open the global clipboard object. The recomended
    // way is to construct a TClipboard object using the TClipboard(HWND) ctor
    //
    TClipboard&       OpenClipboard();

    //
    // timer
    //
    bool              KillTimer(uint timerId);
    uint              SetTimer(uint timerId, uint timeout, TIMERPROC proc = 0);

    //
    // caret, cursor, font
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

    //
    // hot keys
    //
#if defined(BI_PLAT_WIN32)
    bool              RegisterHotKey(int  idHotKey,
                                     uint modifiers,
                                     uint virtKey);
    bool              UnregisterHotKey(int idHotKey);
#endif

    //
    // Misc
    //
    bool              WinHelp(const char far* helpFile,
                              uint            command,
                              uint32           data);
    int               MessageBox(const char far* text,
                                 const char far* caption = 0,
                                 uint            type = MB_OK);
    HTASK             GetWindowTask() const;
    void              DragAcceptFiles(bool accept);

    TCurrentEvent&   GetCurrentEvent() {return GetApplication()->GetCurrentEvent();}

  protected:
    //
    // these events are processed by TWindow
    //
    void              EvClose();
    int               EvCreate(CREATESTRUCT far& createStruct);
    void              EvDestroy();
    LRESULT           EvCompareItem(uint ctrlId, COMPAREITEMSTRUCT far& compareInfo);
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
    LRESULT           EvWin32CtlColor(WPARAM, LPARAM);

    void              CmExit();  // CM_EXIT

    //
    // input validation message handler
    //
    void              EvChildInvalid(HWND hWnd);

    //
    // system messages
    //
    void              EvCommNotify(uint commId, uint status);
    void              EvCompacting(uint compactRatio);
    void              EvDevModeChange(char far* devName);
    void              EvEnable(bool enabled);
    void              EvEndSession(bool endSession);
    void              EvFontChange();
    int               EvPower(uint powerEvent);
    void              EvSysCommand(uint cmdType, TPoint& point);
    void              EvSystemError(uint error);
    void              EvTimeChange();
    void              EvTimer(uint timerId);
    void              EvWinIniChange(char far* section);

    //
    // window manager messages
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
    uint              EvMouseActivate(HWND hWndTopLevel,
                                      uint hitTestCode,
                                      uint msg);

    // The following five are called under Win32 only
    //
    void              EvInputFocus(bool gainingFocus);
    void              EvOtherWindowCreated(HWND hWndOther);
    void              EvOtherWindowDestroyed(HWND hWndOther);
    void              EvPaintIcon();
    void              EvHotKey(int idHotKey);

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

    //
    // keyboard input
    //
    void              EvChar(uint key, uint repeatCount, uint flags);
    void              EvDeadChar(uint deadKey, uint repeatCount, uint flags);
    void              EvKeyDown(uint key, uint repeatCount, uint flags);
    void              EvKeyUp(uint key, uint repeatCount, uint flags);
    void              EvSysChar(uint key, uint repeatCount, uint flags);
    void              EvSysDeadChar(uint key, uint repeatCount, uint flags);
    void              EvSysKeyDown(uint key, uint repeatCount, uint flags);
    void              EvSysKeyUp(uint key, uint repeatCount, uint flags);

    //
    // controls
    //
    HBRUSH            EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType);

    //
    // mouse input
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

    //
    // menu related messages
    //
    void              EvInitMenu(HMENU hMenu);
    void              EvInitMenuPopup(HMENU hPopupMenu,
                                      uint  index,
                                      bool  sysMenu);
    uint              EvMenuChar(uint nChar, uint menuType, HMENU hMenu);
    void              EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu);

    //
    // dialog messages
    //
    void              EvEnterIdle(uint source, HWND hWndDlg);
    uint              EvGetDlgCode(MSG far* msg);

    //
    // print manager messages
    //
    void              EvSpoolerStatus(uint jobStatus, uint jobsLeft);

    //
    // clipboard messages
    //
    void              EvAskCBFormatName(uint bufLen, char far* buffer);
    void              EvChangeCBChain(HWND hWndRemoved, HWND hWndNext);
    void              EvDrawClipboard();
    void              EvDestroyClipboard();
    void              EvHScrollClipboard(HWND hWndCBViewer,
                                         uint scrollCode,
                                         uint pos);
    void              EvPaintClipboard(HWND hWnd, HANDLE hPaintStruct);
    void              EvRenderAllFormats();
    void              EvRenderFormat(uint dataFormat);
    void              EvSizeClipboard(HWND hWndViewer, HANDLE hRect);
    void              EvVScrollClipboard(HWND hWndCBViewer,
                                         uint scrollCode,
                                         uint pos);

    //
    // palette manager messages
    //
    void              EvPaletteChanged(HWND hWndPalChg);
    void              EvPaletteIsChanging(HWND hWndPalChg);
    bool              EvQueryNewPalette();

    //
    // drag-n-drop messages
    //
    void              EvDropFiles(TDropInfo dropInfo);

    //
    // list box messages
    //
    int               EvCharToItem(uint key, HWND hWndListBox, uint caretPos);
    int               EvVKeyToItem(uint key, HWND hWndListBox, uint caretPos);

    //
    // non-client messages
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
    void              EvNCPaint();
    void              EvNCRButtonDblClk(uint hitTest, TPoint& point);
    void              EvNCRButtonDown(uint hitTest, TPoint& point);
    void              EvNCRButtonUp(uint hitTest, TPoint& point);

  protected:
    // Constructor & subsequent initializer for use with virtual derivations
    // Immediate derivitives must call Init() before constructions are done.
    //
    TWindow();
    void              Init(TWindow* parent, const char far* title, TModule* module);

    virtual void      GetWindowClass(WNDCLASS& wndClass);
    virtual char far* GetClassName();

    virtual void      SetupWindow();
    virtual void      CleanupWindow();

    void              DispatchScroll(uint scrollCode, uint thumbPos, HWND hWndCtrl);

    void              LoadAcceleratorTable();
    virtual void      RemoveChild(TWindow* child);

    TWindow*          GetWindowPtr(HWND hWnd) const;

  protected:
    void*        TransferBuffer;
    HACCEL       hAccel;
    TModule*     CursorModule;
    TResId       CursorResId;
    HCURSOR      HCursor;
    uint32       BkgndColor;

  private:
    WNDPROC         Thunk;        // Thunk that load 'this' into registers
    TApplication*   Application;  // Application that this window belongs to
    TModule*        Module;       // default module used for getting resources
    uint32          Flags;
    uint16          ZOrder;
    TWindow*        ChildList;
    TWindow*        SiblingList;
    uint32          UniqueId;

    static uint32   LastUniqueId;

    void              Init(TWindow* parent, TModule* module);
    bool              OrderIsI(TWindow* win, void* position);
    void              AssignZOrder();
    void              AddChild(TWindow* child);
    int               IndexOf(TWindow* child);
    TWindow*          At(int position);

    void              SetUniqueId();

    //
    // hidden to prevent accidental copying or assignment
    //
    TWindow(const TWindow&);
    TWindow& operator =(const TWindow&);

  DECLARE_RESPONSE_TABLE(TWindow);
  DECLARE_STREAMABLE(_OWLCLASS, TWindow, 3);
};  // end of class TWindow

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
inline TWindow* GetObjectPtr(HWND hWnd) {return ::GetWindowPtr(hWnd);}

#if defined(__TRACE) || defined(__WARN)
  ostream& operator <<(ostream& os, const TWindow& w);
#endif

//----------------------------------------------------------------------------

inline void
TWindow::SendNotification(int id, int notifyCode, HWND hCtl, uint msg) {
#if defined(BI_PLAT_WIN32)
  HandleMessage(msg, MAKEWPARAM(id, notifyCode), LPARAM(hCtl));
#else
  HandleMessage(msg, id, MAKELPARAM(hCtl, notifyCode));
#endif
}

//
// HWND wrappers
//
inline LRESULT
TWindow::SendDlgItemMessage(int     childId, uint   msg,
                            WPARAM wParam,  LPARAM lParam) {
  return ::SendDlgItemMessage(HWindow, childId, msg, wParam, lParam);
}

inline bool
TWindow::PostMessage(uint msg, WPARAM wParam, LPARAM lParam) {
  return ::PostMessage(HWindow, msg, wParam, lParam);
}

inline HWND
TWindow::GetCapture() {
  return ::GetCapture();
}

inline HWND
TWindow::SetCapture() {
  return ::SetCapture(HWindow);
}

inline void
TWindow::ReleaseCapture() {
  ::ReleaseCapture();
}

inline HWND
TWindow::GetFocus() {
  return ::GetFocus();
}

inline HWND
TWindow::SetFocus() {
  return ::SetFocus(HWindow);
}

inline bool
TWindow::IsWindowEnabled() const {
  return ::IsWindowEnabled(HWindow);
}

inline bool
TWindow::EnableWindow(bool enable) {
  return ::EnableWindow(HWindow, enable);
}

inline void
TWindow::SetRedraw(bool redraw) {
  SendMessage(WM_SETREDRAW, redraw);
}

inline void
TWindow::ScreenToClient(TPoint& point) const {
  ::ScreenToClient(HWindow, &point);
}

inline void
TWindow::MapWindowPoints(HWND hWndTo, TPoint* points, int count) const {
  ::MapWindowPoints(HWindow, hWndTo, points, count);
}

inline void
TWindow::GetClientRect(TRect& rect) const {
  ::GetClientRect(HWindow, &rect);
}

inline TRect TWindow::GetClientRect() const {
  TRect  rect;
  ::GetClientRect(HWindow, &rect);
  return rect;
}

inline HWND
TWindow::WindowFromPoint(const TPoint& point) {
  return ::WindowFromPoint(point);
}

inline HWND
TWindow::ChildWindowFromPoint(const TPoint& point) const {
  return ::ChildWindowFromPoint(HWindow, point);
}

inline void
TWindow::ClientToScreen(TPoint& point) const {
  ::ClientToScreen(HWindow, &point);
}

inline void
TWindow::GetWindowRect(TRect& rect) const {
  ::GetWindowRect(HWindow, &rect);
}

inline TRect
TWindow::GetWindowRect() const {
  TRect  rect;
  ::GetWindowRect(HWindow, &rect);
  return rect;
}

inline void
TWindow::AdjustWindowRect(TRect& rect, uint32 style, bool menu) {
  ::AdjustWindowRect(&rect, style, menu);
}

inline void
TWindow::AdjustWindowRectEx(TRect& rect, uint32 style, bool menu, uint32 exStyle) {
  ::AdjustWindowRectEx(&rect, style, menu, exStyle);
}


//
// window and class Words and Longs, window properties
//
inline long
TWindow::GetClassName(char far* className, int maxCount) const {
  return ::GetClassName(HWindow, className, maxCount);
}

inline long
TWindow::GetClassLong(int index) const {
  return ::GetClassLong(HWindow, index);
}

inline long
TWindow::SetClassLong(int index, long newLong) {
  return ::SetClassLong(HWindow, index, newLong);
}

inline uint16
TWindow::GetClassWord(int index) const {
  return ::GetClassWord(HWindow, index);
}

inline uint16
TWindow::SetClassWord(int index, uint16 newWord) {
  return ::SetClassWord(HWindow, index, newWord);
}

inline long
TWindow::GetWindowLong(int index) const {
  return ::GetWindowLong(HWindow, index);
}

inline long
TWindow::SetWindowLong(int index, long newLong) {
  return ::SetWindowLong(HWindow, index, newLong);
}

inline uint16
TWindow::GetWindowWord(int index) const {
  return ::GetWindowWord(HWindow, index);
}

inline uint16
TWindow::SetWindowWord(int index, uint16 newWord) {
  return ::SetWindowWord(HWindow, index, newWord);
}

inline int
TWindow::EnumProps(PROPENUMPROC proc) {
  return ::EnumProps(HWindow, proc);
}

inline HANDLE
TWindow::GetProp(uint16 atom) const {
  return :: GetProp(HWindow, (LPCSTR)(uint32)atom);
}

inline HANDLE
TWindow::RemoveProp(uint16 atom) const {
  return :: RemoveProp(HWindow, (LPCSTR)(uint32)atom);
}

inline bool
TWindow::SetProp(uint16 atom, HANDLE data) const {
  return :: SetProp(HWindow, (LPCSTR)(uint32)atom, data);
}

inline HANDLE
TWindow::GetProp(const char far* str) const {
  return ::GetProp(HWindow, str);
}

inline HANDLE
TWindow::RemoveProp(const char far* str) const {
  return ::RemoveProp(HWindow, str);
}

inline bool
TWindow::SetProp(const char far* str, HANDLE data) const {
  return ::SetProp(HWindow, str, data);
}

inline bool
TWindow::MoveWindow(int x, int y, int w, int h, bool repaint) {
  return ::MoveWindow(HWindow, x, y, w, h, repaint);
}

inline bool
TWindow::MoveWindow(const TRect& rect, bool repaint) {
  return ::MoveWindow(HWindow, rect.left, rect.top,
                      rect.Width(), rect.Height(), repaint);
}

inline bool
TWindow::ShowWindow(int cmdShow) {
  return ::ShowWindow(HWindow, cmdShow);
}

inline void
TWindow::ShowOwnedPopups(bool show) {
  ::ShowOwnedPopups(HWindow, show);
}

inline bool
TWindow::IsWindowVisible() const {
  return ::IsWindowVisible(HWindow);
}

inline bool
TWindow::IsZoomed() const {
  return ::IsZoomed(HWindow);
}

inline bool
TWindow::IsIconic() const {
  return ::IsIconic(HWindow);
}

inline int
TWindow::GetWindowTextLength() const {
  return ::GetWindowTextLength(HWindow);
}

inline int
TWindow::GetWindowText(char far* str, int maxCount) const {
  return ::GetWindowText(HWindow, str, maxCount);
}

inline void
TWindow::SetWindowText(const char far* str) {
  ::SetWindowText(HWindow, str);
}

inline bool
TWindow::GetWindowPlacement(WINDOWPLACEMENT* place) const {
  return ::GetWindowPlacement(HWindow, place);
}

inline bool
TWindow::SetWindowPlacement(const WINDOWPLACEMENT* place) {
  return ::SetWindowPlacement(HWindow, place);
}

inline void
TWindow::BringWindowToTop() {
  ::BringWindowToTop(HWindow);
}

inline HWND
TWindow::GetActiveWindow() {
  return ::GetActiveWindow();
}

inline HWND
TWindow::SetActiveWindow() {
  return ::SetActiveWindow(HWindow);
}

inline HWND
TWindow::GetDesktopWindow() {
  return ::GetDesktopWindow();
}

#if defined(BI_PLAT_WIN16)
inline HWND
TWindow::GetSysModalWindow() {
  return ::GetSysModalWindow();
}

inline HWND
TWindow::SetSysModalWindow() {
  return ::SetSysModalWindow(HWindow);
}

inline HWND
TWindow::GetNextWindow(uint flag) const {
  return ::GetNextWindow(HWindow, flag);
}
#endif

inline HWND
TWindow::GetLastActivePopup() const {
  return ::GetLastActivePopup(HWindow);
}

inline HWND
TWindow::GetWindow(uint flag) const {
  return ::GetWindow(HWindow, flag);
}

inline HWND
TWindow::GetTopWindow() const {
  return ::GetTopWindow(HWindow);
}

inline bool
TWindow::SetWindowPos(HWND hWndInsertAfter, const TRect& rect, uint flags) {
  return ::SetWindowPos(HWindow, hWndInsertAfter, rect.left, rect.top,
                        rect.Width(), rect.Height(), flags);
}

inline bool
TWindow::SetWindowPos(HWND hWndInsertAfter,
                      int x, int y, int w, int h,
                      uint flags) {
  return ::SetWindowPos(HWindow, hWndInsertAfter, x, y, w, h, flags);
}

inline void
TWindow::Invalidate(bool erase) {
  ::InvalidateRect(HWindow, 0, erase);
}

inline void
TWindow::InvalidateRect(const TRect& rect, bool erase) {
  ::InvalidateRect(HWindow, &rect, erase);
}

inline void
TWindow::InvalidateRgn(HRGN hRgn, bool erase) {
  ::InvalidateRgn(HWindow, hRgn, erase);
}

inline void
TWindow::Validate() {
  ::ValidateRect(HWindow, 0);
}

inline void
TWindow::ValidateRect(const TRect& rect) {
  ::ValidateRect(HWindow, &rect);
}

inline void
TWindow::ValidateRgn(HRGN hRgn) {
  ::ValidateRgn(HWindow, hRgn);
}

inline void
TWindow::UpdateWindow() {
  ::UpdateWindow(HWindow);
}

inline bool
TWindow::FlashWindow(bool invert) {
  return ::FlashWindow(HWindow, invert);
}

inline bool
TWindow::GetUpdateRect(TRect& rect, bool erase) const {
  return ::GetUpdateRect(HWindow, &rect, erase);
}

inline bool
TWindow::LockWindowUpdate() {
  return ::LockWindowUpdate(HWindow);
}

inline bool
TWindow::RedrawWindow(TRect* update, HRGN hUpdateRgn, uint redraw) {
  return ::RedrawWindow(HWindow, update, hUpdateRgn, redraw);
}

inline int
TWindow::GetScrollPos(int bar) const {
  return ::GetScrollPos(HWindow, bar);
}

inline int
TWindow::SetScrollPos(int bar, int pos, bool redraw) {
  return ::SetScrollPos(HWindow, bar, pos, redraw);
}

inline void
TWindow::GetScrollRange(int bar, int& minPos, int& maxPos) const {
  ::GetScrollRange(HWindow, bar, &minPos, &maxPos);
}

inline void
TWindow::SetScrollRange(int bar, int minPos, int maxPos, bool redraw) {
  ::SetScrollRange(HWindow, bar, minPos, maxPos, redraw);
}

inline bool
TWindow::EnableScrollBar(uint sbFlags, uint arrowFlags) {
  return ::EnableScrollBar(HWindow, sbFlags, arrowFlags);
}

inline void TWindow::ShowScrollBar(int bar, bool show) {
  ::ShowScrollBar(HWindow, bar, show);
}

inline void
TWindow::ScrollWindow(int              dx,
                      int              dy,
                      const TRect far* scroll,
                      const TRect far* clip) {
  ::ScrollWindow(HWindow, dx, dy, scroll, clip);
}

inline void
TWindow::ScrollWindowEx(int              dx,
                        int              dy,
                        const TRect far* scroll,
                        const TRect far* clip,
                        HRGN             hUpdateRgn,
                        TRect far*       update,
                        uint             flags) {
  ::ScrollWindowEx(HWindow, dx, dy, scroll, clip, hUpdateRgn, update, flags);
}

inline int
TWindow::GetDlgCtrlID() const {
  return ::GetDlgCtrlID(HWindow);
}

inline HWND
TWindow::GetDlgItem(int childId) const {
  return ::GetDlgItem(HWindow, childId);
}

inline uint
TWindow::GetDlgItemInt(int childId, bool* translated, bool isSigned) const {
  return ::GetDlgItemInt(HWindow, childId, (int*)translated, isSigned);
}

inline void
TWindow::SetDlgItemInt(int childId, uint value, bool isSigned) const {
  ::SetDlgItemInt(HWindow, childId, value, isSigned);
}

inline int
TWindow::GetDlgItemText(int childId, char far* text, int max) const {
  return ::GetDlgItemText(HWindow, childId, text, max);
}

inline void
TWindow::SetDlgItemText(int childId, const char far* text) const {
  ::SetDlgItemText(HWindow, childId, text);
}

inline uint
TWindow::IsDlgButtonChecked(int buttonId) const {
  return ::IsDlgButtonChecked(HWindow, buttonId);
}

inline HWND
TWindow::GetParent() const {
  return ::GetParent(HWindow);
}

inline bool
TWindow::IsChild(HWND hWnd) const {
  return ::IsChild(HWindow, hWnd);
}

inline HWND
TWindow::GetNextDlgGroupItem(HWND hWndCtrl, bool previous) const {
  return ::GetNextDlgGroupItem(HWindow, hWndCtrl, previous);
}

inline HWND
TWindow::GetNextDlgTabItem(HWND hWndCtrl, bool previous) const {
  return ::GetNextDlgTabItem(HWindow, hWndCtrl, previous);
}

inline void
TWindow::CheckDlgButton(int buttonId, uint check) {
  ::CheckDlgButton(HWindow, buttonId, check);
}

inline void
TWindow::CheckRadioButton(int firstButtonId, int lastButtonId, int checkButtonId) {
  ::CheckRadioButton(HWindow, firstButtonId, lastButtonId, checkButtonId);
}

inline HMENU
TWindow::GetMenu() const {
  return ::GetMenu(HWindow);
}

inline HMENU
TWindow::GetSystemMenu(bool revert) const {
  return ::GetSystemMenu(HWindow, revert);
}

inline bool
TWindow::SetMenu(HMENU hMenu) {
  return ::SetMenu(HWindow, hMenu);
}

inline bool
TWindow::HiliteMenuItem(HMENU hMenu, uint idItem, uint hilite) {
  return ::HiliteMenuItem(HWindow, hMenu, idItem, hilite);
}

inline void
TWindow::DrawMenuBar() {
  ::DrawMenuBar(HWindow);
}

inline TClipboard&
TWindow::OpenClipboard() {
  TClipboard& clip = TClipboard::GetClipboard();

  clip.OpenClipboard(HWindow);
  return clip;
}

inline bool
TWindow::KillTimer(uint timerId) {
  return ::KillTimer(HWindow, timerId);
}

inline uint
TWindow::SetTimer(uint timerId, uint timeout, TIMERPROC proc) {
  return ::SetTimer(HWindow, timerId, timeout, proc);
}

inline void
TWindow::CreateCaret(HBITMAP hBitmap) {
  ::CreateCaret(HWindow, hBitmap, 0, 0);
}

inline void
TWindow::CreateCaret(bool isGray, int width, int height) {
  ::CreateCaret(HWindow, (HBITMAP)(isGray ? 1 : 0), width, height);
}

inline void
TWindow::DestroyCaret() {
  ::DestroyCaret();
}

inline uint
TWindow::GetCaretBlinkTime() {
  return ::GetCaretBlinkTime();
}

inline void
TWindow::GetCaretPos(TPoint& point) {
  ::GetCaretPos(&point);
}

inline void
TWindow::HideCaret() {
  ::HideCaret(HWindow);
}

inline void
TWindow::SetCaretBlinkTime(uint16 milliSecs) {
  ::SetCaretBlinkTime(milliSecs);
}

inline void
TWindow::SetCaretPos(int x, int y) {
  ::SetCaretPos(x, y);
}

inline void
TWindow::SetCaretPos(const TPoint& pos) {
  ::SetCaretPos(pos.x, pos.y);
}

inline void
TWindow::ShowCaret() {
  ::ShowCaret(HWindow);
}

inline void
TWindow::GetCursorPos(TPoint& pos) {
  ::GetCursorPos(&pos);
}

inline void
TWindow::SetWindowFont(HFONT font, bool redraw) {
  HandleMessage(WM_SETFONT, WPARAM(font), redraw);
}

inline HFONT
TWindow::GetWindowFont() {
  return (HFONT)HandleMessage(WM_GETFONT);
}

#if defined(BI_PLAT_WIN32)
inline bool
TWindow::RegisterHotKey(int idHotKey, uint modifiers, uint virtKey) {
  return ::RegisterHotKey(HWindow, idHotKey, modifiers, virtKey);
}

inline bool
TWindow::UnregisterHotKey(int idHotKey) {
  return ::UnregisterHotKey(HWindow, idHotKey);
}
#endif

inline bool
TWindow::WinHelp(const char far* helpFile, uint command, uint32 data) {
  return ::WinHelp(HWindow, helpFile, command, data);
}

inline HTASK
TWindow::GetWindowTask() const {
#if defined(BI_PLAT_WIN32)
  return (HANDLE)::GetWindowThreadProcessId(HWindow, 0);
#else
  return ::GetWindowTask(HWindow);
#endif
}

inline void
TWindow::DragAcceptFiles(bool accept) {
  ::DragAcceptFiles(HWindow, accept);
}

inline TWindow* TWindow::GetWindowPtr(HWND hWnd) const {
  return ::GetWindowPtr(hWnd, GetApplication());
}

//
// inline member functions that call DefWindowProc()
//
inline void    TWindow::EvActivate(uint active,
                                   bool minimized,
                                   HWND hWndOther /*may be 0*/)
                   {DefaultProcessing();}
inline void    TWindow::EvActivateApp(bool active, HTASK hTask /* threadId*/)
                   {DefaultProcessing();}
inline void    TWindow::EvAskCBFormatName(uint bufLen, char far* buffer)
                   {DefaultProcessing();}
inline void    TWindow::EvCancelMode()
                   {DefaultProcessing();}
inline void    TWindow::EvChangeCBChain(HWND hWndRemoved, HWND hWndNext)
                   {DefaultProcessing();}
inline void    TWindow::EvChar(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline int     TWindow::EvCharToItem(uint key, HWND hWndListBox, uint caretPos)
                   {return (int)DefaultProcessing();}
inline int     TWindow::EvVKeyToItem(uint key, HWND hWndListBox, uint caretPos)
                   {return (int)DefaultProcessing();}
inline void    TWindow::EvCommNotify(uint commId, uint status)
                   {DefaultProcessing();}
inline void    TWindow::EvCompacting(uint compactRatio)
                   {DefaultProcessing();}
inline HBRUSH  TWindow::EvCtlColor(HDC hDC, HWND hWndChild, uint ctlType)
                   {return (HBRUSH)DefaultProcessing();}
inline void    TWindow::EvDeadChar(uint deadKey, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvDestroyClipboard()
                   {DefaultProcessing();}
inline void    TWindow::EvDevModeChange(char far*)
                   {DefaultProcessing();}
inline void    TWindow::EvDropFiles(TDropInfo)
                   {DefaultProcessing();}
inline void    TWindow::EvDrawClipboard()
                   {DefaultProcessing();}
inline void    TWindow::EvEnable(bool enabled)
                   {DefaultProcessing();}
inline void    TWindow::EvEndSession(bool endSession)
                   {DefaultProcessing();}
inline void    TWindow::EvEnterIdle(uint source, HWND hWndDlg)
                   {DefaultProcessing();}
inline void    TWindow::EvFontChange()
                   {DefaultProcessing();}
inline uint    TWindow::EvGetDlgCode(MSG far*)
                   {return (uint)DefaultProcessing();}
inline HFONT   TWindow::EvGetFont()
                   {return (HFONT)DefaultProcessing();}
inline void    TWindow::EvGetMinMaxInfo(MINMAXINFO far&)
                   {DefaultProcessing();}
inline void    TWindow::EvGetText(uint buffSize, char far* buff)
                   {DefaultProcessing();}
inline uint    TWindow::EvGetTextLength()
                   {return (uint)DefaultProcessing();}
inline void    TWindow::EvHotKey(int idHotKey)
                   {DefaultProcessing();}
inline void    TWindow::EvInputFocus(bool gainingFocus)
                   {DefaultProcessing();}
inline void    TWindow::EvHScrollClipboard(HWND hWndCBViewer,
                                           uint scrollCode,
                                           uint pos)
                   {DefaultProcessing();}
inline void    TWindow::EvIconEraseBkgnd(HDC)
                   {DefaultProcessing();}
inline void    TWindow::EvInitMenu(HMENU)
                   {DefaultProcessing();}
inline void    TWindow::EvKeyDown(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvKeyUp(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvLButtonDblClk(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvLButtonUp(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvMButtonDblClk(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvMButtonDown(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvMButtonUp(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline uint    TWindow::EvMenuChar(uint nChar, uint menuType, HMENU hMenu)
                   {return (uint)DefaultProcessing();}
inline void    TWindow::EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu)
                   {DefaultProcessing();}
inline uint    TWindow::EvMouseActivate(HWND hWndTopLevel, uint hitTestCode, uint msg)
                   {return (uint)DefaultProcessing();}
inline void    TWindow::EvMouseMove(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline bool    TWindow::EvNCActivate(bool active)
                   {return (bool)DefaultProcessing();}
inline uint    TWindow::EvNCCalcSize(bool calcValidRects, NCCALCSIZE_PARAMS far&)
                   {return (uint)DefaultProcessing();}
inline bool    TWindow::EvNCCreate(CREATESTRUCT far&)
                   {return (bool)DefaultProcessing();}
inline uint    TWindow::EvNCHitTest(TPoint&)
                   {return (uint)DefaultProcessing();}
inline void    TWindow::EvNCLButtonDblClk(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCLButtonDown(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCLButtonUp(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMButtonDblClk(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMButtonDown(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMButtonUp(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMouseMove(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCPaint()
                   {DefaultProcessing();}
inline void    TWindow::EvNCRButtonDblClk(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCRButtonDown(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCRButtonUp(uint hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNextDlgCtl(uint hctlOrDir, uint isHCtl)
                   {DefaultProcessing();}
inline void    TWindow::EvOtherWindowCreated(HWND hWndOther)
                   {DefaultProcessing();}
inline void    TWindow::EvOtherWindowDestroyed(HWND hWndOther)
                   {DefaultProcessing();}
inline void    TWindow::EvPaintIcon()
                   {DefaultProcessing();}
inline void    TWindow::EvPaintClipboard(HWND, HANDLE hPaintStruct)
                   {DefaultProcessing();}
inline void    TWindow::EvPaletteChanged(HWND hWndPalChg)
                   {DefaultProcessing();}
inline void    TWindow::EvPaletteIsChanging(HWND hWndPalChg)
                   {DefaultProcessing();}
inline void    TWindow::EvParentNotify(uint event,
                                       uint childHandleOrX,
                                       uint childIDOrY)
                   {DefaultProcessing();}
inline int     TWindow::EvPower(uint)
                   {return (int)DefaultProcessing();}
inline void    TWindow::EvSysCommand(uint cmdType, TPoint&)
                   {DefaultProcessing();}
inline HANDLE  TWindow::EvQueryDragIcon()
                   {return (HANDLE)DefaultProcessing();}
inline bool    TWindow::EvQueryNewPalette()
                   {return (bool)DefaultProcessing();}
inline bool    TWindow::EvQueryOpen()
                   {return (bool)DefaultProcessing();}
inline void    TWindow::EvQueueSync()
                   {DefaultProcessing();}
inline void    TWindow::EvRenderAllFormats()
                   {DefaultProcessing();}
inline void    TWindow::EvRenderFormat(uint dataFormat)
                   {DefaultProcessing();}
inline void    TWindow::EvRButtonDblClk(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvRButtonDown(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvRButtonUp(uint modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvSetFocus(HWND hWndLostFocus)
                   {DefaultProcessing();}
inline void    TWindow::EvSetFont(HFONT, bool)
                   {DefaultProcessing();}
inline void    TWindow::EvSetRedraw(bool)
                   {DefaultProcessing();}
inline void    TWindow::EvSetText(const char far*)
                   {DefaultProcessing();}
inline void    TWindow::EvShowWindow(bool show, uint status)
                   {DefaultProcessing();}
inline void    TWindow::EvSizeClipboard(HWND hWndViewer, HANDLE hRect)
                   {DefaultProcessing();}
inline void    TWindow::EvSpoolerStatus(uint jobStatus, uint jobsLeft)
                   {DefaultProcessing();}
inline void    TWindow::EvSysChar(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSysDeadChar(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSysKeyDown(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSysKeyUp(uint key, uint repeatCount, uint flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSystemError(uint error)
                   {DefaultProcessing();}
inline void    TWindow::EvTimeChange()
                   {DefaultProcessing();}
inline void    TWindow::EvTimer(uint timerId)
                   {DefaultProcessing();}
inline void    TWindow::EvWinIniChange(char far* section)
                   {DefaultProcessing();}
inline void    TWindow::EvVScrollClipboard(HWND hWndCBViewer,
                                           uint scrollCode,
                                           uint pos)
                   {DefaultProcessing();}
inline void    TWindow::EvWindowPosChanged(WINDOWPOS far& windowPos)
                   {DefaultProcessing();}
inline void    TWindow::EvWindowPosChanging(WINDOWPOS far& windowPos)
                   {DefaultProcessing();}

#endif  // OWL_WINDOW_H
