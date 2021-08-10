//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/bitset.h>
#include <classlib/objstrm.h>

uint8 near TBitSet::Masks[8] = {
  0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
};

TBitSet::TBitSet()
{
  for (int i = 0; i < 32; i++)
    Bits[i] = 0;
}

TBitSet::TBitSet(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] = bs.Bits[i];
}

int
TBitSet::Has(uint8 item)
{
  return (Bits[Loc(item)] & Mask(item)) != 0;
}

TBitSet
TBitSet::operator ~() const
{
  TBitSet temp;
  for (int i = 0; i < 32; i++)
    temp.Bits[i] = uint8(~Bits[i]);
  return temp;  
}

void
TBitSet::DisableItem(uint8 item)
{
  Bits[Loc(item)] &= uint8(~Mask(item));
}

void
TBitSet::EnableItem(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] |= bs.Bits[i];
}

void
TBitSet::DisableItem(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] &= uint8(~(bs.Bits[i]));
}

void
TBitSet::EnableItem(uint8 item)
{
  Bits[Loc(item)] |= Mask(item);
}

TBitSet&
TBitSet::operator &=(const TBitSet& bs)
{
  for (int i = 0; i < 32; i++)
    Bits[i] &= bs.Bits[i];
  return *this;
}

TBitSet
operator &(const TBitSet& bs1, const TBitSet& bs2)
{
  TBitSet temp(bs1);
  temp &= bs2;
  return temp;
}

TBitSet
operator |(const TBitSet& bs1, const TBitSet& bs2)
{
  TBitSet temp(bs1);
  temp |= bs2;
  return temp;
}

int
TBitSet::IsEmpty()
{
  for (int i = 0; i < 32; i++)
    if (Bits[i] != 0)
      return false;
  return true;
}

int
operator ==(const TBitSet& bs1, const TBitSet& bs2)
{
  for (int i = 0; i < 32; i++)
    if (bs1.Bits[i] != bs2.Bits[i])
      return false;
  return true;
}

opstream& operator <<(opstream& out, const TBitSet& bs)
{
  out.fwriteBytes(bs.Bits, sizeof(bs.Bits));
  return out;
}

ipstream& operator >>(ipstream& in, TBitSet& bs)
{
  in.freadBytes(bs.Bits, sizeof(bs.Bits));
  return in;
}

//----------------------------------------------------------------------------

TCharSet::TCharSet() : TBitSet()
{
}

TCharSet::TCharSet(const TCharSet& cs) : TBitSet(cs)
{
}

TCharSet::TCharSet(const char far* str) : TBitSet()
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
