// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'FMTBcd.pas' rev: 6.00

#ifndef FMTBcdHPP
#define FMTBcdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Fmtbcd
{
//-- type declarations -------------------------------------------------------
struct TBcd;
typedef TBcd *PBcd;

#pragma pack(push, 1)
struct TBcd
{
	Byte Precision;
	Byte SignSpecialPlaces;
	Byte Fraction[32];
} ;
#pragma pack(pop)

class DELPHICLASS EBcdException;
class PASCALIMPLEMENTATION EBcdException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EBcdException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EBcdException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EBcdException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EBcdException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EBcdException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EBcdException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EBcdException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EBcdException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EBcdException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EBcdOverflowException;
class PASCALIMPLEMENTATION EBcdOverflowException : public EBcdException 
{
	typedef EBcdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EBcdOverflowException(const AnsiString Msg) : EBcdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EBcdOverflowException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EBcdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EBcdOverflowException(int Ident)/* overload */ : EBcdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EBcdOverflowException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EBcdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EBcdOverflowException(const AnsiString Msg, int AHelpContext) : EBcdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EBcdOverflowException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EBcdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EBcdOverflowException(int Ident, int AHelpContext)/* overload */ : EBcdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EBcdOverflowException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EBcdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EBcdOverflowException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint MaxStringDigits = 0x64;
static const short _NoDecimal = 0xffffff01;
static const Shortint _DefaultDecimals = 0xa;
static const Shortint MaxFMTBcdFractionSize = 0x40;
static const Shortint MaxFMTBcdDigits = 0x20;
static const Shortint DefaultFMTBcdScale = 0x6;
static const Shortint MaxBcdPrecision = 0x12;
static const Shortint MaxBcdScale = 0x4;
extern PACKAGE TBcd NullBcd;
extern PACKAGE Variant __fastcall VarFMTBcdCreate(const AnsiString AValue, Word Precision, Word Scale)/* overload */;
extern PACKAGE Variant __fastcall VarFMTBcdCreate(const double AValue, Word Precision = (Word)(0x12), Word Scale = (Word)(0x4))/* overload */;
extern PACKAGE void __fastcall VarFMTBcdCreate(Variant &ADest, const TBcd &ABcd)/* overload */;
extern PACKAGE Variant __fastcall VarFMTBcdCreate()/* overload */;
extern PACKAGE Variant __fastcall VarFMTBcdCreate(const TBcd &ABcd)/* overload */;
extern PACKAGE bool __fastcall VarIsFMTBcd(const Variant &AValue)/* overload */;
extern PACKAGE Word __fastcall VarFMTBcd(void);
extern PACKAGE TBcd __fastcall StrToBcd(const AnsiString AValue);
extern PACKAGE void __fastcall DoubleToBcd(const double AValue, TBcd &bcd)/* overload */;
extern PACKAGE TBcd __fastcall DoubleToBcd(const double AValue)/* overload */;
extern PACKAGE TBcd __fastcall VarToBcd(const Variant &AValue);
extern PACKAGE TBcd __fastcall IntegerToBcd(const int AValue);
extern PACKAGE double __fastcall BcdToDouble(const TBcd &Bcd);
extern PACKAGE int __fastcall BcdToInteger(const TBcd &Bcd, bool Truncate = false);
extern PACKAGE bool __fastcall TryStrToBcd(const AnsiString AValue, TBcd &Bcd);
extern PACKAGE bool __fastcall NormalizeBcd(const TBcd &InBcd, TBcd &OutBcd, const Word Prec, const Word Scale);
extern PACKAGE int __fastcall BcdCompare(const TBcd &bcd1, const TBcd &bcd2);
extern PACKAGE void __fastcall BcdSubtract(const TBcd &bcdIn1, const TBcd &bcdIn2, TBcd &bcdOut);
extern PACKAGE void __fastcall BcdMultiply(AnsiString StringIn1, AnsiString StringIn2, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdMultiply(const TBcd &bcdIn1, const TBcd &bcdIn2, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdMultiply(const TBcd &bcdIn, const double DoubleIn, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdMultiply(const TBcd &bcdIn, const AnsiString StringIn, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdDivide(AnsiString Dividend, AnsiString Divisor, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdDivide(const TBcd &Dividend, const TBcd &Divisor, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdDivide(const TBcd &Dividend, const double Divisor, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdDivide(const TBcd &Dividend, const AnsiString Divisor, TBcd &bcdOut)/* overload */;
extern PACKAGE void __fastcall BcdAdd(const TBcd &bcdIn1, const TBcd &bcdIn2, TBcd &bcdOut);
extern PACKAGE AnsiString __fastcall BcdToStr(const TBcd &Bcd)/* overload */;
extern PACKAGE Word __fastcall BcdPrecision(const TBcd &Bcd);
extern PACKAGE Word __fastcall BcdScale(const TBcd &Bcd);
extern PACKAGE bool __fastcall IsBcdNegative(const TBcd &Bcd);
extern PACKAGE bool __fastcall CurrToBCD(const System::Currency Curr, TBcd &BCD, int Precision = 0x20, int Decimals = 0x4);
extern PACKAGE bool __fastcall BCDToCurr(const TBcd &BCD, System::Currency &Curr);
extern PACKAGE AnsiString __fastcall BcdToStrF(const TBcd &Bcd, Sysutils::TFloatFormat Format, const int Precision, const int Digits);
extern PACKAGE AnsiString __fastcall FormatBcd(const AnsiString Format, const TBcd &Bcd);

}	/* namespace Fmtbcd */
using namespace Fmtbcd;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FMTBcd
