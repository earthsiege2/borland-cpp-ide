//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.12  $
//
// Definition of class TFrameWindow.
//----------------------------------------------------------------------------
#if !defined(OWL_FRAMEWIN_H)
#define OWL_FRAMEWIN_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_MENU_H)
# include <owl/menu.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// MDI window IDs
//
const int IDW_MDICLIENT     = 32000;  // ID of MDI client window
const int IDW_FIRSTMDICHILD = 32001;  // child window IDs, 32 max to 32032

//
// class TMenuItemEnabler
// ~~~~~ ~~~~~~~~~~~~~~~~
// Command enabler for menu items
//
class _OWLCLASS TMenuItemEnabler : public TCommandEnabler {
  public:
    TMenuItemEnabler(HMENU hMenu, uint id, HWND hWndReceiver, int position);

    // Override member functions of TCommandEnabler
    //
    void    Enable(bool enable);
    void    SetText(const char far* text);
    void    SetCheck(int check);

    // Menu specific member functions
    //
    HMENU   GetMenu();
    int     GetPosition();

  protected_data:
    HMENU   HMenu;
    int     Position;
};

//
// class TFrameWindow
// ~~~~~ ~~~~~~~~~~~~
// Adds the notion of a client window, keyboard navigation, and special
// processing for commands (see member function EvCommand)
//
class _OWLCLASS TFrameWindow : virtual public TWindow {
  public:
    TFrameWindow(TWindow*        parent,
                 const char far* title = 0,
                 TWindow*        clientWnd = 0,
                 bool            shrinkToClient = false,
                 TModule*        module = 0);

    TFrameWindow(HWND hWnd, TModule* module = 0);
   ~TFrameWindow();

    // Menubar manipulating functions
    //
    virtual bool    AssignMenu(TResId menuResId);
    virtual bool    SetMenu(HMENU newMenu);
    void            SetMenuDescr(const TMenuDescr& menuDescr);
    const TMenuDescr* GetMenuDescr() const;
    bool            MergeMenu(const TMenuDescr& childMenuDescr);
    bool            RestoreMenu();
    TModule*        GetMergeModule();

    HICON           GetIcon() const;
    HICON           GetIconSm() const;
    bool            SetIcon(TModule* iconModule, TResId iconResId);
    bool            SetIconSm(TModule* iconModule, TResId iconResIdSm);

    // Client and child window manipulation
    //
    virtual TWindow* GetClientWindow();
    virtual TWindow* SetClientWindow(TWindow* clientWnd);
    void            RemoveChild(TWindow* child);
    virtual HWND    GetCommandTarget();

    // Sets flag indicating that the receiver has requested "keyboard
    // handling" (translation of keyboard input into control selections)
    //
    bool            GetKeyboardHandling() const;
    void            SetKeyboardHandling(bool kh=true);
    void            EnableKBHandler();

    // Override virtual functions defined by TWindow
    //
    bool            PreProcessMsg(MSG& msg);
    bool            IdleAction(long idleCount);
    bool            HoldFocusHWnd(HWND hWndLose, HWND hWndGain);
    bool            SetDocTitle(const char far* docname, int index);

  protected:
    // Constructor & subsequent initializer for use with virtual derivations
    // Immediate derivitives must call Init() before constructions are done.
    //
    TFrameWindow();
    void            Init(TWindow* clientWnd, bool shrinkToClient);

    // The event handler functions that are virtual, and not dispatched thru
    // response tables
    //
    // Extra processing for commands: starts with the focus window and gives
    // it and its parent windows an opportunity to handle the command.
    //
    TResult         EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void            EvCommandEnable(TCommandEnabler& ce);

    // Tell child windows frame has minimized/maximized/restored
    //
    void            BroadcastResizeToChildren(uint sizeType, TSize& size);

    // Message response functions
    //
    void            EvInitMenuPopup(HMENU hPopupMenu, uint index, bool sysMenu);
    void            EvPaint();
    bool            EvEraseBkgnd(HDC);
    HANDLE          EvQueryDragIcon();
    void            EvSetFocus(HWND hWndLostFocus);
    void            EvSize(uint sizeType, TSize& size);
    void            EvParentNotify(uint event,
                                   uint childHandleOrX,
                                   uint childIDOrY);

    void            EvPaletteChanged(THandle hWndPalChg);
    bool            EvQueryNewPalette();

    // Override virtual functions defined by TWindow
    //
    void            SetupWindow();
    void            CleanupWindow();

    // Accesors to data members
    //
    HWND            GetHWndRestoreFocus();
    void            SetHWndRestoreFocus(HWND hwndRestoreFocus);
    int             GetDocTitleIndex() const;
    void            SetDocTitleIndex(int index);
    void            SetMergeModule(TModule* module);

  public_data:
    bool            KeyboardHandling;

  protected_data:
    THandle         HWndRestoreFocus;
    TWindow*        ClientWnd;
    int             DocTitleIndex;
    TModule*        MergeModule;

  private:
    TMenuDescr*     MenuDescr;
    TModule*        IconModule;
    TResId          IconResId;
    TModule*        IconSmModule;
    TResId          IconSmResId;
    TPoint          MinimizedPos;
    HICON           CurIcon;
    HICON           CurIconSm;

    void            Init(TWindow* clientWnd);
    bool            ResizeClientWindow(bool redraw = true);
    TWindow*        FirstChildWithTab();

    // Hidden to prevent accidental copying or assignment
    //
    TFrameWindow(const TFrameWindow&);
    TFrameWindow& operator =(const TFrameWindow&);

  DECLARE_RESPONSE_TABLE(TFrameWindow);
  DECLARE_STREAMABLE(_OWLCLASS, TFrameWindow, 2);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Construct a menu item enabler.
//
inline TMenuItemEnabler::TMenuItemEnabler(HMENU hMenu, uint id,
                                          HWND hWndReceiver, int position)
:
  TCommandEnabler(id, hWndReceiver),
  HMenu(hMenu),
  Position(position)
{
  if (::GetMenuItemID(HMenu, Position) == uint(-1))
    Flags = NonSender;
}

//
// Return the handle of the menu for this menu item.
//
inline HMENU TMenuItemEnabler::GetMenu()
{
  return HMenu;
}

//
// Return the position of the menu item.
//
inline int TMenuItemEnabler::GetPosition()
{
  return Position;
}

//
// Retrieve handle of icon of frame window
// NOTE: Only retrieves icon set via the 'SetIcon' API - does not retrieve
//       the small HICON associated with the HWND.
//
inline HICON TFrameWindow::GetIcon() const
{
    return CurIcon;
}

//
// Retrieve handle of icon of frame window
// NOTE: Only retrieves icon set via the 'SetIconSm' API - does not retrieve
//       the HICON associated with the HWND.
//
inline HICON TFrameWindow::GetIconSm() const
{
  return CurIconSm;
}

//
// Return the menu descriptor for the frame window.
//
inline const TMenuDescr* TFrameWindow::GetMenuDescr() const
{
  return MenuDescr;
}

//
// Return true if the frame window is handling keyboard messages.
//
inline bool TFrameWindow::GetKeyboardHandling() const
{
  return KeyboardHandling;
}

//
// Set the keyboard handling flag for the window.
//
inline void TFrameWindow::SetKeyboardHandling(bool kh)
{
  KeyboardHandling = kh;
}

//
// Sets the keyboard handling flag to true.
//
inline void TFrameWindow::EnableKBHandler()
{
  SetKeyboardHandling(true);
}

//
// Return the handle of the window to restore focus to.
//
inline HWND TFrameWindow::GetHWndRestoreFocus()
{
  return HWndRestoreFocus;
}

//
// Sets the remembered focused window.
//
inline void TFrameWindow::SetHWndRestoreFocus(HWND hwndrestorefocus)
{
  HWndRestoreFocus = hwndrestorefocus;
}

//
// Return the document title index.
//
inline int TFrameWindow::GetDocTitleIndex() const
{
  return DocTitleIndex;
}

//
// Set the current document's title index.
//
inline void TFrameWindow::SetDocTitleIndex(int index)
{
  DocTitleIndex = index;
}

//
// Return the module of the merge menu.
//
inline TModule* TFrameWindow::GetMergeModule()
{
  return MergeModule;
}

//
// Remember where the merged menu came from.
//
inline void TFrameWindow::SetMergeModule(TModule* module)
{
  MergeModule = module;
}

#endif  // OWL_FRAMEWIN_H
