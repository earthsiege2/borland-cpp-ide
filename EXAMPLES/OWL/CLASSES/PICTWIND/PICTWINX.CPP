//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/gdiobjec.h>
#include <owl/pictwind.h>
#include "pictwind.rh"

const char* Picture = "sample.bmp";

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp()
    {
      CurrentHow = TPictureWindow::Center;
    }

    void InitMainWindow();

    void CmCenter()
    {
      CurrentHow = TPictureWindow::Center;
      NewClient(TPictureWindow::Center);
    }
    void CeCenter(TCommandEnabler& ce);

    void CmUpperLeft()
    {
      CurrentHow = TPictureWindow::UpperLeft;
      NewClient(TPictureWindow::UpperLeft);
    }
    void CeUpperLeft(TCommandEnabler& ce);

    void CmStretch()
    {
      CurrentHow = TPictureWindow::Stretch;
      NewClient(TPictureWindow::Stretch);
    }
    void CeStretch(TCommandEnabler& ce);

    void NewClient(TPictureWindow::TDisplayHow how);

  private:
    TPictureWindow::TDisplayHow CurrentHow;

  DECLARE_RESPONSE_TABLE(TSampleApp);
};

void
TSampleApp::CeCenter(TCommandEnabler& ce)
{
  ce.SetCheck(CurrentHow == TPictureWindow::Center?
              TCommandEnabler::Checked :
              TCommandEnabler::Unchecked);
}

void
TSampleApp::CeUpperLeft(TCommandEnabler& ce)
{
  ce.SetCheck(CurrentHow == TPictureWindow::UpperLeft ?
              TCommandEnabler::Checked :
              TCommandEnabler::Unchecked);
}

void
TSampleApp::CeStretch(TCommandEnabler& ce)
{
  ce.SetCheck(CurrentHow == TPictureWindow::Stretch ?
              TCommandEnabler::Checked :
              TCommandEnabler::Unchecked);
}


DEFINE_RESPONSE_TABLE1(TSampleApp, TApplication)
  EV_COMMAND       (CM_CENTER,    CmCenter),
  EV_COMMAND_ENABLE(CM_CENTER,    CeCenter),
  EV_COMMAND       (CM_UPPERLEFT, CmUpperLeft),
  EV_COMMAND_ENABLE(CM_UPPERLEFT, CeUpperLeft),
  EV_COMMAND       (CM_STRETCH,   CmStretch),
  EV_COMMAND_ENABLE(CM_STRETCH,   CeStretch),
END_RESPONSE_TABLE;

void
TSampleApp::NewClient(TPictureWindow::TDisplayHow how)
{
  TWindow* cw = new TPictureWindow(0, new TDib(Picture), how);
  cw->Attr.ExStyle |= WS_EX_CLIENTEDGE;

  TWindow* oldClient = GetMainWindow()->SetClientWindow(cw);

  delete oldClient;
}

void
TSampleApp::InitMainWindow()
{
  TWindow* cw = new TPictureWindow(0, new TDib(Picture), TPictureWindow::Center);
  cw->Attr.ExStyle |= WS_EX_CLIENTEDGE;

  // create main window
  //
  SetMainWindow(new TFrameWindow(0, "Picture Window", cw));
  GetMainWindow()->AssignMenu(IDM_MAINMENU);
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
