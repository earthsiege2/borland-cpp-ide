//----------------------------------------------------------------------------
// (C) Copyright 1994 by Borland International, All rights 
//
//   TXBase class implementation.
//
//----------------------------------------------------------------------------

#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif

#include <osl/defs.h>
#include <osl/except.h>

int TXBase::InstanceCount = 0;

TXBase::TXBase(const string& msg)
 : xmsg(msg)
{
  InstanceCount++;
}

TXBase::TXBase(const TXBase& src)
 : xmsg(src)
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
