#ifndef __VECTOR_CC
#define __VECTOR_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * vector.cc - Non-inline definitions for the Standard Library vector class
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
// This requires that T have a default constructor.
//

  template <class T, class Allocator>
  void vector<T,Allocator>::resize (size_type new_size)
  {
    T value;
    if (new_size > size())
      insert(end(), new_size - size(), value);
    else if (new_size < size())
      erase(begin() + new_size, end());
  }

  template <class T, class Allocator>
  void vector<T,Allocator>::resize (size_type new_size, T value)
  {
    if (new_size > size())
      insert(end(), new_size - size(), value);
    else if (new_size < size())
      erase(begin() + new_size, end());
  }

  template <class T, class Allocator>
  vector<T,Allocator>& vector<T,Allocator>::operator= (const vector<T,Allocator>& x)
  {
    if (&x == this) return *this;
    if (x.size() > capacity())
    {
      __value_alloc_type va(__end_of_storage);
      iterator tmp = va.allocate(x.end() - x.begin(),0);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        __end_of_storage = uninitialized_copy(x.begin(), x.end(), tmp);
      } catch(...) {
        va.deallocate(tmp,x.end()-x.begin());
        throw;
      }
#else
      __end_of_storage = uninitialized_copy(x.begin(), x.end(), tmp);
#endif // _RWSTD_NO_EXCEPTIONS
      __destroy(__start, __finish);
      va.deallocate(__start,__end_of_storage.data()-__start);
      __start = tmp;
    }
    else if (size() >= x.size())
    {
      iterator i = copy(x.begin(), x.end(), begin());
      __destroy(i, __finish);
    }
    else
    {
      copy(x.begin(), x.begin() + size(), begin());
      uninitialized_copy(x.begin() + size(), x.end(), begin() + size());
    }
    __finish = begin() + x.size();
    return *this;
  }

  template <class T, class Allocator>
  void vector<T,Allocator>::__insert_aux (
      iterator position, const T& x)
  {
    if (__finish != __end_of_storage.data())
    {
      __value_alloc_type(__end_of_storage).construct(__finish, *(__finish - 1));
      copy_backward(position, __finish - 1, __finish);
      *position = x;
      ++__finish;
    }
    else
    {
      //
      // We always allocate enough space for a number of additional
      // elements in the vector, unless the size of each element is
      // very large. See definition of __rw_allocation_size in
      // memory.
      //
      __value_alloc_type va(__end_of_storage);
      size_type len = __RWSTD::__rw_allocation_size((value_type*)0,size(),__buffer_size);
      iterator tmp = va.allocate(len,__start);
      uninitialized_copy(begin(), position, tmp);
      va.construct((tmp + (position - begin())), x);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        uninitialized_copy(position, end(), tmp + (position - begin()) + 1); 
      } catch(...) {
        va.deallocate(tmp,len);
        throw;
      }
#else
      uninitialized_copy(position, end(), tmp + (position - begin()) + 1); 
#endif // _RWSTD_NO_EXCEPTIONS
      __destroy(begin(), end());
      va.deallocate(begin(),__end_of_storage.data() - begin());
      __end_of_storage = tmp + len;
      __finish = tmp + size() + 1;
      __start = tmp;
    }
  }

  template <class T, class Allocator>
  void vector<T,Allocator>::__insert_aux (
      iterator position, size_type n, const T& x)
  {
    if (n == 0) return;
    if ((size_type)(__end_of_storage.data() - __finish) >= n)
    {
      iterator old_end = end();
      if ((size_type)(end() - position) > n)
      {
        uninitialized_copy(old_end - n, old_end, old_end);
        __finish += n;
        copy_backward(position, old_end - n, old_end);
        fill(position, position + n, x);
      }
      else
      {
        size_type first_part = n - (old_end - position);
        uninitialized_fill_n(old_end, first_part, x);
        __finish += first_part;
        uninitialized_copy(position, old_end, position + n);
        __finish += n - first_part;
        fill(position, old_end, x);

      }

    }
    else
    {
      __value_alloc_type va(__end_of_storage);
      size_type len = size() + max(size(), n);
      iterator tmp = va.allocate(len,__start);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        uninitialized_copy(begin(), position, tmp);
        uninitialized_fill_n(tmp + (position - begin()), n, x);
        uninitialized_copy(position, end(), tmp + (position - begin() + n));
      } catch(...) {
        va.deallocate(tmp,len);
        throw;
      }
#else
      uninitialized_copy(begin(), position, tmp);
      uninitialized_fill_n(tmp + (position - begin()), n, x);
      uninitialized_copy(position, end(), tmp + (position - begin() + n));
#endif // _RWSTD_NO_EXCEPTIONS
      __destroy(begin(), end());
      va.deallocate(begin(),__end_of_storage.data() - begin());
      __end_of_storage = tmp + len;
      __finish = tmp + size() + n;
      __start = tmp;
    }
  }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template<class T, class Allocator>
  template<class InputIterator>
  void vector<T,Allocator>::__insert_aux2 (iterator position, 
                                    InputIterator first, 
                                    InputIterator last)
#else
  template<class T, class Allocator>
  void vector<T,Allocator>::__insert_aux2 (iterator position,
                                    const_iterator first,
                                    const_iterator last)
#endif
  {
    if (first == last) return;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if ((size_type)(__end_of_storage.data() - __finish) >= n)
    {
      iterator old_end = end();
      if ((size_type)(old_end - position) > n)
      {
        uninitialized_copy(old_end - n, old_end, old_end);
        __finish += n;
        copy_backward(position, old_end - n, old_end);
        copy(first, last, position);
      }
      else
      {
        size_type first_part = (old_end - position);
#ifndef _RWSTD_NO_MEMBER_TEMPLATES
        InputIterator iter(first);
#else
        const_iterator iter(first);
#endif
        advance(iter, first_part);
        uninitialized_copy(iter, last, old_end);
//        uninitialized_copy(first + first_part, last, old_end);
        __finish += n - first_part;
        uninitialized_copy(position, old_end, position + n);
        __finish += first_part;
        copy(first, iter, position);
//        copy(first, first + (old_end - position), position);
      }

    }
    else
    {
      __value_alloc_type va(__end_of_storage);
      size_type len = size() + max(size(), n);
      iterator tmp = va.allocate(len,__start);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        uninitialized_copy(begin(), position, tmp);
        uninitialized_copy(first, last, tmp + (position - begin()));
        uninitialized_copy(position, end(), tmp + (position - begin() + n));
      } catch(...) {
        va.deallocate(tmp,len);
        throw;
      }
#else
      uninitialized_copy(begin(), position, tmp);
      uninitialized_copy(first, last, tmp + (position - begin()));
      uninitialized_copy(position, end(), tmp + (position - begin() + n));
#endif // _RWSTD_NO_EXCEPTIONS
      __destroy(begin(), end());
      va.deallocate(begin(),__end_of_storage.data() - begin());
      __end_of_storage = tmp + len;
      __finish = tmp + size() + n;
      __start = tmp;
    }
  }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
// The body of this function is duplicated in src/vecbool.cpp and
// further down in this file as well.
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
  template <class Allocator>
  template<class InputIterator>
  void vector<bool, Allocator >::insert 
#else
  template<class InputIterator>
  void vector<bool, allocator<bool> >::insert 
#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC
  (iterator position, 
   InputIterator first,
   InputIterator last)

  {
    if (first == last) return;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);
    if (capacity() - size() >= n)
    {
      copy_backward(position, end(), __finish + n);
      copy(first, last, position);
      __finish += n;
    }
    else
    {
      size_type len = size() + max(size(), n);
      unsigned int* q = __bit_alloc(len);
      iterator i = copy(begin(), position, iterator(q, 0));
      i = copy(first, last, i);
      __finish = copy(position, end(), i);
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data() - __start.p);
      __end_of_storage = q + (len + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC
// Duplicates of the followign functions exist in src/stl/vecbool.cpp.
// Which set is used depends on the availability of partial specialization.

  template <class Allocator>
  void vector<bool,Allocator >::flip ()
  {
    for (iterator i = begin(); !(i == end()); i++)
      *i = !(*i);
  }

  template <class Allocator>
  void vector<bool,Allocator >::swap (reference x, reference y)
  {
    bool tmp = x; x = y; y = tmp;
  }

  template <class Allocator>
  void vector<bool,Allocator >::__insert_aux (iterator position, bool x)
  {
    if (__finish.p != __end_of_storage.data())
    {
      __copy_backward(position, __finish - 1, __finish);
      *position = x;
      ++__finish;
    }
    else
    {
      size_type len = size() ? 2 * size() : _RWSTD_WORD_BIT;
      unsigned int* q = __bit_alloc(len);
      iterator i = __copy(begin(), position, iterator(q, 0));
      *i++ = x;
      __finish = __copy(position, end(), i);
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data() - __start.p);
      __end_of_storage = q + (len + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }

  template <class Allocator>
  void vector<bool,Allocator >::insert (iterator position, size_type n, const bool& x)
  {
    if (n == 0) return;
    if (capacity() - size() >= n)
    {
      __copy_backward(position, end(), __finish + n);
      __fill(position, position + n, x);
      __finish += n;
    }
    else
    {
      size_type len = size() + max(size(), n);
      unsigned int* q = __bit_alloc(len);
      iterator i = __copy(begin(), position, iterator(q, 0));
      __fill_n(i, n, x);
      __finish = __copy(position, end(), i + n);
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data() - __start.p);
      __end_of_storage = q + (len + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }
#ifdef _RWSTD_NO_MEMBER_TEMPLATES
  template <class Allocator>
  void vector<bool,Allocator >::insert (iterator position, const_iterator first,
                                        const_iterator last)
  {
    if (first == last) return;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);
    if (capacity() - size() >= n)
    {
      __copy_backward(position, end(), __finish + n);
      __copy(first, last, position);
      __finish += n;
    }
    else
    {
      size_type len = size() + max(size(), n);
      unsigned int* q = __bit_alloc(len);
      iterator i = __copy(begin(), position, iterator(q, 0));
      i = __copy(first, last, i);
      __finish = __copy(position, end(), i);
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data() - __start.p);
      __end_of_storage = q + (len + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

  template <class Allocator>
  void vector<bool,Allocator >::resize (size_type new_size, bool c)
  {
    if (new_size > size())
      insert(end(), new_size - size(), c);
    else if (new_size < size())
      erase(begin() + new_size, end());
  }

#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __VECTOR_CC */
