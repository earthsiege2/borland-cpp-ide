/*-----------------------------------------------------------------------*
 * filename - _srchpth.c
 *
 * function(s)
 *        __searchpath   - searches the PATH environment variable
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef _MT
#include <_thread.h>
#endif
#include <io.h>
#include <string.h>
#include <dir.h>
#include <stdlib.h>

#ifdef _MT

#define pathbuf (char *)THREAD_BUF(pathbuf,_MAX_PATH)

#else

static char pathbuf[_MAX_PATH];

#endif  /* _MT */

/*-----------------------------------------------------------------------*

Name            __searchpath - searches the DOS path

Usage           char *__searchpath(const char *filename);

Prototype in    dir.h

Description     searchpath simply calls _searchenv to search the current
                directory and PATH for filename.

Return value    A pointer to the filename string if the file is successfully
                found; this string is stored in a static array that is
                overwritten with each call.  NULL is returned if the
                file is not found.

*------------------------------------------------------------------------*/

char *pascal near __searchpath(const char *file, int hack)
  {
  char *buf = pathbuf;

  /* A quick check to see if we already have a fully-qualified file name. */

  if( access( file, 0 ) == 0 )
    {
    /* Make sure the path is not a relative path. */

    strcpy( pathbuf, file );

    if( (buf = _fullpath( NULL, pathbuf, _MAX_PATH )) == NULL )
      {
      /* Out of memory.  Just do the best we can and leave pathbuf as it is. */
      }
    else
      {
      strcpy( pathbuf, buf );

      free( buf );
      }

    return( pathbuf );
    }
  else
    {
    _searchenv( file, "PATH", buf );

    return( buf[0] == '\0' ? NULL : buf );
    }
  }
