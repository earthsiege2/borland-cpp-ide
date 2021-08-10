/*  iomanip.h -- streams I/O manipulator declarations

*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1990, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the io stream manipulators.
#endif

#ifndef __IOMANIP_H
#define __IOMANIP_H

#if !defined(___DEFS_H)
#include <_defs.h>
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


template<class typ> class _EXPCLASS smanip {
        ios _FAR & (_RTLENTRY *_fn)(ios _FAR &, typ);
        typ _ag;
public:
        _RTLENTRY smanip(ios _FAR & (_RTLENTRY *_f)(ios _FAR &, typ), typ _a) :
                _fn(_f), _ag(_a) { }
        friend istream _FAR & _RTLENTRY operator>>(istream _FAR & _s, smanip<typ> _FAR & _f) {
                        (*_f._fn)(_s, _f._ag); return _s; }
        friend ostream _FAR & _RTLENTRY operator<<(ostream _FAR & _s, smanip<typ> _FAR & _f) {
                        (*_f._fn)(_s, _f._ag); return _s; }
        };

template<class typ> class _EXPCLASS sapp {
        ios _FAR & (_RTLENTRY *_fn)(ios _FAR &, typ);
public:
        sapp(ios _FAR & (_RTLENTRY *_f)(ios _FAR &, typ)) : _fn(_f) { }
        smanip<typ> _RTLENTRY operator()(typ _z)
                { return smanip<typ>(_fn, _z); }
        };

template<class typ> class _EXPCLASS imanip {
        istream _FAR & (_RTLENTRY *_fn)(istream _FAR &, typ);
        typ _ag;
public:
        _RTLENTRY imanip(istream _FAR & (_RTLENTRY *_f)(istream _FAR &, typ), typ _z ) :
                _fn(_f), _ag(_z) { }
        friend istream _FAR & _RTLENTRY operator>>(istream _FAR & _s, imanip<typ> _FAR & _f) {
                return(*_f._fn)(_s, _f._ag); }
        };

template<class typ> class _EXPCLASS iapply {
        istream _FAR & (_RTLENTRY *_fn)(istream _FAR &, typ);
public:
        _RTLENTRY iapply(istream _FAR & (_RTLENTRY *_f)(istream _FAR &, typ)) :
                _fn(_f) { }
        imanip<typ> _RTLENTRY operator()(typ _z) {
                return IMANIP(typ)(_fn, _z); }
        };

template<class typ> class _EXPCLASS omanip {
        ostream _FAR & (_RTLENTRY *_fn)(ostream _FAR &, typ);
        typ _ag;
public:
        _RTLENTRY omanip(ostream _FAR & (_RTLENTRY *_f)(ostream _FAR &, typ), typ _z ) :
                _fn(_f), _ag(_z) { }
        friend ostream _FAR & _RTLENTRY operator<<(ostream _FAR & _s, omanip<typ> _FAR & _f) {
                return(*_f._fn)(_s, _f._ag); }
        };

template<class typ> class _EXPCLASS oapp {
        ostream _FAR & (_RTLENTRY *_fn)(ostream _FAR &, typ);
public:
        _RTLENTRY oapp(ostream _FAR & (_RTLENTRY *_f)(ostream _FAR &, typ)) :
                _fn(_f) { }
        omanip<typ> _RTLENTRY operator()(typ _z) {
                return omanip<typ>(_fn, _z); }
        };

template<class typ> class _EXPCLASS iomanip {
        iostream _FAR & (_RTLENTRY *_fn)(iostream _FAR &, typ);
        typ _ag;
public:
        _RTLENTRY iomanip(iostream _FAR & (_RTLENTRY *_f)(iostream _FAR &, typ), typ _z ) :
                _fn(_f), _ag(_z) { }
        friend istream _FAR & _RTLENTRY operator>>(iostream _FAR & _s, iomanip<typ> _FAR & _f) {
                return(*_f._fn)(_s, _f._ag); }
        friend ostream _FAR & _RTLENTRY operator<<(iostream _FAR & _s, iomanip<typ> _FAR & _f) {
                return(*_f._fn)(_s, _f._ag); }
        };

template<class typ> class _EXPCLASS ioapp {
        iostream _FAR & (_RTLENTRY *_fn)(iostream _FAR &, typ);
public:
        _RTLENTRY ioapp(iostream _FAR & (_RTLENTRY *_f)(iostream _FAR &, typ)) : _fn(_f) { }
        iomanip<typ> _RTLENTRY operator()(typ _z) {
                return iomanip<typ>(_fn, _z); }
        };

// set the conversion base to 0, 8, 10, or 16
smanip<int>     _RTLENTRY _EXPFUNC setbase(int _b);

// clear the flags bitvector according to the bits set in b
smanip<long>    _RTLENTRY _EXPFUNC resetiosflags(long _b);

// set the flags bitvector according to the bits set in b
smanip<long>    _RTLENTRY _EXPFUNC setiosflags(long _b);

// set fill character for padding a field
smanip<int>     _RTLENTRY _EXPFUNC setfill(int _f);

// set the floating-point precision to n digits
smanip<int>     _RTLENTRY _EXPFUNC setprecision(int _n);

// set the field width to n
smanip<int>     _RTLENTRY _EXPFUNC setw(int _n);


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


#endif  /* __IOMANIP_H */
