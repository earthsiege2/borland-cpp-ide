// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRDatasu.pas' rev: 6.00

#ifndef QRDatasuHPP
#define QRDatasuHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QRMDSU.hpp>	// Pascal unit
#include <QREditor.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <FileCtrl.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrdatasu
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRDataSetup;
class PASCALIMPLEMENTATION TQRDataSetup : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TRadioGroup* DataType;
	Stdctrls::TGroupBox* AliasGB;
	Stdctrls::TButton* BrowseButton;
	Stdctrls::TComboBox* DataBaseName;
	Stdctrls::TGroupBox* TableGroup;
	Stdctrls::TComboBox* TableName;
	Stdctrls::TEdit* FilterExpression;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* FilterLabel;
	Stdctrls::TGroupBox* SQLGroup;
	Stdctrls::TMemo* SQL;
	Stdctrls::TButton* OpenSQL;
	Buttons::TBitBtn* OKButton;
	Buttons::TBitBtn* BitBtn2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TComboBox* IndexName;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TCheckBox* MDEnable;
	Stdctrls::TButton* MDSetupButton;
	void __fastcall DataTypeClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall BrowseButtonClick(System::TObject* Sender);
	void __fastcall DataBaseNameChange(System::TObject* Sender);
	void __fastcall TableNameChange(System::TObject* Sender);
	void __fastcall SQLChange(System::TObject* Sender);
	void __fastcall OKButtonClick(System::TObject* Sender);
	void __fastcall MDEnableClick(System::TObject* Sender);
	void __fastcall MDSetupButtonClick(System::TObject* Sender);
	
private:
	Quickrpt::TQuickRep* FReport;
	Dbtables::TTable* TableComp;
	Dbtables::TQuery* QueryComp;
	Db::TDataSource* MasterDS;
	Dbtables::TTable* DetailTable;
	Qreditor::TQRCustomEditor* FReportEditor;
	Quickrpt::TQRSubDetail* FSubDetail;
	
protected:
	void __fastcall GetEditValues(void);
	void __fastcall SetReport(Quickrpt::TQuickRep* Value);
	void __fastcall SetData(void);
	
public:
	__property Quickrpt::TQuickRep* QuickRep = {read=FReport, write=SetReport};
	__property Quickrpt::TQRSubDetail* SubDetail = {read=FSubDetail, write=FSubDetail};
	__property Qreditor::TQRCustomEditor* ReportEditor = {read=FReportEditor, write=FReportEditor};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRDataSetup(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRDataSetup(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRDataSetup(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRDataSetup(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TQRDataSetup* QRDataSetup;

}	/* namespace Qrdatasu */
using namespace Qrdatasu;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRDatasu
