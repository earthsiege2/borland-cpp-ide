#ifdef __FLAT__
  #include <win32\wingdi.h>
#else
  #error wingdi.h can only be used in a Win32 Application
#endif
