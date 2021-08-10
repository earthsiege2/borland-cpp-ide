/*
*
*    LCONV.C
*
*    module for ANSI C localeconv() function
*
*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <io.h>
#include <string.h>
#include <_string.h>
#include <fcntl.h>
#include <dos.h>
#include <ctype.h>
#include <sys/stat.h>
#include <limits.h>
#include <dir.h>
#include <_locale.h>


struct lconv * _RTLENTRY _EXPFUNC _llocaleconv( void )

{
    /* lock locale convention global structure */
    _lock_locale();

   _localeconvention.decimal_point =
        (char *) &_pLocale->NumericCat.NumericInfo.decimal_point;

   _localeconvention.thousands_sep =
        (char *) &_pLocale->NumericCat.NumericInfo.thousands_sep;

   _localeconvention.grouping =
        (char *) &_pLocale->NumericCat.NumericInfo.grouping;

   _localeconvention.int_curr_symbol =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.int_curr_symbol;

   _localeconvention.currency_symbol =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.currency_symbol;

    _localeconvention.mon_decimal_point =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.mon_decimal_point;

    _localeconvention.mon_thousands_sep =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.mon_thousands_sep;

    _localeconvention.mon_grouping =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.mon_grouping;

    _localeconvention.positive_sign =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.positive_sign;

   _localeconvention.negative_sign =
        (char *) &_pLocale->MonetaryCat.MonetaryInfo.negative_sign;

    _localeconvention.int_frac_digits =
        _pLocale->MonetaryCat.MonetaryInfo.int_frac_digits;

    _localeconvention.frac_digits =
        _pLocale->MonetaryCat.MonetaryInfo.frac_digits;

    _localeconvention.p_cs_precedes =
        _pLocale->MonetaryCat.MonetaryInfo.p_cs_precedes;

    _localeconvention.p_sep_by_space =
        _pLocale->MonetaryCat.MonetaryInfo.p_sep_by_space;

    _localeconvention.n_cs_precedes =
        _pLocale->MonetaryCat.MonetaryInfo.n_cs_precedes;

    _localeconvention.n_sep_by_space =
        _pLocale->MonetaryCat.MonetaryInfo.n_sep_by_space;

    _localeconvention.p_sign_posn =
        _pLocale->MonetaryCat.MonetaryInfo.p_sign_posn;

    _localeconvention.n_sign_posn =
        _pLocale->MonetaryCat.MonetaryInfo.n_sign_posn;

    /* unlock before leaving */
    _unlock_locale();

    return( &_localeconvention );

}

