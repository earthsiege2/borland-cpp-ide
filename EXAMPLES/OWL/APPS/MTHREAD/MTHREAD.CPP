//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// A Multi-thread GDI demo program
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/mdi.h>
#include <string.h>
#include "demobase.h"
#include "line.h"
#include "arty.h"

//
// Menu bar constants
//
const int MenuId             = 100;  // Resource Id of the menubar
const int MoveToLineToDemoId = 201;  // Demo->MoveToDemo Id
const int ArtyDemoId         = 202;  // Demo->Arty Demo Id

const int IconId             = 100;  // Resource Id of the program icon

const int SpeedDelay         = 20;   // Minimum delay between thread iterations

//----------------------------------------------------------------------------

//
//
//
TBaseDemoWindow::TBaseDemoWindow()
:
  TWindow(0, 0, 0),
  Sync(0, 2)        // We'll add 2 objects to this semaphore
{
  Sync.Add(*GetApplication()->GetMutex());  // (Assumes the mutex is present)
  Sync.Add(Done);
}

//
// Start this thread and adjust priority down. The demo windows run at a lower
// priority than the main thread.
//
TThread::THandle
TBaseDemoWindow::Start()
{
  TThread::THandle result = TThread::Start();
  SetPriority(Lowest);
  return result;
}

//
//
//
int
TBaseDemoWindow::Run()
{
  for (;;) {
    Sleep(SpeedDelay);

    // Attempt to lock one of our two semaphores: AppMutex, or Done
    //
    TSemaphoreSet::TLock l(Sync, TSemaphoreSet::WaitAny);

    if (!l.WasAquired())        // We timed out or erred somehow
      return -1;

    if (l.WhichAquired() == 1)  // The Done event was signaled, time to exit
      return 0;
            
    // We've got the AppMutex, call into the derived class for the actual
    // processing
    //
    ClockTick();
  }
}

//
//
//
TApplication*
TBaseDemoWindow::GetApplication() const
{
  return TWindow::GetApplication();
}

//
//
//
bool
TBaseDemoWindow::CanClose()
{
  if (TerminateAndWait(1000) == 0) {
    return true;
  }
  else {
    MessageBox("Timeout while terminating thread", "MTHREAD");
    return false;
  }
}

IMPLEMENT_CASTABLE1(TBaseDemoWindow, TWindow);

//----------------------------------------------------------------------------

//
//
//
class TGdiDemoWindow : public TMDIClient {
  public:
    TGdiDemoWindow() : TMDIClient() { Attr.Style |= WS_TABSTOP; }

  protected:
    void CmMoveToLineToDemo();
    void CmArtyDemo();

  DECLARE_RESPONSE_TABLE(TGdiDemoWindow);
};

DEFINE_RESPONSE_TABLE1(TGdiDemoWindow, TMDIClient)
  EV_COMMAND(MoveToLineToDemoId, CmMoveToLineToDemo),
  EV_COMMAND(ArtyDemoId, CmArtyDemo),
END_RESPONSE_TABLE;


//
// In response to a demo command, create one of the demo windows as the client
// of an mdi child frame. Turn of the icon for the mdi child to allow the
// client to paint itself when iconic.
//

void
TGdiDemoWindow::CmMoveToLineToDemo()
{
  TMDIChild* child = new TMDIChild(*this, "MoveTo/LineTo Window",
                                   new TMoveToLineToWindow);
  child->SetIcon(0, 0);
  child->Create();
}

void
TGdiDemoWindow::CmArtyDemo()
{
  TMDIChild* child = new TMDIChild(*this, "Arty Window", new TArtyWindow);
  child->SetIcon(0, 0);
  child->Create();
}

//----------------------------------------------------------------------------

//
//
//
class TGdiDemoApp : public TApplication {
  public:
    TGdiDemoApp() : TApplication() {}
    void InitMainWindow();
};

//
//
//
void
TGdiDemoApp::InitMainWindow()
{
  TFrameWindow* fw = new TMDIFrame("Multi-Thread Demo", MenuId, *new TGdiDemoWindow);
  fw->SetIcon(this, IconId);
  SetMainWindow(fw);

  // This is very important when using threads with a TApplication, and is
  // new to OWL 5.0. Without this the app runs faster since it doesn't have
  // to lock a mutex during message dispatching.
  //
  EnableMultiThreading(true);
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  // If under Win32, then make sure it is a version that has threads. If Win16
  // then shouldn't build at all
  //
  if (!TSystem::SupportsThreads()) {
    ::MessageBox(0, "This Example requires a multithreaded version of Windows",
                 "OWL Examples", MB_OK);
    return 0;
  }
  return TGdiDemoApp().Run();
}
