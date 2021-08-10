//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993, 1993 by Borland International
//   source\owl\bitset.h
//----------------------------------------------------------------------------
#if !defined(__OWL_BITSET_H)
#define __OWL_BITSET_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif

#if !defined(__CLASSLIB_DEFS_H)
  #include <classlib\defs.h>
#endif

class _BIDSCLASS opstream;
class _BIDSCLASS ipstream;

class _OWLCLASS TBitSet {
  public:
    TBitSet();
    TBitSet(const TBitSet&);

    int Has(int item);

    TBitSet operator ~() const;

    void DisableItem(int item);
    void EnableItem(int item);
    TBitSet& operator +=(int item) {EnableItem(item); return *this;}
    TBitSet& operator -=(int item) {DisableItem(item); return *this;}

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
    int    Loc(int item) {return item / 8;}
    uint8  Mask(int item) {return Masks[item & 0x07];}

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

#endif  // __OWL_BITSET_H
