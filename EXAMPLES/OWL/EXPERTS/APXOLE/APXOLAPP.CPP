//----------------------------------------------------------------------------
//  Project ApxOle
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxOle Application
//  FILE:         apxolapp.cpp
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxOleApp (TApplication).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <owl/docmanag.h>
#include <owl/oledoc.h>

#include <classlib/cmdline.h>
#include <classlib/filename.h>

#include "apxolapp.h"
#include "apxomdic.h"
#include "apxomdi1.h"
#include "apxololv.h"
#include "apxolabd.h"                        // Definition of about dialog.

//{{TApxOleApp Implementation}}


DEFINE_APP_DICTIONARY(AppDictionary);

static TPointer<TOcRegistrar> Registrar;

REGISTRATION_FORMAT_BUFFER(200)

BEGIN_REGISTRATION(ApplicationReg)
  REGDATA(clsid, "{7D270638-64DB-11CF-87A2-0020AF062334}")
  REGDATA(appname, "ApxOle Server")
  REGDATA(description, "ApxOle Server Application")
  REGDATA(cmdline, "")
  REGDATA(usage, ocrMultipleUse)
END_REGISTRATION

//{{DOC_VIEW}}
DEFINE_DOC_TEMPLATE_CLASS(TOleDocument, TApxOleOleView, DocType1);
//{{DOC_VIEW_END}}

//{{DOC_MANAGER}}
BEGIN_REGISTRATION(__dvReg1)
  REGDATA(progid, "ApxOle.Document.1")
  REGDATA(description, "ApxOle Document Version 1")
  REGDATA(extension, "olv")
  REGDATA(docfilter, "*.olv")
  REGDOCFLAGS(dtAutoDelete | dtUpdateDir | dtOverwritePrompt | dtAutoOpen | dtRegisterExt)
//  REGDATA(debugger, "TDW")
  REGDATA(menuname, "TApxOleOleView")
  REGDATA(insertable, "")
  REGDATA(verb0, "&Edit")
  REGDATA(verb1, "&Open")
  REGFORMAT(0, ocrEmbedSource,  ocrContent,  ocrIStorage, ocrGet)
  REGFORMAT(1, ocrMetafilePict, ocrContent,  ocrMfPict | ocrStaticMed, ocrGet)
  REGFORMAT(2, ocrBitmap, ocrContent,  ocrGDI | ocrStaticMed, ocrGet)
  REGFORMAT(3, ocrDib, ocrContent,  ocrHGlobal | ocrStaticMed, ocrGet)
  REGFORMAT(4, ocrLinkSource, ocrContent,  ocrIStream, ocrGet)
END_REGISTRATION
DocType1 __dvt1(__dvReg1);
//{{DOC_MANAGER_END}}


//
// Build a response table for all messages/commands handled by the application.
//
DEFINE_RESPONSE_TABLE2(TApxOleApp, TRecentFiles, TApplication)
//{{TApxOleAppRSP_TBL_BEGIN}}
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
//{{TApxOleAppRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxOleApp
// ~~~~~
//
TApxOleApp::TApxOleApp() : TApplication(::ApplicationReg["appname"], ::Module, &::AppDictionary), TRecentFiles(".\\ApxOle.ini", 4)
{
  Printer = 0;
  Printing = 0;

  SetDocManager(new TDocManager(dmMDI, this));

  ApxMail = new TMailer();

  // INSERT>> Your constructor code here.
}


TApxOleApp::~TApxOleApp()
{
  delete Printer;

  delete ApxMail;

  // INSERT>> Your destructor code here.
}


void TApxOleApp::CreateGadgets(TControlBar* cb, bool server)
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


void TApxOleApp::SetupSpeedBar(TOleMDIFrame* frame)
{
  // Create default toolbar New and associate toolbar buttons with commands.
  //
  TControlBar* cb = new TControlBar(frame);
  CreateGadgets(cb);

  // Setup the toolbar ID used by OLE 2 for toolbar negotiation.
  //
  cb->Attr.Id = IDW_TOOLBAR;

  frame->Insert(*cb, TDecoratedFrame::Top);
}


//--------------------------------------------------------
// TApxOleApp
// ~~~~~
// Application main window construction & intialization.
//
void TApxOleApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  MdiClient = new TApxOleMDIClient(this);
  TOleMDIFrame* frame = new TOleMDIFrame(Name, IDM_MDI, *MdiClient, true, this);

  // Enable acceptance of dropped files
  //
  frame->Attr.ExStyle |= WS_EX_ACCEPTFILES;

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
// TApxOleApp
// ~~~~~
// Application instance initialization.
//
void TApxOleApp::InitInstance()
{
  TApplication::InitInstance();

  ProcessCmdLine(lpCmdLine);
}


//--------------------------------------------------------
// TApxOleApp
// ~~~~~
// Process command line parameters.
//
void TApxOleApp::ProcessCmdLine(char * CmdLine)
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
// TApxOleApp
// ~~~~~
// Register application info.
//
void TApxOleApp::RegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxOle.Application\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcat(buffer, ",1");
  TRegKey(TRegKey::ClassesRoot, "ApxOle.Document.1\\DefaultIcon").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
  strcpy(buffer, "ApxOle.Document.1");
  TRegKey(TRegKey::ClassesRoot, ".olv").SetDefValue(0, REG_SZ, buffer, strlen(buffer));
}


//--------------------------------------------------------
// TApxOleApp
// ~~~~~
// Unregister application info.
//
void TApxOleApp::UnRegisterInfo()
{
  TAPointer<char> buffer = new char[_MAX_PATH];

  GetModuleFileName(buffer, _MAX_PATH);

  TRegKey(TRegKey::ClassesRoot, "ApxOle.Application").DeleteKey("DefaultIcon");
  TRegKey(TRegKey::ClassesRoot, "ApxOle.Document.1").DeleteKey("DefaultIcon");

  TRegKey::ClassesRoot.DeleteKey("ApxOle.Application");
  TRegKey::ClassesRoot.DeleteKey("ApxOle.Document.1");
  TRegKey::ClassesRoot.DeleteKey(".olv");
}



//--------------------------------------------------------
// TApxOleApp
// ~~~~~
// Response Table handlers:
//
void TApxOleApp::EvNewView(TView& view)
{
  TOleView* ov = TYPESAFE_DOWNCAST(&view, TOleView);

  // If  we're embedded and we're opening out of place then don't create the child window.
  //
  if (view.GetDocument().IsEmbedded() && ov && !ov->IsOpenEditing()) {
    TWindow* vw = view.GetWindow();
    vw->SetParent(TYPESAFE_DOWNCAST(GetMainWindow(), TOleFrame)->GetRemViewBucket());
    vw->Create();
  }
  else {
    TMDIClient* mdiClient = TYPESAFE_DOWNCAST(GetMainWindow()->GetClientWindow(), TMDIClient);
    if (mdiClient) {
      TApxOleMDIChild* child = new TApxOleMDIChild(*mdiClient, 0, 0);

      // Assign icons for this child window.
      //
      child->SetIcon(this, IDI_DOC);
      child->SetIconSm(this, IDI_DOC);

      if (view.GetViewMenu())
        child->SetMenuDescr(*view.GetViewMenu());

      child->Create();
      child->SetClientWindow(view.GetWindow());
    }
  }

  if (!ov || !ov->GetOcRemView())
    OcApp->SetOption(amEmbedding, false);
}


void TApxOleApp::EvCloseView(TView&)
{
}


void TApxOleApp::CeFileSend(TCommandEnabler& ce)
{
  ce.Enable((GetDocManager()->GetCurrentDoc() != 0)
            && ApxMail->IsMAPIAvailable());
}


void TApxOleApp::CmFileSend ()
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
// TApxOleApp
// ~~~~~~~~~~~
// Menu Help About ApxOle command
void TApxOleApp::CmHelpAbout()
{
  // Show the modal dialog.
  //
  TApxOleAboutDlg(&TWindow(::GetFocus(), this)).Execute();
}


void TApxOleApp::EvDropFiles(TDropInfo drop)
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


void TApxOleApp::AddFiles(TFileDropletList& files)
{
  // Open all files dragged in.
  //
  for (TFileDropletListIter fileIter(files); fileIter; fileIter++) {
    TDocTemplate* tpl = GetDocManager()->MatchTemplate(fileIter.Current()->GetName());
    if (tpl)
      GetDocManager()->CreateDoc(tpl, fileIter.Current()->GetName());
  }
}


void TApxOleApp::EvOwlDocument(TDocument& doc)
{
  if (doc.GetDocPath())
    SaveMenuChoice(doc.GetDocPath());
}


int32 TApxOleApp::CmFileSelected(uint wp, int32)
{
  TAPointer<char> text = new char[_MAX_PATH];

  GetMenuText(wp, text, _MAX_PATH);
  TDocTemplate* tpl = GetDocManager()->MatchTemplate(text);
  if (tpl)
    GetDocManager()->CreateDoc(tpl, text);
  return 0;
}


void TApxOleApp::EvWinIniChange(char far* section)
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
  ::Registrar = new TOcRegistrar(::ApplicationReg, TOleDocViewFactory<TApxOleApp>(), TApplication::GetCmdLine(), ::DocTemplateStaticHead);
  if (::Registrar->IsOptionSet(amAnyRegOption))
    return 0;

  // If this is an exe server normal run, run the app now. Otherwise, wait
  // until our factory gets a call.
  //
  return ::Registrar->Run();
}
