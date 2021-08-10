//----------------------------------------------------------------------------
// LED Window to Display Numbers
//
//  ledwind.h
//
// Chris Hewitt, 100036,133 
//
// Displays red LEDs on a black background. The chiseled surrounding is
// optional and is designed to fit on a GRAY background. Setting bSurround
// to TRUE adds 2 pixels to height and width. Height is 24, width is 13 *
// number of digits (not counting the surround).
//
// If bClock is TRUE, the LEDWindow becomes an HH:MM:SS clock, and
// lLEDValue should be a time variable (seconds since 1st Jan 1970,
// or, to be more exact, seconds since -05:00 on 0th Jan 1970!), just
// feed it a time value, or, for an elapsed time counter, a number.
//
// The maximum size of an LEDWindow is 10 Digits.
//
// StarTimer and StopTimer may be used to make the LED register
// time intervals between 1 and 60 seconds. The LED will be incremented
// by one for each interval.
//
// The Bitmaps led0.bmp thru led9.bmp must be declared in the resource
// file as LED0Bmp, LED1Bmp etc. (see example).
//
//----------------------------------------------------------------------------
#if !defined (LEDWIND_H)
#define LEDWIND_H

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
class _EXPCLASS TBitmap;
class _EXPCLASS TLedDigit;

class TLedWindow : public TWindow
{
  public:
    TLedWindow(TWindow* parent, int x, int y, int digits, bool surround, 
               bool clock, long value);
   ~TLedWindow();

    void SetupWindow();

    void DisplayNumber(long value);
    bool StartTimer(int interval);
    void StopTimer();

    long       LedValue;        // The Current Value of this LED window
    
  protected:
    void UpdateLeds();
    void Paint(TDC& dc, bool erase, TRect& rect);
    void EvTimer(uint);
  
    TBitmap*   LedBmp[11];      // Bitmaps for LED numbers (0 - 9 + :)
    bool       Beveled;         // True if led frame is beveled
    int        MaxDigits;       // Maximum Number of Digits
    int        DigitStart;      // Start location of LED Digits in Window
    int        Row, Col;        // The parent window offset of LED Window
    TLedDigit* Led[10];         // Handle array for LED Digit Children

    bool       TimerActive;     // Switch indicating if this is a timer
    int        TimerInterval;   // The current Timer interval
    bool       ClockWindow;     // True if this is a Clock
    long       ClockWork;       // Used to store altered time values
    struct tm* tmLedValue;      // Time Struct for Clock Windows
      
    // Note: LedDigits are right to left: *Led[0] (and OldDigit[0]) is
    //       the right-most (ones) digit.

  DECLARE_RESPONSE_TABLE(TLedWindow);
};

#endif
