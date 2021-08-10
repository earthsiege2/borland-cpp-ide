#ifndef __QUEUE_H
#define __QUEUE_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_QUEUE__
#define __STD_QUEUE__

/***************************************************************************
 *
 * queue - declarations for the Standard Library queue classes
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

#include <algorithm>
#include <functional>
#include <deque>
#include <vector>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  template <class T, class Container _RWSTD_COMPLEX_DEFAULT(deque<T>) > 
  class queue;

#ifdef _RWSTD_NO_UNDEFINED_FRIEND
  template <class T, class Container>
  inline bool operator== (const queue<T,Container>& x, 
                          const queue<T,Container>& y);

  template <class T, class Container>
  inline bool operator< (const queue<T,Container>& x, 
                         const queue<T,Container>& y);
#endif

  template <class T, class Container>
  class queue
  {
#ifdef __TURBOC__
    friend bool (std::operator==) (const queue<T,Container>& x,
                            const queue<T,Container>& y);
    friend bool (std::operator<)  (const queue<T,Container>& x,
                            const queue<T,Container>& y);
#else
    friend bool operator== (const queue<T,Container>& x,
                            const queue<T,Container>& y);
    friend bool operator<  (const queue<T,Container>& x,
                            const queue<T,Container>& y);
#endif
  public:

    typedef _TYPENAME Container::value_type         value_type;
    typedef _TYPENAME Container::size_type          size_type;
    typedef _TYPENAME Container::reference          reference;
    typedef _TYPENAME Container::const_reference    const_reference;
    typedef Container                               container_type;

  protected:

    Container c;

  public:
    _EXPLICIT queue(const Container& co _RWSTD_DEFAULT_ARG(Container())) 
    : c(co)
    { ; }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    queue(void) : c(Container())
    { ; }
#endif

    bool                  empty () const              { return c.empty(); }
    size_type             size  () const              { return c.size();  }
    reference             front ()                    { return c.front(); }
    const_reference       front () const              { return c.front(); }
    reference             back  ()                    { return c.back();  }
    const_reference       back  () const              { return c.back();  }
    void                  push  (const value_type& x) { c.push_back(x);   }
    void                  pop   ()                    { c.pop_front();    }

  };

  template <class T, class Container>
  inline bool operator== (const queue<T,Container>& x, 
                          const queue<T,Container>& y)
  {
    return x.c == y.c;
  }

  template <class T, class Container>
  inline bool operator< (const queue<T,Container>& x, 
                         const queue<T,Container>& y)
  {
    return x.c < y.c;
  }

  template <class T, class Container>
  inline bool operator!= (const queue<T,Container>& x, 
                          const queue<T,Container>& y)
  {
    return !(x == y);
  }

  template <class T, class Container>
  inline bool operator> (const queue<T,Container>& x, 
                         const queue<T,Container>& y)
  {
    return y < x;
  }

  template <class T, class Container>
  inline bool operator>= (const queue<T,Container>& x, 
                          const queue<T,Container>& y)
  {
    return !(x < y);
  }

  template <class T, class Container>
  inline bool operator<= (const queue<T,Container>& x, 
                          const queue<T,Container>& y)
  {
    return !(y <  x);
  }

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  template<class T, class Container = vector<T>,
  class Compare = less<_TYPENAME Container::value_type> >
#else
  template <class T, class Container, class Compare> 
#endif
  class priority_queue
  {
  public:

    typedef _TYPENAME Container::value_type         value_type;
    typedef _TYPENAME Container::size_type          size_type;
    typedef _TYPENAME Container::const_reference    const_reference;
    typedef Container                               container_type;

  protected:

    Container c;
    Compare   comp;

  public:

    _EXPLICIT priority_queue (const Compare& x _RWSTD_DEFAULT_ARG(Compare()),
                              const Container& co _RWSTD_DEFAULT_ARG(Container())) 
      : c(co), comp(x) 
    { ; }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    priority_queue (void)
      : c(Container()), comp(Compare()) 
    { ; }

    _EXPLICIT priority_queue (const Compare& x _RWSTD_DEFAULT_ARG(Compare()))
      : c(Container()), comp(x) 
    { ; }
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class InputIterator>
    priority_queue (InputIterator first, InputIterator last, 
                    const Compare& x = Compare(),
					const Container& y = Container())
      : c(y), comp(x) 
    {
      c.insert(c.end(),first,last);
      make_heap(c.begin(), c.end(), comp);
    }
#else
    priority_queue (_TYPENAME Container::const_iterator first,
                    _TYPENAME Container::const_iterator last,
                    const Compare& x _RWSTD_DEFAULT_ARG(Compare()))

      : c(first, last, Container::allocator_type()), comp(x)
    {
      make_heap(c.begin(), c.end(), comp);
    }
#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    priority_queue (_TYPENAME Container::const_iterator first,
                    _TYPENAME Container::const_iterator last,
                    const Compare& x _RWSTD_DEFAULT_ARG(Compare()))
      : c(first, last, Container::allocator_type()), comp(x)
    {
      make_heap(c.begin(), c.end(), comp);
    }

    priority_queue (_TYPENAME Container::const_iterator first,
                    _TYPENAME Container::const_iterator last)
      : c(first, last, Container::allocator_type()), comp(Compare())
    {
      make_heap(c.begin(), c.end(), comp);
    }
#endif
#endif
    
    bool                  empty () const { return c.empty(); }
    size_type             size  () const { return c.size();  }
    const_reference       top   () const { return c.front(); }

    void push (const value_type& x)
    { 
      c.push_back(x); push_heap(c.begin(), c.end(), comp);
    }
    void pop ()
    {
      pop_heap(c.begin(), c.end(), comp); c.pop_back(); 
    }
  };

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif /* __STD_QUEUE__ */
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __QUEUE_H */
