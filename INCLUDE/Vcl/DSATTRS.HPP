// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSAttrS.pas' rev: 5.00

#ifndef DSAttrSHPP
#define DSAttrSHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <LibHelp.hpp>	// Pascal unit
#include <DRIntf.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsattrs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSaveAttributesAs;
class PASCALIMPLEMENTATION TSaveAttributesAs : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TComboBox* BasedOnList;
	Stdctrls::TEdit* AttributeNameEdit;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TButton* OKBtn;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* HelpBtn;
	void __fastcall OKBtnClick(System::TObject* Sender);
	void __fastcall CancelBtnClick(System::TObject* Sender);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	void __fastcall AddToList(const AnsiString Value);
	
public:
	bool __fastcall Execute(const AnsiString TableName, const AnsiString FieldName, AnsiString &AttributesName
		, Drintf::TAttrID &BasedOnID);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSaveAttributesAs(Classes::TComponent* AOwner) : 
		Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSaveAttributesAs(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSaveAttributesAs(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSaveAttributesAs(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall SaveAttributesAsDlg(const AnsiString TableName, const AnsiString FieldName
	, AnsiString &Name, Drintf::TAttrID &BasedOnID);

}	/* namespace Dsattrs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsattrs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSAttrS
