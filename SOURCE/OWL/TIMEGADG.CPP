//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_TIMEGADG_H)
# include <owl/timegadg.h>
#endif
#if !defined(CLASSLIB_TIME_H)
# include <classlib/time.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>
#endif

OWL_DIAGINFO;

//
// Constructor for TTimeGadget.
//
TTimeGadget::TTimeGadget(TGetTimeFunc timeFunc, int id, TBorderStyle border,
                         TAlign align, uint numChars, const char* text,
                         TFont* font)
            :TTextGadget(id, border, align, numChars, text, font),
             TimeFunc(timeFunc)
{
  SetShrinkWrap(false, true);
}

//
// Overriden from TGadget to inform gadget window to setup a timer
//
void
TTimeGadget::Created()
{
  TGadget::Created();
  Window->EnableTimer();
}

//
// Overridden from TGadget to display the current time.
//
bool
TTimeGadget::IdleAction(long count)
{
  TGadget::IdleAction(count);

  string newTime;
  TimeFunc(newTime);
  SetText(newTime.c_str());

  // NOTE: Don't return true to drain system. Let GadgetWindow Timer
  //       message indirectly trigger IdleAction.
  //
  return false;
}

//
// Retrieve the current time.
//
void
TTimeGadget::GetTTime(string& newTime)
{
  TTime time;
  newTime = time.AsString();
}

//
// Win32 specific
//
#if defined(BI_PLAT_WIN32)

//
// Retrieve the system time using the Win32 API.
//
void
TTimeGadget::GetSystemTime(string& newTime)
{
  TAPointer<char> dateBuffer = new char[100];
  TAPointer<char> timeBuffer = new char[100];
  LCID lcid = ::GetUserDefaultLCID();
  SYSTEMTIME systemTime;
  ::GetSystemTime(&systemTime);

  if (::GetTimeFormat(lcid, LOCALE_NOUSEROVERRIDE, &systemTime, 0, timeBuffer, 100)) {
    if (::GetDateFormat(lcid, LOCALE_NOUSEROVERRIDE, &systemTime, 0, dateBuffer, 100)) {
      newTime += dateBuffer;
      newTime += " ";
      newTime += timeBuffer;
    }
  }
}


//
// Retrieve the local time using the Win32 API
//
void
TTimeGadget::GetLocalTime(string& newTime)
{
  TAPointer<char> dateBuffer = new char[100];
  TAPointer<char> timeBuffer = new char[100];
  LCID lcid = ::GetUserDefaultLCID();
  SYSTEMTIME systemTime;
  ::GetLocalTime(&systemTime);

  if (::GetTimeFormat(lcid, LOCALE_NOUSEROVERRIDE, &systemTime, 0, timeBuffer, 100)) {
    if (::GetDateFormat(lcid, LOCALE_NOUSEROVERRIDE, &systemTime, 0, dateBuffer, 100)) {
      newTime += dateBuffer;
      newTime += " ";
      newTime += timeBuffer;
    }
  }
}


#endif
