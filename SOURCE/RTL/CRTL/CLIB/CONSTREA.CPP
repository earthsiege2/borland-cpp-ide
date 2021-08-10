/*-----------------------------------------------------------------------*
 * filename - constrea.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */


#if !defined( __CONSTREA_H )
#include "constrea.h"
#endif  // __CONSTREA_H

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif  // __IOSTREAM_H

conbuf *conbuf::current = 0;
long constream::isCon_ = 0L;

conbuf::conbuf()
{
    ::gettextinfo( &data );
    cursortype = _NORMALCURSOR;
}

int conbuf::overflow( int c )
{
    activate();
    if( c == '\n' )
        putch( '\r' );
    return putch( c );
}

void conbuf::makeActive()
{
    ::window( data.winleft, data.wintop, data.winright, data.winbottom );
    ::textattr( data.attribute );
    ::gotoxy( data.curx, data.cury );
    ::_setcursortype( cursortype );
}

void conbuf::makeInactive()
{
    ::gettextinfo( &data );
}

void conbuf::swap()
{
    if( current != 0 )
        current->deactivate();
    makeActive();
    current = this;
}

constream::constream() : ostream( &buf )
{
    cin.tie( this );
    setf( ios::unitbuf );
    if( !isCon_ )
        isCon_ = bitalloc();
    setf( isCon_ );
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

static ostream& scrsr( ostream& o, int c )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->setcursortype( c );
    return o;
}

omanip<int> _RTLENTRY setcrsrtype( int c )
{
    return omanip<int>( scrsr, c );
}


static ostream& sattr( ostream& o, int a )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->textattr( a );
    return o;
}

omanip<int> _RTLENTRY setattr( int a )
{
    return omanip<int>( sattr, a );
}

static ostream& sxy( ostream& o, int x, int y )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->gotoxy( x, y );
    return o;
}

omanip2<int,int> _RTLENTRY setxy( int a, int b )
{
    return omanip2<int,int>( sxy, a, b );
}

static ostream& sbk( ostream& o, int a )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->textbackground( a );
    return o;
}

omanip<int> _RTLENTRY setbk( int a )
{
    return omanip<int>( sbk, a );
}

static ostream& sclr( ostream& o, int a )
{
    if( constream::isCon( o ) )
        ((constream&)o).rdbuf()->textcolor( a );
    return o;
}

omanip<int> _RTLENTRY setclr( int a )
{
    return omanip<int>( sclr, a );
}
