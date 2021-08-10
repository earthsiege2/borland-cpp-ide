//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\button.h>
#include <owl\dialog.h>
#include <owl\framewin.h>
#include <owl\menu.h>
#include "notify.h"
#include <stdio.h>

//
// Make a button that beeps when pressed.
//
class TBeepButton : public TButton {
  public:
    TBeepButton(TWindow* parent, int resId) : TButton(parent, resId) {}

    // child id notification handled at the child
    //
    void BNClicked();  // BN_CLICKED

  DECLARE_RESPONSE_TABLE(TBeepButton);
};

DEFINE_RESPONSE_TABLE1(TBeepButton, TButton)
  EV_NOTIFY_AT_CHILD(BN_CLICKED, BNClicked),
END_RESPONSE_TABLE;

void
TBeepButton::BNClicked()
{
  MessageBeep(0);
  DefaultProcessing();  // pass it along to parent.
}

//
// Button that sends parent it's own notification code.
//
class TTestButton : public TButton {
  public:

    static UINT   BN_USER_MSG1;       // notification code.

    TTestButton(TWindow* parent, int resId) : TButton(parent, resId) {}

    // child id notification handled at the child
    //
    void BNClicked();  // BN_CLICKED

  DECLARE_RESPONSE_TABLE(TTestButton);
};

DEFINE_RESPONSE_TABLE1(TTestButton, TButton)
  EV_NOTIFY_AT_CHILD(BN_CLICKED, BNClicked),
END_RESPONSE_TABLE;

UINT TTestButton::BN_USER_MSG1 = 400;

//
// One method of notifying the parent of an event.
//
void
TTestButton::BNClicked()
{
  #if defined(__WIN32__)
    Parent->HandleMessage(WM_COMMAND, MAKEWPARAM(Attr.Id, BN_USER_MSG1),
                          LPARAM(HWindow));
  #else
    Parent->HandleMessage(WM_COMMAND, Attr.Id, MAKELPARAM(HWindow, BN_USER_MSG1));
  #endif
}


//----------------------------------------------------------------------------

class TBeepDialog : public TDialog {
  public:
    int           NumClicks;        // number of times BeepButton was pressed.
    TBeepButton*  BeepButton;       // Different buttons...
    TButton*      Button1;
    TTestButton*  Button2;
    TButton*      Button3;
    TButton*      Button4;

    TBeepDialog(TWindow* parent, TResId resId);

    void    HandleButtonMsg();      // ID_BUTTON  push button command
    void    HandleButton1();        // ID_BUTTON1 push button command
    void    HandleButton2(WPARAM);  // ID_BUTTON2 push button command
    void    HandleButton3(WPARAM);  // ID_BUTTON3 push button command
    void    HandleButton4();        // ID_BUTTON4 push button command

  DECLARE_RESPONSE_TABLE(TBeepDialog);
};

DEFINE_RESPONSE_TABLE1(TBeepDialog, TDialog)
  EV_BN_CLICKED(ID_BUTTON, HandleButtonMsg),
  EV_COMMAND(ID_BUTTON4, HandleButton4),
  EV_CHILD_NOTIFY(ID_BUTTON1, BN_CLICKED, HandleButton1),
  EV_CHILD_NOTIFY_AND_CODE(ID_BUTTON2, TTestButton::BN_USER_MSG1, HandleButton2),
  EV_CHILD_NOTIFY_ALL_CODES(ID_BUTTON3, HandleButton3),
END_RESPONSE_TABLE;

TBeepDialog::TBeepDialog(TWindow* parent, TResId resId)
  : TDialog(parent, resId),
    TWindow(parent)
{
  NumClicks = 0;
  BeepButton = new TBeepButton(this, ID_BUTTON);
  Button1 = new TButton(this, ID_BUTTON1);
  Button2 = new TTestButton(this, ID_BUTTON2);
  Button3 = new TButton(this, ID_BUTTON3);
  Button4 = new TButton(this, ID_BUTTON4);
}

//
// Handle BN_CLICKED from 'BeepButton'.  Display the number of times it has
// been pressed.
//
void
TBeepDialog::HandleButtonMsg()
{
  char  text[4];
  sprintf(text, "%d", ++NumClicks);
  ::SetWindowText(GetDlgItem(ID_STATIC), text);
}

//
// Handle BN_CLICKED from 'Button1'.
//
void
TBeepDialog::HandleButton1()
{
  MessageBox("Button1", "Pressed!", MB_OK);
}

//
// Handle BN_USER_MSG1 from 'Button2'.
//
void
TBeepDialog::HandleButton2(WPARAM)
{
  MessageBox("Button2", "Pressed!", MB_OK);
}

//
// Handle BN_CLICKED from 'Button3'.
//
void
TBeepDialog::HandleButton3(WPARAM)
{
  MessageBox("Button3", "Pressed!", MB_OK);
}

//
// Handle BN_CLICKED from 'Button4'.
//
void
TBeepDialog::HandleButton4()
{
  MessageBox("Button4", "Pressed!", MB_OK);
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}

  protected:
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "Notification Tester");
      MainWindow->AssignMenu(IDM_COMMANDS);
    }
    void    CmTest();  // CM_TEST  menu command handler

  DECLARE_RESPONSE_TABLE(TTestApp);
};

DEFINE_RESPONSE_TABLE1(TTestApp, TApplication)
  EV_COMMAND(CM_TEST, CmTest),
END_RESPONSE_TABLE;

void
TTestApp::CmTest()
{
  (new TBeepDialog(MainWindow, IDD_TEST))->Create();
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}
