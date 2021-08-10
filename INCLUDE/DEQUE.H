#ifndef __DEQUE_H
#define __DEQUE_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * deque - Declaration and definition for the Standard Library deque class
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

#ifndef __STD_DEQUE__
#define __STD_DEQUE__

#include <rw/stddefs.h> 
#include <rw/rwdispatch.h> 

#include <stdcomp.h>
#include <algorithm>
#include <iterator>
#include <memory>
#include <stdexcept>

#ifndef deque 
#define deque deque
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Note that _RWSTD_COMPLEX_DEFAULT(x)
// will expand to: ' = x', or nothing,
// depending on your compiler's capabilities and/or
// flag settings (see stdcomp.h).
//
  template <class T, class Allocator _RWSTD_COMPLEX_DEFAULT(allocator<T>) >
  class  deque
  {
  protected:
#ifdef _RWSTD_ALLOCATOR
    typedef _TYPENAME Allocator::template rebind<T>::other __value_alloc_type;
#else
    typedef allocator_interface<Allocator,T>    __value_alloc_type;
#endif

  public:

    //
    // Types.
    //
    class  iterator;
    class  const_iterator;
    friend class iterator;
    friend class const_iterator;
    typedef T                                          value_type;
    typedef Allocator                                  allocator_type;

#ifndef _RWSTD_NO_COMPLICATED_TYPEDEF
    typedef _TYPENAME _RWSTD_ALLOC_SIZE_TYPE              size_type;
    typedef _TYPENAME _RWSTD_ALLOC_DIFF_TYPE              difference_type;
    typedef _TYPENAME __value_alloc_type::reference       reference;
    typedef _TYPENAME __value_alloc_type::const_reference const_reference;
    typedef _TYPENAME __value_alloc_type::pointer         pointer;
    typedef _TYPENAME __value_alloc_type::const_pointer   const_pointer;
#else
    typedef size_t            size_type;
    typedef ptrdiff_t         difference_type;
    typedef T&                reference;
    typedef const T&          const_reference;
    typedef T*                pointer;
    typedef const T*          const_pointer;
#endif  //_RWSTD_NO_COMPLICATED_TYPEDEF

  protected:
#ifdef _RWSTD_ALLOCATOR
    typedef _TYPENAME Allocator::template rebind<pointer>::other __map_alloc_type;
#else
    typedef allocator_interface<allocator_type,pointer> __map_alloc_type;
#endif
    typedef _TYPENAME __map_alloc_type::pointer         __map_pointer;

    static size_type __buffer_size ();

    typedef _RW_STD::iterator<random_access_iterator_tag, value_type,
                    difference_type, pointer,reference> __it;
    typedef _RW_STD::iterator<random_access_iterator_tag, value_type, 
                    difference_type, const_pointer, const_reference> __cit;

  public:
    //
    // Definition of our iterator.
    //
    class iterator : public __it
    {
      friend class deque<T,Allocator>;
      friend class const_iterator;

    protected:

      pointer     current;
      pointer     first;
      pointer     last;
      __map_pointer node;

      iterator (pointer x, __map_pointer y)
        : current(x), first(*y), last(*y + __buffer_size()), node(y) {}

    public:

      iterator () : current(0), first(0), last(0), node(0) {}
      iterator (const iterator& x) 
        : current(x.current), first(x.first), 
          last(x.last), node(x.node) {}     
      reference operator* () const { return *current; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
      pointer operator-> () const { return current; }
#endif
#ifdef _HPACC_
      void operator= (const iterator& x)
      {
	current = x.current;
	first = x.first;
	last = x.last;
	node = x.node;
      }
#endif
      difference_type operator- (const iterator& x) const
      {
        return node == x.node 
        ? current - x.current 
        : difference_type(__buffer_size() * (node - x.node - 1) +
                          (current - first) + (x.last - x.current));
      }
      iterator& operator++ ()
      {
        if (++current == last)
        {
          first = *(++node);
          current = first;
          last = first + __buffer_size();
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
          last = first + __buffer_size();
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
        ? offset / __buffer_size()
        : -(difference_type)((-offset + __buffer_size() - 1) / __buffer_size());
        if (num_node_to_jump == 0)
          current += n;
        else
        {
          node = node + num_node_to_jump;
          first = *node;
          last = first + __buffer_size();
          current = first + (offset - num_node_to_jump * __buffer_size());
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
      bool operator!= (const iterator& x) const { return !(*this == x); } 
      bool operator< (const iterator& x) const
      {
        return (node == x.node) ? (current < x.current) : (node < x.node);
      } 
      bool operator> (const iterator& x) const
      {
        return x < *this;
      }
      bool operator>= (const iterator& x) const
      {
        return !(*this < x);
      }
      bool operator<= (const iterator& x) const
      {
        return !(*this > x);
      }
    };  // End of nested definiton of iterator.

    //
    // Definition of our constant iterator.
    //
    class const_iterator  : public __cit
    {
      friend class deque<T,Allocator>;

    protected:

      pointer     current;
      pointer     first;
      pointer     last;
      __map_pointer node;

      const_iterator (pointer x, __map_pointer y) 
        : current(x), first(*y), last(*y + __buffer_size()), node(y) {}

    public:
       
      const_iterator () : current(0), first(0), last(0), node(0) {}
#if !defined(_MSC_VER) || defined(__BORLANDC__)
      const_iterator (const _TYPENAME deque<T,Allocator>::iterator& x) 
#else
      const_iterator (const iterator& x) 
#endif
        : current(x.current), first(x.first), last(x.last), node(x.node) {}     
      const_reference operator* () const { return *current; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
      const_pointer operator-> () const { return current; }
#endif
      difference_type operator- (const const_iterator& x) const
      {
        return node == x.node 
        ? current - x.current 
        : difference_type(__buffer_size() * (node - x.node - 1) +
                          (current - first) + (x.last - x.current));
      }
      const_iterator& operator++ ()
      {
        if (++current == last)
        {
          first = *(++node);
          current = first;
          last = first + __buffer_size();
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
          last = first + __buffer_size();
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
        ? offset / __buffer_size()
        : -(difference_type)((-offset + __buffer_size() - 1) / __buffer_size());
        if (num_node_to_jump == 0)
          current += n;
        else
        {
          node = node + num_node_to_jump;
          first = *node;
          last = first + __buffer_size();
          current = first + (offset - num_node_to_jump * __buffer_size());
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
      bool operator!= (const const_iterator& x) const { return !(*this == x); }
      bool operator< (const const_iterator& x) const
      {
        return (node == x.node) ? (current < x.current) : (node < x.node);
      } 
      bool operator> (const const_iterator& x) const
      {
        return x < *this;
      }
      bool operator>= (const const_iterator& x) const
      {
        return !(*this < x);
      }
      bool operator<= (const const_iterator& x) const
      {
        return !(*this > x);
      }
    };  // End of nested definiton of const_iterator.

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
    typedef _RW_STD::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef _RW_STD::reverse_iterator<iterator>  reverse_iterator;
#else
    typedef _RW_STD::reverse_iterator<const_iterator, 
      random_access_iterator_tag, value_type, 
      const_reference, const_pointer, difference_type>
      const_reverse_iterator;
    typedef _RW_STD::reverse_iterator<iterator, 
      random_access_iterator_tag, value_type,
      reference, pointer, difference_type>
      reverse_iterator;
#endif

  protected:

    iterator      __start;
    iterator      __finish;
    size_type     __length;
    __map_pointer __map;
    __RWSTD::__rw_basis<size_type,allocator_type>     __map_size;

    void __allocate_at_begin   ();    
    void __allocate_at_end     ();
    void __deallocate_at_begin ();
    void __deallocate_at_end   ();
    void __insert_aux (iterator position, size_type n, const T& x);
#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void __insert_aux (iterator position, InputIterator first, InputIterator last, _RW_is_not_integer)
    { __insert_aux2 (position, first, last); }
    template<class InputIterator>
    void __insert_aux (iterator position, InputIterator first, InputIterator last, _RW_is_integer)
    { __insert_aux (position, (size_type)first, last); }
    template<class InputIterator>
    void __insert_aux2 (iterator position, InputIterator first, InputIterator last);
#endif

  public:
    //
    // construct/copy/destroy
    //
    _EXPLICIT deque (const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) 
      : __start(), __finish(), __length(0), __map(0), __map_size(0,alloc) 
    { ; }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    deque (void) 
      : __start(), __finish(), __length(0), __map(0), __map_size(0,Allocator()) 
    { ; }

    deque (size_type n, const T& value)
      : __start(), __finish(), __length(0), __map(0), __map_size(0,Allocator()) 
    {
      insert(begin(), n, value);
    }
#endif // _RWSTD_NO_DEFAULT_TEMPLATE_ARGS

    _EXPLICIT deque (size_type n)
      : __start(), __finish(), __length(0), __map(0), __map_size(0,Allocator()) 
    {
      insert(begin(), n, T());
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES

    template<class InputIterator>
    deque (InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
      : __start(), __finish(), __length(0), __map(0), __map_size(0,alloc) 
    {
      typedef _TYPENAME _RWdispatch<InputIterator>::_RWtype _RWtype;
      __insert_aux(begin(), first, last, _RWtype());
    }

	deque (size_type n, const T& value,
		   const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
			: __start(), __finish(), __length(0), __map(0), __map_size(0,alloc) 
	{
		insert(begin(), n, value);
	}

#else
    //
    // Build a deque of size n with each element set to copy of value.
    //
    deque (size_type n, const T& value,
           const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __start(), __finish(), __length(0), __map(0), __map_size(0,alloc) 
    {
      insert(begin(), n, value);
    }
    deque (const_iterator first, const_iterator last, const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __start(), __finish(), __length(0), __map(0), __map_size(0,alloc) 
    {
      copy(first, last, back_inserter(*this));
    }
    
    deque (const T* first, const T* last, const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __start(), __finish(), __length(0), __map(0), __map_size(0,alloc) 
    {
      copy(first, last, back_inserter(*this));
    }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    deque (const_iterator first, const_iterator last)
      : __start(), __finish(), __length(0), __map(0), __map_size(0,Allocator()) 
    {
      copy(first, last, back_inserter(*this));
    }
    
    deque (const T* first, const T* last)
      : __start(), __finish(), __length(0), __map(0), __map_size(0,Allocator()) 
    {
      copy(first, last, back_inserter(*this));
    }
#endif // _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
#endif // _RWSTD_NO_MEMBER_TEMPLATES

    deque (const deque<T,Allocator>& x)
      : __start(), __finish(), __length(0), __map(0), __map_size(0,x.get_allocator())
    {
      copy(x.begin(), x.end(), back_inserter(*this));
    }

    ~deque ();
    deque<T,Allocator>& operator= (const deque<T,Allocator>& x)
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

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
	template<class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		erase(begin(), end());
    	typedef _TYPENAME _RWdispatch<InputIterator>::_RWtype _RWtype;
	    __insert_aux(begin(), first, last, _RWtype());
	}
	void assign (size_type n, const T& t)
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
    // Assign n copies of t to this vector.
    //
    void assign (size_type n, const T& t)
    {
      erase(begin(), end()); insert(begin(), n, t);
    }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

    allocator_type get_allocator() const
    {
      return (allocator_type)__map_size;
    }

    //
    // Iterators.
    //
    iterator         begin  ()       { return __start;  }
    const_iterator   begin  () const { return __start;  }
    iterator         end    ()       { return __finish; }
    const_iterator   end    () const { return __finish; }
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
    bool      empty    () const { return __length == 0; }
    size_type size     () const { return __length; }
    size_type max_size () const 
    { return __value_alloc_type(__map_size).max_size(); }
    void      resize (size_type new_size);
    void      resize (size_type new_size, T value);
    //
    // Element access.
    //
    reference       operator[] (size_type n)
    {
#ifdef _RWSTD_BOUNDS_CHECKING
      _RWSTD_THROW(n >= size(), out_of_range,
        __RWSTD::except_msg_string(__RWSTD::rwse_OutOfRange,
          "deque::operator[](size_t)",n,size()).msgstr());
      return *(begin() + n);
#else
      return *(begin() + n);
#endif
    }
    const_reference operator[] (size_type n) const
    {
#ifdef _RWSTD_BOUNDS_CHECKING
      _RWSTD_THROW(n >= size(), out_of_range,
        __RWSTD::except_msg_string(__RWSTD::rwse_OutOfRange,
          "deque::operator[](size_t) const",n,size()).msgstr());
      return *(begin() + n);
#else
      return *(begin() + n);
#endif
    }
    const_reference at (size_type n) const 
    { 
      _RWSTD_THROW(n >= size(), out_of_range,
        __RWSTD::except_msg_string(__RWSTD::rwse_OutOfRange,
          "deque:: at(size_t) const",n,size()).msgstr());
      return *(begin() + n); 
    }
    reference       at (size_type n)
    { 
      _RWSTD_THROW(n >= size(), out_of_range,
        __RWSTD::except_msg_string(__RWSTD::rwse_OutOfRange,
          "deque:: at(size_t)",n,size()).msgstr());
      return *(begin() + n); 
    }
    reference       front ()                       { return *begin();       }
    const_reference front ()                 const { return *begin();       }
    reference       back ()                        { return *(end() - 1);   }
    const_reference back ()                  const { return *(end() - 1);   }

    //
    // Modifiers.
    //
    void push_front (const T& x)
    {
      if (empty() || begin().current == begin().first) 
        __allocate_at_begin();
      __value_alloc_type(__map_size).construct(__start.current-1, x);
      --__start.current;
      ++__length;
    }
    void push_back (const T& x)
    {
      if (empty() || end().current == end().last) 
        __allocate_at_end();
      __value_alloc_type(__map_size).construct(__finish.current, x);
      ++__finish.current;
      ++__length;
    }

    //
    // Insert x at position.
    //
    iterator insert (iterator position, const T& x);

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (iterator position, InputIterator first, 
                 InputIterator last)
    {
        typedef _TYPENAME _RWdispatch<InputIterator>::_RWtype _RWtype;
        __insert_aux(position, first, last, _RWtype());
    }
    void insert (iterator position, size_type n, const T& value)
    { __insert_aux(position,n,value); }
#else
    void insert (iterator position, size_type n, const T& x)
    { __insert_aux(position,n,x); }
    void insert (iterator position, const T* first, const T* last);
    void insert (iterator position, const_iterator first, const_iterator last);
#endif // _RWSTD_NO_MEMBER_TEMPLATES

    void pop_front ()
    {
      iterator tmp = __start;
      ++__start.current;
      --__length; 
      __value_alloc_type(__map_size).destroy(tmp.current);
      if (empty() || begin().current == begin().last) 
        __deallocate_at_begin();
    }
    void pop_back ()
    {
      --__finish.current;
      --__length; 
      __value_alloc_type(__map_size).destroy(__finish.current);
      if (empty() || end().current == end().first) 
        __deallocate_at_end();
    }
    iterator erase (iterator position);
    iterator erase (iterator first, iterator last);    
    void swap (deque<T,Allocator>& x)
    {
      if((allocator_type)__map_size== (allocator_type)x.__map_size)
      {
#ifndef _RWSTD_NO_NAMESPACE
        std::swap(__start,          x.__start);
        std::swap(__finish,         x.__finish);
        std::swap(__length,         x.__length);
        std::swap(__map,            x.__map);
        std::swap(__map_size,       x.__map_size);
#else
        ::swap(__start,             x.__start);
        ::swap(__finish,            x.__finish);
        ::swap(__length,            x.__length);
        ::swap(__map,               x.__map);
        ::swap(__map_size,          x.__map_size);
#endif // _RWSTD_NO_NAMESPACE
      }
      else
      {
        deque<T,Allocator> _x=*this;
        *this=x;
        x=_x;
      }
    }
    void clear()
    {
      erase(begin(),end());
    }
  };

  template <class T, class Allocator>
  inline bool operator== (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
  {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
  }

  template <class T, class Allocator>
  inline bool operator< (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
  {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class T, class Allocator>
  inline bool operator!= (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
  {
    return !(x == y);
  }

  template <class T, class Allocator>
  inline bool operator> (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
  {
    return y < x;
  }

  template <class T, class Allocator>
  inline bool operator>= (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
  {
    return !(x < y);
  }

  template <class T, class Allocator>
  inline bool operator<= (const deque<T,Allocator>& x, const deque<T,Allocator>& y)
  {
    return !(y <  x);
  }

  template <class T, class Allocator>
  inline void swap(deque<T,Allocator>& a, deque<T,Allocator>& b)
  {
    a.swap(b);
  }
#endif // !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <deque.cc>
#endif

#undef deque

#endif /*__STD_DEQUE__*/

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __DEQUE_H */
