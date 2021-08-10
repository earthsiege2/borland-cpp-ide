//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of TGdiBase, base abstract class for all GDI objects that
// have Handles.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif
#include <stdio.h>

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

//
//
//
TGdiBase::TGdiBase(HANDLE handle, TAutoDelete autoDelete)
:
  Handle(handle),
  ShouldDelete(autoDelete==AutoDelete)
{
  PRECONDITION(handle);
}

#pragma warn -par   // resId is never used in small model
//
//
//
void
TGdiBase::CheckValid(uint resId)
{
  CheckValid(Handle, resId);
}

//
//
//
void
TGdiBase::CheckValid(HANDLE handle, uint resId)
{
  if (!handle)
    TXGdi::Raise(resId);
}
#pragma warn .par

//----------------------------------------------------------------------------

//
// For backward compatibility
//
string
TXGdi::Msg(uint resId, HANDLE handle)
{
  return MakeMessage(resId, uint(handle));
}

//
// Construct the object with a string resource and the handle
//
TXGdi::TXGdi(uint resId, HANDLE handle)
:
  TXOwl(MakeMessage(resId, uint(handle)), resId)
{
}

//
// Clone the exception object for safe-throwing across Windows.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXGdi*
#endif
TXGdi::Clone()
{
  return new TXGdi(*this);
}

//
// Throw the exception.
//
void
TXGdi::Throw()
{
  THROW( *this );
}

//
// Throw the exception.
//
void
TXGdi::Raise(uint resId, HANDLE handle)
{
  TXGdi(resId, handle).Throw();
}
