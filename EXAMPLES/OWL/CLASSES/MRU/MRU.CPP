//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/rcntfile.h>
#include <owl/opensave.h>
#include <classlib/pointer.h>
#include <owl/docview.rh>

//
// Class TSampleApp
// ~~~~~ ~~~~~~~~~~
class TSampleApp : public TApplication, public TRecentFiles {
  public:
    TSampleApp() : TApplication(), TRecentFiles(".\\Test.ini", 4) {}

  protected:
    void InitMainWindow();

    void CmOpen();
    TResult EvFileSelected(TParam1 p1, TParam2)
    {
      char text[80];
      GetMenuText(p1, text, sizeof text);
      GetMainWindow()->MessageBox(text, "You've selected", MB_OK);
      return 0;
    }

  DECLARE_RESPONSE_TABLE(TSampleApp);
};

DEFINE_RESPONSE_TABLE2(TSampleApp, TRecentFiles, TApplication)
  EV_REGISTERED(MruFileMessage, EvFileSelected),
  EV_COMMAND(CM_FILEOPEN, CmOpen),
END_RESPONSE_TABLE;

void
TSampleApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, 0, new TWindow(0,0,0));
  frame->AssignMenu("IDM_TEST");
  SetMainWindow(frame);
}

void
TSampleApp::CmOpen()
{
  TOpenSaveDialog::TData data(OFN_NOVALIDATE|OFN_NOCHANGEDIR, "All Files (*.*)|*.*|");
  TFileOpenDialog dialog(GetMainWindow(), data);
  if (dialog.Execute() == IDOK) {
    SaveMenuChoice(data.FileName);
  }
}

int
OwlMain(int /*argc*/, char* /*argv*/[])
{
  return TSampleApp().Run();
}
