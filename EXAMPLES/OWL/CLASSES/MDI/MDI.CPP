//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/mdi.h>
#include <owl/mdichild.h>
#include <stdio.h>

#define IDM_MDIMENU 100

//
// class TMyMDIClient
// ~~~~~ ~~~~~~~~~~~~
class TMyMDIClient : public TMDIClient {
  public:
    TMyMDIClient()
    :
      TMDIClient()
    {
      ChildNum = 0;
    }

    void CmCreateChild();

  private:
    int ChildNum;

  DECLARE_RESPONSE_TABLE(TMyMDIClient);
};

DEFINE_RESPONSE_TABLE1(TMyMDIClient, TMDIClient)
  EV_COMMAND(CM_CREATECHILD, CmCreateChild),
END_RESPONSE_TABLE;

void
TMyMDIClient::CmCreateChild()
{
  char childName[15];
  sprintf(childName, "MDI Child %d", ChildNum++);
  TMDIChild* child = new TMDIChild(*this, childName);
  child->Create();
}

//
// class TMDIApp
// ~~~~~ ~~~~~~~
class TMDIApp : public TApplication {
  public:
    TMDIApp()
    :
      TApplication("MDI Conformist")
    {
    }

    void InitMainWindow();
};

// Construct the TMDIApp's MainWindow object, loading its menu
//
void
TMDIApp::InitMainWindow()
{
  SetMainWindow(new TMDIFrame(GetName(), IDM_MDIMENU, *new TMyMDIClient));
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMDIApp().Run();
}
