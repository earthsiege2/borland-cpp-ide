// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Isapi.pas' rev: 6.00

#ifndef IsapiHPP
#define IsapiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <httpext.h>

namespace Isapi
{
//-- type declarations -------------------------------------------------------
typedef HSE_VERSION_INFO *PHSE_VERSION_INFO;

typedef HSE_VERSION_INFO  THSE_VERSION_INFO;

typedef BOOL __stdcall (*TGetServerVariableProc)(unsigned hConn, char * VariableName, void * Buffer, unsigned &Size);

typedef BOOL __stdcall (*TWriteClientProc)(unsigned ConnID, void * Buffer, unsigned &Bytes, unsigned dwReserved);

typedef BOOL __stdcall (*TReadClientProc)(unsigned ConnID, void * Buffer, unsigned &Size);

typedef BOOL __stdcall (*TServerSupportFunctionProc)(unsigned hConn, unsigned HSERRequest, void * Buffer, unsigned &Size, unsigned &DataType);

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

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Isapi */
using namespace Isapi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Isapi
