//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\filtval.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\validate.h>
#include <owl\applicat.h>
#include <classlib\objstrm.h>

#if !defined(SECTION) || SECTION == 1


TFilterValidator::TFilterValidator(const TCharSet& validChars)
  : TValidator()
{
  ValidChars = validChars;
}

BOOL
TFilterValidator::IsValidInput(char far* str, BOOL /*suppressFill*/)
{
  for (const char far* p = str; *p; p++)
    if (!ValidChars.Has(*p))
      return FALSE;
  return TRUE;
}

BOOL
TFilterValidator::IsValid(const char far* str)
{
  for (const char far* p = str; *p; p++)
    if (!ValidChars.Has(*p))
      return FALSE;
  return TRUE;
}

void
TFilterValidator::Error()
{
  ::MessageBox(0, string(*GetApplicationObject(), IDS_VALINVALIDCHAR).c_str(),
             GetApplicationObject()->GetName(),
             MB_ICONEXCLAMATION | MB_OK | MB_TASKMODAL);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TFilterValidator, TValidator);

void*
TFilterValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TValidator*)GetObject(), is);
  is >> GetObject()->ValidChars;
  return GetObject();
}

void
TFilterValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TValidator*)GetObject(), os);
  os << GetObject()->ValidChars;
}

#endif


