// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Isapi2.pas' rev: 6.00

#ifndef Isapi2HPP
#define Isapi2HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <httpfilt.h>

namespace Isapi2
{
//-- type declarations -------------------------------------------------------
struct HSE_VERSION_INFO;
typedef HSE_VERSION_INFO *PHSE_VERSION_INFO;

#pragma pack(push, 1)
struct HSE_VERSION_INFO
{
	unsigned dwExtensionVersion;
	char lpszExtensionDesc[256];
} ;
#pragma pack(pop)

typedef HSE_VERSION_INFO  THSE_VERSION_INFO;

typedef BOOL __stdcall (*TGetServerVariableProc)(unsigned hConn, char * VariableName, void * Buffer, unsigned &Size);

typedef BOOL __stdcall (*TWriteClientProc)(unsigned ConnID, void * Buffer, unsigned &Bytes, unsigned dwReserved);

typedef BOOL __stdcall (*TReadClientProc)(unsigned ConnID, void * Buffer, unsigned &Size);

typedef BOOL __stdcall (*TServerSupportFunctionProc)(unsigned hConn, unsigned HSERRequest, void * Buffer, PDWORD Size, PDWORD DataType);

struct TEXTENSION_CONTROL_BLOCK;
typedef TEXTENSION_CONTROL_BLOCK *PEXTENSION_CONTROL_BLOCK;

#pragma pack(push, 1)
struct TEXTENSION_CONTROL_BLOCK
{
	unsigned cbSize;
	unsigned dwVersion;
	unsigned ConnID;
	unsigned dwHttpStatusCode;
	char lpszLogData[80];
	char *lpszMethod;
	char *lpszQueryString;
	char *lpszPathInfo;
	char *lpszPathTranslated;
	unsigned cbTotalBytes;
	unsigned cbAvailable;
	void *lpbData;
	char *lpszContentType;
	TGetServerVariableProc GetServerVariable;
	TWriteClientProc WriteClient;
	TReadClientProc ReadClient;
	TServerSupportFunctionProc ServerSupportFunction;
} ;
#pragma pack(pop)

typedef BOOL __stdcall (*TGetExtensionVersion)(HSE_VERSION_INFO &Ver);

typedef unsigned __stdcall (*THttpExtensionProc)(TEXTENSION_CONTROL_BLOCK &ECB);

typedef BOOL __stdcall (*TTerminateExtension)(unsigned dwFlags);

typedef void __stdcall (*THseIoCompletion)(TEXTENSION_CONTROL_BLOCK &ECB, void * pContext, unsigned cbIO, unsigned dwError);

struct THSE_TF_INFO;
typedef THSE_TF_INFO *PHSE_TF_INFO;

#pragma pack(push, 4)
struct THSE_TF_INFO
{
	THseIoCompletion pfnHseIO;
	void *pContext;
	unsigned hFile;
	char *pszStatusCode;
	unsigned BytesToWrite;
	unsigned Offset;
	void *pHead;
	unsigned HeadLength;
	void *pTail;
	unsigned TailLength;
	unsigned dwFlags;
} ;
#pragma pack(pop)

typedef BOOL __stdcall (*TFilterGetServerVariableProc)(void *pfc, char * VariableName, void * Buffer, unsigned &Size);

typedef BOOL __stdcall (*TFilterAddResponseHeadersProc)(void *pfc, char * lpszHeaders, unsigned dwReserved);

typedef BOOL __stdcall (*TFilterWriteClientProc)(void *pfc, void * Buffer, unsigned &Bytes, unsigned dwReserved);

typedef void * __stdcall (*TFilterAllocMemProc)(void *pfc, unsigned cbSize, unsigned dwReserved);

typedef BOOL __stdcall (*TFilterServerSupportFunctionProc)(void *pfc, unsigned sfReq, void * pData, unsigned ul1, unsigned ul2);

struct THTTP_FILTER_CONTEXT;
typedef THTTP_FILTER_CONTEXT *PHTTP_FILTER_CONTEXT;

#pragma pack(push, 4)
struct THTTP_FILTER_CONTEXT
{
	unsigned cbSize;
	unsigned Revision;
	void *ServerContext;
	unsigned ulReserved;
	BOOL fIsSecurePort;
	void *pFilterContext;
	TFilterGetServerVariableProc GetServerVariable;
	TFilterAddResponseHeadersProc AddResponseHeaders;
	TFilterWriteClientProc WriteClient;
	TFilterAllocMemProc AllocMem;
	TFilterServerSupportFunctionProc ServerSupportFunction;
} ;
#pragma pack(pop)

typedef HTTP_FILTER_RAW_DATA *PHTTP_FILTER_RAW_DATA;

typedef HTTP_FILTER_RAW_DATA  THTTP_FILTER_RAW_DATA;

typedef BOOL __stdcall (*TGetHeaderProc)(THTTP_FILTER_CONTEXT &pfc, char * lpszName, void *lpvBuffer, unsigned &lpdwSize);

typedef BOOL __stdcall (*TSetHeaderProc)(THTTP_FILTER_CONTEXT &pfc, char * lpszName, char * lpszValue);

typedef BOOL __stdcall (*TAddHeaderProc)(THTTP_FILTER_CONTEXT &pfc, char * lpszName, char * lpszValue);

struct THTTP_FILTER_PREPROC_HEADERS;
typedef THTTP_FILTER_PREPROC_HEADERS *PHTTP_FILTER_PREPROC_HEADERS;

#pragma pack(push, 4)
struct THTTP_FILTER_PREPROC_HEADERS
{
	TGetHeaderProc GetHeader;
	TSetHeaderProc SetHeader;
	TAddHeaderProc AddHeader;
	unsigned dwReserved;
} ;
#pragma pack(pop)

typedef HTTP_FILTER_AUTHENT *PHTTP_FILTER_AUTHENT;

typedef HTTP_FILTER_AUTHENT  THTTP_FILTER_AUTHENT;

typedef HTTP_FILTER_URL_MAP *PHTTP_FILTER_URL_MAP;

typedef HTTP_FILTER_URL_MAP  THTTP_FILTER_URL_MAP;

typedef HTTP_FILTER_ACCESS_DENIED *PHTTP_FILTER_ACCESS_DENIED;

typedef HTTP_FILTER_ACCESS_DENIED  THTTP_FILTER_ACCESS_DENIED;

typedef HTTP_FILTER_LOG *PHTTP_FILTER_LOG;

typedef HTTP_FILTER_LOG  THTTP_FILTER_LOG;

typedef HTTP_FILTER_VERSION *PHTTP_FILTER_VERSION;

typedef HTTP_FILTER_VERSION  THTTP_FILTER_VERSION;

typedef unsigned __stdcall (*THttpFilterProc)(THTTP_FILTER_CONTEXT &pfc, unsigned Notificationtype, void * pvNotification);

typedef BOOL __stdcall (*TGetFilterVersion)(HTTP_FILTER_VERSION &pVer);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Isapi2 */
using namespace Isapi2;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Isapi2
