//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.12  $
//
// Definition of class TTabItem and TTabControl.
//----------------------------------------------------------------------------
#if !defined(OWL_TABCTRL_H)
#define OWL_TABCTRL_H

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_CONTAIN_H)
# include <owl/contain.h>
#endif
#if !defined(OWL_UPDOWN_H)
# include <owl/updown.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Mentioned in documentation but currently missing from system headers
//
#if !defined(TCIF_ALL)
# define TCIF_ALL  (TCIF_TEXT|TCIF_IMAGE|TCIF_PARAM)
#endif

// Forward ref.
//
class _OWLCLASS TFont;
class _OWLCLASS TTabControl;
class _OWLCLASS TTabEntryInternal;

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TTabItem
// ~~~~~ ~~~~~~~~
//  TTabItem encapsulates the attributes of a single tab within a 
//  tab control. For example, it holds the string containing the
//  tab's text.
//
class _OWLCLASS TTabItem : public TC_ITEM {
  public:
    TTabItem(uint mask);
    TTabItem(const TC_ITEM& tbItem);
    TTabItem(const TTabControl& ctl, int index, uint mask,
             int buffLen = 0, char far* buffer = 0);

    // Used for setting label
    //
    TTabItem(const char far* str, int buffLen = 0, TParam2 param = 0);

    // Used for setting image
    //
    TTabItem(int imageIndex, TParam2 param);

    // Used for setting both image and label
    //
    TTabItem(int imageIndex, const char far*str);

    void    SetLabel(const char far* str, int len = 0);
    void    SetIcon(int imageIndex);
    void    SetParam(TParam2 lp);
};


#if !defined(OWL_NATIVECTRL_ALWAYS)
//
// Class TTabEntryInternal
// ~~~~~ ~~~~~~~~~~~~~~~~~
// TTabEntryInternal is a helper class used by TTabControl when the latter
// implements Tabs without the help of the Common Control Library..
//
// NOTE: You should not rely on the implementation of this class. It's
//       for internal use only.
//
class _OWLCLASS TTabEntryInternal : public TTabItem {
  public:
    TTabEntryInternal(const TC_ITEM& tbItem);
   ~TTabEntryInternal();

    TRect   Rect;           // Actual Location of item in Window
    TSize   Size;           // Desired Size of Tab
    int     Row;            // Row number (MultiLine only)

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TTabEntryInternal(const TTabEntryInternal&);
    TTabEntryInternal& operator =(const TTabEntryInternal&);
};
#endif  //  !OWL_NATIVECTRL_ALWAYS

//
// class TTabHitTestInfo
// ~~~~~ ~~~~~~~~~~~~~~~
//  TTabHitTestInfo is a thin [very thin] wrapper around
//  the TC_HITTESTINFO structure. It's a place-holder for
//  future ObjectWindows enhancements for tabcontrol hit
//  testing..
//
class _OWLCLASS TTabHitTestInfo : public TC_HITTESTINFO {
};

//
// class TTabControl
// ~~~~~ ~~~~~~~~~~~
//  TTabControl encapsulates the tab control - a window that provides
//  a user interface analogous to dividers in a notebook.
//
class _OWLCLASS TTabControl : public TControl {
  public:
    TTabControl(TWindow* parent,
                int             id,
                int x, int y, int w, int h,
                TModule*        module = 0);

    TTabControl(TWindow* parent, int resourceId, TModule* module = 0);
    TTabControl(HWND hwnd);
   ~TTabControl();

    // Add/remove tab items
    //
    int         Add(const TTabItem&);
    int         Add(const char far* tabText);
    int         Insert(const TTabItem&, int index);
    int         Insert(const char far* tabText, int index);
    bool        Delete(int index);
    bool        DeleteAll();

    // Set/Querry attributes of TabControl
    //
    int         GetCount() const;
    int         GetRowCount() const;
    int         GetSel() const;
    int         SetSel(int index);

    // Set/Querry attributes of Tab Items
    //
    bool        GetItem(int index, TTabItem& item) const;
    bool        GetItemRect(int index, TRect& rect) const;
    bool        SetItem(int index, const TTabItem& item);
    bool        SetItemExtra(int extra);
    TSize       SetItemSize(const TSize& size);
    void        SetPadding(const TSize& size);

    // Set/Querry attributes of control window
    //
    void        AdjustRect(bool clientInWindowOut, TRect& rect);
    HIMAGELIST  GetImageList() const;
    HIMAGELIST  SetImageList(HIMAGELIST);
    void        RemoveImage(int index);

    // Tooltip
    //
    HWND        GetToolTips() const;
    void        SetToolTips(HWND toolTip);

    int         HitTest(TTabHitTestInfo&);

    // Override TWindow virtual member function to handle transfers
    //
    uint        Transfer(void* buffer, TTransferDirection direction);

  protected:

    // Override TWindow virtual member functions
    //
    char far*   GetClassName();

    // Override TWindow handlers
    //
    void        EvHScroll(uint scrollCode, uint thumbPos, THandle hWndCtl);
    void        EvVScroll(uint scrollCode, uint thumbPos, THandle hWndCtl);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TTabControl(const TTabControl&);
    TTabControl& operator =(const TTabControl&);

#if !defined(OWL_NATIVECTRL_ALWAYS)

    // The following data members and methods are used when the TTabControl
    // object provides the underlying implementation of 'TabControls'.
    // They are private to this class.
    //
    void        InitCtl();
    void        CleanupCtl();
    void        SetupFont(HFONT font = 0);
    void        SetupNormalFont(TFont* normalFont);
    void        SetupSelectFont(TFont* selectFont);

    void        GetWindowClass(WNDCLASS& wndClass);
    void        SetupWindow();

    // Message Handlers
    //
    void        EvSize(uint sizeType, TSize& size);
    void        EvLButtonDown(uint modKeys, TPoint& point);
    void        EvSetFocus(THandle hWndLostFocus);
    void        EvKillFocus(THandle hWndGetFocus);
    uint        EvGetDlgCode(MSG far* msg);
    void        EvKeyDown(uint key, uint repeatCount, uint flags);


    // NOTE: The Paint() method will only be called if this
    //       object does not encapsulate a predefined class.
    //       See TControl::EvPaint()
    //
    void        Paint(TDC& dc, bool erase, TRect& rect);
    void        PaintTab(TDC& dc, const TRect& tbRect, const char far* txt,
                         bool clip = false);
    void        PaintTabBorder(TDC& dc, const TRect& tbClient,
                               const TRect* selTab = 0);
    void        DrawFocusRect(TDC& dc, bool inFocus);
    void        InvalidateTabRect(int index);


    void        SetTabRect(int index, TRect* newRect);
    void        SetTabRects(int firstTab = 0);
    void        SetTabRectsSingle(int firstTab);
    void        SetTabSize(int index, int width = 0, int height = 0);
    int         TabFromPoint(const TPoint& pt) const;

    int         GetFirstVisibleTab() const;
    void        SetFirstVisibleTab(int);
    void        NotifyAndSelect(int index, bool bringInView = false);
    void        UpdateScrollRange();

    // Querry region of various components currently laid out in the control
    //
    void        GetTabsArea(TRect& rect);
    void        GetClientArea(TRect& rect, bool innerRect = false);
    void        GetSelTabArea(TRect& rect);
    void        GetScrollerArea(TRect& rect);

    // Querry whether a tab is visible or clipped
    //
    bool        IsVisible(int index);
    bool        IsClipped(int index);

    TUpDown*    Updown;               // Points to scroller (single row only)
    TFont*      NormalFont;           // Points to font of non-selected tabs
    TFont*      SelectFont;           // Points to font of selected tabs
    int         SelectedTab;          // Index of selected tab
    int         FirstVisibleTab;      // Index of upper left tab
    int         NumRows;              // Num of rows (Currently still single)
    TSize       Padding;              // Padding between tabs
    TSize       TabSize;              // Desired height (and width) of tabs
    TCollection<TTabEntryInternal>* TabList;

#endif  //  !OWL_NATIVECTRL_ALWAYS

  DECLARE_RESPONSE_TABLE(TTabControl);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inlines implementations
//

//
// Constructor for a Tab Item:
// This constructor is useful when creating a TabItem (TC_ITEM) structure
// which will be filled with information about an existing tab in a
// tab control. For example,
//
//              TTabItem item(TCIF_IMAGE|TCIF_PARAM);
//              tabCtrl.GetItem(index, item);
//
inline TTabItem::TTabItem(uint msk) {
  mask = msk;
}

//
// Constructs a 'TTabItem' object from a 'TC_ITEM' structure using the
// assignment operator.
// NOTE:  Default assignment operator is fine even if we get a shallow copy
//        for 'pszText' since the effective lifetime of a 'TTabItem' is
//        rather short and the underlying control copies/caches the item's
//        label
//
inline TTabItem::TTabItem(const TC_ITEM& tbItem)
{
  *((TC_ITEM*)this) = tbItem;
}

//
// Sets the index of the image assiciated with the tab represented
// by this item structure.
//
inline void TTabItem::SetIcon(int imageIndex)
{
  iImage = imageIndex;
  mask |= TCIF_IMAGE;
}

//
// Sets the user-defined data associated with the tab represented
// by this item structure.
//
inline void TTabItem::SetParam(TParam2 param)
{
  lParam = param;
  mask |= TCIF_PARAM;
}

#if !defined(OWL_NATIVECTRL_ALWAYS)
//
// Destructor of TTabEntryInternal
//
// Cleans up memory allocated for copy of Label
//
inline
TTabEntryInternal::~TTabEntryInternal()
{
  delete[] pszText;
}
#endif

//----------------------------------------------------------------------------
// When ObjectWindows uses the native implementation of TabControl, the
// methods to manipulate the object are simple wrappers around predefined
// Tab Control messages - i.e. TCM_xxxx
//
#if defined(OWL_NATIVECTRL_ALWAYS)

// Adds a new tab described by the 'item' parameter to the tab control.
// The return value is the index of the new tab or -1 in case of error.
//
inline int TTabControl::Add(const TTabItem& item)
{
  return Insert(item, GetCount());
}

// Inserts a new tab described by the 'item' parameter to the tab
// control at the position specified by the 'index' parameter.
// The return value is the index of the new tab or -1 in case of error.
//
inline int TTabControl::Insert(const TTabItem& item, int index)
{
  return (int)SendMessage(TCM_INSERTITEM, index,
                            TParam2((const TC_ITEM far*)(&item)));
}

//
// Removes the item at the position specified by the 'index' parameter.
// Returns 'true' if successful or 'false' otherwise.
//
inline bool TTabControl::Delete(int index)
{
  return SendMessage(TCM_DELETEITEM, index) != 0;
}

//
// Removes all items from the tab control. Returns 'true' if successful or
// 'false' otherwise.
//
inline bool TTabControl::DeleteAll()
{
  return SendMessage(TCM_DELETEALLITEMS) != 0;
}

//
// Returns the number of tab items in the tab control.
//
inline int TTabControl::GetCount() const
{
  return (int)CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETITEMCOUNT);
}

//
// Retrieves the current number of rows in the tab control.
// NOTE: Only tabs with the TCS_MULTILINE style can have multiple rows.
//
inline int TTabControl::GetRowCount() const
{
  return (int)CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETROWCOUNT);
}

//
// Returns the index of the currently selected tab item in the tab control.
// Returns -1 if no tab is selected.
//
inline int TTabControl::GetSel() const
{
  return (int)CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETCURSEL);
}

//
// Selects the tab item at the position specified by the 'index' parameter.
// The return value is the index of the previously selected tab item if
// successful or -1 otherwise.
// NOTE: A tab control does not send TCN_SELCHANGING or TCN_SELCHANGE 
//       notifications when a tab item is selected via this method.
//
inline int TTabControl::SetSel(int index)
{
  return (int)SendMessage(TCM_SETCURSEL, index);
}

//
// Retrieves information about the tab at the position specified by
// the 'index' parameter. Returns true if successful or false otherwise.
// NOTE: The 'mask' member of the 'item' structure specifies which
//       attributes of the tab to return. When spefying TCIF_TEXT, item's
//       pszText member must point to a valid buffer and cchTextMax must
//       specify the size of the buffer.
//
inline bool TTabControl::GetItem(int index, TTabItem& item) const
{
  PRECONDITION(!(item.mask & TCIF_TEXT) || item.pszText);
  return CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETITEM, index,
                                         TParam2((TC_ITEM far*)&item)) != 0;
}

//
// Retrieves the bounding rectangle of a tab within a tab control.
// Returns true if successful or false otherwise. 
// NOTE: 'rect' receives the position in viewport coordinates.
//
inline bool TTabControl::GetItemRect(int index, TRect& rect) const
{
  return CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETITEMRECT,
                                       index, TParam2((LPRECT)&rect)) != 0;
}

//
// Sets some or all of a tab's attributes. The 'mask' member of the
// 'item' parameter specifies which attributes to set.
// Returns true if successful or false otherwise.
//
inline bool TTabControl::SetItem(int index, const TTabItem& item)
{
  return SendMessage(TCM_SETITEM, index,
                       TParam2((const TC_ITEM far*)&item)) != 0;
}

//
// Sets the number of bytes per tab reserved for application-defined
// data in a tab control. Returns true if successful or false otherwise.
// NOTE: This method should be invoked only when the tab control does not
//       contain any tabs.
//
inline bool TTabControl::SetItemExtra(int extra)
{
  return SendMessage(TCM_SETITEMEXTRA, extra) != 0;
}

//
// Sets the size (width/height) of tabs in a fixed-width or owner-draw
// tab control. Returns a TSize object containing the old width and height.
//
inline TSize TTabControl::SetItemSize(const TSize& size)
{
  return TSize(SendMessage(TCM_SETITEMSIZE, 0, MkParam2(size.cx, size.cy)));
}

//
// Sets the amount of space around each tab's icon and label in a tab 
// control. 
//
inline void TTabControl::SetPadding(const TSize& size)
{
  SendMessage(TCM_SETPADDING, 0, MkParam2(size.cx, size.cy));
}

//
// If the 'clientInWindowOut' parameter is false, this method calculates
// the display area of a tab control's display from a window rectangle
// specified by the 'rect' parameter. Otherwise, the method calculates
// the window rectangle that would correspond to display area specified
// by the 'rect' parameter. The 'rect' parameter receives the newly computed
// rectangle.
//
inline void TTabControl::AdjustRect(bool clientInWindowOut, TRect& rect)
{
  SendMessage(TCM_ADJUSTRECT, TParam1(clientInWindowOut), TParam2(&rect));
}

//
// Retrieves the ImageList associated with a tab control. Returns 0 if
// unsuccessful.
//
inline HIMAGELIST TTabControl::GetImageList() const
{
  return (HIMAGELIST)
          CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETIMAGELIST);
}

//
// Assigns an imagelist to the tab control. Returns the handle of the
// previous imagelist or 0 if there is no previous image list.
//
inline HIMAGELIST TTabControl::SetImageList(HIMAGELIST himl)
{
  return (HIMAGELIST)SendMessage(TCM_SETIMAGELIST, 0, TParam2(himl));
}

//
// Removes the image at the position specified by 'index' from the
// imagelist associated with the tab control.
// NOTE: The tab automatically updates each tab's image index so each
//       tab remains associated with the same image it had been.
//
inline void TTabControl::RemoveImage(int index)
{
  SendMessage(TCM_REMOVEIMAGE, index);
}

//
// Retrieves the handle of the tooltip control associated with the 
// tab control. Returns 0 if unsuccessful.
//
inline TWindow::THandle TTabControl::GetToolTips() const
{
  return THandle(CONST_CAST(TTabControl*,this)->SendMessage(TCM_GETTOOLTIPS));
}

//
// Assigns a tooltip control to the tab control. 
//
inline void TTabControl::SetToolTips(THandle toolTip)
{
  SendMessage(TCM_SETTOOLTIPS, TParam1(toolTip));
}

//
// Determines the index of the tab which is at the location 
// specified in the 'pt' member of the 'htInfo' parameter.
// Returns -1 if no tab is at the specified position.
//
inline int TTabControl::HitTest(TTabHitTestInfo& htInfo)
{
  return (int)SendMessage(TCM_HITTEST, 0,
                            TParam2((TC_HITTESTINFO far*)&htInfo));
}

#endif  // OWL_NATIVECTRL_ALWAYS
#endif  // OWL_TABCTRL_H
