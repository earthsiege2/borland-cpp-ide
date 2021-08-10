//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/editfile.h>
#include <owl/mdi.h>
#include <owl/decmdifr.h>
#include <owl/statusba.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/gdiobjec.h>
#include <owl/olemdifr.h>
#include <owl/uihelper.h>
#include <ocf/ocdoc.h>
#include <ocf/ocview.h>

#include "sampcont.h"
#include "mdiole.h"

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
 REGDATA(clsid,      "{5E4BD400-8ABC-101B-A23B-CE4E85D07ED2}")
 REGDATA(appname,    "MdiOle")
END_REGISTRATION

//----------------------------------------------------------------------------
// Ole MDI application class
//

class TOwlMdiApp : public TApplication, public TOcModule {
  public:
    TOwlMdiApp();
   ~TOwlMdiApp();
    void InitMainWindow();
    void InitInstance();

  protected:
    TOpenSaveDialog::TData   FileData;
    TMDIClient*              Client;
    TGadgetWindow::THintMode HintMode;
    TOleMDIFrame*            Frame;
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

  DECLARE_RESPONSE_TABLE(TOwlMdiApp);
};

DEFINE_RESPONSE_TABLE1(TOwlMdiApp, TApplication)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_TOGGLEHINT, CmToggleHint),
  EV_COMMAND_ENABLE(CM_TOGGLEHINT, CeToggleHint),
  EV_COMMAND(CM_TOGGLEBAR, CmToggleBar),
  EV_COMMAND(CM_TOGGLESTATUS, CmToggleStatus),
  EV_COMMAND_ENABLE(CM_TOGGLESTATUS, CeToggleStatus),
END_RESPONSE_TABLE;


TOwlMdiApp::TOwlMdiApp()
 : TApplication(::AppReg["appname"])
{
  // Make OC app helper
  //
  OcInit(*::Registrar, ::Registrar->GetOptions());
}

TOwlMdiApp::~TOwlMdiApp()
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
  cb->Attr.Id = IDW_TOOLBAR;            // From oleframe.h, so we can hide it

  return cb;
}

//
// Construct the TOwlMdiApp's MainWindow of class TMDIFileWindow,
// loading its menu, accelerator table & icon
//
void
TOwlMdiApp::InitMainWindow()
{
  Client = new TMDIClient;
  Frame = new TOleMDIFrame(GetName(), IDM_EDITFILE_DOC, *Client, true);
  SetMainWindow(Frame);

  Frame->Attr.AccelTable = IDA_MDIFILE;
  Frame->SetMenuDescr(TMenuDescr(IDM_EDITFILE_DOC));
  Frame->SetIcon(this, IDI_MULTIFILE);

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
TOwlMdiApp::InitInstance()
{
  TApplication::InitInstance();
  CmFileNew();
}

//
// Respond to "New" command by constructing, creating, and setting up a
// new TFileWindow MDI child
//
void
TOwlMdiApp::CmFileNew()
{
  TMDIChild* child = new TMDIChild(*Client, "", new TOleSampContainer(0, 0));
  child->SetMenuDescr(TMenuDescr(IDM_EDITFILE_CHILD));
  child->SetIcon(this, IDI_DOC);

  TMDIChild* curChild = Client->GetActiveMDIChild();
  if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
    child->Attr.Style |= WS_MAXIMIZE;

  child->Create();
}

//
// Respond to "Open" command by constructing, creating, and setting up a
// new TFileWindow in an MDI child
//
void
TOwlMdiApp::CmFileOpen()
{
  *FileData.FileName = 0;
  if (TFileOpenDialog(MainWindow, FileData).Execute() == IDOK) {
  
    TMDIChild* child;
    
    TRY {
      child = new TMDIChild(*Client, "", new TOleSampContainer(0, FileData.FileName));
    }
    CATCH( (TXObjComp& x) {
      GetMainWindow()->MessageBox(x.why().c_str(), GetName(), 
        MB_OK|MB_ICONEXCLAMATION);
      return;
    })
    
    child->SetMenuDescr(TMenuDescr(IDM_EDITFILE_CHILD));
    child->SetIcon(this, IDI_DOC);

    TMDIChild* curChild = Client->GetActiveMDIChild();
    if (curChild && (curChild->GetWindowLong(GWL_STYLE) & WS_MAXIMIZE))
      child->Attr.Style |= WS_MAXIMIZE;

    child->Create();
  }
}

void
DoCreateChild(TWindow* win, void*)
{
  if (win->IsFlagSet(wfAutoCreate))
    win->Create();
}

void
TOwlMdiApp::CeToggleHint(TCommandEnabler& ce)
{
  ce.SetCheck(HintMode == TGadgetWindow::EnterHints);
}

void
TOwlMdiApp::CmToggleHint()
{
  HintMode = HintMode==TGadgetWindow::PressHints ?
               TGadgetWindow::EnterHints :
               TGadgetWindow::PressHints;

  ControlBar->SetHintMode(HintMode);
  ControlBar->SetHintCommand(-1);  // make sure we don't leave hint text dangling
}

void
TOwlMdiApp::CmToggleBar()
{
  ControlBarLoc = (ControlBarLoc+1) % COUNTOF(Location);
  ControlBar->SetDirection(ControlBarLoc==0 ?
                           TControlBar::Horizontal : TControlBar::Vertical);
  Frame->Insert(*ControlBar, Location[ControlBarLoc]);
  Frame->Layout();
}

void
TOwlMdiApp::CeToggleStatus(TCommandEnabler& ce)
{
  ce.SetCheck(GetMainWindow()->ChildWithId(IDW_STATUSBAR)->IsWindowVisible());
}

void
TOwlMdiApp::CmToggleStatus()
{
  GetMainWindow()->SendMessage(WM_COMMAND, IDW_STATUSBAR);  // toggle status bar on/off
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  ::Registrar = new TOcRegistrar(::AppReg, 0, TApplication::GetCmdLine());
  if (::Registrar->IsOptionSet(amAnyRegOption))
    return 0;
  return TOwlMdiApp().Run();
}
