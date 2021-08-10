#include <limits.h>
#include <float.h>
#include <fastmath.h>

#define _FMAPI_ASM __declspec(naked) _RTLENTRY /* Fast Math API in Assembly */

#pragma inline // Inform the compiler that this file contains assembly

#pragma option push -O2 -w-rvl -w-par // force fast code optimizations and
                                      // disable some pesky warnings

extern "C" {

//-------------------------------------------------------------------------
// Some internal helper functions:
static long double _FMAPI cosh_sinhl(long double x, double factor);
static long double _FMAPI_ASM lnxp1(long double x);


//-------------------------------------------------------------------------
// _fm_init can be called to mask all fpu exceptions prior to using the
//  FastMath routines.
unsigned int _FMAPI _fm_init(void)
{
    //Disable all fpu exceptions, and return the old control word
    return _control87(MCW_EM, EM_INVALID  | EM_DENORMAL  | EM_ZERODIVIDE |
                              EM_OVERFLOW | EM_UNDERFLOW | EM_INEXACT );
}

//-------------------------------------------------------------------------
// double value routines:
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_sin(double x)
{
    asm {
        FLD       qword ptr [esp+04h]
        FSIN
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_cos(double x)
{
    asm {
        FLD       qword ptr [esp+04h]
        FCOS
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_tan(double x)
{
    asm {
        FLD       qword ptr [esp+04h]
        FPTAN
        FSTP                ST(0)        // FPTAN pushes an extra 1.0 after
                                         // result
        RET
    }
}
//-------------------------------------------------------------------------
void _FMAPI_ASM _fm_sincos(double a, double *x, double *y)
{
    asm{
        FLD       qword ptr [esp+04h]    // (a) the angle
        FSINCOS
        MOV                 eax,[esp+10h]// (y) load the address for cosine
        FSTP      qword ptr [eax]        // store it
        MOV                 eax,[esp+0Ch]// (x) load the address for sine
        FSTP      qword ptr [eax]        // store it
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI _fm_acos(double x)
{
    return _fm_atan2(_fm_sqrt(1 - x*x), x);
};
//-------------------------------------------------------------------------
double _FMAPI _fm_asin(double x)
{
    return _fm_atan2(x, _fm_sqrt(1 - x*x));
};
//-------------------------------------------------------------------------
double _FMAPI _fm_atan(double x)
{
    return _fm_atan2(x, 1);
};
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_atan2(double y, double x)
{
    asm {
        FLD       qword ptr [esp+04h]    // load y
        FLD       qword ptr [esp+0Ch]    // load x
        FPATAN
        RET
    }
};
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_exp(double x)
{
    // e**x = 2**(x*log2(e))
    asm {
        FLD       qword ptr [esp+04h]    // load x
        FLDL2E                           // y := x*log2e;
        FMUL
        FLD                 ST(0)        // i := round(y);
        FRNDINT
        FSUB                ST(1), ST    // f := y - i;
        FXCH                ST(1)        // z := 2**f
        F2XM1
        FLD1
        FADD
        FSCALE                           // result := z * 2**i
        FSTP                ST(1)
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_ldexp(double x, int p)
{
  // Result = x * (2**p)
    asm {
        FILD      dword ptr [esp+0Ch]    // load p as an integer
        FLD       qword ptr [esp+04h]    // load x
        FSCALE                           // ST = ST * 2**ST(1)
        FSTP                ST(1)        // ST -> ST(1), pop ST
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_sqrt(double x)
{
    asm {
        FLD       qword ptr [esp+04h]
        FSQRT
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_log(double x)
{
    // Log (x) = Log (2) * Log2 (x)
    asm {
        FLD       qword ptr [esp+04h]    // load x
        FLDLN2                           // y = log(2)
        FXCH                ST(1)        // flip the parameters
        FYL2X                            // compute y * log2(x)
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_log10(double x)
{
    // Log10 (x) = Log10 (2) * Log2 (x)
    asm {
        FLD       qword ptr [esp+04h]    // load x
        FLDLG2                           // y = log10(2)
        FXCH                ST(1)        // flip the parameters
        FYL2X                            // compute y * log2(x)
        RET
    }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_fabs(double x)
{
    asm {
        FLD       qword ptr [esp+04h]    // load x
        FABS                             // change sign to +
        RET
    }
}
//-------------------------------------------------------------------------
// Hyperbolic functions:
//-------------------------------------------------------------------------
double _FMAPI _fm_cosh(double x)
{
  return (double)cosh_sinhl(x, 0.25);
}
//-------------------------------------------------------------------------
double _FMAPI _fm_sinh(double x)
{
  return (double)cosh_sinhl(x, -0.25);
}
//-------------------------------------------------------------------------
double _FMAPI _fm_tanh(double x)
{
  const double MaxTanhDomain = 5678.22249441322;
  long double result;

  if (x > MaxTanhDomain)
    result = 1.0;
  else if (x < -MaxTanhDomain)
    result = -1.0;
  else
  {
    result = exp(x);
    result = result * result;
    result = (result - 1.0) / (result + 1.0);
  }
  return result;
}
//-------------------------------------------------------------------------
double _FMAPI _fm_acosh(double x)
{
  double result;

  if (x <= 1.0)
    result = 0.0;
  else if (x > 1.0e10)
    result = _fm_log(2) + _fm_log(x);
  else
    result = _fm_log(x + _fm_sqrt((x - 1.0) * (x + 1.0)));

  return result;
}
//-------------------------------------------------------------------------
double _FMAPI _fm_asinh(double x)
{
  bool Neg;
  double result;

  if (x == 0)
    result = 0;
  else
  {
    Neg = (x < 0);
    x = _fm_fabs(x);
    if (x > 1.0e10)
      result = _fm_log(2) + _fm_log(x);
    else
    {
      result = x*x;
      result = lnxp1(x + result / (1 + _fm_sqrt(1 + result)));
    }
    if (Neg)
      result = -result;
  }
  return result;
}
//-------------------------------------------------------------------------
double _FMAPI _fm_atanh(double x)
{
  bool Neg;
  double result;

  if (x == 0)
    result = 0;
  else
  {
    Neg = (x < 0);
    x = fabs(x);
    if (x >= 1)
      result = DBL_MAX;
    else
      result = 0.5 * lnxp1((2.0 * x) / (1.0 - x));
    if (Neg)
      result = -result;
  }
  return result;
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_frexp(double x,int *exponent)
{
    asm {
        // Put the exponent ptr in edx
        MOV                 edx,[esp+0Ch]// exponent

        FLD       qword ptr [esp+04h]    // x
        MOV       dword ptr [edx], 0     // if x = 0, return 0

        FTST
        FNSTSW              ax
        FWAIT
        SAHF
        JZ                  l_Done

        FXTRACT                          // ST(1) = exponent,
                                         // (pushed) ST = fraction
        FXCH

        // The FXTRACT instruction normalizes the fraction 1 bit higher than
        // wanted for the definition of frexp() so we need to tweak the
        // result by scaling the fraction down and incrementing the exponent.

        FISTP     dword ptr [edx]
        FLD1
        FCHS
        FXCH
        FSCALE                           // scale fraction
        INC       dword ptr [edx]        // exponent biased to match
        FSTP                ST(1)        // discard -1, leave fraction as TOS

   }
l_Done:
   asm {

        RET                              // mantissa is in ST(0) now
  }
}
//-------------------------------------------------------------------------
double _FMAPI_ASM _fm_hypot(double x, double y)
{
    // formula:  sqrt(x*x + y*y)
    // implemented as:  |y|*sqrt(1+sqr(x/y)), |x| < |x| for greater precision
    asm {
        FLD       qword ptr [esp+0Ch]    // y
        FABS
        FLD       qword ptr [esp+04h]    // x
        FABS
        FCOM
        FNSTSW              ax
        FWAIT
        TEST                ah,045h
        JNZ                 l_1          // if ST > ST(1) then swap
        FXCH                ST(1)        // put larger number in ST(1)
    }
l_1:
    asm {
        FLDZ
        FCOMP
        FNSTSW              ax
        FWAIT
        TEST                ah,040h      // if ST == 0, return ST(1)
        JZ                  l_2
        FSTP                ST           // eat ST(0)
        JMP                 l_3
    }
l_2:
    asm {
        FDIV                ST,ST(1)     // ST = ST / ST(1)
        FMUL                ST,ST        // ST = ST * ST
        FLD1
        FADD                             // ST = ST + 1
        FSQRT                            // ST = sqrt(ST)
        FMUL                             // ST(1) = ST * ST(1); pop ST
    }
l_3:
    asm {
        RET
    }
}
//-------------------------------------------------------------------------
// long double value routines:
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_sinl(long double x)
{
    asm {
        FLD       tbyte ptr [esp+04h]
        FSIN
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_cosl(long double x)
{
    asm {
        FLD       tbyte ptr [esp+04h]
        FCOS
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_tanl(long double x)
{
    asm {
        FLD       tbyte ptr [esp+04h]
        FPTAN
        FSTP                ST(0)        // FPTAN pushes an extra 1.0 after result
        RET
    }
}
//-------------------------------------------------------------------------
void _FMAPI_ASM _fm_sincosl(long double a, long double *x, long double *y)
{
    asm{
        FLD       tbyte ptr [esp+04h]    // (a) the angle
        FSINCOS
        MOV                 eax,[esp+14h]// (y) load the address for cosine
        FSTP      tbyte ptr [eax]        // store it
        MOV                 eax,[esp+10h]// (x) load the address for sine
        FSTP      tbyte ptr [eax]        // store it
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI _fm_acosl(long double x)
{
    return _fm_atan2l(_fm_sqrt(1 - x*x), x);
};
//-------------------------------------------------------------------------
long double _FMAPI _fm_asinl(long double x)
{
    return _fm_atan2l(x, _fm_sqrt(1 - x*x));
};
//-------------------------------------------------------------------------
long double _FMAPI _fm_atanl(long double x)
{
    return _fm_atan2l(x, 1);
};
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_atan2l(long double y, long double x)
{
    asm {
        FLD       tbyte ptr [esp+04h]    // load y
        FLD       tbyte ptr [esp+10h]    // load x
        FPATAN
        RET
    }
};
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_expl(long double x)
{
    //       e**x = 2**(x*log2(e))
    asm{

        FLD       tbyte ptr [esp+04h]    // load x
        FLDL2E                           // y = x*log2e;
        FMUL
        FLD                 ST(0)        // i = round(y);
        FRNDINT
        FSUB                ST(1),ST     // f = y - i;
        FXCH                ST(1)        // z = 2**f
        F2XM1
        FLD1
        FADD
        FSCALE                           // result = z * 2**i
        FSTP                ST(1)
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_ldexpl(long double x, int p)
{
  // Result = x * (2**p)
    asm {
        FILD      dword ptr [esp+10h]    // load p as an integer
        FLD       tbyte ptr [esp+04h]    // load x
        FSCALE                           // ST = ST * 2**ST(1)
        FSTP                ST(1)        // ST -> ST(1), pop ST
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_sqrtl(long double x)
{
    asm {
        FLD       tbyte ptr [esp+04h]
        FSQRT
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_logl(long double x)
{
    // Log (x) = Log (2) * Log2 (x)
    asm {
        FLD       tbyte ptr [esp+04h]    // load x
        FLDLN2                           // y = log(2)
        FXCH                ST(1)        // flip the parameters
        FYL2X                            // compute y * log2(x)
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_log10l(long double x)
{
    // Log10 (x) = Log10 (2) * Log2 (x)
    asm {
        FLD       tbyte ptr [esp+04h]    // load x
        FLDLG2                           // y = log10(2)
        FXCH                ST(1)        // flip the parameters
        FYL2X                            // compute y * log2(x)
        RET
    }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_fabsl(long double x)
{
    asm {
        FLD       tbyte ptr [esp+04h]    // load x
        FABS                             // change sign to +
        RET
    }
}
//-------------------------------------------------------------------------
// Helper function
static long double _FMAPI cosh_sinhl(long double x, double factor)
{
  long double result;

  result = _fm_expl(x) / 2;
  result = result + factor / result;

  return result;
}
//-------------------------------------------------------------------------
// Helper function
static long double _FMAPI_ASM lnxp1(long double x)
{
  // Return natural log(1 + x).  Accurate for x near 0.
    asm {  // Warning don't port this to double, leave it as long double
         FLDLN2
         MOV ax, word  ptr  [esp+04h+8]// exponent
         FLD     tbyte ptr  [esp+04h]
         CMP                ax,03FFDh  // .4225
         JB                 l_1
         FLD1
         FADD
         FYL2X
         JMP                l_2
    }
l_1:
    asm  FYL2XP1
l_2:
    asm  RET
}
//-------------------------------------------------------------------------
// Hyperbolic functions:
//-------------------------------------------------------------------------
long double _FMAPI _fm_coshl(long double x)
{
  return cosh_sinhl(x, 0.25);
}
//-------------------------------------------------------------------------
long double _FMAPI _fm_sinhl(long double x)
{
  return cosh_sinhl(x, -0.25);
}
//-------------------------------------------------------------------------
long double _FMAPI _fm_tanhl(long double x)
{
  const long double MaxTanhDomain = 5678.22249441322L; // Ln(MaxExtended)/2
  long double result;

  if (x > MaxTanhDomain)
    result = 1.0;
  else if (x < -MaxTanhDomain)
    result = -1.0;
  else
  {
    result = _fm_expl(x);
    result = result * result;
    result = (result - 1.0) / (result + 1.0);
  }
  return result;
}
//-------------------------------------------------------------------------
long double _FMAPI _fm_acoshl(long double x)
{
  long double result;

  if (x <= 1.0)
    result = 0.0;
  else if (x > 1.0e10)
    result = _fm_logl(2) + _fm_logl(x);
  else
    result = _fm_logl(x + _fm_sqrtl((x - 1.0) * (x + 1.0)));

  return result;
}
//-------------------------------------------------------------------------
long double _FMAPI _fm_asinhl(long double x)
{
  bool Neg;
  long double result;

  if (x == 0)
    result = 0;
  else
  {
    Neg = (x < 0);
    x = _fm_fabsl(x);
    if (x > 1.0e10)
      result = _fm_logl(2) + _fm_logl(x);
    else
    {
      result = x*x;
      result = lnxp1(x + result / (1 + _fm_sqrtl(1 + result)));
    }
    if (Neg)
      result = -result;
  }
  return result;
}
//-------------------------------------------------------------------------
long double _FMAPI _fm_atanhl(long double x)
{
  bool Neg;
  long double result;

  if (x == 0)
    result = 0;
  else
  {
    Neg = (x < 0);
    x = fabsl(x);
    if (x >= 1)
      result = LDBL_MAX;
    else
      result = 0.5 * lnxp1((2.0 * x) / (1.0 - x));
    if (Neg)
      result = -result;
  }
  return result;
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_frexpl(long double x,int *exponent)
{
    asm {
        // Put the Exponent ptr in edx
        MOV                 edx,[esp+10h]// exponent

        FLD       tbyte ptr [esp+04h]    // x
        MOV       dword ptr [edx], 0     // if x = 0, return 0

        FTST
        FNSTSW              ax
        FWAIT
        SAHF
        JZ                  l_Done

        FXTRACT                          // ST(1) = exponent,
                                         // (pushed) ST = fraction
        FXCH

        // The FXTRACT instruction normalizes the fraction 1 bit higher than
        // wanted for the definition of frexp() so we need to tweak the
        // result by scaling the fraction down and incrementing the exponent.

        FISTP     dword ptr [edx]
        FLD1
        FCHS
        FXCH
        FSCALE                           // scale fraction
        INC       dword ptr [edx]        // exponent biased to match
        FSTP                ST(1)        // discard -1, leave fraction as TOS

   }
l_Done:
   asm {
        RET                              // mantissa is in ST(0) now
  }
}
//-------------------------------------------------------------------------
long double _FMAPI_ASM _fm_hypotl(long double x, long double y)
{
// formula:  sqrt(x*x + y*y)
// implemented as:  |y|*sqrt(1+sqr(x/y)), |x| < |x| for greater precision

    asm {
        FLD       tbyte ptr [esp+10h]    // y
        FABS
        FLD       tbyte ptr [esp+04h]    // x
        FABS
        FCOM
        FNSTSW              ax
        FWAIT
        TEST                ah,045h
        JNZ                 l_1          // if ST > ST(1) then swap
        FXCH                ST(1)        // put larger number in ST(1)
    }
l_1:
    asm {
        FLDZ
        FCOMP
        FNSTSW              ax
        FWAIT
        TEST                ah,040h      // if ST == 0, return ST(1)
        JZ                  l_2
        FSTP                ST           // eat ST(0)
        JMP                 l_3
    }
l_2:
    asm {
        FDIV                ST,ST(1)     // ST = ST / ST(1)
        FMUL                ST,ST        // ST = ST * ST
        FLD1
        FADD                             // ST = ST + 1
        FSQRT                            // ST = sqrt(ST)
        FMUL                             // ST(1) = ST * ST(1); pop ST
    }
l_3:
    asm {
        RET
    }
}
} // "C"


#pragma option pop  // restore the options
