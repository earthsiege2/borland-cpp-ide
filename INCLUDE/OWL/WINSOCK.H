//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Main header of the Winsock OWL subsystem.
//----------------------------------------------------------------------------
#if !defined(OWL_WINSOCK_H)
#define OWL_WINSOCK_H

#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#if !defined (_WINSOCKAPI_)
# include <winsock.h>
#endif
#if !defined(OWL_WSKADDR_H)
# include <owl/wskaddr.h>
#endif
#if !defined(OWL_WSKSOCK_H)
# include <owl/wsksock.h>
#endif
#if !defined(OWL_WSKERR_H)
# include <owl/wskerr.h>
#endif
#if !defined(OWL_WSKHOSTM_H)
# include <owl/wskhostm.h>
#endif
#if !defined(OWL_WSKSOCKD_H)
# include <owl/wsksockd.h>
#endif
#if !defined(OWL_WSKSOCKM_H)
# include <owl/wsksockm.h>
#endif
#if !defined(OWL_WSKSERVM_H)
# include <owl/wskservm.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TWinSockDll
// ~~~~~ ~~~~~~~~~~~
// Wrapper for the WinSock dll itself
//
class _OWLCLASS TWinSockDll : public TModule {
  public:
    TWinSockDll();

    // Socket functions
    //
    TModuleProc3<SOCKET,SOCKET,struct sockaddr far*, int far*> accept;
    TModuleProc3<int,SOCKET,struct sockaddr far*,int>          bind;
    TModuleProc1<int,SOCKET>                                   closesocket;
    TModuleProc3<int,SOCKET,struct sockaddr far*,int>          connect;
    TModuleProc3<int,SOCKET,struct sockaddr far*,int far*>     getpeername;
    TModuleProc3<int,SOCKET,struct sockaddr far*,int far*>     getsockname;
    TModuleProc5<int,SOCKET,int,int,char far*,int far*>        getsockopt;
    TModuleProc1<ulong,ulong>                                  htonl;
    TModuleProc1<ushort,ushort>                                htons;
    TModuleProc1<ulong,const char far*>                        inet_addr;
    TModuleProc1<char far*,struct in_addr>                     inet_ntoa;
    TModuleProc3<int,SOCKET,long,ulong far*>                   ioctlsocket;
    TModuleProc2<int,SOCKET,int>                               listen;
    TModuleProc1<ulong,ulong>                                  ntohl;
    TModuleProc1<ushort,ushort>                                ntohs;
    TModuleProc4<int,SOCKET,char far*,int,int>                 recv;
    TModuleProc6<int,SOCKET,char far*,int,int,struct sockaddr far*,int*>
                                                               recvfrom;
    TModuleProc5<int,int,struct fd_set far*,struct fd_set far*,
                struct fd_set far*,const struct timeval far*>  select;
    TModuleProc4<int,SOCKET,const char far*,int,int>           send;
    TModuleProc6<int,SOCKET,const char far*,int,int,
                 const struct sockaddr far*,int>               sendto;
    TModuleProc5<int,SOCKET,int,int,const char far*,int>       setsockopt;
    TModuleProc2<int,SOCKET,int>                               shutdown;
    TModuleProc3<SOCKET,int,int,int>                           socket;

    // Database functions
    //
    TModuleProc3<struct hostent far*,const char far*,int,int> gethostbyaddr;
    TModuleProc1<struct hostent far*,const char far*>         gethostbyname;
    TModuleProc2<int,char far*,int>                           gethostname;
    TModuleProc2<struct servent far*,const char far*,
                 const char far*>                             getservbyname;
    TModuleProc2<struct servent far*,int,const char far*>     getservbyport;

    TModuleProc1<struct protoent far*,const char far*>        getprotobyname;
    TModuleProc1<struct protoent far*,int>                    getprotobynumber;

    // Microsoft Windows Extension functions
    //
    TModuleProc2<int,uint16,LPWSADATA> WSAStartup;
    TModuleProc0<int> WSACleanup;
    TModuleProcV1<int> WSASetLastError;
    TModuleProc0<int> WSAGetLastError;

    TModuleProc0<int> WSAIsBlocking;
    TModuleProc0<int> WSAUnhookBlockingHook;
    TModuleProc1<FARPROC,FARPROC> WSASetBlockingHook;
    TModuleProc0<int> WSACancelBlockingCall;

    TModuleProc6<HANDLE,HWND,uint,const char far*,const char far*,char far*,int>
                                                      WSAAsyncGetServByName;
    TModuleProc6<HANDLE,HWND,uint,int,const char far*,char far*,int>
                                                      WSAAsyncGetServByPort;
    TModuleProc5<HANDLE,HWND,uint,const char far*,char far*,int>
                                                      WSAAsyncGetProtoByName;
    TModuleProc5<HANDLE,HWND,uint,int,char far*,int>  WSAAsyncGetProtoByNumber;

    TModuleProc5<HANDLE,HWND,uint,const char far*,char far*,int>
                                                      WSAAsyncGetHostByName;
    TModuleProc7<HANDLE,HWND,uint,const char far*,int,int,char far*,int>
                                                      WSAAsyncGetHostByAddr;

    TModuleProc1<int,HANDLE>                WSACancelAsyncRequest;
    TModuleProc4<int,SOCKET,HWND,uint,long> WSAAsyncSelect;

    TModuleProc4<int,SOCKET,char far*,int,int far*> WSARecvEx;
};

//
// class TWinSock
// ~~~~~ ~~~~~~~~
// Loader for the WinSock dll
//
typedef TDllLoader<TWinSockDll> TWinSock;

#if defined(BI_COMP_BORLANDC)
# if defined(_OWLDLL) || defined(BI_APP_DLL)
  //
  // Export template of TDllLoader<TWinSockDll> when building ObjectWindows DLL 
  // and provide import declaration of DLL instance for users of the class.
  //
  template class _OWLCLASS TDllLoader<TWinSockDll>;
# endif 
#endif  

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_WSKDLL_H
