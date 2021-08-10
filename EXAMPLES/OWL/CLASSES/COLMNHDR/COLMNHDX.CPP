//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// Illustrates usage of TColumnHeader class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_LISTBOX_H)
#include <owl/listbox.h>
#endif
#if !defined(OWL_COLMNHDR_H)
#include <owl/colmnhdr.h>
#endif
#if !defined(OWL_INPUTDIA_H)
#include <owl/inputdia.h>
#endif
#if !defined(OLW_VALIDATE_H)
#include <owl/validate.h>
#endif
#include "colmnhdr.h"

//
// A few constants
//
const int   UnChk = TCommandEnabler::Unchecked;
const int   Chk   = TCommandEnabler::Checked;
const int   ColHdrID  = 0x100;              // ID of ColumnHeader control
const int   ListID    = 0x200;              // ID of ListBox control

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void    InitMainWindow();
};

//
// Class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);

  protected:
    void            Paint(TDC& dc, bool erase, TRect& rect);

    // Event handlers
    //
    void            EvSize(uint sizeType, TSize& size);

    void            CmAddHeaderItem();
    void            CeAddHeaderItem(TCommandEnabler& ce)
                    {ce.Enable(ColHdr && ColHdr->IsWindow());}

    void            CmRemoveHeaderItem();
    void            CeRemoveHeaderItem(TCommandEnabler& ce)
                    {ce.Enable(ColHdr && ColHdr->IsWindow()
                                      && ColHdr->GetCount());}

    void            CmTracking(){AllowTracking = !AllowTracking;}
    void            CeTracking(TCommandEnabler& ce)
                    {ce.SetCheck(AllowTracking ? Chk : UnChk);}

    void            CmChanging(){AllowChanging = !AllowChanging;}
    void            CeChanging(TCommandEnabler& ce)
                    {ce.SetCheck(AllowChanging ? Chk : UnChk);}

    // Handlers for ColumnHeader notifications
    //
    bool            ColHdrBeginTrack(THdrNotify far&);
    void            ColHdrEndTrack(THdrNotify far&);
    void            ColHdrDividerDblClick(THdrNotify far&);
    void            ColHdrItemChanged(THdrNotify far&);
    bool            ColHdrItemChanging(THdrNotify far&);
    void            ColHdrItemClick(THdrNotify far&);
    bool            ColHdrTrack(THdrNotify far&);

    // ColumnHeader-related Data members
    //
    TColumnHeader*  ColHdr;
    bool            AllowTracking;
    bool            AllowChanging;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_WM_SIZE,
  EV_COMMAND(CM_ADDITEM,           CmAddHeaderItem),
  EV_COMMAND_ENABLE(CM_ADDITEM,    CeAddHeaderItem),
  EV_COMMAND(CM_REMOVEITEM,        CmRemoveHeaderItem),
  EV_COMMAND_ENABLE(CM_REMOVEITEM, CeRemoveHeaderItem),
  EV_COMMAND(CM_ALLOWTRACKING,   CmTracking),
  EV_COMMAND_ENABLE(CM_ALLOWTRACKING, CeTracking),
  EV_COMMAND(CM_ALLOWITEMCHANGING,   CmChanging),
  EV_COMMAND_ENABLE(CM_ALLOWITEMCHANGING, CeChanging),
  EV_HDN_BEGINTRACK(ColHdrID,       ColHdrBeginTrack),
  EV_HDN_DIVIDERDBLCLICK(ColHdrID,  ColHdrDividerDblClick),
  EV_HDN_ENDTRACK(ColHdrID,         ColHdrEndTrack),
  EV_HDN_ITEMCHANGED(ColHdrID,      ColHdrItemChanged),
  EV_HDN_ITEMCHANGING(ColHdrID,     ColHdrItemChanging),
  EV_HDN_ITEMCLICK(ColHdrID,        ColHdrItemClick),
  EV_HDN_TRACK(ColHdrID,            ColHdrTrack),
END_RESPONSE_TABLE;


TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent),
  AllowTracking(true),
  AllowChanging(true)
{
  Attr.Style |= (WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
  ColHdr = new TColumnHeader(this, ColHdrID, 0, 0, 0, 0);
  ColHdr->Attr.Style |= HDS_BUTTONS;
};

//
// Handles WM_SIZE message sent to client window. This method simply
// invokes the 'Layout' method of the 'TColumnHeader' class.
void
TClientWindow::EvSize(uint sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);

  // Layout header at top of window
  //
  if (ColHdr)
    ColHdr->Layout();
}

//
// WM_PAINT Handler: Draws the rectangle underneath each column
//                   using the color stored in the item data of
//                   the column...
//
void
TClientWindow::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  TRect clientRect = GetClientRect();
  int count = ColHdr->GetCount();

  if (!count) {
    char* noItemMsg = "ColumnHeader contains no items - Please add items.";
    dc.DrawText(noItemMsg, -1, clientRect,
                DT_SINGLELINE|DT_CENTER|DT_VCENTER);
  }
  else {
    TRect columnRect;
    int x = clientRect.left;
    for (int i=0; i<count; i++) {
      THdrItem hdrItem;
      ColHdr->GetItem(hdrItem, i, HDI_LPARAM|HDI_WIDTH);
      columnRect.Set(x, clientRect.top, x+hdrItem.cxy, clientRect.bottom);
      dc.FillRect(columnRect, TBrush(TColor(hdrItem.lParam)));
      x += hdrItem.cxy;
    }
  }
}

//
// Prompts user for some text and creates a new header item
//
void
TClientWindow::CmAddHeaderItem()
{
  char itemText[100] = {0};
  if (TInputDialog(this, "New Item", "Enter item:",
                   itemText, sizeof(itemText)).Execute() == IDOK) {

    // Add text and a random color as item
    //
    THdrItem hdrItem(itemText);
    hdrItem.SetItemData(RGB(random(UCHAR_MAX),
                            random(UCHAR_MAX),
                            random(UCHAR_MAX)));
    ColHdr->Add(hdrItem);
    Invalidate(true);
  }
}

//
// Removes an item from the header control
//
void
TClientWindow::CmRemoveHeaderItem()
{
  char itemIndex[10] = {0};
  if (ColHdr->GetCount() > 0) {
    TInputDialog inputdlg(this, "Remove Item", "Enter index (zero-based):",
                          itemIndex, sizeof(itemIndex), 0,
                          new TRangeValidator(0, ColHdr->GetCount()-1));
    if (inputdlg.Execute() == IDOK) {
      int index = atoi(itemIndex);
      ColHdr->Delete(index);
      Invalidate(true);
    }
  } else {
    MessageBox("No items to remove");
  }
}

//
// Handles HDN_BEGINTRACK notifications...
//
bool
TClientWindow::ColHdrBeginTrack(THdrNotify far&)
{
  return AllowTracking ? false : true;
}

//
// Handles HDN_ENDTRACK notifications...
//
void
TClientWindow::ColHdrEndTrack(THdrNotify far&)
{
  Invalidate(true);
}

//
// Handles HDN_DIVIDERDBLCLK notifications...
//
void
TClientWindow::ColHdrDividerDblClick(THdrNotify far&)
{
  MessageBeep(0);
  MessageBeep(0);
}

//
//
//
void
TClientWindow::ColHdrItemChanged(THdrNotify far&)
{
  Invalidate(true);
}

//
// Handles HDN_ITEMCHANGING notification
//
bool
TClientWindow::ColHdrItemChanging(THdrNotify far&)
{
  return AllowChanging ? false : true;
}

//
// Handles HDN_ITEMCLICK notifications
//
void
TClientWindow::ColHdrItemClick(THdrNotify far& hdrNotify)
{
  // Retrieve the HeaderItem of the clicked guy
  // in case we need some info...
  //
  THdrItem hdrItem;
  ColHdr->GetItem(hdrItem, hdrNotify.iItem, HDI_LPARAM);

  // Update the LPARAM (color)....
  //
  hdrItem.SetItemData(RGB(random(UCHAR_MAX),
                          random(UCHAR_MAX),
                          random(UCHAR_MAX)));
  ColHdr->SetItem(hdrItem, hdrNotify.iItem);

  // Force a redraw
  //
  Invalidate(false);
}

//
// Handles HDN_TRACK notifications...
//
bool
TClientWindow::ColHdrTrack(THdrNotify far&)
{
  return AllowTracking ? false : true;
}

void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, 0, new TClientWindow()));
  GetMainWindow()->AssignMenu(IDM_APPMENU);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
#if defined(BI_PLAT_WIN16)
  if (!TSystem::IsWin95()) {
    ::MessageBox(0, "16-bit column header example designed to run on only Windows 95",
                 "Error", MB_ICONSTOP | MB_OK);
    return -1;
  }
#endif
  return TSampleApp().Run();
}
