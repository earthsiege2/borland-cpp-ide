// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdThreadMgr.pas' rev: 6.00

#ifndef IdThreadMgrHPP
#define IdThreadMgrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SyncObjs.hpp>	// Pascal unit
#include <IdThread.hpp>	// Pascal unit
#include <IdBaseComponent.hpp>	// Pascal unit
#include <IdException.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idthreadmgr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdThreadMgr;
class PASCALIMPLEMENTATION TIdThreadMgr : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Classes::TList* FActiveThreads;
	Syncobjs::TCriticalSection* FLock;
	TMetaClass*FThreadClass;
	
public:
	__fastcall virtual TIdThreadMgr(Classes::TComponent* AOwner);
	virtual Idthread::TIdThread* __fastcall CreateNewThread(void);
	__fastcall virtual ~TIdThreadMgr(void);
	virtual Idthread::TIdThread* __fastcall GetThread(void) = 0 ;
	virtual void __fastcall ReleaseThread(Idthread::TIdThread* AThread) = 0 ;
	void __fastcall TerminateThreads(Classes::TList* Threads);
	__property Classes::TList* ActiveThreads = {read=FActiveThreads};
	__property Syncobjs::TCriticalSection* Lock = {read=FLock};
	__property TMetaClass* ThreadClass = {read=FThreadClass, write=FThreadClass};
};


class DELPHICLASS EIdThreadMgrError;
class PASCALIMPLEMENTATION EIdThreadMgrError : public Idexception::EIdException 
{
	typedef Idexception::EIdException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdThreadMgrError(const AnsiString Msg) : Idexception::EIdException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdThreadMgrError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Idexception::EIdException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdThreadMgrError(int Ident)/* overload */ : Idexception::EIdException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdThreadMgrError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Idexception::EIdException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdThreadMgrError(const AnsiString Msg, int AHelpContext) : Idexception::EIdException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdThreadMgrError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Idexception::EIdException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdThreadMgrError(int Ident, int AHelpContext)/* overload */ : Idexception::EIdException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdThreadMgrError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Idexception::EIdException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdThreadMgrError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIdThreadClassNotSpecified;
class PASCALIMPLEMENTATION EIdThreadClassNotSpecified : public EIdThreadMgrError 
{
	typedef EIdThreadMgrError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIdThreadClassNotSpecified(const AnsiString Msg) : EIdThreadMgrError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIdThreadClassNotSpecified(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EIdThreadMgrError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIdThreadClassNotSpecified(int Ident)/* overload */ : EIdThreadMgrError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIdThreadClassNotSpecified(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EIdThreadMgrError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIdThreadClassNotSpecified(const AnsiString Msg, int AHelpContext) : EIdThreadMgrError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIdThreadClassNotSpecified(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EIdThreadMgrError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIdThreadClassNotSpecified(int Ident, int AHelpContext)/* overload */ : EIdThreadMgrError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIdThreadClassNotSpecified(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EIdThreadMgrError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIdThreadClassNotSpecified(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idthreadmgr */
using namespace Idthreadmgr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdThreadMgr
