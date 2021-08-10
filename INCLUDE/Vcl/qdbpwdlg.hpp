// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QDBPWDlg.pas' rev: 6.00

#ifndef QDBPWDlgHPP
#define QDBPWDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qdbpwdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPasswordDialog;
class PASCALIMPLEMENTATION TPasswordDialog : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TGroupBox* GroupBox1;
	Qstdctrls::TEdit* Edit;
	Qstdctrls::TButton* AddButton;
	Qstdctrls::TButton* RemoveButton;
	Qstdctrls::TButton* RemoveAllButton;
	Qstdctrls::TButton* OKButton;
	Qstdctrls::TButton* CancelButton;
	void __fastcall EditChange(System::TObject* Sender);
	void __fastcall AddButtonClick(System::TObject* Sender);
	void __fastcall RemoveButtonClick(System::TObject* Sender);
	void __fastcall RemoveAllButtonClick(System::TObject* Sender);
	void __fastcall OKButtonClick(System::TObject* Sender);
	
private:
	bool PasswordAdded;
	Db::_di_IDBSession FSession;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPasswordDialog(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPasswordDialog(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPasswordDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TPasswordDialog(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall PasswordDialog(const Db::_di_IDBSession ASession);

}	/* namespace Qdbpwdlg */
using namespace Qdbpwdlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QDBPWDlg
