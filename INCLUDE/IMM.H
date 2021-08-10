#ifdef __FLAT__
  #include <win32\imm.h>
#else
  #error imm.h can only be used in a Win32 Application
#endif // __FLAT__
