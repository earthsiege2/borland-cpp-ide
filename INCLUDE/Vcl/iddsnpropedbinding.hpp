// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdDsnPropEdBinding.pas' rev: 6.00

#ifndef IdDsnPropEdBindingHPP
#define IdDsnPropEdBindingHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddsnpropedbinding
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdPropEdBindingEntry;
class PASCALIMPLEMENTATION TIdPropEdBindingEntry : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* btnOk;
	Stdctrls::TButton* btnCancel;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TListBox* lstBindings;
	Stdctrls::TButton* btnAdd;
	Stdctrls::TButton* btnRemove;
	Stdctrls::TComboBox* cmbPort;
	Stdctrls::TComboBox* cmbHostname;
	Actnlist::TActionList* actBndEditor;
	Actnlist::TAction* actAdd;
	Actnlist::TAction* actRemove;
	void __fastcall lstBindingsClick(System::TObject* Sender);
	void __fastcall actAddExecute(System::TObject* Sender);
	void __fastcall actAddUpdate(System::TObject* Sender);
	void __fastcall actRemoveExecute(System::TObject* Sender);
	void __fastcall actRemoveUpdate(System::TObject* Sender);
	void __fastcall cmbPortKeyPress(System::TObject* Sender, char &Key);
	void __fastcall cmbHostnameKeyPress(System::TObject* Sender, char &Key);
	
private:
	void __fastcall ValidateAddBinding(void);
	void __fastcall SetHostname(const AnsiString Value);
	void __fastcall SetPort(const int Value);
	AnsiString __fastcall PortDescription(const int PortNumber);
	AnsiString __fastcall GetHostname();
	int __fastcall GetPort(void);
	void __fastcall SetBinding(const AnsiString Binding);
	AnsiString __fastcall GetBinding();
	
public:
	__fastcall virtual TIdPropEdBindingEntry(Classes::TComponent* AOwner);
	void __fastcall SetList(const AnsiString Arg);
	AnsiString __fastcall GetList();
	__property AnsiString Binding = {read=GetBinding, write=SetBinding};
	__property AnsiString Hostname = {read=GetHostname, write=SetHostname};
	__property int Port = {read=GetPort, write=SetPort, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TIdPropEdBindingEntry(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TIdPropEdBindingEntry(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TIdPropEdBindingEntry(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TIdPropEdBinding;
class PASCALIMPLEMENTATION TIdPropEdBinding : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TIdPropEdBinding(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TIdPropEdBinding(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Iddsnpropedbinding */
using namespace Iddsnpropedbinding;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdDsnPropEdBinding
