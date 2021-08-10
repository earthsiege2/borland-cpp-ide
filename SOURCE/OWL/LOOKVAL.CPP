//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\lookval.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\validate.h>
#include <owl\applicat.h>
#include <classlib\objstrm.h>

#if !defined(SECTION) || SECTION == 1

//
// TLookupValidator
//

TLookupValidator::TLookupValidator()
{
}

BOOL
TLookupValidator::IsValid(const char far* str)
{
  return Lookup(str);
}

BOOL
TLookupValidator::Lookup(const char far* /*str*/)
{
  return TRUE;
}

//
// TStringLookupValidator
//

TStringLookupValidator::TStringLookupValidator(TSortedStringArray* strings)
  : TLookupValidator()
{
  Strings = strings ? strings : new TSortedStringArray(0, 0, 0);
}

TStringLookupValidator::~TStringLookupValidator()
{
  delete Strings;
}

void
TStringLookupValidator::Error()
{
  ::MessageBox(0, string(*GetApplicationObject(), IDS_VALNOTINLIST).c_str(),
             GetApplicationObject()->GetName(),
             MB_ICONEXCLAMATION | MB_OK | MB_TASKMODAL);
}

BOOL
TStringLookupValidator::Lookup(const char far* str)
{
  if (Strings)
    return Strings->HasMember(str);
  return FALSE;
}

void
TStringLookupValidator::NewStringList(TSortedStringArray* strings)
{
  delete Strings;
  Strings = strings;
}


#endif

#if !defined(SECTION) || SECTION == 2
IMPLEMENT_STREAMABLE1(TLookupValidator, TValidator);

void*
TLookupValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TValidator*)GetObject(), is);
  return GetObject();
}

void
TLookupValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TValidator*)GetObject(), os);
}



IMPLEMENT_STREAMABLE1(TStringLookupValidator, TLookupValidator);

void*
TStringLookupValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TLookupValidator*)GetObject(), is);
  unsigned count;
  is >> count;
  GetObject()->Strings = new TSortedStringArray(count, 0, 5);
  for (unsigned i = 0; i < count; i++ ) {
    string temp;
    is >> temp;
    GetObject()->Strings->Add(temp);
  }
  return GetObject();
}

void
TStringLookupValidator::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TLookupValidator*)GetObject(), os);
  unsigned count = GetObject()->Strings->GetItemsInContainer();
  os << count;
  for (unsigned i = 0; i < count; i++)
    os << (*GetObject()->Strings)[i];
}


#endif
