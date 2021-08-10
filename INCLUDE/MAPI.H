#ifdef __FLAT__
  #include <win32\mapi.h>
#else
  #error mapi.h can only be used in a Win32 Application
#endif // __FLAT__