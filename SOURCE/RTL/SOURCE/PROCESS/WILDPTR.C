/*-----------------------------------------------------------------------*
 * filename - wildptr.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $        */

/* Contains the function pointers used to handle expansion of wild args */

#include <_setargv.h>

/* Init the pointer to the default expansion handler which does no expansion. */

void _RTLENTRY (* _RTLENTRY _targv_expand_ptr)(_TCHAR *_arg, _PFN_ADDARG _pfn_addarg) = _targv_default_expand;
