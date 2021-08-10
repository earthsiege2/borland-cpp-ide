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

//
// TLookupValidator
//

TLookupValidator::TLookupValidator()
{
}

bool
TLookupValidator::IsValid(const char far* str)
{
  return Lookup(str);
}

bool
TLookupValidator::Lookup(const char far* /*str*/)
{
  return true;
}

//----------------------------------------------------------------------------

//
// TSortedStringArray implementation
//
TSortedStringArray::TSortedStringArray(int upper, int lower, int delta)
:
  Data(upper, lower, delta)
{
}

int TSortedStringArray::LowerBound() const
{
  return Data.LowerBound();
}

int TSortedStringArray::UpperBound() const
{
  return Data.UpperBound();
}

unsigned TSortedStringArray::ArraySize() const
{
  return Data.ArraySize();
}

int TSortedStringArray::IsFull() const
{
  return Data.IsFull();
}

int TSortedStringArray::IsEmpty() const
{
  return Data.IsEmpty();
}

unsigned TSortedStringArray::GetItemsInContainer() const
{
  return Data.GetItemsInContainer();
}

int TSortedStringArray::Add(const string& t)
{
  return Data.Add(t);
}

int TSortedStringArray::Detach(const string& t)
{
  return Data.Detach(t);
}

int TSortedStringArray::Detach(int loc)
{
  return Data.Detach(loc);
}

int TSortedStringArray::Destroy(const string& t)
{
  return Detach(t);
}

int TSortedStringArray::Destroy(int loc)
{
  return Detach(loc);
}

int TSortedStringArray::HasMember(const string& t) const
{
  return Data.HasMember(t);
}

int TSortedStringArray::Find(const string& t) const
{
  return Data.Find(t);
}

string& TSortedStringArray::operator [](int loc)
{
  return Data[loc];
}

string& TSortedStringArray::operator [](int loc) const
{
  return Data[loc];
}

void TSortedStringArray::ForEach(IterFunc iter, void* args)
{
  Data.ForEach(iter, args);
}

string* TSortedStringArray::FirstThat(CondFunc cond, void* args) const
{
  return Data.FirstThat(cond, args);
}

string* TSortedStringArray::LastThat(CondFunc cond, void* args) const
{
  return Data.LastThat(cond, args);
}

void TSortedStringArray::Flush()
{
  Data.Flush();
}

//----------------------------------------------------------------------------

//
// TStringLookupValidator
//

TStringLookupValidator::TStringLookupValidator(TSortedStringArray* strings)
:
  TLookupValidator()
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
  TApplication* app = GetApplicationObject();
  const char* msg = app->LoadString(IDS_VALNOTINLIST).c_str();
  TWindow* w = GetWindowPtr(app->GetMainWindow()->GetLastActivePopup());
  if (w)
    w->MessageBox(msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK);
  else
    ::MessageBox(0, msg, app->GetName(), MB_ICONEXCLAMATION|MB_OK|MB_TASKMODAL);
}

bool
TStringLookupValidator::Lookup(const char far* str)
{
  if (Strings)
    return Strings->HasMember(str);
  return false;
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
