// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'XSBuiltIns.pas' rev: 6.00

#ifndef XSBuiltInsHPP
#define XSBuiltInsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <FMTBcd.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xsbuiltins
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TXSTime;
class PASCALIMPLEMENTATION TXSTime : public Invokeregistry::TRemotableXS 
{
	typedef Invokeregistry::TRemotableXS inherited;
	
private:
	AnsiString FFractionalSecondString;
	Word FHour;
	short FHourOffset;
	Word FMinute;
	short FMinuteOffset;
	bool FNegativeOffset;
	Word FSecond;
	bool FUseZeroMilliseconds;
	WideString __fastcall BuildHourOffset();
	AnsiString __fastcall IntToFractionalSeconds(Word Value);
	
protected:
	System::TDateTime __fastcall GetAsTime(void);
	double __fastcall GetFractionalSeconds(void);
	AnsiString __fastcall GetFractionalSecondString();
	short __fastcall GetHourOffset(void);
	Word __fastcall GetMillisecond(void);
	short __fastcall GetMinuteOffset(void);
	void __fastcall SetAsTime(System::TDateTime Value);
	void __fastcall SetFractionalSeconds(double Value);
	void __fastcall SetHour(const Word Value);
	void __fastcall SetHourOffset(const short Value);
	void __fastcall SetMillisecond(const Word Value);
	void __fastcall SetMinute(const Word Value);
	void __fastcall SetMinuteOffset(const short Value);
	void __fastcall SetSecond(const Word Value);
	__property AnsiString FractionalSecondString = {read=GetFractionalSecondString};
	
public:
	__property System::TDateTime AsTime = {read=GetAsTime, write=SetAsTime};
	__property double FractionalSeconds = {read=GetFractionalSeconds, write=SetFractionalSeconds};
	__property Word Hour = {read=FHour, write=SetHour, default=0};
	__property short HourOffset = {read=GetHourOffset, write=SetHourOffset, default=0};
	__property Word Millisecond = {read=GetMillisecond, write=SetMillisecond, default=0};
	__property Word Minute = {read=FMinute, write=SetMinute, default=0};
	__property short MinuteOffset = {read=GetMinuteOffset, write=SetMinuteOffset, nodefault};
	__property Word Second = {read=FSecond, write=SetSecond, default=0};
	__property bool UseZeroMilliseconds = {read=FUseZeroMilliseconds, write=FUseZeroMilliseconds, nodefault};
	TXSTime* __fastcall Clone(void);
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
public:
	#pragma option push -w-inl
	/* TRemotable.Create */ inline __fastcall virtual TXSTime(void) : Invokeregistry::TRemotableXS() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TXSTime(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXSDate;
class PASCALIMPLEMENTATION TXSDate : public Invokeregistry::TRemotableXS 
{
	typedef Invokeregistry::TRemotableXS inherited;
	
private:
	Word FAdditionalYearDigits;
	Word FMonth;
	Word FDay;
	int FYear;
	Word FMaxDay;
	Word FMaxMonth;
	Word FMinDay;
	Word FMinMonth;
	bool FNegativeDate;
	
protected:
	System::TDateTime __fastcall GetAsDate(void);
	int __fastcall GetYear(void);
	void __fastcall SetAsDate(System::TDateTime Value);
	void __fastcall SetMonth(const Word Value);
	void __fastcall SetDay(const Word Value);
	void __fastcall SetYear(const int Value);
	__property Word MaxDay = {read=FMaxDay, write=FMaxDay, nodefault};
	__property Word MaxMonth = {read=FMaxMonth, write=FMaxMonth, nodefault};
	__property Word MinDay = {read=FMinDay, write=FMinDay, nodefault};
	__property Word MinMonth = {read=FMinMonth, write=FMinMonth, nodefault};
	
public:
	__fastcall virtual TXSDate(void);
	__property Word Month = {read=FMonth, write=SetMonth, default=0};
	__property Word Day = {read=FDay, write=SetDay, default=0};
	__property int Year = {read=GetYear, write=SetYear, default=0};
	TXSDate* __fastcall Clone(void);
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
	__property System::TDateTime AsDate = {read=GetAsDate, write=SetAsDate};
public:
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TXSDate(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXSCustomDateTime;
class PASCALIMPLEMENTATION TXSCustomDateTime : public Invokeregistry::TRemotableXS 
{
	typedef Invokeregistry::TRemotableXS inherited;
	
private:
	TXSDate* FDateParam;
	TXSTime* FTimeParam;
	void __fastcall SetUseZeroMilliseconds(bool Value);
	bool __fastcall GetUseZeroMilliseconds(void);
	
protected:
	System::TDateTime __fastcall GetAsDateTime(void);
	Word __fastcall GetDay(void);
	double __fastcall GetFractionalSeconds(void);
	Word __fastcall GetHour(void);
	short __fastcall GetHourOffset(void);
	Word __fastcall GetMonth(void);
	Word __fastcall GetMillisecond(void);
	Word __fastcall GetMinute(void);
	short __fastcall GetMinuteOffset(void);
	Word __fastcall GetSecond(void);
	int __fastcall GetYear(void);
	void __fastcall SetAsDateTime(System::TDateTime Value);
	void __fastcall SetFractionalSeconds(double Value);
	virtual void __fastcall SetDay(const Word Value);
	virtual void __fastcall SetHour(const Word Value);
	virtual void __fastcall SetHourOffset(const short Value);
	virtual void __fastcall SetMillisecond(const Word Value);
	virtual void __fastcall SetMinute(const Word Value);
	virtual void __fastcall SetMinuteOffset(const short Value);
	virtual void __fastcall SetMonth(const Word Value);
	virtual void __fastcall SetSecond(const Word Value);
	virtual void __fastcall SetYear(const int Value);
	__property Word Millisecond = {read=GetMillisecond, write=SetMillisecond, default=0};
	
public:
	__fastcall virtual TXSCustomDateTime(void);
	__fastcall virtual ~TXSCustomDateTime(void);
	__property System::TDateTime AsDateTime = {read=GetAsDateTime, write=SetAsDateTime};
	__property Word Hour = {read=GetHour, write=SetHour, default=0};
	__property Word Minute = {read=GetMinute, write=SetMinute, default=0};
	__property Word Second = {read=GetSecond, write=SetSecond, default=0};
	__property Word Month = {read=GetMonth, write=SetMonth, default=0};
	__property Word Day = {read=GetDay, write=SetDay, default=0};
	__property int Year = {read=GetYear, write=SetYear, default=0};
	__property bool UseZeroMilliseconds = {read=GetUseZeroMilliseconds, write=SetUseZeroMilliseconds, nodefault};
};


class DELPHICLASS TXSDateTime;
class DELPHICLASS TXSDuration;
class PASCALIMPLEMENTATION TXSDateTime : public TXSCustomDateTime 
{
	typedef TXSCustomDateTime inherited;
	
private:
	int __fastcall ValidValue(int Value, int Subtract, int Min, int Max, int &Remainder);
	
public:
	TXSDuration* __fastcall CompareDateTimeParam(const TXSDateTime* Value1, const TXSDateTime* Value2);
	TXSDateTime* __fastcall Clone(void);
	__property Word Millisecond = {read=GetMillisecond, write=SetMillisecond, default=0};
	__property short HourOffset = {read=GetHourOffset, write=SetHourOffset, default=0};
	__property short MinuteOffset = {read=GetMinuteOffset, write=SetMinuteOffset, default=0};
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
public:
	#pragma option push -w-inl
	/* TXSCustomDateTime.Create */ inline __fastcall virtual TXSDateTime(void) : TXSCustomDateTime() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TXSCustomDateTime.Destroy */ inline __fastcall virtual ~TXSDateTime(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXSDuration : public TXSCustomDateTime 
{
	typedef TXSCustomDateTime inherited;
	
private:
	double FDecimalSecond;
	double __fastcall GetDecimalValue(const AnsiString AParam, const AnsiString AType);
	int __fastcall GetIntegerValue(const AnsiString AParam, const AnsiString AType);
	WideString __fastcall GetNumericString(const AnsiString AParam, const AnsiString AType, const bool Decimals = false);
	
protected:
	void __fastcall SetDecimalSecond(const double Value);
	
public:
	__fastcall virtual TXSDuration(void);
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
	__property double DecimalSecond = {read=FDecimalSecond, write=SetDecimalSecond};
public:
	#pragma option push -w-inl
	/* TXSCustomDateTime.Destroy */ inline __fastcall virtual ~TXSDuration(void) { }
	#pragma option pop
	
};


class DELPHICLASS EXSDateTimeException;
class PASCALIMPLEMENTATION EXSDateTimeException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EXSDateTimeException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EXSDateTimeException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EXSDateTimeException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EXSDateTimeException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EXSDateTimeException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EXSDateTimeException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EXSDateTimeException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EXSDateTimeException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EXSDateTimeException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EXSDecimalException;
class PASCALIMPLEMENTATION EXSDecimalException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EXSDecimalException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EXSDecimalException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EXSDecimalException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EXSDecimalException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EXSDecimalException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EXSDecimalException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EXSDecimalException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EXSDecimalException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EXSDecimalException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EXSHexBinaryException;
class PASCALIMPLEMENTATION EXSHexBinaryException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EXSHexBinaryException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EXSHexBinaryException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EXSHexBinaryException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EXSHexBinaryException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EXSHexBinaryException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EXSHexBinaryException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EXSHexBinaryException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EXSHexBinaryException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EXSHexBinaryException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXSHexBinary;
class PASCALIMPLEMENTATION TXSHexBinary : public Invokeregistry::TRemotableXS 
{
	typedef Invokeregistry::TRemotableXS inherited;
	
private:
	AnsiString FHexBinaryString;
	void __fastcall SetAsByteArray(TByteDynArray Value);
	TByteDynArray __fastcall GetAsByteArray();
	
public:
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
	__property AnsiString HexBinaryString = {read=FHexBinaryString, write=FHexBinaryString};
	__property TByteDynArray AsByteArray = {read=GetAsByteArray, write=SetAsByteArray};
public:
	#pragma option push -w-inl
	/* TRemotable.Create */ inline __fastcall virtual TXSHexBinary(void) : Invokeregistry::TRemotableXS() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TXSHexBinary(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXSDecimal;
class PASCALIMPLEMENTATION TXSDecimal : public Invokeregistry::TRemotableXS 
{
	typedef Invokeregistry::TRemotableXS inherited;
	
private:
	AnsiString FDecimalString;
	Fmtbcd::TBcd __fastcall GetAsBcd();
	void __fastcall SetAsBcd(const Fmtbcd::TBcd &Value);
	
public:
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
	__property AnsiString DecimalString = {read=FDecimalString, write=FDecimalString};
	__property Fmtbcd::TBcd AsBcd = {read=GetAsBcd, write=SetAsBcd};
public:
	#pragma option push -w-inl
	/* TRemotable.Create */ inline __fastcall virtual TXSDecimal(void) : Invokeregistry::TRemotableXS() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TXSDecimal(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXSString;
class PASCALIMPLEMENTATION TXSString : public Invokeregistry::TRemotableXS 
{
	typedef Invokeregistry::TRemotableXS inherited;
	
private:
	WideString FString;
	
public:
	virtual void __fastcall XSToNative(WideString Value);
	virtual WideString __fastcall NativeToXS();
public:
	#pragma option push -w-inl
	/* TRemotable.Create */ inline __fastcall virtual TXSString(void) : Invokeregistry::TRemotableXS() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TRemotable.Destroy */ inline __fastcall virtual ~TXSString(void) { }
	#pragma option pop
	
};


typedef TXSDateTime TXSTimeInstant;
;

//-- var, const, procedure ---------------------------------------------------
static const char SHexMarker = '\x24';
static const char SoapTimePrefix = '\x54';
static const char XMLDateSeparator = '\x2d';
static const char XMLHourOffsetMinusMarker = '\x2d';
static const char XMLHourOffsetPlusMarker = '\x2b';
static const char XMLTimeSeparator = '\x3a';
static const Shortint XMLMonthPos = 0x6;
static const Shortint XMLDayPos = 0x9;
static const Shortint XMLYearPos = 0x1;
static const Shortint XMLMilSecPos = 0xa;
static const Shortint XMLDefaultYearDigits = 0x4;
static const char XMLDurationStart = '\x50';
static const char XMLDurationYear = '\x59';
static const char XMLDurationMonth = '\x4d';
static const char XMLDurationDay = '\x44';
static const char XMLDurationHour = '\x48';
static const char XMLDurationMinute = '\x4d';
static const char XMLDurationSecond = '\x53';
#define SNAN "NAN"
extern PACKAGE char SSciNotationMarker;
extern PACKAGE char SDecimal;
extern PACKAGE char SNegative;
extern PACKAGE char SPlus;
extern PACKAGE TXSDateTime* __fastcall DateTimeToXSDateTime(System::TDateTime Value, bool CalcLocalBias = false);

}	/* namespace Xsbuiltins */
using namespace Xsbuiltins;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// XSBuiltIns
