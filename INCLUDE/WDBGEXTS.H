#ifdef __FLAT__
  #include <win32\wdbgexts.h>
#else
  #error wdbgexts.h can only be used in a Win32 Application
#endif // __FLAT__