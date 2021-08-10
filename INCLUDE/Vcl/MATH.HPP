// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Math.pas' rev: 6.00

#ifndef MathHPP
#define MathHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
static const Extended NaN = 0.0 / 0.0;
static const Extended Infinity = 1.0 / 0.0;
static const Extended NegInfinity = -1.0 / 0.0;

namespace Math
{
//-- type declarations -------------------------------------------------------
typedef Shortint TValueSign;

typedef Shortint TRoundToRange;

#pragma option push -b-
enum TPaymentTime { ptEndOfPeriod, ptStartOfPeriod };
#pragma option pop

class DELPHICLASS EInvalidArgument;
class PASCALIMPLEMENTATION EInvalidArgument : public Sysutils::EMathError 
{
	typedef Sysutils::EMathError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidArgument(const AnsiString Msg) : Sysutils::EMathError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidArgument(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::EMathError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidArgument(int Ident)/* overload */ : Sysutils::EMathError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidArgument(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::EMathError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidArgument(const AnsiString Msg, int AHelpContext) : Sysutils::EMathError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidArgument(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::EMathError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidArgument(int Ident, int AHelpContext)/* overload */ : Sysutils::EMathError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidArgument(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::EMathError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidArgument(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFPURoundingMode { rmNearest, rmDown, rmUp, rmTruncate };
#pragma option pop

#pragma option push -b-
enum TFPUPrecisionMode { pmSingle, pmReserved, pmDouble, pmExtended };
#pragma option pop

#pragma option push -b-
enum TFPUException { exInvalidOp, exDenormalized, exZeroDivide, exOverflow, exUnderflow, exPrecision };
#pragma option pop

typedef Set<TFPUException, exInvalidOp, exPrecision>  TFPUExceptionMask;

//-- var, const, procedure ---------------------------------------------------
static const Extended MinSingle = 1.500000E-45;
static const Extended MaxSingle = 3.400000E+38;
static const Extended MinDouble = 5.000000E-324;
static const Extended MaxDouble = 1.700000E+308;
static const Extended MinExtended = 3.400000E-4932;
static const Extended MaxExtended = 1.100000E+4932;
static const Extended MinComp = -9.223372E+18;
static const Extended MaxComp = 9.223372E+18;
static const Shortint NegativeValue = 0xffffffff;
static const Shortint ZeroValue = 0x0;
static const Shortint PositiveValue = 0x1;
extern PACKAGE void __fastcall DivMod(int Dividend, Word Divisor, Word &Result, Word &Remainder);
extern PACKAGE double __fastcall RoundTo(const double AValue, const TRoundToRange ADigit);
extern PACKAGE double __fastcall SimpleRoundTo(const double AValue, const TRoundToRange ADigit = (TRoundToRange)(0xfffffffe));
extern PACKAGE Extended __fastcall DegToRad(const Extended Degrees);
extern PACKAGE Extended __fastcall RadToDeg(const Extended Radians);
extern PACKAGE Extended __fastcall GradToRad(const Extended Grads);
extern PACKAGE Extended __fastcall RadToGrad(const Extended Radians);
extern PACKAGE Extended __fastcall CycleToRad(const Extended Cycles);
extern PACKAGE Extended __fastcall RadToCycle(const Extended Radians);
extern PACKAGE Extended __fastcall DegToGrad(const Extended Degrees);
extern PACKAGE Extended __fastcall DegToCycle(const Extended Degrees);
extern PACKAGE Extended __fastcall GradToDeg(const Extended Grads);
extern PACKAGE Extended __fastcall GradToCycle(const Extended Grads);
extern PACKAGE Extended __fastcall CycleToDeg(const Extended Cycles);
extern PACKAGE Extended __fastcall CycleToGrad(const Extended Cycles);
extern PACKAGE Extended __fastcall LnXP1(const Extended X);
extern PACKAGE Extended __fastcall IntPower(const Extended Base, const int Exponent);
extern PACKAGE Extended __fastcall ArcCos(const Extended X);
extern PACKAGE Extended __fastcall ArcSin(const Extended X);
extern PACKAGE Extended __fastcall ArcTan2(const Extended Y, const Extended X);
extern PACKAGE Extended __fastcall Tan(const Extended X);
extern PACKAGE Extended __fastcall Cotan(const Extended X);
extern PACKAGE Extended __fastcall Secant(const Extended X);
extern PACKAGE Extended __fastcall Cosecant(const Extended X);
extern PACKAGE Extended __fastcall Hypot(const Extended X, const Extended Y);
extern PACKAGE void __fastcall SinCos(const Extended Theta, Extended &Sin, Extended &Cos);
extern PACKAGE void __fastcall Frexp(const Extended X, Extended &Mantissa, int &Exponent);
extern PACKAGE Extended __fastcall Ldexp(const Extended X, const int P);
extern PACKAGE int __fastcall Ceil(const Extended X);
extern PACKAGE int __fastcall Floor(const Extended X);
extern PACKAGE Extended __fastcall Log10(const Extended X);
extern PACKAGE Extended __fastcall Log2(const Extended X);
extern PACKAGE Extended __fastcall LogN(const Extended Base, const Extended X);
extern PACKAGE Extended __fastcall Poly(const Extended X, const double * Coefficients, const int Coefficients_Size);
extern PACKAGE Extended __fastcall Power(const Extended Base, const Extended Exponent);
extern PACKAGE Extended __fastcall Cosh(const Extended X);
extern PACKAGE Extended __fastcall Sinh(const Extended X);
extern PACKAGE Extended __fastcall Tanh(const Extended X);
extern PACKAGE Extended __fastcall ArcCosh(const Extended X);
extern PACKAGE Extended __fastcall ArcSinh(const Extended X);
extern PACKAGE Extended __fastcall ArcTanh(const Extended X);
extern PACKAGE Extended __fastcall Cot(const Extended X);
extern PACKAGE Extended __fastcall Sec(const Extended X);
extern PACKAGE Extended __fastcall Csc(const Extended X);
extern PACKAGE Extended __fastcall CotH(const Extended X);
extern PACKAGE Extended __fastcall SecH(const Extended X);
extern PACKAGE Extended __fastcall CscH(const Extended X);
extern PACKAGE Extended __fastcall ArcCot(const Extended X);
extern PACKAGE Extended __fastcall ArcSec(const Extended X);
extern PACKAGE Extended __fastcall ArcCsc(const Extended X);
extern PACKAGE Extended __fastcall ArcCotH(const Extended X);
extern PACKAGE Extended __fastcall ArcSecH(const Extended X);
extern PACKAGE Extended __fastcall ArcCscH(const Extended X);
extern PACKAGE bool __fastcall IsNan(const double AValue);
extern PACKAGE bool __fastcall IsInfinite(const double AValue);
extern PACKAGE Extended __fastcall Mean(const double * Data, const int Data_Size);
extern PACKAGE double __fastcall MinValue(const double * Data, const int Data_Size);
extern PACKAGE int __fastcall MinIntValue(const int * Data, const int Data_Size);
extern PACKAGE int __fastcall Min(const int A, const int B)/* overload */;
extern PACKAGE __int64 __fastcall Min(const __int64 A, const __int64 B)/* overload */;
extern PACKAGE float __fastcall Min(const float A, const float B)/* overload */;
extern PACKAGE double __fastcall Min(const double A, const double B)/* overload */;
extern PACKAGE Extended __fastcall Min(const Extended A, const Extended B)/* overload */;
extern PACKAGE double __fastcall MaxValue(const double * Data, const int Data_Size);
extern PACKAGE int __fastcall MaxIntValue(const int * Data, const int Data_Size);
extern PACKAGE int __fastcall Max(const int A, const int B)/* overload */;
extern PACKAGE __int64 __fastcall Max(const __int64 A, const __int64 B)/* overload */;
extern PACKAGE float __fastcall Max(const float A, const float B)/* overload */;
extern PACKAGE double __fastcall Max(const double A, const double B)/* overload */;
extern PACKAGE Extended __fastcall Max(const Extended A, const Extended B)/* overload */;
extern PACKAGE TValueSign __fastcall Sign(const int AValue)/* overload */;
extern PACKAGE TValueSign __fastcall Sign(const __int64 AValue)/* overload */;
extern PACKAGE TValueSign __fastcall Sign(const double AValue)/* overload */;
extern PACKAGE Types::TValueRelationship __fastcall CompareValue(const Extended A, const Extended B, Extended Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE Types::TValueRelationship __fastcall CompareValue(const double A, const double B, double Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE Types::TValueRelationship __fastcall CompareValue(const float A, const float B, float Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE Types::TValueRelationship __fastcall CompareValue(const int A, const int B)/* overload */;
extern PACKAGE Types::TValueRelationship __fastcall CompareValue(const __int64 A, const __int64 B)/* overload */;
extern PACKAGE bool __fastcall SameValue(const Extended A, const Extended B, Extended Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE bool __fastcall SameValue(const double A, const double B, double Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE bool __fastcall SameValue(const float A, const float B, float Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE bool __fastcall IsZero(const Extended A, Extended Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE bool __fastcall IsZero(const double A, double Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE bool __fastcall IsZero(const float A, float Epsilon = 0.000000E+00)/* overload */;
extern PACKAGE int __fastcall IfThen(bool AValue, const int ATrue, const int AFalse = 0x0)/* overload */;
extern PACKAGE __int64 __fastcall IfThen(bool AValue, const __int64 ATrue, const __int64 AFalse = 0x000000000)/* overload */;
extern PACKAGE double __fastcall IfThen(bool AValue, const double ATrue, const double AFalse = 0.000000E+00)/* overload */;
extern PACKAGE int __fastcall RandomRange(const int AFrom, const int ATo);
extern PACKAGE int __fastcall RandomFrom(const int * AValues, const int AValues_Size)/* overload */;
extern PACKAGE __int64 __fastcall RandomFrom(const __int64 * AValues, const int AValues_Size)/* overload */;
extern PACKAGE double __fastcall RandomFrom(const double * AValues, const int AValues_Size)/* overload */;
extern PACKAGE bool __fastcall InRange(const int AValue, const int AMin, const int AMax)/* overload */;
extern PACKAGE bool __fastcall InRange(const __int64 AValue, const __int64 AMin, const __int64 AMax)/* overload */;
extern PACKAGE bool __fastcall InRange(const double AValue, const double AMin, const double AMax)/* overload */;
extern PACKAGE int __fastcall EnsureRange(const int AValue, const int AMin, const int AMax)/* overload */;
extern PACKAGE __int64 __fastcall EnsureRange(const __int64 AValue, const __int64 AMin, const __int64 AMax)/* overload */;
extern PACKAGE double __fastcall EnsureRange(const double AValue, const double AMin, const double AMax)/* overload */;
extern PACKAGE void __fastcall MeanAndStdDev(const double * Data, const int Data_Size, Extended &Mean, Extended &StdDev);
extern PACKAGE void __fastcall MomentSkewKurtosis(const double * Data, const int Data_Size, Extended &M1, Extended &M2, Extended &M3, Extended &M4, Extended &Skew, Extended &Kurtosis);
extern PACKAGE Extended __fastcall Norm(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall PopnStdDev(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall PopnVariance(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall RandG(Extended Mean, Extended StdDev);
extern PACKAGE Extended __fastcall StdDev(const double * Data, const int Data_Size);
extern PACKAGE int __fastcall SumInt(const int * Data, const int Data_Size);
extern PACKAGE Extended __fastcall Sum(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall SumOfSquares(const double * Data, const int Data_Size);
extern PACKAGE void __fastcall SumsAndSquares(const double * Data, const int Data_Size, Extended &Sum, Extended &SumOfSquares);
extern PACKAGE Extended __fastcall TotalVariance(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall Variance(const double * Data, const int Data_Size);
extern PACKAGE Extended __fastcall DoubleDecliningBalance(const Extended Cost, const Extended Salvage, int Life, int Period);
extern PACKAGE Extended __fastcall SLNDepreciation(const Extended Cost, const Extended Salvage, int Life);
extern PACKAGE Extended __fastcall SYDDepreciation(const Extended Cost, const Extended Salvage, int Life, int Period);
extern PACKAGE Extended __fastcall InternalRateOfReturn(const Extended Guess, const double * CashFlows, const int CashFlows_Size);
extern PACKAGE Extended __fastcall NetPresentValue(const Extended Rate, const double * CashFlows, const int CashFlows_Size, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall FutureValue(const Extended Rate, int NPeriods, const Extended Payment, const Extended PresentValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall InterestPayment(const Extended Rate, int Period, int NPeriods, const Extended PresentValue, const Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall InterestRate(int NPeriods, const Extended Payment, const Extended PresentValue, const Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall NumberOfPeriods(const Extended Rate, Extended Payment, const Extended PresentValue, const Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall Payment(Extended Rate, int NPeriods, const Extended PresentValue, const Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall PeriodPayment(const Extended Rate, int Period, int NPeriods, const Extended PresentValue, const Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE Extended __fastcall PresentValue(const Extended Rate, int NPeriods, const Extended Payment, const Extended FutureValue, TPaymentTime PaymentTime);
extern PACKAGE TFPURoundingMode __fastcall GetRoundMode(void);
extern PACKAGE TFPURoundingMode __fastcall SetRoundMode(const TFPURoundingMode RoundMode);
extern PACKAGE TFPUPrecisionMode __fastcall GetPrecisionMode(void);
extern PACKAGE TFPUPrecisionMode __fastcall SetPrecisionMode(const TFPUPrecisionMode Precision);
extern PACKAGE TFPUExceptionMask __fastcall GetExceptionMask(void);
extern PACKAGE TFPUExceptionMask __fastcall SetExceptionMask(const TFPUExceptionMask Mask);
extern PACKAGE void __fastcall ClearExceptions(void);

}	/* namespace Math */
using namespace Math;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Math
