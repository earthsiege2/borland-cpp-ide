#ifdef __FLAT__
  #include <win32\tspi.h>
#else
  #error tspi.h can only be used in a Win32 Application
#endif // __FLAT__