//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/treewind.h>
#include <owl/imagelst.h>
#include <classlib/pointer.h>
#include "treewind.rh"

const int TestImage  = 100;
const int TreeWindId = 101;

//
// Class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);

  protected:
    void SetupWindow();

#if defined(BI_PLAT_WIN32)
    void CmSetState();
    void CmGetState();

    // Event handlers
    //
    bool TvnItemExpanding(TTwNotify far& notify)
    {
      TTreeNode node(*TreeWind, notify.itemNew);
      return false;
    }
#endif

  private:

    // Data members
    //
    TPointer<TTreeWindow> TreeWind;
    TPointer<TImageList> ImageList;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
#if defined(BI_PLAT_WIN32)
  EV_TVN_ITEMEXPANDING(TreeWindId, TvnItemExpanding),
  EV_COMMAND(CM_SETSTATE, CmSetState),
  EV_COMMAND(CM_GETSTATE, CmGetState),
#endif
END_RESPONSE_TABLE;

TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent)
{
  // set client window style
  //
  uint32 style = GetStyle();
  SetStyle(style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

  // set treeview window style
  //
  style = TVS_HASLINES | TVS_HASBUTTONS;
#if defined(BI_PLAT_WIN32)
  style |= TVS_LINESATROOT;
#endif

  TreeWind = new TTreeWindow(this, TreeWindId, 10, 10, 400, 200, style);

  ImageList = 0;
#if defined(BI_PLAT_WIN32)
  ImageList = new TImageList(*GetApplication(), TResId(TestImage),
    20, 1, TColor(255, 255, 255), IMAGE_BITMAP, 0);
#endif
}


#if defined(BI_PLAT_WIN32)
void
TClientWindow::CmSetState()
{
  TreeWind->GetSelection().SetState(TVIS_BOLD);
}

void
TClientWindow::CmGetState()
{
  char buffer[1024];
  uint state;

  TTreeNode& node = TreeWind->GetSelection();
  node.GetState(state);
  if (state & TVIS_EXPANDED)
    lstrcpy(buffer, "Selected node is expanded.");
  else
    lstrcpy(buffer, "Selected node is not expanded.");
  MessageBox(buffer);
}
#endif

void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  // Initialize TreeWind
  //
  TTreeNode root = TreeWind->GetRoot();
  root.AddChild(TTreeNode(*TreeWind, "Child 8"));

  TTreeNode parent1 = root.AddChild(TTreeNode(*TreeWind, "Parent 1"));
  TTreeNode child1  = parent1.AddChild(TTreeNode(*TreeWind, "Child 1"));
                      parent1.AddChild(TTreeNode(*TreeWind, "Child 2 (with some longer text)"));

  root.AddChild(TTreeNode(*TreeWind, "Child 0"));

  TTreeNode parent2 = root.AddChild(TTreeNode(*TreeWind, "Parent 2"));
            parent2.AddChild(TTreeNode(*TreeWind, "Child 3"));
            parent2.AddChild(TTreeNode(*TreeWind, "Child 4"));

  TTreeNode subParent1 = child1.InsertItem(TTreeNode(*TreeWind, "Subparent 1"));
            subParent1.AddChild(TTreeNode(*TreeWind, "Child 5"));
            subParent1.AddChild(TTreeNode(*TreeWind, "Child 6"));

  root.AddChild(TTreeNode(*TreeWind, "Child 7"));

  TreeWind->Update();

  parent2.ExpandItem(TVE_EXPAND);
}

//----------------------------------------------------------------------------

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp() : TApplication(){};
    void InitMainWindow();
};

void
TSampleApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, 0, new TClientWindow);
  frame->SetMenuDescr(TMenuDescr(IDM_MAINMENU));
  SetMainWindow(frame);
  GetMainWindow()->SetCaption("TreeWindow class");
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
