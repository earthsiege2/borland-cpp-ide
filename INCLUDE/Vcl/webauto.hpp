// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebAuto.pas' rev: 6.00

#ifndef WebAutoHPP
#define WebAutoHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <HTTPProd.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <WebScript_TLB.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webauto
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIDOfName;
class PASCALIMPLEMENTATION TIDOfName : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FID;
	WideString FName;
	_di_IDispatch FDispatch;
	
public:
	__fastcall TIDOfName(int AID, const WideString AName, _di_IDispatch ADispatch);
	__property int ID = {read=FID, nodefault};
	__property _di_IDispatch DispatchIntf = {read=FDispatch};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIDOfName(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIDsOfNames;
class PASCALIMPLEMENTATION TIDsOfNames : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FNextID;
	Contnrs::TObjectList* FList;
	
public:
	__fastcall TIDsOfNames(void);
	__fastcall virtual ~TIDsOfNames(void);
	TIDOfName* __fastcall FindID(int AID);
	TIDOfName* __fastcall FindName(wchar_t * AName);
	TIDOfName* __fastcall Add(const WideString AName, _di_IDispatch ADispatch);
};


class DELPHICLASS TWebComponentsWrapper;
class PASCALIMPLEMENTATION TWebComponentsWrapper : public TScriptComponent 
{
	typedef TScriptComponent inherited;
	
private:
	TIDsOfNames* FIDsOfNames;
	
protected:
	virtual HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	virtual HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	virtual _di_IDispatch __fastcall DispatchOfName(const AnsiString AName);
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
	virtual _di_IDispatch __fastcall DispatchOfObject(const System::TObject* AObject);
	
public:
	__fastcall virtual TWebComponentsWrapper(Classes::TComponent* AObject);
	__fastcall virtual ~TWebComponentsWrapper(void);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebComponentsWrapper(const System::_di_IInterface Controller) : TScriptComponent(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebComponentsWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptComponent(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IDispatch;	/* IDispatch */
	
public:
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	
};


class DELPHICLASS TWebModuleWrapper;
class PASCALIMPLEMENTATION TWebModuleWrapper : public TWebComponentsWrapper 
{
	typedef TWebComponentsWrapper inherited;
	
protected:
	HRESULT __safecall Get_ClassName_(WideString &Get_ClassName__result);
	HRESULT __safecall Get_Name_(WideString &Get_Name__result);
	virtual System::TObject* __fastcall FindObject(const AnsiString AName);
	HRESULT __safecall Get_Objects(Webscript_tlb::_di_IComponentsWrapper &Get_Objects_result);
	
public:
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name_() { WideString r; HRESULT hr = Get_Name_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name_};
public:
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Create */ inline __fastcall virtual TWebModuleWrapper(Classes::TComponent* AObject) : TWebComponentsWrapper(AObject) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWebComponentsWrapper.Destroy */ inline __fastcall virtual ~TWebModuleWrapper(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TWebModuleWrapper(const System::_di_IInterface Controller) : TWebComponentsWrapper(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TWebModuleWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TWebComponentsWrapper(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IModuleWrapper;	/* Webscript_tlb::IModuleWrapper */
	
public:
	operator IModuleWrapper*(void) { return (IModuleWrapper*)&__IModuleWrapper; }
	operator IComponentWrapper*(void) { return (IComponentWrapper*)&__IModuleWrapper; }
	
};


class DELPHICLASS TModuleObjectsWrapper;
class PASCALIMPLEMENTATION TModuleObjectsWrapper : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	System::TObject* FModule;
	_di_IEnumVariant FEnumerator;
	
protected:
	HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result);
	
public:
	__fastcall TModuleObjectsWrapper(System::TObject* AModule);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TModuleObjectsWrapper(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TModuleObjectsWrapper(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.Destroy */ inline __fastcall virtual ~TModuleObjectsWrapper(void) { }
	#pragma option pop
	
private:
	void *__IComponentsWrapper;	/* Webscript_tlb::IComponentsWrapper */
	
public:
	operator IComponentsWrapper*(void) { return (IComponentsWrapper*)&__IComponentsWrapper; }
	
};


typedef TMetaClass*TWebComponentsWrapperClass;

class DELPHICLASS TAbstractScriptComServerObject;
class PASCALIMPLEMENTATION TAbstractScriptComServerObject : public Comobj::TComServerObject 
{
	typedef Comobj::TComServerObject inherited;
	
private:
	_di_ITypeLib FTypeLib;
	
protected:
	virtual int __fastcall CountObject(bool Created);
	virtual int __fastcall CountFactory(bool Created);
	virtual AnsiString __fastcall GetHelpFileName();
	virtual AnsiString __fastcall GetServerFileName();
	virtual AnsiString __fastcall GetServerKey();
	virtual AnsiString __fastcall GetServerName();
	virtual bool __fastcall GetStartSuspended(void);
	virtual _di_ITypeLib __fastcall GetTypeLib();
	virtual _di_ITypeLib __fastcall ImplGetTypeLib(void) = 0 ;
	virtual void __fastcall SetHelpFileName(const AnsiString Value);
	
public:
	bool __fastcall HaveTypeLib(void);
	void __fastcall RegisterScriptClass(TMetaClass* AClass, const GUID &AClassID);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TAbstractScriptComServerObject(void) : Comobj::TComServerObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAbstractScriptComServerObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TScriptComServerObject;
class PASCALIMPLEMENTATION TScriptComServerObject : public TAbstractScriptComServerObject 
{
	typedef TAbstractScriptComServerObject inherited;
	
protected:
	virtual _di_ITypeLib __fastcall ImplGetTypeLib();
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TScriptComServerObject(void) : TAbstractScriptComServerObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TScriptComServerObject(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIteratorSupport;
class PASCALIMPLEMENTATION TIteratorSupport : public TScriptObject 
{
	typedef TScriptObject inherited;
	
private:
	Sitecomp::_di_IIteratorSupport FIterator;
	bool FEOF;
	bool FReset;
	void *FOwnerData;
	bool FIterating;
	
protected:
	virtual _di_IDispatch __fastcall GetCurrent();
	__property Sitecomp::_di_IIteratorSupport Iterator = {read=FIterator};
	__property void * OwnerData = {read=FOwnerData};
	HRESULT __stdcall Clone(/* out */ _di_IEnumVariant &ppenum);
	HRESULT __stdcall Next(unsigned celt, OleVariant &rgvar, /* out */ unsigned &pceltFetched);
	HRESULT __stdcall Reset(void);
	HRESULT __stdcall Skip(unsigned celt);
	
public:
	__fastcall TIteratorSupport(Sitecomp::_di_IIteratorSupport AIterator);
	__fastcall virtual ~TIteratorSupport(void);
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TIteratorSupport(const System::_di_IInterface Controller) : TScriptObject(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TIteratorSupport(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TScriptObject(Factory, Controller) { }
	#pragma option pop
	
private:
	void *__IEnumVariant;	/* IEnumVariant */
	
public:
	operator IEnumVariant*(void) { return (IEnumVariant*)&__IEnumVariant; }
	
};


class DELPHICLASS TComponentsEnumerator;
class PASCALIMPLEMENTATION TComponentsEnumerator : public TIteratorSupport 
{
	typedef TIteratorSupport inherited;
	
private:
	System::TObject* FObject;
	Sitecomp::_di_IIterateObjectSupport FIterator;
	
protected:
	virtual _di_IDispatch __fastcall GetCurrent();
	
public:
	__fastcall TComponentsEnumerator(System::TObject* AObject);
	__property Sitecomp::_di_IIterateObjectSupport Iterator = {read=FIterator};
public:
	#pragma option push -w-inl
	/* TIteratorSupport.Destroy */ inline __fastcall virtual ~TComponentsEnumerator(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TComObject.CreateAggregated */ inline __fastcall TComponentsEnumerator(const System::_di_IInterface Controller) : TIteratorSupport(Controller) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComObject.CreateFromFactory */ inline __fastcall TComponentsEnumerator(TComObjectFactory* Factory, const System::_di_IInterface Controller) : TIteratorSupport(Factory, Controller) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TAbstractScriptComServerObject* ScriptComServer;
extern PACKAGE void __fastcall InitScriptComServer(void);

}	/* namespace Webauto */
using namespace Webauto;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebAuto
