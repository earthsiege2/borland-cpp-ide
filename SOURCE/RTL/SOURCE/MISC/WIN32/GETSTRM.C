#include <_io.h>
#include <stdio.h>

/* This function is provided for CodeGuard(tm) support only */

FILE * _RTLENTRY _EXPFUNC __getStream( int strm )
{
    return &(_streams[strm]);
}

