// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1991, 1995 by Borland International, All Rights Reserved
//
// Example illustrating PushButtons, Checkboxes, RadioButtons and GroupBoxes
// Also illustrates the GroupBox notifications provided by ObjectWindows.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/button.h>
#include <owl/checkbox.h>
#include <owl/radiobut.h>
#include <owl/groupbox.h>

//
// IDs of Controls
//
const uint16 ID_BUTTON   = 101;
const uint16 ID_RBUTTON1 = 102;
const uint16 ID_RBUTTON2 = 103;
const uint16 ID_CHECKBOX = 104;
const uint16 ID_GROUPBOX = 105;

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
//  TTestWindow is used as the client of a FrameWindow
//
class TTestWindow : public TWindow {
  public:
    TTestWindow();

    // Message Handlers
    //
    void  HandleButtonMsg();      // Handles notifications from ID_BUTTON
    void  HandleCheckBoxMsg();    // Handles notifications from ID_CHECKBOX
    void  HandleGroupBoxMsg(uint);// Handles notifications from ID_GROUPBOX

  protected:
    // C++ Objects behind the controls
    //
    TRadioButton* RButton1;
    TRadioButton* RButton2;
    TCheckBox*    CheckBox;
    TGroupBox*    GroupBox;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};


DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_COMMAND(ID_BUTTON, HandleButtonMsg),
  EV_COMMAND(ID_CHECKBOX, HandleCheckBoxMsg),
  EV_CHILD_NOTIFY_ALL_CODES(ID_GROUPBOX, HandleGroupBoxMsg),
END_RESPONSE_TABLE;

//
// Constructor of TTestWindow
//
//  The constructor instantiates C++ objects representing PushButtons,
//  CheckBoxes, RadioButtons and GroupBoxes.
//
TTestWindow::TTestWindow()
:
  TWindow(0, 0, 0)
{
  new TButton(this, ID_BUTTON, "State of Check Box", 88, 48, 296, 24, false);
  CheckBox = new TCheckBox(this, ID_CHECKBOX, "Check Box Text", 158, 12, 150, 26, 0);
  GroupBox = new TGroupBox(this, ID_GROUPBOX, "Group Box", 158, 102, 176, 108);
  RButton1 = new TRadioButton(this, ID_RBUTTON1, "Radio Button 1",
                              174, 128, 138, 24, GroupBox);
  RButton2 = new TRadioButton(this, ID_RBUTTON2, "Radio Button 2",
                              174, 162, 138, 24, GroupBox);
}

//
// Handles BN_CLICK notifications from the PushButton and displays
// a MessageBox reporting in the state of the CheckBox.
//
void
TTestWindow::HandleButtonMsg()
{
  if (CheckBox->GetCheck() == BF_CHECKED)
    MessageBox("Checked", "The check box is:", MB_OK);
  else
    MessageBox("Unchecked", "The check box is:", MB_OK);
}

//
// Handles BN_CLICK notifications from the CheckBox and displays
// a MessageBox reporting that te CheckBox has been toggle
//
void
TTestWindow::HandleCheckBoxMsg()
{
  MessageBox("Toggled", "The check box has been:", MB_OK);
}

//
// Handles Notifications from the GroupBox and displays a MessageBox
// reporting the currently selected RadioButton
//
void
TTestWindow::HandleGroupBoxMsg(uint /* notifyCode */)
{
  char textBuff[20];

  if (RButton1->GetCheck() == BF_CHECKED)
    RButton1->GetWindowText(textBuff, sizeof(textBuff));
  else
    RButton2->GetWindowText(textBuff, sizeof(textBuff));

  MessageBox(textBuff, "You have selected:", MB_OK);
}


//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow();
};

//
//
//
void
TTestApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, "Button Tester", new TTestWindow);
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
