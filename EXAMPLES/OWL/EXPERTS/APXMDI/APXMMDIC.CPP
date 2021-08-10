//----------------------------------------------------------------------------
//  Project ApxMdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxMdi Application
//  FILE:         apxmmdic.cpp
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TApxMdiMDIClient (TMDIClient).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include <owl/listbox.h>
#include <stdio.h>

#include "apxmdapp.h"
#include "apxmdedf.h"
#include "apxmmdi1.h"
#include "apxmmdic.h"
#include "apxprint.h"
#include "apxprev.h"


//{{TApxMdiMDIClient Implementation}}


//
// Build a response table for all messages/commands handled
// by TApxMdiMDIClient derived from TMDIClient.
//
DEFINE_RESPONSE_TABLE1(TApxMdiMDIClient, TMDIClient)
//{{TApxMdiMDIClientRSP_TBL_BEGIN}}
  EV_COMMAND(CM_MDIFILENEW, CmFileNew),
  EV_COMMAND(CM_MDIFILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILECLOSE, CmFileClose),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrintSetup),
  EV_COMMAND(CM_FILEPRINTPREVIEW, CmFilePrintPreview),
  EV_COMMAND_ENABLE(CM_FILEPRINT, CmPrintEnable),
  EV_COMMAND_ENABLE(CM_FILEPRINTERSETUP, CmPrintEnable),
  EV_COMMAND_ENABLE(CM_FILEPRINTPREVIEW, CmPrintEnable),
  EV_WM_DROPFILES,
//{{TApxMdiMDIClientRSP_TBL_END}}
END_RESPONSE_TABLE;


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~~
// Construction/Destruction handling.
//
TApxMdiMDIClient::TApxMdiMDIClient(TModule* module)
:
  TMDIClient(module)
{
  ChildCount = 0;

  // INSERT>> Your constructor code here.

}


TApxMdiMDIClient::~TApxMdiMDIClient()
{
  Destroy();

  // INSERT>> Your destructor code here.

}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~~
// MDIClient site initialization.
//
void TApxMdiMDIClient::SetupWindow()
{
  // Default SetUpWindow processing.
  //
  TMDIClient::SetupWindow();

  TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);

  // Common file file flags and filters for Open/Save As dialogs.  Filename and directory are
  // computed in the member functions CmFileOpen, and CmFileSaveAs.
  //
  theApp->FileData.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT;
  theApp->FileData.SetFilter("All Files (*.*)|*.*|");
  theApp->FileData.DefExt = "txt";

  // Accept files via drag/drop in the client window.
  //
  DragAcceptFiles(true);
}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~~
// Menu File New command
//
void TApxMdiMDIClient::CmFileNew()
{
  TAPointer<char> title = new char[255];

  // Generate a title for the MDI child window.
  //
  sprintf(title, "%d", ++ChildCount);

  TApxMdiMDIChild* child = new TApxMdiMDIChild(*this, title, 0);

  // Assign icons for this child window.
  //
  child->SetIcon(GetApplication(), IDI_DOC);
  child->SetIconSm(GetApplication(), IDI_DOC);

  // If the current active MDI child is maximize then this one should be also.
  //
  TApxMdiMDIChild* curChild = (TApxMdiMDIChild *)GetActiveMDIChild();
  if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
    child->Attr.Style |= WS_MAXIMIZE;

  child->Create();
}


void TApxMdiMDIClient::OpenFile(const char* fileName)
{
  TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);

  if (fileName)
    strcpy(theApp->FileData.FileName, fileName);

  // Create a MDIChild window whose client is TApxMdiEditFile.
  //
  TApxMdiMDIChild* child = new TApxMdiMDIChild(*this, "", new TApxMdiEditFile(0, 0, 0, 0, 0, 0, 0, theApp->FileData.FileName));

  // Assign icons for this child window.
  //
  child->SetIcon(GetApplication(), IDI_DOC);
  child->SetIconSm(GetApplication(), IDI_DOC);

  // If the current active MDI child is maximize then this one should be also.
  //
  TApxMdiMDIChild* curChild = (TApxMdiMDIChild *)GetActiveMDIChild();
  if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
    child->Attr.Style |= WS_MAXIMIZE;

  child->Create();


  // Add the file to the MRU list.
  //
  theApp->SaveMenuChoice(theApp->FileData.FileName);
}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~~
// Menu File Open command
//
void TApxMdiMDIClient::CmFileOpen()
{
  TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);

  // Display standard Open dialog box to select a file name.
  //
  *(theApp->FileData.FileName) = 0;
  if (TFileOpenDialog(this, theApp->FileData).Execute() == IDOK)
    OpenFile();
}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~~
// Menu File Close command
//
void TApxMdiMDIClient::CmFileClose()
{
  TApxMdiMDIChild* curChild = (TApxMdiMDIChild *)GetActiveMDIChild();

  if (curChild) {
    curChild->CloseWindow();
  }
}

//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~
// Menu File Print command
//
void TApxMdiMDIClient::CmFilePrint()
{
  // Create Printer object if not already created.
  //
  TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);
  if (theApp) {
    if (!theApp->Printer)
      theApp->Printer = new TPrinter(theApp);

    TAPointer<char> docName = new char[_MAX_PATH];

    GetActiveMDIChild()->GetWindowText(docName, _MAX_PATH);

    // Create Printout window and set characteristics.
    //
    TApxPrintout printout(theApp->Printer, docName, GetActiveMDIChild()->GetClientWindow(), true);

    theApp->Printing++;

    // Bring up the Print dialog and print the document.
    //
    theApp->Printer->Print(GetWindowPtr(GetActiveWindow()), printout, true);

    theApp->Printing--;
  }
}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~
// Menu File Print Setup command
//
void TApxMdiMDIClient::CmFilePrintSetup()
{
  TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);
  if (theApp) {
    if (!theApp->Printer)
      theApp->Printer = new TPrinter(theApp);

    // Bring up the Print Setup dialog.
    //
    theApp->Printer->Setup(this);
  }
}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~
// Menu File Print Preview command
//
void TApxMdiMDIClient::CmFilePrintPreview()
{
  TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);
  if (theApp) {
    if (!theApp->Printer)
      theApp->Printer = new TPrinter(GetApplication());

    theApp->Printing++;

    TApxPreviewWin* prevW = new TApxPreviewWin(Parent, theApp->Printer, GetActiveMDIChild()->GetClientWindow(), "Print Preview", new TLayoutWindow(0));
    prevW->Create();

    // Here we resize the preview window to take the size of the MainWindow, then
    // hide the MainWindow.
    //
    TFrameWindow * mainWindow =  GetApplication()->GetMainWindow();
    TRect r = mainWindow->GetWindowRect();
    prevW->MoveWindow(r);
    prevW->ShowWindow(SW_SHOWNORMAL);
    mainWindow->ShowWindow(SW_HIDE);

    GetApplication()->BeginModal(GetApplication()->GetMainWindow());

    // After the user closes the preview Window, we take its size and use it
    // to size the MainWindow, then show the MainWindow again.
    //
    r = prevW->GetWindowRect();
    mainWindow->MoveWindow(r);
    mainWindow->ShowWindow(SW_SHOWNORMAL);

    // We must destroy the preview window explicitly.  Otherwise, the window will
    // not be destroyed until it's parent the MainWindow is destroyed.
    //
    prevW->Destroy();
    delete prevW;

    theApp->Printing--;
  }
}


//--------------------------------------------------------
// TApxMdiMDIClient
// ~~~~~~~~~~
// Menu enabler used by Print, Print Setup and Print Preview.
//
void TApxMdiMDIClient::CmPrintEnable(TCommandEnabler& tce)
{
  if (GetActiveMDIChild()) {
    TApxMdiApp* theApp = TYPESAFE_DOWNCAST(GetApplication(), TApxMdiApp);
    if (theApp) {
      // If we have a Printer already created just test if all is okay.
      // Otherwise create a Printer object and make sure the printer really
      // exists and then delete the Printer object.
      //
      if (!theApp->Printer) {
        theApp->Printer = new TPrinter(theApp);
        tce.Enable(!theApp->Printer->GetSetup().Error);
      }
      else
        tce.Enable(!theApp->Printer->GetSetup().Error);
    }
  }
  else
    tce.Enable(false);
}


void TApxMdiMDIClient::EvDropFiles(TDropInfo)
{
  Parent->ForwardMessage();
}
