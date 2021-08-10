/*  constrea.h

    Defines the class constream, which writes output to the screen
    using the iostream interface.
*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.8.2.2 $ */

#if !defined(__CONSTREA_H)
#define __CONSTREA_H

#include <iosfwd.h>
#include <strstrea.h>
#include <iomanip.h>
#include <iostream.h>

#if !defined(__CONIO_H)
#include <conio.h>
#endif  // __CONIO_H

#if !defined(RC_INVOKED)

#pragma pack(push, 1)

#pragma option push -RT -Vo-

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


class _EXPCLASS conbuf : public streambuf
{

public:

    _RTLENTRY conbuf();
    _RTLENTRY ~conbuf();
    virtual int _RTLENTRY overflow( int = EOF );
    virtual int _RTLENTRY sync();

    void _RTLENTRY clreol();

    void _RTLENTRY setcursortype( int );

    void _RTLENTRY highvideo();
    void _RTLENTRY lowvideo();
    void _RTLENTRY normvideo();

    void _RTLENTRY textattr( int );
    void _RTLENTRY textbackground( int );
    void _RTLENTRY textcolor( int );

    void _RTLENTRY gotoxy( int, int );
    int  _RTLENTRY wherex();
    int  _RTLENTRY wherey();

    void _RTLENTRY delline();
    void _RTLENTRY insline();

    void _RTLENTRY clrscr();
    void _RTLENTRY window( int, int, int, int );

    static void _RTLENTRY textmode( int );

    void _RTLENTRY activate();
    void _RTLENTRY deactivate();

private:

    virtual void _RTLENTRY makeActive();
    virtual void _RTLENTRY makeInactive();
    virtual void _RTLENTRY swap();

    text_info data;
    int cursortype;
    static conbuf *current;

};

inline _RTLENTRY conbuf::~conbuf()
{
    current = 0;
}

inline int _RTLENTRY conbuf::sync()
{
    return 0;
}

inline void _RTLENTRY conbuf::clreol()
{
    activate();
    ::clreol();
}

inline void _RTLENTRY conbuf::setcursortype( int t )
{
    activate();
    cursortype = t;
    ::_setcursortype( t );
}

inline void _RTLENTRY conbuf::highvideo()
{
    activate();
    ::highvideo();
}

inline void _RTLENTRY conbuf::lowvideo()
{
    activate();
    ::lowvideo();
}

inline void _RTLENTRY conbuf::normvideo()
{
    activate();
    ::normvideo();
}

inline void _RTLENTRY conbuf::gotoxy( int x, int y )
{
    activate();
    ::gotoxy( x, y );
}

inline int _RTLENTRY conbuf::wherex()
{
    activate();
    return ::wherex();
}

inline int _RTLENTRY conbuf::wherey()
{
    activate();
    return ::wherey();
}

inline void _RTLENTRY conbuf::textattr( int a )
{
    activate();
    ::textattr( a );
}

inline void _RTLENTRY conbuf::textbackground(int newcolor)
{
    activate();
    ::textbackground( newcolor );
}

inline void _RTLENTRY conbuf::textcolor(int newcolor)
{
    activate();
    ::textcolor( newcolor );
}

inline void _RTLENTRY conbuf::delline()
{
    activate();
    ::delline();
}

inline void _RTLENTRY conbuf::insline()
{
    activate();
    ::insline();
}

inline void _RTLENTRY conbuf::clrscr()
{
    activate();
    ::clrscr();
}

inline void _RTLENTRY conbuf::window(int left, int top, int right, int bottom)
{
    activate();
    ::window( left, top, right, bottom );
}

inline void _RTLENTRY conbuf::textmode( int mode )
{
    ::textmode( mode );
}

inline void _RTLENTRY conbuf::activate()
{
    if( current != this )
        swap();
}

inline void _RTLENTRY conbuf::deactivate()
{
    makeInactive();
}

class _EXPCLASS constream : public ostream
{

public:

    _RTLENTRY constream();
    _RTLENTRY ~constream();

    conbuf* _RTLENTRY rdbuf();     // get the assigned conbuf

    void    _RTLENTRY clrscr();
    void    _RTLENTRY window( int, int, int, int );
    void    _RTLENTRY textmode( int );

    static int _RTLENTRY isCon( ostream& );

private:

    conbuf buf;
    ostream* oldtie;
};

inline _RTLENTRY constream::~constream()
{
    cin.tie(oldtie);
}

inline conbuf* _RTLENTRY constream::rdbuf()
{
    return (conbuf *)ostream::rdbuf();
}

inline void _RTLENTRY constream::clrscr()
{
    rdbuf()->clrscr();
}

inline void _RTLENTRY constream::window( int l, int t, int r, int b )
{
    rdbuf()->window( l, t, r, b );
}

inline void _RTLENTRY constream::textmode( int m )
{
    rdbuf()->textmode( m );
}

inline int _RTLENTRY constream::isCon( ostream& o )
{
    if (dynamic_cast <constream *> (&o) == NULL)
        return 0;
    return 1;
}

template<class T1> class omanip1
{

public:
    omanip1<T1>(ostream& (_RTLENTRY *_f)(ostream&, T1), T1 _z1) :
        _fn(_f), _ag1(_z1){ }
    friend ostream& _RTLENTRY operator<<(ostream& _s, const omanip1<T1>& _f)
        { return(*_f._fn)(_s, _f._ag1); }

private:
    ostream& _RTLENTRY (*_fn)(ostream&, T1);
    T1 _ag1;
};


template<class T1, class T2> class omanip2
{

public:
    omanip2<T1,T2>(ostream& (_RTLENTRY *_f)(ostream&, T1, T2 ), T1 _z1, T2 _z2 ) :
        _fn(_f), _ag1(_z1), _ag2(_z2) { }
    friend ostream& _RTLENTRY operator<<(ostream& _s, const omanip2<T1,T2>& _f)
        { return(*_f._fn)(_s, _f._ag1, _f._ag2); }

private:
    ostream& _RTLENTRY (*_fn)(ostream&, T1, T2);
    T1 _ag1;
    T2 _ag2;
};

ostream& _RTLENTRY clreol( ostream& );
ostream& _RTLENTRY highvideo( ostream& );
ostream& _RTLENTRY lowvideo( ostream& );
ostream& _RTLENTRY normvideo( ostream& );
ostream& _RTLENTRY delline( ostream& );
ostream& _RTLENTRY insline( ostream& );

omanip1<int> _RTLENTRY setcrsrtype( int );
omanip1<int> _RTLENTRY setattr( int );
omanip1<int> _RTLENTRY setbk( int );
omanip1<int> _RTLENTRY setclr( int );
omanip2<int,int> _RTLENTRY setxy( int, int );


#if !defined(RC_INVOKED)

#pragma option pop     // restore options

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  // __CONSTREA_H
