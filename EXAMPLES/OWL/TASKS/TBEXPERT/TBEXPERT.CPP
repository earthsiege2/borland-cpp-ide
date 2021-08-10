//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    TBExpert.cpp
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <classlib/arrays.h>
#include <dir.h>
#include <cstring.h>
#include "TBExpert.h"

const TSize KnownToolSize(30, 20);
const TSize TargetSize(20, 20);
const int MaxFilesInDir = 1000;

//
// TBExpertWindow constructor
//
TTBExpertWindow::TTBExpertWindow()
:
  TLayoutWindow(0, 0, 0),
  DragImage(0),
  KnownImageList(0),
  DynamicImageList(0),
  DragListWindow(0),
  DragItem(0)
{
  Attr.Style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

  KnownListWindow = new TListWindow(this, KnownListWindowId, 40, 40, 400, 200);
  KnownListWindow->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_ICON | LVS_AUTOARRANGE;
  TLayoutMetrics lmKnownListWindow;
  lmKnownListWindow.X.SameAs(lmParent, lmLeft);
  lmKnownListWindow.Y.SameAs(lmParent, lmTop);
  lmKnownListWindow.Width.Absolute(TEdge(lmParent), 80);
  lmKnownListWindow.Height.PercentOf(lmParent, 40);
  SetChildLayoutMetrics(*KnownListWindow, lmKnownListWindow);

  DynamicListWindow = new TListWindow(this, DynamicListWindowId, 40, 40, 400, 200);
  DynamicListWindow->Attr.Style |= LVS_SHAREIMAGELISTS | LVS_ICON | LVS_AUTOARRANGE;
  TLayoutMetrics lmDynamicListWindow;
  lmDynamicListWindow.X.SameAs(lmParent, lmLeft);
  lmDynamicListWindow.Y.Below(KnownListWindow, 1);
  lmDynamicListWindow.Width.SameAs(KnownListWindow, lmWidth);
  lmDynamicListWindow.Height.PercentOf(lmParent, 60);
  SetChildLayoutMetrics(*DynamicListWindow, lmDynamicListWindow);

  GadgetManagerHolder = new TGadgetManagerPlaceHolder(this);
  TLayoutMetrics lmGadgetManagerPlaceHolder;
  lmGadgetManagerPlaceHolder.X.RightOf(KnownListWindow, 1);
  lmGadgetManagerPlaceHolder.Y.SameAs(lmParent, lmTop);
  lmGadgetManagerPlaceHolder.Width.SameAs(lmParent, lmRight);
  lmGadgetManagerPlaceHolder.Height.Absolute(50);
  SetChildLayoutMetrics(*GadgetManagerHolder, lmGadgetManagerPlaceHolder);

  StatusManager = new TStatusManager(this);
  TLayoutMetrics lmStatusManager;
  lmStatusManager.X.RightOf(DynamicListWindow, 1);
  lmStatusManager.Y.Below(GadgetManagerHolder, 1);
  lmStatusManager.Width.SameAs(lmParent, lmRight);
  lmStatusManager.Height.SameAs(lmParent, lmBottom);
  SetChildLayoutMetrics(*StatusManager, lmStatusManager);
}


//
// TBExpertWindow destructor
//
TTBExpertWindow::~TTBExpertWindow()
{
  delete KnownImageList;
  delete DynamicImageList;
}


//
// SetupWindow
//
void
TTBExpertWindow::SetupWindow()
{
  TLayoutWindow::SetupWindow();

  // put new stuff here
  //
  SetupKnownListWindow();
  SetDynamicDir(".");
  StatusManager->SetDragStatus(TStatusManager::BeforeDrag);
}


//
// CleanupWindow
//
void
TTBExpertWindow::CleanupWindow()
{
  // put new stuff here
  //

  TLayoutWindow::CleanupWindow();
}

//
// Response table for TBExpertWindow
//
DEFINE_RESPONSE_TABLE1(TTBExpertWindow, TLayoutWindow)
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
  EV_LVN_BEGINDRAG(KnownListWindowId,   LvnKnownBeginDrag),
  EV_LVN_BEGINDRAG(DynamicListWindowId, LvnDynamicBeginDrag),
  EV_MESSAGE(WUM_DONEMODIFYINGGADGET, EvDoneModifyingGadget),
END_RESPONSE_TABLE;

void
TTBExpertWindow::SetupKnownListWindow()
{
  struct {
    char* Name;
    int   Id;
  } knownGadgets[] = {
    { "Separator", IDB_SEPARATOR },
    { "Mode",      IDB_MODE },
    { "Time",      IDB_TIME },
    { "Text",      IDB_TEXT },
  };

  if (DynamicListWindow && DynamicListWindow->IsWindow()) {
    KnownListWindow->DeleteAllItems();
    delete KnownImageList;
    KnownImageList = new TImageList(KnownToolSize, ILC_COLOR4, 15, 5);

    for (int i = 0; i < sizeof knownGadgets/sizeof knownGadgets[0]; i++)
      KnownImageList->Add(TBitmap(*GetApplication(), knownGadgets[i].Id));

    KnownListWindow->SetImageList(*KnownImageList, TListWindow::Normal);

    for (int i = 0; i < sizeof knownGadgets/sizeof knownGadgets[0]; i++) {
      TListWindItem item(knownGadgets[i].Name);
      item.SetImageIndex(i);
      KnownListWindow->InsertItem(item);
    }
  }
}

void
TTBExpertWindow::SetDynamicDir(const char* dir)
{
  if (DynamicListWindow && DynamicListWindow->IsWindow()) {
    DynamicListWindow->DeleteAllItems();
    delete DynamicImageList;

    DynamicImageList = new TImageList(TargetSize, ILC_COLOR4, 15, 5);

    TSArrayAsVector<string> files(MaxFilesInDir);

    // read .bmp file names into a sorted array
    //
    strcpy(CurrentDir, dir);
    chdir(dir);
    ffblk ff;
    bool done = findfirst("*.bmp", &ff, 0);
    while (!done) {
      TDib dib(ff.ff_name);
      if (dib.Size() == TargetSize)
        files.Add(string(ff.ff_name));
      done = findnext(&ff);
    }

    // add each .bmp into the image list
    //
    TSArrayAsVectorIterator<string> iter(files);
    while (iter) {
      string f = iter.Current();
      DynamicImageList->Add(TBitmap(TDib(f.c_str())));
      iter++;
    }

    // set the image list
    //
    DynamicListWindow->SetImageList(*DynamicImageList, TListWindow::Normal);

    // add the items into the list window
    //
    iter.Restart();
    int index = 0;
    static char buffer[MAXFILE];
    while (iter) {
      string f = iter.Current();
      strcpy(buffer, f.c_str());
      strlwr(buffer);
      TListWindItem item(buffer);
      item.SetImageIndex(index++);
      DynamicListWindow->InsertItem(item);
      iter++;
    }
  }
}


void
TTBExpertWindow::EvLButtonUp(uint modKeys, TPoint& point)
{
  TWindow::EvLButtonUp(modKeys, point);
  if (DragImage != 0) {
    StatusManager->SetDragStatus(TStatusManager::EndDrag);
    ReleaseCapture();
    TImageList::DragLeave(*this);
    TImageList::EndDrag();
    delete DragImage;
    DragImage = 0;
    ShowCursor(true);

    TPoint curPos;
    GetCursorPos(curPos);
    TRect GadgetManagerRect = GadgetManagerHolder->GetWindowRect();
    if (GadgetManagerRect.Contains(curPos)) {
      char buffer[MAXFILE];
      TListWindItem item(buffer, 0, MAXFILE);
      item.SetIndex(DragItem);
      DragListWindow->GetItem(item);
      GadgetDropped(DragListWindow, buffer, DragItem);
    }
    DragListWindow = 0;
    DragItem = 0;
    StatusManager->SetDragStatus(TStatusManager::BeforeDrag);
  }
}

void
TTBExpertWindow::GadgetDropped(TListWindow* window, char* gadgetName, int /*item*/)
{
  if (CountOfGadgetFactories >= MaxGadgetFactories) {
    MessageBox("Too many gadgets", "Error");
    return;
  }

  TGadgetFactory* newFactory = 0;
  if (window->GetId() == KnownListWindowId) {
    if (strcmpi(gadgetName, "Separator") == 0) {
      newFactory = new TGadgetFactory(0, TGadget::None, 6);
    }
    else if (strcmpi(gadgetName, "Mode") == 0) {
      newFactory = new TGadgetFactory(0, TGadget::Recessed, VK_CONTROL, "Ctrl");
    }
    else if (strcmpi(gadgetName, "Time") == 0) {
      newFactory = new TGadgetFactory(0, TGadget::Recessed);
    }
    else if (strcmpi(gadgetName, "Text") == 0) {
      newFactory = new TGadgetFactory(0, TGadget::Recessed, TTextGadget::Left, 6, "Text");
    }
  }
  else {
    char buffer[MAXPATH];
    strcpy(buffer, CurrentDir);
    strcat(buffer, "\\");
    strcat(buffer, gadgetName);
    newFactory = new TGadgetFactory(0, TGadget::None, TButtonGadget::Command,
                                   TButtonGadget::Up, buffer);
  }

  if (newFactory != 0) {
    GadgetFactories[CountOfGadgetFactories] = newFactory;
    CountOfGadgetFactories++;
  }
  // Remove old gadget manager and create a new one
  // Rely on the creation of the gadget manager to simulate adding
  // gadgets
  //
  GadgetManagerHolder->CreateGadgetManager();
}


TResult
TTBExpertWindow::EvDoneModifyingGadget(TParam1, TParam2)
{
  GadgetManagerHolder->CreateGadgetManager();
//  StatusManager->SetDragStatus(TStatusManager::BeforeDrag);
  return 0;
}


void
TTBExpertWindow::EvMouseMove(uint /*modKeys*/, TPoint& point)
{
  if (DragImage != 0) {
    StatusManager->SetDragStatus(TStatusManager::Dragging);
    TImageList::DragMove(point.x + DragOffset.left, point.y + DragOffset.top);
  }
}

void
TTBExpertWindow::LvnKnownBeginDrag(TLwNotify& notify)
{
  StatusManager->SetDragStatus(TStatusManager::BeginDrag);
  LvnBeginDrag(KnownListWindow, notify);
}

void
TTBExpertWindow::LvnDynamicBeginDrag(TLwNotify& notify)
{
  LvnBeginDrag(DynamicListWindow, notify);
}

void
TTBExpertWindow::LvnBeginDrag(TListWindow* listWind, TLwNotify& notify)
{
  DragListWindow = listWind;
  DragItem       = notify.iItem;
  TPoint point;
  DragImage = new TImageList(listWind->CreateDragImage(DragItem, &point));

  listWind->GetItemRect(notify.iItem, &DragOffset, TListWindow::Bounds);
  DragImage->BeginDrag(0, point.x, point.y);
  SetCapture();
  ShowCursor(false);
  TImageList::DragEnter(*this, point.x, point.y);
}
