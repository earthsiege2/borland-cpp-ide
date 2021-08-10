// SYSCOMP.H: Pascal Comp type
// Copyright (c) 1997, 2002 Borland Software Corporation

#if !defined(SYSCOMP_H)		// comp type
#define SYSCOMP_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif

#if !defined(SYSCURR_H)
#include <syscurr.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{
// Comp
// Range: -263+1 .. 263-1, Significant digits: 19-20, Size: 8
// The Comp (computational) type holds only integral values within -263+1
// to 263-1, which is approximately -9.2 * 1018 to 9.2 * 1018.
//
// When a Comp is returned from a Pascal function, it is returned as a
// double (on the floating point stack).
//

  typedef double CompReturn;

  struct PACKAGE CompBase
  {
  protected:
    char __data[8];
  };

  struct PACKAGE Comp : public CompBase
  {
    Comp();
    Comp(double);
    Comp(Currency);
    Comp &operator =(double);
    Comp &operator =(Currency);
    operator double() const;
    operator Currency() const;
  };

  extern PACKAGE double   __cdecl CompToDouble(Comp acomp);
  extern PACKAGE void     __cdecl DoubleToComp(double adouble, Comp &result);
  extern PACKAGE Currency __cdecl CompToCurrency(Comp acomp);
  extern PACKAGE void     __cdecl CurrencyToComp(Currency acurrency, Comp &result);

  inline Comp::Comp()                        { }
  inline Comp::Comp(double d)                { DoubleToComp(d, *this); }
  inline Comp::Comp(Currency d)              { CurrencyToComp(d, *this); }
  inline Comp &Comp::operator = (double d)   { DoubleToComp(d, *this); return *this; }
  inline Comp &Comp::operator = (Currency d) { CurrencyToComp(d, *this); return *this; }
  inline Comp::operator double() const       { return CompToDouble(*this); }
  inline Comp::operator Currency() const     { return CompToCurrency(*this); }
}

#pragma option pop

#endif
