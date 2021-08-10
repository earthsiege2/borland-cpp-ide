#ifndef __DEQUE_CC
#define __DEQUE_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * deque.cc - Non-iniline definitions for the Standard Library deque class
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
  template <class T, class Allocator>
  deque<T,Allocator>::~deque()
  {
    while (!empty()) pop_front();
  }

  template <class T, class Allocator>
  _TYPENAME deque<T,Allocator>::size_type deque<T,Allocator>::__buffer_size ()
  {
    static size_type b_size = 
    max((size_type)1,__RWSTD::__rw_allocation_size((value_type*)0,(size_type)0,(size_type)0));
    return b_size; 
  }

  template <class T, class Allocator>
  void deque<T,Allocator>::__allocate_at_begin ()
  {
    pointer p = __value_alloc_type(__map_size).allocate(__buffer_size(),__start.current);
    if (!empty())
    {
      if (__start.node == __map)
      {
        __map_alloc_type ma(__map_size);
        difference_type i = __finish.node - __start.node;
        size_type new_map_size = (i + 1) * 2;
        __map_pointer tmp;
#ifndef _RWSTD_NO_EXCEPTIONS
        try {
          tmp = ma.allocate(new_map_size,__map);
        } catch(...) {
          __value_alloc_type(__map_size).deallocate(p,__buffer_size());
          throw;
        }      
#else
        tmp = ma.allocate(new_map_size,__map);
#endif //  _RWSTD_NO_EXCEPTIONS
        copy(__start.node, __finish.node + 1, tmp + new_map_size / 4 + 1);
        ma.deallocate(__map,__map_size.data());
        __map = tmp;
        __map[new_map_size / 4] = p;
        __start = iterator(p + __buffer_size(), __map + new_map_size / 4);
        __finish = iterator(__finish.current, __map + new_map_size / 4 + i + 1);
        __map_size = new_map_size;
      }
      else
      {
        *--__start.node = p;
        __start = iterator(p + __buffer_size(), __start.node);
      }
    }
    else
    {
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        __map = __map_alloc_type(__map_size).allocate(__buffer_size(),__map);
      } catch(...) {
        __value_alloc_type(__map_size).deallocate(p,__buffer_size());
        throw;
      }      
#else
      __map = __map_alloc_type(__map_size).allocate(__buffer_size(),__map);
#endif // _RWSTD_NO_EXCEPTIONS
      __map_size = __buffer_size();
      __map[__map_size.data() / 2] = p;
      __start = iterator(p + __buffer_size() / 2 + 1, __map + __map_size.data() / 2);
      __finish = __start;
    }
  }
  template <class T, class Allocator>
  void deque<T,Allocator>::__allocate_at_end ()
  {
    pointer p = __value_alloc_type(__map_size).allocate(__buffer_size(),__start.current);

    if (!empty())
    {
      if (__finish.node == __map + __map_size.data() - 1)
      {
        __map_alloc_type ma(__map_size);
        difference_type i = __finish.node - __start.node;
        size_type new_map_size = (i + 1) * 2;
        __map_pointer tmp;
#ifndef _RWSTD_NO_EXCEPTIONS
        try {
          tmp = ma.allocate(new_map_size,__map);
        } catch(...) {
          __value_alloc_type(__map_size).deallocate(p,__buffer_size());
          throw;
        }      
#else
        tmp = ma.allocate(new_map_size,__map);
#endif // _RWSTD_NO_EXCEPTIONS
        copy(__start.node, __finish.node + 1, tmp + new_map_size / 4);
        ma.deallocate(__map,__map_size.data());
        __map = tmp;
        __map[new_map_size / 4 + i + 1] = p;
        __start = iterator(__start.current, __map + new_map_size / 4);
        __finish = iterator(p, __map + new_map_size / 4 + i + 1);
        __map_size = new_map_size;
      }
      else
      {
        *++__finish.node = p;
        __finish = iterator(p, __finish.node);
      }
    }
    else
    {
      __map_size = __buffer_size();
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        __map = __map_alloc_type(__map_size).allocate(__map_size.data(),__map);
      } catch(...) {
        __value_alloc_type(__map_size).deallocate(p,__buffer_size());
        throw;
      }      
#else
      __map = __map_alloc_type(__map_size).allocate(__map_size.data(),__map);
#endif // _RWSTD_NO_EXCEPTIONS
      __map[__map_size.data() / 2] = p;
      __start = iterator(p + __buffer_size() / 2, __map + __map_size.data() / 2);
      __finish = __start;
    }
  }

  template <class T, class Allocator>
  void deque<T,Allocator>::__deallocate_at_begin ()
  {
    __value_alloc_type(__map_size).deallocate(*__start.node++,__buffer_size());
    if (empty())
    {
      __start = iterator();
      __finish = __start;
      __map_alloc_type(__map_size).deallocate(__map,__map_size.data());
    }
    else
      __start = iterator(*__start.node, __start.node);
  }

  template <class T, class Allocator>
  void deque<T,Allocator>::__deallocate_at_end ()
  {
    __value_alloc_type(__map_size).deallocate(*__finish.node--,__buffer_size());
    if (empty())
    {
      __start = iterator();
      __finish = __start;
      __map_alloc_type(__map_size).deallocate(__map,__map_size.data());
    }
    else
      __finish = iterator(*__finish.node + __buffer_size(), __finish.node);
  }

  template <class T, class Allocator>
  void deque<T,Allocator>::resize (size_type new_size)
  {
    T value;
    if (new_size > size())
      insert(end(), new_size - size(), value);
    else if (new_size < size())
      erase(begin() + new_size,end());
  }

  template <class T, class Allocator>
  void deque<T,Allocator>::resize (size_type new_size, T value)
  {
    if (new_size > size())
      insert(end(), new_size - size(), value);
    else if (new_size < size())
      erase(begin() + new_size,end());
  }

  template <class T, class Allocator>
  _TYPENAME deque<T,Allocator>::iterator 
  deque<T,Allocator>::insert (iterator position, const T& x)
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
      if ((size_type)index < __length/2)
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

  template <class T, class Allocator>
  void deque<T,Allocator>::__insert_aux(iterator position,      
                                      size_type n, const T& x)
  {
    difference_type index     = position - begin();
    difference_type remainder = __length   - index;

    if (remainder > index)
    {
      if (n > (size_type)index)
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
      if (n > (size_type)remainder)
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
        while ((size_type)i < n) push_back(*(begin() + orig_len - n + i++));
        copy_backward(begin() + index, begin() + orig_len - n,
                      begin() + orig_len);
        fill(begin() + index, begin() + index + n, x);
      }
    }
  }
#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template <class T, class Allocator>
  template <class InputIterator>
  void deque<T,Allocator>::__insert_aux2 (iterator position,
                                   InputIterator first, InputIterator last)
  {
    difference_type index     = position - begin();
    difference_type remainder = __length   - index;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if (remainder > (size_type)index)
    {
      if (n > (size_type)index)
      {
        InputIterator m = last - index;
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
      if (n > (size_type)remainder)
      {
        InputIterator m = first + remainder;
        while (m != last) push_back(*m++);
        difference_type i = 0;
        while (i < remainder) push_back(*(begin() + index + i++));
        copy(first, first + remainder, begin() + index);
      }
      else
      {
        difference_type i = 0;
        while ((size_type)i < n) push_back(*(begin() + orig_len - n + i++));
        copy_backward(begin() + index, begin() + orig_len - n,
                      begin() + orig_len);
        copy(first, last, begin() + index);
      }
    }
  }

#else

  template<class T, class Allocator>
  void deque<T,Allocator>::insert (iterator position, 
                                   const_iterator first, 
                                   const_iterator last)
  {
    difference_type index     = position - begin();
    difference_type remainder = __length   - index;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if (remainder > index)
    {
      if (n > (size_type)index)
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
      if (n > (size_type)remainder)
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
        while ((size_type)i < n) push_back(*(begin() + orig_len - n + i++));
        copy_backward(begin() + index, begin() + orig_len - n,
                      begin() + orig_len);
        copy(first, last, begin() + index);
      }
    }
  }

  template<class T, class Allocator>
  void deque<T,Allocator>::insert (iterator position, 
                                   const T* first, const T* last)
  {
    difference_type index     = position - begin();
    difference_type remainder = __length   - index;
    size_type n;
    __initialize(n, size_type(0));
    distance(first, last, n);

    if (remainder > index)
    {
      if (n > (size_type)index)
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
      if (n > (size_type)remainder)
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
        while ((size_type)i < n) push_back(*(begin() + orig_len - n + i++));
        copy_backward(begin() + index, begin() + orig_len - n,
                      begin() + orig_len);
        copy(first, last, begin() + index);
      }
    }
  }

#endif /*_RWSTD_NO_MEMBER_TEMPLATES*/

  template <class T, class Allocator>
  _TYPENAME deque<T,Allocator>::iterator 
  deque<T,Allocator>::erase (iterator position)
  {
    if (end() - position > position - begin())
    {
      copy_backward(begin(), position, position + 1); 
      pop_front();
      return position + 1;
    }
    else
    {
      copy(position + 1, end(), position); 
      pop_back();
      return position;
    }
  }
    
  template <class T, class Allocator>
  _TYPENAME deque<T,Allocator>::iterator 
  deque<T,Allocator>::erase (iterator first, iterator last)
  {
    difference_type n = last - first;
    if (end() - last > first - begin())
    {
      copy_backward(begin(), first, last);
      while(n-- > 0) pop_front();
      return last;
    }
    else
    {
      copy(last, end(), first);
      while(n-- > 0) pop_back();
      return first;
    }
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __DEQUE_CC */
