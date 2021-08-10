#include <signal.h>

#if defined(_BUILDRTLDLL)
extern _CatcherPTR _Cdecl _FARFUNC __signalDS(int sig, _CatcherPTR New, unsigned DS);

_CatcherPTR _Cdecl signal(int sig, _CatcherPTR New)
{
    return __signalDS(sig, New, _DS);
}    
#endif