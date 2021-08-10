/*  iostream.h -- basic stream I/O declarations

    There are some inline functions here which generate a LOT of code
    (as much as 300 bytes), but are available inline because AT&T did
    it that way.  We have also made them true functions in the library
    and conditionally deleted the inline code from this header.

    If you really want these big functions to be inline, #define the
    macro name _BIG_INLINE_ before including this header.

    Programs will compile and link correctly even if some modules are
    compiled with _BIG_INLINE_ and some are not.
*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1990, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef __cplusplus
#error Must use C++ for the type iostream.
#endif

#ifndef __IOSTREAM_H
#define __IOSTREAM_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__MEM_H)
#include <mem.h>    // to get memcpy and NULL
#endif

#pragma option -a-      // byte packing
#pragma option -Vo-     // set standard C++ options
#pragma option -RT

#if defined(__BCOPT__) && !defined(_RTL_ALLOW_po) && !defined(__FLAT__)
#pragma option -po-     // disable Object data calling convention
#endif

// Definition of EOF must match the one in <stdio.h>
#define EOF (-1)

// extract a char from int i, ensuring that zapeof(EOF) != EOF
#define zapeof(i) ((unsigned char)(i))

typedef long streampos;
typedef long streamoff;

_CLASSDEF(ios)
_CLASSDEF(streambuf)
_CLASSDEF(istream)
_CLASSDEF(ostream)
_CLASSDEF(iostream)
_CLASSDEF(istream_withassign)
_CLASSDEF(ostream_withassign)
_CLASSDEF(iostream_withassign)

class _EXPCLASS ios {
public:
    // stream status bits
    enum io_state   {
        goodbit  = 0x00,    // no bit set: all is ok
        eofbit   = 0x01,    // at end of file
        failbit  = 0x02,    // last I/O operation failed
        badbit   = 0x04,    // invalid operation attempted
        hardfail = 0x80     // unrecoverable error
        };

    // stream operation mode
    enum open_mode  {
        in   = 0x01,        // open for reading
        out  = 0x02,        // open for writing
        ate  = 0x04,        // seek to eof upon original open
        app  = 0x08,        // append mode: all additions at eof
        trunc    = 0x10,    // truncate file if already exists
        nocreate = 0x20,    // open fails if file doesn't exist
        noreplace= 0x40,    // open fails if file already exists
        binary   = 0x80     // binary (not text) file
        };

    // stream seek direction
    enum seek_dir { beg=0, cur=1, end=2 };

    // formatting flags
    enum    {
        skipws    = 0x0001, // skip whitespace on input
        left      = 0x0002, // left-adjust output
        right     = 0x0004, // right-adjust output
        internal  = 0x0008, // padding after sign or base indicator
        dec   = 0x0010,     // decimal conversion
        oct   = 0x0020,     // octal conversion
        hex   = 0x0040,     // hexadecimal conversion
        showbase  = 0x0080, // use base indicator on output
        showpoint = 0x0100, // force decimal point (floating output)
        uppercase = 0x0200, // upper-case hex output
        showpos   = 0x0400, // add '+' to positive integers
        scientific= 0x0800, // use 1.2345E2 floating notation
        fixed     = 0x1000, // use 123.45 floating notation
        unitbuf   = 0x2000, // flush all streams after insertion
        stdio     = 0x4000  // flush stdout, stderr after insertion
        };

    // constants for second parameter of seft()
static  const long basefield;       // dec | oct | hex
static  const long adjustfield;     // left | right | internal
static  const long floatfield;      // scientific | fixed

    // constructor, destructor
            _RTLENTRY ios(streambuf _FAR *);
virtual     _RTLENTRY ~ios();

    // for reading/setting/clearing format flags
    long    _RTLENTRY flags();
    long    _RTLENTRY flags(long);
    long    _RTLENTRY setf(long _setbits, long _field);
    long    _RTLENTRY setf(long);
    long    _RTLENTRY unsetf(long);

    // reading/setting field width
    int     _RTLENTRY width();
    int     _RTLENTRY width(int);

    // reading/setting padding character
    char    _RTLENTRY fill();
    char    _RTLENTRY fill(char);

    // reading/setting digits of floating precision
    int     _RTLENTRY precision(int);
    int     _RTLENTRY precision();

    // reading/setting ostream tied to this stream
    ostream _FAR * _RTLENTRY tie(ostream _FAR *);
    ostream _FAR * _RTLENTRY tie();

    // find out about current stream state
    int     _RTLENTRY rdstate();       // return the stream state
    int     _RTLENTRY eof();           // non-zero on end of file
    int     _RTLENTRY fail();          // non-zero if an operation failed
    int     _RTLENTRY bad();           // non-zero if error occurred
    int     _RTLENTRY good();          // non-zero if no state bits set
    void    _RTLENTRY clear(int = 0);  // set the stream state
            _RTLENTRY operator void _FAR * (); // zero if state failed
    int     _RTLENTRY operator! ();    // non-zero if state failed

    streambuf _FAR * _RTLENTRY rdbuf();        // get the assigned streambuf

    // for declaring additional flag bits and user words
static long _RTLENTRY bitalloc();  // acquire a new flag bit, value returned
static int  _RTLENTRY xalloc();    // acquire a new user word, index returned
    long    _FAR & _RTLENTRY iword(int);  // return the nth user word as an int
    void    _FAR * _FAR & _RTLENTRY pword(int);  // return the nth user word as a pointer

static void _RTLENTRY sync_with_stdio();

    // obsolete, for streams 1.2 compatibility
    int     _RTLENTRY skip(int);

protected:
    // additional state flags for ispecial and ospecial
    enum { skipping = 0x100, tied = 0x200 };

    streambuf _FAR * bp;    // the associated streambuf
    ostream _FAR * x_tie;   // the tied ostream, if any
    int     state;          // status bits
    int     ispecial;       // istream status bits  ***
    int     ospecial;       // ostream status bits  ***
    long    x_flags;        // formatting flag bits
    int     x_precision;    // floating-point precision on output
    int     x_width;        // field width on output
    int     x_fill;         // padding character on output
    int     isfx_special;   // unused       ***
    int     osfx_special;   // unused       ***
    int     delbuf;         // unused       ***
    int     assign_private; // unused       ***
/*
 * The data members marked with *** above are not documented in the AT&T
 * release of streams, so we cannot guarantee compatibility with any
 * other streams release in the use or values of these data members.
 * If you can document any expected behavior of these data members, we
 * will try to adjust our implementation accordingly.
 */

            _RTLENTRY ios();       // null constructor, does not initialize

    void    _RTLENTRY init(streambuf _FAR *);  // the actual initialization

    void    _RTLENTRY setstate(int);       // set all status bits

static  void _RTLENTRY (*stdioflush)();

private:
    // for extra flag bits and user words
static  long    nextbit;
static  int usercount;
    union ios_user_union _FAR *userwords;
    int     nwords;
    void    _RTLENTRY usersize(int);

    // these declarations prevent automatic copying of an ios
            _RTLENTRY ios(ios _FAR &);           // declared but not defined
    void    _RTLENTRY operator= (ios _FAR &);    // declared but not defined

};
inline streambuf _FAR * _RTLENTRY ios::rdbuf() { return bp; }
inline ostream _FAR * _RTLENTRY ios::tie() { return x_tie; }
inline char     _RTLENTRY ios::fill() { return (char)x_fill; }
inline int      _RTLENTRY ios::precision() { return x_precision; }
inline int      _RTLENTRY ios::rdstate() { return state; }
inline int      _RTLENTRY ios::eof() { return state & eofbit; }
inline int      _RTLENTRY ios::fail()
                        { return state & (failbit | badbit | hardfail); }
inline int      _RTLENTRY ios::bad() { return state & (badbit | hardfail); }
inline int      _RTLENTRY ios::good() { return state == 0; }
inline long     _RTLENTRY ios::flags() { return x_flags; }
inline int      _RTLENTRY ios::width() { return x_width; }
inline int      _RTLENTRY ios::width(int _w)
                        { int _i = x_width; x_width = _w; return _i; }
inline char     _RTLENTRY ios::fill(char _c)
                        { char _x = (char)x_fill; x_fill = _c; return _x; }
inline int      _RTLENTRY ios::precision(int _p)
                        { int _x = x_precision; x_precision = _p; return _x; }
inline          _RTLENTRY ios::operator void _FAR *()
                        { return fail() ? 0 : this; }
inline int      _RTLENTRY ios::operator! () { return fail(); }


class _CLASSTYPE streambuf {
public:
    // constructors and destructors
        _RTLENTRY streambuf();                 // make empty streambuf
        _RTLENTRY streambuf(char _FAR *, int); // make streambuf with
                                            // given char array
virtual _RTLENTRY ~streambuf();

    // use the provided char array for the buffer if possible
virtual streambuf _FAR * _RTLENTRY setbuf(char _FAR *, int);

    // obsolete, for streams 1.2 compatibility
    streambuf _FAR *  _RTLENTRY setbuf(char _FAR *, int, int);

    // getting (extracting) characters
    int     _RTLENTRY sgetc();         // peek at next char
    int     _RTLENTRY snextc();        // advance to and return next char
    int     _RTLENTRY sbumpc();        // return current char and advance
    void    _RTLENTRY stossc();        // advance to next character
    int     _RTLENTRY sgetn(char _FAR *, int);     // get next n chars
virtual int _RTLENTRY do_sgetn(char _FAR *, int);  // implementation of sgetn
virtual int _RTLENTRY underflow();     // fill empty buffer
    int     _RTLENTRY sputbackc(char); // return char to input
virtual int _RTLENTRY pbackfail(int);  // implementation of sputbackc
    int     _RTLENTRY in_avail();      // number of avail chars in buffer

    // putting (inserting) characters
    int     _RTLENTRY sputc(int);          // put one char
    int     _RTLENTRY sputn(const char _FAR *, int); // put n chars from string
virtual int _RTLENTRY do_sputn(const char _FAR * s, int n); // implementation of sputn
virtual int _RTLENTRY overflow(int = EOF); // flush buffer and make more room
    int     _RTLENTRY out_waiting();       // number of unflushed chars

    // moving around in stream
virtual streampos _RTLENTRY seekoff(streamoff, ios::seek_dir,
                                 int = (ios::in | ios::out));
virtual streampos _RTLENTRY seekpos(streampos, int = (ios::in | ios::out));
virtual int _RTLENTRY sync();

#if defined(__FLAT__)
    // locking and unlocking file handle associated with stream
virtual void _RTLENTRY lock();
virtual void _RTLENTRY unlock();
#endif

    void    _RTLENTRY dbp();       // for debugging streambuf implementations

protected:
    char _FAR * _RTLENTRY base();  // return start of buffer area
    char _FAR * _RTLENTRY ebuf();  // return end+1 of buffer area
    int     _RTLENTRY blen();      // return length of buffer area
    char _FAR * _RTLENTRY pbase(); // return start of put area
    char _FAR * _RTLENTRY pptr();  // return next location in put area
    char _FAR * _RTLENTRY epptr(); // return end+1 of put area
    char _FAR * _RTLENTRY eback(); // return base of putback section of get area
    char _FAR * _RTLENTRY gptr();  // return next location in get area
    char _FAR * _RTLENTRY egptr(); // return end+1 of get area
    void    _RTLENTRY setp(char _FAR *, char _FAR *); // initialize the put pointers
    void    _RTLENTRY setg(char _FAR *, char _FAR *, char _FAR *); // initialize the get pointers
    void    _RTLENTRY pbump(int);  // advance the put pointer
    void    _RTLENTRY gbump(int);  // advance the get pointer
    void    _RTLENTRY setb(char _FAR *, char _FAR *, int = 0 );    // set the buffer area
    void    _RTLENTRY unbuffered(int);// set the buffering state
    int     _RTLENTRY unbuffered();    // non-zero if not buffered
    int     _RTLENTRY allocate();  // set up a buffer area
virtual int _RTLENTRY doallocate();    // implementation of allocate

private:
    short   alloc_;     // non-zero if buffer should be deleted
    short   unbuf_;     // non-zero if unbuffered
    char _FAR * base_;  // start of buffer area
    char _FAR * ebuf_;  // end+1 of buffer area
    char _FAR * pbase_; // start of put area
    char _FAR * pptr_;  // next put location
    char _FAR * epptr_; // end+1 of put area
    char _FAR * eback_; // base of putback section of get area
    char _FAR * gptr_;  // next get location
    char _FAR * egptr_; // end+1 of get area

    int     _RTLENTRY do_snextc(); // implementation of snextc

    // these declarations prevent copying of a streambuf
            _RTLENTRY streambuf(streambuf _FAR &);   // declared but not defined
    void    _RTLENTRY operator= (streambuf _FAR &);  // declared but not defined
};
inline char _FAR * _RTLENTRY streambuf::base()  { return base_; }
inline char _FAR * _RTLENTRY streambuf::pbase() { return pbase_; }
inline char _FAR * _RTLENTRY streambuf::pptr()  { return pptr_; }
inline char _FAR * _RTLENTRY streambuf::epptr() { return epptr_; }
inline char _FAR * _RTLENTRY streambuf::gptr()  { return gptr_; }
inline char _FAR * _RTLENTRY streambuf::egptr() { return egptr_; }
inline char _FAR * _RTLENTRY streambuf::eback() { return eback_; }
inline char _FAR * _RTLENTRY streambuf::ebuf()  { return ebuf_; }
inline int   _RTLENTRY streambuf::unbuffered()  { return unbuf_; }
inline int   _RTLENTRY streambuf::blen() { return (int)(ebuf_ - base_);}
inline void _RTLENTRY streambuf::pbump(int _n) { pptr_ += _n; }
inline void _RTLENTRY streambuf::gbump(int _n) { gptr_ += _n; }
inline void _RTLENTRY streambuf::unbuffered(int _unb) { unbuf_ = (short)(_unb != 0); }
inline int  _RTLENTRY streambuf::in_avail()
                { return (egptr_ > gptr_) ? (int)(egptr_ - gptr_) : 0; }
inline int  _RTLENTRY streambuf::out_waiting()
                { return pptr_ ? (int)(pptr_ - pbase_) : 0; }
inline int  _RTLENTRY streambuf::allocate() {
                return (base_ || unbuf_) ? 0 : doallocate();
                }
inline int  _RTLENTRY streambuf::sgetc() {
                return (gptr_ >= egptr_) ? underflow() :
                   (unsigned char)(*gptr_);
                }
inline int  _RTLENTRY streambuf::snextc() {
                return (! gptr_ || (++gptr_ >= egptr_)) ?
                    do_snextc() :
                    (unsigned char)(*gptr_);
                }
inline int  _RTLENTRY streambuf::sbumpc() {
                return (gptr_ >= egptr_ && underflow() == EOF) ?
                    EOF :
                    (unsigned char)(*gptr_++);
                }
inline void _RTLENTRY streambuf::stossc() {
                if( gptr_ >= egptr_ ) underflow();
                else ++gptr_;
                }
inline int  _RTLENTRY streambuf::sputbackc(char _c) {
                return (gptr_ > eback_) ?
                    (unsigned char)(*--gptr_ = _c) :
                    pbackfail(_c);
                }
inline int  _RTLENTRY streambuf::sputc(int _c) {
                return (pptr_ >= epptr_) ?
                    overflow((unsigned char)_c) :
                    (unsigned char)(*pptr_++ = (char)_c);
                }
#ifdef _BIG_INLINE_
inline int  _RTLENTRY streambuf::sputn(const char _FAR * _s, int _n) {
                if( _n <= (epptr_ - pptr_) ) {
                    memcpy(pptr_, _s, _n);
                    pbump(_n);
                    return _n;
                }
                return do_sputn(_s, _n);
                }
inline int  _RTLENTRY streambuf::sgetn(char _FAR * _s, int _n) {
                if( _n <= (egptr_ - gptr_) ) {
                    memcpy(_s, gptr_, _n);
                    gbump(_n);
                    return _n;
                }
                return do_sgetn(_s, _n);
                }
#endif

#if defined(__FLAT__)
inline void _RTLENTRY streambuf::lock() {}
inline void _RTLENTRY streambuf::unlock() {}
#endif

class _EXPCLASS istream : virtual public ios {
public:
        // constructor and destructor
        _RTLENTRY istream(streambuf _FAR *);
virtual _RTLENTRY ~istream();

        // Obsolete constructors, for streams 1.2 compatibility
        // obsolete: set skip via format, tie via tie() function
        _RTLENTRY istream(streambuf _FAR *, int _sk, ostream _FAR * _t=0);
        // obsolete: use strstream
        _RTLENTRY istream(int _sz, char _FAR *, int _sk=1);
        // obsolete: use fstream
        _RTLENTRY istream(int _fd, int _sk=1, ostream _FAR * _t=0);

    int _RTLENTRY ipfx(int = 0);       // input prefix function
    int _RTLENTRY ipfx0();     // same as ipfx(0)
    int _RTLENTRY ipfx1();     // same as ipfx(1)
    void _RTLENTRY isfx()      { } // unused input suffix function

    // set/read the get pointer's position
    istream _FAR & _RTLENTRY seekg(streampos);
    istream _FAR & _RTLENTRY seekg(streamoff, ios::seek_dir);
    streampos _RTLENTRY tellg();

    int _RTLENTRY sync();

    /*
     * Unformatted extraction operations
     */
    // extract characters into an array
    istream _FAR & _RTLENTRY get(         char _FAR *, int, char = '\n');
    istream _FAR & _RTLENTRY get(  signed char _FAR *, int, char = '\n');
    istream _FAR & _RTLENTRY get(unsigned char _FAR *, int, char = '\n');
    istream _FAR & _RTLENTRY read(         char _FAR *, int);
    istream _FAR & _RTLENTRY read(  signed char _FAR *, int);
    istream _FAR & _RTLENTRY read(unsigned char _FAR *, int);

    // extract characters into an array up to termination char
    istream _FAR & _RTLENTRY getline(         char _FAR *, int, char = '\n');
    istream _FAR & _RTLENTRY getline(  signed char _FAR *, int, char = '\n');
    istream _FAR & _RTLENTRY getline(unsigned char _FAR *, int, char = '\n');

    // extract characters into a streambuf up to termination char
    istream _FAR & _RTLENTRY get(streambuf _FAR &, char = '\n');

    // extract a single character
    istream _FAR & _RTLENTRY get(         char _FAR &);
    istream _FAR & _RTLENTRY get(  signed char _FAR &);
    istream _FAR & _RTLENTRY get(unsigned char _FAR &);
    int            _RTLENTRY get();

    int      _RTLENTRY peek();     // return next char without extraction
    int      _RTLENTRY gcount();   // number of unformatted chars last extracted
    istream _FAR & _RTLENTRY putback(char);  // push back char into input

    // extract and discard chars but stop at delim
    istream _FAR & _RTLENTRY ignore(int = 1, int = EOF);

    /*
     * Formatted extraction operations
     */
    istream _FAR & _RTLENTRY operator>> (istream _FAR & (_RTLENTRY *_f)(istream _FAR &));
    istream _FAR & _RTLENTRY operator>> (ios _FAR & (_RTLENTRY *_f)(ios _FAR &) );
    istream _FAR & _RTLENTRY operator>> (         char _FAR *);
    istream _FAR & _RTLENTRY operator>> (  signed char _FAR *);
    istream _FAR & _RTLENTRY operator>> (unsigned char _FAR *);
    istream _FAR & _RTLENTRY operator>> (         char _FAR &);
    istream _FAR & _RTLENTRY operator>> (  signed char _FAR &);
    istream _FAR & _RTLENTRY operator>> (unsigned char _FAR &);
    istream _FAR & _RTLENTRY operator>> (short _FAR &);
    istream _FAR & _RTLENTRY operator>> (int _FAR &);
    istream _FAR & _RTLENTRY operator>> (long _FAR &);
    istream _FAR & _RTLENTRY operator>> (unsigned short _FAR &);
    istream _FAR & _RTLENTRY operator>> (unsigned int _FAR &);
    istream _FAR & _RTLENTRY operator>> (unsigned long _FAR &);
    istream _FAR & _RTLENTRY operator>> (float _FAR &);
    istream _FAR & _RTLENTRY operator>> (double _FAR &);
    istream _FAR & _RTLENTRY operator>> (long double _FAR &);

    // extract from this istream, insert into streambuf
    istream _FAR & _RTLENTRY operator>> (streambuf _FAR *);

protected:
            _RTLENTRY istream();
    void    _RTLENTRY eatwhite();      // extract consecutive whitespace

private:
    int gcount_;    // chars extracted by last unformatted operation
    signed char _RTLENTRY do_get();    // implementation of get
};
inline int  _RTLENTRY istream::gcount() { return gcount_; }
inline int  _RTLENTRY istream::ipfx0()  { return ipfx(0); }
inline int  _RTLENTRY istream::ipfx1()  { return ipfx(1); }
#ifdef _BIG_INLINE_
inline istream _FAR & _RTLENTRY istream::operator>> (char _FAR & _c) {
                if( ipfx0() )
                    _c = bp->in_avail() ? bp->sbumpc() : do_get();
                return *this;
                }
inline istream _FAR & _RTLENTRY istream::operator>> (signed char _FAR & _c) {
                if( ipfx0() )
                    _c = bp->in_avail() ? bp->sbumpc() : do_get();
                return *this;
                }
inline istream _FAR & _RTLENTRY istream::operator>> (unsigned char _FAR & _c) {
                if( ipfx0() )
                    _c = bp->in_avail() ? bp->sbumpc() : do_get();
                return *this;
                }
#endif
inline istream _FAR & _RTLENTRY istream::operator>> (signed char  _FAR * _p) {
                return  *this >> (char _FAR *)_p;
                }
inline istream _FAR & _RTLENTRY istream::operator>> (unsigned char  _FAR * _p) {
                return  *this >> (char _FAR *)_p;
                }
inline istream _FAR & _RTLENTRY istream::get(signed char  _FAR * _p, int _l, char _t) {
                return get((char _FAR *)_p, _l, _t);
                }
inline istream _FAR & _RTLENTRY istream::get(unsigned char  _FAR * _p, int _l, char _t) {
                return get((char _FAR *)_p, _l, _t);
                }
inline istream _FAR & _RTLENTRY istream::read(signed char  _FAR * _p, int _l) {
                return read((char _FAR *)_p, _l);
                }
inline istream _FAR & _RTLENTRY istream::read(unsigned char  _FAR * _p, int _l) {
                return read((char _FAR *)_p, _l);
                }
inline istream _FAR & _RTLENTRY istream::getline(signed char  _FAR * _p, int _l, char _t) {
                return getline((char _FAR *) _p, _l, _t);
                }
inline istream _FAR & _RTLENTRY istream::getline(unsigned char  _FAR * _p, int _l, char _t) {
                return getline((char _FAR *) _p, _l, _t);
                }
inline int      _RTLENTRY istream::sync() { return bp->sync(); }
inline istream _FAR & _RTLENTRY istream::operator>> (istream _FAR & (_RTLENTRY *_f)(istream _FAR &)) {
                return (*_f)(*this);
                }
#ifdef _BIG_INLINE_
inline istream _FAR & _RTLENTRY istream::get(char _FAR & _c) {
                if( ipfx1() )
                    if( bp->in_avail() ) {
                        gcount_ = 1;
                        _c = bp->sbumpc();
                    }
                else _c = do_get();
                return *this;
                }
inline istream _FAR & _RTLENTRY istream::get(signed char _FAR & _c) {
                if( ipfx1() )
                    if( bp->in_avail()) {
                        gcount_ = 1;
                        _c = bp->sbumpc();
                    }
                else _c = do_get();
                return *this;
                }
inline istream _FAR & _RTLENTRY istream::get(unsigned char _FAR & _c) {
                if( ipfx1() )
                    if( bp->in_avail() ) {
                        gcount_ = 1;
                        _c = bp->sbumpc();
                    }
                else _c = do_get();
                return *this;
                }
inline int _RTLENTRY istream::get() {
                if( ipfx1() ) {
                    int _c = bp->sbumpc();
                    if( _c == EOF ) setstate(eofbit);
                    else gcount_ = 1;
                    return _c;
                }
                else return EOF;
                }
#endif
inline int  _RTLENTRY istream::peek() { return ipfx1() ? bp->sgetc() : EOF; }


class _EXPCLASS ostream : virtual public ios {
public:
    // constructors and destructor
        _RTLENTRY ostream(streambuf _FAR *);
virtual _RTLENTRY ~ostream();
    // Obsolete constructors, for streams 1.2 compatibility
        _RTLENTRY ostream(int _fd); // obsolete, use fstream
        _RTLENTRY ostream(int _sz, char _FAR *); // obsolete, use strstream

    int _RTLENTRY opfx();      // output prefix function
    void _RTLENTRY osfx();     // output suffix function
    ostream _FAR & _RTLENTRY flush();

    // set/read the put pointer's position
    ostream _FAR & _RTLENTRY seekp(streampos);
    ostream _FAR & _RTLENTRY seekp(streamoff, ios::seek_dir);
    streampos _RTLENTRY tellp();

    /*
     * Unformatted insertion operations
     */
    ostream _FAR & _RTLENTRY put(         char);  // insert the character
    ostream _FAR & _RTLENTRY put(signed   char);  // insert the character
    ostream _FAR & _RTLENTRY put(unsigned char);  // insert the character
    ostream _FAR & _RTLENTRY write(const          char _FAR *, int); // insert the string
    ostream _FAR & _RTLENTRY write(const   signed char _FAR *, int); // insert the string
    ostream _FAR & _RTLENTRY write(const unsigned char _FAR *, int); // insert the string

    /*
     * Formatted insertion operations
     */
    // insert the character
    ostream _FAR & _RTLENTRY operator<< (         char);
    ostream _FAR & _RTLENTRY operator<< (  signed char);
    ostream _FAR & _RTLENTRY operator<< (unsigned char);

    // for the following, insert character representation of numeric value
    ostream _FAR & _RTLENTRY operator<< (short);
    ostream _FAR & _RTLENTRY operator<< (unsigned short);
    ostream _FAR & _RTLENTRY operator<< (int);
    ostream _FAR & _RTLENTRY operator<< (unsigned int);
    ostream _FAR & _RTLENTRY operator<< (long);
    ostream _FAR & _RTLENTRY operator<< (unsigned long);
    ostream _FAR & _RTLENTRY operator<< (float);
    ostream _FAR & _RTLENTRY operator<< (double);
    ostream _FAR & _RTLENTRY operator<< (long double);

    // insert the null-terminated string
    ostream _FAR & _RTLENTRY operator<< (const          char _FAR *);
    ostream _FAR & _RTLENTRY operator<< (const   signed char _FAR *);
    ostream _FAR & _RTLENTRY operator<< (const unsigned char _FAR *);

    // insert character representation of the value of the pointer
    ostream _FAR & _RTLENTRY operator<< (void _FAR *);

    // extract from streambuf, insert into this ostream
    ostream _FAR & _RTLENTRY operator<< (streambuf _FAR *);

    // manipulators
    ostream _FAR & _RTLENTRY operator<< (ostream _FAR & (_RTLENTRY *_f)(ostream _FAR &));
    ostream _FAR & _RTLENTRY operator<< (ios _FAR & (_RTLENTRY *_f)(ios _FAR &));

protected:
    int     _RTLENTRY do_opfx();   // implementation of opfx
    void    _RTLENTRY do_osfx();   // implementation of osfx
            _RTLENTRY ostream();

private:
    void    _RTLENTRY outstr(const char _FAR *, const char _FAR *);
};
inline int  _RTLENTRY ostream::opfx() { return ospecial ? do_opfx() : 1; }
inline void _RTLENTRY ostream::osfx() { if( x_flags & (stdio | unitbuf) ) do_osfx(); }
#ifdef _BIG_INLINE_
inline ostream _FAR & _RTLENTRY ostream::operator<< (char _c) {
                if( opfx() )
                    if( bp->sputc(_c) == EOF ) setstate(badbit);
                        osfx();
                return *this;
                }
#endif
inline ostream _FAR & _RTLENTRY ostream::operator<< (signed char _c) {
                return *this << (char)_c;
                }
inline ostream _FAR & _RTLENTRY ostream::operator<< (unsigned char _c) {
                return *this << (char)_c;
                }
inline ostream _FAR & _RTLENTRY ostream::operator<< (const char _FAR * _s) {
                outstr(_s, (const char _FAR *)0);
                return *this;
                }
inline ostream _FAR & _RTLENTRY ostream::operator<< (const signed char _FAR * _s) {
                outstr((const char _FAR *)_s, (const char _FAR *)0);
                return *this;
                }
inline ostream _FAR & _RTLENTRY ostream::operator<< (const unsigned char _FAR * _s) {
                outstr((const char _FAR *)_s, (const char _FAR *)0);
                return *this;
                }
inline ostream _FAR & _RTLENTRY ostream::operator<< (short _i)
                { return *this << (long) _i; }
inline ostream _FAR & _RTLENTRY ostream::operator<< (unsigned short _i)
                { return *this << (unsigned long) _i; }
inline ostream _FAR & _RTLENTRY ostream::operator<< (int _i)
                { return *this << (long) _i; }
inline ostream _FAR & _RTLENTRY ostream::operator<< (unsigned int _i)
                { return *this << (unsigned long) _i; }
inline ostream _FAR & _RTLENTRY ostream::operator<< (float _f)
                { return *this << (long double) _f; }
inline ostream _FAR & _RTLENTRY ostream::operator<< (double _d)
                { return *this << (long double) _d; }
inline ostream _FAR & _RTLENTRY ostream::operator<< (ostream _FAR & (_RTLENTRY *_f)(ostream _FAR &))
                { return (*_f)(*this); }
inline ostream _FAR & _RTLENTRY ostream::write(const signed char _FAR * _s, int _n)
                { return write((const char _FAR *)_s, _n); }
inline ostream _FAR & _RTLENTRY ostream::write(const unsigned char _FAR * _s, int _n)
                { return write((const char _FAR *)_s, _n); }
inline ostream _FAR & _RTLENTRY ostream::put(char _c) {
                if( bp->sputc(_c) == EOF ) setstate(badbit);
                return *this;
                }
inline ostream _FAR & _RTLENTRY ostream::put(signed char _c)
                { return put((char) _c); }
inline ostream _FAR & _RTLENTRY ostream::put(unsigned char _c)
                { return put((char) _c); }
#ifdef _BIG_INLINE_
inline ostream _FAR & _RTLENTRY ostream::write(const char _FAR * _s, int _n) {
                if( ! fail() )
                    if( bp->sputn(_s, _n) != _n )
                        setstate(badbit);
                return *this;
                }
#endif


class _EXPCLASS iostream : public istream, public ostream {
public:
        _RTLENTRY iostream(streambuf _FAR *);
virtual _RTLENTRY ~iostream();

protected:
        _RTLENTRY iostream();
};


class _EXPCLASS istream_withassign : public istream {
public:
        // does no initialization
        _RTLENTRY istream_withassign();

virtual _RTLENTRY ~istream_withassign();

    // gets buffer from istream and does entire initialization
    istream_withassign _FAR & _RTLENTRY operator= (istream _FAR &);

    // associates streambuf with stream and does entire initialization
    istream_withassign _FAR & _RTLENTRY operator= (streambuf _FAR *);
};


class _EXPCLASS ostream_withassign : public ostream {
public:
        // does no initialization
        _RTLENTRY ostream_withassign();

virtual _RTLENTRY ~ostream_withassign();

    // gets buffer from istream and does entire initialization
    ostream_withassign _FAR & _RTLENTRY operator= (ostream _FAR &);

    // associates streambuf with stream and does entire initialization
    ostream_withassign _FAR & _RTLENTRY operator= (streambuf _FAR *);
};


class _EXPCLASS iostream_withassign : public iostream {
public:
        // does no initialization
        _RTLENTRY iostream_withassign();

virtual _RTLENTRY ~iostream_withassign();

    // gets buffer from stream and does entire initialization
    iostream_withassign _FAR & _RTLENTRY operator= (ios _FAR &);

    // associates streambuf with stream and does entire initialization
    iostream_withassign _FAR & _RTLENTRY operator= (streambuf _FAR *);
};

#if defined(__FLAT__)

/*
 * The predefined streams
 */
extern istream_withassign _RTLENTRY _EXPDATA cin;
extern ostream_withassign _RTLENTRY _EXPDATA cout;
extern ostream_withassign _RTLENTRY _EXPDATA cerr;
extern ostream_withassign _RTLENTRY _EXPDATA clog;

/*
 * Manipulators
 */

ostream _FAR &  _RTLENTRY _EXPFUNC endl(ostream _FAR &); // insert newline and flush
ostream _FAR &  _RTLENTRY _EXPFUNC ends(ostream _FAR &); // insert null to terminate string
ostream _FAR &  _RTLENTRY _EXPFUNC flush(ostream _FAR &);// flush the ostream
ios _FAR &      _RTLENTRY _EXPFUNC dec(ios _FAR &);      // set conversion base to decimal
ios _FAR &      _RTLENTRY _EXPFUNC hex(ios _FAR &);      // set conversion base to hexadecimal
ios _FAR &      _RTLENTRY _EXPFUNC oct(ios _FAR &);      // set conversion base to octal
istream _FAR &  _RTLENTRY _EXPFUNC ws(istream _FAR &);   // extract whitespace characters

ios&            _RTLENTRY _EXPFUNC lock(ios&);     // lock file handle
ios&            _RTLENTRY _EXPFUNC unlock(ios&);   // unlock file handle

#else /* __FLAT__  */

/*
 * The predefined streams
 */
extern istream_withassign _RTLENTRY  cin;
extern ostream_withassign _RTLENTRY  cout;
extern ostream_withassign _RTLENTRY  cerr;
extern ostream_withassign _RTLENTRY  clog;

/*
 * Manipulators
 */

ostream _FAR &  _RTLENTRY  endl(ostream _FAR &); // insert newline and flush
ostream _FAR &  _RTLENTRY  ends(ostream _FAR &); // insert null to terminate string
ostream _FAR &  _RTLENTRY  flush(ostream _FAR &);// flush the ostream
ios _FAR &      _RTLENTRY  dec(ios _FAR &);      // set conversion base to decimal
ios _FAR &      _RTLENTRY  hex(ios _FAR &);      // set conversion base to hexadecimal
ios _FAR &      _RTLENTRY  oct(ios _FAR &);      // set conversion base to octal
istream _FAR &  _RTLENTRY  ws(istream _FAR &);   // extract whitespace characters

ios&            _RTLENTRY  lock(ios&);     // lock file handle
ios&            _RTLENTRY  unlock(ios&);   // unlock file handle

#endif

#if !defined(__FLAT__)
/*
 * Initialization call for Easy Windows
 */
extern "C" void  _RTLENTRY _InitEasyWin(void);
#endif

#if defined(__BCOPT__) && !defined(__FLAT__)
#pragma option -po.     // restore Object Data calling convention
#endif

#pragma option -RT.
#pragma option -Vo.     // restore user C++ options
#pragma option -a.      // restore default packing

#endif  /* __IOSTREAM_H */
