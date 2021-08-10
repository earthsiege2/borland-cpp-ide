#include <_io.h>
#include <stdio.h>

#ifdef _RTLDLL
extern  FILE    _RTLENTRY _streams[];
#endif

FILE *__getStream( int strm )
{
    return &(_streams[strm]);
}

