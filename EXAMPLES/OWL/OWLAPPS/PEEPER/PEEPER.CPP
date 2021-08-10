//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\dialog.h>
#include <owl\framewin.h>
#include <owl\listbox.h>
#include <owl\statusba.h>
#include <owl\controlb.h>
#include <owl\buttonga.h>
#include <owl\static.h>
#include <owl\decframe.h>
#include <owl\inputdia.h>
#include <owl\checkbox.h>
#include <cstring.h>
#include "peeper.h"

//
// ListBox id.
//
static const WORD ID_LISTBOX =            1000;

//
// Variables that represent Windows' macros.
//
static WORD MAXIMIZE_MSG =                SC_MAXIMIZE;
static WORD MINIMIZE_MSG =                SC_MINIMIZE;
static WORD PAINT_MSG =                   WM_PAINT;
static WORD RESTORE_MSG =                 SC_RESTORE;
static WORD PASTE_MSG =                   WM_PASTE;
static WORD CLOSE_MSG =                   WM_CLOSE;

//
// TClientWindow response table.
//
DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
  EV_LBN_SELCHANGE(ID_LISTBOX, DisplayWinInfo),
END_RESPONSE_TABLE;

//
// TPeeper Response table
//
DEFINE_RESPONSE_TABLE1(TPeeper, TApplication)
  EV_COMMAND(CM_PEEPING, CmPeeping),
  EV_COMMAND(CM_CHANGE_CAPTION, CmChangeCaption),
  EV_COMMAND(CM_CLEAR_WINDOWLIST, CmClearWindowList),
  EV_COMMAND(CM_SEND_MESSAGE, CmSendMessage),
  EV_COMMAND(CM_HELP, CmHelp),
END_RESPONSE_TABLE;


//
// Global functions, used with ForEach().
//
void SendWMSetText(HWND& hWnd, void* p)
{
  ::SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)(LPCSTR)p);
}

void SendSysMessage(HWND& hWnd, void* p)
{
  ::SendMessage(hWnd, WM_SYSCOMMAND, *(WORD*)p, 0);
}

void SendWMMessage(HWND& hWnd, void* p)
{
  ::SendMessage(hWnd, *(WORD*)p, 0, 0);
}

//////////////////////////////////////////////////////////////////////

//
// TPeeper member functions.
//

void
TPeeper::InitMainWindow()
{
  Client = new TClientWindow;

  // Create frame.  Make it look like a dialog.  Enable menu tracking
  // for hints.
  //
  TDecoratedFrame* frame = new TDecoratedFrame(0, "Peeper", Client, TRUE);
  frame->Attr.Style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
  frame->Attr.W = 324;
  frame->Attr.H = 225;
  frame->SetIcon(this, IDI_PEEPER);

  // Construct, build and insert a control bar into the frame
  //
  Actions = new TControlBar(frame);
  Actions->Insert(*new TButtonGadget(IDB_EXIT, CM_EXIT));
  Actions->Insert(*new TSeparatorGadget);
  Actions->Insert(*new TButtonGadget(IDB_PEEPING, CM_PEEPING));
  Actions->Insert(*new TButtonGadget(IDB_CLEAR_WINDOWLIST, CM_CLEAR_WINDOWLIST));
  Actions->Insert(*new TSeparatorGadget);
  Actions->Insert(*new TButtonGadget(IDB_CHANGE_CAPTION, CM_CHANGE_CAPTION));
  Actions->Insert(*new TButtonGadget(IDB_MESSAGES, CM_SEND_MESSAGE));
  Actions->Insert(*new TSeparatorGadget);
  Actions->Insert(*new TButtonGadget(IDB_HELP, CM_HELP));
  Actions->SetHintMode(TGadgetWindow::EnterHints);
  frame->Insert(*Actions, TDecoratedFrame::Top);

  // Insert message bar into frame. Add some margins since our window has a
  // thin frame & the message bar edges tend to get lost.
  //
  StatusLine = new TMessageBar(0);
  StatusLine->SetText("Command Mode");

  TMargins margins;
  margins.Units = TMargins::Pixels;
  margins.Left = 2;
  margins.Right = 2;
  margins.Top = 1;
  margins.Bottom = 1;
  StatusLine->SetMargins(margins);
  frame->Insert(*StatusLine, TDecoratedFrame::Bottom);

  // Create list box and it's title.
  //
  SelectedWindows = new TListBox(Client, ID_LISTBOX, 6, 28, 300, 106);
  SelWinText = new TStatic(Client, -1, "SelectedWindows", 6, 4, 125, 16, 20);

  MainWindow = frame;

  // Create window list vector.
  //
  WindowList = new TCVectorImp<HWND>(20, 2);
}

//
// CmPeeping(). Set status line to 'Peeping!' and capture mouse.
//
void
TPeeper::CmPeeping()
{
  SetCapture(Client->HWindow);
  Actions->SetHintCommand(-1);
  StatusLine->SetText("Peeping Mode. Right-click to end.");
}

//
// CmChangeCaption(). Prompt user for string.  Change caption of all windows
// in list to string entered by user.
//
void
TPeeper::CmChangeCaption()
{
  char           buffer[81];

  if (WindowList->Count()) {
    buffer[0] = 0;
    TInputDialog   input(Client, "Enter Text", "Text:", buffer, 80);

    if (input.Execute() == IDOK)
       WindowList->ForEach(SendWMSetText, buffer);
  } else
    MainWindow->MessageBox("Must choose some windows first", "Error");
}

//
// CmClearWindowList(). Clear list box that contains the captions of the
// selected windows.  Also, empty window list.
//
void
TPeeper::CmClearWindowList()
{
  WindowList->Flush();
  SelectedWindows->ClearList();
}

//
// CmSendMessage(). Send messages selected by user to all windows in window
// list.
//
void
TPeeper::CmSendMessage()
{
  if (WindowList->Count()) {
    MessagesTB        mtb;      // transfer buffer.
    TMessagesDialog   *messages = new TMessagesDialog(MainWindow, &mtb);

    if (messages->Execute() == IDOK) {
      if (mtb.MaxCB)
        WindowList->ForEach(SendSysMessage, &MAXIMIZE_MSG);
      if (mtb.MinCB)
        WindowList->ForEach(SendSysMessage, &MINIMIZE_MSG);
      if (mtb.PaintCB)
        WindowList->ForEach(SendWMMessage, &PAINT_MSG);
      if (mtb.RestoreCB)
        WindowList->ForEach(SendSysMessage, &RESTORE_MSG);
      if (mtb.PasteCB)
        WindowList->ForEach(SendWMMessage, &PASTE_MSG);
      if (mtb.CloseCB) {
        WindowList->ForEach(SendWMMessage, &CLOSE_MSG);
        CmClearWindowList();
      }
    }
  }
  else
    MainWindow->MessageBox("Must choose some windows first", "Error");
}

//
// CmHelp(). Display help message box.
//
void
TPeeper::CmHelp()
{
  string  msg;

  msg += "Press 'Peep!' button to select windows.\n";
  msg += "While peeping press left mouse button to select window under cursor.\n";
  msg += "When finished peeping press right mouse button to return to command mode.\n";
  MainWindow->MessageBox(msg.c_str(), "Help");
}

//////////////////////////////////////////////////////////////////////

//
// TClientWindow member functions.
//

//
// EvLButtonDown(). Used while peeping. Get caption and handle of window under
// mouse and save.
//
void
TClientWindow::EvLButtonDown(UINT, TPoint &point)
{
  TPoint     p = point;
  HWND       chosenWindow;
  char       caption[128];
  TRect      r;
  TPeeper*   peeper = TYPESAFE_DOWNCAST(GetApplication(),TPeeper);

  ::ClientToScreen(HWindow, &p);
  ::GetWindowRect(peeper->MainWindow->HWindow, &r);

  if (!r.Contains(p)) {
    chosenWindow = ::WindowFromPoint(p);
    peeper->WindowList->Add(chosenWindow);
    if (!::GetWindowText(chosenWindow, caption, sizeof caption))
       peeper->SelectedWindows->AddString("No caption");
    else
       peeper->SelectedWindows->AddString(caption);
  }
}

//
// EvRButtonDown(). Stop peeping. Set status line to 'Command Mode' and
// release mouse capture.
//
void
TClientWindow::EvRButtonDown( UINT, TPoint & )
{
  TPeeper*   peeper = TYPESAFE_DOWNCAST(GetApplication(),TPeeper);

  peeper->Actions->SetHintCommand(-1);
  peeper->StatusLine->SetText("Command Mode.");
  ReleaseCapture();
}

//
// DisplayWinInfo().  Display the following information in a message box when
// item from list box is selected:
//  * Window Class.
//  * demensions of window (left, top, right, bottom).
//  * does the window have a menu?
//  * does the window have children?
//
void
TClientWindow::DisplayWinInfo()
{
  string   infoText;
  char     className[80];
  TRect    winRect;
  HWND     hWnd;
  int      haveMenu;
  int      haveChildren;
  char     buf[80];
  string   comma(", ");
  string   yes("Yes");
  string   no("No");
  string   newLine("\n");
  TPeeper* peeper = TYPESAFE_DOWNCAST(GetApplication(),TPeeper);

  hWnd = (*peeper->WindowList)[peeper->SelectedWindows->GetSelIndex()];

  ::GetClassName(hWnd, className, 80);
  ::GetWindowRect(hWnd, &winRect);
  haveMenu = ::GetMenu(hWnd) != 0;
  haveChildren = ::GetTopWindow(hWnd) != 0;

  infoText += "Window Class: " + string(className) + newLine;
  infoText += "Window Dimensions: ";
  infoText += string(itoa(winRect.left, buf, 10)) + comma +
              string(itoa(winRect.top, buf, 10)) + comma +
              string(itoa(winRect.right, buf, 10)) + comma +
              string(itoa(winRect.bottom, buf, 10)) + newLine;
  infoText += "Window has a menu? " + (haveMenu ? yes : no) + newLine;
  infoText += "Window has Children? " + (haveChildren ? yes : no) + newLine;

  ::MessageBox(0, infoText.c_str(), "Window Info", MB_OK);
}

//////////////////////////////////////////////////////////////////////

int OwlMain(int, char* [])
{
#if defined(__WIN32__)
  if (!(HIWORD(GetVersion())&0x8000)) {
    ::MessageBox(0,"This is not a WIN NT Example", "OWL Examples", MB_OK);
    return 0;
  }
#endif
  return TPeeper().Run();
}
