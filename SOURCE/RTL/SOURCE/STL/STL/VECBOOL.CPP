#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * vecbool.cpp - Source for the Standard Library vector<bool,Allocator> specialization
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

#include <vector>

#ifndef _RWSTD_NO_BOOL
#ifdef _RWSTD_NO_CLASS_PARTIAL_SPEC
// Duplicates of the following functions exist in include/vector.cc.
// Which set is used depends on the availability of partial specialization.

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  void vector<bool,allocator<bool> >::flip ()
  {
#ifndef _RWSTD_NO_NAMESPACE
    using namespace rel_ops;
#endif
    for (iterator i = begin(); i != end(); i++)
      *i = !(*i);
  }

  void vector<bool,allocator<bool> >::swap (vector<bool,allocator<bool> >::reference x, 
					    vector<bool,allocator<bool> >::reference y)
  {
    bool tmp = x; x = y; y = tmp;
  }

  void vector<bool,allocator<bool> >::__insert_aux (iterator position, bool x)
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
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data()-__start.p);
      __end_of_storage = q + (len + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }

  void vector<bool,allocator<bool> >::insert (iterator position, size_type n, const bool& x)
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
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data()-__start.p);
      __end_of_storage = q + (n + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }
#ifdef _RWSTD_NO_MEMBER_TEMPLATES
// The body of this function is duplicated in include/vector.cc
  void vector<bool,allocator<bool> >::insert (iterator position, const_iterator first,
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
      __value_alloc_type(__end_of_storage).deallocate(__start.p,__end_of_storage.data()-__start.p);
      __end_of_storage = q + (len + _RWSTD_WORD_BIT - 1)/_RWSTD_WORD_BIT;
      __start = iterator(q, 0);
    }
  }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

  void vector<bool,allocator<bool> >::resize (size_type new_size, bool c)
  {
    if (new_size > size())
      insert(end(), new_size - size(), c);
    else if (new_size < size())
      erase(begin() + new_size, end());
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC
#endif // _RWSTD_NO_BOOL
