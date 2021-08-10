#ifdef __FLAT__
  #include <win32\tlhelp32.h>
#else
  #error tlhelp32.h can only be used in a Win32 Application
#endif // __FLAT__