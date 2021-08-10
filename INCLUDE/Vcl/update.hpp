// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Update.pas' rev: 6.00

#ifndef UpdateHPP
#define UpdateHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Update
{
//-- type declarations -------------------------------------------------------
__interface IUpdateManager;
typedef System::DelphiInterface<IUpdateManager> _di_IUpdateManager;
__interface INTERFACE_UUID("{7ED7BF35-E349-11D3-AB4A-00C04FB17A72}") IUpdateManager  : public IInterface 
{
	
public:
	virtual bool __fastcall CanRevert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual Classes::TComponent* __fastcall GetComponent(void) = 0 ;
	virtual Classes::TComponent* __fastcall GetAncestor(void) = 0 ;
	virtual bool __fastcall GetHasDescendents(void) = 0 ;
	virtual bool __fastcall GetIsDescendent(void) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual bool __fastcall NameExists(const AnsiString Name) = 0 ;
	virtual void __fastcall Notification(Classes::TPersistent* Component, Classes::TOperation Operation) = 0 ;
	virtual void __fastcall RenameComponent(const AnsiString CurrentName, const AnsiString NewName) = 0 ;
	virtual void __fastcall RenameDescendents(const AnsiString CurrentName, const AnsiString NewName) = 0 ;
	virtual void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo) = 0 ;
	virtual void __fastcall Update(void) = 0 ;
	__property Classes::TComponent* Component = {read=GetComponent};
	__property Classes::TComponent* Ancestor = {read=GetAncestor};
	__property bool HasDescendents = {read=GetHasDescendents};
	__property bool IsDescendent = {read=GetIsDescendent};
};

__interface IUpdateManagerCallback;
typedef System::DelphiInterface<IUpdateManagerCallback> _di_IUpdateManagerCallback;
__interface INTERFACE_UUID("{ABBE7254-5495-11D1-9FB5-0020AF3D82DA}") IUpdateManagerCallback  : public IInterface 
{
	
public:
	virtual void __fastcall Updating(const _di_IUpdateManager Context) = 0 ;
	virtual void __fastcall Updated(const _di_IUpdateManager Context) = 0 ;
	virtual void __fastcall Deleting(const _di_IUpdateManager Context, Classes::TPersistent* Instance) = 0 ;
	virtual Classes::TComponent* __fastcall CreateComponent(TMetaClass* ComponentClass, const Classes::TComponent* Owner) = 0 ;
	virtual void __fastcall WriteComponent(Classes::TWriter* Writer, Classes::TComponent* Component) = 0 ;
	virtual void __fastcall RefuseChildren(Classes::TComponent* Component) = 0 ;
	virtual TMetaClass* __fastcall GetActiveClassGroup(void) = 0 ;
};

#pragma option push -b-
enum TUpdateFilterState { usFilter, usReading, usWriting };
#pragma option pop

class DELPHICLASS TUpdateFiler;
class DELPHICLASS TUpdateObject;
class DELPHICLASS TUpdateManager;
class PASCALIMPLEMENTATION TUpdateObject : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TUpdateObject* FOwner;
	Classes::TPersistent* FObject;
	Classes::TPersistent* FAncestor;
	Classes::TComponent* FObjectOwner;
	Classes::TComponent* FAncestorOwner;
	Classes::TList* FPropList;
	Classes::TList* FChildList;
	TUpdateFiler* FUpdateFiler;
	bool FIsComponent;
	bool FIsCollection;
	bool FUpdateCollection;
	bool FUpdateOrder;
	int FOrder;
	Typinfo::TPropInfo *FPropInfo;
	bool FCompare;
	__fastcall TUpdateObject(TUpdateObject* AOwner, Classes::TPersistent* AObject, Classes::TPersistent* AAncestor, Typinfo::PPropInfo APropInfo, bool Compare, bool AsRoot);
	void __fastcall AddChild(Classes::TComponent* Component);
	bool __fastcall CanRevert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo, bool &Continue);
	System::TMethod __fastcall GetAncestorMethod(Typinfo::PPropInfo PropInfo);
	void * __fastcall GetAncestorPointer(void * Value);
	void * __fastcall GetAncestorReference(Typinfo::PPropInfo PropInfo);
	TUpdateObject* __fastcall FindChild(Classes::TComponent* Component);
	TUpdateObject* __fastcall FindChildProp(Typinfo::PPropInfo APropInfo);
	void __fastcall ComponentDelete(Classes::TComponent* AComponent);
	void __fastcall Filter(void);
	void __fastcall FilterOrder(void);
	bool __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo);
	void __fastcall Update(TUpdateManager* UpdateManager);
	void __fastcall ValidateObjects(void);
	
public:
	__fastcall virtual ~TUpdateObject(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TUpdateObject(void) : System::TObject() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TUpdateFiler : public Classes::TFiler 
{
	typedef Classes::TFiler inherited;
	
private:
	Classes::TStringList* FPropertyList;
	TUpdateObject* FUpdateObject;
	Classes::TWriter* FWriter;
	Classes::TReader* FReader;
	bool FFiltered;
	TUpdateFilterState FState;
	AnsiString FPropName;
	bool FCompare;
	bool __fastcall Empty(void);
	void __fastcall Filter(void);
	void __fastcall FilterProp(const AnsiString Name, bool HasData);
	void __fastcall Update(void);
	
public:
	__fastcall TUpdateFiler(TUpdateObject* AUpdateObject, bool ACompare);
	__fastcall virtual ~TUpdateFiler(void);
	virtual void __fastcall DefineProperty(const AnsiString Name, Classes::TReaderProc ReadData, Classes::TWriterProc WriteData, bool HasData);
	virtual void __fastcall DefineBinaryProperty(const AnsiString Name, Classes::TStreamProc ReadData, Classes::TStreamProc WriteData, bool HasData);
	virtual void __fastcall FlushBuffer(void);
};


#pragma option push -b-
enum TUpdateMode { umNone, umUpdate, umFilter };
#pragma option pop

class PASCALIMPLEMENTATION TUpdateManager : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TUpdateObject* FComponentUpdate;
	Classes::TList* FChildList;
	Classes::TComponent* FComponent;
	Classes::TComponent* FAncestor;
	TUpdateManager* FParent;
	TUpdateMode FMode;
	Classes::TList* FUpdateList;
	Classes::TNotifyEvent FOnUpdating;
	Classes::TNotifyEvent FOnUpdate;
	_di_IUpdateManagerCallback FNotifier;
	void __fastcall Filter(void);
	bool __fastcall GetHasDescendents(void);
	bool __fastcall GetIsDescendent(void);
	void __fastcall UpdateChildren(void);
	void __fastcall SetChildAncestor(Classes::TComponent* Child);
	void __fastcall Updating(Classes::TComponent* Component);
	Classes::TComponent* __fastcall GetAncestor(void);
	Classes::TComponent* __fastcall GetComponent(void);
	System::TObject* __fastcall GetInstance(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	
public:
	__fastcall TUpdateManager(Classes::TComponent* AComponent, Classes::TComponent* AAncestor, _di_IUpdateManager AAncestorManager, const _di_IUpdateManagerCallback ANotifier);
	__fastcall virtual ~TUpdateManager(void);
	bool __fastcall CanRevert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo);
	void __fastcall Notification(Classes::TPersistent* AComponent, Classes::TOperation Operation);
	void __fastcall Modified(void);
	bool __fastcall NameExists(const AnsiString Name);
	void __fastcall RenameComponent(const AnsiString CurrentName, const AnsiString NewName);
	void __fastcall RenameDescendents(const AnsiString CurrentName, const AnsiString NewName);
	void __fastcall Revert(Classes::TPersistent* Instance, Typinfo::PPropInfo PropInfo);
	void __fastcall Update(void);
	__property Classes::TNotifyEvent OnUpdating = {read=FOnUpdating, write=FOnUpdating};
	__property Classes::TNotifyEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
	__property Classes::TComponent* Component = {read=FComponent};
	__property Classes::TComponent* Ancestor = {read=FAncestor};
	__property bool HasDescendents = {read=GetHasDescendents, nodefault};
	__property bool IsDescendent = {read=GetIsDescendent, nodefault};
private:
	void *__IUpdateManager;	/* Update::IUpdateManager */
	void *__IImplementation;	/* Designintf::IImplementation */
	
public:
	operator IImplementation*(void) { return (IImplementation*)&__IImplementation; }
	operator IUpdateManager*(void) { return (IUpdateManager*)&__IUpdateManager; }
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Update */
using namespace Update;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Update
