#ifdef __FLAT__
  #include <win32\winuser.h>
#else
  #error winuser.h can only be used in a Win32 Application
#endif