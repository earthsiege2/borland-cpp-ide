/*
   fstream.h -- class filebuf and fstream declarations

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

#ifndef __cplusplus
#error Must use C++ for the type fstream.
#endif

#ifndef __FSTREAM_H
#define __FSTREAM_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__IOSTREAM_H)
#include <iostream.h>
#endif


#if !defined(RC_INVOKED)

#pragma pack(push, 1)

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-     // disable Object data calling convention
#endif
#endif

#if !defined(__TINY__)
#pragma option -RT
#endif

#pragma option -Vo-

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


_CLASSDEF(filebuf)
_CLASSDEF(fstreambase)
_CLASSDEF(ifstream)
_CLASSDEF(ofstream)
_CLASSDEF(fstream)

class  _EXPCLASS filebuf : public streambuf {
public:
static const int openprot;  // default file protection

    // constructors, destructor
    _RTLENTRY filebuf();   // make a closed filebuf
    _RTLENTRY filebuf(int);    // make a filebuf attached to fd
    _RTLENTRY filebuf(int __f, char _FAR *, int); // same, with specified buffer
    _RTLENTRY ~filebuf();

    int _RTLENTRY is_open();   // is the file open
    int _RTLENTRY fd();        // what is the file descriptor

    // open named file with mode and protection, attach to this filebuf
    filebuf _FAR * _RTLENTRY open(const char _FAR *, int, int = filebuf::openprot);

    filebuf _FAR * _RTLENTRY close();      // flush and close file
    filebuf _FAR * _RTLENTRY attach(int);  // attach this filebuf to opened
                                        // file descriptor

/*
 * These perform the streambuf functions on a filebuf
 * Get and Put pointers are kept together
 */
virtual int _RTLENTRY overflow(int = EOF);
virtual int _RTLENTRY underflow();
virtual int _RTLENTRY sync();
virtual streampos  _RTLENTRY seekoff(streamoff, ios::seek_dir, int);
virtual streambuf _FAR * _RTLENTRY setbuf(char _FAR *, int);

#if defined(__FLAT__)
virtual void _RTLENTRY lock();
virtual void _RTLENTRY unlock();
#endif

protected:
    int xfd;        // the file descriptor, EOF if closed
    int mode;       // the opened mode
    short   opened; // non-zero if file is open

    streampos last_seek;    // unused           ***
    char _FAR *   in_start; // unused           ***

    int _RTLENTRY last_op();   // unused           ***
    char    lahead[2];      // current input char if unbuffered ***
};
/*
 * The data members marked with *** above are not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in the use or values of these data members.
 * If you can document any expected behavior of these data members, we
 * will try to adjust our implementation accordingly.
 */
inline int  _RTLENTRY filebuf::is_open()   { return opened; }
inline int  _RTLENTRY filebuf::fd()        { return xfd; }

class _EXPCLASS fstreambase : virtual public ios {
public:
    _RTLENTRY fstreambase();
    _RTLENTRY fstreambase(const char _FAR *, int, int = filebuf::openprot);
    _RTLENTRY fstreambase(int);
    _RTLENTRY fstreambase(int __f, char _FAR *, int);
    _RTLENTRY ~fstreambase();

    void    _RTLENTRY open(const char _FAR *, int, int = filebuf::openprot);
    void    _RTLENTRY attach(int);
    void    _RTLENTRY close();
    void    _RTLENTRY setbuf(char _FAR *, int);
    filebuf _FAR * _RTLENTRY rdbuf();

protected:
    void    _RTLENTRY verify(int); // unimplemented    ***

private:
    filebuf buf;
};
/*
 * The function member marked with *** above is not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in its use.
 * If you can document any expected behavior of this function member, we
 * will try to adjust our implementation accordingly.
 */
inline filebuf _FAR * _RTLENTRY fstreambase::rdbuf() { return &buf; }

class _EXPCLASS ifstream : public fstreambase, public istream {
public:
    _RTLENTRY ifstream();
    _RTLENTRY ifstream(const char _FAR *,int = ios::in,int = filebuf::openprot);
    _RTLENTRY ifstream(int);
    _RTLENTRY ifstream(int __f, char _FAR *, int);
    _RTLENTRY ~ifstream();

    filebuf _FAR * _RTLENTRY rdbuf();
    void    _RTLENTRY open(const char _FAR *, int = ios::in,
                        int = filebuf::openprot);
};
inline filebuf _FAR * _RTLENTRY ifstream::rdbuf() { return fstreambase::rdbuf(); }
inline void _RTLENTRY ifstream::open(const char _FAR * __name, int __m, int __prot) {
    fstreambase::open(__name, __m | ios::in, __prot);
    }


class _EXPCLASS ofstream : public fstreambase, public ostream {
public:
    _RTLENTRY ofstream();
    _RTLENTRY ofstream(const char _FAR *, int = ios::out, int = filebuf::openprot);
    _RTLENTRY ofstream(int);
    _RTLENTRY ofstream(int __f, char _FAR *, int);
    _RTLENTRY ~ofstream();

    filebuf _FAR * _RTLENTRY rdbuf();
    void    _RTLENTRY open(const char _FAR *, int = ios::out,
                        int = filebuf::openprot);
};
inline filebuf _FAR * _RTLENTRY ofstream::rdbuf() { return fstreambase::rdbuf(); }
inline void _RTLENTRY ofstream::open(const char _FAR * __name, int __m, int __prot) {
    fstreambase::open(__name, __m | ios::out, __prot);
    }


class _EXPCLASS fstream : public fstreambase, public iostream {
public:
    _RTLENTRY fstream();
    _RTLENTRY fstream(const char _FAR *, int, int = filebuf::openprot);
    _RTLENTRY fstream(int);
    _RTLENTRY fstream(int __f, char _FAR *, int);
    _RTLENTRY ~fstream();

    filebuf _FAR * _RTLENTRY rdbuf();
    void    _RTLENTRY open(const char _FAR *, int, int = filebuf::openprot);
};
inline filebuf _FAR * _RTLENTRY fstream::rdbuf() {return fstreambase::rdbuf();}
inline void _RTLENTRY fstream::open(const char _FAR * __name, int __m, int __prot) {
    fstreambase::open(__name, __m, __prot);
    }


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#pragma option -Vo.

#if !defined(__TINY__)
#pragma option -RT.
#endif

#if defined(__BCOPT__)
#if !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po.     // restore Object data calling convention
#endif
#endif

/* restore default packing */
#pragma pack(pop)

#endif  /* !RC_INVOKED */


#endif  /* __FSTREAM_H */
