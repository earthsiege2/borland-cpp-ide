//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   A Multi-thread GDI demo program
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\mdi.h>
#include <string.h>
#include "demobase.h"
#include "line.h"
#include "arty.h"

// Menu bar constants
const int MenuId            =  100;  // Resource Id of the menubar
const int MoveToLineToDemoId=  201;  // Demo->MoveToDemo Id
const int ArtyDemoId        =  202;  // Demo->Arty Demo Id

const int IconId            =  100;  // Resource Id of the program icon

//----------------------------------------------------------------------------

int
TOWLThread::Synch()
{
  HANDLE Signals[2] = { HANDLE(*GetApplication()->GetMutex()), Done };
  return ::WaitForMultipleObjects( 2, Signals, FALSE, -1 );
}

HANDLE
TBaseDemoWindow::Start()
{
  HANDLE Result = TThread::Start();
  SetPriority( THREAD_PRIORITY_LOWEST );
  return Result;
}

unsigned long
TBaseDemoWindow::Run()
{
  for(;;)
    {
    ::Sleep(20);
    if( Synch() != 0 )
        return 0;
    else 
      {
      // This is a little tricky. On return from
      // Synch() this thread owns a lock on the
      // OWL synchronization object. In order to
      // be exception-safe we must have an object
      // whose destructor will release the lock.
      // So we create one, which gives us two nested
      // locks on the synchroniztion object. Then
      // we release one of the locks. The destructor
      // for the TAppLock object releases the other
      // one at the end of this block.

      TApplication::TAppLock l(*GetApplication());
      l.Release();

      // Call into the derived class for the actual processing
      DoRun();
      }
    }
}

TApplication *
TBaseDemoWindow::GetApplication() const
{
  return TWindow::GetApplication();
}

BOOL
TBaseDemoWindow::CanClose()
{
  if( TerminateAndWait( 1000 ) == 0 )
      return TRUE;
  else
      {
      MessageBox( "Timeout while terminating thread", "gdidemo.exe" );
      return FALSE;
      }
}

IMPLEMENT_CASTABLE1(TBaseDemoWindow, TWindow);

//----------------------------------------------------------------------------

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

class TGdiDemoApp : public TApplication {
  public:
    TGdiDemoApp() : TApplication() {}
    void InitMainWindow();
};

void
TGdiDemoApp::InitMainWindow()
{
  MainWindow = new TMDIFrame("Multi-Thread Demo", MenuId, *new TGdiDemoWindow);
  MainWindow->SetIcon(this, IconId);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
#if defined(__WIN32__)
  if ((HIWORD(GetVersion())&0x8000)) {
		::MessageBox(0, "This is a Win NT Example", "OWL Examples", MB_OK);
 		return 0;
  }
#endif
  return TGdiDemoApp().Run();
}

