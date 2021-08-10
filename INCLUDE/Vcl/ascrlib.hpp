// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AscrLib.pas' rev: 6.00

#ifndef AscrLibHPP
#define AscrLibHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StdVCL.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ascrlib
{
//-- type declarations -------------------------------------------------------
typedef Activex::TOleEnum tagSCRIPTSTATE;

typedef Activex::TOleEnum tagSCRIPTTHREADSTATE;

typedef Activex::TOleEnum tagSCRIPTINFO;

typedef Activex::TOleEnum tagSCRIPTITEM;

typedef HWND wireHWND;

__interface IActiveScript;
typedef System::DelphiInterface<IActiveScript> _di_IActiveScript;
__interface IActiveScriptSite;
typedef System::DelphiInterface<IActiveScriptSite> _di_IActiveScriptSite;
__interface INTERFACE_UUID("{BB1A2AE1-A4F9-11CF-8F20-00805F2CD064}") IActiveScript  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall SetScriptSite(const _di_IActiveScriptSite pass) = 0 ;
	virtual HRESULT __stdcall GetScriptSite(GUID &riid, /* out */ void * &ppvObject) = 0 ;
	virtual HRESULT __stdcall SetScriptState(Activex::TOleEnum ss) = 0 ;
	virtual HRESULT __stdcall GetScriptState(/* out */ Activex::TOleEnum &pssState) = 0 ;
	virtual HRESULT __stdcall Close(void) = 0 ;
	virtual HRESULT __stdcall AddNamedItem(wchar_t * pstrName, unsigned dwFlags) = 0 ;
	virtual HRESULT __stdcall AddTypeLib(GUID &rguidTypeLib, unsigned dwMajor, unsigned dwMinor, unsigned dwFlags) = 0 ;
	virtual HRESULT __stdcall GetScriptDispatch(wchar_t * pstrItemName, /* out */ _di_IDispatch &ppdisp) = 0 ;
	virtual HRESULT __stdcall GetCurrentScriptThreadID(/* out */ unsigned &pstidThread) = 0 ;
	virtual HRESULT __stdcall GetScriptThreadID(unsigned dwWin32ThreadId, /* out */ unsigned &pstidThread) = 0 ;
	virtual HRESULT __stdcall GetScriptThreadState(unsigned stidThread, /* out */ Activex::TOleEnum &pstsState) = 0 ;
	virtual HRESULT __stdcall InterruptScriptThread(unsigned stidThread, tagEXCEPINFO &pexcepinfo, unsigned dwFlags) = 0 ;
	virtual HRESULT __stdcall Clone(/* out */ _di_IActiveScript &ppscript) = 0 ;
};

__interface IActiveScriptError;
typedef System::DelphiInterface<IActiveScriptError> _di_IActiveScriptError;
__interface INTERFACE_UUID("{DB01A1E3-A42B-11CF-8F20-00805F2CD064}") IActiveScriptSite  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetLCID(/* out */ unsigned &plcid) = 0 ;
	virtual HRESULT __stdcall GetItemInfo(wchar_t * pstrName, unsigned dwReturnMask, /* out */ System::_di_IInterface &ppiunkItem, /* out */ System::_di_IInterface &ppti) = 0 ;
	virtual HRESULT __stdcall GetDocVersionString(/* out */ WideString &pbstrVersion) = 0 ;
	virtual HRESULT __stdcall OnScriptTerminate(OleVariant &pvarResult, tagEXCEPINFO &pexcepinfo) = 0 ;
	virtual HRESULT __stdcall OnStateChange(Activex::TOleEnum ssScriptState) = 0 ;
	virtual HRESULT __stdcall OnScriptError(const _di_IActiveScriptError pscripterror) = 0 ;
	virtual HRESULT __stdcall OnEnterScript(void) = 0 ;
	virtual HRESULT __stdcall OnLeaveScript(void) = 0 ;
};

__interface INTERFACE_UUID("{EAE1BA61-A4ED-11CF-8F20-00805F2CD064}") IActiveScriptError  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetExceptionInfo(/* out */ tagEXCEPINFO &pexcepinfo) = 0 ;
	virtual HRESULT __stdcall GetSourcePosition(/* out */ unsigned &pdwSourceContext, /* out */ unsigned &pulLineNumber, /* out */ int &plCharacterPosition) = 0 ;
	virtual HRESULT __stdcall GetSourceLineText(/* out */ WideString &pbstrSourceLine) = 0 ;
};

__interface IActiveScriptParse;
typedef System::DelphiInterface<IActiveScriptParse> _di_IActiveScriptParse;
__interface INTERFACE_UUID("{BB1A2AE2-A4F9-11CF-8F20-00805F2CD064}") IActiveScriptParse  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall InitNew(void) = 0 ;
	virtual HRESULT __stdcall AddScriptlet(wchar_t * pstrDefaultName, wchar_t * pstrCode, wchar_t * pstrItemName, wchar_t * pstrSubItemName, wchar_t * pstrEventName, wchar_t * pstrDelimiter, unsigned dwSourceContextCookie, unsigned ulStartingLineNumber, unsigned dwFlags, /* out */ WideString &pBstrName, /* out */ GUID &pexcepinfo) = 0 ;
	virtual HRESULT __stdcall ParseScriptText(wchar_t * pstrCode, wchar_t * pstrItemName, const System::_di_IInterface punkContext, wchar_t * pstrDelimiter, unsigned dwSourceContextCookie, unsigned ulStartingLineNumber, unsigned dwFlags, void * pvarResult, /* out */ tagEXCEPINFO &pexcepinfo) = 0 ;
};

__interface IActiveScriptSiteWindow;
typedef System::DelphiInterface<IActiveScriptSiteWindow> _di_IActiveScriptSiteWindow;
__interface INTERFACE_UUID("{D10F6761-83E9-11CF-8F20-00805F2CD064}") IActiveScriptSiteWindow  : public IInterface 
{
	
public:
	virtual HRESULT __stdcall GetWindow(/* out */ HWND &phwnd) = 0 ;
	virtual HRESULT __stdcall EnableModeless(int fEnable) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint ActiveScriptLibMajorVersion = 0x1;
static const Shortint ActiveScriptLibMinorVersion = 0x0;
extern PACKAGE GUID LIBID_ActiveScriptLib;
extern PACKAGE GUID IID_IActiveScript;
extern PACKAGE GUID IID_IActiveScriptSite;
extern PACKAGE GUID IID_IActiveScriptError;
extern PACKAGE GUID IID_IActiveScriptParse;
extern PACKAGE GUID IID_IActiveScriptSiteWindow;
static const Shortint SCRIPTSTATE_UNINITIALIZED = 0x0;
static const Shortint SCRIPTSTATE_INITIALIZED = 0x5;
static const Shortint SCRIPTSTATE_STARTED = 0x1;
static const Shortint SCRIPTSTATE_CONNECTED = 0x2;
static const Shortint SCRIPTSTATE_DISCONNECTED = 0x3;
static const Shortint SCRIPTSTATE_CLOSED = 0x4;
static const Shortint SCRIPTTHREADSTATE_NOTINSCRIPT = 0x0;
static const Shortint SCRIPTTHREADSTATE_RUNNING = 0x1;
static const Shortint SCRIPTINFO_IUNKNOWN = 0x1;
static const Shortint SCRIPTINFO_ITYPEINFO = 0x2;
static const Shortint SCRIPTITEM_ISVISIBLE = 0x2;
static const Shortint SCRIPTITEM_ISSOURCE = 0x4;
static const Shortint SCRIPTITEM_GLOBALMEMBERS = 0x8;
static const Shortint SCRIPTITEM_ISPERSISTENT = 0x40;
static const Word SCRIPTITEM_CODEONLY = 0x200;
static const Word SCRIPTITEM_NOCODE = 0x400;

}	/* namespace Ascrlib */
using namespace Ascrlib;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AscrLib
