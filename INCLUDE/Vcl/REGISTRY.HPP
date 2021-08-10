// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Registry.pas' rev: 5.00

#ifndef RegistryHPP
#define RegistryHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IniFiles.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Registry
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ERegistryException;
class PASCALIMPLEMENTATION ERegistryException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ERegistryException(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ERegistryException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ERegistryException(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ERegistryException(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ERegistryException(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ERegistryException(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ERegistryException(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ERegistryException(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ERegistryException(void) { }
	#pragma option pop
	
};


struct TRegKeyInfo
{
	int NumSubKeys;
	int MaxSubKeyLen;
	int NumValues;
	int MaxValueLen;
	int MaxDataLen;
	_FILETIME FileTime;
} ;

#pragma option push -b-
enum TRegDataType { rdUnknown, rdString, rdExpandString, rdInteger, rdBinary };
#pragma option pop

struct TRegDataInfo
{
	TRegDataType RegData;
	int DataSize;
} ;

class DELPHICLASS TRegistry;
class PASCALIMPLEMENTATION TRegistry : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	HKEY FCurrentKey;
	HKEY FRootKey;
	bool FLazyWrite;
	AnsiString FCurrentPath;
	bool FCloseRootKey;
	unsigned FAccess;
	void __fastcall SetRootKey(HKEY Value);
	
protected:
	void __fastcall ChangeKey(HKEY Value, const AnsiString Path);
	HKEY __fastcall GetBaseKey(bool Relative);
	int __fastcall GetData(const AnsiString Name, void * Buffer, int BufSize, TRegDataType &RegData);
	HKEY __fastcall GetKey(const AnsiString Key);
	void __fastcall PutData(const AnsiString Name, void * Buffer, int BufSize, TRegDataType RegData);
	void __fastcall SetCurrentKey(HKEY Value);
	
public:
	__fastcall TRegistry(void)/* overload */;
	__fastcall TRegistry(unsigned AAccess)/* overload */;
	__fastcall virtual ~TRegistry(void);
	void __fastcall CloseKey(void);
	bool __fastcall CreateKey(const AnsiString Key);
	bool __fastcall DeleteKey(const AnsiString Key);
	bool __fastcall DeleteValue(const AnsiString Name);
	bool __fastcall GetDataInfo(const AnsiString ValueName, TRegDataInfo &Value);
	int __fastcall GetDataSize(const AnsiString ValueName);
	TRegDataType __fastcall GetDataType(const AnsiString ValueName);
	bool __fastcall GetKeyInfo(TRegKeyInfo &Value);
	void __fastcall GetKeyNames(Classes::TStrings* Strings);
	void __fastcall GetValueNames(Classes::TStrings* Strings);
	bool __fastcall HasSubKeys(void);
	bool __fastcall KeyExists(const AnsiString Key);
	bool __fastcall LoadKey(const AnsiString Key, const AnsiString FileName);
	void __fastcall MoveKey(const AnsiString OldName, const AnsiString NewName, bool Delete);
	bool __fastcall OpenKey(const AnsiString Key, bool CanCreate);
	bool __fastcall OpenKeyReadOnly(const AnsiString Key);
	System::Currency __fastcall ReadCurrency(const AnsiString Name);
	int __fastcall ReadBinaryData(const AnsiString Name, void *Buffer, int BufSize);
	bool __fastcall ReadBool(const AnsiString Name);
	System::TDateTime __fastcall ReadDate(const AnsiString Name);
	System::TDateTime __fastcall ReadDateTime(const AnsiString Name);
	double __fastcall ReadFloat(const AnsiString Name);
	int __fastcall ReadInteger(const AnsiString Name);
	AnsiString __fastcall ReadString(const AnsiString Name);
	System::TDateTime __fastcall ReadTime(const AnsiString Name);
	bool __fastcall RegistryConnect(const AnsiString UNCName);
	void __fastcall RenameValue(const AnsiString OldName, const AnsiString NewName);
	bool __fastcall ReplaceKey(const AnsiString Key, const AnsiString FileName, const AnsiString BackUpFileName
		);
	bool __fastcall RestoreKey(const AnsiString Key, const AnsiString FileName);
	bool __fastcall SaveKey(const AnsiString Key, const AnsiString FileName);
	bool __fastcall UnLoadKey(const AnsiString Key);
	bool __fastcall ValueExists(const AnsiString Name);
	void __fastcall WriteCurrency(const AnsiString Name, System::Currency Value);
	void __fastcall WriteBinaryData(const AnsiString Name, void *Buffer, int BufSize);
	void __fastcall WriteBool(const AnsiString Name, bool Value);
	void __fastcall WriteDate(const AnsiString Name, System::TDateTime Value);
	void __fastcall WriteDateTime(const AnsiString Name, System::TDateTime Value);
	void __fastcall WriteFloat(const AnsiString Name, double Value);
	void __fastcall WriteInteger(const AnsiString Name, int Value);
	void __fastcall WriteString(const AnsiString Name, const AnsiString Value);
	void __fastcall WriteExpandString(const AnsiString Name, const AnsiString Value);
	void __fastcall WriteTime(const AnsiString Name, System::TDateTime Value);
	__property HKEY CurrentKey = {read=FCurrentKey, nodefault};
	__property AnsiString CurrentPath = {read=FCurrentPath};
	__property bool LazyWrite = {read=FLazyWrite, write=FLazyWrite, nodefault};
	__property HKEY RootKey = {read=FRootKey, write=SetRootKey, nodefault};
	__property unsigned Access = {read=FAccess, write=FAccess, nodefault};
};


class DELPHICLASS TRegIniFile;
class PASCALIMPLEMENTATION TRegIniFile : public TRegistry 
{
	typedef TRegistry inherited;
	
private:
	AnsiString FFileName;
	
public:
	__fastcall TRegIniFile(const AnsiString FileName)/* overload */;
	__fastcall TRegIniFile(const AnsiString FileName, unsigned AAccess)/* overload */;
	HIDESBASE AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const 
		AnsiString Default);
	HIDESBASE int __fastcall ReadInteger(const AnsiString Section, const AnsiString Ident, int Default)
		;
	HIDESBASE void __fastcall WriteInteger(const AnsiString Section, const AnsiString Ident, int Value)
		;
	HIDESBASE void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Value);
	HIDESBASE bool __fastcall ReadBool(const AnsiString Section, const AnsiString Ident, bool Default);
		
	HIDESBASE void __fastcall WriteBool(const AnsiString Section, const AnsiString Ident, bool Value);
	void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings);
	void __fastcall ReadSections(Classes::TStrings* Strings);
	void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings);
	void __fastcall EraseSection(const AnsiString Section);
	HIDESBASE void __fastcall DeleteKey(const AnsiString Section, const AnsiString Ident);
	__property AnsiString FileName = {read=FFileName};
public:
	#pragma option push -w-inl
	/* TRegistry.Destroy */ inline __fastcall virtual ~TRegIniFile(void) { }
	#pragma option pop
	
};


class DELPHICLASS TRegistryIniFile;
class PASCALIMPLEMENTATION TRegistryIniFile : public Inifiles::TCustomIniFile 
{
	typedef Inifiles::TCustomIniFile inherited;
	
private:
	TRegIniFile* FRegIniFile;
	
public:
	__fastcall TRegistryIniFile(const AnsiString FileName)/* overload */;
	__fastcall TRegistryIniFile(const AnsiString FileName, unsigned AAccess)/* overload */;
	__fastcall virtual ~TRegistryIniFile(void);
	virtual System::TDateTime __fastcall ReadDate(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Default);
	virtual System::TDateTime __fastcall ReadDateTime(const AnsiString Section, const AnsiString Name, 
		System::TDateTime Default);
	virtual int __fastcall ReadInteger(const AnsiString Section, const AnsiString Ident, int Default);
	virtual double __fastcall ReadFloat(const AnsiString Section, const AnsiString Name, double Default
		);
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Default);
	virtual System::TDateTime __fastcall ReadTime(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Default);
	virtual void __fastcall WriteDate(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Value);
	virtual void __fastcall WriteDateTime(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Value);
	virtual void __fastcall WriteFloat(const AnsiString Section, const AnsiString Name, double Value);
	virtual void __fastcall WriteInteger(const AnsiString Section, const AnsiString Ident, int Value);
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Value);
	virtual void __fastcall WriteTime(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Value);
	virtual void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall ReadSections(Classes::TStrings* Strings);
	virtual void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall EraseSection(const AnsiString Section);
	virtual void __fastcall DeleteKey(const AnsiString Section, const AnsiString Ident);
	virtual void __fastcall UpdateFile(void);
	__property TRegIniFile* RegIniFile = {read=FRegIniFile};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Registry */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Registry;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Registry
