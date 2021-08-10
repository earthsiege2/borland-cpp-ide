#ifdef __FLAT__
  #include <win32\idf.h>
#else
  #error idf.h can only be used in a Win32 Application
#endif // __FLAT__