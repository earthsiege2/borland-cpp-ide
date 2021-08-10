/* complex.h

    Complex Number Library - Include File
    class complex:  declarations for complex numbers.

All function names, member names, and operators have been borrowed
from AT&T C++, except for the addition of:

    friend complex _RTLENTRY acos(complex _FAR &);
    friend complex _RTLENTRY asin(complex _FAR &);
    friend complex _RTLENTRY atan(complex _FAR &);
    friend complex _RTLENTRY log10(complex _FAR &);
    friend complex _RTLENTRY tan(complex _FAR &);
    friend complex _RTLENTRY tanh(complex _FAR &);
    complex _RTLENTRY operator+();
    complex _RTLENTRY operator-();
*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the type complex.
#endif

#if !defined(__COMPLEX_H)
#define __COMPLEX_H


#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__MATH_H)
#include <math.h>
#endif

#if !defined(__IOSTREAM_H)
#include <iostream.h>
#endif


#if !defined(RC_INVOKED)

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-     // disable Object data calling convention
#endif
#endif

#pragma option -Vo-

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


class _EXPCLASS complex {

public:
    // constructors
    _RTLENTRY complex(double __re_val, double __im_val=0);
    _RTLENTRY complex();

    // complex manipulations
    friend double _RTLENTRY _EXPFUNC real(complex _FAR &);   // the real part
    friend double _RTLENTRY _EXPFUNC imag(complex _FAR &);   // the imaginary part
    friend complex _RTLENTRY _EXPFUNC conj(complex _FAR &);  // the complex conjugate
    friend double _RTLENTRY _EXPFUNC norm(complex _FAR &);   // the square of the magnitude
    friend double _RTLENTRY _EXPFUNC arg(complex _FAR &);    // the angle in the plane

    // Create a complex object given polar coordinates
    friend complex _RTLENTRY _EXPFUNC polar(double __mag, double __angle=0);

    // Overloaded ANSI C math functions
    friend double  _RTLENTRY _EXPFUNC abs(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC acos(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC asin(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC atan(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC cos(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC cosh(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC exp(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC log(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC log10(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC pow(complex _FAR & __base, double __expon);
    friend complex _RTLENTRY _EXPFUNC pow(double __base, complex _FAR & __expon);
    friend complex _RTLENTRY _EXPFUNC pow(complex _FAR & __base, complex _FAR & __expon);
    friend complex _RTLENTRY _EXPFUNC sin(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC sinh(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC sqrt(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC tan(complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC tanh(complex _FAR &);

    // Binary Operator Functions
    friend complex _RTLENTRY _EXPFUNC operator+(complex _FAR &, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator+(double, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator+(complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator-(complex _FAR &, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator-(double, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator-(complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator*(complex _FAR &, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator*(complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator*(double, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator/(complex _FAR &, complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator/(complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator/(double, complex _FAR &);
    friend int _RTLENTRY _EXPFUNC operator==(complex _FAR &, complex _FAR &);
    friend int _RTLENTRY _EXPFUNC operator!=(complex _FAR &, complex _FAR &);
    complex _FAR & _RTLENTRY operator+=(complex _FAR &);
    complex _FAR & _RTLENTRY operator+=(double);
    complex _FAR & _RTLENTRY operator-=(complex _FAR &);
    complex _FAR & _RTLENTRY operator-=(double);
    complex _FAR & _RTLENTRY operator*=(complex _FAR &);
    complex _FAR & _RTLENTRY operator*=(double);
    complex _FAR & _RTLENTRY operator/=(complex _FAR &);
    complex _FAR & _RTLENTRY operator/=(double);
    complex _RTLENTRY operator+();
    complex _RTLENTRY operator-();

// Implementation
private:
        double re, im;
};


// Inline complex functions

inline _RTLENTRY complex::complex(double __re_val, double __im_val)
{
    re = __re_val;
    im = __im_val;
}

inline _RTLENTRY complex::complex()
{
/* if you want your complex numbers initialized ...
    re = im = 0;
*/
}

inline complex _RTLENTRY complex::operator+()
{
    return *this;
}

inline complex _RTLENTRY complex::operator-()
{
    return complex(-re, -im);
}


// Definitions of compound-assignment operator member functions

inline complex _FAR & _RTLENTRY complex::operator+=(complex _FAR & __z2)
{
    re += __z2.re;
    im += __z2.im;
    return *this;
}

inline complex _FAR & _RTLENTRY complex::operator+=(double __re_val2)
{
    re += __re_val2;
    return *this;
}

inline complex _FAR & _RTLENTRY complex::operator-=(complex _FAR & __z2)
{
    re -= __z2.re;
    im -= __z2.im;
    return *this;
}

inline complex _FAR & _RTLENTRY complex::operator-=(double __re_val2)
{
    re -= __re_val2;
    return *this;
}

inline complex _FAR & _RTLENTRY complex::operator*=(double __re_val2)
{
    re *= __re_val2;
    im *= __re_val2;
    return *this;
}

inline complex _FAR & _RTLENTRY complex::operator/=(double __re_val2)
{
    re /= __re_val2;
    im /= __re_val2;
    return *this;
}


// Definitions of non-member complex functions

inline double _RTLENTRY real(complex _FAR & __z)
{
    return __z.re;
}

inline double _RTLENTRY imag(complex _FAR & __z)
{
    return __z.im;
}

inline complex _RTLENTRY conj(complex _FAR & __z)
{
    return complex(__z.re, -__z.im);
}

inline complex _RTLENTRY polar(double __mag, double __angle)
{
    return complex(__mag*cos(__angle), __mag*sin(__angle));
}


// Definitions of non-member binary operator functions

inline complex _RTLENTRY operator+(complex _FAR & __z1, complex _FAR & __z2)
{
    return complex(__z1.re + __z2.re, __z1.im + __z2.im);
}

inline complex _RTLENTRY operator+(double __re_val1, complex _FAR & __z2)
{
    return complex(__re_val1 + __z2.re, __z2.im);
}

inline complex _RTLENTRY operator+(complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re + __re_val2, __z1.im);
}

inline complex _RTLENTRY operator-(complex _FAR & __z1, complex _FAR & __z2)
{
    return complex(__z1.re - __z2.re, __z1.im - __z2.im);
}

inline complex _RTLENTRY operator-(double __re_val1, complex _FAR & __z2)
{
    return complex(__re_val1 - __z2.re, -__z2.im);
}

inline complex _RTLENTRY operator-(complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re - __re_val2, __z1.im);
}

inline complex _RTLENTRY operator*(complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re*__re_val2, __z1.im*__re_val2);
}

inline complex _RTLENTRY operator*(double __re_val1, complex _FAR & __z2)
{
    return complex(__z2.re*__re_val1, __z2.im*__re_val1);
}

inline complex _RTLENTRY operator/(complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re/__re_val2, __z1.im/__re_val2);
}

inline int _RTLENTRY operator==(complex _FAR & __z1, complex _FAR & __z2)
{
    return __z1.re == __z2.re && __z1.im == __z2.im;
}

inline int _RTLENTRY operator!=(complex _FAR & __z1, complex _FAR & __z2)
{
    return __z1.re != __z2.re || __z1.im != __z2.im;
}


// Complex stream I/O

ostream _FAR & _RTLENTRY _EXPFUNC operator<<(ostream _FAR &, complex _FAR &);
istream _FAR & _RTLENTRY _EXPFUNC operator>>(istream _FAR &, complex _FAR &);


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#pragma option -Vo.

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po.     // restore Object data calling convention
#endif
#endif

#endif  /* !RC_INVOKED */


#endif  // __COMPLEX_H

