//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
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
    static SOCKET      accept(SOCKET s, struct sockaddr far* addr,
                        int far* addrLen);
    static int         bind(SOCKET s, struct sockaddr far* addr, int nameLen);
    static int         closesocket(SOCKET s);
    static int         connect(SOCKET s, struct sockaddr far* name, int nameLen);
    static int         getpeername(SOCKET s, struct sockaddr far* name,
                        int far* nameLen);
    static int         getsockname(SOCKET s, struct sockaddr far* name,
                        int far* nameLen);
    static int         getsockopt(SOCKET s, int level, int optName, char far* optVal,
                        int far* optLen);
    static ulong       htonl(ulong hostLong);
    static ushort      htons(ushort hostShort);
    static ulong       inet_addr(const char far* cp);
    static char far*   inet_ntoa(struct in_addr in);
    static int         ioctlsocket(SOCKET s, long cmd, ulong far* argp);
    static int         listen(SOCKET s, int backlog);
    static ulong       ntohl(ulong netLong);
    static ushort      ntohs(ushort netShort);
    static int         recv(SOCKET s, char far* buf, int len, int flags);
    static int         recvfrom(SOCKET s, char far* buf, int len, int flags,
                        struct sockaddr far* from, int* fromLen);
    static int         select(int nfds, struct fd_set far* readfds,
                        struct fd_set far* writefds,
                        struct fd_set far* exceptfds,
                        const struct timeval far* timeout);
    static int         send(SOCKET s, const char far* buf, int len, int flags);
    static int         sendto(SOCKET s, const char far* buf, int len, int flags,
                        const struct sockaddr far* to, int toLen);
    static int         setsockopt(SOCKET s, int level, int optName,
                        const char far* optVal, int optLen);
    static int         shutdown(SOCKET s, int how);
    static SOCKET      socket(int af, int type, int protocol);

    // Database functions
    //
    static struct hostent  far*  gethostbyaddr(const char far* addr, int len,
                                  int type);
    static struct hostent  far*  gethostbyname(const char far* name);
    static int                   gethostname(char far* name, int nameLen);
    static struct servent  far*  getservbyname(const char far* name,
                                  const char far* proto);
    static struct servent  far*  getservbyport(int port, const char far* proto);
    static struct protoent far*  getprotobyname(const char far* name);
    static struct protoent far*  getprotobynumber(int proto);

    // Microsoft Windows Extension functions
    //
    static int     WSAStartup(uint16 versionRequested, LPWSADATA WSAData);
    static int     WSACleanup(void);
    static void    WSASetLastError(int error);
    static int     WSAGetLastError(void);
    static BOOL    WSAIsBlocking(void);
    static int     WSAUnhookBlockingHook(void);
    static FARPROC WSASetBlockingHook(FARPROC blockFunc);
    static int     WSACancelBlockingCall(void);
    static HANDLE  WSAAsyncGetServByName(HWND hWnd, uint msg,
                    const char far* name, const char far* proto, char far* buf,
                    int bufLen);
    static HANDLE  WSAAsyncGetServByPort(HWND hWnd, uint msg, int port,
                    const char far* proto, char far* buf, int bufLen);
    static HANDLE  WSAAsyncGetProtoByName(HWND hWnd, uint msg,
                    const char far* name, char far* buf, int bufLen);
    static HANDLE  WSAAsyncGetProtoByNumber(HWND hWnd, uint msg, int number,
                    char far* buf, int bufLen);
    static HANDLE  WSAAsyncGetHostByName(HWND hWnd, uint msg,
                    const char far* name, char far* buf, int bufLen);
    static HANDLE  WSAAsyncGetHostByAddr(HWND hWnd, uint msg,
                    const char far* addr, int len, int type, char far* buf,
                    int bufLen);
    static int     WSACancelAsyncRequest(HANDLE hTaskHandle);
    static int     WSAAsyncSelect(SOCKET s, HWND hWnd, uint msg, long event);
    static int     WSARecvEx(SOCKET s, char far* buf, int len, int far* flags);

    // Check for presence of Winsock DLL
    //
    static TModule& WinSockModule();
    static bool IsAvailable();
};

//
// class TWinSock
// ~~~~~ ~~~~~~~~
// Loader for the WinSock dll
//

class _OWLCLASS TWinSock
{
  public:
    static bool         IsAvailable(void);
    static TWinSockDll* Dll(void);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_WSKDLL_H
