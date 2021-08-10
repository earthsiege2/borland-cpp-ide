/* stdiostream.h -- class stdiobuf and stdiostream declarations

    NOTE: These are inefficient and obsolete.  Use the standard classes and
    functions in <fstream.h> instead.
*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the type stdiostream.
#endif

#ifndef __STDSTREAM_H
#define __STDSTREAM_H

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif

#if !defined( __STDIO_H )
#include <stdio.h>
#endif


#pragma option -Vo-
#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-
#endif

#pragma option -RT

_CLASSDEF(stdiobuf)
_CLASSDEF(stdiostream)

class _EXPCLASS stdiobuf : public streambuf {
public:
    _RTLENTRY stdiobuf(FILE _FAR *);
    FILE _FAR * _RTLENTRY stdiofile();
    _RTLENTRY ~stdiobuf();

    virtual int _RTLENTRY overflow(int=EOF);
    virtual int _RTLENTRY pbackfail(int);
    virtual int _RTLENTRY sync();
    virtual streampos _RTLENTRY seekoff(streamoff, ios::seek_dir, int);
    virtual int _RTLENTRY underflow();

private:
    FILE _FAR * sio;            
    char    lahead[2];
};
inline  FILE _FAR * _RTLENTRY stdiobuf::stdiofile() { return sio; }


class _EXPCLASS stdiostream : public ios {
public:
        _RTLENTRY stdiostream(FILE _FAR *);
        _RTLENTRY ~stdiostream();
    stdiobuf _FAR * _RTLENTRY rdbuf();

private:
    stdiobuf buf;
};
inline  stdiobuf _FAR * _RTLENTRY stdiostream::rdbuf() { return &buf; }

#pragma option -RT.

#pragma option -Vo.
#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__) 
#pragma option -po.
#endif

#endif   /* __STDSTREAM_H */

