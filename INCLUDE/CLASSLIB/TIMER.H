//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.3  $
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_TIMER_H)
#define CLASSLIB_TIMER_H

#include <classlib/defs.h>

#if !defined(BI_PLAT_DOS) && !defined(BUILDBIDSTIMER)
# error class TTimer only available under DOS
#endif

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
# pragma option -po-
#endif

class TTimer
{

public:

    TTimer();

    void Start();
    void Stop();
    void Reset();

    int Status();
    double Time();

    static double Resolution();

private:

    static unsigned Adjust;
    static unsigned Calibrate();
    int Running;

    struct TIME
        {
        unsigned long DosCount;
        unsigned TimerCount;
        };

    TIME StartTime;

    double Time_;

};

#if defined( BI_OLDNAMES )
#define Timer TTimer
#endif

inline int TTimer::Status()
{
    return Running;
}

inline double TTimer::Time()
{
    return Time_/1.E6;
}

inline double TTimer::Resolution()
{
    return 839/1.E9;
}

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#pragma option -Vo.

#endif  // CLASSLIB_TIMER_H
