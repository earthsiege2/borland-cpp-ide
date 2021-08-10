// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ISAPIThreadPool.pas' rev: 6.00

#ifndef ISAPIThreadPoolHPP
#define ISAPIThreadPoolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <Isapi2.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Isapithreadpool
{
//-- type declarations -------------------------------------------------------
typedef TMetaClass*TISAPIThreadPoolClass;

typedef DynamicArray<unsigned >  ISAPIThreadPool__2;

class DELPHICLASS TISAPIThreadPool;
class DELPHICLASS TISAPIThread;
class PASCALIMPLEMENTATION TISAPIThreadPool : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FInitialized;
	DynamicArray<unsigned >  FThreads;
	unsigned FRequestQueue;
	bool FInitCOM;
	int FMin;
	int FMax;
	int __fastcall GetThreadCount(void);
	void __fastcall SetMax(const int Value);
	void __fastcall SetMin(const int Value);
	void __fastcall SetInitCOM(const bool Value);
	
protected:
	virtual void __fastcall Initialize(void);
	bool __fastcall PushBack(Isapi2::PEXTENSION_CONTROL_BLOCK ECB);
	virtual void __fastcall ShutDown(void);
	__property unsigned RequestQueue = {read=FRequestQueue, nodefault};
	
public:
	__fastcall virtual TISAPIThreadPool(bool InitCOM);
	__fastcall virtual ~TISAPIThreadPool(void);
	__property bool InitCOM = {read=FInitCOM, write=SetInitCOM, nodefault};
	bool __fastcall DispatchThread(Isapi2::PEXTENSION_CONTROL_BLOCK AECB);
	bool __fastcall RemoveThread(TISAPIThread* AISAPIThread);
	__property int Min = {read=FMin, write=SetMin, default=1};
	__property int Max = {read=FMax, write=SetMax, default=32};
	__property int ThreadCount = {read=GetThreadCount, nodefault};
};


class PASCALIMPLEMENTATION TISAPIThread : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	unsigned FHandle;
	unsigned FThreadID;
	bool FSuspended;
	bool FTerminated;
	Isapi2::TEXTENSION_CONTROL_BLOCK *FECB;
	TISAPIThreadPool* FISAPIThreadPool;
	
public:
	__fastcall TISAPIThread(TISAPIThreadPool* AISAPIThreadPool);
	__fastcall virtual ~TISAPIThread(void);
	void __fastcall Execute(void);
	void __fastcall Suspend(void);
	void __fastcall Resume(void);
	__property bool Suspended = {read=FSuspended, nodefault};
	__property bool Terminated = {read=FTerminated, write=FTerminated, nodefault};
	__property Isapi2::PEXTENSION_CONTROL_BLOCK ECB = {read=FECB, write=FECB};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Byte NumberOfThreads;
extern PACKAGE TMetaClass*ThreadPoolClass;
extern PACKAGE BOOL __stdcall GetExtensionVersion(Isapi2::HSE_VERSION_INFO &Ver);
extern PACKAGE unsigned __stdcall HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB);
extern PACKAGE BOOL __stdcall TerminateExtension(unsigned dwFlags);

}	/* namespace Isapithreadpool */
using namespace Isapithreadpool;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ISAPIThreadPool
