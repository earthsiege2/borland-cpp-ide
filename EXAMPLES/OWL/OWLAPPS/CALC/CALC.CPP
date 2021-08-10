//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991 by Borland International
//    Simple four function calculator
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dc.h>
#include <owl\dialog.h>
#include <owl\framewin.h>
#include <cstring.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define min(a,b)   (((a) <(b)) ? (a) :(b))

const char AppName[] = "Calc"; // Name of app, window title & icon resource id

const int DisplayDigits = 15;  // number of digits in calculator display

const int ID_DISPLAY = 400;    // control ID of display static text

enum TCalcState {CS_FIRST, CS_VALID, CS_ERROR};  // calculator state

// Calculator dialog window object
//
class TCalc : public TDialog {
  public:
    TCalcState  CalcStatus;
    char        Operator;
    char        Number[DisplayDigits + 1];
    BOOL        Negative;
    double      Operand;
    TBrush      BlueBrush;

    TCalc();

    void          FlashButton(char key);
    void          Error();

    void          SetDisplay(double r);
    void          GetDisplay(double& r);
    virtual void  UpdateDisplay();

    void          CheckFirst();
    void          InsertKey(char key);
    void          CalcKey(char key);
    void          Clear();

  protected:
    //
    // override EvCommand() defined by class TWindow
    //
    LRESULT       EvCommand(UINT, HWND, UINT);

    void          EvPaint();

    //
    // message response functions
    //
    HBRUSH        EvCtlColor(HDC, HWND hWndChild, UINT ctlType);

  DECLARE_RESPONSE_TABLE(TCalc);
};

DEFINE_RESPONSE_TABLE1(TCalc, TDialog)
  EV_WM_PAINT,
  EV_WM_CTLCOLOR,
END_RESPONSE_TABLE;

//
// Calculator constructor.  Create blue brush for calculator background,
// and do a clear command.
//
TCalc::TCalc()
  : TWindow((TWindow*)0),
    TDialog(0, AppName),
    BlueBrush(TColor(0, 0, 255))
{
  Clear();
}

//
// Colorize the calculator. Allows background to show through corners of
//  buttons, uses yellow text on black background in the display, and sets
//  the dialog background to blue.
//
HBRUSH
TCalc::EvCtlColor(HDC hDC, HWND hWndChild, UINT ctlType)
{
  switch (ctlType) {
    case CTLCOLOR_BTN:
      SetBkMode(hDC, TRANSPARENT);
      return (HBRUSH)GetStockObject(NULL_BRUSH);

    case CTLCOLOR_STATIC:
      SetTextColor(hDC, TColor::LtYellow);
      SetBkMode(hDC, TRANSPARENT);
      return (HBRUSH)GetStockObject(BLACK_BRUSH);

    case CTLCOLOR_DLG:
      SetBkMode(hDC, TRANSPARENT);
      return (HBRUSH)BlueBrush;

    default:
      return TDialog::EvCtlColor(hDC, hWndChild, ctlType);
  }
}

//
// Even dialogs can have their backgrounds painted on.  This creates
//  a red ellipse over the blue background.
//
void
TCalc::EvPaint()
{
  TBrush    redBrush(TColor(255, 0, 0));
  TPaintDC  dc(*this);

  dc.SelectObject(redBrush);
  dc.SelectStockObject(NULL_PEN);

  TRect clientRect = GetClientRect();
  clientRect.bottom = clientRect.right;
  clientRect.Offset(-clientRect.right/4, -clientRect.right/4);
  dc.Ellipse(clientRect);
}

//
// Flash a button with the value of Key.  Looks exactly like a
// click of the button with the mouse.
//
void
TCalc::FlashButton(char key)
{
  if (key == 0x0D)
     key = '=';  // Treat Enter like '='

  HWND button = GetDlgItem(toupper(key));

  if (button) {
    ::SendMessage(button, BM_SETSTATE, 1, 0);

    for (int delay = 1; delay <= 30000; ++delay)
      ;

    ::SendMessage(button, BM_SETSTATE, 0, 0);
  }
}

//
// here we handle all of the child id notifications (BN_CLICKED from the
// buttons) and all accelerators at once rather than have separate response
// table entries for each...
//
LRESULT
TCalc::EvCommand(UINT id, HWND hWndCtl, UINT notifyCode)
{
  if (hWndCtl != 0 && notifyCode == BN_CLICKED)
    CalcKey(char(id));  // button notification

  else if (hWndCtl == 0 && notifyCode == 1) {
    //
    // from an accelerator
    //
    FlashButton(char(id));
    CalcKey(char(id));
  }

  return TDialog::EvCommand(id, hWndCtl, notifyCode);
}

//
// Set Display text to the current value.
//
void
TCalc::UpdateDisplay()
{
  char  str[DisplayDigits + 2];

  if (Negative)
    strcpy(str, "-");

  else
    str[0] = '\0';

  ::SetWindowText(GetDlgItem(ID_DISPLAY), strcat(str, Number));
}

//
// Clear the calculator.
//
void
TCalc::Clear()
{
  CalcStatus = CS_FIRST;
  strcpy(Number, "0");
  Negative = FALSE;
  Operator = '=';
}

void
TCalc::Error()
{
  CalcStatus = CS_ERROR;
  strcpy(Number, "Error");
  Negative = FALSE;
}

void
TCalc::SetDisplay(double r)
{
  char*  first;
  char*  last;
  int    charsToCopy;
  char   str[64];

  //
  // limit results of calculations to 7 digits to the right of the dec. point
  //
  r = (floor(r * 10000000L + .5)) / 10000000L;

  sprintf(str, "%0.10f", r);
  first = str;
  Negative = FALSE;

  if (str[0] == '-') {
    first++;
    Negative = TRUE;
  }

  if (strlen(first) > DisplayDigits + 1 + 10 )
    Error();

  else {
    last = strchr(first, 0);

    while (last[-1] == '0')
      --last;

    if (last[-1] == '.')
      --last;

    charsToCopy = min(DisplayDigits + 1, int(last - first));
    strncpy(Number, first, charsToCopy);
    Number[charsToCopy] = 0;
  }
}

void
TCalc::GetDisplay(double& r)
{
  r = atof(Number);

  if (Negative)
    r = -r;
}

void
TCalc::CheckFirst()
{
  if (CalcStatus == CS_FIRST) {
    CalcStatus = CS_VALID;
    strcpy(Number, "0");
    Negative = FALSE;
  }
}

void
TCalc::InsertKey(char key)
{
  int l = strlen(Number);

  if (l < DisplayDigits) {
    Number[l] = key;
    Number[l + 1] = 0;
  }
}

//
// Process calculator key.
//
void
TCalc::CalcKey(char key)
{
  key = (char)toupper(key);

  if (CalcStatus == CS_ERROR && key != 'C')
    key = ' ';

  if (key >= '0' && key <= '9') {
    CheckFirst();

    if (strcmp(Number, "0") == 0)
      Number[0] = '\0';

    InsertKey(key);

  } else if (key == '+' || key == '-' || key == '*' ||
             key == '/' || key == '=' || key == '%' || key == 0x0D) {

    if (CalcStatus == CS_VALID) {
      CalcStatus = CS_FIRST;
      double  r;
      GetDisplay(r);

      if (key == '%') {
        switch(Operator) {
          case '+':
          case '-':
            r = Operand * r / 100;
            break;

          case '*':
          case '/':
            r /= 100;
            break;
        }
      }

      switch(Operator) {
        case '+':
          SetDisplay(Operand + r);
          break;

        case '-':
          SetDisplay(Operand - r);
          break;

        case '*':
          SetDisplay(Operand * r);
          break;

        case '/':
          if (r == 0)
            Error();

          else
            SetDisplay(Operand / r);
          break;
      }
    }

    Operator = key;
    GetDisplay(Operand);

  } else
    switch(key) {
      case '.':
        CheckFirst();
        if (!strchr(Number, '.'))
          InsertKey(key);
        break;

      case 0x8:
        CheckFirst();
        if (strlen(Number) == 1)
          strcpy(Number, "0");
        else
          Number[strlen(Number) - 1] = '\0';
        break;

      case '_':
        Negative = !Negative;
        break;

      case 'C':
        Clear();
        break;
    }

  UpdateDisplay();
}

//----------------------------------------------------------------------------

//
// Calculator application object
//
class TCalcApp : public TApplication {
  public:
    TCalcApp(const char far* name) : TApplication(name) {}

    void   InitMainWindow();
};

//
// Create calculator as the application's main window.
//
void
TCalcApp::InitMainWindow()
{
  TWindow* calcWin = new TCalc;
  calcWin->Attr.AccelTable = AppName;

  MainWindow = new TFrameWindow(0, Name, calcWin, TRUE);
  MainWindow->SetIcon(this, AppName);
  MainWindow->Attr.Style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TCalcApp(AppName).Run();
}
