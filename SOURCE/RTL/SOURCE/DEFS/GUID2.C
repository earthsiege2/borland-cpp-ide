/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     guid2.c                                                  |*/
/*|                                                              |*/
/*|     This file contains the predefined GUIDs that also        |*/
/*|     prevent the EXE from running under WIN32s.               |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#define __inline         // for VFW.H's static __inline functions
#include <objbase.h>
#include <vfw.h>