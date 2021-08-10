//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.31  $
//
// Implements the TTooltip class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_TOOLTIP_H)
# include <owl/tooltip.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(WINSYS_UIMETRIC_H)
# include <winsys/uimetric.h>
#endif


OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlControl);        // General Controls diagnostic group

//
// Size of container of tools
//
const int InitSize = 5;               // Initial size of tool container
const int InitDelta= 5;               // Inc/Dec of tools container
const int DefDelay = 500;             // Default delay is 1/2 second
const int HorzPad  = 4;               // Side pads around text of tooltip
const int VertPad  = 2;               // Top/Down pads around text of tooltip
const int DefTipTextCacheSize = 128;  // Default cache size of tip text

//
// Timer id used by Tooltip window
//
const unsigned TOOLTIP_TIMERID = 0xABBA;

//
// Default constructor of TToolInfo - used mainly when retrieving
// information about the current tool of the tooltip control or
// for initializing a brand new tool to be registered with the
// control. For example,
//
//              TToolInfo ti(true);
//              tooltip.GetCurrentTool(ti);
//
TToolInfo::TToolInfo(bool allocCache)
{
  memset(this, 0, sizeof(TOOLINFO));
  cbSize = sizeof(TOOLINFO);
  if (allocCache) {
    CacheText = new char[DefTipTextCacheSize];
    lpszText = (char*)CacheText;
  }
}

//
// Constructor for tool implemented as rectangular area within
// a window's client area. 'window' receives the 'TTN_NEEDTEXT'
// notification in case of txt default to LPSTR_TEXTCALLBACK.
//
TToolInfo::TToolInfo(HWND window, const TRect& rc, uint toolId,
                     const char* txt /*=LPSTR_TEXTCALLBACK*/)
{
  memset(this, 0, sizeof(TOOLINFO));
  cbSize = sizeof(TOOLINFO);
  SetToolInfo(window, toolId);
  SetRect(rc);
#if defined(BI_PLAT_WIN32)

  // NOTE: When we're using the Common Control implementation we don't want
  //       to cache the text since we won't keep a copy of the TToolInfo
  //       structure around.
  //
  SetText(txt, false);
#elif defined(BI_PLAT_WIN16)
  SetText(txt, true);
#endif
}

//
// Constructor for tool implemented as rectangular area within
// a window's client area. 'strRes' and 'hInst' specify a string
// resource of the message to be used by the tooltip window.
//
TToolInfo::TToolInfo(HWND window, const TRect& rc, uint toolId,
                     int strRes, HINSTANCE hInst)
{
  memset(this, 0, sizeof(TOOLINFO));
  cbSize = sizeof(TOOLINFO);
  SetToolInfo(window, toolId, rc);
  SetText(strRes, hInst);
}

//
// Constructor for tool implemented as windows (eg. child/controls).
// 'parent' receives the 'TTN_NEEDTEXT' notification in case of
// 'txt' defaults to the LPSTR_TEXTCALLBACK.
//
TToolInfo::TToolInfo(HWND parent, HWND toolWnd,
                     const char* txt /*=LPSTR_TEXTCALLBACK*/)
{
  memset(this, 0, sizeof(TOOLINFO));
  cbSize = sizeof(TOOLINFO);
  SetToolInfo(toolWnd, parent);
#if defined(BI_PLAT_WIN32)
  SetText(txt, false);
#elif defined(BI_PLAT_WIN16)
  SetText(txt, true);
#endif
}

//
// Constructor for tool implemented as a window (child/control).
// 'strRes' and 'hInst' specify a string resource to be used by
// the tooltip window.
//
TToolInfo::TToolInfo(HWND parent, HWND toolWnd,
                     int strRes, HINSTANCE hInst)
{
  memset(this, 0, sizeof(TOOLINFO));
  cbSize = sizeof(TOOLINFO);
  SetToolInfo(toolWnd, parent);
  SetText(strRes, hInst);
}

//
//
//
TToolInfo::TToolInfo(const TToolInfo& other)
{
  // Use assignment operator
  //
  *this = other;
}

//
//
//
TToolInfo&
TToolInfo::operator =(const TToolInfo& other)
{
  if (&other != this) {
    *((TOOLINFO*)this) = *((TOOLINFO*)&other);
    if (other.lpszText == other.GetCacheText())
      SetText(other.GetCacheText());
    /***
    else
     'other.lpszText' is assumed to be NULL, LPSTR_CALLBACK or pointing
      to a buffer with a long lifetime. In all three cases a shallow copy of
      the pointer is safe.
    ***/
  }
  return *this;
}

//
//
//
void
TToolInfo::SetToolInfo(HWND toolWin, uint id)
{
  PRECONDITION(::IsWindow(toolWin));
  hwnd = toolWin;
  uFlags &= ~TTF_IDISHWND;
  uId = id;
}

//
//
//
void
TToolInfo::SetToolInfo(HWND toolWin, uint id, const TRect& rc)
{
  SetToolInfo(toolWin, id);
  SetRect(rc);
}

//
//
//
void
TToolInfo::SetToolInfo(HWND toolWin, HWND parent)
{
  PRECONDITION(::IsWindow(toolWin));
  PRECONDITION(::IsWindow(parent));
  hwnd = parent;
  uFlags |= TTF_IDISHWND;
  uId = uint(toolWin);
}

//
// Sets the text of this tool by providing a buffer that contains
// the string. The boolean 'copy' flag specifies whether the method
// should make a local copy of the string.
//
void
TToolInfo::SetText(const char* text, bool copy)
{
  if (text == LPSTR_TEXTCALLBACK || !text || !copy) {
    lpszText = (char*)text;
    CacheText= 0;
  }
  else {
    CacheText = strnewdup(text);
    lpszText = (char*)CacheText;
  }
}

//
// This method returns the actual HWND linked to a tool. For tools
// implemented as a rectangle within a client area, the window's
// handle is returned. For tools associated with a control, the handle
// of the control is returned.
//
HWND
TToolInfo::GetToolWindow() const
{
  return (uFlags & TTF_IDISHWND) ? HWND(uId) : hwnd;
}

//
// This method retrieves the actual RECT  linked to a tool. For tools
// implemented as a rectangle within a client area, that rectangle
// is retrieved. For tools associated with a control, the latter's client
// area is retrieved.
//
void
TToolInfo::GetToolRect(TRect& rc) const
{
  if (uFlags & TTF_IDISHWND) {
    CHECK(::IsWindow(HWND(uId)));
    ::GetClientRect(HWND(uId), &rc);
  }
  else {
    rc = rect;
  }
}

//
// This method determines whether a particular location of a window is
// relevant to this tool. For tools implemented as a rectangle within
// a window's client area, we simply check that 'pt' is within that
// rectangle. For tools representing a child window, we check that
// 'pt' is within the client area of the child window.
// NOTE: 'pt' must be relative to the window's client area...
// Returns true if succesful or false otherwise.
//
bool
TToolInfo::IsPointInTool(HWND win, const TPoint& pt) const
{
  HWND window = GetToolWindow();
  if (window == win) {
    TRect rc;
    GetToolRect(rc);
    if (rc.Contains(pt))
      return true;
  }
  return false;
}

//----------------------------------------------------------------------------
// TTooltipText
//

//
// Sets text of tooltip to specified buffer.
// NOTE: The buffer pointed to by the specified parameter must be
//       valid for as long as the TTooltipText points to it.
//       For temporary buffers, use the 'CopyText' method instead.
//
void
TTooltipText::SetText(char* buff)
{
  lpszText = buff;
}

//
// Sets the text of the tooltip. The text is copied into the
// buffer owned by the 'TTooltipText'.
//
void
TTooltipText::CopyText(const char* text)
{
  strncpy(szText, text, sizeof(szText));
}

//
// Sets the text of the tooltip. The 'resId' identifies a string resource
// found in the module pointed to by the 'hInstance' parameter.
//
void
TTooltipText::SetText(int resId, HINSTANCE hInstance)
{
  lpszText = CONST_CAST(char far*, MAKEINTRESOURCE(resId));
  hinst = hInstance;
}

//----------------------------------------------------------------------------
// TTooltipEnabler
//

//
// Construct enabler object to be sent to a window so that the latter
// can provide the text of the specified tool.
//
TTooltipEnabler::TTooltipEnabler(TTooltipText& tt, HWND hReceiver)
:
  TCommandEnabler(tt.hdr.idFrom, hReceiver),
  TipText(tt)
{
}

//
// Sets the text of the tool specified by the TTooltipEnabler object.
// NOTE: The text is copied to the TTooltopText structure.
//
void
TTooltipEnabler::SetText(const char far* text)
{
  TipText.CopyText(text);
}

//
// Place-holder function - Does nothing...
//
void
TTooltipEnabler::SetCheck(int /*check*/)
{
}

//----------------------------------------------------------------------------
// TTooltip
//

//
// Constructor for TTooltip
//
// Initializes its data fields using parameters passed and default values
//
// By default, a Tooltip associated with the TTooltip will:
//   - be active regardless of whether its owner is active or inactive
//
TTooltip::TTooltip(TWindow* parent, bool alwaysTip, TModule* module)
         :TControl(parent, 0, "", 0, 0, 0, 0, module)
{
  Attr.Style = (WS_POPUP | WS_DISABLED);


  if (alwaysTip)
    Attr.Style |= TTS_ALWAYSTIP;

#if defined(BI_PLAT_WIN16)

  Attr.Style |= WS_BORDER;

#elif defined(BI_PLAT_WIN32)

  if (TSystem::Has3dUI())
    Attr.ExStyle |= WS_EX_WINDOWEDGE;
  else
    Attr.Style |= WS_BORDER;

#endif

  Attr.ExStyle |= WS_EX_TOPMOST;

  // Use Native implementation if available
  //
  NativeUse = TCommCtrl::IsAvailable() ? nuAlways : nuNever;

#if defined(BI_PLAT_WIN16)

  // When running in an environment where the system does not provide
  // Common Controls we need to initialize the variables used for
  // emulating a tabcontrol...
  //
  Init();

#elif defined(BI_PLAT_WIN32)

  // For 32-bit platforms we rely on the Common Control Library
  //
  CHECK(TCommCtrl::IsAvailable());
#endif
}

#if defined(BI_PLAT_WIN32)
//
// Constructor to alias a non-OWL TOOLTIP control. Specially useful when
// used with controls that automatically create a tooltip (eg TabControls
// with TCS_TOOLTIPS style).
//
TTooltip::TTooltip(THandle handle, TModule* module)
:
  TControl(handle, module)
{
  PRECONDITION(handle);
  CHECK(TCommCtrl::IsAvailable());
}
#endif

//
// Destructor of TTooltip class.
//
TTooltip::~TTooltip()
{
#if defined(BI_PLAT_WIN16)
  Cleanup();
#endif
}

//
// Returns the native class of the tooltip control or the class
// implementing OWL's version of tooltips.
//
char far*
TTooltip::GetClassName()
{
#if defined(BI_PLAT_WIN32)

  PRECONDITION(TCommCtrl::IsAvailable());
  return TOOLTIPS_CLASS;

#elif defined(BI_PLAT_WIN16)

  // OWL implements tooltips in 16-bit
  //
  return "OWL_Tooltip";
#endif
}

//----------------------------------------------------------------------------
// The following is only relevant if the 'TTooltip' object needs to be
// flexible and support cases where the OS does not provide the underlying
// implementation of TOOLTIPS.
//
#if defined(BI_PLAT_WIN16)

//
// Message Response Table of TTooltip...
//
DEFINE_RESPONSE_TABLE1(TTooltip, TControl)
  EV_WM_TIMER,
  EV_WM_SETTEXT,
  EV_WM_SETFONT,
  EV_WM_GETFONT,
  EV_WM_LBUTTONDOWN,
  EV_WM_RBUTTONDOWN,
END_RESPONSE_TABLE;

//
// Activates or deactivates the tooltip control. If 'activate' is true,
// the tooltip control is activated, If it is false the tooltip control
// is deactivated.
//
void
TTooltip::Activate(bool activate)
{
  Active = activate;
}

//
// Registers a tool with the tooltip control. The 'TToolInfo' parameter
// contains information that the tooltip control needs to display text
// for the tool.
// NOTE: This method does not check for duplicate tool ids!
//
bool
TTooltip::AddTool(const TToolInfo& ti)
{
  ToolList->Append(new TToolInfo(ti));
  return true;
}

//
// Removes a tool from the tooltip control. You must invoke the
// 'SetToolInfo' method of TToolInfo to identify the tool to remove.
// [i.e. the 'hwnd' or 'uId' members of the TToolInfo must identify the tool].
//
void
TTooltip::DeleteTool(const TToolInfo& ti)
{
  // Make sure we don't hang on to a dangling pointer
  //
  if (&ti == ActiveTool)
    ActiveTool = 0;
  if (&ti == PotentialTool)
    PotentialTool = 0;

  int i;
  for (i=0; i<ToolList->GetCount(); i++) {
    if ((*ToolList)[i] == ti) {
      ToolList->FreeAt(i);
      break;
    }
  }
  WARNX(OwlControl, i==ToolList->GetCount(), 0, "Unable to delete tool");
}

//
// Retrieves the information that the tooltip control maintains
// about the specified tool. Returns true if successul or false otherwise.
// NOTE: The index is zero-based and the TToolInfo structure receives
//       the information about the tool.
//
bool
TTooltip::EnumTools(uint index, TToolInfo& ti) const
{
  if (index < ToolList->GetCount()) {
    ti = (TToolInfo&)((*ToolList)[index]);
    return true;
  }
  TRACEX(OwlControl, 0, "EnumTools: Invalid index specified");
  return false;
}

//
// Retrieves information about the current tool. The 'TToolInfo'
// parameter receives the information. Returns true if successful or
// false otherwise.
//
bool
TTooltip::GetCurrentTool(TToolInfo& /*ti*/) const
{
  TRACEX(OwlControl, 0, "TTooltip::GetCurrentTool requires system "\
                        "implementation of tooltips");
  return false;
}

//
// Retrieves the text associated with the specified tool. You must
// invoke the 'SetToolInfo' of the TToolInfo object to identify the tool.
// [i.e. the 'hwnd' or 'uId' members of the TToolInfo must identify the tool].
//
void
TTooltip::GetToolText(TToolInfo& ti) const
{
  int i;
  for (i=0; i<ToolList->GetCount(); i++) {
    if ((*ToolList)[i] == ti) {
      ti.lpszText = ((*ToolList)[i]).lpszText;
      break;
    }
  }
  WARNX(OwlControl, i==ToolList->GetCount(), 0, "Tool text not found");
}

//
// Returns the number of tools currently registered with the
// tooltip control.
//
uint
TTooltip::GetToolCount() const
{
  return ToolList->GetCount();
}

//
// Retrieves the information that the tooltip control maintains about
// a tool. You must invoke the 'SetToolInfo' of TToolInfo object to identify
// the tool. [i.e. the 'hwnd' or 'uId' members of the TToolInfo must
// identify the tool].
//
bool
TTooltip::GetToolInfo(TToolInfo& ti) const
{
  for (int i=0; i<ToolList->GetCount(); i++) {
    if ((*ToolList)[i] == ti) {
      ti = (TToolInfo&)((*ToolList)[i]);
      return true;
    }
  }
  TRACEX(OwlControl, 0, "GetToolInfo: tool not found");
  return false;
}

//
// Sets the information that the tooltip control maintains for a
// particular tool. You must invoke the 'SetToolInfo' of the ToolInfo object
// to identify the tool.
//
void
TTooltip::SetToolInfo(const TToolInfo& ti)
{
  for (int i=0; i<ToolList->GetCount(); i++) {
    if ((*ToolList)[i] == ti) {
      (*ToolList)[i] = ti;
      return;
    }
  }
  TRACEX(OwlControl, 0, "SetToolInfo: tool not found");
}

//
// Sets the text of a tool. You must invoke the 'SetToolInfo' method of
// TToolInfo to identify the tool being referred to.
//
void
TTooltip::UpdateTipText(const TToolInfo& ti)
{
  for (int i=0; i<ToolList->GetCount(); i++) {
    if ((*ToolList)[i] == ti) {
      (*ToolList)[i] = ti;
      return;
    }
  }
  TRACEX(OwlControl, 0, "UpdateTipText: tool not found");
}

//
// Determines whether a tool is within a specified point. The method
// also retrieves information about the tool if one is identified at
// that location. Returns true if a tool if found at the location or
// false otherwise.
//
bool
TTooltip::HitTest(TTooltipHitTestInfo& /*ttHTInfo*/) const
{
  TRACEX(OwlControl, 0, "TTooltip::HitTest requires native "\
                        "implementation of tooltips");
  return false;
}

//
// Updates the bounding rectangle of a tool. You must invoke the 'SetToolId'
// method of TToolInfo to identify the tool. [i.e. the 'uId' member
// of the TToolInfo must identify the tool].
//
void
TTooltip::NewToolRect(const TToolInfo& ti)
{
  for (int i=0; i<ToolList->GetCount(); i++) {
    if ((*ToolList)[i] == ti) {
      (*ToolList)[i].rect = ti.rect;
      return;
    }
  }
  TRACEX(OwlControl, 0, "NewToolRect: tool not found");
}

//
// Passes a mouse message to the tooltip control for processing.
//
void
TTooltip::RelayEvent(MSG& msg)
{
  if (Active) {

    // Filter messages and pass on interesting ones...
    //
    switch(msg.message) {

      case WM_MOUSEMOVE:
      case WM_LBUTTONDOWN:
      case WM_LBUTTONUP:
      case WM_MBUTTONDOWN:
      case WM_MBUTTONUP:
      case WM_RBUTTONDOWN:
      case WM_RBUTTONUP: {
          // Compute mouse location
          //
          TPoint pt(LOWORD(msg.lParam), HIWORD(msg.lParam));

          // Relay the event
          //
          RelayEvent(msg.hwnd, msg.message, pt);
        }
        break;

      default:
        break;
    }
  }
}

//
// Sets the initial, reshow and autopopup durations for a tooltip
// control. The 'flag' parameter can be one of the following:
//      TTDT_AUTOMATIC: Automatically calculates the initial. reshow
//                      and autopopup duration based on 'delay'.
//      TTDT_AUTOPOP:   Sets the length of time before the tooltip
//                      window is hidden if the cursor remains
//                      stationary in the tool's bounding rectangle
//                      after the tooltip window has disappeared.
//      TTDT_INITIAL:   Set the length of time that the cursor must
//                      remain stationary within the bounding rectangle
//                      before the tooltip window is displayed.
//      TTDT_RESHOW:    Set the length of time before subsequent tooltip
//                      windows are displayed when the cursor is moved
//                      from one tool to another.
//
// NOTE: The 'delay' duration is in milliseconds.
//
void
TTooltip::SetDelayTime(WPARAM /*flag*/, int delay)
{
  Delay = delay;

  // Restart timer if one's enabled
  //
  if (TimerEnabled) {
    DisableTimer();
    EnableTimer();
  }

  // 'flag' is ignored when ObjectWindows provides underlying
  // implementation of tooltips..
  //
  TRACEX(OwlControl, 0, "TTooltip::SetDelayTime: flag is ignored");

}

//----------------------------------------------------------------------------
// Helper routines used by ObjectWindows' implementation of Tooltips
//

//
// Initialize internal variables
//
void
TTooltip::Init()
{
  Active = true;
  TimerEnabled = false;
  Delay = DefDelay;
  ToolFont = 0;
  ToolList = 0;
  ActiveTool = 0;
  PotentialTool = 0;
}

//
// Cleanup internal variables
//
void
TTooltip::Cleanup()
{
  delete ToolList;
  delete ToolFont;
}

//
// Update the CLASSINFO to be registered to include SAVEBITS and
// a NUL brush.
//
void
TTooltip::GetWindowClass(WNDCLASS& wndClass)
{
  TControl::GetWindowClass(wndClass);
  wndClass.style = CS_HREDRAW|CS_VREDRAW|CS_SAVEBITS;
  wndClass.hbrBackground = 0;
}

//
// Overriden to initialize internal variables when providing
// underlying implementation of tooltips.
//
void
TTooltip::SetupWindow()
{
  TControl::SetupWindow();

  // Initialize helper objects used by OWL's implementation
  //
  SetBkgndColor(TColor::Transparent);
  ToolFont = new TFont("MS Sans Serif", -9);
  ToolList = new TCollection<TToolInfo>(InitSize, InitDelta);
}

//
// Overriden to cleanup internal variables when providing
// underlying implementation of tooltips.
//
void
TTooltip::CleanupWindow()
{
  TControl::CleanupWindow();

  // Cleanup any pending timers
  //
  DisableTimer();
}

//
// WM_PAINT Handler: displays tip if we have an active tool
//
void
TTooltip::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  if (ActiveTool) {
    TRect rcClient;
    GetClientRect(rcClient);

    TColor bkgColor = TColor::SysInfoBk;
    TColor txtColor = TColor::SysInfoText;

    // Set up background/colours etc..
    //
    TBrush bkBrush(bkgColor);
    dc.FillRect(rcClient, bkBrush);
    dc.SetTextColor(txtColor);
    dc.SetBkMode(TRANSPARENT);

    // Draw text
    //
    dc.SelectObject(*ToolFont);
    dc.DrawText(ActiveTool->GetCacheText(), -1, rcClient,
                DT_CENTER|DT_SINGLELINE|DT_VCENTER);
    dc.RestoreFont();
  }
}

//
// Sets on a timer and updates the state variable
//
void
TTooltip::EnableTimer()
{
  // Set on the timer if not already set
  //
  if (!TimerEnabled) {
    SetTimer(TOOLTIP_TIMERID, Delay);
    TimerEnabled = true;
  }
}

//
// Kills the timer if it was enabled
//
void
TTooltip::DisableTimer()
{
  if (TimerEnabled) {
    KillTimer(TOOLTIP_TIMERID);
    TimerEnabled = false;
  }
}

//
// WM_TIMER Handler: Display a tip if the appropriate timeout has
//                   occur for a tool.
//
void
TTooltip::EvTimer(uint timerId)
{
  // Check for out timerID - just in case
  //
  if (timerId == TOOLTIP_TIMERID) {

    // Retrieve current location of cursor
    //
    TPoint curLoc;
    GetCursorPos(curLoc);

    // If we've been waiting on a tool, check & tip it
    //
    if (!ActiveTool) {
      if (PotentialTool) {
        if (curLoc == MouseLoc) {
          // Update tool pointers
          //
          ActiveTool = PotentialTool;
          PotentialTool = 0;
          ShowActiveTip(curLoc);
        }
      }
    }
    else {
      // Check if mouse is still within the ActiveTool and hide tip if not
      //
      HWND hwnd = WindowFromPoint(curLoc);
      if (hwnd)
        ::MapWindowPoints(HWND_DESKTOP, hwnd, LPPOINT(&curLoc), 1);
      if (!ActiveTool->IsPointInTool(hwnd, curLoc)) {
        ActiveTool = 0;
        HideActiveTip();
      }
    }
  }
}

//
// WM_GETFONT Handler: Return font used by tooltip
//
HFONT
TTooltip::EvGetFont()
{
  HFONT hFont = (ToolFont && HFONT(*ToolFont)) ? HFONT(*ToolFont) :
                HFONT(GetStockObject(ANSI_VAR_FONT));
  return hFont;
}

//
// WM_SETFONT Handler: Sets a new font to be used by handler
//
void
TTooltip::EvSetFont(HFONT hFont, bool /*redraw*/)
{
  delete ToolFont;
  ToolFont = hFont ? new TFont(hFont) : (TFont*)0;

  //
  //
  // if (redraw)
  //   Invalidate();
}

//
// WM_LBUTTONDOWN handler
//
void
TTooltip::EvLButtonDown(uint /*modKeys*/, TPoint& /*point*/)
{
  // NOP
}

//
// WM_RBUTTONDOWN handler
//
void
TTooltip::EvRButtonDown(uint /*modKeys*/, TPoint& /*point*/)
{
  // NOP
}


//
// Checked relayed event and filter the ones that matter to the
// tooltip.
//
void
TTooltip::RelayEvent(HWND receiver, uint msg, const TPoint& pt)
{
  // If there's a current active tool, validate it based on the current event.
  // Hide and reset the current active tool if necessary.
  //
  if (ActiveTool) {
    if (!ActiveTool->IsPointInTool(receiver, pt)) {
      ActiveTool = 0;
      HideActiveTip();
    }
  }

  // If there are no current active tools, validate any 'pending' tool or look
  // for a new 'pending' tool.
  //
  if (!ActiveTool && msg == WM_MOUSEMOVE) {
    if (!PotentialTool || !PotentialTool->IsPointInTool(receiver, pt)) {

      // Reset the 'pending' tool pointer and stop the timer
      //
      PotentialTool = 0;
      DisableTimer();

      // Scan for a new tool, if found, save the current mouse location and
      // restart the timer.
      //
      for (int i=0; i<ToolList->GetCount(); i++) {
        TToolInfo& tool = (*ToolList)[i];
        if (tool.IsPointInTool(receiver, pt)) {
          PotentialTool = &tool;
          EnableTimer();
          break;
        }
      }
    }
  }

  // If we have a potential tool but no active tool, update the mouse location
  //
  if (!ActiveTool && PotentialTool)
    GetCursorPos(MouseLoc);

  // Kill the timer if we have neither a potential nor active tool
  //
  if (!PotentialTool && !ActiveTool)
    DisableTimer();
}

//
// Displays the tip of the current tool at the specified location, if we
// have the hint text.
//
void
TTooltip::ShowActiveTip(TPoint& pt)
{
  PRECONDITION(ActiveTool);

  char* tipText   = 0;
  HINSTANCE hInst = 0;
  uint strResId   = 0;
  TTooltipText ttText;

  // Retrieve text if necessary
  //
  if (ActiveTool->lpszText == LPSTR_TEXTCALLBACK) {
    CHECK(::IsWindow(ActiveTool->hwnd));

    memset(&ttText, 0, sizeof(ttText));
    ttText.hdr.hwndFrom = GetHandle();
    ttText.hdr.idFrom = ActiveTool->uId;
    ttText.hdr.code = TTN_NEEDTEXT;
    ttText.uFlags = ActiveTool->uFlags;
    ::SendMessage(ActiveTool->hwnd, WM_NOTIFY, WPARAM(ActiveTool->uId),
                  LPARAM(&ttText));

    // Check if text is being provided via a resource
    // NOTE: Non null 'hinst' implies 'lpszText' is a string resource
    //       identifier.
    //
    if (ttText.hinst && ttText.lpszText) {
      hInst = ttText.hinst;
      strResId = LOWORD(ttText.lpszText);
    }
    else if (ttText.szText[0]) {
      tipText = ttText.szText;
    }
    else if (ttText.lpszText) {
      tipText = ttText.lpszText;
    }
  }
  else if (ActiveTool->hinst && ActiveTool->lpszText) {
    hInst = ActiveTool->hinst;
    strResId = LOWORD(ActiveTool->lpszText);
  }

  // Load string from resource, if necessary
  //
  if (hInst && strResId) {
    if (LoadString(hInst, strResId, ttText.szText, sizeof(ttText.szText)))
      tipText = ttText.szText;
  }

  // If we don't have any text, abort operation
  //
  if (!tipText && !ActiveTool->GetCacheText())
    return;

  // Cache newly retrieve tip text
  //
  if (tipText)
    ActiveTool->SetText(tipText);

  // Now that we've cached the text, compute the size of the display
  //
  TSize size; {
    TClientDC dc(*this);
    dc.SelectObject(*ToolFont);
    dc.GetTextExtent(ActiveTool->GetCacheText(),
                     strlen(ActiveTool->GetCacheText()),
                     size);
    dc.RestoreFont();
  }

  // Add some padding - position tip...
  //
  size.cx += HorzPad*2;
  size.cy += VertPad*2;
  if (pt.y + size.cy + TUIMetric::CyMenu < TUIMetric::CyScreen)
    pt.y += TUIMetric::CyMenu;
  else
    pt.y -= TUIMetric::CyMenu;
  if (pt.x + size.cx > TUIMetric::CxScreen)
    pt.x = TUIMetric::CxScreen - size.cx;

  // Move & Display tip...
  //
  TRect rcLoc(pt, size);
  SetWindowPos(HWND_TOPMOST, rcLoc, SWP_NOACTIVATE|SWP_SHOWWINDOW);
  UpdateWindow();
}

//
// Hides the tooltip window
//
void
TTooltip::HideActiveTip()
{
  // Hide tooltip window
  //
  ShowWindow(SW_HIDE);
}

#endif  //  BI_PLAT_WIN16
