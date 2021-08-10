//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/editfile.h>
#include <services/cstring.h>

class TFileApp : public TApplication {
  public:
    TFileApp() : TApplication("File Window") {}

  protected:
    void   InitMainWindow();
    void   CmFileNew();
    void   CmFileOpen();

  DECLARE_RESPONSE_TABLE(TFileApp);
};

DEFINE_RESPONSE_TABLE1(TFileApp, TApplication)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
END_RESPONSE_TABLE;

//
// Construct the TFileApp's MainWindow's client of type TEditFile
//
void
TFileApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, Name, new TEditFile);
  MainWindow->AssignMenu(IDM_EDITFILE);
  MainWindow->Attr.AccelTable = IDA_EDITFILE;
  MainWindow->SetIcon(this, 201);
}

void
TFileApp::CmFileNew()
{
  TEditFile* ef = TYPESAFE_DOWNCAST(MainWindow->GetClientWindow(), TEditFile);
  CHECK(ef);
  ef->NewFile();
}

void
TFileApp::CmFileOpen()
{
  TEditFile* ef = TYPESAFE_DOWNCAST(MainWindow->GetClientWindow(), TEditFile);
  CHECK(ef);
  ef->Open();
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TFileApp().Run();
}
