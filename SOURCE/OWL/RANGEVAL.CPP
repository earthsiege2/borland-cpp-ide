//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TRangeValidator, integer numeric range input validator
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/validate.h>
#include <owl/applicat.h>
#include <owl/appdict.h>
#include <owl/framewin.h>

#if !defined(SECTION) || SECTION == 1

//
//
//
TRangeValidator::TRangeValidator(long min, long max)
:
  TFilterValidator("0-9+-")
{
  if (min >= 0)
    ValidChars -= '-';
  Min = min;
  Max = max;
}

void
TRangeValidator::Error()
{
  TApplication* app = GetApplicationObject();
  string msgTmpl = app->LoadString(IDS_VALNOTINRANGE).c_str();
  char* msg = new char[msgTmpl.length() + 10 + 10 + 1];
  wsprintf(msg, msgTmpl.c_str(), Min, Max);
  TWindow* w = GetWindowPtr(app->GetMainWindow()->GetLastActivePopup());
  if (w)
    w->MessageBox(msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK);
  else
    ::MessageBox(0, msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK|MB_TASKMODAL);
  delete [] msg;
}

bool
TRangeValidator::IsValid(const char far* s)
{
  if (TFilterValidator::IsValid(s)) {
    long value = atol(s);
    if (value >= Min && value <= Max)
      return true;
  }
  return false;
}

uint
TRangeValidator::Transfer(char far* s, void* buffer, TTransferDirection direction)
{
  if (Options & voTransfer) {
    if (direction == tdGetData) {
      *(long*)buffer = atol(s);
    }
    else if (direction == tdSetData) {
      wsprintf(s, "%ld", *(long*)buffer);
    }
    return sizeof(long);
  }
  else
    return 0;
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TRangeValidator, TFilterValidator);

void*
TRangeValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TFilterValidator*)GetObject(), is);
  is >> GetObject()->Min >> GetObject()->Max;
  return GetObject();
}

void
TRangeValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TFilterValidator*)GetObject(), os);
  os << GetObject()->Min << GetObject()->Max;
}

#endif
