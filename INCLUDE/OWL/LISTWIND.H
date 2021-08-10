//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Definition of TListWindow class
//----------------------------------------------------------------------------
#if !defined(OWL_LISTWIND_H)
#define OWL_LISTWIND_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(BI_PLAT_WIN32)
# error OWL: listwind.h only supports WIN32 targets
#endif

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TListWindow;
class _OWLCLASS TLwFindInfo;
class _OWLCLASS TLwHitTestInfo;
class _OWLCLASS TLwComparator;

#include <pshpack1.h>
//
// class TLwNotify
// ~~~~~ ~~~~~~~~~
// Basic TListWindow notification
//
class _OWLCLASS TLwNotify : public TNotify {
  public:
    int     iItem;          // index of the item
    int     iSubItem;       // index of the subitem (column)
    uint    uNewState;      // new state of the item
    uint    uOldState;      // old state of the item
    uint    uChanged;       // member indicating what changed
    POINT   ptAction;       // point action occurred, valid for LVN_BEGINDRAG &
                            // LVN_BEGINRDRAG
    TParam2 lParam;         // additional data member Only valid for LVN_DELETEITEM
};

//
// class TLwDispInfoNotify
// ~~~~~ ~~~~~~~~~~~~~~~~~
// A TListWindow notification to repaint an item.
//
class _OWLCLASS TLwDispInfoNotify : public TNotify {
  public:
    LV_ITEM item;           // item to repaint
};

//
// class TLwKeyDownNotify
// ~~~~~ ~~~~~~~~~~~~~~~~
// A TListWindow notification that a key has been pressed.
//
class _OWLCLASS TLwKeyDownNotify : public TNotify {
  public:
    uint16 wVKey;           // which key was pressed
    uint   flags;           // flags of the key
};

#include <poppack.h>

//
// class TLwFindInfo
// ~~~~~ ~~~~~~~~~~~
// A structure to find an item in a TListWindow.
//
class _OWLCLASS TLwFindInfo : public LV_FINDINFO {
  public:
    TLwFindInfo(LV_FINDINFO);   // make a copy
    TLwFindInfo();

    // Accessors
    //
    void SetData(TParam2 param);
    void SetPartial(char far* text = 0);
    void SetString(char far* text = 0);
    void SetSubstring(char far* text = 0);
    void SetWrap(bool = true);

  protected:
    void Init();
};

//
// class TLwHitTestInfo
// ~~~~~ ~~~~~~~~~~~~~~
// Determines if a point is somewhere on an item or not.
//
class _OWLCLASS TLwHitTestInfo : public LV_HITTESTINFO {
  public:
    TLwHitTestInfo();
    TLwHitTestInfo(TPoint& p);
    TLwHitTestInfo(LV_HITTESTINFO); // make a copy

    void SetPoint(TPoint& p);
    int  GetIndex();
    uint GetFlags();

  protected:
    void Init();
};

//
// class TLwComparator
// ~~~~~ ~~~~~~~~~~~~~
// A base class for comparisons to sort items.
//
class _OWLCLASS TLwComparator {
  public:
    // Return value is < 0 if item1 < item2
    //                 = 0 if item1 == item2
    //                 > 0 if item1 > item2
    // lParam is user-defined value
    //
    virtual int Compare(uint32 item1, uint32 item2, uint32 lParam) const;
};

//
// class TListWindItem
// ~~~~~ ~~~~~~~~~~~~~
// An item in the TListWindow.
//
class _OWLCLASS TListWindItem : public LV_ITEM {
  public:
    // State of an item.
    //
    enum TListState {
      Focus           = LVIS_FOCUSED,         // Only one item has focus
      Selected        = LVIS_SELECTED,        // Marked as selected
      Cut             = LVIS_CUT,             // Marked for cut & paste
      DropHilited     = LVIS_DROPHILITED,     // Marked as drop target
      OverlayMask     = LVIS_OVERLAYMASK,     // Retrieve one-based overlay image index
      StateImageMask  = LVIS_STATEIMAGEMASK,  // Retrieve one-based state image index
    };

    // Constructors
    //
    TListWindItem();        // zero every data member
    TListWindItem(LV_ITEM); // make a copy
    TListWindItem(char far*, int subitem = 0, int len = 0);

    // Accessors
    //
    void GetText(char far*, int len = 0);
    void SetText(char far*, int len = 0);

    // Index is the 0-based "row"
    //
    int  GetIndex() const;
    void SetIndex(int);

    // Column number
    //
    int  GetSubItem() const;
    void SetSubItem(int);

    // Extra data
    //
    uint32 GetItemData() const;
    void   SetItemData(uint32);

    // ImageList index
    //
    int  GetImageIndex() const;
    void SetImageIndex(int index);

    // State of the item. See TListState for details.
    //
    int  GetState() const;
    void SetState(TListState state);

    // ImageList index for the state
    //
    int  GetStateImage() const;
    void SetStateImage(int index);

  protected:
    void Init();
};

//
// class TListWindColumn
// ~~~~~ ~~~~~~~~~~~~~~~
// A column in the TListWindow.
//
class _OWLCLASS TListWindColumn : public LV_COLUMN {
  public:
    // How to align a column
    //
    enum TFormat {
      Left   = LVCFMT_LEFT,    // Left justified
      Center = LVCFMT_CENTER,  // Centered
      Right  = LVCFMT_RIGHT,   // Right justified
    };

    // Constructors
    //
    TListWindColumn();          // zero every data member
    TListWindColumn(LV_COLUMN); // make a copy
    TListWindColumn(char far*, int width, TFormat how = Left, int subItem = 0);

    void SetText(char far*, int = 0);
    void SetFormat(TFormat how);
    void SetWidth(int pixels);
    void SetSubItem(int);               // column number

  protected:
    void Init();
};

//
// class TListWindow
// ~~~~~ ~~~~~~~~~~~
// Encapsulates the ListView.
// The ListWindow have four views: Icon, Small Icon, Report, and List.
// The view is determined by the style of the ListWindow set either with
// Attr.Style or SetWindowLong.
//
class _OWLCLASS TListWindow : public TControl {
  public:
    // How to arrange the items in the control
    //
    enum TArrangeCode {
      Default       = LVA_DEFAULT,     // Use default for control style
      Left          = LVA_ALIGNLEFT,   // Align items to the left edge
      Top           = LVA_ALIGNTOP,    // Align items to the top edge
      SnapToGrid    = LVA_SNAPTOGRID,  // Snap icons to nearest grid position
    };

    // Type of iamge list for use with the control
    //
    enum TImageListType {
      Normal = LVSIL_NORMAL,    // Normal image list.
      Small  = LVSIL_SMALL,     // Small icons for LVS_SMALLICON
      State  = LVSIL_STATE,     // State image
    };

    // Type of rectangle boundaries to retrieve
    //
    enum TItemRectType {
      Bounds = LVIR_BOUNDS,     // Entire boundary (icon and label)
      Icon   = LVIR_ICON,       // Only the icon
      Label  = LVIR_LABEL,      // Only the label
    };

    // Next item to retrieve from current item
    //
    enum TNextItemCode {
      // Only one relational property
      //
      Above       = LVNI_ABOVE,       // Directly above
      All         = LVNI_ALL,         // By index
      Below       = LVNI_BELOW,       // Directly below
      ToLeft      = LVNI_TOLEFT,      // Left of
      ToRight     = LVNI_TORIGHT,     // Right of

      // Can have multiple state searches
      //
      Cut         = LVNI_CUT,         // Marked for cut & paste
      DropHilited = LVNI_DROPHILITED, // Marked for drop target
      Focused     = LVNI_FOCUSED,     // Marked as having focus
      Selected    = LVNI_SELECTED,    // Marked as selected
    };

    // Constructors and destructors
    //
    TListWindow(TWindow* parent, int id, int x, int y, int w, int h,
                TModule* module = 0);
    TListWindow(TWindow* parent, int resourceId, TModule* module = 0);
   ~TListWindow();

    // Column manipulation
    //
    int  InsertColumn(int colNum, TListWindColumn&);
    bool DeleteColumn(int colNum);
    bool GetColumn(int index, LV_COLUMN far*);
    int  GetColumnWidth(int index);
    bool SetColumn(int index, TListWindColumn&);
    bool SetColumnWidth(int index, int width);

    // Item manipulation
    //
    bool GetItem(TListWindItem&);
    int  GetNextItem(int index, TNextItemCode code);
    int  GetItemCount();
    void SetItemCount(int numItems);
    bool GetItemPosition(int index, POINT far*);
    bool SetItemPosition(int index, POINT p);
    bool GetItemRect(int index, RECT far*, TItemRectType);
    uint GetItemState(int index, uint mask);
    bool SetItemState(int index, uint state, uint mask);
    int  GetItemText(int index, int subItem, char far* text, int size);
    int  InsertItem(TListWindItem&);
    bool DeleteAnItem(int itemIndex);
    bool DeleteAllItems();
    bool SetItem(TListWindItem&);
    void SetItemText(int index, TListWindItem&);
    int  FindItem(int startIndex, const TLwFindInfo far* findInfo);
    bool SortItems(const TLwComparator& Comparator, uint32 lParam = 0);
    bool Arrange(TArrangeCode code);

    // Image list manipulation
    //
    HIMAGELIST CreateDragImage(int itemIndex, TPoint* upLeft);
    HIMAGELIST GetImageList(TImageListType);
    bool       SetImageList(HIMAGELIST list, TImageListType type);

    // Color manipulation
    //
    COLORREF GetBkColor();
    bool     SetBkColor(COLORREF c);
    COLORREF GetTextBkColor();
    bool     SetTextBkColor(COLORREF c);
    COLORREF GetTextColor();
    bool     SetTextColor(COLORREF c);

    // Callbacks
    //
    uint GetCallBackMask();
    bool SetCallBackMask(uint mask);

    // Miscellaneous
    //
    int  GetTopIndex();
    HWND EditLabel(int itemIndex);
    HWND GetEditControl();
    bool Update(int index);
    int  HitTest(TLwHitTestInfo&);
    bool Scroll(int dx, int dy);
    bool GetOrigin(POINT far*);
    int  GetStringWidth(char far* text);
    bool GetViewRect(RECT far*);
    bool EnsureVisible(int index, bool partialOk);
    bool RedrawItems(int startIndex, int endIndex);
    int  GetCountPerPage();

  protected:
    char far* GetClassName();

  private:
    TListWindow(const TListWindow&);
    TListWindow& operator=(const TListWindow&);

  DECLARE_STREAMABLE(_OWLCLASS, TListWindow, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Override this to compare two items for sorting items.
// If item1 < item2, return -1.
// If item1 == item2, return 0.
// Else return 1.
//
inline int
TLwComparator::Compare(uint32 item1, uint32 item2, uint32 lParam) const
{
  return 0;
}

//
// Rearrange the ListWindow
//
inline bool
TListWindow::Arrange(TArrangeCode code)
{
  return ToBool(SendMessage(LVM_ARRANGE, (int)code));
}

//
// Create a drag image. The returned HIMAGELIST should be deleted.
//
inline HIMAGELIST
TListWindow::CreateDragImage(int itemIndex, TPoint* upLeft)
{
  return (HIMAGELIST)SendMessage(LVM_CREATEDRAGIMAGE, itemIndex, TParam2(upLeft));
}

//
// Deletes the column number 'colNum'
//
inline bool
TListWindow::DeleteColumn(int colNum)
{
  return ToBool(SendMessage(LVM_DELETECOLUMN, colNum));
}

//
// Removes all items from the ListWindow
//
inline bool
TListWindow::DeleteAllItems()
{
  return ToBool(SendMessage(LVM_DELETEALLITEMS));
}

//
// Removes one item from the ListWindow
//
inline bool
TListWindow::DeleteAnItem(int itemIndex)
{
  return ToBool(SendMessage(LVM_DELETEITEM, itemIndex));
}

//
// Edit the text associated with the item number 'itemIndex'.
// Similar to clicking on the label of an icon on the new shell.
//
inline HWND
TListWindow::EditLabel(int itemIndex)
{
  return (HWND)SendMessage(LVM_EDITLABEL, itemIndex);
}

//
// Makes sure the item number 'index' is visible.
// Will scroll the item into view if necessary.
//
inline bool
TListWindow::EnsureVisible(int index, bool partialOk)
{
  return ToBool(SendMessage(LVM_ENSUREVISIBLE, index, TParam2(partialOk)));
}

//
// Locates the item indicated by 'findInfo'.
// Returns the index of the item if found.
// Returns -1, if not found.
//
inline int
TListWindow::FindItem(int startIndex, const TLwFindInfo far* findInfo)
{
  return (int)SendMessage(LVM_FINDITEM, startIndex, TParam2(findInfo));
}

//
// Inserts the item into the position indicated by item.iItem.
//
inline int
TListWindow::InsertItem(TListWindItem& item)
{
  return (int)SendMessage(LVM_INSERTITEM, 0, TParam2(&item));
}

//
// Inserts the column 'colItem' into column number 'colNum'.
//
inline int
TListWindow::InsertColumn(int colNum, TListWindColumn& colItem)
{
  return (int)SendMessage(LVM_INSERTCOLUMN, colNum, TParam2(&colItem));
}

//
// Returns the background color of the ListWindow
//
inline COLORREF
TListWindow::GetBkColor()
{
  return (COLORREF)SendMessage(LVM_GETBKCOLOR);
}

//
// Return the callback mask.
//
inline uint
TListWindow::GetCallBackMask()
{
  return (uint)SendMessage(LVM_GETCALLBACKMASK);
}

//
// Returns the column information of column number 'index'.
//
inline bool
TListWindow::GetColumn(int index, LV_COLUMN far* column)
{
  return ToBool(SendMessage(LVM_GETCOLUMN, index, TParam2(column)));
}

//
// Returns the width of the column 'index'.
//
inline int
TListWindow::GetColumnWidth(int index)
{
  return (int)SendMessage(LVM_GETCOLUMNWIDTH, index);
}

//
// Returns the number of fully visible items that can fit vertically
// in list or report view.
//
inline int
TListWindow::GetCountPerPage()
{
  return (int)SendMessage(LVM_GETCOUNTPERPAGE);
}

//
// Returns the HWND of the edit control used for editing labels.
//
inline HWND
TListWindow::GetEditControl()
{
  return (HWND)SendMessage(LVM_GETEDITCONTROL);
}

//
// Returns the IMAGELIST for the type.
//
inline HIMAGELIST
TListWindow::GetImageList(TImageListType type)
{
  return (HIMAGELIST)SendMessage(LVM_GETIMAGELIST, type);
}

//
// Returns the information specified by item.
//
inline bool
TListWindow::GetItem(TListWindItem& item)
{
  return ToBool(SendMessage(LVM_GETITEM, 0, TParam2(&item)));
}

//
// Returns the number of items total in the ListWindow
//
inline int
TListWindow::GetItemCount()
{
  return (int)SendMessage(LVM_GETITEMCOUNT);
}

//
// Returns the item's position.
//
inline bool
TListWindow::GetItemPosition(int index, POINT far* p)  
{
  return ToBool(SendMessage(LVM_GETITEMPOSITION, index, TParam2(p)));
}

//
// Returns the item's size.
// TItemRectType indicates what type of rectangle to return.
//
inline bool
TListWindow::GetItemRect(int index, RECT far* r, TItemRectType type) 
{
  r->left = type;
  return ToBool(SendMessage(LVM_GETITEMRECT, index, TParam2(r)));
}

//
// Returns the current state of the item (selected, focused, etc.)
//
inline uint
TListWindow::GetItemState(int index, uint mask)
{
  return (uint)SendMessage(LVM_GETITEMSTATE, index, TParam2(mask));
}

//
// Returns the text of the item.
//
inline int
TListWindow::GetItemText(int index, int subItem, char far* text, int size)
{
  TListWindItem item(text, size);
  item.SetSubItem(subItem);
  return (int)SendMessage(LVM_GETITEMTEXT, index, TParam2(&item));
}

//
// Returns the index of the 'next' item after item 'index'.
// See TNextItemCode for more details.
//
inline int
TListWindow::GetNextItem(int index, TNextItemCode code)
{
  return (int)SendMessage(LVM_GETNEXTITEM, index, MkParam2(code, 0));
}

//
// Retrieves the current view origin of the ListWindow.
// Returns false if current ListWindow is in list or report view.
//
inline bool
TListWindow::GetOrigin(POINT far* p)
{
  return ToBool(SendMessage(LVM_GETORIGIN, 0, TParam2(p)));
}

//
// Returns the width of the text using the current ListWindow's font.
//
inline int
TListWindow::GetStringWidth(char far* text)
{
  return (int)SendMessage(LVM_GETSTRINGWIDTH, 0, TParam2(text));
}

//
// Returns the text background color of the ListWindow.
//
inline COLORREF
TListWindow::GetTextBkColor()
{
  return (COLORREF)SendMessage(LVM_GETTEXTBKCOLOR);
}

//
// Returns the text color of the ListWindow.
//
inline COLORREF
TListWindow::GetTextColor()
{
  return (COLORREF)SendMessage(LVM_GETTEXTCOLOR);
}

//
// Returns the index of the topmost visible item.
//
inline int
TListWindow::GetTopIndex()
{
  return (int)SendMessage(LVM_GETTOPINDEX);
}

//
// Returns the bouding rectangle of all items in the ListWindow.
// ListWindow must be in icon or small icon view.
//
inline bool
TListWindow::GetViewRect(RECT far* r)
{
  return ToBool(SendMessage(LVM_GETVIEWRECT, 0, TParam2(r)));
}

//
// Returns the index of the item indicated by 'info'
//
inline int
TListWindow::HitTest(TLwHitTestInfo& info)
{
  return (int)SendMessage(LVM_HITTEST, 0, TParam2(&info));
}

//
// Invalidates rectangle between the items between 'startIndex' and 'endIndex'
//
inline bool
TListWindow::RedrawItems(int startIndex, int endIndex)
{
  return ToBool(SendMessage(LVM_REDRAWITEMS, 0, MkParam2(startIndex, endIndex)));
}

//
// Scroll the contents of the ListWindow.
// The parameters 'dx' and 'dy' are in pixels.
//
inline bool
TListWindow::Scroll(int dx, int dy)
{
  return ToBool(SendMessage(LVM_SCROLL, 0, MkParam2(dx, dy)));
}

//
// Sets the background color of the ListWindow.
//
inline bool
TListWindow::SetBkColor(COLORREF c)
{
  return ToBool(SendMessage(LVM_SETBKCOLOR, 0, TParam2(c)));
}

//
// Sets the callback mask.
//
inline bool
TListWindow::SetCallBackMask(uint mask)
{
  return ToBool(SendMessage(LVM_SETCALLBACKMASK, mask));
}

//
// Sets the attributes of the column 'index'
//
inline bool
TListWindow::SetColumn(int index, TListWindColumn& column)
{
  return ToBool(SendMessage(LVM_SETCOLUMN, index, TParam2(&column)));
}

//
// Sets the column width of 'index'.
//
inline bool
TListWindow::SetColumnWidth(int index, int width)
{
  return ToBool(SendMessage(LVM_SETCOLUMNWIDTH, index, MkParam2(width, 0)));
}

//
// Sets the imagelist for the type.
//
inline bool
TListWindow::SetImageList(HIMAGELIST list, TImageListType type)
{
  return ToBool(SendMessage(LVM_SETIMAGELIST, type, TParam2(list)));
}

//
// Sets the attributes of the item 'item'.
//
inline bool
TListWindow::SetItem(TListWindItem& item)
{
  return ToBool(SendMessage(LVM_SETITEM, 0, TParam2(&item)));
}

//
// Optimizes inserting a large number of items.
//
inline void
TListWindow::SetItemCount(int numItems)
{
  SendMessage(LVM_SETITEMCOUNT, numItems);
}

//
// Sets the item to a particular point.
// Only valid for icon or small icon view.
//
inline bool
TListWindow::SetItemPosition(int index, POINT p)
{
  return ToBool(SendMessage(LVM_SETITEMPOSITION, index, MkParam2(p.x, p.y)));
}

//
// Sets the text for the item.
//
inline void
TListWindow::SetItemText(int index, TListWindItem& item)
{
  SendMessage(LVM_SETITEMTEXT, index, TParam2(&item));
}

//
// Sets the background color of the ListWindow.
//
inline bool
TListWindow::SetTextBkColor(COLORREF c)
{
  return ToBool(SendMessage(LVM_SETTEXTBKCOLOR, 0, TParam2(c)));
}

//
// Sets the text color of the items.
//
inline bool
TListWindow::SetTextColor(COLORREF c)
{
  return ToBool(SendMessage(LVM_SETTEXTCOLOR, 0, TParam2(c)));
}

//
// Updates the ListWindow.
// If the list window has LVS_AUTOARRANGE, the items are automatically
// arranged to their proper locations.
//
inline bool
TListWindow::Update(int index)
{
  return ToBool(SendMessage(LVM_UPDATE, index));
}

//
// Returns the item's index.
//
inline int
TListWindItem::GetIndex() const
{
  return iItem;
}

//
// Returns the column number for the item
//
inline int
TListWindItem::GetSubItem() const
{
  return iSubItem;
}

//
// Returns the item's index.
//
inline int
TLwHitTestInfo::GetIndex()
{
  return iItem;
}

//
// Returns the flag for the item
//
inline uint
TLwHitTestInfo::GetFlags()
{
  return flags;
}

#endif  // OWL_LISTWIND_H



