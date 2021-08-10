// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Imagehlp.pas' rev: 5.00

#ifndef ImagehlpHPP
#define ImagehlpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <imagehlp.h>

namespace Imagehlp
{
//-- type declarations -------------------------------------------------------
typedef _IMAGEHLP_STATUS_REASON TImagehlpStatusReason;

typedef BOOL __stdcall (*TImagehlpStatusRoutine)(_IMAGEHLP_STATUS_REASON Reason, char * ImageName, char * 
	DllName, unsigned Va, unsigned Parameter);

typedef _LOADED_IMAGE *PloadedImage;

typedef _LOADED_IMAGE  LoadedImage;

typedef _IMAGE_DEBUG_INFORMATION *PimageDebugInformation;

typedef _IMAGE_DEBUG_INFORMATION  TImageDebugInformation;

typedef ADDRESS_MODE TAddressMode;

typedef _tagADDRESS *PAddress;

typedef _tagADDRESS  TAddress;

typedef _KDHELP *PKdHelp;

typedef _KDHELP  TKdHelp;

typedef _tagSTACKFRAME *PStackFrame;

typedef _tagSTACKFRAME  TStackFrame;

typedef BOOL __stdcall (*TReadProcessMemoryRoutine)(unsigned hProcess, void * lpBaseAddress, void * 
	lpBuffer, unsigned nSize, unsigned &lpNumberOfBytesRead);

typedef void * __stdcall (*TFunctionTableAccessRoutine)(unsigned hProcess, unsigned AddrBase);

typedef unsigned __stdcall (*TGetModuleBaseRoutine)(unsigned hProcess, unsigned ReturnAddress);

typedef unsigned __stdcall (*TTranslateAddressRoutine)(unsigned hProcess, unsigned hThread, PAddress 
	lpaddr);

typedef API_VERSION *PApiVersion;

typedef API_VERSION  TApiVersion;

typedef BOOL __stdcall (*TSymEnummodulesCallback)(char * ModuleName, unsigned BaseOfDll, void * UserContext
	);

typedef BOOL __stdcall (*TSymEnumsymbolsCallback)(char * SymbolName, unsigned SymbolAddress, unsigned 
	SymbolSize, void * UserContext);

typedef BOOL __stdcall (*TEnumloadedModulesCallback)(char * ModuleName, unsigned ModuleBase, unsigned 
	ModuleSize, void * UserContext);

typedef BOOL __stdcall (*TSymbolRegisteredCallback)(unsigned hProcess, unsigned ActionCode, void * CallbackData
	, void * UserContext);

typedef SYM_TYPE TSymType;

typedef _IMAGEHLP_SYMBOL *PImagehlpSymbol;

typedef _IMAGEHLP_SYMBOL  TImagehlpSymbol;

typedef _IMAGEHLP_MODULE *PImagehlpModule;

typedef _IMAGEHLP_MODULE  TImagehlpModule;

typedef _IMAGEHLP_DEFERRED_SYMBOL_LOAD *PImagehlpDeferredSymbolLoad;

typedef _IMAGEHLP_DEFERRED_SYMBOL_LOAD  TImagehlpDeferredSymbolLoad;

typedef _IMAGEHLP_DUPLICATE_SYMBOL *PImagehlpDuplicateSymbol;

typedef _IMAGEHLP_DUPLICATE_SYMBOL  TImagehlpDuplicateSymbol;

typedef void *TDigestHandle;

typedef BOOL __stdcall (*TDigestFunction)(void * refdata, Windows::PByte pData, unsigned dwLength);

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Imagehlp */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imagehlp;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Imagehlp
