/*-----------------------------------------------------------------------*
 * filename - locale.c
 *
 * function(s)
 *        setlocale  - set the locale specific info
 *        localeconv - gets the locale specific info
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */


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
#include <_ctype.h>
#include <_locale.h>

extern unsigned char _Cdecl _lower[ 256 ];
extern unsigned char _Cdecl _upper[ 256 ];

/*
*    allocate and initialize a locale object 
*    FUNCTION ASSUMES LOCALE IS LOCKED VIA _lsetlocale()
*/

int __initialize_locale( void )

{
    /*
        if locale object has already been allocated dynamically
        then it's already initialized
    */

      if ( _pLocale->LocaleHdr.ObjAllocType == _DYNAMIC )
        return( LOCALE_NO_ERROR );
    
    // initialize locale pointer
    _pLocale = ( struct LOCALEOBJECT * )
        _OSMEMALLOC( sizeof( struct LOCALEOBJECT ), 1 );

    /* allocation failed? */
    if ( _pLocale == NULL )
    {
        /* restore "C" locale */
        _pLocale = &_Clocale;

        return( LOCALE_ERROR );
    }

    /* set this now so it can be deallocated */
      _pLocale->LocaleHdr.ObjAllocType = _DYNAMIC;

    // allocate ctype and case conversion tables space
    _pLocale->pCtype =
        _OSMEMALLOC( SBCS_CTYPE_CATSIZE, 1 );

    /* allocation failed? */
    if ( _pLocale->pCtype == NULL )

    {
        /* deallocate memory */
        __uninitialize_locale();

        return( LOCALE_ERROR );
    }

    /* set tolower table address */
    _pLocale->pToLower = (unsigned char *)
        ( &( (unsigned char) (unsigned int) _pLocale->pCtype [ SBCS_CTYPE_TSIZE ] ) );

    /* set toupper table address */
    _pLocale->pToUpper = (unsigned char *)
        ( &( (unsigned char) _pLocale->pToLower [ SBCS_LOWER_TSIZE ] ) );

    /* start with the "C" locale */
    __set_c_locale( LC_ALL );

    return( LOCALE_NO_ERROR );

}

/*
*  uninitialize locale
*  free any memory allocated used for locales/
*/

#pragma exit __uninitialize_locale 20

int _RTLENTRY _EXPFUNC __uninitialize_locale( void )

{
    /* statically allocated locale? */
    if ( _pLocale->LocaleHdr.ObjAllocType == _STATIC )
        return( 1 );

    _lock_locale();

    if ( _pLocale->pClass )
        _OSMEMFREE( _pLocale->pClass );

    if ( _pLocale->pCtype ) 
        _OSMEMFREE( _pLocale->pCtype );

    if ( _pLocale )
        _OSMEMFREE( _pLocale );
 
    /* restore "C" locale */
    _pLocale = &_Clocale;

    _unlock_locale();

    return( 1 );

}

/*
*    setup the 'C' locale
*    FUNCTION ASSUMES LOCALE IS LOCKED VIA _lsetlocale()
*/

char * _RTLENTRY __set_c_locale( int category )

{
    int i;
    int nCats;
    char *ReturnPtr = NULL;

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
                (char *) &_pLocale->CollationCat,
                (char *) &_Clocale.CollationCat,
                sizeof( struct CollateCategory ) );

            /* set collation functions */
           _pLocale->pcollate   = strcmp;
           _pLocale->ptransform = strxfrm;

            ReturnPtr = (char *) _pLocale->CollationCat.Header.CategoryName;

            break;

        case LC_CTYPE:

            memcpy(
                (char *) &_pLocale->CtypeCat,
                (char *) &_Clocale.CtypeCat,
                sizeof( struct CtypeCategory ) );

            memcpy( _pLocale->pCtype,   &_ctype, SBCS_CTYPE_BSIZE );
            memcpy( _pLocale->pToLower, &_lower, SBCS_LOWER_BSIZE );
            memcpy( _pLocale->pToUpper, &_upper, SBCS_UPPER_BSIZE );

            ReturnPtr = (char *) _pLocale->CtypeCat.Header.CategoryName;

            break;


        case LC_MONETARY:

            memcpy(
                (char *) &_pLocale->MonetaryCat,
                (char *) &_Clocale.MonetaryCat,
                sizeof( struct MonetaryCategory ) );

            ReturnPtr = (char *) _pLocale->MonetaryCat.Header.CategoryName;
    
            break;

        case LC_NUMERIC:
            memcpy(
                (char *) &_pLocale->NumericCat,
                (char *) &_Clocale.NumericCat,
                sizeof( struct NumericCategory ) );

            ReturnPtr = (char *) _pLocale->NumericCat.Header.CategoryName;

            break;

        case LC_TIME:

            memcpy(
                (char *) &_pLocale->TimeCat,
                (char *) &_Clocale.TimeCat,
                sizeof( struct TimeCategory ) );

            ReturnPtr = (char *) _pLocale->TimeCat.Header.CategoryName;

            break;

        case LC_MESSAGES:
            memcpy(
                (char *) &_pLocale->MessagesCat,
                (char *) &_Clocale.MessagesCat,
                sizeof( struct MessagesCategory ) );

            ReturnPtr = (char *) _pLocale->MessagesCat.Header.CategoryName;

            break;

        case LC_userdef:
            memcpy(
                (char *) &_pLocale->UserCat,
                (char *) &_Clocale.UserCat,
                sizeof( struct UserCategory ) );

            ReturnPtr = (char *) _pLocale->UserCat.Header.CategoryName;

            break;

        default:

            ReturnPtr = NULL;

            break;

        } /* switch */

    } /* while */

    /* update the full locale string */
    sprintf(
        (char *) _pLocale->LocaleString,
        "%s;%s;%s;%s;%s;%s;%s;",
        _pLocale->CollationCat.Header.CategoryName,
        _pLocale->CtypeCat.Header.CategoryName,
        _pLocale->MonetaryCat.Header.CategoryName,
        _pLocale->NumericCat.Header.CategoryName,
        _pLocale->TimeCat.Header.CategoryName,
        _pLocale->MessagesCat.Header.CategoryName,
        _pLocale->UserCat.Header.CategoryName );
 
    /* update localeconvention structure */
    localeconv();

    if ( category == LC_ALL )
        return( _pLocale->LocaleString );

    return( ReturnPtr );
}
