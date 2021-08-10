//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmdapp.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxMdiApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <classlib/cmdline.h>
#include <winsys/registry.h>

#include "apxmdapp.h"
#include "apxmmdic.h"
#include "apxmdabd.h"                        // Definition of about dialog.

//{{TApxMdiApp Implementation}}


//
// Build a response table for all messages/commands handled by the application.
//
DEFINE_RESPONSE_TABLE2(TApxMdiApp, TRecentFiles, TApplication)
//{{TApxMdiAppRSP_TBL_BEGIN}}
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
  EV_WM_DROPFILES,
  EV_WM_WININICHANGE,
  EV_REGISTERED(MruFileMessage, CmFileSelected),
//{{TApxMdiAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxMdiApp
// ~~~~~
//
TApxMdiApp::TApxMdiApp() : TApplication("AppExpert MDI Example"), TRecentFiles(".\\ApxMdi.ini", 4)
{

  Printer = 0;
  Printing = 0;

  // INSERT>> Your constructor code here.
}


TApxMdiApp::~TApxMdiApp()
{
  delete Printer;

  // INSERT>> Your destructor code here.
}


void TApxMdiApp::SetupSpeedBar(TDecoratedMDIFrame* frame)
{
  ApxHarbor = new THarbor(*frame);

  // Create default toolbar New and associate toolbar buttons with commands.
  //
  TDockableControlBar* cb = new TDockableControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_MDIFILENEW, CM_MDIFILENEW));
  cb->Insert(*new TButtonGadget(CM_MDIFILEOPEN, CM_MDIFILEOPEN));
  cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cb->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cb->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITFIND, CM_EDITFIND));
  cb->Insert(*new TButtonGadget(CM_EDITFINDNEXT, CM_EDITFINDNEXT));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));
  cb->Insert(*new TButtonGadget(CM_FILEPRINTPREVIEW, CM_FILEPRINTPREVIEW));

  // Add caption and fly-over help hints.
  //
  cb->SetCaption("Toolbar");
  cb->SetHintMode(TGadgetWindow::EnterHints);

  ApxHarbor->Insert(*cb, alTop);
}


//--------------------------------------------------------
// TApxMdiApp
// ~~~~~
// Application intialization.
//
void TApxMdiApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  MdiClient = new TApxMdiMDIClient;
  TDecoratedMDIFrame* frame = new TDecoratedMDIFrame(Name, IDM_MDI, *MdiClient, true);

  // Enable acceptance of dropped files
  //
  frame->Attr.ExStyle |= WS_EX_ACCEPTFILES;

  // Assign ICON w/ this application.
  //
  frame->SetIcon(this, IDI_MDIAPPLICATION);
  frame->SetIconSm(this, IDI_MDIAPPLICATION);

  // Associate with the accelerator table.
  //
  frame->Attr.AccelTable = IDM_MDI;

  SetupSpeedBar(frame);

  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed,
                                  TStatusBar::CapsLock        |
                                  TStatusBar::NumLock         |
                                  TStatusBar::ScrollLock);
  frame->Insert(*sb, TDecoratedFrame::Bottom);

  SetMainWindow(frame);

  frame->SetMenuDescr(TMenuDescr(IDM_MDI));
}


//--------------------------------------------------------
// TApxMdiApp
// ~~~~~
// Application instance initialization.
//
void TApxMdiApp::InitInstance()
{
  TApplication::InitInstance();

  ProcessCmdLine(lpCmdLine);
}


//--------------------------------------------------------
// TApxMdiApp
// ~~~~~
// Process command line parameters.
//
void TApxMdiApp::ProcessCmdLine(char * CmdLine)
{
  TCmdLine cmd(CmdLine);

  while (cmd.Kind != TCmdLine::Done) {
    if (cmd.Kind == TCmdLine::Option) {
      if (strnicmp(cmd.Token, "unregister", cmd.TokenLen) == 0) {
        UnRegisterInfo();
        return;
      }
    }
    cmd.NextToken();
  }

  RegisterInfo();
}


//--------------------------------------------------------
// TApxMdiApp
// ~~~~~
// Register application info.
//
void TApxMdiApp::RegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxMdi.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
  TRegKey(TRegKey::ClassesRoot, "ApxMdi.Document.1\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcpy(buffer, "ApxMdi.Document.1");
  TRegKey(TRegKey::ClassesRoot, ".txt").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
}


//--------------------------------------------------------
// TApxMdiApp
// ~~~~~
// Unregister application info.
//
void TApxMdiApp::UnRegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxMdi.Application").DeleteKey("DefaultIcon");
  TRegKey(TRegKey::ClassesRoot, "ApxMdi.Document.1").DeleteKey("DefaultIcon");

  TRegKey::ClassesRoot.DeleteKey("ApxMdi.Application");
  TRegKey::ClassesRoot.DeleteKey("ApxMdi.Document.1");
  TRegKey::ClassesRoot.DeleteKey(".txt");
}





//--------------------------------------------------------
// TApxMdiApp
// ~~~~~~~~~~~
// Menu Help About ApxMdi command
//
void TApxMdiApp::CmHelpAbout()
{
  // Show the modal dialog.
  //
  TApxMdiAboutDlg(MainWindow).Execute();
}


void TApxMdiApp::EvDropFiles(TDropInfo drop)
{
  TFileDropletList files;

  // Iterate thru the entries in drop and create FileDrops objects for each
  // one.
  //
  int fileCount = drop.DragQueryFileCount();  // Number of files dropped.
  for (int i = 0; i < fileCount; i++)
    files.Add(new TFileDroplet(drop, i));

  // Open the files that were dropped.
  //
  AddFiles(files);

  // Release the memory allocated for this handle with DragFinish.
  //
  drop.DragFinish();
}


void TApxMdiApp::AddFiles(TFileDropletList& files)
{
  TApxMdiMDIClient* theClient = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TApxMdiMDIClient);

  if (theClient) {
    // Open all files dragged in.
    //
    for (TFileDropletListIter fileIter(files); fileIter; fileIter++)
      theClient->OpenFile(fileIter.Current()->GetName());
  }
}


int32 TApxMdiApp::CmFileSelected(uint wp, int32)
{
  TAPointer<char> text = new char[_MAX_PATH];

  GetMenuText(wp, text, _MAX_PATH);

  TApxMdiMDIClient* theClient = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TApxMdiMDIClient);

  if (theClient)
    theClient->OpenFile(text);
  return 0;
}


void TApxMdiApp::EvWinIniChange(char far* section)
{
  if (strcmp(section, "windows") == 0) {
    // If the device changed in the WIN.INI file then the printer
    // might have changed.  If we have a TPrinter(Printer) then
    // check and make sure it's identical to the current device
    // entry in WIN.INI.
    //
    if (Printer) {
      const int bufferSize = 255;
      char printDBuffer[bufferSize];
      LPSTR printDevice = printDBuffer;
      LPSTR devName;
      LPSTR driverName = 0;
      LPSTR outputName = 0;
      if (::GetProfileString("windows", "device", "", printDevice, bufferSize)) {
        // The string which should come back is something like:
        //
        //      HP LaserJet III,hppcl5a,LPT1:
        //
        // Where the format is:
        //
        //      devName,driverName,outputName
        //
        devName = printDevice;
        while (*printDevice) {
          if (*printDevice == ',') {
            *printDevice++ = 0;
            if (!driverName)
              driverName = printDevice;
            else
              outputName = printDevice;
          }
          else
            printDevice = ::AnsiNext(printDevice);
        }

        if (Printer->GetSetup().Error != 0                ||
            strcmp(devName, Printer->GetSetup().GetDeviceName()) != 0  ||
            strcmp(driverName, Printer->GetSetup().GetDriverName()) != 0 ||
            strcmp(outputName, Printer->GetSetup().GetOutputName()) != 0 ) {
          // New printer installed so get the new printer device now.
          //
          delete Printer;
          Printer = new TPrinter(this);
        }
      }
      else {
        // No printer installed(GetProfileString failed).
        //
        delete Printer;
        Printer = new TPrinter(this);
      }
    }
  }
}


int OwlMain(int , char* [])
{
  TApxMdiApp   app;
  return app.Run();
}

