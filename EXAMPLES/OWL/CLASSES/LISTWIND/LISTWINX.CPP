//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//   Defines class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/listwind.h>
#include <owl/imagelst.h>
#include <owl/menu.h>
#include <owl/editsear.rh>      // Get resources
#include <owl/editfile.rh>      // Get resources
#include <stdio.h>
#include <dir.h>
#include "listwind.rh"

const int ListWindId = 100;

//
// Class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);
   ~TClientWindow();

  protected:
    void SetupWindow();

    void EvLButtonUp(uint modKeys, TPoint& point);
    void EvMouseMove(uint modKeys, TPoint& point);
    void LvnBeginDrag(TLwNotify& notify);

    // Event handlers
    //
    void CeLargeIcon(TCommandEnabler& ce) {
      ce.SetCheck(Type == LargeIcon ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
    }
    void CmLargeIcon();

    void CeSmallIcon(TCommandEnabler& ce) {
      ce.SetCheck(Type == SmallIcon ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
    }
    void CmSmallIcon();

    void CeList(TCommandEnabler& ce) {
      ce.SetCheck(Type == List ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
    }
    void CmList();

    void CeDetail(TCommandEnabler& ce) {
      ce.SetCheck(Type == Detail ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
    }
    void CmDetail();

    // Data members
    //
    TListWindow*  ListWind;
    TImageList*   ImageList;
    TImageList*   DragImage;
    bool          InDrag;
    char          Buffer[256];
    TRect         DragOffset;

    enum TListWindowType {
      LargeIcon, SmallIcon, List, Detail
    } Type;


  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_WM_MOUSEMOVE,
  EV_WM_LBUTTONUP,
  EV_COMMAND       (CM_VIEWLARGEICON, CmLargeIcon),
  EV_COMMAND_ENABLE(CM_VIEWLARGEICON, CeLargeIcon),
  EV_COMMAND       (CM_VIEWSMALLICON, CmSmallIcon),
  EV_COMMAND_ENABLE(CM_VIEWSMALLICON, CeSmallIcon),
  EV_COMMAND       (CM_VIEWLIST,      CmList),
  EV_COMMAND_ENABLE(CM_VIEWLIST,      CeList),
  EV_COMMAND       (CM_VIEWDETAIL,    CmDetail),
  EV_COMMAND_ENABLE(CM_VIEWDETAIL,    CeDetail),
  EV_LVN_BEGINDRAG(ListWindId, LvnBeginDrag),
END_RESPONSE_TABLE;

TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent),
  ListWind(0),
  DragImage(0),
  InDrag(false)
{
  AssignContextMenu(new TPopupMenu(TMenu(*GetApplication(), IDM_VIEW)));
  Attr.Style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

  // Initialize ImageList
  //
  ImageList = new TImageList(TSize(20, 20), ILC_COLOR4, 15, 5);
  ImageList->Add(TBitmap(*GetApplication(), CM_FILENEW));
  ImageList->Add(TBitmap(*GetApplication(), CM_FILEOPEN));
  ImageList->Add(TBitmap(*GetApplication(), CM_FILESAVE));
  ImageList->Add(TBitmap(*GetApplication(), CM_FILESAVEAS));
  ImageList->Add(TBitmap(*GetApplication(), CM_FILEPRINT));

  ImageList->Add(TBitmap(*GetApplication(), CM_EDITCUT));
  ImageList->Add(TBitmap(*GetApplication(), CM_EDITCOPY));
  ImageList->Add(TBitmap(*GetApplication(), CM_EDITPASTE));
  ImageList->Add(TBitmap(*GetApplication(), CM_EDITFIND));
  ImageList->Add(TBitmap(*GetApplication(), CM_EDITREPLACE));
  ImageList->Add(TBitmap(*GetApplication(), CM_EDITFINDNEXT));
}

TClientWindow::~TClientWindow()
{
  delete ImageList;
}

void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  CmLargeIcon();
}

void
TClientWindow::EvLButtonUp(uint, TPoint&)
{
  if (InDrag) {
    InDrag = false;
    ReleaseCapture();
    TImageList::DragLeave(*this);
    TImageList::EndDrag();
    delete DragImage;
    DragImage = 0;
    ShowCursor(true);
  }
}

void
TClientWindow::EvMouseMove(uint, TPoint& point)
{
  if (InDrag) {
    TImageList::DragMove(point.x + DragOffset.left, point.y + DragOffset.top);
  }
}

void
TClientWindow::LvnBeginDrag(TLwNotify& notify)
{
  InDrag = true;
  TPoint point;
  DragImage = new TImageList(ListWind->CreateDragImage(notify.iItem, &point));

  ListWind->GetItemRect(notify.iItem, &DragOffset, TListWindow::Bounds);

  DragImage->BeginDrag(0, point.x, point.y);
  SetCapture();
  ShowCursor(false);
  TImageList::DragEnter(*this, point.x, point.y);
}

void
TClientWindow::CmLargeIcon()
{
  Type = LargeIcon;
  delete ListWind;
  ListWind = new TListWindow(this, ListWindId, 40, 40, 400, 200);
  ListWind->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_ICON;
  ListWind->Create();

  ListWind->SetImageList(*ImageList, TListWindow::Normal);

  for (int i = 0; i < ImageList->GetImageCount(); i++) {
    sprintf(Buffer, "Item %d", i);
    TListWindItem item(Buffer);
    item.SetImageIndex(i);
    ListWind->InsertItem(item);
  }
}

void
TClientWindow::CmSmallIcon()
{
  Type = SmallIcon;
  delete ListWind;

  ListWind = new TListWindow(this, ListWindId, 40, 40, 400, 200);
  ListWind->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_SMALLICON;
  ListWind->Create();

  ListWind->SetImageList(*ImageList, TListWindow::Small);

  for (int i = 0; i < ImageList->GetImageCount(); i++) {
    sprintf(Buffer, "Item %d", i);
    TListWindItem item(Buffer);
    item.SetImageIndex(i);
    ListWind->InsertItem(item);
  }
}

void
TClientWindow::CmList()
{
  Type = List;
  delete ListWind;

  ListWind = new TListWindow(this, ListWindId, 40, 40, 400, 200);
  ListWind->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_LIST;
  ListWind->Create();

  for (int i = 0; i < ImageList->GetImageCount(); i++) {
    sprintf(Buffer, "Item %d", i);
    TListWindItem item(Buffer);
    ListWind->InsertItem(item);
  }
}

void
TClientWindow::CmDetail()
{
  Type = Detail;
  delete ListWind;

  ListWind = new TListWindow(this, ListWindId, 40, 40, 400, 200);
  ListWind->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_REPORT;
  ListWind->Create();

  ListWind->SetImageList(*ImageList, TListWindow::State);

  TListWindColumn column("Column", 100);
  ListWind->InsertColumn(0, column);

  for (int i = 0; i < ImageList->GetImageCount(); i++) {
    sprintf(Buffer, "Item %d", i);
    TListWindItem item(Buffer);
    item.SetStateImage(i);
    ListWind->InsertItem(item);
  }
}

//----------------------------------------------------------------------------

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp()
    :
      TApplication()
    {
    }

    void InitMainWindow();
};

void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "ListWindow Example", new TClientWindow));
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
