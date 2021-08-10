// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StFilSys.pas' rev: 6.00

#ifndef StFilSysHPP
#define StFilSysHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ToolsAPI.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <IStreams.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stfilsys
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOTANotifier;
class DELPHICLASS TActiveTStringsProperty;
class PASCALIMPLEMENTATION TActiveTStringsProperty : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TComponent* FComponent;
	AnsiString FPropertyName;
	Toolsapi::_di_IOTAModule FModule;
	Toolsapi::_di_IOTAFormEditor FFormEditor;
	Toolsapi::_di_IOTAModuleNotifier FModuleNotifier;
	Toolsapi::_di_IOTAFormNotifier FFormModuleNotifier;
	int FIndex;
	int FModuleNotifierIndex;
	int FFormNotifierIndex;
	int FDiskAge;
	void __fastcall SetModule(const Toolsapi::_di_IOTAModule Value);
	void __fastcall SetComponent(Classes::TComponent* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall TActiveTStringsProperty(Classes::TComponent* AOwner, Classes::TComponent* AComponent, const AnsiString APropertyName);
	__fastcall virtual ~TActiveTStringsProperty(void);
	void __fastcall RenameComponent(const AnsiString OldName, const AnsiString NewName);
	__property Toolsapi::_di_IOTAModule Module = {read=FModule, write=SetModule};
	__property Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	__property AnsiString PropertyName = {read=FPropertyName, write=FPropertyName};
	__property int DiskAge = {read=FDiskAge, write=FDiskAge, nodefault};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TActiveTStringsProperty(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TOTANotifier : public Toolsapi::TNotifierObject 
{
	typedef Toolsapi::TNotifierObject inherited;
	
protected:
	TActiveTStringsProperty* FOwner;
	HIDESBASE void __fastcall Destroyed(void);
	
public:
	__fastcall TOTANotifier(TActiveTStringsProperty* AOwner);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOTANotifier(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOTAModuleNotifier;
class PASCALIMPLEMENTATION TOTAModuleNotifier : public TOTANotifier 
{
	typedef TOTANotifier inherited;
	
protected:
	HIDESBASE void __fastcall Modified(void);
	bool __fastcall CheckOverwrite(void);
	void __fastcall ModuleRenamed(const AnsiString NewName);
public:
	#pragma option push -w-inl
	/* TOTANotifier.Create */ inline __fastcall TOTAModuleNotifier(TActiveTStringsProperty* AOwner) : TOTANotifier(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOTAModuleNotifier(void) { }
	#pragma option pop
	
private:
	void *__IOTAModuleNotifier;	/* Toolsapi::IOTAModuleNotifier */
	
public:
	operator IOTAModuleNotifier*(void) { return (IOTAModuleNotifier*)&__IOTAModuleNotifier; }
	operator IOTANotifier*(void) { return (IOTANotifier*)&__IOTAModuleNotifier; }
	
};


class DELPHICLASS TOTAFormNotifier;
class PASCALIMPLEMENTATION TOTAFormNotifier : public TOTANotifier 
{
	typedef TOTANotifier inherited;
	
protected:
	void __fastcall FormActivated(void);
	void __fastcall FormSaving(void);
	void __fastcall ComponentRenamed(void * ComponentHandle, const AnsiString OldName, const AnsiString NewName);
public:
	#pragma option push -w-inl
	/* TOTANotifier.Create */ inline __fastcall TOTAFormNotifier(TActiveTStringsProperty* AOwner) : TOTANotifier(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOTAFormNotifier(void) { }
	#pragma option pop
	
private:
	void *__IOTAFormNotifier;	/* Toolsapi::IOTAFormNotifier */
	
public:
	operator IOTAFormNotifier*(void) { return (IOTAFormNotifier*)&__IOTAFormNotifier; }
	operator IOTANotifier*(void) { return (IOTANotifier*)&__IOTAFormNotifier; }
	
};


class DELPHICLASS TStringsStream;
class PASCALIMPLEMENTATION TStringsStream : public Istreams::TIMemoryStream 
{
	typedef Istreams::TIMemoryStream inherited;
	
private:
	Classes::TComponent* FComponent;
	Classes::TStrings* FStringsProperty;
	TActiveTStringsProperty* FActiveTStringsProperty;
	bool FModified;
	__fastcall TStringsStream(TActiveTStringsProperty* ActiveTStringsProperty, Classes::TComponent* AComponent, const AnsiString APropName, int Mode);
	void __fastcall SetDesignerModified(void);
	
public:
	__fastcall virtual ~TStringsStream(void);
	virtual HRESULT __stdcall Write(void * pv, int cb, PLongint pcbWritten);
public:
	#pragma option push -w-inl
	/* TIMemoryStream.Create */ inline __fastcall TStringsStream(Classes::TMemoryStream* Stream, Classes::TStreamOwnership Ownership) : Istreams::TIMemoryStream(Stream, Ownership) { }
	#pragma option pop
	
};


class DELPHICLASS TStringsFileSystem;
class PASCALIMPLEMENTATION TStringsFileSystem : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Classes::TStringList* FActiveTStringsProperties;
	
public:
	__fastcall TStringsFileSystem(void);
	__fastcall virtual ~TStringsFileSystem(void);
	TActiveTStringsProperty* __fastcall GetTStringsProperty(const AnsiString IDent, Classes::TComponent* AComponent, const AnsiString APropertyName);
	_di_IStream __fastcall GetFileStream(const AnsiString FileName, int Mode);
	int __fastcall FileAge(const AnsiString FileName);
	bool __fastcall RenameFile(const AnsiString OldName, const AnsiString NewName);
	bool __fastcall IsReadonly(const AnsiString FileName);
	bool __fastcall IsFileBased(void);
	bool __fastcall DeleteFile(const AnsiString FileName);
	bool __fastcall FileExists(const AnsiString FileName);
	AnsiString __fastcall GetTempFileName(const AnsiString FileName);
	AnsiString __fastcall GetBackupFileName(const AnsiString FileName);
	AnsiString __fastcall GetIDString();
private:
	void *__IOTAFileSystem;	/* Toolsapi::IOTAFileSystem */
	
public:
	operator IOTAFileSystem*(void) { return (IOTAFileSystem*)&__IOTAFileSystem; }
	
};


//-- var, const, procedure ---------------------------------------------------
#define sTStringsFileSystem "Delphi.TStringsFileSystem"
extern PACKAGE TStringsFileSystem* StringsFileSystem;
extern PACKAGE System::_di_IInterface StringsFileSystemCounter;
extern PACKAGE int StringsFileSystemIndex;
extern PACKAGE void __fastcall Register(void);
extern PACKAGE void __fastcall Unregister(void);

}	/* namespace Stfilsys */
using namespace Stfilsys;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StFilSys
