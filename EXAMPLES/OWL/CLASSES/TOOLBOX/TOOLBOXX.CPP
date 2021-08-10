//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/floatfra.h>
#include <owl/toolbox.h>
#include <owl/buttonga.h>
#include <owl/bitmapga.h>
#include "toolbox.rh"

//
// class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {
  public:
    TClientWindow();

  protected:
    void    ButtonHandler(uint id);
    bool    EvSetCursor(HWND hWndCursor, uint hitTest, uint mouseMsg);

    void    Paint(TDC& dc, bool repaint, TRect& rect);
    TPointer<TCursor> Cursor;

  DECLARE_RESPONSE_TABLE(TClientWindow);
};


//
// class TToolBoxApp
// ~~~~~ ~~~~~~~~~~~
class TToolBoxApp : public TApplication {
  public:
    void InitMainWindow();
};


//
// Response table for ToolBoxWindow
//
DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_WM_SETCURSOR,
  EV_COMMAND_AND_ID(CM_CMD1,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD2,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD3,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD4,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD5,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD6,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD7,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD8,   ButtonHandler),
  EV_COMMAND_AND_ID(CM_CMD9,   ButtonHandler),
END_RESPONSE_TABLE;

TClientWindow::TClientWindow() : TWindow(0, "Toolbox Sample")
{}

//
//
//
void
TClientWindow::ButtonHandler(uint id)
{
  if (id >= CM_CMD1 && id <= CM_CMD9)
    Cursor = new TCursor(*GetModule(), TResId(id));
}

//
//
//
void  
TClientWindow::Paint(TDC& dc, bool /*repaint*/, TRect& /*rect*/)
{
  TRect rect;
  GetClientRect(rect);

  const char msg[]="This window's cursor matches the button "
                   "gadget selected on it's toolbox";
  dc.DrawText(msg, sizeof(msg)-1, rect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}

//
//
//
bool    
TClientWindow::EvSetCursor(HWND /*hWndCursor*/, uint /*hitTest*/, 
                           uint /*mouseMsg*/)
{
  TCursor* cursor = Cursor;
  if (cursor && cursor->GetHandle()) {
    ::SetCursor(*cursor);
    return true;
  }
  return false;
}

//
// InitMainWindow
//
void
TToolBoxApp::InitMainWindow()
{
  // Main window: frame + client
  //
  TClientWindow* client = new TClientWindow;
  TFrameWindow* frame = new TFrameWindow(0, "ToolBox application", client);

  // Palette: Floating frame + toolbox
  //
  TToolBox* tb = new TToolBox(0, 3);
  for (int i=CM_CMD1; i<=CM_CMD9; i++)
   tb->Insert(*new TButtonGadget(i, i, TButtonGadget::Exclusive));

  TFloatingFrame* ff = new TFloatingFrame(frame, "Sample toolbox", tb, true,
                                 TFloatingFrame::DefaultCaptionHeight, true);
  ff->Attr.ExStyle |= WS_EX_PALETTEWINDOW;

  SetMainWindow(frame);
}


//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TToolBoxApp app;
  return app.Run();
}

