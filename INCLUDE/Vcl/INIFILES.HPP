// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IniFiles.pas' rev: 5.00

#ifndef IniFilesHPP
#define IniFilesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Inifiles
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomIniFile;
class PASCALIMPLEMENTATION TCustomIniFile : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FFileName;
	
public:
	__fastcall TCustomIniFile(const AnsiString FileName);
	bool __fastcall SectionExists(const AnsiString Section);
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Default) = 0 ;
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Value) = 0 ;
	virtual int __fastcall ReadInteger(const AnsiString Section, const AnsiString Ident, int Default);
	virtual void __fastcall WriteInteger(const AnsiString Section, const AnsiString Ident, int Value);
	virtual bool __fastcall ReadBool(const AnsiString Section, const AnsiString Ident, bool Default);
	virtual void __fastcall WriteBool(const AnsiString Section, const AnsiString Ident, bool Value);
	virtual System::TDateTime __fastcall ReadDate(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Default);
	virtual System::TDateTime __fastcall ReadDateTime(const AnsiString Section, const AnsiString Name, 
		System::TDateTime Default);
	virtual double __fastcall ReadFloat(const AnsiString Section, const AnsiString Name, double Default
		);
	virtual System::TDateTime __fastcall ReadTime(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Default);
	virtual void __fastcall WriteDate(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Value);
	virtual void __fastcall WriteDateTime(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Value);
	virtual void __fastcall WriteFloat(const AnsiString Section, const AnsiString Name, double Value);
	virtual void __fastcall WriteTime(const AnsiString Section, const AnsiString Name, System::TDateTime 
		Value);
	virtual void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall ReadSections(Classes::TStrings* Strings) = 0 ;
	virtual void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings) = 0 
		;
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


class DELPHICLASS TIniFile;
class PASCALIMPLEMENTATION TIniFile : public TCustomIniFile 
{
	typedef TCustomIniFile inherited;
	
public:
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Default);
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Value);
	virtual void __fastcall ReadSection(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall ReadSections(Classes::TStrings* Strings);
	virtual void __fastcall ReadSectionValues(const AnsiString Section, Classes::TStrings* Strings);
	virtual void __fastcall EraseSection(const AnsiString Section);
	virtual void __fastcall DeleteKey(const AnsiString Section, const AnsiString Ident);
	virtual void __fastcall UpdateFile(void);
public:
	#pragma option push -w-inl
	/* TCustomIniFile.Create */ inline __fastcall TIniFile(const AnsiString FileName) : TCustomIniFile(
		FileName) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIniFile(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMemIniFile;
class PASCALIMPLEMENTATION TMemIniFile : public TCustomIniFile 
{
	typedef TCustomIniFile inherited;
	
private:
	Classes::TStringList* FSections;
	Classes::TStrings* __fastcall AddSection(const AnsiString Section);
	void __fastcall LoadValues(void);
	
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
	virtual AnsiString __fastcall ReadString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Default);
	void __fastcall Rename(const AnsiString FileName, bool Reload);
	void __fastcall SetStrings(Classes::TStrings* List);
	virtual void __fastcall UpdateFile(void);
	virtual void __fastcall WriteString(const AnsiString Section, const AnsiString Ident, const AnsiString 
		Value);
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Inifiles */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Inifiles;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IniFiles
