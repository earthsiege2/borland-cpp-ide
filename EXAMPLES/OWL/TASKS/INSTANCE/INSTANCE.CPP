//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <winsys/system.h>
#include <string.h>

//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    TTestApp()
    :
      TApplication("Instance Tester")
    {
      WindowTitle = "Additional Instance";
    }

  protected:
    string WindowTitle;

    // With per-instance data (supported under NT), every instance looks
    // like the first since each has its own independent data segment & cannot
    // share segments, i.e. GetInstanceData() is not supported.
    //
    void InitApplication()
    {
      if (TSystem::SupportsInstanceData())
        WindowTitle = "An Instance";
      else
        WindowTitle = "First Instance";
    }

    void InitMainWindow()
    {
      MainWindow = new TFrameWindow(0, WindowTitle.c_str());
    }
};

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
