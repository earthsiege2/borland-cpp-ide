//----------------------------------------------------------------------------
//  Project ApxSdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdi Application
//  FILE:         apxsdapp.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxSdiApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <classlib/cmdline.h>
#include <winsys/registry.h>
#include <stdio.h>

#include "apxsdapp.h"
#include "apxsdedf.h"                        // Definition of client class.
#include "apxsdabd.h"                        // Definition of about dialog.


//{{TApxSdiApp Implementation}}


//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE2(TApxSdiApp, TRecentFiles, TApplication)
//{{TApxSdiAppRSP_TBL_BEGIN}}
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrintSetup),
  EV_COMMAND(CM_FILEPRINTPREVIEW, CmFilePrintPreview),
  EV_COMMAND_ENABLE(CM_FILEPRINT, CmPrintEnable),
  EV_COMMAND_ENABLE(CM_FILEPRINTERSETUP, CmPrintEnable),
  EV_COMMAND_ENABLE(CM_FILEPRINTPREVIEW, CmPrintEnable),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
  EV_WM_DROPFILES,
  EV_WM_WININICHANGE,
  EV_REGISTERED(MruFileMessage, CmFileSelected),
//{{TApxSdiAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxSdiApp
//
TApxSdiApp::TApxSdiApp() : TApplication("AppExpert SDI Example"), TRecentFiles(".\\ApxSdi.ini", 4)
{

  Printer = 0;
  Printing = 0;

  // Common file file flags and filters for Open/Save As dialogs.  Filename and directory are
  // computed in the member functions CmFileOpen, and CmFileSaveAs.
  //
  FileData.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
  FileData.SetFilter("All Files (*.*)|*.*|");
  FileData.DefExt = "txt";

  // INSERT>> Your constructor code here.
}


TApxSdiApp::~TApxSdiApp()
{
  delete Printer;

  // INSERT>> Your destructor code here.
}


void TApxSdiApp::SetupSpeedBar(TDecoratedFrame* frame)
{
  ApxHarbor = new THarbor(*frame);

  // Create default toolbar New and associate toolbar buttons with commands.
  //
  TDockableControlBar* cb = new TDockableControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW));
  cb->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN));
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
// TApxSdiApp
// ~~~~~
// Application intialization.
//
void TApxSdiApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  TSDIDecFrame* frame = new TSDIDecFrame(0, GetName(), 0, true);

  // Enable acceptance of dropped files
  //
  frame->Attr.ExStyle |= WS_EX_ACCEPTFILES;

  // Assign ICON w/ this application.
  //
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->SetIconSm(this, IDI_SDIAPPLICATION);

  // Menu associated with window and accelerator table associated with table.
  //
  frame->AssignMenu(IDM_SDI);

  // Associate with the accelerator table.
  //
  frame->Attr.AccelTable = IDM_SDI;

  SetupSpeedBar(frame);

  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed,
                                  TStatusBar::CapsLock        |
                                  TStatusBar::NumLock         |
                                  TStatusBar::ScrollLock);
  frame->Insert(*sb, TDecoratedFrame::Bottom);

  SetMainWindow(frame);

  frame->SetMenuDescr(TMenuDescr(IDM_SDI));
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~
// Application instance initialization.
//
void TApxSdiApp::InitInstance()
{
  TApplication::InitInstance();

  ProcessCmdLine(lpCmdLine);
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~
// Process command line parameters.
//
void TApxSdiApp::ProcessCmdLine(char * CmdLine)
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
// TApxSdiApp
// ~~~~~
// Register application info.
//
void TApxSdiApp::RegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxSdi.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
  TRegKey(TRegKey::ClassesRoot, "ApxSdi.Document.1\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcpy(buffer, "ApxSdi.Document.1");
  TRegKey(TRegKey::ClassesRoot, ".txt").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~
// Unregister application info.
//
void TApxSdiApp::UnRegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxSdi.Application").DeleteKey("DefaultIcon");
  TRegKey(TRegKey::ClassesRoot, "ApxSdi.Document.1").DeleteKey("DefaultIcon");

  TRegKey::ClassesRoot.DeleteKey("ApxSdi.Application");
  TRegKey::ClassesRoot.DeleteKey("ApxSdi.Document.1");
  TRegKey::ClassesRoot.DeleteKey(".txt");
}



//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~~
// Menu File New command
//
void TApxSdiApp::CmFileNew()
{
  TApxSdiEditFile* client = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TApxSdiEditFile);     // Client window for the frame.
  client->NewFile();
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~~
// Menu File Open command
//
void TApxSdiApp::CmFileOpen()
{
  // Display standard Open dialog box to select a file name.
  //
  *FileData.FileName = 0;

  TApxSdiEditFile* client = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TApxSdiEditFile);     // Client window for the frame.
  if (client->CanClose())
    if (TFileOpenDialog(GetMainWindow(), FileData).Execute() == IDOK)
      OpenFile();
}


void TApxSdiApp::OpenFile(const char* fileName)
{
  if (fileName)
    strcpy(FileData.FileName, fileName);

  TApxSdiEditFile* client = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TApxSdiEditFile);     // Client window for the frame.
  client->ReplaceWith(FileData.FileName);

  // Add the file to the MRU list.
  //
  SaveMenuChoice(FileData.FileName);
}


//{{TSDIDecFrame Implementation}}


TSDIDecFrame::TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection, TModule* module)
:
  TDecoratedFrame(parent, title, !clientWnd ? new TApxSdiEditFile(0, 0, 0) : clientWnd, trackMenuSelection, module)
{
  // INSERT>> Your constructor code here.

}


TSDIDecFrame::~TSDIDecFrame()
{
  // INSERT>> Your destructor code here.

}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~
// Menu File Print command
//
void TApxSdiApp::CmFilePrint()
{
  // Create Printer object if not already created.
  //
  if (!Printer)
    Printer = new TPrinter(this);

  TAPointer<char> docName = new char[_MAX_PATH];
  GetMainWindow()->GetWindowText(docName, _MAX_PATH);

  // Create Printout window and set characteristics.
  //
  TApxPrintout printout(Printer, docName, GetMainWindow()->GetClientWindow());
  printout.SetBanding(true);

  Printing++;

  // Bring up the Print dialog and print the document.
  //
  Printer->Print(GetWindowPtr(GetActiveWindow()), printout, true);

  Printing--;
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~
// Menu File Print Setup command
//
void TApxSdiApp::CmFilePrintSetup()
{
  if (!Printer)
    Printer = new TPrinter(this);

  // Bring up the Print Setup dialog.
  //
  Printer->Setup(GetMainWindow());
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~
// Menu File Print Preview command
//
void TApxSdiApp::CmFilePrintPreview()
{
  TSDIDecFrame* sdiFrame = TYPESAFE_DOWNCAST(GetMainWindow(), TSDIDecFrame);
  if (sdiFrame) {
    if (!Printer)
      Printer = new TPrinter(this);

    Printing++;

    TApxPreviewWin* prevW = new TApxPreviewWin(sdiFrame, Printer, sdiFrame->GetClientWindow(), "Print Preview", new TLayoutWindow(0));
    prevW->Create();

    // Here we resize the preview window to take the size of the MainWindow, then
    // hide the MainWindow.
    //
    TFrameWindow * mainWindow =  GetMainWindow();
    TRect r = mainWindow->GetWindowRect();
    prevW->MoveWindow(r);
    prevW->ShowWindow(SW_SHOWNORMAL);
    mainWindow->ShowWindow(SW_HIDE);

    BeginModal(GetMainWindow());

    // After the user closes the preview Window, we take its size and use it
    // to size the MainWindow, then show the MainWindow again.
    //
    r = prevW->GetWindowRect();
    mainWindow->MoveWindow(r);
    mainWindow->ShowWindow(SW_SHOWNORMAL);

    Printing--;

    // Now that printing is off we can invalidate because the edit window to repaint.
    //
    GetMainWindow()->SetRedraw(true);
    GetMainWindow()->Invalidate();

    // We must destroy the preview window explicitly.  Otherwise, the window will
    // not be destroyed until it's parent the MainWindow is destroyed.
    //
    prevW->Destroy();
    delete prevW;
  }
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~
// Menu enabler used by Print, Print Setup and Print Preview.
//
void TApxSdiApp::CmPrintEnable(TCommandEnabler& tce)
{
  // If we have a Printer already created just test if all is okay.
  // Otherwise create a Printer object and make sure the printer really exists
  // and then delete the Printer object.
  //
  if (!Printer) {
    Printer = new TPrinter(this);
      tce.Enable(!Printer->GetSetup().Error);
  }
  else
    tce.Enable(!Printer->GetSetup().Error);
}


//--------------------------------------------------------
// TApxSdiApp
// ~~~~~~~~~~~
// Menu Help About ApxSdi command
//
void TApxSdiApp::CmHelpAbout()
{
  // Show the modal dialog.
  //
  TApxSdiAboutDlg(MainWindow).Execute();
}


void TApxSdiApp::EvDropFiles(TDropInfo drop)
{
  // Tell DragQueryFile the file interested in (0) and the length of your buffer.
  //
  int    namelen = drop.DragQueryFileNameLen(0) + 1;
  char*  fileName = new char[namelen];

  drop.DragQueryFile(0, fileName, namelen);

  // Open the file that was dropped.
  //
  AddFile(fileName);

  // Release the memory allocated for this handle with DragFinish.
  //
  drop.DragFinish();
  delete[] fileName;
}


void TApxSdiApp::AddFile(const char* FileName)
{
  // Open the file dragged in.
  //
  TApxSdiEditFile* client = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TApxSdiEditFile);
  if (client->CanClose()) {
    strcpy(FileData.FileName, FileName);
    client->ReplaceWith(FileData.FileName);

    // Add the file to the MRU list.
    //
    SaveMenuChoice(FileData.FileName);
  }
}


int32 TApxSdiApp::CmFileSelected(uint wp, int32)
{
  TAPointer<char> text = new char[_MAX_PATH];

  GetMenuText(wp, text, _MAX_PATH);

  OpenFile(text);
  return 0;
}


void TApxSdiApp::EvWinIniChange(char far* section)
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
  TApxSdiApp   app;
  return app.Run();
}
