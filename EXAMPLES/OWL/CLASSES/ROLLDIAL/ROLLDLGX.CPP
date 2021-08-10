//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    RollDlgX.cpp
//
// Date:         8-Jun-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/rolldial.h>
#include "RollDlgX.rh"

//
// class RollDlgXApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~~
class TRollDlgXApp : public TApplication {
  public:
    TRollDlgXApp()
    :
      TApplication()
    {
    }

    void InitMainWindow();
};


//
// class RollDlgXWindow
// ~~~~~ ~~~~~~~~~~~~~
class TRollDlgXWindow : public TWindow {
  public:
    TRollDlgXWindow()
    :
      TWindow(0, 0, 0)
    {
    }

  protected:
    void CmTest1Dialog();

  DECLARE_RESPONSE_TABLE(TRollDlgXWindow);
};

//
// class TTest1Dialog
// ~~~~~ ~~~~~~~~~~~~
class TTest1Dialog : public TRollDialog {
  public:
    TTest1Dialog(TWindow* parent, TResId resId, bool animated = true,
                 bool fullSize = true, TModule* module = 0)
    :
      TRollDialog(parent, resId, animated, fullSize, module)
    {
    }

    void EvLButtonDown(uint modKeys, TPoint& point) {
#if defined(BI_PLAT_WIN32)
      Reposition();
#endif
    }

  DECLARE_RESPONSE_TABLE(TTest1Dialog);
};

DEFINE_RESPONSE_TABLE1(TTest1Dialog, TRollDialog)
  EV_WM_LBUTTONDOWN,
END_RESPONSE_TABLE;


//
// Response table for RollDlgXWindow
//
DEFINE_RESPONSE_TABLE1(TRollDlgXWindow, TWindow)
  EV_COMMAND(CM_TEST1DIALOG, CmTest1Dialog),
END_RESPONSE_TABLE;


//
//
//
void
TRollDlgXWindow::CmTest1Dialog()
{
  TTest1Dialog* dialog = new TTest1Dialog(this, IDD_TEST1);
  dialog->SetFlag(wfDeleteOnClose);
  dialog->Create();
  dialog->Show(SW_SHOWNORMAL);
}


//
// InitMainWindow
//
void
TRollDlgXApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "RollDlgX application",
    new TRollDlgXWindow);
  frame->AssignMenu(IDM_MAINMENU);
  SetMainWindow(frame);
}


//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TRollDlgXApp app;
  return app.Run();
}

