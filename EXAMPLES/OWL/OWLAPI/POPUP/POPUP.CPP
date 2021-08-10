//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <string.h>
#include <owl\dc.h>

const int CM_WINDOW = 100;                // base id for different windows.

class TSubWindow : public TFrameWindow {
  public:
    enum TType { Child, PopParent, PopNoParent };

    TSubWindow(TWindow* parent, TType type);
   ~TSubWindow();

  protected:
    void EvSize(UINT sizeType, TSize& size)
      {Invalidate(); TFrameWindow::EvSize(sizeType, size);}
    void Paint(TDC& dc, BOOL, TRect&);

  private:
    TType Type;

  DECLARE_RESPONSE_TABLE(TSubWindow);
};

DEFINE_RESPONSE_TABLE1(TSubWindow, TFrameWindow)
  EV_WM_SIZE,
END_RESPONSE_TABLE;

// pointers to different child windows.
//
TWindow* SubWinPtr[] = { 0, 0, 0 };       

// Titles for the different child windows.
//
const char* SubWinTitle[] = {
  "Child Window", "Popup with Parent", "Popup without Parent"
};

// How the different child windows will be created.
//
long SubWinStyle[] = {
  WS_VISIBLE | WS_CHILD | WS_CAPTION | WS_BORDER
             | WS_SYSMENU | WS_MINIMIZEBOX | WS_THICKFRAME,
  WS_VISIBLE | WS_POPUP | WS_OVERLAPPEDWINDOW,
  WS_VISIBLE | WS_POPUP | WS_OVERLAPPEDWINDOW
};

// Initial position of child windows.
//
TPoint SubWinPos[] = {
  TPoint(10, 10),
  TPoint(34, 72),
  TPoint(54, 92)
};

// Some text to be display in the client area of the child windows.
//
const char* SubWinText[] = {
  "Child windows cannot be moved outside their parent window.  When " \
    "minimized, a child window's icon resides within the parent " \
    "window.",
  "Popup windows can be moved outside their parent window.  A popup " \
    "with a parent is always displayed in front of the parent, " \
    "even when the parent is focused.  To test this, click on the " \
    "parent window.  When minimized, popup icons reside on the desktop.",
  "Popup windows can be moved outside their parent window.  A popup " \
    "without a parent allows the parent to be brought to the front " \
    "when focused. To test this, click on the parent window.  When " \
    "minimized, popup icons reside on the desktop."
};

//
// Create window of specified type, indicated by 'type'.
// Title and position of window set according to value of 'type'.
//
TSubWindow::TSubWindow(TWindow* parent, TType type)
  : TFrameWindow(parent, SubWinTitle[type]),
    Type(type)
{
  Attr.Style = SubWinStyle[Type];
  Attr.X = SubWinPos[Type].x;
  Attr.Y = SubWinPos[Type].y;
  Attr.W = 300;
  Attr.H = 150;
}

//
// Destroy window.  SubWinPtr[Type] is set to 0 to indicate that the window
// has be closed.
//
TSubWindow::~TSubWindow()
{
  SubWinPtr[Type] = 0;
}

//
// Draw help text in client are of window.
//
void
TSubWindow::Paint(TDC& dc, BOOL, TRect&)
{
  TRect rect = GetClientRect();
  rect.Inflate(-2, 0);
  dc.DrawText(SubWinText[Type], strlen(SubWinText[Type]), rect, DT_WORDBREAK);
}

//----------------------------------------------------------------------------

class TMainWindow : public TFrameWindow {
  public:
    TMainWindow(const char* title);

    void ShowSubWindow(TWindow* parent, TSubWindow::TType type);
    void EvInitMenu(HMENU menu);
    void CmChild();
    void CmPopParent();
    void CmPopNoParent();

  DECLARE_RESPONSE_TABLE(TMainWindow);
};

DEFINE_RESPONSE_TABLE1(TMainWindow, TFrameWindow)
  EV_WM_INITMENU,
  EV_COMMAND(CM_WINDOW + TSubWindow::Child, CmChild),
  EV_COMMAND(CM_WINDOW + TSubWindow::PopParent, CmPopParent),
  EV_COMMAND(CM_WINDOW + TSubWindow::PopNoParent, CmPopNoParent),
END_RESPONSE_TABLE;

TMainWindow::TMainWindow(const char* title)
  : TFrameWindow(0, title),
    TWindow(0, title)
{
  Attr.X = 0;
  Attr.Y = 0;
  Attr.W = 400;
  Attr.H = 215;
  AssignMenu("COMMANDS");
}

//
// Create sub-window.  If sub-window, specified by 'type', does not exist
// then create it, else make the sub-window the active window.
//
void
TMainWindow::ShowSubWindow(TWindow* parent, TSubWindow::TType type)
{
  if (!SubWinPtr[type])
    (SubWinPtr[type] = new TSubWindow(parent, type))->Create();

  else {
    SubWinPtr[type]->SetFocus();
    SubWinPtr[type]->SetActiveWindow();
  }
}

//
// Setup menu state.  If sub-window has been created then then check that
// menu item, else uncheck it.
//
void
TMainWindow::EvInitMenu(HMENU menu)
{
  for (int i = TSubWindow::Child; i <= TSubWindow::PopNoParent; i++) {
    WORD state;
    if (!SubWinPtr[i])
      state = MF_UNCHECKED;
    else
      state = MF_CHECKED;
    ::CheckMenuItem(menu, CM_WINDOW + i, state);
  }
}

//
// Create the different child windows...
//

void
TMainWindow::CmChild()
{
  ShowSubWindow(this, TSubWindow::Child);
}

void
TMainWindow::CmPopParent()
{
  ShowSubWindow(this, TSubWindow::PopParent);
}

void
TMainWindow::CmPopNoParent()
{
  ShowSubWindow(0, TSubWindow::PopNoParent);
}

//----------------------------------------------------------------------------

class TPopupApp : public TApplication {
  public:
    TPopupApp() : TApplication("Popup") {}
    void InitMainWindow()
                     {MainWindow = new TMainWindow("Parent Window");}

    BOOL CanClose();
};

BOOL
TPopupApp::CanClose()
{
   // In order to avoid debugging kernel warning messages, ensure that
   // the parentless popup window is destroyed before exiting the
   // application.
   //
   if (SubWinPtr[TSubWindow::PopNoParent])
      SubWinPtr[TSubWindow::PopNoParent]->ShutDownWindow();
   return TRUE;
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TPopupApp().Run();
}
