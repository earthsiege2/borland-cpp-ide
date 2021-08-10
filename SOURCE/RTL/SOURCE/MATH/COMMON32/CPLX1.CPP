/*-----------------------------------------------------------------------*
 * filename - cplx1.cpp
 * C++ Complex Library Routines
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <complex.h>


double _RTLENTRY _EXPFUNC abs(complex & z)
{
    return (sqrt(z.re*z.re + z.im*z.im));
}

double _RTLENTRY _EXPFUNC norm(complex & z)
{
    return (z.re*z.re + z.im*z.im);
}

complex & _RTLENTRY complex::operator*=(complex & z2)
{
    double temp_re = this->re*z2.re - this->im*z2.im;
    double temp_im = this->im*z2.re + this->re*z2.im;

    this->re = temp_re;
    this->im = temp_im;
    return *this;
}

complex _RTLENTRY _EXPFUNC operator*(complex & z1, complex & z2)
{
    double temp_re = z1.re*z2.re - z1.im*z2.im;
    double temp_im = z1.im*z2.re + z1.re*z2.im;
    return complex(temp_re, temp_im);
}
