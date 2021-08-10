//----------------------------------------------------------------------------
//  ObjectWindows
//
//  OWLAPP.CPP
//  
//  Creates an OWL application with an OWL frame window, but uses a VCL
//  form as the client window.  
//
//  Copyright (c) 1997 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
// #include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/decframe.h>
#include <owl/statusba.h>
#include <vcl/vcl.h>
#pragma hdrstop

#include "htmlform.h"
#include "adopt.h"
#include "main.rh"

//
// Array of URLs corresponding to choices on the Sites menu
//
char* Sites[] = {
  "http://www.borland.com/borlandcpp/owl/owl.html",      // Borland OWL
  "http://www.cs.rpi.edu/~wiseb/owl-list/",              // mailing list
  "http://www.mdex.net/~kentr/bc50faq.htm",              // Borland C++ FAQ
  "http://www.borland.com/bcppbuilder/",                 // C++Builder
  "http://www.bby.com.au/%7Egnb/wp/jan96/index.html",    // Jan96 C++ wp
  
  // Here's another great OWL site, but it uses HTML features
  // that the NetManage ActiveX HTML browser control does not
  // support, so there's no point having it on this menu.
  //
  // "http://www.pfdpf.state.oh.us/msawczyn/owl/files/",    // OWL sources
};

//----------------------------------------------------------------------------
//
// class TMyApp
// ~~~~~ ~~~~~~
// 
class TMyApp: public OWL::TApplication
{
public:
  TMyApp(const char* name): OWL::TApplication(name) {}
  void InitMainWindow();
};

//----------------------------------------------------------------------------
//
// class TMyFrame
// ~~~~~ ~~~~~~~~
//
class TMyFrame: public TDecoratedFrame
{
public:
  // The constructor turns off menu tracking in the base
  // decorated frame because it won't work.  OWL and VCL
  // assign the same ID to different resource strings.  As
  // a result of the conflict, if you turn menu tracking on,
  // irrelevant VCL strings appear as hints on the status
  // bar when you select commands from the frame's system menu.
  //
  TMyFrame(TWindow* parent, const char far *title = 0,
           TWindow* clientWnd = 0)
      : TDecoratedFrame(parent, title, clientWnd,
                        /*trackMenuSelection*/ false) {}
  void SetupWindow(void);
protected:
  void CmSite(TParam1 cmdId);
DECLARE_RESPONSE_TABLE(TMyFrame);
};

//----------------------------------------------------------------------------
//
// class TVCLFormClient
// ~~~~~ ~~~~~~~~~~~~~~
// OWL alias for an HWND created by VCL's TForm class
//
class TVCLFormClient: public TWindow {
public:
  TVCLFormClient(TWindow* parent = 0)
      : Form(0), TWindow(parent) {}
  void PerformCreate(int menuOrId);
  void SetURL(const char* _URL);
  const char* GetURL();
  void SetParentProperty(HWND hWnd);
  void MakeVisible();

protected:
  bool PreProcessMsg(MSG &msg);
  
private:
  char URL[2048];
  TPointer<TForm1> Form;
};

//----------------------------------------------------------------------------
// TMyApp implementation
//

void
TMyApp::InitMainWindow()
{
  TMyFrame* frame = new TMyFrame(0, GetName(), new TVCLFormClient());
  SetMainWindow(frame);

  // Add an OWL status bar to the bottom of the frame
  //
  OWL::TStatusBar*  sbar = new OWL::TStatusBar(frame, TGadget::None,
                                         OWL::TStatusBar::SizeGrip);
  sbar->SetWideHints(false);
  sbar->Insert(TTextGadget(ID_TEXTGADGET, TGadget::None));
  frame->Insert(*sbar, TDecoratedFrame::Bottom);

  // Tell the window what menu to present
  //
  GetMainWindow()->AssignMenu(IDM_MAINMENU);
}

//----------------------------------------------------------------------------
// TMyFrame implementation
//

//
// When frame window exists, adopt the VCL application window
// and display the client form.
//
void
TMyFrame::SetupWindow()
{
  TFrameWindow::SetupWindow();
  AdoptVCLAppWindow(GetHandle());

  // Remove the outline the form wants to draw around itself
  // and then make the form draw itself on the screen.
  // 
  TVCLFormClient* form = TYPESAFE_DOWNCAST(GetClientWindow(), TVCLFormClient);
  form->ModifyStyle(WS_BORDER, 0);
  form->MakeVisible();
}

//
//
//
void
TMyFrame::CmSite(TParam1 cmdId)
{
  uint index = cmdId - CM_CMDBASE;
  TVCLFormClient* form = TYPESAFE_DOWNCAST(GetClientWindow(), TVCLFormClient);
  if (form)
    form->SetURL(Sites[index]);
}

DEFINE_RESPONSE_TABLE1(TMyFrame, TDecoratedFrame)
  EV_COMMAND_AND_ID(CM_BORLANDOWL,  CmSite),
  EV_COMMAND_AND_ID(CM_OWLLIST,     CmSite),
  EV_COMMAND_AND_ID(CM_BCFAQ,       CmSite),
  EV_COMMAND_AND_ID(CM_CBUILDER,    CmSite),  
  EV_COMMAND_AND_ID(CM_CPPWP,       CmSite),
END_RESPONSE_TABLE;

//----------------------------------------------------------------------------
// TVCLFormClient implementation
//

//
// Override a TWindow virtual to create the HWND directly.
// TVCLFormClient and the VCL TForm1 class both end up 
// wrapping the same HWND.
//
void
TVCLFormClient::PerformCreate(int /*menuOrId*/)
{
  PRECONDITION(!Form);

  // create the actual VCL form object
  //
  Form = new TForm1(Parent->GetHandle());
  if (Form) {
    CHECK(Form->Handle);

    // Give the OWL TWindow object the handle of the Windows
    // object it aliases
    //
    SetHandle(Form->Handle);
  }
}

//
// Let the form process keystrokes in its own way.  Without
// this method, you can't tab between control on the form.
//
bool
TVCLFormClient::PreProcessMsg(MSG &msg)
{
  // Duplicates the code in FORMS.PAS for IsKeyMsg()
  //
  if ((msg.message >= WM_KEYFIRST) && (msg.message <= WM_KEYLAST) &&
      (GetCapture() == 0)) {
    if (SendMessage(CN_BASE + msg.message, msg.wParam, msg.lParam) != 0)
      return true;
  }
  
  return IsDialogMessage(GetHandle(), &msg);
}

//
//
//
void
TVCLFormClient::MakeVisible()
{
  Form->Visible = true;
}

//
//
//
void
TVCLFormClient::SetParentProperty(HWND hwnd)
{
  PRECONDITION(Form);  
  Form->ParentWindow = hwnd;
}

//
//
//
void
TVCLFormClient::SetURL(const char* _URL)
{
  if (_URL) {
    strcpy(URL, _URL);
    if (Form)
      Form->RetrieveURL(URL);
  }
}

//
//
//
const char*
TVCLFormClient::GetURL()
{
  return URL;
}

//----------------------------------------------------------------------------
// OwlMain
//

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyApp("OWL App").Run();
}
