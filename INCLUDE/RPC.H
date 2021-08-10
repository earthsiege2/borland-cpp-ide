#if !defined(__RPC_H__)
  #ifdef __FLAT__
    #include <win32\rpc.h>
  #else
    #error rpc.h can only be used in a Win32 Application
  #endif
#endif /* __RPC_H_ */