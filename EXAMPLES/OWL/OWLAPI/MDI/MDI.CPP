//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\mdi.h>
#include <owl\mdichild.h>
#include <stdio.h>

class TMyMDIClient : public TMDIClient {
  public:
    TMyMDIClient() : TMDIClient() {ChildNum = 0;}
  
    TMDIChild* InitChild();

  private:
    WORD ChildNum;
    
  DECLARE_RESPONSE_TABLE (TMyMDIClient);
};

DEFINE_RESPONSE_TABLE1(TMyMDIClient, TMDIClient)
END_RESPONSE_TABLE;

TMDIChild*
TMyMDIClient::InitChild()
{
  char childName[15];
  sprintf(childName, "MDI Child %d", ChildNum++);
  return new TMDIChild(*this, childName);
}

//----------------------------------------------------------------------------

class TMDIApp : public TApplication {
  public:
    TMDIApp() : TApplication("MDI Conformist") {}
    void InitMainWindow();
};

// Construct the TMDIApp's MainWindow object, loading its menu
//
void
TMDIApp::InitMainWindow()
{
  MainWindow = new TMDIFrame(GetName(), "MDIMenu", *new TMyMDIClient);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMDIApp().Run();
}
