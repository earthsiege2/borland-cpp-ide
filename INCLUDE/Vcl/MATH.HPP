// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Math.pas' rev: 5.00

#ifndef MathHPP
#define MathHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Math
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TPaymentTime { ptEndOfPeriod, ptStartOfPeriod };
#pragma option pop

class DELPHICLASS EInvalidArgument;
class PASCALIMPLEMENTATION EInvalidArgument : public Sysutils::EMathError 
{
	typedef Sysutils::EMathError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidArgument(const AnsiString Msg) : Sysutils::EMathError(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidArgument(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::EMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidArgument(int Ident)/* overload */ : Sysutils::EMathError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidArgument(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : Sysutils::EMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidArgument(const AnsiString Msg, int AHelpContext
		) : Sysutils::EMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidArgument(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::EMathError(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidArgument(int Ident, int AHelpContext)/* overload */
		 : Sysutils::EMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidArgument(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EMathError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidArgument(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Extended MinSingle = 1.500000E-45;
static const Extended MaxSingle = 3.400000E+38;
static const Extended MinDouble = 5.000000E-324;
static const Extended MaxDouble = 1.700000E+308;
static const Extended MinExtended = 3.400000E-4932;
static const Extended MaxExtended = 1.100000E+4932;
static const Extended MinComp = -9.223372E+18;
static const Extended MaxComp = 9.223372E+18;
extern PACKAGE Extended __fastcall DegToRad(Extended Degrees);
extern PACKAGE Extended __fastcall RadToDeg(Extended Radians);
extern PACKAGE Extended __fastcall GradToRad(Extended Grads);
extern PACKAGE Extended __fastcall RadToGrad(Extended Radians);
extern PACKAGE Extended __fastcall CycleToRad(Extended Cycles);
extern PACKAGE Extended __fastcall RadToCycle(Extended Radians);
extern PACKAGE Extended __fastcall LnXP1(Extended X);
extern PACKAGE Extended __fastcall IntPower(Extended Base, int Exponent);
extern PACKAGE Extended __fastcall ArcCos(Extended X);
extern PACKAGE Extended __fastcall ArcSin(Extended X);
extern PACKAGE Extended __fastcall ArcTan2(Extended Y, Extended X);
extern PACKAGE Extended __fastcall Tan(Extended X);
extern PACKAGE Extended __fastcall Cotan(Extended X);
extern PACKAGE Extended __fastcall Hypot(Extended X, Extended Y);
extern PACKAGE void __fastcall SinCos(Extended Theta, Extended &Sin, Extended &Cos);
extern PACKAGE void __fastcall Frexp(Extended X, Extended &Mantissa, int &Exponent);
extern PACKAGE Extended __fastcall Ldexp(Extended X, int P);
extern PACKAGE int __fastcall Ceil(Extended X);
extern PACKAGE int __fastcall Floor(Extended X);
extern PACKAGE Extended __fastcall Log10(Extended X);
extern PACKAGE Extended __fastcall Log2(Extended X);
extern PACKAGE Extended __fastcall LogN(Extended Base, Extended X);
extern PACKAGE Extended __fastcall Poly(Extended X, const double * Coefficients, const int Coefficients_Size
	);
extern PACKAGE Extended __fastcall Power(Extended Base, Extended Exponent);
extern PACKAGE Extended __fastcall Cosh(Extended X);
extern PACKAGE Extended __fastcall Sinh(Extended X);
extern PACKAGE Extended __fastcall Tanh(Extended X);
extern PACKAGE Extended __fastcall ArcCosh(Extended X);
extern PACKAGE Extended __fastcall ArcSinh(Extended X);
extern PACKAGE Extended __fastcall ArcTanh(Extended X);
extern PACKAGE Extended __fastcall Mean(const double * Data, const int Data_Size);
extern PACKAGE double __fastcall MinValue(const double * Data, const int Data_Size);
extern PACKAGE int __fastcall MinIntValue(const int * Data, const int Data_Size);
extern PACKAGE int __fastcall Min(int A, int B)/* overload */;
extern PACKAGE __int64 __fastcall Min(__int64 A, __int64 B)/* overload */;
extern PACKAGE float __fastcall Min(float A, float B)/* overload */;
extern PACKAGE double __fastcall Min(double A, double B)/* overload */;
extern PACKAGE Extended __fastcall Min(Extended A, Extended B)/* overload */;
extern PACKAGE double __fastcall MaxValue(const double * Data, const int Data_Size);
extern PACKAGE int __fastcall MaxIntValue(const int * Data, const int Data_Size);
extern PACKAGE int __fastcall Max(int A, int B)/* overload */;
extern PACKAGE __int64 __fastcall Max(__int64 A, __int64 B)/* overload */;
extern PACKAGE float __fastcall Max(float A, float B)/* overload */;
extern PACKAGE double __fastcall Max(double A, double B)/* overload */;
extern PACKAGE Extended __fastcall Max(Extended A, Extended B)/* overload */;
extern PACKAGE void __fastcall MeanAndStdDev(const double * Data, const int Data_Size, Extended &Mean
	, Extended &StdDev);
extern PACKAGE void __fastcall MomentSkewKurtosis(const double * Data, const int Data_Size, Extended 
	&M1, Extended &M2, Extended &M3, Extended &M4, Extended &Skew, Extended &Kurtosis);
extern PACKAGE Extended __fastcall Norm(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall PopnStdDev(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall PopnVariance(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall RandG(Extended Mean, Extended StdDev);
extern PACKAGE Extended __fastcall StdDev(const double * Data, const int Data_Size);
extern PACKAGE int __fastcall SumInt(const int * Data, const int Data_Size);
extern PACKAGE Extended __fastcall Sum(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall SumOfSquares(const double * Data, const int Data_Size);
extern PACKAGE void __fastcall SumsAndSquares(const double * Data, const int Data_Size, Extended &Sum
	, Extended &SumOfSquares);
extern PACKAGE Extended __fastcall TotalVariance(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall Variance(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall DoubleDecliningBalance(Extended Cost, Extended Salvage, int Life, 
	int Period);
extern PACKAGE Extended __fastcall SLNDepreciation(Extended Cost, Extended Salvage, int Life);
extern PACKAGE Extended __fastcall SYDDepreciation(Extended Cost, Extended Salvage, int Life, int Period
	);
extern PACKAGE Extended __fastcall InternalRateOfReturn(Extended Guess, const double * CashFlows, const 
	int CashFlows_Size);
extern PACKAGE Extended __fastcall NetPresentValue(Extended Rate, const double * CashFlows, const int 
	CashFlows_Size, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall FutureValue(Extended Rate, int NPeriods, Extended Payment, Extended 
	PresentValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall InterestPayment(Extended Rate, int Period, int NPeriods, Extended 
	PresentValue, Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall InterestRate(int NPeriods, Extended Payment, Extended PresentValue
	, Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall NumberOfPeriods(Extended Rate, Extended Payment, Extended PresentValue
	, Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall Payment(Extended Rate, int NPeriods, Extended PresentValue, Extended 
	FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall PeriodPayment(Extended Rate, int Period, int NPeriods, Extended PresentValue
	, Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall PresentValue(Extended Rate, int NPeriods, Extended Payment, Extended 
	FutureValue, TPaymentTime PaymentTime);

}	/* namespace Math */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Math;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Math
