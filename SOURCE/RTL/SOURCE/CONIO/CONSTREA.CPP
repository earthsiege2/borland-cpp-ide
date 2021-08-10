/*-----------------------------------------------------------------------*
 * filename - constrea.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */


#if !defined( __CONSTREA_H )
#include "constrea.h"
#endif  // __CONSTREA_H

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif  // __IOSTREAM_H

conbuf *conbuf::current = 0;

_RTLENTRY conbuf::conbuf()
{
    ::gettextinfo( &data );
    cursortype = _NORMALCURSOR;
}

int _RTLENTRY conbuf::overflow( int c )
{
    activate();
    if( c == '\n' )
        putch( '\r' );
    return putch( c );
}

void _RTLENTRY conbuf::makeActive()
{
    ::window( data.winleft, data.wintop, data.winright, data.winbottom );
    ::textattr( data.attribute );
    ::gotoxy( data.curx, data.cury );
    ::_setcursortype( cursortype );
}

void _RTLENTRY conbuf::makeInactive()
{
    ::gettextinfo( &data );
}

void _RTLENTRY conbuf::swap()
{
    if( current != 0 )
        current->deactivate();
    makeActive();
    current = this;
}

_RTLENTRY constream::constream()
{
    init (&buf);
    oldtie = cin.tie( this );
    setf( ios::unitbuf );
}

ostream& _RTLENTRY clreol( ostream& o )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->clreol();
    return o;
}

ostream& _RTLENTRY highvideo( ostream& o )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->highvideo();
    return o;
}

ostream& _RTLENTRY lowvideo( ostream& o )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->lowvideo();
    return o;
}

ostream& _RTLENTRY normvideo( ostream& o )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->normvideo();
    return o;
}

ostream& _RTLENTRY delline( ostream& o )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->delline();
    return o;
}

ostream& _RTLENTRY insline( ostream& o )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->insline();
    return o;
}

static ostream& _RTLENTRY scrsr( ostream& o, int c )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->setcursortype( c );
    return o;
}

omanip1<int> _RTLENTRY setcrsrtype( int c )
{
    return omanip1<int>( scrsr, c );
}


static ostream& _RTLENTRY sattr( ostream& o, int a )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->textattr( a );
    return o;
}

omanip1<int> _RTLENTRY setattr( int a )
{
    return omanip1<int>( sattr, a );
}

static ostream& _RTLENTRY sxy( ostream& o, int x, int y )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->gotoxy( x, y );
    return o;
}

omanip2<int,int> _RTLENTRY setxy( int a, int b )
{
    return omanip2<int,int>( sxy, a, b );
}

static ostream& _RTLENTRY sbk( ostream& o, int a )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->textbackground( a );
    return o;
}

omanip1<int> _RTLENTRY setbk( int a )
{
    return omanip1<int>( sbk, a );
}

static ostream& _RTLENTRY sclr( ostream& o, int a )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->textcolor( a );
    return o;
}

omanip1<int> _RTLENTRY setclr( int a )
{
    return omanip1<int>( sclr, a );
}
