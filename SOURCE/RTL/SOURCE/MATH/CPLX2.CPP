/*-----------------------------------------------------------------------*
 * filename - cplx2.cpp
 * C++ Complex Library Routines
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1990, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.3 $        */

#include <complex.h>

static const complex _RTLENTRY complex_zero(0, 0);
inline long double sqr(double x) { return x*x;}

#pragma warn -lvc

complex & _RTLENTRY complex::operator/=(const complex & z2)
{
    long double sum_sqrs = norm(z2);
    *this *= conj(z2);
    re /= sum_sqrs;
    im /= sum_sqrs;
    return *this;
}

complex _RTLENTRY _EXPFUNC operator/(const complex & z1, const complex & z2)
{
    return z1 * conj(z2) / norm(z2);
}

complex _RTLENTRY _EXPFUNC operator/(double re_val1, const complex & z2)
{
    return re_val1 * conj(z2) / norm(z2);
}

complex _RTLENTRY _EXPFUNC acos(const complex & z)
{
    // complex i(0,1);
    // return -i*log(z+i*sqrt(1-z*z));
    complex temp1(1 - sqr(z.re) + sqr(z.im), -2*z.re*z.im);
    double phi = arg(temp1)/2;
    double rp = sqrt(abs(temp1));
    complex temp2(z.re - rp*sin(phi), z.im + rp*cos(phi));
    return complex(arg(temp2), -log(abs(temp2)));
}

double _RTLENTRY _EXPFUNC arg(const complex & z)
{
    return z == complex_zero ? 0.0 : atan2(z.im, z.re);
}

complex _RTLENTRY _EXPFUNC asin(const complex & z)
{
    // complex i(0,1);
    // return -i*log(i*z+sqrt(1-z*z));

    complex temp1(1 - sqr(z.re) + sqr(z.im), -2*z.re*z.im);
    double phi = arg(temp1) / 2;
    double rp = sqrt(abs(temp1));
    complex temp2(-z.im + rp*cos(phi), z.re + rp*sin(phi));
    return complex(arg(temp2), -log(abs(temp2)));
}

complex _RTLENTRY _EXPFUNC atan(const complex & z)
{
    // complex i(0, 1);
    // return -0.5*i * log((1+i*z)/(1-i*z));
    // if z=i then a floating-point exception may occur

    double opb = 1 + z.im;
    double a2 = sqr(z.re);
    double den = opb*opb + a2;
    complex temp(((1-z.im)*opb - a2)/den, 2*z.re/den);
    return complex(arg(temp)/2, -log(abs(temp))/2);
}

complex _RTLENTRY _EXPFUNC cos(const complex & z)
{
    // complex i(0, 1);
    // return (exp(i*z) + exp(-i*z))/2;

    long double eb  = exp(z.im);
    long double emb = 1 / eb;
    return complex(cos(z.re)*(emb+eb)/2, sin(z.re)*(emb-eb)/2);
}

complex _RTLENTRY _EXPFUNC cosh(const complex & z)
{
    // return (exp(z) + exp(-z))/2;
    long double ea = exp(z.re);
    long double eainv = 1 / ea;
    return complex(cos(z.im)*(ea + eainv)/2, sin(z.im)*(ea - eainv)/2);
}

complex _RTLENTRY _EXPFUNC exp(const complex & z)
{
    return polar(exp(z.re),z.im);
}

complex _RTLENTRY _EXPFUNC log(const complex & z)
{
    // exception if z = 0
    return complex(log(abs(z)), arg(z));
}

complex _RTLENTRY _EXPFUNC log10(const complex & z)
{
    // return log10e*log(z);
    return log(z) * M_LOG10E;
}

complex _RTLENTRY _EXPFUNC pow(const complex & base, double expon)
{
    // return exp(expon*log(base));

    if (base == complex_zero && expon > 0) return complex_zero;
    return polar(pow(abs(base), expon), expon*arg(base));
}

complex _RTLENTRY _EXPFUNC pow(double base, const complex & expon)
{
    // return exp(expon*log(base));
    if (base == 0 && real(expon) > 0) return complex_zero;
    double lnx = log(fabs(base));
    if (base > 0.0)
        return exp(expon * lnx);
    return exp(expon * complex(lnx,M_PI));
}

complex _RTLENTRY _EXPFUNC pow(const complex & base, const complex & expon)
{
    if (base == complex_zero && real(expon) > 0) return complex_zero;
    return exp(expon * log(base));
}

complex _RTLENTRY _EXPFUNC sin(const complex & z)
{
    // complex i(0,1);
    // return (exp(i*z) - exp(-i*z))/(2*i);

    long double eb  = exp(z.im);
    long double emb = 1 / eb;
    return complex(sin(z.re)*(emb+eb)/2, -0.5*cos(z.re)*(emb-eb));
}

complex _RTLENTRY _EXPFUNC sinh(const complex & z)
{
    // return (exp(z) - exp(-z))/2
    long double ea = exp(z.re);
    long double eainv = 1 / ea;
    return complex(cos(z.im)*(ea - eainv)/2, sin(z.im)*(ea + eainv)/2);
}

complex _RTLENTRY _EXPFUNC sqrt(const complex & z)
{
    // return pow(z, 0.5);
    return polar(sqrt(abs(z)), arg(z) / 2);
}

complex _RTLENTRY _EXPFUNC tan(const complex & z)
{
    // return sin(z)/cos(z)
    double sina = sin(z.re);
    double cosa = cos(z.re);
    long double eb = exp(z.im);
    long double emb = 1 / eb;
    double emin = emb - eb;
    double eplus = emb + eb;
    return complex(4*sina*cosa, -emin*eplus)
        / (sqr(cosa*eplus) + sqr(sina*emin));
}

complex _RTLENTRY _EXPFUNC tanh(const complex & z)
{
    // return sinh(z)/cosh(z);
    double sinb = sin(z.im);
    double cosb = cos(z.im);
    long double ea = exp(z.re);
    long double eainv = 1 / ea;
    double eamin = ea - eainv;
    double eapls = ea + eainv;
    long double div = (sqr(cosb*eapls) + sqr(sinb*eamin));

    return complex((eamin/div)*eapls, (4*sinb*cosb)/div);
}


// Stream I/O function definitions

ostream & _RTLENTRY _EXPFUNC operator<<(ostream & s, const complex & z)
{
    return s << "(" << real(z) << ", " << imag(z) << ")";
}

istream & _RTLENTRY _EXPFUNC operator>>(istream & s, complex & z)
{
    double re_val = 0.0, im_val = 0.0;
    char c = 0;

    s >> c;
    if (c == '(') {
        s >> re_val >> c;
         if (c == ',') s >> im_val >> c;
         if (c != ')') s.clear(ios::badbit | s.rdstate());
    }
    else {
        s.putback(c);
        s >> re_val;
    }
    if (s) z = complex(re_val, im_val);
    return s;
}

#pragma warn .lvc

