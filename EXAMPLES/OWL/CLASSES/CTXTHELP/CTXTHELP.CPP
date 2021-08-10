//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_HLPMANAG_H)
# include <owl/hlpmanag.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#include "CtxtHelp.rh"
#include "HelpIds.hh"

//
// class CtxtHelpApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~~
class TCtxtHelpApp : public TApplication, public THelpFileManager {
  public:
    TCtxtHelpApp(const char* name)
    :
      TApplication(name),
      THelpFileManager("testhelp.hlp") { }

   ~TCtxtHelpApp() { }

    void InitMainWindow();

  DECLARE_RESPONSE_TABLE(TCtxtHelpApp);
};

//
// class TCtxtDialog
// ~~~~~ ~~~~~~~~~~~
class TCtxtDialog : public TDialog {
  public:
    TCtxtDialog(TWindow* parent, TResId id, TModule* module = 0)
    :
      TDialog(parent, id, module) { }

   ~TCtxtDialog() { }

    void  SetupWindow();
    void  CleanupWindow();

  DECLARE_HELPCONTEXT(TCtxtDialog);
};

//
//
//
void
TCtxtDialog::SetupWindow()
{
  TDialog::SetupWindow();
  SETUP_HELPCONTEXT(TCtxtHelpApp, TCtxtDialog);
}

//
//
//
void
TCtxtDialog::CleanupWindow()
{
  CLEANUP_HELPCONTEXT(TCtxtHelpApp, TCtxtDialog);
  TDialog::CleanupWindow();
}


DEFINE_HELPCONTEXT(TCtxtDialog)
  HCENTRY_CONTROL(IDH_IDC_NAME,   IDC_NAME),
  HCENTRY_CONTROL(IDH_IDC_PHONE,  IDC_PHONE),
  HCENTRY_CONTROL(IDH_IDC_NUMBER, IDC_NUMBER),
  HCENTRY_CONTROL(IDH_IDOK,       IDOK),
  HCENTRY_CONTROL(IDH_IDCANCEL,   IDCANCEL),
  HCENTRY_CONTROL(IDH_IDHELP,     IDHELP),
END_HELPCONTEXT;


//
// class CtxtHelpWindow
// ~~~~~ ~~~~~~~~~~~~~
class TCtxtHelpWindow : public TWindow {
  public:
    TCtxtHelpWindow() : TWindow(0, 0, 0) {}
   ~TCtxtHelpWindow() {}

    void  SetupWindow();
    void  CleanupWindow();
    void  CmDummy();
    void  CmDialog();

  DECLARE_RESPONSE_TABLE(TCtxtHelpWindow);
  DECLARE_HELPCONTEXT(TCtxtHelpWindow);
};


//
// SetupWindow
//
void
TCtxtHelpWindow::SetupWindow()
{
  TWindow::SetupWindow();
  SETUP_HELPCONTEXT(TCtxtHelpApp, TCtxtHelpWindow);
}


//
// CleanupWindow
//
void
TCtxtHelpWindow::CleanupWindow()
{
  CLEANUP_HELPCONTEXT(TCtxtHelpApp, TCtxtHelpWindow);
  TWindow::CleanupWindow();
}

//
//
//
void
TCtxtHelpWindow::CmDummy()
{
  MessageBox("Not currently implemented");
}

//
//
//
void
TCtxtHelpWindow::CmDialog()
{
  TCtxtDialog dialog(this, IDD_DIALOG);
  dialog.Execute();
}

//
// Response table for CtxtHelpWindow
//
DEFINE_RESPONSE_TABLE1(TCtxtHelpWindow, TWindow)
  EV_COMMAND(CM_POPUPAITEM1, CmDummy),
  EV_COMMAND(CM_POPUPBITEM2, CmDummy),
  EV_COMMAND(CM_DIALOG, CmDialog),
END_RESPONSE_TABLE;

DEFINE_HELPCONTEXT(TCtxtHelpWindow)
  HCENTRY_MENU(IDH_CM_POPUPAITEM1, CM_POPUPAITEM1),
  HCENTRY_MENU(IDH_CM_POPUPBITEM2, CM_POPUPBITEM2),
  HCENTRY_MENU(IDH_CM_DIALOG,      CM_DIALOG),
END_HELPCONTEXT;

//
// InitMainWindow
//
void
TCtxtHelpApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Context-sensitive help application",
    new TCtxtHelpWindow);
  frame->AssignMenu(IDM_MAINMENU);
  SetMainWindow(frame);
}

DEFINE_RESPONSE_TABLE2(TCtxtHelpApp, THelpFileManager, TApplication)
END_RESPONSE_TABLE;

//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TCtxtHelpApp app("CTXTHELP");
  return app.Run();
}

