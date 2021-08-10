//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TBitSet, a set of up to 256 bit flags
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_BITSET_H)
# include <owl/bitset.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif

uint8 near TBitSet::Masks[8] = {
  0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
};

//
// Initialize all the bits to 0.
//
TBitSet::TBitSet()
{
  for (int i = 0; i < 32; i++)
    Bits[i] = 0;
}

//
// Make a copy of the bits.
//
TBitSet::TBitSet(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] = bs.Bits[i];
}

//
// Return true if a bit is turned on.
//
int
TBitSet::Has(uint8 item) const
{
  return (Bits[Loc(item)] & Mask(item)) != 0;
}

//
// Negate a bit.
//
TBitSet
TBitSet::operator ~() const
{
  TBitSet temp;
  for (int i = 0; i < 32; i++)
    temp.Bits[i] = uint8(~Bits[i]);
  return temp;
}

//
// Turn off a specific bit.
//
void
TBitSet::DisableItem(uint8 item)
{
  Bits[Loc(item)] &= uint8(~Mask(item));
}

//
// Logically OR in the set of bits.
//
void
TBitSet::EnableItem(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] |= bs.Bits[i];
}

//
// Logically
//
void
TBitSet::DisableItem(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] &= uint8(~(bs.Bits[i]));
}

//
// Turn on a specific bit.
//
void
TBitSet::EnableItem(uint8 item)
{
  Bits[Loc(item)] |= Mask(item);
}

//
// Logically AND each individual bits.
//
TBitSet&
TBitSet::operator &=(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] &= bs.Bits[i];
  return *this;
}

//
// Return the AND of two bitsets.
//
TBitSet
operator &(const TBitSet& bs1, const TBitSet& bs2)
{
  TBitSet temp(bs1);
  temp &= bs2;
  return temp;
}

//
// Return the OR of two bitsets.
//
TBitSet
operator |(const TBitSet& bs1, const TBitSet& bs2)
{
  TBitSet temp(bs1);
  temp |= bs2;
  return temp;
}

//
// Return true if all bits are off.
//
int
TBitSet::IsEmpty() const
{
  for (int i = 0; i < 32; i++)
    if (Bits[i] != 0)
      return false;
  return true;
}

//
// Return true if the two bitsets are indentical.
//
int
operator ==(const TBitSet& bs1, const TBitSet& bs2)
{
  for (int i = 0; i < 32; i++)
    if (bs1.Bits[i] != bs2.Bits[i])
      return false;
  return true;
}

//
// Insert the bitset into a persistent output stream.
//
opstream& operator <<(opstream& out, const TBitSet& bs)
{
  out.fwriteBytes(bs.Bits, sizeof(bs.Bits));
  return out;
}

//
// Extract the bitset from a persistent input stream.
//
ipstream& operator >>(ipstream& in, TBitSet& bs)
{
  in.freadBytes(bs.Bits, sizeof(bs.Bits));
  return in;
}

//----------------------------------------------------------------------------

//
// Construct a default character set.
// All items are set to 0.
//
TCharSet::TCharSet()
:
  TBitSet()
{
}

//
// Copy the bitset into this character set.
//
TCharSet::TCharSet(const TBitSet& bs)
:
  TBitSet(bs)
{
}

//
// Construct a character set from a string.
// The characters act as the index for the bitset.
//
TCharSet::TCharSet(const char far* str)
:
  TBitSet()
{
  for (const char far* p = str; *p; p++) {
    if (*p == '\\')
      p++;
    else if (*p == '-' && p > str && p[1]) {  // handle "A-Z" type shorthands
      p++;
      for (char c = char(p[-2]+1); c < *p; c++) // replace "-" with "B..Y"
        EnableItem(c);
    }
    EnableItem(*p);
  }
}
