//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/applicat.h>
#include <owl/editfile.h>
#include <owl/mdi.h>
#include <owl/decmdifr.h>
#include <owl/statusba.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/gdiobjec.h>
#include <owl/ocfevent.h>
#include <owl/uihandle.h>
#include <owl/oleframe.h>

#include <ocf/ocfpch.h>
#include <ocf/ocapp.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>
#include <ocf/ocstorag.h>
#include <ocf/ocreg.h>

#include "sampcont.h"
#include "sdiole.h"

// Locations for toolbar placement
//
const TDecoratedFrame::TLocation Location[] = {
  TDecoratedFrame::Top,
  TDecoratedFrame::Left,
  TDecoratedFrame::Right
};

// App registration object
//
static TPointer<TOcRegistrar> Registrar;

// Registration tables
//
REGISTRATION_FORMAT_BUFFER(100)

BEGIN_REGISTRATION(AppReg)
 REGDATA(clsid,      "{5E4BD410-8ABC-101B-A23B-CE4E85D07ED2}")
 REGDATA(appname,    "SdiOle")
END_REGISTRATION

//----------------------------------------------------------------------------
// Ole SDI application class
//

class TOwlSdiApp : public TApplication, public TOcModule {
  public:
    TOwlSdiApp();
   ~TOwlSdiApp();
    void InitMainWindow();
    void InitInstance();

  protected:
    TOpenSaveDialog::TData   FileData;
    TGadgetWindow::THintMode HintMode;
    TOleFrame*               Frame;
    TControlBar*             ControlBar;
    int                      ControlBarLoc;

  protected:
    void CmFileNew();
    void CmFileOpen();
    void CmToggleHint();
    void CeToggleHint(TCommandEnabler&);
    void CmToggleBar();
    void CmToggleStatus();
    void CeToggleStatus(TCommandEnabler&);

  DECLARE_RESPONSE_TABLE(TOwlSdiApp);
};

DEFINE_RESPONSE_TABLE1(TOwlSdiApp, TApplication)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_TOGGLEHINT, CmToggleHint),
  EV_COMMAND_ENABLE(CM_TOGGLEHINT, CeToggleHint),
  EV_COMMAND(CM_TOGGLEBAR, CmToggleBar),
  EV_COMMAND(CM_TOGGLESTATUS, CmToggleStatus),
  EV_COMMAND_ENABLE(CM_TOGGLESTATUS, CeToggleStatus),
END_RESPONSE_TABLE;


TOwlSdiApp::TOwlSdiApp()
 : TApplication(::AppReg["appname"])
{
  // Make OC app helper
  //
  OcInit(*::Registrar, ::Registrar->GetOptions());
}

TOwlSdiApp::~TOwlSdiApp()
{
}

static TControlBar*
BuildControlBar(TWindow* parent, TControlBar::TTileDirection direction)
{
  TControlBar* cb = new TControlBar(parent, direction);
  cb->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW));
  cb->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN));
  cb->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
  cb->Insert(*new TButtonGadget(CM_FILESAVEAS, CM_FILESAVEAS));

  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cb->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cb->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cb->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));

  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_EDITFIND, CM_EDITFIND));
  cb->Insert(*new TButtonGadget(CM_EDITREPLACE, CM_EDITREPLACE));
  cb->Insert(*new TButtonGadget(CM_EDITFINDNEXT, CM_EDITFINDNEXT));

  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_TOGGLEHINT, CM_TOGGLEHINT,
                      TButtonGadget::NonExclusive));
  cb->Insert(*new TSeparatorGadget(6));
  cb->Insert(*new TButtonGadget(CM_TOGGLEBAR, CM_TOGGLEBAR));

  cb->Attr.Style |= WS_CLIPSIBLINGS;    // since toolbar may move around
  cb->Attr.Id = IDW_TOOLBAR;

  return cb;
}

//
// Construct the TOwlSdiApp's MainWindow loading its menu, accelerator table
// & icon
//
void
TOwlSdiApp::InitMainWindow()
{
  Frame = new TOleFrame(GetName(), 0, true);
  SetMainWindow(Frame);

  Frame->Attr.AccelTable = IDA_SDIFILE;
  Frame->SetMenuDescr(TMenuDescr(IDM_EDITFILE_DOC));
  Frame->SetIcon(this, IDI_SINGLEFILE);

  // Construct, build and insert a control bar into the frame. Start out at
  // the top of the frame
  //
  HintMode = TGadgetWindow::PressHints;
  ControlBarLoc = 0;
  ControlBar = BuildControlBar(Frame, TControlBar::Horizontal);
  Frame->Insert(*ControlBar, Location[ControlBarLoc]);

  // Construct a status bar & insert it at the bottom
  //
  TStatusBar* sb = new TStatusBar(0, TGadget::Recessed,
           TStatusBar::CapsLock | TStatusBar::NumLock | TStatusBar::Overtype);

  Frame->Insert(*sb, TDecoratedFrame::Bottom);

  EnableCtl3d(true);

  // Initialize the file data struct used for open and saveas
  //
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
  FileData.SetFilter(string(*this, IDS_DOCFILEFILTER).c_str());
}

//
// Call file new command handler to get the initial new window
//
void
TOwlSdiApp::InitInstance()
{
  TApplication::InitInstance();
  CmFileNew();
}

//
// Respond to "New" command by constructing, creating, and setting up a
// new TFileWindow MDI child
//
void
TOwlSdiApp::CmFileNew()
{
  // check to save old...

  TWindow* client = new TOleSampContainer(0, 0);
  TWindow* oldClient = GetMainWindow()->SetClientWindow(client);
  if (oldClient) {
    oldClient->Destroy();
    delete oldClient;
  }
}

//
// Respond to "Open" command by constructing, creating, and setting up a
// new TFileWindow, and deleting the old one
//
void
TOwlSdiApp::CmFileOpen()
{
  // check to save old...

  *FileData.FileName = 0;
  if (TFileOpenDialog(MainWindow, FileData).Execute() == IDOK) {
    TWindow* client = new TOleSampContainer(0, FileData.FileName);
    TWindow* oldClient = GetMainWindow()->SetClientWindow(client);
    if (oldClient) {
      oldClient->Destroy();
      delete oldClient;
    }
  }
}

void
TOwlSdiApp::CeToggleHint(TCommandEnabler& ce)
{
  ce.SetCheck(HintMode == TGadgetWindow::EnterHints);
}

void
TOwlSdiApp::CmToggleHint()
{
  HintMode = HintMode==TGadgetWindow::PressHints ?
               TGadgetWindow::EnterHints :
               TGadgetWindow::PressHints;

  ControlBar->SetHintMode(HintMode);
  ControlBar->SetHintCommand(-1);  // make sure we don't leave hint text dangling
}

void
TOwlSdiApp::CmToggleBar()
{
  ControlBarLoc = (ControlBarLoc+1) % COUNTOF(Location);
  ControlBar->SetDirection(ControlBarLoc==0 ?
                           TControlBar::Horizontal : TControlBar::Vertical);
  Frame->Insert(*ControlBar, Location[ControlBarLoc]);
  Frame->Layout();
}

void
TOwlSdiApp::CeToggleStatus(TCommandEnabler& ce)
{
  ce.SetCheck(GetMainWindow()->ChildWithId(IDW_STATUSBAR)->IsWindowVisible());
}

void
TOwlSdiApp::CmToggleStatus()
{
  GetMainWindow()->SendMessage(WM_COMMAND, IDW_STATUSBAR);  // toggle status bar on/off
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  ::Registrar = new TOcRegistrar(::AppReg, 0, TApplication::GetCmdLine());
  if (::Registrar->IsOptionSet(amAnyRegOption))
    return 0;
  return TOwlSdiApp().Run();
}
