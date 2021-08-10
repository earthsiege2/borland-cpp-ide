//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/picklist.h>
#include <stdio.h>
#include "picklist.rh"

//
// classTTestWindow
// ~~~~~~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow()
    :
      TWindow(0, 0, 0)
    {
    }

    void CmPickItem()
    {
      // Build up a string array of selections to choose from
      //
      TStringArray strings(10, 2, 10);
      strings.Add("Snow");
      strings.Add("Great horned");
      strings.Add("Grey");
      strings.Add("Bald");
      strings.Add("Barn");

      // Construct a pick list dialog using the string array built above, and
      // then add another string for the fun of it.
      //
      TPickListDialog picklist(this, &strings, 0, 0, "Owls");
      picklist.AddString("Hoot");

      // If the execute return result is non-negative, then a selection was
      // made
      //
      int result = picklist.Execute();
      if (result >= 0) {
        char msg[80];
        sprintf(msg, "Item #%d, string:%s", result,
                result < strings.UpperBound() ? strings[result].c_str()
                                              : "Beyond list...");
        MessageBox(msg, "You've selected", MB_OK);
      }
    }

    void CmPickPopItem()
    {
      TPickListPopup picklist(this, "Owls");
      picklist.AddString("Snow");
      picklist.AddString("Great horned");
      picklist.AddString("Grey");
      picklist.AddString("Bald");
      picklist.AddString("Barn");
      picklist.AddString("Hoot");

      int result = picklist.Execute();
      if (result >= 0) {
        char msg[80];
        sprintf(msg, "Item #%d", result);
        MessageBox(msg, "You've selected", MB_OK);
      }
    }

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_COMMAND(CM_PICKITEM, CmPickItem),
  EV_COMMAND(CM_PICKPOPITEM, CmPickPopItem),
END_RESPONSE_TABLE;

//
// class TTestApp
// ~~~~~ ~~~~~~~~
class TTestApp : public TApplication {
  public:
    void InitMainWindow();
};

void
TTestApp::InitMainWindow()
{
  TWindow* testWindow = new TTestWindow;
  TDecoratedFrame* frame = new TDecoratedFrame(0, "Test application", testWindow, true);
  frame->AssignMenu(IDM_MAINMENU);
  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TTestApp app;
  return app.Run();
}

