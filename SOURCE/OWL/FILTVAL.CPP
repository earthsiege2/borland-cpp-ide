//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/validate.h>
#include <owl/applicat.h>
#include <owl/appdict.h>
#include <owl/framewin.h>

#if !defined(SECTION) || SECTION == 1


TFilterValidator::TFilterValidator(const TCharSet& validChars)
:
  TValidator()
{
  ValidChars = validChars;
}

bool
TFilterValidator::IsValidInput(char far* str, bool /*suppressFill*/)
{
  for (const char far* p = str; *p; p++)
    if (!ValidChars.Has(*p))
      return false;
  return true;
}

bool
TFilterValidator::IsValid(const char far* str)
{
  for (const char far* p = str; *p; p++)
    if (!ValidChars.Has(*p))
      return false;
  return true;
}

void
TFilterValidator::Error()
{
  TApplication* app = GetApplicationObject();
  string msg = app->LoadString(IDS_VALINVALIDCHAR);
  TWindow* w = GetWindowPtr(app->GetMainWindow()->GetLastActivePopup());
  if (w)
    w->MessageBox(msg.c_str(), app->GetName(), MB_ICONEXCLAMATION|MB_OK);
  else
    ::MessageBox(0, msg.c_str(), app->GetName(), MB_ICONEXCLAMATION|MB_OK|MB_TASKMODAL);
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


