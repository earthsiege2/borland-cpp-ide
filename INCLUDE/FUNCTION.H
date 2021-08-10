#ifndef __FUNCTION_H
#define __FUNCTION_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_FUNCTIONAL__
#define __STD_FUNCTIONAL__

/***************************************************************************
 *
 * functional - global template functions
 *
 ***************************************************************************
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-1999 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software – Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/

#include <stdcomp.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// The bases of many of the function objects here.
//

  template <class Arg, class Result>
  struct unary_function
  {
    typedef Arg argument_type;
    typedef Result result_type;
  };

  template <class Arg1, class Arg2, class Result>
  struct binary_function
  {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
  };

//
// Arithmetic operators.
//

  template <class T>
  struct plus : public binary_function<T, T, T>
  {
    typedef _TYPENAME binary_function<T, T, T>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::result_type result_type;
    T operator() (const T& x, const T& y) const { return x + y; }
  };

  template <class T>
  struct minus : public binary_function<T, T, T>
  {
    typedef _TYPENAME binary_function<T, T, T>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::result_type result_type;
    T operator() (const T& x, const T& y) const { return x - y; }
  };

  template <class T>
  struct multiplies : public binary_function<T, T, T>
  {
    typedef _TYPENAME binary_function<T, T, T>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::result_type result_type;
    T operator() (const T& x, const T& y) const { return x * y; }
  };

  template <class T>
  struct divides : public binary_function<T, T, T>
  {
    typedef _TYPENAME binary_function<T, T, T>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::result_type result_type;
    T operator() (const T& x, const T& y) const { return x / y; }
  };

  template <class T>
  struct modulus : public binary_function<T, T, T>
  {
    typedef _TYPENAME binary_function<T, T, T>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, T>::result_type result_type;
    T operator() (const T& x, const T& y) const { return x % y; }
  };

  template <class T>
  struct negate : public unary_function<T, T>
  {
    typedef _TYPENAME unary_function<T,T>::argument_type argument_type;
    typedef _TYPENAME unary_function<T,T>::result_type result_type;
    T operator() (const T& x) const { return -x; }
  };

//
// Comparisons.
//

  template <class T>
  struct equal_to : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x == y; }
  };

  template <class T>
  struct not_equal_to : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x != y; }
  };

  template <class T>
  struct greater : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x > y; }
  };

  template <class T>
  struct less : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x < y; }
  };

  template <class T>
  struct greater_equal : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x >= y; }
  };

  template <class T>
  struct less_equal : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x <= y; }
  };

//
// Logical operations.
//

  template <class T>
  struct logical_and : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x && y; }
  };

  template <class T>
  struct logical_or : public binary_function<T, T, bool>
  {
    typedef _TYPENAME binary_function<T, T, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<T, T, bool>::result_type result_type;
    bool operator() (const T& x, const T& y) const { return x || y; }
  };

  template <class T>
  struct logical_not : public unary_function<T, bool>
  {
    typedef _TYPENAME unary_function<T,bool>::argument_type argument_type;
    typedef _TYPENAME unary_function<T,bool>::result_type result_type;
    bool operator() (const T& x) const { return !x; }
  };

//
// Negators.
//

  template <class Predicate>
  class unary_negate : public unary_function<_TYPENAME Predicate::argument_type,
  bool>
  {
  protected:
    Predicate pred;
  public:
    typedef _TYPENAME unary_function<_TYPENAME Predicate::argument_type,bool>::argument_type argument_type;
    typedef _TYPENAME unary_function<_TYPENAME Predicate::argument_type,bool>::result_type result_type;
    _EXPLICIT unary_negate (const Predicate& x) : pred(x) {}
    bool operator() (const _TYPENAME unary_function<
                     _TYPENAME Predicate::argument_type,bool>::argument_type& x) const
    { return !pred(x); }
  };

  template <class Predicate>
  inline unary_negate<Predicate> not1(const Predicate& pred)
  {
    return unary_negate<Predicate>(pred);
  }

  template <class Predicate> 
  class binary_negate
    : public binary_function<_TYPENAME Predicate::first_argument_type,
  _TYPENAME Predicate::second_argument_type, bool>
  {
  protected:
    Predicate pred;
  public:
    typedef _TYPENAME binary_function<_TYPENAME Predicate::first_argument_type,
    _TYPENAME Predicate::second_argument_type, bool>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<_TYPENAME Predicate::first_argument_type,
    _TYPENAME Predicate::second_argument_type, bool>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<_TYPENAME Predicate::first_argument_type,
    _TYPENAME Predicate::second_argument_type, bool>::result_type result_type;
    _EXPLICIT binary_negate (const Predicate& x) : pred(x) {}
    bool operator() (const _TYPENAME binary_function<_TYPENAME Predicate::first_argument_type,
                     _TYPENAME Predicate::second_argument_type, bool>::first_argument_type& x, 
                     const _TYPENAME binary_function<_TYPENAME Predicate::first_argument_type,
                     _TYPENAME Predicate::second_argument_type, bool>::second_argument_type& y) const
    {
      return !pred(x, y); 
    }
  };

  template <class Predicate>
  inline binary_negate<Predicate> not2(const Predicate& pred)
  {
    return binary_negate<Predicate>(pred);
  }

//
// Binders.
//

  template <class Operation> 
  class binder1st :public unary_function<_TYPENAME Operation::second_argument_type,
  _TYPENAME Operation::result_type>
  {
  protected:
    Operation op;
    _TYPENAME Operation::first_argument_type value;
  public:
    typedef _TYPENAME unary_function<_TYPENAME Operation::second_argument_type,
    _TYPENAME Operation::result_type>::argument_type argument_type;
    typedef _TYPENAME unary_function<_TYPENAME Operation::second_argument_type,
    _TYPENAME Operation::result_type>::result_type result_type;
    binder1st (const Operation& x,
               const _TYPENAME Operation::first_argument_type& y)
      : op(x), value(y) {}
    _TYPENAME unary_function<_TYPENAME Operation::second_argument_type,
      _TYPENAME Operation::result_type>::result_type
    operator() (const _TYPENAME unary_function<_TYPENAME Operation::second_argument_type,
                _TYPENAME Operation::result_type>::argument_type& x) const
    {
      return op(value, x); 
    }
  };

  template <class Operation, class T>
  inline binder1st<Operation> bind1st (const Operation& op, const T& x)
  {
    typedef _TYPENAME Operation::first_argument_type the_argument_type;
    return binder1st<Operation>(op, the_argument_type(x));
  }

  template <class Operation> 
  class binder2nd : public unary_function<_TYPENAME Operation::first_argument_type,
  _TYPENAME Operation::result_type>
  {
  protected:
    Operation op;
    _TYPENAME Operation::second_argument_type value;
  public:
    typedef _TYPENAME unary_function<_TYPENAME Operation::first_argument_type,
    _TYPENAME Operation::result_type>::argument_type argument_type;
    typedef _TYPENAME unary_function<_TYPENAME Operation::first_argument_type,
    _TYPENAME Operation::result_type>::result_type result_type;
    binder2nd (const Operation& x,
               const _TYPENAME Operation::second_argument_type& y) 
      : op(x), value(y) {}
    _TYPENAME unary_function<_TYPENAME Operation::first_argument_type,
      _TYPENAME Operation::result_type>::result_type
    operator() (const _TYPENAME unary_function<_TYPENAME Operation::first_argument_type,
                _TYPENAME Operation::result_type>::argument_type& x) const
    {
      return op(x, value); 
    }
  };

  template <class Operation, class T>
  inline binder2nd<Operation> bind2nd (const Operation& op, const T& x)
  {
    typedef _TYPENAME Operation::second_argument_type the_argument_type;
    return binder2nd<Operation>(op, the_argument_type(x));
  }
//
// Adaptors.
//

  template <class Arg, class Result>
  class pointer_to_unary_function : public unary_function<Arg, Result>
  {
  protected:
    Result (*ptr)(Arg);
  public:
    typedef _TYPENAME unary_function<Arg,Result>::argument_type argument_type;
    typedef _TYPENAME unary_function<Arg,Result>::result_type result_type;
    _EXPLICIT pointer_to_unary_function (Result (*x)(Arg)) : ptr(x) {}
    Result operator() (Arg x) const { return ptr(x); }
  };

  template <class Arg, class Result>
  inline pointer_to_unary_function<Arg, Result> ptr_fun(Result (*x)(Arg))
  {
    return pointer_to_unary_function<Arg, Result>(x);
  }

  template <class Arg1, class Arg2, class Result>
  class pointer_to_binary_function : public binary_function<Arg1, Arg2, Result>
  {
  protected:
    Result (*ptr)(Arg1, Arg2);
  public:
    typedef _TYPENAME binary_function<Arg1, Arg2, Result>::second_argument_type second_argument_type;
    typedef _TYPENAME binary_function<Arg1, Arg2, Result>::first_argument_type first_argument_type;
    typedef _TYPENAME binary_function<Arg1, Arg2, Result>::result_type result_type;
    _EXPLICIT pointer_to_binary_function (Result (*x)(Arg1, Arg2)) : ptr(x) {}
    Result operator() (Arg1 x, Arg2 y) const
    {
      return ptr(x, y); 
    }
  };

  template <class Arg1, class Arg2, class Result>
  inline pointer_to_binary_function<Arg1, Arg2, Result> 
  ptr_fun(Result (*x)(Arg1, Arg2))
  {
    return pointer_to_binary_function<Arg1, Arg2, Result>(x);
  }

//
// Pointer to member function adaptors
//
// mem_fun_t, mem_fun1_t
//

  template <class S, class T> 
  class mem_fun_t  : public unary_function<T*,S>
  {
    S (T::*pmf)();

  public:
    _EXPLICIT mem_fun_t(S (T::*p)()) : pmf(p)
    { ; }
    S operator()(T* p) const
    { return (p->*pmf)(); }
  };
  template <class S, class T, class A> 
  class mem_fun1_t : public binary_function<T*,A,S>
  {
    S (T::*pmf)(A);

  public:
    _EXPLICIT mem_fun1_t(S (T::*p)(A)) : pmf(p)
    { ; }
    S operator()(T* p, A a) const
    { return (p->*pmf)(a); }
  };

  template <class S, class T> 
  inline mem_fun_t<S,T> mem_fun(S (T::*f)())
  {
    return mem_fun_t<S,T>(f);
  }

  template <class S, class T, class A> 
  inline mem_fun1_t<S,T,A> mem_fun(S (T::*f)(A))
  {
    return mem_fun1_t<S,T,A>(f);
  }

//
// mem_fun_ref_t, mem_fun1_ref_t
//

  template <class S, class T> 
  class mem_fun_ref_t  : public unary_function<T,S>
  {
    S (T::*pmf)();

  public:
    _EXPLICIT mem_fun_ref_t(S (T::*p)()) : pmf(p)
    { ; }
    S operator()(T& p) const
    { return (p.*pmf)(); }
  };
  template <class S, class T, class A> 
  class mem_fun1_ref_t : public binary_function<T,A,S>
  {
    S (T::*pmf)(A);

  public:
    _EXPLICIT mem_fun1_ref_t(S (T::*p)(A)) : pmf(p) 
    { ; }
    S operator()(T& p, A a) const
    { return (p.*pmf)(a); }
  };

  template <class S, class T> 
  inline mem_fun_ref_t<S,T> mem_fun_ref(S (T::*f)())
  {
    return mem_fun_ref_t<S,T>(f);
  }

  template <class S, class T, class A> 
  inline mem_fun1_ref_t<S,T,A> mem_fun_ref(S (T::*f)(A))
  {
    return mem_fun1_ref_t<S,T,A>(f);
  }

  // 
  // const_mem_fun_t and const_mem_fun1_t
  //

  template <class S, class T> 
  class const_mem_fun_t  : public unary_function<T*,S>
  {
    S (T::*pmf)() const;

  public:
    _EXPLICIT const_mem_fun_t(S (T::*p)() const) : pmf(p)
    { ; }
    S operator()(const T* p) const
    { return (p->*pmf)(); }
  };
  template <class S, class T, class A> 
  class const_mem_fun1_t : public binary_function<T*,A,S>
  {
    S (T::*pmf)(A) const;

  public:
    _EXPLICIT const_mem_fun1_t(S (T::*p)(A) const) : pmf(p)
    { ; }
    S operator()(const T* p, A a) const
    { return (p->*pmf)(a); }
  };

  template <class S, class T> 
  inline const_mem_fun_t<S,T> mem_fun(S (T::*f)() const)
  {
    return const_mem_fun_t<S,T>(f);
  }

  template <class S, class T, class A> 
  inline const_mem_fun1_t<S,T,A> mem_fun(S (T::*f)(A) const)
  {
    return const_mem_fun1_t<S,T,A>(f);
  }

//
// const_mem_fun_ref_t, const_mem_fun1_ref_t
//

  template <class S, class T> 
  class const_mem_fun_ref_t  : public unary_function<T,S>
  {
    S (T::*pmf)() const;

  public:
    _EXPLICIT const_mem_fun_ref_t(S (T::*p)() const) : pmf(p)
    { ; }
    S operator()(const T& p) const
    { return (p.*pmf)(); }
  };
  template <class S, class T, class A> 
  class const_mem_fun1_ref_t : public binary_function<T,A,S>
  {
    S (T::*pmf)(A) const;

  public:
    _EXPLICIT const_mem_fun1_ref_t(S (T::*p)(A) const) : pmf(p) 
    { ; }
    S operator()(const T& p, A a) const
    { return (p.*pmf)(a); }
  };

  template <class S, class T> 
  inline const_mem_fun_ref_t<S,T> mem_fun_ref(S (T::*f)() const)
  {
    return const_mem_fun_ref_t<S,T>(f);
  }

  template <class S, class T, class A> 
  inline const_mem_fun1_ref_t<S,T,A> mem_fun_ref(S (T::*f)(A) const)
  {
    return const_mem_fun1_ref_t<S,T,A>(f);
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif /*__STD_FUNCTIONAL__*/
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __FUNCTION_H */
