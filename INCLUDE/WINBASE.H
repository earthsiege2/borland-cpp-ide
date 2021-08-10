#ifdef __FLAT__
  #include <win32\winbase.h>
#else
  #error winbase.h can only be used in a Win32 Application
#endif