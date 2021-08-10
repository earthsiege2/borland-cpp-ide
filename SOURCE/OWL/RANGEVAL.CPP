//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of TRangeValidator, integer numeric range input validator
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#include <stdio.h>

OWL_DIAGINFO;

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

//
//
//
void
TRangeValidator::Error(TWindow* owner)
{
  PRECONDITION(owner);
  TApplication* app = owner->GetApplication();
  string msgTmpl = app->LoadString(IDS_VALNOTINRANGE);
  TAPointer<char> msg = new char[msgTmpl.length() + 10 + 10 + 1];
  sprintf(msg, msgTmpl.c_str(), Min, Max);
  owner->MessageBox(msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK);
}

//
//
//
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

//
//
//
uint
TRangeValidator::Transfer(char far* s, void* buffer, TTransferDirection direction)
{
  if (Options & voTransfer) {
    if (direction == tdGetData) {
      *(long*)buffer = atol(s);
    }
    else if (direction == tdSetData) {
      wsprintf(s, "%ld", *(long*)buffer);  // need wsprintf for char far*
    }
    return sizeof(long);
  }
  else
    return 0;
}

//
// Adjust the 'value' of the text, given a cursor position & an amount
// Return the actual amount adjusted.
//
int
TRangeValidator::Adjust(string& text, uint& /*begPos*/, uint& /*endPos*/, int amount)
{
  long value = atol(text.c_str());
  long newValue = value + amount;
  if (newValue < Min)
    newValue = Min;
  else if (newValue > Max)
    newValue = Max;

  char buffer[15];
  sprintf(buffer, "%ld", newValue);
  text = buffer;

  return int(newValue - value);
}


#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TRangeValidator, TFilterValidator);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TRangeValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TFilterValidator*)GetObject(), is);
  is >> GetObject()->Min >> GetObject()->Max;
  return GetObject();
}

//
//
//
void
TRangeValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TFilterValidator*)GetObject(), os);
  os << GetObject()->Min << GetObject()->Max;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
