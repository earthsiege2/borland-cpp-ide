#ifndef __BITSET_H
#define __BITSET_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_BITS
#define __STD_BITS

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
#include <rw/stddefs.h> 
#include <rw/rwstderr.h>

#ifndef _RWSTD_NO_NEW_HEADER
#include <climits>
#include <cstddef>
#else
#include <limits.h>
#include <stddef.h>
#endif

#ifdef _RW_STD_IOSTREAM
#ifdef _HPACC_
#include <iostream>
#else
#include <iosfwd>
#endif
#else
class  ostream;
class  istream;
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
#ifdef _RW_STD_EXCEPT
#include <stdexcept>
#endif
#endif

#include <string>
#ifndef _RWSTD_BC5_ENUM_BUG
#define _NELEMENTS NumOfElems
#else
#define _NELEMENTS NumOfElems()
#endif /*_RWSTD_BC5_ENUM_BUG*/

#ifndef _RWSTD_NO_NAMESPACE 
namespace __rwstd {
#endif
//
// Exception error messages.
//
#ifdef _RWSTD_LOCALIZED_ERRORS
  extern const unsigned int _RWSTDExport __rw_bitset_InvalidPosition;
  extern const unsigned int _RWSTDExport __rw_bitset_InvalidCtorArgument;
  extern const unsigned int _RWSTDExport __rw_bitset_ConversionOverflow;
#else
  extern const char _RWSTDExportFunc(*) __rw_bitset_InvalidPosition;
  extern const char _RWSTDExportFunc(*) __rw_bitset_InvalidCtorArgument;
  extern const char _RWSTDExportFunc(*) __rw_bitset_ConversionOverflow;
#endif//_RWSTD_LOCALIZED_ERRORS

#ifndef _RWSTD_NO_NAMESPACE 
} namespace std {
#endif

  template <size_t N>
  class _RWSTDExportTemplate bitset
  {
  private:
    //
    // The type of array in which we store the bits.
    //
    typedef unsigned int VectorType;
    //
    // Number of bits in an array element.
    //
    enum { BitsPerChunk = CHAR_BIT*sizeof(unsigned int) };
    //
    // Number of array elements.
    //
#ifndef _RWSTD_BC5_ENUM_BUG
    enum { NumOfElems = N == 0 ? 1 : 1 + ((N - 1) / BitsPerChunk) };
#else
    size_t NumOfElems () const
    {
      return N == 0 ? 1 : 1 + ((N - 1) / BitsPerChunk);
    }
#endif /*_RWSTD_BC5_ENUM_BUG*/
    //
    // Number of bits in an unsigned long.
    //
    enum { BitsInUnsignedLong = CHAR_BIT*sizeof(unsigned long) };
    //
    // The array of bits.
    //
#ifndef _RWSTD_BC5_ENUM_BUG
    VectorType bits[_NELEMENTS];
#else
    VectorType* bits;
#endif /*_RWSTD_BC5_ENUM_BUG*/

  protected:
    //
    // Is pos a valid bitset position?
    //
    bool valid_position (size_t pos) const _RWSTD_THROW_SPEC_NULL
    {
      return N > pos ? true : false;
    }
    //
    // Given a bit position `pos', returns the index into the appropriate
    // chunk in bits[] such that 0 <= index < BitsPerChunk.
    //
    unsigned long index (size_t pos) const _RWSTD_THROW_SPEC_NULL
    {
#if UINT_MAX == 256
      return 7 & pos;
#elif UINT_MAX == 65535
      return 15 & pos;
#elif UINT_MAX == 4294967295
      return 31 & pos;
#elif UINT_MAX == 18446744073709551615
      return 63 & pos;
#else
      return pos % BitsPerChunk;
#endif
    }

  public:

    typedef bool element_type;
#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
    const size_t bitset_size;
#else
#ifndef _RWSTD_NO_STI_TEMPLATE
    static const size_t bitset_size = N;
#else
    static const size_t bitset_size;
#endif
#endif

    //
    // bit reference
    //
    class reference
    {
      friend class bitset<N>;
    private:
      bitset<N>& ref;
      size_t     pos;
      reference (bitset<N>& r, size_t p) _RWSTD_THROW_SPEC_NULL
      : ref(r), pos(p) {}
    public:
      //
      // for b[i] = x;
      //
      reference& operator= (bool val) _RWSTD_THROW_SPEC_NULL
      {
        ref.set(pos, val); return *this;
      }
      //
      // for b[i] = b[j];
      //
      reference& operator= (const reference& rhs) _RWSTD_THROW_SPEC_NULL
      {
        ref.set(pos, rhs.ref.test(rhs.pos)); return *this;
      }
      //
      // for x = ~b[i];
      //
      bool operator~ () const _RWSTD_THROW_SPEC_NULL { return !ref.test(pos);}
      //
      // for x = b[i];
      //
      operator bool () const _RWSTD_THROW_SPEC_NULL { return ref.test(pos); }
      reference& flip() _RWSTD_THROW_SPEC_NULL { ref.flip(pos); return *this;}
    };
    //
    // constructors
    //
    bitset () _RWSTD_THROW_SPEC_NULL
#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
      : bitset_size(N)
#endif
    {
#ifndef _RWSTD_BC5_ENUM_BUG
      memset(bits, 0, sizeof(bits));
#else
      bits = new VectorType[_NELEMENTS];
      memset(bits, 0, _NELEMENTS*sizeof(VectorType));
#endif /*_RWSTD_BC5_ENUM_BUG*/
    }
    bitset (unsigned long val) _RWSTD_THROW_SPEC_NULL
#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
      : bitset_size(N)
#endif
    {
      //
      // Initialize first M bit positions to the corresponding
      // bit values in val. M is the smaller of N and the value
      // CHAR_BIT * sizeof(unsigned long).
      //
#ifndef _RWSTD_BC5_ENUM_BUG
      memset(bits, 0, sizeof(bits));
#else
      bits = new VectorType[_NELEMENTS];
      memset(bits, 0, _NELEMENTS*sizeof(VectorType));
#endif /*_RWSTD_BC5_ENUM_BUG*/
      size_t M = N < BitsInUnsignedLong ? N : BitsInUnsignedLong;
      for (size_t i = 0; i < M; i++)
        if (val & (1UL << i))
          set(i);
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class charT, class traits, class Allocator>
    _EXPLICIT bitset (const basic_string<charT,traits,Allocator>&,
                      _TYPENAME basic_string<charT,traits,Allocator>::size_type=0,
                      _TYPENAME basic_string<charT,traits,Allocator>::size_type=
                      std::template basic_string<charT,traits,Allocator>::npos) // RW_BUG
/*    _EXPLICIT bitset (const basic_string<charT,traits,Allocator>,
                      _TYPENAME basic_string<charT,traits,Allocator>::size_type=0,
                      _TYPENAME basic_string<charT,traits,Allocator>::size_type=
                      basic_string<charT,traits,Allocator>::npos)
*/
#else
      _EXPLICIT bitset (const string& str,
                        size_t pos = 0,
                        size_t n = (size_t) -1)
#endif // _RWSTD_NO_MEMBER_TEMPLATES
      _RWSTD_THROW_SPEC((out_of_range, invalid_argument));

      // We _EXPLICITly defined the copy constructor, though
      // WP 23.3.5 allows us to use the default generated one.
      //
      bitset (const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
        : bitset_size(N)
#endif
    {
#ifndef _RWSTD_BC5_ENUM_BUG
      memcpy(bits, rhs.bits, sizeof(bits));
#else
      bits = new VectorType[_NELEMENTS];
      memcpy(bits, rhs.bits, _NELEMENTS*sizeof(VectorType));
#endif /*_RWSTD_BC5_ENUM_BUG*/
    }
    //
    // We _EXPLICITly defined the assignment, though
    // WP 23.3.5 allows us to use the default generated one.
    //
    bitset<N>& operator= (const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
    {
      if (!(this == &rhs))
#ifndef _RWSTD_BC5_ENUM_BUG
        memcpy(bits, rhs.bits, sizeof(bits));
#else
      memcpy(bits, rhs.bits, _NELEMENTS*sizeof(VectorType));
#endif /*_RWSTD_BC5_ENUM_BUG*/
      return *this;
    }
#ifdef _RWSTD_BC5_ENUM_BUG
    ~bitset () _RWSTD_THROW_SPEC_NULL { delete [] bits; }
#endif
    //
    // bitset operations
    //
    bitset<N>& operator&= (const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
    {
      for (size_t i = 0; i < _NELEMENTS; i++)
        bits[i] &= rhs.bits[i];
      return *this;
    }
    bitset<N>& operator|= (const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
    {
      for (size_t i = 0; i < _NELEMENTS; i++)
        bits[i] |= rhs.bits[i];
      return *this;
    }
    bitset<N>& operator^= (const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
    {
      for (size_t i = 0; i < _NELEMENTS; i++)
        bits[i] ^= rhs.bits[i];
      return *this;
    }
    //
    // Replaces bit at position I with a value determined as follows:
    //
    //   If (I <  pos) the new value is 0
    //   If (I >= pos) the new value is the previous value at position I - pos
    //
    bitset<N>& operator<<= (size_t pos) _RWSTD_THROW_SPEC_NULL
    {
      if (pos)
        for (long i = N - 1; i >= 0 ; --i)
          set(i, i <(long)pos || test(i - pos) == 0 ? 0 : 1);
      return *this;
    }
    //
    // Replaces bit at position I with a value determined as follows:
    //
    //   If (pos >= N-i) the new value is zero
    //   If (pos <  N-i) the new value is the previous value at position I + pos
    //
    bitset<N>& operator>>= (size_t pos) _RWSTD_THROW_SPEC_NULL
    {
      if (pos)
        for (size_t i = 0; i < N; i++)
          set(i, pos >= N - i || test(i + pos) == 0 ? 0 : 1);
      return *this;
    }
    bitset<N>& set () _RWSTD_THROW_SPEC_NULL
    {
      for (size_t i = 0; i < _NELEMENTS; i++)
        bits[i] = ~0;
      return *this;
    }
    bitset<N>& set (size_t pos, int val = 1) _RWSTD_THROW_SPEC((out_of_range))
    {
      _RWSTD_THROW(!valid_position(pos),out_of_range,
                   __RWSTD::except_msg_string(__RWSTD::__rw_bitset_InvalidPosition,
                                              "bitset::set(size_t,int )",pos).msgstr());

      if (val)
        bits[pos / BitsPerChunk] |=  (1UL << index(pos));
      else
        bits[pos / BitsPerChunk] &= ~(1UL << index(pos));
      return *this;
    }
    bitset<N>& reset () _RWSTD_THROW_SPEC_NULL
    {
      memset(bits, 0, sizeof(bits)); return *this;
    }
    bitset<N>& reset (size_t pos) _RWSTD_THROW_SPEC((out_of_range))
    {
      return set(pos, 0);
    }
    bitset<N> operator~ () const _RWSTD_THROW_SPEC_NULL
    {
      bitset<N> tmp(*this); return tmp.flip();
    }
    bitset<N>& flip () _RWSTD_THROW_SPEC_NULL
    {
      for (size_t i = 0; i < _NELEMENTS; i++) 
        bits[i] = ~bits[i];
      return *this;
    }
    bitset<N>& flip (size_t pos) _RWSTD_THROW_SPEC((out_of_range))
    {
      _RWSTD_THROW(!valid_position(pos),out_of_range,
                   __RWSTD::except_msg_string(__RWSTD::__rw_bitset_InvalidPosition,
                                              "bitset::flip(size_t)",pos).msgstr());

      bits[pos / BitsPerChunk] ^= (1UL << index(pos));
      return *this;
    }
    //
    // element access
    //
    reference operator[] (size_t pos) _RWSTD_THROW_SPEC((out_of_range))
    {
      //
      // We check that pos is valid here so that NONE of the reference
      // member functions need check.  This way ALL the reference member
      // functions can have empty throw specifications.
      //
      _RWSTD_THROW(!valid_position(pos),out_of_range,
                   __RWSTD::except_msg_string(__RWSTD::__rw_bitset_InvalidPosition,
                                              "bitset::operator[](size_t)",pos).msgstr());

      reference r(*this, pos); return r;
    }
    //
    // conversion functions
    //
    unsigned long  to_ulong  () const _RWSTD_THROW_SPEC((overflow_error));

#if !defined ( _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE) && !defined (_HPACC_)  && !defined(_RWSTD_NO_EXPLICIT_ARGS) 
    template <class charT, class traits, class Allocator>
    basic_string<charT,traits,Allocator>   to_string () const;
#else
    string         to_string () const;
#endif
    //
    // miscellaneous member functions
    //
    size_t count () const _RWSTD_THROW_SPEC_NULL;
    size_t size  () const _RWSTD_THROW_SPEC_NULL { return N; }
    bool operator== (const bitset<N>& rhs) const _RWSTD_THROW_SPEC_NULL
    {
      for (size_t i = 0; i+1 < _NELEMENTS; i++)
        if (!(bits[i] == rhs.bits[i]))
          return false;
      for (size_t j = (_NELEMENTS-1)*BitsPerChunk; j < N; j++)
        if (!(test(j) == rhs.test(j)))
          return false;
      return true;
    }
    bool operator!= (const bitset<N>& rhs) const _RWSTD_THROW_SPEC_NULL
    {
      return !(*this == rhs);
    }
    bool test (size_t pos) const _RWSTD_THROW_SPEC((out_of_range))
    {
      _RWSTD_THROW(!valid_position(pos),out_of_range,
                   __RWSTD::except_msg_string(__RWSTD::__rw_bitset_InvalidPosition,
                                              "bitset::test(size_t) const",pos).msgstr());

      return (bits[pos / BitsPerChunk] & (1UL << index(pos))) != 0;
    }
    bool any () const _RWSTD_THROW_SPEC_NULL
    {
      bool flag = false;
      for (size_t i = 0; i+1 <= _NELEMENTS && !flag; i++)
        if (bits[i])
          flag = true;
      return flag;
    }
    bool none () const _RWSTD_THROW_SPEC_NULL
    {
      bool flag = true;
      for (size_t i = 0; i+1 <= _NELEMENTS && flag; i++)
        if (bits[i])
          flag = false;
      return flag;
    }
    bitset<N> operator<< (size_t pos) const _RWSTD_THROW_SPEC_NULL
    {
      bitset<N> tmp(*this); tmp <<= pos; return tmp;
    }
    bitset<N> operator>> (size_t pos) const _RWSTD_THROW_SPEC_NULL
    {
      bitset<N> tmp(*this); tmp >>= pos; return tmp;
    }
  };
#ifndef _RWSTD_NO_NONTYPE_ARGS
  template<size_t N>
  inline bitset<N>  operator& (const bitset<N>& lhs,
                               const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
  {
    bitset<N> tmp(lhs); tmp &= rhs; return tmp;
  }

  template<size_t N>
  inline bitset<N>  operator| (const bitset<N>& lhs,
                               const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
  {
    bitset<N> tmp(lhs); tmp |= rhs; return tmp;
  }

  template<size_t N>
  inline bitset<N>  operator^ (const bitset<N>& lhs,
                               const bitset<N>& rhs) _RWSTD_THROW_SPEC_NULL
  {
    bitset<N> tmp(lhs); tmp ^= rhs; return tmp;
  }

#ifdef _RW_STD_IOSTREAM
  template<class charT, class traits, size_t N> 
  inline basic_ostream<charT,traits>&  
  operator<< (basic_ostream<charT,traits>& os, const bitset<N>& x)
  {
#if !defined ( _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE) && !defined (_HPACC_)  && !defined(_RWSTD_NO_EXPLICIT_ARGS) 
    return os << x.to_string<charT,traits,allocator<charT> >();
#else
    return os << x.to_string();
#endif
  }

  template<class charT, class traits, size_t N> 
  inline basic_istream<charT,traits>&  
  operator>> (basic_istream<charT,traits>& is, bitset<N>& x)
  {
    string str(N, '0');

    for (size_t count = 0; count < N && !is.eof(); )
    {
#if !defined(_RWSTD_NO_NONTYPE_ARGS) && defined(_RW_STD_IOSTREAM)
      charT c = 0;   
#else
      char c = 0;
#endif
      is >> c;
      if (c == '1' || c == '0')
      { 
        str.append(1, c);
        count++; 
      }
      else
      {
        is.putback(c);
        break;
      }
    }

    if (str.size() == 0)
      is.setstate(ios::failbit);

#ifdef __TURBOC__
    x = bitset<N>(str, (string::size_type) 0, (string::size_type) string::npos);
#else
    x = bitset<N>(str);
#endif

    return is;
  }

#else
  template<size_t N> 
  inline ostream&  
  operator<< (ostream& os, const bitset<N>& x)
  {
#if !defined(_RWSTD_NO_TEMPLATE_ON_RETURN_TYPE) && !defined(_RWSTD_NO_EXPLICIT_ARGS) && !defined(_HPACC_)
    return os << x.to_string<char,char_traits<char>,allocator<char> >();
#else
    return os << x.to_string();
#endif
  }

  template<size_t N> 
  istream&  
  operator>> (istream& is, bitset<N>& x);
#endif //  _RW_STD_IOSTREAM
#endif  /* _RWSTD_NO_NONTYPE_ARGS */

#undef _NELEMENTS

#ifndef _RWSTD_NO_NAMESPACE
} 
#endif

#if defined(_RWSTD_NO_DESTROY_BUILTIN) || defined(_RWSTD_NO_DESTROY_NONBUILTIN)
#ifndef _RWSTD_NO_NONTYPE_ARGS

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif
//
// Specializations of STL destroy for bitset.
//
  template <size_t N> inline void __destroy (bitset<N>**)   {;}
  template <size_t N> inline void __destroy (bitset<N>***)  {;}
  template <size_t N> inline void __destroy (bitset<N>****) {;}

#ifndef _RWSTD_NO_NAMESPACE
} 
#endif
#endif
#endif
#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <bitset.cc>
#endif
#endif /*__STD_BITS*/

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __BITSET_H */
