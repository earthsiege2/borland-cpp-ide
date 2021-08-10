/*  strstream.h -- class strstream declarations

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the type strstream.
#endif

#ifndef __STRSTREAM_H
#define __STRSTREAM_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__IOSTREAM_H)
#include <iostream.h>
#endif

#pragma option -Vo-
#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-
#endif

#pragma option -a-
#pragma option -RT

_CLASSDEF(strstreambuf)
_CLASSDEF(strstreambase)
_CLASSDEF(istrstream)
_CLASSDEF(ostrstream)
_CLASSDEF(strstream)

class _EXPCLASS strstreambuf : public streambuf {
public:
    _RTLENTRY strstreambuf();
    _RTLENTRY strstreambuf(int n);
    _RTLENTRY strstreambuf(void _FAR * (*a)(long), void (*f)(void _FAR *));
    _RTLENTRY strstreambuf(         char _FAR * _s, int,
                                    char _FAR * _strt=0);
    _RTLENTRY strstreambuf(signed   char _FAR * _s, int,
                           signed   char _FAR * _strt=0);
    _RTLENTRY strstreambuf(unsigned char _FAR * _s, int,
                           unsigned char _FAR * _strt=0);
    _RTLENTRY ~strstreambuf();

    void    _RTLENTRY freeze(int = 1);
    char _FAR *  _RTLENTRY str();
virtual int _RTLENTRY doallocate();
virtual int _RTLENTRY overflow(int);
virtual int _RTLENTRY underflow();
virtual int _RTLENTRY sync();
virtual streambuf _FAR * _RTLENTRY setbuf(char _FAR *, int);
virtual streampos   _RTLENTRY seekoff(streamoff, ios::seek_dir, int);

private:
    void _FAR *  _RTLENTRY (*allocf)(long);
    void    _RTLENTRY (*freef)(void _FAR *);
    short   ssbflags;
    enum    { dynamic = 1, frozen = 2, unlimited = 4 };
    int next_alloc;

    void    _RTLENTRY init(char _FAR *, int, char _FAR *);
};


class _EXPCLASS strstreambase : public virtual ios {
public:
    strstreambuf _FAR * _RTLENTRY rdbuf();

protected:
        _RTLENTRY strstreambase(char _FAR *, int, char _FAR *);
        _RTLENTRY strstreambase();
        _RTLENTRY ~strstreambase();
private:
        strstreambuf buf;
};
inline strstreambuf _FAR * _RTLENTRY strstreambase::rdbuf()
                                    { return &this->buf; }


class _EXPCLASS istrstream : public strstreambase, public istream {
public:
        _RTLENTRY istrstream(         char _FAR *);
        _RTLENTRY istrstream(signed   char _FAR *);
        _RTLENTRY istrstream(unsigned char _FAR *);
        _RTLENTRY istrstream(         char _FAR *, int);
        _RTLENTRY istrstream(signed   char _FAR *, int);
        _RTLENTRY istrstream(unsigned char _FAR *, int);
        _RTLENTRY ~istrstream();
};


class _EXPCLASS ostrstream : public strstreambase, public ostream {
public:
        _RTLENTRY ostrstream(         char _FAR *, int, int = ios::out);
        _RTLENTRY ostrstream(signed   char _FAR *, int, int = ios::out);
        _RTLENTRY ostrstream(unsigned char _FAR *, int, int = ios::out);
        _RTLENTRY ostrstream();
        _RTLENTRY ~ostrstream();

    char _FAR * _RTLENTRY str();
    int     _RTLENTRY pcount();
};
inline char _FAR * _RTLENTRY ostrstream::str()
                { return strstreambase::rdbuf()->str(); }
inline int  _RTLENTRY ostrstream::pcount()
                { return strstreambase::rdbuf()->out_waiting(); }


class _EXPCLASS strstream : public strstreambase, public iostream {
public:
        _RTLENTRY strstream();
        _RTLENTRY strstream(         char _FAR *, int _sz, int _m);
        _RTLENTRY strstream(signed   char _FAR *, int _sz, int _m);
        _RTLENTRY strstream(unsigned char _FAR *, int _sz, int _m);
        _RTLENTRY ~strstream();

    char _FAR * _RTLENTRY str();
};
inline char _FAR * _RTLENTRY strstream::str()
                { return strstreambase::rdbuf()->str(); }

#pragma option -Vo.
#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__) 
#pragma option -po.
#endif

#pragma option -RT.
#pragma option -a.  /* restore default packing */

#endif  /* __STRSTREAM_H */
