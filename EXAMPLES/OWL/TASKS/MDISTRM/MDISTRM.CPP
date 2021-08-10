//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
// This example shows a persistent desktop using the MDI metaphor.  It is
// identical to the owlapi\mdi example, but with streaming code added to
// implement persistence for the frame, parent (client) window, and children.
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/mdi.h>
#include <owl/mdichild.h>
#include <stdio.h>
#include "mdistrm.h"

const char DskFile[] = "MDISTRM.SAV";
const char AppName[] = "MDI Object Streaming Example";

//----------------------------------------------------------------------------

//
// Here's our client, it's fully streamable.
//
class TMyMDIClient : public TMDIClient {
  public:
    TMyMDIClient() : TMDIClient() {ChildNum = 0;}
  
    TMDIChild*  InitChild();
    bool        CanClose();     //virtual from TWindow

  private:
    uint16      ChildNum;
    
  DECLARE_STREAMABLE(, TMyMDIClient, 1);
};

IMPLEMENT_CASTABLE1(TMyMDIClient, TMDIClient);
IMPLEMENT_STREAMABLE1(TMyMDIClient, TMDIClient);

//
// Our application object is also fully streamable and
// we use it to stream out its client (which contains the
// MDI child windows) to achieve a persistent desktop.
//
class TMDIApp : public TApplication {
  public:
    TMDIApp() : TApplication(AppName) {}
    void InitMainWindow();
    void InitInstance();
    void CmSaveState();
    void CmRestoreState();

  private:
    TMyMDIClient* Client;

  DECLARE_RESPONSE_TABLE(TMDIApp);
  DECLARE_STREAMABLE(, TMDIApp, 1);
};

DEFINE_RESPONSE_TABLE1(TMDIApp, TApplication)
  EV_COMMAND(CM_SAVESTATE, CmSaveState),
  EV_COMMAND(CM_RESTORESTATE, CmRestoreState),
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE1(TMDIApp, TApplication);
IMPLEMENT_STREAMABLE1(TMDIApp, TApplication);


//----------------------------------------------------------------------------

//
//
//
TMDIChild*
TMyMDIClient::InitChild()
{
  char childName[15];

  // Create a unique (numbered) caption for our MDI child
  //
  sprintf(childName, "MDI Child %d", ChildNum++);

  // and then create that child.
  //
  return new TMDIChild(*this, childName);
}

//
//
//
bool
TMyMDIClient::CanClose()
{
  // Save our persistent desktop, before closing down the client.
  // We have to (safely and dynamically) cast to our application
  // object type so that we can call our save state routine.
  //
  TMDIApp *app = TYPESAFE_DOWNCAST(GetApplication(),TMDIApp);
  if (app)
    app->CmSaveState();

  return TMDIClient::CanClose();
}

//
// Writes the TMyMDIClient instance to the passed opstream.
//
void
TMyMDIClient::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TMDIClient*)GetObject(), os);
  
  // Write out the member data for our MDI Client.
  os << GetObject()->ChildNum;
}

//
// Reads an instance of TMyMDIClient from the passed ipstream.
//
void *
TMyMDIClient::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TMDIClient*)GetObject(), is);

  // Read in the member data for our MDI Client.
  is >> GetObject()->ChildNum;

  return GetObject();
}


//----------------------------------------------------------------------------

//
// Construct the TMDIApp's MainWindow (frame) object and save
// a pointer to its client window in the Client data member.
// Restore the desktop if we've got one already streamed.
//
void
TMDIApp::InitMainWindow()
{
  // Create MDI frame window, load its menu, and create its client.
  //
  MainWindow = new TMDIFrame(GetName(), "MDIMenu", *(Client=new TMyMDIClient));
}

//
//
//
void
TMDIApp::InitInstance()
{
  TApplication::InitInstance();

  // Restore our persistent desktop, if there's a stream that already exists.
  //
  ifpstream is(DskFile);
  if (!is.bad())
  {
    is.close();
    CmRestoreState();
  }
}

//
// Save the the position and contents of the windows to the "desktop" file.
//
void
TMDIApp::CmSaveState()
{
  ofpstream os(DskFile);

  // Stream out 'this' object (our MDI application and children).
  //
  os << *this;

  os.close();

  if (os.bad()) {
    unlink(DskFile);
    MainWindow->MessageBox("Unable to write desktop file.", "Disk error",
                           MB_OK | MB_ICONEXCLAMATION);
  }
}

//
// Read windows' positions and contents from the "desktop" file.
//
void
TMDIApp::CmRestoreState()
{
  char* errorMsg = 0;

  ifpstream is(DskFile);
  if (is.bad())
    errorMsg = "Unable to open desktop file.";

  else {
    // Close any MDI children we may have.
    //
    Client->CloseChildren();
    try {
      // Stream into 'this' object our (new) MDI application and children.
      //
      is >> *this;
      if (is.bad())
        errorMsg = "Error reading desktop file.";
    }
    catch (xalloc) {
      if (Client->HWindow)
        Client->CloseChildren();
      errorMsg = "Not enough memory to open file.";
    }
    is.close();
  }
  if (errorMsg)
    MainWindow->MessageBox(errorMsg, "Error", MB_OK | MB_ICONEXCLAMATION);
}

//
//
//
void 
TMDIApp::Streamer::Write(opstream& os) const
{
  // Stream out our app's mainwindow size/coordinates and our client
  // window (the client will stream any child windows it may contain).
  //
  WriteBaseObject((TApplication*)GetObject(), os);
  os << GetObject()->MainWindow->Attr.X;
  os << GetObject()->MainWindow->Attr.Y;
  os << GetObject()->MainWindow->Attr.W;
  os << GetObject()->MainWindow->Attr.H;

  os << *( GetObject()->Client );
  os << GetObject()->Client->GetActiveMDIChild();
}

//
//
//
void*
TMDIApp::Streamer::Read(ipstream& is, uint32 /*version*/ ) const
{
  // Stream in our app's mainwindow frame coordinates, updating its frame
  // size, and stream in its client window.
  //
  ReadBaseObject((TApplication*)GetObject(), is);
  is >> GetObject()->MainWindow->Attr.X;
  is >> GetObject()->MainWindow->Attr.Y;
  is >> GetObject()->MainWindow->Attr.W;
  is >> GetObject()->MainWindow->Attr.H;

  is >> *( GetObject()->Client );
  TMDIChild* active;
  is >> active;

  // If our mainwindow already exists (i.e., we're restoring from the menu)
  // then make sure it's redrawn correctly, with the 'new' extent attributes
  // (what they were when they were last streamed to file).
  //
  if (GetObject()->MainWindow->HWindow)
    GetObject()->MainWindow->MoveWindow(GetObject()->MainWindow->Attr.X,
                                        GetObject()->MainWindow->Attr.Y,
                                        GetObject()->MainWindow->Attr.W,
                                        GetObject()->MainWindow->Attr.H,
                                        true);

  // Finally, create the interface objects for our children,
  // restoring the active window.
  //
  GetObject()->Client->CreateChildren();
  if (active)
    GetObject()->Client->HandleMessage(WM_MDIACTIVATE,(uint)active->GetHandle());
  return GetObject();
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMDIApp().Run();
}
