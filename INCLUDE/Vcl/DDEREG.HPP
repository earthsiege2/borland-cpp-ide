// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DDEReg.pas' rev: 5.00

#ifndef DDERegHPP
#define DDERegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <DdeMan.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ddereg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSrvrConvEdit;
class PASCALIMPLEMENTATION TSrvrConvEdit : public Dsgnintf::TDefaultEditor 
{
	typedef Dsgnintf::TDefaultEditor inherited;
	
protected:
	virtual void __fastcall EditProperty(Dsgnintf::TPropertyEditor* PropertyEditor, bool &Continue, bool 
		&FreeEditor);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TSrvrConvEdit(Classes::TComponent* AComponent
		, Dsgnintf::_di_IFormDesigner ADesigner) : Dsgnintf::TDefaultEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSrvrConvEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCliConvEdit;
class PASCALIMPLEMENTATION TCliConvEdit : public Dsgnintf::TDefaultEditor 
{
	typedef Dsgnintf::TDefaultEditor inherited;
	
protected:
	virtual void __fastcall EditProperty(Dsgnintf::TPropertyEditor* PropertyEditor, bool &Continue, bool 
		&FreeEditor);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TCliConvEdit(Classes::TComponent* AComponent
		, Dsgnintf::_di_IFormDesigner ADesigner) : Dsgnintf::TDefaultEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TCliConvEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSrvrItemEdit;
class PASCALIMPLEMENTATION TSrvrItemEdit : public Dsgnintf::TDefaultEditor 
{
	typedef Dsgnintf::TDefaultEditor inherited;
	
public:
	virtual void __fastcall Copy(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TSrvrItemEdit(Classes::TComponent* AComponent
		, Dsgnintf::_di_IFormDesigner ADesigner) : Dsgnintf::TDefaultEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSrvrItemEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDdeLinkDlg;
class PASCALIMPLEMENTATION TDdeLinkDlg : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TEdit* TopicEdit;
	Stdctrls::TEdit* AppEdit;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TButton* OK;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* PasteBtn;
	Stdctrls::TButton* HelpBtn;
	void __fastcall doPasteLink(System::TObject* Sender);
	void __fastcall DoPasteCheck(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	
private:
	HIDESBASE MESSAGE void __fastcall WMActivate(Messages::TWMActivate &Message);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDdeLinkDlg(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDdeLinkDlg(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDdeLinkDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDdeLinkDlg(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


class DELPHICLASS TDdeLinkInfoProperty;
class PASCALIMPLEMENTATION TDdeLinkInfoProperty : public Dsgnintf::TPropertyEditor 
{
	typedef Dsgnintf::TPropertyEditor inherited;
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
	virtual AnsiString __fastcall GetValue();
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDdeLinkInfoProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDdeLinkInfoProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDdeClientItemProperty;
class PASCALIMPLEMENTATION TDdeClientItemProperty : public Dsgnintf::TStringProperty 
{
	typedef Dsgnintf::TStringProperty inherited;
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TDdeClientItemProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TDdeClientItemProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Ddereg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ddereg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DDEReg
