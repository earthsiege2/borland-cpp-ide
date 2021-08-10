//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- step13.cpp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/decmdifr.h>
#include <owl/dialog.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <owl/docmanag.h>
#include <stdlib.h>
#include <string.h>
#include "step13.rc"

class TDrawApp : public TApplication {
  public:
    TDrawApp() : TApplication() {}

  protected:
    // Override methods of TApplication
    void InitInstance();
    void InitMainWindow();

    // Event handlers
    void EvNewView  (TView& view);
    void EvCloseView(TView& view);
    void EvDropFiles(TDropInfo dropInfo);
    void CmAbout();

    TMDIClient* Client;
  DECLARE_RESPONSE_TABLE(TDrawApp);
};

DEFINE_RESPONSE_TABLE1(TDrawApp, TApplication)
  EV_OWLVIEW(dnCreate, EvNewView),
  EV_OWLVIEW(dnClose,  EvCloseView),
  EV_WM_DROPFILES,
  EV_COMMAND(CM_ABOUT, CmAbout),
END_RESPONSE_TABLE;

void
TDrawApp::InitMainWindow()
{
  // Construct the decorated frame window
  TDecoratedMDIFrame* frame = new TDecoratedMDIFrame("Drawing Pad", 0,
                                    *(Client = new TMDIClient), true);
  // Construct a status bar
  TStatusBar* sb = new TStatusBar(frame, TGadget::Recessed);

  // Construct a control bar
  TControlBar* cb = new TControlBar(frame);
  cb->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_FILESAVEAS, CM_FILESAVEAS, TButtonGadget::Command));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_PENSIZE, CM_PENSIZE, TButtonGadget::Command));
  cb->Insert(*new TButtonGadget(CM_PENCOLOR, CM_PENCOLOR, TButtonGadget::Command));
  cb->Insert(*new TSeparatorGadget);
  cb->Insert(*new TButtonGadget(CM_ABOUT, CM_ABOUT, TButtonGadget::Command));
  cb->SetHintMode(TGadgetWindow::EnterHints);

  // Insert the status bar and control bar into the frame
  frame->Insert(*sb, TDecoratedFrame::Bottom);
  frame->Insert(*cb, TDecoratedFrame::Top);

  // Set the main window and its menu
  SetMainWindow(frame);
  GetMainWindow()->SetMenuDescr(TMenuDescr("COMMANDS",1,1,0,0,1,1));

  // Install the document manager
  SetDocManager(new TDocManager(dmMDI | dmMenu));
}

void
TDrawApp::InitInstance()
{
  TApplication::InitInstance();
  GetMainWindow()->DragAcceptFiles(true);
}

void
TDrawApp::EvDropFiles(TDropInfo dropInfo)
{
  int fileCount = dropInfo.DragQueryFileCount();
  for (int index = 0; index < fileCount; index++) {
    int fileLength = dropInfo.DragQueryFileNameLen(index)+1;
    char* filePath = new char [fileLength];
    dropInfo.DragQueryFile(index, filePath, fileLength);
    TDocTemplate* tpl = GetDocManager()->MatchTemplate(filePath);
    if (tpl)
      tpl->CreateDoc(filePath);
    delete filePath;
  }
  dropInfo.DragFinish();
}

void
TDrawApp::EvNewView(TView& view)
{
  TMDIChild* child = new TMDIChild(*Client, 0, view.GetWindow());
  if (view.GetViewMenu())
    child->SetMenuDescr(*view.GetViewMenu());
  child->Create();
}

void
TDrawApp::EvCloseView(TView& /*view*/)
{
  // Nothing needs to be done here for MDI
}

void
TDrawApp::CmAbout()
{
  TDialog(GetMainWindow(), IDD_ABOUT).Execute();
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}
