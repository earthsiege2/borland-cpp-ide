//----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// bdtevent.cpp
// Event mechanism portion of the PME subsystem for BDT
//-----------------------------------------------------------------------------

#include <vdbt\bdte.h>

#pragma hdrstop

//-----------------------------------------------------------------------------
//
//
//
TBdtEventSourceBase::TBdtEventSourceBase(const TSrcAttachFunctor& ftor)
:
  Sink(0),
  Ftor(ftor)
{
}

//
// Clean up the sink chain on destruction
//
TBdtEventSourceBase::~TBdtEventSourceBase()
{
  for (TBdtEventSinkBase* sp = Sink; sp; sp = sp->Next)
    sp->Source = 0;
}

//
// Add an event sink to the chain for this source
//
void TBdtEventSourceBase::operator +=(TBdtEventSinkBase& sink)
{
  // Notify that we now have connections
  //
  if (!Sink)
    Ftor(*this,true);

  // Detach from existing chain
  //
  if (sink.Source)
    (*sink.Source) -= sink;

  // Insert at head of event sink chain
  //
  TBdtEventSinkBase* oldsink = Sink;
  Sink = &sink;
  sink.Next = oldsink;
  sink.Source = this;
}

//
// Remove an event sink from the chain for this source
//
void TBdtEventSourceBase::operator -=(TBdtEventSinkBase& sink)
{
  if (Sink) {
    for (TBdtEventSinkBase** sp = &Sink; *sp; sp = &(*sp)->Next) {
      if (*sp == &sink) {
        *sp = (*sp)->Next;
        sink.Next = 0;
        sink.Source = 0;
        break;
      }
    }

    // Notify that we no longer have connections
    //
    if (!Sink)
      Ftor(*this,false);
  }
}

//-----------------------------------------------------------------------------

//
// Events sinks auto-detach when destructed
//
TBdtEventSinkBase::~TBdtEventSinkBase()
{
  if (Source)
    *Source -= *this;
}

//
// Events sinks auto-detach when destructed
//
void TBdtEventSinkBase::Detach()
{
  if (Source)
    *Source -= *this;
}
