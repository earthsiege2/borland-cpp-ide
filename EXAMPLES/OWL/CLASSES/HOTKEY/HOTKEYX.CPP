//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Illustrates usage of THotKey class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/hotkey.h>
#include <owl/inputdia.h>
#include "hotkey.h"

#if !defined(WM_SETHOTKEY)        
# define WM_SETHOTKEY  0x0032
#endif

//
// Class TClientWindow
// ~~~~~ ~~~~~~~~~~~~~
class TClientWindow : public TWindow {

    // Simple structure used when performing transfers between
    // the configure dialog and the client window.
    //
    struct {
      uint16 hotkey;
    } xferData;

  public:
    TClientWindow(TWindow* parent= 0);

  protected:

    // Message Handlers
    //
    void        ConfigureHotKey();

  DECLARE_RESPONSE_TABLE(TClientWindow);
};

DEFINE_RESPONSE_TABLE1(TClientWindow, TWindow)
  EV_COMMAND(IDM_HOTKEY, ConfigureHotKey),
END_RESPONSE_TABLE;


TClientWindow::TClientWindow(TWindow* parent)
:
  TWindow(parent)
{
  xferData.hotkey = 0;
  Attr.Style |= (WS_CLIPSIBLINGS|WS_CLIPCHILDREN);
}

void
TClientWindow::ConfigureHotKey()
{
  TDialog dlg(this, IDD_HOTKEYDLG);
  new THotKey(&dlg, IDC_HOTKEY);
  dlg.SetTransferBuffer(&xferData);

  // If successful set a HOTKEY for the application's main window
  // NOTE: HOTKEYs cannot be set for windows with the WS_CHILD still.
  //       Hence, the client window is not a valid target for HOTKEYs.
  //
  if (dlg.Execute() == IDOK && xferData.hotkey) {
    LRESULT rslt = GetApplication()->GetMainWindow()->SendMessage(WM_SETHOTKEY,
                                                                  xferData.hotkey);
    // Inform user of the status of the attempt to set a HOTKEY
    //
    switch(rslt) {
      case 2: MessageBox("Hot key previously assigned", "INFO");
              break;

      case 1: MessageBox("Hot key successfully assigned\n"
                         "Pressing the hotkey will now activate\n"
                         "this application's main window", "INFO");
              break;

      case 0: MessageBox("Invalid window for hot key", "INFO");
              break;

      case -1: MessageBox("Invalid hot key", "INFO");
               break;

      default: MessageBox("Unknown error setting hot key", "INFO");
               break;
    }
  }
}

//----------------------------------------------------------------------------

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void InitMainWindow();
};

void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, 0, new TClientWindow()));
  GetMainWindow()->AssignMenu(ID_APPMENU);
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
#if defined(BI_PLAT_WIN16)
  if (!TSystem::IsWin95()) {
    ::MessageBox(0, "16-bit hotkey example designed to run on only Windows 95",
                 "Error", MB_ICONSTOP | MB_OK);
    return -1;
  }
#endif
  return TSampleApp().Run();
}
