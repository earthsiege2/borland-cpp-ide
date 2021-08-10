#ifndef __STD_QUEUE__
#define __STD_QUEUE__

/***************************************************************************
 *
 * queue - declarations for the Standard Library queue classes
 *
 * $Id: queue,v 1.18 1995/09/11 18:56:24 lijewski Exp $
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
 * (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 *
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#include <stdcomp.h>

#include <algorith>
#include <deque>

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifdef RWSTD_NO_UNDECLARED_FRIEND
template <class T, class Container> class queue;

template <class T, class Container>
bool operator== (const queue<T,Container>& x, const queue<T,Container>& y);

template <class T, class Container>
bool operator< (const queue<T,Container>& x, const queue<T,Container>& y);
#endif

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template <class T, class Container = deque<T> >
#else
template <class T, class Container>
#endif
class queue
{
    friend bool operator== (const queue<T,Container>& x,
                            const queue<T,Container>& y);
    friend bool operator<  (const queue<T,Container>& x,
                            const queue<T,Container>& y);
  public:

    typedef typename Container::value_type value_type;
    typedef typename Container::size_type  size_type;

  protected:

    Container c;

  public:

    bool                  empty () const              { return c.empty(); }
    size_type             size  () const              { return c.size();  }
    value_type&           front ()                    { return c.front(); }
    const value_type&     front () const              { return c.front(); }
    value_type&           back  ()                    { return c.back();  }
    const value_type&     back  () const              { return c.back();  }
    void                  push  (const value_type& x) { c.push_back(x);   }
    void                  pop   ()                    { c.pop_front();    }

};

template <class T, class Container>
inline bool operator== (const queue<T,Container>& x, const queue<T,Container>& y)
{
    return x.c == y.c;
}

template <class T, class Container>
inline bool operator< (const queue<T,Container>& x, const queue<T,Container>& y)
{
    return x.c < y.c;
}

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template<class T, class Container = vector<T>,
         class Compare = less<typename Container::value_type> >
#else
template <class T, class Container, class Compare>
#endif
class priority_queue
{
  public:

    typedef typename Container::value_type value_type;
    typedef typename Container::size_type  size_type;

  protected:

    Container c;
    Compare   comp;

  public:

    explicit priority_queue (const Compare& x = Compare()) : c(), comp(x) {}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class InputIterator>
    priority_queue (InputIterator first, InputIterator last,
                    const Compare& x = Compare()) : c(first, last), comp(x)
#else
    priority_queue (typename Container::const_iterator first,
                    typename Container::const_iterator last,
                    const Compare& x = Compare()) : c(first, last), comp(x)
#endif
    {
        make_heap(c.begin(), c.end(), comp);
    }


    bool                  empty () const { return c.empty(); }
    size_type             size  () const { return c.size();  }
    value_type&           top   ()       { return c.front(); }
    const value_type&     top   () const { return c.front(); }

    void push (const value_type& x)
    {
        c.push_back(x); push_heap(c.begin(), c.end(), comp);
    }
    void pop ()
    {
        pop_heap(c.begin(), c.end(), comp); c.pop_back();
    }
};

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif /* __STD_QUEUE__ */
