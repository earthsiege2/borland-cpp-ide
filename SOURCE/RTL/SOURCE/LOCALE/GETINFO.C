/*------------------------------------------------------------------------
 * filename - getinfo.c
 *
 * function(s)
 *      _getLocaleNumeric  - return the required info about the locale
 *
 *
 *
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <ntbc.h>
#include <winnls.h>
#include <locale.h>
#include <_locale.h>

const void* _getLocaleNumericInfo(LCTYPE info)
{
    LPWIN32LOCALE locale = __locale;

    switch (info)
    {
    case LOCALE_SDECIMAL:      return (locale->numeric->Decimal);
    case LOCALE_STHOUSAND:     return (locale->numeric->ThousandSeparator);
    case LOCALE_SGROUPING:     return (locale->numeric->Grouping);
    case LOCALE_SPOSITIVESIGN: return (locale->numeric->PositiveSign);
    case LOCALE_SNEGATIVESIGN: return (locale->numeric->NegativeSign);
    default: return NULL;
    }
}

