//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- step15.cpp
//   Embed/Linking Server example
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/dialog.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/statusba.h>
#include <owl/docmanag.h>
#include <owl/olemdifr.h>
#include <owl/oleview.h>
#include <stdlib.h>
#include <string.h>
#include "step15.rc"

DEFINE_APP_DICTIONARY(AppDictionary);
static TPointer<TOcRegistrar> Registrar;

// Registration
//
REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
  REGDATA(clsid,      "{5E4BD320-8ABC-101B-A23B-CE4E85D07ED2}")
  REGDATA(appname,    "DrawPad Server")
END_REGISTRATION

//
// TDrawApp
//
class _USERCLASS TDrawApp : public TApplication, public TOcModule {
  public:
    TDrawApp() :
      TApplication(::AppReg["appname"], ::Module, &::AppDictionary) {}

  protected:
    TMDIClient*      Client;

    // Override methods of TApplication
    void InitInstance();
    void InitMainWindow();

    // Event handlers
    void EvNewView(TView& view);
    void EvCloseView(TView& view);
    void EvDropFiles(TDropInfo dropInfo);
    void CmAbout();

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
  TOleMDIFrame* frame;
  frame = new TOleMDIFrame(GetName(), 0, *(Client = new TMDIClient(this)), true, this);

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

  cb->Attr.Id = IDW_TOOLBAR;

  // Insert the status bar and control bar into the frame
  frame->Insert(*sb, TDecoratedFrame::Bottom);
  frame->Insert(*cb, TDecoratedFrame::Top);

  // Set the main window and its menu
  SetMainWindow(frame);
  GetMainWindow()->SetMenuDescr(TMenuDescr(IDM_MDICMNDS));

  // Install the document manager
  SetDocManager(new TDocManager(dmMDI, this));
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
    GetDocManager()->CreateDoc(tpl, filePath);
    delete filePath;
  }
  dropInfo.DragFinish();
}

void
TDrawApp::EvNewView(TView& view)
{
  TOleView* ov = TYPESAFE_DOWNCAST(&view, TOleView);
  if (view.GetDocument().IsEmbedded() && ov && !ov->IsOpenEditing()) {
    TWindow* vw = view.GetWindow();
    vw->SetParent(TYPESAFE_DOWNCAST(GetMainWindow(), TOleFrame)->GetRemViewBucket());
    vw->Create();
  }
  else {
    TMDIChild* child = new TMDIChild(*Client, 0);
    if (view.GetViewMenu())
      child->SetMenuDescr(*view.GetViewMenu());
    child->Create();
    child->SetClientWindow(view.GetWindow());
  }

  if (!ov || !ov->GetOcRemView())
    OcApp->SetOption(amEmbedding, false);
}

void
TDrawApp::EvCloseView(TView& /*view*/)
{
  // nothing needs to be done here for MDI
}

void
TDrawApp::CmAbout()
{
  TDialog(&TWindow(::GetFocus(), this), IDD_ABOUT).Execute();
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  try {
    Registrar = new TOcRegistrar(AppReg, TOleDocViewFactory<TDrawApp>(),
                                 TApplication::GetCmdLine(), ::DocTemplateStaticHead);
    if (Registrar->IsOptionSet(amAnyRegOption))
      return 0;

    // If this is an exe server normal run, run the app now. Otherwise, wait
    // until our factory gets a call (don't call us, we'll call you)
    //
    return Registrar->Run();
  }
  catch (xmsg& x) {
    ::MessageBox(0, x.why().c_str(), "Exception", MB_OK);
  }
  return -1;
}
