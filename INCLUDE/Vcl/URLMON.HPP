// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'UrlMon.pas' rev: 6.00

#ifndef UrlMonHPP
#define UrlMonHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
//---------------------------------------------------------------------------
// if compilation errors occur while attempting to access structs, unions, or enums
// define NO_WIN32_LEAN_AND_MEAN so that the appropriate windows headers are included.
//---------------------------------------------------------------------------
#if defined(NO_WIN32_LEAN_AND_MEAN)
#include "rpc.h"
#include "rpcndr.h"
#include "urlmon.h"
  #ifndef COM_NO_WINDOWS_H
  #include "windows.h" 
  #include "ole2.h"
  #endif
#endif
DECLARE_DINTERFACE_TYPE(IPersistMoniker);
DECLARE_DINTERFACE_TYPE(IBindProtocol);
DECLARE_DINTERFACE_TYPE(IBinding);
DECLARE_DINTERFACE_TYPE(IBindStatusCallback);
DECLARE_DINTERFACE_TYPE(IAuthenticate);
DECLARE_DINTERFACE_TYPE(IHttpNegotiate);
DECLARE_DINTERFACE_TYPE(IWindowForBindingUI);
DECLARE_DINTERFACE_TYPE(ICodeInstall);
DECLARE_DINTERFACE_TYPE(IWinInetInfo);
DECLARE_DINTERFACE_TYPE(IHttpSecurity);
DECLARE_DINTERFACE_TYPE(IWinInetHttpInfo);
DECLARE_DINTERFACE_TYPE(IBindHost);
DECLARE_DINTERFACE_TYPE(IInternet);
DECLARE_DINTERFACE_TYPE(IInternetBindInfo);
DECLARE_DINTERFACE_TYPE(IInternetProtocolRoot);
DECLARE_DINTERFACE_TYPE(IInternetProtocol);
DECLARE_DINTERFACE_TYPE(IInternetProtocolSink);
DECLARE_DINTERFACE_TYPE(IInternetSession);
DECLARE_DINTERFACE_TYPE(IInternetThreadSwitch);
DECLARE_DINTERFACE_TYPE(IInternetPriority);
DECLARE_DINTERFACE_TYPE(IInternetProtocolInfo);
DECLARE_DINTERFACE_TYPE(IInternetSecurityMgrSite);
DECLARE_DINTERFACE_TYPE(IInternetSecurityManager);
DECLARE_DINTERFACE_TYPE(IInternetHostSecurityManager);
DECLARE_DINTERFACE_TYPE(IInternetZoneManager);
DECLARE_DINTERFACE_TYPE(ISoftDistExt);
DECLARE_DINTERFACE_TYPE(IDataFilter);
DECLARE_DINTERFACE_TYPE(IEncodingFilterFactory);
#if !defined(NO__WIN32_LEAN_AND_MEAN)
struct _tagBINDINFO;
struct _REMSECURITY_ATTRIBUTES;
struct _tagRemBINDINFO;
struct tagRemFORMATETC;
struct _tagPROTOCOLDATA;
struct _ZONEATTRIBUTES;
struct _tagCODEBASEHOLD;
struct _tagSOFTDISTINFO;
struct _tagPROTOCOLFILTERDATA;
struct _tagDATAINFO;
struct _tagHIT_LOGGING_INFO;
#endif

namespace Urlmon
{
//-- type declarations -------------------------------------------------------
typedef unsigned TBindVerb;

typedef unsigned TBindInfoF;

typedef unsigned TBindF;

typedef unsigned TBSCF;

typedef unsigned TBindStatus;

typedef unsigned TCIPStatus;

typedef unsigned TBindString;

typedef unsigned TPiFlags;

typedef unsigned TOIBdgFlags;

typedef unsigned TParseAction;

typedef unsigned TPSUAction;

typedef unsigned TQueryOption;

typedef unsigned TPUAF;

typedef unsigned TSZMFlags;

typedef unsigned TUrlZone;

typedef unsigned TUrlTemplate;

typedef unsigned TZAFlags;

typedef unsigned TUrlZoneReg;

typedef _tagBINDINFO *PBindInfo;

typedef _tagBINDINFO  TBindInfo;

typedef _REMSECURITY_ATTRIBUTES *PRemSecurityAttributes;

typedef _REMSECURITY_ATTRIBUTES  TRemSecurityAttributes;

typedef _tagRemBINDINFO *PRemBindInfo;

typedef _tagRemBINDINFO  TRemBindInfo;

typedef tagRemFORMATETC *PRemFormatEtc;

typedef tagRemFORMATETC  TRemFormatEtc;

typedef _tagPROTOCOLDATA *PProtocolData;

typedef _tagPROTOCOLDATA  TProtocolData;

typedef _ZONEATTRIBUTES *PZoneAttributes;

typedef _ZONEATTRIBUTES  TZoneAttributes;

typedef _tagCODEBASEHOLD *PCodeBaseHold;

typedef _tagCODEBASEHOLD  TCodeBaseHold;

typedef _tagSOFTDISTINFO *PSoftDistInfo;

typedef _tagSOFTDISTINFO  TSoftDistInfo;

typedef _tagPROTOCOLFILTERDATA *PProtocolFilterData;

typedef _tagPROTOCOLFILTERDATA  TProtocolFilterData;

typedef _tagDATAINFO *PDataInfo;

typedef _tagDATAINFO  TDataInfo;

typedef _tagHIT_LOGGING_INFO *PHitLoggingInfo;

typedef _tagHIT_LOGGING_INFO  THitLoggingInfo;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Urlmon */
using namespace Urlmon;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// UrlMon
