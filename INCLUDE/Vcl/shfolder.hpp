// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SHFolder.pas' rev: 6.00

#ifndef SHFolderHPP
#define SHFolderHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <shfolder.h>

namespace Shfolder
{
//-- type declarations -------------------------------------------------------
typedef HRESULT __stdcall (*PFNSHGETFOLDERPATH)(HWND hwnd, int csidl, unsigned hToken, unsigned dwFlags, char * pszPath);

typedef HRESULT __stdcall (*TSHGetFolderPathA)(HWND hwnd, int csidl, unsigned hToken, unsigned dwFlags, char * pszPath);

typedef HRESULT __stdcall (*TSHGetFolderPathW)(HWND hwnd, int csidl, unsigned hToken, unsigned dwFlags, char * pszPath);

typedef HRESULT __stdcall (*TSHGetFolderPath)(HWND hwnd, int csidl, unsigned hToken, unsigned dwFlags, char * pszPath);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Shfolder */
using namespace Shfolder;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SHFolder
