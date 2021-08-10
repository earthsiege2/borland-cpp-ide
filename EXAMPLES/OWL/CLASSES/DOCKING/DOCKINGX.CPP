//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Docking window example main source file
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/printer.h>
#include <owl/buttonga.h>
#include <owl/textgadg.h>
#include <owl/controlb.h>
#include <owl/controlg.h>
#include <owl/statusba.h>
#include <owl/docking.h>
#include <owl/combobox.h>
#include <owl/edit.h>
#include <owl/decmdifr.h>
#include <owl/editfile.h>
#include <dir.h>
#include "docking.h"

//
// Build a response table for all messages/commands handled
// by the application.
//
DEFINE_RESPONSE_TABLE1(TDockingApp, TApplication)
//{{TDockingAppRSP_TBL_BEGIN}}
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
  EV_COMMAND(CM_MDIFILENEW, CmFileNew),
  EV_COMMAND(CM_MDIFILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILEPRINT, CmFilePrint),
  EV_COMMAND(CM_FILEPRINTERSETUP, CmFilePrintSetup),
  EV_COMMAND(CM_FILEPRINTPREVIEW, CmFilePrintPreview),
  EV_COMMAND_ENABLE(CM_FILEPRINT, CePrint),
  EV_COMMAND_ENABLE(CM_FILEPRINTERSETUP, CePrint),
  EV_COMMAND_ENABLE(CM_FILEPRINTPREVIEW, CePrint),
END_RESPONSE_TABLE;


//
//
//
TDockingApp::TDockingApp()
:
  TApplication("Docking Example")
{
}


TDockingApp::~TDockingApp()
{
}

static TDockable* newSpeedbar(TDecoratedFrame* frame, const char far* caption)
{
  // Create command toolbar and associate toolbar buttons with commands.
  //
  TDockableControlBar* cb = new TDockableControlBar(frame);
  cb->SetCaption(caption);
  cb->Insert(*new TButtonGadget(CM_MDIFILENEW, CM_MDIFILENEW));
  cb->Insert(*new TButtonGadget(CM_MDIFILEOPEN, CM_MDIFILEOPEN));
  cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cb->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cb->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_EDITREDO, CM_EDITREDO));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_EDITFIND, CM_EDITFIND));
  cb->Insert(*new TButtonGadget(CM_EDITFINDNEXT, CM_EDITFINDNEXT));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));
  cb->Insert(*new TButtonGadget(CM_FILEPRINTPREVIEW, CM_FILEPRINTPREVIEW));

  // Add fly-over help hints.
  cb->SetHintMode(TGadgetWindow::EnterHints);
  return cb;
}

void TDockingApp::SetupSpeedBar(TDecoratedFrame* frame)
{
  Harbor = new THarbor(*frame);

  // Create text style toolbar and associate toolbar buttons with commands.
  //
  TDockableControlBar* cb2 = new TDockableControlBar(frame);
  cb2->SetCaption("Toolbar with Combobox");
  TComboBox* cBox = new TComboBox(0, 500, 0, 0, 180, 150, CBS_DROPDOWNLIST, 20);
  cb2->Insert(*new TControlGadget(*cBox));
  cb2->Insert(*new TSeparatorGadget);
  cb2->Insert(*new TControlGadget(*new TComboBox(0, 510, 0, 0, 50, 100, CBS_DROPDOWNLIST, 20)));
  cb2->Insert(*new TSeparatorGadget);
  cb2->Insert(*new TButtonGadget(CM_FONTBOLD, CM_FONTBOLD));
  cb2->Insert(*new TSeparatorGadget);
  cb2->Insert(*new TButtonGadget(CM_FONTITALIC, CM_FONTITALIC));
  cb2->Insert(*new TSeparatorGadget);
  cb2->Insert(*new TButtonGadget(CM_FONTUNDER, CM_FONTUNDER));
  cb2->Insert(*new TSeparatorGadget);
  cb2->Insert(*new TButtonGadget(CM_FONTLEFT, CM_FONTLEFT));
  cb2->Insert(*new TButtonGadget(CM_FONTRIGHT, CM_FONTRIGHT));
  cb2->Insert(*new TButtonGadget(CM_FONTCENTER, CM_FONTCENTER));

  Harbor->Insert(*cb2, alTop);
  Harbor->Insert(*newSpeedbar(frame, "Toolbar 1"), alTop);
  Harbor->Insert(*newSpeedbar(frame, "Toolbar 2"), alRight);

  // Create coord toolbar and associate toolbar buttons with commands.
  //
  TDockableControlBar* cb3 = new TDockableControlBar(frame);
  cb3->SetCaption("Toolbar with Edit controls");

  cb3->Insert(*new TTextGadget(650, TGadget::None, TTextGadget::Left, 1, "X"));
  cb3->Insert(*new TControlGadget(*new TEdit(0, 651, "10", 0, 0, 60, 24, 4)));
  cb3->Insert(*new TSeparatorGadget);

  cb3->Insert(*new TTextGadget(660, TGadget::None, TTextGadget::Left, 1, "Y"));
  cb3->Insert(*new TControlGadget(*new TEdit(0, 661, "20", 0, 0, 60, 24, 4)));
  cb3->Insert(*new TSeparatorGadget);

  cb3->Insert(*new TTextGadget(670, TGadget::None, TTextGadget::Left, 1, "W"));
  cb3->Insert(*new TControlGadget(*new TEdit(0, 671, "30", 0, 0, 60, 24, 4)));
  cb3->Insert(*new TSeparatorGadget);

  cb3->Insert(*new TTextGadget(680, TGadget::None, TTextGadget::Left, 1, "H"));
  cb3->Insert(*new TControlGadget(*new TEdit(0, 681, "40", 0, 0, 60, 24, 4)));

  Harbor->Insert(*cb3, alLeft);
}

//
// Application intialization.
//
void TDockingApp::InitMainWindow()
{
  if (nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  MdiClient = new TMDIClient;
  TDecoratedMDIFrame* frame = new TDecoratedMDIFrame(Name, IDM_MAIN, *MdiClient, true);

  // Assign ICON w/ this application.
  //
  frame->SetIcon(this, IDI_MDIAPPLICATION);

  // Associate with the accelerator table.
  //
  frame->Attr.AccelTable = IDA_MAIN;

  SetupSpeedBar(frame);

  TStatusBar *sb = new TStatusBar(frame, TGadget::Recessed,
                  TStatusBar::CapsLock | TStatusBar::NumLock |
                  TStatusBar::ScrollLock | TStatusBar::SizeGrip);
  frame->Insert(*sb, TDecoratedFrame::Bottom);

  SetMainWindow(frame);

  frame->SetMenuDescr(TMenuDescr(IDM_MAIN, 1, 2, 0, 0, 1, 1));
}


//
// Menu Help About palette.exe command
//
void TDockingApp::CmHelpAbout()
{
  GetMainWindow()->MessageBox("Dockable toolbar Example", "About", MB_OK);
}

void TDockingApp::CmFileNew()
{
  char  title[255];

  // Generate a title for the MDI child window.
  //
  wsprintf(title, "%d", ChildCount++);

  TMDIChild* child = new TMDIChild(*MdiClient, title, new TEditFile(0, 0, 0));

  // Associate ICON w/ this child window.
  //
  child->SetIcon(this, IDI_DOC);

  // If the current active MDI child is maximize then this one should be also.
  //
  TMDIChild* curChild = MdiClient->GetActiveMDIChild();
  if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
    child->Attr.Style |= WS_MAXIMIZE;

  child->Create();
}

void TDockingApp::OpenFile(const char* fileName)
{
  if (fileName)
    strcpy(FileData.FileName, fileName);

  // Create a MDIChild window whose client is TEditFile.
  //
  TMDIChild* child = new TMDIChild(*MdiClient, "",
    new TEditFile(0, 0, 0, 0, 0, 0, 0, FileData.FileName));

  // Associate ICON w/ this child window.
  //
  child->SetIcon(this, IDI_DOC);

  // If the current active MDI child is maximize then this one should be also.
  //
  TMDIChild* curChild = MdiClient->GetActiveMDIChild();
  if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
    child->Attr.Style |= WS_MAXIMIZE;

  child->Create();
}

//
// Menu File Open command
//
void TDockingApp::CmFileOpen()
{
  // Display standard Open dialog box to select a file name.
  //
  *FileData.FileName = 0;
  if (TFileOpenDialog(GetMainWindow(), FileData).Execute() == IDOK)
    OpenFile();
}

//
// Menu File Print command
//
void TDockingApp::CmFilePrint()
{
}

//
// Menu File Print Setup command
//
void TDockingApp::CmFilePrintSetup()
{
}

//
// Menu File Print Preview command
//
void TDockingApp::CmFilePrintPreview()
{
}

//
// Menu enabler used by Print, Print Setup and Print Preview.
//
void TDockingApp::CePrint(TCommandEnabler& ce)
{
  ce.Enable(true);
}

int OwlMain(int , char* [])
{
  return TDockingApp().Run();
}
