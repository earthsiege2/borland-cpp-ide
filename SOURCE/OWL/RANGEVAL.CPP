//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\rangeval.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\validate.h>
#include <owl\applicat.h>
#include <classlib\objstrm.h>

#if !defined(SECTION) || SECTION == 1

//
// TRangeValidator
//


TRangeValidator::TRangeValidator(long min, long max)
  : TFilterValidator("0-9+-")
{
  if (min >= 0)
    ValidChars -= '-';
  Min = min;
  Max = max;
}

void
TRangeValidator::Error()
{
  char msg[81];
  wsprintf(msg, string(*GetApplicationObject(), IDS_VALNOTINRANGE).c_str(), Min, Max);
  ::MessageBox(0, msg, GetApplicationObject()->GetName(), 
    MB_ICONEXCLAMATION | MB_OK | MB_TASKMODAL);
}

BOOL
TRangeValidator::IsValid(const char far* s)
{
  if (TFilterValidator::IsValid(s)) {
    long value = atol(s);
    if (value >= Min && value <= Max)
      return TRUE;
  }
  return FALSE;
}

UINT
TRangeValidator::Transfer(char far* s, void* buffer, TTransferDirection direction)
{
  if (Options & voTransfer) {
    if (direction == tdGetData) {
      *(long*)buffer = atol(s);

    } else if (direction == tdSetData) {
      wsprintf(s, "%ld", *(long*)buffer);
    }
    return sizeof(long);

  } else
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
