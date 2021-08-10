#ifdef __FLAT__
  #include <win32\msacmdlg.h>
#else
  #error msacmdlg.h can only be used in a Win32 Application
#endif