// ---------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1991, 1995 by Borland International, All Rights Reserved
// ---------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <cstring.h>
#include "dllhello.h"
#include "calldll.h"

static TModule ResourceDll("resource.dll");   // DLL to be loaded.

//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow()
    :
      TWindow(0, 0, ::Module) // associate with this module
    {
    }

    void SetupWindow();
    void CleanupWindow();

    void CmCreate();          // Call into a DLL to create a window.
    void CmRString();         // Load a String resource from a DLL.
    void CmRCursor();         // Load a Cursor resource from a DLL.
    void CmRIcon();           // Load a Icon resource from a DLL.
    void CmRBitmap();         // Load a Bitmap resource from a DLL.

    void Paint(TDC& dc, bool erase, TRect& rect);

  private:
    HICON   SampleIcon;       // Handle to Icon.
    HBITMAP SampleBitmap;     // Handle to Bitmap.

  DECLARE_RESPONSE_TABLE(TTestWindow);
};


DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_COMMAND(CM_CREATE, CmCreate),
  EV_COMMAND(CM_RSTRING, CmRString),
  EV_COMMAND(CM_RCURSOR, CmRCursor),
  EV_COMMAND(CM_RICON, CmRIcon),
  EV_COMMAND(CM_RBITMAP, CmRBitmap),
END_RESPONSE_TABLE;


void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();
  SampleIcon = 0;
  SampleBitmap = 0;
}


void
TTestWindow::CleanupWindow()
{
  if (SampleIcon)
    ::DestroyIcon(SampleIcon);      // Cleanup resources.
  if (SampleBitmap)
    ::DeleteObject(SampleBitmap);
  TWindow::CleanupWindow();
}


//
// Call into DLL to create window.
//
void
TTestWindow::CmCreate()
{
  CreateDLLWindow(HWindow);
}


//
// Load a String from resource DLL. Display it in a message box.
//
void
TTestWindow::CmRString()
{
  const int resLen = 30;

  char far* str = new char[resLen];

  ResourceDll.LoadString(ID_STRING, str, resLen);
  MessageBox(str, "The String Is!", MB_OK);
  delete[] str;
}


//
// Load and set Cursor for window.
//
void
TTestWindow::CmRCursor()
{
  SetCursor(&ResourceDll, ID_CURSOR);
}


//
// Load and display cursor on window.
//
void
TTestWindow::CmRIcon()
{
  char    temp[5];
  string  resIdAsString;

  itoa(ID_ICON, temp, 10);
  resIdAsString = "#";
  resIdAsString += temp;
  SampleIcon = ResourceDll.LoadIcon(resIdAsString.c_str());
  CHECK(SampleIcon);
  Invalidate();
}


//
// Load and display Bitmap on window.
//
void
TTestWindow::CmRBitmap()
{
  SampleBitmap = ResourceDll.LoadBitmap(ID_BITMAP);
  CHECK(SampleBitmap);
  Invalidate();
}


//
// Will display Icon and Bitmap resource if they have been loaded.
//
void
TTestWindow::Paint(TDC& dc, bool, TRect&)
{
  if (SampleIcon)
    dc.DrawIcon(5, 5, TIcon(SampleIcon));
  if (SampleBitmap) {
    TMemoryDC memDC;
    memDC.SelectObject(TBitmap(SampleBitmap));
    dc.BitBlt(50, 5, 64, 64, memDC, 0, 0 );
  }
}


//
// class TCallDllApp
// ~~~~~ ~~~~~~~~~~~
class TCallDllApp : public TApplication {
  public:
    void InitMainWindow();
};


void
TCallDllApp::InitMainWindow()
{
  MainWindow = new TFrameWindow(0, "CallDll", new TTestWindow);
  MainWindow->AssignMenu(IDM_COMMANDS);
}


int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TCallDllApp().Run();
}
