//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// functor.cpp
// C++ Functor template implementation
//
// Based on Functors described in
//  Rich Hickey's 'Callbacks in C++ using template functors' Feb 95 C++ Report
//
//-----------------------------------------------------------------------------

#include <vdbt\bdtf.h>

#pragma hdrstop

#include <memory.h>

//-----------------------------------------------------------------------------
//
// Functor base class constructor implentation
//
TFunctorBase::TFunctorBase(const void* c, const void* f, size_t sz)
{
  if (c) {
    Callee = const_cast<void*>(c);
    memcpy(MemberFunc, f, sz);
  }
  else {
    Func = f;
  }
}
