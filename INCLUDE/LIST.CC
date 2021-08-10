#ifndef __LIST_CC
#define __LIST_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig

/***************************************************************************
 *
 * list.cc - Non-nline list definitions for the Standard Library
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
#include <limits>

#define _RWSTD_LIST_SORT_COUNTERS 64

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  template <class T, class Allocator>
  void list<T,Allocator>::__deallocate_buffers ()
  {
    while (__buffer_list.data())
    {
      __buffer_pointer tmp = __buffer_list;
      __buffer_list = (__buffer_pointer)(__buffer_list.data()->next_buffer);
      __list_node_alloc_type(__buffer_list).deallocate(tmp->buffer,tmp->size);
      __buffer_alloc_type(__buffer_list).deallocate(tmp,1);
    }
    __free_list = 0;
    __next_avail = 0;
    __last = 0;
  }

//
// This requires that T have a default constructor.
//

  template <class T, class Allocator>
  void list<T,Allocator>::resize (size_type new_size)
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

  template <class T, class Allocator>
  void list<T,Allocator>::resize (size_type new_size, T value)
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

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template <class T, class Allocator>   
  template<class InputIterator>
  void list<T,Allocator>::__insert_aux2 (iterator position, InputIterator first,
                                  InputIterator locallast)
  {
    while (first != locallast) insert(position, *first++);
  }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

#ifdef _RWSTD_NO_MEMBER_TEMPLATES
  template <class T, class Allocator>   
  void list<T, Allocator>::insert (iterator position, 
                                   const_iterator first,
                                   const_iterator locallast)
  {
    while (first != locallast) insert(position, *first++);
  }
  template <class T, class Allocator>
  void list<T, Allocator>::insert (iterator position, 
                                   const T* first, const T* locallast)
  {
    while (first != locallast) insert(position, *first++);
  }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

  template <class T, class Allocator>
  void list<T, Allocator>::__insert_aux (iterator position, 
                                         size_type n, const T& x)
  {
    while (n--) insert(position, x);
  }

  template <class T, class Allocator>
  _TYPENAME list<T, Allocator>::iterator 
  list<T, Allocator>::erase (iterator first, iterator locallast)
  {
    iterator tmp = end();
    while (first != locallast) 
    {
      tmp = erase(first++);
    }
    return tmp;
  }

  template <class T, class Allocator>
  list<T, Allocator>& list<T, Allocator>::operator= (const list<T, Allocator>& x)
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

  template <class T, class Allocator>
  void list<T, Allocator>::remove (const T& value)
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

  template <class T, class Allocator>
  void list<T, Allocator>::unique ()
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

  template <class T, class Allocator>
		  void list<T, Allocator>::merge (list<T, Allocator>& x)
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
        __transfer(first1, first2, ++next, x);
        first2 = next;
      }
      else
        first1++;
    }
    if (first2 != last2) 
      __transfer(last1, first2, last2, x);
  }

  template <class T, class Allocator>
  void list<T, Allocator>::reverse ()
  {
    if (size() < 2) return;
    for (iterator first = ++begin(); first != end();)
    {
      iterator old = first++;
      __transfer(begin(), old, first, *this);
    }
  }

  // sorts list by moving nodes within list.  This preserves iterators pointing to
  // elements of the list.
  template <class T, class Allocator>
		  void list<T, Allocator>::sort ()
  {
	  for (unsigned int n = 1; n < size(); n *= 2) {
		  iterator i1 = begin(), i2 = begin(), i3 = begin();
		  __advance(i2, (difference_type) n, end());
		  __advance(i3, (difference_type) (2*n), end());
		  for (unsigned int m = 0; m < (size()+(2*n))/(n*2); m++) {
			  if (i1 != end() && i2 != end()) {
				  __adjacent_merge(i1, i2, i3);
				  i1 = i3;
				  i2 = i3;
				  __advance(i2, (difference_type) n, end());
				  __advance(i3, (difference_type) 2*n, end());
			  }
		  }
	  }
  }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template<class T, class Allocator>
  template<class Predicate> void list<T, Allocator>::remove_if (Predicate pred)
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

  template<class T, class Allocator>
  template<class BinaryPredicate> void list<T, Allocator>::unique (BinaryPredicate pred)
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

  template<class T, class Allocator>
  template<class Compare> void list<T, Allocator>::merge (list<T, Allocator>& x, Compare comp)
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
        __transfer(first1, first2, ++next, x);
        first2 = next;
      }
      else
        first1++;
    }
    if (first2 != last2) 
      __transfer(last1, first2, last2, x);
  }

  template <class T, class Allocator>
	template<class Compare> void list<T, Allocator>::sort (Compare comp)
  {
	  for (int n = 1; n < size(); n *= 2) {
		  iterator i1 = begin(), i2 = begin(), i3 = begin();
		  __advance(i2, (difference_type) n, end());
		  __advance(i3, (difference_type) (2*n), end());
		  for (int m = 0; m < (size()+(2*n))/(n*2); m++) {
			  if (i1 != end() && i2 != end()) {
				  __adjacent_merge(i1, i2, i3, comp);
				  i1 = i3;
				  i2 = i3;
				  __advance(i2, (difference_type) n, end());
				  __advance(i3, (difference_type) 2*n, end());
			  }
		  }
	  }
  }

/*
  template<class T, class Allocator>
  template<class Compare> void list<T, Allocator>::sort (Compare comp)
  {
    if (size() < 2) return;

    list<T, Allocator> carry(get_allocator());
    list<T, Allocator> counter[ _RWSTD_LIST_SORT_COUNTERS];
    for (int i = 0; i < _RWSTD_LIST_SORT_COUNTERS; i++)
      counter[i].__set_allocator(get_allocator());
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
    while (fill--) merge(counter[fill], comp);
  }
  */
#endif /*_RWSTD_NO_MEMBER_TEMPLATES*/

#undef _RWSTD_LIST_SORT_COUNTERS

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __LIST_CC */
