//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of a bit set and a character set
//----------------------------------------------------------------------------
#if !defined(OWL_BITSET_H)
#define OWL_BITSET_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _BIDSCLASS opstream;
class _BIDSCLASS ipstream;

//
// class TBitSet
// ~~~~~ ~~~~~~~
// Simplifies setting and testing bits in a 32 count array of uint8 (32 bytes).
//
class _OWLCLASS TBitSet {
  public:
    TBitSet();
    TBitSet(const TBitSet& src);

    int Has(uint8 item) const;

    TBitSet operator ~() const;

    void DisableItem(uint8 item);
    void EnableItem(uint8 item);
    TBitSet& operator +=(uint8 item);
    TBitSet& operator -=(uint8 item);

    void DisableItem(const TBitSet& bs);
    void EnableItem(const TBitSet& bs);
    TBitSet& operator +=(const TBitSet& bs);
    TBitSet& operator |=(const TBitSet& bs);
    TBitSet& operator -=(const TBitSet& bs);
    TBitSet& operator &=(const TBitSet& bs);

    int TBitSet::IsEmpty() const;

    friend TBitSet operator &(const TBitSet& bs1, const TBitSet& bs2);
    friend TBitSet operator |(const TBitSet& bs1, const TBitSet& bs2);

    friend int operator ==(const TBitSet& bs1, const TBitSet& bs2);
    friend int operator !=(const TBitSet& bs1, const TBitSet& bs2);

    friend opstream& operator <<(opstream& out, const TBitSet& bs);
    friend ipstream& operator >>(ipstream& in, TBitSet& bs);

  private:
    int    Loc(uint8 item) const;
    uint8  Mask(uint8 item) const;

    static uint8 near Masks[8];

    uint8  Bits[32];
};

//
// class CharSet
// ~~~~~ ~~~~~~~~
class _OWLCLASS TCharSet : public TBitSet {
  public:
    TCharSet();
    TCharSet(const TBitSet& src);
    TCharSet(const char far* str);
};

//
// TBitFlags is a *lightweight* class for setting, clearing and querrying
// bit flags. It's intenteded to be used with a 'short' or 'long' type
// allowing an easy method to handle 16 and 32 bit flags respectively.
//
// For example:
//
//    class TMyClass : public TMyBase, public TBitFlags<short> {
//
template <class T> class _OWLCLASS TBitFlags {
  public:
    TBitFlags(T  t = 0);

    // Query, Clear and Set flag bits
    //
    T       Clear(T t);
    T       Set(T t);
    bool    IsSet(T t) const;

  protected:
    T       Bits;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Enable the bit
inline TBitSet& TBitSet::operator +=(uint8 item)
{
  EnableItem(item);
  return *this;
}

//
inline TBitSet& TBitSet::operator -=(uint8 item)
{
  DisableItem(item);
  return *this;
}

//
inline TBitSet& TBitSet::operator +=(const TBitSet& bs)
{
  EnableItem(bs);
  return *this;
}

//
inline TBitSet& TBitSet::operator |=(const TBitSet& bs)
{
  EnableItem(bs);
  return *this;
}

//
inline TBitSet& TBitSet::operator -=(const TBitSet& bs)
{
  DisableItem(bs);
  return *this;
}

//
// Return the index of the item searched for.
//
inline int TBitSet::Loc(uint8 item) const {
  return item / 8;
}

//
// Return the mask needed to look for a specific bit.
//
inline uint8 TBitSet::Mask(uint8 item) const {
  return Masks[item & 0x07];
}

//
// Return true if the bitsets are not identical.
// (Return the negative of operator ==).
//
inline int operator !=(const TBitSet& bs1, const TBitSet& bs2)
{
  return !operator ==(bs1, bs2);
}

//
// Initialize the Flags to the specified parameter
//
template <class T>
TBitFlags<T>::TBitFlags(T t)
:
  Bits(t)
{
}

//
// Activate the bits that are enabled in the specified parameter
//
template <class T>
T TBitFlags<T>::Set(T t)
{
  return Bits |= t;
}

//
// Clear the bits that are enabled in the specified parameter
//
template <class T>
T TBitFlags<T>::Clear(T t)
{
  return Bits &= ~t;
}

//
// Return true of the ON bits of the parameter are currently enabled.
// Return false otherwise.
//
template <class T>
bool TBitFlags<T>::IsSet(T t) const
{
  return (Bits & t) != 0;
}

#endif  // OWL_BITSET_H
