// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WinSock.pas' rev: 6.00

#ifndef WinSockHPP
#define WinSockHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <winsock.h>
namespace Winsock
{
typedef fd_set *PFDSet;
typedef fd_set TFDSet;
}

namespace Winsock
{
//-- type declarations -------------------------------------------------------
typedef timeval *PTimeVal;

typedef timeval  TTimeVal;

typedef hostent *PHostEnt;

typedef hostent  THostEnt;

typedef netent *PNetEnt;

typedef netent  TNetEnt;

typedef servent *PServEnt;

typedef servent  TServEnt;

typedef protoent *PProtoEnt;

typedef protoent  TProtoEnt;

typedef in_addr *PInAddr;

typedef in_addr  TInAddr;

typedef sockaddr_in *PSockAddrIn;

typedef sockaddr_in  TSockAddrIn;

typedef WSAData *PWSAData;

typedef WSAData  TWSAData;

typedef sockproto *PSockProto;

typedef sockproto  TSockProto;

typedef linger *PLinger;

typedef linger  TLinger;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Winsock */
using namespace Winsock;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WinSock
