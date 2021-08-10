/*
*
*    LSETLOCL.C
*
*    module for ANSI C setlocale() function
*    handles all available locales
*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

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


/*---------------------------------------------------------------------*
*
*     setlocale( int category, const char *locale )
*
*     category: LC_ALL,  LC_COLLATE, LC_CTYPE, LC_MONETARY, LC_NUMERIC,
*               LC_TIME, LC_MESSAGES, LC_userdef
*
*    locale:   locale name
*        e.g. "en_US.DOS437", "fr_CA.DOS850", "jp_JP.SJIS", "en_GB.DOS850@Euro", etc.
*
*    if locale is NULL:
*        returns current locale name for specified category
*    if category is LC_ALL a full locale name pointer is returned that
*        contains the names of each category delimited by semi-colons
*
*
*    if locale is a NULL string (""):
*        looks for locale category in DOS environment in the following
*    POSIX defined sequence:
*    LC_ALL, LC_*, LANG
*
*        e.g. LC_CTYPE=fr_CA.DOS850, LC_ALL=en_US.DOS437
*
*
*    reads requested locale/category from locale library file
*    allocates memory for interchangable locales and categories
*    return pointer to locale or category name depending on request
*
*---------------------------------------------------------------------*/

char * _CType _FARFUNC _lsetlocale( int category, const char *locale )

{
    char *ModifierPtr;
    char *ReturnPtr = NULL;

    int  nCats;
    int  i;

    short Temp16;
    unsigned int nbytes;

    /* temporary pointers */
    char *pClass;
    char *pExpansion;
    char *pCompression;
    char *pSubstitution;
    char *pCurrentTable;

    struct LocaleLibraryStatus LibStatus;

    _QRTLDataBlock;

    memset( (void *) &LibStatus, 0, sizeof( struct LocaleLibraryStatus ) );

    /* is _pLocale still referencing the static "C" locale? */
    if ( _QRTLInstanceData(_pLocale)->LocaleHdr.ObjAllocType == _STATIC )
    {
        /*
           if this call is setlocale( LC_ALL, "C" ) then
           there is no need to allocate memory
        */
        if ( locale != NULL )
        {
            if ( ( strcmp( locale, C_LOCALE_FULL_STR ) == 0 && category == LC_ALL ) ||
                 ( strcmp( locale, C_LOCALE_SHORT_STR ) == 0 && category == LC_ALL ) )

                return( _QRTLInstanceData(_pLocale)->LocaleString );
        }

        /* initialize dynamic locale */
        if ( __initialize_locale() == LOCALE_ERROR )
            return( NULL );
    }

    if ( locale != NULL )

    {
        /* the "C" locale ? */
        if ( ( strcmp( locale, C_LOCALE_FULL_STR ) == 0 ) ||
             ( strcmp( locale, C_LOCALE_SHORT_STR ) == 0 ) )

        {
            if ( _QRTLInstanceData(_pLocale)->LocaleHdr.ObjAllocType == _DYNAMIC )
            {
                /* Delete the existing locale memory before setting it back
                   to _STATIC (free the memory and satisfy CG)
                */
                int _CType _FARFUNC __uninitialize_locale( void );
                __uninitialize_locale();
            }

            return( __set_c_locale( category ) );
        }
    }

    /*
        if locale is a NULL pointer
        return a string pointer to the name of the
        locale category
    */

    if ( locale == NULL )

    {
        switch( category )
        {

        case LC_ALL:
            ReturnPtr = _QRTLInstanceData(_pLocale)->LocaleString;
            break;

        case LC_COLLATE:
            ReturnPtr = _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName;
            break;

        case LC_CTYPE:
            ReturnPtr = _QRTLInstanceData(_pLocale)->CtypeCat.Header.CategoryName;
            break;

        case LC_MONETARY:
            ReturnPtr = _QRTLInstanceData(_pLocale)->MonetaryCat.Header.CategoryName;
            break;

        case LC_NUMERIC:
            ReturnPtr = _QRTLInstanceData(_pLocale)->NumericCat.Header.CategoryName;
            break;

        case LC_TIME:
            ReturnPtr = _QRTLInstanceData(_pLocale)->TimeCat.Header.CategoryName;
            break;

        case LC_MESSAGES:
            ReturnPtr = _QRTLInstanceData(_pLocale)->MessagesCat.Header.CategoryName;
            break;

        case LC_userdef:
            ReturnPtr = _QRTLInstanceData(_pLocale)->UserCat.Header.CategoryName;
            break;

        default:
            ReturnPtr = NULL;
        }

        return( ReturnPtr );
    }

    /*
        if locale is a null string get appropriate environmental locale info.
    */

    if ( *locale == '\0' )
        return( __read_localeenv( category ) );

    /* is locale a full locale string? */
    if ( _ISLOCALESTRING( locale ) )

    {
        /* set each category in locale string */
        if ( __set_localestring_locale( category, locale ) != LOCALE_ERROR )

            /* if successful, recurse to return the category name string */
            return ( _lsetlocale( category, NULL ) );

        else
            return( NULL );
    }

    /*
        find any category modifier part of the locale name:
        e.g. @dBASE in fr_FR.850@dBASE etc.
    */

    if ( ( ModifierPtr = strchr( locale, MODIFIER_SYM ) ) == NULL )

    {
        /* no modifier, so load default for each required category */
        LibStatus.LoadDefaultCategory = 1;

        LibStatus.localename_len = strlen( locale );

    }

    else
    {
        /* there is a modifier, so load required category by name */
        LibStatus.LoadDefaultCategory = 0;

        /* determine length up to modifier portion */
        LibStatus.localename_len = (int) ( (char *) ModifierPtr - (char *) locale );
    }

    LibStatus.plocalename = locale;

    /* open locale library */
    if ( __open_localelib( &LibStatus ) != OSFILE_NO_ERROR )
    {
        return( NULL );
    }

    /* open requested locale */
    if ( __open_locale( &LibStatus ) != OSFILE_NO_ERROR )
    {
        return( NULL );
    }

    /* duplicate the locale in case of a serious error */
    if ( __dup_locale( &LibStatus.ptmplocale, &_QRTLInstanceData(_pLocale) ) == LOCALE_ERROR )
        return( NULL );

    /*
        ensure locale is a single-byte locale.
    */

    if ( ( _QRTLInstanceData(_pLocale)->LocaleHdr.nCharMinBytes != 1 ) ||
         ( _QRTLInstanceData(_pLocale)->LocaleHdr.nCharMaxBytes != 1 ) )
    {
        __delete_locale( &LibStatus.ptmplocale );

        return( NULL );
    }

    i = category;

    /*  assume load a single category */
    nCats = 1;

    /*
        not 'LC_ALL' specifies a single category
        'LC_ALL' specifies all categories
    */

    if ( category == LC_ALL )
    {
        /*
            load all categories: LC_ALL
            except LC_userdef which is optional
        */
        nCats = LC_LAST -1;

        /* increment to first category */
        i++;
    }

    while( nCats-- )
    {

        if ( __read_localecat( &LibStatus, i ) != LOCALE_NO_ERROR )
        {
            __locale_error( &LibStatus, NULL );
            return( NULL );
        }

        switch( i++ )
        {

        case LC_COLLATE:

            /* allocate enough memory for class and all collation tables */
            pClass =
                (char *) _OSMEMALLOC(
                _QRTLInstanceData(_pLocale)->CollationCat.CollateInfo.nTableSize, 1 );

            if ( pClass == NULL )

            {
                /* file handle, mem to dealloc */
                __locale_error( &LibStatus, NULL );
                return( NULL );
            }

            /* read class and all level collation tables */
            if (
                _OSFILEREAD(
                    LibStatus.Lhandle,
                    (void *) pClass,
                    ( SBCS_COLLATECLASS_BSIZE +
                    ( SBCS_COLLATELEVEL_BSIZE *
                    _QRTLInstanceData(_pLocale)->CollationCat.CollateInfo.nLevels ) ),
                    (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

            {
                /* file handle, mem to dealloc */
                __locale_error( &LibStatus, pClass );
                return( NULL );
            }

            /* set next table address location */
            pCurrentTable =
                ( &( pClass
                [
                ( SBCS_COLLATECLASS_BSIZE +
                ( SBCS_COLLATELEVEL_BSIZE *
                _QRTLInstanceData(_pLocale)->CollationCat.CollateInfo.nLevels ) )
                ] ) );

            /* read number of expansion collation elements */
            if (
                _OSFILEREAD(
                    LibStatus.Lhandle,
                    (void *) &Temp16,
                    sizeof( short ),
                    (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

            {
                /* file handle, mem to dealloc */
                __locale_error( &LibStatus, pClass );
                return( NULL );
            }

            /* expansion table to read? */
            if ( Temp16 != 0 )
            {
                pExpansion = pCurrentTable;

                /* read all expansion collation element tables */
                if (
                    _OSFILEREAD(
                        LibStatus.Lhandle,
                        (void *) pExpansion,
                        ( sizeof( struct Expansion ) * Temp16 ),
                        (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

                {
                    /* file handle, mem to dealloc */
                    __locale_error( &LibStatus, pClass );
                    return( NULL );
                }

                /* set next table address location */
                pCurrentTable += nbytes;

            } else {

                pExpansion = NULL;

            }


            /* read number of compression collation elements */
            if (
                _OSFILEREAD(
                    LibStatus.Lhandle,
                    (void *) &Temp16,
                    sizeof( short ),
                    (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

            {
                /* file handle, mem to dealloc */
                __locale_error( &LibStatus, pClass );
                return( NULL );
            }

            /* compression table to read? */
            if ( Temp16 != 0 )
            {

                /* set compression table address */
                pCompression = pCurrentTable;

                /* read all compress collation element tables */
                if (
                    _OSFILEREAD(
                        LibStatus.Lhandle,
                        (void *) pCompression,
                        ( sizeof( struct Compression ) * Temp16 ),
                        (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )
                {
                    /* file handle, mem to dealloc */
                    __locale_error( &LibStatus, pClass );
                    return( NULL );
                }

                /* set next table address location */
                pCurrentTable += nbytes;

            } else {

                pCompression = NULL;

            }

            /* read number of substitution collation elements */
            if (
                _OSFILEREAD(
                    LibStatus.Lhandle,
                    (void *) &Temp16,
                    sizeof( short ),
                    (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

            {
                /* file handle, mem to dealloc */
                __locale_error( &LibStatus, pClass );
                return( NULL );
            }

            /* compression table to read? */
            if ( Temp16 != 0 )

            {

                /* set substitution table address */
                pSubstitution = pCurrentTable;

                /* read all substitution collation element tables */
                if (
                    _OSFILEREAD(
                        LibStatus.Lhandle,
                        (void *) pSubstitution,
                        ( sizeof( struct Substitution ) * Temp16 ),
                        (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

                {
                    /* file handle, mem to dealloc */
                    __locale_error( &LibStatus, pClass );
                    return( NULL );
                }

            } else {

                pSubstitution = NULL;

            }

            /* set collation functions */
           _QRTLInstanceData(_pLocale)->pcollate   = _strcoll;
           _QRTLInstanceData(_pLocale)->ptransform = _strxfrm;

            /* remove previous class and collation tables */
            if ( _QRTLInstanceData(_pLocale)->pClass != NULL )
                _OSMEMFREE( _QRTLInstanceData(_pLocale)->pClass );

            /* set new class and collation tables */
            _QRTLInstanceData(_pLocale)->pClass           = pClass;

            /* set locale pointers */
            _QRTLInstanceData(_pLocale)->pExpandTbl       = (struct Expansion    *) pExpansion;
            _QRTLInstanceData(_pLocale)->pCompressTbl     = (struct Compression  *) pCompression;
            _QRTLInstanceData(_pLocale)->pSubstitutionTbl = (struct Substitution *) pSubstitution;

            ReturnPtr = _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName;

            break;

        case LC_CTYPE:

            /* point to lowercase table */
            _QRTLInstanceData(_pLocale)->pToLower = (unsigned char *)
                ( &( (unsigned char) _QRTLInstanceData(_pLocale)->pCtype [ SBCS_CTYPE_TSIZE ] ) );

            /* point to uppercase table */
            _QRTLInstanceData(_pLocale)->pToUpper = (unsigned char *)
                ( &( (unsigned char) _QRTLInstanceData(_pLocale)->pToLower [ SBCS_LOWER_TSIZE ] ) );

            ReturnPtr = _QRTLInstanceData(_pLocale)->CtypeCat.Header.CategoryName;

            break;

        case LC_MONETARY:

            ReturnPtr = _QRTLInstanceData(_pLocale)->MonetaryCat.Header.CategoryName;

            break;

        case LC_NUMERIC:

            ReturnPtr = _QRTLInstanceData(_pLocale)->NumericCat.Header.CategoryName;

            break;

        case LC_TIME:

            ReturnPtr = _QRTLInstanceData(_pLocale)->TimeCat.Header.CategoryName;

            break;

        case LC_MESSAGES:

            ReturnPtr = _QRTLInstanceData(_pLocale)->MessagesCat.Header.CategoryName;

            break;

        case LC_userdef:

            /* has a memory address been set for this category? */
            if ( _QRTLInstanceData(_pLocale)->UserCat.UserInfo == NULL )
                break;

            ReturnPtr = _QRTLInstanceData(_pLocale)->UserCat.Header.CategoryName;

            break;

        default:

            ReturnPtr = NULL;

            break;

        } /* switch */

    } /* while */

    /* close locale library */
    _OSFILECLOSE( LibStatus.Lhandle );

    /* update the full locale string */
    sprintf(
        _QRTLInstanceData(_pLocale)->LocaleString,
        "%s;%s;%s;%s;%s;%s;%s;",
        _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->CtypeCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->MonetaryCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->NumericCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->TimeCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->MessagesCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->UserCat.Header.CategoryName );

    if ( category == LC_ALL )
        ReturnPtr = _QRTLInstanceData(_pLocale)->LocaleString;

    /* delete duplicate locale */
    if ( LibStatus.ptmplocale != NULL )
        __delete_locale( &LibStatus.ptmplocale );

    /* update localeconvention structure */
    _llocaleconv();

    return( ReturnPtr );
}

/*
    open a locale library
*/

int __open_localelib( struct LocaleLibraryStatus *LibStatus )
{
    unsigned int nbytes;
    _QRTLDataBlock;

    /* find the locale library file */
    if ( __find_localelib( _QRTLInstanceData(_LocaleLibName) ) == OSFILE_ERROR )
        return( OSFILE_ERROR );

    /* open locale library */
    if (
        _OSFILEOPEN(
            _QRTLInstanceData(_LocaleLibName),
            (unsigned int) ( O_BINARY | O_RDONLY ),
            (int *) &LibStatus->Lhandle ) != OSFILE_NO_ERROR )

    {
        /* file handle, mem to dealloc */
        __locale_error( LibStatus, NULL );
        return( OSFILE_ERROR );
    }

    /* read locale library header */
     if (
        _OSFILEREAD(
            LibStatus->Lhandle,
            (void *) &LibStatus->LibHdr,
            sizeof( struct LocaleLibraryHeader ),
            &nbytes ) != OSFILE_NO_ERROR )

    {
        /* file handle, mem to dealloc */
        __locale_error( LibStatus, NULL );
        return( OSFILE_ERROR );
    }

    if ( _CHECKVERSION( LibStatus->LibHdr.LocaleLibraryVersion ) == LOCALE_ERROR )

    {
        /* file handle, mem to dealloc */
        __locale_error( LibStatus, NULL );
        return( OSFILE_ERROR );
    }

    /* library has locales? */
    if ( LibStatus->LibHdr.nLocales == 0 )

    {
        /* file handle, mem to dealloc */
        __locale_error( LibStatus, NULL );
        return( OSFILE_ERROR );
    }

    return( OSFILE_NO_ERROR );

}

/*
    open a locale within the locale library
*/

int __open_locale( struct LocaleLibraryStatus *LibStatus )

{
    unsigned int nbytes;
    int i;
    int match;
    _QRTLDataBlock;

    /* find locale name. e.g. en_US.437 */
    for ( i = 0; i < LibStatus->LibHdr.nLocales; i++ ) {

         if (
           _OSFILEREAD(
              LibStatus->Lhandle,
              (void *) &LibStatus->Location,
              sizeof( struct LocaleLocation ),
              (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

        {
            /* file handle, mem to dealloc */
            __locale_error( LibStatus, NULL );
            return( LOCALE_ERROR );
        }

        /* locale name matches? */
        if ( ( match = strncmp( LibStatus->plocalename, LibStatus->Location.LocaleName, LibStatus->localename_len ) ) == 0 )
            break;
    }

    if ( match != 0 )
    {
        __locale_error( LibStatus, NULL );
        return( LOCALE_ERROR );
    }

    /* seek to the named locale */
    if (
        _OSFILESEEK(
            LibStatus->Lhandle,
            LibStatus->Location.LocaleOffset,
            SEEK_SET ) == OSFILE_ERROR )

    {
        /* file handle, mem to dealloc */
        __locale_error( LibStatus, NULL );
        return( LOCALE_ERROR );
    }

    /* read locale header */
    if (
        _OSFILEREAD(
         LibStatus->Lhandle,
         (void *) &_QRTLInstanceData(_pLocale)->LocaleHdr,
         sizeof( struct LocaleHeader ),
         (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

    {
        /* file handle, mem to dealloc */
        __locale_error( LibStatus, NULL );
        return( LOCALE_ERROR );
    }

    return( LOCALE_NO_ERROR );

}

/*
    find requested category
*/

int __find_localecat( struct LocaleLibraryStatus *LibStatus )

{
    int i;
    short Temp16;
    unsigned int nbytes;

    /* read number of categories */
    if (
        _OSFILEREAD(
            LibStatus->Lhandle,
            (void *) &Temp16,
            sizeof( short ),
            (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

        {
            /* file handle, mem to dealloc */
            __locale_error( LibStatus, NULL );
            return( LOCALE_ERROR );
        }


    for ( i = 0; i < Temp16; i++ ) {

        /* read category header */
         if (
            _OSFILEREAD(
                LibStatus->Lhandle,
                (void *) &LibStatus->TempCatHdr,
                sizeof( struct CategoryHeader ),
                (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

        {
            /* file handle, mem to dealloc */
            __locale_error( LibStatus, NULL );
            return( LOCALE_ERROR );
        }

        /* match category name */

        /* if searching for default (with no modifier name) */

        if ( LibStatus->LoadDefaultCategory )

        {
            if ( !strncmp( LibStatus->plocalename, LibStatus->TempCatHdr.CategoryName, LibStatus->localename_len ) )

                /* is the default? */
                if ( LibStatus->TempCatHdr.DefaultCategory )
                    return( LOCALE_NO_ERROR );

        }

        else

        /* searching for full category name */
        {
            if ( !strcmp( LibStatus->plocalename, LibStatus->TempCatHdr.CategoryName ) )
                return( LOCALE_NO_ERROR );

        }

        /* seek to next category */
        if (
            _OSFILESEEK(
                LibStatus->Lhandle,
                LibStatus->TempCatHdr.CategorySize - sizeof( struct CategoryHeader ),
                SEEK_CUR ) == OSFILE_ERROR )

        {
            /* file handle, mem to dealloc */
            __locale_error( LibStatus, NULL );
            return( LOCALE_ERROR );
        }

    }

    /* category not found */
    return( LOCALE_ERROR );
}

/*
    set the locale from environment strings
*/

int __set_localestring_locale( int __category, const char _FAR *__locale )

{
    char LocaleString[ ( LC_LAST * MAX_LCNAME_LEN ) ];
    char *CatStartPtr = (char *) __locale;
    char *CatEndPtr;
    int  i;

    strcpy( LocaleString, __locale );

    CatStartPtr = (char *) &LocaleString;

    for ( i = LC_COLLATE; i < LC_LAST +1; i++ )
    {

        if ( ( CatEndPtr = strchr( CatStartPtr, LOCALE_STR_SYM ) ) != NULL ) {

            *CatEndPtr = (unsigned char) '\0';

            if ( __category == LC_ALL )

            {
                if ( _lsetlocale( i, CatStartPtr ) == NULL )
                    return( LOCALE_ERROR );
            }
            else
            {
                if ( i == __category )
                    if ( _lsetlocale( i, CatStartPtr ) == NULL )
                        return( LOCALE_ERROR );
            }

            CatStartPtr = ++CatEndPtr;
        }
        else
        {
            return( LOCALE_ERROR );

        } /* if */

    } /* for */

    return( LOCALE_NO_ERROR );
}


/*
    close locale library,
    free memory,
    restore original locale and
*/

void __locale_error( struct LocaleLibraryStatus *LibStatus, void *MemPtr )

{
    struct LOCALEOBJECT *porglocale;
    _QRTLDataBlock;

    /* close this file if open */
    if ( LibStatus->Lhandle != 0 )
        _OSFILECLOSE( LibStatus->Lhandle );

    /* free this memory if allocated */
    if ( MemPtr != NULL )
        _OSMEMFREE( MemPtr );

    /* get current global locale */
    porglocale = _QRTLInstanceData(_pLocale);

    if ( LibStatus->ptmplocale != NULL )
        _QRTLInstanceData(_pLocale) = LibStatus->ptmplocale;

    if ( porglocale )
        __delete_locale( &porglocale );
}

/*
* read category info
*/

int __read_localecat( struct LocaleLibraryStatus *LibStatus, int category )

{

    int   cat_mask;
    long  cat_offset;
    void  *cat_hdr;
    void  *cat_info;
    unsigned int cat_infosize;
    unsigned int nbytes;
    _QRTLDataBlock;

    switch( category )
   {

    case LC_COLLATE:

        cat_mask = __LC_COLLATE;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.CollationOffset;

        cat_info = (void *) &_QRTLInstanceData(_pLocale)->CollationCat.CollateInfo;

        cat_infosize = sizeof( struct Collate );

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->CollationCat.Header;

        break;

    case LC_CTYPE:

        cat_mask = __LC_CTYPE;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.TypeOffset;

        cat_info = (void *) _QRTLInstanceData(_pLocale)->pCtype;

        cat_infosize = SBCS_CTYPE_CATSIZE;

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->CtypeCat.Header;

        break;

    case LC_MONETARY:

        cat_mask = __LC_MONETARY;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.MonetaryOffset;

        cat_info = (void *) &_QRTLInstanceData(_pLocale)->MonetaryCat.MonetaryInfo;

        cat_infosize = sizeof( struct Monetary );

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->MonetaryCat.Header;

        break;

     case LC_NUMERIC:

        cat_mask = __LC_NUMERIC;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.NumericOffset;

        cat_info = (void *) &_QRTLInstanceData(_pLocale)->NumericCat.NumericInfo;

        cat_infosize = sizeof( struct Numeric );

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->NumericCat.Header;

        break;

    case LC_TIME:

        cat_mask = __LC_TIME;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.TimeOffset;

        cat_info = (void *) &_QRTLInstanceData(_pLocale)->TimeCat.TimeDateInfo;

        cat_infosize = sizeof( struct TimeDate );

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->TimeCat.Header;

        break;

    case LC_MESSAGES:

        cat_mask = __LC_MESSAGES;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.MessagesOffset;

        cat_info = (void *) &_QRTLInstanceData(_pLocale)->MessagesCat.MessagesInfo;

        cat_infosize = sizeof( struct Messages );

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->MessagesCat.Header;

        break;

    case LC_userdef:

        cat_mask = __LC_userdef;

        cat_offset = _QRTLInstanceData(_pLocale)->LocaleHdr.UserDefinitionsOffset;

        if ( _QRTLInstanceData(_pLocale)->UserCat.UserInfo == NULL )
            return( LOCALE_ERROR );

        cat_info = (void *) _QRTLInstanceData(_pLocale)->UserCat.UserInfo;

        /* size is unknown at this point */
        cat_infosize = 0;

        cat_hdr = (void *) &_QRTLInstanceData(_pLocale)->UserCat.Header;

        break;

    default:
        return( LOCALE_ERROR );

    }

    if ( ! ( _QRTLInstanceData(_pLocale)->LocaleHdr.CategoriesSupported & cat_mask ) )
        return( LOCALE_ERROR );

    if (
        _OSFILESEEK(
        LibStatus->Lhandle,
        cat_offset,
        SEEK_SET ) == OSFILE_ERROR )

        {
            /* file handle, mem to dealloc */
            __locale_error( LibStatus, NULL );
            return( LOCALE_ERROR );
        }

    if ( __find_localecat( LibStatus ) == LOCALE_NO_ERROR )

    {
        /*
            determine size for LC_userdef data
            now that header has been read
        */
        if ( category == LC_userdef )
            cat_infosize =
                LibStatus->TempCatHdr.CategorySize -
                ( sizeof( struct CategoryHeader )  -
                sizeof( void _FAR * ) );

        /* read category data */
        if (
            _OSFILEREAD(
            LibStatus->Lhandle,
            (void *) cat_info,
            cat_infosize,
            (unsigned int *) &nbytes ) != OSFILE_NO_ERROR )

            {
                /* file handle, mem to dealloc */
                __locale_error( LibStatus, NULL );
                return( LOCALE_ERROR );
            }

        /* copy the temporary header to localeobject */
        memcpy( (void *) cat_hdr, (void *) &LibStatus->TempCatHdr, sizeof( struct CategoryHeader ) );

    }
    else
    {

        return( LOCALE_ERROR );

    }

    return( LOCALE_NO_ERROR );

}

/*
*    read the environment settings for locale category and
*    call setlocale().
*/

char * __read_localeenv( int category )

{
    char *envptr;

    if ( ( envptr = getenv( _LocaleCatNames[ LC_ALL ] ) ) != NULL )
        return( _lsetlocale( category, envptr ) );

    if ( ( category >= LC_COLLATE ) && ( category <= LC_LAST ) )

        if ( ( envptr = getenv( _LocaleCatNames[ category ] ) ) != NULL )

            return( _lsetlocale( category, envptr ) );

    if ( ( envptr = getenv( LANGVAR ) ) != NULL )
        return( _lsetlocale( category, envptr ) );

    return( __set_c_locale( category ) );
}

/*---------------------------------------------------------------------*
*
* __find_localelib()
*
* search for specified 'localelib' filename in following sequence:
*
* 1: default directory if 'localelib' is simple file name
*    or if 'localelib' specifies a full pathname.
*
* 2: directory where application executed from.
*
* 3: search down DOS PATH environment variable.
*
*---------------------------------------------------------------------*/

int __find_localelib( char *localelib )

{
    struct path_components pathspec1;
    struct path_components pathspec2;
    char *pName;
    char tmp_pathname[ MAXPATH + 1 ];
    struct ffblk fileblock;
    _QRTLDataBlock;

    /* look in specified directory for the locale library */
    if (findfirst( (const char _FAR *) localelib, &fileblock, 0 ) == 0 )
    {
        strcpy ( _QRTLInstanceData(_LocaleLibName), localelib );
        return( OSFILE_NO_ERROR );
    }

    /*
    *    search the locale library file in applications directory
    */

#ifdef _Windows

    /* split program name to get its directory */
    fnsplit( _argv0,
        pathspec1._drive_,
        pathspec1._dir_,
        pathspec1._name_,
        pathspec1._ext_ );
#else

    /* split program name to get its directory */
    fnsplit( _argv[ 0 ],
        pathspec1._drive_,
        pathspec1._dir_,
        pathspec1._name_,
        pathspec1._ext_ );

#endif

    /* split current locale library name to get its directory */
    fnsplit( localelib,
        pathspec2._drive_,
        pathspec2._dir_,
        pathspec2._name_,
        pathspec2._ext_ );

    /* compose locale library pathname */
    fnmerge( tmp_pathname,
        pathspec1._drive_,
        pathspec1._dir_,
        pathspec2._name_,
        pathspec2._ext_ );

    /* is file there? */
    if ( findfirst( tmp_pathname, &fileblock, 0 ) == 0 )
    {
        strcpy ( _QRTLInstanceData(_LocaleLibName), tmp_pathname );
        return( OSFILE_NO_ERROR );
    }

    /* find the locale library file by DOS PATH */
    if ( ( pName = searchpath( localelib ) ) != NULL )
    {
        strcpy ( _QRTLInstanceData(_LocaleLibName), pName );
        return( OSFILE_NO_ERROR );
    }

    /* cannot find the specified locale library */
    return( OSFILE_ERROR );
}


/*
    delete a LOCALEOBJECT
*/

int __delete_locale( struct LOCALEOBJECT **pdeletelocale )

{
    /* statically allocated locale? */
    if ( (*pdeletelocale)->LocaleHdr.ObjAllocType == _STATIC )
        return( 1 );

    if ( (*pdeletelocale)->pClass )
        _OSMEMFREE( (*pdeletelocale)->pClass );

    if ( (*pdeletelocale)->pCtype )
        _OSMEMFREE( (*pdeletelocale)->pCtype );

    if ( (*pdeletelocale) )
        _OSMEMFREE( *pdeletelocale );

    *pdeletelocale = NULL;

    return( 1 );

}

/*
    duplicate a LOCALEOBJECT
*/

int __dup_locale( struct LOCALEOBJECT **pdstlocale, struct LOCALEOBJECT **psrclocale )
{

    *pdstlocale = (struct LOCALEOBJECT *)
        _OSMEMALLOC( sizeof( struct LOCALEOBJECT ), 1 );

    /* allocation failed? */
    if ( *pdstlocale == NULL )
        return( LOCALE_ERROR );

    memcpy
    (
        *pdstlocale,
        *psrclocale,
        sizeof( struct LOCALEOBJECT )
    );

    /* set this now so it can be deallocated */
    (*pdstlocale)->LocaleHdr.ObjAllocType = _DYNAMIC;

    /*
        if there are no collation tables ( 'C' locale )
        don't allocate memory
    */

    if ( (*psrclocale)->CollationCat.CollateInfo.nTableSize > 0 )
    {

        (*pdstlocale)->pClass =
                _OSMEMALLOC(
                    (*psrclocale)->CollationCat.CollateInfo.nTableSize, 1 );

        if ( (*pdstlocale)->pClass == NULL )
        {
            /* deallocate memory */
            __delete_locale( pdstlocale );

            return( LOCALE_ERROR );
        }

        memcpy(
            (*pdstlocale)->pClass,
            (*psrclocale)->pClass,
            (*psrclocale)->CollationCat.CollateInfo.nTableSize );

        if ( (*psrclocale)->pExpandTbl != NULL )
            (*pdstlocale)->pExpandTbl = (struct Expansion*)
                &( (*pdstlocale)->pClass ) +
                (unsigned)(((*psrclocale)->pExpandTbl - (*psrclocale)->pClass));

        if ( (*psrclocale)->pCompressTbl != NULL )
            (*pdstlocale)->pCompressTbl = (struct Compression *)
                &( (*pdstlocale)->pCompressTbl ) +
                (unsigned)(((*psrclocale)->pCompressTbl - (*psrclocale)->pClass));

        if ( (*psrclocale)->pSubstitutionTbl != NULL )
            (*pdstlocale)->pSubstitutionTbl = (struct Substitution *)
                &( (*pdstlocale)->pSubstitutionTbl ) +
                (unsigned)(((*psrclocale)->pSubstitutionTbl - (*psrclocale)->pClass));

    }
    else
	(*pdstlocale)->pClass = NULL;

     /* allocate ctype and case conversion tables space */
    (*pdstlocale)->pCtype =
        _OSMEMALLOC( SBCS_CTYPE_CATSIZE, 1 );

    /* allocation failed? */
    if ( (*pdstlocale)->pCtype == NULL )

    {
        /* deallocate memory */
        __delete_locale( pdstlocale );

        return( LOCALE_ERROR );
    }

    /* copy ctype, upper and lower tables */
    memcpy( (*pdstlocale)->pCtype, (*psrclocale)->pCtype, SBCS_CTYPE_CATSIZE );

    /* set tolower table address */
    (*pdstlocale)->pToLower = (unsigned char *)
        ( &( (unsigned char) (unsigned int) (*pdstlocale)->pCtype [ SBCS_CTYPE_TSIZE ] ) );

    /* set toupper table address */
    (*pdstlocale)->pToUpper = (unsigned char *)
        ( &( (unsigned char) (*pdstlocale)->pToLower [ SBCS_LOWER_TSIZE ] ) );

    return( LOCALE_NO_ERROR );
}

