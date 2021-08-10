//----------------------------------------------------------------------------
//  ObjectWindows - (C) Copyright 1994 by Borland International
//    Command-enabling sample application
//    Fourth version adds a tool bar.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include "cmdenabl.h"
#include <owl/decframe.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/statusba.h>

//  Class definitions:
//  TCmdEnableApp -- application object initializes TApplication, overrides
//    InitMainWindow.
class TCmdEnableApp : public TApplication
{
  public:
    TCmdEnableApp() : TApplication() {}
  protected:
    void InitMainWindow();
};

//  TCmdEnableWindow -- window object initializes TWindow, adds four event
//    handlers, adds response table for four events.
class TCmdEnableWindow : public TWindow {
  public:
    TCmdEnableWindow(TWindow* parent = 0);

  protected:
    bool isDirty;
    bool isNewFile;

    // Event handlers
    void CmFileNew();
    void CmFileOpen();
    void CmFileSave();
    void CmFileSaveAs();
    void CmToggleDirty();
    void CmToggleNew();
    void CmShowState();

    // Command-enabling functions
    void CeFileNew(TCommandEnabler&);
    void CeFileOpen(TCommandEnabler&);
    void CeFileSave(TCommandEnabler&);
    void CeToggleDirty(TCommandEnabler&);
    void CeToggleNew(TCommandEnabler&);

    DECLARE_RESPONSE_TABLE(TCmdEnableWindow);
};

DEFINE_RESPONSE_TABLE1(TCmdEnableWindow, TWindow)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_TOGGLEDIRTY, CmToggleDirty),
  EV_COMMAND(CM_TOGGLENEW, CmToggleNew),
  EV_COMMAND(CM_SHOWSTATE, CmShowState),
  EV_COMMAND_ENABLE(CM_FILENEW, CeFileNew),
  EV_COMMAND_ENABLE(CM_FILEOPEN, CeFileOpen),
  EV_COMMAND_ENABLE(CM_FILESAVE, CeFileSave),
  EV_COMMAND_ENABLE(CM_TOGGLEDIRTY, CeToggleDirty),
  EV_COMMAND_ENABLE(CM_TOGGLENEW, CeToggleNew),
END_RESPONSE_TABLE;

// Put the OwlMain here just to get it out of the way
int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TCmdEnableApp().Run();
}

//  Class function definitions
//  class TCmdEnableApp
//  TCmdEnableApp::InitMainWindow
void
TCmdEnableApp::InitMainWindow()
{
  // Construct the decorated frame window
  TDecoratedFrame* frame = new TDecoratedFrame(0, "Command-enabling sample application", new TCmdEnableWindow, true);

  // Construct a control bar
  TControlBar *cb = new TControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILESAVEAS, CM_FILESAVEAS, TButtonGadget::Command));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_TOGGLEDIRTY, CM_TOGGLEDIRTY, TButtonGadget::NonExclusive));
  cb->Insert(*new TButtonGadget(CM_TOGGLENEW, CM_TOGGLENEW, TButtonGadget::NonExclusive));
  cb->Insert(*new TButtonGadget(CM_SHOWSTATE, CM_SHOWSTATE, TButtonGadget::Command));

  // Turn hints on to fly-over
  cb->SetHintMode(TGadgetWindow::EnterHints);

  // Create a status bar
  TStatusBar *sb = new TStatusBar(frame);

  // Insert the control bar and status bar into the frame
  frame->Insert(*cb, TDecoratedFrame::Top);
  frame->Insert(*sb, TDecoratedFrame::Bottom);

  // Set the main window and its menu
  SetMainWindow(frame);
  GetMainWindow()->AssignMenu("COMMANDS");
}

TCmdEnableWindow::TCmdEnableWindow(TWindow *parent) : TWindow(parent)
{
  isNewFile = true;
  isDirty = false;
}

void
TCmdEnableWindow::CmFileNew()
{
  isDirty=false;
  isNewFile=true;
  MessageBox("Opened a new file.\nisDirty=false\nisNewFile=true", "File action taken");
}

void
TCmdEnableWindow::CmFileOpen()
{
  isDirty=false;
  isNewFile=false;
  MessageBox("Opened an existing file.\nisDirty=false\nisNewFile=false", "File action taken");
}

void
TCmdEnableWindow::CmFileSave()
{
  isDirty=false;
  isNewFile=false;
  MessageBox("Saved an existing file.\nisDirty=false\nisNewFile=false", "File action taken");
}

void
TCmdEnableWindow::CmFileSaveAs()
{
  isDirty=false;
  isNewFile=false;
  MessageBox("Saved a file under a new name.\nisDirty=false\nisNewFile=false", "File action taken");
}

void
TCmdEnableWindow::CmToggleDirty()
{
  isDirty=!isDirty;
}

void
TCmdEnableWindow::CmToggleNew()
{
  isNewFile=!isNewFile;
}


void
TCmdEnableWindow::CmShowState()
{
  string str(isDirty ? "isDirty = true\n" : "isDirty = false\n");
  str += (isNewFile ? "isNewFile = true" : "isNewFile = false");
  MessageBox(str.c_str(), "Current state");
}

void
TCmdEnableWindow::CeFileNew(TCommandEnabler& ce)
{
  // Enable CmFileNew if not dirty
  ce.Enable(!isDirty);
}

void
TCmdEnableWindow::CeFileOpen(TCommandEnabler& ce)
{
  // Enable CmFileOpen if not dirty
  ce.Enable(!isDirty);
}

void
TCmdEnableWindow::CeFileSave(TCommandEnabler& ce)
{
  // Enable CmFileSave if not new file and is dirty.
  ce.Enable(!isNewFile && isDirty);
}

void
TCmdEnableWindow::CeToggleDirty(TCommandEnabler& ce)
{
  ce.SetCheck(isDirty ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

void
TCmdEnableWindow::CeToggleNew(TCommandEnabler& ce)
{
  ce.SetCheck(isNewFile ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}
