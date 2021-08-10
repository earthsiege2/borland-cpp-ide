/*
*
*    _LOCALE.H
*
*    locale support definitions
*
*
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

#ifndef ___LOCALE_H
#define ___LOCALE_H

#pragma pragma pack(push, 1)

#ifndef __FLAT__

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(__STDDEF_H)
#include <stddef.h>
#endif

#if !defined(__LOCALE_H)
#include <locale.h>
#endif

#if !defined(__DIR_H)
#include <dir.h>
#endif

/* version info */
#define LCLIB_MAJOR_VERSION                      1
#define LCLIB_MINOR_VERSION                      0
#define LCLIB_REVISION                           1

/* error codes */
#define LOCALE_NO_ERROR                          0
#define LOCALE_ERROR                            -1
#define OSFILE_NO_ERROR                          0
#define OSFILE_ERROR                            -1


#define MAX_COMPRESS_ELEMENT_SIZE               10
#define MAX_EXPANSION_ELEMENT_SIZE              10
#define MAX_STRING_ELEMENT_SIZE                 10
#define MAX_SUBSTITUTION_ELEMENT_SIZE           10
#define MAX_LEVELS                               8
#define MAX_LOCALE_NAME                         25

#define MAX_DAYS                                 7
#define MAX_MONS                                12
#define MAX_AMPM                                 2
#define MAX_ALT_DIGITS                         100

#define MAX_ABDAY_LEN                           10
#define MAX_ABMON_LEN                           10
#define MAX_DAY_LEN                             20
#define MAX_MON_LEN                             20
#define MAX_AMPM_LEN                            10
#define MAX_DTFMT_LEN                           25
#define MAX_ALT_DIGIT_LEN                       10

#define _AM                                      0
#define _PM                                      1

#define FORWARD_RULE                          0x01
#define BACKWARD_RULE                         0x02

#define SUBSTITUTE_RULE                       0x04
#define NO_SUBSTITUTE_RULE                    0x08

#define POSITION_RULE                         0x10
#define NO_POSITION_RULE                      0x20

#define MAX_LCNAME_LEN                          32
#define MAX_CATNAME_LEN                         32
#define MAX_CSNAME_LEN                          16
#define MAX_EXPAND_CHARS                        16
#define MAX_COMPRESS_CHARS                      16
#define MAX_SUBSTITUTE_STRS                     16

/* SBCS code set size */
#define SBCS_SIZE                              256

#define _TOUPPER_                        SBCS_SIZE
#define _TOLOWER_                        SBCS_SIZE

#define _SBCS_                              0x0101
#define _MBCS_12_                           0x0102
#define _DBCS_                              0x0202
#define _MBCS_STATE_                        0x0000


/* type size: */

/* collation class */
#define SBCS_COLLATECLASS_TSIZE     ( SBCS_SIZE + 1 )

/* collation level */
#define SBCS_COLLATELEVEL_TSIZE     ( SBCS_SIZE + 1 )

/* byte size: */

/* collation class */
#define SBCS_COLLATECLASS_BSIZE     ( SBCS_COLLATECLASS_TSIZE * sizeof( unsigned char ) )

/* collation level */
#define SBCS_COLLATELEVEL_BSIZE     ( SBCS_COLLATELEVEL_TSIZE * sizeof( unsigned char ) )

/* type size: */

/* ctype */
#define SBCS_CTYPE_TSIZE            ( SBCS_SIZE + 1 )

/* lower */
#define SBCS_LOWER_TSIZE            ( SBCS_SIZE )

/* upper */
#define SBCS_UPPER_TSIZE            ( SBCS_SIZE )

/* byte size: */

/* ctype */
#define SBCS_CTYPE_BSIZE            ( SBCS_CTYPE_TSIZE * sizeof( unsigned char ) )

/* lower */
#define SBCS_LOWER_BSIZE            ( SBCS_LOWER_TSIZE * sizeof( unsigned char ) )

/* upper */
#define SBCS_UPPER_BSIZE            ( SBCS_UPPER_TSIZE * sizeof( unsigned char ) )

/* category size: */

/* LC_CTYPE */
#define SBCS_CTYPE_CATSIZE         (                   \
                                    SBCS_CTYPE_BSIZE + \
                                    SBCS_LOWER_BSIZE + \
                                    SBCS_UPPER_BSIZE   \
                                   )

#define LC_RESERVED1                             8
#define LC_RESERVED2                             9
#define LC_RESERVED3                            10
#define LC_RESERVED4                            11
#define LC_RESERVED5                            12
#define LC_RESERVED6                            13


/* computed bit masks */
#define __LC_COLLATE                        0x0001
#define __LC_CTYPE                          0x0002
#define __LC_MONETARY                       0x0004
#define __LC_NUMERIC                        0x0008
#define __LC_TIME                           0x0010
#define __LC_MESSAGES                       0x0020
#define __LC_userdef                        0x0040

#define __LC_RESERVED1                      0x0080
#define __LC_RESERVED2                      0x0100
#define __LC_RESERVED3                      0x0200
#define __LC_RESERVED4                      0x0400
#define __LC_RESERVED5                      0x0800
#define __LC_RESERVED6                      0x1000

#define _STATIC                             0x0000
#define _DYNAMIC                            0x0001

#define SEGLOC                                0x02

#define LENGTH_DIFFERENCE                  0x07f7f

#define CODESET_SIZE                     SBCS_SIZE


/* string status */
#define INSTRING1                             0x00
#define INSTRING2                             0x01
#define INSUBSTITUTION                        0x02
#define INEXPANSION                           0x04
#define STRING_ENDED                          0x80

/* collation character classes */
#define CLASS_NORMAL                           0x01
#define CLASS_SUBSTITUTE                       0x02
#define CLASS_EXPAND                           0x04
#define CLASS_COMPRESS                         0x08
#define CLASS_POSITION                         0x10

#define IGNORE_WEIGHT                          0x00
#define POSITION_PREFIX                        0x01


#define LANGVAR                                "LANG"
#define LOCALE_LIB                             "LOCALE.BLL"
#define MODIFIER_SYM                           (short) '@'
#define LOCALE_STR_SYM                         (short) ';'

#define C_LOCALE_FULL_STR                      "C;C;C;C;C;C;;"
#define C_LOCALE_SHORT_STR                     "C"

#define POSIX_LOCALE_FULL_STR                  "POSIX;POSIX;POSIX;POSIX;POSIX;POSIX;;"
#define POSIX_LOCALE_SHORT_STR                 "POSIX"


struct Collate {

    unsigned short CollationID;

    unsigned short nLevels;

    unsigned char LevelRules[ MAX_LEVELS ];

    unsigned short nTableSize;

};

struct Compression {

    unsigned char ElementLength;

    unsigned char CmpCollationElement[ MAX_COMPRESS_ELEMENT_SIZE ];

    unsigned char LevelWeight[ MAX_LEVELS ];

};


struct Expansion {

    unsigned char ExpCollationElement;

    unsigned char ExpansionLength;

    unsigned char LevelWeight1[ MAX_LEVELS ][ MAX_EXPANSION_ELEMENT_SIZE ];

};


struct Substitution {

    unsigned char StringLength;

    unsigned char StringElement[ MAX_STRING_ELEMENT_SIZE ];

    unsigned char SubstitutionLength;

    unsigned char SubstitutionElement[ MAX_SUBSTITUTION_ELEMENT_SIZE ];

};

struct TimeDate {

    unsigned char abday[ MAX_DAYS ][ MAX_ABDAY_LEN ];

    unsigned char day[ MAX_DAYS ][ MAX_DAY_LEN ];

    unsigned char abmon[ MAX_MONS ][ MAX_ABMON_LEN ];

    unsigned char mon[ MAX_MONS ][ MAX_MON_LEN ];

    unsigned char am_pm[ MAX_AMPM ][ MAX_AMPM_LEN ];

    unsigned char d_t_fmt[ MAX_DTFMT_LEN ];

    unsigned char d_fmt[ MAX_DTFMT_LEN ];

    unsigned char t_fmt[ MAX_DTFMT_LEN ];

    unsigned char t_fmt_ampm[ MAX_DTFMT_LEN ];

    unsigned char era[ MAX_DTFMT_LEN ];

    unsigned char era_year[ MAX_DTFMT_LEN ];

    unsigned char era_d_fmt[ MAX_DTFMT_LEN ];

    unsigned char alt_digits[ MAX_ALT_DIGITS * MAX_ALT_DIGIT_LEN ];

};

struct Numeric {

    unsigned char decimal_point[ 2 ];

    unsigned char thousands_sep[ 10 ];

    unsigned char grouping[ 20 ];

};

struct Monetary {

    unsigned char int_curr_symbol[ 5 ];

    unsigned char currency_symbol[ 5 ];

    unsigned char mon_decimal_point[ 2 ];

    unsigned char mon_thousands_sep[ 5 ];

    unsigned char mon_grouping[ 5 ];

    unsigned char positive_sign[ 5 ];

    unsigned char negative_sign[ 5 ];

    unsigned char int_frac_digits;

    unsigned char frac_digits;

    unsigned char p_cs_precedes;

    unsigned char p_sep_by_space;

    unsigned char n_cs_precedes;

    unsigned char n_sep_by_space;

    unsigned char p_sign_posn;

    unsigned char n_sign_posn;

};

struct Messages {

    unsigned char yesexpr[ 5 ];

    unsigned char noexpr[ 5 ];

};

struct CategoryHeader {

    unsigned short CategorySize;

    char CategoryName[ MAX_CATNAME_LEN ];

    short DefaultCategory;

};

struct TimeCategory {

    struct CategoryHeader Header;

    struct TimeDate TimeDateInfo;

};

struct NumericCategory {

    struct CategoryHeader Header;

    struct Numeric NumericInfo;

};

struct MonetaryCategory {

    struct CategoryHeader Header;

    struct Monetary MonetaryInfo;

};

struct MessagesCategory {

    struct CategoryHeader Header;

    struct Messages MessagesInfo;

};

struct CollateCategory {

    struct CategoryHeader Header;

    struct Collate CollateInfo;

};

struct CtypeCategory {

    struct CategoryHeader Header;

};

struct UserCategory {

    struct CategoryHeader Header;

    void * UserInfo;

};

struct LocaleVersion {

    unsigned char _Name[ MAX_LCNAME_LEN ];

    unsigned char _Major;

    unsigned char _Minor;

    unsigned char _Revision;

    /* padding for word alignment */
    unsigned char _Reserved;

};

struct LocaleLocation {

    char LocaleName[ MAX_LCNAME_LEN ];

    unsigned short ID;

    long LocaleOffset;

};


struct LocaleLibraryHeader {

    struct LocaleVersion LocaleLibraryVersion;

    unsigned short nLocales;

};

struct LocaleHeader {

    struct LocaleVersion ThisVersion;

    short ObjAllocType;

    unsigned short LocaleID;

    unsigned short LanguageID;

    /* minimum bytes in a character */
    unsigned char nCharMinBytes;

    /* maximum bytes in a character */
    unsigned char nCharMaxBytes;

    /* number of LC_ categories in this locale */
    short    nCategories;

    /* number of user defined LC_ categories in this locale */
    short    nUserDefCategories;

    /* LC_ categories supported: bitmap */
    unsigned short CategoriesSupported;

    /* LC_TYPE (character type tables) */
    long TypeOffset;

    /* LC_COLLATE (collation table area) */
    long CollationOffset;

    /* LC_TIME (time structure area) */
    long TimeOffset;

    /*    LC_MONETARY (monetary structure area) */
    long MonetaryOffset;

    /* LC_NUMERIC (numeric structure area) */
    long NumericOffset;

    /* LC_MESSAGES (message table area) */
    long MessagesOffset;

    /* LC_userdef (user defined data structures area) */
    long UserDefinitionsOffset;

};


struct LocaleLib {

    struct LocaleLibraryHeader ThisLib;

    struct LocaleLocation Locales;
};

struct LocaleLibraryStatus {

        struct LocaleLibraryHeader LibHdr;

        struct LocaleLocation Location;

        struct CategoryHeader TempCatHdr;

        int  Lhandle;

        const char *plocalename;

        int  localename_len;

        unsigned char LoadDefaultCategory;

    struct LOCALEOBJECT *ptmplocale;
};

struct LOCALEOBJECT {

    struct LocaleHeader LocaleHdr;

    char LocaleString[ ( LC_LAST * MAX_LCNAME_LEN ) ];

    /* LC_CTYPE */

    struct CtypeCategory CtypeCat;

    unsigned char *pCtype;

    unsigned char *pToLower;

    unsigned char *pToUpper;

    /* LC_COLLATE */
    struct CollateCategory CollationCat;

    /* class and collation tables */
    void *pClass;

    /* special collation tables */
    struct Expansion    *pExpandTbl;
    struct Compression  *pCompressTbl;
    struct Substitution *pSubstitutionTbl;

    /* collation function */
    int    _RTLENTRY _EXPFUNC (*pcollate) ( const char *__s1, const char *__s2 );

    /* collation transform function */
    size_t _RTLENTRY _EXPFUNC (*ptransform) ( char *__s1, const char *__s2, size_t __n );

    /* LC_MONETARY */
    struct MonetaryCategory MonetaryCat;

    /* LC_NUMERIC */
    struct NumericCategory NumericCat;

    /* LC_TIME */
    struct TimeCategory TimeCat;

    /* LC_MESSAGES */
    struct MessagesCategory MessagesCat;

    /* LC_userdef */
    struct UserCategory UserCat;

    struct LOCALEOBJECT *pNextLocale;

};

struct path_components {

        char    _drive_[ MAXDRIVE ];
        char    _dir_  [ MAXDIR ];
        char    _name_ [ MAXFILE ];
        char    _ext_  [ MAXEXT ];
};

/* macros */

#define _ISLOCALESTRING( str )                                         \
                                                                       \
           ( ( (str != NULL) && strchr( str, LOCALE_STR_SYM ) != NULL ) ? 1 : 0 )

#define _CHECKVERSION( hdr )                                           \
                                                                       \
    ( ( hdr._Major == LCLIB_MAJOR_VERSION ) && ( hdr._Minor == LCLIB_MINOR_VERSION ) ? LOCALE_NO_ERROR : LOCALE_ERROR )

#define _OSFILEOPEN( filename, flags, fhandle )                        \
                                                                       \
            ( fhandle = open( (const char *) filename, flags ) )

#define _OSFILESEEK( fhandle, offset, mode )                           \
                                                                       \
            lseek( fhandle, offset, mode )

#define _OSFILEREAD( fhandle, buffer, nBytes, nRead )                  \
                                                                       \
            ( nRead = read( fhandle, buffer, nBytes ) )

#define _OSFILECLOSE( fhandle )                                        \
                                                                       \
            close( fhandle );

#define _OSMEMALLOC( nitems, size )                                    \
                                                                       \
            calloc( (size_t) nitems, (size_t) size );

#define _OSMEMFREE( memptr )                                           \
                                                                       \
            free( memptr );


/* internal prototypes */

struct lconv * _RTLENTRY _EXPFUNC _llocaleconv( void );

char * __lsetlocale( int __category, const char *__locale );

char * __set_c_locale( int __category );

int    __find_localecat( struct LocaleLibraryStatus *__LibStatus );

int   __set_localestring_locale( int __category, const char  *__locale );

int   __initialize_locale( void );

int   _RTLENTRY _EXPFUNC __uninitialize_locale( void );

void  __locale_error( struct LocaleLibraryStatus *__LibStatus, void * __MemPtr );

int   __dup_locale( struct LOCALEOBJECT **__pdstlocale, struct LOCALEOBJECT **__psrclocale );

int   __delete_locale( struct LOCALEOBJECT **__pdeletelocale );

int   __open_localelib( struct LocaleLibraryStatus *__LibStatus );

int   __open_locale( struct LocaleLibraryStatus *__LibStatus );

int   __read_localecat( struct LocaleLibraryStatus *LibStatus, int __category );

char *__read_localeenv( int __category );

int   __find_localelib( char *__localelib );

char *_RTLENTRY _EXPFUNC _setlocalelib( char *__fname );

void  _RTLENTRY _EXPFUNC _setlocalebuff( void _FAR *__localebuff );

void  _RTLENTRY _EXPFUNC _setstrxfrm
(
    size_t _RTLENTRY _EXPFUNC (*ptransform) ( char *, const char *, size_t )
);

void  _RTLENTRY _EXPFUNC _setstrcoll
(
    int _RTLENTRY _EXPFUNC (*pcollate) ( const char *, const char * )
);

#if defined( _MT )

void _lock_locale( void );
void _unlock_locale( void );
void _RTLENTRY _init_locale( void );

#else

#define _lock_locale()
#define _unlock_locale()
#define _init_locale()

#endif

/* externals */

extern struct LOCALEOBJECT _Clocale;

#ifdef _Windows
extern  char *_argv0;
#else
extern  char **_Cdecl _argv;
#endif

extern const char *_LocaleCatNames[ LC_LAST + 1 ];

extern struct LOCALEOBJECT *_pLocale;

extern struct lconv _localeconvention;

extern char _LocaleLibName[ MAXPATH + 1 ];

#define __pLocale _pLocale

#else  // #ifndef __FLAT__

#include <windows.h>
#include <winnls.h>
#include <time.h>

#if !defined(__LOCALE_H)
#include <locale.h>
#endif

#define LOCALE_ERROR(code) 0x00000100 + code
#define ERROR_LOCALE_INVALID   (APPLICATION_ERROR_MASK + LOCALE_ERROR(1))
#define ERROR_CATEGORY_INVALID (APPLICATION_ERROR_MASK + LOCALE_ERROR(2))
#define ERROR_LOCALE_NOTINSTALLED (APPLICATION_ERROR_MASK + LOCALE_ERROR(3))
#define ERROR_LOCALE_NOTSUPPORTED (APPLICATION_ERROR_MASK + LOCALE_ERROR(4))
#define ERROR_CATEGORY_NOTOPEN (APPLICATION_ERROR_MASK + LOCALE_ERROR(5))
#define ERROR_MBCS_CODEPAGE_INVALID (APPLICATION_ERROR_MASK + LOCALE_ERROR(6))

#define LC_STRING   0x0001
#define LC_NUMBER   0x0002


typedef struct tagCollate {
  short dummy;
} WIN32COLLATE, *LPWIN32COLLATE;

typedef struct tagCtype {
  unsigned short cType[257];     // array containing types of data (_ALPHA, _NUMERIC, etc...)
} WIN32CTYPE, *LPWIN32CTYPE;

typedef struct tagMonetary {
  short Digits;                 // Number of fractional digits
  short IntlDigits;             // Number of fractional intl digits
  short Mode;                   // Currency mode
  short NegMode;                // Negative currency mode
  short PositiveFormat;         // Positive formatting
  short NegativeFormat;         // Negative formatting
  short PosSymbolPrec;          // Is the Symbol preceds amount
  short PosSymbolSpace;         // Is the positive symbol separeated by space
  short NegSymbolPrec;          // Is the negative Symbol preceds amount
  short NegSymbolSpace;         // Is the negative symbol separeated by space

  LPSTR ThousandSeparator;      // Thousand separator symbol
  LPSTR Decimal;                // Floating point symbol
  LPSTR Symbol;                 // Monetary Symbol
  LPSTR IntlSymbol;             // Monetary Intl Symbol
  LPSTR Grouping;               // Grouping
  LPSTR PositiveSign;           // Positive Sign
  LPSTR NegativeSign;           // Negative Sign
  LPSTR NegativeFormatString;   // Negative format string
} WIN32MONETARY, *LPWIN32MONETARY;

typedef struct tagTime {
  LPSTR DateSeparator;          // Date separator
  LPSTR TimeSeparator;          // Time separator
  LPSTR TimeFormat;             // Time formatting string
  LPSTR ShortFormat;            // Short date formatting sting
  LPSTR LongFormat;             // Long date formatting string
  LPSTR AM;                     // AM designor
  LPSTR PM;                     // PM designor

  short Order;                  // Short date-format ordering
  short LongOrder;              // Long date-format ordering
  short TimeFmt;                // Time format specifier (AM/PM || 24h)
  short Century;                // Century specification (4 digits or 2)
  short TimeLeadZeros;          // Leading zeros in time fields.
  short DayLeadZeros;           // Leading zeros in Day fields
  short MonthLeadZeros;         // Leading zeros in Month fields

  LPSTR DayName1;               // Day name for Mon
  LPSTR DayName2;               // Day name for Tue
  LPSTR DayName3;               // Day name for Wed
  LPSTR DayName4;               // Day name for Thu
  LPSTR DayName5;               // Day name for Fri
  LPSTR DayName6;               // Day name for Sat
  LPSTR DayName7;               // Day name for Sun

  LPSTR AbrvDayName1;           // Abbreviated day name for Mon
  LPSTR AbrvDayName2;           // Abbreviated day name for Tue
  LPSTR AbrvDayName3;           // Abbreviated day name for Wed
  LPSTR AbrvDayName4;           // Abbreviated day name for Thu
  LPSTR AbrvDayName5;           // Abbreviated day name for Fri
  LPSTR AbrvDayName6;           // Abbreviated day name for Sat
  LPSTR AbrvDayName7;           // Abbreviated day name for Sun

  LPSTR MonthName1;             // Month name for Jan
  LPSTR MonthName2;             // Month name for Feb
  LPSTR MonthName3;             // Month name for Mar
  LPSTR MonthName4;             // Month name for Apr
  LPSTR MonthName5;             // Month name for May
  LPSTR MonthName6;             // Month name for Jun
  LPSTR MonthName7;             // Month name for Jul
  LPSTR MonthName8;             // Month name for Aug
  LPSTR MonthName9;             // Month name for Sep
  LPSTR MonthName10;            // Month name for Oct
  LPSTR MonthName11;            // Month name for Nov
  LPSTR MonthName12;            // Month name for Dec

  LPSTR AbrvMonthName1;         // Abbreviated Month name for Jan
  LPSTR AbrvMonthName2;         // Abbreviated Month name for Feb
  LPSTR AbrvMonthName3;         // Abbreviated Month name for Mar
  LPSTR AbrvMonthName4;         // Abbreviated Month name for Apr
  LPSTR AbrvMonthName5;         // Abbreviated Month name for May
  LPSTR AbrvMonthName6;         // Abbreviated Month name for Jun
  LPSTR AbrvMonthName7;         // Abbreviated Month name for Jul
  LPSTR AbrvMonthName8;         // Abbreviated Month name for Aug
  LPSTR AbrvMonthName9;         // Abbreviated Month name for Sep
  LPSTR AbrvMonthName10;        // Abbreviated Month name for Oct
  LPSTR AbrvMonthName11;        // Abbreviated Month name for Nov
  LPSTR AbrvMonthName12;        // Abbreviated Month name for Dec

} WIN32TIME, *LPWIN32TIME;


typedef struct tagNumeric {
  LPSTR ThousandSeparator;      // Thousand separator symbol
  LPSTR Decimal;                // Floating point symbol
  LPSTR Grouping;               // Grouping
  LPSTR PositiveSign;           // Positive Sign
  LPSTR NegativeSign;           // Negative Sign
  short Digits;                 // Number of fractional digits
} WIN32NUMERIC, *LPWIN32NUMERIC;


/* a pointer on this structure is stored in the Tls of each thread
   We can like this retrieve the data at anytime and take advantage
   of multithreading for locale management.
 */

typedef struct tagLocale {

  long            codepage;     // Code page of the locale
  LCID            handle;       // LCID of the locale
  BOOL            isCLocale;    // is that locale "C" locale ?
  int             country;

  LPWIN32CTYPE    ctype;        // CType category of the locale
  LPWIN32MONETARY monetary;     // Monetary category of the locale
  LPWIN32NUMERIC  numeric;      // Numeric category of the locale
  LPWIN32COLLATE  collate;      // Collate category of the locale
  LPWIN32TIME     time;         // Time category of the locale

  LPSTR setLocaleReturn;
  LPWSTR setLocaleReturnW;
} WIN32LOCALE, *LPWIN32LOCALE;

LPWSTR _setLocale32W(SHORT Category, LPCWSTR LocaleName);
LPSTR _setLocale32A(SHORT Category, LPCSTR localeName);

const void* _getLocaleTimeInfo(LCTYPE info);
const void* _getLocaleMonetaryInfo(LCTYPE info);
const void* _getLocaleNumericInfo(LCTYPE info);
char* _win32DateTimeToPOSIX(char* DateTime, char* dest, int size);
const void* _getLocaleMonetaryNegFmt();
int   _getLocaleEra(char* buf, int bufsize, const struct tm *t);

#ifdef __MT__

  void _lockLocale(void);
  void _unlockLocale(void);

  #define _lock_locale()    _lockLocale()
  #define _unlock_locale()  _unlockLocale()

  #define LOCKLOCALE    _lockLocale()
  #define UNLOCKLOCALE  _unlockLocale()

#else

  #define _lock_locale()
  #define _unlock_locale()

  #define LOCKLOCALE
  #define UNLOCKLOCALE

#endif

extern _EXPDATA LPWIN32LOCALE __locale;
extern struct lconv _localeconvention;

#endif // __FLAT__ || !__FLAT__

#pragma pragma pack(pop)

#endif /* ___LOCALE_H */

