/*  bcd.h

    BCD Number Library - Include File
    class bcd:  declarations for decimal numbers.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $ */


#ifndef __BCD_H
#define __BCD_H

#ifndef __cplusplus
#error Must use C++ for the type bcd.
#endif

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(__MATH_H)
#include <math.h>
#endif

#include <iosfwd>

#if !defined(RC_INVOKED)

#pragma pack(push, 1)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#define _BcdMaxDecimals     5000

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
    friend inline long double _RTLENTRY real(const bcd  &);   // Return the real part

    // Overloaded ANSI C math functions
    friend inline bcd _RTLENTRY _EXPFUNC abs(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC acos(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC asin(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC atan(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC cos(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC cosh(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC exp(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC log(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC log10(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC pow(const bcd  & base, const bcd  & expon);
    friend inline bcd _RTLENTRY _EXPFUNC sin(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC sinh(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC sqrt(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC tan(const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC tanh(const bcd  &);

    // Binary Operator Functions
    friend inline bcd _RTLENTRY _EXPFUNC operator+(const bcd  &, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator+(long double, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator+(const bcd  &, long double);
    friend inline bcd _RTLENTRY _EXPFUNC operator-(const bcd  &, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator-(long double, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator-(const bcd  &, long double);
    friend inline bcd _RTLENTRY _EXPFUNC operator*(const bcd  &, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator*(const bcd  &, long double);
    friend inline bcd _RTLENTRY _EXPFUNC operator*(long double, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator/(const bcd  &, const bcd  &);
    friend inline bcd _RTLENTRY _EXPFUNC operator/(const bcd  &, long double);
    friend inline bcd _RTLENTRY _EXPFUNC operator/(long double, const bcd  &);
    friend inline int _RTLENTRY _EXPFUNC operator==(const bcd  &, const bcd  &);
    friend inline int _RTLENTRY _EXPFUNC operator!=(const bcd  &, const bcd  &);
    friend inline int _RTLENTRY _EXPFUNC operator>=(const bcd  &, const bcd  &);
    friend inline int _RTLENTRY _EXPFUNC operator<=(const bcd  &, const bcd  &);
    friend inline int _RTLENTRY _EXPFUNC operator>(const bcd  &, const bcd  &);
    friend inline int _RTLENTRY _EXPFUNC operator<(const bcd  &, const bcd  &);
    bcd  & _RTLENTRY operator+=(const bcd  &);
    bcd  & _RTLENTRY operator+=(long double);
    bcd  & _RTLENTRY operator-=(const bcd  &);
    bcd  & _RTLENTRY operator-=(long double);
    bcd  & _RTLENTRY operator*=(const bcd  &);
    bcd  & _RTLENTRY operator*=(long double);
    bcd  & _RTLENTRY operator/=(const bcd  &);
    bcd  & _RTLENTRY operator/=(long double);
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
    long double _RTLENTRY _EXPFUNC __bcd_tobinary (const bcd *p);
    void        _RTLENTRY _EXPFUNC __bcd_todecimal(long double x, int decimals, bcd *p);
    long double _RTLENTRY _EXPFUNC __bcd_log10    (const bcd *p);
    void        _RTLENTRY _EXPFUNC __bcd_pow10    (int n, bcd *p);
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

inline long double _RTLENTRY real(const bcd  &z)
{
    return __bcd_tobinary(&z);
}

// Definitions of compound-assignment operator member functions

inline bcd& _RTLENTRY bcd::operator+=(const bcd  &b)
{
    __bcd_todecimal(real(*this)+real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator+=(long double b)
{
    __bcd_todecimal(real(*this)+b,_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator-=(const bcd  &b)
{
    __bcd_todecimal(real(*this)-real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator-=(long double b)
{
    __bcd_todecimal(real(*this)-b,_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator*=(const bcd  &b)
{
    __bcd_todecimal(real(*this)*real(b),_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator*=(long double b)
{
    __bcd_todecimal(real(*this)*b,_BcdMaxDecimals,this);
    return *this;
}

inline bcd& _RTLENTRY bcd::operator/=(const bcd  &b)
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

inline bcd _RTLENTRY operator+(const bcd  &a, const bcd  &b)
{
    return bcd(real(a) + real(b));
}

inline bcd _RTLENTRY operator+(long double a, const bcd  &b)
{
    return bcd(a + real(b));
}

inline bcd _RTLENTRY operator+(const bcd  &a, long double b)
{
    return bcd(real(a) + b);
}

inline bcd _RTLENTRY operator-(const bcd  &a, const bcd  &b)
{
    return bcd(real(a) - real(b));
}

inline bcd _RTLENTRY operator-(long double a, const bcd  &b)
{
    return bcd(a - real(b));
}

inline bcd _RTLENTRY operator-(const bcd  &a, long double b)
{
    return bcd(real(a) - b);
}

inline bcd _RTLENTRY operator*(const bcd  &a, const bcd  &b)
{
    return bcd(real(a) * real(b));
}

inline bcd _RTLENTRY operator*(const bcd  &a, long double b)
{
    return bcd(real(a) * b);
}

inline bcd _RTLENTRY operator*(long double a, const bcd  &b)
{
    return bcd(a * real(b));
}

inline bcd _RTLENTRY operator/(const bcd  &a, const bcd   &b)
{
    return bcd(real(a) / real(b));
}

inline bcd _RTLENTRY operator/(long double a, const bcd  &b)
{
    return bcd(a / real(b));
}

inline bcd _RTLENTRY operator/(const bcd  &a, long double b)
{
    return bcd(real(a) / b);
}

inline int _RTLENTRY operator==(const bcd  &a, const bcd  &b)
{
    return real(a) == real(b);
}

inline int _RTLENTRY operator!=(const bcd  &a, const bcd  &b)
{
    return real(a) != real(b);
}

inline int _RTLENTRY operator>=(const bcd  &a, const bcd  &b)
{
    return real(a) >= real(b);
}

inline int _RTLENTRY operator<=(const bcd  &a, const bcd  &b)
{
    return real(a) <= real(b);
}

inline int _RTLENTRY operator>(const bcd  &a, const bcd  &b)
{
    return real(a) > real(b);
}

inline int _RTLENTRY operator<(const bcd  &a, const bcd  &b)
{
    return real(a) < real(b);
}

inline bcd _RTLENTRY bcd::operator+()
{
    return *this;
}

inline bcd _RTLENTRY bcd::operator-()
{
    return bcd(-real(*this));
}

inline bcd _RTLENTRY abs(const bcd& a)   { return bcd(fabs(real(a)));}
inline bcd _RTLENTRY acos(const bcd& a)  { return bcd(acos(real(a)));}
inline bcd _RTLENTRY asin(const bcd& a)  { return bcd(asin(real(a)));}
inline bcd _RTLENTRY atan(const bcd& a)  { return bcd(atan(real(a)));}
inline bcd _RTLENTRY cos(const bcd& a)   { return bcd(cos(real(a)));}
inline bcd _RTLENTRY cosh(const bcd& a)  { return bcd(cosh(real(a)));}
inline bcd _RTLENTRY exp(const bcd& a)   { return bcd(exp(real(a)));}
inline bcd _RTLENTRY log(const bcd& a)   { return bcd(log(real(a)));}
inline bcd _RTLENTRY log10(const bcd& a) { return bcd(__bcd_log10(&a));}
inline bcd _RTLENTRY sin(const bcd& a)   { return bcd(sin(real(a)));}
inline bcd _RTLENTRY sinh(const bcd& a)  { return bcd(sinh(real(a)));}
inline bcd _RTLENTRY sqrt(const bcd& a)  { return bcd(sqrt(real(a)));}
inline bcd _RTLENTRY tan(const bcd& a)   { return bcd(tan(real(a)));}
inline bcd _RTLENTRY tanh(const bcd& a)  { return bcd(tanh(real(a)));}

inline bcd _RTLENTRY pow(const bcd& a, const bcd& b)   { return bcd(pow(real(a),real(b)));}
inline void _RTLENTRY pow10(int n, bcd& a) { __bcd_pow10(n,&a);}

// bcd stream I/O

std::ostream  & _RTLENTRY _EXPFUNC operator<<(std::ostream  &, const bcd  &);
std::istream  & _RTLENTRY _EXPFUNC operator>>(std::istream  &, bcd  &);


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

/* restore default packing */
#pragma pack(pop)

#endif  /* !RC_INVOKED */

#endif  // __BCD_H
