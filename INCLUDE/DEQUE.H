/* $Revision:   8.1  $ */

/***************************************************************************
 *
 * deque - Declaration and definition for the Standard Library deque class
 *
 * $Id: deque,v 1.43 1995/09/29 04:16:00 hart Exp $
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

#ifndef __STD_DEQUE__
#define __STD_DEQUE__

#include <stddefs.h>

#include <stdcomp.h>
#include <function>
#include <algorith>
#include <iterator>

#ifndef Allocator
#define Allocator allocator
#include <memory>
#endif

#ifndef deque
#define deque deque
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

template <class T>
class  deque
{
  public:

    class  iterator;
    class  const_iterator;
    friend class iterator;
    friend class const_iterator;

  public:

    typedef T                             value_type;
    typedef Allocator<T>                  data_allocator_type;
    typedef Allocator<T>::pointer         pointer;
    typedef Allocator<T>::reference       reference;
    typedef Allocator<T>::const_reference const_reference;
    typedef Allocator<T>::size_type       size_type;
    typedef Allocator<T>::difference_type difference_type;
    typedef Allocator<pointer>            map_allocator_type;

  protected:

    data_allocator_type data_allocator;
    map_allocator_type  map_allocator;

    typedef Allocator<pointer>::pointer map_pointer;

    static size_type buffer_size ()
    {
        //
        // Each time we allocate memory we reserve space for
        // a chunk of objects of type T.  This is currently tuned to
        // allocate memory in 1K chunks, except for large objects.
        //
        return sizeof(T) >= 1024 ? 1 : 1024 / sizeof(T);
    }

  public:
    //
    // Definition of our iterator.
    //
    class iterator : public random_access_iterator<T, difference_type>
    {
        friend class deque<T>;
        friend class const_iterator;

      protected:

        pointer     current;
        pointer     first;
        pointer     last;
        map_pointer node;

        iterator (pointer x, map_pointer y)
            : current(x), first(*y), last(*y + buffer_size()), node(y) {}

      public:

        iterator () : current(0), first(0), last(0), node(0) {}
        reference operator* () const { return *current; }
        difference_type operator- (const iterator& x) const
        {
            return node == x.node
                ? current - x.current
                : difference_type(buffer_size() * (node - x.node - 1) +
                                  (current - first) + (x.last - x.current));
        }
        iterator& operator++ ()
        {
            if (++current == last)
            {
                first = *(++node);
                current = first;
                last = first + buffer_size();
            }
            return *this;
        }
        iterator operator++ (int)
        {
            iterator tmp = *this; ++*this; return tmp;
        }
        iterator& operator-- ()
        {
            if (current == first)
            {
                first = *(--node);
                last = first + buffer_size();
                current = last;
            }
            --current;
            return *this;
        }
        iterator operator-- (int)
        {
            iterator tmp = *this; --*this; return tmp;
        }
        iterator& operator+= (difference_type n)
        {
            difference_type offset = n + (current - first);
            difference_type num_node_to_jump = offset >= 0
                ? offset / buffer_size()
                : -((-offset + buffer_size() - 1) / buffer_size());
            if (num_node_to_jump == 0)
                current += n;
            else
            {
                node = node + num_node_to_jump;
                first = *node;
                last = first + buffer_size();
                current = first + (offset - num_node_to_jump * buffer_size());
            }
            return *this;
        }
        iterator& operator-= (difference_type n) { return *this += -n; }
        iterator operator+ (difference_type n) const
        {
            iterator tmp = *this; return tmp += n;
        }
        iterator operator- (difference_type n) const
        {
            iterator tmp = *this; return tmp -= n;
        }
        reference operator[] (difference_type n) { return *(*this + n); }
        bool operator== (const iterator& x) const
        {
            return current == x.current ||
                ((current == first || x.current == x.first) &&
                 *this - x == 0);
        }
        bool operator< (const iterator& x) const
        {
            return (node == x.node) ? (current < x.current) : (node < x.node);
        }
    };  // End of nested definiton of iterator.

    //
    // Definition of our constant iterator.
    //
    class const_iterator : public random_access_iterator<T, difference_type>
    {
        friend class deque<T>;

      protected:

        pointer     current;
        pointer     first;
        pointer     last;
        map_pointer node;

        const_iterator (pointer x, map_pointer y)
            : current(x), first(*y), last(*y + buffer_size()), node(y) {}

      public:

        const_iterator () : current(0), first(0), last(0), node(0) {}
        const_iterator (const iterator& x)
            : current(x.current), first(x.first), last(x.last), node(x.node) {}
        const_reference operator* () const { return *current; }
        difference_type operator- (const const_iterator& x) const
        {
            return node == x.node
            ? current - x.current
            : difference_type(buffer_size() * (node - x.node - 1) +
                  (current - first) + (x.last - x.current));
        }
        const_iterator& operator++ ()
        {
            if (++current == last)
            {
                first = *(++node);
                current = first;
                last = first + buffer_size();
            }
        return *this;
        }
        const_iterator operator++ (int)
        {
            const_iterator tmp = *this; ++*this; return tmp;
        }
        const_iterator& operator-- ()
        {
            if (current == first)
            {
                first = *(--node);
                last = first + buffer_size();
                current = last;
            }
            --current;
            return *this;
        }
        const_iterator operator-- (int)
        {
            const_iterator tmp = *this; --*this; return tmp;
        }
        const_iterator& operator+= (difference_type n)
        {
            difference_type offset = n + (current - first);
            difference_type num_node_to_jump = offset >= 0
                ? offset / buffer_size()
                : -((-offset + buffer_size() - 1) / buffer_size());
            if (num_node_to_jump == 0)
                current += n;
            else
            {
                node = node + num_node_to_jump;
                first = *node;
                last = first + buffer_size();
                current = first + (offset - num_node_to_jump * buffer_size());
            }
            return *this;
        }
        const_iterator& operator-= (difference_type n) { return *this += -n; }
        const_iterator operator+ (difference_type n) const
        {
            const_iterator tmp = *this; return tmp += n;
        }
        const_iterator operator- (difference_type n) const
        {
            const_iterator tmp = *this; return tmp -= n;
        }
        const_reference operator[] (difference_type n)
        {
            return *(*this + n);
        }
        bool operator== (const const_iterator& x) const
        {
            return current == x.current ||
                ((current == first || x.current == x.first) &&
             *this - x == 0);
        }
        bool operator< (const const_iterator& x) const
        {
            return (node == x.node) ? (current < x.current) : (node < x.node);
        }
    };  // End of nested definiton of const_iterator.

    typedef reverse_iterator<const_iterator, value_type, const_reference,
                             difference_type>
            const_reverse_iterator;
    typedef reverse_iterator<iterator, value_type, reference, difference_type>
            reverse_iterator;

  protected:

    iterator    start;
    iterator    finish;
    size_type   length;
    map_pointer map;
    size_type   map_size;

    void allocate_at_begin   ();
    void allocate_at_end     ();
    void deallocate_at_begin ();
    void deallocate_at_end   ();

  public:
    //
    // construct/copy/destroy
    //
    deque () : start(), finish(), length(0), map(0), map_size(0) { }
    //
    // Build a deque of size n with each element set to default for type T.
    // Requires that T have a default constructor.
    //
    explicit deque (size_type n)
        : start(), finish(), length(0), map(0), map_size(0)
    {
        insert(begin(), n, T());
    }
    //
    // Build a deque of size n with each element set to copy of value.
    //
    explicit deque (size_type n, const T& value)
        : start(), finish(), length(0), map(0), map_size(0)
    {
        insert(begin(), n, value);
    }
    deque (const deque<T>& x)
        : start(), finish(), length(0), map(0), map_size(0)
    {
        copy(x.begin(), x.end(), back_inserter(*this));
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    deque (InputIterator first, InputIterator last)
        : start(), finish(), length(0), map(0), map_size(0)
    {
        copy(first, last, back_inserter(*this));
    }
#else
    deque (const_iterator first, const_iterator last)
        : start(), finish(), length(0), map(0), map_size(0)
    {
        copy(first, last, back_inserter(*this));
    }
    deque (const T* first, const T* last)
        : start(), finish(), length(0), map(0), map_size(0)
    {
        copy(first, last, back_inserter(*this));
    }
#endif

    ~deque ();
    deque<T>& operator= (const deque<T>& x)
    {
        if (!(this == &x))
        {
            if (size() >= x.size())
                erase(copy(x.begin(), x.end(), begin()), end());
            else
                copy(x.begin() + size(), x.end(),
                     inserter(*this,copy(x.begin(),x.begin()+size(),begin())));
        }
        return *this;
    }
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void assign (InputIterator first, InputIterator last)
    {
        erase(begin(), end()); insert(begin(), first, last);
    }
    //
    // Assign n copies of default value of type T to vector.
    // This requires that T have a default constructor.
    //
    template<class Size, class T>
    void assign (Size n)
    {
        erase(begin(), end()); insert(begin(), n, T());
    }
    //
    // Assign n copies of t to this vector.
    //
    template<class Size, class T>
    void assign (Size n, const T& t)
    {
        erase(begin(), end()); insert(begin(), n, t);
    }
#else
    void assign (const_iterator first, const_iterator last)
    {
        erase(begin(), end()); insert(begin(), first, last);
    }
    void assign (const T* first, const T* last)
    {
        erase(begin(), end()); insert(begin(), first, last);
    }
    //
    // Assign n copies of default value of type T to vector.
    // This requires that T have a default constructor.
    //
    void assign (size_type n)
    {
        erase(begin(), end()); insert(begin(), n, T());
    }
    //
    // Assign n copies of t to this vector.
    //
    void assign (size_type n, const T& t)
    {
        erase(begin(), end()); insert(begin(), n, t);
    }
#endif
    //
    // Iterators.
    //
    iterator         begin  ()       { return start;  }
    const_iterator   begin  () const { return start;  }
    iterator         end    ()       { return finish; }
    const_iterator   end    () const { return finish; }
    reverse_iterator rbegin ()
    {
      reverse_iterator tmp(end()); return tmp;
    }
    const_reverse_iterator rbegin () const
    {
        const_reverse_iterator tmp(end()); return tmp;
    }
    reverse_iterator rend ()
    {
        reverse_iterator tmp(begin()); return tmp;
    }
    const_reverse_iterator rend () const
    {
        const_reverse_iterator tmp(begin()); return tmp;
    }
    //
    // Capacity.
    //
    size_type size     () const { return length;                    }
    size_type max_size () const { return data_allocator.max_size(); }
    bool      empty    () const { return length == 0;               }
    void      resize (size_type new_size);
    void      resize (size_type new_size, T value);
    //
    // Element access.
    //
    reference       operator[] (size_type n)       { return *(begin() + n); }
    const_reference operator[] (size_type n) const { return *(begin() + n); }
    const_reference at (size_type n)         const { return *(begin() + n); }
    reference       at (size_type n)               { return *(begin() + n); }
    reference       front ()                       { return *begin();       }
    const_reference front ()                 const { return *begin();       }
    reference       back ()                        { return *(end() - 1);   }
    const_reference back ()                  const { return *(end() - 1);   }
    //
    // Modifiers.
    //
    void push_front (const T& x)
    {
        if (empty() || begin().current == begin().first) allocate_at_begin();
        --start.current;
        construct(start.current, x);
        ++length;
    }
    void push_back (const T& x)
    {
        if (empty() || end().current == end().last) allocate_at_end();
        construct(finish.current, x);
        ++finish.current;
        ++length;
    }
    //
    // Insert default value of type T at position.
    // Requires that T have a default constructor.
    //
    iterator insert (iterator position);
    //
    // Insert x at position.
    //
    iterator insert (iterator position, const T& x);
    void insert (iterator position, size_type n, const T& x);

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class Iterator>
    void insert(iterator position, Iterator first, Iterator last);
#else
    void insert (iterator position, const T* first, const T* last);
    void insert (iterator position, const_iterator first, const_iterator last);
#endif

    void pop_front ()
    {
        destroy(start.current);
        ++start.current;
        --length;
        if (empty() || begin().current == begin().last) deallocate_at_begin();
    }
    void pop_back ()
    {
        --finish.current;
        destroy(finish.current);
        --length;
        if (empty() || end().current == end().first) deallocate_at_end();
    }
    void erase (iterator position);
    void erase (iterator first, iterator last);
    void swap (deque<T>& x)
    {
#ifndef RWSTD_NO_NAMESPACE
        std::swap(start,          x.start);
        std::swap(finish,         x.finish);
        std::swap(length,         x.length);
        std::swap(map,            x.map);
        std::swap(map_size,       x.map_size);
        std::swap(data_allocator, x.data_allocator);
        std::swap(map_allocator,  x.map_allocator);
#else
        ::swap(start,             x.start);
        ::swap(finish,            x.finish);
        ::swap(length,            x.length);
        ::swap(map,               x.map);
        ::swap(map_size,          x.map_size);
        ::swap(data_allocator,    x.data_allocator);
        ::swap(map_allocator,     x.map_allocator);
#endif
    }
};

template <class T>
deque<T>::~deque()
{
    while (!empty()) pop_front();
}

template <class T>
void deque<T>::allocate_at_begin ()
{
    pointer p = data_allocator.allocate(buffer_size());
    if (!empty())
    {
        if (start.node == map)
        {
            difference_type i = finish.node - start.node;
            map_size = (i + 1) * 2;
            map_pointer tmp = map_allocator.allocate(map_size);
            copy(start.node, finish.node + 1, tmp + map_size / 4 + 1);
            map_allocator.deallocate(map);
            map = tmp;
            map[map_size / 4] = p;
            start = iterator(p + buffer_size(), map + map_size / 4);
            finish = iterator(finish.current, map + map_size / 4 + i + 1);
        }
        else
        {
            *--start.node = p;
            start = iterator(p + buffer_size(), start.node);
        }
    }
    else
    {
        map_size = buffer_size();
        map = map_allocator.allocate(map_size);
        map[map_size / 2] = p;
        start = iterator(p + buffer_size() / 2 + 1, map + map_size / 2);
        finish = start;
    }
}

template <class T>
void deque<T>::allocate_at_end ()
{
    pointer p = data_allocator.allocate(buffer_size());

    if (!empty())
    {
        if (finish.node == map + map_size - 1)
        {
            difference_type i = finish.node - start.node;
            map_size = (i + 1) * 2;
            map_pointer tmp = map_allocator.allocate(map_size);
            copy(start.node, finish.node + 1, tmp + map_size / 4);
            map_allocator.deallocate(map);
            map = tmp;
            map[map_size / 4 + i + 1] = p;
            start = iterator(start.current, map + map_size / 4);
            finish = iterator(p, map + map_size / 4 + i + 1);
        }
        else
        {
            *++finish.node = p;
            finish = iterator(p, finish.node);
        }
    }
    else
    {
        map_size = buffer_size();
        map = map_allocator.allocate(map_size);
        map[map_size / 2] = p;
        start = iterator(p + buffer_size() / 2, map + map_size / 2);
        finish = start;
    }
}

template <class T>
void deque<T>::deallocate_at_begin ()
{
    data_allocator.deallocate(*start.node++);
    if (empty())
    {
        start = iterator();
        finish = start;
        map_allocator.deallocate(map);
    }
    else
        start = iterator(*start.node, start.node);
}

template <class T>
void deque<T>::deallocate_at_end ()
{
    data_allocator.deallocate(*finish.node--);
    if (empty())
    {
        start = iterator();
        finish = start;
        map_allocator.deallocate(map);
    }
    else
        finish = iterator(*finish.node + buffer_size(), finish.node);
}

template <class T>
void deque<T>::resize (size_type new_size)
{
    T value;
    if (new_size > size())
        insert(end(), new_size - size(), value);
    else if (new_size < size())
        erase(begin() + new_size,end());
}

template <class T>
void deque<T>::resize (size_type new_size, T value)
{
    if (new_size > size())
        insert(end(), new_size - size(), value);
    else if (new_size < size())
        erase(begin() + new_size,end());
}

template <class T>
deque<T>::iterator deque<T>::insert (iterator position)
{
    T x;

    if (position == begin())
    {
        push_front(x); return begin();
    }
    else if (position == end())
    {
        push_back(x); return end() - 1;
    }
    else
    {
        difference_type index = position - begin();
        if (index < length)
        {
            push_front(*begin());
            copy(begin() + 2, begin() + index + 1, begin() + 1);
        }
        else
        {
            push_back(*(end() - 1));
            copy_backward(begin() + index, end() - 2, end() - 1);
        }
        *(begin() + index) = x;
        return begin() + index;
    }
}

template <class T>
deque<T>::iterator deque<T>::insert (iterator position, const T& x)
{
    if (position == begin())
    {
        push_front(x); return begin();
    }
    else if (position == end())
    {
        push_back(x); return end() - 1;
    }
    else
    {
        difference_type index = position - begin();
        if (index < length)
        {
            push_front(*begin());
            copy(begin() + 2, begin() + index + 1, begin() + 1);
        }
        else
        {
            push_back(*(end() - 1));
            copy_backward(begin() + index, end() - 2, end() - 1);
        }
        *(begin() + index) = x;
        return begin() + index;
    }
}

template <class T>
void deque<T>::insert (iterator position, size_type n, const T& x)
{
    difference_type index     = position - begin();
    difference_type remainder = length   - index;

    if (remainder > index)
    {
        if (n > index)
        {
            difference_type m = n - index;
            while (m-- > 0) push_front(x);
            difference_type i = index;
            while (i--) push_front(*(begin() + n - 1));
            fill(begin() + n, begin() + n + index, x);
        }
        else
        {
            difference_type i = n;
            while (i--) push_front(*(begin() + n - 1));
            copy(begin() + n + n, begin() + n + index, begin() + n);
            fill(begin() + index, begin() + n + index, x);
        }
    }
    else
    {
        difference_type orig_len = index + remainder;
        if (n > remainder)
        {
            difference_type m = n - remainder;
            while (m-- > 0) push_back(x);
            difference_type i = 0;
            while (i < remainder) push_back(*(begin() + index + i++));
            fill(begin() + index, begin() + orig_len, x);
        }
        else
        {
            difference_type i = 0;
            while (i < n) push_back(*(begin() + orig_len - n + i++));
            copy_backward(begin() + index, begin() + orig_len - n,
                          begin() + orig_len);
            fill(begin() + index, begin() + index + n, x);
        }
    }
}


#ifndef RWSTD_NO_MEMBER_TEMPLATES
template <class T>
template <class Iterator>
void deque<T>::insert (iterator position, Iterator first, Iterator last)
{
    difference_type index     = position - begin();
    difference_type remainder = length   - index;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if (remainder > index)
    {
        if (n > index)
        {
            Iterator m = last - index;
            while (m != first) push_front(*--m);
            difference_type i = index;
            while (i--) push_front(*(begin() + n - 1));
            copy(last - index, last, begin() + n);
        }
        else
        {
            difference_type i = n;
            while (i--) push_front(*(begin() + n - 1));
            copy(begin() + n + n, begin() + n + index, begin() + n);
            copy(first, last, begin() + index);
        }
    }
    else
    {
        difference_type orig_len = index + remainder;
        if (n > remainder)
        {
            Iterator m = first + remainder;
            while (m != last) push_back(*m++);
            difference_type i = 0;
            while (i < remainder) push_back(*(begin() + index + i++));
            copy(first, first + remainder, begin() + index);
        }
        else
        {
            difference_type i = 0;
            while (i < n) push_back(*(begin() + orig_len - n + i++));
            copy_backward(begin() + index, begin() + orig_len - n,
                          begin() + orig_len);
            copy(first, last, begin() + index);
        }
    }
}

#else

template<class T>
void deque<T>::insert (iterator position, const_iterator first, const_iterator last)
{
    difference_type index     = position - begin();
    difference_type remainder = length   - index;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if (remainder > index)
    {
        if (n > index)
        {
            const_iterator m = last - index;
            while (m != first) push_front(*--m);
            difference_type i = index;
            while (i--) push_front(*(begin() + n - 1));
            copy(last - index, last, begin() + n);
        }
        else
        {
            difference_type i = n;
            while (i--) push_front(*(begin() + n - 1));
            copy(begin() + n + n, begin() + n + index, begin() + n);
            copy(first, last, begin() + index);
        }
    }
    else
    {
        difference_type orig_len = index + remainder;
        if (n > remainder)
        {
            const_iterator m = first + remainder;
            while (m != last) push_back(*m++);
            difference_type i = 0;
            while (i < remainder) push_back(*(begin() + index + i++));
            copy(first, first + remainder, begin() + index);
        }
        else
        {
            difference_type i = 0;
            while (i < n) push_back(*(begin() + orig_len - n + i++));
            copy_backward(begin() + index, begin() + orig_len - n,
                          begin() + orig_len);
            copy(first, last, begin() + index);
        }
    }
}

template<class T>
void deque<T>::insert (iterator position, const T* first, const T* last)
{
    difference_type index     = position - begin();
    difference_type remainder = length   - index;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if (remainder > index)
    {
        if (n > index)
        {
            const T* m = last - index;
            while (m != first) push_front(*--m);
            difference_type i = index;
            while (i--) push_front(*(begin() + n - 1));
            copy(last - index, last, begin() + n);
        }
        else
        {
            difference_type i = n;
            while (i--) push_front(*(begin() + n - 1));
            copy(begin() + n + n, begin() + n + index, begin() + n);
            copy(first, last, begin() + index);
        }
    }
    else
    {
        difference_type orig_len = index + remainder;
        if (n > remainder)
        {
            const T* m = first + remainder;
            while (m != last) push_back(*m++);
            difference_type i = 0;
            while (i < remainder) push_back(*(begin() + index + i++));
            copy(first, first + remainder, begin() + index);
        }
        else
        {
            difference_type i = 0;
            while (i < n) push_back(*(begin() + orig_len - n + i++));
            copy_backward(begin() + index, begin() + orig_len - n,
                          begin() + orig_len);
            copy(first, last, begin() + index);
        }
    }
}

#endif /*RWSTD_NO_MEMBER_TEMPLATES*/

template <class T>
void deque<T>::erase (iterator position)
{
    if (end() - position > position - begin())
    {
        copy_backward(begin(), position, position + 1); pop_front();
    }
    else
    {
        copy(position + 1, end(), position); pop_back();
    }
}

template <class T>
void deque<T>::erase (iterator first, iterator last)
{
    difference_type n = last - first;
    if (end() - last > first - begin())
    {
        copy_backward(begin(), first, last);
        while(n-- > 0) pop_front();
    }
    else
    {
        copy(last, end(), first);
        while(n-- > 0) pop_back();
    }
}

template <class T>
inline bool operator== (const deque<T>& x, const deque<T>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class T>
inline bool operator< (const deque<T>& x, const deque<T>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

#undef Allocator
#undef deque

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif /*__STD_DEQUE__*/
