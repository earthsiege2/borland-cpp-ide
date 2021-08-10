//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
//
// Illustrates usage of TAnimateCtl class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/animctrl.h>
#include "animctl.h"

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void InitMainWindow();
};

//
// class TAnimDialog
// ~~~~~ ~~~~~~~~~~~
//
class TAnimDialog : public TDialog {
  public:
    TAnimDialog(TWindow* parent, TResId res = TResId(IDD_ANIMATE));

    void            ButtonClicked(uint btnId);
    void            ButtonEnabler(TCommandEnabler& ce);

  protected:
    bool            Playing;
    TAnimateCtrl*   AnimCtrl;
    
  DECLARE_RESPONSE_TABLE(TAnimDialog);
};

//
// Dialog's response table
//
DEFINE_RESPONSE_TABLE1(TAnimDialog, TDialog)
  EV_COMMAND_AND_ID(IDC_REWIND, ButtonClicked),
  EV_COMMAND_AND_ID(IDC_STOP, ButtonClicked),
  EV_COMMAND_AND_ID(IDC_PLAY, ButtonClicked),
  EV_COMMAND_AND_ID(IDC_FORWARD, ButtonClicked),
  EV_COMMAND_ENABLE(IDC_REWIND, ButtonEnabler),
  EV_COMMAND_ENABLE(IDC_STOP, ButtonEnabler),
  EV_COMMAND_ENABLE(IDC_PLAY, ButtonEnabler),
  EV_COMMAND_ENABLE(IDC_FORWARD, ButtonEnabler),
END_RESPONSE_TABLE;

//
// Constructor of animation dialog: Create AnimCtl object to alias control
//
TAnimDialog::TAnimDialog(TWindow* parent, TResId res) :
             TDialog(parent, res), Playing(false)
{
  AnimCtrl = new TAnimateCtrl(this, IDC_ANIMATE);
}

//
// Responds to BN_CLICK notifications from buttons
//
void
TAnimDialog::ButtonClicked(uint btnId)
{
  switch (btnId) {
    case IDC_REWIND:  AnimCtrl->Seek(0);            
                      break;

    case IDC_STOP:    AnimCtrl->Stop();             
                      Playing = false;
                      break;

    case IDC_PLAY:    AnimCtrl->Play(0, -1, -1);    
                      Playing = true;
                      break;

    case IDC_FORWARD: AnimCtrl->Seek(USHRT_MAX);   
                      break;
  }
}

//
// Responds to command enablers for buttons
//
void
TAnimDialog::ButtonEnabler(TCommandEnabler& ce)
{
  switch (ce.GetId()) {
    case IDC_STOP:    ce.Enable(Playing);   break;
    case IDC_PLAY:    ce.Enable(!Playing);  break;
    case IDC_REWIND:  ce.Enable(!Playing);  break;
    case IDC_FORWARD: ce.Enable(!Playing);  break;
  }
}

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);

  protected:

    // Message Handlers
    //
    void        EvSize(uint, TSize&);

    // Command handlers
    //
    void        CmAnimate();
    void        CeAnimate(TCommandEnabler& ce);
    void        CmStop();
    void        CeStop(TCommandEnabler& ce);
    void        CmDialog();

    // State info.
    //
    bool        Playing;

    TAnimateCtrl* AnimateCtrl;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};


//
// Response table of client window
//
DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_COMMAND(CM_ANIMATE, CmAnimate),
  EV_COMMAND(CM_STOP, CmStop),
  EV_COMMAND_ENABLE(CM_ANIMATE, CeAnimate),
  EV_COMMAND_ENABLE(CM_STOP, CeStop),
  EV_COMMAND(CM_DIALOG, CmDialog),
  EV_WM_SIZE,
END_RESPONSE_TABLE;

//
// Client window: Contains an animation control
//
TClientWindow::TClientWindow(TWindow* parent) : TWindow(parent), 
                                                Playing(false)
{
  ModifyStyle(0, WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
  AnimateCtrl = new TAnimateCtrl(this, 0x100, 0, 0, 0, 0);
};


//
// WM_SIZE Handler: Layout animation control within client window
//
void
TClientWindow::EvSize(uint, TSize& size)
{
  if (AnimateCtrl && AnimateCtrl->IsWindow())
    AnimateCtrl->MoveWindow(0, 0, size.cx, size.cy);
}

//
// Animate the in the client window
//
void
TClientWindow::CmAnimate()
{
  if (AnimateCtrl->Open(MAKEINTRESOURCE(SAMPLE_ONE))) {

    // Play from beginning(0) to end(-1), indefinitely(-1)
    //
    AnimateCtrl->Play(0, -1, -1);
    Playing = true;
  }
  else {
    MessageBox("Unable to open AVI resource", "Error");
  }
}

//
// Enable 'ANIMATE' option is not currently playing
//
void
TClientWindow::CeAnimate(TCommandEnabler& ce)
{
  ce.Enable(!Playing);
}


//
// Stop any animation
//
void
TClientWindow::CmStop()
{
  AnimateCtrl->Stop();
  Playing = false;
}

//
// Enable STOP if currently playing
//
void
TClientWindow::CeStop(TCommandEnabler& ce)
{
  ce.Enable(Playing == true);
}

//
// Display a dialog containing an animation control
//
void
TClientWindow::CmDialog()
{
  TAnimDialog(this).Execute();
}


//
// Set Main window object
//
void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, "Animation", new TClientWindow()));
  GetMainWindow()->AssignMenu(IDM_APPMENU);
}

//
// Entry point of application
//
int
OwlMain(int, char*[])
{
  return TSampleApp().Run();
}
