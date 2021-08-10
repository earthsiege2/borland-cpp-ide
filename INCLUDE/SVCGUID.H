#ifdef __FLAT__
  #include <win32\svcguid.h>
#else
  #error svcguid.h can only be used in a Win32 Application
#endif