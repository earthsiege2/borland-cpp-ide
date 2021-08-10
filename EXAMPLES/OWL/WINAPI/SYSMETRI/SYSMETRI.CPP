//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1995 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/uihelper.h>
#include <owl/listbox.h>
#include <owl/gdiobjec.h>
#include <stdio.h>

class TTestWindow : public TListBox {
  public:
    TTestWindow();

    void Update();

  protected:
    void    SetupWindow();
    void    EvWinIniChange(char far*) { Update(); }
#if defined(BI_PLAT_WIN32)
    void    EvDisplayChange(bool, int, int) { Update(); }
#endif

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TListBox)
  EV_WM_WININICHANGE,
#if defined(BI_PLAT_WIN32)
  EV_WM_DISPLAYCHANGE,
#endif
END_RESPONSE_TABLE;

TTestWindow::TTestWindow()
:
  TListBox(0, 1, 0, 0, 100, 200)
{
  Attr.Style &= ~LBS_SORT;
  Attr.Style |= LBS_NOINTEGRALHEIGHT;
  Attr.ExStyle |= WS_EX_CLIENTEDGE;
}

//
//
//
void
TTestWindow::SetupWindow()
{
  TWindow::SetupWindow();
  Update();
}

static char* sSMLabel[] = {
  "CxScreen",       // 0
  "CyScreen",       // 1
  "CxVScroll",      // 2
  "CyHScroll",      // 3
  "CyCaption",      // 4
  "CxBorder",       // 5
  "CyBorder",       // 6
  "CxFixedFrame",   // 7
  "CyFixedFrame",   // 8
  "CyVThumb",       // 9
  "CxHThumb",       // 10
  "CxIcon",         // 11
  "CyIcon",         // 12
  "CxCursor",       // 13
  "CyCursor",       // 14
  "CyMenu",         // 15
  "CxFullScreen",   // 16
  "CyFullScreen",   // 17
  "CyKanjiWindow",  // 18
  "MousePresent",   // 19
  "CyVScroll",      // 20
  "CxHScroll",      // 21
  "Debug",          // 22
  "SwapButton",     // 23
  "Reserved1",      // 24
  "Reserved2",      // 25
  "Reserved3",      // 26
  "Reserved4",      // 27
  "CxMin",          // 28
  "CyMin",          // 29
  "CxSize",         // 30
  "CySize",         // 31
  "CxSizeFrame",    // 32
  "CySizeFrame",    // 33
  "CxMinTrack",     // 34
  "CyMinTrack",     // 35
  "CxDoubleClk",    // 36
  "CyDoubleClk",    // 37
  "CxIconSpacing",  // 38
  "CyIconSpacing",  // 39
  "MenuDropAlignment", // 40
  "PenWindows",     // 41
  "DbcsEnabled",    // 42
  "CMouseButtons",  // 43
  "Secure",         // 44
  "CxEdge",         // 45
  "CyEdge",         // 46
  "CxMinSpacing",   // 47
  "CyMinSpacing",   // 48
  "CxSmIcon",       // 49
  "CySmIcon",       // 50
  "CySmCaption",    // 51
  "CxSmSize",       // 52
  "CySmSize",       // 53
  "CxMenuSize",     // 54
  "CyMenuSize",     // 55
  "Arrange",        // 56
  "CxMinimized",    // 57
  "CyMinimized",    // 58
  "CxMaxTrack",     // 59
  "CyMaxTrack",     // 60
  "CxMaximized",    // 61
  "CyMaximized",    // 62
  "ShowSounds",     // 63
  "KeyboardPref",   // 64
  "HighContrast",   // 65
  "ScreenReader",   // 66
  "CleanBoot",      // 67
  "CxDrag",         // 68
  "CyDrag",         // 69
  "Network",        // 70
  "CxMenuCheck",    // 71
  "CyMenuCheck",    // 72
  "SlowMachine",    // 73
  "MideastEnabled", // 74
};

void
TTestWindow::Update() // "WindowMetrics" ?
{
  ClearList();

  // Display sys metric values in listbox
  //
  for (int i = 0; i < SM_CMETRICS; i++) {
    char metricStr[256];
    sprintf(metricStr, "%s: %d", sSMLabel[i], ::GetSystemMetrics(i));
    AddString(metricStr);
  }
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "SysMetrics", new TTestWindow, true);
//      MainWindow->Attr.Style &= ~WS_THICKFRAME;
      MainWindow->Attr.ExStyle |= WS_EX_CONTROLPARENT | WS_EX_TOOLWINDOW;
        //WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW;
//  Attr.ExStyle |= WS_EX_CONTROLPARENT; //WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW;
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TTestApp().Run();
}
