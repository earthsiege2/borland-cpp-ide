#ifdef __FLAT__
  #include <win32\pcrt32.h>
#else
  #error pcrt32.h can only be used in a Win32 Application
#endif // __FLAT__