#ifdef __FLAT__
  #include <win32\winspool.h>
#else
  #error winspool.h can only be used in a Win32 Application
#endif