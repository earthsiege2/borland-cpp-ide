//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of many of OWL's container classes
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CONTAIN_H)
# include <owl/contain.h>
#endif


//
//
//
TStringArray::TStringArray(int upper, int lower, int delta)
:
  Data(upper, lower, delta)
{
}

//
//
//
int TStringArray::LowerBound() const
{
  return Data.LowerBound();
}

//
//
//
int TStringArray::UpperBound() const
{
  return Data.UpperBound();
}

//
//
//
unsigned TStringArray::ArraySize() const
{
  return Data.ArraySize();
}

//
//
//
int TStringArray::IsFull() const
{
  return Data.IsFull();
}

//
//
//
int TStringArray::IsEmpty() const
{
  return Data.IsEmpty();
}

//
//
//
unsigned TStringArray::GetItemsInContainer() const
{
  return Data.GetItemsInContainer();
}

//
//
//
int TStringArray::Add(const string& t)
{
  return Data.Add(t);
}

//
//
//
int TStringArray::Detach(const string& t)
{
  return Data.Detach(t);
}

//
//
//
int TStringArray::Detach(int loc)
{
  return Data.Detach(loc);
}

//
//
//
int TStringArray::Destroy(const string& t)
{
  return Detach(t);
}

//
//
//
int TStringArray::Destroy(int loc)
{
  return Detach(loc);
}

//
//
//
int TStringArray::HasMember(const string& t) const
{
  return Data.HasMember(t);
}

//
//
//
int TStringArray::Find(const string& t) const
{
  return Data.Find(t);
}

//
//
//
string& TStringArray::operator [](int loc)
{
  return Data[loc];
}

//
//
//
string& TStringArray::operator [](int loc) const
{
  return Data[loc];
}

//
//
//
void TStringArray::ForEach(IterFunc iter, void* args)
{
  Data.ForEach(iter, args);
}

//
//
//
string* TStringArray::FirstThat(CondFunc cond, void* args) const
{
  return Data.FirstThat(cond, args);
}

//
//
//
string* TStringArray::LastThat(CondFunc cond, void* args) const
{
  return Data.LastThat(cond, args);
}

//
//
//
void TStringArray::Flush()
{
  Data.Flush();
}

//----------------------------------------------------------------------------

//
//
//
TIntArray::TIntArray(int upper, int lower, int delta)
:
  Data(upper, lower, delta)
{
}

//
//
//
int TIntArray::LowerBound() const
{
  return Data.LowerBound();
}

//
//
//
int TIntArray::UpperBound() const
{
  return Data.UpperBound();
}

//
//
//
unsigned TIntArray::ArraySize() const
{
  return Data.ArraySize();
}

//
//
//
int TIntArray::IsFull() const
{
  return Data.IsFull();
}

//
//
//
int TIntArray::IsEmpty() const
{
  return Data.IsEmpty();
}

//
//
//
unsigned TIntArray::GetItemsInContainer() const
{
  return Data.GetItemsInContainer();
}

//
//
//
int TIntArray::Add(const TInt& t)
{
  return Data.Add(t);
}

//
//
//
int TIntArray::Detach(const TInt& t)
{
  return Data.Detach(t);
}

//
//
//
int TIntArray::Detach(int loc)
{
  return Data.Detach(loc);
}

//
//
//
int TIntArray::Destroy(const TInt& t)
{
  return Detach(t);
}

//
//
//
int TIntArray::Destroy(int loc)
{
  return Detach(loc);
}

//
//
//
int TIntArray::HasMember(const TInt& t) const
{
  return Data.HasMember(t);
}

//
//
//
int TIntArray::Find(const TInt& t) const
{
  return Data.Find(t);
}

//
//
//
TInt& TIntArray::operator [](int loc)
{
  return Data[loc];
}

//
//
//
TInt& TIntArray::operator [](int loc) const
{
  return Data[loc];
}

//
//
//
void TIntArray::ForEach(IterFunc iter, void* args)
{
  Data.ForEach(iter, args);
}

//
//
//
TInt* TIntArray::FirstThat(CondFunc cond, void* args) const
{
  return Data.FirstThat(cond, args);
}

//
//
//
TInt* TIntArray::LastThat(CondFunc cond, void* args) const
{
  return Data.LastThat(cond, args);
}

//
//
//
void TIntArray::Flush()
{
  Data.Flush();
}

//----------------------------------------------------------------------------

//
//
//
TUint32Array::TUint32Array(int upper, int lower, int delta)
:
  Data(upper, lower, delta)
{
}

//
//
//
int TUint32Array::LowerBound() const
{
  return Data.LowerBound();
}

//
//
//
int TUint32Array::UpperBound() const
{
  return Data.UpperBound();
}

//
//
//
unsigned TUint32Array::ArraySize() const
{
  return Data.ArraySize();
}

//
//
//
int TUint32Array::IsFull() const
{
  return Data.IsFull();
}

//
//
//
int TUint32Array::IsEmpty() const
{
  return Data.IsEmpty();
}

//
//
//
unsigned TUint32Array::GetItemsInContainer() const
{
  return Data.GetItemsInContainer();
}

//
//
//
int TUint32Array::Add(const uint32& t)
{
  return Data.Add(t);
}

//
//
//
int TUint32Array::Detach(const uint32& t)
{
  return Data.Detach(t);
}

//
//
//
int TUint32Array::Detach(int loc)
{
  return Data.Detach(loc);
}

//
//
//
int TUint32Array::Destroy(const uint32& t)
{
  return Detach(t);
}

//
//
//
int TUint32Array::Destroy(int loc)
{
  return Detach(loc);
}

//
//
//
int TUint32Array::HasMember(const uint32& t) const
{
  return Data.HasMember(t);
}

//
//
//
int TUint32Array::Find(const uint32& t) const
{
  return Data.Find(t);
}

//
//
//
uint32& TUint32Array::operator [](int loc)
{
  return Data[loc];
}

//
//
//
uint32& TUint32Array::operator [](int loc) const
{
  return Data[loc];
}

//
//
//
void TUint32Array::ForEach(IterFunc iter, void* args)
{
  Data.ForEach(iter, args);
}

//
//
//
uint32* TUint32Array::FirstThat(CondFunc cond, void* args) const
{
  return Data.FirstThat(cond, args);
}

//
//
//
uint32* TUint32Array::LastThat(CondFunc cond, void* args) const
{
  return Data.LastThat(cond, args);
}

//
//
//
void TUint32Array::Flush()
{
  Data.Flush();
}
