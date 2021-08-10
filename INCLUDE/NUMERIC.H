#ifndef __NUMERIC_H
#define __NUMERIC_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_NUMERIC
#define __STD_NUMERIC

/***************************************************************************
 *
 * numeric - Declarations for the Standard Library algorithms
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

#include <functional>
#include <iterator>

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  template <class InputIterator, class T>
  T accumulate (InputIterator first, InputIterator last, T init)
  {
    while (first != last) init = init + *first++;
    return init;
  }

  template <class InputIterator, class T, class BinaryOperation>
  T accumulate (InputIterator first, InputIterator last, T init,
                BinaryOperation binary_op)
  {
    while (first != last) init = binary_op(init, *first++);
    return init;
  }

  template <class InputIterator1, class InputIterator2, class T>
  T inner_product (InputIterator1 first1, InputIterator1 last1,
                   InputIterator2 first2, T init)
  {
    while (first1 != last1) init = init + (*first1++ * *first2++);
    return init;
  }

  template <class InputIterator1, class InputIterator2, class T,
  class BinaryOperation1, class BinaryOperation2>
  T inner_product (InputIterator1 first1, InputIterator1 last1,
                   InputIterator2 first2, T init, BinaryOperation1 binary_op1,
                   BinaryOperation2 binary_op2)
  {
    while (first1 != last1) 
      init = binary_op1(init, binary_op2(*first1++, *first2++));
    return init;
  }

  template <class InputIterator, class OutputIterator, class T>
  OutputIterator __partial_sum (InputIterator first, InputIterator last,
                                OutputIterator result, T*)
  {
    T value = *first;
    while (++first != last)
    {
      value = value + *first;
      *++result = value;
    }
    return ++result;
  }

  template <class InputIterator, class OutputIterator>
  inline OutputIterator partial_sum (InputIterator first, InputIterator last,
                                     OutputIterator result)
  {
    return first == last ? result :
    (*result = *first,
     __partial_sum(first, last, result, _RWSTD_VALUE_TYPE(first)));
  }

  template <class InputIterator, class OutputIterator, class T,
  class BinaryOperation>
  OutputIterator __partial_sum (InputIterator first, InputIterator last,
                                OutputIterator result, T*,
                                BinaryOperation binary_op)
  {
    T value = *first;
    while (++first != last)
    {
      value = binary_op(value, *first);
      *++result = value;
    }
    return ++result;
  }

  template <class InputIterator, class OutputIterator, class BinaryOperation>
  inline OutputIterator partial_sum (InputIterator first, InputIterator last,
                                     OutputIterator result,
                                     BinaryOperation binary_op)
  {
    return first == last ? result :
    (*result = *first,
     __partial_sum(first, last, result, _RWSTD_VALUE_TYPE(first),binary_op));
  }

  template <class InputIterator, class OutputIterator, class T>
  OutputIterator __adjacent_difference (InputIterator first, InputIterator last, 
                                        OutputIterator result, T*)
  {
    T value = *first;
    while (++first != last)
    {
      T tmp = *first;
      *++result = tmp - value;
      value = tmp;
    }
    return ++result;
  }

  template <class InputIterator, class OutputIterator>
  inline OutputIterator adjacent_difference (InputIterator first,
                                             InputIterator last, 
                                             OutputIterator result)
  {
    return first == last ? result :
    (*result = *first,
     __adjacent_difference(first, last, result, _RWSTD_VALUE_TYPE(first)));
  }

  template <class InputIterator, class OutputIterator, class T, 
  class BinaryOperation>
  OutputIterator __adjacent_difference (InputIterator first, InputIterator last, 
                                        OutputIterator result, T*,
                                        BinaryOperation binary_op)
  {
    T value = *first;
    while (++first != last)
    {
      T tmp = *first;
      *++result = binary_op(tmp, value);
      value = tmp;
    }
    return ++result;
  }

  template <class InputIterator, class OutputIterator, class BinaryOperation>
  inline OutputIterator adjacent_difference (InputIterator first,
                                             InputIterator last,
                                             OutputIterator result,
                                             BinaryOperation binary_op)
  {
    return first == last ? result :
    (*result = *first,
     __adjacent_difference(first, last, result, _RWSTD_VALUE_TYPE(first),
                           binary_op));
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __NUMERIC_H */
