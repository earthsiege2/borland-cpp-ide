/*
*
*    LOCALE.C
*
*    initialize and uninitialize locale objects
*
*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if defined( _RTLDLL )
#pragma option -zC_TEXTA
#endif

#ifdef _Windows
#include <windows.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <io.h>
#include <string.h>
#include <fcntl.h>
#include <dos.h>      
#include <math.h>
#include <sys/stat.h>
#include <limits.h>
#include <rtldata.h>
#include <_ctype.h>
#include <_locale.h>

extern unsigned char _Cdecl _lower[ 256 ];
extern unsigned char _Cdecl _upper[ 256 ];

/*
*    allocate and initialize a locale object 
*/

int __initialize_locale( void )

{
    _QRTLDataBlock;

    /*
        if locale object has already been allocated dynamically
        then it's already initialized
    */

      if ( _QRTLInstanceData(_pLocale)->LocaleHdr.ObjAllocType == _DYNAMIC )
        return( LOCALE_NO_ERROR );
    
    // initialize locale pointer
    _QRTLInstanceData(_pLocale) = ( struct LOCALEOBJECT _FAR * )
        _OSMEMALLOC( sizeof( struct LOCALEOBJECT ), 1 );

    /* allocation failed? */
    if ( _QRTLInstanceData(_pLocale) == NULL )
    {
        /* restore "C" locale */
        _QRTLInstanceData(_pLocale) = &_Clocale;
        return( LOCALE_ERROR );
    }

    /* set this now so it can be deallocated */
      _QRTLInstanceData(_pLocale)->LocaleHdr.ObjAllocType = _DYNAMIC;

    // allocate ctype and case conversion tables space
    _QRTLInstanceData(_pLocale)->pCtype =
        _OSMEMALLOC( SBCS_CTYPE_CATSIZE, 1 );

    /* allocation failed? */
    if ( _QRTLInstanceData(_pLocale)->pCtype == NULL )

    {
        /* deallocate memory */
        __uninitialize_locale();

        return( LOCALE_ERROR );
    }

    /* set tolower table address */
    _QRTLInstanceData(_pLocale)->pToLower = (unsigned char *)
        ( &( (unsigned char) (unsigned int) _QRTLInstanceData(_pLocale)->pCtype [ SBCS_CTYPE_TSIZE ] ) );

    /* set toupper table address */
    _QRTLInstanceData(_pLocale)->pToUpper = (unsigned char *)
        ( &( (unsigned char) _QRTLInstanceData(_pLocale)->pToLower [ SBCS_LOWER_TSIZE ] ) );

    /* start with the "C" locale */
    __set_c_locale( LC_ALL );

    return( LOCALE_NO_ERROR );

}

/*
*  uninitialize locale
*  free any memory allocated used for locales/
*/

#pragma exit __uninitialize_locale 20

int _CType _FARFUNC __uninitialize_locale( void )

{
    _QRTLDataBlock;

    /* statically allocated locale? */
    if ( _QRTLInstanceData(_pLocale)->LocaleHdr.ObjAllocType == _STATIC )
        return( 1 );

    if ( _QRTLInstanceData(_pLocale)->pClass )
        _OSMEMFREE( _QRTLInstanceData(_pLocale)->pClass );

    if ( _QRTLInstanceData(_pLocale)->pCtype ) 
        _OSMEMFREE( _QRTLInstanceData(_pLocale)->pCtype );

    if ( _QRTLInstanceData(_pLocale) )
        _OSMEMFREE( _QRTLInstanceData(_pLocale) );
 
    /* restore "C" locale */
    _QRTLInstanceData(_pLocale) = &_Clocale;

    return( 1 );

}

char * __set_c_locale( int category )

{
    int i;
    int nCats;
    char *ReturnPtr = NULL;
    _QRTLDataBlock;

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

        switch( i++ )
        {

        case LC_COLLATE:
    
            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->CollationCat,
                (char *) &_Clocale.CollationCat,
                sizeof( struct CollateCategory ) );

            /* set collation functions */
            _QRTLInstanceData(_pLocale)->pcollate   = strcmp;
            _QRTLInstanceData(_pLocale)->ptransform = strxfrm;

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName;

            break;

        case LC_CTYPE:

            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->CtypeCat,
                (char *) &_Clocale.CtypeCat,
                sizeof( struct CtypeCategory ) );

            memcpy( _QRTLInstanceData(_pLocale)->pCtype,   &_ctype, SBCS_CTYPE_BSIZE );
            memcpy( _QRTLInstanceData(_pLocale)->pToLower, &_lower, SBCS_LOWER_BSIZE );
            memcpy( _QRTLInstanceData(_pLocale)->pToUpper, &_upper, SBCS_UPPER_BSIZE );

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->CtypeCat.Header.CategoryName;

            break;


        case LC_MONETARY:

            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->MonetaryCat,
                (char *) &_Clocale.MonetaryCat,
                sizeof( struct MonetaryCategory ) );

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->MonetaryCat.Header.CategoryName;
    
            break;

        case LC_NUMERIC:
            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->NumericCat,
                (char *) &_Clocale.NumericCat,
                sizeof( struct NumericCategory ) );

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->NumericCat.Header.CategoryName;

            break;

        case LC_TIME:

            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->TimeCat,
                (char *) &_Clocale.TimeCat,
                sizeof( struct TimeCategory ) );

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->TimeCat.Header.CategoryName;

            break;

        case LC_MESSAGES:
            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->MessagesCat,
                (char *) &_Clocale.MessagesCat,
                sizeof( struct MessagesCategory ) );

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->MessagesCat.Header.CategoryName;

            break;

        case LC_userdef:
            memcpy(
                (char *) &_QRTLInstanceData(_pLocale)->UserCat,
                (char *) &_Clocale.UserCat,
                sizeof( struct UserCategory ) );

            ReturnPtr = (char *) _QRTLInstanceData(_pLocale)->UserCat.Header.CategoryName;

            break;

        default:

            ReturnPtr = NULL;

            break;

        } /* switch */

    } /* while */

    /* update the full locale string */
    sprintf(
        (char *) _QRTLInstanceData(_pLocale)->LocaleString,
        "%s;%s;%s;%s;%s;%s;%s;",
        _QRTLInstanceData(_pLocale)->CollationCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->CtypeCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->MonetaryCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->NumericCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->TimeCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->MessagesCat.Header.CategoryName,
        _QRTLInstanceData(_pLocale)->UserCat.Header.CategoryName );
 
    /* update localeconvention structure */
    localeconv();

    if ( category == LC_ALL )
        return( _QRTLInstanceData(_pLocale)->LocaleString );

    return( ReturnPtr );
}
