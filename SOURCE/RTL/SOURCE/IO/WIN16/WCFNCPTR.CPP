/*------------------------------------------------------------------------
 * filename - wcfncptr.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <windows.h>

WORD  (*__ReadBufFPtr)(char *Buffer, WORD Count) = 0;
void  (*__WriteBufFPtr)(char *Buffer, WORD Count)= 0;
