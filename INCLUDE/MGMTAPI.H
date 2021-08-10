#ifdef __FLAT__
  #include <win32\mgmtapi.h>
#else
  #error mgmtapi.h can only be used in a Win32 Application
#endif