/*-----------------------------------------------------------------------*
 * filename - setargv2.c
 *
 * function(s)
 *        _setargv2 - set up argv[]
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <_defs.h>

#if defined(_BUILDRTLDLL)
/*----------------------------------------------------------------------
 * BCC generates an external reference to __setargv__ when it compiles
 * a main() function that takes argc and argv parameters.  The following
 * declaration satisfies that reference and forces this module to be linked.
 */
int _setargv__ = 0;

void _setargv( void );

static void _setargv2( void )
  {
  _setargv();
  }

#pragma startup _setargv2 3      /* force _setargv2 to be called at startup */
#endif