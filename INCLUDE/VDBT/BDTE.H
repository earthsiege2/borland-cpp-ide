//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// Extension to the event mechanism of the PME subsystem for BDT for
// attach/detach notification at the source object.
//
// The templates meant for actual end use are:
//
// Void return, N arguments
//  TBdtEventSourceV0              -- TBdtEventSinkV0
//  TBdtEventSourceV1<P1>          -- TBdtEventSinkV1<P1>
//  TBdtEventSourceV2<P1,P2>       -- TBdtEventSinkV2<P1,P2>
//  TBdtEventSourceV3<P1,P2,P3>    -- TBdtEventSinkV3<P1,P2,P3>
//  TBdtEventSourceV4<P1,P2,P3,P4> -- TBdtEventSinkV4<P1,P2,P3,P4>
//
// Return R, N arguments
//  TBdtEventSource0<R>             -- TBdtEventSink0<R>
//  TBdtEventSource1<R,P1>          -- TBdtEventSink1<R,P1>
//  TBdtEventSource2<R,P1,P2>       -- TBdtEventSink2<R,P1,P2>
//  TBdtEventSource3<R,P1,P2,P3>    -- TBdtEventSink3<R,P1,P2,P3>
//  TBdtEventSource4<R,P1,P2,P3,P4> -- TBdtEventSink4<R,P1,P2,P3,P4>
//
//-----------------------------------------------------------------------------

#if !defined(BDTE_H)
#define BDTE_H

#include <vdbt\bdtf.h>

//
// Mangle the function, class and variable names so we can have
// mulitpale versions of the same functions and variables in one
// .LIB file.
//
#if defined( __DLL__ ) && ! defined( __FLAT__ )
#  if defined( _RTLDLL )
#    define TBdtEventSourceBase dTBdtEventSourceBase
#    define TBdtEventSinkBase   dTBdtEventSinkBase
#  else _RTLDLL
#    define TBdtEventSourceBase uTBdtEventSourceBase
#    define TBdtEventSinkBase   uTBdtEventSinkBase
#  endif _RTLDLL
#elif defined( _RTLDLL )
#  define TBdtEventSourceBase iTBdtEventSourceBase
#  define TBdtEventSinkBase   iTBdtEventSinkBase
#endif __DLL__

//
class TBdtEventSourceBase
{
  public:
    typedef TFunctorV2<const TBdtEventSourceBase&,bool> TSrcAttachFunctor;

    TBdtEventSourceBase(const TSrcAttachFunctor& ftor);
   ~TBdtEventSourceBase();

    void operator +=(class TBdtEventSinkBase& sink);
    void operator -=(class TBdtEventSinkBase& sink);

    class TBdtEventSinkBase* Sink;
    TSrcAttachFunctor        Ftor;
};

//
class TBdtEventSinkBase
{
  public:
    TBdtEventSinkBase() : Source(0), Next(0) {}
   ~TBdtEventSinkBase();

    void Detach();

    TBdtEventSinkBase*   Next;   // Allows event sink chaining
    TBdtEventSourceBase* Source; // Allows cleanup disconnect & sender reference
};

//-----------------------------------------------------------------------------
// Events with void return & 0 parameters

class TBdtEventSinkV0;

class TBdtEventSourceV0 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSourceV0(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    // Invoke the source to fire the event to the sink(s)
    //
    void operator ()();

    // Expose the attach (+=) and detach (-=) operators implemented in the base
    //
    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

class TBdtEventSinkV0 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctorV1<TBdtEventSinkV0&> TFunctor;

    // Construct a sink that bound to a given functor that handles the event
    //
    TBdtEventSinkV0(const TFunctor& functor) : Ftor(functor) {}

    // Sink the event by forwarding to the functor. Called by the event source,
    // or by anyone to simulate an event
    //
    void operator()() { Ftor(*this); }

    // Pass this event to the next sink in the chain, if there is one
    //
    void Pass()
    {
      if (Next)
        (*reinterpret_cast<TBdtEventSinkV0*>(Next))();
    }

    // Return the event source object
    //
    TBdtEventSourceV0* GetSource() {return reinterpret_cast<TBdtEventSourceV0*>(Source);}

    // Detach this sink from whatever source it might be attached to
    //
    TBdtEventSinkBase::Detach;

  private:
    TFunctor Ftor;
};

inline void TBdtEventSourceV0::operator ()() {
  if (Sink)
    (*reinterpret_cast<TBdtEventSinkV0*>(Sink))();
}

//-----------------------------------------------------------------------------
// Events with 0 parameters

template <class R> class TBdtEventSink0;

template <class R> class TBdtEventSource0 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSource0(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    R operator ()()
    {
      if (Sink)
        return (*reinterpret_cast<TBdtEventSink0<R>*>(Sink))();
      //!CQ What to return if no more sinks in the chain?
      return 0;
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class R> class TBdtEventSink0 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctor1<R,TBdtEventSink0<R>&> TFunctor;
    TBdtEventSink0(const TFunctor& functor) : Ftor(functor) {}

    R operator()() { return Ftor(*this); }

    R Pass()
    {
      if (Next)
        return (*reinterpret_cast<TBdtEventSink0<R>*>(Next))();
      //!CQ What to return if no more sinks in the chain?
      return 0;
    }

    TBdtEventSource0<R>* GetSource() {return reinterpret_cast<TBdtEventSource0<R>*>(Source);}

    TBdtEventSinkBase::Detach;

  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with void return & 1 parameter

template <class P1> class TBdtEventSinkV1;

template <class P1> class TBdtEventSourceV1 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSourceV1(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    void operator ()(P1 p1)
    {
      if (Sink)
        (*reinterpret_cast<TBdtEventSinkV1<P1>*>(Sink))(p1);
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class P1> class TBdtEventSinkV1 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctorV2<TBdtEventSinkV1<P1>&,P1> TFunctor;
    TBdtEventSinkV1(const TFunctor& functor) : Ftor(functor) {}

    void operator()(P1 p1) { Ftor(*this, p1); }

    void Pass(P1 p1)
    {
      if (Next)
        (*reinterpret_cast<TBdtEventSinkV1<P1>*>(Next))(p1);
    }

    TBdtEventSourceV1<P1>* GetSource() {return reinterpret_cast<TBdtEventSourceV1<P1>*>(Source);}

    TBdtEventSinkBase::Detach;

  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with 1 parameter

template <class R, class P1> class TBdtEventSink1;

template <class R, class P1> class TBdtEventSource1 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSource1(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    R operator ()(P1 p1)
    {
      if (Sink)
        return (*reinterpret_cast<TBdtEventSink1<R,P1>*>(Sink))(p1);
      return 0;
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class R, class P1> class TBdtEventSink1 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctor2<R,TBdtEventSink1<R,P1>&,P1> TFunctor;
    TBdtEventSink1(const TFunctor& functor) : Ftor(functor) {}

    R operator()(P1 p1) { return Ftor(*this, p1); }

    R Pass(P1 p1)
    {
      if (Next)
        return (*reinterpret_cast<TBdtEventSink1<R,P1>*>(Next))(p1);
      return 0;
    }

    TBdtEventSource1<R,P1>* GetSource() {return reinterpret_cast<TBdtEventSource1<R,P1>*>(Source);}

    TBdtEventSinkBase::Detach;

  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with void return & 2 parameters

template <class P1, class P2> class TBdtEventSinkV2;

template <class P1, class P2> class TBdtEventSourceV2 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSourceV2(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    void operator ()(P1 p1, P2 p2)
    {
      if (Sink)
        (*reinterpret_cast<TBdtEventSinkV2<P1,P2>*>(Sink))(p1,p2);
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class P1, class P2> class TBdtEventSinkV2 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctorV3<TBdtEventSinkV2<P1,P2>&,P1,P2> TFunctor;
    TBdtEventSinkV2(const TFunctor& functor) : Ftor(functor) {}

    void operator()(P1 p1, P2 p2) { Ftor(*this, p1, p2); }

    void Pass(P1 p1, P2 p2)
    {
      if (Next)
        (*reinterpret_cast<TBdtEventSinkV2<P1,P2>*>(Next))(p1,p2);
    }

    TBdtEventSourceV2<P1,P2>* GetSource() {return reinterpret_cast<TBdtEventSourceV2<P1,P2>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with 2 parameters

template <class R, class P1, class P2> class TBdtEventSink2;

template <class R, class P1, class P2> class TBdtEventSource2 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSource2(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    R operator ()(P1 p1, P2 p2)
    {
      if (Sink)
        return (*reinterpret_cast<TBdtEventSink2<R,P1,P2>*>(Sink))(p1,p2);
      return 0;
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class R, class P1, class P2> class TBdtEventSink2 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctor3<R,TBdtEventSink2<R,P1,P2>&,P1,P2> TFunctor;
    TBdtEventSink2(const TFunctor& functor) : Ftor(functor) {}

    R operator()(P1 p1, P2 p2) { return Ftor(*this, p1, p2); }

    R Pass(P1 p1, P2 p2)
    {
      if (Next)
        return (*reinterpret_cast<TBdtEventSink2<R,P1,P2>*>(Next))(p1,p2);
      return 0;
    }

    TBdtEventSource2<R,P1,P2>* GetSource() {return reinterpret_cast<TBdtEventSource2<R,P1,P2>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with void return & 3 parameters

template <class P1, class P2, class P3> class TBdtEventSinkV3;

template <class P1, class P2, class P3>
class TBdtEventSourceV3 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSourceV3(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    void operator ()(P1 p1, P2 p2, P3 p3)
    {
      if (Sink)
        (*reinterpret_cast<TBdtEventSinkV3<P1,P2,P3>*>(Sink))(p1,p2,p3);
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class P1, class P2, class P3>
class TBdtEventSinkV3 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctorV4<TBdtEventSinkV3<P1,P2,P3>&,P1,P2,P3> TFunctor;
    TBdtEventSinkV3(const TFunctor& functor) : Ftor(functor) {}

    void operator()(P1 p1, P2 p2, P3 p3) { Ftor(*this, p1, p2, p3); }

    void Pass(P1 p1, P2 p2, P3 p3)
    {
      if (Next)
        (*reinterpret_cast<TBdtEventSinkV3<P1,P2,P3>*>(Next))(p1,p2,p3);
    }

    TBdtEventSourceV3<P1,P2,P3>* GetSource() {return reinterpret_cast<TBdtEventSourceV3<P1,P2,P3>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with 3 parameters

template <class R, class P1, class P2, class P3> class TBdtEventSink3;

template <class R, class P1, class P2, class P3>
class TBdtEventSource3 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSource3(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    R operator ()(P1 p1, P2 p2, P3 p3)
    {
      if (Sink)
        return (*reinterpret_cast<TBdtEventSink3<R,P1,P2,P3>*>(Sink))(p1,p2,p3);
      return 0;
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class R, class P1, class P2, class P3>
class TBdtEventSink3 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctor4<R,TBdtEventSink3<R,P1,P2,P3>&,P1,P2,P3> TFunctor;
    TBdtEventSink3(const TFunctor& functor) : Ftor(functor) {}

    R operator()(P1 p1, P2 p2, P3 p3) { return Ftor(*this, p1, p2, p3); }

    R Pass(P1 p1, P2 p2, P3 p3)
    {
      if (Next)
        return (*reinterpret_cast<TBdtEventSink3<R,P1,P2,P3>*>(Next))(p1,p2,p3);
      return 0;
    }

    TBdtEventSource3<R,P1,P2,P3>* GetSource() {return reinterpret_cast<TBdtEventSource3<R,P1,P2,P3>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with void return & 4 parameters

template <class P1, class P2, class P3, class P4> class TBdtEventSinkV4;

template <class P1, class P2, class P3, class P4>
class TBdtEventSourceV4 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSourceV4(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4)
    {
      if (Sink)
        (*reinterpret_cast<TBdtEventSinkV4<P1,P2,P3,P4>*>(Sink))(p1,p2,p3,p4);
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class P1, class P2, class P3, class P4>
class TBdtEventSinkV4 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctorV5<TBdtEventSinkV4<P1,P2,P3,P4>&,P1,P2,P3,P4> TFunctor;
    TBdtEventSinkV4(const TFunctor& functor) : Ftor(functor) {}

    void operator()(P1 p1, P2 p2, P3 p3, P4 p4) { Ftor(*this,p1,p2,p3,p4); }

    void Pass(P1 p1, P2 p2, P3 p3, P4 p4)
    {
      if (Next)
        (*reinterpret_cast<TBdtEventSinkV4<P1,P2,P3,P4>*>(Next))(p1,p2,p3,p4);
    }

    TBdtEventSourceV4<P1,P2,P3,P4>* GetSource() {return reinterpret_cast<TBdtEventSourceV4<P1,P2,P3,P4>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with 4 parameters

template <class R, class P1, class P2, class P3, class P4> class TBdtEventSink4;

template <class R, class P1, class P2, class P3, class P4>
class TBdtEventSource4 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSource4(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4)
    {
      if (Sink)
        return (*reinterpret_cast<TBdtEventSink4<R,P1,P2,P3,P4>*>(Sink))(p1,p2,p3,p4);
      return 0;
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};


template <class R, class P1, class P2, class P3, class P4>
class TBdtEventSink4 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctor5<R,TBdtEventSink4<R,P1,P2,P3,P4>&,P1,P2,P3,P4> TFunctor;
    TBdtEventSink4(const TFunctor& functor) : Ftor(functor) {}

    R operator()(P1 p1, P2 p2, P3 p3, P4 p4) { return Ftor(*this,p1,p2,p3,p4); }

    R Pass(P1 p1, P2 p2, P3 p3, P4 p4)
    {
      if (Next)
        return (*reinterpret_cast<TBdtEventSink4<R,P1,P2,P3,P4>*>(Next))(p1,p2,p3,p4);
      return 0;
    }

    TBdtEventSource4<R,P1,P2,P3,P4>* GetSource() {return reinterpret_cast<TBdtEventSource4<R,P1,P2,P3,P4>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with void return & 5 parameters

template <class P1, class P2, class P3, class P4, class P5> class TBdtEventSinkV5;

template <class P1, class P2, class P3, class P4, class P5>
class TBdtEventSourceV5 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSourceV5(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    void operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      if (Sink)
        (*reinterpret_cast<TBdtEventSinkV5<P1,P2,P3,P4,P5>*>(Sink))(p1,p2,p3,p4,p5);
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};

template <class P1, class P2, class P3, class P4, class P5>
class TBdtEventSinkV5 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctorV6<TBdtEventSinkV5<P1,P2,P3,P4,P5>&,P1,P2,P3,P4,P5> TFunctor;
    TBdtEventSinkV5(const TFunctor& functor) : Ftor(functor) {}

    void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) { Ftor(*this,p1,p2,p3,p4,p5); }

    void Pass(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      if (Next)
        (*reinterpret_cast<TBdtEventSinkV5<P1,P2,P3,P4,P5>*>(Next))(p1,p2,p3,p4,p5);
    }

    TBdtEventSourceV5<P1,P2,P3,P4,P5>* GetSource() {return reinterpret_cast<TBdtEventSourceV5<P1,P2,P3,P4,P5>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------
// Events with 5 parameters

template <class R, class P1, class P2, class P3, class P4, class P5> class TBdtEventSink5;

template <class R, class P1, class P2, class P3, class P4, class P5>
class TBdtEventSource5 : protected TBdtEventSourceBase
{
  public:
    TBdtEventSource5(const TSrcAttachFunctor& ftor) : TBdtEventSourceBase(ftor) {}

    R operator ()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      if (Sink)
        return (*reinterpret_cast<TBdtEventSink5<R,P1,P2,P3,P4,P5>*>(Sink))(p1,p2,p3,p4,p5);
      return 0;
    }

    TBdtEventSourceBase::operator +=;    
    TBdtEventSourceBase::operator -=;    
};


template <class R, class P1, class P2, class P3, class P4, class P5>
class TBdtEventSink5 : protected TBdtEventSinkBase
{
  public:
    typedef TFunctor6<R,TBdtEventSink5<R,P1,P2,P3,P4,P5>&,P1,P2,P3,P4,P5> TFunctor;
    TBdtEventSink5(const TFunctor& functor) : Ftor(functor) {}

    R operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) { return Ftor(*this,p1,p2,p3,p4,p5); }

    R Pass(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      if (Next)
        return (*reinterpret_cast<TBdtEventSink5<R,P1,P2,P3,P4,P5>*>(Next))(p1,p2,p3,p4,p5);
      return 0;
    }

    TBdtEventSource5<R,P1,P2,P3,P4,P5>* GetSource() {return reinterpret_cast<TBdtEventSource5<R,P1,P2,P3,P4,P5>*>(Source);}

    TBdtEventSinkBase::Detach;
    
  private:
    TFunctor Ftor;
};

//-----------------------------------------------------------------------------

#define SrcAttach_FUNCTOR(func) \
        Functor((TBdtEventSourceBase::TSrcAttachFunctor*)0, func)

#define SrcAttach_MFUNCTOR(object,memberFunc) \
        Functor((TBdtEventSourceBase::TSrcAttachFunctor*)0, object, memberFunc)


#endif // BDTE_H
