#ifndef __STD_VECTOR__
#define __STD_VECTOR__
/* $Revision:   8.1  $ */

/***************************************************************************
 *
 * vector - declarations for the Standard Library vector class
 *
 * $Id: vector,v 1.41 1995/09/14 23:53:38 lijewski Exp $
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
#include <iterator>
#include <algorith>

#ifndef Allocator
#define Allocator allocator
#include <memory>
#endif

#ifndef vector
#define vector vector
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

template <class T>
class vector
{
  public:
    //
    // Types.
    //
    typedef Allocator<T>                               vector_allocator;
    typedef typename vector_allocator::reference       reference;
    typedef typename vector_allocator::const_reference const_reference;
    typedef typename vector_allocator::pointer         iterator;
    typedef typename vector_allocator::const_pointer   const_iterator;
    typedef typename vector_allocator::size_type       size_type;
    typedef typename vector_allocator::difference_type difference_type;
    typedef          T                                 value_type;
    typedef reverse_iterator<const_iterator, value_type,
                             const_reference, difference_type>
                                                       const_reverse_iterator;
    typedef reverse_iterator<iterator, value_type,
                             reference, difference_type>
                                                       reverse_iterator;
  protected:

    Allocator<T> the_allocator;

    iterator start;
    iterator finish;
    iterator end_of_storage;

    void insert_aux (iterator position, const T& x);

  public:
    //
    // construct/copy/destroy
    //
    vector () : start(0), finish(0), end_of_storage(0) {}
    //
    // Build a vector of size n with each element set to default for type T.
    // This requires that T have a default constructor.
    //
    explicit vector (size_type n)
    {
        start = the_allocator.allocate(n);
        T value;
        uninitialized_fill_n(start, n, value);
        finish = start + n;
        end_of_storage = finish;
    }
    //
    // Build a vector of size n with each element set to copy of value.
    //
    explicit vector (size_type n, const T& value)
    {
        start = the_allocator.allocate(n);
        uninitialized_fill_n(start, n, value);
        finish = start + n;
        end_of_storage = finish;
    }
    vector (const vector<T>& x)
    {
        start = the_allocator.allocate(x.end() - x.begin());
        finish = uninitialized_copy(x.begin(), x.end(), start);
        end_of_storage = finish;
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class InputIterator>
    vector (InputIterator first, InputIterator last)
#else
    vector (const_iterator first, const_iterator last)
#endif
     {
        size_type n;
        __initialize(n, size_type(0));
        distance(first, last, n);
        start = the_allocator.allocate(n);
        finish = uninitialized_copy(first, last, start);
        end_of_storage = finish;
    }

    ~vector ()
    {
        destroy(start, finish); the_allocator.deallocate(start);
    }
    vector<T>& operator= (const vector<T>& x);

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void assign (InputIterator first, InputIterator last)
#else
    void assign (const_iterator first, const_iterator last)
#endif
    {
        erase(begin(), end()); insert(begin(), first, last);
    }
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
    iterator       begin ()       { return start;  }
    const_iterator begin () const { return start;  }
    iterator       end ()         { return finish; }
    const_iterator end ()   const { return finish; }

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
    size_type size ()     const { return size_type(end() - begin()); }
    size_type max_size () const { return the_allocator.max_size();   }
    void resize (size_type new_size);
    void resize (size_type new_size, T value);

    size_type capacity () const { return size_type(end_of_storage - begin()); }
    bool      empty ()    const { return begin() == end();                    }
    void reserve (size_type n)
    {
        if (capacity() < n)
        {
            iterator tmp = the_allocator.allocate(n);
            uninitialized_copy(begin(), end(), tmp);
            destroy(start, finish);
            the_allocator.deallocate(start);
            finish = tmp + size();
            start = tmp;
            end_of_storage = begin() + n;
        }
    }

    //
    // Element access.
    //
    reference       operator[] (size_type n)       { return *(begin() + n); }
    const_reference operator[] (size_type n) const { return *(begin() + n); }
    reference       at (size_type n)               { return *(begin() + n); }
    const_reference at (size_type n)         const { return *(begin() + n); }
    reference       front ()                       { return *begin();       }
    const_reference front ()                 const { return *begin();       }
    reference       back ()                        { return *(end() - 1);   }
    const_reference back ()                  const { return *(end() - 1);   }

    //
    // Modifiers.
    //
    void push_back (const T& x)
    {
        if (finish != end_of_storage)
        {
            construct(finish, x); finish++;
        }
        else
            insert_aux(end(), x);
    }
    void pop_back()
    {
        --finish; destroy(finish);
    }
    //
    // Insert default value of type T at position.
    // Requires that T have a default constructor.
    //
    iterator insert (iterator position)
    {
        size_type n = position - begin();
        T x;
        if (finish != end_of_storage && position == end())
        {
            construct(finish, x); finish++;
        }
        else
            insert_aux(position, x);
        return begin() + n;
    }
    //
    // Insert x at position.
    //
    iterator insert (iterator position, const T& x)
    {
        size_type n = position - begin();
        if (finish != end_of_storage && position == end())
        {
            construct(finish, x); finish++;
        }
        else
            insert_aux(position, x);
        return begin() + n;
    }
    void insert (iterator position, size_type n, const T& x);

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);
#else
    void insert (iterator position, const_iterator first, const_iterator last);
#endif

    void swap (vector<T>& x)
    {
#ifndef RWSTD_NO_NAMESPACE
        std::swap(start, x.start);
        std::swap(finish, x.finish);
        std::swap(end_of_storage, x.end_of_storage);
        std::swap(the_allocator,x.the_allocator);
#else
        ::swap(start, x.start);
        ::swap(finish, x.finish);
        ::swap(end_of_storage, x.end_of_storage);
        ::swap(the_allocator,x.the_allocator);
#endif
    }
    void erase (iterator position)
    {
        if (position + 1 != end()) copy(position + 1, end(), position);
        --finish;
        destroy(finish);
    }
    void erase (iterator first, iterator last)
    {
        iterator i = copy(last, end(), first);
        destroy(i, finish);
        finish = finish - (last - first);
    }
};

template <class T>
inline bool operator== (const vector<T>& x, const vector<T>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class T>
inline bool operator< (const vector<T>& x, const vector<T>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

//
// This requires that T have a default constructor.
//

template <class T>
void vector<T>::resize (size_type new_size)
{
    T value;
    if (new_size > size())
        insert(end(), new_size - size(), value);
    else if (new_size < size())
        erase(begin() + new_size, end());
}

template <class T>
void vector<T>::resize (size_type new_size, T value)
{
    if (new_size > size())
        insert(end(), new_size - size(), value);
    else if (new_size < size())
        erase(begin() + new_size, end());
}

template <class T>
vector<T>& vector<T>::operator= (const vector<T>& x)
{
    if (&x == this) return *this;
    if (x.size() > capacity())
    {
        destroy(start, finish);
        the_allocator.deallocate(start);
        start = the_allocator.allocate(x.end() - x.begin());
        end_of_storage = uninitialized_copy(x.begin(), x.end(), start);
    }
    else if (size() >= x.size())
    {
        iterator i = copy(x.begin(), x.end(), begin());
        destroy(i, finish);
    }
    else
    {
        copy(x.begin(), x.begin() + size(), begin());
        uninitialized_copy(x.begin() + size(), x.end(), begin() + size());
    }
    finish = begin() + x.size();
    return *this;
}

template <class T>
void vector<T>::insert_aux (iterator position, const T& x)
{
    if (finish != end_of_storage)
    {
        construct(finish, *(finish - 1));
        copy_backward(position, finish - 1, finish);
        *position = x;
        ++finish;
    }
    else
    {
        //
        // We always allocate enough space for a number of additional
        // elements in the vector, unless the size of each element is
        // very large.
        //
        const size_type CHUNKSIZE = sizeof(T) >= 1024 ? 1 : 1024 / sizeof(T);
        size_type len = size() ? 2 * size() : CHUNKSIZE;
        iterator tmp = the_allocator.allocate(len);
        uninitialized_copy(begin(), position, tmp);
        construct((tmp + (position - begin())), x);
        uninitialized_copy(position, end(), tmp + (position - begin()) + 1);
        destroy(begin(), end());
        the_allocator.deallocate(begin());
        end_of_storage = tmp + len;
        finish = tmp + size() + 1;
        start = tmp;
    }
}

template <class T>
void vector<T>::insert (iterator position, size_type n, const T& x)
{
    if (n == 0) return;
    if (end_of_storage - finish >= n)
    {
        if (end() - position > n)
        {
            uninitialized_copy(end() - n, end(), end());
            copy_backward(position, end() - n, end());
            fill(position, position + n, x);
        }
        else
        {
            uninitialized_copy(position, end(), position + n);
            fill(position, end(), x);
            uninitialized_fill_n(end(), n - (end() - position), x);
        }
        finish += n;
    }
    else
    {
        size_type len = size() + max(size(), n);
        iterator tmp = the_allocator.allocate(len);
        uninitialized_copy(begin(), position, tmp);
        uninitialized_fill_n(tmp + (position - begin()), n, x);
        uninitialized_copy(position, end(), tmp + (position - begin() + n));
        destroy(begin(), end());
        the_allocator.deallocate(begin());
        end_of_storage = tmp + len;
        finish = tmp + size() + n;
        start = tmp;
    }
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class T>
template<class InputIterator>
void vector<T>::insert (iterator position, InputIterator first,
                        InputIterator last)
#else
template<class T>
void vector<T>::insert (iterator position, const_iterator first,
                        const_iterator last)
#endif
{
    if (first == last) return;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);
    if (end_of_storage - finish >= n)
    {
        if (end() - position > n)
        {
            uninitialized_copy(end() - n, end(), end());
            copy_backward(position, end() - n, end());
            copy(first, last, position);
        }
        else
        {
            uninitialized_copy(position, end(), position + n);
            copy(first, first + (end() - position), position);
            uninitialized_copy(first + (end() - position), last, end());
        }
        finish += n;
    }
    else
    {
        size_type len = size() + max(size(), n);
        iterator tmp = the_allocator.allocate(len);
        uninitialized_copy(begin(), position, tmp);
        uninitialized_copy(first, last, tmp + (position - begin()));
        uninitialized_copy(position, end(), tmp + (position - begin() + n));
        destroy(begin(), end());
        the_allocator.deallocate(begin());
        end_of_storage = tmp + len;
        finish = tmp + size() + n;
        start = tmp;
    }
}

//
// If bool is a builtin type, we provide a vector<bool> specialization.
//
#ifndef RWSTD_NO_BOOL

#define __WORD_BIT (int(CHAR_BIT*sizeof(unsigned int)))

class vector<bool>
{
  public:
    //
    // types
    //
    typedef Allocator<unsigned int>                     vector_allocator;
    typedef bool                                        value_type;
    typedef typename vector_allocator::size_type        size_type;
    typedef typename vector_allocator::difference_type  difference_type;
    //
    // forward declarations
    //
    class iterator;
    class const_iterator;
    //
    // bit reference
    //
    class reference
    {
        friend class iterator;
        friend class const_iterator;
      protected:
        unsigned int* p;
        unsigned int mask;
        reference (unsigned int* x, unsigned int y) : p(x), mask(y) {}
      public:
        reference () : p(0), mask(0) {}
        operator bool () const { return !(!(*p & mask)); }
        reference& operator= (bool x)
        {
            if (x)
                *p |= mask;
            else
                *p &= ~mask;
            return *this;
        }
        reference& operator= (const reference& x) { return *this = bool(x); }
        bool operator== (const reference& x) const
        {
            return bool(*this) == bool(x);
        }
        bool operator< (const reference& x) const
        {
            return bool(*this) < bool(x);
        }
        void flip () { *p ^= mask; }
    };

    typedef bool const_reference;
    //
    // Definition of our iterator.
    //
    class iterator : public random_access_iterator<bool, difference_type>
    {
        friend class vector<bool>;
        friend class const_iterator;

      protected:

        unsigned int* p;
        unsigned int  offset;

        void bump_up ()
        {
            if (offset++ == __WORD_BIT - 1)
            {
                offset = 0; ++p;
            }
        }
        void bump_down ()
        {
            if (offset-- == 0)
            {
                offset = __WORD_BIT - 1; --p;
            }
        }

      public:

        iterator () : p(0), offset(0) {}
        iterator (unsigned int* x, unsigned int y) : p(x), offset(y) {}

        reference operator* () const { return reference(p, 1U << offset); }
        iterator& operator++ ()
        {
            bump_up(); return *this;
        }
        iterator operator++ (int)
        {
            iterator tmp = *this; bump_up(); return tmp;
        }
        iterator& operator-- ()
        {
            bump_down(); return *this;
        }
        iterator operator-- (int)
        {
            iterator tmp = *this; bump_down(); return tmp;
        }
        iterator& operator+= (difference_type i)
        {
            difference_type n = i + offset;
            p += n / __WORD_BIT;
            n = n % __WORD_BIT;
            if (n < 0)
            {
                offset = n + __WORD_BIT; --p;
            }
            else
                offset = n;
            return *this;
        }
        iterator& operator-= (difference_type i)
        {
            *this += -i; return *this;
        }
        iterator operator+ (difference_type i) const
        {
            iterator tmp = *this; return tmp += i;
        }
        iterator operator- (difference_type i) const
        {
            iterator tmp = *this; return tmp -= i;
        }
        difference_type operator- (iterator x) const
        {
            return __WORD_BIT * (p - x.p) + offset - x.offset;
        }
        reference operator[] (difference_type i)
        {
            return *(*this + i);
        }
        bool operator== (const iterator& x) const
        {
            return p == x.p && offset == x.offset;
        }
        bool operator< (iterator x) const
        {
            return p < x.p || (p == x.p && offset < x.offset);
        }
    };
    //
    // Definition of our const_iterator.
    //
    class const_iterator
        : public random_access_iterator<bool, difference_type>
    {
        friend class vector<bool>;

      protected:

        unsigned int* p;
        unsigned int offset;
        void bump_up ()
        {
            if (offset++ == __WORD_BIT - 1)
            {
                offset = 0; ++p;
            }
        }
        void bump_down()
        {
            if (offset-- == 0)
            {
                offset = __WORD_BIT - 1; --p;
            }
        }

      public:

        const_iterator () : p(0), offset(0) {}
        const_iterator (unsigned int* x, unsigned int y) : p(x), offset(y) {}
        const_iterator (const iterator& x) : p(x.p), offset(x.offset) {}

        const_reference operator* () const
        {
            return reference(p, 1U << offset);
        }
        const_iterator& operator++ ()
        {
            bump_up(); return *this;
        }
        const_iterator operator++ (int)
        {
            const_iterator tmp = *this; bump_up(); return tmp;
        }
        const_iterator& operator-- ()
        {
            bump_down(); return *this;
        }
        const_iterator operator-- (int)
        {
            const_iterator tmp = *this; bump_down(); return tmp;
        }
        const_iterator& operator+= (difference_type i)
        {
            difference_type n = i + offset;
            p += n / __WORD_BIT;
            n = n % __WORD_BIT;
            if (n < 0)
            {
                offset = n + __WORD_BIT; --p;
            }
            else
                offset = n;
            return *this;
        }
        const_iterator& operator-= (difference_type i)
        {
            *this += -i; return *this;
        }
        const_iterator operator+ (difference_type i) const
        {
            const_iterator tmp = *this; return tmp += i;
        }
        const_iterator operator- (difference_type i) const
        {
            const_iterator tmp = *this; return tmp -= i;
        }
        difference_type operator- (const_iterator x) const
        {
            return __WORD_BIT * (p - x.p) + offset - x.offset;
        }
        const_reference operator[] (difference_type i)
        {
            return *(*this + i);
        }
        bool operator== (const const_iterator& x) const
        {
            return p == x.p && offset == x.offset;
        }
        bool operator< (const_iterator x) const
        {
            return p < x.p || (p == x.p && offset < x.offset);
        }
    };
    //
    // types
    //
    typedef reverse_iterator<const_iterator,
                             value_type,
                             const_reference,
                             difference_type> const_reverse_iterator;
    typedef reverse_iterator<iterator,
                             value_type,
                             reference,
                             difference_type> reverse_iterator;
  protected:

    Allocator<unsigned int> the_allocator;
    iterator                start;
    iterator                finish;
    unsigned int*           end_of_storage;

    unsigned int* bit_alloc (size_type n)
    {
        return the_allocator.allocate((n + __WORD_BIT - 1)/__WORD_BIT);
    }
    void initialize (size_type n)
    {
        unsigned int* q = bit_alloc(n);
        end_of_storage = q + (n + __WORD_BIT - 1)/__WORD_BIT;
        start = iterator(q, 0);
        finish = start + n;
    }
    void insert_aux (iterator position, bool x);

  public:

    //
    // construct/copy/destroy
    //
    explicit vector ()
        : start(iterator()), finish(iterator()), end_of_storage(0) {}
    explicit vector (size_type n, bool value = bool())
    {
        initialize(n); fill(start.p, end_of_storage, value ? ~0 : 0);
    }
    vector (const vector<bool>& x)
    {
        initialize(x.size()); copy(x.begin(), x.end(), start);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class InputIterator>
    vector (InputIterator first, InputIterator last)
    {
        size_type n;
        __initialize(n, size_type(0));
        distance(first, last, n);
        initialize(n);
        copy(first, last, start);
    }
#else
    vector (const_iterator first, const_iterator last)
    {
        size_type n;
        __initialize(n, size_type(0));
        distance(first, last, n);
        initialize(n);
        copy(first, last, start);
    }
    vector (const bool* first, const bool* last)
    {
        size_type n;
        __initialize(n, size_type(0));
        distance(first, last, n);
        initialize(n);
        copy(first, last, start);
    }
#endif
    ~vector () { the_allocator.deallocate(start.p); }
    vector& operator= (const vector<bool>& x)
    {
        if (&x == this) return *this;
        if (x.size() > capacity())
        {
            the_allocator.deallocate(start.p);
            initialize(x.size());
        }
        copy(x.begin(), x.end(), begin());
        finish = begin() + x.size();
        return *this;
    }
#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void assign (InputIterator first, InputIterator last)
#else
    void assign (const_iterator first, const_iterator last)
#endif
    {
        erase(begin(), end()); insert(begin(), first, last);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class Size, class T>
    void assign (Size n, const bool& t = bool())
#else
    void assign (size_type n, const bool& t = bool())
#endif
    {
        erase(begin(), end()); insert(begin(), n, t);
    }
    //
    // iterators
    //
    iterator       begin ()       { return start; }
    const_iterator begin () const { return start; }
    iterator       end   ()       { return finish; }
    const_iterator end   () const { return finish; }

    reverse_iterator       rbegin () { return reverse_iterator(end()); }
    const_reverse_iterator rbegin () const
    {
        return const_reverse_iterator(end());
    }
    reverse_iterator       rend () { return reverse_iterator(begin()); }
    const_reverse_iterator rend () const
    {
        return const_reverse_iterator(begin());
    }
    //
    // capacity
    //
    size_type size     () const { return size_type(end() - begin());  }
    size_type max_size () const { return the_allocator.max_size(); }
    void resize (size_type new_size, bool c = false);
    size_type capacity () const
    {
        return size_type(const_iterator(end_of_storage, 0) - begin());
    }
    bool empty () const { return begin() == end(); }
    void reserve (size_type n)
    {
        if (capacity() < n)
        {
            unsigned int* q = bit_alloc(n);
            finish = copy(begin(), end(), iterator(q, 0));
            the_allocator.deallocate(start.p);
            start = iterator(q, 0);
            end_of_storage = q + (n + __WORD_BIT - 1)/__WORD_BIT;
        }
    }
    //
    // element access
    //
    reference       operator[] (size_type n)       { return *(begin() + n); }
    const_reference operator[] (size_type n) const { return *(begin() + n); }
    reference       at (size_type n)               { return *(begin() + n); }
    const_reference at (size_type n)         const { return *(begin() + n); }
    reference       front ()       { return *begin();     }
    const_reference front () const { return *begin();     }
    reference       back  ()       { return *(end() - 1); }
    const_reference back  () const { return *(end() - 1); }
    //
    // modifiers
    //
    void push_back (bool x)
    {
        if (finish.p != end_of_storage)
            *finish++ = x;
        else
            insert_aux(end(), x);
    }
    void pop_back () { --finish; }
    iterator insert (iterator position, const bool& x = bool())
    {
        size_type n = position - begin();
        if (finish.p != end_of_storage && position == end())
            *finish++ = x;
        else
            insert_aux(position, x);
        return begin() + n;
    }
    void insert (iterator position, size_type n, const bool& x = bool());

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);
#else
    void insert (iterator position, const_iterator first,
                 const_iterator last);
#endif

    void erase (iterator position)
    {
        if (position + 1 != end())
            copy(position + 1, end(), position);
        --finish;
    }
    void erase(iterator first, iterator last)
    {
        finish = copy(last, end(), first);
    }
    void swap (vector<bool>& x)
    {
#ifndef RWSTD_NO_NAMESPACE
        std::swap(start,          x.start);
        std::swap(finish,         x.finish);
        std::swap(the_allocator,  x.the_allocator);
        std::swap(end_of_storage, x.end_of_storage);
#else
        ::swap(start,          x.start);
        ::swap(finish,         x.finish);
        ::swap(the_allocator,  x.the_allocator);
        ::swap(end_of_storage, x.end_of_storage);
#endif
    }
    void flip ();
};

inline bool operator== (const vector<bool>& x, const vector<bool>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

inline bool operator< (const vector<bool>& x, const vector<bool>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

void vector<bool>::flip ()
{
    for (iterator i = begin(); i != end(); i++)
        *i = !(*i);
}

void swap (typename vector<bool>::reference x,
           typename vector<bool>::reference y)
{
    bool tmp = x; x = y; y = tmp;
}

void vector<bool>::insert_aux (iterator position, bool x)
{
    if (finish.p != end_of_storage)
    {
        copy_backward(position, finish - 1, finish);
        *position = x;
        ++finish;
    }
    else
    {
        size_type len = size() ? 2 * size() : __WORD_BIT;
        unsigned int* q = bit_alloc(len);
        iterator i = copy(begin(), position, iterator(q, 0));
        *i++ = x;
        finish = copy(position, end(), i);
        the_allocator.deallocate(start.p);
        end_of_storage = q + (len + __WORD_BIT - 1)/__WORD_BIT;
        start = iterator(q, 0);
    }
}

void vector<bool>::insert (iterator position, size_type n, const bool& x)
{
    if (n == 0) return;
    if (capacity() - size() >= n)
    {
        copy_backward(position, end(), finish + n);
        fill(position, position + n, x);
        finish += n;
    }
    else
    {
        size_type len = size() + max(size(), n);
        unsigned int* q = bit_alloc(len);
        iterator i = copy(begin(), position, iterator(q, 0));
        fill_n(i, n, x);
        finish = copy(position, end(), i + n);
        the_allocator.deallocate(start.p);
        end_of_storage = q + (n + __WORD_BIT - 1)/__WORD_BIT;
        start = iterator(q, 0);
    }
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class InputIterator>
void vector<bool>::insert (iterator position, InputIterator first,
                           InputIterator last)
#else
void vector<bool>::insert (iterator position, const_iterator first,
                           const_iterator last)
#endif
{
    if (first == last) return;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);
    if (capacity() - size() >= n)
    {
        copy_backward(position, end(), finish + n);
        copy(first, last, position);
        finish += n;
    }
    else
    {
        size_type len = size() + max(size(), n);
        unsigned int* q = bit_alloc(len);
        iterator i = copy(begin(), position, iterator(q, 0));
        i = copy(first, last, i);
        finish = copy(position, end(), i);
        the_allocator.deallocate(start.p);
        end_of_storage = q + (len + __WORD_BIT - 1)/__WORD_BIT;
        start = iterator(q, 0);
    }
}

void vector<bool>::resize (size_type new_size, bool c)
{
  if (new_size > size())
      insert(end(), new_size - size(), c);
  else if (new_size < size())
      erase(begin() + new_size, end());
}

#undef __WORD_BIT

#endif /*RWSTD_NO_BOOL*/

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#undef Allocator
#undef vector

#endif /*__STD_VECTOR__*/
