// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QDBLogDlg.pas' rev: 6.00

#ifndef QDBLogDlgHPP
#define QDBLogDlgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qdblogdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLoginDialog;
class PASCALIMPLEMENTATION TLoginDialog : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qextctrls::TPanel* Panel;
	Qextctrls::TBevel* Bevel;
	Qstdctrls::TLabel* DatabaseName;
	Qstdctrls::TButton* OKButton;
	Qstdctrls::TButton* CancelButton;
	Qextctrls::TPanel* Panel1;
	Qstdctrls::TLabel* Label1;
	Qstdctrls::TLabel* Label2;
	Qstdctrls::TLabel* Label3;
	Qstdctrls::TEdit* Password;
	Qstdctrls::TEdit* UserName;
	void __fastcall FormShow(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TLoginDialog(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLoginDialog(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLoginDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TLoginDialog(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall LoginDialog(const AnsiString ADatabaseName, AnsiString &AUserName, AnsiString &APassword);
extern PACKAGE bool __fastcall LoginDialogEx(const AnsiString ADatabaseName, AnsiString &AUserName, AnsiString &APassword, bool NameReadOnly);
extern PACKAGE bool __fastcall RemoteLoginDialog(AnsiString &AUserName, AnsiString &APassword);
extern PACKAGE void __fastcall SetCursorType(const int CurIndex);

}	/* namespace Qdblogdlg */
using namespace Qdblogdlg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QDBLogDlg
