//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of TWinSockDll, a WinSock dll loader & wrapper
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif

#if defined(BI_PLAT_WIN32)
  static char WinSockDllName[] = "WSock32.dll";
#else
  static char WinSockDllName[] = "Winsock.dll";
#endif

//
//
//
TWinSockDll::TWinSockDll()
:
  TModule(WinSockDllName, true, true),

  accept(*this, "accept"),
  bind(*this, "bind"),
  closesocket(*this, "closesocket"),
  connect(*this, "connect"),
  getpeername(*this, "getpeername"),
  getsockname(*this, "getsockname"),
  getsockopt(*this, "getsockopt"),
  htonl(*this, "htonl"),  //*
  htons(*this, "htons"),  //*
  inet_addr(*this, "inet_addr"),
  inet_ntoa(*this, "inet_ntoa"),
  ioctlsocket(*this, "ioctlsocket"),
  listen(*this, "listen"),
  ntohl(*this, "htonl"),  //*
  ntohs(*this, "htons"),  //*
  recv(*this, "recv"),
  recvfrom(*this, "recvfrom"),
  select(*this, "select"),
  send(*this, "send"),
  sendto(*this, "sendto"),
  setsockopt(*this, "setsockopt"),
  shutdown(*this, "shutdown"),
  socket(*this, "socket"),
  gethostbyaddr(*this, "gethostbyaddr"),
  gethostbyname(*this, "gethostbyname"),
  gethostname(*this, "gethostname"),
  getservbyname(*this, "getservbyname"),
  getservbyport(*this, "getservbyport"),
  getprotobyname(*this, "getprotobyname"),
  getprotobynumber(*this, "getprotobynumber"),

  WSAStartup(*this, "WSAStartup"),
  WSACleanup(*this, "WSACleanup"),
  WSASetLastError(*this, "WSASetLastError"),
  WSAGetLastError(*this, "WSAGetLastError"),

  WSAIsBlocking(*this, "WSAIsBlocking"),
  WSAUnhookBlockingHook(*this, "WSAUnhookBlockingHook"),
  WSASetBlockingHook(*this, "WSASetBlockingHook"),
  WSACancelBlockingCall(*this, "WSACancelBlockingCall"),
  
  WSAAsyncGetServByName(*this, "WSAAsyncGetServByName"),
  WSAAsyncGetServByPort(*this, "WSAAsyncGetServByPort"),
  WSAAsyncGetProtoByName(*this, "WSAAsyncGetProtoByName"),
  WSAAsyncGetProtoByNumber(*this, "WSAAsyncGetProtoByNumber"),
  WSAAsyncGetHostByName(*this, "WSAAsyncGetHostByName"),
  WSAAsyncGetHostByAddr(*this, "WSAAsyncGetHostByAddr"),

  WSACancelAsyncRequest(*this, "WSACancelAsyncRequest"),
  WSAAsyncSelect(*this, "WSAAsyncSelect"),
  WSARecvEx(*this, "WSARecvEx")
{
}

#if (__BORLANDC__ >= 0x500)
//
// Force an instantiation of the dll loader class template here
//
template class /*_OWLCLASS*/ TDllLoader<TWinSockDll>;
#endif
