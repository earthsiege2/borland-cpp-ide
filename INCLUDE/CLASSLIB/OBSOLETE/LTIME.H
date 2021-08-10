/*------------------------------------------------------------------------*/
/*                                                                        */
/*  LTIME.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991, 1993                            */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __LTIME_H )
#define __LTIME_H

#define BI_OLDNAMES

#if !defined( __DOS_H )
#include <Dos.h>
#endif  // __DOS_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __SORTABLE_H )
#include "classlib\obsolete\Sortable.h"
#endif  // __SORTABLE_H

#pragma option -Vo-
#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po-
#endif

_CLASSDEF(ostream)
_CLASSDEF(BaseTime)
_CLASSDEF(Time)

class _CLASSTYPE BaseTime : public Sortable
{

public:

    unsigned hour() const;
    unsigned minute() const;
    unsigned second() const;
    unsigned hundredths() const;
    void setHour( unsigned _TCHAR );
    void setMinute( unsigned _TCHAR );
    void setSecond( unsigned _TCHAR );
    void setHundredths( unsigned _TCHAR );

    virtual classType isA() const = 0;
    virtual _TCHAR _FAR *nameOf() const = 0;
    virtual hashValueType hashValue() const;
    virtual int isEqual( const Object _FAR & ) const;
    virtual int isLessThan( const Object _FAR & ) const;
    virtual void printOn( ostream _FAR & ) const = 0;

protected:

    BaseTime();
    BaseTime( const BaseTime _FAR & );
    BaseTime( unsigned _TCHAR,
              unsigned _TCHAR = 0,
              unsigned _TCHAR = 0,
              unsigned _TCHAR = 0
            );

private:

    unsigned _TCHAR HH;
    unsigned _TCHAR MM;
    unsigned _TCHAR SS;
    unsigned _TCHAR HD;
};

inline BaseTime::BaseTime()
{
    struct time t;
    gettime( &t );
    HH = t.ti_hour;
    MM = t.ti_min;
    SS = t.ti_sec;
    HD = t.ti_hund;
}

inline BaseTime::BaseTime( const BaseTime _FAR & B ) :
    HH(B.HH), MM(B.MM), SS(B.SS), HD(B.HD)
{
}

inline BaseTime::BaseTime( unsigned _TCHAR H, unsigned _TCHAR M, unsigned _TCHAR S, unsigned _TCHAR D )
{
    setHour( H );
    setMinute( M );
    setSecond( S );
    setHundredths( D );
}

inline unsigned BaseTime::hour() const
{
    return HH;
}

inline unsigned BaseTime::minute() const
{
    return MM;
}

inline unsigned BaseTime::second() const
{
    return SS;
}

inline unsigned BaseTime::hundredths() const
{
    return HD;
}

inline void BaseTime::setHour( unsigned _TCHAR anHour )
{
    PRECONDITION( anHour < 24 );
    HH = anHour;
}

inline void BaseTime::setMinute( unsigned _TCHAR M )
{
    PRECONDITION( M < 60 );
    MM = M;
}

inline void BaseTime::setSecond( unsigned _TCHAR S )
{
    PRECONDITION( S < 60 );
    SS = S;
}

inline void BaseTime::setHundredths( unsigned _TCHAR D )
{
    PRECONDITION( D < 100 );
    HD = D;
}

class _CLASSTYPE Time : public BaseTime
{

public:

    Time();
    Time( const Time _FAR & );
    Time( unsigned _TCHAR,
          unsigned _TCHAR = 0,
          unsigned _TCHAR = 0,
          unsigned _TCHAR = 0
        );

    virtual classType isA() const
        {
        return timeClass;
        }

    virtual _TCHAR _FAR *nameOf() const
        {
        return "Time";
        }

    virtual void printOn( ostream _FAR & ) const;
};

inline Time::Time() : BaseTime()
{
}

inline Time::Time( const Time& T ) : BaseTime( T )
{
}

inline Time::Time( unsigned _TCHAR H, unsigned _TCHAR M, unsigned _TCHAR S,
                   unsigned _TCHAR D ) :  BaseTime( H, M, S, D )
{
}

#if defined( __BCOPT__ ) && !defined( __FLAT__ ) && !defined( _ALLOW_po )
#pragma option -po.
#endif
#pragma option -Vo.

#endif  // __LTIME_H

