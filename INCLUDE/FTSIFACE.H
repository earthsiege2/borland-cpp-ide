#ifdef __FLAT__
  #include <win32\ftsiface.h>
#else
  #error ftsiface.h can only be used in a Win32 Application
#endif // __FLAT__