/*  
   fstream.h -- class filebuf and fstream declarations

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

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

#pragma option -a-
#pragma option -Vo-
#pragma option  -RT


#if !defined(__FLAT__)

#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-
#endif

_CLASSDEF(filebuf)
_CLASSDEF(fstreambase)
_CLASSDEF(ifstream)
_CLASSDEF(ofstream)
_CLASSDEF(fstream)

class  _CLASSTYPE filebuf : public streambuf {
public:
static const int openprot;  // default file protection

    // constructors, destructor
    _Cdecl filebuf();   // make a closed filebuf
    _Cdecl filebuf(int);    // make a filebuf attached to fd
    _Cdecl filebuf(int __f, char _FAR *, int); // same, with specified buffer
    _Cdecl ~filebuf();

    int _Cdecl is_open();   // is the file open
    int _Cdecl fd();        // what is the file descriptor

    // open named file with mode and protection, attach to this filebuf
    filebuf _FAR * _Cdecl open(const char _FAR *, int, int = filebuf::openprot);

    filebuf _FAR * _Cdecl close();      // flush and close file
    filebuf _FAR * _Cdecl attach(int);  // attach this filebuf to opened
                                        // file descriptor

/*
 * These perform the streambuf functions on a filebuf
 * Get and Put pointers are kept together
 */
virtual int _Cdecl overflow(int = EOF);
virtual int _Cdecl underflow();
virtual int _Cdecl sync();
virtual streampos  _Cdecl seekoff(streamoff, ios::seek_dir, int);
virtual streambuf _FAR * _Cdecl setbuf(char _FAR *, int);

protected:
    int xfd;        // the file descriptor, EOF if closed
    int mode;       // the opened mode
    short   opened; // non-zero if file is open

    streampos last_seek;    // unused           ***
    char _FAR *   in_start; // unused           ***

    int _Cdecl last_op();   // unused           ***
    char    lahead[2];      // current input char if unbuffered ***
};
/*
 * The data members marked with *** above are not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in the use or values of these data members.
 * If you can document any expected behavior of these data members, we
 * will try to adjust our implementation accordingly.
 */
inline int  _Cdecl filebuf::is_open()   { return opened; }
inline int  _Cdecl filebuf::fd()        { return xfd; }

class _CLASSTYPE fstreambase : virtual public ios {
public:
    _Cdecl fstreambase();
    _Cdecl fstreambase(const char _FAR *, int, int = filebuf::openprot);
    _Cdecl fstreambase(int);
    _Cdecl fstreambase(int __f, char _FAR *, int);
    _Cdecl ~fstreambase();

    void    _Cdecl open(const char _FAR *, int, int = filebuf::openprot);
    void    _Cdecl attach(int);
    void    _Cdecl close();
    void    _Cdecl setbuf(char _FAR *, int);
    filebuf _FAR * _Cdecl rdbuf();

protected:
    void    _Cdecl verify(int); // unimplemented    ***

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
inline filebuf _FAR * _Cdecl fstreambase::rdbuf() { return &buf; }

class _CLASSTYPE ifstream : public fstreambase, public istream {
public:
    _Cdecl ifstream();
    _Cdecl ifstream(const char _FAR *,int = ios::in,int = filebuf::openprot);
    _Cdecl ifstream(int);
    _Cdecl ifstream(int __f, char _FAR *, int);
    _Cdecl ~ifstream();

    filebuf _FAR * _Cdecl rdbuf();
    void    _Cdecl open(const char _FAR *, int = ios::in,
                        int = filebuf::openprot);
};
inline filebuf _FAR * _Cdecl ifstream::rdbuf() { return fstreambase::rdbuf(); }
inline void _Cdecl ifstream::open(const char _FAR * __name, int __m, int __prot) {
    fstreambase::open(__name, __m | ios::in, __prot);
    }


class _CLASSTYPE ofstream : public fstreambase, public ostream {
public:
    _Cdecl ofstream();
    _Cdecl ofstream(const char _FAR *, int = ios::out, int = filebuf::openprot);
    _Cdecl ofstream(int);
    _Cdecl ofstream(int __f, char _FAR *, int);
    _Cdecl ~ofstream();

    filebuf _FAR * _Cdecl rdbuf();
    void    _Cdecl open(const char _FAR *, int = ios::out,
                        int = filebuf::openprot);
};
inline filebuf _FAR * _Cdecl ofstream::rdbuf() { return fstreambase::rdbuf(); }
inline void _Cdecl ofstream::open(const char _FAR * __name, int __m, int __prot) {
    fstreambase::open(__name, __m | ios::out, __prot);
    }

 
class _CLASSTYPE fstream : public fstreambase, public iostream {
public:
    _Cdecl fstream();
    _Cdecl fstream(const char _FAR *, int, int = filebuf::openprot);
    _Cdecl fstream(int);
    _Cdecl fstream(int __f, char _FAR *, int);
    _Cdecl ~fstream();

    filebuf _FAR * _Cdecl rdbuf();
    void    _Cdecl open(const char _FAR *, int, int = filebuf::openprot);
};
inline filebuf _FAR * _Cdecl fstream::rdbuf() {return fstreambase::rdbuf();}
inline void _Cdecl fstream::open(const char _FAR * __name, int __m, int __prot) {
    fstreambase::open(__name, __m, __prot);
    }

#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__) 
#pragma option -po.
#endif

#else  /* defined __FLAT__ */

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
    _RTLENTRY filebuf(int _f, char *, int); // same, with specified buffer
    _RTLENTRY ~filebuf();

    int _RTLENTRY is_open();   // is the file open
    int _RTLENTRY fd();        // what is the file descriptor

    // open named file with mode and protection, attach to this filebuf
    filebuf* _RTLENTRY open( const char *, int,
                                int = filebuf::openprot );

    filebuf* _RTLENTRY close();      // flush and close file
    filebuf* _RTLENTRY attach(int);  // attach this filebuf to opened
                                        // file descriptor

/*
 * These perform the streambuf functions on a filebuf
 * Get and Put pointers are kept together
 */
virtual int _RTLENTRY overflow(int = EOF);
virtual int _RTLENTRY underflow();
virtual int _RTLENTRY sync();
virtual streampos  _RTLENTRY seekoff(streamoff, ios::seek_dir, int);
virtual streambuf* _RTLENTRY setbuf(char *, int);
virtual void _RTLENTRY lock();
virtual void _RTLENTRY unlock();

protected:
    int xfd;        // the file descriptor, EOF if closed
    int mode;       // the opened mode
    short   opened; // non-zero if file is open

    streampos last_seek;    // unused           ***
    char *   in_start; // unused           ***

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
    _RTLENTRY fstreambase(const char *, int, int = filebuf::openprot);
    _RTLENTRY fstreambase(int);
    _RTLENTRY fstreambase(int _f, char *, int);
    _RTLENTRY ~fstreambase();

    void    _RTLENTRY open(const char *, int, int = filebuf::openprot);
    void    _RTLENTRY attach(int);
    void    _RTLENTRY close();
    void    _RTLENTRY setbuf(char *, int);
    filebuf* _RTLENTRY rdbuf();

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
inline filebuf* _RTLENTRY fstreambase::rdbuf() { return &buf; }


class _EXPCLASS ifstream : public fstreambase, public istream {
public:
    _RTLENTRY ifstream();
    _RTLENTRY ifstream(const char *,int = ios::in,int = filebuf::openprot);
    _RTLENTRY ifstream(int);
    _RTLENTRY ifstream(int _f, char *, int);
    _RTLENTRY ~ifstream();

    filebuf* _RTLENTRY rdbuf();
    void    _RTLENTRY open(const char *, int = ios::in,
                        int = filebuf::openprot);
};
inline filebuf* _RTLENTRY ifstream::rdbuf() { return fstreambase::rdbuf(); }
inline void _RTLENTRY ifstream::open(const char * name, int m, int prot) {
                fstreambase::open(name, m | ios::in, prot);
                }


class _EXPCLASS ofstream : public fstreambase, public ostream {
public:
    _RTLENTRY ofstream();
    _RTLENTRY ofstream(const char *, int = ios::out,
                    int = filebuf::openprot);
    _RTLENTRY ofstream(int);
    _RTLENTRY ofstream(int _f, char *, int);
    _RTLENTRY ~ofstream();

    filebuf* _RTLENTRY rdbuf();
    void    _RTLENTRY open(const char *, int = ios::out,
                        int = filebuf::openprot);
};
inline filebuf* _RTLENTRY ofstream::rdbuf() { return fstreambase::rdbuf(); }
inline void _RTLENTRY ofstream::open(const char * name, int m, int prot) {
                fstreambase::open(name, m | ios::out, prot);
                }


class _EXPCLASS fstream : public fstreambase, public iostream {
public:
    _RTLENTRY fstream();
    _RTLENTRY fstream(const char *, int, int = filebuf::openprot);
    _RTLENTRY fstream(int);
    _RTLENTRY fstream(int _f, char *, int);
    _RTLENTRY ~fstream();

    filebuf* _RTLENTRY rdbuf();
    void    _RTLENTRY open(const char *, int, int = filebuf::openprot);
};
inline filebuf* _RTLENTRY fstream::rdbuf() {return fstreambase::rdbuf();}
inline void _RTLENTRY fstream::open(const char * name, int m, int prot) {
                fstreambase::open(name, m, prot);
                }

#endif  /* __FLAT__ */

#pragma option -RT.
#pragma option -Vo.
#pragma option -a. /* restore default packing */

#endif  /* __FSTREAM_H */
