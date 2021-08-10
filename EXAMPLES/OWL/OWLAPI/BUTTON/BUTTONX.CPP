//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\button.h>
#include <owl\checkbox.h>
#include <owl\radiobut.h>
#include <owl\groupbox.h>

const WORD ID_BUTTON   = 101;
const WORD ID_RBUTTON1 = 102;
const WORD ID_RBUTTON2 = 103;
const WORD ID_CHECKBOX = 104;
const WORD ID_GROUPBOX = 105;

class TTestWindow : public TWindow {
  public:
    TRadioButton* RButton1;
    TRadioButton* RButton2;
    TCheckBox*    CheckBox;
    TGroupBox*    GroupBox;

    TTestWindow();

    // button handlers
    //
    void  HandleButtonMsg();    // ID_BUTTON
    void  HandleCheckBoxMsg();  // ID_CHECKBOX

    void  HandleGroupBoxMsg(UINT);

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_COMMAND(ID_BUTTON, HandleButtonMsg),
  EV_COMMAND(ID_CHECKBOX, HandleCheckBoxMsg),
  EV_CHILD_NOTIFY_ALL_CODES(ID_GROUPBOX, HandleGroupBoxMsg),
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
  : TWindow(0, 0, 0)
{
  new TButton(this, ID_BUTTON, "State of Check Box", 88, 48, 296, 24, FALSE);
  CheckBox = new TCheckBox(this, ID_CHECKBOX, "Check Box Text", 158, 12, 150, 26, 0);
  GroupBox = new TGroupBox(this, ID_GROUPBOX, "Group Box", 158, 102, 176, 108);
  RButton1 = new TRadioButton(this, ID_RBUTTON1, "Radio Button 1",
                              174, 128, 138, 24, GroupBox);
  RButton2 = new TRadioButton(this, ID_RBUTTON2, "Radio Button 2", 
                              174, 162, 138, 24, GroupBox);
}

void
TTestWindow::HandleButtonMsg()
{
  if (CheckBox->GetCheck() == BF_CHECKED)
    MessageBox("Checked", "The check box is:", MB_OK);

  else
    MessageBox("Unchecked", "The check box is:", MB_OK);
}

void
TTestWindow::HandleCheckBoxMsg()
{
  MessageBox("Toggled", "The check box has been:", MB_OK);
}

void
TTestWindow::HandleGroupBoxMsg(UINT /* notifyCode */)
{
  char textBuff[20];

  if (RButton1->GetCheck() == BF_CHECKED)
    RButton1->GetWindowText(textBuff, sizeof(textBuff));

  else
    RButton2->GetWindowText(textBuff, sizeof(textBuff));

  MessageBox(textBuff, "You have selected:", MB_OK);
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void  InitMainWindow();
};

void
TTestApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, "Button Tester", new TTestWindow);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
