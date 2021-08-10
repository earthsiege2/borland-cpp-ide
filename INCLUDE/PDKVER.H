#ifdef __FLAT__
  #include <win32\pdkver.h>
#else
  #error pdkver.h can only be used in a Win32 Application
#endif // __FLAT__