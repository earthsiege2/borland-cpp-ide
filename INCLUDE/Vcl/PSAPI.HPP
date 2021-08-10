// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Psapi.pas' rev: 5.00

#ifndef PsapiHPP
#define PsapiHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <psapi.h>

namespace Psapi
{
//-- type declarations -------------------------------------------------------
typedef void * *PPointer;

typedef BOOL __stdcall (*TEnumProcesses)(PDWORD lpidProcess, unsigned cb, unsigned &cbNeeded);

typedef BOOL __stdcall (*TEnumProcessModules)(unsigned hProcess, PDWORD lphModule, unsigned cb, unsigned 
	&lpcbNeeded);

typedef unsigned __stdcall (*TGetModuleBaseNameA)(unsigned hProcess, Windows::HINST hModule, char * 
	lpBaseName, unsigned nSize);

typedef unsigned __stdcall (*TGetModuleBaseNameW)(unsigned hProcess, Windows::HINST hModule, wchar_t * 
	lpBaseName, unsigned nSize);

typedef unsigned __stdcall (*TGetModuleBaseName)(unsigned hProcess, Windows::HINST hModule, char * lpBaseName
	, unsigned nSize);

typedef unsigned __stdcall (*TGetModuleFileNameExA)(unsigned hProcess, Windows::HINST hModule, char * 
	lpFilename, unsigned nSize);

typedef unsigned __stdcall (*TGetModuleFileNameExW)(unsigned hProcess, Windows::HINST hModule, wchar_t * 
	lpFilename, unsigned nSize);

typedef unsigned __stdcall (*TGetModuleFileNameEx)(unsigned hProcess, Windows::HINST hModule, char * 
	lpFilename, unsigned nSize);

typedef _MODULEINFO  TModuleInfo;

typedef _MODULEINFO *PModuleInfo;

typedef BOOL __stdcall (*TGetModuleInformation)(unsigned hProcess, Windows::HINST hModule, LPMODULEINFO 
	lpmodinfo, unsigned cb);

typedef BOOL __stdcall (*TEmptyWorkingSet)(unsigned hProcess);

typedef BOOL __stdcall (*TQueryWorkingSet)(unsigned hProcess, void * pv, unsigned cb);

typedef BOOL __stdcall (*TInitializeProcessForWsWatch)(unsigned hProcess);

typedef _PSAPI_WS_WATCH_INFORMATION  TPSAPIWsWatchInformation;

typedef _PSAPI_WS_WATCH_INFORMATION *PPSAPIWsWatchInformation;

typedef BOOL __stdcall (*TGetWsChanges)(unsigned hProcess, PPSAPI_WS_WATCH_INFORMATION lpWatchInfo, 
	unsigned cb);

typedef unsigned __stdcall (*TGetMappedFileNameA)(unsigned hProcess, void * lpv, char * lpFilename, 
	unsigned nSize);

typedef unsigned __stdcall (*TGetMappedFileNameW)(unsigned hProcess, void * lpv, wchar_t * lpFilename
	, unsigned nSize);

typedef unsigned __stdcall (*TGetMappedFileName)(unsigned hProcess, void * lpv, char * lpFilename, unsigned 
	nSize);

typedef unsigned __stdcall (*TGetDeviceDriverBaseNameA)(void * ImageBase, char * lpBaseName, unsigned 
	nSize);

typedef unsigned __stdcall (*TGetDeviceDriverBaseNameW)(void * ImageBase, wchar_t * lpBaseName, unsigned 
	nSize);

typedef unsigned __stdcall (*TGetDeviceDriverBaseName)(void * ImageBase, char * lpBaseName, unsigned 
	nSize);

typedef unsigned __stdcall (*TGetDeviceDriverFileNameA)(void * ImageBase, char * lpFileName, unsigned 
	nSize);

typedef unsigned __stdcall (*TGetDeviceDriverFileNameW)(void * ImageBase, wchar_t * lpFileName, unsigned 
	nSize);

typedef unsigned __stdcall (*TGetDeviceDriverFileName)(void * ImageBase, char * lpFileName, unsigned 
	nSize);

typedef BOOL __stdcall (*TEnumDeviceDrivers)(PPointer lpImageBase, unsigned cb, unsigned &lpcbNeeded
	);

typedef _PROCESS_MEMORY_COUNTERS  TProcessMemoryCounters;

typedef _PROCESS_MEMORY_COUNTERS *PProcessMemoryCounters;

typedef BOOL __stdcall (*TGetProcessMemoryInfo)(unsigned Process, PPROCESS_MEMORY_COUNTERS ppsmemCounters
	, unsigned cb);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Psapi */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Psapi;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Psapi
