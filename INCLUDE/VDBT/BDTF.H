//-----------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// C++ Functor template implementation
//
// The templates meant for actual end use are:
//
// Void return, N arguments
//  TFunctorV0
//  TFunctorV1<P1>
//  TFunctorV2<P1,P2>
//  TFunctorV3<P1,P2,P3>
//  TFunctorV4<P1,P2,P3,P4>
//  TFunctorV5<P1,P2,P3,P4,P5>
//
// Return R, N arguments
//  TFunctor0<R>
//  TFunctor1<R,P1>
//  TFunctor2<R,P1,P2>
//  TFunctor3<R,P1,P2,P3>
//  TFunctor4<R,P1,P2,P3,P4>
//  TFunctor5<R,P1,P2,P3,P4,P5>
//
// The Functor() template function is invoked to create a temporary translator
// to initialize the actual functor. Currently, the first argument to Functor()
// must be a dummy pointer to the desired TFunctor template. When templatized
// member functions are available, this arg will be eliminated.
//
// Based on Functors described in
//  Rich Hickey's 'Callbacks in C++ using template functors' Feb 95 C++ Report
//
//-----------------------------------------------------------------------------

#if !defined(BDTF_H)
#define BDTF_H

#include <ctype.h>  // get size_t definition

//
// Base functor class holds all of the actual data
//
class TFunctorBase
{
  public:
    typedef void (TFunctorBase::*TMemberFunc)();

    TFunctorBase() : Callee(0), Func(0) {}
    TFunctorBase(const void* c, const void* f, size_t sz);

    operator bool() const {return Func || Callee;}

//    class TDummyInit {};

    union {
      const void* Func;
      char MemberFunc[sizeof(TMemberFunc)];  // ASSUMES this is always enough space
    };
    void* Callee;
};
      
//-----------------------------------------------------------------------------
// Functor with 0 parameters, void return

class TFunctorV0 : protected TFunctorBase
{
  public:
    TFunctorV0(/*TDummyInit* = 0*/) {}
    void operator()() const {
      Thunk(*this);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&);
    TFunctorV0(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class Func>
class TFunctionTranslatorV0 : public TFunctorV0
{
  public:
    TFunctionTranslatorV0(Func f) : TFunctorV0(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor)
    {
      (Func(ftor.Func))();
    }
};

template <class Callee, class TMemFunc>
class TMemberTranslatorV0 : public TFunctorV0
{
  public:
    TMemberTranslatorV0(Callee& c, const TMemFunc& mf)
      : TFunctorV0(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)();
    }
};

template <class TRT>
inline TFunctionTranslatorV0<TRT(*)()>
Functor(TFunctorV0*, TRT(*f)())
{
  return TFunctionTranslatorV0<TRT(*)()>(f);
}

template <class Callee, class TRT, class CallType>
inline TMemberTranslatorV0<Callee, TRT (CallType::*)()>
Functor(TFunctorV0*, Callee& c, TRT(CallType::* const& f)())
{
  typedef TRT (CallType::*TMemFunc)();
  return TMemberTranslatorV0<Callee, TMemFunc>(c,f);
}

template <class Callee, class TRT, class CallType>
inline TMemberTranslatorV0<const Callee, TRT(CallType::*)() const>
Functor(TFunctorV0*, const Callee& c, TRT(CallType::* const& f)() const)
{
  typedef TRT (CallType::*TMemFunc)() const;
  return TMemberTranslatorV0<const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 0 parameters, return R

template <class R>
class TFunctor0 : protected TFunctorBase
{
  public:
    TFunctor0(/*TDummyInit* = 0*/) {}

    R operator()() const {
      return Thunk(*this);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&);
    TFunctor0(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class Func>
class TFunctionTranslator0 : public TFunctor0<R>
{
  public:
    TFunctionTranslator0(Func f) : TFunctor0(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor)
    {
      return (Func(ftor.Func))();
    }
};

template <class R, class Callee, class TMemFunc>
class TMemberTranslator0 : public TFunctor0<R>
{
  public:
    TMemberTranslator0(Callee& c, const TMemFunc& mf)
      : TFunctor0<R>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)();
    }
};

template <class R, class TRT>
inline TFunctionTranslator0<R,TRT(*)()>
Functor(TFunctor0<R>*, TRT(*f)())
{
  return TFunctionTranslator0<R,TRT(*)()>(f);
}

template <class R, class Callee, class TRT, class CallType>
inline TMemberTranslator0<R, Callee, TRT(CallType::*)()>
Functor(TFunctor0<R>*, Callee& c, TRT(CallType::* const& f)())
{
  typedef TRT (CallType::*TMemFunc)();
  return TMemberTranslator0<R, Callee, TMemFunc>(c,f);
}

template <class R, class Callee, class TRT, class CallType>
inline TMemberTranslator0<R, const Callee, TRT(CallType::*)() const>
Functor(TFunctor0<R>*, const Callee& c, TRT(CallType::* const& f)() const)
{
  typedef TRT (CallType::*TMemFunc)() const;
  return TMemberTranslator0<R, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 1 parameter, void return

template <class P1>
class TFunctorV1 : protected TFunctorBase
{
  public:
    TFunctorV1(/*TDummyInit* = 0*/) {}

    void operator()(P1 p1) const
    {
      Thunk(*this, p1);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&, P1);
    TFunctorV1(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class P1, class Func>
class TFunctionTranslatorV1 : public TFunctorV1<P1>
{
  public:
    TFunctionTranslatorV1(Func f) : TFunctorV1<P1>(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1)
    {
      (Func(ftor.Func))(p1);
    }
};

template <class P1, class Callee, class TMemFunc>
class TMemberTranslatorV1 : public TFunctorV1<P1>
{
  public:
    TMemberTranslatorV1(Callee& c, const TMemFunc& mf)
      : TFunctorV1<P1>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)(p1);
    }
};

template <class P1, class TRT, class TP1>
inline TFunctionTranslatorV1<P1, TRT(*)(TP1)>
Functor(TFunctorV1<P1>*, TRT(*f)(TP1))
{
  return TFunctionTranslatorV1<P1, TRT(*)(TP1)>(f);
}

template <class P1, class Callee, class TRT, class CallType, class TP1>
inline TMemberTranslatorV1<P1, Callee, TRT (CallType::*)(TP1)>
Functor(TFunctorV1<P1>*, Callee& c, TRT (CallType::* const& f)(TP1))
{
  typedef TRT (CallType::*TMemFunc)(TP1);
  return TMemberTranslatorV1<P1, Callee, TMemFunc>(c,f);
}

template <class P1, class Callee, class TRT, class CallType, class TP1>
inline TMemberTranslatorV1<P1, const Callee, TRT(CallType::*)(TP1) const>
Functor(TFunctorV1<P1>*, const Callee& c, TRT(CallType::* const& f)(TP1) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1) const;
  return TMemberTranslatorV1<P1, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 1 parameter, return R

template <class R, class P1>
class TFunctor1 : protected TFunctorBase
{
  public:
    TFunctor1(/*TDummyInit* = 0*/) {}

    R operator()(P1 p1) const
    {
      return Thunk(*this, p1);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&, P1);
    TFunctor1(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class P1, class Func>
class TFunctionTranslator1 : public TFunctor1<R,P1>
{
  public:
    TFunctionTranslator1(Func f) : TFunctor1<P1,R>(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1)
    {
      return (Func(ftor.Func))(p1);
    }
};

template <class R, class P1, class Callee, class TMemFunc>
class TMemberTranslator1 : public TFunctor1<R,P1>
{
  public:
    TMemberTranslator1(Callee& c, const TMemFunc& mf)
      : TFunctor1<R,P1>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)(p1);
    }
};

template <class R, class P1, class TRT, class TP1>
inline TFunctionTranslator1<R, P1, TRT(*)(TP1)>
Functor(TFunctor1<R,P1>*, TRT(*f)(TP1))
{
  return TFunctionTranslator1<R, P1, TRT(*)(TP1)>(f);
}

template <class R, class P1, class Callee, class TRT, class CallType, class TP1>
inline TMemberTranslator1<R, P1, Callee, TRT (CallType::*)(TP1)>
Functor(TFunctor1<R,P1>*, Callee& c, TRT(CallType::* const& f)(TP1))
{
  typedef TRT (CallType::*TMemFunc)(TP1);
  return TMemberTranslator1<R, P1, Callee, TMemFunc>(c,f);
}

template <class R, class P1, class Callee, class TRT, class CallType, class TP1>
inline TMemberTranslator1<R, P1, const Callee, TRT(CallType::*)(TP1) const>
Functor(TFunctor1<R,P1>*, const Callee& c, TRT(CallType::* const& f)(TP1) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1) const;
  return TMemberTranslator1<R, P1, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 2 parameters, void return

template <class P1, class P2>
class TFunctorV2 : protected TFunctorBase
{
  public:
    TFunctorV2(/*TDummyInit* = 0*/) {}

    void operator()(P1 p1, P2 p2) const
    {
      Thunk(*this, p1, p2);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&, P1, P2);
    TFunctorV2(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class P1, class P2, class Func>
class TFunctionTranslatorV2 : public TFunctorV2<P1,P2>
{
  public:
    TFunctionTranslatorV2(Func f) : TFunctorV2<P1,P2>(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2)
    {
      (Func(ftor.Func))(p1, p2);
    }
};

template <class P1, class P2, class Callee, class TMemFunc>
class TMemberTranslatorV2 : public TFunctorV2<P1,P2>
{
  public:
    TMemberTranslatorV2(Callee& c, const TMemFunc& mf)
      : TFunctorV2<P1,P2>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)(p1, p2);
    }
};

template <class P1, class P2, class TRT, class TP1, class TP2>
inline TFunctionTranslatorV2<P1, P2, TRT (*)(TP1,TP2)>
Functor(TFunctorV2<P1,P2>*, TRT (*f)(TP1,TP2))
{
  return TFunctionTranslatorV2<P1, P2, TRT(*)(TP1,TP2)>(f);
}

template <class P1, class P2,
          class Callee, class TRT, class CallType,
          class TP1, class TP2>
inline TMemberTranslatorV2<P1, P2, Callee, TRT (CallType::*)(TP1,TP2)>
Functor(TFunctorV2<P1,P2>*, Callee& c, TRT (CallType::* const& f)(TP1,TP2))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2);
  return TMemberTranslatorV2<P1, P2, Callee, TMemFunc>(c,f);
}

template <class P1, class P2,
          class Callee, class TRT, class CallType,
          class TP1, class TP2>
inline TMemberTranslatorV2<P1, P2, const Callee, TRT(CallType::*)(TP1,TP2) const>
Functor(TFunctorV2<P1,P2>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2) const;
  return TMemberTranslatorV2<P1, P2, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 2 parameters, return R

template <class R, class P1, class P2>
class TFunctor2 : protected TFunctorBase
{
  public:
    TFunctor2(/*TDummyInit* = 0*/) {}

    R operator()(P1 p1, P2 p2) const
    {
      return Thunk(*this, p1, p2);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&, P1, P2);
    TFunctor2(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class P1, class P2, class Func>
class TFunctionTranslator2 : public TFunctor2<R,P1,P2>
{
  public:
    TFunctionTranslator2(Func f) : TFunctor2<P1,P2>(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2)
    {
      return (Func(ftor.Func))(p1, p2);
    }
};

template <class R, class P1, class P2, class Callee, class TMemFunc>
class TMemberTranslator2 : public TFunctor2<R,P1,P2>
{
  public:
    TMemberTranslator2(Callee& c, const TMemFunc& mf)
      : TFunctor2<P1,P2>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)(p1, p2);
    }
};

template <class R, class P1, class P2, class TRT, class TP1, class TP2>
inline TFunctionTranslator2<R, P1, P2, TRT(*)(TP1,TP2)>
Functor(TFunctor2<R,P1,P2>*, TRT(*f)(TP1,TP2))
{
  return TFunctionTranslator2<R, P1, P2, TRT(*)(TP1,TP2)>(f);
}

template <class R, class P1, class P2,
          class Callee, class TRT, class CallType,
          class TP1, class TP2>
inline TMemberTranslator2<R, P1, P2, Callee, TRT(CallType::*)(TP1,TP2)>
Functor(TFunctor2<R,P1,P2>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2);
  return TMemberTranslator2<R, P1, P2, Callee, TMemFunc>(c,f);
}

template <class R, class P1, class P2,
          class Callee, class TRT, class CallType,
          class TP1, class TP2>
inline TMemberTranslator2<R, P1, P2, const Callee, TRT(CallType::*)(TP1,TP2) const>
Functor(TFunctor2<R,P1,P2>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2) const;
  return TMemberTranslator2<R, P1, P2, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 3 parameters, void return

template <class P1, class P2, class P3>
class TFunctorV3 : protected TFunctorBase
{
  public:
    TFunctorV3(/*TDummyInit* = 0*/) {}

    void operator()(P1 p1, P2 p2, P3 p3) const
    {
      Thunk(*this, p1, p2, p3);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&, P1, P2, P3);
    TFunctorV3(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class P1, class P2, class P3, class Func>
class TFunctionTranslatorV3 : public TFunctorV3<P1,P2,P3>
{
  public:
    TFunctionTranslatorV3(Func f) : TFunctorV3<P1,P2,P3>(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3)
    {
      (Func(ftor.Func))(p1, p2, p3);
    }
};

template <class P1, class P2, class P3, class Callee, class TMemFunc>
class TMemberTranslatorV3 : public TFunctorV3<P1,P2,P3>
{
  public:
    TMemberTranslatorV3(Callee& c, const TMemFunc& mf)
      : TFunctorV3<P1,P2,P3>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)(p1, p2, p3);
    }
};

template <class P1, class P2, class P3,
          class TRT, class TP1, class TP2, class TP3>
inline TFunctionTranslatorV3<P1, P2, P3, TRT(*)(TP1,TP2,TP3)>
Functor(TFunctorV3<P1,P2,P3>*, TRT(*f)(TP1,TP2,TP3))
{
  return TFunctionTranslatorV3<P1, P2, P3, TRT(*)(TP1,TP2,TP3)>(f);
}

template <class P1, class P2, class P3,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3>
inline TMemberTranslatorV3<P1, P2, P3, Callee, TRT(CallType::*)(TP1,TP2,TP3)>
Functor(TFunctorV3<P1,P2,P3>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3);
  return TMemberTranslatorV3<P1, P2, P3, Callee, TMemFunc>(c,f);
}

template <class P1, class P2, class P3,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3>
inline TMemberTranslatorV3<P1, P2, P3, const Callee, TRT(CallType::*)(TP1,TP2,TP3) const>
Functor(TFunctorV3<P1,P2,P3>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3) const;
  return TMemberTranslatorV3<P1, P2, P3, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 3 parameters, return R

template <class R, class P1, class P2, class P3>
class TFunctor3 : protected TFunctorBase
{
  public:
    TFunctor3(/*TDummyInit* = 0*/) {}

    R operator()(P1 p1, P2 p2, P3 p3) const
    {
      return Thunk(*this, p1, p2, p3);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&, P1, P2, P3);
    TFunctor3(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class P1, class P2, class P3, class Func>
class TFunctionTranslator3 : public TFunctor3<R,P1,P2,P3>
{
  public:
    TFunctionTranslator3(Func f) : TFunctor3<R,P1,P2,P3>(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3)
    {
      return (Func(ftor.Func))(p1, p2, p3);
    }
};

template <class R, class P1, class P2, class P3, class Callee, class TMemFunc>
class TMemberTranslator3 : public TFunctor3<R,P1,P2,P3>
{
  public:
    TMemberTranslator3(Callee& c, const TMemFunc& mf)
      : TFunctor3<R,P1,P2,P3>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)(p1, p2, p3);
    }
};

template <class R, class P1, class P2, class P3,
          class TRT, class TP1, class TP2, class TP3>
inline TFunctionTranslator3<R,P1, P2, P3, TRT (*)(TP1,TP2,TP3)>
Functor(TFunctor3<R,P1,P2,P3>*, TRT(*f)(TP1,TP2,TP3))
{
  return TFunctionTranslator3<R, P1, P2, P3, TRT(*)(TP1,TP2,TP3)>(f);
}

template <class R, class P1, class P2, class P3,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3>
inline TMemberTranslator3<R,P1, P2, P3, Callee, TRT(CallType::*)(TP1,TP2,TP3)>
Functor(TFunctor3<R,P1,P2,P3>*, Callee& c, TRT (CallType::* const& f)(TP1,TP2,TP3))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3);
  return TMemberTranslator3<R, P1, P2, P3, Callee, TMemFunc>(c,f);
}

template <class R, class P1, class P2, class P3,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3>
inline TMemberTranslator3<R,P1, P2, P3, const Callee, TRT(CallType::*)(TP1,TP2,TP3) const>
Functor(TFunctor3<R,P1,P2,P3>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3) const;
  return TMemberTranslator3<R, P1, P2, P3, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 4 parameters, void return

template <class P1, class P2, class P3, class P4>
class TFunctorV4 : protected TFunctorBase
{
  public:
    TFunctorV4(/*TDummyInit* = 0*/) {}

    void operator()(P1 p1, P2 p2, P3 p3, P4 p4) const
    {
      Thunk(*this, p1, p2, p3, p4);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&, P1, P2, P3, P4);
    TFunctorV4(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class P1, class P2, class P3, class P4, class Func>
class TFunctionTranslatorV4 : public TFunctorV4<P1,P2,P3,P4>
{
  public:
    TFunctionTranslatorV4(Func f) : TFunctorV4<P1,P2,P3,P4>(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4)
    {
      (Func(ftor.Func))(p1, p2, p3, p4);
    }
};

template <class P1, class P2, class P3, class P4, class Callee, class TMemFunc>
class TMemberTranslatorV4 : public TFunctorV4<P1,P2,P3,P4>
{
  public:
    TMemberTranslatorV4(Callee& c, const TMemFunc& mf)
      : TFunctorV4<P1,P2,P3,P4>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)(p1, p2, p3, p4);
    }
};

template <class P1, class P2, class P3, class P4,
          class TRT, class TP1, class TP2, class TP3, class TP4>
inline TFunctionTranslatorV4<P1, P2, P3, P4, TRT(*)(TP1,TP2,TP3,TP4)>
Functor(TFunctorV4<P1,P2,P3,P4>*, TRT(*f)(TP1,TP2,TP3,TP4))
{
  return TFunctionTranslatorV4<P1, P2, P3, P4, TRT(*)(TP1,TP2,TP3,TP4)>(f);
}

template <class P1, class P2, class P3, class P4, class Callee,
          class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4>
inline TMemberTranslatorV4<P1, P2, P3, P4, Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4)>
Functor(TFunctorV4<P1,P2,P3,P4>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4);
  return TMemberTranslatorV4<P1, P2, P3, P4, Callee, TMemFunc>(c,f);
}

template <class P1, class P2, class P3, class P4,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4>
inline TMemberTranslatorV4<P1, P2, P3, P4, const Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4) const>
Functor(TFunctorV4<P1,P2,P3,P4>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4) const;
  return TMemberTranslatorV4<P1, P2, P3, P4, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 4 parameters, return R

template <class R, class P1, class P2, class P3, class P4>
class TFunctor4 : protected TFunctorBase
{
  public:
    TFunctor4(/*TDummyInit* = 0*/) {}

    R operator()(P1 p1, P2 p2, P3 p3, P4 p4) const
    {
      return Thunk(*this, p1, p2, p3, p4);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&, P1, P2, P3, P4);
    TFunctor4(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class P1, class P2, class P3, class P4, class Func>
class TFunctionTranslator4 : public TFunctor4<R,P1,P2,P3,P4>
{
  public:
    TFunctionTranslator4(Func f) : TFunctor4<R,P1,P2,P3,P4>(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4)
    {
      return (Func(ftor.Func))(p1, p2, p3, p4);
    }
};

template <class R, class P1, class P2, class P3, class P4, class Callee, class TMemFunc>
class TMemberTranslator4 : public TFunctor4<R,P1,P2,P3,P4>
{
  public:
    TMemberTranslator4(Callee& c, const TMemFunc& mf)
      : TFunctor4<R,P1,P2,P3,P4>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)(p1, p2, p3, p4);
    }
};

template <class R, class P1, class P2, class P3, class P4,
          class TRT, class TP1, class TP2, class TP3, class TP4>
inline TFunctionTranslator4<R, P1, P2, P3, P4, TRT(*)(TP1,TP2,TP3,TP4)>
Functor(TFunctor4<R,P1,P2,P3,P4>*, TRT(*f)(TP1,TP2,TP3,TP4))
{
  return TFunctionTranslator4<R, P1, P2, P3, P4, TRT(*)(TP1,TP2,TP3,TP4)>(f);
}

template <class R, class P1, class P2, class P3, class P4,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4>
inline TMemberTranslator4<R, P1, P2, P3, P4, Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4)>
Functor(TFunctor4<R,P1,P2,P3,P4>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4);
  return TMemberTranslator4<R, P1, P2, P3, P4, Callee, TMemFunc>(c,f);
}

template <class R, class P1, class P2, class P3, class P4,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4>
inline TMemberTranslator4<R, P1, P2, P3, P4, const Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4) const>
Functor(TFunctor4<R,P1,P2,P3,P4>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4) const;
  return TMemberTranslator4<R, P1, P2, P3, P4, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 5 parameters, void return

template <class P1, class P2, class P3, class P4, class P5>
class TFunctorV5 : protected TFunctorBase
{
  public:
    TFunctorV5(/*TDummyInit* = 0*/) {}

    void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) const
    {
      Thunk(*this, p1, p2, p3, p4, p5);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&, P1, P2, P3, P4, P5);
    TFunctorV5(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class P1, class P2, class P3, class P4, class P5, class Func>
class TFunctionTranslatorV5 : public TFunctorV5<P1,P2,P3,P4,P5>
{
  public:
    TFunctionTranslatorV5(Func f) : TFunctorV5<P1,P2,P3,P4,P5>(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      (Func(ftor.Func))(p1, p2, p3, p4, p5);
    }
};

template <class P1, class P2, class P3, class P4, class P5, class Callee, class TMemFunc>
class TMemberTranslatorV5 : public TFunctorV5<P1,P2,P3,P4,P5>
{
  public:
    TMemberTranslatorV5(Callee& c, const TMemFunc& mf)
      : TFunctorV5<P1,P2,P3,P4,P5>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)(p1, p2, p3, p4, p5);
    }
};

template <class P1, class P2, class P3, class P4, class P5,
          class TRT, class TP1, class TP2, class TP3, class TP4, class TP5>
inline TFunctionTranslatorV5<P1, P2, P3, P4, P5, TRT(*)(TP1,TP2,TP3,TP4,TP5)>
Functor(TFunctorV5<P1,P2,P3,P4,P5>*, TRT(*f)(TP1,TP2,TP3,TP4,TP5))
{
  return TFunctionTranslatorV5<P1, P2, P3, P4, P5, TRT(*)(TP1,TP2,TP3,TP4,TP5)>(f);
}

template <class P1, class P2, class P3, class P4, class P5,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5>
inline TMemberTranslatorV5<P1, P2, P3, P4, P5, Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5)>
Functor(TFunctorV5<P1,P2,P3,P4,P5>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5);
  return TMemberTranslatorV5<P1, P2, P3, P4, P5, Callee, TMemFunc>(c,f);
}

template <class P1, class P2, class P3, class P4, class P5,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5>
inline TMemberTranslatorV5<P1, P2, P3, P4, P5, const Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5) const>
Functor(TFunctorV5<P1,P2,P3,P4,P5>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5) const;
  return TMemberTranslatorV5<P1, P2, P3, P4, P5, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 5 parameters, return R

template <class R, class P1, class P2, class P3, class P4, class P5>
class TFunctor5 : protected TFunctorBase
{
  public:
    TFunctor5(/*TDummyInit* = 0*/) {}

    R operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5) const
    {
      return Thunk(*this, p1, p2, p3, p4, p5);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&, P1, P2, P3, P4, P5);
    TFunctor5(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class P1, class P2, class P3, class P4, class P5, class Func>
class TFunctionTranslator5 : public TFunctor5<R,P1,P2,P3,P4,P5>
{
  public:
    TFunctionTranslator5(Func f) : TFunctor5<R,P1,P2,P3,P4,P5>(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      return (Func(ftor.Func))(p1, p2, p3, p4, p5);
    }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class Callee, class TMemFunc>
class TMemberTranslator5 : public TFunctor5<R,P1,P2,P3,P4,P5>
{
  public:
    TMemberTranslator5(Callee& c, const TMemFunc& mf)
      : TFunctor5<R,P1,P2,P3,P4,P5>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)(p1, p2, p3, p4, p5);
    }
};

template <class R, class P1, class P2, class P3, class P4, class P5,
          class TRT, class TP1, class TP2, class TP3, class TP4, class TP5>
inline TFunctionTranslator5<R,P1, P2, P3, P4, P5, TRT(*)(TP1,TP2,TP3,TP4,TP5)>
Functor(TFunctor5<R,P1,P2,P3,P4,P5>*, TRT(*f)(TP1,TP2,TP3,TP4,TP5))
{
  return TFunctionTranslator5<R, P1, P2, P3, P4, P5, TRT(*)(TP1,TP2,TP3,TP4,TP5)>(f);
}

template <class R, class P1, class P2, class P3, class P4, class P5,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5>
inline TMemberTranslator5<R,P1, P2, P3, P4, P5, Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5)>
Functor(TFunctor5<R,P1,P2,P3,P4,P5>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5);
  return TMemberTranslator5<R, P1, P2, P3, P4, P5, Callee, TMemFunc>(c,f);
}

template <class R, class P1, class P2, class P3, class P4, class P5,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5>
inline TMemberTranslator5<R,P1, P2, P3, P4, P5, const Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5) const>
Functor(TFunctor5<R,P1,P2,P3,P4,P5>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5) const;
  return TMemberTranslator5<R, P1, P2, P3, P4, P5, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 6 parameters, void return

template <class P1, class P2, class P3, class P4, class P5, class P6>
class TFunctorV6 : protected TFunctorBase
{
  public:
    TFunctorV6(/*TDummyInit* = 0*/) {}

    void operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) const
    {
      Thunk(*this, p1, p2, p3, p4, p5, p6);
    }
    TFunctorBase::operator bool;

  protected:
    typedef void (*TThunk)(const TFunctorBase&, P1, P2, P3, P4, P5, P6);
    TFunctorV6(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class P1, class P2, class P3, class P4, class P5, class P6, class Func>
class TFunctionTranslatorV6 : public TFunctorV6<P1,P2,P3,P4,P5,P6>
{
  public:
    TFunctionTranslatorV6(Func f) : TFunctorV6<P1,P2,P3,P4,P5,P6>(Thunk,0,f,0) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
    {
      (Func(ftor.Func))(p1, p2, p3, p4, p5, p6);
    }
};

template <class P1, class P2, class P3, class P4, class P5, class P6, class Callee, class TMemFunc>
class TMemberTranslatorV6 : public TFunctorV6<P1,P2,P3,P4,P5,P6>
{
  public:
    TMemberTranslatorV6(Callee& c, const TMemFunc& mf)
      : TFunctorV6<P1,P2,P3,P4,P5,P6>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static void Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      (callee->*memFunc)(p1, p2, p3, p4, p5, p6);
    }
};

template <class P1, class P2, class P3, class P4, class P5, class P6,
          class TRT, class TP1, class TP2, class TP3, class TP4, class TP5, class TP6>
inline TFunctionTranslatorV6<P1, P2, P3, P4, P5, P6, TRT(*)(TP1,TP2,TP3,TP4,TP5,TP6)>
Functor(TFunctorV6<P1,P2,P3,P4,P5,P6>*, TRT(*f)(TP1,TP2,TP3,TP4,TP5,TP6))
{
  return TFunctionTranslatorV6<P1, P2, P3, P4, P5, P6, TRT(*)(TP1,TP2,TP3,TP4,TP5,TP6)>(f);
}

template <class P1, class P2, class P3, class P4, class P5, class P6,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5, class TP6>
inline TMemberTranslatorV6<P1, P2, P3, P4, P5, P6, Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5,TP6)>
Functor(TFunctorV6<P1,P2,P3,P4,P5,P6>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5,TP6))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5,TP6);
  return TMemberTranslatorV6<P1, P2, P3, P4, P5, P6, Callee, TMemFunc>(c,f);
}

template <class P1, class P2, class P3, class P4, class P5, class P6,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5, class TP6>
inline TMemberTranslatorV6<P1, P2, P3, P4, P5, P6, const Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5,TP6) const>
Functor(TFunctorV6<P1,P2,P3,P4,P5,P6>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5,TP6) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5,TP6) const;
  return TMemberTranslatorV6<P1, P2, P3, P4, P5, P6, const Callee, TMemFunc>(c,f);
}

//-----------------------------------------------------------------------------
// Functor with 6 parameters, return R

template <class R, class P1, class P2, class P3, class P4, class P5, class P6>
class TFunctor6 : protected TFunctorBase
{
  public:
    TFunctor6(/*TDummyInit* = 0*/) {}

    R operator()(P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6) const
    {
      return Thunk(*this, p1, p2, p3, p4, p5, p6);
    }
    TFunctorBase::operator bool;

  protected:
    typedef R (*TThunk)(const TFunctorBase&, P1, P2, P3, P4, P5, P6);
    TFunctor6(const TThunk& t, const void* c, const void* f, size_t sz)
      : TFunctorBase(c,f,sz), Thunk(t) {}

  private:
    TThunk Thunk;
};

template <class R, class P1, class P2, class P3, class P4, class P5, class P6, class Func>
class TFunctionTranslator6 : public TFunctor6<R,P1,P2,P3,P4,P5,P6>
{
  public:
    TFunctionTranslator6(Func f) : TFunctor6<R,P1,P2,P3,P4,P5,P6>(Thunk,0,f,0) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
    {
      return (Func(ftor.Func))(p1, p2, p3, p4, p5, p6);
    }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class P6, class Callee, class TMemFunc>
class TMemberTranslator6 : public TFunctor6<R,P1,P2,P3,P4,P5,P6>
{
  public:
    TMemberTranslator6(Callee& c, const TMemFunc& mf)
      : TFunctor6<R,P1,P2,P3,P4,P5,P6>(Thunk, &c, &mf, sizeof(TMemFunc)) {}

    static R Thunk(const TFunctorBase& ftor, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
    {
      Callee* callee = reinterpret_cast<Callee*>(ftor.Callee);
      TMemFunc& memFunc(*(TMemFunc*)(void*)ftor.MemberFunc);
      return (callee->*memFunc)(p1, p2, p3, p4, p5, p6);
    }
};

template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class TRT, class TP1, class TP2, class TP3, class TP4, class TP5, class TP6>
inline TFunctionTranslator6<R,P1, P2, P3, P4, P5, P6, TRT(*)(TP1,TP2,TP3,TP4,TP5,TP6)>
Functor(TFunctor6<R,P1,P2,P3,P4,P5,P6>*, TRT(*f)(TP1,TP2,TP3,TP4,TP5,TP6))
{
  return TFunctionTranslator6<R, P1, P2, P3, P4, P5, P6, TRT(*)(TP1,TP2,TP3,TP4,TP5,TP6)>(f);
}

template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5, class TP6>
inline TMemberTranslator6<R,P1, P2, P3, P4, P5, P6, Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5,TP6)>
Functor(TFunctor6<R,P1,P2,P3,P4,P5,P6>*, Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5,TP6))
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5,TP6);
  return TMemberTranslator6<R, P1, P2, P3, P4, P5, P6, Callee, TMemFunc>(c,f);
}

template <class R, class P1, class P2, class P3, class P4, class P5, class P6,
          class Callee, class TRT, class CallType,
          class TP1, class TP2, class TP3, class TP4, class TP5, class TP6>
inline TMemberTranslator6<R,P1, P2, P3, P4, P5, P6, const Callee, TRT(CallType::*)(TP1,TP2,TP3,TP4,TP5,TP6) const>
Functor(TFunctor6<R,P1,P2,P3,P4,P5,P6>*, const Callee& c, TRT(CallType::* const& f)(TP1,TP2,TP3,TP4,TP5,TP6) const)
{
  typedef TRT (CallType::*TMemFunc)(TP1,TP2,TP3,TP4,TP5,TP6) const;
  return TMemberTranslator6<R, P1, P2, P3, P4, P5, P6, const Callee, TMemFunc>(c,f);
}

#endif // BDTF_H
