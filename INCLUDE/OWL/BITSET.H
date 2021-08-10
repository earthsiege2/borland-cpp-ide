//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Definition of a bit mask set
//----------------------------------------------------------------------------
#if !defined(OWL_BITSET_H)
#define OWL_BITSET_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif

class _BIDSCLASS opstream;
class _BIDSCLASS ipstream;

class _OWLCLASS TBitSet {
  public:
    TBitSet();
    TBitSet(const TBitSet&);

    int Has(uint8 item);

    TBitSet operator ~() const;

    void DisableItem(uint8 item);
    void EnableItem(uint8 item);
    TBitSet& operator +=(uint8 item) {EnableItem(item); return *this;}
    TBitSet& operator -=(uint8 item) {DisableItem(item); return *this;}

    void DisableItem(const TBitSet& bs);
    void EnableItem(const TBitSet& bs);
    TBitSet& operator +=(const TBitSet& bs) {EnableItem(bs); return *this;}
    TBitSet& operator |=(const TBitSet& bs) {EnableItem(bs); return *this;}
    TBitSet& operator -=(const TBitSet& bs) {DisableItem(bs); return *this;}
    TBitSet& operator &=(const TBitSet& bs);

    int TBitSet::IsEmpty();

    friend TBitSet operator &(const TBitSet& bs1, const TBitSet& bs2);
    friend TBitSet operator |(const TBitSet& bs1, const TBitSet& bs2);

    friend int operator ==(const TBitSet& bs1, const TBitSet& bs2);
    friend int operator !=(const TBitSet& bs1, const TBitSet& bs2);

    friend opstream& operator <<(opstream& out, const TBitSet& bs);
    friend ipstream& operator >>(ipstream& in, TBitSet& bs);

  private:
    int    Loc(uint8 item) {return item / 8;}
    uint8  Mask(uint8 item) {return Masks[item & 0x07];}

    static uint8 near Masks[8];

    uint8  Bits[32];
};

class _OWLCLASS TCharSet : public TBitSet {
  public:
    TCharSet();
    TCharSet(const TCharSet&);
    TCharSet(const char far* str);
};


inline int operator !=(const TBitSet& bs1, const TBitSet& bs2) {
  return !operator ==(bs1, bs2);
}

#endif  // OWL_BITSET_H
