// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Rio.pas' rev: 6.00

#ifndef RioHPP
#define RioHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <WebNode.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <OPConvert.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#if defined(__WIN32__)
#pragma link "wininet.lib"
#endif

namespace Rio
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TBeforeExecuteEvent)(const AnsiString MethodName, WideString &SOAPRequest);

typedef void __fastcall (__closure *TAfterExecuteEvent)(const AnsiString MethodName, Classes::TStream* SOAPResponse);

class DELPHICLASS TRIO;
class PASCALIMPLEMENTATION TRIO : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	#pragma pack(push, 1)
	GUID FIID;
	#pragma pack(pop)
	
	bool FInterfaceBound;
	int FRefCount;
	void *IntfTable;
	void *IntfTableP;
	void *IntfStubs;
	void *StubAddr;
	void *ErrorStubAddr;
	bool IntfReg;
	bool LegalCC;
	bool HasRTTI;
	Byte CallStub[19];
	int CallStubIdx;
	Invokeregistry::TInvContext* FContext;
	TAfterExecuteEvent FOnAfterExecute;
	TBeforeExecuteEvent FOnBeforeExecute;
	__int64 __fastcall Generic(int CallID, void * Params);
	void __fastcall GenericStub(void);
	void __fastcall ErrorEntry(void);
	bool __fastcall GenVTable(const GUID &IID);
	void __fastcall GenPushI(int I);
	void __fastcall GenDWORD(unsigned DW);
	void __fastcall GenByte(Byte B);
	void __fastcall GenRET(Word BytesPushed = (Word)(0x0));
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	
protected:
	Intfinfo::TIntfMetaData IntfMD;
	Opconvert::_di_IOPConvert FConverter;
	Webnode::_di_IWebNode FWebNode;
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	virtual void __fastcall DoAfterExecute(const AnsiString MethodName, Classes::TStream* Response);
	virtual void __fastcall DoBeforeExecute(const AnsiString MethodName, WideString &Request);
	
public:
	__fastcall virtual TRIO(Classes::TComponent* AOwner);
	__fastcall virtual ~TRIO(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	/* virtual class method */ virtual System::TObject* __fastcall NewInstance(TMetaClass* vmt);
	__property int RefCount = {read=FRefCount, nodefault};
	__property Opconvert::_di_IOPConvert Converter = {read=FConverter, write=FConverter};
	__property Webnode::_di_IWebNode WebNode = {read=FWebNode, write=FWebNode};
	
__published:
	__property TAfterExecuteEvent OnAfterExecute = {read=FOnAfterExecute, write=FOnAfterExecute};
	__property TBeforeExecuteEvent OnBeforeExecute = {read=FOnBeforeExecute, write=FOnBeforeExecute};
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	operator IInterface*(void) { return (IInterface*)&__IInterface; }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint StubSize = 0x13;

}	/* namespace Rio */
using namespace Rio;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Rio
