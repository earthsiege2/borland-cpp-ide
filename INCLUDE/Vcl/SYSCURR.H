// SYSCURR.H: Pascal Currency type
// Copyright (c) 1997, 2002 Borland Software Corporation

#if !defined(SYSCURR_H)		// currency type
#define SYSCURR_H

#if !defined(SystemHPP)
#error Do not include this file directly.  Include 'system.hpp'.
#endif

#if !defined(SYSMAC_H)
#include <sysmac.h>
#endif
#if !defined(DSTRING_H)
#include <dstring.h>
#endif
#if !defined(WSTRING_H)
#include <wstring.h>
#endif

#pragma option push -w-inl -w-lvc

namespace System
{
	class RTL_DELPHIRETURN CurrencyBase
	{
	public:
	  __int64 Val;
	};

	class RTL_DELPHIRETURN Currency : public CurrencyBase
	{
	  friend Currency __fastcall operator +(int lhs, const Currency& rhs);
	  friend Currency __fastcall operator -(int lhs, const Currency& rhs);
	  friend Currency __fastcall operator *(int lhs, const Currency& rhs);
	  friend Currency __fastcall operator /(int lhs, const Currency& rhs);
	  friend Currency __fastcall operator +(double lhs, const Currency& rhs);
	  friend Currency __fastcall operator -(double lhs, const Currency& rhs);
	  friend Currency __fastcall operator *(double lhs, const Currency& rhs);
	  friend Currency __fastcall operator /(double lhs, const Currency& rhs);
	public:
	  __fastcall Currency()                        {Val = 0;}
	  __fastcall Currency(double val)              {Val = _roundToInt64(10000 * val);}
	  __fastcall Currency(int val)                 {Val = 10000*(__int64)val;}
	  __fastcall Currency(const CurrencyBase& src) {Val = src.Val;}
	  __fastcall Currency(const Currency& src)     {Val = src.Val;}
	  __fastcall Currency(const AnsiString& src);

	  Currency& __fastcall operator =(double rhs)
	  {
		Val = _roundToInt64(10000 * rhs);
		return *this;
	  }
	  Currency& __fastcall operator =(int rhs)
	  {Val = 10000*(__int64)rhs; return *this;}
	  Currency& __fastcall operator =(const CurrencyBase& rhs)
	  {Val=rhs.Val;return *this;}
	  Currency& __fastcall operator =(const Currency& rhs)
	  {Val = rhs.Val; return *this;}

	  Currency& __fastcall operator +=(const Currency& rhs)
	  {Val += rhs.Val; return *this;}
	  Currency& __fastcall operator -=(const Currency& rhs)
	  {Val -= rhs.Val; return *this;}
	  Currency& __fastcall operator *=(const Currency& rhs)
	  {Val *= rhs.Val; Val /= 10000; return *this;}
	  Currency& __fastcall operator /=(const Currency& rhs)
	  {Val *= 10000; Val /= rhs.Val; return *this;}
	  Currency& __fastcall operator %=(int rhs)
	  {Val %= 10000 * (__int64)rhs; return *this;}

	  Currency& operator ++() {Val += 10000; return *this;}
	  Currency operator ++(int) {Currency tmp(*this); Val += 10000; return tmp;}
	  Currency& operator --() {Val -= 10000; return *this;}
	  Currency operator --(int) {Currency tmp(*this); Val -= 10000; return tmp;}

	  Currency __fastcall operator +(const Currency& rhs) const
	  {Currency tmp(*this); return tmp += rhs;}
	  Currency __fastcall operator -(const Currency& rhs) const
	  {Currency tmp(*this); return tmp -= rhs;}
	  Currency __fastcall operator *(const Currency& rhs) const
	  {Currency tmp(*this); return tmp *= rhs;}
	  Currency __fastcall operator /(const Currency& rhs) const
	  {Currency tmp(*this); return tmp /= rhs;}

	  Currency __fastcall operator +(int rhs) const
	  {Currency tmp(*this); return tmp += Currency(rhs);}
	  Currency __fastcall operator -(int rhs) const
	  {Currency tmp(*this); return tmp -= Currency(rhs);}
	  Currency __fastcall operator *(int rhs) const
	  {Currency tmp(*this); return tmp *= Currency(rhs);}
	  Currency __fastcall operator /(int rhs) const
	  {Currency tmp(*this); return tmp /= Currency(rhs);}
	  Currency __fastcall operator %(int rhs) const
	  {return Currency(static_cast<int>(Val % (10000 * (__int64)rhs))) / 10000;}

	  Currency __fastcall operator +(double rhs) const
	  {Currency tmp(*this); return tmp += Currency(rhs);}
	  Currency __fastcall operator -(double rhs) const
	  {Currency tmp(*this); return tmp -= Currency(rhs);}
	  Currency __fastcall operator *(double rhs) const
	  {Currency tmp(*this); return tmp *= Currency(rhs);}
	  Currency __fastcall operator /(double rhs) const
	  {Currency tmp(*this); return tmp /= Currency(rhs);}

	  Currency __fastcall operator -() const
	  {Currency tmp(*this); tmp.Val = -(tmp.Val); return tmp;}

	  Currency __fastcall operator !() const
	  {Currency tmp(*this); tmp.Val = !(tmp.Val); return tmp;}

	  // comparisons (Currency rhs)
	  bool __fastcall operator ==(const Currency& rhs) const
	  {return Val == rhs.Val;}
	  bool __fastcall operator !=(const Currency& rhs) const
	  {return Val != rhs.Val;}
	  bool __fastcall operator >(const Currency& rhs) const
	  {return Val > rhs.Val;}
	  bool __fastcall operator <(const Currency& rhs) const
	  {return Val < rhs.Val;}
	  bool __fastcall operator >=(const Currency& rhs) const
	  {return Val >= rhs.Val;}
	  bool __fastcall operator <=(const Currency& rhs) const
	  {return Val <= rhs.Val;}

	  // comparisons (int rhs)
	  bool __fastcall operator ==(int rhs) const
	  {return Val == 10000 * (__int64)rhs;}
	  bool __fastcall operator !=(int rhs) const
	  {return Val != 10000 * (__int64)rhs;}
	  bool __fastcall operator >(int rhs) const
	  {return Val > 10000 * (__int64)rhs;}
	  bool __fastcall operator <(int rhs) const
	  {return Val < 10000 * (__int64)rhs;}
	  bool __fastcall operator >=(int rhs) const
	  {return Val >= 10000 * (__int64)rhs;}
	  bool __fastcall operator <=(int rhs) const
	  {return Val <= 10000 * (__int64)rhs;}

	  // comparisons (double rhs)
	  bool __fastcall operator ==(double rhs) const
	  {return Val == _roundToInt64(10000 * (long double)rhs);}
	  bool __fastcall operator !=(double rhs) const
	  {return Val != _roundToInt64(10000 * (long double)rhs);}
	  bool __fastcall operator >(double rhs) const
	  {return Val > _roundToInt64(10000 * (long double)rhs);}
	  bool __fastcall operator <(double rhs) const
	  {return Val < _roundToInt64(10000 * (long double)rhs);}
	  bool __fastcall operator >=(double rhs) const
	  {return Val >= _roundToInt64(10000 * (long double)rhs);}
	  bool __fastcall operator <=(double rhs) const
	  {return Val <= _roundToInt64(10000 * (long double)rhs);}

	  __fastcall operator double() const {return ((double)Val) / 10000;}
	  __fastcall operator int() const    {return (int) (Val / 10000);}
	  __fastcall operator AnsiString() const;
	};

  // Currency friends
  //
	inline Currency __fastcall operator +(int lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp += rhs;}
	inline Currency __fastcall operator -(int lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp -= rhs;}
	inline Currency __fastcall operator *(int lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp *= rhs;}
	inline Currency __fastcall operator /(int lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp /= rhs;}
	inline Currency __fastcall operator +(double lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp += rhs;}
	inline Currency __fastcall operator -(double lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp -= rhs;}
	inline Currency __fastcall operator *(double lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp *= rhs;}
	inline Currency __fastcall operator /(double lhs, const Currency& rhs)
	{Currency tmp(lhs); return tmp /= rhs;}

  // NOTE: Insertion/Extraction operators of VCL classes are only visible
  //       if VCL_IOSTREAM is defined.
  //
  #if defined(VCL_IOSTREAM)
	ostream& operator << (ostream& os, const Currency& arg);
	istream& operator >> (istream& is, Currency& arg);
  #endif

}

#pragma option pop

#endif
