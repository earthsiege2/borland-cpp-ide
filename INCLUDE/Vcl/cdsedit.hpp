// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'CDSEdit.pas' rev: 6.00

#ifndef CDSEditHPP
#define CDSEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignIntf.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Cdsedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClientDataForm;
class PASCALIMPLEMENTATION TClientDataForm : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TListBox* DataSetList;
	Stdctrls::TButton* OkBtn;
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* HelpBtn;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall OkBtnClick(System::TObject* Sender);
	void __fastcall HelpBtnClick(System::TObject* Sender);
	void __fastcall DataSetListDblClick(System::TObject* Sender);
	void __fastcall DataSetListKeyPress(System::TObject* Sender, char &Key);
	
private:
	Dbclient::TClientDataSet* FDataSet;
	Designintf::_di_IDesigner FDesigner;
	void __fastcall CheckComponent(const AnsiString Value);
	bool __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClientDataForm(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClientDataForm(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClientDataForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TClientDataForm(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditClientDataSet(Dbclient::TClientDataSet* ADataSet, Designintf::_di_IDesigner ADesigner);
extern PACKAGE AnsiString __fastcall GetLoadFromFileName();
extern PACKAGE bool __fastcall LoadFromFile(Dbclient::TClientDataSet* ADataSet);
extern PACKAGE void __fastcall SaveToFile(Dbclient::TClientDataSet* ADataSet, Dbclient::TDataPacketFormat Format = (Dbclient::TDataPacketFormat)(0x0));

}	/* namespace Cdsedit */
using namespace Cdsedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CDSEdit
