/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1993, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <signal.h>

#if defined(_BUILDRTLDLL)
extern _CatcherPTR _FARFUNC __signalDS(int sig, _CatcherPTR New, unsigned DS);

_CatcherPTR signal(int sig, _CatcherPTR New)
{
    return __signalDS(sig, New, _DS);
}
#endif
