//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.22  $
//
// Implementation of classes TTabItem and TTabControl.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_TABCTRL_H)
# include <owl/tabctrl.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlCommCtrl);        // CommonCtrl Diagnostic group

//
// Constants used in OWL's implementation of Tab Controls
//
const int InitSize     = 5;         // Initial size of Tab Collection
const int InitDelta    = 5;         // Inc. when expanding collection
const int HorzPad      = 6;         // Pad on each side of tab label
const int VertPad      = 4;         // Pad above/below each tab label
const int HorzSelInc   = 1;         // Inc. for selected tab
const int VertSelInc   = 1;         // Inc. for selected tab
const int HorzMargin   = 3;         // Margin on left/right of control
const int VertMargin   = 3;         // Margin above control
const int ClientMargin = 2;         // Inner margin of tab's client area
const int ID_Updown    = 0x100;     // Ctl. identifier of scroller;

//
// Constructor for a Tab Item
//
// The item is initialized with the state of an actual tab in
// a created tab control.
//
TTabItem::TTabItem(const TTabControl& ctl, int index, uint msk,
                   int buffLen, char far* buffer)
{
  PRECONDITION(ctl.GetHandle());

  // When retrieving text, a buffer and length must be supplied
  //
  PRECONDITION(!(msk & TCIF_TEXT) || (buffLen && buffer));

  mask = msk;
  if (buffer && buffLen)
    SetLabel(buffer, buffLen);

  ctl.GetItem(index, *this);
}

//
// Constructor for a Tab Item
//
// The tab item's label field is initialized to the specified
// buffer and extra parameter set to the 'param' parameter.
//
TTabItem::TTabItem(const char far* str, int buffLen, TParam2 param)
{
  mask = 0;
  iImage = -1;

  SetParam(param);
  SetLabel(str, buffLen);
}

//
// Constructor for a Tab Item
//
// The tab item is initialized with the IMAGELIST index and extra
// parameter specified.
//
TTabItem::TTabItem(int imageIndex, TParam2 param)
{
  mask = 0;
  pszText = 0;
  cchTextMax = 0;

  SetParam(param);
  SetIcon(imageIndex);
}

//
// Constructor for a Tab Item
//
// The tab item is initialized with the IMAGELIST index and label
// specified..
//
TTabItem::TTabItem(int imageIndex, const char far* str)
{
  mask = 0;
  SetIcon(imageIndex);
  SetLabel(str);
}

//
// Initializes the structure member representing the tab's text
//
void
TTabItem::SetLabel(const char far* str, int len)
{
  pszText = CONST_CAST(char far*, str);
  cchTextMax = len ? len : strlen(str);
  mask |= TCIF_TEXT;
}

//----------------------------------------------------------------------------
DEFINE_RESPONSE_TABLE1(TTabControl, TControl)
  EV_WM_HSCROLL,
  EV_WM_VSCROLL,
#if !defined(OWL_NATIVECTRL_ALWAYS)
  EV_WM_SIZE,
  EV_WM_LBUTTONDOWN,
  EV_WM_SETFOCUS,
  EV_WM_KILLFOCUS,
  EV_WM_GETDLGCODE,
  EV_WM_KEYDOWN,
#endif  // OWL_NATIVECTRL_ALWAYS
END_RESPONSE_TABLE;


//
// constructor for TTabControl
//
// initializes its data fields using parameters passed and default values
//
// by default, a TabControl associated with the TTabControl will:
//   - be visible upon creation
//   - display only one row of tabs.
//
TTabControl::TTabControl(TWindow*   parent,
                         int        id,
                         int x, int y, int w, int h,
                         TModule*   module)
:
  TControl(parent, id, 0, x, y, w, h, module)
#if !defined(OWL_NATIVECTRL_ALWAYS)
  ,Updown(0), NormalFont(0), SelectFont(0), TabList(0)
#endif
{
  Attr.Style |= (TCS_SINGLELINE|TCS_TABS|WS_CLIPCHILDREN|WS_CLIPSIBLINGS);

  // By default we'll use the native implementation if it's available
  //
  NativeUse = TCommCtrl::IsAvailable() ? nuAlways : nuNever;

#if !defined(OWL_NATIVECTRL_ALWAYS)
  // When running in an environment where the system does not provide
  // Common Controls we need to initialize the variables used for
  // emulating a tabcontrol...
  //
  if (!TCommCtrl::IsAvailable())
    InitCtl();
#else
  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());
#endif
}

//
// Constructor for a TTabControl object associated with a Tab Control
// specified in a dialog resource.
//
TTabControl::TTabControl(TWindow*   parent,
                         int        resourceId,
                         TModule*   module)
:
  TControl(parent, resourceId, module)
{
  // By default we'll use the native implementation if it's available
  // NOTE: Since this control is really originating from a dialog
  //       resource, we cannot ascertain the classname used by the
  //       resource designer before having access to the HWND.
  //       Hence, we'll assume that if we're running on a system
  //       with native common control support, the dialog resource
  //       specified the native class name.
  //
  NativeUse = TCommCtrl::IsAvailable() ? nuAlways : nuNever;

#if !defined(OWL_NATIVECTRL_ALWAYS)
  // When running in an environment where the system does not provide
  // Common Controls we need to initialize the variables used for
  // emulating a tabcontrol...
  //
  if (!TCommCtrl::IsAvailable())
    InitCtl();
#else
  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());
#endif
}

//
// Constructor for a TTabControl object to be associated with 
// an already created Tab Control.
//
TTabControl::TTabControl(HWND hwnd) : TControl(hwnd)
{
  PRECONDITION(hwnd && ::IsWindow(hwnd));

  // Here we'll assume if the Common Control Library is available, the
  // window passed is being backed by the CommonControl Library (i.e.
  // OWL does not need to provide the underlying implementation for
  // tab controls.
}

//
// Cleans up if underlying Tab support was provided by ObjectWindows
//
TTabControl::~TTabControl()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  // When running in an environment where the system does not provide
  // Common Controls we need to cleanup the variables used for
  // emulating a tabcontrol...
  //
  if (!TCommCtrl::IsAvailable())
    CleanupCtl();
#endif
}

//
// Returns the class name of the underlying control associated with
// the TTabControl object.
//
char far*
TTabControl::GetClassName()
{
#if defined(OWL_NATIVECTRL_ALWAYS)
  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  PRECONDITION(TCommCtrl::IsAvailable());
  NativeUse = TNativeUse(NativeUse | nuUsing);
  return WC_TABCONTROL;

#else
  // Update flags (??)
  //
  if (TCommCtrl::IsAvailable())
    NativeUse = TNativeUse(NativeUse | nuUsing);
  else
    NativeUse = TNativeUse(NativeUse & ~nuUsing);

  // For debugging purposes only
  //
#if defined(__OWL_NO_COMMCTRL)

  // CommCtrl is always available under the new Shell - If IsAvailable()
  // returns false, we must be running a test/debugging run. Return a
  // non-system name to avoid conflicts
  //
  if (!TCommCtrl::IsAvailable() && TSystem::Has3dUI())
    return "OWL_Tab";
#endif

  // Return same name irrespective of whether OWL or Common Control Library
  // provides underlying implementation. This eases the usage of the control
  // in a dialog resource.
  //
  return WC_TABCONTROL;
#endif
}

//
// Transfer is not implemented in TTabControl given that each item
// interacts with settings outside of the TC_ITEM members. [eg. the 
// image index points to the ImageList].
//
uint
TTabControl::Transfer(void* /*buffer*/, TTransferDirection /*direction*/)
{
  TRACEX(OwlCommCtrl, 0, "TTabControl::Transfer is not implemented");
  return 0;
}

#if defined(OWL_NATIVECTRL_ALWAYS)
//
// Keep TWindow from rerouting this message - it must be left as is 
// for the tab control as it may originate from the control's spin.
//
void
TTabControl::EvVScroll(uint, uint, THandle)
{
  DefaultProcessing();
}

//
// Keep TWindow from rerouting this message - it must be left as is 
// for the tab control as it may originate from the control's spin.
//
void
TTabControl::EvHScroll(uint, uint, THandle)
{
  DefaultProcessing();
}

#else   

//
// Handler for WM_VSCROLL messages
//
void
TTabControl::EvVScroll(uint scrollCode, uint /*pos*/, THandle /*hWndCtl*/)
{
  if (TCommCtrl::IsAvailable()) {
    DefaultProcessing();
  } 
  else {
    if (scrollCode == SB_LINEDOWN) {
      if (GetFirstVisibleTab() > 0)
        SetFirstVisibleTab(GetFirstVisibleTab()-1);
    }
    else if (scrollCode == SB_LINEUP) {
      if (!IsVisible(GetCount()-1) || IsClipped(GetCount()-1))
        SetFirstVisibleTab(GetFirstVisibleTab()+1);
    }
  }
}

//
// Handler for WM_VSCROLL messages
//
void
TTabControl::EvHScroll(uint, uint, THandle)
{
  DefaultProcessing();
}
#endif  


#if !defined(OWL_NATIVECTRL_ALWAYS)

//
// By default, GetWindowClass is only called if the class is not
// already registered - i.e. If GetClassInfo on the classname failed.
// Therefore, when we use the Common Control Library, the following
// method is never invoked.
//
void
TTabControl::GetWindowClass(WNDCLASS& wndClass)
{
  TControl::GetWindowClass(wndClass);
  wndClass.hbrBackground = HBRUSH(COLOR_BTNFACE + 1);
  wndClass.style = CS_VREDRAW|CS_HREDRAW;
}

//
// SetupWindow: Initializes internal state variables when 
// ObjectWindows provides the underlying support for tab controls.
//
void
TTabControl::SetupWindow()
{
  TControl::SetupWindow();

  if (!TCommCtrl::IsAvailable()) {
    // Setup Fonts used by control
    //
    SetupFont();
  }
}

//
// If the 'clientInWindowOut' parameter is false, this method calculates
// the display area of a tab control's display from a window rectangle
// specified by the 'rect' parameter. Otherwise, the method calculates
// the window rectangle that would correspond to display area specified
// by the 'rect' parameter. The 'rect' parameter receives the newly computed
// rectangle.
//
void
TTabControl::AdjustRect(bool clientInWindowOut, TRect& rect)
{
  if (TCommCtrl::IsAvailable())
    SendMessage(TCM_ADJUSTRECT, TParam1(clientInWindowOut), TParam2(&rect));
  else {

    // NOTE: The following logic is simplified by letting windows provide 
    //       the delta between WindowRect and ClientRect and
    //       then offseting the passed rectangle accordingly...
    //       If the tab is at (0, 0, 0, 0) [for example, if it's
    //       minimized], this logic will fail. 
    //      
    //       A better approach [but more involved] would be to 
    //       use AdjustWindowRectEx and the system metrics information
    //       to perform the computation.

    // Retrieve current rectangles of tab to have the deltas
    // between the window rect and the client area...
    //
    TRect clientArea, winRect;
    GetClientArea(clientArea, true);
    GetWindowRect(winRect);

    // Make the window-rect (0, 0)-based so it may be used 
    // as a delta...
    //
    ::MapWindowPoints(HWND_DESKTOP, *this, (LPPOINT)&winRect, 2);

    if (clientInWindowOut) {
      // 'rect' specifies the clientarea, we give back the 
      // Windowrect...
      //
      rect.left  -= (clientArea.left - winRect.left);
      rect.right += (winRect.right - clientArea.right);
      rect.top   -= (clientArea.top - winRect.top);
      rect.bottom+= (winRect.bottom - clientArea.bottom);
    }
    else {
      // 'rect' specifies the WindowRect, we give back the 
      // clientArea...
      //
      rect.left  += (clientArea.left - winRect.left);
      rect.right -= (winRect.right - clientArea.right);
      rect.top   += (clientArea.top - winRect.top);
      rect.bottom-= (winRect.bottom - clientArea.bottom);
    }
  }
}

//
// Adds a new tab described by the 'item' parameter to the tab control.
// The return value is the index of the new tab or -1 in case of error.
//
int
TTabControl::Add(const TTabItem& item)
{
  return Insert(item, GetCount());
}

//
// Adds a new tab with the 'tabText' caption to the tab control
// Returns the index of the new tab, if successful or -1 otherwise.
//
int 
TTabControl::Add(const char far* tabText)
{
  return Insert(tabText, GetCount());
}

//
// Inserts a new tab described by the 'item' parameter to the tab
// control at the position specified by the 'index' parameter.
// The return value is the index of the new tab or -1 in case of error.
//
int
TTabControl::Insert(const TTabItem& item, int index)
{
  if (TCommCtrl::IsAvailable())
    return (int)SendMessage(TCM_INSERTITEM, index,
                            TParam2((const TC_ITEM far*)(&item)));
  else  {
    // Insert the helper object
    //
    TabList->InsertAt(index, new TTabEntryInternal(item));

    // Set desired size of tab
    //
    SetTabSize(index);

    // Invalidate the whole client on first tab to allow the border
    // to be redrawn...
    // NOTE: We'll opt to select the first item added... Is this
    //       acceptable or should we allow the control to have 
    //       items where none is selected until User-action??
    //
    if (GetCount() == 1)  {
      SetSel(0);
      Invalidate();
    }

    // Allow control to (re)layout the various tabItem locations
    // based on their indices..
    //
    SetTabRects(FirstVisibleTab);

    // Return the index of the tab
    //
    return index;
  }
}

//
// Inserts a new tab with the caption 'tabText' at the 
// specified 'index'. Returns the index of the new tab, if successful.
//
int
TTabControl::Insert(const char far* tabText, int index)
{
  return Insert(TTabItem(tabText), index);
}

//
// Removes the item at the position specified by the 'index' parameter.
// Returns 'true' if successful or 'false' otherwise.
//
bool
TTabControl::Delete(int index)
{
  if (TCommCtrl::IsAvailable()) {
    return SendMessage(TCM_DELETEITEM, index) != 0;
  }
  else {

    // Validate/free item at index...
    //
    if (index < GetCount()) {

      // Keep flag if we'll need to redraw
      //
      bool needRedraw = IsVisible(index);

      // Invalidate the leaving tab
      //
      if (needRedraw)
        InvalidateTabRect(index);

      // Free the item structure
      //
      TabList->FreeAt(index);

      // Layout tabs or invalidate if we just lost the last tab
      //
      if (GetCount() == 0) { 
        FirstVisibleTab = 0;
        SelectedTab = -1;
        Invalidate();
      }
      else {
        if (FirstVisibleTab == GetCount())
          FirstVisibleTab--;

        if (needRedraw) 
          SetTabRects(FirstVisibleTab);
      }

      return true;
    }
  }
  return false;
}

//
// Removes all items from the tab control. Returns 'true' if successful or
// 'false' otherwise.
//
bool
TTabControl::DeleteAll()
{
  if (TCommCtrl::IsAvailable())
    return SendMessage(TCM_DELETEALLITEMS) != 0;
  else {
    while(GetCount())
      Delete(0);
  }
  return true;
}

//
// Returns the number of tab items in the tab control.
//
int
TTabControl::GetCount() const
{
  if (TCommCtrl::IsAvailable())
    return (int)CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETITEMCOUNT);
  else
    return TabList->GetCount();
}

//
// Retrieves the current number of rows in the tab control.
// NOTE: Only tabs with the TCS_MULTILINE style can have multiple rows.
//
int
TTabControl::GetRowCount() const
{
  if (TCommCtrl::IsAvailable())
    return (int)CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETROWCOUNT);
  else
    return NumRows;
}

//
// Returns the index of the currently selected tab item in the tab control.
// Returns -1 if no tab is selected.
//
int
TTabControl::GetSel() const
{
  if (TCommCtrl::IsAvailable())
    return (int)CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETCURSEL);
  else
    return SelectedTab;
}

//
// Selects the tab item at the position specified by the 'index' parameter.
// The return value is the index of the previously selected tab item if
// successful or -1 otherwise.
// NOTE: A tab control does not send TCN_SELCHANGING or TCN_SELCHANGE 
//       notifications when a tab item is selected via this method.
//
int
TTabControl::SetSel(int index)
{
  if (TCommCtrl::IsAvailable())
    return (int)SendMessage(TCM_SETCURSEL, index);
  else {
    PRECONDITION(index < GetCount());
    PRECONDITION(index >= 0);

    int prevSel = GetSel();
    if (index != prevSel) {

      // Invalidate area occupied by previously selected item
      //
      if (prevSel >= 0 && IsVisible(prevSel))
        InvalidateTabRect(prevSel);

      // Update selected index
      //
      SelectedTab = index;

      // Invalidate area occupied by new selection
      //
      if (index >= 0 && IsVisible(index))
        InvalidateTabRect(index);
    }
    return prevSel;
  }
}

//
// Retrieves information about the tab at the position specified by
// the 'index' parameter. Returns true if successful or false otherwise.
// NOTE: The 'mask' member of the 'item' structure specifies which
//       attributes of the tab to return. When spefying TCIF_TEXT, item's
//       pszText member must point to a valid buffer and cchTextMax must
//       specify the size of the buffer.
//
bool
TTabControl::GetItem(int index, TTabItem& item) const
{
  if (TCommCtrl::IsAvailable())
    return CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETITEM, index,
                                           TParam2((TC_ITEM far*)&item)) != 0;
  else {

    // Validate index
    //
    if (index < GetCount()) {

      TTabEntryInternal& tabInfo = (*TabList)[index];

      if (item.mask & TCIF_TEXT)
        strncpy(item.pszText, tabInfo.pszText, item.cchTextMax);

      if (item.mask & TCIF_IMAGE)
        item.iImage = tabInfo.iImage;

      if (item.mask & TCIF_PARAM)
        item.lParam = tabInfo.lParam ;

      return true;
    }
  }
  return false;
}

//
// Retrieves the bounding rectangle of a tab within a tab control.
// Returns true if successful or false otherwise. 
// NOTE: 'rect' receives the position in viewport coordinates.
//
bool
TTabControl::GetItemRect(int index, TRect& rect) const
{
  if (TCommCtrl::IsAvailable())
    return CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETITEMRECT,
                                         index, TParam2((LPRECT)&rect)) != 0;
  else {
    if (index < GetCount()) {
      rect = (*TabList)[index].Rect;
      return true;
    }
  }
  return false;
}

//
// Sets some or all of a tab's attributes. The 'mask' member of the
// 'item' parameter specifies which attributes to set.
// Returns true if successful or false otherwise.
//
bool
TTabControl::SetItem(int index, const TTabItem& item)
{
  if (TCommCtrl::IsAvailable())
    return SendMessage(TCM_SETITEM, index,
                       TParam2((const TC_ITEM far*)&item)) != 0;
  else {
    if (index < GetCount()) {

      // Retrieve reference to our helper object
      //
      TTabEntryInternal& tabInfo = (*TabList)[index];

      if (item.mask & TCIF_TEXT) {
        delete[] tabInfo.pszText;
        tabInfo.pszText = strnewdup(item.pszText);
      }

      if (item.mask & TCIF_IMAGE)
        tabInfo.iImage = item.iImage;

      if (item.mask & TCIF_PARAM)
        tabInfo.lParam = item.lParam;

      // Force redraw if necessary
      //
      if (IsVisible(index) && (item.mask & (TCIF_TEXT|TCIF_IMAGE))) {
        InvalidateTabRect(index);
        SetTabRects(FirstVisibleTab);
      }
      return true;
    }
  }
  return false;
}

//
// Sets the number of bytes per tab reserved for application-defined
// data in a tab control. Returns true if successful or false otherwise.
// NOTE: This method should be invoked only when the tab control does not
//       contain any tabs.
//
bool
TTabControl::SetItemExtra(int extra)
{
  if (TCommCtrl::IsAvailable())
    return SendMessage(TCM_SETITEMEXTRA, extra) != 0;
  else
    // Not necessary when OWL provides underlying implementation of tabs
    // since C++ provides a safer way to add extra data: derivation!
    //
    return false;
}

//
// Sets the size (width/height) of tabs in a fixed-width or owner-draw
// tab control. Returns a TSize object containing the old width and height.
//
TSize
TTabControl::SetItemSize(const TSize& size)
{
  if (TCommCtrl::IsAvailable())
    return TSize(SendMessage(TCM_SETITEMSIZE, 0, MkParam2(size.cx, size.cy)));
  else {
    TSize prevSize = TabSize;
    TabSize = size;
    return prevSize;
  }
}

//
// Sets the amount of space around each tab's icon and label in a tab 
// control. 
//
void
TTabControl::SetPadding(const TSize& size)
{
  if (TCommCtrl::IsAvailable())
    SendMessage(TCM_SETPADDING, 0, MkParam2(size.cx, size.cy));
  else {
    Padding = size;
  }
}

//
// Retrieves the ImageList associated with a tab control. Returns 0 if
// unsuccessful.
//
HIMAGELIST
TTabControl::GetImageList() const
{
  if (TCommCtrl::IsAvailable())
    return (HIMAGELIST)
            CONST_CAST(TTabControl*, this)->SendMessage(TCM_GETIMAGELIST);
  else
    TRACEX(OwlCommCtrl, 0, "TTabControl::GetImageList requires system "\
                           "implementation of tab controls");
    return 0;
}

//
// Assigns an imagelist to the tab control. Returns the handle of the
// previous imagelist or 0 if there is no previous image list.
//
HIMAGELIST
TTabControl::SetImageList(HIMAGELIST himl)
{
  if (TCommCtrl::IsAvailable())
    return (HIMAGELIST)SendMessage(TCM_SETIMAGELIST, 0, TParam2(himl));
  else
    TRACEX(OwlCommCtrl, 0, "TTabControl::SetImageList requires system "\
                           "implementation of tab controls");
    return 0;
}

//
// Removes the image at the position specified by 'index' from the
// imagelist associated with the tab control.
// NOTE: The tab automatically updates each tab's image index so each
//       tab remains associated with the same image it had been.
//
void
TTabControl::RemoveImage(int index)
{
  if (TCommCtrl::IsAvailable())
    SendMessage(TCM_REMOVEIMAGE, index);
  else {
    TRACEX(OwlCommCtrl, 0, "TTabControl::RemoveImage requires system "\
                           "implementation of tab controls");
  }
}

//
// Retrieves the handle of the tooltip control associated with the 
// tab control. Returns 0 if unsuccessful.
//
TWindow::THandle
TTabControl::GetToolTips() const
{
  if (TCommCtrl::IsAvailable()) {
    return THandle(CONST_CAST(TTabControl*,this)->SendMessage(TCM_GETTOOLTIPS));
  }
  else {
    TRACEX(OwlCommCtrl, 0, "TTabControl::GetToolTips requires system "\
                           "implementation of tab controls");
    return 0;
  }
}

//
// Assigns a tooltip control to the tab control. 
//
void
TTabControl::SetToolTips(THandle toolTip)
{
  if (TCommCtrl::IsAvailable())
    SendMessage(TCM_SETTOOLTIPS, TParam1(toolTip));
  else {
    TRACEX(OwlCommCtrl, 0, "TTabControl::SetToolTips requires system "\
                           "implementation of tab controls");
  }
}

//
// Determines the index of the tab which is at the location 
// specified in the 'pt' member of the 'htInfo' parameter.
// Returns -1 if no tab is at the specified position.
//
int
TTabControl::HitTest(TTabHitTestInfo& htInfo)
{
  if (TCommCtrl::IsAvailable()) {
    return (int)SendMessage(TCM_HITTEST, 0,
                              TParam2((TC_HITTESTINFO far*)&htInfo));
  }
  else {
    TRACEX(OwlCommCtrl, 0, "TTabControl::HitTest requires system "\
                           "implementation of tab controls");
    return 0;
  }
}

//----------------------------------------------------------------------------

//
// Constructor of a TabEntry object
//
TTabEntryInternal::TTabEntryInternal(const TC_ITEM& tbItem)
:
 TTabItem(tbItem),
 Rect(0, 0, 0, 0),
 Size(0, 0),
 Row(0)
{
  // Make our own copy of the text if specified
  //
  if (mask & TCIF_TEXT && pszText)
    pszText = strnewdup(pszText);
  else
    pszText = 0;
}

//
// Inflates a Tab's rectangle when the latter is selected
//
inline void
AdjustSelRect(TRect& rect) {
  rect.Inflate(HorzSelInc, 0);
  rect.top -= VertSelInc;
}

//
// Determines if two rectangles meet
// NOTE: This is different from TRect::Touches which reponds
//       negatively when 'right == left' or 'top == bottom'.
//
inline bool
RectsMeet(const TRect& rc1, const TRect rc2) {
  return (rc1.right >= rc2.left && rc1.left <= rc2.right &&
          rc1.bottom >= rc2.top && rc1.top <= rc2.bottom) ? true : false;
}

//
// Initialize variables when ObjectWindows provides underlying
// support for tab control...
//
void
TTabControl::InitCtl()
{
  // Initialize internal structures when using OWL's implementation
  //
  SelectedTab= -1;
  FirstVisibleTab = 0;
  NumRows = 1;
  Padding = TSize(1, 1);
  TabSize = TSize(0, 0);
  TabList = new TCollection<TTabEntryInternal>(InitSize, InitDelta);
  Updown = new TUpDown(this, ID_Updown, 0, 0, 0, 0, this);
  Updown->ModifyStyle(UDS_WRAP, UDS_HORZ);
}

//
// Cleanup internal structures when ObjectWindows provides underlying
// implementation for tab control.
//
void
TTabControl::CleanupCtl()
{
  delete NormalFont;
  delete SelectFont;
  delete TabList;
}


//
// Paint's a tab item
//
void
TTabControl::PaintTab(TDC& dc, const TRect& tbRect, 
                      const char far* txt, bool clip)
{
  // Grab a few pens
  //
  TPen hiPen(TColor::Sys3dHilight);
  TPen txtPen(TColor::SysBtnText);
  TPen drkPen(TColor::Sys3dShadow);

  //
  // Draw highlights for top tabs
  //
  dc.SelectObject(hiPen);
  dc.MoveTo(tbRect.left,    tbRect.bottom);
  dc.LineTo(tbRect.left,    tbRect.top+2);
  dc.LineTo(tbRect.left+2,  tbRect.top);
  dc.LineTo(tbRect.right-1, tbRect.top);
  dc.RestorePen();

  if (clip) {
    // Draw a 'torn' edge
    //
    dc.SelectObject(drkPen);
    int x;
    for (int i = 1, y = tbRect.top; y < tbRect.bottom; y += 3, i++) {
      x = ((i%4) - 2*((i%4)/3))-1;
      dc.MoveTo(tbRect.right + x, y);
      dc.LineTo(tbRect.right + x, min(y+3, int(tbRect.bottom)));
    }
    dc.RestorePen();
  }
  else {
    dc.SelectObject(drkPen);
    dc.MoveTo(tbRect.right-1, tbRect.bottom);
    dc.LineTo(tbRect.right-1, tbRect.top);
    dc.RestorePen();

    dc.SelectObject(txtPen);
    dc.MoveTo(tbRect.right, tbRect.bottom);
    dc.LineTo(tbRect.right, tbRect.top+1);
    dc.RestorePen();
  }

  // Display the label
  //
  TRect txtRect = tbRect;
  txtRect.left += HorzPad;      
  dc.DrawText(txt, -1, txtRect, DT_LEFT|DT_SINGLELINE|DT_VCENTER);
}

//
// Paint tab item's border
//
void
TTabControl::PaintTabBorder(TDC& dc, const TRect& tbClient, const TRect* selTab)
{
  // Grab a few pens
  //
  TPen hiPen(TColor::Sys3dHilight);
  TPen drkPen(TColor::Sys3dShadow);

  // Draw highlights
  //
  dc.SelectObject(hiPen);
  dc.MoveTo(tbClient.left,  tbClient.bottom);
  dc.LineTo(tbClient.left,  tbClient.top);

  // Skip the selected tab (if there's one)
  //
  if (selTab) {
    dc.LineTo(selTab->left,  tbClient.top);
    dc.MoveTo(selTab->right, tbClient.top);
  }

  dc.LineTo(tbClient.right, tbClient.top);
  dc.RestorePen();

  // Draw Shadow on top of tabs
  //
  dc.SelectObject(drkPen);
  dc.LineTo(tbClient.right, tbClient.bottom);
  dc.LineTo(tbClient.left, tbClient.bottom);
  dc.RestorePen();
}

//
// WM_PAINT handler... paints individual tab items
//
void
TTabControl::Paint(TDC& dc, bool /*erase*/, TRect& rect)
{
  // Retrieve client area of tab control
  //
  TRect tbClient;
  GetClientArea(tbClient);

  // Retrieve rectangle of selected tab
  //
  TRect selRect;
  if (GetSel() >= 0)
    GetSelTabArea(selRect);

  // Paint if there are any tab entries
  //
  if (TabList->GetCount()) {

    // Setup the DC for text output
    //
    dc.SelectObject(*NormalFont);
    dc.SetBkMode(TRANSPARENT);

    // Iterate through the tabs
    //
    for (int i=0; i<TabList->GetCount(); i++) {
      const TRect& tbRect = (*TabList)[i].Rect;

      // Only paint if necessary
      //
      if (RectsMeet(rect, tbRect)) {
        const TTabEntryInternal& tab= (*TabList)[i];

        // Skip the selection: it's drawn last
        //
        if (i == GetSel())
          continue;

        PaintTab(dc, tbRect, tab.pszText, IsClipped(i));
      }
    }
    dc.RestoreObjects();


    // Handle the Selected Tab
    //
    if (GetSel() >= 0) {

      // Draw only if necessary
      //
      if (RectsMeet(rect, selRect)) {

        // Check if it's clipped
        //
        bool selIsClipped = IsClipped(GetSel());

        // Pick bold font and paint it
        //
        dc.SelectObject(*SelectFont);
        const TTabEntryInternal& tab= (*TabList)[GetSel()];
        PaintTab(dc, selRect, tab.pszText, selIsClipped);

        // Draw Focus rect
        //
        if (GetFocus() == *this)
          DrawFocusRect(dc, true);

        dc.RestoreObjects();
      }
    }
  }

  // Draw a border around the client area
  //
  if (GetSel() >= 0)
    PaintTabBorder(dc, tbClient, &selRect);
  else
    PaintTabBorder(dc, tbClient);
}


//
// Draws a focus rectangle around the selected tab entry.
//
void
TTabControl::DrawFocusRect(TDC& dc, bool /*inFocus*/)
{
  if (GetCount() > 0 && GetSel() >= 0) {
    TRect tbRect = (*TabList)[GetSel()].Rect;
    tbRect.Inflate(-HorzSelInc, -VertSelInc);
    dc.DrawFocusRect(tbRect);
  }
}

//
// Handles WM_SIZE by repositions individual tab items.
//
void
TTabControl::EvSize(uint sizeType, TSize& size)
{
  if (TCommCtrl::IsAvailable()) {
    DefaultProcessing();
  }
  else {
    TControl::EvSize(sizeType, size);

    // Layout tabs, if we've got any
    //
    if (sizeType != SIZE_MAXHIDE && sizeType != SIZE_MINIMIZED) 
      if (GetCount())
        SetTabRects(FirstVisibleTab);
  }
}

//
// Handles WM_LBUTTONDOWN: Check for tab selection...
//
void
TTabControl::EvLButtonDown(uint /*modKeys*/, TPoint& point)
{
  if (TCommCtrl::IsAvailable()) {
    DefaultProcessing();
  }
  else {

    // Select the tab hit - if any
    //
    int hitIndex = TabFromPoint(point);
    if (hitIndex != -1) 
      if (hitIndex != GetSel()) 
        NotifyAndSelect(hitIndex, true);

    // Grab focus
    //
    if (!(GetStyle() & TCS_FOCUSNEVER))
      SetFocus();
  }
}

//
// Handles WM_SETFOCUS: Draw focus to identify selected tab
//
void
TTabControl::EvSetFocus(THandle /*hWndLostFocus*/)
{
  if (TCommCtrl::IsAvailable()) {
    DefaultProcessing();
  }
  else {
    DrawFocusRect(TClientDC(*this), true);
  }
}

//
// Handles WM_KILLFOCUS: Remove focus around selected tab
//
void
TTabControl::EvKillFocus(THandle hWndGetFocus)
{
  TControl::EvKillFocus(hWndGetFocus);

  if (!TCommCtrl::IsAvailable()) {
    DrawFocusRect(TClientDC(*this), false);
  }
}

//
// Handles WM_GETDLGCODE: Request arrow keys
//
uint
TTabControl::EvGetDlgCode(MSG far* msg)
{
  if (TCommCtrl::IsAvailable()) {
    return TControl::EvGetDlgCode(msg);
  }
  else {
    return TControl::EvGetDlgCode(msg) | DLGC_WANTARROWS;
  }
}

//
// Handles WM_KEYDOWN: Allow arrow keys to move through tab items
//
void
TTabControl::EvKeyDown(uint key, uint /*repeatCount*/, uint flags)
{
  if (TCommCtrl::IsAvailable()) {
    DefaultProcessing();
  }
  else {
    TTabKeyDown tbKydn(*this, Attr.Id, TCN_KEYDOWN, uint16(key), flags);
    SendNotification(::GetParent(*this), Attr.Id, tbKydn);

    // Select next or previous tab on Right and Left arrow respectively
    //
    if (key == VK_RIGHT) {
      if (GetSel() < GetCount()-1)
        NotifyAndSelect(GetSel()+1, true);
    }
    else if (key == VK_LEFT) {
      if (GetSel() > 0)
        NotifyAndSelect(GetSel()-1, true);
    }
  }
}

//
// Assigns a size to a tab. If both width or height are zero, the size is
// determined from the size of the text and/or image of the tab item.
//
void
TTabControl::SetTabSize(int index, int width, int height)
{
  TTabEntryInternal& tab = (*TabList)[index];

  // Store height of tab
  //
  tab.Size.cy = height ? height : TabSize.cy + VertPad*2;

  // Store width of tab
  //
  if (width)
    tab.Size.cx = width;
  else {
    if ((GetStyle() & TCS_FIXEDWIDTH) && TabSize.cx != 0) 
      tab.Size.cx = TabSize.cx;      
    else {

      // Retrieve width and height of text
      //
      if (tab.pszText) {

        // Use screen DC & selected font
        //
        TScreenDC dc;
        dc.SelectObject(*SelectFont);

        // Compute size of label
        //
        TSize txtSize;
        dc.GetTextExtent(tab.pszText, strlen(tab.pszText), txtSize);
        dc.RestoreFont();

        tab.Size.cx = width ? width : txtSize.cx + HorzPad*2;
      }
    }
  }
}

//
// Invalidates the rectangle occupied by the tab at the specified index
//
void
TTabControl::InvalidateTabRect(int index)
{
  PRECONDITION(IsVisible(index));
  TRect tbRect = (*TabList)[index].Rect;
  if (index == GetSel()) {
    AdjustSelRect(tbRect);

    // Lower bottom to allow upper border of client area to 
    // be redrawn...
    //
    tbRect.bottom++;
  }
  // Extend right end to catch dark shadow
  //
  tbRect.right++;

  // Extend further to cover torn edge
  //
  if (IsClipped(index))
    tbRect.right++;

  // Invalidate
  //
  InvalidateRect(tbRect, true);
}

//
// Accessor for index of the first visible tab item
//
int
TTabControl::GetFirstVisibleTab() const
{
  return FirstVisibleTab;
}

//
// Sets the index of the first visible tab
//
void
TTabControl::SetFirstVisibleTab(int index)
{
  PRECONDITION(GetCount());
  PRECONDITION(index < GetCount());
  PRECONDITION(index >= 0);

  if (index != FirstVisibleTab) {
    FirstVisibleTab = index;
    SetTabRects(FirstVisibleTab);

    // Update scoller's range
    //
    UpdateScrollRange();
  }
}

//
// Updates the rectangle occupied by the tab item at the position
// identified by the 'index' parameter.
//
void
TTabControl::SetTabRect(int index, TRect* newRect)
{
  TRect& tbRect = ((*TabList)[index]).Rect;
  if (!tbRect.IsNull())
    InvalidateTabRect(index);

  if (!newRect)
    tbRect.SetNull();
  else {
    tbRect = *newRect;
    if (!tbRect.IsNull())
      InvalidateTabRect(index);
  }
}

//
// Updates the size/locations of tab items.
//
void
TTabControl::SetTabRects(int firstTab)
{
  // First hide the tabs preceeding the first one
  //
  for (int i=0; i<firstTab; i++)
    SetTabRect(i, 0);

  // Layout each item's location
  //
  SetTabRectsSingle(firstTab);
}

//
// Updates the locations/size of tabs in a single row..
//
void
TTabControl::SetTabRectsSingle(int firstTab)
{
  // Retrieve the area where tabs can hang out
  //
  TRect tabArea;
  GetTabsArea(tabArea);

  // Loop vars to keep track of upper left corner assignments
  //
  int x = tabArea.left;
  int y = tabArea.top;

  TRect newRect;

  // Assume scrollers are off unless we have tabs off to the left
  //
  int index;
  int count = GetCount();
  bool showScroller = firstTab ? true : false;

  // Check if the width of tabs exceeds the width of the control -
  // which would imply that we need scrollers
  //
  if (!showScroller) {
    for (index=firstTab; index<count; index++) {
      TTabEntryInternal& tab= (*TabList)[index];
      x += (tab.Size.cx + Padding.cx);
      if (x > tabArea.right) {
        showScroller = true;
        break;
      }
    }
  }

  // If we'll need scrollers, shrink the tab-area to accomodate
  //
  TRect scrollRect(0, 0, 0, 0);    
  if (showScroller) {
    GetScrollerArea(scrollRect);
    tabArea.right = scrollRect.left-HorzMargin;
  }

  // Iterate through tab, positioning each one
  //
  x = tabArea.left;
  for (index=firstTab; index<count; index++) {
    TTabEntryInternal& tab= (*TabList)[index];
    TRect& tbRect = tab.Rect;

    // Allocate space within the current row using
    // the tab's desired width
    //
    int width = tab.Size.cx;
    int height= tab.Size.cy;

    // Each tab's individual height should match the global TabSize
    //
    CHECK(height == TabSize.cy + VertPad*2);

    // Break if we're going off the viewport to the right
    //
    if (x >= tabArea.right) 
      break;

    // Compute new rectangle
    //
    newRect.Set(x, y, min(x+width, int(tabArea.right-HorzMargin)), y+height);

    // Update tab's rectangle
    //
    if (tbRect != newRect)
      SetTabRect(index, &newRect);

    // Set left side of next tab using some padding
    //
    x += (width + Padding.cx);
  }

  // Make any remaining tabs to the right invisible
  //
  while(index < count)
    SetTabRect(index++, 0);

  // Show/Hide the scrollers & update the scroll range/pos
  //
  Updown->SetWindowPos(HWND_TOP, scrollRect,
                       showScroller ? SWP_NOACTIVATE|SWP_SHOWWINDOW :
                                      SWP_HIDEWINDOW);
  if (showScroller)
    UpdateScrollRange();
}



//
// Select a tab and send the appropriate notifications
//
void        
TTabControl::NotifyAndSelect(int index, bool bringInView)
{
  PRECONDITION(index >= 0);
  PRECONDITION(index < GetCount());

  // First notify that we're about to change selection
  //
  TNotify not(*this, Attr.Id, TCN_SELCHANGING);
  if (!SendNotification(::GetParent(*this), Attr.Id, not)) {

    // If notification was not vetoed, proceed...
    //
    SetSel(index);

    // Notify of selection change
    //
    not.code = TCN_SELCHANGE;
    SendNotification(::GetParent(*this), Attr.Id, not);
  }

  // Bring tab into view if necessary
  //
  if (bringInView) {
    if (!IsVisible(index) || IsClipped(index)) {

      // If index it hidden on the left side, make it the first tab
      //
      if (index < GetFirstVisibleTab())
        SetFirstVisibleTab(index);
      else {

        // If the selected index is too much to the right, scroll
        // things left until it comes in view
        //
        while ((index > GetFirstVisibleTab()) && 
               (!IsVisible(index) || IsClipped(index)))
          SetFirstVisibleTab(GetFirstVisibleTab()+1);          
      }
    }
  }
}

//
// Responds to requests to scroll tabs
//
void
TTabControl::UpdateScrollRange()
{
  int left = 0;
  int cnt = GetCount();

  // Find index of leftmost item
  // NOTE: Leftmost item is never clipped on the left side
  //
  while (left < cnt && !IsVisible(left))
    left++;

  // Find how many items not fully are hanging on the right
  //      
  int noShowRight = 0;
  for (int i = cnt-1; i >=0; i--)
    if (!IsVisible(i) || IsClipped(i))
      noShowRight++;
   
  // Now we want the scroller to allow us to go left 'left' times and go
  // right 'noShowRight' times.
  //      
  Updown->SetRange(0, noShowRight);
  Updown->SetPos(left);
}

//
// Update the Bold and Normal font used by the
// TabControl when displaying Tab labels
//
void
TTabControl::SetupFont(HFONT font)
{
  if (font == 0) {
    // Try to get our parent's font
    //
    font = Parent->GetWindowFont();

    // Use the default UI font
    //
    if (!font) {
      LOGFONT lf;
      TDefaultGUIFont().GetObject(lf);
      font = CreateFontIndirect(&lf);
    }
  }

  // Create Normal and Bold versions of the font for the
  // TabControl's use.
  //
  if (font) {
    LOGFONT lf;
    if (::GetObject(font, sizeof lf, &lf)) {

      lf.lfWeight = FW_NORMAL;
      SetupNormalFont(new TFont(&lf));

      lf.lfWeight = FW_BOLD;
      SetupSelectFont(new TFont(&lf));
    }

    // Update tab height as it must a least match the font's height
    //
    CHECK(SelectFont);
    TScreenDC dc;
    dc.SelectObject(*SelectFont);
    static char smplTxt[] = "M|#_^";
    dc.GetTextExtent(smplTxt, sizeof smplTxt, TabSize);
    dc.RestoreFont();
  }
}

//
// Updates the font used for non-selected tabs
//
void        
TTabControl::SetupNormalFont(TFont* normalFont)
{
  PRECONDITION(!normalFont || normalFont->IsGDIObject());
  delete NormalFont;
  NormalFont = normalFont;
}

//
// Updates the font used for the selected tab
//
void        
TTabControl::SetupSelectFont(TFont* selectFont)
{
  PRECONDITION(!selectFont || selectFont->IsGDIObject());
  delete SelectFont;
  SelectFont = selectFont;
}

//
// Compute the index of the tab at the specified location.
// Returns -1 if unsuccessful.
//
int
TTabControl::TabFromPoint(const TPoint& pt) const
{
  for (int i=0; i<TabList->GetCount(); i++) {
    TRect& tbRect = (*TabList)[i].Rect;
    if (tbRect.Contains(pt))
      return i;
  }
  return -1;
}

//
// Retrieves the desired location of the scrollers within the tab
// control - Assumes we're in 'SingleRow' mode.
// Must *NOT* be called when there are not tabs in the tab controls
//
void
TTabControl::GetScrollerArea(TRect& rect)
{
  PRECONDITION(GetCount() > 0);
  PRECONDITION(!(GetStyle() & TCS_MULTILINE));

  // Retrieve area tabs hang in
  //
  GetTabsArea(rect);

  // Shrink area to almost match the tabs height with a 
  // width twice as big
  //
  rect.Inflate(0, -1);
  rect.left = rect.right - rect.Height()*2;
}

//
// Retrieves the area of the selected tab item.
//
void
TTabControl::GetSelTabArea(TRect& rect)
{
  PRECONDITION(GetSel() >= 0);
  PRECONDITION(GetSel() < GetCount());

  rect = (*TabList)[GetSel()].Rect;
  AdjustSelRect(rect);
}

//
// Retrieves the rectangle within which tabs lie. If there are no tabs in
// the control, then only the left, top and right sides are valid as the
// bottom requires tabs to be computed
//
void
TTabControl::GetTabsArea(TRect& rect)
{
  // First retrieve left, top and right borders
  //
  GetClientRect(rect);
  rect.Inflate(-(HorzMargin+HorzSelInc), -VertMargin);

  // Adjust bottom if there are tabs in the control
  //
  if (GetCount() > 0)
    rect.bottom = rect.top + 
                 (GetRowCount()*(TabSize.cy + VertPad*2 + Padding.cy));
}

//
// Retrieves the rectangle outside the area of tabs
//
// ClientArea = ClientRect with following adjustments
//  (a) left  += HorMargin;
//  (b) right -= HorMargin;
//  (c) top   += (GetRowCount()*(TabSize.cy + VertPad*2 + Padding.cy))-1
//  (d) bottom-= VertMargin;
//
// The Client area described above is the outer client area - i.e. the
// area around which we draw a raised rectangle. This rectangle is
// further shrunk by 'ClientMargin' on all four sizes when computing
// the inner rectangle, the area where a page would be displayed 
// for example.
//
void
TTabControl::GetClientArea(TRect& rect, bool innerRect)
{
  // Retrieve client area and adjust left, right and bottom sides
  //
  GetClientRect(rect);
  rect.Inflate(-HorzMargin, -VertMargin);

  // If there are tabs, adjust the top accordingly
  //
  if (GetCount() > 0) {

    // Adjust top to skip row(s) of tabs
    //
    rect.top += (GetRowCount()*(TabSize.cy + VertPad*2 + Padding.cy))-1;
    if (innerRect) 
      rect.Inflate(-ClientMargin, -ClientMargin);
  }
}

//
// Indicates whether the tab at the specified position is visible.
//
bool
TTabControl::IsVisible(int index)
{
  PRECONDITION(index < GetCount());
  TTabEntryInternal& tab= (*TabList)[index];
  return tab.Rect.IsNull() ? false : true;
}

//
// Indicates whether the tab the the specified position is clipped.
// NOTE: Does not check if the tab is visible...
//       Will be inaccurate for hidden tab items!
//
bool
TTabControl::IsClipped(int index)
{
  PRECONDITION(index < GetCount());
  TTabEntryInternal& tab= (*TabList)[index];
  return tab.Size.cx > tab.Rect.Width();
}


#endif  // !OWL_NATIVECTRL_ALWAYS
