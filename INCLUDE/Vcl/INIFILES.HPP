// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IniFiles.pas' rev: 6.00

#ifndef IniFilesHPP
#define IniFilesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Inifiles
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EIniFileException;
class PASCALIMPLEMENTATION EIniFileException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIniFileException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIniFileException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIniFileException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIniFileException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIniFileException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIniFileException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIniFileException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIniFileException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIniFileException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomIniFile;
class PASCALIMPLEMENTATION TCustomIniFile : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FFileName;
	
public:
	__fastcall TCustomIniFile(const AnsiString FileName);
	bool __fastcall SectionExists(const AnsiString Section);
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString Default) = 0 ;
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString Value) = 0 ;
	virtual int __fastcall ReadInteger(const AnsiString Section, const AnsiString Ident, int Default);
	virtual void __fastcall WriteInteger(const AnsiString Section, const AnsiString Ident, int Value);
	virtual bool __fastcall ReadBool(const AnsiString Section, const AnsiString Ident, bool Default);
	virtual void __fastcall WriteBool(const AnsiString Section, const AnsiString Ident, bool Value);
	virtual int __fastcall ReadBinaryStream(const AnsiString Section, const AnsiString Name, Classes::TStream* Value);
	virtual System::TDateTime __fastcall ReadDate(const AnsiString Section, const AnsiString Name, System::TDateTime Default);
	virtual System::TDateTime __fastcall ReadDateTime(const AnsiString Section, const AnsiString Name, System::TDateTime Default);
	virtual double __fastcall ReadFloat(const AnsiString Section, const AnsiString Name, double Default);
	virtual System::TDateTime __fastcall ReadTime(const AnsiString Section, const AnsiString Name, System::TDateTime Default);
	virtual void __fastcall WriteBinaryStream(const AnsiString Section, const AnsiString Name, Classes::TStream* Value);
	virtual void __fastcall WriteDate(const AnsiString Section, const AnsiString Name, System::TDateTime Value);
	virtual void __fastcall WriteDateTime(const AnsiString Section, const AnsiString Name, System::TDateTime Value);
	virtual void __fastcall WriteFloat(const AnsiString Section, const AnsiString Name, double Value);
	virtual void __fastcall WriteTime(const AnsiString Section, const AnsiString Name, System::TDateTime Value);
	virtual void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall ReadSections(Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall EraseSection(const AnsiString Section) = 0 ;
	virtual void __fastcall DeleteKey(const AnsiString Section, const AnsiString Ident) = 0 ;
	virtual void __fastcall UpdateFile(void) = 0 ;
	bool __fastcall ValueExists(const AnsiString Section, const AnsiString Ident);
	__property AnsiString FileName = {read=FFileName};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomIniFile(void) { }
	#pragma option pop
	
};


struct THashItem;
typedef THashItem *PHashItem;

typedef PHashItem *PPHashItem;

#pragma pack(push, 4)
struct THashItem
{
	THashItem *Next;
	AnsiString Key;
	int Value;
} ;
#pragma pack(pop)

typedef DynamicArray<PHashItem >  IniFiles__4;

class DELPHICLASS TStringHash;
class PASCALIMPLEMENTATION TStringHash : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	DynamicArray<PHashItem >  Buckets;
	
protected:
	PPHashItem __fastcall Find(const AnsiString Key);
	virtual unsigned __fastcall HashOf(const AnsiString Key);
	
public:
	__fastcall TStringHash(int Size);
	__fastcall virtual ~TStringHash(void);
	void __fastcall Add(const AnsiString Key, int Value);
	void __fastcall Clear(void);
	void __fastcall Remove(const AnsiString Key);
	bool __fastcall Modify(const AnsiString Key, int Value);
	int __fastcall ValueOf(const AnsiString Key);
};


class DELPHICLASS THashedStringList;
class PASCALIMPLEMENTATION THashedStringList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	TStringHash* FValueHash;
	TStringHash* FNameHash;
	bool FValueHashValid;
	bool FNameHashValid;
	void __fastcall UpdateValueHash(void);
	void __fastcall UpdateNameHash(void);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall virtual ~THashedStringList(void);
	virtual int __fastcall IndexOf(const AnsiString S);
	virtual int __fastcall IndexOfName(const AnsiString Name);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall THashedStringList(void) : Classes::TStringList() { }
	#pragma option pop
	
};


class DELPHICLASS TMemIniFile;
class PASCALIMPLEMENTATION TMemIniFile : public TCustomIniFile 
{
	typedef TCustomIniFile inherited;
	
private:
	Classes::TStringList* FSections;
	Classes::TStrings* __fastcall AddSection(const AnsiString Section);
	bool __fastcall GetCaseSensitive(void);
	void __fastcall LoadValues(void);
	void __fastcall SetCaseSensitive(bool Value);
	
public:
	__fastcall TMemIniFile(const AnsiString FileName);
	__fastcall virtual ~TMemIniFile(void);
	void __fastcall Clear(void);
	virtual void __fastcall DeleteKey(const AnsiString Section, const AnsiString Ident);
	virtual void __fastcall EraseSection(const AnsiString Section);
	void __fastcall GetStrings(Classes::TStrings* List);
	virtual void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall ReadSections(Classes::TStrings* Strings);
	virtual void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings);
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString Default);
	void __fastcall Rename(const AnsiString FileName, bool Reload);
	void __fastcall SetStrings(Classes::TStrings* List);
	virtual void __fastcall UpdateFile(void);
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString Value);
	__property bool CaseSensitive = {read=GetCaseSensitive, write=SetCaseSensitive, nodefault};
};


class DELPHICLASS TIniFile;
class PASCALIMPLEMENTATION TIniFile : public TCustomIniFile 
{
	typedef TCustomIniFile inherited;
	
public:
	__fastcall virtual ~TIniFile(void);
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString Default);
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString Value);
	virtual void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall ReadSections(Classes::TStrings* Strings);
	virtual void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall EraseSection(const AnsiString Section);
	virtual void __fastcall DeleteKey(const AnsiString Section, const AnsiString Ident);
	virtual void __fastcall UpdateFile(void);
public:
	#pragma option push -w-inl
	/* TCustomIniFile.Create */ inline __fastcall TIniFile(const AnsiString FileName) : TCustomIniFile(FileName) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Inifiles */
using namespace Inifiles;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IniFiles
