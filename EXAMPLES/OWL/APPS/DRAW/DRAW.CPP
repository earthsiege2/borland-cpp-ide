//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dc.h>
#include <owl/opensave.h>
#include <owl/inputdia.h>
#include <services/cstring.h>
#include <services/dir.h>
#include "draw.rh"

class TDrawWindow : public TFrameWindow {
  public:
    TDrawWindow(TWindow* parent, const char far* title);

    void CleanupWindow();

  protected:
    void EvLButtonDown(uint modKeys, TPoint& point);
    void EvLButtonUp(uint modKeys, TPoint& point);
    void EvMouseMove(uint modKeys, TPoint& point);
    void EvRButtonDown(uint modKeys, TPoint& point);
    void CmRecord();
    void CmStop();
    void CmPlay();

  private:
    TClientDC*    HoldDC;
    TMetaFileDC*  MetaFileDC;
    bool          Recording;
    bool          ButtonDown;

    TOpenSaveDialog::TData  FileData;

    bool CloseMetaFile();
    void DisplayMessage(const string& msg);

  DECLARE_RESPONSE_TABLE(TDrawWindow);
};

DEFINE_RESPONSE_TABLE1(TDrawWindow, TFrameWindow)
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
  EV_WM_RBUTTONDOWN,
  EV_COMMAND(CM_RECORD, CmRecord),
  EV_COMMAND(CM_STOP, CmStop),
  EV_COMMAND(CM_PLAY, CmPlay),
END_RESPONSE_TABLE;

//
//
//
TDrawWindow::TDrawWindow(TWindow* parent, const char far* title)
:
  TFrameWindow(parent, title)
{
  ButtonDown = false;
  HoldDC = 0;
  MetaFileDC = 0;
  Recording = false;
  AssignMenu("DRAW_MENU");

  //
  // Initialize file open data.
  //
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY;
  FileData.SetFilter("MetaFiles (*.WMF)|*.wmf|");
}

//
// CleanupWindow(). Close and destroy meta file (disk file remains);
//
void
TDrawWindow::CleanupWindow()
{
  CmStop();
}

//
// Define a TDrawWindow's response to an incoming "left-button-down"
// message.  In response, TDrawWindows prepare to draw a line,
// setting the current position in client area, retrieving a display
// context from MS-Windows, and capturing mouse input.  Write drawing to
// metafile if recording.
//
void
TDrawWindow::EvLButtonDown(uint, TPoint& point)
{
  if (!ButtonDown) {
    ButtonDown = true;
    SetCapture();    // Direct all subsequent mouse input to this window
    HoldDC = new TClientDC(*this);
    HoldDC->MoveTo(point);
    if (Recording)
      MetaFileDC->MoveTo(point);
  }
}

//
// Define a TDrawWindow's response to an incoming "mouse-move"
// message.  In response, TDrawWindows draw a line using the new
// position of the mouse. Write drawing to metafile if recording
//
void
TDrawWindow::EvMouseMove(uint /*modKeys*/, TPoint& point)
{
  if (ButtonDown) {
    HoldDC->LineTo(point);   // draw the line
    if (Recording)
      MetaFileDC->LineTo(point);
  }
}

//
// Define a TDrawWindow's response to an incoming "left-button-up"
// message.  In response, TDrawWindows "cleanup" required after a
// line is drawn, releasing the display context to MS-Windows, and
// releasing mouse input.
//
void
TDrawWindow::EvLButtonUp(uint, TPoint&)
{
  if (ButtonDown) {
    ReleaseCapture();
    delete HoldDC;
    HoldDC = 0;
    ButtonDown = false;
  }
}

//
// Define a TDrawWindow's response to an incoming
// "right-button-down" message.  In response, TDrawWindows "clear"
// their client area.
// Invalidate the entire window--Windows will send WM_PAINT message to the
// window.  If recording close metafile and display message.
//
void
TDrawWindow::EvRButtonDown(uint, TPoint&)
{
  Invalidate(true);
  CmStop();
}

//
// Ask user for a filename and create metafile.  Set flag indicating that
// we are recording metafile.  If already recording then close it and display
// message.
//
void
TDrawWindow::CmRecord()
{
  *FileData.FileName = 0;
  if (TFileSaveDialog(this, FileData, 0, "Record MetaFile").Execute() == IDOK) {
    CmStop();
    MetaFileDC = new TMetaFileDC(FileData.FileName);
    Recording = true;
    Invalidate(true);                       // clear the client area.
  }
}

//
// Stop any current MetaFile recording.
//
void
TDrawWindow::CmStop()
{
  if (CloseMetaFile())
    DisplayMessage("Current MetaFile recording complete.");
}

//
// Ask user for a file to play.  Assumes file is a metafile (PlayOnto will
// fail if it isn't).  If already recording then close it and display message.
// Before playing metafile clear client area.
//
void
TDrawWindow::CmPlay()
{
  *FileData.FileName = 0;
  if (TFileOpenDialog(this, FileData, 0, "Open MetaFile").Execute() == IDOK) {
    CmStop();
    Invalidate(true);                       // clear the client area.
    UpdateWindow();
    TMetaFilePict mf(FileData.FileName);
    HoldDC = new TClientDC(*this);
    mf.PlayOnto(*HoldDC, GetClientRect().Size());
    delete HoldDC;
    HoldDC = 0;
  }
}

//
// Close and destroy metafile, disk file remains.  Return true if we were
// recording, else false.
//
bool
TDrawWindow::CloseMetaFile()
{
  if (Recording) {
    delete MetaFileDC;
    Recording = false;
    return true;
  }
  return false;
}

//
// Display a message to user.
//
void
TDrawWindow::DisplayMessage(const string& msg)
{
  MessageBox(msg.c_str(), GetApplication()->GetName(), MB_OK);
}

//----------------------------------------------------------------------------

//
//
//
class TDrawApp : public TApplication {
  public:
    TDrawApp() : TApplication("Draw") {}
    void InitMainWindow();
};

//
//
//
void
TDrawApp::InitMainWindow()
{
  MainWindow = new TDrawWindow(0, "Draw Away!");
}

//
//
//
int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TDrawApp().Run();
}
