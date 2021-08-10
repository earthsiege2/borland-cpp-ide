//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TGdiBase, base abstract GDI object class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdibase.h>

//
// TGdiBase constructors
//
TGdiBase::TGdiBase()
:
  Handle(0),
  ShouldDelete(true)
{
  // Handle must be set by derived class
}

TGdiBase::TGdiBase(HANDLE handle, TAutoDelete autoDelete)
:
  Handle(handle),
  ShouldDelete(autoDelete==AutoDelete)
{
  PRECONDITION(handle);
}

#pragma warn -par   // resId is never used in small model
void
TGdiBase::CheckValid(uint resId)
{
  CheckValid(Handle, resId);
}

void
TGdiBase::CheckValid(HANDLE handle, uint resId)
{
  if (!handle)
    THROW( TXGdi(resId) );
}
#pragma warn .par

string
TGdiBase::TXGdi::Msg(unsigned resId, HANDLE handle)
{
  bool   found;  // did we locate the string
  string rscMsg = ResourceIdToString(&found, resId);

  if (found) {
    char buf[255];

    // supply Handle of gdi object if we have one
    //
    wsprintf(buf, rscMsg.c_str(), handle);
    return string(buf);
  }
  else
    return rscMsg;
}

TGdiBase::TXGdi::TXGdi(unsigned resId, HANDLE handle)
:
  TXOwl(Msg(resId, handle), resId)
{
}

TXOwl*
TGdiBase::TXGdi::Clone()
{
  return new TXGdi(*this);
}

void
TGdiBase::TXGdi::Throw()
{
  THROW( *this ); 
}
