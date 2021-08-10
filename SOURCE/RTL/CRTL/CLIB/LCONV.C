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

#if defined( _RTLDLL )
#pragma option -zC_TEXTA
#endif

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
#include <rtldata.h>
#include <_locale.h>


struct lconv * _RTLENTRY _EXPFUNC _llocaleconv( void )
{
    _QRTLDataBlock;

   _QRTLInstanceData(_localeconvention).decimal_point =
        (char *) &_QRTLInstanceData(_pLocale)->NumericCat.NumericInfo.decimal_point;

   _QRTLInstanceData(_localeconvention).thousands_sep =
        (char *) &_QRTLInstanceData(_pLocale)->NumericCat.NumericInfo.thousands_sep;

   _QRTLInstanceData(_localeconvention).grouping =
        (char *) &_QRTLInstanceData(_pLocale)->NumericCat.NumericInfo.grouping;

   _QRTLInstanceData(_localeconvention).int_curr_symbol =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.int_curr_symbol;

   _QRTLInstanceData(_localeconvention).currency_symbol =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.currency_symbol;

    _QRTLInstanceData(_localeconvention).mon_decimal_point =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.mon_decimal_point;

    _QRTLInstanceData(_localeconvention).mon_thousands_sep =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.mon_thousands_sep;

    _QRTLInstanceData(_localeconvention).mon_grouping =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.mon_grouping;

    _QRTLInstanceData(_localeconvention).positive_sign =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.positive_sign;

   _QRTLInstanceData(_localeconvention).negative_sign =
        (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.negative_sign;

    _QRTLInstanceData(_localeconvention).int_frac_digits =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.int_frac_digits;

    _QRTLInstanceData(_localeconvention).frac_digits =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.frac_digits;

    _QRTLInstanceData(_localeconvention).p_cs_precedes =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.p_cs_precedes;

    _QRTLInstanceData(_localeconvention).p_sep_by_space =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.p_sep_by_space;

    _QRTLInstanceData(_localeconvention).n_cs_precedes =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.n_cs_precedes;

    _QRTLInstanceData(_localeconvention).n_sep_by_space =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.n_sep_by_space;

    _QRTLInstanceData(_localeconvention).p_sign_posn =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.p_sign_posn;

    _QRTLInstanceData(_localeconvention).n_sign_posn =
        _QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo.n_sign_posn;

    return( &_QRTLInstanceData(_localeconvention) );

}

