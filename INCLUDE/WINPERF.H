#ifdef __FLAT__
  #include <win32\winperf.h>
#else
  #error winperf.h can only be used in a Win32 Application
#endif