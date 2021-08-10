//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

//
// Empty constructor.
//
TUIPart::TUIPart()
{
}

//
// Draw the part onto a DC.
// The type and state control how the part should be painted.
//
bool
TUIPart::Paint(TDC& dc, TRect& rect, TType type, TState state)
{
  return DrawFrameControl(dc, rect, type, state);
}

//
// Wrapper for the DrawFrameControl API.
//
bool
TUIPart::DrawFrameControl(TDC& dc, TRect& rect, TType type, TState state)
{
#if defined(BI_PLAT_WIN32)
  static bool hasDrawFrameControl = true;

  // Try once to see if the API call is available. If not, do ourselves.
  //
  if (hasDrawFrameControl) {
    if (::DrawFrameControl(dc, &rect, type, state))
      return true;
    if (::GetLastError() == ERROR_CALL_NOT_IMPLEMENTED)
      hasDrawFrameControl = false;
    else
      return false;
  }
#endif

  //
  return false;
}

