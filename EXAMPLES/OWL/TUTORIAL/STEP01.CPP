//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Tutorial application -- step01.cpp
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>

class TMyApp : public TApplication {
  public:
    TMyApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Sample ObjectWindows Program"));
    }
};

int OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyApp().Run();
}
