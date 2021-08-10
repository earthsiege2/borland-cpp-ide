// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DbCombo.pas' rev: 6.00

#ifndef DbComboHPP
#define DbComboHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Controls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <FileCtrl.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbcombo
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TAliasDrive;
class PASCALIMPLEMENTATION TAliasDrive : public Filectrl::TDriveComboBox 
{
	typedef Filectrl::TDriveComboBox inherited;
	
private:
	Graphics::TBitmap* FAliasBitmap;
	Classes::TStrings* FAliasList;
	void __fastcall LoadBitmaps(void);
	void __fastcall FreeBitmaps(void);
	
protected:
	virtual void __fastcall BuildList(void);
	DYNAMIC void __fastcall Click(void);
	
public:
	__fastcall virtual TAliasDrive(Classes::TComponent* AOwner);
	__fastcall virtual ~TAliasDrive(void);
	void __fastcall AddAliases(Classes::TStrings* Value);
	bool __fastcall SetAlias(const AnsiString EditText);
	__property Graphics::TBitmap* AliasBitmap = {read=FAliasBitmap};
	__property Classes::TStrings* AliasList = {read=FAliasList};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAliasDrive(HWND ParentWindow) : Filectrl::TDriveComboBox(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TAliasListBox;
class PASCALIMPLEMENTATION TAliasListBox : public Filectrl::TDirectoryListBox 
{
	typedef Filectrl::TDirectoryListBox inherited;
	
private:
	bool FShowAlias;
	AnsiString FAliasName;
	Graphics::TBitmap* FAliasBitmap;
	void __fastcall SetAliasBitmap(Graphics::TBitmap* Value);
	
protected:
	virtual void __fastcall BuildList(void);
	
public:
	__fastcall virtual TAliasListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TAliasListBox(void);
	__property AnsiString AliasName = {read=FAliasName, write=FAliasName};
	__property Graphics::TBitmap* AliasBitmap = {read=FAliasBitmap, write=SetAliasBitmap};
	__property bool ShowAlias = {read=FShowAlias, write=FShowAlias, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAliasListBox(HWND ParentWindow) : Filectrl::TDirectoryListBox(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TAliasFileListBox;
class PASCALIMPLEMENTATION TAliasFileListBox : public Filectrl::TFileListBox 
{
	typedef Filectrl::TFileListBox inherited;
	
protected:
	Classes::TStringList* FTableList;
	bool FShowAlias;
	AnsiString FAliasName;
	bool FSystem;
	virtual void __fastcall ReadFileNames(void);
	virtual void __fastcall ReadBitmaps(void);
	
public:
	__fastcall virtual TAliasFileListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TAliasFileListBox(void);
	__property Classes::TStringList* TableList = {read=FTableList};
	__property bool ShowAlias = {read=FShowAlias, write=FShowAlias, nodefault};
	__property AnsiString AliasName = {read=FAliasName, write=FAliasName};
	__property bool System = {read=FSystem, write=FSystem, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TAliasFileListBox(HWND ParentWindow) : Filectrl::TFileListBox(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ProcessAlias(AnsiString EditText, AnsiString &Alias, AnsiString &DirPart, AnsiString &FilePart);

}	/* namespace Dbcombo */
using namespace Dbcombo;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DbCombo
