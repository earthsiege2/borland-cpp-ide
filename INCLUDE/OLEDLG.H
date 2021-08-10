#ifdef __FLAT__
  #include <win32\oledlg.h>
#else
  #error oledlg.h can only be used in a Win32 Application
#endif // __FLAT__