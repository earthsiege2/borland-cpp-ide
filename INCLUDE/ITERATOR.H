#ifndef __STD_ITERATOR__
#define __STD_ITERATOR__
/* $Revision:   8.1  $ */

/***************************************************************************
 *
 * iterator - iterator declarations for the Standard Library
 *
 * $Id: iterator,v 1.32 1995/10/03 17:39:30 lijewski Exp $
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

#ifndef RWSTD_NO_NEW_HEADER
#include <cstddef>
#else
#include <stddef.h>
#endif

#ifdef RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif

#include <function>

#ifdef RWSTD_NO_BASE_CLASS_MATCH
#define RWSTD_VALUE_TYPE(a) value_type(*(a))
#else
#define RWSTD_VALUE_TYPE(a) value_type(a)
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Standard iterator tags.
//

struct input_iterator_tag
{
    input_iterator_tag() {;}
};

struct output_iterator_tag
{
    output_iterator_tag() {;}
};

struct forward_iterator_tag
{
    forward_iterator_tag() {;}
};

struct bidirectional_iterator_tag
{
    bidirectional_iterator_tag() {;}
};

struct random_access_iterator_tag
{
    random_access_iterator_tag() {;}
};

//
// Basic iterators.
//

template <class T, class Distance> struct input_iterator
{
#ifdef RWSTD_NO_BASE_CLASS_MATCH
    T* operator* () { return (T*)(0); }
#endif
};

struct output_iterator {};
template <class T, class Distance> struct forward_iterator
{
#ifdef RWSTD_NO_BASE_CLASS_MATCH
    T* operator* () { return (T*)(0); }
#endif
};

template <class T, class Distance> struct bidirectional_iterator
{
#ifdef RWSTD_NO_BASE_CLASS_MATCH
    T* operator* () { return (T*)(0); }
#endif
};

template <class T, class Distance> struct random_access_iterator
{
#ifdef RWSTD_NO_BASE_CLASS_MATCH
    T* operator* () { return (T*)(0); }
#endif
};

//
// Iterator category.
//

template <class T, class Distance>
inline input_iterator_tag
iterator_category (const input_iterator<T, Distance>&)
{
    return input_iterator_tag();
}

inline output_iterator_tag iterator_category (const output_iterator&)
{
    return output_iterator_tag();
}

template <class T, class Distance>
inline forward_iterator_tag
iterator_category (const forward_iterator<T, Distance>&)
{
    return forward_iterator_tag();
}

template <class T, class Distance>
inline bidirectional_iterator_tag
iterator_category (const bidirectional_iterator<T, Distance>&)
{
    return bidirectional_iterator_tag();
}

template <class T, class Distance>
inline random_access_iterator_tag
iterator_category (const random_access_iterator<T, Distance>&)
{
    return random_access_iterator_tag();
}

template <class T>
inline random_access_iterator_tag iterator_category (const T*)
{
    return random_access_iterator_tag();
}

//
// Value type.
//

#ifndef RWSTD_NO_BASE_CLASS_MATCH
template <class T, class Distance>
inline T* value_type (const input_iterator<T, Distance>&)
{
    return (T*)(0);
}

template <class T, class Distance>
inline T* value_type (const forward_iterator<T, Distance>&)
{
    return (T*)(0);
}

template <class T, class Distance>
inline T* value_type (const bidirectional_iterator<T, Distance>&)
{
    return (T*)(0);
}

template <class T, class Distance>
inline T* value_type (const random_access_iterator<T, Distance>&)
{
    return (T*)(0);
}

template <class T>
inline T* value_type (const T*) { return (T*)(0); }
#else
template <class T>
inline T* value_type (const T) { return (T*)(0); }
#endif

//
// Distance type.
//

#ifndef RWSTD_NO_BASE_CLASS_MATCH
template <class T, class Distance>
inline Distance* distance_type (const input_iterator<T, Distance>&)
{
    return (Distance*)(0);
}

template <class T, class Distance>
inline Distance* distance_type (const forward_iterator<T, Distance>&)
{
    return (Distance*)(0);
}

template <class T, class Distance>
inline Distance*
distance_type (const bidirectional_iterator<T, Distance>&)
{
    return (Distance*)(0);
}

template <class T, class Distance>
inline Distance*
distance_type (const random_access_iterator<T, Distance>&)
{
    return (Distance*)(0);
}

template <class T>
inline ptrdiff_t* distance_type (const T*) { return (ptrdiff_t*)(0); }
#else
template <class T>
inline ptrdiff_t* distance_type (const T)  { return (ptrdiff_t*)(0); }
#endif

//
// Iterator operations.
//

template <class InputIterator, class Distance>
void __distance (InputIterator first, InputIterator last, Distance& n,
                 input_iterator_tag)
{
    while (first != last) { ++first; ++n; }
}

template <class ForwardIterator, class Distance>
void __distance (ForwardIterator first, ForwardIterator last, Distance& n,
                 forward_iterator_tag)
{
    while (first != last) { ++first; ++n; }
}

template <class BidirectionalIterator, class Distance>
void __distance (BidirectionalIterator first, BidirectionalIterator last,
                 Distance& n, bidirectional_iterator_tag)
{
    while (first != last) { ++first; ++n; }
}

template <class RandomAccessIterator, class Distance>
inline void __distance (RandomAccessIterator first, RandomAccessIterator last,
                        Distance& n, random_access_iterator_tag)
{
    n = last - first;
}

template <class InputIterator, class Distance>
inline void distance (InputIterator first, InputIterator last, Distance& n)
{
#ifndef RWSTD_NO_BASE_CLASS_MATCH
    __distance(first, last, n, iterator_category(first));
#else
    __distance(first, last, n, input_iterator_tag());
#endif
}

#ifdef RWSTD_NO_BASE_CLASS_MATCH
//
// We include assert() to test for possible problem in advance().
// Furthermore, we FORCE assert() to always expand.
//
#ifdef  NDEBUG
#define __RW_NDEBUG
#undef  NDEBUG
#endif
#ifndef RWSTD_NO_NEW_HEADER
#include <cassert>
#else
#include <assert.h>
#endif

#endif /*RWSTD_NO_BASE_CLASS_MATCH*/

template <class InputIterator, class Distance>
void __advance (InputIterator& i, Distance n, input_iterator_tag)
{
#ifdef RWSTD_NO_BASE_CLASS_MATCH
    //
    // All uses of advance() end up calling this template, even
    // when advance() is being invoked on a bidirectional or random
    // iterator.  We need to check that n is non-negative, or else
    // this algorithm will fail horribly.  We MUST document the
    // restriction that advance() only be called with non-negative
    // Distance.  There don't appear to be any explicit uses of advance()
    // with a negative Distance argument in the STL library itself.
    //
    // This assert() is ALWAYS on -- see how it's included'd above.
    //
    assert(n >= 0);
#endif /*RWSTD_NO_BASE_CLASS_MATCH*/
    while (n--) ++i;
}

//
// Don't forget to turn off expansion of assert() if that's what the
// user expects.
//
#ifdef  __RW_NDEBUG
#define NDEBUG
#undef  __RW_NDEBUG
#endif

template <class ForwardIterator, class Distance>
void __advance (ForwardIterator& i, Distance n, forward_iterator_tag)
{
    while (n--) ++i;
}

template <class BidirectionalIterator, class Distance>
void __advance (BidirectionalIterator& i, Distance n,
                bidirectional_iterator_tag)
{
    if (n >= 0)
        while (n--) ++i;
    else
        while (n++) --i;
}

template <class RandomAccessIterator, class Distance>
inline void __advance (RandomAccessIterator& i, Distance n,
                       random_access_iterator_tag)
{
    i += n;
}

template <class InputIterator, class Distance>
inline void advance (InputIterator& i, Distance n)
{
#ifndef RWSTD_NO_BASE_CLASS_MATCH
    __advance(i, n, iterator_category(i));
#else
    __advance(i, n, input_iterator_tag());
#endif
}

//
// Reverse bidirectional iterator.
//

    //
    // Forward declarations.
    //

#ifdef RWSTD_NO_UNDECLARED_FRIEND
template <class BidirectionalIterator, class T, class Reference,
          class Distance> class reverse_bidirectional_iterator;

template <class BidirectionalIterator, class T, class Reference,
          class Distance>
bool operator== (
      const reverse_bidirectional_iterator<BidirectionalIterator, T, Reference,
                                           Distance>& x,
      const reverse_bidirectional_iterator<BidirectionalIterator, T, Reference,
                                           Distance>& y);
#endif

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template <class BidirectionalIterator, class T, class Reference = T&,
          class Distance = ptrdiff_t>
#else
template <class BidirectionalIterator, class T, class Reference,
          class Distance>
#endif

//
// Reference = T&
// Distance  = ptrdiff_t
//
class reverse_bidirectional_iterator
    : public bidirectional_iterator<T,Distance>
{
    typedef reverse_bidirectional_iterator<BidirectionalIterator, T, Reference,
                                           Distance> self;
    friend bool operator== (const self& x, const self& y);

  protected:

    BidirectionalIterator current;

  public:

    reverse_bidirectional_iterator() {}
    explicit reverse_bidirectional_iterator (BidirectionalIterator x)
        : current(x) {}
    BidirectionalIterator base() { return current; }
    Reference operator* () const
    {
        BidirectionalIterator tmp = current; return *--tmp;
    }
    self& operator++ ()    { --current; return *this;                 }
    self  operator++ (int) { self tmp = *this; --current; return tmp; }
    self& operator-- ()    { ++current; return *this;                 }
    self  operator-- (int) { self tmp = *this; ++current; return tmp; }
};

template <class BidirectionalIterator, class T, class Reference,
          class Distance>
inline bool operator== (
    const reverse_bidirectional_iterator<BidirectionalIterator, T, Reference,
                                         Distance>& x,
    const reverse_bidirectional_iterator<BidirectionalIterator, T, Reference,
                                         Distance>& y)
{
    return x.current == y.current;
}

//
// Reverse iterator.
//

    //
    // Forward Declarations.
    //
#ifdef RWSTD_NO_UNDECLARED_FRIEND
template <class RandomAccessIterator, class T, class Reference,
          class Distance>  class reverse_iterator;

template <class RandomAccessIterator, class T, class Reference, class Distance>
bool operator== (const reverse_iterator<RandomAccessIterator, T,
                 Reference, Distance>& x,
                 const reverse_iterator<RandomAccessIterator, T,
                 Reference, Distance>& y);

template <class RandomAccessIterator, class T, class Reference, class Distance>
bool operator< (const reverse_iterator<RandomAccessIterator, T,
                Reference, Distance>& x,
                const reverse_iterator<RandomAccessIterator, T,
                Reference, Distance>& y);

template <class RandomAccessIterator, class T, class Reference, class Distance>
Distance operator- (const reverse_iterator<RandomAccessIterator, T,
                    Reference, Distance>& x,
                    const reverse_iterator<RandomAccessIterator, T,
                    Reference, Distance>& y);

template <class RandomAccessIterator, class T, class Reference, class Distance>
reverse_iterator<RandomAccessIterator, T, Reference, Distance>
operator+ (Distance n,
      const reverse_iterator<RandomAccessIterator, T, Reference, Distance>& x);
#endif

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template <class RandomAccessIterator, class T, class Reference = T&,
          class Distance = ptrdiff_t>
#else
template <class RandomAccessIterator, class T, class Reference,
          class Distance>
#endif

//
// Reference = T&
// Distance  = ptrdiff_t
//
class reverse_iterator : public random_access_iterator<T, Distance>
{
    typedef reverse_iterator<RandomAccessIterator,T,Reference,Distance> self;

    friend bool operator==    (const self& x, const self& y);
    friend bool operator<     (const self& x, const self& y);
    friend Distance operator- (const self& x, const self& y);
    friend self operator+     (Distance n, const self& x);

  protected:

    RandomAccessIterator current;

  public:

    reverse_iterator() {}
    explicit reverse_iterator (RandomAccessIterator x) : current(x) {}
    RandomAccessIterator base () { return current; }
    Reference operator* () const { return *(current - 1); }

    self& operator++ ()    { --current; return *this;                 }
    self  operator++ (int) { self tmp = *this; --current; return tmp; }
    self& operator-- ()    { ++current; return *this;                 }
    self  operator-- (int) { self tmp = *this; ++current; return tmp; }

    self  operator+  (Distance n) const { self tmp(current - n); return tmp; }
    self& operator+= (Distance n)       { current -= n; return *this;        }
    self  operator-  (Distance n) const { self tmp(current + n); return tmp; }
    self& operator-= (Distance n)       { current += n; return *this;        }

    Reference operator[] (Distance n) { return *(*this + n); }
};

template <class RandomAccessIterator, class T, class Reference, class Distance>
inline bool operator== (const reverse_iterator<RandomAccessIterator, T,
                        Reference, Distance>& x,
                        const reverse_iterator<RandomAccessIterator, T,
                        Reference, Distance>& y)
{
    return x.current == y.current;
}

template <class RandomAccessIterator, class T, class Reference, class Distance>
inline bool operator< (const reverse_iterator<RandomAccessIterator, T,
                       Reference, Distance>& x,
                       const reverse_iterator<RandomAccessIterator, T,
                       Reference, Distance>& y)
{
    return y.current < x.current;
}

template <class RandomAccessIterator, class T, class Reference, class Distance>
inline Distance operator- (const reverse_iterator<RandomAccessIterator, T,
                           Reference, Distance>& x,
                           const reverse_iterator<RandomAccessIterator, T,
                           Reference, Distance>& y)
{
    return y.current - x.current;
}

template <class RandomAccessIterator, class T, class Reference, class Distance>
inline reverse_iterator<RandomAccessIterator, T, Reference, Distance>
operator+ (Distance n, const reverse_iterator<RandomAccessIterator, T,
           Reference, Distance>& x)
{
    return reverse_iterator<RandomAccessIterator, T, Reference, Distance>
    (x.current - n);
}

//
// Back insert iterator.
//

template <class Container>
class back_insert_iterator : public output_iterator
{
  protected:

    Container& container;

  public:

    explicit back_insert_iterator (Container& x) : container(x) {}
    back_insert_iterator<Container>&
    operator= (const typename Container::value_type& value)
    {
        container.push_back(value); return *this;
    }
    back_insert_iterator<Container>& operator*  ()    { return *this; }
    back_insert_iterator<Container>& operator++ ()    { return *this; }
    back_insert_iterator<Container>& operator++ (int) { return *this; }
};

template <class Container>
inline back_insert_iterator<Container> back_inserter (Container& x)
{
    return back_insert_iterator<Container>(x);
}

//
// Front insert iterator.
//

template <class Container>
class front_insert_iterator : public output_iterator
{
  protected:

    Container& container;

  public:

    explicit front_insert_iterator (Container& x) : container(x) {}
    front_insert_iterator<Container>&
    operator= (const typename Container::value_type& value)
    {
        container.push_front(value); return *this;
    }
    front_insert_iterator<Container>& operator*  ()    { return *this; }
    front_insert_iterator<Container>& operator++ ()    { return *this; }
    front_insert_iterator<Container>& operator++ (int) { return *this; }
};

template <class Container>
inline front_insert_iterator<Container> front_inserter (Container& x)
{
    return front_insert_iterator<Container>(x);
}

//
// Insert iterator.
//

template <class Container>
class insert_iterator : public output_iterator
{
  protected:

    Container&                   container;
    typename Container::iterator iter;

  public:

    insert_iterator (Container& x, typename Container::iterator i)
        : container(x), iter(i) {}
    insert_iterator<Container>&
    operator= (const typename Container::value_type& value)
    {
        iter = container.insert(iter, value); ++iter; return *this;
    }
    insert_iterator<Container>& operator*  ()    { return *this; }
    insert_iterator<Container>& operator++ ()    { return *this; }
    insert_iterator<Container>& operator++ (int) { return *this; }
};

template <class Container, class Iterator>
inline insert_iterator<Container> inserter (Container& x, Iterator i)
{
    typename Container::iterator c(i);
    insert_iterator<Container> tmp(x, c);
    return tmp;
}

//
// Stream iterators.
//

#ifdef RWSTD_NO_UNDECLARED_FRIEND
template <class T, class Distance>
class istream_iterator;

template <class T, class Distance>
bool operator== (const istream_iterator<T, Distance>& x,
                 const istream_iterator<T, Distance>& y);
#endif

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template <class T, class Distance = ptrdiff_t> // Distance == ptrdiff_t
#else
template <class T, class Distance>             // Distance == ptrdiff_t
#endif
class istream_iterator : public input_iterator<T, Distance>
{
  friend bool operator== (const istream_iterator<T, Distance>& x,
                          const istream_iterator<T, Distance>& y);
protected:

    istream* stream;
    T        value;
    bool     end_marker;

    void read ()
    {
        end_marker = (*stream) ? true : false;
        if (end_marker) *stream >> value;
        end_marker = (*stream) ? true : false;
    }
public:

    istream_iterator () : stream(&cin), end_marker(false) {}
    istream_iterator (istream& s) : stream(&s) { read(); }
    const T& operator* () const { return value; }
    istream_iterator<T, Distance>& operator++ ()
    {
        read(); return *this;
    }
    istream_iterator<T, Distance> operator++ (int)
    {
        istream_iterator<T, Distance> tmp = *this; read(); return tmp;
    }
};

template <class T, class Distance>
inline bool operator== (const istream_iterator<T, Distance>& x,
                        const istream_iterator<T, Distance>& y)
{
    return x.stream == y.stream && x.end_marker == y.end_marker ||
           x.end_marker == false && y.end_marker == false;
}

template <class T>
class ostream_iterator : public output_iterator
{
protected:

    ostream* stream;
    char*    string;

public:

    ostream_iterator (ostream& s) : stream(&s), string(0) {}
    ostream_iterator (ostream& s, char* c) : stream(&s), string(c)  {}
    ostream_iterator<T>& operator= (const T& value)
    {
        *stream << value;
        if (string) *stream << string;
        return *this;
    }
    ostream_iterator<T>& operator*  ()    { return *this; }
    ostream_iterator<T>& operator++ ()    { return *this; }
    ostream_iterator<T>& operator++ (int) { return *this; }
};

//
// istreambuf_iterator and ostreambuf_iterator eventually go here.
//

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif
