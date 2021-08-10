//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//
// This is a sample application using the OWL library that demonstrats the
// use of the Windows 3.1 DDEML API in a client application.  You should
// first build the server application, DDESVR.EXE, and run it.  Then run the
// client application, DDECLI.EXE, to start a conversation.  Detailed
// information on DDEML can found in the online help and is suggested
// reading for anyone interested in writing DDEML applications.  Search on
// the keyword DDEML.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <owl\menu.h>
#include <owl\inputdia.h>
#include "ddecli.rh"
#include <ddeml.h>
#include <stdio.h>
#include <string.h>

class TDMLClWnd;

class TDMLClApp : public TApplication {
  public:
    TDMLClApp() : TApplication(),CallBackProc((FARPROC)CallBack) {
      InstId = 0;
      }
    void InitMainWindow();
    void InitInstance();
    int TermInstance(int status);

    DWORD   InstId;
    static HDDEDATA FAR PASCAL _export CallBack(WORD, WORD, HCONV, HSZ, HSZ,
                                                HDDEDATA, DWORD, DWORD);

    TProcInstance CallBackProc;
};


class TDMLClWnd : public TFrameWindow {
  public:
    TDMLClWnd(TWindow*, const char*);
    virtual ~TDMLClWnd();

    virtual void SetupWindow();

    void EvPaint();
    void EvInitMenu(HMENU);
    void CmConnect();
    void CmRequest();
    void CmPoke();
    void CmAdvise(WPARAM id);
    void CmHelpAbout();

    void ReceivedData(HDDEDATA);

    DWORD   InstId() {
      return ((TDMLClApp*)GetApplication())->InstId;
      }

    char    Data[128];
    HCONV   HConv;
    BOOL    Loop;
    HSZ     Service;
    HSZ     Topic;
    HSZ     Item;

  DECLARE_RESPONSE_TABLE(TDMLClWnd);
};

DEFINE_RESPONSE_TABLE1(TDMLClWnd, TFrameWindow)
  EV_WM_PAINT,
  EV_WM_INITMENU,
  EV_COMMAND(CM_CONNECT, CmConnect),
  EV_COMMAND(CM_REQUEST, CmRequest),
  EV_COMMAND(CM_POKE, CmPoke),
  EV_COMMAND_AND_ID(CM_ADVISE, CmAdvise),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
END_RESPONSE_TABLE;

static TDMLClWnd* This = 0;

TDMLClWnd::TDMLClWnd(TWindow* parent, const char* title)
  : TFrameWindow(parent, title),
    TWindow(parent, title)
{
  Data[0] = 0;
  HConv = 0;
  Loop = 0;
}

TDMLClWnd::~TDMLClWnd()
{
  // This clean up is required for those resources that were allocated during
  // the DDEML conversation.
  //
  if (HConv)
    DdeDisconnect(HConv);     // Let the other party know we are leaving

  if (InstId()) {
    DdeFreeStringHandle(InstId(), Service);
    DdeFreeStringHandle(InstId(), Topic);
    DdeFreeStringHandle(InstId(), Item);
    }
}

void
TDMLClWnd::SetupWindow()
{
  This = this;
  TFrameWindow::SetupWindow();

  AssignMenu(TDMLClWnd_MENU);

  Service = Topic = Item = 0;

  Service = DdeCreateStringHandle(InstId(), "TDMLSR_Server", CP_WINANSI);
  Topic = DdeCreateStringHandle(InstId(), "Borland", CP_WINANSI);
  Item = DdeCreateStringHandle(InstId(), "Products", CP_WINANSI);
  if (!Service || !Topic || !Item) {
    MessageBox("Creation of strings failed.", Title, MB_ICONSTOP);
    PostQuitMessage(0);
  }
}

void
TDMLClWnd::EvPaint()
{
  TPaintDC paintDC(HWindow);
  TRect rect;
  char msg[] = "This example of the Dynamic Data Exchange Management "
               "Library obtains the names of various Borland products "
               "from the server DDESVR.EXE. To get started, first run "
               "DDESVR.EXE and then select the \"Connect!\" menu item.";

  GetClientRect(rect);
  if (*Data)
    // The Data string is obtained from the DDESVR.EXE DDE Server.
    paintDC.DrawText(Data, strlen(Data), rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
  else
    paintDC.DrawText(msg, strlen(msg), rect, DT_WORDBREAK);
}

void
TDMLClWnd::EvInitMenu(HMENU menuHandle)
{
  // This technique is used to automatically update the status of the various
  // menu choices just before the menu is displayed.
  //
  TMenu menu(menuHandle);
  menu.EnableMenuItem(CM_CONNECT, !HConv ? MF_ENABLED : MF_GRAYED);
  menu.EnableMenuItem(CM_REQUEST, HConv ? MF_ENABLED : MF_GRAYED);
  menu.EnableMenuItem(CM_POKE, HConv ? MF_ENABLED : MF_GRAYED);
  menu.EnableMenuItem(CM_ADVISE, HConv ? MF_ENABLED : MF_GRAYED);
  menu.CheckMenuItem(CM_ADVISE, MF_BYCOMMAND | Loop ? MF_CHECKED : MF_UNCHECKED);
  DrawMenuBar();
}

//
// The following 4 functions are used to communicate with DDE Server(s).
//

void
TDMLClWnd::CmConnect()
{
  HConv = DdeConnect(InstId(),Service, Topic, 0);
  if (HConv)
    PostMessage(WM_INITMENU, WPARAM(GetMenu()));
  else
    MessageBox("Can't start conversation.\nTry running DDESVR (the server).",
               Title,
               MB_ICONSTOP);
}

//
// Request a data item. ReceiveData will be called asynchronously by the
// callback 
//
void
TDMLClWnd::CmRequest()
{
  DdeClientTransaction(0, 0, HConv, Item, CF_TEXT, XTYP_REQUEST, TIMEOUT_ASYNC, 0);
}

//
// Poke a string over to the server
//
void
TDMLClWnd::CmPoke()
{
  char buff[42] = "";
  if (TInputDialog(this, Title, "Poke string: ", buff, sizeof buff).Execute() == IDOK)
    DdeClientTransaction((unsigned char*)buff, strlen(buff)+1, HConv, Item, CF_TEXT, XTYP_POKE, 1000, 0);
}

//
// Start or stop a continuous advise loop.
//
void
TDMLClWnd::CmAdvise(WPARAM id)
{
  TMenu menu(GetMenu());
  if (menu.GetMenuState(id, MF_BYCOMMAND) == MF_UNCHECKED) {
    DWORD temp;
    if (DdeClientTransaction(0, 0, HConv, Item, CF_TEXT, XTYP_ADVSTART | XTYPF_ACKREQ, 1000, &temp)) {
      menu.CheckMenuItem(id, MF_BYCOMMAND | MF_CHECKED);
      Loop = TRUE;
    }
  } else {
    DWORD temp;
    if (DdeClientTransaction(0, 0, HConv, Item, CF_TEXT, XTYP_ADVSTOP, 1000, &temp)) {
      menu.CheckMenuItem(id, MF_BYCOMMAND | MF_UNCHECKED);
      Loop = FALSE;
    }
  }
  DrawMenuBar();
}

void
TDMLClWnd::CmHelpAbout()
{
  MessageBox("DDECLI.EXE\nWritten using ObjectWindows\n"
             "Copyright (c) 1991, 1993 by Borland International",
             "About DDECLI", MB_ICONINFORMATION);
}

//
// This function is called when the callback function is notified of
// available data.
//
void
TDMLClWnd::ReceivedData(HDDEDATA hData)
{
  if (hData) {
    DdeGetData(hData, (unsigned char*)Data, sizeof Data, 0);
    Invalidate(TRUE);
  }
}


//
// This call back function is the heart of interaction between this program
// and DDEML.  Because Windows doesn't pass C++ 'this' pointers to call
// back functions, a static 'this' pointer was used.  If you wanted to
// create a Client that would allow for more than one conversation, using a
// List of conversations and their associated 'this' pointers would be one
// possible method to try.  The XTYP_ constants are described in detail in
// the online help.
//
HDDEDATA FAR PASCAL _export
TDMLClApp::CallBack(WORD type, WORD, HCONV hConv, HSZ, HSZ, HDDEDATA hData,
                    DWORD, DWORD)
{
  switch (type) {
    case XTYP_ADVDATA:
      if (hConv == This->HConv)
        This->ReceivedData(hData);
      return (HDDEDATA)DDE_FACK;

    case XTYP_XACT_COMPLETE:
      if (hConv == This->HConv)
        This->ReceivedData(hData);
      break;

    case XTYP_DISCONNECT:
      This->MessageBox("Disconnected.", This->Title, MB_ICONINFORMATION);
      This->HConv = 0;
      This->Loop = 0;
      This->PostMessage(WM_INITMENU, WPARAM(This->GetMenu()));
      break;

    case XTYP_ERROR:
      This->MessageBox("A critical DDE error has occured.", This->Title, MB_ICONINFORMATION);
  }
  return 0;
}


void 
TDMLClApp::InitMainWindow()
{
  MainWindow = new TDMLClWnd(0, "DDECLI (A DDE Client)");
}

void
TDMLClApp::InitInstance()
{

  // The code below sets up the DDEML call back function that is used by the
  // DDE Management Library to carry out data transfers between
  // applications.
  //
  if (DdeInitialize(&InstId, (PFNCALLBACK)(FARPROC)CallBackProc, APPCMD_CLIENTONLY, 0) != DMLERR_NO_ERROR) {
      ::MessageBox(0,"Initialization failed.", "DDEML Client", MB_ICONSTOP|MB_TASKMODAL);
      PostQuitMessage(0);
    }

  // Must come after we've initialized DDE since InitInstance will trigger
  // SetupWindow
  TApplication::InitInstance();
}

int
TDMLClApp::TermInstance(int status)
{
  if (InstId) {
    DdeUninitialize(InstId);
  }
  return TApplication::TermInstance(status);
}


int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDMLClApp().Run();
}
