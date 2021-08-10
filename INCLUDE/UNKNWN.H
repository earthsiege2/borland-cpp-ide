#ifdef __FLAT__
  #include <win32\unknwn.h>
#else
  #error unknwn.h can only be used in a Win32 Application
#endif // __FLAT__