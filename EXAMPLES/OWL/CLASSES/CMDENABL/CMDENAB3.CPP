// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1994, 1995 by Borland International, All Rights Reserved
//
//  Command-enabling sample application
//  Third version implements check marks on the toggle functions.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include "cmdenabl.h"

//
// class TCmdEnableApp
// ~~~~~ ~~~~~~~~~~~~~
// Application object initializes TApplication, overrides InitMainWindow.
class TCmdEnableApp : public TApplication {
  public:
    TCmdEnableApp() : TApplication() {}

  protected:
    void InitMainWindow();
};


//
// class TCmdEnableWindow
// ~~~~~ ~~~~~~~~~~~~~~~~
// Window object initializes TWindow, adds four event handlers,
// adds response table for four events.
//
class TCmdEnableWindow : public TWindow {
  public:
    TCmdEnableWindow(TWindow* parent = 0);

  protected:
    // Event handlers
    //
    void CmFileNew();
    void CmFileOpen();
    void CmFileSave();
    void CmFileSaveAs();
    void CmToggleDirty();
    void CmToggleNew();
    void CmShowState();

    // Command-enabling functions
    //
    void CeFileNew(TCommandEnabler&);
    void CeFileOpen(TCommandEnabler&);
    void CeFileSave(TCommandEnabler&);
    void CeToggleDirty(TCommandEnabler&);
    void CeToggleNew(TCommandEnabler&);

    bool IsDirty;
    bool IsNewFile;

  DECLARE_RESPONSE_TABLE(TCmdEnableWindow);
};


//
//
//
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

//
// TCmdEnableApp::InitMainWindow
//
void
TCmdEnableApp::InitMainWindow()
{
  // Construct the frame window
  //
  TFrameWindow* frame = new TFrameWindow(0, "Command-enabling sample application",
    new TCmdEnableWindow, true);

  // Set the main window and its menu
  //
  SetMainWindow(frame);
  GetMainWindow()->AssignMenu(MN_COMMANDS);
}


//
//
//
TCmdEnableWindow::TCmdEnableWindow(TWindow* parent)
:
  TWindow(parent),
  IsNewFile(true),
  IsDirty(false)
{
}


//
//
//
void
TCmdEnableWindow::CmFileNew()
{
  IsDirty   = false;
  IsNewFile = true;
  MessageBox("Opened a new file.\nIsDirty=false\nIsNewFile=true",
    "File action taken");
}


//
//
//
void
TCmdEnableWindow::CmFileOpen()
{
  IsDirty   = false;
  IsNewFile = false;
  MessageBox("Opened an existing file.\nIsDirty=false\nIsNewFile=false",
    "File action taken");
}


//
//
//
void
TCmdEnableWindow::CmFileSave()
{
  IsDirty   = false;
  IsNewFile = false;
  MessageBox("Saved an existing file.\nIsDirty=false\nIsNewFile=false",
    "File action taken");
}


//
//
//
void
TCmdEnableWindow::CmFileSaveAs()
{
  IsDirty   = false;
  IsNewFile = false;
  MessageBox("Saved a file under a new name.\nIsDirty=false\nIsNewFile=false",
    "File action taken");
}


//
//
//
void
TCmdEnableWindow::CmToggleDirty()
{
  IsDirty=!IsDirty;
}


//
//
//
void
TCmdEnableWindow::CmToggleNew()
{
  IsNewFile=!IsNewFile;
}


//
//
//
void
TCmdEnableWindow::CmShowState()
{
  string str(IsDirty ? "IsDirty = true\n" : "IsDirty = false\n");
  str += (IsNewFile ? "IsNewFile = true" : "IsNewFile = false");
  MessageBox(str.c_str(), "Current state");
}


//
//
//
void
TCmdEnableWindow::CeFileNew(TCommandEnabler& ce)
{
  // Enable CmFileNew if not dirty
  //
  ce.Enable(!IsDirty);
}


//
//
//
void
TCmdEnableWindow::CeFileOpen(TCommandEnabler& ce)
{
  // Enable CmFileOpen if not dirty
  //
  ce.Enable(!IsDirty);
}


//
//
//
void
TCmdEnableWindow::CeFileSave(TCommandEnabler& ce)
{
  // Enable CmFileSave if not new file and is dirty.
  //
  ce.Enable(!IsNewFile && IsDirty);
}


//
//
//
void
TCmdEnableWindow::CeToggleDirty(TCommandEnabler& ce)
{
  ce.SetCheck(IsDirty ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}


//
//
//
void
TCmdEnableWindow::CeToggleNew(TCommandEnabler& ce)
{
  ce.SetCheck(IsNewFile ? TCommandEnabler::Checked : TCommandEnabler::Unchecked);
}

//
// Put the OwlMain here just to get it out of the way
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TCmdEnableApp().Run();
}

