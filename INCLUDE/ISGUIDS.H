#ifdef __FLAT__
  #include <win32\isguids.h>
#else
  #error isguids.h can only be used in a Win32 Application
#endif // __FLAT__