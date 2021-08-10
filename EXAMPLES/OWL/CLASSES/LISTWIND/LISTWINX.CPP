//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1996, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.9  $
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/listwind.h>
#include <owl/listbox.h>
#include <owl/imagelst.h>
#include <owl/menu.h>
#include <owl/editsear.rh>
#include <owl/editfile.rh>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include "listwind.rh"

const int ListWindId = 100;
const int MAX_ITEMS = 20;
const int MAX_CHARS = 25;

//----------------------------------------------------------------------------

//
// Class TInfoDialog
// ~~~~~ ~~~~~~~~~~~

class TInfoDialog : public TDialog {
  public:
    TInfoDialog(TWindow* parent, int resId, int count);
    static char strings[MAX_ITEMS][MAX_CHARS];
  protected:
    void SetupWindow(void);
  private:
    TListBox* ListBox;
    int Count;
};

char TInfoDialog::strings[MAX_ITEMS][MAX_CHARS];

TInfoDialog::TInfoDialog(TWindow* parent, int resId, int count)
:
  TDialog(parent, resId),
  Count(count)
{
  ListBox = new TListBox(this, IDC_LISTBOX);
}

void
TInfoDialog::SetupWindow()
{
  TDialog::SetupWindow();

  // Fill the list box with the list of selected indexes
  //
  for (int i = 0; i < Count; i++)
  {
    ListBox->AddString(strings[i]);
  }
}

//-----------------------------------------------------------

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

    void CeAnySelected(TCommandEnabler& ce) {
      ce.Enable(ListWind->GetSelCount() > 0);
    }

    void CmShowSelected();
    void CmShowSelectionState();
    void CmShowSelStrings();
    void CmSelectAll();
    void CmUnselect();

    // Data members
    //
    TListWindow*  ListWind;
    TImageList*   LgImageList;
    TImageList*   SmImageList;
    TImageList*   DragImage;
    bool          InDrag;
    char          Buffer[256];
    TRect         DragOffset;

    enum TListWindowType {
      LargeIcon,
      SmallIcon,
      List,
      Detail
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
  EV_LVN_BEGINDRAG (ListWindId, LvnBeginDrag),
  EV_COMMAND       (CM_SHOWSELECTED,  CmShowSelected),
  EV_COMMAND_ENABLE(CM_SHOWSELECTED,  CeAnySelected),
  EV_COMMAND       (CM_SHOWSTATE,     CmShowSelectionState),
  EV_COMMAND_ENABLE(CM_SHOWSTATE,     CeAnySelected),
  EV_COMMAND       (CM_SHOWSTRINGS,   CmShowSelStrings),
  EV_COMMAND_ENABLE(CM_SHOWSTRINGS,   CeAnySelected),
  EV_COMMAND       (CM_SELECTALL,     CmSelectAll),
  EV_COMMAND       (CM_UNSELECT,      CmUnselect),
  EV_COMMAND_ENABLE(CM_UNSELECT,      CeAnySelected),
END_RESPONSE_TABLE;

TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent),
  ListWind(0),
  DragImage(0),
  InDrag(false)
{
  TMenu cMenu(*GetApplication(), IDM_VIEW);
  AssignContextMenu(new TPopupMenu(cMenu));

  // Initialize ImageLists
  //
  LgImageList = new TImageList(TSize(32, 32), ILC_COLOR4, 15, 5);
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_1));
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_2));
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_3));
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_4));

  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_5));
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_6));
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_7));
  LgImageList->Add(TIcon(*GetApplication(), (TResId)ICON_8));

  SmImageList = new TImageList(TSize(16, 16), ILC_COLOR4, 15, 5);
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_1));
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_2));
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_3));
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_4));

  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_5));
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_6));
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_7));
  SmImageList->Add(TIcon(*GetApplication(), (TResId)ICON_8));

  // Create Listview control
  //
  Type = SmallIcon;
  ListWind = new TListWindow(this, ListWindId, 40, 40, 300, 250);
  ListWind->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_SMALLICON;
  ListWind->SetBkgndColor( TColor::Sys3dFace );

  SetBkgndColor( TColor::Sys3dFace );
}

TClientWindow::~TClientWindow()
{
  delete LgImageList;
  delete SmImageList;
}

void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  ListWind->SetTextBkColor( TColor::Sys3dFace );

  ListWind->SetImageList(*LgImageList, TListWindow::Normal);
  ListWind->SetImageList(*SmImageList, TListWindow::Small);

  TListWindColumn column("Column", 100);
  ListWind->InsertColumn(0, column);

  for (int i = 0; i < SmImageList->GetImageCount(); i++) {
    sprintf(Buffer, "Item %d", i);
    TListWindItem item(Buffer);
    item.SetImageIndex(i);
    ListWind->InsertItem(item);
  }
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
  if( Type != LargeIcon )  {
    Type = LargeIcon;
    ListWind->ModifyStyle(LVS_TYPEMASK, LVS_ICON);
 }
}

void
TClientWindow::CmSmallIcon()
{
  if( Type != SmallIcon )  {
    Type = SmallIcon;
    ListWind->ModifyStyle( LVS_TYPEMASK, LVS_SMALLICON );
 }
}

void
TClientWindow::CmList()
{
  if( Type != List )  {
    Type = List;
    ListWind->ModifyStyle( LVS_TYPEMASK, LVS_LIST );
  }
}

void
TClientWindow::CmDetail()
{
  if( Type != Detail )  {
    Type = Detail;
    ListWind->ModifyStyle( LVS_TYPEMASK, LVS_REPORT );
  }
}

void
TClientWindow::CmShowSelected()
{
  int indexes[MAX_ITEMS];
  int count = ListWind->GetSelIndexes(indexes, MAX_ITEMS);

  // Fill the dialog's string buffer
  //
  for (int i = 0; i < count; i++)
    itoa(indexes[i], TInfoDialog::strings[i], 10);

  // Now show the dialog
  //
  TInfoDialog showSel(this, IDD_SHOWSELECT, count);
  showSel.Execute();
}

void
TClientWindow::CmShowSelectionState()
{
  // Enumerate all items and fill the dialog's string buffer
  //
  int count = ListWind->GetItemCount();
  for (int i = 0; i < count; i++) {
    wsprintf(TInfoDialog::strings[i],
      "Item %d %s", i, ListWind->IsSelected(i) ? "selected" : "not selected");
  }

  // Show the dialog
  //
  TInfoDialog showSel(this, IDD_SHOWSELECT, count);
  showSel.Execute();
}

void
TClientWindow::CmShowSelStrings()
{
  // allocate an array of strings to receive data from the list view
  //
  char* bufferArray[MAX_ITEMS];
  for (int i = 0; i < ListWind->GetSelCount(); i++)
    bufferArray[i] = new char[MAX_CHARS];

  // fetch the strings from all selected items
  //
  int count = ListWind->GetSelStrings(bufferArray,
                MAX_ITEMS, MAX_CHARS);

  // copy the strings to the dialog's buffer
  //
  for (int i = 0; i < count; i++) {
    lstrcpy(TInfoDialog::strings[i], bufferArray[i]);
    delete [] bufferArray[i];
  }

  // show the dialog
  //
  TInfoDialog showSel(this, IDD_SHOWSELECT, count);
  showSel.Execute();
}

void
TClientWindow::CmSelectAll()
{
  ListWind->SetSelItemRange(true, 0, ListWind->GetItemCount() - 1);
}

void
TClientWindow::CmUnselect()
{
  int indexes[MAX_ITEMS];
  int count = ListWind->GetSelIndexes(indexes, MAX_ITEMS);
  ListWind->SetSelIndexes(indexes, count, false);
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
  GetMainWindow()->AssignMenu(IDM_MENU1);
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
