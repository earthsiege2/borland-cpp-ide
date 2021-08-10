/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TIME.CPP                                                              */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __TIME_H )
#include <time.h>
#endif

#if !defined( __STDIO_H )
#include <stdio.h>
#endif

#if !defined( __CHECKS_H )
#include <checks.h>
#endif

#if !defined( CLASSLIB_TIME_H )
#include <classlib/time.h>
#endif

enum TimeZone { CarolineIslands=-11,    MarianaIslands,         Japan, 
                China,                  minusSeven,             minusSix, 
                Pakistan,               CaspianSea,             Turkey, 
                Finland,                Europe,                 Greenwich, 
                Azores,                 two,                    Greenland, 
                Atlantic,               USEastern,              USCentral, 
                USMountain,             USPacific,              Alaska, 
                Hawaii,                 Bearing};

static const unsigned long SECONDS_IN_DAY  = 86400L;
static const unsigned long SECONDS_IN_HOUR = 3600L;
static const unsigned      SECONDS_IN_MIN  = 60;

//  Be sure that you have set your environment variable TZ.
//  For example, for Pacific coast time, set TZ=PDT8PST.  
//  For other time zones, see your manuals.

struct TInitTime
{
    TInitTime()
        { tzset(); }
};

static TInitTime cludgeTime;      // To force the call to tzset()


const TDate TTime::RefDate( (DayTy)0, (YearTy)0 );
const TDate TTime::MaxDate( (DayTy)49709L, (YearTy)0 ); // ((2**32)-1)/SECONDS_IN_DAY -1
static const int SUNDAY = 7;

int TTime::AssertDate( const TDate _BIDSFAR & date )
{
    return date.Between(RefDate,MaxDate);
}   

/******************* private member functions ***********************/


// Adjust for local time zone and Daylight Savings Time.
ClockTy TTime::LocalSecs() const
{
    TTime local_time( Sec - timezone );
    if (local_time.IsDST())
        local_time.Sec += SECONDS_IN_HOUR;
    return local_time.Sec;
}

/*
 * Builds the time from a local time, adjusting to GMT.  Does *not* adjust for DST.
 */
TTime TTime::BuildLocal( const TDate _BIDSFAR & date, HourTy h )
{
    return TTime( SECONDS_IN_DAY * (date-RefDate) + 
                  SECONDS_IN_HOUR * h + 
                  timezone);
}

/*************** public static member functions *******************/

/*
 * Return the time at which DST starts for the given year.
 * Note that the time returned is the time at which DST starts locally,
 * but it is returned in GMT.
 */
TTime TTime::BeginDST( unsigned year )
{
    if( year > 1986 ) 
        {
        TDate endMarch(31, 3, year);
        return BuildLocal( endMarch.Previous(SUNDAY)+7, 2 );
        }

    // Ah, remember those energy conscious years...???
    if( year==1974 )
        return BuildLocal( TDate(6,1,1974), 2 );
    if( year==1975 )
        return BuildLocal( TDate(23,2,1975), 2 );

    TDate endApril( 30, 4, year );
    return BuildLocal( endApril.Previous(SUNDAY), 2 );
}


/*
 * Return the time at which DST ends for the given year.
 * Note that the time returned is the time at which DST ends locally,
 * but it is returned in GMT.
 */
TTime TTime::EndDST( unsigned year )
{
    TDate endOctober( 31, 10, year );
    return BuildLocal( endOctober.Previous(SUNDAY), 1 );
}


/************************* constructor *********************************/

// Construct TTime with current time (seconds since Jan 1, 1901).
TTime::TTime()
{
  time_t ltime;
  time(&ltime);
  struct tm _FAR *t = localtime(&ltime);

  // Construct the date.  The time struct returns int, so casts are used.

  TDate today( (DayTy)t->tm_mday,
               (MonthTy)(t->tm_mon + 1),
               (YearTy)t->tm_year );

  *this = TTime( today, 
                 (HourTy)t->tm_hour, 
                 (MinuteTy)t->tm_min, 
                 (SecondTy)t->tm_sec );
} 

// Specified time and today's date:
TTime::TTime( HourTy h, MinuteTy m, SecondTy s )
{
    Sec = TTime( TDate(),h,m,s ).Sec;
}

/*
 * Construct a Time for the specified (local) Date, hour, minute, and second.
 * Note: this algorithm will fail if DST correction is something other
 * than an hour.
 * It is complicated by the DST boundary problem: 
 * 1) Times in the phantom zone between 2AM and 3AM when DST is invoked are invalid.
 * 2) Times in the hour after 1AM when DST ends, are redundant.
 * Checking for these situations necessitates a lot of jumping back 
 * and forth by an hour to check for the boundary.
 */
TTime::TTime( const TDate _BIDSFAR & date, HourTy h, MinuteTy m, SecondTy s )
{
    if( date.IsValid() )
        {
        Sec =   SECONDS_IN_DAY  * (date-RefDate) + 
                SECONDS_IN_HOUR * (h-1L) +    /* Note the adjustment by one hour */
                SECONDS_IN_MIN  * m + s;
        if( Sec )
            Sec += timezone;           // Adjust to GMT.

        if( IsDST() )
            {
            Sec += SECONDS_IN_HOUR;
            if( IsDST() ) 
                Sec -= SECONDS_IN_HOUR;
            }
        else
            {
            Sec += SECONDS_IN_HOUR;
            if( IsDST() ) 
                Sec = 0;            // Invalid "phantom" time.
            }
        }
    else
        Sec = 0;    // Invalid date
}

/*************** conversion from TTime to TDate *******************/

// Type conversion to date.
TDate::TDate( const TTime _BIDSFAR & t )
{
    Julnum = t.IsValid() ? jul1901 + (JulTy)(t.LocalSecs()/SECONDS_IN_DAY) : 0;
}

/********************* public member functions **********************/

int TTime::CompareTo( const TTime _BIDSFAR &t ) const
{
    ClockTy diff = Sec - t.Sec;
    return diff==0 ? 0 : diff>0 ? 1 : -1;
}

// Hash function:
unsigned TTime::Hash() const
{
    return (unsigned)Sec;
}

/*
 * The hour in local time:
 */
HourTy TTime::Hour() const
{
    return HourTy((LocalSecs() % SECONDS_IN_DAY) / SECONDS_IN_HOUR);
}

/*
 * The hour in GMT:
 */
HourTy TTime::HourGMT() const 
{
    return HourTy((Sec % SECONDS_IN_DAY) / SECONDS_IN_HOUR);
} 

/*
 * Return TRUE if DST is active for this time:
 */
int TTime::IsDST() const
{
  if( !daylight ) 
    return 0;

  DayTy daycount = (unsigned)(Sec/SECONDS_IN_DAY);
  YearTy year = TDate( (DayTy)daycount, (YearTy)0 ).Year();

  // Check to see if the time falls between the starting & stopping DST times.
  return *this >= BeginDST( year ) && *this < EndDST( year );
}

TTime TTime::Max( const TTime _BIDSFAR & t ) const 
{
    if( *this > t ) 
        return *this;
    else
        return t;
}

TTime TTime::Min( const TTime _BIDSFAR & t ) const 
{
    if( *this < t ) 
        return *this;
    else
        return t;
}

/*
 * minute, in local time
 */
MinuteTy TTime::Minute() const
{
    return MinuteTy(((LocalSecs()%SECONDS_IN_DAY)%SECONDS_IN_HOUR)/SECONDS_IN_MIN);
}

/*
 * minute: GMT
 */
MinuteTy TTime::MinuteGMT() const 
{
    return MinuteTy(((Sec%SECONDS_IN_DAY)%SECONDS_IN_HOUR)/SECONDS_IN_MIN);
} 

// second;local time or GMT 
SecondTy TTime::Second() const 
{
    return SecondTy(((Sec%SECONDS_IN_DAY)%SECONDS_IN_HOUR)%SECONDS_IN_MIN);
}

