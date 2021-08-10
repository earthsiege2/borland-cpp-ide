/*-----------------------------------------------------------------------*
 * filename - initwild.c
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1999, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

/* Sets the function pointers used to handle expansion of wild args (or not to)
*/

#include <_setargv.h>

/*----------------------------------------------------------------------
 * _init_wild_handlers - sets the pointers to the argument expanders
 *
 * This function will be called directly by the startup code for EXEs.
 * It modifies pointers in setargv.c to point to the function that will
 * cause wildcard arguments to be expanded (or not to be).
 */
void _init_wild_handlers(void (**wild_func)(char *, _PFN_ADDARG), void (**wwild_func)(wchar_t *, _PFN_ADDARG))
{
    _argv_expand_ptr = *wild_func;
    _wargv_expand_ptr = *wwild_func;
}
