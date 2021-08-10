/*-----------------------------------------------------------------------*
 * filename - clocale.c
 *
 * __locale global
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */


#include <_locale.h>

WIN32MONETARY CMonetary = {
    2,                                      // Digits (# fractional digits)
    2,                                      // IntlDigits (# of fractional intl digits)
    0,                                      // Mode (currency mode)
    0,                                      // NegMode (negative currency mode)
    0,                                      // PositiveFormat
    0,                                      // NegativeFormat
    0,                                      // PosSymbolPrec (is positive symbol preceeded by amount?)
    0,                                      // PosSymbolSpace (is positive sym separated by space?)
    0,                                      // NegSymbolPrec (is negative sym preceeded by amount?)
    0,                                      // NegSymbolSpace (is negative sym separated by space?)
    "",                                     // ThousandSeparator (thousand separator symbol)
    ".",                                    // Decimal (floating point symbol)
    "",                                     // Symbol (monetary symbol)
    "",                                     // IntlSymbol (monetary international symbol)
    "",                                     // Grouping
    "",                                     // PositiveSign
    "-",                                    // NegativeSign
    "($v)"                                  // Negative Format string
};

WIN32NUMERIC CNumeric = {
    "",                                     // ThousandSeparator
    ".",                                    // Decimal (floating point symbol)
    "",                                     // Grouping
    "",                                     // PositiveSign
    "-",                                    // NegativeSign
    2                                       // Digits (number of fractional digits)
};

WIN32TIME CTimeDate = {
    "/",                                    // DateSeparator (_SDATE)
    ":",                                    // TimeSeparator (_STIME)
    "%H:%M:%S",                             // TimeFormat (_STIMEFORMAT)
    "%m/%d/%y",                             // ShortFormat (date) (_SSHORTDATE)
    "%A, %B %d, %Y",                        // LongFormat (date) (_SLONGDATE)
    "AM",                                   // AM (_S1159)
    "PM",                                   // PM (_S2359)
    0,                                      // Order (short date-format order) (_IDATE)
    0,                                      // LongOrder (long date-format order) (_ILDATE)
    0,                                      // TimeFmt (AM/PM || 24h) (_ITIME)
    0,                                      // Century (4 digits or 2) (_ICENTURY)
    0,                                      // TimeLeadZeros (_TLZERO)
    0,                                      // DayLeadZeros (_IDAYLZERO)
    0,                                      // MonthLeadZeros (_IMONLZERO)
    "Monday",                               // DayName1
    "Tuesday",                              // DayName2
    "Wednesday",                            // DayName3
    "Thursday",                             // DayName4
    "Friday",                               // DayName5
    "Saturday",                             // DayName6
    "Sunday",                               // DayName7
    "Mon",                                  // AbrvDayName1
    "Tue",                                  // AbrvDayName2
    "Wed",                                  // AbrvDayName3
    "Thu",                                  // AbrvDayName4
    "Fri",                                  // AbrvDayName5
    "Sat",                                  // AbrvDayName6
    "Sun",                                  // AbrvDayName7
    "January",                              // MonthName1
    "February",                             // MonthName2
    "March",                                // MonthName3
    "April",                                // MonthName4
    "May",                                  // MonthName5
    "June",                                 // MonthName6
    "July",                                 // MonthName7
    "August",                               // MonthName8
    "September",                            // MonthName9
    "October",                              // MonthName10
    "November",                             // MonthName11
    "December",                             // MonthName12

    "Jan",                                  // AbrvMonthName1
    "Feb",                                  // AbrvMonthName2
    "Mar",                                  // AbrvMonthName3
    "Apr",                                  // AbrvMonthName4
    "May",                                  // AbrvMonthName5
    "Jun",                                  // AbrvMonthName6
    "Jul",                                  // AbrvMonthName7
    "Aug",                                  // AbrvMonthName8
    "Sep",                                  // AbrvMonthName9
    "Oct",                                  // AbrvMonthName10
    "Nov",                                  // AbrvMonthName11
    "Dec"                                   // AbrvMonthName12
};

WIN32LOCALE CLOCALE = {
    0,                                      // codepage of the locale
    0,                                      // handle (LCID of the locale)
    1,                                      // isCLocale (is that locale "C" locale?)
    0,                                      // country
    NULL,                                   // cType (category of the locale)
    &CMonetary,                             // Monetary   "
    &CNumeric,                              // Numeric    "
    NULL,                                   // Collate    "
    &CTimeDate,                             // Time       "
    "C",                                    // setLocaleReturn
    L"C"                                    // setLocaleReturnW
};

/*
  __locale is the global locale for the application
*/
LPWIN32LOCALE _EXPDATA __locale = &CLOCALE;
