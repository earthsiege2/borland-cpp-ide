#ifdef __FLAT__
  #include <win32\error.h>
#else
  #error error.h can only be used in a Win32 Application
#endif // __FLAT__
