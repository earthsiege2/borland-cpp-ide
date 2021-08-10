//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1994 by Borland International
//   Tutorial application -- delphictl.cpp
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include "dlwrap.h"
#include "testdll.h"


class TDelphiCtlApp : public TApplication {
  public:
    TDelphiCtlApp() : TApplication() {}

    void InitMainWindow()
    {
      SetMainWindow(new TFrameWindow(0, "Sample OWL Window containing a Delphi control",
	  new TDelphiFormWrapper(MakeTestForm, 0, 0, 0))
      );
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDelphiCtlApp().Run();
}
