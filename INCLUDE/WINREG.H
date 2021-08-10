#ifdef __FLAT__
  #include <win32\winreg.h>
#else
  #error winreg.h can only be used in a Win32 Application
#endif