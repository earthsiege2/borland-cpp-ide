//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// Sample illustrating the TTabControl class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/tabctrl.h>
#include <owl/button.h>
#include <owl/groupbox.h>
#include <owl/radiobut.h>
#include <owl/checkbox.h>
#include <owl/inputdia.h>
#include <owl/notetab.h>
#include <owl/commctrl.h>
#include <stdio.h>
#include "tabctrl.h"

//
// Define a few constants
//
const int   TabCtlID  = 0x100;        // ID of the TabControl


//
// Template to toggle bits on and off
//
template <class T1, class T2>
inline void BitsOnOff(T1& value, T2 bitOn, T2 bitOff)
{
  value |=  bitOn;
  value &= ~bitOff;
}

//
//
//
class TNoteTabDlg : public TDialog {
  public:
    TNoteTabDlg(TWindow* parent, TResId id);

    void      SetupWindow();

  protected:
    TNoteTab* NoteTab;

    // Event handlers
    //
    void      TabSelChange(TNotify far&);
    
  DECLARE_RESPONSE_TABLE(TNoteTabDlg);
};

DEFINE_RESPONSE_TABLE1(TNoteTabDlg, TDialog)
  EV_TCN_SELCHANGE(IDC_NOTETAB, TabSelChange),
END_RESPONSE_TABLE;

char *Tabs[]   = {"Title", "Ship To", "Order Notes"};
int  TitleIDs[]= {IDC_RADIOBUTTON1, IDC_RADIOBUTTON2, IDC_RADIOBUTTON3};
int  ShipIDs[] = {IDC_STATIC1, IDC_EDIT1, IDC_STATIC2, IDC_EDIT2};
int  OrderIDs[]= {IDC_STATIC3, IDC_EDIT3};

//
//
//
TNoteTabDlg::TNoteTabDlg(TWindow* parent, TResId id)
            :TDialog(parent, id)
{
  NoteTab = new TNoteTab(this, IDC_NOTETAB);
  NoteTab->SetWindowFace(true);
}

//
//
//
void
TNoteTabDlg::SetupWindow()
{
  TDialog::SetupWindow();
  for (int i=0; i<sizeof(Tabs)/sizeof(Tabs[0]); i++)
    NoteTab->Add(Tabs[i]);
  NoteTab->SetSel(0);
}

//
//
//
void      
TNoteTabDlg::TabSelChange(TNotify far&)
{
  int index = NoteTab->GetSel(), i;
  for (i=0; i<COUNTOF(TitleIDs); i++) {
    ::ShowWindow(GetDlgItem(TitleIDs[i]), index == 0 ? SW_SHOW : SW_HIDE);
    ::EnableWindow(GetDlgItem(TitleIDs[i]), index == 0 ? TRUE : FALSE);
  }
  for (i=0; i<COUNTOF(ShipIDs); i++) {
    ::ShowWindow(GetDlgItem(ShipIDs[i]), index == 1 ? SW_SHOW : SW_HIDE);
    ::EnableWindow(GetDlgItem(ShipIDs[i]), index == 1 ? TRUE : FALSE); 
  }              
  for (i=0; i<COUNTOF(OrderIDs); i++) {
    ::ShowWindow(GetDlgItem(OrderIDs[i]), index == 2 ? SW_SHOW : SW_HIDE);
    ::EnableWindow(GetDlgItem(OrderIDs[i]), index == 2 ? TRUE : FALSE);
  }              
}


//
// class TMainWindow
// ~~~~~ ~~~~~~~~~~~
class TMainWindow : public TFrameWindow {
  public:
    TMainWindow(TWindow* clientWnd, bool shrinkToClient = false);

  protected:

    //
    //
    void      AdjustTabClient();

    // Message Handlers
    //
    void          EvSize(uint sizeType, TSize& size);

    void          TabSelChange(TNotify far&);
    bool          TabSelChanging(TNotify far&);
    void          TabKeyDown(TTabKeyDown far&);

    void          CmNewTab();
    void          CmAddItem();

    void          CmRemoveItem();
    void          CeRemoveItem(TCommandEnabler& ce);

    void          CmDeleteAll();
    void          CeDeleteAll(TCommandEnabler& ce);

    void          CmChangeItem();
    void          CeChangeItem(TCommandEnabler& ce);

    void          CmInfo();

    void          CmVetoSelChanging();
    void          CeVetoSelChanging(TCommandEnabler& ce);

    void          CmShowNoteTab();

  public:
    TTabControl*  Tab;

  protected:
    bool          VetoSelChanging;
    TWindow*      Client;

  DECLARE_RESPONSE_TABLE(TMainWindow);
};


DEFINE_RESPONSE_TABLE1(TMainWindow, TFrameWindow)
  EV_WM_SIZE,

  // Tab Control Notifications
  //
  EV_TCN_SELCHANGE(TabCtlID, TabSelChange),
  EV_TCN_SELCHANGING(TabCtlID, TabSelChanging),
  EV_TCN_KEYDOWN(TabCtlID, TabKeyDown),

  // Menu Commands
  //
  EV_COMMAND(CM_NEWTAB,       CmNewTab),
  EV_COMMAND(CM_ADDITEM,      CmAddItem),

  EV_COMMAND(CM_REMOVEITEM,   CmRemoveItem),
  EV_COMMAND_ENABLE(CM_REMOVEITEM, CeRemoveItem),

  EV_COMMAND(CM_DELETEALL,    CmDeleteAll),
  EV_COMMAND_ENABLE(CM_DELETEALL, CeDeleteAll),

  EV_COMMAND(CM_CHANGEITEM,   CmChangeItem),
  EV_COMMAND_ENABLE(CM_CHANGEITEM, CeChangeItem),

  EV_COMMAND(CM_INFO,         CmInfo),
  EV_COMMAND(CM_SHOWNOTETAB,  CmShowNoteTab),

  EV_COMMAND(CM_VETOSELCHANGING,  CmVetoSelChanging),
  EV_COMMAND_ENABLE(CM_VETOSELCHANGING, CeVetoSelChanging),
END_RESPONSE_TABLE;

//
//
//
TMainWindow::TMainWindow(TWindow* clientWnd, bool shrinkToClient)
            :TFrameWindow(0, "Tabs & Notetabs", clientWnd, shrinkToClient),
             VetoSelChanging(false), Tab(0), Client(0)
{
}

void
TMainWindow::AdjustTabClient()
{
  // Retrieve pointer to tab control, the client window
  //
  TTabControl* tab = TYPESAFE_DOWNCAST(GetClientWindow(), TTabControl);
  if (tab && tab->GetHandle()) {

    // Retrieve the window rectangle of the tab control
    //
    TRect rect;
    tab->GetWindowRect(rect);

    // NOTE: GetWindowRect returns screen coordinates... we'll need
    //       to have the coordinates relative to the frame window,
    //       the parent of both the tab and client window
    ::MapWindowPoints(HWND_DESKTOP, *this, (LPPOINT)&rect, 2);

    // Ask the tab for it's 'client-area' based in it window location
    //
    tab->AdjustRect(false, rect);

    // Move the Client window
    //
    if (Client && Client->GetHandle())
      Client->SetWindowPos(HWND_TOP, rect, SWP_SHOWWINDOW);
  }
}

//
//
//
void
TMainWindow::EvSize(uint sizeType, TSize& size)
{
  // Let frame resize the client
  //
  TFrameWindow::EvSize(sizeType, size);

  // Adjust the edit control (which is kind of the client of the
  // tab control)...
  //
  AdjustTabClient();
}

//
//
//
void
TMainWindow::TabSelChange(TNotify far& /*nm*/)
{
}

//
//
//
bool
TMainWindow::TabSelChanging(TNotify far& /*nm*/)
{
  return VetoSelChanging ? 1 : 0;
}

//
//
//
void
TMainWindow::TabKeyDown(TTabKeyDown far& /*tk*/)
{
  // NOP
}

//
// CmNewTab() creates a dialog which allows the user to select the type
// of TabControl to be created. It then proceeds to create the control
// and makes the new control the client of the application's frame window.
//
void
TMainWindow::CmNewTab()
{
  // Create/Initialize a structure to set and retrieve data;
  //
  struct {
    uint16   buttonStyle;
    uint16   defStyle;
    uint16   singleLine;
    uint16   multipleLine;
  } dlgData = {0, 1, 1, 0};

  // Create C++ objects representing the Dialog and its controls
  //
  TDialog* dlg = new TDialog(this, IDD_NEWTAB);
  new TRadioButton(dlg, IDC_RADIOBUTTON1);
  new TRadioButton(dlg, IDC_RADIOBUTTON2);
  new TRadioButton(dlg, IDC_RADIOBUTTON3);
  new TRadioButton(dlg, IDC_RADIOBUTTON4);

  // Set the transfer buffer and execute the dialog
  //
  dlg->SetTransferBuffer(&dlgData);
  if (dlg->Execute() == IDOK) {
    // Create a new Tab Control
    //
    TTabControl* tab = new TTabControl(0, TabCtlID, 0, 0, 0, 0);

    // Convert selection into style bits
    //
    if (dlgData.defStyle)
      BitsOnOff(tab->Attr.Style, TCS_TABS, TCS_BUTTONS);
    if (dlgData.buttonStyle)
      BitsOnOff(tab->Attr.Style, TCS_BUTTONS, TCS_TABS);
    if (dlgData.singleLine)
      BitsOnOff(tab->Attr.Style, TCS_SINGLELINE, TCS_MULTILINE);
    if (dlgData.multipleLine)
      BitsOnOff(tab->Attr.Style, TCS_MULTILINE, TCS_SINGLELINE);

    // Cleanup prior client window
    //
    TWindow* oldClient = SetClientWindow(tab);
    Tab = tab;
    if (oldClient) {
      if (oldClient->GetHandle())
        oldClient->Destroy();
      delete oldClient;
    }
  }
}

//
// This function prompts the user for a label and creates a new
// tab item...
//
void
TMainWindow::CmAddItem()
{
  // Prompt user for the label of the tab item
  //
  char lblTxt[80] = {0};
  TInputDialog promptDlg(this, "New Item", "Enter Item Label",
                         lblTxt, sizeof(lblTxt));
  if (promptDlg.Execute() == IDOK) {
    if (lblTxt[0]) {

      // Retrieve a pointer to the tab control
      //
      TTabControl* tab = TYPESAFE_DOWNCAST(GetClientWindow(), TTabControl);

      // Add a new item to the tabcontrol
      //
      if (tab) {
        TTabItem tabItem(lblTxt);
        tab->Add(tabItem);

        // Adjust Client in case the Tab items got rearranged
        //
        AdjustTabClient();
      }
    }
  }
}

//
//
//
void
TMainWindow::CeRemoveItem(TCommandEnabler& ce)
{
  ce.Enable((Tab && Tab->GetSel() != -1) ? true : false);
}


//
// This methods offers the user a list of the tab items and removes
// the selected one (if one is selected via the picklist dialog).
//
void
TMainWindow::CmRemoveItem()
{
  // Prompt user for the label of the tab item
  //
  char indexTxt[80] = {0};
  TInputDialog promptDlg(this, "Remove Item", "Enter Item Index",
                        indexTxt, sizeof(indexTxt));
  if (promptDlg.Execute() == IDOK && indexTxt[0]) {
    // Retrieve a pointer to the tab control
    //
    TTabControl* tab = TYPESAFE_DOWNCAST(GetClientWindow(), TTabControl);

    int index = atoi(indexTxt);

    // Remove item from tabcontrol
    //
    if (tab) {
      if (index < tab->GetCount() && index >=0) {
        tab->Delete(index);

        // Adjust Client in case the Tab items got rearranged
        //
        AdjustTabClient();
      } else {
        MessageBox("Invalid index specified", "INFO");
      }
    }
  }
}

//
//
//
void
TMainWindow::CmChangeItem()
{
  int index = Tab->GetSel();
  if (index != -1) {
    char label[80];
    TTabItem item(*Tab, index, TCIF_TEXT, sizeof(label), label);

    char prmpt[100];
    sprintf(prmpt, "New label of (%s)", label);

    TInputDialog promptDlg(this, "Change Item", prmpt, label, sizeof(label));
    if (promptDlg.Execute() == IDOK) {
      if (label[0]) {
        Tab->SetItem(index, item);

        // Adjust Client in case the Tab items got rearranged
        //
        AdjustTabClient();
      }
    }
  }
}

//
//
//
void
TMainWindow::CeChangeItem(TCommandEnabler& ce)
{
  ce.Enable((Tab && Tab->GetSel() != -1) ? true : false);
}

//
//
//
void
TMainWindow::CmDeleteAll()
{
  TTabControl* tab = TYPESAFE_DOWNCAST(GetClientWindow(), TTabControl);
  if (tab) {
    tab->DeleteAll();

    // Adjust Client in case the Tab items got rearranged
    //
    AdjustTabClient();
  }
}

//
//
//
void
TMainWindow::CeDeleteAll(TCommandEnabler& ce)
{
  ce.Enable((Tab && Tab->GetCount()) ? true : false);
}

//
//
//
void
TMainWindow::CmVetoSelChanging()
{
  VetoSelChanging = !VetoSelChanging;
}

//
//
//
void
TMainWindow::CeVetoSelChanging(TCommandEnabler& ce)
{
  ce.SetCheck(VetoSelChanging ? TCommandEnabler::Checked :
                                TCommandEnabler::Unchecked);
}

//
//
//
void TMainWindow::CmInfo()
{
  char infoStr[1024];
  sprintf(infoStr, "Count:%d, RowCount:%d, Sel:%d, ImageList:%08X",
          Tab->GetCount(), Tab->GetRowCount(), Tab->GetSel(), 
          Tab->GetImageList());
  MessageBox(infoStr, "INFO");          
}

//
//
//
void          
TMainWindow::CmShowNoteTab()
{
  TNoteTabDlg(this, IDD_NOTETAB).Execute();
}


//----------------------------------------------------------------------------

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
// A simple Application Object which simply defines InitMainWindow()
// to initialize the application's frame and client windows.
//
class TSampleApp : public TApplication {
  public:
    void      InitMainWindow();
};

//
//
//
void
TSampleApp::InitMainWindow()
{
  // Use tab as client of the main window
  //
  TTabControl* tab = new TTabControl(0, TabCtlID, 0, 0, 0, 0);

  // Create frame (with tab as client)
  //
  TMainWindow* frame = new TMainWindow(tab);
  frame->Tab = tab;

  SetMainWindow(frame);
  GetMainWindow()->AssignMenu(IDM_APPMENU);

  // Enable CTL3D
  //
  EnableCtl3d();
}

//
//
//
int
OwlMain(int /*argc*/, char */*argv*/[])
{
  return TSampleApp().Run();
}
