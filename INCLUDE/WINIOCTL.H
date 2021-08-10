#ifdef __FLAT__
  #include <win32\winioctl.h>
#else
  #error winioctl.h can only be used in a Win32 Application
#endif
