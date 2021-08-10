/*-----------------------------------------------------------------------*
 * filename - locales.c
 *
 * function(s)
 *        _lock_locale     - lock 
 *        _block_locale    - unlock
 *        _init_locale     - initialize
 *----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

//#include <ntbc.h>

#include <_io.h>
#include <_thread.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <_locale.h>

#ifdef _MT

static lock_t locale_lock;


/*---------------------------------------------------------------------*

Name            _lock_locale - lock global locale

Usage           void _lock_locale( void );

Prototype in    _locale.h

Related
functions usage void _unlock_locale();

Description     This function locks the global locale to prevent other
                threads from using that locale.
                A matching _unlock_locale call must be made to
                unlock the locale.  Nested locks can be be performed
                on a the locale, as long as they are matched
                by an equal number of unlock operations.

Return value    None.

*---------------------------------------------------------------------*/

void _lock_locale( void )
{
	_lock( locale_lock, "locking global locale" );
}

/*---------------------------------------------------------------------*

Name            _unlock_locale - lock a file handle

Usage           void _unlock_locale( void );

Prototype in    _locale.h

Related
functions usage void _lock_locale();

Description     This function locks the global locale to prevent other
                threads from using that locale.

Return value    None.

*---------------------------------------------------------------------*/

void _unlock_locale( void )
{
	_unlock( locale_lock, "unlocking global locale" );
}

/*---------------------------------------------------------------------*

Name            _init_locale - initialize global locale and lock

Usage           void _init_locale(void);

Description     This function

Return value    None.

*---------------------------------------------------------------------*/

void _RTLENTRY _init_locale( void )
{
#pragma startup _init_locale 1

	_create_lock( &locale_lock, "creating global locale lock" );
}

#endif  /* _MT */

