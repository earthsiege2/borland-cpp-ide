//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/dialog.h>
#include <owl/dc.h>
#include <winsys/uimetric.h>
#include "aclock.h"
#include <alloc.h>
#include <dos.h>
#include <stdlib.h>
#include <math.h>
#include <mmsystem.h>
#include <stdio.h>

#define USE_BWCC

#if defined(USE_BWCC)
# define IDD_ABOUT "IDD_ABOUT_BWCC"
#else
# define IDD_ABOUT "IDD_ABOUT"
#endif

const float Pi2 = 2*3.141592;

//
// Chime & cukoo sounds based on the WIN.INI entries
//
const char ChimeSoundStr[] = "SystemAsterisk";
const char CuckooSoundStr[] = "SystemExclamation";

//
// Animated class animates a set of bitmaps
//
class Animated {
  public:
    Animated(HINSTANCE hInst, int numB, char far* name, int delayTics, int endTics);
   ~Animated();

    void DisplayBegin(TDC& dc, int x, int y);
    void DisplayNext(TDC& dc);

    BOOL IsRunning() {return WaitingTic;}

  private:
    int       DelayTics;    // Amount to delay between frames (18.2 ticks/sec)
    int       EndTics;      // Amount to delay after sequence
    int       WaitingTic;   // Countdown for animation timing

    int       NumBmps;      // number of bitmaps
    int       CurBmp;       // currently displayed bitmap
    TBitmap** Bmps;         // bitmaps
    int       X;            // position of bitmap
    int       Y;
};


//
// Construct an animated sequence
//
Animated::Animated(HINSTANCE hInst, int numB, char far* name, int delayTics, int endTics)
 : WaitingTic(0)
{
  NumBmps = numB;
  CurBmp = 0;
  Bmps = new (TBitmap(*[NumBmps]));  //  create array of numB TBitmap*'s

  DelayTics = delayTics;
  EndTics = endTics;

  // Load in bitmap resources
  //
  for (int j = 0; j < NumBmps; j++) {
    char resName[40];
    sprintf(resName, "%s%d", name, j+1);
    Bmps[j] = new TBitmap(hInst, resName);
  }
}

//
//
//
Animated::~Animated()
{
  for (int j = 0; j < NumBmps; j++)
    delete Bmps[j];
  delete[] Bmps;
}

//
// Begin to draw the series of bitmaps timed to the timer.
//
void
Animated::DisplayBegin(TDC& dc, int x, int y)
{
  CurBmp = 0;
  X = x;
  Y = y;
  WaitingTic = 1;   // prime the time clock
  DisplayNext(dc);
}

//
// Draw each of the bitmaps timed to the timer.
//
void
Animated::DisplayNext(TDC& dc)
{
  WaitingTic--;
  if (WaitingTic || CurBmp == NumBmps)
    return;

  TMemoryDC memDC(dc);

  memDC.SelectObject(*Bmps[CurBmp]);
  dc.BitBlt(X, Y, Bmps[CurBmp]->Width(), Bmps[CurBmp]->Height(),
            memDC, 0, 0, SRCCOPY);

  WaitingTic = (++CurBmp == NumBmps) ? EndTics : DelayTics;
}

//----------------------------------------------------------------------------

//
//
//
class TClockWindow : public TFrameWindow {
  public:
    TClockWindow(const char* title);
    ~TClockWindow();

  protected:
    void SetupWindow();

    void PaintHands(TDC& dc, struct time time);
    void Paint(TDC&, bool, TRect&);

    void EvTimer(uint);
    void CmAbout();
    void CmChime();
    void CmCuckoo();

  private:
    TBitmap*    FaceBitmap;   // Clock face bitmap
    TPoint      Center;       // Center of clock
    int         Radius;       // Clock radius
    struct time LastTime;     // Last time drawn
    TPen*       HourPen;      // Pen for clock hour hand
    TPen*       MinutePen;    // Pen for clock minute hand
    Animated*   CuckooAnim;   // Cuckoo sequence

  DECLARE_RESPONSE_TABLE(TClockWindow);
};

DEFINE_RESPONSE_TABLE1(TClockWindow, TFrameWindow)
  EV_WM_TIMER,
  EV_COMMAND(CM_ABOUT, CmAbout),
  EV_COMMAND(CM_EFFECTCHIME, CmChime),
  EV_COMMAND(CM_EFFECTCUCKOO, CmCuckoo),
END_RESPONSE_TABLE;

//
// Load animation sequences and set size in the constructor
//
TClockWindow::TClockWindow(const char* title)
  : TFrameWindow(0, title, 0),
    TWindow(0, title)
{
  // load face bitmap
  //
  FaceBitmap = new TBitmap(*GetModule(), "FACE_BMP");

  // load cuckoo sequence & set frame& end delay time in 1/10 sec tics
  //
  CuckooAnim = new Animated(*GetModule(), 8, "CUCKOO", 9, 80);

  // Set the window size to size of bitmap plus non-client area size
  //
  Attr.W = FaceBitmap->Width() + 2* TUIMetric::CxBorder;
  Attr.H = FaceBitmap->Height() + TUIMetric::CyBorder +
                                  TUIMetric::CyCaption +
                                  TUIMetric::CyMenu ;
  Attr.Style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX);

  Center.x = FaceBitmap->Width() / 2;
  Center.y = FaceBitmap->Height() / 2;
  Radius = 3*(Center.x < Center.y ? Center.x : Center.y) / 4;
}

//
//
//
TClockWindow::~TClockWindow()
{
  KillTimer(1);      // Get rid of timer
  delete MinutePen;  // delete pens, bitmaps, animations
  delete HourPen;
  delete FaceBitmap;
  delete CuckooAnim;
}

//
// Do any HWindow required setup tasks here, not in constructor
//
void
TClockWindow::SetupWindow()
{
  TFrameWindow::SetupWindow();

  // set the timer - get called every minute
  //
  if (!SetTimer(1, 60000U, 0)) {
    MessageBox("Out of Timers", GetApplication()->GetName(),
               MB_ICONEXCLAMATION|MB_OK);
  }

  // Create the pens for the clock hands
  //
  HourPen = new TPen(TColor(0, 255, 255), 4);   // cyan
  MinutePen = new TPen(TColor(255, 0, 255), 4); // purple
}

//
// Paint the clock background and then the hands
//
void
TClockWindow::Paint(TDC& dc, bool, TRect&)
{
  TMemoryDC memDC(dc);
  memDC.SelectObject(*FaceBitmap);
  dc.BitBlt(0, 0, FaceBitmap->Width(), FaceBitmap->Height(), memDC,
            0, 0, SRCCOPY);
  gettime(&LastTime);                   //paint the first time
  PaintHands(dc, LastTime);
}

//
// Paint the hour and minute hands onto the face
//
void
TClockWindow::PaintHands(TDC& dc, struct time time)
{
  // Compute the location of the hands
  //
  float minuteAngle = time.ti_min * Pi2 / 60;
  float hourAngle = (time.ti_hour % 12) * Pi2 / 12 + minuteAngle/12;

  TPoint hourPt((Radius/2)*sin(hourAngle) + Center.x,
                (-Radius/2)*cos(hourAngle) + Center.y);
  TPoint minutePt(Radius*sin(minuteAngle) + Center.x,
                  -Radius*cos(minuteAngle) + Center.y);

  // Now draw them.  Note the use of XOR to simplify erasing.
  //
  dc.SetROP2(R2_XORPEN);
  dc.SelectObject(*HourPen);
  dc.MoveTo(Center);
  dc.LineTo(hourPt);
  dc.SelectObject(*MinutePen);
  dc.MoveTo(Center);
  dc.LineTo(minutePt);
  dc.RestorePen();
}

//
// Menu item Effect:Chime
//
// Stop any currently playing sound, and then play the chime sound.
//
void
TClockWindow::CmChime()
{
  sndPlaySound(0,0);
  sndPlaySound(ChimeSoundStr, SND_ASYNC);
}

//
// Menu item Effect:Cuckoo
//
// Stop any currently playing sound, and then play the cuckoo sound.
//
void
TClockWindow::CmCuckoo()
{
  sndPlaySound(0,0);
  sndPlaySound(CuckooSoundStr, SND_ASYNC);

  // Do cute graphics, temporarally speeding up timer for animation
  //
  TClientDC dc(*this);
  SetTimer(1, 10, 0);
  CuckooAnim->DisplayBegin(dc, 55, 125);
}

//
// Called each timer tick. Every 1/10th second during animation and
// every minute to paints hands
//
void
TClockWindow::EvTimer(uint)
{
  TClientDC dc(*this);

  // If an animation is running, let it draw. If its done then, clean up.
  //
  if (CuckooAnim->IsRunning()) {
    CuckooAnim->DisplayNext(dc);
    if (!CuckooAnim->IsRunning()) {
      SetTimer(1, 60000U, 0);
      Invalidate(FALSE);
    }
    return;
  }

  PaintHands(dc, LastTime);
  gettime(&LastTime);
  PaintHands(dc, LastTime);

  // Every hour play a chime
  //
  if (LastTime.ti_min == 0) {
    CmChime();
    if (LastTime.ti_hour == 0)  // If midnight, time for the cuckoo
      CmCuckoo();
  }
}

//  About dialog box
//
void
TClockWindow::CmAbout()
{
  TDialog(this, IDD_ABOUT).Execute();
}

//----------------------------------------------------------------------------


class TClockApp : public TApplication {
  public:
    TClockApp() : TApplication() {}
    void InitMainWindow();
};

void
TClockApp::InitMainWindow()
{
  MainWindow = new TClockWindow("Cuckoo Clock");
  MainWindow->AssignMenu("TOOL_MENU");
  MainWindow->SetIcon(this, IDI_APP);
#if defined(USE_BWCC)
  EnableBWCC();
#endif
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TClockApp().Run();
}
