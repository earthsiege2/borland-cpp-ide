//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.16  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TListWindow;
class _OWLCLASS TLwFindInfo;
class _OWLCLASS TLwHitTestInfo;
class _OWLCLASS TLwComparator;

// Constant representing all mask flags of LV_COLUMN/LV_ITEM
//
#if !defined(LVCF_ALL)
# define LVCF_ALL  (LVCF_FMT|LVCF_SUBITEM|LVCF_TEXT|LVCF_WIDTH)
#endif
#if !defined(LVIF_ALL)
# define LVIF_ALL  (LVIF_TEXT|LVIF_IMAGE|LVIF_PARAM|LVIF_STATE)
#endif

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

    void    SetPoint(TPoint& p);
    int     GetIndex();
    uint    GetFlags();

  protected:
    void    Init();
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
// Object representing an item of a TListWindow control - i.e. contains
// information about the item's icon, label, state and application-defined
// value
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

    // Construct an empty ListWindItem structure; typically used for 
    // retrieving information about an existing item. For example,
    //
    //    TListWindItem lstItem;
    //    ListWindow->GetItem(lstItem, index, subItem);
    //    ShowString(lstItem.GetText());
    // 
    TListWindItem(uint msk = LVIF_ALL, bool allocCache = true);        

    // Make a copy from 'raw' system structure
    //
    TListWindItem(const LV_ITEM& lvItem);

    // Construct an object which represents an item to be
    // added/inserted into a Listview control. For example,
    //
    //  TListWindItem lstItem(database.FieldName(fldIndex), fldIndex);
    //  ListWindow->AddItem(lstItem);
    //
    TListWindItem(const char* text, int subitem = 0, int len = 0);

    // Construct an object representing an existing item from a ListView 
    // constrol.
    //
    TListWindItem(const TListWindow& ctl, int index, int subItem, 
                  uint msk = LVIF_ALL);
   ~TListWindItem();

    // Retrieve/Set item's text
    //
    char*     GetText() const;
    void      GetText(char* buff, int len = 0) const;
    void      SetText(const char* text, int len = 0);

    // Index is the 0-based "row"
    //
    int       GetIndex() const;
    void      SetIndex(int);

    // Column number
    //
    int       GetSubItem() const;
    void      SetSubItem(int);

    // Extra data
    //
    uint32    GetItemData() const;
    void      SetItemData(uint32);

    // ImageList index
    //
    int       GetImageIndex() const;
    void      SetImageIndex(int index);

    // State of the item. See TListState for details.
    //
    int       GetState() const;
    void      SetState(TListState state);

    // ImageList index for the state
    //
    int       GetStateImage() const;
    void      SetStateImage(int index);

    // Cache management routines
    //
    void      AllocCache(bool setpszText = true);
    void      FlushCache();

  protected:
    void            Init();
    TAPointer<char> Cache;
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
      Left   = LVCFMT_LEFT,           // Left justified
      Center = LVCFMT_CENTER,         // Centered
      Right  = LVCFMT_RIGHT,          // Right justified
    };

    // Zeroes out members and allocates a cache for the column text.
    // Use this constructor to create a TListWindColumn object used for
    // retrieving information about an existing column..
    //
    TListWindColumn(uint mask = LVCF_ALL, int subItem = 0);

    // Construct a ListWindColumn object from a control. This constructor
    // provides a quick way to construct and retrieve information about a
    // column
    //
    TListWindColumn(const TListWindow& ctl, int index, uint mask = LVCF_ALL,
                    int subItem = 0);
                    
    // Make a copy of system structure
    //
    TListWindColumn(const LV_COLUMN& lvColumn);       

    // Quick ways to construct TListWindColumn object when inserting/adding
    // new columns to a Listview control
    //
    // Use the first one if you want to just specify the index and text -
    // OWL will compute the text extent from the default GUI font]
    // Use the second one one if you want more control over the formatting]
    //
    TListWindColumn(char* txt, int width, TFormat how = Left, int subItem = 0);
   ~TListWindColumn();

    // Initialize members of object
    //
    void              SetText(const char* txt, int = 0);
    void              SetFormat(TFormat how);
    void              SetWidth(int pixels, char* txt = 0);
    void              SetSubItem(int subItem);               
    
    // Retrieve information from object
    // [NOTE: These members only return static data currently in the
    //        structure.]
    //
    char*             GetText() const     { return pszText;      }
    TFormat           GetFormat() const   { return TFormat(fmt); }
    int               GetWidth() const    { return cx;           }
    int               GetSubItem() const  { return iSubItem;     }

    // Cache management routines
    //
    void              AllocCache(bool setpszText = true);
    void              FlushCache();

  protected:
    void              Init();
    TAPointer<char>   Cache;
};

//
// class TListWindow
// ~~~~~ ~~~~~~~~~~~
// Encapsulates the ListView control, a window that displays a collection 
// of items, each item consisting of an icon and a label. List view controls 
// provide several ways of arranging items and displaying individual items. 
// For example, additional information about each item can be displayed in 
// columns to the right of the icon and label.
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
      Bounds        = LVIR_BOUNDS,     // Entire boundary (icon and label)
      Icon          = LVIR_ICON,       // Only the icon
      Label         = LVIR_LABEL,      // Only the label
      SelectBounds  = LVIR_SELECTBOUNDS// Union of Icon+Label but no colmns
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
    int   InsertColumn(int colNum, const TListWindColumn&);
    bool  DeleteColumn(int colNum);
    bool  GetColumn(int index, LV_COLUMN*); 
    bool  GetColumn(int index, TListWindColumn& column) const; 
    int   GetColumnWidth(int index) const;
    bool  SetColumn(int index, const TListWindColumn&);
    bool  SetColumnWidth(int index, int width);

    // Retrieve/Set item data
    //
    bool GetItem(TListWindItem&, int index = -1, int subitem = -1) const;
    bool SetItem(TListWindItem&, int index = -1, int subitem = -1);

    int  GetNextItem(int index, TNextItemCode code) const;
    int  GetItemCount() const;
    void SetItemCount(int numItems);
    bool GetItemPosition(int index, POINT far*);        
    bool GetItemPosition(int index, TPoint& pt) const;  
    bool SetItemPosition(int index, const TPoint& pt);  

    bool GetItemRect(int index, RECT far*, TItemRectType);  
    uint GetItemState(int index, uint mask) const;
    bool SetItemState(int index, uint state, uint mask);
    int  GetItemText(int index, int subItem, char* text, int size) const;

    // Add/Insert/Delete
    //
    int  AddItem(TListWindItem& newItem);
    int  InsertItem(TListWindItem& newItem, int index = -1);

    // NOTE: The following should be named 'DeleteItem' to be consistent.
    //       However, it would then hide TControl's DeleteItem...
    //
    bool DeleteAnItem(int itemIndex);
    bool DeleteAllItems();

    // Update item attributes
    //
    bool SetItemText(int index, const TListWindItem& item);
    bool SetItemText(int index, int subItem, const char* text);

    // Find/Sort/Arrange
    //
    int  FindItem(int startIndex, const TLwFindInfo* findInfo); 
    bool SortItems(const TLwComparator& Comparator, uint32 lParam = 0);
    bool Arrange(TArrangeCode code);

    // Item selection
    //
    bool IsSelected(int index) const;
    int  GetSelCount(void) const;
    int  GetSelIndexes(int* indexes, int maxCount) const;
    int  GetSelStrings(char far** strs, int maxCount, int maxChars, int subItem = 0) const;
    bool SetSel(int index, bool select);
    bool SetSelIndexes(int* indexes, int numSelections, bool select);
    bool SetSelItemRange(bool select, int first, int last);

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
    uint GetCallBackMask() const;
    bool SetCallBackMask(uint mask);

    // Miscellaneous
    //
    int  GetTopIndex() const;
    HWND EditLabel(int itemIndex);
    HWND GetEditControl() const;
    bool Update(int index);
    int  HitTest(TLwHitTestInfo&);
    bool Scroll(int dx, int dy);
    bool GetOrigin(POINT*);               
    int  GetStringWidth(char far* text);
    bool GetViewRect(RECT far*);          
    bool EnsureVisible(int index, bool partialOk);
    bool RedrawItems(int startIndex, int endIndex);
    int  GetCountPerPage() const;

  protected:
    char far* GetClassName();

  private:
    TListWindow(const TListWindow&);
    TListWindow& operator=(const TListWindow&);

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
  PRECONDITION(GetHandle());
  return SendMessage(LVM_ARRANGE, (int)code) != 0;
}

//
// Create a drag image. The returned HIMAGELIST should be deleted.
//
inline HIMAGELIST
TListWindow::CreateDragImage(int itemIndex, TPoint* upLeft)
{
  PRECONDITION(GetHandle());
  return (HIMAGELIST)SendMessage(LVM_CREATEDRAGIMAGE, itemIndex, TParam2(upLeft));
}

//
// Deletes the column number 'colNum'
//
inline bool
TListWindow::DeleteColumn(int colNum)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_DELETECOLUMN, colNum) != 0;
}

//
// Removes all items from the ListWindow
//
inline bool
TListWindow::DeleteAllItems()
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_DELETEALLITEMS) != 0;
}

//
// Removes one item from the ListWindow
//
inline bool
TListWindow::DeleteAnItem(int itemIndex)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_DELETEITEM, itemIndex) != 0;
}

//
// Edit the text associated with the item number 'itemIndex'.
// Similar to clicking on the label of an icon on the new shell.
//
inline HWND
TListWindow::EditLabel(int itemIndex)
{
  PRECONDITION(GetHandle());
  return (HWND)SendMessage(LVM_EDITLABEL, itemIndex);
}

//
// Makes sure the item number 'index' is visible.
// Will scroll the item into view if necessary.
//
inline bool
TListWindow::EnsureVisible(int index, bool partialOk)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_ENSUREVISIBLE, index, TParam2(partialOk)) != 0;
}

//
// Locates the item indicated by 'findInfo'.
// Returns the index of the item if found.
// Returns -1, if not found.
//
inline int
TListWindow::FindItem(int startIndex, const TLwFindInfo far* findInfo)
{
  PRECONDITION(GetHandle());
  return (int)SendMessage(LVM_FINDITEM, startIndex, TParam2(findInfo));
}

//
// Add item to the end of the list.
//
inline int
TListWindow::AddItem(TListWindItem& item)
{
  PRECONDITION(GetHandle());
  return (int)InsertItem(item, GetItemCount());
}

//
// Inserts the item into the position indicated by item.iItem.
//
inline int
TListWindow::InsertItem(TListWindItem& item, int index /*= -1*/)
{
  PRECONDITION(GetHandle());
  if (index != -1)
    item.iItem = index;
  return (int)SendMessage(LVM_INSERTITEM, 0, TParam2(&item));
}

//
// Inserts the column 'colItem' into column number 'colNum'.
//
inline int
TListWindow::InsertColumn(int colNum, const TListWindColumn& colItem)
{
  PRECONDITION(GetHandle());
  return (int)SendMessage(LVM_INSERTCOLUMN, colNum, TParam2(&colItem));
}

//
// Returns the background color of the ListWindow
//
inline COLORREF
TListWindow::GetBkColor()
{
  PRECONDITION(GetHandle());
  return (COLORREF)SendMessage(LVM_GETBKCOLOR);
}

//
// Return the callback mask.
//
inline uint
TListWindow::GetCallBackMask() const
{
  PRECONDITION(GetHandle());
  return (uint) CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETCALLBACKMASK);
}

//
// Returns the column information of column number 'index'.
//
inline bool
TListWindow::GetColumn(int index, LV_COLUMN* column) 
{
  PRECONDITION(column);
  PRECONDITION(GetHandle());
  return SendMessage(LVM_GETCOLUMN, index, TParam2(column)) != 0;
}

//
// Returns the column information of column number 'index'.
//
inline bool
TListWindow::GetColumn(int index, TListWindColumn& column) const
{
  PRECONDITION(GetHandle());
  
  return CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETCOLUMN, 
                                                     index, 
                                                     TParam2(&column)) != 0;
}

//
// Returns the width of the column 'index'.
//
inline int
TListWindow::GetColumnWidth(int index) const
{
  PRECONDITION(GetHandle());
  return int(CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETCOLUMNWIDTH, 
                                                         index));
}

//
// Returns the number of fully visible items that can fit vertically
// in list or report view.
//
inline int
TListWindow::GetCountPerPage() const
{
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETCOUNTPERPAGE);
}

//
// Returns the HWND of the edit control used for editing labels.
//
inline HWND
TListWindow::GetEditControl() const
{
  PRECONDITION(GetHandle());
  return (HWND)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETEDITCONTROL);
}

//
// Returns the IMAGELIST for the type.
//
inline HIMAGELIST
TListWindow::GetImageList(TImageListType type)
{
  PRECONDITION(GetHandle());
  return (HIMAGELIST)SendMessage(LVM_GETIMAGELIST, type);
}

//
// Returns the information specified by item.
//
inline bool
TListWindow::GetItem(TListWindItem& item, int index /*= -1*/,
                     int subItem /*= -1*/) const
{
  PRECONDITION(GetHandle());
  if (index != -1)
    item.iItem = index;
  if (subItem != -1)
    item.iSubItem = subItem;
  return CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETITEM, 0, TParam2(&item)) != 0;
}

//
// Returns the number of items total in the ListWindow
//
inline int
TListWindow::GetItemCount() const
{
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETITEMCOUNT);
}

//
// Returns the item's position.
//
inline bool
TListWindow::GetItemPosition(int index, POINT far* p)  
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_GETITEMPOSITION, index, TParam2(p)) != 0;
}

//
//
//
inline bool 
TListWindow::GetItemPosition(int index, TPoint& pt) const
{
  PRECONDITION(GetHandle());
  return CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETITEMPOSITION, index, TParam2(&pt)) != 0;
}

//
// Returns the item's size.
// TItemRectType indicates what type of rectangle to return.
//
inline bool
TListWindow::GetItemRect(int index, RECT* r, TItemRectType type) 
{
  PRECONDITION(GetHandle());
  r->left = type;
  return SendMessage(LVM_GETITEMRECT, index, TParam2(r)) != 0;
}

//
// Returns the current state of the item (selected, focused, etc.)
//
inline uint
TListWindow::GetItemState(int index, uint mask) const
{
  PRECONDITION(GetHandle());
  return (uint)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETITEMSTATE, index, TParam2(mask));
}

//
// Returns the text of the item.
//
inline int
TListWindow::GetItemText(int index, int subItem, char* text, int size) const
{
  PRECONDITION(GetHandle());
  TListWindItem item(text, subItem, size);
  return (int)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETITEMTEXT, index, TParam2(&item));
}

//
// Returns the index of the 'next' item after item 'index'.
// See TNextItemCode for more details.
//
inline int
TListWindow::GetNextItem(int index, TNextItemCode code) const
{
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETNEXTITEM, index, MkParam2(code, 0));
}

//
// Retrieves the current view origin of the ListWindow.
// Returns false if current ListWindow is in list or report view.
//
inline bool
TListWindow::GetOrigin(POINT far* p)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_GETORIGIN, 0, TParam2(p)) != 0;
}

//
// Returns the width of the text using the current ListWindow's font.
//
inline int
TListWindow::GetStringWidth(char* text)
{
  PRECONDITION(GetHandle());
  return (int)SendMessage(LVM_GETSTRINGWIDTH, 0, TParam2(text));
}

//
// Returns the text background color of the ListWindow.
//
inline COLORREF
TListWindow::GetTextBkColor()
{
  PRECONDITION(GetHandle());
  return (COLORREF)SendMessage(LVM_GETTEXTBKCOLOR);
}

//
// Returns the text color of the ListWindow.
//
inline COLORREF
TListWindow::GetTextColor()
{
  PRECONDITION(GetHandle());
  return (COLORREF)SendMessage(LVM_GETTEXTCOLOR);
}

//
// Returns the index of the topmost visible item.
//
inline int
TListWindow::GetTopIndex() const
{
  PRECONDITION(GetHandle());
  return (int)CONST_CAST(TListWindow*, this)->SendMessage(LVM_GETTOPINDEX);
}

//
// Returns the bouding rectangle of all items in the ListWindow.
// ListWindow must be in icon or small icon view.
//
inline bool
TListWindow::GetViewRect(RECT far* r)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_GETVIEWRECT, 0, TParam2(r)) != 0;
}

//
// Returns the index of the item indicated by 'info'
//
inline int
TListWindow::HitTest(TLwHitTestInfo& info)
{
  PRECONDITION(GetHandle());
  return (int)SendMessage(LVM_HITTEST, 0, TParam2(&info));
}

//
// Invalidates rectangle between the items between 'startIndex' and 'endIndex'
//
inline bool
TListWindow::RedrawItems(int startIndex, int endIndex)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_REDRAWITEMS, 0, MkParam2(startIndex, endIndex)) != 0;
}

//
// Scroll the contents of the ListWindow.
// The parameters 'dx' and 'dy' are in pixels.
//
inline bool
TListWindow::Scroll(int dx, int dy)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SCROLL, 0, MkParam2(dx, dy)) != 0;
}

//
// Sets the background color of the ListWindow.
//
inline bool
TListWindow::SetBkColor(COLORREF c)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETBKCOLOR, 0, TParam2(c)) != 0;
}

//
// Sets the callback mask.
//
inline bool
TListWindow::SetCallBackMask(uint mask)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETCALLBACKMASK, mask) != 0;
}

//
// Sets the attributes of the column 'index'
//
inline bool
TListWindow::SetColumn(int index, const TListWindColumn& column)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETCOLUMN, index, TParam2(&column)) != 0;
}

//
// Sets the column width of 'index'.
//
inline bool
TListWindow::SetColumnWidth(int index, int width)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETCOLUMNWIDTH, index, MkParam2(width, 0)) != 0;
}

//
// Sets the imagelist for the type.
//
inline bool
TListWindow::SetImageList(HIMAGELIST list, TImageListType type)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETIMAGELIST, type, TParam2(list)) != 0;
}

//
// Sets the attributes of the item 'item'.
//
inline bool
TListWindow::SetItem(TListWindItem& item, int index /*= -1*/, 
                     int subItem /*= -1*/)
{
  PRECONDITION(GetHandle());
  if (index != -1)
    item.iItem = index;
  if (subItem != -1)
    item.iSubItem = subItem;
  return SendMessage(LVM_SETITEM, 0, TParam2(&item)) != 0;
}

//
// Optimizes inserting a large number of items.
//
inline void
TListWindow::SetItemCount(int numItems)
{
  PRECONDITION(GetHandle());
  SendMessage(LVM_SETITEMCOUNT, numItems);
}


//
// Sets the item to a particular point.
// Only valid for icon or small icon view.
//
inline bool 
TListWindow::SetItemPosition(int index, const TPoint& pt) 
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETITEMPOSITION, index, MkParam2(pt.x, pt.y)) != 0;
}

//
// Sets the text for the item.
//
inline bool
TListWindow::SetItemText(int index, const TListWindItem& item)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETITEMTEXT, index, TParam2(&item)) != 0;
}

//
//
//
inline bool
TListWindow::SetItemText(int index, int subItem, const char* text)
{
  PRECONDITION(GetHandle());
  return SetItemText(index, TListWindItem(text, subItem));
}

//
// Sets the background color of the ListWindow.
//
inline bool
TListWindow::SetTextBkColor(COLORREF c)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETTEXTBKCOLOR, 0, TParam2(c)) != 0;
}

//
// Sets the text color of the items.
//
inline bool
TListWindow::SetTextColor(COLORREF c)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_SETTEXTCOLOR, 0, TParam2(c)) != 0;
}

//
// Updates the ListWindow.
// If the list window has LVS_AUTOARRANGE, the items are automatically
// arranged to their proper locations.
//
inline bool
TListWindow::Update(int index)
{
  PRECONDITION(GetHandle());
  return SendMessage(LVM_UPDATE, index) != 0;
}

//
// Returns the text of the item.
//
inline char*
TListWindItem::GetText() const
{
  return pszText;
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



