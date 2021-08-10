#ifndef __STD_BITS
#define __STD_BITS
/* $Revision:   8.1  $ */

/***************************************************************************
 *
 * bitset - class bitset declaration
 *
 * $Id: bitset,v 1.55 1995/09/29 23:52:59 smithey Exp $
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
#include <stddefs.h>

#ifndef RWSTD_NO_NEW_HEADER
#include <climits>
#include <cstddef>
#else
#include <limits.h>
#include <stddef.h>
#endif

#ifdef RW_STD_IOSTREAM
#include <iosfwd>
#else
class  ostream;
class  istream;
#endif

#ifndef RWSTD_NO_EXCEPTIONS
#ifdef RW_STD_EXCEPT
#include <stdexcept>
#endif
#endif

#include <string>

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Exception error messages.
//
extern char RWSTDExport  __rw_bitset_InvalidPosition[];
extern char RWSTDExport  __rw_bitset_InvalidCtorArgument[];
extern char RWSTDExport  __rw_bitset_ConversionOverflow[];

template <size_t N>
class  bitset
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
#ifndef RWSTD_BC5_ENUM_BUG
    enum { NumOfElems = N == 0 ? 1 : 1 + ((N - 1) / BitsPerChunk) };
    #define NELEMENTS NumOfElems
#else
    int NumOfElems () const
    {
        return N == 0 ? 1 : 1 + ((N - 1) / BitsPerChunk);
    }
    #define NELEMENTS NumOfElems()
#endif /*RWSTD_BC5_ENUM_BUG*/
    //
    // Number of bits in an unsigned long.
    //
    enum { BitsInUnsignedLong = CHAR_BIT*sizeof(unsigned long) };
    //
    // The array of bits.
    //
#ifndef RWSTD_BC5_ENUM_BUG
    VectorType bits[NELEMENTS];
#else
    VectorType* bits;
#endif /*RWSTD_BC5_ENUM_BUG*/

  protected:
    //
    // Is pos a valid bitset position?
    //
    bool valid_position (size_t pos) const RWSTD_THROW_SPEC_NULL
    {
        return N > pos ? true : false;
    }
    //
    // Given a bit position `pos', returns the index into the appropriate
    // chunk in bits[] such that 0 <= index < BitsPerChunk.
    //
    size_t index (size_t pos) const RWSTD_THROW_SPEC_NULL
    {
#if UINT_MAX == 256
        return 7 & pos;
#elif UINT_MAX == 65535
        return 15 & pos;
#elif UINT_MAX == 4294967295
        return 31 & pos;
#elif UINT_MAX == 18446744073709551616
        return 63 & pos;
#else
        return pos % BitsPerChunk;
#endif
    }

  public:
    //
    // bit reference
    //
    class reference
    {
        friend class bitset<N>;
      private:
        bitset<N>& ref;
        size_t     pos;
        reference (bitset<N>& r, size_t p) RWSTD_THROW_SPEC_NULL
            : ref(r), pos(p) {}
      public:
        ~reference() RWSTD_THROW_SPEC_NULL {}
        //
        // for b[i] = x;
        //
        reference& operator= (bool val) RWSTD_THROW_SPEC_NULL
        {
            ref.set(pos, val); return *this;
        }
        //
        // for b[i] = b[j];
        //
        reference& operator= (const reference& rhs) RWSTD_THROW_SPEC_NULL
        {
            ref.set(pos, rhs.ref.test(rhs.pos)); return *this;
        }
        //
        // for x = ~b[i];
        //
        bool operator~ () const RWSTD_THROW_SPEC_NULL { return !ref.test(pos);}
        //
        // for x = b[i];
        //
        operator bool () const RWSTD_THROW_SPEC_NULL { return ref.test(pos); }
        //
        // flips the bit
        //
        reference& flip() RWSTD_THROW_SPEC_NULL { ref.flip(pos); return *this;}
    };
    //
    // constructors
    //
    bitset () RWSTD_THROW_SPEC_NULL
    {
#ifndef RWSTD_BC5_ENUM_BUG
        memset(bits, 0, sizeof(bits));
#else
        bits = new VectorType[NELEMENTS];
        //
        // TODO -- check for bits == 0 here?
        //
        memset(bits, 0, NELEMENTS*sizeof(VectorType));
#endif /*RWSTD_BC5_ENUM_BUG*/
    }
    bitset (unsigned long val) RWSTD_THROW_SPEC_NULL
    {
        //
        // Initialize first M bit positions to the corresponding
        // bit values in val. M is the smaller of N and the value
        // CHAR_BIT * sizeof(unsigned long).
        //
#ifndef RWSTD_BC5_ENUM_BUG
        memset(bits, 0, sizeof(bits));
#else
        bits = new VectorType[NELEMENTS];
        //
        // TODO -- check for bits == 0 here?
        //
        memset(bits, 0, NELEMENTS*sizeof(VectorType));
#endif /*RWSTD_BC5_ENUM_BUG*/
        size_t M = N < BitsInUnsignedLong ? N : BitsInUnsignedLong;
        for (size_t i = 0; i < M; i++)
            if (val & (1 << i))
                set(i);
    }
    explicit bitset (const string& str,
                     size_t pos = 0,
                     size_t n = (size_t) -1)
                     RWSTD_THROW_SPEC((out_of_range, invalid_argument));
    //
    // We explicitly defined the copy constructor, though
    // WP 17.2.2.2 allows us to use the default generated one.
    //
    bitset (const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
    {
#ifndef RWSTD_BC5_ENUM_BUG
        memcpy(bits, rhs.bits, sizeof(bits));
#else
        bits = new VectorType[NELEMENTS];
        //
        // TODO -- check for bits == 0 here?
        //
        memcpy(bits, rhs.bits, NELEMENTS*sizeof(VectorType));
#endif /*RWSTD_BC5_ENUM_BUG*/
    }
    //
    // We explicitly defined the assignment, though
    // WP 17.2.2.2 allows us to use the default generated one.
    //
    bitset<N>& operator= (const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
    {
        if (!(this == &rhs))
#ifndef RWSTD_BC5_ENUM_BUG
            memcpy(bits, rhs.bits, sizeof(bits));
#else
            memcpy(bits, rhs.bits, NELEMENTS*sizeof(VectorType));
#endif /*RWSTD_BC5_ENUM_BUG*/
        return *this;
    }
#ifdef RWSTD_BC5_ENUM_BUG
    ~bitset () RWSTD_THROW_SPEC_NULL { delete [] bits; }
#endif
    //
    // bitset operations
    //
    bitset<N>& operator&= (const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
    {
        for (size_t i = 0; i < NELEMENTS; i++)
            bits[i] &= rhs.bits[i];
        return *this;
    }
    bitset<N>& operator|= (const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
    {
        for (size_t i = 0; i < NELEMENTS; i++)
            bits[i] |= rhs.bits[i];
        return *this;
    }
    bitset<N>& operator^= (const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
    {
        for (size_t i = 0; i < NELEMENTS; i++)
            bits[i] ^= rhs.bits[i];
        return *this;
    }
    //
    // Replaces bit at position I with a value determined as follows:
    //
    //   If (I <  pos) the new value is 0
    //   If (I >= pos) the new value is the previous value at position I - pos
    //
    bitset<N>& operator<<= (size_t pos) RWSTD_THROW_SPEC_NULL
    {
        if (pos)
            for (long i = N - 1; i >= 0 ; --i)
                set(i, i < pos || test(i - pos) == 0 ? 0 : 1);
        return *this;
    }
    //
    // Replaces bit at position I with a value determined as follows:
    //
    //   If (pos >= N-i) the new value is zero
    //   If (pos <  N-i) the new value is the previous value at position I + pos
    //
    bitset<N>& operator>>= (size_t pos) RWSTD_THROW_SPEC_NULL
    {
        if (pos)
            for (size_t i = 0; i < N; i++)
                set(i, pos >= N - i || test(i + pos) == 0 ? 0 : 1);
        return *this;
    }
    bitset<N>& set () RWSTD_THROW_SPEC_NULL
    {
        for (size_t i = 0; i < NELEMENTS; i++)
            bits[i] = ~0;
        return *this;
    }
    bitset<N>& set (size_t pos, int val = 1) RWSTD_THROW_SPEC((out_of_range))
    {
        RWSTD_THROW(!valid_position(pos),
                    out_of_range,
                    __rw_bitset_InvalidPosition);
        if (val)
            bits[pos / BitsPerChunk] |=  (1 << index(pos));
        else
            bits[pos / BitsPerChunk] &= ~(1 << index(pos));
        return *this;
    }
    bitset<N>& reset () RWSTD_THROW_SPEC_NULL
    {
        memset(bits, 0, sizeof(bits)); return *this;
    }
    bitset<N>& reset (size_t pos) RWSTD_THROW_SPEC((out_of_range))
    {
        return set(pos, 0);
    }
    bitset<N> operator~ () RWSTD_THROW_SPEC_NULL
    {
        bitset<N> tmp(*this); return tmp.flip();
    }
    bitset<N>& flip () RWSTD_THROW_SPEC_NULL
    {
        for (size_t i = 0; i < NELEMENTS; i++)
            bits[i] = ~bits[i];
        return *this;
    }
    bitset<N>& flip (size_t pos) RWSTD_THROW_SPEC((out_of_range))
    {
        RWSTD_THROW(!valid_position(pos),
                    out_of_range,
                    __rw_bitset_InvalidPosition);
        bits[pos / BitsPerChunk] ^= (1 << index(pos));
        return *this;
    }
    //
    // element access
    //
    reference operator[] (size_t pos) RWSTD_THROW_SPEC((out_of_range))
    {
        //
        // We check that pos is valid here so that NONE of the reference
        // member functions need check.  This way ALL the reference member
        // functions can have empty throw specifications.
        //
        RWSTD_THROW(!valid_position(pos),
                    out_of_range,
                    __rw_bitset_InvalidPosition);
        reference r(*this, pos); return r;
    }
    //
    // conversion functions
    //
    unsigned long  to_ulong  () const RWSTD_THROW_SPEC((overflow_error));
    string         to_string () const;
    //
    // miscellaneous member functions
    //
    size_t count () const RWSTD_THROW_SPEC_NULL;
    size_t size  () const RWSTD_THROW_SPEC_NULL { return N; }
    bool operator== (const bitset<N>& rhs) const RWSTD_THROW_SPEC_NULL
    {
        bool flag = true;
        for (size_t i = 0; i < NELEMENTS && flag; i++)
            if (!(bits[i] == rhs.bits[i]))
                flag = false;
        return flag;
    }
    bool operator!= (const bitset<N>& rhs) const RWSTD_THROW_SPEC_NULL
    {
        return !(*this == rhs);
    }
    bool test (size_t pos) const RWSTD_THROW_SPEC((out_of_range))
    {
        RWSTD_THROW(!valid_position(pos),
                    out_of_range,
                    __rw_bitset_InvalidPosition);
        return (bits[pos / BitsPerChunk] & (1 << index(pos))) != 0;
    }
    bool any () const RWSTD_THROW_SPEC_NULL
    {
        bool flag = false;
        for (size_t i = 0; i < NELEMENTS && !flag; i++)
            if (bits[i])
                flag = true;
        return flag;
    }
    bool none () const RWSTD_THROW_SPEC_NULL
    {
        bool flag = true;
        for (size_t i = 0; i < NELEMENTS && flag; i++)
            if (bits[i])
                flag = false;
        return flag;
    }
    bitset<N> operator<< (size_t pos) const RWSTD_THROW_SPEC_NULL
    {
        bitset<N> tmp(*this); tmp <<= pos; return tmp;
    }
    bitset<N> operator>> (size_t pos) const RWSTD_THROW_SPEC_NULL
    {
        bitset<N> tmp(*this); tmp >>= pos; return tmp;
    }
};

template <size_t N>
bitset<N>::bitset (const string& str,
                   size_t pos,
                   size_t n) RWSTD_THROW_SPEC((out_of_range, invalid_argument))
{
    size_t slen = str.size();

    RWSTD_THROW(pos > slen,
                out_of_range,
                __rw_bitset_InvalidPosition);

    size_t rlen = n < (slen - pos) ? n : slen - pos;
    size_t M = N >= rlen ? rlen : N;
#ifndef RWSTD_BC5_ENUM_BUG
    memset(bits, 0, sizeof(bits));
#else
    bits = new VectorType[NELEMENTS];
    //
    // TODO -- check for bits == 0 here?
    //
    memset(bits, 0, NELEMENTS*sizeof(VectorType));
#endif /*RWSTD_BC5_ENUM_BUG*/
    for (size_t i = pos; i < M + pos; i++)
    {
        char c = str[slen - i - 1];

        RWSTD_THROW(!(c == '0' || c == '1'),
                    invalid_argument,
                    __rw_bitset_InvalidCtorArgument);

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
string
bitset<N>::to_string () const
{
    string s;
    if (N)
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
bitset<N>::to_ulong () const RWSTD_THROW_SPEC((overflow_error))
{
    const size_t size_long = sizeof(unsigned long);

    for (size_t i = NELEMENTS-1; size_long/sizeof(VectorType) <= i; --i)
        RWSTD_THROW(bits[i],
                    overflow_error,
                    __rw_bitset_ConversionOverflow);

    unsigned long result = 0;

    for (size_t pos = 0; pos < N; pos++)
        if (test(pos))
            result |= 1 << pos;

    return result;
}

//
// Returns the count of the number of set bits.
//

template <size_t N>
size_t
bitset<N>::count () const RWSTD_THROW_SPEC_NULL
{
    size_t sum = 0;

#if UINT_MAX <= 4294967295
    //
    // A sophisticated implementaton that works if BitsPerChunk < 63
    //
    for (size_t i = 0; i < NELEMENTS; i++)
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
    for (size_t i = 0; i < NELEMENTS; i++)
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

#ifndef RWSTD_NO_NONTYPE_ARGS
template<size_t N>
bitset<N>  operator& (const bitset<N>& lhs,
                     const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
{
    bitset<N> tmp(lhs); tmp &= rhs; return tmp;
}

template<size_t N>
bitset<N>  operator| (const bitset<N>& lhs,
                     const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
{
    bitset<N> tmp(lhs); tmp |= rhs; return tmp;
}

template<size_t N>
bitset<N>  operator^ (const bitset<N>& lhs,
                     const bitset<N>& rhs) RWSTD_THROW_SPEC_NULL
{
    bitset<N> tmp(lhs); tmp ^= rhs; return tmp;
}

template<size_t N> ostream&  operator<< (ostream& os, const bitset<N>& x)
{
    return os << x.to_string();
}

template <size_t N>
istream&
 operator>> (istream& is, bitset<N>& x)
{
    string str(N, '0');

    for (size_t count = 0; count < N && !is.eof(); )
    {
        char c = 0;
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
#ifdef RW_STD_IOSTREAM
        is.setstate(ios::failbit);
#else
        is.clear(ios::failbit);
#endif

    x = bitset<N>(str);

    return is;
}
#endif /*RWSTD_NO_NONTYPE_ARGS*/

#if defined(RWSTD_NO_DESTROY_BUILTIN) || defined(RWSTD_NO_DESTROY_NONBUILTIN)
#ifndef RWSTD_NO_NONTYPE_ARGS
//
// Specializations of STL destroy for bitset.
//
template <size_t N> inline void destroy (bitset<N>**)   {;}
template <size_t N> inline void destroy (bitset<N>***)  {;}
template <size_t N> inline void destroy (bitset<N>****) {;}
#endif
#endif

#undef NELEMENTS

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif /*__STD_BITS*/
