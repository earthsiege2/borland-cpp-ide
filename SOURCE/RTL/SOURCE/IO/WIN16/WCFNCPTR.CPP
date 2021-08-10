/*------------------------------------------------------------------------
 * filename - wcfncptr.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <windows.h>

WORD  (*__ReadBufFPtr)(char *Buffer, WORD Count) = 0;
void  (*__WriteBufFPtr)(char *Buffer, WORD Count)= 0;
