/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <signal.h>

#if defined(_BUILDRTLDLL)
extern _CatcherPTR _FARFUNC __signalDS(int sig, _CatcherPTR New, unsigned DS);

_CatcherPTR signal(int sig, _CatcherPTR New)
{
    return __signalDS(sig, New, _DS);
}
#endif
