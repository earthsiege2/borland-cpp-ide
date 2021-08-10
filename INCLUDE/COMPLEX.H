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
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $ */

#ifndef __cplusplus
#error Must use C++ for the type complex.
#endif

#if !defined(__USING_STD_NAMES__)

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
    friend double  _RTLENTRY _EXPFUNC real(const complex _FAR &);   // the real part
    friend double  _RTLENTRY _EXPFUNC imag(const complex _FAR &);   // the imaginary part
    friend complex _RTLENTRY _EXPFUNC conj(const complex _FAR &);   // the complex conjugate
    friend double  _RTLENTRY _EXPFUNC norm(const complex _FAR &);   // the square of the magnitude
    friend double  _RTLENTRY _EXPFUNC arg(const complex _FAR &);    // the angle in the plane

    // Create a complex object given polar coordinates
    friend complex _RTLENTRY _EXPFUNC polar(double __mag, double __angle=0);

    // Overloaded ANSI C math functions
    friend double  _RTLENTRY _EXPFUNC abs(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC acos(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC asin(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC atan(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC cos(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC cosh(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC exp(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC log(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC log10(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC pow(const complex _FAR & __base, double __expon);
    friend complex _RTLENTRY _EXPFUNC pow(double __base, const complex _FAR & __expon);
    friend complex _RTLENTRY _EXPFUNC pow(const complex _FAR & __base, const complex _FAR & __expon);
    friend complex _RTLENTRY _EXPFUNC sin(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC sinh(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC sqrt(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC tan(const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC tanh(const complex _FAR &);

    // Binary Operator Functions
    friend complex _RTLENTRY _EXPFUNC operator+(const complex _FAR &, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator+(double, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator+(const complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator-(const complex _FAR &, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator-(double, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator-(const complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator*(const complex _FAR &, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator*(const complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator*(double, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator/(const complex _FAR &, const complex _FAR &);
    friend complex _RTLENTRY _EXPFUNC operator/(const complex _FAR &, double);
    friend complex _RTLENTRY _EXPFUNC operator/(double, const complex _FAR &);
    friend int _RTLENTRY _EXPFUNC operator==(const complex _FAR &, const complex _FAR &);
    friend int _RTLENTRY _EXPFUNC operator!=(const complex _FAR &, const complex _FAR &);
    complex _FAR & _RTLENTRY operator+=(const complex _FAR &);
    complex _FAR & _RTLENTRY operator+=(double);
    complex _FAR & _RTLENTRY operator-=(const complex _FAR &);
    complex _FAR & _RTLENTRY operator-=(double);
    complex _FAR & _RTLENTRY operator*=(const complex _FAR &);
    complex _FAR & _RTLENTRY operator*=(double);
    complex _FAR & _RTLENTRY operator/=(const complex _FAR &);
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

inline complex _FAR & _RTLENTRY complex::operator+=(const complex _FAR & __z2)
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

inline complex _FAR & _RTLENTRY complex::operator-=(const complex _FAR & __z2)
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

inline double _RTLENTRY real(const complex _FAR & __z)
{
    return __z.re;
}

inline double _RTLENTRY imag(const complex _FAR & __z)
{
    return __z.im;
}

inline complex _RTLENTRY conj(const complex _FAR & __z)
{
    return complex(__z.re, -__z.im);
}

inline complex _RTLENTRY polar(double __mag, double __angle)
{
    return complex(__mag*cos(__angle), __mag*sin(__angle));
}


// Definitions of non-member binary operator functions

inline complex _RTLENTRY operator+(const complex _FAR & __z1, const complex _FAR & __z2)
{
    return complex(__z1.re + __z2.re, __z1.im + __z2.im);
}

inline complex _RTLENTRY operator+(double __re_val1, const complex _FAR & __z2)
{
    return complex(__re_val1 + __z2.re, __z2.im);
}

inline complex _RTLENTRY operator+(const complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re + __re_val2, __z1.im);
}

inline complex _RTLENTRY operator-(const complex _FAR & __z1, const complex _FAR & __z2)
{
    return complex(__z1.re - __z2.re, __z1.im - __z2.im);
}

inline complex _RTLENTRY operator-(double __re_val1, const complex _FAR & __z2)
{
    return complex(__re_val1 - __z2.re, -__z2.im);
}

inline complex _RTLENTRY operator-(const complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re - __re_val2, __z1.im);
}

inline complex _RTLENTRY operator*(const complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re*__re_val2, __z1.im*__re_val2);
}

inline complex _RTLENTRY operator*(double __re_val1, const complex _FAR & __z2)
{
    return complex(__z2.re*__re_val1, __z2.im*__re_val1);
}

inline complex _RTLENTRY operator/(const complex _FAR & __z1, double __re_val2)
{
    return complex(__z1.re/__re_val2, __z1.im/__re_val2);
}

inline int _RTLENTRY operator==(const complex _FAR & __z1, const complex _FAR & __z2)
{
    return __z1.re == __z2.re && __z1.im == __z2.im;
}

inline int _RTLENTRY operator!=(const complex _FAR & __z1, const complex _FAR & __z2)
{
    return __z1.re != __z2.re || __z1.im != __z2.im;
}


// Complex stream I/O

ostream _FAR & _RTLENTRY _EXPFUNC operator<<(ostream _FAR &, const complex _FAR &);
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

#else   // __USING_STD_NAMES__

#ifndef __STD_COMPLEX
#define __STD_COMPLEX

/***************************************************************************
 *
 * complex - Declaration for the Standard Library complex class
 *
 * $Id: complex,v 1.58 1995/10/04 00:40:32 hart Exp $
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 *
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#include <stdcomp.h>
#include <stddefs.h>

//
// Hack to get around extraneous exception specification bug in math stuff.
//
#ifdef exception
#undef exception
#else
#define exception math_exception
#endif

#ifndef RWSTD_NO_NEW_HEADER
#include <cmath>
#else
#include <math.h>
#endif

//
// Undo hack.
//
#ifdef exception
#undef exception
#endif

//
// MSVC provides it's own complex
//
#ifdef _MSC_VER
#ifdef complex
#undef complex
#endif
#endif

#include <utility>

#ifdef RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef RWSTD_NO_FORWARD_SPECIALIZATIONS
template <class T>
class complex
{
  public:
    complex (const T& re_arg=0, const T& imag_arg=0) { re_=re_arg; im_=imag_arg; }

    T imag () const { return im_; }
    T real () const { return re_; }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag();}

    template <class X> complex<T>& operator=  (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag(); return *this;}
    template <class X> complex<T>& operator+= (const complex<X>& rhs) {re_+=rhs.real(); im_+=rhs.imag(); return *this;}
    template <class X> complex<T>& operator-= (const complex<X>& rhs) {re_-=rhs.real(); im_-=rhs.imag(); return *this;}
    template <class X> complex<T>& operator*= (const complex<X>& rhs) {T tmp=re_*rhs.real()-im_*rhs.imag(); im_=im_*rhs.real()+re_*rhs.imag(); re_=tmp; return *this;}
    template <class X> complex<T>& operator/= (const complex<X>&);
#endif

  private:
    T re_, im_;
};


#else

//
// The complex template definition must be placed after specializations to
// satisfy several compilers' rather bizarre preference.
//
template <class T>
class complex;
#endif

class RWSTDExport complex<float>;
class RWSTDExport complex<double>;
class RWSTDExport complex<long double>;

#ifdef RWSTD_NO_UNDECLARED_FRIEND
istream& RWSTDExport operator>> (istream&,       complex<float>&);
ostream& RWSTDExport operator<< (ostream&, const complex<float>&);
istream& RWSTDExport operator>> (istream&,       complex<double>&);
ostream& RWSTDExport operator<< (ostream&, const complex<double>&);
istream& RWSTDExport operator>> (istream&,       complex<long double>&);
ostream& RWSTDExport operator<< (ostream&, const complex<long double>&);
#endif

class complex<float>
{
  public:
    complex (const float& re_arg=0.0f, const float& imag_arg=0.0f) { re_=re_arg; im_=imag_arg; }
    complex (const complex<float>&);
    explicit complex (const complex<double>&);
    explicit complex (const complex<long double>&);

    float imag () const { return im_; }
    float real () const { return re_; }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex<float>& operator=  (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag(); return *this;}
    template <class X> complex<float>& operator+= (const complex<X>& rhs) {re_+=rhs.real(); im_+=rhs.imag(); return *this;}
    template <class X> complex<float>& operator-= (const complex<X>& rhs) {re_-=rhs.real(); im_-=rhs.imag(); return *this;}
    template <class X> complex<float>& operator*= (const complex<X>& rhs) {float tmp=re_*rhs.real()-im_*rhs.imag(); im_=im_*rhs.real()+re_*rhs.imag(); re_=tmp; return *this;}
    template <class X> complex<float>& operator/= (const complex<X>&);
#else /* Have to specialize each one :-( */

    complex<float>& operator=  (const complex<float>&);
    complex<float>& operator+= (const complex<float>&);
    complex<float>& operator-= (const complex<float>&);
    complex<float>& operator*= (const complex<float>&);
    complex<float>& operator/= (const complex<float>&);

    complex<float>& operator=  (const complex<double>&);
    complex<float>& operator+= (const complex<double>&);
    complex<float>& operator-= (const complex<double>&);
    complex<float>& operator*= (const complex<double>&);
    complex<float>& operator/= (const complex<double>&);

    complex<float>& operator=  (const complex<long double>&);
    complex<float>& operator+= (const complex<long double>&);
    complex<float>& operator-= (const complex<long double>&);
    complex<float>& operator*= (const complex<long double>&);
    complex<float>& operator/= (const complex<long double>&);
#endif

    friend istream& operator>> (istream&,       complex<float>&);
    friend ostream& operator<< (ostream&, const complex<float>&);

  private:
    float re_, im_;
};

class  complex<double>
{
  public:
    complex (const double& re_arg=0.0, const double& imag_arg=0.0) { re_=re_arg; im_=imag_arg; }
    complex (const complex<float>&);
    complex (const complex<double>&);
    explicit complex (const complex<long double>&);

    double imag () const { return im_; }
    double real () const { return re_; }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex<double>& operator=  (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag(); return *this;}
    template <class X> complex<double>& operator+= (const complex<X>& rhs) {re_+=rhs.real(); im_+=rhs.imag(); return *this;}
    template <class X> complex<double>& operator-= (const complex<X>& rhs) {re_-=rhs.real(); im_-=rhs.imag(); return *this;}
    template <class X> complex<double>& operator*= (const complex<X>& rhs) {double tmp=re_*rhs.real()-im_*rhs.imag(); im_=im_*rhs.real()+re_*rhs.imag(); re_=tmp; return *this;}
    template <class X> complex<double>& operator/= (const complex<X>&);

#else /* Have to specialize each one :-( */

    complex<double>& operator=  (const complex<float>&);
    complex<double>& operator+= (const complex<float>&);
    complex<double>& operator-= (const complex<float>&);
    complex<double>& operator*= (const complex<float>& rhs);
    complex<double>& operator/= (const complex<float>&);

    complex<double>& operator=  (const complex<double>& rhs);
    complex<double>& operator+= (const complex<double>& rhs);
    complex<double>& operator-= (const complex<double>& rhs);
    complex<double>& operator*= (const complex<double>& rhs);
    complex<double>& operator/= (const complex<double>&);

    complex<double>& operator=  (const complex<long double>&);
    complex<double>& operator+= (const complex<long double>&);
    complex<double>& operator-= (const complex<long double>&);
    complex<double>& operator*= (const complex<long double>&);
    complex<double>& operator/= (const complex<long double>&);
#endif

    friend istream& operator>> (istream&,       complex<double>&);
    friend ostream& operator<< (ostream&, const complex<double>&);

  private:
    double re_, im_;
};

class complex<long double>
{
  public:
    complex (const long double& re_arg=0.0L, const long double& imag_arg=0.0L) { re_=re_arg; im_=imag_arg; }
    complex (const complex<float>&);
    complex (const complex<double>&);
    complex (const complex<long double>&);

    long double imag () const { return im_; }
    long double real () const { return re_; }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex<long double>& operator=  (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag(); return *this;}
    template <class X> complex<long double>& operator+= (const complex<X>& rhs) {re_+=rhs.real(); im_+=rhs.imag(); return *this;}
    template <class X> complex<long double>& operator-= (const complex<X>& rhs) {re_-=rhs.real(); im_-=rhs.imag(); return *this;}
    template <class X> complex<long double>& operator*= (const complex<X>& rhs) {long double tmp=re_*rhs.real()-im_*rhs.imag(); im_=im_*rhs.real()+re_*rhs.imag(); re_=tmp; return *this;}
    template <class X> complex<long double>& operator/= (const complex<X>&);

#else /* Have to specialize each one :-( */

    complex<long double>& operator=  (const complex<float>&);
    complex<long double>& operator+= (const complex<float>&);
    complex<long double>& operator-= (const complex<float>&);
    complex<long double>& operator*= (const complex<float>&);
    complex<long double>& operator/= (const complex<float>&);

    complex<long double>& operator=  (const complex<double>&);
    complex<long double>& operator+= (const complex<double>&);
    complex<long double>& operator-= (const complex<double>&);
    complex<long double>& operator*= (const complex<double>&);
    complex<long double>& operator/= (const complex<double>&);

    complex<long double>& operator=  (const complex<long double>&);
    complex<long double>& operator+= (const complex<long double>&);
    complex<long double>& operator-= (const complex<long double>&);
    complex<long double>& operator*= (const complex<long double>&);
    complex<long double>& operator/= (const complex<long double>&);
#endif

    friend istream& operator>> (istream&,       complex<long double>&);
    friend ostream& operator<< (ostream&, const complex<long double>&);

  private:
    long double re_, im_;
};

#ifdef RWSTD_NO_FORWARD_SPECIALIZATIONS
template <class T>
class complex
{
  public:
    complex (const T& re_arg=0, const T& imag_arg=0) { re_=re_arg; im_=imag_arg; }

    T imag () const { return im_; }
    T real () const { return re_; }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag();}

    template <class X> complex<T>& operator=  (const complex<X>& rhs) {re_=rhs.real(); im_=rhs.imag(); return *this;}
    template <class X> complex<T>& operator+= (const complex<X>& rhs) {re_+=rhs.real(); im_+=rhs.imag(); return *this;}
    template <class X> complex<T>& operator-= (const complex<X>& rhs) {re_-=rhs.real(); im_-=rhs.imag(); return *this;}
    template <class X> complex<T>& operator*= (const complex<X>& rhs) {T tmp=re_*rhs.real()-im_*rhs.imag(); im_=im_*rhs.real()+re_*rhs.imag(); re_=tmp; return *this;}
    template <class X> complex<T>& operator/= (const complex<X>&);
#endif

  private:
    T re_, im_;
};


#endif

//
// complex<float> specializations.
//
inline
complex<float>::complex (const complex<float>& cf)
{
    re_ = cf.real(); im_ = cf.imag();
}

inline
complex<float>::complex (const complex<double>& cd)
{
    re_ = cd.real(); im_ = cd.imag();
}

inline
complex<float>::complex (const complex<long double>& cld)
{
    re_ = cld.real(); im_ = cld.imag();
}

inline complex<float>&
complex<float>::operator= (const complex<float>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator+= (const complex<float>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator-= (const complex<float>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator*= (const complex<float>& rhs)
{
    float tmp = re_*rhs.real()-im_*rhs.imag();
    im_       = im_*rhs.real()+re_*rhs.imag();
    re_       = tmp;
    return *this;
}

inline complex<float>&
complex<float>::operator= (const complex<double>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator+= (const complex<double>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator-= (const complex<double>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator*= (const complex<double>& rhs)
{
    float tmp = re_*rhs.real()-im_*rhs.imag();
    im_       = im_*rhs.real()+re_*rhs.imag();
    re_       = tmp;
    return *this;
}

inline complex<float>&
complex<float>::operator= (const complex<long double>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator+= (const complex<long double>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator-= (const complex<long double>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<float>&
complex<float>::operator*= (const complex<long double>& rhs)
{
    float tmp = re_*rhs.real()-im_*rhs.imag();
    im_       = im_*rhs.real()+re_*rhs.imag();
    re_       = tmp;
    return *this;
}

//
// complex<double> specializations.
//

inline
complex<double>::complex (const complex<float>& cf)
    : re_(cf.real()), im_(cf.imag()) {}

inline
complex<double>::complex (const complex<double>& cd)
    : re_(cd.real()), im_(cd.imag()) {}

inline
complex<double>::complex (const complex<long double>& cld)
    : re_(cld.real()), im_(cld.imag()) {}

inline complex<double>&
complex<double>::operator= (const complex<float>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator+= (const complex<float>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator-= (const complex<float>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator*= (const complex<float>& rhs)
{
    double tmp = re_*rhs.real()-im_*rhs.imag();
    im_        = im_*rhs.real()+re_*rhs.imag();
    re_        = tmp;
    return *this;
}

inline complex<double>&
complex<double>::operator= (const complex<double>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator+= (const complex<double>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator-= (const complex<double>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator*= (const complex<double>& rhs)
{
    double tmp = re_*rhs.real()-im_*rhs.imag();
    im_        = im_*rhs.real()+re_*rhs.imag();
    re_        = tmp;
    return *this;
}

inline complex<double>&
complex<double>::operator= (const complex<long double>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator+= (const complex<long double>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator-= (const complex<long double>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<double>&
complex<double>::operator*= (const complex<long double>& rhs)
{
    double tmp = re_*rhs.real()-im_*rhs.imag();
    im_        = im_*rhs.real()+re_*rhs.imag();
    re_        = tmp;
    return *this;
}

//
// complex<long double> specializations.
//

inline
complex<long double>::complex (const complex<float>& cf)
    : re_(cf.real()), im_(cf.imag()) {}

inline
complex<long double>::complex (const complex<double>& cd)
    : re_(cd.real()), im_(cd.imag()) {}

inline
complex<long double>::complex (const complex<long double>& cld)
    : re_(cld.real()), im_(cld.imag()) {}

inline complex<long double>&
complex<long double>::operator= (const complex<float>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator+= (const complex<float>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator-= (const complex<float>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator*= (const complex<float>& rhs)
{
    long double tmp = re_*rhs.real()-im_*rhs.imag();
    im_             = im_*rhs.real()+re_*rhs.imag();
    re_             = tmp;
    return *this;
}

inline complex<long double>&
complex<long double>::operator= (const complex<double>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator+= (const complex<double>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator-= (const complex<double>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator*= (const complex<double>& rhs)
{
    long double tmp = re_*rhs.real()-im_*rhs.imag();
    im_             = im_*rhs.real()+re_*rhs.imag();
    re_             = tmp;
    return *this;
}

inline complex<long double>&
complex<long double>::operator= (const complex<long double>& rhs)
{
    re_ = rhs.real(); im_ = rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator+= (const complex<long double>& rhs)
{
    re_ += rhs.real(); im_ += rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator-= (const complex<long double>& rhs)
{
    re_ -= rhs.real(); im_ -= rhs.imag(); return *this;
}

inline complex<long double>&
complex<long double>::operator*= (const complex<long double>& rhs)
{
    long double tmp = re_*rhs.real()-im_*rhs.imag();
    im_             = im_*rhs.real()+re_*rhs.imag();
    re_             = tmp;
    return *this;
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template <class T>
template <class X>
complex<T>&
complex<T>::operator/= (const complex<X>& rhs)
{
    T denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    T re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    T im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_     = re;
    im_     = im;
    return *this;
}

template <class X>
complex<float>&
complex<float>::operator/= (const complex<X>& rhs)
{
    float denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    float re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    float im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_         = re;
    im_         = im;
    return *this;
}

template <class X>
complex<double>&
complex<double>::operator/= (const complex<X>& rhs)
{
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_          = re;
    im_          = im;
    return *this;
}

template <class X>
complex<long double>&
complex<long double>::operator/= (const complex<X>& rhs)
{
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    long double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_               = re;
    im_               = im;
    return *this;
}

#else /* No member function templates, have to specialize :-( */

inline complex<float>&
complex<float>::operator/= (const complex<float>& rhs)
{
    float denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    float re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    float im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_         = re;
    im_         = im;
    return *this;
}

inline complex<float>&
complex<float>::operator/= (const complex<double>& rhs)
{
    float denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    float re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    float im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_         = re;
    im_         = im;
    return *this;
}

inline complex<float>&
complex<float>::operator/= (const complex<long double>& rhs)
{
    float denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    float re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    float im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_         = re;
    im_         = im;
    return *this;
}

inline complex<double>&
complex<double>::operator/= (const complex<float>& rhs)
{
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_          = re;
    im_          = im;
    return *this;
}

inline complex<double>&
complex<double>::operator/= (const complex<double>& rhs)
{
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_          = re;
    im_          = im;
    return *this;
}

inline complex<double>&
complex<double>::operator/= (const complex<long double>& rhs)
{
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_          = re;
    im_          = im;
    return *this;
}

inline complex<long double>&
complex<long double>::operator/= (const complex<float>& rhs)
{
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    long double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_               = re;
    im_               = im;
    return *this;
}

inline complex<long double>&
complex<long double>::operator/= (const complex<double>& rhs)
{
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    long double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_               = re;
    im_               = im;
    return *this;
}

inline complex<long double>&
complex<long double>::operator/= (const complex<long double>& rhs)
{
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (re_*rhs.real()+im_*rhs.imag())/denom;
    long double im    = (rhs.real()*im_-re_*rhs.imag())/denom;
    re_               = re;
    im_               = im;
    return *this;
}
#endif

//
// complex non-member operations
//

template <class T>
inline complex<T> operator+ (const complex<T>& lhs, const complex<T>& rhs)
{
    complex<T> tmp = lhs; return tmp += rhs;
}

template <class T>
inline complex<T> operator+ (const complex<T>& lhs, const T& rhs)
{
    return complex<T>(rhs+lhs.real(), lhs.imag());
}

template <class T>
inline complex<T> operator+ (const T& lhs, const complex<T>& rhs)
{
    return complex<T>(lhs+rhs.real(), rhs.imag());
}

template <class T>
inline complex<T> operator- (const complex<T>& lhs, const complex<T>& rhs)
{
    complex<T> tmp = lhs; return tmp -= rhs;
}

template <class T>
inline complex<T> operator- (const complex<T>& lhs, const T& rhs)
{
    return complex<T>(lhs.real()-rhs, lhs.imag());
}

template <class T>
inline complex<T> operator- (const T& lhs, const complex<T>& rhs)
{
    return complex<T>(lhs-rhs.real(), -rhs.imag());
}

template <class T>
inline complex<T> operator* (const complex<T>& lhs, const complex<T>& rhs)
{
    complex<T> tmp = lhs; return tmp *= rhs;
}

template <class T>
inline complex<T> operator* (const complex<T>& lhs, const T& rhs)
{
    return complex<T>(rhs*lhs.real(), rhs*lhs.imag());
}

template <class T>
inline complex<T> operator* (const T& lhs, const complex<T>& rhs)
{
    return complex<T>(lhs*rhs.real(), lhs*rhs.imag());
}

template <class T>
inline complex<T> operator/ (const complex<T>& lhs, const complex<T>& rhs)
{
    complex<T> tmp = lhs; return tmp /= rhs;
}

template <class T>
inline complex<T> operator/ (const complex<T>& lhs, const T& rhs)
{
    return complex<T>(lhs.real()/rhs, lhs.imag()/rhs);
}

template <class T>
inline complex<T> operator/ (const T& lhs, const complex<T>& rhs)
{
    register T denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    return complex<T>(lhs*rhs.real()/denom,(-lhs*rhs.imag())/denom);
}

template <class T>
inline complex<T> operator+ (const complex<T>& lhs) { return lhs; }

template <class T>
inline complex<T> operator- (const complex<T>& lhs)
{
    return complex<T>(-lhs.real(), -lhs.imag());
}

template <class T>
inline bool operator== (const complex<T>& lhs, const complex<T>& rhs)
{
    return lhs.real() == rhs.real() && lhs.imag() == rhs.imag();
}

template <class T>
inline bool operator== (const T& lhs, const complex<T>& rhs)
{
    return lhs == rhs.real() && rhs.imag() == 0;
}

template <class T>
inline bool operator== (const complex<T>& lhs, const T& rhs)
{
    return lhs.real() == rhs && lhs.imag() == 0;
}

#ifndef RWSTD_NO_PART_SPEC_OVERLOAD
template <class T>
inline bool operator!= (const complex<T>& lhs, const complex<T>& rhs)
{
    return lhs.real() != rhs.real() || lhs.imag() != rhs.imag();
}
#endif

template <class T>
inline bool operator!= (const T& lhs, const complex<T>& rhs)
{
    return lhs != rhs.real() || rhs.imag() != 0;
}

template <class T>
inline bool operator!= (const complex<T>& lhs, const T& rhs)
{
    return lhs.real() != rhs || lhs.imag() != 0;
}

//
// complex value operations
//

template<class T>
inline T real (const complex<T>& a) { return a.real(); }

template<class T>
inline T imag (const complex<T>& a) { return a.imag(); }

template <class T>
inline T norm (const complex<T>& a)
{
    return a.real()*a.real() + a.imag()*a.imag();
}

template <class T>
inline T abs (const complex<T>& a) { return ::sqrt(norm(a)); }

//
// We guarantee that arg(complex<T>(0,0)) == 0.
//

template <class T>
inline T arg (const complex<T>& a)
{
    return a == complex<T>(0,0) ? T(0) : ::atan2 (a.imag(), a.real());
}

template <class T>
complex<T> conj (const complex<T>& a)
{
    return complex<T>(a.real(), -a.imag());
}

#if _MSC_VER < 901
//
// A very bizarre Microsoft problem.
//
inline complex<float> conj (const complex<float>& a)
{
    return complex<float>(a.real(), -a.imag());
}
inline complex<double> conj (const complex<double>& a)
{
    return complex<double>(a.real(), -a.imag());
}
inline complex<long double> conj (const complex<long double>& a)
{
    return complex<long double>(a.real(), -a.imag());
}
#endif

template <class T>
inline complex<T> polar (T r, T theta)
{
    return complex<T>(r*::cos(theta), r*::sin(theta));
}

//
// transcendentals
//

template <class T>
inline complex<T> acos (const complex<T>& a)
{
    const complex<T> i(0,1);
    return -i * log(a + i*sqrt(complex<T>(1,0) - a*a));
}

template <class T>
inline complex<T> asin (const complex<T>& a)
{
    const complex<T> i(0,1);
    return i * log(i*a + sqrt(complex<T>(1,0) - a*a));
}

template <class T>
inline complex<T> atan (const complex<T>& a)
{
    const complex<T> i(0,1);
    return i/T(2) * log((i+a)/(i-a));
}
template <class T>
inline complex<T> atan2 (const complex<T>& lhs, const complex<T>& rhs)
{
    return atan(lhs/rhs);
}

template <class T>
inline complex<T> atan2 (const complex<T>& lhs, T rhs)
{
    return atan(lhs/rhs);
}

template <class T>
inline complex<T> atan2 (T lhs, const complex<T>& rhs)
{
    return atan(lhs/rhs);
}

//
// complex<T> cosine of complex<T> number a
//      cos (a) = cos u * cosh v - i * sin u * sinh v
//

template <class T>
inline complex<T> cos (const complex<T>& a)
{
    return complex<T>(::cos(a.real())*::cosh(a.imag()),
                      -::sin(a.real())*::sinh(a.imag()));
}

//
// complex<T> hyperbolic cosine of complex<T> number a
//      cosh (a) = cosh u * cosv + i * sinh u * sin v
//

template <class T>
inline complex<T> cosh (const complex<T>& a)
{
    return complex<T>(::cosh(a.real())*::cos(a.imag()),
                      ::sinh(a.real())*::sin(a.imag()));
}

//
// complex<T> exponential of  complex<T> number a
//      exp (a) = exp(u) * (cos v + i * sin v)
//

template <class T>
inline complex<T> exp (const complex<T>& a)
{
    register T e = ::exp(a.real());
    return complex<T>(e*::cos(a.imag()), e*::sin(a.imag()));
}

//
// complex<T> natural log of complex<T> number a
//      log(a) = log(r) + i * theta
//

template <class T>
inline complex<T> log (const complex<T>& a)
{
    return complex<T>(::log(abs(a)), arg(a));
}

template <class T>
complex<T> log10 (const complex<T>& a)
{
    static const T log10e = ::log10(::exp(T(1)));
    return log10e * log(a);
}

//
// For all the power functions:
//
//   0**0 == 1
//   0**x == 0 for x != 0
//

//
// complex<T> number a raised to an integer power n
//
// a**n = r**n * (cos(n theta) + i sin (n theta))
//

template <class T>
complex<T> pow (const complex<T>& a, int n)
{
    if (a == complex<T>(0,0))
        return n == 0 ? complex<T>(1,0) : complex<T>(0,0);

    if (a.imag() == 0)
        return a.real() < 0
            ? pow(a, complex<T>(n,0)) : complex<T>(::pow(a.real(),T(n)), 0);

    register T r  = ::pow(T(abs(a)), T(n));
    register T th = T(n) * arg(a);

    return complex<T>(r*::cos(th), r*::sin(th));
}


//
// complex<T> number a raised to a real power s
//
// a**s = exp(s * log(a))
//

template <class T>
complex<T> pow (const complex<T>& a, T s)
{
    if (a == complex<T>(0,0))
        return s == T(0) ? complex<T>(1,0) : complex<T>(0,0);

    if (a.imag() == 0)
        return a.real() < 0
            ? pow(a, complex<T>(s,0)) : complex<T>(::pow(a.real(),s), 0);

    return exp(s*log(a));
}


//
// real number s raised to a complex<T> power a
//
//  s**a = exp(a * log (s))
//

template <class T>
complex<T> pow (T s, const complex<T>& a)
{
    if (s == T(0))
        return a == complex<T>(0,0) ? complex<T>(1,0) : complex<T>(0,0);

    if (s < 0)
        return pow(complex<T>(s,0), a);

    if (a.imag() == 0)
        return complex<T>(::pow(s, a.real()), 0);
    return complex<T>(exp(a * (T) ::log(s)));
}


//
// complex<T> number a1 raised to a complex<T> power a2
//
// a1**a2 = rho * (cos(phi) + i sin(phi))
//      rho = r1 **u2   *  exp (-v2* theta1)
//      phi = v2 * log(r1) + u2 * theta1
//

template <class T>
complex<T> pow (const complex<T>& a1, const complex<T>& a2)
{
    if (a1 == complex<T>(0,0))
        return a2 == complex<T>(0,0) ? complex<T>(1,0) : complex<T>(0,0);

    T r1   = abs(a1);
    T u2   = real(a2);
    T v2   = imag(a2);
    T th1  = arg(a1);
    T rho  = ::pow(r1, u2) * ::exp(-v2 * th1);
    T phi  = v2 * ::log(r1) + u2 * th1;

    return complex<T>(rho*::cos(phi), rho*::sin(phi));
}


//
// complex<T> sine of complex<T> number a
//      sin (a) = sin u * cosh v + i * cos u * sinh v
//
template <class T>
inline complex<T> sin (const complex<T>& a)
{
    return complex<T>(::sin(a.real())*::cosh(a.imag()),
                      ::cos(a.real())*::sinh(a.imag()));
}

//
// complex<T> hyperbolic sine of complex<T> number a
//      sinh (a) = sinh u cos v + i cosh u sin v
//
template <class T>
inline complex<T> sinh (const complex<T>& a)
{
    return complex<T>(::sinh(a.real())*::cos(a.imag()),
                      ::cosh(a.real())*::sin(a.imag()));
}

//
// complex<T> square root of complex<T> number a
//      sqrt(a) = sqrt(r) * ( cos (theta/2) + i sin (theta/2) )
//
template <class T>
inline complex<T> sqrt (const complex<T>& a)
{
    register T r  = ::sqrt(abs(a));
    register T th = arg(a)/2.;
    return complex<T>(r*::cos(th), r*::sin(th));
}

template <class T>
inline complex<T> tan (const complex<T>& a) { return sin(a)/cos(a); }

template <class T>
inline complex<T> tanh (const complex<T>& a) { return sinh(a)/cosh(a); }

#ifdef RW_STD_IOSTREAM
template <class T,class charT, class traits>
basic_istream<charT, traits >&  operator>> (basic_istream<charT, traits >& is,complex<T>& x)
#else
template <class T>
istream& operator>> (istream& is, complex<T>& x)
#endif
{
    //
    // operator >> reads a complex number x in the form
    // u
    // (u)
    // (u, v)
    //
    T u = 0, v = 0;
    char c;

    is >> c;
    if (c == '(')
    {
        is >> u >> c;
        if (c == ',') { is >> v  >> c;}
        if (c != ')' )
        {
#ifdef RW_STD_IOSTREAM
            is.setstate(ios::failbit);
#else
            is.clear(ios::failbit);
#endif
        }
    }
    else
    {
        is.putback(c);
        is >> u;
    }

    if (is)
        x = complex<T>(u,v);

    return is;
}

#ifdef RW_STD_IOSTREAM
template <class T,class charT, class traits>
basic_istream<charT, traits >&  operator>> (basic_istream<charT, traits >& is,complex<float>& x)
#else
istream&  operator>> (istream& is, complex<float>& x)
#endif
{
    //
    // operator >> reads a complex number x in the form
    // u
    // (u)
    // (u, v)
    //
    float u = 0, v = 0;
    char c;

    is >> c;
    if (c == '(')
    {
        is >> u >> c;
        if (c == ',') { is >> v  >> c;}
        if (c != ')' )
        {
#ifdef RW_STD_IOSTREAM
            is.setstate(ios::failbit);
#else
            is.clear(ios::failbit);
#endif
        }
    }
    else
    {
        is.putback(c);
        is >> u;
    }

    if (is)
        x = complex<float>(u,v);

    return is;
}

#ifdef RW_STD_IOSTREAM
template <class T,class charT, class traits>
basic_istream<charT, traits >&  operator>> (basic_istream<charT, traits >& is,complex<double>& x)
#else
istream&  operator>> (istream& is, complex<double>& x)
#endif
{
    //
    // operator >> reads a complex number x in the form
    // u
    // (u)
    // (u, v)
    //
    double u = 0, v = 0;
    char c;

    is >> c;
    if (c == '(')
    {
        is >> u >> c;
        if (c == ',') { is >> v  >> c;}
        if (c != ')' )
        {
#ifdef RW_STD_IOSTREAM
            is.setstate(ios::failbit);
#else
            is.clear(ios::failbit);
#endif
        }
    }
    else
    {
        is.putback(c);
        is >> u;
    }

    if (is)
        x = complex<double>(u,v);

    return is;
}

#ifndef RWSTD_NO_STREAM_LONG_DOUBLE
#ifdef RW_STD_IOSTREAM
template <class T,class charT, class traits>
basic_istream<charT, traits >&  operator>> (basic_istream<charT, traits >& is,complex<long double>& x)
#else
istream&  operator>> (istream& is, complex<long double>& x)
#endif
{
    //
    // operator >> reads a complex number x in the form
    // u
    // (u)
    // (u, v)
    //
    long double u = 0, v = 0;
    char c;

    is >> c;
    if (c == '(')
    {
        is >> u >> c;
        if (c == ',') { is >> v  >> c;}
        if (c != ')' )
        {
#ifdef RW_STD_IOSTREAM
            is.setstate(ios::failbit);
#else
            is.clear(ios::failbit);
#endif
        }
    }
    else
    {
        is.putback(c);
        is >> u;
    }

    if (is)
        x = complex<long double>(u,v);

    return is;
}
#endif /*RWSTD_NO_STREAM_LONG_DOUBLE*/

#ifdef RW_STD_IOSTREAM
template <class T,class charT,class traits>
basic_ostream<charT,traits > >&  operator<< (basic_ostream<charT, traits >& os,const complex<T>& x)
#else
template <class T>
ostream&  operator<< (ostream& os, const complex<T>& x)
#endif
{
    return os << "(" << x.real() << "," << x.imag() << ")";
}

#ifdef RW_STD_IOSTREAM
template <class T,class charT,class traits>
basic_ostream<charT,traits > >&  operator<< (basic_ostream<charT, traits >& os,const complex<float>& x)
#else
ostream&  operator<< (ostream& os, const complex<float>& x)
#endif
{
    return os << "(" << x.real() << "," << x.imag() << ")";
}

#ifdef RW_STD_IOSTREAM
template <class T,class charT,class traits>
basic_ostream<charT,traits > >&  operator<< (basic_ostream<charT, traits >& os,const complex<double>& x)
#else
ostream&  operator<< (ostream& os, const complex<double>& x)
#endif
{
    return os << "(" << x.real() << "," << x.imag() << ")";
}

#ifndef RWSTD_NO_STREAM_LONG_DOUBLE
#ifdef RW_STD_IOSTREAM
template <class T,class charT,class traits>
basic_ostream<charT,traits > >&  operator<< (basic_ostream<charT, traits >& os,const complex<long double>& x)
#else
ostream&  operator<< (ostream& os, const complex<long double>& x)
#endif
{
    return os << "(" << x.real() << "," << x.imag() << ")";
}
#endif /*RWSTD_NO_STREAM_LONG_DOUBLE*/

#if defined(RWSTD_NO_DESTROY_BUILTIN) || defined(RWSTD_NO_DESTROY_NONBUILTIN)
//
// Specializations of STL destroy for complex.
//
inline void destroy (complex<float>**)         {}
inline void destroy (complex<float>***)        {}
inline void destroy (complex<float>****)       {}
inline void destroy (complex<double>**)        {}
inline void destroy (complex<double>***)       {}
inline void destroy (complex<double>****)      {}
inline void destroy (complex<long double>**)   {}
inline void destroy (complex<long double>***)  {}
inline void destroy (complex<long double>****) {}
#endif

 // Export functions

/* template complex<float> RWSTDExportTemplate pow (const complex<float>& a, int n);
 template complex<double> RWSTDExportTemplate pow (const complex<double>& a, int n);
 template complex<long double> RWSTDExportTemplate pow (const complex<long double>& a, int n);
 template complex<float>  RWSTDExportTemplate pow (const complex<float>& a, float s);
 template complex<double>  RWSTDExportTemplate pow (const complex<double>& a, double s);
 template complex<long double>  RWSTDExportTemplate pow (const complex<long double>& a, long double s);
 template complex<float> RWSTDExportTemplate pow (float s, const complex<float>& a);
 template complex<double> RWSTDExporttemplate pow (double s, const complex<double>& a);
 template complex<long double> RWSTDExporttemplate pow (long double s, const complex<long double>& a);
 template complex<float> RWSTDExportTemplate pow (const complex<float>& a1, const complex<float>& a2);
 template complex<double> RWSTDExportTemplate pow (const complex<double>& a1, const complex<double>& a2);
 template complex<long double> RWSTDExportTemplate pow (const complex<long double>& a1, const complex<long double>& a2);
 template complex<float> RWSTDExportTemplate log10 (const complex<float>& a);
 template complex<double> RWSTDExportTemplate log10 (const complex<double>& a);
 template complex<long double> RWSTDExportTemplate log10 (const complex<long double>& a);       */


#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif /* __STD_COMPLEX */

#endif // __USING_STD_NAMES__
