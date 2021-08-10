//----------------------------------------------------------------------------
//  ObjectWindows - (C) Copyright 199 by Borland International
//    Command-enabling sample application
//    Third version implements check marks on the toggle functions.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include "cmdenabl.h"

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
  // Construct the frame window
  TFrameWindow* frame = new TFrameWindow(0, "Command-enabling sample application", new TCmdEnableWindow, true);

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
