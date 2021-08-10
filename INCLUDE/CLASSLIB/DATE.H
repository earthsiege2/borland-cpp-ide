/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DATE.H                                                                */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB__DATE_H )
#define CLASSLIB__DATE_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

class _EXPCLASS string;
class _EXPCLASS istream;
class _EXPCLASS ostream;
class _BIDSCLASS TTime;
class _BIDSCLASS ipstream;
class _BIDSCLASS opstream;

typedef unsigned DayTy;
typedef unsigned MonthTy;
typedef unsigned YearTy;
typedef unsigned long JulTy;

static const JulTy jul1901 = 2415386L;  // Julian day for 1/1/1901

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TDate                                                           */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSCLASS TDate
{

public:

    enum HowToPrint
        {
        Normal,
        Terse,
        Numbers,
        EuropeanNumbers,
        European
        };

    // Construct a TDate with the current date

    TDate();

    // Construct a TDate with a given day of the year and a given year.
    // The base date for this computation is Dec. 31 of the previous year.
    // If year == 0, Construct a TDate with Jan. 1, 1901 as the "day zero".
    // i.e., TDate(-1,0) = Dec. 31, 1900 and TDate(1,0) = Jan. 2, 1901.

    TDate( DayTy day, YearTy year );

    //  Construct a TDate for the given day, month, and year.
    TDate( DayTy, const char _BIDSFAR * month, YearTy );
    TDate( DayTy, MonthTy, YearTy );
    TDate( istream _BIDSFAR & s );      // Read date from stream.
    TDate( const TTime _BIDSFAR & );    // Construct a TDate from a TTime

    string AsString() const;
    int Between( const TDate _BIDSFAR & d1, const TDate _BIDSFAR & d2 ) const;
    int CompareTo( const TDate _BIDSFAR & ) const;
    DayTy Day() const;            // 1-365
    DayTy DayOfMonth() const;     // 1-31
    DayTy FirstDayOfMonth() const;
    DayTy FirstDayOfMonth( MonthTy ) const;
    unsigned Hash() const;
    int IsValid() const;
    int Leap()  const;                             // leap year?
    TDate Max( const TDate _BIDSFAR & dt ) const;
    TDate Min( const TDate _BIDSFAR & dt ) const;
    MonthTy Month() const;
    const char _BIDSFAR *NameOfDay() const;
    const char _BIDSFAR *NameOfMonth() const;
    TDate Previous( const char _BIDSFAR *dayName ) const;  // Return date of previous dayName
    TDate Previous( DayTy ) const;                // Same as above, but use day of week
    DayTy WeekDay() const;
    YearTy Year() const;

    // Date comparisons:
    int operator <  ( const TDate _BIDSFAR & date ) const;
    int operator <= ( const TDate _BIDSFAR & date ) const;
    int operator >  ( const TDate _BIDSFAR & date ) const;
    int operator >= ( const TDate _BIDSFAR & date ) const;
    int operator == ( const TDate _BIDSFAR & date ) const;
    int operator != ( const TDate _BIDSFAR & date ) const;

    // Arithmetic operators:
    JulTy operator - ( const TDate _BIDSFAR & dt ) const;
    friend TDate _BIDSFUNC operator + ( const TDate _BIDSFAR & dt, int dd );
    friend TDate _BIDSFUNC operator + ( int dd, const TDate _BIDSFAR & dt );
    friend TDate _BIDSFUNC operator - ( const TDate _BIDSFAR & dt, int dd );
    void operator ++ ();
    void operator -- ();
    void operator += ( int dd );
    void operator -= ( int dd );

    // Read or write dates:
    friend ostream _BIDSFAR & _BIDSFUNC operator << ( ostream _BIDSFAR & s, const TDate _BIDSFAR & d );
    friend istream _BIDSFAR & _BIDSFUNC operator >> ( istream _BIDSFAR & s, TDate _BIDSFAR & d );

    // Read or write dates on persistent streams
    friend opstream _BIDSFAR & _BIDSFUNC operator << ( opstream _BIDSFAR & s, const TDate _BIDSFAR & d );
    friend ipstream _BIDSFAR & _BIDSFUNC operator >> ( ipstream _BIDSFAR & s, TDate _BIDSFAR & d );

    // Static member functions:
    static const char _BIDSFAR *DayName( DayTy weekDayNumber );
    static DayTy DayOfWeek( const char _BIDSFAR * dayName );
    static int DayWithinMonth( MonthTy, DayTy, YearTy );
    static DayTy DaysInYear( YearTy );
    static MonthTy IndexOfMonth( const char * _BIDSFAR monthName );
    static JulTy Jday( MonthTy, DayTy, YearTy );
    static int LeapYear( YearTy year );
    static const char _BIDSFAR *MonthName( MonthTy monthNumber );
    static HowToPrint SetPrintOption( HowToPrint h );

protected:

    static int AssertWeekDayNumber( DayTy d );
    static int AssertIndexOfMonth( MonthTy m );

private:

    JulTy Julnum;                   // Julian Day Number (Not same as Julian date.)
    static HowToPrint PrintOption;  // Printing with different formats

    void ParseFrom( istream _BIDSFAR & );     // Reading dates
    void _BIDSNEARFUNC Mdy( MonthTy _BIDSFAR &, DayTy _BIDSFAR &, YearTy _BIDSFAR & ) const;
    TDate( JulTy j );

};

#if defined( BI_OLDNAMES )
#define BI_Date TDate
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TDate inline functions                                                */
/*                                                                        */
/*------------------------------------------------------------------------*/

inline TDate::TDate( istream& s )
{
    ParseFrom(s);
}

inline int TDate::Between( const TDate& d1, const TDate& d2 ) const
{
    return Julnum >= d1.Julnum && Julnum <= d2.Julnum;
}

inline DayTy TDate::FirstDayOfMonth() const
{
    return FirstDayOfMonth(Month());
}

inline int TDate::IsValid() const
{
    return Julnum>0;
}

inline int TDate::Leap() const
{
    return LeapYear(Year());
}

inline const char *TDate::NameOfDay() const
{
    return DayName(WeekDay());
}

inline const char *TDate::NameOfMonth() const
{
    return MonthName(Month());
}

inline int TDate::operator < ( const TDate& date ) const
{
    return Julnum < date.Julnum;
}

inline int TDate::operator <= ( const TDate& date ) const
{
    return Julnum <= date.Julnum;
}

inline int TDate::operator > ( const TDate& date ) const
{
    return Julnum > date.Julnum;
}

inline int TDate::operator >= ( const TDate& date ) const
{
    return Julnum >= date.Julnum;
}

inline int TDate::operator == ( const TDate& date ) const
{
    return Julnum == date.Julnum;
}

inline int TDate::operator != ( const TDate& date ) const
{
    return Julnum != date.Julnum;
}

inline JulTy TDate::operator - ( const TDate& dt ) const
{
    return Julnum - dt.Julnum;
}

inline TDate _BIDSFUNC operator + ( const TDate& dt, int dd )
{
    return TDate(dt.Julnum + dd);
}

inline TDate _BIDSFUNC operator + ( int dd, const TDate& dt )
{
    return TDate(dt.Julnum + dd);
}

inline TDate _BIDSFUNC operator - ( const TDate& dt, int dd )
{
    return TDate(dt.Julnum - dd);
}

inline void TDate::operator ++ ()
{
    Julnum += 1;
}

inline void TDate::operator -- ()
{
    Julnum -= 1;
}

inline void TDate::operator += ( int dd )
{
    Julnum += dd;
}

inline void TDate::operator -= ( int dd )
{
    Julnum -= dd;
}

inline istream& _BIDSFUNC operator >> ( istream& s, TDate& d )
{
    d.ParseFrom(s);
    return s;
}

inline int TDate::AssertWeekDayNumber( DayTy d )
{
    return d>=1 && d<=7;
}

inline int TDate::AssertIndexOfMonth( MonthTy m )
{
    return m>=1 && m<=12;
}

inline TDate::TDate( JulTy j )
{
    Julnum = j;
}

inline HashValue( TDate _BIDSFAR & d )
{
    return d.Hash();
}

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // CLASSLIB_DATE_H
