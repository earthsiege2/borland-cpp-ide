//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/treewind.h>
#include <owl/imagelst.h>

const int TestImage  = 100;
const int TreeWindId = 101;

//
// Class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);
   ~TClientWindow();

  protected:
    void SetupWindow();

#if defined(BI_PLAT_WIN32)
    // Event handlers
    //
    bool TvnItemExpanding(TTwNotify far&)
    {
      MessageBeep(-1);
      return false;
    }
#endif

    // Data members
    //
    TTreeWindow* TreeWind;
    TImageList* ImageList;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
#if defined(BI_PLAT_WIN32)
  EV_TVN_ITEMEXPANDING(TreeWindId, TvnItemExpanding),
#endif
END_RESPONSE_TABLE;

TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent)
{
  Attr.Style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

  TTreeWindow::TStyle style = TTreeWindow::TStyle(TTreeWindow::twsHasLines | TTreeWindow::twsHasButtons);
#if defined(BI_PLAT_WIN32)
  style = TTreeWindow::TStyle(style | TTreeWindow::twsLinesAtRoot);
#endif

  TreeWind = new TTreeWindow(this, TreeWindId, 10, 10, 400, 200, style);

  ImageList = 0;
#if defined(BI_PLAT_WIN32)
  ImageList = new TImageList(*GetApplication(), TResId(TestImage),
    20, 1, TColor(255, 255, 255), IMAGE_BITMAP, 0);
#endif
}

TClientWindow::~TClientWindow()
{
  delete ImageList;
}

void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  // Initialize TreeWind
  //
  TTreeNode root = TreeWind->GetRoot();
  root.AddChild(TTreeItem("Child 8"));

  TTreeNode parent1 = root.AddChild(TTreeItem("Parent 1"));
  TTreeNode child1  = parent1.AddChild(TTreeItem("Child 1"));
                      parent1.AddChild(TTreeItem("Child 2 (with some longer text)"));

  root.AddChild(TTreeItem("Child 0"));

  TTreeNode parent2 = root.AddChild(TTreeItem("Parent 2"));
            parent2.AddChild(TTreeItem("Child 3"));
            parent2.AddChild(TTreeItem("Child 4"));

  TTreeNode subParent1 = child1.InsertItem(TTreeItem("Subparent 1"));
            subParent1.AddChild(TTreeItem("Child 5"));
            subParent1.AddChild(TTreeItem("Child 6"));

  root.AddChild(TTreeItem("Child 7"));


//  TTreeNode child(root, TTreeNode::Child);
//            child = child.GetNextSibling();

  TreeWind->Update();

  parent2.ExpandItem(TTreeNode::Expand);
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
  SetMainWindow(new TFrameWindow(0, 0, new TClientWindow));
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
