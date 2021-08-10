//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Simple fixed point class that maintains numbers as 16.16
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_FIXEDPNT_H)
#define CLASSLIB_FIXEDPNT_H

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TFixedPoint
// ~~~~~ ~~~~~~~~~~~
class TFixedPoint {
  public:
    TFixedPoint(int s = 0) {Value = long(s) << 16;}
    TFixedPoint(int num, int denom) {Value = long(num) * 65536L / denom;}

    // Unary negation operator
    //
    TFixedPoint         operator -() {return -Value;}

    // Postfix increment/decrement operators
    //
    void           operator ++(int) {Value += 1L << 16;}
    void           operator --(int) {Value -= 1L << 16;}

    // Bitwise logical operators
    //
    TFixedPoint    operator <<(unsigned n) {return Value << _TCHAR(n);}
    TFixedPoint    operator >>(unsigned n) {return Value >> _TCHAR(n);}

    // Assignment operators
    //
    TFixedPoint&   operator <<=(unsigned n) {Value <<= n; return *this;}
    TFixedPoint&   operator >>=(unsigned n) {Value >>= n; return *this;}

    TFixedPoint&   operator +=(const TFixedPoint& f) {Value += f.Value; return *this;}

    TFixedPoint&   operator -=(const TFixedPoint& f) {Value -= f.Value; return *this;}

    TFixedPoint&   operator *=(int s) {Value *= s; return *this;}
    TFixedPoint&   operator *=(const TFixedPoint& f) {Value = (Value >> 8) * (f.Value >> 8);
                                                 return *this;}

    TFixedPoint&   operator /=(int s) {Value /= s; return *this;}
    TFixedPoint&   operator /=(const TFixedPoint& f) {Value /= f.Value >> 8; Value <<= 8;
                                                 return *this;}

    // Binary arithmetic operators
    //
    friend TFixedPoint operator +(const TFixedPoint& l,
                             const TFixedPoint& r) {return l.Value + r.Value;}
    friend TFixedPoint operator +(int           l,
                             const TFixedPoint& r) {return TFixedPoint(l) += r.Value;}
    friend TFixedPoint operator +(const TFixedPoint& l,
                             int           r) {return r + l;}

    friend TFixedPoint operator -(const TFixedPoint& l,
                             const TFixedPoint& r) {return l.Value - r.Value;}
    friend TFixedPoint operator -(int           l,
                             const TFixedPoint& r) {return TFixedPoint(l) -= r.Value;}
    friend TFixedPoint operator -(const TFixedPoint& l,
                             int           r) {return l - TFixedPoint(r);}

    friend TFixedPoint operator *(const TFixedPoint& l,
                             const TFixedPoint& r) {return (l.Value >> 8) * (r.Value >> 8);}
    friend TFixedPoint operator *(int           l,
                             const TFixedPoint& r) {return l * r.Value;}
    friend TFixedPoint operator *(const TFixedPoint& l,
                             int           r) {return l.Value * r;}

    friend TFixedPoint operator /(const TFixedPoint& l,
                             const TFixedPoint& r) {return (l.Value /(r.Value >> 8)) << 8;}
    friend TFixedPoint operator /(int           l,
                             const TFixedPoint& r) {return (long(l) << 16) / r.Value;}
    friend TFixedPoint operator /(const TFixedPoint& l,
                             int           r) {return l.Value / r;}

    // Equality operators
    //
    friend bool   operator ==(const TFixedPoint& l,
                              const TFixedPoint& r) {return l.Value == r.Value;}
    friend bool   operator !=(const TFixedPoint& l,
                              const TFixedPoint& r) {return l.Value != r.Value;}

    // Conversion operator to int
    //
    operator int() {return int(Value >> 16);}

  private:
    TFixedPoint(long v) {Value = v;}

    long  Value;
};

#if defined(BI_NAMESPACE)
}   // namespace ClassLib
#endif

#endif  // CLASSLIB_FIXEDPNT_H
