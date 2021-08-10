//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TNoteTab
//----------------------------------------------------------------------------
#if !defined(OWL_NOTETAB_H)
#define OWL_NOTETAB_H

// Macro defining class name (usable in resource definition)
//
#if !defined(OWL_NOTETAB)
# define OWL_NOTETAB "OWL_Notetab"
#endif

#if !defined(RC_INVOKED)

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(CLASSLIB_VECTIMP_H)
# include <classlib/vectimp.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TFont;

//
// class TNoteTabItem
// ~~~~~ ~~~~~~~~~~~~
// TNoteTabItem holds information about each tab in a notetab control.
// For example, the structure contains information about the title and size
// of each tab item.
//
struct TNoteTabItem
{
    TNoteTabItem(const char* label, uint32 clientData = 0);
    TNoteTabItem();

    TRect     Rect;             // Location of tab [client-area base coords]
    string    Label;            // Label of tab
    TSize     LabelSize;        // Width and height of label
    uint32    ClientData;       // User-defined data associated with item
};

//
// class TNoteTab
// ~~~~~ ~~~~~~~~
// TNoteTab encapsulates a tab control with each tab item along the bottom
// of the window.
//
class _OWLCLASS TNoteTab : public TControl {
  public:
    TNoteTab(TWindow*   parent,
             int        id,
             int x, int y, int w, int h,
             TWindow*   buddy = 0,
             bool       dialogBuddy = true,
             TModule*   module = 0);

    TNoteTab(TWindow* parent, int resourceId,
             TWindow* buddy = 0, 
             bool     dialogBuddy = true,
             TModule* module = 0);
   ~TNoteTab();

    // Add/remove tab items
    //
    int         Add(const char* txt, uint32 clientData = 0);
    int         Insert(const char* txt, int index, uint32 clientData = 0);
    bool        Delete(int index);
    bool        DeleteAll();

    // Set/Query attributes of TabControl
    //
    int         GetCount() const;
    int         GetSel() const;
    int         SetSel(int index);
    void        SetWindowFace(bool);         
    bool        GetWindowFace() const;         
    void        SetStyle3d(bool);            
    bool        GetStyle3d() const;

    // Set/Query attributes of Tab Items
    //
    bool        GetItem(int index, TNoteTabItem& item) const;
    bool        SetItem(int index, const TNoteTabItem& item);
    bool        IsVisible(int index) const;

    // Set/Query attributes of control window
    //
    void        AdjustRect(bool clientInWindowOut, TRect& rect);

    // Set/Query buddy window
    //
    HWND        GetBuddy() const;
    void        SetBuddy(HWND buddy);

    // Override TWindow virtual member function to handle transfers
    //
    uint        Transfer(void* buffer, TTransferDirection direction);

  protected:

    // Override TWindow virtual member functions
    //
    char far*   GetClassName();
    void        SetupWindow();
    void        Paint(TDC& dc, bool erase, TRect& rect);

    // Message Handlers
    //
    void        EvSize(uint sizeType, TSize& size);
    void        EvLButtonDown(uint modKeys, TPoint& point);
    uint        EvGetDlgCode(MSG far* msg);
    void        EvKeyDown(uint key, uint repeatCount, uint flags);

    // Routines handling underlying implementation
    //
    void        InitCtrl();
    void        SetupFont(HFONT font = 0);
    void        SetTabRects(int firstTab);
    void        InvalidateTabRect(int index);
    void        SetTabSize(int index);
    int         TabFromPoint(const TPoint& pt);
    void        GetTabsArea(TRect& rect);
    void        GetScrollerArea(TRect& rect);
    void        NotifyAndSelect(int index);

  protected_data:    
    bool        WindowFace;         // Active tab should use window color
    bool        Style3d;            // Draw with 3d style
    int         TopMargin;          // amount of space to res

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TNoteTab(const TNoteTab&);
    TNoteTab& operator =(const TNoteTab&);

    TFont*      TabFont;
    TWindow*    Buddy;
    THandle     BuddyHandle;
    TRect       ScrollRect;
    int         FirstVisibleTab;
    int         SelectedTab;
    TCVectorImp<TNoteTabItem*>* TabList;

  DECLARE_RESPONSE_TABLE(TNoteTab);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations

//
// Constructor of Notetab Item object. Initializes object with specified
// string label and optional user-defined data.
//
inline
TNoteTabItem::TNoteTabItem(const char* label, uint32 clientData)
: 
  Label(label),
  ClientData(clientData)
{
}

//
// Default constructor of Notetab Item object.
//
inline
TNoteTabItem::TNoteTabItem()
{
}

//
// Specify whether active tab should use the system's window color. If the
// the 'wf' parameter is true, the system's window color is used.
//
inline void 
TNoteTab::SetWindowFace(bool wf)
{
  WindowFace = wf;
}

//
// Return the flag specifying whether the active tab should use the system's
// window color.
//
inline bool 
TNoteTab::GetWindowFace() const
{
  return WindowFace;
}

//
// Specify whether the note tab should draw a 3D edge. if 'st' is true, the
// control displays a 3D edge.
//
inline void 
TNoteTab::SetStyle3d(bool st)
{
  Style3d = st;
}

//
// Return the flag specifying whether the notetab control should draw a 3D
// border.
//
inline bool 
TNoteTab::GetStyle3d() const
{
  return Style3d;
}

#endif  // !RC_INVOKED 
#endif  //  OWL_NOTETAB_H
