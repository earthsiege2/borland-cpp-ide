// SYSTDATE.H: Pascal TDateTime support
// Copyright (c) 1997, 2002 Borland Software Corporation

#if !defined(SYSTDATE_H)
#define SYSTDATE_H

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
	class RTL_DELPHIRETURN TDateTimeBase
	{
	public:
	  double Val;
	};

	class RTL_DELPHIRETURN TDateTime : public TDateTimeBase
	{
	public:
	  // Used by TDateTime(const AnsiString& src)
	  enum TDateTimeFlag {Date, Time, DateTime};

	  static TDateTime __fastcall CurrentDate();
	  static TDateTime __fastcall CurrentTime();
	  static TDateTime __fastcall CurrentDateTime();
	  static TDateTime __fastcall FileDateToDateTime(int fileDate);

	  __fastcall TDateTime()                                  {Val = 0;}
	  __fastcall TDateTime(const TDateTimeBase& src)          {Val = src.Val;}
	  __fastcall TDateTime(const TDateTime& src)              {Val = src.Val;}
	  __fastcall TDateTime(const double src)                  {Val = src;}
	  __fastcall TDateTime(const int src)                     {Val = src;}
	  __fastcall TDateTime(const AnsiString& src, TDateTimeFlag flag = DateTime);
	  __fastcall TDateTime(unsigned short year, unsigned short month,
					  unsigned short day);
	  __fastcall TDateTime(unsigned short hour, unsigned short min,
					  unsigned short sec, unsigned short msec);

	  TDateTime& __fastcall operator =(const TDateTimeBase& rhs)
	  {Val = rhs.Val;return *this;}
	  TDateTime& __fastcall operator =(const TDateTime& rhs)
	  {Val = rhs.Val;  return *this;}
	  TDateTime& __fastcall operator =(const double rhs)
	  {Val = rhs; return *this;}
	  TDateTime& __fastcall operator =(const int rhs)
	  {Val = rhs; return *this;}

	  TDateTime& __fastcall operator +=(const TDateTimeBase& rhs)
	  {Val+=rhs.Val;return *this;}
	  TDateTime& __fastcall operator +=(const TDateTime& rhs)
	  {Val += rhs.Val; return *this;}
	  TDateTime& __fastcall operator +=(const double rhs)
	  {Val += rhs; return *this;}
	  TDateTime& __fastcall operator +=(const int rhs)
	  {Val += rhs; return *this;}

	  TDateTime& __fastcall operator -=(const TDateTimeBase& rhs)
	  {Val-=rhs.Val;return *this;}
	  TDateTime& __fastcall operator -=(const TDateTime& rhs)
	  {Val -= rhs.Val; return *this;}
	  TDateTime& __fastcall operator -=(const double rhs)
	  {Val -= rhs; return *this;}
	  TDateTime& __fastcall operator -=(const int rhs)
	  {Val -= rhs; return *this;}

	  TDateTime& operator ++() {Val++; return *this;}
	  TDateTime operator ++(int) {TDateTime tmp(*this); Val++; return tmp;}
	  TDateTime& operator --() {Val--; return *this;}
	  TDateTime operator --(int) {TDateTime tmp(*this); Val--; return tmp;}

	  TDateTime __fastcall operator +(const TDateTimeBase& rhs) const
	  {return Val+rhs.Val;}
	  TDateTime __fastcall operator +(const TDateTime& rhs) const
	  {return Val+rhs.Val;}
	  TDateTime __fastcall operator +(const double rhs) const {return Val+rhs;}
	  TDateTime __fastcall operator +(const int rhs) const {return Val+rhs;}

	  TDateTime __fastcall operator -(const TDateTimeBase& rhs) const
	  {return Val-rhs.Val;}
	  TDateTime __fastcall operator -(const TDateTime& rhs) const
	  {return Val-rhs.Val;}
	  TDateTime __fastcall operator -(const double rhs) const {return Val-rhs;}
	  TDateTime __fastcall operator -(const int rhs) const {return Val-rhs;}

	  // comparisons
	  bool __fastcall operator ==(const TDateTime& rhs) const
	  {return Val == rhs.Val;}
	  bool __fastcall operator !=(const TDateTime& rhs) const
	  {return Val != rhs.Val;}
	  bool __fastcall operator >(const TDateTime& rhs) const
	  {return Val > rhs.Val;}
	  bool __fastcall operator <(const TDateTime& rhs) const
	  {return Val < rhs.Val;}
	  bool __fastcall operator >=(const TDateTime& rhs) const
	  {return Val >= rhs.Val;}
	  bool __fastcall operator <=(const TDateTime& rhs) const
	  {return Val <= rhs.Val;}

	  __fastcall operator AnsiString() const;//<Date||Time||DateTime>String(smart)
	  AnsiString __fastcall FormatString(const AnsiString& format) const;
	  AnsiString __fastcall DateString() const;
	  AnsiString __fastcall TimeString() const;
	  AnsiString __fastcall DateTimeString() const;
	  __fastcall operator double() const {return Val;}
	  __fastcall operator int() const    {return (int)Val;}

	  int __fastcall DayOfWeek() const;
	  int __fastcall FileDate() const;
	  void __fastcall DecodeDate(unsigned short* year, unsigned short*
					 month, unsigned short* day) const;
	  void __fastcall DecodeTime(unsigned short* hour, unsigned short*
					 min, unsigned short* sec, unsigned short* msec) const;
	};

  // NOTE: Insertion/Extraction operators of VCL classes are only visible
  //       if VCL_IOSTREAM is defined.
  //
  #if defined(VCL_IOSTREAM)
	ostream& operator <<(ostream& os, const TDateTime& arg);
	istream& operator >>(istream& is, TDateTime& arg);
  #endif

}

#pragma option pop

#endif
