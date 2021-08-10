//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
//----------------------------------------------------------------------------
#include <owl/pch.h>

#if !defined(OWL_COLMNHDR_H)
#include <owl/colmnhdr.h>
#endif

#if !defined(OWL_NATIVECTRL_ALWAYS)
# if !defined(OWL_UIHELPER_H)
#   include <owl/uihelper.h>
# endif
# if !defined(OWL_COLMNHDR_RH)
#   include <owl/colmnhdr.rh>
# endif
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlCommCtrl);

//
// Default size of string and bitmap items, both measured in pixels
//
int  THdrItem::DefStringItemSize = 100;
int  THdrItem::DefBitmapItemSize = 32;

//
// API to allow user to update ObjectWindows' default string size.
// NOTE: Since the variable maintaining that information is shared
//       by every instance of this class, use this function with
//       caution.
//
void
THdrItem::SetDefStringSize(int size)
{
  DefStringItemSize = size;
}

//
// API to allow the user to update ObjectWindows' default bitmap
// item size.
// NOTE: Since the variable maintaining that information is shared
//       by every instance of this class, use this function with
//       caution.
void
THdrItem::SetDefBitmapSize(int size)
{
  DefBitmapItemSize = size;
}

//
// Constructs a THdrItem object for an item consisting of
// both a string and a bitmapped image.
//
THdrItem::THdrItem(const char far* str, HBITMAP hbm)
{
  mask = HDI_FORMAT;
  fmt  = HDF_LEFT;
  SetText(str);
  SetWidth(DefStringItemSize);
  SetBitmap(hbm);
  lParam = 0;
}

//
// Constructs a THdrItem object for an item which has a string
// Defaults to left alignment and the DefaultStringItemSize.
//
THdrItem::THdrItem(const char far* str)
{
  mask = HDI_FORMAT;
  fmt  = HDF_LEFT;
  SetText(str);
  SetWidth(DefStringItemSize);
  lParam = 0;
}

//
// Constructs a THdrItem object for an item which has a bitmapped image
// Defaults to left alignment and the default bitmap item size.
//
THdrItem::THdrItem(HBITMAP hbm)
{
  mask = HDI_FORMAT;
  fmt  = HDF_LEFT;
  SetBitmap(hbm);
  SetWidth(DefBitmapItemSize);
  lParam = 0;
}

//
// Constructs an 'empty' THdrItem with the specified 'msk' enabled.
// This flavour of the constructor is mainly used to construct an object
// which is used to retrieve information about an existing item.
//
THdrItem::THdrItem(uint msk)
{
  mask = msk;
}

//
// Constructs an 'empty' THdrItem with the specified 'msk' enabled.
// This flavour of the constructor is mainly used to construct an object
// which is used to retrieve information about an existing item. 'buffer'
// specifies a location which will receive the text of the item and 'len'
// specifies the size of the buffer.
//
THdrItem::THdrItem(char far* buffer, int len, uint msk)
{
  mask = msk;
  cchTextMax = len;
  pszText = buffer;
  hbm = 0;
  lParam = 0;
}

//
// Sets the text of the HeaderItem object.
// NOTE: The format flags is not updated to contain any alignment flags
//
void
THdrItem::SetText(const char far* str)
{
  mask      |= (HDI_TEXT|HDI_FORMAT);
  fmt       |= (HDF_STRING);
  pszText    = CONST_CAST(char far*, str);
  cchTextMax = strlen(str);     // This is probably superfluous,
                                // albeit harmless
}

//
// Sets the bitmap handle of the HeaderItem object.
// NOTE: The format flags is not updated to contain any alignment flags
//
void
THdrItem::SetBitmap(HBITMAP bitmap)
{
  mask |= (HDI_BITMAP|HDI_FORMAT);
  fmt  |= HDF_BITMAP;
  hbm   = bitmap;
}

//
// Sets the width of the item
//
void
THdrItem::SetWidth(int width)
{
  cxy = width;
  mask &= ~HDI_HEIGHT;
  mask |=  HDI_WIDTH;
}

//
// Sets the height of the item
//
void
THdrItem::SetHeight(int height)
{
  cxy = height;
  mask &= ~HDI_WIDTH;
  mask |=  HDI_HEIGHT;
}

//
// Sets the application-defined item data attached to this item object
//
void
THdrItem::SetItemData(TParam2 data)
{
  lParam = data;
  mask  |= HDI_LPARAM;
}


//----------------------------------------------------------------------------

//
// constructor for TColumnHeader
//
// initializes its data fields using parameters passed and default values
//
// by default, a ColumnHeader associated with the TColumnHeader will:
//   - be visible upon creation
//   - have a border, divider tracks
//   - be a horizontal header window
//
TColumnHeader::TColumnHeader(TWindow*   parent,
                             int        id,
                             int x, int y, int w, int h,
                             TModule*   module)
:
  TControl(parent, id, 0, x, y, w, h, module)
#if !defined(OWL_NATIVECTRL_ALWAYS)
  , Item(1,0,3) , Font(NULL)
#endif
{
  // By default we'll use the native implementation if it's available
  //
  NativeUse = TCommCtrl::IsAvailable () ? ClassNativeUse : nuNever;

  // here's a strange: although Win95 defines HDS_HORZ, it is defined as '0',
  // which would indicate that the only column headings supported are horizontal
  // headings.  Also, there is no HDS_VERT.
  // In any case, we explicitly 'test' for HDS_HORZ in the code below and we
  // try to forsee what could happen if (and when) HDS_VERT gets defined.
  Attr.Style |= HDS_HORZ;

#if !defined(OWL_NATIVECTRL_ALWAYS)
  // When running in an environment where the system does not provide
  // Common Controls we need to initialize the variables used for
  // emulating a column heading
  //
  if (NativeUse != nuAlways)
    InitCtl();
#else
  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());
#endif

  TRACEX(OwlCommCtrl, OWL_CDLEVEL, "TColumnHeader constructed @" << (void*)this);
}

//
// Constructor of a ColumnHeader object which aliases a control found
// within a dialog.
//
TColumnHeader::TColumnHeader(TWindow*   parent,
                             int        resourceId,
                             TModule*   module)
:
  TControl(parent, resourceId, module)
#if !defined(OWL_NATIVECTRL_ALWAYS)
  ,Item(1,0,3),Font(NULL)
#endif
{

  NativeUse = TCommCtrl::IsAvailable() ? ClassNativeUse : nuNever;

#if !defined(OWL_NATIVECTRL_ALWAYS)
  // When running in an environment where the system does not provide
  // Common Controls we need to initialize the variables used for
  // emulating a tabcontrol...
  //
  if (NativeUse != nuAlways)
    InitCtl();
#else
  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());
#endif
  TRACEX(OwlCommCtrl, OWL_CDLEVEL, "TColumnHeader constructed from resource @" << (void*)this);
}


TColumnHeader::~TColumnHeader()
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  // When running in an environment where the system does not provide
  // Common Controls we need to cleanup the variables used for
  // emulating a column control...
  //
  if (!(NativeUse & nuUsing)) {
    CleanupCtl();
  }
#endif
}

void TColumnHeader::InitCtl()
{
  Font = new TDefaultGUIFont();
  Operation = NONE;
  Pressed = -1;
}


void TColumnHeader::CleanupCtl()
{
  delete Font;
}

//
// Returns the class name of the underlying control associated with
// the TColumnHeader object.
// NOTE: The logic used depends on the availability of native
//       Common Control support. In the case where OWL provides
//       the underlying support, we'll specify a TColumnHeader -specific
//       classname although that's not necessary [it eases debugging]
//
char far*
TColumnHeader::GetClassName()
{
#if defined(OWL_NATIVECTRL_ALWAYS)
  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  PRECONDITION(TCommCtrl::IsAvailable());
  NativeUse = TNativeUse(NativeUse | nuUsing);
  return WC_HEADER;
#else
  // Pick name based on availability of native OS support
  //
  char far* name = (NativeUse & nuAlways) ? WC_HEADER : "OWL_ColumnHeader";

  // Update flags (??)
  //
  if (NativeUse & nuAlways)
    NativeUse = TNativeUse(NativeUse | nuUsing);
  else
    NativeUse = TNativeUse(NativeUse & ~nuUsing);

  return name;
#endif
}

//
// If successful this method returns the number of items in the
// header control. In case of failure it returns -1.
//
int
TColumnHeader::GetCount() const
{
  if (NativeUse & nuUsing) {
    return (int)CONST_CAST(TColumnHeader*,this)->SendMessage(HDM_GETITEMCOUNT);
  }
  else {
    return Item.GetItemsInContainer();
  }
}

//
// This method retrieves the size and position of a header control
// within a given rectangle. It determines the appropriate dimensions
// of a new header control that is to occupy the given rectangle.
// Upon entry the 'boundingRect' parameter specifies the rectangle
// within which the columnHeader must lie. The control then updates
// the WINDOWPOS structure to contain the desired/appropriate dimensions
// for the control to occupy within the specified rectangle.
//
bool
TColumnHeader::Layout(TRect& boundingRect, WINDOWPOS& wp)
{
  if(NativeUse & nuUsing) {
    HD_LAYOUT hdl;
    hdl.prc   = &boundingRect;
    hdl.pwpos = &wp;
    return SendMessage(HDM_LAYOUT, 0, TParam2(&hdl)) != 0;
  }
  else {
    wp.hwnd = GetHandle();
    wp.hwndInsertAfter = NULL;
    wp.flags = SWP_NOZORDER;
    wp.x = boundingRect.left;
    wp.y = boundingRect.top;

    TClientDC dc(GetHandle());

    if(Font!=NULL) {
      dc.SelectObject(*Font);
    }

    TEXTMETRIC tm;
    dc.GetTextMetrics(tm);

    // The hard-coded value represents extra border space.  This could be
    // computed using TUIBorder, but there is no easy way to extract the space
    // used by the edges.
    const int BORDER_SPACE=4;

    if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
      wp.cx=boundingRect.Width();
      wp.cy=tm.tmHeight+BORDER_SPACE;
    }
    else {
      wp.cy=boundingRect.Height();
      wp.cx=tm.tmMaxCharWidth+BORDER_SPACE;
    }
    return true;
  }
}

//
// This method repositions the columnHeader control within the client area
// of its parent window by taking advantage of the columnHeader's ability
// to specify its desired/appropriate position from a specified bounding
// rectangle. This method assumes that the control will occupy the full
// width of the client area of its parent.
//
bool
TColumnHeader::Layout(uint swpFlags)
{
  WINDOWPOS wp;
  TRect rect = Parent->GetClientRect();
  if (Layout(rect, wp)) {
    SetWindowPos(wp.hwndInsertAfter, wp.x, wp.y, wp.cx, wp.cy,
                 wp.flags|swpFlags);
    return true;
  }
  return false;
}

//
// Adds a new item to the column header.
// The following illustrates a typical use of the 'Add' method:
//
//      THdrItem hdrItem("&Employee Names");
//      hdr.Add(hdrItem);
//
int
TColumnHeader::Add(const THdrItem& item)
{
  return Insert(item, GetCount());
}

//
// Inserts a new item at the specified location, 'index', in the
// columnHeader control.
// The following illustrates a typical use of the 'Insert' method:
//
//    THdrItem hdrItem(GetModule().LoadBitmap(IDB_COMPANYLOGO));
//    hdr.Insert(hdrItem, 0);
//
int
TColumnHeader::Insert(const THdrItem& item, int index)
{
  if (NativeUse & nuUsing) {
    return SendMessage(HDM_INSERTITEM, index, TParam2(&item)) != 0;
  }
  else {
    if(index < 0) {
      return false;
    }
    if((uint)index > Item.GetItemsInContainer()) {
      index = Item.GetItemsInContainer();
    }
    TItem it(item);
    Item.AddAt(item,index);
    Invalidate();
    return true;
  }
}

//
// Deletes the item at the specified 'index' from the header control.
//
bool
TColumnHeader::Delete(int index)
{
  if (NativeUse & nuUsing) {
    return SendMessage(HDM_DELETEITEM, index) != FALSE;
  }
  else {
    if(index<0 || (uint)index >= Item.GetItemsInContainer()) {
      return false;
    }
    Item.Detach(index);
    Invalidate();
    return true;
  }
}

//
// Retrieves information about the item at the specified index by filling
// out the 'itemInfo' structure passed in. The 'msk' contains one or more
// HDI_xxxx constants and can be used to specify which information should
// be copied.
//
bool
TColumnHeader::GetItem(THdrItem& itemInfo, int index, uint msk)
{
  itemInfo.mask |= msk;
  if (NativeUse & nuUsing) {
    return SendMessage(HDM_GETITEM, index, TParam2(&itemInfo)) != 0;
  }
  else {
    if(index<0 || (uint)index>=Item.GetItemsInContainer()) {
      return false;
    }

    const TItem &it=Item[index];

    if(itemInfo.mask & it.mask & HDI_BITMAP) {
      itemInfo.hbm=it.hbm;
    }
    if(itemInfo.mask & it.mask & HDI_FORMAT) {
      itemInfo.fmt=it.fmt;
    }
    if(itemInfo.mask & it.mask & (HDI_HEIGHT|HDI_WIDTH)) {
      itemInfo.cxy=it.cxy;
    }
    if(itemInfo.mask & it.mask & HDI_LPARAM) {
      itemInfo.lParam=it.lParam;
    }
    if(itemInfo.mask & it.mask & HDI_TEXT) {
      itemInfo.pszText=it.pszText;
      itemInfo.cchTextMax=it.cchTextMax;
    }
    return true;
  }
}

//
// Updates the attribute(s) a the item at the specified 'index'. The
// 'itemInfo' structure contains the new attributes of the item.
//
bool
TColumnHeader::SetItem(const THdrItem& itemInfo, int index)
{
  if (NativeUse & nuUsing) {
    return SendMessage(HDM_SETITEM, index, TParam2(&itemInfo)) != 0;
  }
  else {
    if(index<0 || (uint)index>=Item.GetItemsInContainer()) {
      return false;
    }

    if(SendNotify(HDN_ITEMCHANGING,index)) {
      return false;
    }

    TItem &it=Item[index];

    if(itemInfo.mask & HDI_BITMAP) {
      it.hbm = itemInfo.hbm;
      it.mask |= HDI_BITMAP;
    }
    if(itemInfo.mask & HDI_FORMAT) {
      it.fmt = itemInfo.fmt;
      it.mask |= HDI_FORMAT;
    }
    // note that HDI_WIDTH==HDI_HEIGHT, so only one check needed
    if(itemInfo.mask & HDI_WIDTH) {
      it.cxy = itemInfo.cxy;
      it.mask |= HDI_WIDTH;
    }
    if(itemInfo.mask & HDI_LPARAM) {
      it.lParam = itemInfo.lParam;
      it.mask |= HDI_LPARAM;
    }
    if(itemInfo.mask & HDI_TEXT) {
      if(it.mask & HDI_TEXT) {
        delete [] it.pszText;
      }
      it.pszText = new char[itemInfo.cchTextMax];
      memcpy(it.pszText, itemInfo.pszText, itemInfo.cchTextMax);
      it.cchTextMax = itemInfo.cchTextMax;
      it.mask |= HDI_TEXT;
    }

    Invalidate();
    SendNotify(HDN_ITEMCHANGED, index);

    return true;
  }
}

//
// Transfers are not implemented for ColumnHeaders. Simply return 0.
//

uint
TColumnHeader::Transfer(void* /*buffer*/, TTransferDirection /*direction*/)
{
  TRACEX(OwlCommCtrl, OWL_CDLEVEL, "TColumnHeader::Transfer is not"\
                                   "implemented!");
  return 0;
}

//
// Tests a point to determine which header item, if any, is at the
// specified point.
// NOTE: The coordinates are specified via the 'pt' member of the
//       THeaderHitTestInfo parameter.
//

int
TColumnHeader::HitTest(THeaderHitTestInfo& ht)
{
  if (NativeUse & nuUsing) {
    return (int)SendMessage(HDM_HITTEST, 0, TParam2(&ht));
  }
  else {
    // we need the client rectangle to check for hits...
    TRect clientRect=GetClientRect();

    // if not inside client rectangle, return above or below
    if(!clientRect.Contains(ht.pt)) {
      ht.flags=0;

      if(ht.pt.x<clientRect.left) {
        ht.flags|=HHT_TOLEFT;
      }
      else if(ht.pt.x>=clientRect.right) {
        ht.flags|=HHT_TORIGHT;
      }

      if(ht.pt.y<clientRect.top) {
        ht.flags|=HHT_ABOVE;
      }
      else if(ht.pt.y>=clientRect.bottom) {
        ht.flags|=HHT_BELOW;
      }

      return ht.iItem=-1;
    }

    // Determine hot box around dividing line
    TRect hotBox = clientRect;
    TSize hotSize(GetSystemMetrics(SM_CXDOUBLECLK), GetSystemMetrics(SM_CYDOUBLECLK));

    if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
      hotBox.left = -hotSize.cx;
      hotBox.right = hotSize.cx;
    }
    else {
      hotBox.top = -hotSize.cy;
      hotBox.bottom = hotSize.cy;
    }

    // Scan for the split position associated with the given point
    for(uint index=0; index < Item.GetItemsInContainer(); ++index) {
      // Move the hot box
      if((Attr.Style & HDS_HORZ)==HDS_HORZ)
        hotBox.Offset(Item[index].cxy,0);
      else
        hotBox.Offset(0,Item[index].cxy);

      // If a next item exists, define a hot box beyond its start edge. If this zone is hit,
      // we will return the next item.
      if(index < Item.GetItemsInContainer()-1) {
        TRect nextHotBox = hotBox;

        if((Attr.Style & HDS_HORZ) == HDS_HORZ) {
          nextHotBox.right = hotBox.right+Item[index+1].cxy;
          nextHotBox.left = nextHotBox.right-hotSize.cx;
        }
        else {
          nextHotBox.bottom = hotBox.bottom+Item[index+1].cxy;
          nextHotBox.top = nextHotBox.bottom-hotSize.cy;
        }
        if(nextHotBox.Contains(ht.pt) && nextHotBox.Touches(hotBox)) {
          ht.flags = HHT_ONDIVOPEN;
          ht.iItem = index+1;
          return ht.iItem;
        }
      }

      // Check if hot box contains point
      if(hotBox.Contains(ht.pt)) {
        ht.flags=HHT_ONDIVIDER;
        ht.iItem=index;
        return ht.iItem;
      }

      // check if it is in the item itself
      TRect itemRect;
      if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
        itemRect.left=hotBox.left+hotSize.cx-Item[index].cxy;
        itemRect.right=hotBox.left;
        itemRect.top=hotBox.top;
        itemRect.bottom=hotBox.bottom;
      }
      else {
        itemRect.left=hotBox.left;
        itemRect.right=hotBox.right;
        itemRect.top=hotBox.top+hotSize.cy-Item[index].cxy;
        itemRect.bottom=hotBox.top;
      }

      if(itemRect.Contains(ht.pt)) {
        ht.flags = HHT_ONHEADER;
        ht.iItem = index;
        return ht.iItem;
      }
    }
    ht.flags = HHT_NOWHERE;
    return ht.iItem = -1;
  }
}

#if !defined(OWL_NATIVECTRL_ALWAYS)
DEFINE_RESPONSE_TABLE1(TColumnHeader, TControl)
  EV_WM_GETFONT,
  EV_WM_SETFONT,
  EV_WM_LBUTTONDOWN,
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_SETCURSOR,
END_RESPONSE_TABLE;

TNativeUse TColumnHeader::ClassNativeUse=nuAlways;

TColumnHeader::TItem::TItem()
{
  mask=0;
}

TColumnHeader::TItem::TItem(const HD_ITEM &other)
{
  Init(other);
}

TColumnHeader::TItem::~TItem()
{
  Cleanup();
}

TColumnHeader::TItem &TColumnHeader::TItem::operator=(const TItem &other)
{
  if(this!=&other) {
    Cleanup();
    Init(other);
  }
  return *this;
}

bool TColumnHeader::TItem::operator==(const TItem &other) const
{
  return this==&other;
}

void TColumnHeader::TItem::Cleanup()
{
  if(mask & HDI_TEXT) {
    delete [] pszText;
  }
  mask=0;
}

void TColumnHeader::TItem::Init(const HD_ITEM &other)
{
  mask = other.mask;
  cxy = other.cxy;
  hbm = other.hbm;
  fmt = other.fmt;
  lParam = other.lParam;
  if(other.mask & HDI_TEXT) {
    pszText=new char[cchTextMax=other.cchTextMax];
    memcpy(pszText,other.pszText,other.cchTextMax);
  }
}

LRESULT TColumnHeader::SendNotify(uint code,int item)
{
  HD_NOTIFY notify;

  notify.hdr.hwndFrom = GetHandle();
  notify.hdr.idFrom = GetId();
  notify.hdr.code = code;
  notify.iItem = item;
  notify.iButton = 0;
  if(GetKeyState(VK_RBUTTON)<0) {
    notify.iButton |= 1;
  }
  if(GetKeyState(VK_MBUTTON)<0) {
    notify.iButton |= 2;
  }
  notify.pitem = &Item[item];
  return Parent->SendMessage(WM_NOTIFY, GetId(), reinterpret_cast<LPARAM>(&notify));
}

void TColumnHeader::TrackLine(int pos)
{
  // Determine start and end points of tracking lines in screen coordinates
  TRect clientRect=GetClientRect();

  TPoint start,end;

  if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
    start.x=end.x=pos;
    start.y=clientRect.top;
    end.y=clientRect.bottom;
  }
  else {
    start.y=end.y=pos;
    start.x=clientRect.left;
    end.x=clientRect.right;
  }

  // Move track lines in track window
  TClientDC dc(GetHandle());
  dc.SelectStockObject(WHITE_PEN);
  int oldROP2=dc.SetROP2(R2_XORPEN);
  dc.MoveTo(start);
  dc.LineTo(end);
  dc.SetROP2(oldROP2);
}

void TColumnHeader::BeginTrack(const TPoint &point,int iItem)
{
  Operation=TRACKING;
  // Set initial tracking parameters
  TrackPoint=point;
  HotItem=iItem;
  TrackSize=Item[HotItem].cxy;
  TrackStart=0;
  for(int index=0;index<HotItem;++index)
    TrackStart+=Item[index].cxy;
  TrackLine(TrackStart+TrackSize);
}


void TColumnHeader::Track(const TPoint &point)
{
  // erase line at previous position
  TrackLine(TrackStart+TrackSize);
  if((Attr.Style & HDS_HORZ)==HDS_HORZ)
    TrackSize=Item[HotItem].cxy+point.x-TrackPoint.x;
  else
    TrackSize=Item[HotItem].cxy+point.y-TrackPoint.y;
  if(TrackSize<0)
    TrackSize=0;
  // draw line at new position
  TrackLine(TrackStart+TrackSize);
}

void TColumnHeader::EndTrack()
{
  Operation=NONE;
  TrackLine(TrackStart+TrackSize);
  Item[HotItem].cxy=TrackSize;
  Invalidate();
  SendNotify(HDN_ENDTRACK,HotItem);
}

void TColumnHeader::SetNativeUse(TNativeUse nu)
{
  ClassNativeUse=nu;
}

void TColumnHeader::Paint(TDC &dc,bool /*erase*/,TRect &rect)
{
  // all text will be drawn like buttons (even if they're not)
  dc.SetTextColor(TColor::SysBtnText);
  dc.SetBkColor(TColor::Sys3dFace);
  dc.SetBkMode(TRANSPARENT);

  // Set initial output box
  TRect clientRect=GetClientRect();

  if(Item.IsEmpty()) {
    dc.TextRect(clientRect);
      return;
  }

  TPoint topLeft=clientRect.TopLeft();

  if(Font!=NULL)
    dc.SelectObject(*Font);

  // compute the size of the horizontal and vertical spacing we may need (to
  // prevent the headings to "stick" to close to the edge).
  TEXTMETRIC tm;
  dc.GetTextMetrics(tm);
  TSize spaceSize(tm.tmAveCharWidth,tm.tmHeight);

  // Draw everything
  for(uint index=0;index<Item.GetItemsInContainer();++index) {

    // compute the item rectangle for this item
    TSize size;
    if((Attr.Style & HDS_HORZ)==HDS_HORZ)
      size=TSize(Item[index].cxy,clientRect.Height());
    else
      size=TSize(clientRect.Width(),Item[index].cxy);

    TRect itemRect(topLeft,size);

    // Only paint if item is visible and in clipping rectangle
    if(Item[index].cxy>0 && itemRect.Touches(rect)) {
      // draw the line separating 2 items
      if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
        --itemRect.right;
        dc.MoveTo(itemRect.TopRight());
        dc.LineTo(itemRect.BottomRight());
      }
      else {
        --itemRect.bottom;
        dc.MoveTo(itemRect.BottomLeft());
        dc.LineTo(itemRect.BottomRight());
      }

      TUIBorder::TStyle style;
      if(Attr.Style & HDS_BUTTONS)
          style=(Pressed==(int)index)?TUIBorder::ButtonDn:TUIBorder::ButtonUp;
      else
        style=TUIBorder::Plain;

      TUIBorder border(itemRect,style);
      border.Paint(dc);
      itemRect=border.GetClientRect();

      if(Item[index].fmt & HDF_OWNERDRAW) {
        // if the item is owner drawn, send a WM_DRAWITEM to paint it
        DRAWITEMSTRUCT drawStruct;

        // we can't write the following, since ODT_HEADER is not defined
        drawStruct.CtlType=ODT_HEADER;
        drawStruct.CtlID=Attr.Id;
        drawStruct.itemID=index;
        drawStruct.itemAction=ODA_DRAWENTIRE;
        drawStruct.itemState=(Pressed==(int)index)?ODS_SELECTED:0;
        drawStruct.hwndItem=*this;
        drawStruct.hDC=dc;
        drawStruct.rcItem=itemRect;
        drawStruct.itemData=Item[index].lParam;
        Parent->SendMessage(WM_DRAWITEM,Attr.Id,reinterpret_cast<LPARAM>(&drawStruct));
      }
      else {
        // the item is either a text, a bitmap or both.
        // erase the background
        dc.TextRect(itemRect);

        // get the size of the (optional) bitmap
        TSize bitmapSize;

        if(Item[index].fmt & HDF_BITMAP) {
          TBitmap bitmap(Item[index].hbm);
          bitmapSize.cx=bitmap.Width();
          bitmapSize.cy=bitmap.Height();
          }
        else
          bitmapSize.cx=bitmapSize.cy=0;

        // get the size of the (optional) string
        TSize stringSize;

        if(Item[index].fmt & HDF_STRING)
          stringSize=dc.GetTextExtent(Item[index].pszText,Item[index].cchTextMax);
        else
          stringSize.cx=stringSize.cy=0;

        // compute the size of the entire item
        TSize itemSize;

        if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
          itemSize.cy=max(bitmapSize.cy,stringSize.cy);
          itemSize.cx=bitmapSize.cx+stringSize.cx;
          // add space between bitmap and text if bitmap is present
          if(Item[index].fmt & HDF_BITMAP)
            itemSize.cx+=spaceSize.cx;
        }
        else {
          itemSize.cx=max(bitmapSize.cx,stringSize.cx);
          itemSize.cy=bitmapSize.cy+stringSize.cy;
          // add space between bitmap and text if bitmap is present
          if(Item[index].fmt & HDF_BITMAP)
            itemSize.cy+=spaceSize.cy;
        }

        // with the information we now have, we can align the item as a whole
        // 'p' will be the point where we'll begin drawing the item
        TPoint p=itemRect.TopLeft();
        if((Attr.Style & HDS_HORZ)==HDS_HORZ) {
          if(Item[index].fmt & HDF_LEFT)
            p.x+=spaceSize.cx;
          else if(Item[index].fmt & HDF_CENTER)
            p.x+=(itemRect.Width()-itemSize.cx)/2;
          else if(Item[index].fmt & HDF_RIGHT)
            p.x=itemRect.right-(spaceSize.cx+itemSize.cx);
        }
        else {
          if(Item[index].fmt & HDF_LEFT)
            p.y+=spaceSize.cy;
          else if(Item[index].fmt & HDF_CENTER)
            p.y+=(itemRect.Height()-itemSize.cy)/2;
          else if(Item[index].fmt & HDF_RIGHT)
            p.y=itemRect.bottom-(spaceSize.cy+itemSize.cy);
        }

        // paint the (optional) bitmap
        if(Item[index].fmt & HDF_BITMAP) {
          TBitmap bitmap(Item[index].hbm);
          TMemoryDC memdc;
          memdc.SelectObject(bitmap);
          dc.BitBlt(TRect(p,bitmapSize),memdc,TPoint(0,0));
          p.x+=bitmapSize.cx+spaceSize.cx;
        }
        // paint the (optional) string
        if(Item[index].fmt & HDF_STRING)
          dc.DrawText(Item[index].pszText,Item[index].cchTextMax,TRect(p,stringSize),DT_NOPREFIX|DT_NOCLIP);
        }
      }

      // Set for next part
      if((Attr.Style & HDS_HORZ)==HDS_HORZ)
        topLeft.x+=size.cx;
      else
        topLeft.y+=size.cy;
    }

  // Erase last part
  TRect drawBox=clientRect;
  drawBox.left=topLeft.x;
  drawBox.top=topLeft.y;
  if((Attr.Style & HDS_HORZ)==HDS_HORZ)
    drawBox.right=clientRect.right;
  else
    drawBox.bottom=clientRect.bottom;

  if(!drawBox.IsEmpty() && drawBox.Touches(rect))
    dc.TextRect(drawBox);

  // Restore context
  dc.RestoreObjects();
}

void TColumnHeader::EvSetFont(HFONT hFont, bool redraw)
{
  TControl::EvSetFont(hFont, redraw);
  if(NativeUse & nuUsing) {
    return;
  }

  // Create new font. If header has any items, redraw.
  delete Font;
  Font = new TFont(hFont);
  if (redraw && GetCount() > 0) {
    Invalidate(true);
  }
}

HFONT TColumnHeader::EvGetFont()
{
  if(NativeUse & nuUsing)
    return TControl::EvGetFont();
  else {
    if(Font)
      return *Font;
    else
      return (HFONT)DefaultProcessing();
  }
}

bool TColumnHeader::EvSetCursor(HWND hWndCursor,uint hitTest,uint mouseMsg)
{
  if(NativeUse & nuUsing)
    return TControl::EvSetCursor(hWndCursor,hitTest,mouseMsg);

  if(hitTest==HTCLIENT) {
    TPoint p;

    GetCursorPos(p);
    ScreenToClient(p);
    THeaderHitTestInfo ht(p);
    HitTest(ht);
    if(ht.flags & HHT_ONDIVOPEN)
      SetCursor(::Module,((Attr.Style & HDS_HORZ)==HDS_HORZ)?IDC_SPLITH:IDC_SPLITV);
    else if(ht.flags & HHT_ONDIVIDER)
      SetCursor(::Module,((Attr.Style & HDS_HORZ)==HDS_HORZ)?IDC_SIZEBARH:IDC_SIZEBARV);
    else
      SetCursor(0,IDC_ARROW);
    }

  // Now call base class to change cursor
  return TControl::EvSetCursor(hWndCursor,hitTest,mouseMsg);
}

void TColumnHeader::EvLButtonDown(uint modKeys,TPoint &point)
{
  // Invoke defautl processing
  if(NativeUse & nuUsing)
    TControl::EvLButtonDown(modKeys,point);
  else {
    // See if we are on an item start tracking if so
    THeaderHitTestInfo ht(point);
    if(HitTest(ht)!=-1) {
      if((ht.flags & HHT_ONHEADER) && (Attr.Style & HDS_BUTTONS)) {
        HotItem=Pressed=ht.iItem;
        Invalidate(false);
        Operation=CLICKING;
        SetCapture();
      }
      else if(ht.flags & (HHT_ONDIVIDER|HHT_ONDIVOPEN)) {
        if(SendNotify(HDN_BEGINTRACK,ht.iItem))
          return;
        BeginTrack(point,ht.iItem);
        SetCapture();
      }
    }
  }
}

void TColumnHeader::EvLButtonDblClk(uint modKeys,TPoint &point)
{
  if(NativeUse & nuUsing)
    TControl::EvLButtonDblClk(modKeys, point);
  else {
    THeaderHitTestInfo ht(point);
    if(HitTest(ht)!=-1) {
      if((ht.flags & HHT_ONHEADER) && (Attr.Style & HDS_BUTTONS))
        SendNotify(HDN_ITEMDBLCLICK,ht.iItem);
      else if(ht.flags & (HHT_ONDIVIDER|HHT_ONDIVOPEN))
        SendNotify(HDN_DIVIDERDBLCLICK,ht.iItem);
    }
  }
}

void TColumnHeader::EvMouseMove(uint modKeys,TPoint &point)
{
  if(NativeUse & nuUsing)
    TControl::EvMouseMove(modKeys,point);
  else
    switch(Operation) {
      case CLICKING:
      {
        THeaderHitTestInfo ht(point);
        if(HitTest(ht)==HotItem) {
          // mouse in the header initially clicked on
          if(Pressed!=HotItem) {
            Pressed=HotItem;
            Invalidate(false);
          }
        }
        else {
          // mouse left the header initially clicked on
          if(Pressed!=-1) {
            Pressed=-1;
            Invalidate(false);
          }
        }
      }
      break;

      case TRACKING:
      {
        if(SendNotify(HDN_TRACK,HotItem)) {
          EndTrack();
          ReleaseCapture();
        }
        else
          Track(point);
      }
      break;
    } // switch
}

void TColumnHeader::EvLButtonUp(uint modKeys,TPoint &point)
{
  if(NativeUse & nuUsing)
    TControl::EvLButtonUp(modKeys,point);
  else
    switch(Operation) {
      case CLICKING:
        // If this seems a little strange, note that Windows95 sends a
        // HDN_ITEMCLICK on WM_LBUTTONUP, so we have to emulate that behaviour.
        if(Pressed==HotItem) {
          SendNotify(HDN_ITEMCLICK,HotItem);
          Pressed=-1;
          Invalidate(false);
        }
        Operation=NONE;
        ReleaseCapture();
        break;

      case TRACKING:
        EndTrack();
        ReleaseCapture();
        break;
      }
}

#endif
