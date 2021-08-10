/*
*
*    CLOCALE.C
*
*    the "C" locale and other locale related globals
*
*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <_locale.h>

extern unsigned char _Cdecl _lower[ 256 ];
extern unsigned char _Cdecl _upper[ 256 ];

/*
 * The "C" locale static object
*/

struct LOCALEOBJECT _Clocale =

{
   /* struct LocaleHeader */
    {

        {
            C_LOCALE_SHORT_STR,
            1, 0, 0, 0,
        },

        _STATIC,
        1, 0,

        /* min & max char bytes */
        1, 1,

        6,
        0,

        __LC_COLLATE + __LC_CTYPE + __LC_TIME + __LC_MONETARY + __LC_NUMERIC + __LC_MESSAGES,

        0, 0, 0,    0, 0, 0, 0
    },

    /* locale string */

    C_LOCALE_FULL_STR,

    /* LC_CTYPE */

    {

        {
        ( sizeof( struct CategoryHeader ) ) +
        ( sizeof( int ) * SBCS_SIZE ) +
        ( 2 * SBCS_SIZE ),

        C_LOCALE_SHORT_STR,

        },
    },

    (unsigned char *) &_ctype,
    (unsigned char *) &_lower,
    (unsigned char *) &_upper,

    /* LC_COLLATE */
    {
        {
            0,
            C_LOCALE_SHORT_STR,
        },

        {
            0,
            0,
            { 0, 0, 0, 0, 0, 0, 0, 0 },
            0,
        },
    },

    NULL,
    NULL,
    NULL,
    NULL,

    strcmp,
    strxfrm,

    /* LC_MONETARY */
    {
        {
            ( sizeof( struct CategoryHeader ) + ( sizeof( struct Monetary ) ) ),
            C_LOCALE_SHORT_STR,
        },

        /* struct Monetary */
        {

        "",          /*  int_curr_symbol   */

        "",          /*  currency_symbol   */

        "",          /*  mon_decimal_point */

        "",          /*  mon_thousands_sep */

        "",          /*  mon_grouping      */

        "",          /*  positive_sign     */

        "",          /*  negative_sign     */

        CHAR_MAX,    /*  int_frac_digits   */

        CHAR_MAX,    /*  frac_digits       */

        CHAR_MAX,    /*  p_cs_precedes     */
        
        CHAR_MAX,    /*  p_sep_by_space    */

        CHAR_MAX,    /*  n_cs_precedes     */

        CHAR_MAX,    /*  n_sep_by_space    */

        CHAR_MAX,    /*  p_sign_posn       */

        CHAR_MAX     /*  n_sign_posn       */

        },
    },

    /* LC_NUMERIC */

    {
        {
            ( sizeof( struct CategoryHeader ) + ( sizeof( struct Numeric ) ) ),
            C_LOCALE_SHORT_STR,
        },

        /* struct Numeric */
        {

        ".",            /* decimal point */

        "",            /* thousands_sep */

        ""                /* grouping      */

        },
    },

    /* LC_TIME */
    {
        {
            ( sizeof( struct CategoryHeader ) + ( sizeof( struct TimeDate ) ) ),
            C_LOCALE_SHORT_STR,
        },

        /* struct TimeDate */
        {

        {
            "Sun",
            "Mon",
            "Tue",
            "Wed",
            "Thu",
            "Fri",
            "Sat"
        },

        {
            "Sunday",   
            "Monday",   
            "Tuesday",  
            "Wednesday",
            "Thursday", 
            "Friday",   
            "Saturday", 
        },

        {
            "Jan",
            "Feb",
            "Mar",
            "Apr",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
        },

        {
            "January",  
            "February", 
            "March",    
            "April",    
            "May",      
            "June",     
            "July",     
            "August",   
            "September",
            "October",  
            "November", 
            "December" 
        },

        {
            "AM",
            "PM"
        },

        "%a %b %d %X %Y",

        "%a %b %d",

        "%H:%M:%S",

        "%I:%M:%S %p",

        " ",

        " ",

        " ",

        {
            /* alt_digits */
            0
        },

        },
    },

    /* LC_MESSAGES */
    {
        {
            ( sizeof( struct CategoryHeader ) + ( sizeof( struct Messages ) ) ),
            C_LOCALE_SHORT_STR,
        },

        /* struct Messages */
        {
            "y",
            "n",
        },
    },

    /* LC_userdef */
    {
        {
            sizeof( struct CategoryHeader ) +
            sizeof( struct Messages ),
            "",
        },

        NULL,
    },
};

const char *_LocaleCatNames[ LC_LAST + 1 ] =

{
    "LC_ALL",
    "LC_COLLATE",
    "LC_CTYPE",
    "LC_MONETARY",
    "LC_NUMERIC",
    "LC_TIME",
    "LC_MESSAGES",
    "LC_userdef"
};

/* initial state of _pLocale refers to the static "C" locale */
struct LOCALEOBJECT * _EXPDATA _pLocale = (struct LOCALEOBJECT *) &_Clocale;

/* default locale library name */
char _EXPDATA _LocaleLibName[ MAXPATH + 1 ] = { LOCALE_LIB };
