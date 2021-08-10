//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//
// This is a sample application using the OWL library that demonstrats the
// use of the Windows 3.1 DDEML API in a server application.  You should
// first build this application and run it.  Run the client application,
// DDECLI.EXE, to start a conversation with this Server.  Detailed
// information on DDEML can found in the online help and is suggested
// reading for anyone interested in writing DDEML applications.  Search on
// the keyword DDEML.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\menu.h>
#include <ddeml.h>
#include <string.h>

#define CM_ABOUT 0x100


class TDMLSrApp : public TApplication {
  public:
    TDMLSrApp() : TApplication(),CallBackProc((FARPROC)CallBack) {
      nCmdShow = SW_SHOWMINIMIZED;
      InstId=0;
      }

    void InitMainWindow();
    BOOL IdleAction(long);

    void InitInstance();
    int TermInstance(int status);

    DWORD   InstId;
    static HDDEDATA FAR PASCAL _export CallBack(WORD, WORD, HCONV, HSZ, HSZ,
                                                HDDEDATA, DWORD, DWORD);

    TProcInstance CallBackProc;

};


class TDMLSrWnd : public TFrameWindow {
  public:
    TDMLSrWnd(TWindow*, const char*);
    ~TDMLSrWnd();
    void SetupWindow();

    void EvSysCommand(UINT cmdType, TPoint&);
    BOOL EvQueryOpen();

    virtual BOOL MatchTopicAndService(HSZ, HSZ);
    virtual BOOL MatchTopicAndItem(HSZ, HSZ);
    virtual HDDEDATA WildConnect(HSZ, HSZ, WORD);
    virtual HDDEDATA DataRequested(WORD);
    virtual void UpdateData();

    DWORD   InstId() {
      return ((TDMLSrApp*)GetApplication())->InstId;
      }

    HCONV   HConv;
    BOOL    Loop;
    HSZ     Service;
    HSZ     Topic;
    HSZ     Item;

  DECLARE_RESPONSE_TABLE(TDMLSrWnd);
  DECLARE_CASTABLE;
};

DEFINE_RESPONSE_TABLE1(TDMLSrWnd, TFrameWindow)
  EV_WM_SYSCOMMAND,
  EV_WM_QUERYOPEN,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE1(TDMLSrWnd, TFrameWindow);


TDMLSrWnd* This = 0;

TDMLSrWnd::TDMLSrWnd(TWindow* parent, const char* title)
  : TFrameWindow(parent, title)
{
  HConv = 0;
  Loop = FALSE;
}

TDMLSrWnd::~TDMLSrWnd()
{
  // This clean up is required for those resources that were allocated during
  // the DDE conversation.
  //
  if (HConv)
    DdeDisconnect(HConv);   // Let the other party know we are leaving

  if (InstId()) {
    DdeNameService(InstId(), Service, 0, DNS_UNREGISTER);
    if (Service)
      DdeFreeStringHandle(InstId(), Service);
    if (Topic)
      DdeFreeStringHandle(InstId(), Topic);
    if (Item)
      DdeFreeStringHandle(InstId(), Item);
  }
}

void
TDMLSrWnd::SetupWindow()
{
  This = this;

  TFrameWindow::SetupWindow();

  Service = Topic = Item = 0;

  // The strings below are the 'Service', 'Topic' and 'Item' identifiers
  // that this application makes available, through DDE, to other
  // applications.
  //
  Service = DdeCreateStringHandle(InstId(), "TDMLSR_Server", CP_WINANSI);
  Topic = DdeCreateStringHandle(InstId(), "Borland", CP_WINANSI);
  Item = DdeCreateStringHandle(InstId(), "Products", CP_WINANSI);
  if (Service && Topic && Item) {
    if (DdeNameService(InstId(), Service, 0, DNS_REGISTER) != 0) {
      // If everything is successful then an About choice is added to the
      // system menu.
      //
      TMenu menu(GetSystemMenu());
      menu.AppendMenu(MF_BYCOMMAND | MF_SEPARATOR, -1, "");
      menu.AppendMenu(MF_BYCOMMAND | MF_STRING, CM_ABOUT, "&About DDESVR");
    } else {
      MessageBox("Registration failed.", Title, MB_ICONSTOP);
      PostQuitMessage(0);
    }
  } else {
    MessageBox("String creation failed.", Title, MB_ICONSTOP);
    PostQuitMessage(0);
  }
}

//
// The code below is used to trap the About menu choice when it is selected
// from the system menu.
//
void
TDMLSrWnd::EvSysCommand(UINT cmdType, TPoint&)
{
  if ((cmdType & 0xFFF0) == CM_ABOUT)
    MessageBox("DDESVR.EXE\nWritten using ObjectWindows\nCopyright (c) 1991, 1993 by Borland International", "About DDESVR", MB_ICONINFORMATION);
  else
    DefaultProcessing();
}

//
// This seemingly insignificant function is what keeps this program
// minimized, no matter what the user might try to do.
//
BOOL
TDMLSrWnd::EvQueryOpen()
{
  return FALSE;
}

//
// This function is used to compare incoming Topic and Service requests.
// This example DDE Server only makes one Service and one Topic available
// so the logic is simple for this case but could be more complex for
// Servers that offer multiple Services or Topics.
//
BOOL
TDMLSrWnd::MatchTopicAndService(HSZ topic, HSZ service)
{
  if (DdeCmpStringHandles(Topic, topic) == 0)
    if (DdeCmpStringHandles(Service, service) == 0)
      return TRUE;
  return FALSE;
}

//
// This function is used to compare incoming Topic and Item pair requests.
// This Server only makes one Topic with one Item available so the logic is
// simple for this case but could be more complex if the Server offered
// multiple Items for multiple Topics.
//
BOOL
TDMLSrWnd::MatchTopicAndItem(HSZ hsz1, HSZ hsz2)
{
  if (DdeCmpStringHandles(Topic, hsz1) == 0)
    if (DdeCmpStringHandles(Item, hsz2) == 0)
      return TRUE;
  return FALSE;
}

//
// This function responds to 'system wide' polling of any available
// Services with specific Topics, any Topics with specific Services or any
// Services with any Topics.  It simply replies with a match, if there is
// one, so that the polling application can open data discussions later, if
// desired.
//
HDDEDATA
TDMLSrWnd::WildConnect(HSZ hsz1, HSZ hsz2, WORD wFmt)
{
  HSZPAIR hszpTemp[] = { { Service, Topic }, { 0, 0 } };

  if (!hsz1 && !hsz2)    // Returns all if true
    return DdeCreateDataHandle(InstId(), (LPBYTE)&hszpTemp[0], sizeof(hszpTemp), 0L, 0, wFmt, 0);

  if (!hsz1 && DdeCmpStringHandles(hsz2, Service) == 0)
    return DdeCreateDataHandle(InstId(), (LPBYTE)&hszpTemp[0], sizeof(hszpTemp), 0L, 0, wFmt, 0);

  if (DdeCmpStringHandles(hsz1, Topic) == 0 && !hsz2)
    return DdeCreateDataHandle(InstId(), (LPBYTE)&hszpTemp[0], sizeof(hszpTemp), 0L, 0, wFmt, 0);

  return 0;
}

//
//
//
HDDEDATA
TDMLSrWnd::DataRequested(WORD wFmt)
{
  static char szItems[][42] = {
    "Borland C++ with Object Windows",
    "Turbo C++",
    "Borland Pascal with Objects",
    "Paradox For Windows",
    "dBase",
    "Quattro Pro For Windows"
  };

  static int iLoop = 0;
  if (wFmt == CF_TEXT) {
    iLoop++;
    iLoop %= sizeof(szItems) / sizeof(szItems[0]);
    return DdeCreateDataHandle(InstId(), (unsigned char *)szItems[iLoop], sizeof(szItems[iLoop]), 0, Item, wFmt, 0);
  }
  return 0;
}

//
// This is triggered by the IdleAction() loop above whenever the user
// enters an advise loop.
//
void
TDMLSrWnd::UpdateData()
{
  DdePostAdvise(InstId(), Topic, Item);
}

//
// This call back function is the heart of interaction between this program
// and DDE.  Because Windows doesn't pass C++ 'this' pointers to call
// back functions, a static 'this' pointer was used.  If you wanted to
// create a Server that would allow for more than one conversation, using a
// List of conversations and their associated 'this' pointers would be one
// possible method to try.  The XTYP_ constants are described in detail in
// the online help.
//
HDDEDATA FAR PASCAL
TDMLSrApp::CallBack(WORD wType, WORD wFmt, HCONV hConv, HSZ hsz1, HSZ hsz2,
                    HDDEDATA hData, DWORD, DWORD)
{
  switch (wType) {
    case XTYP_ADVREQ:
      if (This->MatchTopicAndItem(hsz1, hsz2))
        return This->DataRequested(wFmt);
      return 0;

    case XTYP_ADVSTART:
      if (!This->Loop && This->MatchTopicAndItem(hsz1, hsz2)) {
        This->Loop = TRUE;
        return (HDDEDATA)1;
      }
      return 0;

    case XTYP_ADVSTOP:
      if (This->Loop && This->MatchTopicAndItem(hsz1, hsz2))
        This->Loop = FALSE;
      break;

    case XTYP_CONNECT:
      if (!This->HConv)
        if (This->MatchTopicAndService(hsz1, hsz2))
          return (HDDEDATA)1;
      return 0;

    case XTYP_CONNECT_CONFIRM:
      This->HConv = hConv;
      break;

    case XTYP_DISCONNECT:
      if (hConv == This->HConv) {
        This->HConv = 0;
        This->Loop = FALSE;
      }
      break;

    case XTYP_ERROR:
      This->MessageBox("A critical DDE error has occured.", This->Title, MB_ICONINFORMATION);
      break;

    case XTYP_EXECUTE:
      return DDE_FNOTPROCESSED;

    case XTYP_POKE: {
      char temp[128];
      strcpy(temp, "The server received: ");
      int size = strlen(temp);
      DdeGetData(hData, (unsigned char *)&temp[size], sizeof(temp) - size, 0);
      ::MessageBox(GetFocus(), temp, This->Title, MB_ICONINFORMATION);
      return (HDDEDATA)DDE_FACK;
     }

    case XTYP_REQUEST:
      if (This->MatchTopicAndItem(hsz1, hsz2))
        return This->DataRequested(wFmt);
      return 0;

    case XTYP_WILDCONNECT:
      return This->WildConnect(hsz1, hsz2, wFmt);
  }
  return 0;
}


//
// Make server window, and start it off minimized--it will keep itself like
// that.
//
void
TDMLSrApp::InitMainWindow()
{
  MainWindow = new TDMLSrWnd(0, "DDESVR (A DDE Server)");
}

//
// There are 16 available timers in Windows.  This little trick uses the
// OWL IdleAction() member function to save that scarce resource.
//
BOOL
TDMLSrApp::IdleAction(long)
{
  static DWORD dwTime = GetTickCount();
  TDMLSrWnd* win = TYPESAFE_DOWNCAST(MainWindow, TDMLSrWnd);
  if (MainWindow && win->Loop)
    if (GetTickCount() - dwTime > 1000) {
      dwTime = GetTickCount();
      win->UpdateData();
    }
  return TRUE;
}

void
TDMLSrApp::InitInstance()
{
  // The code below sets up the DDEML call back function that is used by the
  // DDE Management Library to carry out data transfers between
  // applications.
  //
  if (DdeInitialize(&InstId, (PFNCALLBACK)(FARPROC)CallBackProc, 0, 0) != DMLERR_NO_ERROR) {
      ::MessageBox(0,"Initialization failed.", "DDEML Server", MB_ICONSTOP|MB_TASKMODAL);
      PostQuitMessage(0);
    }

  // Must come after we've initialized DDE since InitInstance will trigger
  // SetupWindow
  TApplication::InitInstance();
}

int
TDMLSrApp::TermInstance(int status)
{
  if (InstId) {
    DdeUninitialize(InstId);
  }
  return TApplication::TermInstance(status);
}


int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDMLSrApp().Run();
}
