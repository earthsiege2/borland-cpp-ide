#ifdef __FLAT__
  #include <win32\mspst.h>
#else
  #error mspst.h can only be used in a Win32 Application
#endif // __FLAT__