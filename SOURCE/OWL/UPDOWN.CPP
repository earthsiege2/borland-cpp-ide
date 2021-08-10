//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
// Implementation of the TUpDown class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_UPDOWN_H)
# include <owl/updown.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#include <stdio.h>

DIAG_DECLARE_GROUP(OwlCommCtrl);        // CommonCtrl Diagnostic group

//
// Constants used when ObjectWindows provides the underlying implementation of
// the Up-down control...
//
const uint UpDownTimerID1 = 0x1000;     // Initial timer (for startup delay)
const uint UpDownTimerID2 = 0x1001;     // Regular timer (for notifications)
const uint InitDelay      = 500;        // Initial delay before notifying
const uint RepeatDelay    = 50;         // Interval between notifications

DEFINE_RESPONSE_TABLE1(TUpDown, TControl)
  EV_WM_VSCROLL,
  EV_WM_HSCROLL,
#if !defined(OWL_NATIVECTRL_ALWAYS)
  EV_WM_ENABLE,
  EV_WM_SHOWWINDOW,
  EV_WM_CANCELMODE,
  EV_WM_TIMER,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
#endif
END_RESPONSE_TABLE;

//
// Constructor of UpDown control
//
TUpDown::TUpDown(TWindow* parent, int id, int x, int y, int w, int h,
                 TWindow* buddy, TModule* module)
:
  TControl(parent, id, "", x, y, w, h, module),
  Buddy(buddy),
  Lower(0),
  Upper(100),
  Pos(0)
{
  Attr.Style = WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP;

  // Update flag based on availability of Common Control Library
  //
  NativeUse = TCommCtrl::IsAvailable() ? nuAlways : nuNever;

#if !defined(OWL_NATIVECTRL_ALWAYS)

  // When running in an environment where the system does not provide
  // Common Controls we need to initialize the variables used for
  // emulating a tabcontrol...
  //
  if (!TCommCtrl::IsAvailable()) {
    Base = 10;
  }

#else

  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());

#endif
}

//
// Constructor to alias an up-down control which is part of a dialog
// resource
//
TUpDown::TUpDown(TWindow* parent, int resourceId, TWindow* buddy, TModule* module)
:
  TControl(parent, resourceId, module),
  Buddy(buddy),
  Lower(0),
  Upper(100),
  Pos(0)
{
  // Update flag based on availability of Common Control Library
  //
  NativeUse = TCommCtrl::IsAvailable() ? nuAlways : nuNever;

#if !defined(OWL_NATIVECTRL_ALWAYS)

  // When running in an environment where the system does not provide Common
  // Controls we need to initialize the variables used for emulation.
  //
  if (!TCommCtrl::IsAvailable()) {
    Base = 10;
  }
#else

  // When OWL is built with the NATIVECTRL_ALWAYS option, the Common Control
  // library MUST be available....
  //
  CHECK(TCommCtrl::IsAvailable());

#endif
}

//
// Return the ClassName of the underlying control.
//
// NOTE: The name returned depends upon whether we're on a system where the OS
//       provides the underlying implementation of UPDOWN controls. Also, when
//       emulating we choose to return a distinct class name; this is not
//       strictly necessary with ObjectWindows. However, it facilitates
//       debugging.
//
char far*
TUpDown::GetClassName()
{
#if defined(OWL_NATIVECTRL_ALWAYS)

  // When OWL is built with the NATIVECTRL_ALWAYS option, the
  // Common Control library MUST be available....
  //
  PRECONDITION(TCommCtrl::IsAvailable());
  NativeUse = TNativeUse(NativeUse | nuUsing);
  return UPDOWN_CLASS;

#else
  // By default we'll use the native implementation if it's available
  //
  if (TCommCtrl::IsAvailable())
    NativeUse = TNativeUse(NativeUse | nuUsing);
  else
    NativeUse = TNativeUse(NativeUse & ~nuUsing);

  // Return class name as per usage...
  //
  return TCommCtrl::IsAvailable() ? UPDOWN_CLASS : "OWL_UpDown";
#endif
}

//
// Override to invoke the OS' 'CreateUpDownControl' method on systems where
// we're using the native implementation of UpDown controls
//
void
TUpDown::PerformCreate(int id)
{
#if !defined(OWL_NATIVECTRL_ALWAYS)
  if (!(NativeUse & nuUsing)) {
    TControl::PerformCreate(id);
    return;
  }
#endif

  PRECONDITION(TCommCtrl::IsAvailable());
  SetHandle(TCommCtrl::Dll()->CreateUpDownControl(Attr.Style,
                                            Attr.X, Attr.Y, Attr.W, Attr.H,
                                            Parent ? Parent->GetHandle() : 0,
                                            id,
                                            *GetModule(),
                                            Buddy ? Buddy->GetHandle() : 0,
                                            Upper, Lower, Pos));
}

//
// Keep TWindow from rerouting these, must be left as-is for updown control
//
void
TUpDown::EvVScroll(uint, uint, THandle)
{
  DefaultProcessing();
}

//
// Keep TWindow from rerouting these, must be left as-is for updown control
//
void
TUpDown::EvHScroll(uint, uint, THandle)
{
  DefaultProcessing();
}


#if !defined(OWL_NATIVECTRL_ALWAYS)

//
// Retrieve acceleration information for the underlying up-down control
//
int
TUpDown::GetAccel(int count, TUDAccel far* accels) const
{
  if (NativeUse & nuUsing) {
    return (int)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETACCEL, count, TParam2(accels));
  }
  else {
    // This feature is not implemented by the emulation version
    // of the UpDown control
    TRACEX(OwlCommCtrl, 0, "TUpDown::GetAccel requires native \
                           CommCtrl implementation");
    return 0;
  }
}

//
// Retrieve the current radix base of the underlying up-down control.
// Return value is either 10 or 16.
//
int
TUpDown::GetBase() const
{
  if (NativeUse & nuUsing) {
    return (int)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETBASE);
  }
  else {
    return Base;
  }
}

//
// Return handle of buddy window of underlying up-down control
//
HWND
TUpDown::GetBuddy() const
{
  if (NativeUse & nuUsing) {
    return (HWND)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETBUDDY);
  }
  else {
    return BuddyHandle;
  }
}

//
// Return current position of underlying up-down control. The high-order word
// in non-zero in case of an error. The current position is in the low-order
// word.
//
int32
TUpDown::GetPos() const
{
  if (NativeUse & nuUsing) {
    return (int32)LoUint16(CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETPOS));
  }
  else {
    return uint32(Pos);
  }
}

//
// Retrieve the minimum and maximum range of the underlying up-down control.
// The low-order word contains the maximum position while the high-order word
// contains the minimum position.
//
uint32
TUpDown::GetRange() const
{
  if (NativeUse & nuUsing) {
    return (uint32)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETRANGE);
  }
  else {
    return MAKELONG(Upper, Lower);
  }
}

//
// Retrieve the minimum and maximum range of the underlying up-down control into
// the specified 'lower' and 'upper' variables respectively.
//
void
TUpDown::GetRange(int& lower, int& upper) const
{
  if (NativeUse & nuUsing) {
    uint32 ret = CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETRANGE);
    lower = HiUint16(ret);
    upper = LoUint16(ret);
  }
  else {
    lower = Lower;
    upper = Upper;
  }
}

//
// Set the acceleration of the underlying up-down control. 'count' specifies
// the number of structures specified in 'accels' while the latter is the
// address of an array of TUDAccel structures.
//
bool
TUpDown::SetAccel(int count, const TUDAccel far* accels)
{
  if (NativeUse & nuUsing) {
    return SendMessage(UDM_SETACCEL, count, TParam2(accels)) != 0;
  }
  else {
    // This feature is not implemented by the emulation version
    // of the UpDown control
    TRACEX(OwlCommCtrl, 0, "TUpDown::SetAccel requires native \
                           CommCtrl implementation");
    return false;
  }
}

//
// Sets the radix of the underlying up-down control. The 'base' parameter
// should be either '10' or '16' for decimal and hexadecimal respectively.
//
int
TUpDown::SetBase(int base)
{
  if (NativeUse & nuUsing) {
    return int(SendMessage(UDM_SETBASE, base));
  }
  else {
    if (base == 10 || base == 16) {
      int prevBase = Base;
      Base = base;
      return prevBase;
    }
    TRACEX(OwlCommCtrl, 0, "TUpDown::SetBase: invalid base:" << base );
  }
  return 0;
}

//
// Sets the buddy window of the underlying up-down control.
//
TWindow::THandle
TUpDown::SetBuddy(HWND hBuddy)
{
  if (NativeUse & nuUsing) {
    return TWindow::THandle(SendMessage(UDM_SETBUDDY, TParam1(hBuddy)));
  }
  else {
    HWND oldBuddy = BuddyHandle;
    BuddyHandle = hBuddy;
    return oldBuddy;
  }
}

//
// Set the current position of the underlying up-down control. The return value
// is the previous position.
//
int32
TUpDown::SetPos(int pos)
{
  if (NativeUse & nuUsing) {
    return SendMessage(UDM_SETPOS, 0, MkParam2(pos, 0));
  }
  else {
    int32 oldPos = Pos;
    Pos = pos;
    if (GetStyle() & UDS_SETBUDDYINT)
      SetBuddyInt();
    return oldPos;
  }
}

//
// Set the minimum and maximum positions of the up-down control.
//
// NOTE: Neither 'lower' nor 'upper' can be greater than UD_MAXVAL or less than
//       UD_MINVAL. Futhermore, the difference between the two positions must
//       not exceed UD_MAXVAL;
//
void
TUpDown::SetRange(int lower, int upper)
{
  PRECONDITION(lower >= UD_MINVAL);
  PRECONDITION(upper >= UD_MINVAL);

#if defined(BI_PLAT_WIN32)
  // The following checks are implicit in 16-bit given the range of an int
  //
  PRECONDITION(lower <= UD_MAXVAL);
  PRECONDITION(upper <= UD_MAXVAL);
  PRECONDITION(abs(upper-lower) <= UD_MAXVAL);
#endif

  if (NativeUse & nuUsing) {
    SendMessage(UDM_SETRANGE, 0, MkParam2(upper, lower));
  }
  else {
    Lower = lower;
    Upper = upper;
  }
}

//
//
//
static void
poorPersonsArrows(TDC& dc, TRect& rect, bool sideways, bool incr, bool prssd) 
{
  TRect boxRect(rect);
  if (prssd)
    boxRect.Offset(1, 1);

  int bh = boxRect.Height();
  int bw = boxRect.Width();

  if (!sideways) {
    int ydelta = incr ? (bh*2/3) : (bh+2)/3;
    TPoint begPt = boxRect.TopLeft().OffsetBy((bw+1)/4, ydelta);
    TPoint endPt = begPt.OffsetBy((bw+1)/2, 0);
    while (begPt.x < endPt.x) {
      dc.MoveTo(begPt);
      dc.LineTo(endPt);
      begPt.Offset( 1, incr ? -1 : 1);
      endPt.Offset(-1, incr ? -1 : 1);
    }
  } 
  else {
    int xdelta = incr ? (bw+2)/3 : (bw*2/3);
    TPoint begPt = boxRect.TopLeft().OffsetBy(xdelta, (bh+1)/4);
    TPoint endPt = begPt.OffsetBy(0, (bh+1)/2);
    while (begPt.y < endPt.y) {
      dc.MoveTo(begPt);
      dc.LineTo(endPt);
      begPt.Offset(incr ? 1 : -1,  1);
      endPt.Offset(incr ? 1 : -1, -1);
    }
  }
}

//
// Handle WM_PAINT messages - Paint control based on the state of the latter.
//
// NOTE: We do not have to check for 'NativeUse' here since the virtual method
//       'Paint' is not called for predefined classes - i.e. it's not invoked
//       when we use the Native implementation..
//
void
TUpDown::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  // Paint 'increment' rectangle
  //
  TRect btnRect;
  GetSpinRect(btnRect, true);
  bool pressed = IsSet(csIncrement) && !IsSet(csMouseOut);

  // Draw button borders
  //
  TUIBorder(btnRect, pressed ? TUIBorder::ButtonDn : TUIBorder::ButtonUp, 
            TUIBorder::Fill).Paint(dc);

  // Draw arrows
  //
  poorPersonsArrows(dc, btnRect, GetStyle() & UDS_HORZ, true, pressed);

  // Paint 'decrement' rectangle
  //
  GetSpinRect(btnRect, false);
  pressed = IsSet(csDecrement) && !IsSet(csMouseOut);

  // Draw button borders
  //
  TUIBorder(btnRect, pressed ? TUIBorder::ButtonDn : TUIBorder::ButtonUp, 
            TUIBorder::Fill).Paint(dc);

  // Draw arrows
  //
  poorPersonsArrows(dc, btnRect, GetStyle() & UDS_HORZ, false, pressed);
}

//
// Override to initialize members when ObjectWindows provides the underlying
// implementation of the UpDown control.
//
void
TUpDown::SetupWindow()
{
  if (NativeUse & nuUsing)  {
    TControl::SetupWindow();
  }
  else {
    // Store away the handle to the buddy window
    //
    if (Buddy && Buddy->GetHandle())
      BuddyHandle = Buddy->GetHandle();

    // Validate buddy
    //
    if (!BuddyHandle || !::IsWindow(BuddyHandle)) {
      // Automatically pick previous window in Z-order as buddy
      //
      if (GetStyle() & UDS_AUTOBUDDY) {
        BuddyHandle = GetWindow(GW_HWNDPREV);
      }
    }

    // Handle alignment requirements
    //
    if (BuddyHandle && ::IsWindow(BuddyHandle)) {
      TRect budRect;
      ::GetWindowRect(BuddyHandle, &budRect);
      ::MapWindowPoints(HWND_DESKTOP, ::GetParent(BuddyHandle), 
                        LPPOINT(&budRect.left), 2);

      if (GetStyle() & UDS_ALIGNRIGHT) {
        SetWindowPos(0, budRect.right+1, budRect.top,0,0,
                     SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
      }
      else if (GetStyle() & UDS_ALIGNLEFT) {
        TRect udRect = GetWindowRect();
        SetWindowPos(0, budRect.left-(udRect.Width()+1), budRect.top,0,0,
                     SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOZORDER);
      }
    }

    // Don't erase background in EvEraseBkgnd, just do it in paint
    //
    SetBkgndColor(TColor::Transparent);
  }
}

//
// Handle WM_ENABLE messages to allow control to paint according to its current
// state..
//
void
TUpDown::EvEnable(bool enabled)
{
  if (NativeUse & nuUsing) {
    TControl::EvEnable(enabled);
  }
  else {
    // Update state of control
    //
    if (enabled)
      Clear(csGrayed);
    else
      Set(csGrayed);

    // Force a repaint
    //
    Invalidate();
    UpdateWindow();
  }
}

//
// Handle WM_SHOWWINDOW to keep track of the Window's visibility.
//
void
TUpDown::EvShowWindow(bool show, uint status)
{
  if (NativeUse & nuUsing) {
    TControl::EvShowWindow(show, status);
  }
  else {
    // Update state flags
    //
    if (show)
      Clear(csHidden);
    else
      Set(csHidden);
  }
}

//
// Handle WM_CANCELMODE messages to reset current processing.
//
void
TUpDown::EvCancelMode()
{
  if (NativeUse & nuUsing) {
    TControl::EvCancelMode();
  }
  else {

    // Clear action states
    //
    Clear(csIncrement|csDecrement|csMouseOut);
       
    // Release capture
    //
    if (GetCapture() == *this) {
      ReleaseCapture();
    }

    // Kill timers, clear timer flags
    //
    if (IsSet(csTimer1On)) {
      KillTimer(UpDownTimerID1);
    }
    if (IsSet(csTimer2On)) {
      KillTimer(UpDownTimerID2);
    }
    Clear(csTimer1On|csTimer2On);
  }
}

//
// Handle WM_TIMER messages to send periodic notifications
//
void
TUpDown::EvTimer(uint timerId)
{
  if (NativeUse & nuUsing) {
    TControl::EvTimer(timerId);
  }
  else {
    // Skip the first delayed timer and set-off the repeat one
    //
    if (timerId == UpDownTimerID1) {
      KillTimer(UpDownTimerID1);
      Clear(csTimer1On);

      SetTimer(UpDownTimerID2, RepeatDelay);
      Set(csTimer2On);
    }

    // We're now in repeat-mode
    //
    if (!IsSet(csMouseOut)) {
      Action();
    }
  }
}

//
// Handle WM_LBUTTONDOWN to process up/down scroll mouse requests
//
void
TUpDown::EvLButtonDown(uint modKeys, TPoint& point)
{
  if (NativeUse & nuUsing) {
    TControl::EvLButtonDown(modKeys, point);
  }
  else {
    if (GetCapture() != *this) {

      // Retrieve rectangle and side activated...
      //
      TRect btnRect;
      uint side = GetSpinRectFromPoint(btnRect, point);

      // Stop processing if we've hit the ceiling or the floor
      //
      if (!(GetStyle() & UDS_WRAP))
        if ((side == csIncrement && Pos == Upper) ||
            (side == csDecrement && Pos == Lower))
          return;

      // Update Flags
      //
      Set(side);
      Clear(csMouseOut);

      // Force repaint
      //
      InvalidateRect(btnRect);
      UpdateWindow();

      // Update our internal 'Pos' variable from the buddy if necessary
      //
      if (GetStyle() & UDS_SETBUDDYINT)
        GetBuddyInt();

      // Fire notifications
      //
      Action();

      // Hog mouse messages
      //
      SetCapture();

      // Set a first-crack/delayed timer
      //
      SetTimer(UpDownTimerID1, InitDelay);
      Set(csTimer1On);
    }
  }
}

//
// Handle WM_LBUTTONDBLCLK, which we handle just like a regular LBUTTONDOWN
//
void
TUpDown::EvLButtonDblClk(uint modKeys, TPoint& point)
{
  if (NativeUse & nuUsing) {
    TControl::EvLButtonDblClk(modKeys, point);
  }
  else {
    // For our purpose, a DoubleClick's just another click...
    //
    EvLButtonDown(modKeys, point);
  }
}

//
// Handle WM_LBUTTONUP to reset mouse down/dblclk processing
//
void
TUpDown::EvLButtonUp(uint modKeys, TPoint& point)
{
  if (NativeUse & nuUsing) {
    TControl::EvLButtonUp(modKeys, point);
  }
  else {
    // Kill timers, clear timer flags
    //
    if (IsSet(csTimer1On))
      KillTimer(UpDownTimerID1);

    if (IsSet(csTimer2On))
      KillTimer(UpDownTimerID2);

    Clear(csTimer1On|csTimer2On);

    // ReleaseCapture
    //
    if(GetCapture() == *this)
      ReleaseCapture();

    if (IsSet(csIncrement|csDecrement) && !IsSet(csMouseOut)) {

      // Retrieve rectangle of button
      //
      TRect rect;
      GetSpinRectFromState(rect);

      // Clear 'active' states
      //
      Clear(csIncrement|csDecrement|csMouseOut);

      // Force repaint of area
      //
      InvalidateRect(rect);
      UpdateWindow();
    }
    else {
      Clear(csIncrement|csDecrement|csMouseOut);
    }
  }
}

//
// Handle WM_MOUSEMOVE to monitor mouse location which processing mouse
// down/dblclk requests.
//
void
TUpDown::EvMouseMove(uint modKeys, TPoint& point)
{
  if (NativeUse & nuUsing) {
    TControl::EvMouseMove(modKeys, point);
  }
  else {
    // Check if we're in 'clicked' mode
    //
    if (IsSet(csIncrement) || IsSet(csDecrement)) {

      // Retrieve clicked/active rectangle
      //
      TRect rect;
      GetSpinRectFromState(rect);

      // Save the state bits
      //
      uint savedState = Bits;

      // Update state based on current cursor location
      //
      if (rect.Contains(point))
        Clear(csMouseOut);
      else
        Set(csMouseOut);

      // Invalidate if necessary
      //
      if (Bits != savedState) {
        InvalidateRect(rect);
        UpdateWindow();
      }
    }
  }
}

//
// Retrieve the rectangle of either 'up' or 'down' button
//
void
TUpDown::GetSpinRect(TRect& rect, bool incRect)
{
  // Start with client area
  //
  GetClientRect(rect);

  // Hit test based on style/requested side
  //
  if (GetStyle() & UDS_HORZ) {
    if (incRect)
      rect.left = rect.Width()/2;
    else
      rect.right = rect.Width()/2;
  }
  else {
    if (incRect)
      rect.bottom = rect.Height()/2;
    else
      rect.top += rect.Height()/2;
  }
}

//
// Retrieve the rectangle of the 'active' button based on the current state of
// the control.
//
void
TUpDown::GetSpinRectFromState(TRect& rect)
{
  if (IsSet(csIncrement)) {
    CHECK(!IsSet(csDecrement));
    GetSpinRect(rect, true);
  }
  else {
    CHECK(IsSet(csDecrement));
    GetSpinRect(rect, false);
  }
}

//
// Retrieves the rectangle of the 'active' button based on the location
// specified via 'pt'. Returns either 'csIncrement' or 'csDecrement' to
// indicate which area the point was in.
//
uint
TUpDown::GetSpinRectFromPoint(TRect& rect, const TPoint& pt)
{
  // Start with client area
  //
  GetClientRect(rect);

  uint side;

  // Hit test based on style/point location
  //
  if (GetStyle() & UDS_HORZ) {
    if (pt.x > rect.Width()/2) {
      rect.left = rect.Width()/2;
      side = csIncrement;
    }
    else {
      rect.right = rect.Width()/2 + 1;
      side = csDecrement;
    }
  }
  else {
    if (pt.y > rect.Height()/2) {
      rect.top += rect.Height()/2;
      side = csDecrement;
    }
    else {
      rect.bottom = rect.Height()/2 + 1;
      side = csIncrement;
    }
  }
  return side;
}

//
// Send UP or DOWN notifications
//
void
TUpDown::Action()
{
  // Compute delta based on flags
  //
  // NOTE: This method automatically handles 'wrapping' since it's *NOT* called
  //       if we've reached a rangeLimit and are not in 'wrap' mode.
  //
  int delta;
  if (IsSet(csIncrement)) {
    // Increment implies 'Pos' gravitates towards 'Upper'
    //
    if (Lower < Upper && Pos < Upper)
      delta = 1;
    else if (Lower > Upper && Pos > Upper)
      delta = -1;
    else if (Pos == Upper)
      delta = (Upper > Lower) ? (Lower - Upper) : (Upper - Lower);
  }
  else {
    // Decrement implies 'Pos' gravitates towards 'Lower'
    //
    if (Lower < Upper && Pos > Lower)
      delta = -1;
    else if (Lower > Upper && Pos < Lower)
      delta = 1;
    else if (Pos == Lower)
      delta = (Upper > Lower) ? (Upper - Lower) : (Lower - Upper);
  }

  // Send UDN_DELTAPOS notification to parent
  //
  TNmUpDown info(*this, Attr.Id, UDN_DELTAPOS, Pos, delta);
  if (Parent && Parent->GetHandle()) {

    // Stop if parent vetoed change
    //
    if (Parent->SendNotification(Attr.Id, info) != 0)
      return;
  }

  // Adjust position using delta (potentially modified by parent)
  //
  Pos += info.iDelta;

  // Handle Buddy
  //
  if (::IsWindow(BuddyHandle)) {

    // Set control's text
    //
    if (GetStyle() & UDS_SETBUDDYINT) {
      SetBuddyInt();
    }
    else {

      // Shoot notification to buddy
      //
      int code = IsSet(csIncrement) ? SB_LINEUP : SB_LINEDOWN;
      ::SendMessage(BuddyHandle, WM_VSCROLL, MAKELONG(code, Pos),
                    TParam2(GetHandle()));
    }
  }
}

//
// Update buddy's caption based on current position
//
void
TUpDown::SetBuddyInt() const
{
  PRECONDITION(GetStyle() & UDS_SETBUDDYINT);

  if (::IsWindow(BuddyHandle)) {
    // Make text out of pos
    //
    char txt1[20];
    char *pTxt = txt1;

    if (Base == 16)
      sprintf(txt1, "%X", Pos);
    else
      sprintf(txt1, "%d", Pos);

    // Put in commas, unless 'UDS_NOTHOUSANDS'
    //
    char txt2[20];

    if (!(GetStyle() & UDS_NOTHOUSANDS)) {
      // Don't bother if the string's len than 3 characters long
      //
      int len = strlen(txt1);
      if (len > 3) {
        int i = len % 3;
        char* p = txt2;
        for (int j = 0; j < len; j++) {
          if (j % 3 == i)
            *p++ = ',';
          *p++ = *pTxt++;
        }

        // Copy 0 terminator
        //
        *p = *pTxt;

        // Point to buffer with commas
        //
        pTxt = txt2;
      }
    }

    // Set text via 'WM_SETTEXT'...
    //
    ::SetWindowText(BuddyHandle, pTxt);
  }
}

//
// Retrieve current position from buddy's caption
//
void
TUpDown::GetBuddyInt()
{
  PRECONDITION(GetStyle() & UDS_SETBUDDYINT);

  if (::IsWindow(BuddyHandle)) {

    // Make text out of pos
    //
    char txt1[20];
    if (::GetWindowText(BuddyHandle, txt1, sizeof(txt1))) {

      // Strip commas
      //
      char txt2[20];
      char *src = txt1, *dst = txt2;
      do {
        if (*src != ',')
          *dst++ = *src;
      } while(*src++);

      // Validate & Update internal variable
      //
      long newPos = strtol(txt2, 0, Base == 16 ? 16 : 10);
      if (newPos && newPos >= Lower && newPos <= Upper)
        Pos = int(newPos);
    }
  }
}

#endif  //  !OWL_NATIVECTRL_ALWAYS
