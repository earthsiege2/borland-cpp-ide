#ifdef __FLAT__
  #include <win32\msviddrv.h>
#else
  #error msviddrv.h can only be used in a Win32 Application
#endif