#if !defined(__RPCNDR_H__)
  #ifdef __FLAT__
    #include <win32\rpcndr.h>
  #else
    #error rpcndr.h can only be used in a Win32 Application
  #endif
#endif /* __RPCNDR_H__ */