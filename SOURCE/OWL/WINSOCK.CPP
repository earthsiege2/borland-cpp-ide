//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of TWinSockDll, a WinSock dll loader & wrapper
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif

OWL_DIAGINFO;

#if defined(BI_PLAT_WIN32)
  static char WinSockDllName[] = "WSock32.dll";
#else
  static char WinSockDllName[] = "Winsock.dll";
#endif

//
// Construct wrapper object and load DLL
//

TWinSockDll::TWinSockDll()
:
  TModule(WinSockDllName, true, true)
{}

//
//  Standard socket functions
//

SOCKET
TWinSockDll::accept(SOCKET s, struct sockaddr far* addr, int far* addrLen)
{
  static TModuleProc3<SOCKET,SOCKET,struct sockaddr far*, int far*>
    accept(WinSockModule(), "accept");
  return accept(s, addr, addrLen);
}

int
TWinSockDll::bind(SOCKET s, struct sockaddr far* addr, int nameLen)
{
  static TModuleProc3<int,SOCKET,struct sockaddr far*,int>
    bind(WinSockModule(), "bind");
  return bind(s, addr, nameLen);
}

int
TWinSockDll::closesocket(SOCKET s)
{
  static TModuleProc1<int,SOCKET> closesocket(WinSockModule(), "closesocket");
  return closesocket(s);
}

int
TWinSockDll::connect(SOCKET s, struct sockaddr far* name, int nameLen)
{
  static TModuleProc3<int,SOCKET,struct sockaddr far*,int>
    connect(WinSockModule(), "connect");
  return connect(s, name, nameLen);
}

int
TWinSockDll::getpeername(SOCKET s, struct sockaddr far* name, int far* nameLen)
{
  static TModuleProc3<int,SOCKET,struct sockaddr far*,int far*>
    getpeername(WinSockModule(), "getpeername");
  return getpeername(s, name, nameLen);
}

int
TWinSockDll::getsockname(SOCKET s, struct sockaddr far* name, int far* nameLen)
{
  static TModuleProc3<int,SOCKET,struct sockaddr far*,int far*>
    getsockname(WinSockModule(), "getsockname");
  return getsockname(s, name, nameLen);
}

int
TWinSockDll::getsockopt(SOCKET s, int level, int optName, char far* optVal, int far* optLen)
{
  static TModuleProc5<int,SOCKET,int,int,char far*,int far*>
    getsockopt(WinSockModule(), "getsockopt");
  return getsockopt(s, level, optName, optVal, optLen);
}

ulong
TWinSockDll::htonl(ulong hostLong)
{
  static TModuleProc1<ulong,ulong> htonl(WinSockModule(), "htonl");
  return htonl(hostLong);
}

ushort
TWinSockDll::htons(ushort hostShort)
{
  static TModuleProc1<ushort,ushort> htons(WinSockModule(), "htons");
  return htons(hostShort);
}

ulong
TWinSockDll::inet_addr(const char far* cp)
{
  static TModuleProc1<ulong,const char far*> inet_addr(WinSockModule(), "inet_addr");
  return inet_addr(cp);
}

char far*
TWinSockDll::inet_ntoa(struct in_addr in)
{
  static TModuleProc1<char far*,struct in_addr> inet_ntoa(WinSockModule(), "inet_ntoa");
  return inet_ntoa(in);
}

int
TWinSockDll::ioctlsocket(SOCKET s, long cmd, ulong far* argp)
{
  static TModuleProc3<int,SOCKET,long,ulong far*>
    ioctlsocket(WinSockModule(), "ioctlsocket");
  return ioctlsocket(s, cmd, argp);
}

int
TWinSockDll::listen(SOCKET s, int backlog)
{
  static TModuleProc2<int,SOCKET,int> listen(WinSockModule(), "listen");
  return listen(s, backlog);
}

ulong
TWinSockDll::ntohl(ulong netLong)
{
  static TModuleProc1<ulong,ulong> ntohl(WinSockModule(), "ntohl");
  return ntohl(netLong);
}

ushort
TWinSockDll::ntohs(ushort netShort)
{
  static TModuleProc1<ushort,ushort> ntohs(WinSockModule(), "ntohs");
  return ntohs(netShort);
}

int
TWinSockDll::recv(SOCKET s, char far* buf, int len, int flags)
{
  static TModuleProc4<int,SOCKET,char far*,int,int> recv(WinSockModule(), "recv");
  return recv(s, buf, len, flags);
}

int
TWinSockDll::recvfrom(SOCKET s, char far* buf, int len, int flags,
  struct sockaddr far* from, int* fromLen)
{
  static TModuleProc6<int,SOCKET,char far*,int,int,struct sockaddr far*,int*>
    recvfrom(WinSockModule(), "recvfrom");
  return recvfrom(s, buf, len, flags, from, fromLen);
}

int
TWinSockDll::select(int nfds, struct fd_set far* readfds,
  struct fd_set far* writefds, struct fd_set far* exceptfds,
  const struct timeval far* timeout)
{
  static TModuleProc5<int,int,struct fd_set far*,struct fd_set far*,
    struct fd_set far*,const struct timeval far*> select(WinSockModule(), "select");
  return select(nfds, readfds, writefds, exceptfds, timeout);
}

int
TWinSockDll::send(SOCKET s, const char far* buf, int len, int flags)
{
  static TModuleProc4<int,SOCKET,const char far*,int,int> send(WinSockModule(), "send");
  return send(s, buf, len, flags);
}

int
TWinSockDll::sendto(SOCKET s, const char far* buf, int len, int flags,
  const struct sockaddr far* to, int toLen)
{
  static TModuleProc6<int,SOCKET,const char far*,int,int,
    const struct sockaddr far*,int> sendto(WinSockModule(), "sendto");
  return sendto(s, buf, len, flags, to, toLen);
}

int
TWinSockDll::setsockopt(SOCKET s, int level, int optName,
  const char far* optVal, int optLen)
{
  static TModuleProc5<int,SOCKET,int,int,const char far*,int>
    setsockopt(WinSockModule(), "setsockopt");
  return setsockopt(s, level, optName, optVal, optLen);
}

int
TWinSockDll::shutdown(SOCKET s, int how)
{
  static TModuleProc2<int,SOCKET,int> shutdown(WinSockModule(), "shutdown");
  return shutdown(s, how);
}

SOCKET
TWinSockDll::socket(int af, int type, int protocol)
{
  static TModuleProc3<SOCKET,int,int,int> socket(WinSockModule(), "socket");
  return socket(af, type, protocol);
}

//
// Database functions
//

struct hostent far*
TWinSockDll::gethostbyaddr(const char far* addr, int len, int type)
{
  static TModuleProc3<struct hostent far*,const char far*,int,int>
    gethostbyaddr(WinSockModule(), "gethostbyaddr");
  return gethostbyaddr(addr, len, type);
}

struct hostent far*
TWinSockDll::gethostbyname(const char far* name)
{
  static TModuleProc1<struct hostent far*,const char far*>
    gethostbyname(WinSockModule(), "gethostbyname");
  return gethostbyname(name);
}

int
TWinSockDll::gethostname(char far* name, int nameLen)
{
  static TModuleProc2<int,char far*,int> gethostname(WinSockModule(), "gethostname");
  return gethostname(name, nameLen);
}

struct servent far*
TWinSockDll::getservbyname(const char far* name, const char far* proto)
{
  static TModuleProc2<struct servent far*,const char far*, const char far*>
    getservbyname(WinSockModule(), "getservbyname");
  return getservbyname(name, proto);
}

struct servent far*
TWinSockDll::getservbyport(int port, const char far* proto)
{
  static TModuleProc2<struct servent far*,int,const char far*>
    getservbyport(WinSockModule(), "getservbyport");
  return getservbyport(port, proto);
}

struct protoent far*
TWinSockDll::getprotobyname(const char far* name)
{
  static TModuleProc1<struct protoent far*, const char far*>
    getprotobyname(WinSockModule(), "getprotobyname");
  return getprotobyname(name);
}

struct protoent far*
TWinSockDll::getprotobynumber(int proto)
{
  static TModuleProc1<struct protoent far*, int>
    getprotobynumber(WinSockModule(), "getprotobynumber");
  return getprotobynumber(proto);
}

//
// Microsoft Windows Extension functions
//

int
TWinSockDll::WSAStartup(uint16 versionRequested, LPWSADATA WSAData)
{
  static TModuleProc2<int,uint16,LPWSADATA> WSAStartup(WinSockModule(), "WSAStartup");
  return WSAStartup(versionRequested, WSAData);
}

int
TWinSockDll::WSACleanup(void)
{
  static TModuleProc0<int> WSACleanup(WinSockModule(), "WSACleanup");
  return WSACleanup();
}

void
TWinSockDll::WSASetLastError(int error)
{
  static TModuleProcV1<int> WSASetLastError(WinSockModule(), "WSASetLastError");
  WSASetLastError(error);
}

int
TWinSockDll::WSAGetLastError(void)
{
  static TModuleProc0<int> WSAGetLastError(WinSockModule(), "WSAGetLastError");
  return WSAGetLastError();
}

BOOL
TWinSockDll::WSAIsBlocking(void)
{
  static TModuleProc0<int> WSAIsBlocking(WinSockModule(), "WSAIsBlocking");
  return WSAIsBlocking();
}

int
TWinSockDll::WSAUnhookBlockingHook(void)
{
  static TModuleProc0<int> WSAUnhookBlockingHook(WinSockModule(), "WSAUnhookBlockingHook");
  return WSAUnhookBlockingHook();
}

FARPROC
TWinSockDll::WSASetBlockingHook(FARPROC blockFunc)
{
  static TModuleProc1<FARPROC,FARPROC>
    WSASetBlockingHook(WinSockModule(), "WSASetBlockingHook");
  return WSASetBlockingHook(blockFunc);
}

int
TWinSockDll::WSACancelBlockingCall(void)
{
  static TModuleProc0<int> WSACancelBlockingCall(WinSockModule(), "WSACancelBlockingCall");
  return WSACancelBlockingCall();
}

HANDLE
TWinSockDll::WSAAsyncGetServByName(HWND hWnd, uint msg, const char far* name,
  const char far* proto, char far* buf, int bufLen)
{
  static TModuleProc6<HANDLE,HWND,uint,const char far*,const char far*,
    char far*,int> WSAAsyncGetServByName(WinSockModule(), "WSAAsyncGetServByName");
  return WSAAsyncGetServByName(hWnd, msg, name, proto, buf, bufLen);
}

HANDLE
TWinSockDll::WSAAsyncGetServByPort(HWND hWnd, uint msg, int port,
  const char far* proto, char far* buf, int bufLen)
{
  static TModuleProc6<HANDLE,HWND,uint,int,const char far*,char far*,int>
    WSAAsyncGetServByPort(WinSockModule(), "WSAAsyncGetServByPort");
  return WSAAsyncGetServByPort(hWnd, msg, port, proto, buf, bufLen);
}

HANDLE
TWinSockDll::WSAAsyncGetProtoByName(HWND hWnd, uint msg, const char far* name,
  char far* buf, int bufLen)
{
  static TModuleProc5<HANDLE,HWND,uint,const char far*,char far*,int>
    WSAAsyncGetProtoByName(WinSockModule(), "WSAAsyncGetProtoByName");
  return WSAAsyncGetProtoByName(hWnd, msg, name, buf, bufLen);
}

HANDLE
TWinSockDll::WSAAsyncGetProtoByNumber(HWND hWnd, uint msg, int number,
  char far* buf, int bufLen)
{
  static TModuleProc5<HANDLE,HWND,uint,int,char far*,int>
    WSAAsyncGetProtoByNumber(WinSockModule(), "WSAAsyncGetProtoByNumber");
  return WSAAsyncGetProtoByNumber(hWnd, msg, number, buf, bufLen);
}

HANDLE
TWinSockDll::WSAAsyncGetHostByName(HWND hWnd, uint msg, const char far* name,
  char far* buf, int bufLen)
{
  static TModuleProc5<HANDLE,HWND,uint,const char far*,char far*,int>
    WSAAsyncGetHostByName(WinSockModule(), "WSAAsyncGetHostByName");
  return WSAAsyncGetHostByName(hWnd, msg, name, buf, bufLen);
}

HANDLE
TWinSockDll::WSAAsyncGetHostByAddr(HWND hWnd, uint msg, const char far* addr,
  int len, int type, char far* buf, int bufLen)
{
  static TModuleProc7<HANDLE,HWND,uint,const char far*,int,int,char far*,int>
    WSAAsyncGetHostByAddr(WinSockModule(), "WSAAsyncGetHostByAddr");
  return WSAAsyncGetHostByAddr(hWnd, msg, addr, len, type, buf, bufLen);
}

int
TWinSockDll::WSACancelAsyncRequest(HANDLE hTaskHandle)
{
  static TModuleProc1<int,HANDLE>
    WSACancelAsyncRequest(WinSockModule(), "WSACancelAsyncRequest");
  return WSACancelAsyncRequest(hTaskHandle);
}

int
TWinSockDll::WSAAsyncSelect(SOCKET s, HWND hWnd, uint msg, long event)
{
  static TModuleProc4<int,SOCKET,HWND,uint,long>
    WSAAsyncSelect(WinSockModule(), "WSAAsyncSelect");
  return WSAAsyncSelect(s, hWnd, msg, event);
}

int
TWinSockDll::WSARecvEx(SOCKET s, char far* buf, int len, int far* flags)
{
  TModuleProc4<int,SOCKET,char far*,int,int far*> WSARecvEx(WinSockModule(), "WSARecvEx");
  return WSARecvEx(s, buf, len, flags);
}

TModule& 
TWinSockDll::WinSockModule()
{
  static TModule winSockModule(WinSockDllName, true, true);
  return winSockModule;
}

bool 
TWinSockDll::IsAvailable()
{
  return WinSockModule().IsLoaded();
}

bool       
TWinSock::IsAvailable()
{
  return TWinSockDll::IsAvailable();
}

TWinSockDll* 
TWinSock::Dll()
{
  static TWinSockDll winSockDll;
  return &winSockDll;
}

