/*  bcd.h

    BCD Number Library - Include File
    class bcd:  declarations for decimal numbers.

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the type bcd.
#endif

#if !defined(__BCD_H)
#define __BCD_H

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

#pragma option -a-

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


#define _BcdMaxDecimals     5000

_CLASSDEF(bcd)

class _EXPCLASS bcd {

public:
    // constructors
    _RTLENTRY bcd();
    _RTLENTRY bcd(int x);
    _RTLENTRY bcd(unsigned int x);
    _RTLENTRY bcd(long x);
    _RTLENTRY bcd(unsigned long x);
    _RTLENTRY bcd(double x, int decimals = _BcdMaxDecimals);
    _RTLENTRY bcd(long double x, int decimals = _BcdMaxDecimals);

    // bcd manipulations
    friend long double _RTLENTRY real(bcd _FAR &);   // Return the real part

    // Overloaded ANSI C math functions
    friend bcd _RTLENTRY _EXPFUNC abs(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC acos(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC asin(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC atan(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC cos(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC cosh(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC exp(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC log(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC log10(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC pow(bcd _FAR & base, bcd _FAR & expon);
    friend bcd _RTLENTRY _EXPFUNC sin(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC sinh(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC sqrt(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC tan(bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC tanh(bcd _FAR &);

    // Binary Operator Functions
    friend bcd _RTLENTRY _EXPFUNC operator+(bcd _FAR &, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator+(long double, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator+(bcd _FAR &, long double);
    friend bcd _RTLENTRY _EXPFUNC operator-(bcd _FAR &, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator-(long double, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator-(bcd _FAR &, long double);
    friend bcd _RTLENTRY _EXPFUNC operator*(bcd _FAR &, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator*(bcd _FAR &, long double);
    friend bcd _RTLENTRY _EXPFUNC operator*(long double, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator/(bcd _FAR &, bcd _FAR &);
    friend bcd _RTLENTRY _EXPFUNC operator/(bcd _FAR &, long double);
    friend bcd _RTLENTRY _EXPFUNC operator/(long double, bcd _FAR &);
    friend int _RTLENTRY _EXPFUNC operator==(bcd _FAR &, bcd _FAR &);
    friend int _RTLENTRY _EXPFUNC operator!=(bcd _FAR &, bcd _FAR &);
    friend int _RTLENTRY _EXPFUNC operator>=(bcd _FAR &, bcd _FAR &);
    friend int _RTLENTRY _EXPFUNC operator<=(bcd _FAR &, bcd _FAR &);
    friend int _RTLENTRY _EXPFUNC operator>(bcd _FAR &, bcd _FAR &);
    friend int _RTLENTRY _EXPFUNC operator<(bcd _FAR &, bcd _FAR &);
    bcd _FAR & _RTLENTRY operator+=(bcd _FAR &);
    bcd _FAR & _RTLENTRY operator+=(long double);
    bcd _FAR & _RTLENTRY operator-=(bcd _FAR &);
    bcd _FAR & _RTLENTRY operator-=(long double);
    bcd _FAR & _RTLENTRY operator*=(bcd _FAR &);
    bcd _FAR & _RTLENTRY operator*=(long double);
    bcd _FAR & _RTLENTRY operator/=(bcd _FAR &);
    bcd _FAR & _RTLENTRY operator/=(long double);
    bcd  _RTLENTRY operator+();
    bcd  _RTLENTRY operator-();

// Implementation
private:
    long mantissa[2];
    int expo;
};

// const bcd _bcd_zero(0);

enum _bcdexpo {
    _ExpoZero,
    _ExpoInf,
    _ExpoNan
};

extern "C"
{
#if defined(__FLAT__)
    long double _RTLENTRY _EXPFUNC __bcd_tobinary (const bcd *p);
    void        _RTLENTRY _EXPFUNC __bcd_todecimal(long double x, int decimals, bcd *p);
    long double _RTLENTRY _EXPFUNC __bcd_log10    (bcd *p);
    void        _RTLENTRY _EXPFUNC __bcd_pow10    (int n, bcd *p);
#else
    long double __pascal _EXPFUNC __bcd_tobinary(const bcd __far *p);
    void        __pascal _EXPFUNC __bcd_todecimal(long double x, int decimals, bcd __far *p);
    long double __pascal _EXPFUNC __bcd_log10(bcd __far *p);
    void        __pascal _EXPFUNC __bcd_pow10(int n, bcd __far *p);
#endif
}

inline _RTLENTRY bcd::bcd()
{
/* if you want zero ...
    mantissa[0] = 0;
    mantissa[1] = 0;
    expo = ExpoZero;
*/
}

inline _RTLENTRY bcd::bcd(long double x, int decimals)
{
    __bcd_todecimal(x,decimals,this);
}

inline _RTLENTRY bcd::bcd(double x, int decimals)
{
    __bcd_todecimal(x,decimals,this);
}

inline _RTLENTRY bcd::bcd(int x)
{
    mantissa[0] = x;
    mantissa[1] = x >= 0 ? 0 : -1;
    expo = 0;
}

inline _RTLENTRY bcd::bcd(unsigned int x)
{
    mantissa[0] = x;
    mantissa[1] = 0;
    expo = 0;
}

inline _RTLENTRY bcd::bcd(long x)
{
    mantissa[0] = x;
    mantissa[1] = x >= 0 ? 0 : -1;
    expo = 0;
}

inline _RTLENTRY bcd::bcd(unsigned long x)
{
    mantissa[0] = x;
    mantissa[1] = 0;
    expo = 0;
}

inline long double _RTLENTRY real(bcd _FAR &z)
{
    return __bcd_tobinary(&z);
}

// Definitions of compound-assignment operator member functions

inline bcd& _RTLENTRY bcd::operator+=(bcd _FAR &b)
{
    __bcd_todecimal(real(*this)+real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator+=(long double b)
{
    __bcd_todecimal(real(*this)+b,_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator-=(bcd _FAR &b)
{
    __bcd_todecimal(real(*this)-real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator-=(long double b)
{
    __bcd_todecimal(real(*this)-b,_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator*=(bcd _FAR &b)
{
    __bcd_todecimal(real(*this)*real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator*=(long double b)
{
    __bcd_todecimal(real(*this)*b,_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator/=(bcd _FAR &b)
{
    __bcd_todecimal(real(*this)/real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator/=(long double b)
{
    __bcd_todecimal(real(*this)/b,_BcdMaxDecimals,this);
    return *this;
}


// Definitions of non-member binary operator functions

inline bcd _RTLENTRY operator+(bcd _FAR &a, bcd _FAR &b)
{
    return bcd(real(a) + real(b));
}

inline bcd _RTLENTRY operator+(long double a, bcd _FAR &b)
{
    return bcd(a + real(b));
}

inline bcd _RTLENTRY operator+(bcd _FAR &a, long double b)
{
    return bcd(real(a) + b);
}

inline bcd _RTLENTRY operator-(bcd _FAR &a, bcd _FAR &b)
{
    return bcd(real(a) - real(b));
}

inline bcd _RTLENTRY operator-(long double a, bcd _FAR &b)
{
    return bcd(a - real(b));
}

inline bcd _RTLENTRY operator-(bcd _FAR &a, long double b)
{
    return bcd(real(a) - b);
}

inline bcd _RTLENTRY operator*(bcd _FAR &a, bcd _FAR &b)
{
    return bcd(real(a) * real(b));
}

inline bcd _RTLENTRY operator*(bcd _FAR &a, long double b)
{
    return bcd(real(a) * b);
}

inline bcd _RTLENTRY operator*(long double a, bcd _FAR &b)
{
    return bcd(a * real(b));
}

inline bcd _RTLENTRY operator/(bcd _FAR &a, bcd  _FAR &b)
{
    return bcd(real(a) / real(b));
}

inline bcd _RTLENTRY operator/(long double a, bcd _FAR &b)
{
    return bcd(a / real(b));
}

inline bcd _RTLENTRY operator/(bcd _FAR &a, long double b)
{
    return bcd(real(a) / b);
}

inline int _RTLENTRY operator==(bcd _FAR &a, bcd _FAR &b)
{
    return real(a) == real(b);
}

inline int _RTLENTRY operator!=(bcd _FAR &a, bcd _FAR &b)
{
    return real(a) != real(b);
}

inline int _RTLENTRY operator>=(bcd _FAR &a, bcd _FAR &b)
{
    return real(a) >= real(b);
}

inline int _RTLENTRY operator<=(bcd _FAR &a, bcd _FAR &b)
{
    return real(a) <= real(b);
}

inline int _RTLENTRY operator>(bcd _FAR &a, bcd _FAR &b)
{
    return real(a) > real(b);
}

inline int _RTLENTRY operator<(bcd _FAR &a, bcd _FAR &b)
{
    return real(a) < real(b);
}

inline bcd _RTLENTRY bcd::operator+()
{
    return *this;
}

inline bcd _RTLENTRY bcd::operator-()
{
//  return bcd(-real(this));

// 1's comp
    mantissa[0] = - ++ mantissa[0];
    mantissa[1] = - ++ mantissa[1];
// inc
    if (++mantissa[0] == 0) ++mantissa[1];
    return *this;
}

inline bcd _RTLENTRY abs(bcd& a)   { return bcd(fabs(real(a)));}
inline bcd _RTLENTRY acos(bcd& a)  { return bcd(acos(real(a)));}
inline bcd _RTLENTRY asin(bcd& a)  { return bcd(asin(real(a)));}
inline bcd _RTLENTRY atan(bcd& a)  { return bcd(atan(real(a)));}
inline bcd _RTLENTRY cos(bcd& a)   { return bcd(cos(real(a)));}
inline bcd _RTLENTRY cosh(bcd& a)  { return bcd(cosh(real(a)));}
inline bcd _RTLENTRY exp(bcd& a)   { return bcd(exp(real(a)));}
inline bcd _RTLENTRY log(bcd& a)   { return bcd(log(real(a)));}
inline bcd _RTLENTRY log10(bcd& a) { return bcd(__bcd_log10(&a));}
inline bcd _RTLENTRY sin(bcd& a)   { return bcd(sin(real(a)));}
inline bcd _RTLENTRY sinh(bcd& a)  { return bcd(sinh(real(a)));}
inline bcd _RTLENTRY sqrt(bcd& a)  { return bcd(sqrt(real(a)));}
inline bcd _RTLENTRY tan(bcd& a)   { return bcd(tan(real(a)));}
inline bcd _RTLENTRY tanh(bcd& a)  { return bcd(tanh(real(a)));}

inline bcd _RTLENTRY pow(bcd& a, bcd& b)   { return bcd(pow(real(a),real(b)));}
inline void _RTLENTRY pow10(int n, bcd& a) { __bcd_pow10(n,&a);}

// bcd stream I/O

#if defined(__FLAT__)
ostream _FAR & _RTLENTRY _EXPFUNC operator<<(ostream _FAR &, bcd _FAR &);
istream _FAR & _RTLENTRY _EXPFUNC operator>>(istream _FAR &, bcd _FAR &);
#else
ostream _FAR & __pascal _EXPFUNC operator<<(ostream _FAR &, bcd _FAR &);
istream _FAR & __pascal _EXPFUNC operator>>(istream _FAR &, bcd _FAR &);
#endif


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

#pragma option -a.

#endif  /* !RC_INVOKED */


#endif  // __BCD_H


