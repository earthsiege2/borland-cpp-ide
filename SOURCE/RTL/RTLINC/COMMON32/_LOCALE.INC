;[]-----------------------------------------------------------------[]
;|      _LOCALE.INC  --  Locale Rules & Structures for assembler     |
;[]-----------------------------------------------------------------[]

;
;       C/C++ Run Time Library - Version 1.5
; 
;       Copyright (c) 1992, 1994 by Borland International
;       All Rights Reserved.
; 

_CPTR_ALLOC   equ <DD FAR PTR ?>

_DPTR_ALLOC   equ <DD FAR PTR ?>


_Cdecl              EQU     <cdecl>
_CType              EQU     <_Cdecl>

NULL                EQU     0

size_t              TYPEDEF WORD 
wchar_t             TYPEDEF WORD 

LC_ALL              EQU     0
LC_COLLATE          EQU     1
LC_CTYPE            EQU     2
LC_MONETARY         EQU     3
LC_NUMERIC          EQU     4
LC_TIME             EQU     5
LC_MESSAGES         EQU     6
LC_userdef          EQU     7
LC_LAST             EQU     <LC_userdef>


LCLIB_MAJOR_VERSION EQU     1
LCLIB_MINOR_VERSION EQU     0
LCLIB_REVISION      EQU     1

LOCALE_NO_ERROR     EQU     0
LOCALE_ERROR        EQU     <-1>

OSFILE_NO_ERROR     EQU     0
OSFILE_ERROR        EQU     <-1>

MAX_COMPRESS_ELEMENT_SIZE               EQU     10
MAX_EXPANSION_ELEMENT_SIZE              EQU     10
MAX_STRING_ELEMENT_SIZE                 EQU     10
MAX_SUBSTITUTION_ELEMENT_SIZE           EQU     10

MAX_LEVELS          EQU     8

MAX_LOCALE_NAME     EQU     25

MAX_DAYS            EQU     7
MAX_MONS            EQU     12
MAX_AMPM            EQU     2
MAX_ALT_DIGITS      EQU     100
MAX_ABDAY_LEN       EQU     10
MAX_ABMON_LEN       EQU     10
MAX_DAY_LEN         EQU     20
MAX_MON_LEN         EQU     20
MAX_AMPM_LEN        EQU     10
MAX_DTFMT_LEN       EQU     25
MAX_ALT_DIGIT_LEN   EQU     10

_AM                 EQU     0
_PM                 EQU     1

FORWARD_RULE        EQU     001h
BACKWARD_RULE       EQU     002h
SUBSTITUTE_RULE     EQU     004h
NO_SUBSTITUTE_RULE  EQU     008h
POSITION_RULE       EQU     010h
NO_POSITION_RULE    EQU     020h

MAX_LCNAME_LEN      EQU     32
MAX_CATNAME_LEN     EQU     32
MAX_CSNAME_LEN      EQU     16
MAX_EXPAND_CHARS    EQU     16
MAX_COMPRESS_CHARS  EQU     16
MAX_SUBSTITUTE_STRS EQU     16

SBCS_SIZE           EQU     256

_TOUPPER_           EQU     <SBCS_SIZE>

_TOLOWER_           EQU     <SBCS_SIZE>

_SBCS_              EQU     00101h

_MBCS_12_           EQU     00102h

_DBCS_              EQU     00202h

_MBCS_STATE_        EQU     0

SBCS_COLLATECLASS_TSIZE                 EQU     <( SBCS_SIZE + 1 )>

SBCS_COLLATELEVEL_TSIZE                 EQU     <( SBCS_SIZE + 1 )>

SBCS_COLLATECLASS_BSIZE                 EQU     <( SBCS_COLLATECLASS_TSIZE * sizeof( unsigned char ) )>

SBCS_COLLATELEVEL_BSIZE                 EQU     <( SBCS_COLLATELEVEL_TSIZE * sizeof( unsigned char ) )>

SBCS_CTYPE_TSIZE    EQU     <( SBCS_SIZE + 1 )>

SBCS_LOWER_TSIZE    EQU     <( SBCS_SIZE )>

SBCS_UPPER_TSIZE    EQU     <( SBCS_SIZE )>

SBCS_CTYPE_BSIZE    EQU     <( SBCS_CTYPE_TSIZE * sizeof( unsigned char ) )>

SBCS_LOWER_BSIZE    EQU     <( SBCS_LOWER_TSIZE * sizeof( unsigned char ) )>

SBCS_UPPER_BSIZE    EQU     <( SBCS_UPPER_TSIZE * sizeof( unsigned char ) )>

SBCS_CTYPE_CATSIZE  EQU     <( SBCS_CTYPE_BSIZE + SBCS_LOWER_BSIZE + SBCS_UPPER_BSIZE )>

LC_RESERVED1        EQU     8
LC_RESERVED2        EQU     9
LC_RESERVED3        EQU     10
LC_RESERVED4        EQU     11
LC_RESERVED5        EQU     12
LC_RESERVED6        EQU     13

__LC_COLLATE        EQU     00001h
__LC_CTYPE          EQU     00002h
__LC_MONETARY       EQU     00004h
__LC_NUMERIC        EQU     00008h
__LC_TIME           EQU     00010h
__LC_MESSAGES       EQU     00020h
__LC_userdef        EQU     00040h

__LC_RESERVED1      EQU     00080h
__LC_RESERVED2      EQU     00100h
__LC_RESERVED3      EQU     00200h
__LC_RESERVED4      EQU     00400h
__LC_RESERVED5      EQU     00800h
__LC_RESERVED6      EQU     01000h

_STATIC             EQU     0
_DYNAMIC            EQU     00001h

SEGLOC              EQU     002h

LENGTH_DIFFERENCE   EQU     007f7fh

CODESET_SIZE        EQU     <SBCS_SIZE>

INSTRING1           EQU     0
INSTRING2           EQU     001h
INSUBSTITUTION      EQU     002h
INEXPANSION         EQU     004h
STRING_ENDED        EQU     080h

CLASS_NORMAL        EQU     001h
CLASS_SUBSTITUTE    EQU     002h
CLASS_EXPAND        EQU     004h
CLASS_COMPRESS      EQU     008h
CLASS_POSITION      EQU     010h

IGNORE_WEIGHT       EQU     0

POSITION_PREFIX     EQU     001h

Collate             STRUC   
CollationID         DW      ?
nLevels             DW      ?
LevelRules          DB      8 DUP ( ? )
nTableSize          DW      ?

Collate             ENDS

Compression         STRUC   
ElementLength       DB      ?
CmpCollationElement DB      10 DUP ( ? )
LevelWeight         DB      8 DUP ( ? )

Compression         ENDS

Expansion           STRUC   

ExpCollationElement DB      ?
ExpansionLength     DB      ?
LevelWeight1        DB      80 DUP ( ? )

Expansion           ENDS

Substitution        STRUC   
StringLength        DB      ?
StringElement       DB      10 DUP ( ? )
SubstitutionLength  DB      ?
SubstitutionElement DB      10 DUP ( ? )

Substitution        ENDS

TimeDate            STRUC   
abday               DB      70 DUP ( ? )
day                 DB      140 DUP ( ? )
abmon               DB      120 DUP ( ? )
mon                 DB      240 DUP ( ? )
am_pm               DB      20 DUP ( ? )
d_t_fmt             DB      25 DUP ( ? )
d_fmt               DB      25 DUP ( ? )
t_fmt               DB      25 DUP ( ? )
t_fmt_ampm          DB      25 DUP ( ? )
era                 DB      25 DUP ( ? )
era_year            DB      25 DUP ( ? )
era_d_fmt           DB      25 DUP ( ? )
alt_digits          DB      1000 DUP ( ? )

TimeDate            ENDS

Numeric             STRUC   
decimal_point       DB      2 DUP ( ? )
thousands_sep       DB      10 DUP ( ? )
grouping            DB      20 DUP ( ? )

Numeric             ENDS

Monetary            STRUC   
int_curr_symbol     DB      5 DUP ( ? )
currency_symbol     DB      5 DUP ( ? )
mon_decimal_point   DB      2 DUP ( ? )
mon_thousands_sep   DB      5 DUP ( ? )
mon_grouping        DB      5 DUP ( ? )
positive_sign       DB      5 DUP ( ? )
negative_sign       DB      5 DUP ( ? )
int_frac_digits     DB      ?
frac_digits         DB      ?
p_cs_precedes       DB      ?
p_sep_by_space      DB      ?
n_cs_precedes       DB      ?
n_sep_by_space      DB      ?
p_sign_posn         DB      ?
n_sign_posn         DB      ?

Monetary            ENDS

Messages            STRUC   
yesexpr             DB      5 DUP ( ? )
noexpr              DB      5 DUP ( ? )

Messages            ENDS

CategoryHeader      STRUC   
CategorySize        DW      ?
CategoryName        DB      32 DUP ( ? )
DefaultCategory     DW      ?

CategoryHeader      ENDS

TimeCategory        STRUC   
Header              CategoryHeader      <>
TimeDateInfo        TimeDate<>

TimeCategory        ENDS

NumericCategory     STRUC   
Header              CategoryHeader      <>
NumericInfo         Numeric <>

NumericCategory     ENDS

MonetaryCategory    STRUC   
Header              CategoryHeader      <>
MonetaryInfo        Monetary<>

MonetaryCategory    ENDS

MessagesCategory    STRUC   
Header              CategoryHeader      <>
MessagesInfo        Messages<>

MessagesCategory    ENDS

CollateCategory     STRUC   
Header              CategoryHeader      <>
CollateInfo         Collate <>

CollateCategory     ENDS

CtypeCategory       STRUC   
Header              CategoryHeader      <>

CtypeCategory       ENDS

UserCategory        STRUC   
Header              CategoryHeader      <>
UserInfo            _DPTR_ALLOC

UserCategory        ENDS

LocaleVersion       STRUC   
_Name               DB      32 DUP ( ? )
_Major              DB      ?
_Minor              DB      ?
_Revision           DB      ?
_Reserved           DB      ?

LocaleVersion       ENDS

LocaleLocation      STRUC   
LocaleName          DB      32 DUP ( ? )
ID                  DW      ?
LocaleOffset        DD      ?

LocaleLocation      ENDS

LocaleLibraryHeader STRUC   
LocaleLibraryVersion          LocaleVersion     <>
nLocales            DW      ?

LocaleLibraryHeader ENDS

LocaleHeader        STRUC   

ThisVersion         LocaleVersion     <>
ObjAllocType        DW      ?
LocaleID            DW      ?
LanguageID          DW      ?
nCharMinBytes       DB      ?
nCharMaxBytes       DB      ?
nCategories         DW      ?
nUserDefCategories  DW      ?
CategoriesSupported DW      ?
TypeOffset          DD      ?
CollationOffset     DD      ?
TimeOffset          DD      ?
MonetaryOffset      DD      ?
NumericOffset       DD      ?
MessagesOffset      DD      ?
UserDefinitionsOffset                   DD      ?

LocaleHeader        ENDS

LocaleLib           STRUC   

ThisLib             LocaleLibraryHeader <>
Locales             LocaleLocation      <>

LocaleLib           ENDS

LocaleLibraryStatus STRUC   

LibHdr              LocaleLibraryHeader <>
Location            LocaleLocation      <>
TempCatHdr          CategoryHeader      <>
Lhandle             DD      ?
plocalename         _DPTR_ALLOC
localename_len      DD      ?
LoadDefaultCategory DB      ?
ptmplocale          _DPTR_ALLOC
LocaleLibraryStatus ENDS


LOCALEOBJECT        STRUC   

LocaleHdr           LocaleHeader      <>
LocaleString        DB ( LC_LAST * MAX_LCNAME_LEN ) DUP ( ? )
CtypeCat            CtypeCategory     <>
pCtype              _DPTR_ALLOC
pToLower            _DPTR_ALLOC
pToUpper            _DPTR_ALLOC
CollationCat        CollateCategory   <>
pClass              _DPTR_ALLOC
pExpandTbl          _DPTR_ALLOC
pCompressTbl        _DPTR_ALLOC
pSubstitutionTbl    _DPTR_ALLOC
pcollate            _CPTR_ALLOC
ptransform          _CPTR_ALLOC
MonetaryCat         MonetaryCategory  <>
NumericCat          NumericCategory   <>
TimeCat             TimeCategory      <>
MessagesCat         MessagesCategory  <>
UserCat             UserCategory      <>
pNextLocale         _DPTR_ALLOC

LOCALEOBJECT        ENDS
