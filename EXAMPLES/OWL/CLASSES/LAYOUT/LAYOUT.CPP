//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
// Program Description:
//  Interactive program to demonstrate TLayout window.  It creates
//  a frame window, colored child windows and a client window.
//
//  The menu choice lets you bring up a dialog to let you set values for a
//  TLayoutMetrics structure for the various child windows (the dialog is
//  modeless, so you can layout several windows at the same time).
//  A TLayoutMetrics (declared in layoutwi.h) has four TLayoutConstraints
//  in it, X, Y, Width and Height.  When the dialog comes up, you choose
//  which constraint you want to select, then set the various members of
//  that constraint.
//  There are some constraints that you don't do with layout windows.
//  For example, if you constrain the lmWidth edges of a X constraint, it
//  will cause a error.  (The lmWidth edge is best constrained through the
//  Width constraint).
//
//  Functionality Demonstrated:
//   OWL:  Low level use of TLayoutWindow and TLayoutMetrics
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/framewin.h>
#include <owl/applicat.h>
#include <owl/layoutwi.h>
#include "layout.rh"
#include "layout.h"
#include "laydia.h"

TMyChildWindow::TMyChildWindow(TWindow* parent, int id, char far* title,
                               TColor color)
:
  TWindow(parent, title)
{
  SetBkgndColor(color);
  Attr.Style = WS_CHILD | WS_BORDER | WS_VISIBLE | WS_TABSTOP | WS_CLIPSIBLINGS;
  Attr.Id = id;
  static int i = 0;
  Attr.X = 10 + i++ * 100;
  Attr.Y = 10;
  Attr.W = 100;
  Attr.H = 100;
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TMyLayout, TLayoutWindow)
  EV_COMMAND(CM_LAYOUT, CmLayout),
  EV_COMMAND(CM_RELAYOUT, CmReLayout),
END_RESPONSE_TABLE;

TMyLayout::TMyLayout(TWindow* parent)
:
  TLayoutWindow(parent, 0)
{
  Attr.Style |= WS_BORDER;

  static TColor ChildColor[] = {
    RGB(0xFF, 0x00, 0x00),
    RGB(0x00, 0xFF, 0x00),
    RGB(0x00, 0x00, 0xFF),
    RGB(0xFF, 0xFF, 0x00),
    RGB(0x00, 0xFF, 0xFF),
    RGB(0xFF, 0x00, 0xFF),
  };
  static char* ChildName[] = {
    "Red",
    "Green",
    "Blue",
    "Yellow",
    "Cyan",
    "Magenta",
  };

  int i = 0;
  for (; i < MaxChildren; i++)
    ChildInfo[i].Child = new TMyChildWindow(this, i+1, ChildName[i], ChildColor[i]);
  ChildInfo[i].Child = 0;

  LayoutDialog = new TLayoutDialog(this, "IDD_LAYOUT", ChildInfo);

}

void
TMyLayout::CmLayout()
{
  // Only one layout dialog at a time please
  //
  if (!LayoutDialog->GetHandle())
    LayoutDialog->Create();
}

//
// Re-layout all of the children. Not really needed
//
void
TMyLayout::CmReLayout()
{
  for (int i = 0; i < MaxChildren; i++)
    SetChildLayoutMetrics(*ChildInfo[i].Child, ChildInfo[i].LayoutMetrics);
  try {
    Layout();
  }
  catch (TXOwl& exception) {
    MessageBox(exception.why().c_str(), "Exception");
  }
}

void
TMyLayout::SetupWindow()
{
  TLayoutWindow::SetupWindow();
  PostMessage(WM_COMMAND, CM_RELAYOUT);
}

//
// class TLayoutApp
// ~~~~~ ~~~~~~~~~~
class TLayoutApp : public TApplication {
  public:
    void InitMainWindow() {
      TFrameWindow* frame = new TFrameWindow(0, "Layout Window", new TMyLayout(0));
      frame->AssignMenu(IDM_LAYOUT);
      SetMainWindow(frame);
    }
};

int
OwlMain(int, char**)
{
  return TLayoutApp().Run();
}
