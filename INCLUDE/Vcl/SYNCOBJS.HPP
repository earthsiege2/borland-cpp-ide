// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SyncObjs.pas' rev: 5.00

#ifndef SyncObjsHPP
#define SyncObjsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Syncobjs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSynchroObject;
class PASCALIMPLEMENTATION TSynchroObject : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall Acquire(void);
	virtual void __fastcall Release(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSynchroObject(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSynchroObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS THandleObject;
class PASCALIMPLEMENTATION THandleObject : public TSynchroObject 
{
	typedef TSynchroObject inherited;
	
private:
	unsigned FHandle;
	int FLastError;
	
public:
	__fastcall virtual ~THandleObject(void);
	__property int LastError = {read=FLastError, nodefault};
	__property unsigned Handle = {read=FHandle, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall THandleObject(void) : TSynchroObject() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TWaitResult { wrSignaled, wrTimeout, wrAbandoned, wrError };
#pragma option pop

class DELPHICLASS TEvent;
class PASCALIMPLEMENTATION TEvent : public THandleObject 
{
	typedef THandleObject inherited;
	
public:
	__fastcall TEvent(Windows::PSecurityAttributes EventAttributes, bool ManualReset, bool InitialState
		, const AnsiString Name);
	TWaitResult __fastcall WaitFor(unsigned Timeout);
	void __fastcall SetEvent(void);
	void __fastcall ResetEvent(void);
public:
	#pragma option push -w-inl
	/* THandleObject.Destroy */ inline __fastcall virtual ~TEvent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSimpleEvent;
class PASCALIMPLEMENTATION TSimpleEvent : public TEvent 
{
	typedef TEvent inherited;
	
public:
	__fastcall TSimpleEvent(void);
public:
	#pragma option push -w-inl
	/* THandleObject.Destroy */ inline __fastcall virtual ~TSimpleEvent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCriticalSection;
class PASCALIMPLEMENTATION TCriticalSection : public TSynchroObject 
{
	typedef TSynchroObject inherited;
	
private:
	_RTL_CRITICAL_SECTION FSection;
	
public:
	__fastcall TCriticalSection(void);
	__fastcall virtual ~TCriticalSection(void);
	virtual void __fastcall Acquire(void);
	virtual void __fastcall Release(void);
	void __fastcall Enter(void);
	void __fastcall Leave(void);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Syncobjs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Syncobjs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SyncObjs
