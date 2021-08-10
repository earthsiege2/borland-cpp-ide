/*-----------------------------------------------------------------------*
 * filename - version.c
 *
 * variables
 *      _osmajor    - major OS version number
 *      _osminor    - minor OS version number
 *      _osmode     - protected mode flag
 *      _osversion  - combined version number
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1991, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.7 $        */

#include <ntbc.h>

#include <stdlib.h>

/*----------------------------------------------------------------------
 * Public variables.
 */
unsigned char _RTLENTRY _EXPDATA _osmajor = 0;
unsigned char _RTLENTRY _EXPDATA _osminor = 0;
unsigned char _RTLENTRY _EXPDATA _osmode  = OS2_MODE;
unsigned int  _RTLENTRY _EXPDATA _osversion = 0;
unsigned int  _RTLENTRY _EXPDATA _version = 0;

/*---------------------------------------------------------------------*

Name            _init_version - get OS version number

Usage           void _init_version(void);

Prototype in

Description     Query NT for the major and minor version number.
                Only called once at startup time if any of the _os???
                variables are used.

Return value    None.

*---------------------------------------------------------------------*/

void _init_version()
{
#pragma startup _init_version 0 /* Queries the OS and sets _osmajor, _osminor & _osversion */

    DWORD version;

    /* Get the major and minor version numbers from NT.
     * Use the upper word to get the major and minor version numbers
     * of the OS.  The low word contains the Windows version numbers,
     * and is ignored.
     */
    version = GetVersion();

    _osmajor = (unsigned char)(version & 0xff);
    _osminor = (unsigned char)((version >> 8) & 0xff);
    _osversion = _version = (unsigned short) _osmajor + (_osminor << 8);
}
