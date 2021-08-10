#ifdef __FLAT__
  #include <win32\winsvc.h>
#else
  #error winsvc.h can only be used in a Win32 Application
#endif