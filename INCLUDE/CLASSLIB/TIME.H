/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TIME.H                                                                */
/*                                                                        */
/*  Copyright (c) 1993 Borland International                              */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined(__CLASSLIB_TIME_H)
#define __CLASSLIB_TIME_H

#if !defined( __TIME_H )
#include <time.h>
#endif  // __TIME_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_DATE_H )
#include "classlib\date.h"
#endif  // __CLASSLIB_DATE_H

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

class _EXPCLASS string;
class _EXPCLASS istream;
class _EXPCLASS ostream;
class _BIDSCLASS ipstream;
class _BIDSCLASS opstream;

typedef unsigned HourTy;
typedef unsigned MinuteTy;
typedef unsigned SecondTy;
typedef unsigned long ClockTy;

static const unsigned long secFrom_Jan_1_1901_to_Jan_1_1970 = 2177452800L;

class _BIDSCLASS TTime
{

public:

    friend TDate::TDate( const TTime _BIDSFAR & );

    TTime();                  // Current time
    TTime( ClockTy s );       // Seconds since Jan 1, 1901.
    TTime( HourTy h, MinuteTy m, SecondTy s = 0 );
                                // Specified time and today's date
    TTime( const TDate _BIDSFAR &, HourTy h=0, MinuteTy m=0, SecondTy s=0 );
                                // Given date and time

    string AsString() const;
    int CompareTo( const TTime _BIDSFAR & ) const;
    unsigned Hash() const;
    HourTy Hour() const;        // hour: local time
    HourTy HourGMT() const;     // hour: GMT
    int IsDST() const;
    int IsValid() const;
    TTime Max( const TTime _BIDSFAR & t ) const;
    TTime Min( const TTime _BIDSFAR & t ) const;
    MinuteTy Minute() const;    // minute: local time
    MinuteTy MinuteGMT() const; // minute: GMT
    SecondTy Second() const;    // second: local time or GMT
    ClockTy Seconds() const;

    // Write times:
    friend ostream _BIDSFAR & _BIDSFUNC operator << ( ostream _BIDSFAR &, const TTime _BIDSFAR & );

    // Read or write times on persistent streams
    friend opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & s, const TTime _BIDSFAR & d );
    friend ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & s, TTime _BIDSFAR & d );

    // Boolean operators.
    int operator <  ( const TTime _BIDSFAR & t ) const;
    int operator <= ( const TTime _BIDSFAR & t ) const;
    int operator >  ( const TTime _BIDSFAR & t ) const;
    int operator >= ( const TTime _BIDSFAR & t ) const;
    int operator == ( const TTime _BIDSFAR & t ) const;
    int operator != ( const TTime _BIDSFAR & t ) const;
    int Between( const TTime _BIDSFAR & a, const TTime _BIDSFAR & b ) const;

    // Add or subtract seconds.
    friend TTime _BIDSFUNC operator + ( const TTime _BIDSFAR & t, long s );
    friend TTime _BIDSFUNC operator + ( long s, const TTime _BIDSFAR & t );
    friend TTime operator - ( const TTime _BIDSFAR & t, long s );
    friend TTime operator - ( long s, const TTime _BIDSFAR & t );
    void operator++();
    void operator--();
    void operator+=(long s);
    void operator-=(long s);

    // Static member functions:
    static TTime BeginDST( unsigned year ); // Start of DST for given year.
    static TTime EndDST( unsigned year );   // End of DST for given year.
    static int PrintDate( int );    // Whether to include date when printing time

protected:

    static int AssertDate( const TDate _BIDSFAR & );
    static const TDate RefDate;
    static const TDate MaxDate;

private:

    ClockTy Sec;        // Seconds since 1/1/1901.
    static int PrintDateFlag;  // True to print date along with time.

    ClockTy LocalSecs() const;
    static TTime BuildLocal( const TDate _BIDSFAR &, HourTy );

};

#if defined( BI_OLDNAMES )
#define BI_Time TTime
#endif

inline TTime::TTime( ClockTy s )
{
    Sec = s;
}

inline int TTime::IsValid() const
{
    return Sec > 0;
}

inline ClockTy TTime::Seconds() const
{
    return Sec;
}

inline int TTime::operator <  ( const TTime& t ) const
{
    return Sec < t.Sec;
}

inline int TTime::operator <= ( const TTime& t ) const
{
    return Sec <= t.Sec;
}

inline int TTime::operator >  ( const TTime& t ) const
{
    return Sec > t.Sec;
}

inline int TTime::operator >= ( const TTime& t ) const
{
    return Sec >= t.Sec;
}

inline int TTime::operator == ( const TTime& t ) const
{
    return Sec == t.Sec;
}

inline int TTime::operator != ( const TTime& t ) const
{
    return Sec != t.Sec;
}

inline int TTime::Between( const TTime& a, const TTime& b ) const
{
    return *this >= a && *this <= b;
}

inline TTime operator + ( const TTime& t, long s )
{
    return TTime(t.Sec+s);
}

inline TTime operator + ( long s, const TTime& t )
{
    return TTime(t.Sec+s);
}

inline TTime operator - ( const TTime& t, long s )
{
    return TTime(t.Sec-s);
}

inline TTime operator - ( long s, const TTime& t )
{
    return TTime(t.Sec-s);
}

inline void TTime::operator++()
{
    Sec += 1;
}

inline void TTime::operator--()
{
    Sec -= 1;
}

inline void TTime::operator+=(long s)
{
    Sec += s;
}

inline void TTime::operator-=(long s)
{
    Sec -= s;
}

inline HashValue( TTime _BIDSFAR & t )
{
    return t.Hash();
}

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // __CLASSLIB_TIME_H

