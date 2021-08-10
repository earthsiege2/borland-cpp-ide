#ifdef __FLAT__
  #include <win32\nddeapi.h>
#else
  #error nddeapi.h can only be used in a Win32 Application
#endif