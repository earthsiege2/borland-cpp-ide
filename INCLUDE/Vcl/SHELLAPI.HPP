// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ShellAPI.pas' rev: 6.00

#ifndef ShellAPIHPP
#define ShellAPIHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <shellapi.h>

namespace Shellapi
{
//-- type declarations -------------------------------------------------------
typedef wchar_t * *PPWideChar;

struct _DRAGINFOA;
typedef _DRAGINFOA *PDragInfoA;

struct _DRAGINFOW;
typedef _DRAGINFOW *PDragInfoW;

typedef _DRAGINFOA *PDragInfo;

#pragma pack(push, 4)
struct _DRAGINFOA
{
	unsigned uSize;
	Types::TPoint pt;
	BOOL fNC;
	char *lpFileList;
	unsigned grfKeyState;
} ;
#pragma pack(pop)

typedef _DRAGINFOA  TDragInfoA;

typedef _DRAGINFOA *LPDRAGINFOA;

#pragma pack(push, 4)
struct _DRAGINFOW
{
	unsigned uSize;
	Types::TPoint pt;
	BOOL fNC;
	wchar_t *lpFileList;
	unsigned grfKeyState;
} ;
#pragma pack(pop)

typedef _DRAGINFOW  TDragInfoW;

typedef _DRAGINFOW *LPDRAGINFOW;

typedef _DRAGINFOA  _DRAGINFO;

typedef _AppBarData *PAppBarData;

typedef _AppBarData  TAppBarData;

typedef _SHFILEOPSTRUCTA *PSHFileOpStructA;

typedef _SHFILEOPSTRUCTW *PSHFileOpStructW;

typedef _SHFILEOPSTRUCTA *PSHFileOpStruct;

typedef _SHFILEOPSTRUCTA  TSHFileOpStructA;

typedef _SHFILEOPSTRUCTW  TSHFileOpStructW;

typedef _SHFILEOPSTRUCTA  TSHFileOpStruct;

typedef _SHNAMEMAPPINGA *PSHNameMappingA;

typedef _SHNAMEMAPPINGW *PSHNameMappingW;

typedef _SHNAMEMAPPINGA *PSHNameMapping;

typedef _SHNAMEMAPPINGA  TSHNameMappingA;

typedef _SHNAMEMAPPINGW  TSHNameMappingW;

typedef _SHNAMEMAPPINGA  TSHNameMapping;

typedef _SHELLEXECUTEINFOA *PShellExecuteInfoA;

typedef _SHELLEXECUTEINFOW *PShellExecuteInfoW;

typedef _SHELLEXECUTEINFOA *PShellExecuteInfo;

typedef _SHELLEXECUTEINFOA  TShellExecuteInfoA;

typedef _SHELLEXECUTEINFOW  TShellExecuteInfoW;

typedef _SHELLEXECUTEINFOA  TShellExecuteInfo;

typedef _NOTIFYICONDATAA *PNotifyIconDataA;

typedef _NOTIFYICONDATAW *PNotifyIconDataW;

typedef _NOTIFYICONDATAA *PNotifyIconData;

typedef _NOTIFYICONDATAA  TNotifyIconDataA;

typedef _NOTIFYICONDATAW  TNotifyIconDataW;

typedef _NOTIFYICONDATAA  TNotifyIconData;

typedef _SHFILEINFOA *PSHFileInfoA;

typedef _SHFILEINFOW *PSHFileInfoW;

typedef _SHFILEINFOA *PSHFileInfo;

typedef _SHFILEINFOA  TSHFileInfoA;

typedef _SHFILEINFOW  TSHFileInfoW;

typedef _SHFILEINFOA  TSHFileInfo;

//-- var, const, procedure ---------------------------------------------------
#define shell32 "shell32.dll"

}	/* namespace Shellapi */
using namespace Shellapi;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ShellAPI
