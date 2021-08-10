//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/button.h>
#include "modalwin.h"

class TModalWindow : public TWindow {
  public:
    TModalWindow(TWindow* parent, char far* title, int flags = MB_APPLMODAL,
                 TModule* module=0);
    int Execute();
    void Destroy(int retValue);

  private:
    void CmAppModalChild();
    void CmTaskModalChild();
    void CmSysModalChild();
    void CmCancel() { Destroy(IDCANCEL); }
    void EvSysCommand(uint cmdType, TPoint& point);

    int ModalFlags;

  DECLARE_RESPONSE_TABLE(TModalWindow);
};
DEFINE_RESPONSE_TABLE1(TModalWindow, TWindow)
  EV_COMMAND(CM_APPMODAL_CHILD, CmAppModalChild),
  EV_COMMAND(CM_TASKMODAL_CHILD, CmTaskModalChild),
  EV_COMMAND(CM_SYSMODAL_CHILD, CmSysModalChild),
  EV_COMMAND(IDCANCEL, CmCancel),
  EV_WM_SYSCOMMAND,
END_RESPONSE_TABLE;

TModalWindow::TModalWindow(TWindow* parent, char far* title,
                           int flags, TModule* module)
  : TWindow(parent, title, module),
    ModalFlags(flags)
{
  new TButton(this, CM_APPMODAL_CHILD, "&AppModal", 5, 5, 80, 25);
  new TButton(this, CM_TASKMODAL_CHILD, "&TaskModal", 90, 5, 80, 25);
  new TButton(this, CM_SYSMODAL_CHILD, "&SysModal", 5, 35, 80, 25);
  new TButton(this, IDCANCEL, "&Close", 90, 35, 80, 25);
  Attr.Style &= ~WS_CHILD;
  Attr.Style |= WS_POPUPWINDOW | WS_CAPTION;
  Attr.ExStyle = WS_EX_DLGMODALFRAME;
  Attr.X = Parent->GetWindowRect().left+40;
  Attr.Y = Parent->GetWindowRect().top+60;
  Attr.W = 175 + 2*GetSystemMetrics(SM_CXDLGFRAME);
  Attr.H = 65 + 2*GetSystemMetrics(SM_CYDLGFRAME) + GetSystemMetrics(SM_CYCAPTION);
}

int TModalWindow::Execute()
{
  Create();
  return GetApplication()->BeginModal(
//    (ModalFlags & (MB_TASKMODAL | MB_SYSTEMMODAL)) ?
    (ModalFlags & (MB_TASKMODAL)) ?
      this :     // task,sys modal need this window
      Parent,    // app modal needs parent to disable
    ModalFlags);
}

void TModalWindow::Destroy(int result)
{
  GetApplication()->EndModal(result);
  TWindow::Destroy(result);
}

void TModalWindow::EvSysCommand(uint cmdType, TPoint& point)
{
  if ((cmdType & 0xFFF0) == SC_CLOSE)
    Destroy(IDCANCEL);
  else
    TWindow::EvSysCommand(cmdType, point);
}

void TModalWindow::CmAppModalChild()
{
  TModalWindow* mw = new TModalWindow(this, "App Modal Child", MB_APPLMODAL);
  mw->Execute();
  delete mw;
}

void TModalWindow::CmTaskModalChild()
{
  TModalWindow* mw = new TModalWindow(this, "Task Modal Child", MB_TASKMODAL);
  mw->Execute();
  delete mw;
}

void TModalWindow::CmSysModalChild()
{
  TModalWindow* mw = new TModalWindow(this, "Sys Modal Child", MB_SYSTEMMODAL);
  mw->Execute();
  delete mw;
}

//----------------------------------------------------------------------------


class TModalApp : public TApplication {
  public:
    TModalApp() : TApplication() {}

  private:
    void InitMainWindow();
    void CmMWAbout();
    void CmDAbout();

  DECLARE_RESPONSE_TABLE(TModalApp);
};

DEFINE_RESPONSE_TABLE(TModalApp)
  EV_COMMAND(CM_MWABOUT, CmMWAbout),
  EV_COMMAND(CM_DABOUT,  CmDAbout),
END_RESPONSE_TABLE;

void
TModalApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, "Modal Windows");
  MainWindow->AssignMenu("TOOL_MENU");
  MainWindow->SetIcon(this, "ICON_1");
}

//  About dialog box
//
void
TModalApp::CmMWAbout()
{
 TModalWindow(GetMainWindow(), "App Modal Window").Execute();
}

void
TModalApp::CmDAbout()
{
  TDialog(GetMainWindow(), "IDD_ABOUT").Execute();
}


int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TModalApp().Run();
}
