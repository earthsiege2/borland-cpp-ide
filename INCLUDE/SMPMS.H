#ifdef __FLAT__
  #include <win32\smpms.h>
#else
  #error smpms.h can only be used in a Win32 Application
#endif // __FLAT__