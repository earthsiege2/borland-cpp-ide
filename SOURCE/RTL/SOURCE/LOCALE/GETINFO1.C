/*------------------------------------------------------------------------
 * filename - getinfo1.c
 *
 * function(s)
 *      _getLocaleTimeInfo - return the required info about the locale
 *
 *
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#include <ntbc.h>
#include <winnls.h>
#include <locale.h>
#include <_locale.h>

const void* _getLocaleTimeInfo(LCTYPE info)
{
    LPWIN32LOCALE locale = __locale;

    switch (info)
    {
    case LOCALE_SDATE:              return (locale->time->DateSeparator);
    case LOCALE_STIME:              return (locale->time->TimeSeparator);
    case LOCALE_STIMEFORMAT:        return (locale->time->TimeFormat);
    case LOCALE_SSHORTDATE:         return (locale->time->ShortFormat);
    case LOCALE_SLONGDATE:          return (locale->time->LongFormat);
    case LOCALE_S1159:              return (locale->time->AM);
    case LOCALE_S2359:              return (locale->time->PM);
    case LOCALE_SDAYNAME1:          return (locale->time->DayName1);
    case LOCALE_SDAYNAME2:          return (locale->time->DayName2);
    case LOCALE_SDAYNAME3:          return (locale->time->DayName3);
    case LOCALE_SDAYNAME4:          return (locale->time->DayName4);
    case LOCALE_SDAYNAME5:          return (locale->time->DayName5);
    case LOCALE_SDAYNAME6:          return (locale->time->DayName6);
    case LOCALE_SDAYNAME7:          return (locale->time->DayName7);
    case LOCALE_SABBREVDAYNAME1:    return (locale->time->AbrvDayName1);
    case LOCALE_SABBREVDAYNAME2:    return (locale->time->AbrvDayName2);
    case LOCALE_SABBREVDAYNAME3:    return (locale->time->AbrvDayName3);
    case LOCALE_SABBREVDAYNAME4:    return (locale->time->AbrvDayName4);
    case LOCALE_SABBREVDAYNAME5:    return (locale->time->AbrvDayName5);
    case LOCALE_SABBREVDAYNAME6:    return (locale->time->AbrvDayName6);
    case LOCALE_SABBREVDAYNAME7:    return (locale->time->AbrvDayName7);
    case LOCALE_SMONTHNAME1:        return (locale->time->MonthName1);
    case LOCALE_SMONTHNAME2:        return (locale->time->MonthName2);
    case LOCALE_SMONTHNAME3:        return (locale->time->MonthName3);
    case LOCALE_SMONTHNAME4:        return (locale->time->MonthName4);
    case LOCALE_SMONTHNAME5:        return (locale->time->MonthName5);
    case LOCALE_SMONTHNAME6:        return (locale->time->MonthName6);
    case LOCALE_SMONTHNAME7:        return (locale->time->MonthName7);
    case LOCALE_SMONTHNAME8:        return (locale->time->MonthName8);
    case LOCALE_SMONTHNAME9:        return (locale->time->MonthName9);
    case LOCALE_SMONTHNAME10:       return (locale->time->MonthName10);
    case LOCALE_SMONTHNAME11:       return (locale->time->MonthName11);
    case LOCALE_SMONTHNAME12:       return (locale->time->MonthName12);
    case LOCALE_SABBREVMONTHNAME1:  return (locale->time->AbrvMonthName1);
    case LOCALE_SABBREVMONTHNAME2:  return (locale->time->AbrvMonthName2);
    case LOCALE_SABBREVMONTHNAME3:  return (locale->time->AbrvMonthName3);
    case LOCALE_SABBREVMONTHNAME4:  return (locale->time->AbrvMonthName4);
    case LOCALE_SABBREVMONTHNAME5:  return (locale->time->AbrvMonthName5);
    case LOCALE_SABBREVMONTHNAME6:  return (locale->time->AbrvMonthName6);
    case LOCALE_SABBREVMONTHNAME7:  return (locale->time->AbrvMonthName7);
    case LOCALE_SABBREVMONTHNAME8:  return (locale->time->AbrvMonthName8);
    case LOCALE_SABBREVMONTHNAME9:  return (locale->time->AbrvMonthName9);
    case LOCALE_SABBREVMONTHNAME10: return (locale->time->AbrvMonthName10);
    case LOCALE_SABBREVMONTHNAME11: return (locale->time->AbrvMonthName11);
    case LOCALE_SABBREVMONTHNAME12: return (locale->time->AbrvMonthName12);

    case LOCALE_IDATE     :         return (void*) (locale->time->Order);
    case LOCALE_ILDATE    :         return (void*) (locale->time->LongOrder);
    case LOCALE_ITIME     :         return (void*) (locale->time->TimeFmt);
    case LOCALE_ICENTURY  :         return (void*) (locale->time->Century);
    case LOCALE_ITLZERO   :         return (void*) (locale->time->TimeLeadZeros);
    case LOCALE_IDAYLZERO :         return (void*) (locale->time->DayLeadZeros);
    case LOCALE_IMONLZERO :         return (void*) (locale->time->MonthLeadZeros);
    default:                        return NULL;
    }
}
