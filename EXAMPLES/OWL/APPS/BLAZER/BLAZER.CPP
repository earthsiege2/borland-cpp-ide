//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Implementation of the main application TBlazerApp.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/decframe.h>
#include <owl/panespli.h>
#include <owl/controlg.h>
#include <owl/docking.h>
#include <owl/combobox.h>
#include <owl/statusba.h>
#include <owl/timegadg.h>
#include <owl/modegad.h>
#include <owl/buttonga.h>
#include <owl/splashwi.h>
#include <owl/mailer.h>
#include <owl/opensave.h>
#include <owl/mci.h>
#include "blazer.h"

//
// Forward declarations
//
class TBlazerApp;
class TClientWindow;

//
// Globals
//
static TBlazerSplash* Splash;

TStatusBar*     StatusBar;
TComboBox*      ListOfDrives;
TBlazerApp*     Application;
TClientWindow*  ClientWindow;

//
// Since TBlazerApp uses three base classes with TEventHandlers, we
// need to use DEFINE_RESPONSE_TABLE3 for defining the response table.
// The order of the base classes listed is important (make sure TApplication
// comes last).
//
DEFINE_RESPONSE_TABLE3(TBlazerApp, THelpFileManager, TRecentFiles, TApplication)
  EV_REGISTERED(MruFileMessage, CmMruSelected),
  EV_COMMAND   (CM_FILESELECT,  CmFileSelect),
  EV_COMMAND   (CM_HELPABOUT,   CmHelpAbout),
END_RESPONSE_TABLE;

//
//
//
TBlazerSplash::TBlazerSplash(TDib& dib,
  int width, int height, int style, uint timeOut,
  const char far* title, TModule* module)
:
  TSplashWindow(dib, width, height, style, timeOut, title, module)
{
  Engine = new TMciWaveAudio("engine.wav");
}

//
//
//
TBlazerSplash::~TBlazerSplash()
{
  delete Engine;
}

//
// Initialize the base classes.
// Create the mailer object.
//
TBlazerApp::TBlazerApp()
:
  THelpFileManager(HELPFILENAME),
  TRecentFiles(INIFILENAME, 6),
  Mailer(0)
{
  try {
    Mailer = new TMailer;
  }
  catch (TXBase&) {
  }
}

//
// Destroy the mailer object.
//
TBlazerApp::~TBlazerApp()
{
  delete Mailer;
}

//
// Select files to be inserted into the MRU list.
//
void
TBlazerApp::CmFileSelect()
{
  TOpenSaveDialog::TData data(OFN_NOVALIDATE | OFN_NOCHANGEDIR,
    "All Files (*.*)|*.*|");
  if (TFileOpenDialog(GetMainWindow(), data).Execute() == IDOK)
    ::Application->SaveMenuChoice(data.FileName);
}

//
// A choice for the MRU list has been chosen.
// The parameter wp is the id of the choice.
//
TResult
TBlazerApp::CmMruSelected(TParam1 wp, TParam2)
{
  const int MaxLen = 80;
  TAPointer<char> text = new char[MaxLen];
  GetMenuText(wp, text, MaxLen);
  GetMainWindow()->MessageBox(text, "You've selected", MB_OK);
  return 0;
}

//
// Display the About window modally by calling Execute() instead of Create().
//
void
TBlazerApp::CmHelpAbout()
{
  TAboutWindow* about = new TAboutWindow(GetMainWindow());
  about->Execute();
  delete about;
}


//
// InitMainWindow().
// This function gets called because OWL needs to create a main window.
// This is the ideal time to create a splash screen (before the main
// window is visible).
//
void
TBlazerApp::InitMainWindow()
{
  int style = TSplashWindow::CaptureMouse |
              TSplashWindow::ShrinkToFit;
  int timeOut = 5000;

  // create the splash screen
  //
  ::Splash = new TBlazerSplash(*new TDib("splslogo.bmp"), 400, 300,
    style, timeOut, "", this);
  ::Splash->Create();
  ::Splash->UpdateWindow();

  // play the engine
  //
  if (::Splash->Engine)
    ::Splash->Engine->Play(MCI_NOTIFY);

  // create the main window
  //
  ::ClientWindow = new TClientWindow();
  TDecoratedFrame* frame = new TDecoratedFrame(0, "Blazer Sample Application",
    ::ClientWindow, true);
  frame->AssignMenu(IDM_MAINMENU);
  frame->SetIcon(::Application, IDI_BIGICON);
  SetMainWindow(frame);

  // create a harbor for the docking gadget windows.
  //
  Harbor = new THarbor(*frame);

  // create the status bar
  //
  ::StatusBar = new TStatusBar(frame, TGadget::Recessed, TStatusBar::SizeGrip);
  frame->Insert(*::StatusBar, TDecoratedFrame::Bottom);

  // create the dockable drive control bar
  //
  TDockableControlBar* controlBar = new TDockableControlBar(frame);
  TTextGadget* driveText = new TTextGadget(0, TGadget::None, TTextGadget::Left,
    5, "Current:");
  driveText->SetShrinkWrap(true, true);
  controlBar->Insert(*driveText);
  controlBar->Insert(*new TSeparatorGadget);

  // initialize the list of drives
  //
  ::ListOfDrives = new TComboBoxAsGadget(0, DrivesId, 0, 0, 50, 100,
    CBS_DROPDOWNLIST | CBS_HASSTRINGS, 0);
  controlBar->Insert(*new TControlGadget(*::ListOfDrives));
  controlBar->SetCaption("Select Drive");
  Harbor->Insert(*controlBar, alTop);

  // initialize status control bar
  //
  TDockableControlBar* tracker = new TDockableControlBar(frame);
  tracker->Insert(*new TModeGadget(VK_NUMLOCK, "Num"));
  tracker->Insert(*new TSeparatorGadget);
  tracker->Insert(*new TModeGadget(VK_CAPITAL, "Cap"));
  tracker->Insert(*new TSeparatorGadget);
  tracker->Insert(*new TModeGadget(VK_SCROLL, "Scr"));
  tracker->SetCaption("Status");
  Harbor->Insert(*tracker, alBottom);

  // initialize the time status indicator
  //
  TDockableControlBar* timeIndicator = new TDockableControlBar(frame);
  timeIndicator->Insert(*new TTimeGadget);
  timeIndicator->SetCaption("Time");
  Harbor->Insert(*timeIndicator, alBottom);

  // create the tools
  //
  TDockableControlBar* tools = new TDockableControlBar(frame);
  tools->Insert(*new TButtonGadget(IDB_CONTEXTSELECT, CM_CONTEXTSELECT));
  tools->Insert(*new TButtonGadget(IDB_FILESEND, CM_FILESEND));
  tools->Insert(*new TSeparatorGadget);
  tools->Insert(*new TButtonGadget(IDB_HELP, CM_HELPABOUT));
  tools->Insert(*new TButtonGadget(IDB_EXIT, CM_EXIT));
  tools->SetCaption("Tools");
  tools->SetHintMode(TGadgetWindow::EnterHints);

  Harbor->Insert(*tools, alTop, 0, rpRightOf, controlBar);
}


//
// InitInstance().
// This function is called after the main window has been created.
// This is the place to initialize the combobox for the drive letters
// because we need to make sure it has been created before adding
// any strings into it.
//
void
TBlazerApp::InitInstance()
{
  // Initialize main window
  //
  TApplication::InitInstance();

  // Fill drive combobox
  //
  const int MaxDriveLen = 1024;
  TAPointer<char> drivesToAdd = new char[MaxDriveLen];
  if (::GetLogicalDriveStrings(MaxDriveLen, drivesToAdd)) {
    char* aDrive = drivesToAdd;
    do {
      int length = strlen(aDrive) + 1;
      if (::GetDriveType(aDrive) == DRIVE_FIXED) {
        if (aDrive[strlen(aDrive) - 1] == '\\')
          aDrive[strlen(aDrive) - 1] = 0;
        ::ListOfDrives->AddString(strupr(aDrive));
      }
      aDrive += length;
    } while(*aDrive);
  }

  // Select first drive
  //
  if (ListOfDrives->GetCount() > 0) {
    ::ListOfDrives->SetSelIndex(0);
    ::ClientWindow->CbnDriveSelected();
  }

  // Now done with splash screen.
  //
  delete ::Splash;
  ::Splash = 0;
}


//
// Starting point
//
int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  int retVal;
  ::Application = new TBlazerApp;
  retVal = ::Application->Run();
  delete ::Application;
  ::Application = 0;
  return retVal;
}
