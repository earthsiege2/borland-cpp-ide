/*
*
*    INITCAT.C
*
*    Includes all the functions to initialize our categories.
*
*    function(s)
*    _setCType    - set the cType type
*    _setMonetary - set the monetary type
*    _setTime     - set the time type
*    _setNumeric  - set the numeric type
*    _setCollate  - set the collate type
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_locale.h>
#include <ctype.h>

/*
  allocate the buffer that will contain value
  and fill it with the requested information
*/
int _allocAndGetValue(LCID locale, LCTYPE info, LPSTR* buffer)
{
    int BuffSize;

    BuffSize = GetLocaleInfoA(locale, info, *buffer, 0);
    *buffer = (LPSTR) malloc((BuffSize + 1) * sizeof(char));
    if (buffer == NULL)
    {
        SetLastError(ERROR_OUTOFMEMORY);
        return 0;
    }
    return GetLocaleInfoA(locale, info, *buffer, BuffSize + 1) ? 1 : 0;
}

/*
  return the numeric value corresponding to the requested information
*/
int _getShortValue(LCID locale, LCTYPE info, SHORT* value, int maxlength)
{
    int error;
    char *buffer = (char*) malloc(++maxlength * sizeof(char));

    if (buffer == NULL)
    {
        SetLastError(ERROR_OUTOFMEMORY);
        return 0;
    }

    error = GetLocaleInfoA(locale, info, buffer, maxlength);
    if (error != 0)
    {
        *value = (SHORT) atoi(buffer);
        free(buffer);
        return 1;
    }

    free(buffer);
    return 0;
}

/*
  Initialize the Ctype structure by retriving the information from
  the locale
  return 0 if and error occurs
*/
int _setCType(LCID locale, LONG codepage, LPWIN32CTYPE Ctype)
{

    int i;
    unsigned char *p;
    unsigned char *buffer;
    CPINFO CPInfo;

    if (locale == 0)
    {
        memcpy(Ctype->cType, &_chartype[1], 256);
        return 1;
    }
    else
    {
        buffer = (unsigned char *) malloc(257 * sizeof(char));
        if (!buffer)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return 0;
        }

        /* construct string composed of first 256 chars in sequence */
        p = buffer;
        for (i=0; i < 256; i++)
            *p++ = (unsigned char) i;

        if (GetCPInfo( codepage, &CPInfo) == FALSE)
        {
            free(buffer);
            return 0;
        }

        if (CPInfo.MaxCharSize > 1)
        {
            for (p = (unsigned char *)CPInfo.LeadByte; p[0] && p[1]; p += 2)
            {
                for (i = p[0]; i <= p[1]; i++)
                    buffer[i] = 0;
            }
        }

        /* convert to newctype1 table */
        Ctype->cType[0] = 0;
        if (GetStringTypeA (locale, CT_CTYPE1, (char *) buffer, 256, &Ctype->cType[1]) == FALSE)
        {
            free(buffer);
            return 0;
        }
    }
    free(buffer);
    return 1;
}

/*
  Initialize the Monetary structure by retriving the information from
  the locale
  return 0 if and error occurs
*/
int _setMonetary(LCID locale, LPWIN32MONETARY Monetary)
{
    int Error = 1;
    char* NegativeFormats[12] = {
        "($v)",
        "-$v" ,
        "$-v" ,
        "$v-" ,
        "(v$)",
        "-v$" ,
        "v-$" ,
        "v$-" ,
        "-v $",
        "-$ v",
        "v $-",
        "$ v-"
    };


    Error &= _allocAndGetValue(locale, LOCALE_SMONDECIMALSEP,  &Monetary->Decimal);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHOUSANDSEP, &Monetary->ThousandSeparator);
    Error &= _allocAndGetValue(locale, LOCALE_SCURRENCY,  &Monetary->Symbol);
    Error &= _allocAndGetValue(locale, LOCALE_SINTLSYMBOL,  &Monetary->IntlSymbol);
    Error &= _allocAndGetValue(locale, LOCALE_SMONGROUPING,  &Monetary->Grouping);
    Error &= _allocAndGetValue(locale, LOCALE_SPOSITIVESIGN,  &Monetary->PositiveSign);
    Error &= _allocAndGetValue(locale, LOCALE_SNEGATIVESIGN,  &Monetary->NegativeSign);

    Error &= _getShortValue(locale, LOCALE_ICURRDIGITS,  &Monetary->Digits, 3);
    Error &= _getShortValue(locale, LOCALE_IINTLCURRDIGITS, &Monetary->IntlDigits, 3);
    Error &= _getShortValue(locale, LOCALE_ICURRENCY, &Monetary->Mode, 2);
    Error &= _getShortValue(locale, LOCALE_INEGCURR, &Monetary->NegMode, 3);
    Error &= _getShortValue(locale, LOCALE_IPOSSIGNPOSN,  &Monetary->PositiveFormat, 2);
    Error &= _getShortValue(locale, LOCALE_INEGSIGNPOSN,  &Monetary->NegativeFormat, 3);

    Error &= _getShortValue(locale, LOCALE_IPOSSYMPRECEDES,  &Monetary->PosSymbolPrec, 2);
    Error &= _getShortValue(locale, LOCALE_IPOSSEPBYSPACE,  &Monetary->PosSymbolSpace, 2);
    Error &= _getShortValue(locale, LOCALE_INEGSYMPRECEDES,  &Monetary->NegSymbolPrec, 2);
    Error &= _getShortValue(locale, LOCALE_INEGSEPBYSPACE,  &Monetary->NegSymbolSpace, 2);

    Monetary->NegativeFormatString = strdup(NegativeFormats[Monetary->NegMode]);

    return Error ? 1 : 0;
}

/*
  Initialize the Time structure by retriving the information from
  the locale
  return 0 if and error occurs
*/
int _setTime(LCID locale, LPWIN32TIME Time)
{
    int Error = 1;
    char Buffer[64];

    Error &= _allocAndGetValue(locale, LOCALE_SDATE,  &Time->DateSeparator);
    Error &= _allocAndGetValue(locale, LOCALE_STIME,  &Time->TimeSeparator);
    Error &= _allocAndGetValue(locale, LOCALE_STIMEFORMAT,  &Time->TimeFormat);
    Error &= _allocAndGetValue(locale, LOCALE_SSHORTDATE,  &Time->ShortFormat);
    Error &= _allocAndGetValue(locale, LOCALE_SLONGDATE,  &Time->LongFormat);
    Error &= _allocAndGetValue(locale, LOCALE_S1159,  &Time->AM);
    Error &= _allocAndGetValue(locale, LOCALE_S2359,  &Time->PM);

    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME1,  &Time->DayName1);
    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME2,  &Time->DayName2);
    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME3,  &Time->DayName3);
    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME4,  &Time->DayName4);
    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME5,  &Time->DayName5);
    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME6,  &Time->DayName6);
    Error &= _allocAndGetValue(locale, LOCALE_SDAYNAME7,  &Time->DayName7);

    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME1,  &Time->AbrvDayName1);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME2,  &Time->AbrvDayName2);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME3,  &Time->AbrvDayName3);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME4,  &Time->AbrvDayName4);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME5,  &Time->AbrvDayName5);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME6,  &Time->AbrvDayName6);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVDAYNAME7,  &Time->AbrvDayName7);

    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME1,  &Time->MonthName1);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME2,  &Time->MonthName2);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME3,  &Time->MonthName3);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME4,  &Time->MonthName4);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME5,  &Time->MonthName5);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME6,  &Time->MonthName6);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME7,  &Time->MonthName7);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME8,  &Time->MonthName8);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME9,  &Time->MonthName9);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME10,  &Time->MonthName10);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME11,  &Time->MonthName11);
    Error &= _allocAndGetValue(locale, LOCALE_SMONTHNAME12,  &Time->MonthName12);

    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME1,  &Time->AbrvMonthName1);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME2,  &Time->AbrvMonthName2);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME3,  &Time->AbrvMonthName3);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME4,  &Time->AbrvMonthName4);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME5,  &Time->AbrvMonthName5);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME6,  &Time->AbrvMonthName6);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME7,  &Time->AbrvMonthName7);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME8,  &Time->AbrvMonthName8);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME9,  &Time->AbrvMonthName9);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME10,  &Time->AbrvMonthName10);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME11,  &Time->AbrvMonthName11);
    Error &= _allocAndGetValue(locale, LOCALE_SABBREVMONTHNAME12,  &Time->AbrvMonthName12);

    Error &= _getShortValue(locale, LOCALE_IDATE,  &Time->Order, 2);
    Error &= _getShortValue(locale, LOCALE_ILDATE,  &Time->LongOrder, 2);
    Error &= _getShortValue(locale, LOCALE_ITIME,  &Time->TimeFmt, 2);
    Error &= _getShortValue(locale, LOCALE_ICENTURY,  &Time->Century, 1);
    Error &= _getShortValue(locale, LOCALE_ITLZERO,  &Time->TimeLeadZeros, 2);
    Error &= _getShortValue(locale, LOCALE_IDAYLZERO,  &Time->DayLeadZeros, 2);
    Error &= _getShortValue(locale, LOCALE_IMONLZERO,  &Time->MonthLeadZeros, 2);


    if (Error != 0)
    {
        _win32DateTimeToPOSIX(Time->TimeFormat, Buffer, 64);
        free(Time->TimeFormat);
        Time->TimeFormat = strdup(Buffer);

        _win32DateTimeToPOSIX(Time->ShortFormat, Buffer, 64);
        free(Time->ShortFormat);
        Time->ShortFormat = strdup(Buffer);

        _win32DateTimeToPOSIX(Time->LongFormat, Buffer, 64);
        free(Time->LongFormat);
        Time->LongFormat = strdup(Buffer);
    }
    return Error ? 1 : 0;
}

/*
  Initialize the Numeric structure by retriving the information from
  the locale
  return 0 if and error occurs
*/
int _setNumeric(LCID locale, LPWIN32NUMERIC Numeric)
{
    int Error = 1;

    Error &= _allocAndGetValue(locale, LOCALE_SDECIMAL,  &Numeric->Decimal);
    Error &= _allocAndGetValue(locale, LOCALE_STHOUSAND, &Numeric->ThousandSeparator);
    Error &= _allocAndGetValue(locale, LOCALE_SGROUPING,  &Numeric->Grouping);
    Error &= _allocAndGetValue(locale, LOCALE_SPOSITIVESIGN,  &Numeric->PositiveSign);
    Error &= _allocAndGetValue(locale, LOCALE_SNEGATIVESIGN,  &Numeric->NegativeSign);

    Error &= _getShortValue(locale, LOCALE_IDIGITS,  &Numeric->Digits, 3);
    return Error ? 1 : 0;
}

/*
  Initialize the Collate structure by retriving the information from
  the locale
  return 0 if and error occurs
*/

#pragma argsused

int _setCollate(LCID locale, LPWIN32COLLATE Collate)
{
    return 1;
}
