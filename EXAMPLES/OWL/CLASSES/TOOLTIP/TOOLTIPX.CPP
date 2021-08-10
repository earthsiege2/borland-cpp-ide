//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// Illustrates usage of TTooltip class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/decframe.h>
#include <owl/statusba.h>
#include <owl/controlb.h>
#include <owl/buttonga.h>
#include <owl/inputdia.h>
#include <owl/tooltip.h>
#include <owl/combobox.h>
#include <owl/controlg.h>
#include <stdio.h>
#include "tooltip.h"

const int ID_COMBOBOX = 0x1000;

TRect redRect   = TRect(10, 10, 100, 100);
TRect blueRect  = TRect(110, 10, 200, 100);
TRect yellowRect= TRect(10, 110, 100, 200);
TRect greenRect = TRect(110, 110, 200, 200);

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp() : Tooltip(0){}

    // Override virtuals from TApplication
    //
    void    InitMainWindow();

    // Application's tooltip control
    //
    TTooltip* Tooltip;
};

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow(TWindow* parent= 0);

  protected:

    bool            PreProcessMsg(MSG& msg);
    void            Paint(TDC& dc, bool erase, TRect& rect);
    void            SetupWindow();

    // Command handlers
    //
    void            CmToolbarTip();
    void            CeToolbarTip(TCommandEnabler&);
    void            CmWindowTip();
    void            CeWindowTip(TCommandEnabler&);

    // Notification handlers
    //
    void            GreenTipText(TTooltipText far& ttText);
    void            YellowTipText(TTooltipText far& ttText);

    // Flags whether tooltip's active
    //
    bool            ToolbarTipActive;
    bool            WindowTipActive;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_TTN_NEEDTEXT(ID_YELLOWTOOL, YellowTipText),
  EV_TTN_NEEDTEXT(ID_GREENTOOL, GreenTipText),
  EV_COMMAND(CM_TOOLBARTIP, CmToolbarTip),
  EV_COMMAND_ENABLE(CM_TOOLBARTIP, CeToolbarTip),
  EV_COMMAND(CM_WINDOWTIP, CmWindowTip),
  EV_COMMAND_ENABLE(CM_WINDOWTIP, CeWindowTip),
END_RESPONSE_TABLE;

//
//
//
TClientWindow::TClientWindow(TWindow* parent) 
              :TWindow(parent), ToolbarTipActive(true), WindowTipActive(true)
{
}

//
//
//
void
TClientWindow::SetupWindow()
{
  TWindow::SetupWindow();

  TSampleApp* app = TYPESAFE_DOWNCAST(GetApplication(), TSampleApp);
  if (app) {
    TTooltip* tooltip = app->Tooltip;
    if (tooltip && tooltip->GetHandle()) {

      // Add tooltip for red rectangle - For this tip, we'll provide
      // a string when adding the tool.
      // NOTE: Since TToolInfo will cache the text, make sure that the
      //       object's lifetime is valid for the lifetime of the tooltip
      //
      TToolInfo tiRed(*this, redRect, ID_REDTOOL, "Red rectangle");
      tooltip->AddTool(tiRed);

      // Add tooltip for blue rectangle specifying string resource
      //
      TToolInfo tiBlue(*this, blueRect, ID_BLUETOOL,
                      ID_BLUETOOL, *GetApplication());
      tooltip->AddTool(tiBlue);

      // Add tooltip for yellow rectangle leaving out the text.
      // Tooltip will send TTN_NEEDTEXT notification at runtime
      //
      TToolInfo tiYellow(*this, yellowRect, ID_YELLOWTOOL);
      tooltip->AddTool(tiYellow);

      // Add tooltip for green rectangle leaving out the text.
      // Tooltip will send TTN_NEEDTEXT notification at runtime
      //
      TToolInfo tiGreen(*this, greenRect, ID_GREENTOOL);
      tooltip->AddTool(tiGreen);

      // Add tooltip for combobox in controlbar
      //
    }
  }
}

//
//
//
bool
TClientWindow::PreProcessMsg(MSG& msg)
{
  TSampleApp* app = TYPESAFE_DOWNCAST(GetApplication(), TSampleApp);
  if (app) {
    TTooltip* tooltip = app->Tooltip;
    if (tooltip && tooltip->IsWindow()) 
      tooltip->RelayEvent(msg);
  }

  // Always let event go through!
  //
  return TWindow::PreProcessMsg(msg);
}

//
//
//
void
TClientWindow::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  dc.TextRect(blueRect, TColor(0, 0, 0xff));
  dc.TextRect(redRect, TColor(0xff, 0, 0));
  dc.TextRect(yellowRect, TColor(0xff, 0xff, 0));
  dc.TextRect(greenRect, TColor(0, 0xff, 0));
}

//
//
//
void
TClientWindow::GreenTipText(TTooltipText far& ttText)
{
  // Provide tiptext string using constant string
  //
  TTooltipText& foo = *(TTooltipText*)&ttText;
  foo.CopyText("Green Rectangle");
}

//
//
//
void
TClientWindow::YellowTipText(TTooltipText far& ttText)
{
  // Provide tiptext using a string resource
  //
  TTooltipText& foo = *(TTooltipText*)&ttText;
  foo.SetText(ID_YELLOWTOOL, *GetApplication());
}

void            
TClientWindow::CmToolbarTip()
{
  ToolbarTipActive = !ToolbarTipActive;
  TWindow* tb = GetApplication()->GetMainWindow()->ChildWithId(IDW_TOOLBAR);
  if (tb) {
    TGadgetWindow *gw = TYPESAFE_DOWNCAST(tb, TGadgetWindow);
    if (gw)
      gw->EnableTooltip(ToolbarTipActive);
  }
}

void            
TClientWindow::CeToolbarTip(TCommandEnabler &ce)
{
  ce.SetCheck(ToolbarTipActive ? TCommandEnabler::Checked :
                                 TCommandEnabler::Unchecked);
}

void            
TClientWindow::CmWindowTip()
{
  WindowTipActive = !WindowTipActive;
  TSampleApp* app = TYPESAFE_DOWNCAST(GetApplication(), TSampleApp);
  if (app) {
    TTooltip* tooltip = app->Tooltip;
    tooltip->Activate(WindowTipActive);
  }
}

void            
TClientWindow::CeWindowTip(TCommandEnabler &ce)
{
  ce.SetCheck(WindowTipActive ? TCommandEnabler::Checked :
                                TCommandEnabler::Unchecked);
}

//----------------------------------------------------------------------------

void
TSampleApp::InitMainWindow()
{
  // Setup main window + client
  //
  SetMainWindow(new TDecoratedFrame(0, "Tooltip Example", 
                new TClientWindow()));

  // Create decoration objects
  //
  TStatusBar*  sbar = new TStatusBar(GetMainWindow());
  TControlBar* cbar = new TControlBar(GetMainWindow());
  cbar->Attr.Id = IDW_TOOLBAR;

  // Insert gadgets in control bar
  //
  cbar->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW));
  cbar->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN));
  cbar->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
  cbar->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));

  cbar->Insert(*new TSeparatorGadget);
  cbar->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cbar->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cbar->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cbar->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));

  cbar->Insert(*new TSeparatorGadget);
  TComboBox* cBox = new TComboBox(0, ID_COMBOBOX, 0, 0, 180, 150, 
                                  CBS_DROPDOWNLIST, -1);
  cbar->Insert(*new TControlGadget(*cBox));

  // Insert decorations in main window
  //
  TYPESAFE_DOWNCAST(GetMainWindow(), TDecoratedFrame)->Insert(
                    *cbar, TDecoratedFrame::Top);
  TYPESAFE_DOWNCAST(GetMainWindow(), TDecoratedFrame)->Insert(
                    *sbar, TDecoratedFrame::Bottom);

  GetMainWindow()->AssignMenu(IDM_MAINMENU);

  // Associated tooltip object with client window of our SDI application
  //
  Tooltip = new TTooltip(GetMainWindow()->GetClientWindow());
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSampleApp().Run();
}
