/*------------------------------------------------------------------------
 * filename - getinfo2.c
 *
 * function(s)
 *      _getLocaleMonetary - return the required info about the locale
 *      _getLocaleMonetaryNegFmt - return the monertary negative format
 *
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1998, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <ntbc.h>
#include <winnls.h>
#include <locale.h>
#include <_locale.h>

const void* _getLocaleMonetaryInfo(LCTYPE info)
{
    LPWIN32LOCALE locale = __locale;

    switch (info)
    {
    case LOCALE_SMONDECIMALSEP:   return (locale->monetary->Decimal);
    case LOCALE_SMONTHOUSANDSEP:  return (locale->monetary->ThousandSeparator);
    case LOCALE_SCURRENCY:        return (locale->monetary->Symbol);
    case LOCALE_SINTLSYMBOL:      return (locale->monetary->IntlSymbol);
    case LOCALE_SMONGROUPING:     return (locale->monetary->Grouping);
    case LOCALE_SPOSITIVESIGN:    return (locale->monetary->PositiveSign);
    case LOCALE_SNEGATIVESIGN:    return (locale->monetary->NegativeSign);

    case LOCALE_ICURRDIGITS:      return (void*) (locale->monetary->Digits);
    case LOCALE_IINTLCURRDIGITS:  return (void*) (locale->monetary->IntlDigits);
    case LOCALE_ICURRENCY:        return (void*) (locale->monetary->Mode);
    case LOCALE_INEGCURR:         return (void*) (locale->monetary->NegMode);
    case LOCALE_IPOSSIGNPOSN:     return (void*) (locale->monetary->PositiveFormat);
    case LOCALE_INEGSIGNPOSN:     return (void*) (locale->monetary->NegativeFormat);
    case LOCALE_IPOSSYMPRECEDES:  return (void*) (locale->monetary->PosSymbolPrec);
    case LOCALE_IPOSSEPBYSPACE:   return (void*) (locale->monetary->PosSymbolSpace);
    case LOCALE_INEGSYMPRECEDES:  return (void*) (locale->monetary->NegSymbolPrec);
    case LOCALE_INEGSEPBYSPACE:   return (void*) (locale->monetary->NegSymbolSpace);
    default: return NULL;
    }
}

const void* _getLocaleMonetaryNegFmt()
{
    LPWIN32LOCALE locale = __locale;

    return locale->monetary->NegativeFormatString;
};
