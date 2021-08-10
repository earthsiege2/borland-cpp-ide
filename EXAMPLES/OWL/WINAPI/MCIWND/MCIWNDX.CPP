//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Illustrates usage of TMciWnd class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include "mciwnd.h"
#include "mciwndx.h"

//
//
//
const int ID_MCIWND = 0x100;

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    void    InitMainWindow();
};

//
//
//
void
TSampleApp::InitMainWindow()
{
  SetMainWindow(new TFrameWindow(0, 0, 
                                 new TMciWnd(0, ID_MCIWND, 0, 0, 0, 0, 0),
                                 true));
  GetMainWindow()->AssignMenu(IDM_APP);
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
