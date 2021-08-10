// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ComObj.pas' rev: 5.00

#ifndef ComObjHPP
#define ComObjHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Comobj
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TComServerObject;
class PASCALIMPLEMENTATION TComServerObject : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual int __fastcall CountObject(bool Created) = 0 ;
	virtual int __fastcall CountFactory(bool Created) = 0 ;
	virtual AnsiString __fastcall GetHelpFileName(void) = 0 ;
	virtual AnsiString __fastcall GetServerFileName(void) = 0 ;
	virtual AnsiString __fastcall GetServerKey(void) = 0 ;
	virtual AnsiString __fastcall GetServerName(void) = 0 ;
	virtual bool __fastcall GetStartSuspended(void) = 0 ;
	virtual _di_ITypeLib __fastcall GetTypeLib(void) = 0 ;
	virtual void __fastcall SetHelpFileName(const AnsiString Value) = 0 ;
	
public:
	__property AnsiString HelpFileName = {read=GetHelpFileName, write=SetHelpFileName};
	__property AnsiString ServerFileName = {read=GetServerFileName};
	__property AnsiString ServerKey = {read=GetServerKey};
	__property AnsiString ServerName = {read=GetServerName};
	__property _di_ITypeLib TypeLib = {read=GetTypeLib};
	__property bool StartSuspended = {read=GetStartSuspended, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TComServerObject(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TComServerObject(void) { }
	#pragma option pop
	
};


__interface IServerExceptionHandler;
typedef System::DelphiInterface<IServerExceptionHandler> _di_IServerExceptionHandler;
__interface INTERFACE_UUID("{6A8D432B-EB81-11D1-AAB1-00C04FB16FBC}") IServerExceptionHandler  : public IUnknown 
	
{
	
public:
	virtual void __fastcall OnException(const WideString ServerClass, const WideString ExceptionClass, 
		const WideString ErrorMessage, int ExceptAddr, const WideString ErrorIID, const WideString ProgID, 
		int &Handled, HRESULT &Result) = 0 ;
};

#pragma option push -b-
enum TClassInstancing { ciInternal, ciSingleInstance, ciMultiInstance };
#pragma option pop

#pragma option push -b-
enum TThreadingModel { tmSingle, tmApartment, tmFree, tmBoth };
#pragma option pop

class DELPHICLASS TAggregatedObject;
class PASCALIMPLEMENTATION TAggregatedObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FController;
	_di_IUnknown __fastcall GetController();
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	
public:
	__fastcall TAggregatedObject(_di_IUnknown Controller);
	__property _di_IUnknown Controller = {read=GetController};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAggregatedObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TContainedObject;
class PASCALIMPLEMENTATION TContainedObject : public TAggregatedObject 
{
	typedef TAggregatedObject inherited;
	
protected:
	HIDESBASE virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
public:
	#pragma option push -w-inl
	/* TAggregatedObject.Create */ inline __fastcall TContainedObject(_di_IUnknown Controller) : TAggregatedObject(
		Controller) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TContainedObject(void) { }
	#pragma option pop
	
private:
	void *__IUnknown;	/* IUnknown */
	
public:
	operator IUnknown*(void) { return (IUnknown*)&__IUnknown; }
	
};


class DELPHICLASS TAutoIntfObject;
class PASCALIMPLEMENTATION TAutoIntfObject : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_ITypeInfo FDispTypeInfo;
	System::TInterfaceEntry *FDispIntfEntry;
	#pragma pack(push, 1)
	GUID FDispIID;
	#pragma pack(pop)
	
	
protected:
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * 
		DispIDs);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * 
		VarResult, void * ExcepInfo, void * ArgErr);
	HRESULT __stdcall InterfaceSupportsErrorInfo(const GUID &iid);
	
public:
	__fastcall TAutoIntfObject(const _di_ITypeLib TypeLib, const GUID &DispIntf);
	virtual HRESULT __fastcall SafeCallException(System::TObject* ExceptObject, void * ExceptAddr);
	__property System::PInterfaceEntry DispIntfEntry = {read=FDispIntfEntry};
	__property _di_ITypeInfo DispTypeInfo = {read=FDispTypeInfo};
	__property GUID DispIID = {read=FDispIID};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAutoIntfObject(void) { }
	#pragma option pop
	
private:
	void *__IDispatch;	/* IDispatch */
	void *__ISupportErrorInfo;	/* ISupportErrorInfo */
	
public:
	operator ISupportErrorInfo*(void) { return (ISupportErrorInfo*)&__ISupportErrorInfo; }
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	
};


class DELPHICLASS EOleError;
class PASCALIMPLEMENTATION EOleError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOleError(const AnsiString Msg) : Sysutils::Exception(Msg)
		 { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleError(const AnsiString Msg, const System::TVarRec * 
		Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleError(int Ident, const System::TVarRec * Args, const 
		int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleError(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOleSysError;
class PASCALIMPLEMENTATION EOleSysError : public EOleError 
{
	typedef EOleError inherited;
	
private:
	HRESULT FErrorCode;
	
public:
	__fastcall EOleSysError(const AnsiString Message, HRESULT ErrorCode, int HelpContext);
	__property HRESULT ErrorCode = {read=FErrorCode, write=FErrorCode, nodefault};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleSysError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EOleError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleSysError(int Ident)/* overload */ : EOleError(Ident
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleSysError(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : EOleError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleSysError(const AnsiString Msg, int AHelpContext) : 
		EOleError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleSysError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EOleError(Msg, Args, Args_Size, AHelpContext) { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleSysError(int Ident, int AHelpContext)/* overload */
		 : EOleError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleSysError(System::PResStringRec ResStringRec, 
		const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EOleError(ResStringRec
		, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleSysError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOleException;
class PASCALIMPLEMENTATION EOleException : public EOleSysError 
{
	typedef EOleSysError inherited;
	
private:
	AnsiString FSource;
	AnsiString FHelpFile;
	
public:
	__fastcall EOleException(const AnsiString Message, HRESULT ErrorCode, const AnsiString Source, const 
		AnsiString HelpFile, int HelpContext);
	__property AnsiString HelpFile = {read=FHelpFile, write=FHelpFile};
	__property AnsiString Source = {read=FSource, write=FSource};
public:
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EOleSysError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleException(int Ident)/* overload */ : EOleSysError(Ident
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleException(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : EOleSysError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleException(const AnsiString Msg, int AHelpContext) : 
		EOleSysError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EOleSysError(Msg, Args, Args_Size, AHelpContext) { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleException(int Ident, int AHelpContext)/* overload */
		 : EOleSysError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EOleSysError(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOleRegistrationError;
class PASCALIMPLEMENTATION EOleRegistrationError : public EOleError 
{
	typedef EOleError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOleRegistrationError(const AnsiString Msg) : EOleError(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleRegistrationError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : EOleError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleRegistrationError(int Ident)/* overload */ : EOleError(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleRegistrationError(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : EOleError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleRegistrationError(const AnsiString Msg, int AHelpContext
		) : EOleError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleRegistrationError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : EOleError(Msg, Args, Args_Size, AHelpContext) { }
		
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleRegistrationError(int Ident, int AHelpContext)/* overload */
		 : EOleError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleRegistrationError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EOleError(ResStringRec
		, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleRegistrationError(void) { }
	#pragma option pop
	
};


struct TCallDesc;
typedef TCallDesc *PCallDesc;

#pragma pack(push, 1)
struct TCallDesc
{
	Byte CallType;
	Byte ArgCount;
	Byte NamedArgCount;
	Byte ArgTypes[256];
} ;
#pragma pack(pop)

struct TDispDesc;
typedef TDispDesc *PDispDesc;

#pragma pack(push, 1)
struct TDispDesc
{
	int DispID;
	Byte ResType;
	TCallDesc CallDesc;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int CoInitFlags;
extern PACKAGE HRESULT __fastcall HandleSafeCallException(System::TObject* ExceptObject, void * ExceptAddr
	, const GUID &ErrorIID, const WideString ProgID, const WideString HelpFileName);
extern PACKAGE void __fastcall OleError(HRESULT ErrorCode);
extern PACKAGE void __fastcall OleCheck(HRESULT Result);
extern PACKAGE GUID __fastcall StringToGUID(const AnsiString S);
extern PACKAGE AnsiString __fastcall GUIDToString(const GUID &ClassID);
extern PACKAGE GUID __fastcall ProgIDToClassID(const AnsiString ProgID);
extern PACKAGE AnsiString __fastcall ClassIDToProgID(const GUID &ClassID);
extern PACKAGE void __fastcall CreateRegKey(const AnsiString Key, const AnsiString ValueName, const 
	AnsiString Value);
extern PACKAGE void __fastcall DeleteRegKey(const AnsiString Key);
extern PACKAGE AnsiString __fastcall GetRegStringValue(const AnsiString Key, const AnsiString ValueName
	);
extern PACKAGE _di_IUnknown __fastcall CreateComObject(const GUID &ClassID);
extern PACKAGE _di_IUnknown __fastcall CreateRemoteComObject(const WideString MachineName, const GUID 
	&ClassID);
extern PACKAGE _di_IDispatch __fastcall CreateOleObject(const AnsiString ClassName);
extern PACKAGE _di_IDispatch __fastcall GetActiveOleObject(const AnsiString ClassName);
extern PACKAGE wchar_t * __fastcall StringToLPOLESTR(const AnsiString Source);
extern PACKAGE AnsiString __fastcall CreateClassID();
extern PACKAGE void __fastcall RegisterComServer(const AnsiString DLLName);
extern PACKAGE void __fastcall RegisterAsService(const AnsiString ClassID, const AnsiString ServiceName
	);
extern PACKAGE void __fastcall InterfaceConnect(const _di_IUnknown Source, const GUID &IID, const _di_IUnknown 
	Sink, int &Connection);
extern PACKAGE void __fastcall InterfaceDisconnect(const _di_IUnknown Source, const GUID &IID, int &
	Connection);
extern PACKAGE void __fastcall DispatchInvoke(const _di_IDispatch Dispatch, PCallDesc CallDesc, Activex::PDispIDList 
	DispIDs, void * Params, System::PVariant Result);
extern PACKAGE void __fastcall DispatchInvokeError(int Status, const tagEXCEPINFO &ExcepInfo);

}	/* namespace Comobj */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Comobj;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ComObj
