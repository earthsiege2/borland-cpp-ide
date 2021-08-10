//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Illustrates usage of PropertySheets and PropertyPages
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_PROPSHT_H)
# include <owl/propsht.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_CHOOSECO_H)
# include <owl/chooseco.h>
#endif
#include <stdio.h>
#include "propsht.h"

//
// class TWinAttrDlg
// ~~~~~ ~~~~~~~~~~~
class TWinAttrDlg : public TPropertyPage {
  public:
    TWinAttrDlg(TPropertySheet* parent);

    // Overriden virtuals
    //
    void              SetupWindow();
    int               Apply(TNotify&);

    // Event handlers
    //
    void              BkColorClick();
    void              EnChange();

    TColor            BkColor;
    TAPointer<char>   Caption;

  DECLARE_RESPONSE_TABLE(TWinAttrDlg);
};

TWinAttrDlg::TWinAttrDlg(TPropertySheet* parent)
            :TPropertyPage(parent, IDD_WINATTR, "WinAttrDlg", IDI_COLOR)
{
}

DEFINE_RESPONSE_TABLE1(TWinAttrDlg, TPropertyPage)
    EV_BN_CLICKED(IDC_BKCOLOR, BkColorClick),
    EV_EN_CHANGE(IDC_TEXTEDIT, EnChange),
END_RESPONSE_TABLE;

void
TWinAttrDlg::SetupWindow()
{
  TPropertyPage::SetupWindow();

  // Grab client window's caption
  //
  Caption = new char[_MAX_PATH];
  GetApplication()->GetMainWindow()->GetWindowText(Caption, _MAX_PATH);
  SetDlgItemText(IDC_TEXTEDIT, Caption);

  // Client's color is the default window color [??]
  //
  BkColor = TColor::SysWindow;
}

void
TWinAttrDlg::BkColorClick()
{
  TChooseColorDialog::TData colorData;
  TAPointer<TColor> custColors = new TColor[16];
  colorData.Flags = CC_RGBINIT;
  colorData.Color = BkColor;
  colorData.CustColors = custColors;
  if (TChooseColorDialog(this, colorData).Execute() == IDOK) {
    if (colorData.Color != BkColor) {
      BkColor = colorData.Color;
      GetSheet()->PageChanged(*this);
    }
  }
}

void
TWinAttrDlg::EnChange()
{
  char text[_MAX_PATH];
  text[0] = 0;
  GetDlgItemText(IDC_TEXTEDIT, text, sizeof(text));
  if (strcmp(text, Caption))
    GetSheet()->PageChanged(*this);
}

int               
TWinAttrDlg::Apply(TNotify& not)
{
  // Set color
  //
  GetApplication()->GetMainWindow()->GetClientWindow()->SetBkgndColor(BkColor);
  GetApplication()->GetMainWindow()->GetClientWindow()->Invalidate();

  // And caption
  //
  char text[_MAX_PATH];
  text[0] = 0;
  GetDlgItemText(IDC_TEXTEDIT, text, sizeof(text));
  if (strcmp(text, Caption)) {
    GetApplication()->GetMainWindow()->SetWindowText(text);
    Caption = strnewdup(text);
  }

  // These changes are not 'Cancellable'
  //
  GetSheet()->CancelToClose();

  return TPropertyPage::Apply(not);
}

//----------------------------------------------------------------------------

//
// class TTestPage
// ~~~~~ ~~~~~~~~~
class TTestPage : public TPropertyPage {
  public:
    TTestPage(TPropertySheet* parent);

    // Event handlers
    //
    void EvCommandAndId(uint id);

    // Override virtuals of TPropertyPage
    //
    int   SetActive(TNotify&);    // PSN_SETACTIVE
    bool  KillActive(TNotify&);   // PSN_KILLACTIVE
    int   Apply(TNotify&);        // PSN_APPLY
    void  Reset(TNotify&);        // PSN_RESET
    void  Help(TNotify&);         // PSN_HELP
    bool  QueryCancel(TNotify&);  // PSN_QUERYCANCEL

    DECLARE_RESPONSE_TABLE(TTestPage);
};

TTestPage::TTestPage(TPropertySheet* parent)
          :TPropertyPage(parent, IDD_SAMPLEPAGE, "TestPage")
{
}

DEFINE_RESPONSE_TABLE1(TTestPage, TPropertyPage)

  // Handlers of control specific to this page/dialog
  //
  EV_COMMAND_AND_ID(IDC_SIM_APPLY,        EvCommandAndId),
  EV_COMMAND_AND_ID(IDC_SIM_XCELTOCLOSE,  EvCommandAndId),
  EV_COMMAND_AND_ID(IDC_SIM_CHANGED,      EvCommandAndId),
  EV_COMMAND_AND_ID(IDC_SIM_UNCHANGED,    EvCommandAndId),

  EV_COMMAND_AND_ID(IDC_ADDPAGE,          EvCommandAndId),
  EV_COMMAND_AND_ID(IDC_REMPAGE,          EvCommandAndId),
  EV_COMMAND_AND_ID(IDC_SELPAGE,          EvCommandAndId),
  EV_COMMAND_AND_ID(IDC_PAGEINFO,         EvCommandAndId),
END_RESPONSE_TABLE;

void
TTestPage::EvCommandAndId(uint id)
{
  switch(id) {
    case IDC_SIM_APPLY:
         GetSheet()->Apply();
         break;

    case IDC_SIM_XCELTOCLOSE:
         GetSheet()->CancelToClose();
         break;

    case IDC_SIM_CHANGED:
         GetSheet()->PageChanged(*this);
         break;

    case IDC_SIM_UNCHANGED:
         GetSheet()->PageUnchanged(*this);
         break;
  }
}

int   
TTestPage::SetActive(TNotify& not)    
{
  return TPropertyPage::SetActive(not);
}

bool  
TTestPage::KillActive(TNotify& not)
{
  return TPropertyPage::KillActive(not);
}

int   
TTestPage::Apply(TNotify& not)
{
  return TPropertyPage::Apply(not);
}

void  
TTestPage::Reset(TNotify& not)
{
  TPropertyPage::Reset(not);
}

void  
TTestPage::Help(TNotify& not)
{
  TPropertyPage::Help(not);
  MessageBox("Invoke WinHelp() here", GetModule()->GetName(), MB_OK);
}

bool  
TTestPage::QueryCancel(TNotify& not)
{
  return TPropertyPage::QueryCancel(not);
}

//----------------------------------------------------------------------------

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {

  public:
    TClientWindow(TWindow* parent= 0);

  protected:
    // Message Handlers
    //
    void        Properties(bool modal);
    void        PropertiesModal()    { Properties(true);  }
    void        PropertiesModeless() { Properties(false); }

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_COMMAND(CM_PROPERTY, PropertiesModal),
  EV_COMMAND(CM_PROPMODELESS, PropertiesModeless),
END_RESPONSE_TABLE;


TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent)
{
  Attr.Style |= (WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
}

void
TClientWindow::Properties(bool modal)
{
  // Allocate a PropertySheet object
  //
  TPropertySheet* ps = new TPropertySheet(this, "Options", 0, false, 
                                PSH_HASHELP);

  // Allocate PropertyPage objects using the sheet as 'parent' parameters
  //
  new TWinAttrDlg(ps);
  (new TTestPage(ps))->SetFlags(PSP_HASHELP);
  
  if (modal)
    ps->Execute();
  else
    ps->Create();
}

//----------------------------------------------------------------------------

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void    InitMainWindow();
};

void
TSampleApp::InitMainWindow()
{
  EnableCtl3d();
  SetName("Property Sheet");
  SetMainWindow(new TFrameWindow(0, GetName(), new TClientWindow()));
  GetMainWindow()->AssignMenu(IDM_APPMENU);
}

int
OwlMain(int /*argc*/, char*/*argv*/[])
{
  return TSampleApp().Run();
}
