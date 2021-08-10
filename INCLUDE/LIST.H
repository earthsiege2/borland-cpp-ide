#ifndef __LIST_H
#define __LIST_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_LIST__
#define __STD_LIST__

/***************************************************************************
 *
 * list - list declarations for the Standard Library
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
#include <iterator>
#include <memory>
#include <stdexcept>
#include <rw/rwdispatch.h>

#ifndef list
#define list list
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
  class list
  {
  protected:
    struct __list_node;
    struct __list_node_buffer;
    friend struct __list_node;
    friend struct __list_node_buffer;

#ifdef _RWSTD_ALLOCATOR
    typedef _TYPENAME Allocator::template rebind<__list_node>::other  __list_node_alloc_type;
    typedef _TYPENAME Allocator::template rebind<T>::other __value_alloc_type;
    typedef _TYPENAME Allocator::template rebind<__list_node_buffer>::other  __buffer_alloc_type;
#else
    typedef allocator_interface<Allocator,__list_node>  __list_node_alloc_type;
    typedef allocator_interface<Allocator,T>          __value_alloc_type;
    typedef allocator_interface<Allocator,__list_node_buffer>   __buffer_alloc_type;
#endif // _RWSTD_ALLOCATOR

  public:
    //
    // types
    //
    typedef _TYPENAME __value_alloc_type::reference        reference;
    typedef _TYPENAME __value_alloc_type::const_reference  const_reference;
    typedef _TYPENAME __value_alloc_type::size_type        size_type;
    typedef _TYPENAME __value_alloc_type::difference_type  difference_type;
    typedef T                                    value_type;
    typedef Allocator                            allocator_type;
    typedef _TYPENAME __value_alloc_type::pointer        pointer;
    typedef _TYPENAME __value_alloc_type::const_pointer  const_pointer;

  protected:
    typedef _TYPENAME __list_node_alloc_type::pointer    __link_type;
    typedef _TYPENAME __buffer_alloc_type::pointer       __buffer_pointer;

    struct __list_node
    {
      __link_type next;
      __link_type prev;
      T           data;
    };

    struct __list_node_buffer
    {
      __buffer_pointer next_buffer;
      size_type        size;
      __link_type      buffer;
    };

    size_type          __buffer_size;    
    __RWSTD::__rw_basis<__buffer_pointer,allocator_type>   __buffer_list;
    __link_type        __free_list;
    __link_type        __next_avail;
    __link_type        __last;
    __link_type        __node;
    size_type          __length;
    
    void __add_new_buffer (size_type n)
    {
      __buffer_pointer tmp = 
        __buffer_alloc_type(__buffer_list).allocate(
          _RWSTD_STATIC_CAST(size_type,1),__buffer_list.data());
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        tmp->buffer = __list_node_alloc_type(__buffer_list).allocate(n,__last);
      } catch(...) {
        __buffer_alloc_type(__buffer_list).deallocate(tmp,1);
        throw;
      }      
#else
      tmp->buffer = __list_node_alloc_type(__buffer_list).allocate(n,__last);
#endif // _RWSTD_NO_EXCEPTIONS
      tmp->next_buffer = __buffer_list;
      tmp->size = n;
      __buffer_list = tmp;
      __next_avail = __buffer_list.data()->buffer; 
      __last = __next_avail + n;
    }
    void __deallocate_buffers ();
    __link_type __get_node (size_type n)
    {
      __link_type tmp = __free_list;
      return __free_list ? (__free_list = (__link_type)(__free_list->next), tmp) 
      : (__next_avail == __last ? (__add_new_buffer(n), __next_avail++) 
         : __next_avail++);
    }
    void __put_node (__link_type p) { p->next = __free_list; __free_list = p; }

    void __init(size_type n = 0)  
    {
      __buffer_size = max((size_type)1,
                        __RWSTD::__rw_allocation_size((value_type*)0,
                                                      (size_type)0,
                                                      (size_type)0));
      __node = __get_node(n == 0 ? __buffer_size : n + 1);
      (*__node).next = __node;
      (*__node).prev = __node; 
    }
    void __init(size_type n, value_type value)  
    {
      __init(n);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), n, value);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), n, value);
#endif
    }

    typedef _RW_STD::iterator<bidirectional_iterator_tag, value_type,
                    difference_type, pointer,reference> __it;
    typedef _RW_STD::iterator<bidirectional_iterator_tag, value_type, 
                    difference_type, const_pointer, const_reference> __cit;

  public:
    
    class iterator;
    class const_iterator;
    friend class iterator;
    friend class const_iterator;

    class iterator : public __it
    {
      friend class list<T,Allocator>;
      friend class const_iterator;

    protected:
      
      __link_type node;
      iterator (__link_type x) : node(x) {}
    
    public:

      iterator () {}
      bool operator== (const iterator& x) const { return node == x.node; }
      bool operator!= (const iterator& x) const { return !(*this == x); }
      reference operator* () const { return (*node).data; } 
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
      pointer operator-> () const { return &(node->data); }
#endif
      iterator& operator++ ()
      { 
        node = (__link_type)((*node).next); return *this;
      }
      iterator operator++ (int)
      {
        iterator tmp = *this; ++*this; return tmp;
      }
      iterator& operator-- ()
      {
        node = (__link_type)((*node).prev); return *this;
      }
      iterator operator-- (int)
      {
        iterator tmp = *this; --*this; return tmp;
      }
    };  // End of definition of iterator class.

    class const_iterator : public __cit
    {
      friend class list<T,Allocator>;

    protected:
      
      __link_type node;
      const_iterator (__link_type x) : node(x) {}
    
    public:

      const_iterator () {}
#if !defined(_MSC_VER) || defined(__BORLANDC__)
      const_iterator (const  _TYPENAME list<T,Allocator>::iterator& x) : node(x.node) {}
#else
      const_iterator (const iterator& x) : node(x.node) {}
#endif
      bool operator== (const const_iterator& x) const {return node==x.node;}
      bool operator!= (const const_iterator x) const { return !(*this == x); } 
      const_reference operator* () const { return (*node).data; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
      const_pointer operator-> () const { return &(node->data); }
#endif
      const_iterator& operator++ ()
      { 
        node = (__link_type)((*node).next); return *this;
      }
      const_iterator operator++ (int)
      {
        const_iterator tmp = *this; ++*this; return tmp;
      }
      const_iterator& operator-- ()
      {
        node = (__link_type)((*node).prev); return *this;
      }
      const_iterator operator-- (int)
      {
        const_iterator tmp = *this;
        --*this;
        return tmp;
      }
    };  // End of definition of const_iterator class.

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
    typedef _RW_STD::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef _RW_STD::reverse_iterator<iterator>  reverse_iterator;
#else
    typedef __reverse_bi_iterator<const_iterator, 
      bidirectional_iterator_tag, value_type, 
      const_reference, const_pointer, difference_type>
      const_reverse_iterator;
    typedef __reverse_bi_iterator<iterator, 
      bidirectional_iterator_tag, value_type,
      reference, pointer, difference_type>
      reverse_iterator;
#endif

    //
    // construct/copy/destroy
    //
    list (const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) 
      : __length(0), __buffer_list(0,alloc),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init(1);
    }
    
#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS  
    list (void) 
      : __length(0), __buffer_list(0,Allocator()),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init(1);
    }

    list (size_type n, const T& value)
      : __length(0), __buffer_list(0,Allocator()),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init(n,value);
    }
#endif // _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    _EXPLICIT list (size_type n) 
      : __length(0), __buffer_list(0,Allocator()),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      T value = T();
      __init(n,value);
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES

    template<class InputIterator>
    void __init_aux (InputIterator first, InputIterator locallast, _RW_is_not_integer)
    {
      __init();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), first, locallast);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), first, locallast);
#endif
    }
    template<class InputIterator>
    void __init_aux (InputIterator first, InputIterator last, _RW_is_integer)
    { __init(first, last); }

    template<class InputIterator>
    list (InputIterator first, InputIterator locallast,
          const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __length(0), __buffer_list(0,alloc),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
        typedef _TYPENAME _RWdispatch<InputIterator>::_RWtype _RWtype;
        __init_aux(first, locallast, _RWtype());
    }
    list (size_type n, const T& value,
          const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      :  __length(0), __buffer_list(0,alloc),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    { __init(n, value); }
#else
    //
    // Build a list of size n with each element set to a copy of value.
    //
    list (size_type n, const T& value,
          const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) 
      : __length(0), __buffer_list(0,alloc),
       __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init(n, value);
    }

    list (const_iterator first, const_iterator locallast,
          const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __length(0), __buffer_list(0,alloc),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), first, locallast);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), first, locallast);
#endif
    }
    list (const T* first, const T* locallast,
          const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __length(0), __buffer_list(0,alloc),
       __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), first, locallast);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), first, locallast);
#endif
    }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    list (const_iterator first, const_iterator locallast)
      : __length(0), __buffer_list(0,Allocator()),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), first, locallast);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), first, locallast);
#endif
    }

    list (const T* first, const T* locallast)
      : __length(0), __buffer_list(0,Allocator()),
        __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), first, locallast);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), first, locallast);
#endif
    }
#endif // _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
#endif // _RWSTD_NO_MEMBER_TEMPLATES

    list (const list<T,Allocator>& x) : __length(0), __buffer_list(0,x.get_allocator()),
      __free_list(0), __next_avail(0), __last(0), __node(0)
    {
      __init();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(begin(), x.begin(), x.end());
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(begin(), x.begin(), x.end());
#endif
    }

    ~list ()
    {
      if (__node)
      {
        erase(begin(), end());
        __put_node(__node);
        __deallocate_buffers();
      }
    }
    list<T,Allocator>& operator= (const list<T,Allocator>& x);   

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
    { erase(begin(), end()); insert(begin(), first, last); }
    void assign (const T* first, const T* last)
    { erase(begin(), end()); insert(begin(), first, last); }
    //
    // Assign n copies of t to this list.
    //
    void assign (size_type n, const T& t)
    { erase(begin(), end()); insert(begin(), n, t); }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

    allocator_type get_allocator() const
    {
      return (allocator_type)__buffer_list;
    }

    //
    // Iterators.
    //
    iterator       begin ()       { return _RWSTD_STATIC_CAST(__link_type,((*__node).next)); }
    const_iterator begin () const { return _RWSTD_STATIC_CAST(__link_type,((*__node).next)); }

    iterator       end ()         { return __node;                      }
    const_iterator end ()   const { return __node;                      }
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
    bool empty ()         const { return __length == 0;                }
    size_type size ()     const { return __length;                     }
    size_type max_size () const 
    { return __list_node_alloc_type(__buffer_list).max_size(); }
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
    void push_front (const T& x) { insert(begin(), x); }
    void push_back  (const T& x) { insert(end(), x);   }
    void pop_front  ()           { erase(begin());     }
    void pop_back   ()           { iterator tmp = end(); erase(--tmp); }

    //
    // Insert x at position.
    //
    iterator insert (iterator position, const T& x)
    {
      __value_alloc_type va(__buffer_list);
      __link_type tmp = __get_node(__buffer_size);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
       va.construct(va.address((*tmp).data),x);
      } catch(...) {
        __put_node(tmp);
        throw;
      }      
#else
      va.construct(va.address((*tmp).data),x);
#endif // _RWSTD_NO_EXCEPTIONS
      (*tmp).next = position.node;
      (*tmp).prev = (*position.node).prev;
      (*(__link_type((*position.node).prev))).next = tmp;
      (*position.node).prev = tmp;
      ++__length;
      return tmp;
    }

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

    iterator erase (iterator position)
    {
      if (position == end())
        return end();
      iterator tmp = (iterator)(__link_type((*position.node).next));
      (*(__link_type((*position.node).prev))).next = (*position.node).next;
      (*(__link_type((*position.node).next))).prev = (*position.node).prev;
      --__length;
      __value_alloc_type va(__buffer_list);
      va.destroy(va.address((*position.node).data));
      __put_node(position.node);
      return tmp;
    }
    iterator erase      (iterator first, iterator last);
    void swap (list<T,Allocator>& x)
    {
      if((allocator_type)__buffer_list==(allocator_type)x.__buffer_list)
      {

#ifndef _RWSTD_NO_NAMESPACE
        std::swap(__node, x.__node); 
        std::swap(__length, x.__length);
        std::swap(__buffer_list,x.__buffer_list);
        std::swap(__free_list,x.__free_list);
        std::swap(__next_avail,x.__next_avail);
        std::swap(__last,x.__last);
#else
        ::swap(__node, x.__node); 
        ::swap(__length, x.__length);
        ::swap(__buffer_list,x.__buffer_list);
        ::swap(__free_list,x.__free_list);
        ::swap(__next_avail,x.__next_avail);
        ::swap(__last,x.__last);
#endif // _RWSTD_NO_NAMESPACE
      }
      else
      {
        list<T,Allocator> _x = *this;
        *this=x;
        x=_x;
      }
    }

    void clear()
    {
      erase(begin(),end());
    }

  protected:
    
    void __transfer (iterator position, iterator first, 
					 iterator last, list<T,Allocator>& x)
    {
      if (this == &x)
      {
        (*(__link_type((*last.node).prev))).next = position.node;
        (*(__link_type((*first.node).prev))).next = last.node;
        (*(__link_type((*position.node).prev))).next = first.node;  
        __link_type tmp = __link_type((*position.node).prev);
        (*position.node).prev = (*last.node).prev;
        (*last.node).prev = (*first.node).prev; 
        (*first.node).prev = tmp;
      }
      else
      {
        insert(position,first,last);
        x.erase(first,last);
      }
    }

	void __advance(iterator &i, difference_type n, iterator end)
	{
		for (int j = 0; j < (int) n; j++) {
			if (i != end) ++i;
		}
	}

	// uses transfer_node to merge in list by transfering nodes to list
	void __adjacent_merge (iterator first1, iterator last1,
						   iterator last2)
	{
		iterator first2 = last1;
		int n = 0;
		distance(first1, last1, n);
		int count = 0;

		while (count <= n && first2 != last2)
		{
			if (*first2 < *first1)
			{
				iterator next = first2;
				__transfer(first1, first2, ++next, *this);
				first2 = next;
			}
			else {
				first1++;
				count++;
			}
		}
	}

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
	// uses transfer_node to merge in list by transfering nodes to list
	template<class Compare>
	void __adjacent_merge (iterator first1, iterator last1,
						   iterator last2, Compare comp)
	{
		iterator first2 = last1;
		int n = 0;
		distance(first1, last1, n);
		int count = 0;

		while (count <= n && first2 != last2)
		{
			if (comp(*first2,*first1))
			{
				iterator next = first2;
				__transfer(first1, first2, ++next, *this);
				first2 = next;
			}
			else {
				first1++;
				count++;
			}
		}
	}
#endif

// used by the sort() member function
    void __set_allocator(allocator_type a)
    {  
      __buffer_list = a; 
    }
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
    // list operations.
    //
    void splice (iterator position, list<T,Allocator>& x)
    {
      if (!x.empty())
        __transfer(position, x.begin(), x.end(), x);
    }
    void splice (iterator position, list<T,Allocator>& x, iterator i)
    { 
      iterator k = i;
      if (k != position && ++k != position)
      {
        iterator j = i;
        __transfer(position, i, ++j, x);
      }
    }
    void splice (iterator position, list<T,Allocator>& x, iterator first, iterator last)
    {
      if (first != last)
      {
        difference_type n;
        __initialize(n, difference_type(0));
        distance(first, last, n);
        __transfer(position, first, last, x);
      }
    }
    void remove  (const T& value);
    void unique  ();
	void merge   (list<T,Allocator>& x);
    void reverse ();
    void sort    ();

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class Predicate>       void remove_if (Predicate pred);
    template<class BinaryPredicate> void unique    (BinaryPredicate pred);
    template<class Compare>         void merge     (list<T,Allocator>& x, Compare comp);
    template<class Compare>         void sort      (Compare comp);
#endif // _RWSTD_NO_MEMBER_TEMPLATES

#ifndef _RWSTD_STRICT_ANSI
    // Non-standard function for setting buffer allocation size
    size_type allocation_size() { return __buffer_size; }
    size_type allocation_size(size_type new_size) 
    { 
      size_type tmp = __buffer_size; 
      __buffer_size = max((size_type)1,new_size);
      return tmp;
    }
#endif // _RWSTD_STRICT_ANSI
  };

  template <class T, class Allocator>
  inline bool operator== (const list<T,Allocator>& x, const list<T,Allocator>& y)
  {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
  }

  template <class T, class Allocator>
  inline bool operator< (const list<T,Allocator>& x, const list<T,Allocator>& y)
  {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class T, class Allocator>
  inline bool operator!= (const list<T,Allocator>& x, const list<T,Allocator>& y)
  {
    return !(x == y);
  }

  template <class T, class Allocator>
  inline bool operator> (const list<T,Allocator>& x, const list<T,Allocator>& y)
  {
    return y < x;
  }

  template <class T, class Allocator>
  inline bool operator>= (const list<T,Allocator>& x, const list<T,Allocator>& y)
  {
    return !(x < y);
  }

  template <class T, class Allocator>
  inline bool operator<= (const list<T,Allocator>& x, const list<T,Allocator>& y)
  {
    return !(y <  x);
  }

  template <class T, class Allocator>
  inline void swap(list<T,Allocator>& a, list<T,Allocator>& b)
  {
    a.swap(b);
  }
#endif // !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <list.cc>
#endif

#undef list
#endif /*__STD_LIST__*/

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __LIST_H */
