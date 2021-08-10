//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1995 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/serialze.h>
#include <winsys/system.h>
#include "diagxprt.h"
#include "setup.h"

#include <toolhelp.h>
#include <iostream.h>
#include <cstring.h>
#include <stdio.h>

#include "diagxprt.rh"

//----------------------------------------------------------------------------
//
//  class TDiagClient
//

DEFINE_RESPONSE_TABLE1(TDiagClient, TEditFile)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND(CM_SETUP, CmSetup),
  EV_COMMAND(CM_START, CmStart),
  EV_COMMAND(CM_STOP, CmStop),
  EV_COMMAND(CM_MEM, CmMem),
  EV_COMMAND(CM_HELP, CmHelp),
  EV_COMMAND_ENABLE(CM_FILENEW, CmFileNewEnable),
  EV_COMMAND_ENABLE(CM_FILEOPEN, CmFileOpenEnable),
  EV_COMMAND_ENABLE(CM_FILESAVE, CmFileSaveEnable),
  EV_COMMAND_ENABLE(CM_SETUP, CmSetupEnable),
  EV_COMMAND_ENABLE(CM_START, CmStartEnable),
  EV_COMMAND_ENABLE(CM_STOP, CmStopEnable),
  EV_MESSAGE(CM_LOGPARAMERROR, CmLogParamError),
  EV_MESSAGE(CM_LOGERROR, CmLogError),
  EV_MESSAGE(CM_OUTSTR, CmOutStr),
//  EV_MESSAGE(CM_DEFAULT, CmDefault),  // Will display unhandled toolhelp ids
END_RESPONSE_TABLE;

//
//
//
TDiagClient* TDiagClient::pThis;

//
//
//
void
TDiagClient::CmStart()
{
  nActive = 1;
}

//
//
//
void
TDiagClient::CmStop()
{
  nActive = 0;
}

//
//
//
void
TDiagClient::CmSetup()
{
  nActive--;
  TSetupDialog(this).Execute();
  nActive++;
}

//
//
//
static char* helpText[] = {
  "DIAGXPRT displays diagnostic messages sent by OutputDebugString()",
  "or by the RTL diagnostic macros, TRACEX & WARNX.",
  "OWL diagnostics can be enabled or disabled by using the configure button.",
  "There are two levels of diagnostics used in OWL, 0 and 1.  You can configure",
  "this for each area.",
  "You can also add your own diagnostic groups.  Each new group will be",
  "written to the OWL.INI file and the declaration placed on the clipboard",
  "for inclusion in your code.",
  "The OWL.INI file is only read when your application loads.",
  "Please see the RTL documentation and online help for a complete description",
  "of the diagnostic macros and their use.  You may also look in OWL source",
  "for additional examples.",
  0
};

//
//
//
void
TDiagClient::CmHelp()
{
  SetSelection(-1, -1);

  for (int i = 0; helpText[i]; i++) {
    Insert(helpText[i]);
    Insert("\r\n");
  }
}

//
// Dumps memory statistics into output window
//
void
TDiagClient::CmMem()
{
  static char buf[80];

  MEMMANINFO info;
  info.dwSize=sizeof(info);

  SYSHEAPINFO sysInfo;
  sysInfo.dwSize=sizeof(sysInfo);

  SetSelection(-1, -1);

  Insert("Compacting heap, please wait\r\n");

  DWORD freeMemEst = GlobalCompact(-1);
  sprintf(buf,"Estimated free memory = %lu\r\n",freeMemEst);
  Insert(buf);

  if (!TSystem::IsWin95() && MemManInfo(&info)) {
    Insert("MemManInfo() reports...\r\n");
    sprintf(buf,"..Largest free block = %lu\r\n", info.dwLargestFreeBlock);
    Insert(buf);
    sprintf(buf,"..Max pages available = %lu\r\n", info.dwMaxPagesAvailable);
    Insert(buf);
    sprintf(buf,"..Max pages lockable = %lu\r\n", info.dwMaxPagesLockable);
    Insert(buf);
    sprintf(buf,"..Total linear space = %lu\r\n", info.dwTotalLinearSpace);
    Insert(buf);
    sprintf(buf,"..Total unlocked pages = %lu\r\n", info.dwTotalUnlockedPages);
    Insert(buf);
    sprintf(buf,"..Free pages = %lu\r\n", info.dwFreePages);
    Insert(buf);
    sprintf(buf,"..Total pages = %lu\r\n", info.dwTotalPages);
    Insert(buf);
    sprintf(buf,"..Free linear space = %lu\r\n", info.dwFreeLinearSpace);
    Insert(buf);
    sprintf(buf,"..Swap file pages = %lu\r\n", info.dwSwapFilePages);
    Insert(buf);
    sprintf(buf,"..Page size = %u\r\n",  info.wPageSize);
    Insert(buf);
  }
  else
    Insert("MemManInfo() failed\r\n");

  if (SystemHeapInfo(&sysInfo)) {
    Insert("SysHeapInfo() reports...\r\n");
    sprintf(buf,"..User free percent = %u\r\n", sysInfo.wUserFreePercent);
    Insert(buf);
    sprintf(buf,"..GDI free percent = %u\r\n", sysInfo.wGDIFreePercent);
    Insert(buf);
  }
  else
    Insert("SysHeapInfo() failed\r\n");
}

//
// Override of TEditFile::CanClear()
//
bool
TDiagClient::CanClear()
{
  // We don't want to be prompted all the time to see if we want to save the
  // text
  //
  return true;
}

//
//
//
void
TDiagClient::SetupWindow()
{
  TEditFile::SetupWindow();
  nActive = 0;
  pThis = this;
  pThunk = MakeProcInstance(FARPROC(Callback), *GetModule());

  // Create 2 fonts: A big one and a small one. Names & sizes are loaded
  // from resource file.
  //
  pFont0 = new TFont(
    string(*GetModule(), IDS_FONT0_NAME).c_str(),
    atoi(string(*GetModule(), IDS_FONT0_SIZE).c_str()));
  pFont1 = new TFont(
    string(*GetModule(), IDS_FONT1_NAME).c_str(),
    atoi(string(*GetModule(), IDS_FONT1_SIZE).c_str()));

  SetSize(bigSize);
  LoadMode();
  NotifyRegister(0, (LPFNNOTIFYCALLBACK)pThunk, NF_NORMAL);
}

//
//
//
void
TDiagClient::CleanupWindow()
{
  SaveMode();

  // Un-register our callback by toolhelp
  //
  NotifyUnRegister(0);
  FreeProcInstance(pThunk);
  delete pFont0;
  delete pFont1;
}

//
//
//
void
TDiagClient::SetSize(Size s)
{
  // Called when the frame window changes "size" (small or big). We make
  // here the client window reflect the change by modifying some attributes
  size = s;

  // Small font for smallSize, large font for bigSize
  //
  SetWindowFont(*(size == bigSize ? pFont0 : pFont1), true);

  // No scroll bar for smallSize, scroll bars for largeSize
  //
  Attr.Style = GetWindowLong(GWL_STYLE);
  if (size == bigSize)
    Attr.Style |= (WS_VSCROLL+WS_HSCROLL);
  else
    Attr.Style &= ~(WS_VSCROLL+WS_HSCROLL);
  SetWindowLong(GWL_STYLE, Attr.Style);
}

//
//
//
void
FixUpEOL(char *str)
{
  while (*str) {
    // Normalize the \r\n ordering (edit doesn't tolerate \n\r)
    //
    if (str[0] == '\n') {
      if (str[1] == '\r')
        str[1] = '\n';
      else
        memmove(str+1,str,strlen(str)+1);
      str[0] = '\r';
      str += 2;
    }
    else
      str++;
  }
}

//
//
//
LRESULT
TDiagClient::CmDefault(WPARAM id, LPARAM /*data*/)
{
  if (!nActive)
    return true;

  char buf[128];
  sprintf(buf,"Toolhelp callback id: %u\r\n",id);

  // To avoid beeing overflown: passed 200 lines, keep deleting
  // the first line so that the number of lines cannot grow
  //
  if (GetNumLines() >= 200)
    DeleteLine(0);

  // Append the line to display to the end of the edit buffer
  //
  SetSelection(-1, -1);
  Insert(buf);
  SetSelection(-1, -1);

  return true;
}

//
// This gets called as a result of a message post from the toolhelp
// callback
//
LRESULT
TDiagClient::CmOutStr(WPARAM /*id*/, LPARAM data)
{
  if (!nActive)
    return true;

  // To avoid beeing overflown: passed 200 lines, keep deleting
  // the first line so that the number of lines cannot grow
  //
  if (GetNumLines() >= 200)
    DeleteLine(0);

  // Append the line to display to the end of the edit buffer
  //
  TDispData far* d = (TDispData far *)data;
  SetSelection(-1, -1);
  FixUpEOL(d->ProcName);
  Insert(d->ProcName); // Really message

  // Assume that caller of OutputDebugString is responsible for \r\n
  // Insert("\r\n");
  //
  SetSelection(-1, -1);

  // This was allocated in call back
  //
  delete d;
  return true;
}

//
//
//
LRESULT
TDiagClient::CmLogParamError(WPARAM /*id*/, LPARAM data)
{
  if (!nActive)
    return true;

  TDispData far* d = (TDispData far *)data;
  char buf[128];
  FormatLogParamError(buf, sizeof(buf), d);

  // To avoid beeing overflown: passed 200 lines, keep deleting
  // the first line so that the number of lines cannot grow
  //
  if (GetNumLines() >= 200)
    DeleteLine(0);

  // Append the line to display to the end of the edit buffer
  //
  SetSelection(-1, -1);
  Insert(buf);
  SetSelection(-1, -1);

  delete d;
  return true;
}

//
//
//
LRESULT
TDiagClient::CmLogError(WPARAM /*id*/, LPARAM data)
{
  if (!nActive)
    return true;

  TDispData far* d = (TDispData far*)data;
  char buf[128];
  FormatLogError(buf, sizeof(buf), d);

  // To avoid beeing overflown: passed 200 lines, keep deleting
  // the first line so that the number of lines cannot grow
  //
  if (GetNumLines() >= 200)
    DeleteLine(0);

  // Append the line to display to the end of the edit buffer
  //
  SetSelection(-1, -1);
  Insert(buf);
  SetSelection(-1, -1);

  delete d;
  return true;
}

//
//
//
void
TDiagClient::SaveMode()
{
  WritePrivateProfileString(DIAG_CLS, DIAG_MODE, nActive > 0 ? "1":"0", DIAG_INI);
}

void
TDiagClient::LoadMode()
{
  char b[4];
  GetPrivateProfileString(DIAG_CLS, DIAG_MODE, "0", b, sizeof(b), DIAG_INI);
  nActive = *b != '0';
}

//----------------------------------------------------------------------------
//
//  class TDiagFrame
//

DEFINE_RESPONSE_TABLE3(TDiagFrame, TTinyCaption, TDecoratedFrame, TSerializeReceiver)
  EV_WM_SYSCOMMAND,
  EV_WM_SIZE,
END_RESPONSE_TABLE;

//
//
//
TDiagFrame::TDiagFrame(const char* t, TWindow* c)
:
  TDecoratedFrame(0, t, c, true),
  TTinyCaption(),
  TWindow(0, t, 0)
{
  // This frame window is special. We start with a normal caption but are
  // prepared to switch to a tiny caption...
  //
  Attr.Style = WS_OVERLAPPEDWINDOW & ~WS_VISIBLE;
  EnableTinyCaption(44, false);
  TCEnabled = false;
}

//
//
//
void
TDiagFrame::SetupWindow()
{
  TDecoratedFrame::SetupWindow();

  // Add to the system menu a menu-item which can be used to switch
  // to a tiny-caption and back to normal:
  //
  TSystemMenu Menu(*this);
  Menu.InsertMenu(SC_CLOSE, MF_BYCOMMAND|MF_CHECKED, SC_TOGGLE_SIZE,
                  string(*GetModule(), IDS_DECORATED).c_str());
  Menu.InsertMenu(SC_CLOSE, MF_BYCOMMAND|MF_SEPARATOR, -1, 0);

  // Restore the window to size it had at the last session:
  //
  char b[20];
  if (GetPrivateProfileString(DIAG_CLS, DIAG_RECT, "", b, sizeof(b), OWL_INI)) {
    sscanf(b, "%d,%d,%d,%d", &rect.left, &rect.top, &rect.right, &rect.bottom);
    MoveWindow(rect, true);
  }
}

//
//
//
void
TDiagFrame::CleanupWindow()
{
  TDecoratedFrame::CleanupWindow();

  // Remember the size for the next time:
  //
  char b[20];
  sprintf(b, "%d,%d,%d,%d", rect.left, rect.top, rect.right, rect.bottom);
  WritePrivateProfileString(DIAG_CLS, DIAG_RECT, b, OWL_INI);
}

//
//
//
void
TDiagFrame::EvSize(uint type, TSize &size)
{
  TDecoratedFrame::EvSize(type, size);

  // We remember the size of the frame window whenever it changes.
  // Note however that we are only interested by 'normal' resizes,
  // not resizes dued to maximized or minimized operations.
  //
  if (type == SIZE_RESTORED)
    rect = GetWindowRect();
}

//
//
//
LRESULT
TDiagFrame::EvCommand(uint id, HWND hWndCtl, uint notifyCode)
{
  LRESULT er;

  // Give a chance to the TTinyCaption mixin to completely process the
  // events it knows about:
  //
  if (TTinyCaption::DoCommand(id, hWndCtl, notifyCode, er) == esComplete)
    return er;

  // Otherwise, forward to the frame window
  //
  return TFrameWindow::EvCommand(id, hWndCtl, notifyCode);
}

//
//
//
void
TDiagFrame::EvSysCommand(uint id,TPoint& pt)
{
  switch (id) {
    case SC_TOGGLE_SIZE:
      // Here we are: the user selected the toggle menu-item
      // from the system menu
      CmToggleSize();
      break;
    default:
      if (TTinyCaption::DoSysCommand(id, pt) == esPartial)
        TFrameWindow::EvSysCommand(id, pt);
  }
}

//
//
//
void
TDiagFrame::CmToggleSize()
{
  TCEnabled ^= true;

  // Toggle the menu-item in the system menu
  //
  TSystemMenu Menu(*this);
  uint bCheck = TCEnabled ? MF_UNCHECKED:MF_CHECKED;
  Menu.CheckMenuItem(SC_TOGGLE_SIZE, MF_BYCOMMAND | bCheck);

  // Toggle the toolbar visibility
  //
  TDecoratedFrame::EvCommand(CM_TOOLBAR, 0, 0);

  // Toggle the status bar visibility
  //
  TDecoratedFrame::EvCommand(CM_STATUSBAR, 0, 0);

  // Notify the client that we want to toggle the size
  //
  TDiagClient *pClient = TYPESAFE_DOWNCAST(ClientWnd, TDiagClient);
  CHECK(pClient != 0);
  pClient->SetSize(TCEnabled ? TDiagClient::smallSize:TDiagClient::bigSize);

  // Force a calcsize by simulating a window resize
  //
  TRect rect = GetWindowRect();
  rect.right--;
  MoveWindow(rect, false);
  rect.right++;
  MoveWindow(rect, true);
}

//
//
//
void
TDiagFrame::DataReceived(uint32 length, void* data)
{
  TEditFile* edit = TYPESAFE_DOWNCAST(GetClientWindow(), TEditFile);
  if (edit) {
    uint len = uint(length);
    char* str = new char[len + 1];
    strncpy(str, (char*)data, len);
    str[len] = 0;
    edit->SetSelection(-1, -1);
    FixUpEOL(str);
    edit->Insert((char*)str);
//    edit->Insert("\r\n");
    edit->SetSelection(-1, -1);
    delete[] str;
  }
}

//----------------------------------------------------------------------------
//
//  class TOwlDiagApp
//

//
// This defines the icons for the speedbar
//
int TOwlDiagApp::speedbar[] = {
  CM_FILENEW, CM_FILENEW,
  CM_FILEOPEN, CM_FILEOPEN,
  CM_FILESAVE, CM_FILESAVE,
  CM_FILESAVEAS, CM_FILESAVEAS,
  -1, -1,
  CM_EDITCOPY, CM_EDITCOPY,
  CM_EDITCUT, CM_EDITCUT,
  CM_EDITPASTE, CM_EDITPASTE,
  -1, -1,
  CM_EDITFIND, CM_EDITFIND,
  CM_EDITREPLACE, CM_EDITREPLACE,
  CM_EDITFINDNEXT, CM_EDITFINDNEXT,
  -1, -1,
  CM_SETUP, CM_SETUP,
  -1, -1,
  IDB_START, CM_START,
  IDB_STOP, CM_STOP,
  -1, -1,
  IDB_MEM,  CM_MEM,
  IDB_HELP, CM_HELP,
  0, 0
};

//
//
//
void
TOwlDiagApp::InitMainWindow()
{
  TDiagFrame *frame = new TDiagFrame(
    string(*this, IDS_TITLE).c_str(), new TDiagClient);

  TControlBar* cb = new TControlBar(frame);

  for (int *pID = speedbar; *pID; pID += 2) {
    if (pID[0] == -1)
      cb->Insert(*new TSeparatorGadget(6));
    else
      cb->Insert(*new TButtonGadget(pID[0], pID[1]));
  }
  cb->Attr.Id = CM_TOOLBAR;

  // Turn on control bar hints.
  //
  cb->SetHintMode(TGadgetWindow::EnterHints);

  frame->Insert(*cb, TDecoratedFrame::Top);

  MainWindow = frame;
  MainWindow->SetIcon(this, IC_OWLDIAG);

  // Construct a status bar & insert it at the bottom
  //
  TStatusBar *pS = new TStatusBar(0, TGadget::Recessed,
    TStatusBar::CapsLock | TStatusBar::NumLock | TStatusBar::ScrollLock);
//  pS->Attr.Id = CM_STATUSBAR;
  frame->Insert(*pS, TDecoratedFrame::Bottom);

//  EnableCtl3d(true);
}

//
//  Entry point
//

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  ::SetMessageQueue(32);
  return TOwlDiagApp().Run();
}
