/*-----------------------------------------------------------------------*
 * filename - files.c
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_nfile.h>

/*----------------------------------------------------------------------
 * The following external reference forces _init_streams (in streams.obj)
 * to be called at startup.
 */
extern void _RTLENTRY _init_streams(void);
#pragma startup       _init_streams 5

/*---------------------------------------------------------------------*

Name            _streams

Description     _streams is the array of FILE structures used by the
                stream handling functions.

*---------------------------------------------------------------------*/

#define _F_STDIN        (_F_READ | _F_TERM | _F_LBUF)
#define _F_STDOUT       (_F_WRIT | _F_TERM | _F_LBUF)
#define _F_STDERR       (_F_WRIT | _F_TERM)

FILE    _RTLENTRY _EXPDATA _streams [_NFILE_] =
{
        { NULL, NULL, 0, 0, 0, _F_STDIN,  0, 0, 0 },
        { NULL, NULL, 0, 0, 0, _F_STDOUT, 0, 1, 0 },
        { NULL, NULL, 0, 0, 0, _F_STDERR, 0, 2, 0 }
};
