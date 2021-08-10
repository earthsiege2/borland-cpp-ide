//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// MAIN.CPP
// This file is the OWL half of an example that combines OWL and VCL.
// The program creates an OWL-based TApplication object and frame
// window, but in response to a menu command it invokes a VCL form
// that was created with C++Builder.  The form acts as a modal dialog
// box offering the user a choice of colors.  
//
// MAIN.CPP demonstrates the following interactions with a VCL form:
//
// * tell the form what color is  selected (the form shows the user the
//   current selection)
// * invoke the form, making it visible
// * when the form closes, ask it what color was chosen
//
// All this takes place in TMyFrame::CmColor, the menu command handler.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/framewin.h>
#include <owl/applicat.h>
#include <classlib/pointer.h>
#include <vcl/vcl.h>            // OK to include VCL & OWL, but OWL first
#pragma hdrstop
#include "adopt.h"              // for adopting VCL's application window
#include "vcldlg.h"             // C++Builder form unit header
#include "main.h"               

//
// class TMyFrame
// ~~~~~ ~~~~~~~~
// A method of this object invokes the C++Builder form defined
// in VCLDLG.CPP.
//
class TMyFrame: public TFrameWindow {
public:
  TMyFrame(TWindow* parent, const char far* title = 0)
      : TFrameWindow(parent, title), Color(ClassLib::TColor::SysWindow) {}
  void SetupWindow(void);

protected:
  // In response to the CM_COLOR menu command, invokes a VCL-based
  // dialog box where the user selects a color.
  //
  void CmColor();

private:
  // Stores the most recently selected window background color.
  // (Default = COLOR_WINDOW)
  //
  ClassLib::TColor Color;
  
DECLARE_RESPONSE_TABLE(TMyFrame);  
};

void
TMyFrame::SetupWindow()
{
  // Without this, the VCL TApplication window (which is created first,
  // before WinMain) becomes an invisible peer of the main application
  // window, with its own icon in the task bar.
  //
  AdoptVCLAppWindow(GetHandle());
}

//
// class TMyApp
// ~~~~~ ~~~~~~
// A very normal OWL application object.  Does nothing unusual.
// 
class TMyApp : public OWL::TApplication {
  public:
    TMyApp() : OWL::TApplication("VCL Dialog") {}

  private:
    void InitMainWindow();
};

//
//
//
void
TMyApp::InitMainWindow()
{
  MainWindow = new TMyFrame(0, Name);
  MainWindow->AssignMenu(IDM_APPMENU);
}

//
//
//
DEFINE_RESPONSE_TABLE1(TMyFrame, TWindow)
  EV_COMMAND(CM_COLOR, CmColor),
END_RESPONSE_TABLE;

//
// CmColor
// Let the user choose a color.  Invoke a dialog box to do this.
// (The dialog box is a C++Builder form.)
//
void
TMyFrame::CmColor()
{
  // Create the form object
  //
  TPointer<TForm1> dlg = new TForm1(::Application);

  // Set the color selection scroll bars to the current color setting
  //
  dlg->SetSelectedColor(Color);

  // Center the dialog within the frame window's client area
  //
  ClassLib::TRect rect;
  ClassLib::TPoint upperLeft;
  GetClientRect(rect);
  upperLeft.x = (rect.Width()  - dlg->Width)  / 2;
  upperLeft.y = (rect.Height() - dlg->Height) / 2;
  ClientToScreen(upperLeft);
  dlg->Left = upperLeft.x;
  dlg->Top  = upperLeft.y;

  // Invoke the form, running it as a modal dialog
  //
  TModalResult result = dlg->ShowModal();

  // If user closed with the OK button, change color setting
  //
  if (result == mrOk) {
    Color = dlg->GetSelectedColor();
    SetBkgndColor(Color);
    Invalidate();
  }
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyApp().Run();
}
