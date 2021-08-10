//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Declaration of class TFrameWindow.
//----------------------------------------------------------------------------
#if !defined(OWL_FRAMEWIN_H)
#define OWL_FRAMEWIN_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif

// MDI window IDs
//
const int IDW_MDICLIENT     = 32000;  // ID of MDI client window 
const int IDW_FIRSTMDICHILD = 32001;  // child window IDs, 32 max to 32032

//
// command enabler for menu items
//
class _OWLCLASS TMenuItemEnabler : public TCommandEnabler {
  public:
    TMenuItemEnabler(HMENU hMenu, uint id, HWND hWndReceiver, int position)
      : TCommandEnabler(id, hWndReceiver) {HMenu = hMenu; Position = position;}

    //
    // override member functions of TCommandEnabler
    //
    void  Enable(bool);
    void  SetText(const char far*);
    void  SetCheck(int);
    HMENU GetMenu() {return HMenu;}
    int   GetPosition() {return Position;}

  protected:
    HMENU  HMenu;
    int    Position;
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
    bool         KeyboardHandling;

    TFrameWindow(TWindow*        parent,
                 const char far* title = 0,
                 TWindow*        clientWnd = 0,
                 bool            shrinkToClient = false,
                 TModule*        module = 0);

    TFrameWindow(HWND hWnd, TModule* module = 0);
   ~TFrameWindow();

    //
    // Menubar manipulating functions
    //
    virtual bool      AssignMenu(TResId menuResId);
    virtual bool      SetMenu(HMENU newMenu);
    void              SetMenuDescr(const TMenuDescr& menuDescr);
    const TMenuDescr* GetMenuDescr() const {return MenuDescr;}
    bool              MergeMenu(const TMenuDescr& childMenuDescr);
    bool              RestoreMenu();

    bool              SetIcon(TModule* iconModule, TResId iconResId);

    virtual TWindow*  GetClientWindow();
    virtual TWindow*  SetClientWindow(TWindow* clientWnd);
    void              RemoveChild(TWindow* child);
    virtual HWND      GetCommandTarget();

    //
    // sets flag indicating that the receiver has requested "keyboard
    // handling" (translation of keyboard input into control selections)
    //
    void              EnableKBHandler() {KeyboardHandling = true;}

    //
    // override virtual functions defined by TWindow
    //
    bool              PreProcessMsg(MSG& msg);
    bool              IdleAction(long idleCount);
    bool              HoldFocusHWnd(HWND hWndLose, HWND hWndGain);
    bool              SetDocTitle(const char far* docname, int index);

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
    void              Init(TWindow* clientWnd, bool shrinkToClient);
    
    //
    // extra processing for commands: starts with the focus window and gives
    // it and its parent windows an opportunity to handle the command
    //
    LRESULT           EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void              EvCommandEnable(TCommandEnabler& ce);

    //
    // message response functions
    //
    void              EvInitMenuPopup(HMENU hPopupMenu,
                                      uint  index,
                                      bool  sysMenu);
    void              EvPaint();
    bool              EvEraseBkgnd(HDC);
    HANDLE            EvQueryDragIcon();
    void              EvSetFocus(HWND hWndLostFocus);
    void              EvSize(uint sizeType, TSize& size);
    void              EvParentNotify(uint event,
                                     uint childHandleOrX,
                                     uint childIDOrY);
    void              EvEnterIdle(uint source, HWND hWndDlg);

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
    bool              ResizeClientWindow(bool redraw = true);
    TWindow*          FirstChildWithTab();

    //
    // hidden to prevent accidental copying or assignment
    //
    TFrameWindow(const TFrameWindow&);
    TFrameWindow& operator =(const TFrameWindow&);

  DECLARE_RESPONSE_TABLE(TFrameWindow);
  DECLARE_STREAMABLE(_OWLCLASS, TFrameWindow, 1);
};

#endif  // OWL_FRAMEWIN_H
