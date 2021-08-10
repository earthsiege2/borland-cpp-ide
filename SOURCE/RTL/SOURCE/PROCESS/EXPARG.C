/*-----------------------------------------------------------------------*
 * filename - exparg.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#include <_setargv.h>

/*----------------------------------------------------------------------
 * _targv_default_expand - dummy wildcard expansion routine
 */
void _RTLENTRY _EXPFUNC _targv_default_expand(_TCHAR *_arg, _PFN_ADDARG _pfn_addarg)
{
    _pfn_addarg(_arg, 0);        /* add argument without making a copy */
}
