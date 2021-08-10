//----------------------------------------------------------------------------
//  Project ApxMdiDv
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdiDv Application
//  FILE:         apxmddva.cpp
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxMdiDvApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <owl/docmanag.h>
#include <owl/filedoc.h>

#include <classlib/cmdline.h>
#include <classlib/filename.h>

#include "apxmddva.h"
#include "apmdmdic.h"
#include "apmdmdi1.h"
#include "apxmddev.h"
#include "apxmddad.h"                        // Definition of about dialog.

//{{TApxMdiDvApp Implementation}}



//{{DOC_VIEW}}
DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TApxMdiDvEditView, DocType1);
//{{DOC_VIEW_END}}

//{{DOC_MANAGER}}
DocType1 __dvt1("All Files", "*.*", 0, "txt", dtAutoDelete | dtUpdateDir | dtOverwritePrompt);
//{{DOC_MANAGER_END}}


//
// Build a response table for all messages/commands handled by the application.
//
DEFINE_RESPONSE_TABLE2(TApxMdiDvApp, TRecentFiles, TApplication)
//{{TApxMdiDvAppRSP_TBL_BEGIN}}
  EV_OWLVIEW(dnCreate, EvNewView),
  EV_OWLVIEW(dnClose,  EvCloseView),
  EV_COMMAND(CM_FILESEND, CmFileSend),
  EV_COMMAND_ENABLE(CM_FILESEND, CeFileSend),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
  EV_WM_DROPFILES,
  EV_WM_WININICHANGE,
  EV_OWLDOCUMENT(dnCreate, EvOwlDocument),
  EV_OWLDOCUMENT(dnRename, EvOwlDocument),
  EV_REGISTERED(MruFileMessage, CmFileSelected),
//{{TApxMdiDvAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxMdiDvApp
// ~~~~~
//
TApxMdiDvApp::TApxMdiDvApp() : TApplication("AppExpert MDI DocView Example"), TRecentFiles(".\\ApxMdiDv.ini", 4)
{
  Printer = 0;
  Printing = 0;

  SetDocManager(new TDocManager(dmMDI, this));

  ApxMail = new TMailer();

  // INSERT>> Your constructor code here.
}


TApxMdiDvApp::~TApxMdiDvApp()
{
  delete Printer;

  delete ApxMail;

  // INSERT>> Your destructor code here.
}


void TApxMdiDvApp::CreateGadgets(TDockableControlBar* cb, bool server)
{
  if (!server) {
    cb->Insert(*new TButtonGadget(CM_MDIFILENEW, CM_MDIFILENEW));
    cb->Insert(*new TButtonGadget(CM_MDIFILEOPEN, CM_MDIFILEOPEN));
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


void TApxMdiDvApp::SetupSpeedBar(TDecoratedMDIFrame* frame)
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
// TApxMdiDvApp
// ~~~~~
// Application main window construction & intialization.
//
void TApxMdiDvApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  MdiClient = new TApxMdiDvMDIClient(this);
  TDecoratedMDIFrame* frame = new TDecoratedMDIFrame(Name, IDM_MDI, *MdiClient, true, this);

  // Enable acceptance of dropped files
  //
  frame->Attr.ExStyle |= WS_EX_ACCEPTFILES;

  nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  // Assign icons for this application.
  //
  frame->SetIcon(this, IDI_MDIAPPLICATION);
  frame->SetIconSm(this, IDI_MDIAPPLICATION);

  // Associate with the accelerator table.
  //
  frame->Attr.AccelTable = IDM_MDI;

  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed,
                                  TStatusBar::CapsLock        |
                                  TStatusBar::NumLock         |
                                  TStatusBar::ScrollLock);
  frame->Insert(*sb, TDecoratedFrame::Bottom);

  SetupSpeedBar(frame);

  SetMainWindow(frame);

  frame->SetMenuDescr(TMenuDescr(IDM_MDI));

}


//--------------------------------------------------------
// TApxMdiDvApp
// ~~~~~
// Application instance initialization.
//
void TApxMdiDvApp::InitInstance()
{
  TApplication::InitInstance();

  ProcessCmdLine(lpCmdLine);
}


//--------------------------------------------------------
// TApxMdiDvApp
// ~~~~~
// Process command line parameters.
//
void TApxMdiDvApp::ProcessCmdLine(char * CmdLine)
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
// TApxMdiDvApp
// ~~~~~
// Register application info.
//
void TApxMdiDvApp::RegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxMdiDv.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
  TRegKey(TRegKey::ClassesRoot, "ApxMdiDv.Document.1\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcpy(buffer, "ApxMdiDv.Document.1");
  TRegKey(TRegKey::ClassesRoot, ".txt").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
}


//--------------------------------------------------------
// TApxMdiDvApp
// ~~~~~
// Unregister application info.
//
void TApxMdiDvApp::UnRegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxMdiDv.Application").DeleteKey("DefaultIcon");
  TRegKey(TRegKey::ClassesRoot, "ApxMdiDv.Document.1").DeleteKey("DefaultIcon");

  TRegKey::ClassesRoot.DeleteKey("ApxMdiDv.Application");
  TRegKey::ClassesRoot.DeleteKey("ApxMdiDv.Document.1");
  TRegKey::ClassesRoot.DeleteKey(".txt");
}



//--------------------------------------------------------
// TApxMdiDvApp
// ~~~~~
// Response Table handlers:
//
void TApxMdiDvApp::EvNewView(TView& view)
{
  TMDIClient* mdiClient = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TMDIClient);
  if (mdiClient) {
    TApxMdiDvMDIChild* child = new TApxMdiDvMDIChild(*mdiClient, 0, view.GetWindow());

    // Set the menu descriptor for this view.
    //
    if (view.GetViewMenu())
      child->SetMenuDescr(*view.GetViewMenu());

    // Assign icons with this child window.
    //
    child->SetIcon(this, IDI_DOC);
    child->SetIconSm(this, IDI_DOC);

    child->Create();
  }
}


void TApxMdiDvApp::EvCloseView(TView&)
{
}


void TApxMdiDvApp::CeFileSend(TCommandEnabler& ce)
{
  ce.Enable((GetDocManager()->GetCurrentDoc() != 0)
            && ApxMail->IsMAPIAvailable());
}


void TApxMdiDvApp::CmFileSend ()
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
// TApxMdiDvApp
// ~~~~~~~~~~~
// Menu Help About ApxMdiDv command
void TApxMdiDvApp::CmHelpAbout()
{
  // Show the modal dialog.
  //
  TApxMdiDvAboutDlg(GetMainWindow()).Execute();
}


void TApxMdiDvApp::EvDropFiles(TDropInfo drop)
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


void TApxMdiDvApp::AddFiles(TFileDropletList& files)
{
  // Open all files dragged in.
  //
  for (TFileDropletListIter fileIter(files); fileIter; fileIter++) {
    TDocTemplate* tpl = GetDocManager()->MatchTemplate(fileIter.Current()->GetName());
    if (tpl)
      GetDocManager()->CreateDoc(tpl, fileIter.Current()->GetName());
  }
}


void TApxMdiDvApp::EvOwlDocument(TDocument& doc)
{
  if (doc.GetDocPath())
    SaveMenuChoice(doc.GetDocPath());
}


int32 TApxMdiDvApp::CmFileSelected(uint wp, int32)
{
  TAPointer<char> text = new char[_MAX_PATH];

  GetMenuText(wp, text, _MAX_PATH);
  TDocTemplate* tpl = GetDocManager()->MatchTemplate(text);
  if (tpl)
    GetDocManager()->CreateDoc(tpl, text);
  return 0;
}


void TApxMdiDvApp::EvWinIniChange(char far* section)
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
  TApxMdiDvApp   app;
  return app.Run();
}
