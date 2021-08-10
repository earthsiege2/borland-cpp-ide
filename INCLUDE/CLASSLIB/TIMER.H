/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TIMER.H                                                               */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_TIMER_H )
#define __CLASSLIB_TIMER_H

#if defined( _Windows ) && !defined( _BUILDRTLDLL )
#error TTimer not available for Windows
#endif

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif	// __CLASSLIB_DEFS_H

#pragma option -Vo-
#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
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

#endif  // __CLASSLIB_TIMER_H

