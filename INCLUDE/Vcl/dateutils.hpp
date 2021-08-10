// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DateUtils.pas' rev: 6.00

#ifndef DateUtilsHPP
#define DateUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dateutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const Shortint DaysPerWeek = 0x7;
static const Shortint WeeksPerFortnight = 0x2;
static const Shortint MonthsPerYear = 0xc;
static const Shortint YearsPerDecade = 0xa;
static const Shortint YearsPerCentury = 0x64;
static const Word YearsPerMillennium = 0x3e8;
static const Shortint DayMonday = 0x1;
static const Shortint DayTuesday = 0x2;
static const Shortint DayWednesday = 0x3;
static const Shortint DayThursday = 0x4;
static const Shortint DayFriday = 0x5;
static const Shortint DaySaturday = 0x6;
static const Shortint DaySunday = 0x7;
static const Extended OneHour = 4.166667E-02;
static const Extended OneMinute = 6.944444E-04;
static const Extended OneSecond = 1.157407E-05;
static const Extended OneMillisecond = 1.157407E-08;
extern PACKAGE Word DaysPerYear[2];
static const Word RecodeLeaveFieldAsIs = 0xffff;
extern PACKAGE double ApproxDaysPerMonth;
extern PACKAGE double ApproxDaysPerYear;
extern PACKAGE System::TDateTime __fastcall DateOf(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall TimeOf(const System::TDateTime AValue);
extern PACKAGE bool __fastcall IsInLeapYear(const System::TDateTime AValue);
extern PACKAGE bool __fastcall IsPM(const System::TDateTime AValue);
extern PACKAGE bool __fastcall IsValidDate(const Word AYear, const Word AMonth, const Word ADay);
extern PACKAGE bool __fastcall IsValidTime(const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond);
extern PACKAGE bool __fastcall IsValidDateTime(const Word AYear, const Word AMonth, const Word ADay, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond);
extern PACKAGE bool __fastcall IsValidDateMonthWeek(const Word AYear, const Word AMonth, const Word AWeekOfMonth, const Word ADayOfWeek);
extern PACKAGE bool __fastcall IsValidDateDay(const Word AYear, const Word ADayOfYear);
extern PACKAGE bool __fastcall IsValidDateWeek(const Word AYear, const Word AWeekOfYear, const Word ADayOfWeek);
extern PACKAGE Word __fastcall DaysInYear(const System::TDateTime AValue);
extern PACKAGE Word __fastcall DaysInAYear(const Word AYear);
extern PACKAGE Word __fastcall DaysInMonth(const System::TDateTime AValue);
extern PACKAGE Word __fastcall DaysInAMonth(const Word AYear, const Word AMonth);
extern PACKAGE Word __fastcall WeeksInYear(const System::TDateTime AValue);
extern PACKAGE Word __fastcall WeeksInAYear(const Word AYear);
extern PACKAGE System::TDateTime __fastcall Today(void);
extern PACKAGE System::TDateTime __fastcall Yesterday(void);
extern PACKAGE System::TDateTime __fastcall Tomorrow(void);
extern PACKAGE bool __fastcall IsToday(const System::TDateTime AValue);
extern PACKAGE bool __fastcall IsSameDay(const System::TDateTime AValue, const System::TDateTime ABasis);
extern PACKAGE Word __fastcall YearOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MonthOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall WeekOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall DayOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall HourOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MinuteOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall SecondOf(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MilliSecondOf(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall StartOfTheYear(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall EndOfTheYear(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall StartOfTheMonth(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall EndOfTheMonth(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall StartOfTheWeek(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall EndOfTheWeek(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall StartOfTheDay(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall EndOfTheDay(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall StartOfAYear(const Word AYear);
extern PACKAGE System::TDateTime __fastcall EndOfAYear(const Word AYear);
extern PACKAGE System::TDateTime __fastcall StartOfAMonth(const Word AYear, const Word AMonth);
extern PACKAGE System::TDateTime __fastcall EndOfAMonth(const Word AYear, const Word AMonth);
extern PACKAGE System::TDateTime __fastcall StartOfAWeek(const Word AYear, const Word AWeekOfYear, const Word ADayOfWeek = (Word)(0x1));
extern PACKAGE System::TDateTime __fastcall EndOfAWeek(const Word AYear, const Word AWeekOfYear, const Word ADayOfWeek = (Word)(0x7));
extern PACKAGE System::TDateTime __fastcall StartOfADay(const Word AYear, const Word ADayOfYear)/* overload */;
extern PACKAGE System::TDateTime __fastcall EndOfADay(const Word AYear, const Word ADayOfYear)/* overload */;
extern PACKAGE System::TDateTime __fastcall StartOfADay(const Word AYear, const Word AMonth, const Word ADay)/* overload */;
extern PACKAGE System::TDateTime __fastcall EndOfADay(const Word AYear, const Word AMonth, const Word ADay)/* overload */;
extern PACKAGE Word __fastcall MonthOfTheYear(const System::TDateTime AValue);
extern PACKAGE Word __fastcall WeekOfTheYear(const System::TDateTime AValue)/* overload */;
extern PACKAGE Word __fastcall WeekOfTheYear(const System::TDateTime AValue, Word &AYear)/* overload */;
extern PACKAGE Word __fastcall DayOfTheYear(const System::TDateTime AValue);
extern PACKAGE Word __fastcall HourOfTheYear(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall MinuteOfTheYear(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall SecondOfTheYear(const System::TDateTime AValue);
extern PACKAGE __int64 __fastcall MilliSecondOfTheYear(const System::TDateTime AValue);
extern PACKAGE Word __fastcall WeekOfTheMonth(const System::TDateTime AValue)/* overload */;
extern PACKAGE Word __fastcall WeekOfTheMonth(const System::TDateTime AValue, Word &AYear, Word &AMonth)/* overload */;
extern PACKAGE Word __fastcall DayOfTheMonth(const System::TDateTime AValue);
extern PACKAGE Word __fastcall HourOfTheMonth(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MinuteOfTheMonth(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall SecondOfTheMonth(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall MilliSecondOfTheMonth(const System::TDateTime AValue);
extern PACKAGE Word __fastcall DayOfTheWeek(const System::TDateTime AValue);
extern PACKAGE Word __fastcall HourOfTheWeek(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MinuteOfTheWeek(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall SecondOfTheWeek(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall MilliSecondOfTheWeek(const System::TDateTime AValue);
extern PACKAGE Word __fastcall HourOfTheDay(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MinuteOfTheDay(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall SecondOfTheDay(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall MilliSecondOfTheDay(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MinuteOfTheHour(const System::TDateTime AValue);
extern PACKAGE Word __fastcall SecondOfTheHour(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall MilliSecondOfTheHour(const System::TDateTime AValue);
extern PACKAGE Word __fastcall SecondOfTheMinute(const System::TDateTime AValue);
extern PACKAGE unsigned __fastcall MilliSecondOfTheMinute(const System::TDateTime AValue);
extern PACKAGE Word __fastcall MilliSecondOfTheSecond(const System::TDateTime AValue);
extern PACKAGE bool __fastcall WithinPastYears(const System::TDateTime ANow, const System::TDateTime AThen, const int AYears);
extern PACKAGE bool __fastcall WithinPastMonths(const System::TDateTime ANow, const System::TDateTime AThen, const int AMonths);
extern PACKAGE bool __fastcall WithinPastWeeks(const System::TDateTime ANow, const System::TDateTime AThen, const int AWeeks);
extern PACKAGE bool __fastcall WithinPastDays(const System::TDateTime ANow, const System::TDateTime AThen, const int ADays);
extern PACKAGE bool __fastcall WithinPastHours(const System::TDateTime ANow, const System::TDateTime AThen, const __int64 AHours);
extern PACKAGE bool __fastcall WithinPastMinutes(const System::TDateTime ANow, const System::TDateTime AThen, const __int64 AMinutes);
extern PACKAGE bool __fastcall WithinPastSeconds(const System::TDateTime ANow, const System::TDateTime AThen, const __int64 ASeconds);
extern PACKAGE bool __fastcall WithinPastMilliSeconds(const System::TDateTime ANow, const System::TDateTime AThen, const __int64 AMilliSeconds);
extern PACKAGE int __fastcall YearsBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE int __fastcall MonthsBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE int __fastcall WeeksBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE int __fastcall DaysBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE __int64 __fastcall HoursBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE __int64 __fastcall MinutesBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE __int64 __fastcall SecondsBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE __int64 __fastcall MilliSecondsBetween(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall YearSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall MonthSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall WeekSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall DaySpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall HourSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall MinuteSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall SecondSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE double __fastcall MilliSecondSpan(const System::TDateTime ANow, const System::TDateTime AThen);
extern PACKAGE System::TDateTime __fastcall IncYear(const System::TDateTime AValue, const int ANumberOfYears = 0x1);
extern PACKAGE System::TDateTime __fastcall IncWeek(const System::TDateTime AValue, const int ANumberOfWeeks = 0x1);
extern PACKAGE System::TDateTime __fastcall IncDay(const System::TDateTime AValue, const int ANumberOfDays = 0x1);
extern PACKAGE System::TDateTime __fastcall IncHour(const System::TDateTime AValue, const __int64 ANumberOfHours = 0x000000001);
extern PACKAGE System::TDateTime __fastcall IncMinute(const System::TDateTime AValue, const __int64 ANumberOfMinutes = 0x000000001);
extern PACKAGE System::TDateTime __fastcall IncSecond(const System::TDateTime AValue, const __int64 ANumberOfSeconds = 0x000000001);
extern PACKAGE System::TDateTime __fastcall IncMilliSecond(const System::TDateTime AValue, const __int64 ANumberOfMilliSeconds = 0x000000001);
extern PACKAGE System::TDateTime __fastcall EncodeDateTime(const Word AYear, const Word AMonth, const Word ADay, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond);
extern PACKAGE void __fastcall DecodeDateTime(const System::TDateTime AValue, /* out */ Word &AYear, /* out */ Word &AMonth, /* out */ Word &ADay, /* out */ Word &AHour, /* out */ Word &AMinute, /* out */ Word &ASecond, /* out */ Word &AMilliSecond);
extern PACKAGE System::TDateTime __fastcall EncodeDateWeek(const Word AYear, const Word AWeekOfYear, const Word ADayOfWeek = (Word)(0x1));
extern PACKAGE void __fastcall DecodeDateWeek(const System::TDateTime AValue, /* out */ Word &AYear, /* out */ Word &AWeekOfYear, /* out */ Word &ADayOfWeek);
extern PACKAGE System::TDateTime __fastcall EncodeDateDay(const Word AYear, const Word ADayOfYear);
extern PACKAGE void __fastcall DecodeDateDay(const System::TDateTime AValue, /* out */ Word &AYear, /* out */ Word &ADayOfYear);
extern PACKAGE System::TDateTime __fastcall EncodeDateMonthWeek(const Word AYear, const Word AMonth, const Word AWeekOfMonth, const Word ADayOfWeek);
extern PACKAGE void __fastcall DecodeDateMonthWeek(const System::TDateTime AValue, /* out */ Word &AYear, /* out */ Word &AMonth, /* out */ Word &AWeekOfMonth, /* out */ Word &ADayOfWeek);
extern PACKAGE bool __fastcall TryEncodeDateTime(const Word AYear, const Word AMonth, const Word ADay, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond, /* out */ System::TDateTime &AValue);
extern PACKAGE bool __fastcall TryEncodeDateWeek(const Word AYear, const Word AWeekOfYear, /* out */ System::TDateTime &AValue, const Word ADayOfWeek = (Word)(0x1));
extern PACKAGE bool __fastcall TryEncodeDateDay(const Word AYear, const Word ADayOfYear, /* out */ System::TDateTime &AValue);
extern PACKAGE bool __fastcall TryEncodeDateMonthWeek(const Word AYear, const Word AMonth, const Word AWeekOfMonth, const Word ADayOfWeek, System::TDateTime &AValue);
extern PACKAGE System::TDateTime __fastcall RecodeYear(const System::TDateTime AValue, const Word AYear);
extern PACKAGE System::TDateTime __fastcall RecodeMonth(const System::TDateTime AValue, const Word AMonth);
extern PACKAGE System::TDateTime __fastcall RecodeDay(const System::TDateTime AValue, const Word ADay);
extern PACKAGE System::TDateTime __fastcall RecodeHour(const System::TDateTime AValue, const Word AHour);
extern PACKAGE System::TDateTime __fastcall RecodeMinute(const System::TDateTime AValue, const Word AMinute);
extern PACKAGE System::TDateTime __fastcall RecodeSecond(const System::TDateTime AValue, const Word ASecond);
extern PACKAGE System::TDateTime __fastcall RecodeMilliSecond(const System::TDateTime AValue, const Word AMilliSecond);
extern PACKAGE System::TDateTime __fastcall RecodeDate(const System::TDateTime AValue, const Word AYear, const Word AMonth, const Word ADay);
extern PACKAGE System::TDateTime __fastcall RecodeTime(const System::TDateTime AValue, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond);
extern PACKAGE System::TDateTime __fastcall RecodeDateTime(const System::TDateTime AValue, const Word AYear, const Word AMonth, const Word ADay, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond);
extern PACKAGE bool __fastcall TryRecodeDateTime(const System::TDateTime AValue, const Word AYear, const Word AMonth, const Word ADay, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond, /* out */ System::TDateTime &AResult);
extern PACKAGE Types::TValueRelationship __fastcall CompareDateTime(const System::TDateTime A, const System::TDateTime B);
extern PACKAGE bool __fastcall SameDateTime(const System::TDateTime A, const System::TDateTime B);
extern PACKAGE Types::TValueRelationship __fastcall CompareDate(const System::TDateTime A, const System::TDateTime B);
extern PACKAGE bool __fastcall SameDate(const System::TDateTime A, const System::TDateTime B);
extern PACKAGE Types::TValueRelationship __fastcall CompareTime(const System::TDateTime A, const System::TDateTime B);
extern PACKAGE bool __fastcall SameTime(const System::TDateTime A, const System::TDateTime B);
extern PACKAGE Word __fastcall NthDayOfWeek(const System::TDateTime AValue);
extern PACKAGE void __fastcall DecodeDayOfWeekInMonth(const System::TDateTime AValue, /* out */ Word &AYear, /* out */ Word &AMonth, /* out */ Word &ANthDayOfWeek, /* out */ Word &ADayOfWeek);
extern PACKAGE System::TDateTime __fastcall EncodeDayOfWeekInMonth(const Word AYear, const Word AMonth, const Word ANthDayOfWeek, const Word ADayOfWeek);
extern PACKAGE bool __fastcall TryEncodeDayOfWeekInMonth(const Word AYear, const Word AMonth, const Word ANthDayOfWeek, const Word ADayOfWeek, /* out */ System::TDateTime &AValue);
extern PACKAGE double __fastcall DateTimeToJulianDate(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall JulianDateToDateTime(const double AValue);
extern PACKAGE bool __fastcall TryJulianDateToDateTime(const double AValue, /* out */ System::TDateTime &ADateTime);
extern PACKAGE double __fastcall DateTimeToModifiedJulianDate(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall ModifiedJulianDateToDateTime(const double AValue);
extern PACKAGE bool __fastcall TryModifiedJulianDateToDateTime(const double AValue, /* out */ System::TDateTime &ADateTime);
extern PACKAGE __int64 __fastcall DateTimeToUnix(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall UnixToDateTime(const __int64 AValue);
extern PACKAGE void __fastcall InvalidDateTimeError(const Word AYear, const Word AMonth, const Word ADay, const Word AHour, const Word AMinute, const Word ASecond, const Word AMilliSecond, const System::TDateTime ABaseDate = 0.000000E+00);
extern PACKAGE void __fastcall InvalidDateWeekError(const Word AYear, const Word AWeekOfYear, const Word ADayOfWeek);
extern PACKAGE void __fastcall InvalidDateDayError(const Word AYear, const Word ADayOfYear);
extern PACKAGE void __fastcall InvalidDateMonthWeekError(const Word AYear, const Word AMonth, const Word AWeekOfMonth, const Word ADayOfWeek);
extern PACKAGE void __fastcall InvalidDayOfWeekInMonthError(const Word AYear, const Word AMonth, const Word ANthDayOfWeek, const Word ADayOfWeek);

}	/* namespace Dateutils */
using namespace Dateutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DateUtils
