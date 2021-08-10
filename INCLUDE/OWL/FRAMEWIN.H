//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\framewin.h
//   Declaration of class TFrameWindow.
//----------------------------------------------------------------------------
#if !defined(__OWL_FRAMEWIN_H)
#define __OWL_FRAMEWIN_H

#if !defined(__OWL_WINDOW_H)
  #include <owl\window.h>
#endif

const int IDW_MDICLIENT     = 32001;
const int IDW_FIRSTMDICHILD = 32002;

//
//  class TMenuDescr
//  ----- ----------
//
//  Menu information used to allow merging of two menus
//
struct _OWLCLASS TMenuDescr {
    enum TGroup {
      FileGroup,
      EditGroup,
      ContainerGroup,
      ObjectGroup,
      WindowGroup,
      HelpGroup,
      NumGroups
    };
    TMenuDescr();
    TMenuDescr(TResId id, int fg, int eg, int cg, int og, int wg, int hg,
               TModule* module = ::Module);

    TResId   Id;
    TModule* Module;       // pointer to constructor caller's module
    int      GroupCount[NumGroups];
    
    friend ipstream& operator >>(ipstream& is, TMenuDescr& m);
    friend opstream& operator <<(opstream& os, const TMenuDescr& m);
};

//
//  class TFrameWindow
//  ----- ------------
//
//  adds the notion of a client window, keyboard navigation, and special
//  processing for commands (see member function EvCommand)
//
class _OWLCLASS TFrameWindow : virtual public TWindow {
  public:
    BOOL         KeyboardHandling;

    TFrameWindow(TWindow*        parent,
                 const char far* title = 0,
                 TWindow*        clientWnd = 0,
                 BOOL            shrinkToClient = FALSE,
                 TModule*        module = 0);

    TFrameWindow(HWND hWnd, TModule* module = 0);
   ~TFrameWindow();

    //
    // Menubar manipulating functions
    //
    virtual BOOL      AssignMenu(TResId menuResId);
    virtual BOOL      SetMenu(HMENU newMenu);
    void              SetMenuDescr(const TMenuDescr& menuDescr);
    const TMenuDescr* GetMenuDescr() const {return MenuDescr;}
    BOOL              MergeMenu(const TMenuDescr& childMenuDescr);
    BOOL              RestoreMenu();

    BOOL              SetIcon(TModule* iconModule, TResId iconResId);

    virtual TWindow*  GetClientWindow();
    virtual TWindow*  SetClientWindow(TWindow* clientWnd);

    //
    // sets flag indicating that the receiver has requested "keyboard
    // handling" (translation of keyboard input into control selections)
    //
    void              EnableKBHandler() {KeyboardHandling = TRUE;}

    //
    // override virtual functions defined by TWindow
    //
    BOOL              PreProcessMsg(MSG& msg);
    BOOL              IdleAction(long idleCount);
    BOOL              HoldFocusHWnd(HWND hWndLose, HWND hWndGain);
    BOOL              SetDocTitle(LPCSTR docname, int index);

  protected:
    HWND         HWndRestoreFocus;
    TWindow*     ClientWnd;
    int          DocTitleIndex;
    TModule*     MergeModule;

    //
    // Constructor & subsequent initializer for use with virtual derivations
    // Immediate derivitives must call Init() before constructions are done.
    //
    TFrameWindow();
    void              Init(TWindow* clientWnd, BOOL shrinkToClient);
    
    //
    // extra processing for commands: starts with the focus window and gives
    // it and its parent windows an opportunity to handle the command
    //
    LRESULT           EvCommand(UINT id, HWND hWndCtl, UINT notifyCode);
    void              EvCommandEnable(TCommandEnabler& ce);

    //
    // message response functions
    //
    void              EvInitMenuPopup(HMENU hPopupMenu,
                                      UINT  index,
                                      BOOL  sysMenu);
    void              EvPaint();
    BOOL              EvEraseBkgnd(HDC);
    HANDLE            EvQueryDragIcon();
    void              EvSetFocus(HWND hWndLostFocus);
    void              EvSize(UINT sizeType, TSize& size);
    void              EvParentNotify(UINT event,
                                     UINT childHandleOrX,
                                     UINT childIDOrY);

    //
    // override virtual function defined by TWindow
    //
    void              SetupWindow();

  private:
    TMenuDescr*  MenuDescr;
    TModule*     IconModule;
    TResId       IconResId;
    TPoint       MinimizedPos;

    void              Init(TWindow* clientWnd);
    BOOL              ResizeClientWindow(BOOL redraw = TRUE);
    TWindow*          FirstChildWithTab();

    //
    // hidden to prevent accidental copying or assignment
    //
    TFrameWindow(const TFrameWindow&);
    TFrameWindow& operator =(const TFrameWindow&);

  DECLARE_RESPONSE_TABLE(TFrameWindow);
  DECLARE_STREAMABLE(_OWLCLASS, TFrameWindow, 1);
};

#endif  // __OWL_FRAMEWIN_H
