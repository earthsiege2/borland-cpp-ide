//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.6  $
//
// Sample illustrating how to 'Execute' non-dialog windows 
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_BUTTON_H)
# include <owl/button.h>
#endif
#include "modalwin.h"

class TModalWindow : public TWindow {
  public:
    TModalWindow(TWindow* parent, char far* title, int flags = MB_APPLMODAL,
                 TModule* module=0);

    // Override DoExecute so we may implement App/Sys modal
    // NOTE: TWindow's Execute defaults to TASKMODAL
    //
    int  DoExecute();

  protected:
    // Message Handlers
    //
    void CmAppModalChild();
    void CmTaskModalChild();
    void CmSysModalChild();
    void CmCancel() { Destroy(IDCANCEL); }
    void EvSysCommand(uint cmdType, TPoint& point);

  private:
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
  SetAcceleratorTable(IDA_MODALWIN);
}

//
//
//
int 
TModalWindow::DoExecute()
{
  // NOTE: There's no real concept of SYSTEM MODAL windows in the 32-bit
  //       world. We're going to default to TASKMODAL for SYSTEM MODAL
  //       requests - For that we can just use TWindow's Execute support
  //
#if   defined(BI_PLAT_WIN16)
  if (ModalFlags & MB_TASKMODAL)
#elif defined(BI_PLAT_WIN32)
  if ((ModalFlags & MB_TASKMODAL) || (ModalFlags & MB_SYSTEMMODAL))
#endif
    return TWindow::DoExecute();

  else {
    if (GetApplication()) {
      if (Create()) {
        SetFlag(wfModalWindow);

        // NOTE: MB_APPLMODAL implies the first parameter points to the
        //       window to disable. Otherwise that parameter points to 
        //       the window to make modal.
        //
        TWindow* winparam = (ModalFlags & MB_SYSTEMMODAL) ? 
                            TYPESAFE_DOWNCAST(this, TWindow) : Parent;
        return GetApplication()->BeginModal(winparam, ModalFlags);
      }
    }
  }
  return -1;
}

//
//
//
void 
TModalWindow::EvSysCommand(uint cmdType, TPoint& point)
{
  if ((cmdType & 0xFFF0) == SC_CLOSE)
    Destroy(IDCANCEL);
  else
    TWindow::EvSysCommand(cmdType, point);
}

//
//
//
void 
TModalWindow::CmAppModalChild()
{
  TModalWindow* mw = new TModalWindow(this, "App Modal Child", MB_APPLMODAL);
  mw->Execute();
  delete mw;
}

//
//
//
void 
TModalWindow::CmTaskModalChild()
{
  TModalWindow* mw = new TModalWindow(this, "Task Modal Child", MB_TASKMODAL);
  mw->Execute();
  delete mw;
}

//
//
//
void 
TModalWindow::CmSysModalChild()
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
    void        InitMainWindow();
    void        CmMWAbout();
    void        CmDAbout();

  DECLARE_RESPONSE_TABLE(TModalApp);
};

DEFINE_RESPONSE_TABLE(TModalApp)
  EV_COMMAND(CM_MWABOUT, CmMWAbout),
  EV_COMMAND(CM_DABOUT,  CmDAbout),
END_RESPONSE_TABLE;

void
TModalApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Modal Windows");
  frame->AssignMenu(IDM_MODALWIN);
  frame->SetIcon(this, IDI_MODALWIN);
  SetMainWindow(frame);
}

//  About dialog box
//
void
TModalApp::CmMWAbout()
{
  // NOTE: Here we're defaulting to MB_APPLMODAL. 
  //
  TModalWindow(GetMainWindow(), "App Modal Window").Execute();
}

//
//
void
TModalApp::CmDAbout()
{
  TDialog(GetMainWindow(), IDD_ABOUT).Execute();
}


int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TModalApp().Run();
}
