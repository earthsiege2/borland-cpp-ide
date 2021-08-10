#if !defined(__objidl_h__)
  #ifdef __FLAT__
    #include <win32\objidl.h>
  #else
    #error objidl.h can only be used in a Win32 Application
  #endif /* __FLAT__ */
#endif /* __objidl_h__ */
