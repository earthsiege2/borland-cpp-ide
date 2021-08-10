#ifndef __STD_LIST__
#define __STD_LIST__

/***************************************************************************
 *
 * list - list declarations for the Standard Library
 *
 * $Id: list,v 1.47 1995/09/18 23:31:35 lijewski Exp $
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

#include <function>
#include <algorith>
#include <iterator>

#ifndef Allocator
#define Allocator allocator
#include <memory>
#endif

#ifndef list
#define list list
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

template <class T>
class list
{
  protected:

    typedef Allocator<void>::pointer void_pointer;

    struct list_node;
    friend struct list_node;

    struct list_node
    {
        void_pointer next;
        void_pointer prev;
        T            data;
    };

    Allocator<list_node>  list_node_allocator;
    Allocator<T>          value_allocator;

  public:
    //
    // types
    //
    typedef T                                     value_type;
    typedef Allocator<T>                          value_allocator_type;
    typedef Allocator<T>::pointer                 pointer;
    typedef Allocator<T>::reference               reference;
    typedef Allocator<T>::const_reference         const_reference;
    typedef Allocator<list_node>              list_node_allocator_type;
    typedef Allocator<list_node>::pointer         link_type;
    typedef Allocator<list_node>::size_type       size_type;
    typedef Allocator<list_node>::difference_type difference_type;

  protected:

    static size_type buffer_size ()
    {
        //
        // Each time we allocate memory we reserve space for
        // this many nodes.  This is currently tuned to
        // allocate memory in 1K chunks, except for large objects.
        //
        return sizeof(list_node) >= 1024 ? 1 : 1024 / sizeof(list_node);
    };

    struct list_node_buffer;
    friend struct list_node_buffer;

    struct list_node_buffer
    {
        void_pointer next_buffer;
        link_type    buffer;
    };

  public:

    typedef Allocator<list_node_buffer>          buffer_allocator_type;
    typedef Allocator<list_node_buffer>::pointer buffer_pointer;

  protected:

    Allocator<list_node_buffer>   buffer_allocator;
    buffer_pointer                buffer_list;
    link_type                     free_list;
    link_type                     next_avail;
    link_type                     last;

    void add_new_buffer ()
    {
        buffer_pointer tmp = buffer_allocator.allocate((size_type)1);
        tmp->buffer = list_node_allocator.allocate(buffer_size());
        tmp->next_buffer = buffer_list;
        buffer_list = tmp;
        next_avail = buffer_list->buffer;
        last = next_avail + buffer_size();
    }
    void deallocate_buffers ();
    link_type get_node ()
    {
        link_type tmp = free_list;
        return free_list ? (free_list = (link_type)(free_list->next), tmp)
            : (next_avail == last ? (add_new_buffer(), next_avail++)
               : next_avail++);
    }
    void put_node (link_type p) { p->next = free_list; free_list = p; }

  protected:

    link_type node;
    size_type length;

  public:

    class iterator;
    class const_iterator;

    class iterator : public bidirectional_iterator<T, difference_type>
    {
        friend class list<T>;
        friend class const_iterator;

      protected:

        link_type node;
        iterator (link_type x) : node(x) {}

      public:

        iterator () {}
        bool operator== (const iterator& x) const { return node == x.node; }
        reference operator* () const { return (*node).data; }
        iterator& operator++ ()
        {
            node = (link_type)((*node).next); return *this;
        }
        iterator operator++ (int)
        {
            iterator tmp = *this; ++*this; return tmp;
        }
        iterator& operator-- ()
        {
            node = (link_type)((*node).prev); return *this;
        }
        iterator operator-- (int)
        {
            iterator tmp = *this; --*this; return tmp;
        }
    };  // End of definition of iterator class.

    class const_iterator : public bidirectional_iterator<T, difference_type>
    {
        friend class list<T>;

      protected:

        link_type node;
        const_iterator (link_type x) : node(x) {}

      public:

        const_iterator () {}
        const_iterator (const iterator& x) : node(x.node) {}
        bool operator== (const const_iterator& x) const {return node==x.node;}
        const_reference operator* () const { return (*node).data; }
        const_iterator& operator++ ()
        {
            node = (link_type)((*node).next); return *this;
        }
        const_iterator operator++ (int)
        {
            const_iterator tmp = *this; ++*this; return tmp;
        }
        const_iterator& operator-- ()
        {
            node = (link_type)((*node).prev); return *this;
        }
        const_iterator operator-- (int)
        {
            const_iterator tmp = *this;
            --*this;
            return tmp;
        }
    };  // End of definition of cosnt_iterator class.

    typedef reverse_bidirectional_iterator<const_iterator, value_type,
                                           const_reference, difference_type>
            const_reverse_iterator;
    typedef reverse_bidirectional_iterator<iterator, value_type, reference,
                                           difference_type>
            reverse_iterator;

    //
    // construct/copy/destroy
    //
    list () : length(0)
    {
        buffer_list = 0;
        free_list = next_avail = last = 0;
        node = get_node();
        (*node).next = node;
        (*node).prev = node;
    }
    //
    // Build a list of size n with each element set to default for type T.
    // This requires that T have a default constructor.
    //
    explicit list (size_type n) : length(0)
    {
        T value;
        buffer_list = 0;
        free_list   = next_avail = last = 0;
        node        = get_node();
        (*node).next = node;
        (*node).prev = node;
        insert(begin(), n, value);
    }
    //
    // Build a vector of size n with each element set to a copy of value.
    //
    explicit list (size_type n, const T& value) : length(0)
    {
        buffer_list = 0;
        free_list   = next_avail = last = 0;
        node        = get_node();
        (*node).next = node;
        (*node).prev = node;
        insert(begin(), n, value);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    list (InputIterator first, InputIterator locallast) : length(0)
    {
        buffer_list = 0;
        free_list = next_avail = last = 0;
        node = get_node();
        (*node).next = node;
        (*node).prev = node;
        insert(begin(), first, locallast);
    }
#else
    list (const_iterator first, const_iterator locallast) : length(0)
    {
        buffer_list = 0;
        free_list = next_avail = last = 0;
        node = get_node();
        (*node).next = node;
        (*node).prev = node;
        insert(begin(), first, locallast);
    }
    list (const T* first, const T* locallast) : length(0)
    {
        buffer_list = 0;
        free_list = next_avail = last = 0;
        node = get_node();
        (*node).next = node;
        (*node).prev = node;
        insert(begin(), first, locallast);
    }
#endif

    list (const list<T>& x) : length(0)
    {
        buffer_list = 0;
        free_list = next_avail = last = 0;
        node = get_node();
        (*node).next = node;
        (*node).prev = node;
        insert(begin(), x.begin(), x.end());
    }
    ~list ()
    {
        erase(begin(), end());
        put_node(node);
        deallocate_buffers();
    }
    list<T>& operator= (const list<T>& x);

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void assign (InputIterator first, InputIterator last)
    {
        erase(begin(), end()); insert(begin(), first, last);
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
#endif
    //
    // Assign n copies of default value of type T to vector.
    // This requires that T have a default constructor.
    //
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class Size, class T>
    void assign (Size n)
#else
    void assign (size_type n)
#endif
    {
        erase(begin(), end()); insert(begin(), n, T());
    }
    //
    // Assign n copies of t to this vector.
    //
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class Size, class T>
    void assign (Size n, const T& t)
#else
    void assign (size_type n, const T& t)
#endif
    {
        erase(begin(), end()); insert(begin(), n, t);
    }
    //
    // Iterators.
    //
    iterator       begin ()       { return (link_type)((*node).next); }
    const_iterator begin () const { return (link_type)((*node).next); }
    iterator       end ()         { return node;                      }
    const_iterator end ()   const { return node;                      }
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
    bool empty ()         const { return length == 0;                    }
    size_type size ()     const { return length;                         }
    size_type max_size () const { return list_node_allocator.max_size(); }
    void resize (size_type new_size);
    void resize (size_type new_size, T value);
    //
    // Element access.
    //
    reference       front ()       { return *begin();   }
    const_reference front () const { return *begin();   }
    reference       back  ()       { return *(--end()); }
    const_reference back  () const { return *(--end()); }
    //
    // Modifiers.
    //
    //
    // Insert default value of type T at position.
    // Requires that T have a default constructor.
    //
    iterator insert (iterator position)
    {
        T x;
        link_type tmp = get_node();
        construct(value_allocator.address((*tmp).data), x);
        (*tmp).next = position.node;
        (*tmp).prev = (*position.node).prev;
        (*(link_type((*position.node).prev))).next = tmp;
        (*position.node).prev = tmp;
        ++length;
        return tmp;
    }
    //
    // Insert x at position.
    //
    iterator insert (iterator position, const T& x)
    {
        link_type tmp = get_node();
        construct(value_allocator.address((*tmp).data), x);
        (*tmp).next = position.node;
        (*tmp).prev = (*position.node).prev;
        (*(link_type((*position.node).prev))).next = tmp;
        (*position.node).prev = tmp;
        ++length;
        return tmp;
    }
    void insert (iterator position, size_type n, const T& x);

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);
#else
    void insert (iterator position, const T* first, const T* last);
    void insert (iterator position, const_iterator first, const_iterator last);
#endif

    void erase (iterator position)
    {
        (*(link_type((*position.node).prev))).next = (*position.node).next;
        (*(link_type((*position.node).next))).prev = (*position.node).prev;
        destroy(value_allocator.address((*position.node).data));
        put_node(position.node);
        --length;
    }
    void erase      (iterator first, iterator last);
    void push_front (const T& x) { insert(begin(), x); }
    void push_back  (const T& x) { insert(end(), x);   }
    void pop_front  ()           { erase(begin());     }
    void pop_back   ()           { iterator tmp = end(); erase(--tmp); }
    void swap (list<T>& x)
    {
#ifndef RWSTD_NO_NAMESPACE
        std::swap(node, x.node);
        std::swap(length, x.length);
        std::swap(buffer_list,x.buffer_list);
        std::swap(free_list,x.free_list);
        std::swap(next_avail,x.next_avail);
        std::swap(list_node_allocator,x.list_node_allocator);
        std::swap(value_allocator,x.value_allocator);
        std::swap(buffer_allocator,x.buffer_allocator);
        std::swap(last,x.last);
#else
        ::swap(node, x.node);
        ::swap(length, x.length);
        ::swap(buffer_list,x.buffer_list);
        ::swap(free_list,x.free_list);
        ::swap(next_avail,x.next_avail);
        ::swap(list_node_allocator,x.list_node_allocator);
        ::swap(value_allocator,x.value_allocator);
        ::swap(buffer_allocator,x.buffer_allocator);
        ::swap(last,x.last);
#endif
    }

  protected:

    void transfer (iterator position, iterator first, iterator last)
    {
        (*(link_type((*last.node).prev))).next = position.node;
        (*(link_type((*first.node).prev))).next = last.node;
        (*(link_type((*position.node).prev))).next = first.node;
        link_type tmp = link_type((*position.node).prev);
        (*position.node).prev = (*last.node).prev;
        (*last.node).prev = (*first.node).prev;
        (*first.node).prev = tmp;
    }

  public:
    //
    // list operations.
    //
    void splice (iterator position, list<T>& x)
    {
        if (!x.empty())
        {
            transfer(position, x.begin(), x.end());
            length += x.length;
            x.length = 0;
        }
    }
    void splice (iterator position, list<T>& x, iterator i)
    {
        iterator j = i;
        transfer(position, i, ++j);
        ++length;
        --x.length;
    }
    void splice (iterator position, list<T>& x, iterator first, iterator last)
    {
        if (first != last)
        {
            difference_type n;
            __initialize(n, difference_type(0));
            distance(first, last, n);
            x.length -= n;
            length += n;
            transfer(position, first, last);
        }
    }
    void remove  (const T& value);
    void unique  ();
    void merge   (list<T>& x);
    void reverse ();
    void sort    ();

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class Predicate>       void remove_if (Predicate pred);
    template<class BinaryPredicate> void unique    (BinaryPredicate pred);
    template<class Compare>         void merge     (list<T>& x, Compare comp);
    template<class Compare>         void sort      (Compare comp);
#endif
};

template <class T>
inline bool operator== (const list<T>& x, const list<T>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class T>
inline bool operator< (const list<T>& x, const list<T>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T>
void list<T>::deallocate_buffers ()
{
    while (buffer_list)
    {
        buffer_pointer tmp = buffer_list;
        buffer_list = (buffer_pointer)(buffer_list->next_buffer);
        list_node_allocator.deallocate(tmp->buffer);
        buffer_allocator.deallocate(tmp);
    }
    free_list = 0;
    next_avail = 0;
    last = 0;
}

//
// This requires that T have a default constructor.
//

template <class T>
void list<T>::resize (size_type new_size)
{
    T value;
    if (new_size > size())
        insert(end(), new_size - size(), value);
    else if (new_size < size())
    {
        iterator tmp = begin();
        advance(tmp, (difference_type) new_size);
        erase(tmp, end());
    }
}

template <class T>
void list<T>::resize (size_type new_size, T value)
{
    if (new_size > size())
        insert(end(), new_size - size(), value);
    else if (new_size < size())
    {
        iterator tmp = begin();
        advance(tmp, (difference_type) new_size);
        erase(tmp, end());
    }
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template <class T>
template<class InputIterator>
void list<T>::insert (iterator position, InputIterator first,
                      InputIterator locallast)
{
    while (first != locallast) insert(position, *first++);
}
#else
template <class T>
void list<T>::insert (iterator position, const_iterator first,
                      const_iterator locallast)
{
    while (first != locallast) insert(position, *first++);
}
template <class T>
void list<T>::insert (iterator position, const T* first, const T* locallast)
{
    while (first != locallast) insert(position, *first++);
}
#endif

template <class T>
void list<T>::insert (iterator position, size_type n, const T& x)
{
    while (n--) insert(position, x);
}

template <class T>
void list<T>::erase (iterator first, iterator locallast)
{
    while (first != locallast) erase(first++);
}

template <class T>
list<T>& list<T>::operator= (const list<T>& x)
{
    if (this != &x)
    {
        iterator first1 = begin();
        iterator last1 = end();
        const_iterator first2 = x.begin();
        const_iterator last2 = x.end();
        while (first1 != last1 && first2 != last2) *first1++ = *first2++;
        if (first2 == last2)
            erase(first1, last1);
        else
            insert(last1, first2, last2);
    }
    return *this;
}

template <class T>
void list<T>::remove (const T& value)
{
    iterator first = begin();
    iterator last = end();
    while (first != last)
    {
        iterator next = first;
        ++next;
        if (*first == value) erase(first);
        first = next;
    }
}

template <class T>
void list<T>::unique ()
{
    iterator first = begin();
    iterator last = end();
    if (first == last) return;
    iterator next = first;
    while (++next != last)
    {
        if (*first == *next)
            erase(next);
        else
            first = next;
        next = first;
    }
}

template <class T>
void list<T>::merge (list<T>& x)
{
    iterator first1 = begin();
    iterator last1 = end();
    iterator first2 = x.begin();
    iterator last2 = x.end();
    while (first1 != last1 && first2 != last2)
    {
        if (*first2 < *first1)
        {
            iterator next = first2;
            transfer(first1, first2, ++next);
            first2 = next;
        }
        else
            first1++;
    }
    if (first2 != last2) transfer(last1, first2, last2);
    length += x.length;
    x.length = 0;
}

template <class T>
void list<T>::reverse ()
{
    if (size() < 2) return;
    for (iterator first = ++begin(); first != end();)
    {
        iterator old = first++;
        transfer(begin(), old, first);
    }
}

template <class T>
void list<T>::sort ()
{
    if (size() < 2) return;
    list<T> carry;
    list<T> counter[64];
    int fill = 0;
    while (!empty())
    {
        carry.splice(carry.begin(), *this, begin());
        int i = 0;
        while (i < fill && !counter[i].empty())
        {
            counter[i].merge(carry);
            carry.swap(counter[i++]);
        }
        carry.swap(counter[i]);
        if (i == fill) ++fill;
    }
    while (fill--) merge(counter[fill]);
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class T>
template<class Predicate> void list<T>::remove_if (Predicate pred)
{
    iterator first = begin();
    iterator last = end();
    while (first != last)
    {
        iterator next = first;
        ++next;
        if (pred(*first)) erase(first);
        first = next;
    }
}

template<class T>
template<class BinaryPredicate> void list<T>::unique (BinaryPredicate pred)
{
    iterator first = begin();
    iterator last = end();
    if (first == last) return;
    iterator next = first;
    while (++next != last)
    {
        if (pred(*first, *next))
            erase(next);
        else
            first = next;
        next = first;
    }
}

template<class T>
template<class Compare> void list<T>::merge (list<T>& x, Compare comp)
{
    iterator first1 = begin();
    iterator last1  = end();
    iterator first2 = x.begin();
    iterator last2  = x.end();
    while (first1 != last1 && first2 != last2)
    {
        if (comp(*first2, *first1))
        {
            iterator next = first2;
            transfer(first1, first2, ++next);
            first2 = next;
        }
        else
            first1++;
    }
    if (first2 != last2) transfer(last1, first2, last2);
    length += x.length;
    x.length = 0;
}

template<class T>
template<class Compare> void list<T>::sort (Compare comp)
{
    if (size() < 2) return;
    list<T> carry;
    list<T> counter[64];
    int fill = 0;
    while (!empty())
    {
        carry.splice(carry.begin(), *this, begin());
        int i = 0;
        while (i < fill && !counter[i].empty())
        {
            counter[i].merge(carry, comp);
            carry.swap(counter[i++]);
        }
        carry.swap(counter[i]);
        if (i == fill) ++fill;
    }
    while (fill--) merge(counter[fill]);
}
#endif /*RWSTD_NO_MEMBER_TEMPLATES*/

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#undef Allocator
#undef list

#endif /*__STD_LIST__*/
