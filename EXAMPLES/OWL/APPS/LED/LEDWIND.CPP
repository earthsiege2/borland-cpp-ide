//----------------------------------------------------------------------------
// LED Window to Display Numbers
//
//  ledwind.cpp
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/dc.h>
#include <owl/gdiobjec.h>
#include "ledwind.h"
#include <time.h>

const int DigitW = 13;
const int DigitH = 23;

//
//
//
class TLedDigit : public TWindow {
  public:
    TLedDigit(TWindow* parent, TPoint& p);
    void UpdateDigit(TBitmap* ledBmp);

  protected:
    void Paint(TDC& dc, bool erase, TRect& rect);

    TBitmap* CurrentLedBmp;      // Digit bitmap Currently in Window

//  DECLARE_RESPONSE_TABLE(TLedDigit);
};

//DEFINE_RESPONSE_TABLE1(TLedDigit, TWindow)
//END_RESPONSE_TABLE;

//
// LedDigit - Create a new LedDigit
//
TLedDigit::TLedDigit(TWindow* parent, TPoint& p)
:
  TWindow(parent, "")
{
  Attr.X = p.x;
  Attr.Y = p.y;
  Attr.W = DigitW;
  Attr.H = DigitH;
  Attr.Style = WS_VISIBLE|WS_CHILD;
  CurrentLedBmp = 0;
}

//
// UpdateDigit - Set the digit in question invalid if it has changed
//
void TLedDigit::UpdateDigit(TBitmap* ledBmp)
{
  if (ledBmp != CurrentLedBmp) {
    CurrentLedBmp = ledBmp;
    Invalidate(false);      // Assumes that HWindow is valid
  }
}

//
// Paint - Paint the LedDigit
//
void TLedDigit::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  if (CurrentLedBmp) {
    TMemoryDC  memDC(dc);
    memDC.SelectObject(*CurrentLedBmp);
    dc.BitBlt(0, 0, 13, 24, memDC, 0, 0, SRCCOPY);
  }
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TLedWindow, TWindow)
  EV_WM_TIMER,
END_RESPONSE_TABLE;

//
// Called with parent window handle, int x and y offsets in parent,
// int number of digits, and bool beveled setting.
//
TLedWindow::TLedWindow(TWindow* parent, int x, int y,
                       int digits, bool beveled, bool clock, long value)
:
  TWindow(parent, "")
{
  LedValue = value;
  if (clock)
  {
    digits = 8;                          // A clock HH:MM:SS
    ClockWork = LedValue;                // Work field for localtime
    if (ClockWork < 86400l)              // Time is actually since -05:00
      ClockWork = ClockWork + 18000l;    // on 0th Jan 1970 !
    tmLedValue = localtime(&ClockWork);  // Point struct at Value
  }

  if (digits > 10)
    digits = 10;

  Attr.W = 13*digits;
  Attr.H = 24;
  DigitStart = Attr.W;
  if (beveled)
  {
    Attr.W = Attr.W + 2;
    Attr.H = Attr.H + 2;
    DigitStart--;
  }
  Attr.X = x;
  Attr.Y = y;
  Attr.Style = WS_VISIBLE|WS_CHILD;

  HINSTANCE inst = *GetApplication();
  LedBmp[0] = new TBitmap(inst, "Led0Bmp");
  LedBmp[1] = new TBitmap(inst, "Led1Bmp");
  LedBmp[2] = new TBitmap(inst, "Led2Bmp");
  LedBmp[3] = new TBitmap(inst, "Led3Bmp");
  LedBmp[4] = new TBitmap(inst, "Led4Bmp");
  LedBmp[5] = new TBitmap(inst, "Led5Bmp");
  LedBmp[6] = new TBitmap(inst, "Led6Bmp");
  LedBmp[7] = new TBitmap(inst, "Led7Bmp");
  LedBmp[8] = new TBitmap(inst, "Led8Bmp");
  LedBmp[9] = new TBitmap(inst, "Led9Bmp");
  LedBmp[10] = new TBitmap(inst, "LedColBmp");

  Beveled = beveled;
  MaxDigits = digits;

  TimerActive = false;
  TimerInterval = 0;
  ClockWindow = clock;

  TPoint pos(DigitStart - (DigitW-1), 0);
  if (Beveled)
    pos += TSize(1,1);
  for (int i = 0; i < MaxDigits; i++, pos -= TSize(DigitW,0))
    Led[i] = new TLedDigit(this, pos);

  // Modify the background color attribute to 3dFace (grey usually)
  //
  SetBkgndColor(TColor::Sys3dFace);
}

//
//
//
TLedWindow::~TLedWindow()
{
  for (int i = 0; i < 11; i++)
    delete LedBmp[i];
}

//
//
//
void TLedWindow::SetupWindow()
{
  TWindow::SetupWindow();
  UpdateLeds();          // Set up initial Led values
}

//
// DisplayNumber - Accept a number to Display
//
void TLedWindow::DisplayNumber(long value)
{
  LedValue = value;
  if (ClockWindow)
  {
    ClockWork = LedValue;               // Work field for localtime
    if (ClockWork < 86400l)             // Handle 0th Jan 1970
      ClockWork = ClockWork + 18000l;   // Add 5 hours
    tmLedValue = localtime(&ClockWork); // Point struct at Value
  }
  UpdateLeds();
}

//
// StartTimer - Used to Start an Led Timer Window
//
bool TLedWindow::StartTimer(int interval)
{
  // Set Timer (pass interval to SetTimer in milliseconds)
  //
  if (interval == 0 || interval > 60 || !SetTimer(1, interval*1000, 0))
    return false;

  TimerActive = true;
  TimerInterval = interval;
  return true;
}

//
// StopTimer - Stops a previously started Led timer window
//
void TLedWindow::StopTimer()
{
  if (TimerActive)
  {
    KillTimer(1);
    TimerActive = false;
    TimerInterval = 0;
  }
}

//
// Called for each WM_TIMER received by this TLedWindow
//
void TLedWindow::EvTimer(UINT)
{
  LedValue = LedValue + 1;
  if (ClockWindow)
  {
    ClockWork = ClockWork + 1;                // Work field for localtime
    tmLedValue = localtime(&ClockWork);       // Point struct at Value
  }
  UpdateLeds();
}

//
// Paint TLedWindow bevel if enabled
//
void TLedWindow::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  if (Beveled) {
    dc.SelectObject(TPen(TColor::Sys3dFace));
    dc.MoveTo(0, 0);
    dc.LineTo(MaxDigits*DigitW+1, 0);
    dc.MoveTo(0, 0);
    dc.LineTo(0, DigitH+1);

    dc.SelectObject(TPen(TColor::Sys3dHilight));
    dc.MoveTo(0, DigitH+1);
    dc.LineTo(MaxDigits*DigitW+1, DigitH+1);
    dc.MoveTo(MaxDigits*DigitW+1, 0);
    dc.LineTo(MaxDigits*DigitW+1, DigitH+2);

    dc.SetPixel(TPoint(MaxDigits*DigitW+1, 0), TColor(192, 192, 192));
    dc.SetPixel(TPoint(0, DigitH+1), TColor(192, 192, 192));
  }
}

//
// UpdateLeds - Work out which LedDigits need to be replaced,
// then invalidate the little suckers. This is simple except if
// Clock = true, in which case we need to handle ':'s.
//
void TLedWindow::UpdateLeds()
{
  long value = LedValue;
  for (int i = 0; i < MaxDigits; i++) {
    int  digit;
    if (ClockWindow && (i == 2 || i == 5))
      // Digit 10 is ':', use for positions 2 and 5 of clocks
      digit = 10;
    else {
      if (ClockWindow && tmLedValue) {
        // Treat Clock as 3 different values
        if (i == 0)
          value = tmLedValue->tm_sec;
        else if (i == 3)
          value = tmLedValue->tm_min;
        else if (i == 6)
          value = tmLedValue->tm_hour;
      }
      digit = (int)(value - (value/10)*10);
      value = value/10;
    }
    Led[i]->UpdateDigit(LedBmp[digit]);
  }
}
