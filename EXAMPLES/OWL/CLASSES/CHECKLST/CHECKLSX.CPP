//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/checklst.h>
#include <stdio.h>

const int CheckListId = 100;
const int NumItems = 15;

char Buffer[4096];

//
// class CheckListXWindow
// ~~~~~ ~~~~~~~~~~~~~~~~
class TCheckListXWindow : public TWindow {
  public:
    TCheckListXWindow();
   ~TCheckListXWindow();

    void  SetupWindow();
    void  CleanupWindow();

    bool  CanClose();

  private:
    TCheckList* CheckList;
    TCheckListItem* Items;

  DECLARE_RESPONSE_TABLE(TCheckListXWindow);
};


//
// CheckListXWindow constructor
//
TCheckListXWindow::TCheckListXWindow()
:
  TWindow(0, 0, 0)
{
  Items = new TCheckListItem[NumItems];

  for (int i = 0; i < NumItems; i++) {
    char buffer[20];
    sprintf(buffer, "Item %d", i);
    Items[i].SetText(buffer);
  }
  Items[0].Toggle();
  Items[1].SetIndeterminate();
  Items[2].SetThreeStates(true);

  CheckList = new TCheckList(this, CheckListId, 10, 10, 400, 200, Items, NumItems);
}


//
// CheckListXWindow destructor
//
TCheckListXWindow::~TCheckListXWindow()
{
  delete[] Items;
}


//
// SetupWindow
//
void
TCheckListXWindow::SetupWindow()
{
  TWindow::SetupWindow();
  // put new stuff here
  //

}

//
//
//
bool
TCheckListXWindow::CanClose()
{
  ::Buffer[0] = 0;
  strcpy(::Buffer, "You've selected\r\n");
  for (int i = 0; i < NumItems; i++) {
    if (Items[i].IsChecked() || Items[i].IsIndeterminate()) {
      char temp[20];
      Items[i].GetText(temp, 20);
      strcat(::Buffer, temp);
      if (Items[i].IsIndeterminate())
        strcat(::Buffer, " (ind)");
      strcat(::Buffer, "\r\n");
    }
  }

  return MessageBox(::Buffer, "Okay to close?", MB_OKCANCEL) == IDOK;
}


//
// CleanupWindow
//
void
TCheckListXWindow::CleanupWindow()
{
  // put new stuff here
  //
  TWindow::CleanupWindow();
}


//
// Response table for CheckListXWindow
//
DEFINE_RESPONSE_TABLE1(TCheckListXWindow, TWindow)
END_RESPONSE_TABLE;


//
// class CheckListXApplication
// ~~~~~ ~~~~~~~~~~~~~~~~~~~~~
class TCheckListXApp : public TApplication {
  public:
    TCheckListXApp()
    {
    }
   ~TCheckListXApp()
    {
    }

    void InitMainWindow()
    {
      TFrameWindow* frame = new TFrameWindow(0, "CheckListX application",
        new TCheckListXWindow);
      SetMainWindow(frame);
    }
};


//
// OwlMain
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  TCheckListXApp app;
  return app.Run();
}









