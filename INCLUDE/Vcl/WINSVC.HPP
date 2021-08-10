// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WinSvc.pas' rev: 5.00

#ifndef WinSvcHPP
#define WinSvcHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Winsvc
{
//-- type declarations -------------------------------------------------------
typedef char * *PLPSTRA;

typedef wchar_t * *PLPWSTRW;

typedef char * *PLPSTR;

typedef _SERVICE_STATUS *PServiceStatus;

typedef _SERVICE_STATUS  TServiceStatus;

typedef _ENUM_SERVICE_STATUSA *PEnumServiceStatusA;

typedef _ENUM_SERVICE_STATUSW *PEnumServiceStatusW;

typedef _ENUM_SERVICE_STATUSA *PEnumServiceStatus;

typedef _ENUM_SERVICE_STATUSA  TEnumServiceStatusA;

typedef _ENUM_SERVICE_STATUSW  TEnumServiceStatusW;

typedef _ENUM_SERVICE_STATUSA  TEnumServiceStatus;

typedef _QUERY_SERVICE_LOCK_STATUSA *PQueryServiceLockStatusA;

typedef _QUERY_SERVICE_LOCK_STATUSW *PQueryServiceLockStatusW;

typedef _QUERY_SERVICE_LOCK_STATUSA *PQueryServiceLockStatus;

typedef _QUERY_SERVICE_LOCK_STATUSA  TQueryServiceLockStatusA;

typedef _QUERY_SERVICE_LOCK_STATUSW  TQueryServiceLockStatusW;

typedef _QUERY_SERVICE_LOCK_STATUSA  TQueryServiceLockStatus;

typedef _QUERY_SERVICE_CONFIGA *PQueryServiceConfigA;

typedef _QUERY_SERVICE_CONFIGW *PQueryServiceConfigW;

typedef _QUERY_SERVICE_CONFIGA *PQueryServiceConfig;

typedef _QUERY_SERVICE_CONFIGA  TQueryServiceConfigA;

typedef _QUERY_SERVICE_CONFIGW  TQueryServiceConfigW;

typedef _QUERY_SERVICE_CONFIGA  TQueryServiceConfig;

typedef void *TServiceMainFunctionA;

typedef void *TServiceMainFunctionW;

typedef void *TServiceMainFunction;

typedef _SERVICE_TABLE_ENTRYA *PServiceTableEntryA;

typedef _SERVICE_TABLE_ENTRYW *PServiceTableEntryW;

typedef _SERVICE_TABLE_ENTRYA *PServiceTableEntry;

typedef _SERVICE_TABLE_ENTRYA  TServiceTableEntryA;

typedef _SERVICE_TABLE_ENTRYW  TServiceTableEntryW;

typedef _SERVICE_TABLE_ENTRYA  TServiceTableEntry;

typedef void *THandlerFunction;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Winsvc */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Winsvc;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WinSvc
