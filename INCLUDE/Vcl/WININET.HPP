// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WinInet.pas' rev: 6.00

#ifndef WinInetHPP
#define WinInetHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <wininet.h>

namespace Wininet
{
//-- type declarations -------------------------------------------------------
typedef void * *PHINTERNET;

typedef Word *PINTERNET_PORT;

typedef int *PInternetScheme;

typedef int TInternetScheme;

struct TInternetAsyncResult;
typedef TInternetAsyncResult *PInternetAsyncResult;

#pragma pack(push, 1)
struct TInternetAsyncResult
{
	unsigned dwResult;
	unsigned dwError;
} ;
#pragma pack(pop)

struct TInternetPrefetchStatus;
typedef TInternetPrefetchStatus *PInternetPrefetchStatus;

#pragma pack(push, 1)
struct TInternetPrefetchStatus
{
	unsigned dwStatus;
	unsigned dwSize;
} ;
#pragma pack(pop)

typedef INTERNET_PROXY_INFO *PInternetProxyInfo;

typedef INTERNET_PROXY_INFO  TInternetProxyInfo;

typedef INTERNET_VERSION_INFO *PInternetVersionInfo;

typedef INTERNET_VERSION_INFO  TInternetVersionInfo;

typedef HTTP_VERSION_INFO *PHttpVersionInfo;

typedef HTTP_VERSION_INFO  THttpVersionInfo;

typedef INTERNET_CONNECTED_INFO *PInternetConnectedInfo;

typedef INTERNET_CONNECTED_INFO  TInternetConnectedInfo;

typedef URL_COMPONENTS *PURLComponents;

typedef URL_COMPONENTS  TURLComponents;

typedef INTERNET_CERTIFICATE_INFO *PInternetCertificateInfo;

typedef INTERNET_CERTIFICATE_INFO  TInternetCertificateInfo;

typedef INTERNET_BUFFERSA *PInternetBuffersA;

typedef INTERNET_BUFFERSW *PInternetBuffersW;

typedef INTERNET_BUFFERSA *PInternetBuffers;

typedef INTERNET_BUFFERSA  TInternetBuffersA;

typedef INTERNET_BUFFERSW  TInternetBuffersW;

typedef INTERNET_BUFFERSA  INTERNET_BUFFERS;

typedef void *TFNInternetStatusCallback;

typedef void * *PFNInternetStatusCallback;

typedef GOPHER_FIND_DATAA *PGopherFindDataA;

typedef GOPHER_FIND_DATAW *PGopherFindDataW;

typedef GOPHER_FIND_DATAA *PGopherFindData;

typedef GOPHER_FIND_DATAA  GOPHER_FIND_DATA;

typedef GOPHER_FIND_DATAA  TGopherFindDataA;

typedef GOPHER_FIND_DATAW  TGopherFindDataW;

typedef GOPHER_FIND_DATAA  TGopherFindData;

typedef GOPHER_ADMIN_ATTRIBUTE_TYPE *PGopherAdminAttributeType;

typedef GOPHER_ADMIN_ATTRIBUTE_TYPE  TGopherAdminAttributeType;

typedef GOPHER_MOD_DATE_ATTRIBUTE_TYPE *PGopherModDateAttributeType;

typedef GOPHER_MOD_DATE_ATTRIBUTE_TYPE  TGopherModDateAttributeType;

typedef GOPHER_TTL_ATTRIBUTE_TYPE *PGopherTtlAttributeType;

typedef GOPHER_TTL_ATTRIBUTE_TYPE  TGopherTtlAttributeType;

typedef GOPHER_SCORE_ATTRIBUTE_TYPE *PGopherScoreAttributeType;

typedef GOPHER_SCORE_ATTRIBUTE_TYPE  TGopherScoreAttributeType;

typedef GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE *PGopherScoreRangeAttributeType;

typedef GOPHER_SCORE_RANGE_ATTRIBUTE_TYPE  TGopherScoreRangeAttributeType;

typedef GOPHER_SITE_ATTRIBUTE_TYPE *PGopherSiteAttributeType;

typedef GOPHER_SITE_ATTRIBUTE_TYPE  TGopherSiteAttributeType;

typedef GOPHER_ORGANIZATION_ATTRIBUTE_TYPE *PGopherOrganizationAttributeType;

typedef GOPHER_ORGANIZATION_ATTRIBUTE_TYPE  TGopherOrganizationAttributeType;

typedef GOPHER_LOCATION_ATTRIBUTE_TYPE *PGopherLocationAttributeType;

typedef GOPHER_LOCATION_ATTRIBUTE_TYPE  TGopherLocationAttributeType;

typedef GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE *PGopherGeographicalLocationAttributeType;

typedef GOPHER_GEOGRAPHICAL_LOCATION_ATTRIBUTE_TYPE  TGopherGeographicalLocationAttributeType;

typedef GOPHER_TIMEZONE_ATTRIBUTE_TYPE *PGopherTimezoneAttributeType;

typedef GOPHER_TIMEZONE_ATTRIBUTE_TYPE  TGopherTimezoneAttributeType;

typedef GOPHER_PROVIDER_ATTRIBUTE_TYPE *PGopherProviderAttributeType;

typedef GOPHER_PROVIDER_ATTRIBUTE_TYPE  TGopherProviderAttributeType;

typedef GOPHER_VERSION_ATTRIBUTE_TYPE *PGopherVersionAttributeType;

typedef GOPHER_VERSION_ATTRIBUTE_TYPE  TGopherVersionAttributeType;

typedef GOPHER_ABSTRACT_ATTRIBUTE_TYPE *PGopherAbstractAttributeType;

typedef GOPHER_ABSTRACT_ATTRIBUTE_TYPE  TGopherAbstractAttributeType;

typedef GOPHER_VIEW_ATTRIBUTE_TYPE *PGopherViewAttributeType;

typedef GOPHER_VIEW_ATTRIBUTE_TYPE  TGopherViewAttributeType;

typedef GOPHER_VERONICA_ATTRIBUTE_TYPE *PGopherVeronicaAttributeType;

typedef GOPHER_VERONICA_ATTRIBUTE_TYPE  TGopherVeronicaAttributeType;

typedef GOPHER_ASK_ATTRIBUTE_TYPE *PGopherAskAttributeType;

typedef GOPHER_ASK_ATTRIBUTE_TYPE  TGopherAskAttributeType;

typedef GOPHER_UNKNOWN_ATTRIBUTE_TYPE *PGopherUnknownAttributeType;

typedef GOPHER_UNKNOWN_ATTRIBUTE_TYPE  TGopherUnknownAttributeType;

typedef GOPHER_ATTRIBUTE_TYPE *PGopherAttributeType;

typedef GOPHER_ATTRIBUTE_TYPE  TGopherAttributeType;

typedef void *TFNGopherAttributeEnumerator;

typedef void * *PFNGopherAttributeEnumerator;

typedef INTERNET_CACHE_ENTRY_INFOA *PInternetCacheEntryInfoA;

typedef INTERNET_CACHE_ENTRY_INFOW *PInternetCacheEntryInfoW;

typedef INTERNET_CACHE_ENTRY_INFOA *PInternetCacheEntryInfo;

typedef INTERNET_CACHE_ENTRY_INFOA  TInternetCacheEntryInfoA;

typedef INTERNET_CACHE_ENTRY_INFOW  TInternetCacheEntryInfoW;

typedef INTERNET_CACHE_ENTRY_INFOA  TInternetCacheEntryInfo;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Wininet */
using namespace Wininet;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WinInet
