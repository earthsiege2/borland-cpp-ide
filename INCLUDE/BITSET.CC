#ifndef __BITSET_CC
#define __BITSET_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * bitset - class bitset declaration
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

#ifdef _HPACC_
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
#endif //_HPACC_

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _NELEMENTS
#  ifndef _RWSTD_BC5_ENUM_BUG
#define _NELEMENTS NumOfElems
#  else
#define _NELEMENTS NumOfElems()
#  endif /*_RWSTD_BC5_ENUM_BUG*/
#endif /* _NELEMENTS */

#ifndef _RWSTD_MSC22_STATIC_INIT_BUG
  template <size_t N>
  const size_t bitset<N>::bitset_size 
#ifdef _RWSTD_NO_STI_TEMPLATE
  = N
#endif
  ;
#endif /* _RWSTD_MSC22_STATIC_INIT_BUG */
  template <size_t N>
#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template <class charT, class traits, class Allocator>
  bitset<N>::bitset (const basic_string<charT,traits,Allocator> &str,
                     _TYPENAME basic_string<charT,traits,Allocator>::size_type pos,
                     _TYPENAME basic_string<charT,traits,Allocator>::size_type n)
#else
  bitset<N>::bitset (const string& str,
                     size_t pos,
                     size_t n) 
#endif // _RWSTD_NO_MEMBER_TEMPLATES
  _RWSTD_THROW_SPEC((out_of_range, invalid_argument))
#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
  : bitset_size(N)
#endif
  {
    size_t slen = str.size();

    _RWSTD_THROW(pos > slen,out_of_range,
                 __RWSTD::except_msg_string(__RWSTD::__rw_bitset_InvalidPosition,
                                            "bitset::bitset(const string&,size_t,size_t)",pos,slen).msgstr());

    size_t rlen = n < (slen - pos) ? n : slen - pos;
    size_t M = N >= rlen ? rlen : N;
#ifndef _RWSTD_BC5_ENUM_BUG
    memset(bits, 0, sizeof(bits));
#else
    bits = new VectorType[_NELEMENTS];
    memset(bits, 0, _NELEMENTS*sizeof(VectorType));
#endif /*_RWSTD_BC5_ENUM_BUG*/
    for (size_t i = pos; i < M + pos; i++)
    {
      char c = str[slen - i - 1];

      _RWSTD_THROW(!(c == '0' || c == '1'), invalid_argument,
                   __RWSTD::except_msg_string(__RWSTD:: __rw_bitset_InvalidCtorArgument,
                                              "bitset::bitset(const string&,size_t,size_t)").msgstr());

      if (c == '1') set(i - pos);
    }
  }

//
// Constructs an object of type string and initializes it
// to a string of length N characters. Each character is
// determined by the value of its corresponding bit position
// in *this. Character position N-1 corresponds to bit
// position zero. Subsequent decreasing character positions
// correspond to increasing bit positions. Bit value zero becomes
// the character 0, bit value one becomes the character 1.
//

  template <size_t N>
#if !defined ( _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE) && !defined (_HPACC_)  && !defined(_RWSTD_NO_EXPLICIT_ARGS) 
  template <class charT, class traits, class Allocator>
  basic_string<charT,traits,Allocator>
#else
  string 
#endif
  bitset<N>::to_string () const 
  {
#if !defined ( _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE) && !defined (_HPACC_)  && !defined(_RWSTD_NO_EXPLICIT_ARGS) 
    basic_string<charT,traits,Allocator>   s;
#else
    string s;
#endif
    for (long i = N - 1; i >= 0; --i)
      s.append(1, test(i) ? '1' : '0');
    return s;
  }

//
// If the integral value x corresponding to the bitset in *this
// cannot be represented as type unsigned long, throws overflow_error.
//

  template <size_t N>
  unsigned long
  bitset<N>::to_ulong () const _RWSTD_THROW_SPEC((overflow_error))
  {
    const size_t size_long = sizeof(unsigned long);

    for (size_t i = _NELEMENTS-1; size_long/sizeof(VectorType) <= i; --i)

      _RWSTD_THROW(bits[i], overflow_error,
                   __RWSTD::except_msg_string(__RWSTD::__rw_bitset_ConversionOverflow,
                                              "bitset::to_ulong() const").msgstr());
    unsigned long result = 0;

    for (size_t pos = 0; pos < N; pos++)
      if (test(pos))
        result |= 1UL << pos;

    return result;
  } 

//
// Returns the count of the number of set bits.
//

  template <size_t N>
  size_t
  bitset<N>::count () const _RWSTD_THROW_SPEC_NULL
  {
    size_t sum = 0;

#if UINT_MAX <= 4294967295
    //
    // A sophisticated implementaton that works if BitsPerChunk < 63
    //
    for (size_t i = 0; i < _NELEMENTS; i++)
    {
      unsigned long n = bits[i];
      unsigned long t = n - ((n>>1) & 033333333333) - ((n>>2) & 011111111111);
      t = ((t + (t >> 3)) & 030707070707);

      unsigned long x = t & 07700770077;
      unsigned long y = (t >> 6) & 07700770077;

      t = x + y;
      t = ((t >> 12) + (t >> 24) + t) & 0777;
      t = (t >> 6) + (t & 077);
      t = t + 1;

      sum += (t >> 6) + (t & 077) - 1;
    }
#else
    //
    // The more naive implementation that always works.
    //
    for (size_t i = 0; i < _NELEMENTS; i++)
    {
      unsigned long n = bits[i];
      while (n)
      {
        n &= n-1;
        sum++;
      }
    }
#endif
    return sum;
  }
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __BITSET_CC */
