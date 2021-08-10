//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <dir.h>
#include "appbtnba.h"
#include "appwin.h"
#include "applaunc.rh"

#if defined(BI_PLAT_WIN32) && defined(_RTLDLL)
extern int __cdecl _setargv__;
#pragma extref  _setargv__
#endif

class TAppLauncher : public TApplication {
  public:
    TAppLauncher(char* startupPath);

  protected:
    string              StartupPath;    // path to exe.
    TAppButtonBar*      AppButtons;     // Button bar that contains buttons.

    void InitMainWindow();

};

//
// Constructor. Extract the path (without the exe name).
//
TAppLauncher::TAppLauncher(char* startupPath)
  : TApplication()
{
  char drive[MAXDRIVE];
  char dir[MAXDIR];
  fnsplit(startupPath, drive, dir, 0, 0);
  StartupPath = string(drive) + dir;
}

//
// InitMainWindow().  Create a default button bar (will be changed later).
// Create frame window with button bar as the client.
//
void TAppLauncher::InitMainWindow()
{
  AppButtons = new TAppButtonBar(0, 1);
  MainWindow = new TAppWindow("Apps", AppButtons, StartupPath);
  MainWindow->SetIcon(this, IDI_APPLAUNCHER);
}

//
//
//
int
OwlMain(int /*argc*/, char* argv[])
{
  return TAppLauncher(argv[0]).Run();
}
