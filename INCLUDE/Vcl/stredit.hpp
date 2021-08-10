// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StrEdit.pas' rev: 6.00

#ifndef StrEditHPP
#define StrEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStrEditDlg;
class PASCALIMPLEMENTATION TStrEditDlg : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* CodeWndBtn;
	Dialogs::TOpenDialog* OpenDialog;
	Dialogs::TSaveDialog* SaveDialog;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Menus::TPopupMenu* StringEditorMenu;
	Menus::TMenuItem* LoadItem;
	Menus::TMenuItem* SaveItem;
	Menus::TMenuItem* CodeEditorItem;
	void __fastcall FileOpen(System::TObject* Sender);
	void __fastcall FileSave(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall CodeWndBtnClick(System::TObject* Sender);
	
protected:
	bool FModified;
	virtual Classes::TStrings* __fastcall GetLines(void) = 0 ;
	virtual void __fastcall SetLines(const Classes::TStrings* Value) = 0 ;
	virtual Controls::TWinControl* __fastcall GetLinesControl(void) = 0 ;
	
public:
	__property Classes::TStrings* Lines = {read=GetLines, write=SetLines};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TStrEditDlg(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TStrEditDlg(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TStrEditDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStrEditDlg(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TStringListProperty;
class PASCALIMPLEMENTATION TStringListProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
protected:
	virtual TStrEditDlg* __fastcall EditDialog(void);
	virtual Classes::TStrings* __fastcall GetStrings(void);
	virtual void __fastcall SetStrings(const Classes::TStrings* Value);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TStringListProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TStringListProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TValueListProperty;
class PASCALIMPLEMENTATION TValueListProperty : public TStringListProperty 
{
	typedef TStringListProperty inherited;
	
protected:
	virtual TStrEditDlg* __fastcall EditDialog(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TValueListProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TStringListProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TValueListProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Stredit */
using namespace Stredit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StrEdit
