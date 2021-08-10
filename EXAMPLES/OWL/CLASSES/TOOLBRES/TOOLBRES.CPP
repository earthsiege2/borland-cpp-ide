//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// Illustrates usage of Toolbar resource
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DECFRAME_H)
# include <owl/decframe.h>
#endif
#if !defined(OWL_STATUSBA_H)
# include <owl/statusba.h>
#endif
#if !defined(OWL_CONTROLB_H)
# include <owl/controlb.h>
#endif
#if !defined(OWL_RESOURCE_H)
# include <owl/resource.h>
#endif
#if !defined(OWL_EDITFILE_H)
# include <owl/editfile.h>
#endif
#include <stdio.h>

//
// class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication {
  public:
    TSampleApp(){}

    // Override virtuals from TApplication
    //
    void    InitMainWindow();
};

void
TSampleApp::InitMainWindow()
{
  // Setup main window + client
  //
  SetMainWindow(new TDecoratedFrame(0, 0, new TEditFile()));

  // Create decoration objects
  //
  TStatusBar*  sbar = new TStatusBar(GetMainWindow());
  TControlBar* cbar = new TControlBar(GetMainWindow());

  // Build toolbar from resource
  //
  TToolbarBldr(*cbar, 1000).Build();

#if 0

  // Load toolbar resource
  // NOTE: Don't let TToolbarRes own bitmap, we'll give it to TCelArray 
  //       instead.
  //
  TToolbarRes tbRes(*this, 1000, NoAutoDelete);
  if (tbRes.IsOK()) {
    TCelArray* celArray = new TCelArray(&tbRes.GetBitmap(), tbRes.GetCount(),
                                        TSize(tbRes.GetWidth(),
                                              tbRes.GetHeight()));
    cbar->SetCelArray(celArray);

    //
    //
    for (int i=0, j=0; i<tbRes.GetCount(); i++) {
      if (tbRes.GetIds()[i] == 0)
        cbar->Insert(*new TSeparatorGadget(6));
      else {
        cbar->Insert(*new TButtonGadget(j, tbRes.GetIds()[i], 
                                        TButtonGadget::Command, 
                                        false, TButtonGadget::Up, true));
        j++;
      }
    }
  }

/////////////////////////// OLD METHOD ////////////////////////////////

  // Insert gadgets in control bar
  //
  cbar->Insert(*new TButtonGadget(CM_FILENEW, CM_FILENEW));
  cbar->Insert(*new TButtonGadget(CM_FILEOPEN, CM_FILEOPEN));
  cbar->Insert(*new TButtonGadget(CM_FILESAVE, CM_FILESAVE));
  cbar->Insert(*new TButtonGadget(CM_FILEPRINT, CM_FILEPRINT));

  cbar->Insert(*new TSeparatorGadget(6));
  cbar->Insert(*new TButtonGadget(CM_EDITUNDO, CM_EDITUNDO));
  cbar->Insert(*new TButtonGadget(CM_EDITCUT, CM_EDITCUT));
  cbar->Insert(*new TButtonGadget(CM_EDITCOPY, CM_EDITCOPY));
  cbar->Insert(*new TButtonGadget(CM_EDITPASTE, CM_EDITPASTE));

#endif

  // Insert decorations in main window
  //
  TYPESAFE_DOWNCAST(GetMainWindow(), TDecoratedFrame)->Insert(
                    *cbar, TDecoratedFrame::Top);
  TYPESAFE_DOWNCAST(GetMainWindow(), TDecoratedFrame)->Insert(
                    *sbar, TDecoratedFrame::Bottom);

  GetMainWindow()->AssignMenu(100);
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSampleApp().Run();
}
