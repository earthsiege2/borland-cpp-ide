//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// Illustrates usage of TColumnHeader class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h>
#endif
#if !defined(OWL_COLMNHDR_H)
# include <owl/colmnhdr.h>
#endif
#if !defined(OWL_INPUTDIA_H)
# include <owl/inputdia.h>
#endif
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_CHOOSEFO_H)
# include <owl/choosefo.h>
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
   ~TClientWindow();

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

    void            CmChangeHeaderFont();
    void            CeChangeHeaderFont(TCommandEnabler& ce)
                    {ce.Enable(ColHdr && ColHdr->IsWindow()
                                      && ColHdr->GetCount());}

    void            CmResizing(){AllowResizing = !AllowResizing;}
    void            CeResizing(TCommandEnabler& ce)
                    {ce.SetCheck(AllowResizing ? Chk : UnChk);}

    void            CmClicking();
    void            CeClicking(TCommandEnabler& ce)
                    {ce.SetCheck(ColHdr->GetStyle() & HDS_BUTTONS ? Chk : UnChk);}

    // Handlers for ColumnHeader notifications
    //
    bool            ColHdrBeginTrack(THdrNotify far&);
    void            ColHdrEndTrack(THdrNotify far&);
    void            ColHdrDividerDblClick(THdrNotify far&);
    void            ColHdrItemChanged(THdrNotify far&);
    bool            ColHdrItemChanging(THdrNotify far& notify);
    void            ColHdrItemClick(THdrNotify far&);
    bool            ColHdrTrack(THdrNotify far&);

    // ColumnHeader-related Data members
    //
    TColumnHeader*  ColHdr;
    bool            AllowResizing;
    bool            AllowClicking;
    TPointer<TFont> ColHdrFont;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_WM_SIZE,
  EV_COMMAND(CM_ADDITEM,              CmAddHeaderItem),
  EV_COMMAND_ENABLE(CM_ADDITEM,       CeAddHeaderItem),
  EV_COMMAND(CM_REMOVEITEM,           CmRemoveHeaderItem),
  EV_COMMAND_ENABLE(CM_REMOVEITEM,    CeRemoveHeaderItem),
  EV_COMMAND(CM_CHANGEFONT,           CmChangeHeaderFont),
  EV_COMMAND_ENABLE(CM_CHANGEFONT,    CeChangeHeaderFont),
  EV_COMMAND(CM_ALLOWRESIZING,        CmResizing),
  EV_COMMAND_ENABLE(CM_ALLOWRESIZING, CeResizing),
  EV_COMMAND(CM_ALLOWCLICKING,        CmClicking),
  EV_COMMAND_ENABLE(CM_ALLOWCLICKING, CeClicking),
  EV_HDN_BEGINTRACK(ColHdrID,         ColHdrBeginTrack),
  EV_HDN_DIVIDERDBLCLICK(ColHdrID,    ColHdrDividerDblClick),
  EV_HDN_ENDTRACK(ColHdrID,           ColHdrEndTrack),
  EV_HDN_ITEMCHANGED(ColHdrID,        ColHdrItemChanged),
  EV_HDN_ITEMCHANGING(ColHdrID,       ColHdrItemChanging),
  EV_HDN_ITEMCLICK(ColHdrID,          ColHdrItemClick),
  EV_HDN_TRACK(ColHdrID,              ColHdrTrack),
END_RESPONSE_TABLE;


TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent),
  AllowResizing(true),
  AllowClicking(true)
{
  uint32 oldStyle = GetStyle();
  SetStyle(oldStyle |= (WS_CLIPSIBLINGS|WS_CLIPCHILDREN));

  ColHdr = new TColumnHeader(this, ColHdrID, 0, 0, 0, 0);
  oldStyle = ColHdr->GetStyle();
  ColHdr->SetStyle(oldStyle |= HDS_BUTTONS);
};

TClientWindow::~TClientWindow()
{
  delete ColHdr;
}

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
    char* noItemMsg = "ColumnHeader contains no items.  Please add items.";
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
// Changes the font used in the header control
//
void
TClientWindow::CmChangeHeaderFont()
{
  TChooseFontDialog::TData FontData;

  FontData.DC = 0;
  FontData.Flags =
    CF_EFFECTS | CF_FORCEFONTEXIST | CF_SCREENFONTS | CF_INITTOLOGFONTSTRUCT;
  FontData.Color = 0;
  FontData.Style = 0;
  FontData.FontType = SCREEN_FONTTYPE;
  FontData.SizeMin = 0;
  FontData.SizeMax = 0;

  // Fill FontData.LogFont with info about the column header's current font
  //
  TPointer<TFont> oldFont;
  HFONT hFont = ColHdr->GetWindowFont();
  if (hFont) {
    oldFont = new TFont(hFont);
  }
  else {
    oldFont = new TFont((HFONT)::GetStockObject(SYSTEM_FONT));
  }
  oldFont->GetObject(FontData.LogFont);

  // Ask user to select a new font.  Send font to column header.
  if (TChooseFontDialog(this, FontData).Execute() == IDOK) {
    ColHdrFont = new TFont(&FontData.LogFont);
    ColHdr->SetWindowFont(ColHdrFont->GetHandle(), true);
  }
}                                

//
// Toggle the style bit that controls whether the
// column header receives HDN_ITEMCLICK notifications.
//
void
TClientWindow::CmClicking()
{
  uint32 oldStyle = ColHdr->GetStyle();
  ColHdr->SetStyle(oldStyle ^= HDS_BUTTONS);
  ColHdr->Invalidate();
}

//
// Handles HDN_BEGINTRACK notifications...
//
bool
TClientWindow::ColHdrBeginTrack(THdrNotify far&)
{
  return AllowResizing ? false : true;
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

// Handle HDN_ITEMCHANGING notification
// This notification comes when any attribute of a given
// item is about to change.
//
bool
TClientWindow::ColHdrItemChanging(THdrNotify far& notify)
{
  // Mask flags indicate what is changing.  If the user
  // is re-sizing a column, the width bit is set.
  //
  if (notify.pitem->mask & HDI_WIDTH)  
    return AllowResizing ? false : true;   

  return false;               // allow any other change
}

//
// Handles HDN_ITEMCLICK notifications
// 
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
  return AllowResizing ? false : true;
}

void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "ColumnHeader Example", 
                new TClientWindow()));
  GetMainWindow()->AssignMenu(IDM_APPMENU);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSampleApp().Run();
}
