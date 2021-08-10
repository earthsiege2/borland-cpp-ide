/*-----------------------------------------------------------------------*
 * filename - pureerr.cpp
 * Error routine linked in when pure function called
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1990, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

/*
   A pointer to this routine is linked into virtual vectors whenever
   a virtual function has been declared pure.  Ideally, the error
   message should be printed without using printf or stream I/O,
   since we would rather not pull in the code for those.  Such a
   result is system-dependent and beyond the scope of this implementation.
*/

#include <_io.h>
#pragma option -k  /* Enable standard stack frame so the debugger guys don't
                      get so grouchy when stepping in the debugger.
                   */
extern "C" void _RTLENTRY _pure_error_()
{
    _ErrorExit("Pure virtual function called");
}
