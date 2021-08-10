/*-----------------------------------------------------------------------*
 * filename - _cfinfo.c
 *
 * variables:
 *      _cfinfo_value - pointer to value of _C_FILE_INFO environment variable
 *      _cfinfo_name  - name of _C_FILE_INFO environment variable
 *      _cfinfo_get   - pointer to function to construct _C_FILE_INFO
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

static int dummy_get(char *p)
{
    if (p)
        *p = '\0';
    return 0;
}

int (*_cfinfo_get)(char *) = dummy_get; /* function to get file info */

#ifdef __OS2__
char *_cfinfo_value = (char *)0;        /* pointer to value of env. variable */
char  _cfinfo_name[] = "_C_FILE_INFO="; /* name of env. variable */
#endif
