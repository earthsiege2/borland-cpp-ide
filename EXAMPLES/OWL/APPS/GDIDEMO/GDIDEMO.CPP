//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
//   A GDI demo program
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/mdi.h>
#include <string.h>
#include "demobase.h"
#include "line.h"
#include "fontx.h"
#include "bitblt.h"
#include "arty.h"

//
// Menu bar constants
//
const int MenuId            =  100;  // Resource Id of the menubar
const int MoveToLineToDemoId=  201;  // Demo->MoveToDemo Id
const int FontDemoId        =  202;  // Demo->Font Demo Id
const int BitBltDemoId      =  203;  // Demo->BitBlt Demo Id
const int ArtyDemoId        =  204;  // Demo->Arty Demo Id

const int IconId            =  100;  // Resource Id of the program icon

IMPLEMENT_CASTABLE1(TBaseDemoWindow, TWindow);

//----------------------------------------------------------------------------

//
//
//
class TGdiDemoWindow : public TMDIClient {
  public:
    TGdiDemoWindow() : TMDIClient() { Attr.Style |= WS_TABSTOP; }

  protected:
    void SetupWindow();
    void CleanupWindow();

    void CmMoveToLineToDemo();
    void CmFontDemo();
    void CmBitBltDemo();
    void CmArtyDemo();

    void EvTimer(uint TimerId);

  DECLARE_RESPONSE_TABLE(TGdiDemoWindow);
};

DEFINE_RESPONSE_TABLE1(TGdiDemoWindow, TMDIClient)
  EV_COMMAND(MoveToLineToDemoId, CmMoveToLineToDemo),
  EV_COMMAND(FontDemoId, CmFontDemo),
  EV_COMMAND(BitBltDemoId, CmBitBltDemo),
  EV_COMMAND(ArtyDemoId, CmArtyDemo),
  EV_WM_TIMER,
END_RESPONSE_TABLE;


//
// Setup the main demo window, and try to allocate its timer
//
void
TGdiDemoWindow::SetupWindow()
{
  TMDIClient::SetupWindow();

  int result = IDRETRY;
  while (SetTimer(0, 50, 0) == 0 && result == IDRETRY)
    result = MessageBox("Could not Create Timer", "GDIDemo", MB_RETRYCANCEL);
  if (result == IDCANCEL)
    PostQuitMessage(0);
}

//
//
//
void
TGdiDemoWindow::CleanupWindow()
{
  KillTimer(0);
  TMDIClient::CleanupWindow();
}

//
// In response to a demo command, create one of the demo windows as the client
// of an mdi child frame. Turn of the icon for the mdi child to allow the
// client to paint itself when iconic.
//

void
TGdiDemoWindow::CmMoveToLineToDemo()
{
  TMDIChild* child = new TMDIChild(*this, "MoveTo/LineTo Window", 
                                   new TMoveToLineToWindow);
  child->SetIcon(0, 0);
  child->Create();
}

void
TGdiDemoWindow::CmFontDemo()
{
  TMDIChild* child = new TMDIChild(*this, "Font Window", new TFontWindow);
  child->SetIcon(GetApplication(), 101);
  child->Create();
}

void
TGdiDemoWindow::CmBitBltDemo()
{
  TMDIChild* child = new TMDIChild(*this, "BitBlt Window", new TBitBltWindow);
  child->SetIcon(0, 0);
  child->Create();
}

void
TGdiDemoWindow::CmArtyDemo()
{
  TMDIChild* child = new TMDIChild(*this, "Arty Window", new TArtyWindow);
  child->SetIcon(0, 0);
  child->Create();
}

//
// Get client demo window from mdi child frame using typesafe downcasting
//
void
ChildTimers(TWindow* p, void*)
{
  TFrameWindow* frame = TYPESAFE_DOWNCAST(p, TFrameWindow);
  CHECK(frame);
  TBaseDemoWindow* demoWin = TYPESAFE_DOWNCAST(frame->GetClientWindow(), TBaseDemoWindow);
  CHECK(demoWin);
  demoWin->TimerTick();
}

//
// In response to WMTimer messages, each MDI child window's TimerTick
// Method is called.
//
void
TGdiDemoWindow::EvTimer(uint)
{
  ForEach(ChildTimers, 0);
}

//----------------------------------------------------------------------------

//
//
//
class TGdiDemoApp : public TApplication {
  public:
    TGdiDemoApp() : TApplication() {}
    void InitMainWindow();
};

//
//
//
void
TGdiDemoApp::InitMainWindow()
{
  TFrameWindow* fw =  new TMDIFrame("GDI Demo", MenuId, *new TGdiDemoWindow);
  fw->SetIcon(this, IconId);
  SetMainWindow(fw);
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TGdiDemoApp().Run();
}
