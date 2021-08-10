//----------------------------------------------------------------------------
//  Project ApxSdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdiDv Application
//  FILE:         apxsddva.cpp
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxSdiDvApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/docmanag.h>
#include <owl/statusba.h>
#include <owl/filedoc.h>

#include <classlib/cmdline.h>
#include <classlib/filename.h>

#include "apxsddva.h"
#include "apxsddev.h"                        // Definition of client class.
#include "apxsddad.h"                        // Definition of about dialog.


//{{TApxSdiDvApp Implementation}}



//{{DOC_VIEW}}
DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TApxSdiDvEditView, DocType1);
//{{DOC_VIEW_END}}

//{{DOC_MANAGER}}
DocType1 __dvt1("All Files", "*.*", 0, "txt", dtAutoDelete | dtUpdateDir | dtOverwritePrompt);
//{{DOC_MANAGER_END}}


//
// Build a response table for all messages/commands handled by the application.
//
DEFINE_RESPONSE_TABLE2(TApxSdiDvApp, TRecentFiles, TApplication)
//{{TApxSdiDvAppRSP_TBL_BEGIN}}
  EV_OWLVIEW(dnCreate, EvNewView),
  EV_OWLVIEW(dnClose,  EvCloseView),
  EV_COMMAND(CM_FILESEND, CmFileSend),
  EV_COMMAND_ENABLE(CM_FILESEND, CeFileSend),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrintSetup),
  EV_COMMAND(CM_FILEPRINTPREVIEW, CmFilePrintPreview),
  EV_COMMAND_ENABLE(CM_FILEPRINT, CmPrintEnable),
  EV_COMMAND_ENABLE(CM_FILEPRINTERSETUP, CmPrintEnable),
  EV_COMMAND_ENABLE(CM_FILEPRINTPREVIEW, CmPrintEnable),
  EV_WM_DROPFILES,
  EV_WM_WININICHANGE,
  EV_OWLDOCUMENT(dnCreate, EvOwlDocument),
  EV_OWLDOCUMENT(dnRename, EvOwlDocument),
  EV_REGISTERED(MruFileMessage, CmFileSelected),
//{{TApxSdiDvAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~
//
TApxSdiDvApp::TApxSdiDvApp() : TApplication("AppExpert SDI DocView Example"), TRecentFiles(".\\ApxSdiDv.ini", 4)
{
  Printer = 0;
  Printing = 0;

  SetDocManager(new TDocManager(dmSDI, this));

  ApxMail = new TMailer();

  // INSERT>> Your constructor code here.
}


TApxSdiDvApp::~TApxSdiDvApp()
{
  delete Printer;

  delete ApxMail;

  // INSERT>> Your destructor code here.
}


void TApxSdiDvApp::CreateGadgets(TDockableControlBar* cb, bool server)
{
  if (!server) {
    cb->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW));
    cb->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN));
    cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
    cb->Insert(*new TSeparatorGadget(6));
  }

  cb->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cb->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cb->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITFIND, CM_EDITFIND));
  cb->Insert(*new TButtonGadget(CM_EDITFINDNEXT, CM_EDITFINDNEXT));

  if (!server) {
    cb->Insert(*new TSeparatorGadget(6));
    cb->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));
    cb->Insert(*new TButtonGadget(CM_FILEPRINTPREVIEW, CM_FILEPRINTPREVIEW));
  }

  // Add caption and fly-over help hints.
  //
  cb->SetCaption("Toolbar");
  cb->SetHintMode(TGadgetWindow::EnterHints);
}


void TApxSdiDvApp::SetupSpeedBar(TDecoratedFrame* frame)
{
  ApxHarbor = new THarbor(*frame);

  // Create default toolbar New and associate toolbar buttons with commands.
  //
  TDockableControlBar* cb = new TDockableControlBar(frame);
  CreateGadgets(cb);

  // Setup the toolbar ID used by OLE 2 for toolbar negotiation.
  //
  cb->Attr.Id = IDW_TOOLBAR;

  ApxHarbor->Insert(*cb, alTop);
}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~
// Application main window construction & intialization.
//
void TApxSdiDvApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  TSDIDecFrame* frame = new TSDIDecFrame(0, GetName(), 0, true, this);

  // Enable acceptance of dropped files
  //
  frame->Attr.ExStyle |= WS_EX_ACCEPTFILES;

  // Assign icons for this application.
  //
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->SetIconSm(this, IDI_SDIAPPLICATION);

  // Menu associated with window and accelerator table associated with table.
  //
  frame->AssignMenu(IDM_SDI);

  // Associate with the accelerator table.
  //
  frame->Attr.AccelTable = IDM_SDI;

  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed,
                                  TStatusBar::CapsLock        |
                                  TStatusBar::NumLock         |
                                  TStatusBar::ScrollLock);
  frame->Insert(*sb, TDecoratedFrame::Bottom);

  SetupSpeedBar(frame);

  SetMainWindow(frame);

  frame->SetMenuDescr(TMenuDescr(IDM_SDI));

}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~
// Application instance initialization.
//
void TApxSdiDvApp::InitInstance()
{
  TApplication::InitInstance();
  GetDocManager()->CreateAnyDoc(0, dtNewDoc);
  ProcessCmdLine(lpCmdLine);
}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~
// Process command line parameters.
//
void TApxSdiDvApp::ProcessCmdLine(char * CmdLine)
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
// TApxSdiDvApp
// ~~~~~
// Register application info.
//
void TApxSdiDvApp::RegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxSdiDv.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
  TRegKey(TRegKey::ClassesRoot, "ApxSdiDv.Document.1\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcpy(buffer, "ApxSdiDv.Document.1");
  TRegKey(TRegKey::ClassesRoot, ".txt").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~
// Unregister application info.
//
void TApxSdiDvApp::UnRegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxSdiDv.Application").DeleteKey("DefaultIcon");
  TRegKey(TRegKey::ClassesRoot, "ApxSdiDv.Document.1").DeleteKey("DefaultIcon");

  TRegKey::ClassesRoot.DeleteKey("ApxSdiDv.Application");
  TRegKey::ClassesRoot.DeleteKey("ApxSdiDv.Document.1");
  TRegKey::ClassesRoot.DeleteKey(".txt");
}



//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~
// Response Table handlers:
//
void TApxSdiDvApp::EvNewView(TView& view)
{
  GetMainWindow()->SetClientWindow(view.GetWindow());
  if (!view.IsOK())
    GetMainWindow()->SetClientWindow(0);
  else if (view.GetViewMenu())
    GetMainWindow()->MergeMenu(*view.GetViewMenu());
}


void TApxSdiDvApp::EvCloseView(TView&)
{
  GetMainWindow()->SetClientWindow(0);
  GetMainWindow()->SetCaption("AppExpert SDI DocView Example");
}


//{{TSDIDecFrame Implementation}}


TSDIDecFrame::TSDIDecFrame(TWindow* parent, const char far* title, TWindow* clientWnd, bool trackMenuSelection, TModule* module)
:
  TDecoratedFrame(parent, title, clientWnd, trackMenuSelection, module)
{
  // INSERT>> Your constructor code here.

}


TSDIDecFrame::~TSDIDecFrame()
{
  // INSERT>> Your destructor code here.

}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~~~~~~
// Menu File Print command
//
void TApxSdiDvApp::CmFilePrint()
{
  // Create Printer object if not already created.
  //
  if (!Printer)
    Printer = new TPrinter(this);

  TDocument* currentDoc = GetDocManager()->GetCurrentDoc();

  TAPointer<char> docName = new char[_MAX_PATH];

  if (currentDoc->GetTitle())
    strcpy(docName, currentDoc->GetTitle());
  else
    strcpy(docName, "Document");

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
// TApxSdiDvApp
// ~~~~~~~~~~
// Menu File Print Setup command
//
void TApxSdiDvApp::CmFilePrintSetup()
{
  if (!Printer)
    Printer = new TPrinter(this);

  // Bring up the Print Setup dialog.
  //
  Printer->Setup(GetMainWindow());
}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~~~~~~
// Menu File Print Preview command
//
void TApxSdiDvApp::CmFilePrintPreview()
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
// TApxSdiDvApp
// ~~~~~~~~~~
// Menu enabler used by Print, Print Setup and Print Preview.
//
void TApxSdiDvApp::CmPrintEnable(TCommandEnabler& tce)
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


void TApxSdiDvApp::CeFileSend(TCommandEnabler& ce)
{
  ce.Enable((GetDocManager()->GetCurrentDoc() != 0)
            && ApxMail->IsMAPIAvailable());
}


void TApxSdiDvApp::CmFileSend ()
{
  // Check to see if a document exists
  //
  TDocument* currentDoc = GetDocManager()->GetCurrentDoc();

  if (currentDoc) {
    TAPointer<char> savedPath = new char[_MAX_PATH];
    TAPointer<char> docName = new char[_MAX_PATH];

    bool dirtyState = currentDoc->IsDirty();

    if (currentDoc->GetDocPath())
      strcpy(savedPath, currentDoc->GetDocPath());
    else
      strcpy(savedPath, "");

    if (currentDoc->GetTitle())
      strcpy(docName, currentDoc->GetTitle());
    else
      strcpy(docName, "Document");

    TFileName tempFile(TFileName::TempFile);

    currentDoc->SetDocPath(tempFile.Canonical().c_str());
    currentDoc->Commit(true);

    currentDoc->SetDocPath(savedPath);
    currentDoc->SetDirty(dirtyState);

    ApxMail->SendDocuments(GetMainWindow(), tempFile.Canonical().c_str(), docName, false);

    tempFile.Remove();
  }
}


//--------------------------------------------------------
// TApxSdiDvApp
// ~~~~~~~~~~~
//
// Menu Help About ApxSdiDv command
void TApxSdiDvApp::CmHelpAbout()
{
  // Show the modal dialog.
  //
  TApxSdiDvAboutDlg(GetMainWindow()).Execute();
}


void TApxSdiDvApp::EvDropFiles(TDropInfo drop)
{
  // Tell DragQueryFile the file interested in (0) and the length of your buffer.
  //
  int    nameLength = drop.DragQueryFileNameLen(0) + 1;
  char*  fileName = new char[nameLength];

  drop.DragQueryFile(0, fileName, nameLength);

  // Open the file that was dropped.
  //
  AddFile(fileName);

  // Release the memory allocated for this handle with DragFinish.
  //
  drop.DragFinish();
  delete[] fileName;
}


void TApxSdiDvApp::AddFile(const char* FileName)
{
  TDocTemplate* tpl = GetDocManager()->MatchTemplate(FileName);
  if (tpl)
    GetDocManager()->CreateDoc(tpl, FileName);
}


void TApxSdiDvApp::EvOwlDocument(TDocument& doc)
{
  if (doc.GetDocPath())
    SaveMenuChoice(doc.GetDocPath());
}


int32 TApxSdiDvApp::CmFileSelected(uint wp, int32)
{
  TAPointer<char> text = new char[_MAX_PATH];

  GetMenuText(wp, text, _MAX_PATH);
  TDocTemplate* tpl = GetDocManager()->MatchTemplate(text);
  if (tpl)
    GetDocManager()->CreateDoc(tpl, text);
  return 0;
}

void TApxSdiDvApp::EvWinIniChange(char far* section)
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
  TApxSdiDvApp   app;
  return app.Run();
}
