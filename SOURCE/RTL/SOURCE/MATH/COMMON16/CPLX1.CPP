/*-----------------------------------------------------------------------*
 * filename - cplx1.cpp
 * C++ Complex Library Routines
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.4  $        */


#ifdef _RTLDLL
static void __debug(void){}
#pragma codeseg _TEXTB
#endif

#pragma inline

#define RETURN_TOS  ;\
    long double x_tos;      ;\
    asm fstp    tbyte ptr x_tos ;\
        return x_tos;

#include <complex.h>
#include "asmrules.h"

#define REAL    qword ptr
#define REAL1   dword ptr
#define REAL2   qword ptr
#define REAL3   tbyte ptr

#define LONG    dword ptr
#define WORD    word ptr
#define BYTE    byte ptr


double _Cdecl _FARFUNC abs(const complex _FAR & z)
{
asm LES_    bx, z
asm fld REAL ES_ [bx]
asm fmul    st(0), st(0)
asm fld REAL ES_ [bx+8]
asm fmul    st(0), st(0)
asm fadd
asm fsqrt
    RETURN_TOS;
}

double _Cdecl _FARFUNC norm(const complex _FAR & z)
{
/*
    return z.re*z.re + z.im*z.im;
*/
asm LES_    bx, z
asm fld REAL ES_ [bx]
asm fmul    st(0), st(0)
asm fld REAL ES_ [bx+8]
asm fmul    st(0), st(0)
asm fadd
    RETURN_TOS;
}

complex _FAR & _Cdecl complex::operator*=(const complex _FAR & z2)
{
#if defined(_RTL_ALLOW_po)
    double tmp;
    tmp = re*z2.re - im*z2.im;
    im = im*z2.re + re*z2.im;
    re = tmp;
#else
asm LES_    bx, z2
asm fld REAL ES_ [bx+8]
asm fld st(0)
asm fld REAL ES_ [bx]
asm fld st(0)

asm LES_    bx, this
asm fmul    REAL ES_ [bx+8]
asm fxch    st(1)
asm fmul    REAL ES_ [bx]

asm fxch    st(2)
asm fmul    REAL ES_ [bx]
asm fxch    st(3)
asm fmul    REAL ES_ [bx+8]
asm fsubp   st(2), st(0)
asm faddp   st(2), st(0)

asm fstp    REAL ES_ [bx]
asm fstp    REAL ES_ [bx+8]
#endif

    return *this;
}

complex _Cdecl _FARFUNC operator*(const complex _FAR & z1, const complex _FAR & z2)
{
    double temp_re = z1.re*z2.re - z1.im*z2.im;
    double temp_im = z1.im*z2.re + z1.re*z2.im;
    return complex(temp_re, temp_im);
}
