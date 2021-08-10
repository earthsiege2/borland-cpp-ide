//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All rights 
//
//$Revision:   5.4  $
//
// TXBase class implementation.
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/exbase.h>

int TXBase::InstanceCount = 0;

TXBase::TXBase(const string& msg)
:
  xmsg(msg)
{
  InstanceCount++;
}

TXBase::TXBase(const TXBase& src)
:
  xmsg(src)
{
  InstanceCount++;
}

TXBase::~TXBase()
{
  InstanceCount--;
}

TXBase*
TXBase::Clone()
{
  return new TXBase(*this);
}

void
TXBase::Throw()
{
  THROW( *this );
}

//
// Construct a TXBase exception from scratch, and throw it
//
void
TXBase::Raise(const string& msg)
{
  TXBase(msg).Throw();
}
