//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//
// This is an example of an application which implements context
// sensitive help for menu choices.  To use the application, hit
// F1 when a menu item is highlighted.  The program checks for F1
// being down in the WM_ENTERIDLE message.  If it is down, it sets
// a flag and simulates the selection of the menu item.  The help
// is then shown in the command message for that menu item.
// When the command is received, we just check to see if the flag
// has been set which indicates that the user wants help on the command.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include "help.rh"
#include <string.h>

static char HelpFile[] = "HELP.HLP";

class TOwlHelpWnd : public TFrameWindow {
  public:
    TOwlHelpWnd(const char* title);

    void EvPaint();
    void EvEnterIdle(UINT source, HWND hWndDlg);
    void CmMenuItemA();
    void CmMenuItemB();
    void CmExit();
    void CmHelpIndex();
    void CmHelpHelp();
    void CmHelpAbout();

  private:
    BOOL F1Pressed;
    
  DECLARE_RESPONSE_TABLE(TOwlHelpWnd);
};

DEFINE_RESPONSE_TABLE1(TOwlHelpWnd, TWindow)
  EV_WM_PAINT,
  EV_WM_ENTERIDLE,
  EV_COMMAND(CM_MENUITEMA, CmMenuItemA),
  EV_COMMAND(CM_MENUITEMB, CmMenuItemB),
  EV_COMMAND(CM_EXIT, CmExit),
  EV_COMMAND(CM_HELPINDEX, CmHelpIndex),
  EV_COMMAND(CM_HELPHELP, CmHelpHelp),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
END_RESPONSE_TABLE;


const char ClientAreaText[] =
  "To Get help, press F1 while a menu item is highlighted.  WinHelp will be "
  "called to show help on that topic.  If help is not shown, it is because "
  "the mouse button is pressed.  Release the mouse button to see help.";


TOwlHelpWnd::TOwlHelpWnd(const char* title)
  : TFrameWindow(0, title), 
    TWindow(0, title)
{
  F1Pressed = FALSE;
  AssignMenu(OWLHELPAPMENU);        // menu resID needs to be duped
  Attr.AccelTable = OWLHELPAPACCEL; // AccelTable can be assigned
}

void
TOwlHelpWnd::EvPaint()
{
  TPaintDC paintDC(HWindow);
  
  TRect rectClient;
  GetClientRect(rectClient);
  rectClient.Inflate(-rectClient.right, -rectClient.bottom);
  paintDC.SetBkMode(TRANSPARENT);
  paintDC.DrawText(ClientAreaText, strlen(ClientAreaText),
                   rectClient, DT_CENTER | DT_VCENTER | DT_WORDBREAK);
}

void
TOwlHelpWnd::EvEnterIdle(UINT source, HWND)
{
  // if the keystate high bit is set, then the key is pressed
  if (source == MSGF_MENU && (::GetKeyState(VK_F1) & 0x8000)) {
    F1Pressed = TRUE;
    PostMessage(WM_KEYDOWN, VK_RETURN);

  } else
    DefaultProcessing();
}

void
TOwlHelpWnd::CmMenuItemA()
{
  if (F1Pressed) {
    WinHelp(HelpFile, HELP_CONTEXT, HELP_MENUITEMA);
    F1Pressed = FALSE;

  } else {
    MessageBox("In Menu Item A command", Title, MB_ICONINFORMATION);
  }
}

void
TOwlHelpWnd::CmMenuItemB()
{
  if (F1Pressed) {
    WinHelp(HelpFile, HELP_CONTEXT, HELP_MENUITEMB);
    F1Pressed = FALSE;

  } else {
    MessageBox("In Menu Item B Command", Title, MB_ICONINFORMATION);
  }
}

void
TOwlHelpWnd::CmExit()
{
  if (F1Pressed) {
    WinHelp(HelpFile, HELP_CONTEXT, HELP_EXIT);
    F1Pressed = FALSE;

  } else {
    TWindow::CmExit();
  }
}

void
TOwlHelpWnd::CmHelpIndex()
{
  WinHelp(HelpFile, HELP_INDEX, 0);
}

void
TOwlHelpWnd::CmHelpHelp()
{
  WinHelp(HelpFile, HELP_HELPONHELP, 0);
}

void
TOwlHelpWnd::CmHelpAbout()
{
  MessageBox("HELP\nWritten using ObjectWindows\n"
             "Copyright (c) 1991, 1993 Borland",
             "About Help", MB_ICONINFORMATION);
}


class TOwlHelpApp : public TApplication {
  public:
    TOwlHelpApp() : TApplication() {}
    void InitInstance() {   
      TApplication::InitInstance();
      HAccTable = LoadAccelerators(OWLHELPAPACCEL);
    }
    void InitMainWindow();
};

void
TOwlHelpApp::InitMainWindow()
{
  MainWindow = new TOwlHelpWnd("OWL Help Example");
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TOwlHelpApp().Run();
}
