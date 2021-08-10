#ifdef __FLAT__
  #include <win32\lsapi.h>
#else
  #error lsapi.h can only be used in a Win32 Application
#endif
