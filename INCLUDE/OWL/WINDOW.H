//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\window.h
//   Base window class definition, including HWND encapsulation.
//----------------------------------------------------------------------------
#if !defined(__OWL_WINDOW_H)
#define __OWL_WINDOW_H

#if !defined(__OWL_POINT_H)
  #include <owl\point.h>
#endif
#if !defined(__OWL_CLIPBOAR_H)
  #include <owl\clipboar.h>
#endif
#if !defined(__OWL_WINDOWEV_H)
  #include <owl\windowev.h>
#endif
#if !defined(__OWL_MODULE_H)
  #include <owl\module.h>
#endif
#if defined(__WIN32__) && !defined(__CLASSLIB_THREAD_H)
  #include <classlib\thread.h>
#endif
#include <owl\window.rh>

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
  wfAlias           = 0x0001,
  wfAutoCreate      = 0x0002,
  wfFromResource    = 0x0004,
  wfShrinkToClient  = 0x0008,
  wfMainWindow      = 0x0010,
  wfStreamTop       = 0x0020,
  wfPredefinedClass = 0x0040,
  wfTransfer        = 0x0080,
  wfUnHidden        = 0x0100,  // used temporarily when destroying MDI child
  wfUnDisabled      = 0x0200,  // used temporarily when destroying MDI child
};

//
// Transfer function flags
//
enum TTransferDirection {tdGetData, tdSetData, tdSizeData};

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
const DWORD NoColor = 0xFF000000l;  // let DefWindowProc erase
const DWORD NoErase = 0xFE000000l;  // don't erase, wait for Paint

//
//  windows 3.1 windowsx.h name confict with TWindows::GetFirstChild()
//
#if defined(GetFirstChild)
  #undef GetFirstChild(hwnd)
#endif

typedef void (*TActionFunc)(TWindow* win, void* param);
typedef BOOL (*TCondFunc)(TWindow* win, void* param);

typedef void (TWindow::*TActionMemFunc)(TWindow* win, void* param);
typedef BOOL (TWindow::*TCondMemFunc)(TWindow* win, void* param);

//
//  class TCommandEnabler
//  ----- ---------------
//
//  provides an extensible interface for auto enabling/disabling of commands
//  (menu items, tool bar buttons, ...)
//
class _OWLCLASS TCommandEnabler {
  public:
    const UINT  Id;

    TCommandEnabler(UINT id, HWND hWndReceiver = 0);

    virtual void  Enable(BOOL enable = TRUE);  // sets "Handled" to TRUE
    virtual void  SetText(LPCSTR text) = 0;
    enum {Unchecked, Checked, Indeterminate};
    virtual void  SetCheck(int check) = 0;  // Unchecked, Checked, or Indeterminate

    BOOL        GetHandled() {return Handled;}
    BOOL        IsReceiver(HWND hReceiver) {return hReceiver==HWndReceiver;}

  protected:
    const HWND  HWndReceiver;
    BOOL        Handled;
};

//
//  struct TWindowsAttr
//  ------ ------------
//
//  Window creation attributes
//
struct TWindowAttr {
    DWORD      Style;
    DWORD      ExStyle;
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
        TXWindow(TWindow* win = 0, UINT resourceId = IDS_INVALIDWINDOW);
        TXWindow(const TXWindow& src);
        int Unhandled(TModule* app, unsigned promptResId);
        TXOwl* Clone();
        void Throw() {throw *this;}
        TWindow*      Window;
        static string Msg(TWindow* wnd, UINT resourceid);
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
    void              SetFlag(TWindowFlag mask) {Flags |= DWORD(mask);}
    void              ClearFlag(TWindowFlag mask) {Flags &= DWORD(~mask);}
    BOOL              IsFlagSet(TWindowFlag mask) {return (Flags & mask) ? 1 : 0;}

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
    virtual BOOL      Register();

    //
    // create/destroy an MS_Windows element to be associated with an OWL window
    //
    virtual BOOL      Create();
    virtual void      PerformCreate(int menuOrId);
    BOOL              CreateChildren();
    virtual void      Destroy(int retVal = 0);

    //
    // suggest an Owl window to close itself
    //
    virtual void      CloseWindow(int retVal = 0);

    //
    // This function is obsolete. Destroy() should be called directly, & then
    // the window destructed (using delete, etc).
    //
    void              ShutDownWindow(int retVal = 0);

  #if defined(__WIN32__)
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
    // if you return TRUE, further processing of the message is halted
    //
    // if you override this method in a derived class, make sure to call this
    // routine because it handles translation of accelerators...
    //
    virtual BOOL      PreProcessMsg(MSG& msg);
    virtual BOOL      IdleAction(long idleCount);
    virtual BOOL      HoldFocusHWnd(HWND hWndLose, HWND hWndGain);

    int               GetId() const {return Attr.Id;}
    TWindow*          ChildWithId(int id) const;

    virtual void      SetParent(TWindow* newParent);
    virtual BOOL      SetDocTitle(LPCSTR docname, int index);

    void              Show(int cmdShow);
    void              SetCaption(const char far* title);
    void              GetWindowTextTitle();
    void              GetHWndState();
    BOOL              SetCursor(TModule* module, TResId resId);
    void              SetBkgndColor(DWORD color) {BkgndColor = color;}

    virtual BOOL      CanClose();

    //
    // forwards the current event to "hWnd" using either PostMessage() or
    // SendMessage(). Owl window version calls directly to window proc on send.
    //
    LRESULT           ForwardMessage(HWND hWnd, BOOL send = TRUE);
    LRESULT           ForwardMessage(BOOL send = TRUE);

    //
    // send message to all children
    //
    void              ChildBroadcastMessage(UINT msg, WPARAM wParam=0, LPARAM lParam=0);

    //
    // Notify a window (parent usually) of a child action.
    //
    void              SendNotification(int id, int notifyCode, HWND hCtl,
                                       UINT msg = WM_COMMAND);

    //
    // Called from StdWndProc to allow exceptions to be caught and suspended.
    // Calls HandleMessage from within try block. Catches and suspends all
    // exceptions before returning to Windows (Windows is not exception safe).
    //
    LRESULT           ReceiveMessage(UINT   msg,
                                     WPARAM wParam = 0,
                                     LPARAM lParam = 0);

    //
    // Call a Window's window proc to handle a message. Similar to SendMessage
    // but more direct.
    //
    LRESULT           HandleMessage(UINT   msg,
                                    WPARAM wParam = 0,
                                    LPARAM lParam = 0);

    //
    // virtual functions called to handle a message, and to deal with an
    // unhandled message in a default way.
    //
    virtual LRESULT   WindowProc(UINT msg, WPARAM wParam, LPARAM lParam);
    virtual LRESULT   DefWindowProc(UINT msg, WPARAM wParam, LPARAM lParam);

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
    virtual LRESULT   EvCommand(UINT id, HWND hWndCtl, UINT notifyCode);

    //
    // called by WindowProc() to handle WM_COMMAND_ENABLE
    //
    virtual void      EvCommandEnable(TCommandEnabler& ce);

    //
    // default processing, deals with special cases or calling DefWindowProc
    //
    LRESULT           DefaultProcessing();

    //
    // Paint function called by base classes when responding to WM_PAINT
    //
    virtual void      Paint(TDC& dc, BOOL erase, TRect& rect);

    //
    // transfer buffer
    //
    void              SetTransferBuffer(void* transferBuffer)
                          {TransferBuffer = transferBuffer;}
    virtual UINT      Transfer(void* buffer, TTransferDirection direction);
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
    BOOL              IsWindow() const {return ::IsWindow(HWindow);}

    //
    // messages
    //
    LRESULT           SendMessage(UINT   msg,
                                  WPARAM wParam = 0,
                                  LPARAM lParam = 0);
    LRESULT           SendDlgItemMessage(int    childId,
                                         UINT   msg,
                                         WPARAM wParam = 0,
                                         LPARAM lParam = 0);
    BOOL              PostMessage(UINT   msg,
                                  WPARAM wParam = 0,
                                  LPARAM lParam = 0);
    static HWND       GetCapture();
    HWND              SetCapture();
    static void       ReleaseCapture();
    static HWND       GetFocus();
    HWND              SetFocus();
    BOOL              IsWindowEnabled() const;
    virtual BOOL      EnableWindow(BOOL enable);
    void              SetRedraw(BOOL redraw);

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
    static void       AdjustWindowRect(TRect& rect, DWORD style, BOOL menu);
    static void       AdjustWindowRectEx(TRect& rect, DWORD style,
                                         BOOL  menu,  DWORD exStyle);

    //
    // window and class Words and Longs, window properties
    //
    long              GetClassName(char far* className, int maxCount) const;
    long              GetClassLong(int index) const;
    long              SetClassLong(int index, long newLong);
    WORD              GetClassWord(int index) const;
    WORD              SetClassWord(int index, WORD newWord);
    long              GetWindowLong(int index) const;
    long              SetWindowLong(int index, long newLong);
    WORD              GetWindowWord(int index) const;
    WORD              SetWindowWord(int index, WORD newWord);
    int               EnumProps(PROPENUMPROC proc);
    HANDLE            GetProp(WORD atom) const;
    HANDLE            RemoveProp(WORD atom) const;
    BOOL              SetProp(WORD atom, HANDLE data) const;
    HANDLE            GetProp(const char far* str) const;
    HANDLE            RemoveProp(const char far* str) const;
    BOOL              SetProp(const char far* str, HANDLE data) const;

    //
    // window placement(X,Y) and display
    //
    BOOL              MoveWindow(int x, int y, int w, int h, BOOL repaint = FALSE);
    BOOL              MoveWindow(const TRect& rect, BOOL repaint = FALSE);
    virtual BOOL      ShowWindow(int cmdShow);
    void              ShowOwnedPopups(BOOL show);
    BOOL              IsWindowVisible() const;
    BOOL              IsZoomed() const;
    BOOL              IsIconic() const;
    int               GetWindowTextLength() const;
    int               GetWindowText(char far* str, int maxCount) const;
    void              SetWindowText(const char far* str);
    BOOL              GetWindowPlacement(WINDOWPLACEMENT* place) const;
    BOOL              SetWindowPlacement(const WINDOWPLACEMENT* place);

    //
    // window positioning(Z), sibling relationships
    //
    void              BringWindowToTop();
    static HWND       GetActiveWindow();
    HWND              SetActiveWindow();
    static HWND       GetDesktopWindow();
  #if !defined(__WIN32__)
    static HWND       GetSysModalWindow();
    HWND              SetSysModalWindow();
  #endif
    HWND              GetLastActivePopup() const;
    HWND              GetNextWindow(UINT dirFlag) const;
    HWND              GetTopWindow() const;
    HWND              GetWindow(UINT cmd) const;
    BOOL              SetWindowPos(HWND         hWndInsertAfter,
                                   const TRect& rect,
                                   UINT         flags);
    BOOL              SetWindowPos(HWND hWndInsertAfter,
                                   int x, int y, int w, int h,
                                   UINT flags);

    //
    // window painting: invalidating, validating & updating
    //
    void              Invalidate(BOOL erase = TRUE);
    void              InvalidateRect(const TRect& rect, BOOL erase = TRUE);
    void              InvalidateRgn(HRGN hRgn, BOOL erase = TRUE);
    void              Validate();
    void              ValidateRect(const TRect& rect);
    void              ValidateRgn(HRGN hRgn);
    void              UpdateWindow();
    BOOL              FlashWindow(BOOL invert);
    BOOL              GetUpdateRect(TRect& rect, BOOL erase = TRUE) const;
    BOOL              GetUpdateRgn(TRegion& rgn, BOOL erase = TRUE) const;
    BOOL              LockWindowUpdate();
    BOOL              RedrawWindow(TRect* update,
                                   HRGN   hUpdateRgn,
                                   UINT   redrawFlags = RDW_INVALIDATE | RDW_UPDATENOW | RDW_ERASE);

    //
    // scrolling and scrollbars
    //
    int               GetScrollPos(int bar) const;
    int               SetScrollPos(int bar, int pos, BOOL redraw = TRUE);
    void              GetScrollRange(int bar, int& minPos, int& maxPos) const;
    void              SetScrollRange(int  bar,
                                     int  minPos,
                                     int  maxPos,
                                     BOOL redraw = TRUE);
    BOOL              EnableScrollBar(UINT sbFlags=SB_BOTH,
                                      UINT arrowFlags=ESB_ENABLE_BOTH);
    void              ShowScrollBar(int bar, BOOL show = TRUE);
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
                                     UINT             flags = 0);

    //
    // parent/child with Ids
    //
    int               GetDlgCtrlID() const;
    HWND              GetDlgItem(int childId) const;
    UINT              GetDlgItemInt(int   childId,
                                    BOOL* translated = 0,
                                    BOOL  isSigned = TRUE) const;
    void              SetDlgItemInt(int  childId,
                                    UINT value,
                                    BOOL isSigned = TRUE) const;
    int               GetDlgItemText(int       childId,
                                     char far* text,
                                     int       max) const;
    void              SetDlgItemText(int childId, const char far* text) const;
    UINT              IsDlgButtonChecked(int buttonId) const;
    HWND              GetParent() const;
    BOOL              IsChild(HWND) const;
    HWND              GetNextDlgGroupItem(HWND hWndCtrl,
                                          BOOL previous = FALSE) const;
    HWND              GetNextDlgTabItem(HWND HWndCtrl,
                                        BOOL previous = FALSE) const;
    void              CheckDlgButton(int buttonId, UINT check);
    void              CheckRadioButton(int firstButtonId,
                                       int lastButtonId,
                                       int checkButtonId);

    //
    // menus and menubar
    //
    HMENU             GetMenu() const;
    HMENU             GetSystemMenu(BOOL revert = FALSE) const;
    BOOL              SetMenu(HMENU hMenu);
    BOOL              HiliteMenuItem(HMENU hMenu, UINT idItem, UINT hilite);
    void              DrawMenuBar();

    //
    // clipboard
    //
    TClipboard&       OpenClipboard();

    //
    // timer
    //
    BOOL              KillTimer(UINT timerId);
    UINT              SetTimer(UINT timerId, UINT timeout, TIMERPROC proc = 0);

    //
    // caret, cursor, font
    //
    void              CreateCaret(HBITMAP hBitmap);
    void              CreateCaret(BOOL isGray, int width, int height);
    static UINT       GetCaretBlinkTime();
    static void       GetCaretPos(TPoint& point);
    void              HideCaret();
    static void       SetCaretBlinkTime(WORD milliSecs);
    static void       SetCaretPos(int x, int y);
    static void       SetCaretPos(const TPoint& pos);
    void              ShowCaret();
    static void       DestroyCaret();
    static void       GetCursorPos(TPoint& pos);
    void              SetWindowFont(HFONT font, BOOL redraw);
    HFONT             GetWindowFont();

    //
    // hot keys
    //
  #if defined(__WIN32__)
    BOOL              RegisterHotKey(int  idHotKey,
                                     UINT modifiers,
                                     UINT virtKey);
    BOOL              UnregisterHotKey(int idHotKey);
  #endif

    //
    // Misc
    //
    BOOL              WinHelp(const char far* helpFile,
                              UINT            command,
                              DWORD           data);
    int               MessageBox(const char far* text,
                                 const char far* caption = 0,
                                 UINT            type = MB_OK);
    HTASK             GetWindowTask() const;
    void              DragAcceptFiles(BOOL accept);

  protected:
    //
    // these events are processed by TWindow
    //
    void              EvClose();
    int               EvCreate(CREATESTRUCT far& createStruct);
    void              EvDestroy();
    LRESULT           EvCompareItem(UINT ctrlId, COMPAREITEMSTRUCT far& compareInfo);
    void              EvDeleteItem(UINT ctrlId, DELETEITEMSTRUCT far& deleteInfo);
    void              EvDrawItem(UINT ctrlId, DRAWITEMSTRUCT far& drawInfo);
    void              EvMeasureItem(UINT ctrlId, MEASUREITEMSTRUCT far& measureInfo);
    void              EvHScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl);
    void              EvVScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtl);
    void              EvMove(TPoint& clientOrigin);
    void              EvNCDestroy();
    BOOL              EvQueryEndSession();
    void              EvSize(UINT sizeType, TSize& size);
    void              EvLButtonDown(UINT modKeys, TPoint& point);
    BOOL              EvEraseBkgnd(HDC);
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
    void              EvCompacting(UINT compactRatio);
    void              EvDevModeChange(char far* devName);
    void              EvEnable(BOOL enabled);
    void              EvEndSession(BOOL endSession);
    void              EvFontChange();
    int               EvPower(UINT powerEvent);
    void              EvSysCommand(UINT cmdType, TPoint& point);
    void              EvSystemError(UINT error);
    void              EvTimeChange();
    void              EvTimer(UINT timerId);
    void              EvWinIniChange(char far* section);

    //
    // window manager messages
    //
    void              EvActivate(UINT active,
                                 BOOL minimized,
                                 HWND hWndOther /* may be 0 */);
    void              EvActivateApp(BOOL active, HTASK hTask);
    void              EvCancelMode();
    void              EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
    void              EvIconEraseBkgnd(HDC hDC);
    void              EvKillFocus(HWND hWndGetFocus /* may be 0 */);
    UINT              EvMouseActivate(HWND hWndTopLevel,
                                      UINT hitTestCode,
                                      UINT msg);

    // The following five are called under Win32 only
    //
    void              EvInputFocus(BOOL gainingFocus);
    void              EvOtherWindowCreated(HWND hWndOther);
    void              EvOtherWindowDestroyed(HWND hWndOther);
    void              EvPaintIcon();
    void              EvHotKey(int idHotKey);

    void              EvParentNotify(UINT event,
                                     UINT childHandleOrX,
                                     UINT childIDOrY);
    HANDLE            EvQueryDragIcon();
    BOOL              EvQueryOpen();
    BOOL              EvSetCursor(HWND hWndCursor,
                                  UINT hitTest,
                                  UINT mouseMsg);
    void              EvSetFocus(HWND hWndLostFocus /* may be 0 */);
    void              EvSetFont(HFONT, BOOL);
    void              EvSetText(const char far*);
    void              EvShowWindow(BOOL show, UINT status);
    void              EvWindowPosChanged(WINDOWPOS far& windowPos);
    void              EvWindowPosChanging(WINDOWPOS far& windowPos);

    //
    // keyboard input
    //
    void              EvChar(UINT key, UINT repeatCount, UINT flags);
    void              EvDeadChar(UINT deadKey, UINT repeatCount, UINT flags);
    void              EvKeyDown(UINT key, UINT repeatCount, UINT flags);
    void              EvKeyUp(UINT key, UINT repeatCount, UINT flags);
    void              EvSysChar(UINT key, UINT repeatCount, UINT flags);
    void              EvSysDeadChar(UINT key, UINT repeatCount, UINT flags);
    void              EvSysKeyDown(UINT key, UINT repeatCount, UINT flags);
    void              EvSysKeyUp(UINT key, UINT repeatCount, UINT flags);

    //
    // controls
    //
    HBRUSH            EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType);

    //
    // mouse input
    //
    void              EvLButtonDblClk(UINT modKeys, TPoint& point);
    void              EvLButtonUp(UINT modKeys, TPoint& point);
    void              EvMButtonDblClk(UINT modKeys, TPoint& point);
    void              EvMButtonDown(UINT modKeys, TPoint& point);
    void              EvMButtonUp(UINT modKeys, TPoint& point);
    void              EvMouseMove(UINT modKeys, TPoint& point);
    void              EvRButtonDblClk(UINT modKeys, TPoint& point);
    void              EvRButtonDown(UINT modKeys, TPoint& point);
    void              EvRButtonUp(UINT modKeys, TPoint& point);

    //
    // menu related messages
    //
    void              EvInitMenu(HMENU hMenu);
    void              EvInitMenuPopup(HMENU hPopupMenu,
                                      UINT  index,
                                      BOOL  sysMenu);
    UINT              EvMenuChar(UINT nChar, UINT menuType, HMENU hMenu);
    void              EvMenuSelect(UINT menuItemId, UINT flags, HMENU hMenu);

    //
    // dialog messages
    //
    void              EvEnterIdle(UINT source, HWND hWndDlg);
    UINT              EvGetDlgCode(MSG far*);

    //
    // print manager messages
    //
    void              EvSpoolerStatus(UINT jobStatus, UINT jobsLeft);

    //
    // clipboard messages
    //
    void              EvAskCBFormatName(UINT bufLen, char far* buffer);
    void              EvChangeCBChain(HWND hWndRemoved, HWND hWndNext);
    void              EvDrawClipboard();
    void              EvDestroyClipboard();
    void              EvHScrollClipboard(HWND hWndCBViewer,
                                         UINT scrollCode,
                                         UINT pos);
    void              EvPaintClipboard(HWND hWnd, HANDLE hPaintStruct);
    void              EvRenderAllFormats();
    void              EvRenderFormat(UINT dataFormat);
    void              EvSizeClipboard(HWND hWndViewer, HANDLE hRect);
    void              EvVScrollClipboard(HWND hWndCBViewer,
                                         UINT scrollCode,
                                         UINT pos);

    //
    // palette manager messages
    //
    void              EvPaletteChanged(HWND hWndPalChg);
    void              EvPaletteIsChanging(HWND hWndPalChg);
    BOOL              EvQueryNewPalette();

    //
    // drag-n-drop messages
    //
    void              EvDropFiles(TDropInfo dropInfo);

    //
    // list box messages
    //
    int               EvCharToItem(UINT key, HWND hWndListBox, UINT caretPos);
    int               EvVKeyToItem(UINT key, HWND hWndListBox, UINT caretPos);

    //
    // non-client messages
    //
    BOOL              EvNCActivate(BOOL active);
    UINT              EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far& params);
    BOOL              EvNCCreate(CREATESTRUCT far& createStruct);
    UINT              EvNCHitTest(TPoint& point);
    void              EvNCLButtonDblClk(UINT hitTest, TPoint& point);
    void              EvNCLButtonDown(UINT hitTest, TPoint& point);
    void              EvNCLButtonUp(UINT hitTest, TPoint& point);
    void              EvNCMButtonDblClk(UINT hitTest, TPoint& point);
    void              EvNCMButtonDown(UINT hitTest, TPoint& point);
    void              EvNCMButtonUp(UINT hitTest, TPoint& point);
    void              EvNCMouseMove(UINT hitTest, TPoint& point);
    void              EvNCPaint();
    void              EvNCRButtonDblClk(UINT hitTest, TPoint& point);
    void              EvNCRButtonDown(UINT hitTest, TPoint& point);
    void              EvNCRButtonUp(UINT hitTest, TPoint& point);

  protected:
    void*        TransferBuffer;
    HACCEL       hAccel;
    TModule*     CursorModule;
    TResId       CursorResId;
    HCURSOR      HCursor;
    DWORD        BkgndColor;

    //
    // Constructor & subsequent initializer for use with virtual derivations
    // Immediate derivitives must call Init() before constructions are done.
    //
    TWindow();
    void              Init(TWindow* parent, const char far* title, TModule* module);

    virtual void      GetWindowClass(WNDCLASS& wndClass);
    virtual char far* GetClassName();

    virtual void      SetupWindow();
    virtual void      CleanupWindow();

    void              DispatchScroll(UINT scrollCode, UINT thumbPos, HWND hWndCtrl);

    void              LoadAcceleratorTable();
    virtual void      RemoveChild(TWindow* child);

  private:
    WNDPROC         Thunk;        // Thunk that load 'this' into registers
    TApplication*   Application;  // Application that this window belongs to
    TModule*        Module;       // default module used for getting resources
    DWORD           Flags;
    WORD            ZOrder;
    TWindow*        ChildList;
    TWindow*        SiblingList;
    DWORD           UniqueId;

    static DWORD    LastUniqueId;

    void              Init(TWindow* parent, TModule* module);
    BOOL              OrderIsI(TWindow* win, void* position);
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
  DECLARE_STREAMABLE(_OWLCLASS, TWindow, 1);
};  // end of class TWindow

//
// A TActionFunc defined in window.cpp
//
void DoEnableAutoCreate(TWindow* win, void*);

//
// Global funciton to retrieve a TWindow pointer given an HWND
//
TWindow* _OWLFUNC GetWindowPtr(HWND hWnd);
inline TWindow*   GetObjectPtr(HWND hWnd) {return GetWindowPtr(hWnd);}

#if defined(__TRACE) || defined(__WARN)
  ostream& operator <<(ostream& os, const TWindow& w);
#endif

//----------------------------------------------------------------------------

inline void
TWindow::SendNotification(int id, int notifyCode, HWND hCtl, UINT msg) {
  #if defined(__WIN32__)
    HandleMessage(msg, MAKEWPARAM(id, notifyCode), LPARAM(hCtl));
  #else
    HandleMessage(msg, id, MAKELPARAM(hCtl, notifyCode));
  #endif
}

//
// HWND wrappers
//
inline LRESULT
TWindow::SendDlgItemMessage(int     childId, UINT   msg,
                             WPARAM wParam,  LPARAM lParam) {
  return ::SendDlgItemMessage(HWindow, childId, msg, wParam, lParam);
}

inline BOOL
TWindow::PostMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
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

inline BOOL
TWindow::IsWindowEnabled() const {
  return ::IsWindowEnabled(HWindow);
}

inline BOOL
TWindow::EnableWindow(BOOL enable) {
  return ::EnableWindow(HWindow, enable);
}

inline void
TWindow::SetRedraw(BOOL redraw) {
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
TWindow::AdjustWindowRect(TRect& rect, DWORD style, BOOL menu) {
  ::AdjustWindowRect(&rect, style, menu);
}

inline void
TWindow::AdjustWindowRectEx(TRect& rect, DWORD style, BOOL menu, DWORD exStyle) {
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

inline WORD
TWindow::GetClassWord(int index) const {
  return ::GetClassWord(HWindow, index);
}

inline WORD
TWindow::SetClassWord(int index, WORD newWord) {
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

inline WORD
TWindow::GetWindowWord(int index) const {
  return ::GetWindowWord(HWindow, index);
}

inline WORD
TWindow::SetWindowWord(int index, WORD newWord) {
  return ::SetWindowWord(HWindow, index, newWord);
}

inline int
TWindow::EnumProps(PROPENUMPROC proc) {
  return ::EnumProps(HWindow, proc);
}

inline HANDLE
TWindow::GetProp(WORD atom) const {
  return :: GetProp(HWindow, (LPCSTR)(DWORD)atom);
}

inline HANDLE
TWindow::RemoveProp(WORD atom) const {
  return :: RemoveProp(HWindow, (LPCSTR)(DWORD)atom);
}

inline BOOL
TWindow::SetProp(WORD atom, HANDLE data) const {
  return :: SetProp(HWindow, (LPCSTR)(DWORD)atom, data);
}

inline HANDLE
TWindow::GetProp(const char far* str) const {
  return ::GetProp(HWindow, str);
}

inline HANDLE
TWindow::RemoveProp(const char far* str) const {
  return ::RemoveProp(HWindow, str);
}

inline BOOL
TWindow::SetProp(const char far* str, HANDLE data) const {
  return ::SetProp(HWindow, str, data);
}

inline BOOL
TWindow::MoveWindow(int x, int y, int w, int h, BOOL repaint) {
  return ::MoveWindow(HWindow, x, y, w, h, repaint);
}

inline BOOL
TWindow::MoveWindow(const TRect& rect, BOOL repaint) {
  return ::MoveWindow(HWindow, rect.left, rect.top,
                      rect.Width(), rect.Height(), repaint);
}

inline BOOL
TWindow::ShowWindow(int cmdShow) {
  return ::ShowWindow(HWindow, cmdShow);
}

inline void
TWindow::ShowOwnedPopups(BOOL show) {
  ::ShowOwnedPopups(HWindow, show);
}

inline BOOL
TWindow::IsWindowVisible() const {
  return ::IsWindowVisible(HWindow);
}

inline BOOL
TWindow::IsZoomed() const {
  return ::IsZoomed(HWindow);
}

inline BOOL
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

inline BOOL
TWindow::GetWindowPlacement(WINDOWPLACEMENT* place) const {
  return ::GetWindowPlacement(HWindow, place);
}

inline BOOL
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

#if !defined(__WIN32__)
inline HWND
TWindow::GetSysModalWindow() {
  return ::GetSysModalWindow();
}

inline HWND
TWindow::SetSysModalWindow() {
  return ::SetSysModalWindow(HWindow);
}

inline HWND
TWindow::GetNextWindow(UINT flag) const {
  return ::GetNextWindow(HWindow, flag);
}
#endif

inline HWND
TWindow::GetLastActivePopup() const {
  return ::GetLastActivePopup(HWindow);
}

inline HWND
TWindow::GetWindow(UINT flag) const {
  return ::GetWindow(HWindow, flag);
}

inline HWND
TWindow::GetTopWindow() const {
  return ::GetTopWindow(HWindow);
}

inline BOOL
TWindow::SetWindowPos(HWND hWndInsertAfter, const TRect& rect, UINT flags) {
  return ::SetWindowPos(HWindow, hWndInsertAfter, rect.left, rect.top,
                        rect.Width(), rect.Height(), flags);
}

inline BOOL
TWindow::SetWindowPos(HWND hWndInsertAfter,
                      int x, int y, int w, int h,
                      UINT flags) {
  return ::SetWindowPos(HWindow, hWndInsertAfter, x, y, w, h, flags);
}

inline void
TWindow::Invalidate(BOOL erase) {
  ::InvalidateRect(HWindow, 0, erase);
}

inline void
TWindow::InvalidateRect(const TRect& rect, BOOL erase) {
  ::InvalidateRect(HWindow, &rect, erase);
}

inline void
TWindow::InvalidateRgn(HRGN hRgn, BOOL erase) {
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

inline BOOL
TWindow::FlashWindow(BOOL invert) {
  return ::FlashWindow(HWindow, invert);
}

inline BOOL
TWindow::GetUpdateRect(TRect& rect, BOOL erase) const {
  return ::GetUpdateRect(HWindow, &rect, erase);
}

inline BOOL
TWindow::LockWindowUpdate() {
  return ::LockWindowUpdate(HWindow);
}

inline BOOL
TWindow::RedrawWindow(TRect* update, HRGN hUpdateRgn, UINT redraw) {
  return ::RedrawWindow(HWindow, update, hUpdateRgn, redraw);
}

inline int
TWindow::GetScrollPos(int bar) const {
  return ::GetScrollPos(HWindow, bar);
}

inline int
TWindow::SetScrollPos(int bar, int pos, BOOL redraw) {
  return ::SetScrollPos(HWindow, bar, pos, redraw);
}

inline void
TWindow::GetScrollRange(int bar, int& minPos, int& maxPos) const {
  ::GetScrollRange(HWindow, bar, &minPos, &maxPos);
}

inline void
TWindow::SetScrollRange(int bar, int minPos, int maxPos, BOOL redraw) {
  ::SetScrollRange(HWindow, bar, minPos, maxPos, redraw);
}

inline BOOL
TWindow::EnableScrollBar(UINT sbFlags, UINT arrowFlags) {
  return ::EnableScrollBar(HWindow, sbFlags, arrowFlags);
}

inline void TWindow::ShowScrollBar(int bar, BOOL show) {
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
                        UINT             flags) {
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

inline UINT
TWindow::GetDlgItemInt(int childId, BOOL* translated, BOOL isSigned) const {
  return ::GetDlgItemInt(HWindow, childId, translated, isSigned);
}

inline void
TWindow::SetDlgItemInt(int childId, UINT value, BOOL isSigned) const {
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

inline UINT
TWindow::IsDlgButtonChecked(int buttonId) const {
  return ::IsDlgButtonChecked(HWindow, buttonId);
}

inline HWND
TWindow::GetParent() const {
  return ::GetParent(HWindow);
}

inline BOOL
TWindow::IsChild(HWND hWnd) const {
  return ::IsChild(HWindow, hWnd);
}

inline HWND
TWindow::GetNextDlgGroupItem(HWND hWndCtrl, BOOL previous) const {
  return ::GetNextDlgGroupItem(HWindow, hWndCtrl, previous);
}

inline HWND
TWindow::GetNextDlgTabItem(HWND hWndCtrl, BOOL previous) const {
  return ::GetNextDlgTabItem(HWindow, hWndCtrl, previous);
}

inline void
TWindow::CheckDlgButton(int buttonId, UINT check) {
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
TWindow::GetSystemMenu(BOOL revert) const {
  return ::GetSystemMenu(HWindow, revert);
}

inline BOOL
TWindow::SetMenu(HMENU hMenu) {
  return ::SetMenu(HWindow, hMenu);
}

inline BOOL
TWindow::HiliteMenuItem(HMENU hMenu, UINT idItem, UINT hilite) {
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

inline BOOL
TWindow::KillTimer(UINT timerId) {
  return ::KillTimer(HWindow, timerId);
}

inline UINT
TWindow::SetTimer(UINT timerId, UINT timeout, TIMERPROC proc) {
  return ::SetTimer(HWindow, timerId, timeout, proc);
}

inline void
TWindow::CreateCaret(HBITMAP hBitmap) {
  ::CreateCaret(HWindow, hBitmap, 0, 0);
}

inline void
TWindow::CreateCaret(int shade, int width, int height) {
  ::CreateCaret(HWindow,(HBITMAP) shade, width, height);
}

inline void
TWindow::DestroyCaret() {
  ::DestroyCaret();
}

inline UINT
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
TWindow::SetCaretBlinkTime(WORD milliSecs) {
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
TWindow::SetWindowFont(HFONT font, BOOL redraw) {
  HandleMessage(WM_SETFONT, WPARAM(font), redraw);
}

inline HFONT
TWindow::GetWindowFont() {
  return (HFONT)HandleMessage(WM_GETFONT);
}

#if defined(__WIN32__)
inline BOOL
TWindow::RegisterHotKey(int idHotKey, UINT modifiers, UINT virtKey) {
  return ::RegisterHotKey(HWindow, idHotKey, modifiers, virtKey);
}

inline BOOL
TWindow::UnregisterHotKey(int idHotKey) {
  return ::UnregisterHotKey(HWindow, idHotKey);
}
#endif

inline BOOL
TWindow::WinHelp(const char far* helpFile, UINT command, DWORD data) {
  return ::WinHelp(HWindow, helpFile, command, data);
}

inline HTASK
TWindow::GetWindowTask() const {
#if defined(__WIN32__)
  return (HANDLE)::GetWindowThreadProcessId(HWindow, 0);
#else
  return ::GetWindowTask(HWindow);
#endif
}

inline void
TWindow::DragAcceptFiles(BOOL accept) {
  ::DragAcceptFiles(HWindow, accept);
}

//
// inline member functions that call DefWindowProc()
//
inline void    TWindow::EvActivate(UINT active,
                                   BOOL minimized,
                                   HWND hWndOther /*may be 0*/)
                   {DefaultProcessing();}
inline void    TWindow::EvActivateApp(BOOL active, HTASK hTask /* threadId*/)
                   {DefaultProcessing();}
inline void    TWindow::EvAskCBFormatName(UINT bufLen, char far* buffer)
                   {DefaultProcessing();}
inline void    TWindow::EvCancelMode()
                   {DefaultProcessing();}
inline void    TWindow::EvChangeCBChain(HWND hWndRemoved, HWND hWndNext)
                   {DefaultProcessing();}
inline void    TWindow::EvChar(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline int     TWindow::EvCharToItem(UINT key, HWND hWndListBox, UINT caretPos)
                   {return (int)DefaultProcessing();}
inline int     TWindow::EvVKeyToItem(UINT key, HWND hWndListBox, UINT caretPos)
                   {return (int)DefaultProcessing();}
inline void    TWindow::EvCompacting(UINT compactRatio)
                   {DefaultProcessing();}
inline HBRUSH  TWindow::EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType)
                   {return (HBRUSH)DefaultProcessing();}
inline void    TWindow::EvDeadChar(UINT deadKey, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvDestroyClipboard()
                   {DefaultProcessing();}
inline void    TWindow::EvDevModeChange(char far*)
                   {DefaultProcessing();}
inline void    TWindow::EvDropFiles(TDropInfo)
                   {DefaultProcessing();}
inline void    TWindow::EvDrawClipboard()
                   {DefaultProcessing();}
inline void    TWindow::EvEnable(BOOL enabled)
                   {DefaultProcessing();}
inline void    TWindow::EvEndSession(BOOL endSession)
                   {DefaultProcessing();}
inline void    TWindow::EvEnterIdle(UINT source, HWND hWndDlg)
                   {DefaultProcessing();}
inline void    TWindow::EvFontChange()
                   {DefaultProcessing();}
inline UINT    TWindow::EvGetDlgCode(MSG far*)
                   {return (UINT)DefaultProcessing();}
inline void    TWindow::EvGetMinMaxInfo(MINMAXINFO far&)
                   {DefaultProcessing();}
inline void  TWindow::EvHotKey(int idHotKey)
                   {DefaultProcessing();}
inline void  TWindow::EvInputFocus(BOOL gainingFocus)
                   {DefaultProcessing();}
inline void    TWindow::EvHScrollClipboard(HWND hWndCBViewer,
                                           UINT scrollCode,
                                           UINT pos)
                   {DefaultProcessing();}
inline void    TWindow::EvIconEraseBkgnd(HDC)
                   {DefaultProcessing();}
inline void    TWindow::EvInitMenu(HMENU)
                   {DefaultProcessing();}
inline void    TWindow::EvInitMenuPopup(HMENU hPopupMenu, UINT index, BOOL sysMenu)
                   {DefaultProcessing();}
inline void    TWindow::EvKeyDown(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvKeyUp(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvLButtonDblClk(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvLButtonUp(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvMButtonDblClk(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvMButtonDown(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvMButtonUp(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline UINT    TWindow::EvMenuChar(UINT nChar, UINT menuType, HMENU hMenu)
                   {return (UINT)DefaultProcessing();}
inline void    TWindow::EvMenuSelect(UINT menuItemId, UINT flags, HMENU hMenu)
                   {DefaultProcessing();}
inline UINT    TWindow::EvMouseActivate(HWND hWndTopLevel, UINT hitTestCode, UINT msg)
                   {return (UINT)DefaultProcessing();}
inline void    TWindow::EvMouseMove(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline BOOL    TWindow::EvNCActivate(BOOL active)
                   {return (BOOL)DefaultProcessing();}
inline UINT    TWindow::EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far&)
                   {return (UINT)DefaultProcessing();}
inline BOOL    TWindow::EvNCCreate(CREATESTRUCT far&)
                   {return (BOOL)DefaultProcessing();}
inline UINT    TWindow::EvNCHitTest(TPoint&)
                   {return (UINT)DefaultProcessing();}
inline void    TWindow::EvNCLButtonDblClk(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCLButtonDown(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCLButtonUp(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMButtonDblClk(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMButtonDown(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMButtonUp(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCMouseMove(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCPaint()
                   {DefaultProcessing();}
inline void    TWindow::EvNCRButtonDblClk(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCRButtonDown(UINT hitTest, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvNCRButtonUp(UINT hitTest, TPoint&)
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
inline void    TWindow::EvParentNotify(UINT event,
                                       UINT childHandleOrX,
                                       UINT childIDOrY)
                   {DefaultProcessing();}
inline int     TWindow::EvPower(UINT)
                   {return (int)DefaultProcessing();}
inline void    TWindow::EvSysCommand(UINT cmdType, TPoint&)
                   {DefaultProcessing();}
inline HANDLE  TWindow::EvQueryDragIcon()
                   {return (HANDLE)DefaultProcessing();}
inline BOOL    TWindow::EvQueryNewPalette()
                   {return (BOOL)DefaultProcessing();}
inline BOOL    TWindow::EvQueryOpen()
                   {return (BOOL)DefaultProcessing();}
inline void    TWindow::EvRenderAllFormats()
                   {DefaultProcessing();}
inline void    TWindow::EvRenderFormat(UINT dataFormat)
                   {DefaultProcessing();}
inline void    TWindow::EvRButtonDblClk(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvRButtonDown(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvRButtonUp(UINT modKeys, TPoint&)
                   {DefaultProcessing();}
inline void    TWindow::EvSetFocus(HWND hWndLostFocus)
                   {DefaultProcessing();}
inline void    TWindow::EvSetFont(HFONT, BOOL)
                   {DefaultProcessing();}
inline void    TWindow::EvSetText(const char far*)
                   {DefaultProcessing();}
inline void    TWindow::EvShowWindow(BOOL show, UINT status)
                   {DefaultProcessing();}
inline void    TWindow::EvSizeClipboard(HWND hWndViewer, HANDLE hRect)
                   {DefaultProcessing();}
inline void    TWindow::EvSpoolerStatus(UINT jobStatus, UINT jobsLeft)
                   {DefaultProcessing();}
inline void    TWindow::EvSysChar(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSysDeadChar(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSysKeyDown(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSysKeyUp(UINT key, UINT repeatCount, UINT flags)
                   {DefaultProcessing();}
inline void    TWindow::EvSystemError(UINT error)
                   {DefaultProcessing();}
inline void    TWindow::EvTimeChange()
                   {DefaultProcessing();}
inline void    TWindow::EvTimer(UINT timerId)
                   {DefaultProcessing();}
inline void    TWindow::EvWinIniChange(char far* section)
                   {DefaultProcessing();}
inline void    TWindow::EvVScrollClipboard(HWND hWndCBViewer,
                                           UINT scrollCode,
                                           UINT pos)
                   {DefaultProcessing();}
inline void    TWindow::EvWindowPosChanged(WINDOWPOS far& windowPos)
                   {DefaultProcessing();}
inline void    TWindow::EvWindowPosChanging(WINDOWPOS far& windowPos)
                   {DefaultProcessing();}

#endif  // __OWL_WINDOW_H
