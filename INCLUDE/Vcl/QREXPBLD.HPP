// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRExpbld.pas' rev: 5.00

#ifndef QRExpbldHPP
#define QRExpbldHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <qr3const.hpp>	// Pascal unit
#include <QRExpr.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Qrexpbld
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TQRExpressionBuilder;
class PASCALIMPLEMENTATION TQRExpressionBuilder : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* MainPage;
	Extctrls::TPanel* DataFieldPage;
	Extctrls::TPanel* FunctionPage;
	Extctrls::TPanel* FuncParamsPage;
	Stdctrls::TLabel* Heading;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TButton* InsertDataFieldBtn;
	Stdctrls::TButton* InsertFunctionBtn;
	Stdctrls::TButton* InsertVariableBtn;
	Stdctrls::TButton* AddPlus;
	Stdctrls::TButton* AddMinus;
	Stdctrls::TButton* AddMul;
	Stdctrls::TButton* AddDiv;
	Stdctrls::TButton* AddEqual;
	Stdctrls::TButton* AddSmaller;
	Stdctrls::TButton* AddLarger;
	Stdctrls::TButton* AddNotEqual;
	Stdctrls::TButton* AddLessEqual;
	Stdctrls::TButton* AddGreaterEqual;
	Stdctrls::TButton* AddNot;
	Stdctrls::TButton* AddAnd;
	Stdctrls::TButton* AddOr;
	Stdctrls::TButton* ValidateBtn;
	Stdctrls::TButton* Clear;
	Stdctrls::TButton* OK;
	Stdctrls::TButton* Cancel;
	Stdctrls::TButton* DataFieldOKBtn;
	Stdctrls::TButton* DataFieldCancelBtn;
	Stdctrls::TGroupBox* DataFieldGB;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* Label3;
	Stdctrls::TComboBox* DataSet;
	Stdctrls::TListBox* DataField;
	Stdctrls::TButton* FunctionOKBtn;
	Stdctrls::TButton* FunctionCancelBtn;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label5;
	Stdctrls::TListBox* AvailableFields;
	Stdctrls::TGroupBox* GroupBox4;
	Stdctrls::TListBox* Categories;
	Stdctrls::TLabel* Label6;
	Stdctrls::TListBox* AvailableFunc;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* FuncName;
	Stdctrls::TLabel* FuncDescription;
	Stdctrls::TGroupBox* GroupBox3;
	Stdctrls::TLabel* CopyFuncName;
	Stdctrls::TLabel* CopyFuncDescription;
	Forms::TScrollBox* FuncParamSB;
	Stdctrls::TButton* FuncParamOkBtn;
	Stdctrls::TButton* FuncArgCancelBtn;
	Stdctrls::TListBox* AvailableDatasets;
	Extctrls::TPanel* VariablePage;
	Stdctrls::TGroupBox* GroupBox5;
	Stdctrls::TButton* VariableOKBtn;
	Stdctrls::TButton* VariableCancelBtn;
	Stdctrls::TListBox* AvailableVariables;
	Stdctrls::TLabel* VariableValue;
	Stdctrls::TLabel* Label1;
	Stdctrls::TButton* ModifyVariables;
	void __fastcall InsertDataFieldBtnClick(System::TObject* Sender);
	void __fastcall DataFieldCancelBtnClick(System::TObject* Sender);
	void __fastcall DataFieldOKBtnClick(System::TObject* Sender);
	void __fastcall FunctionOKBtnClick(System::TObject* Sender);
	void __fastcall CategoriesClick(System::TObject* Sender);
	void __fastcall AvailableFuncClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall InsertFunctionBtnClick(System::TObject* Sender);
	void __fastcall FuncParamOkBtnClick(System::TObject* Sender);
	void __fastcall FuncArgCancelBtnClick(System::TObject* Sender);
	void __fastcall FunctionCancelBtnClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall AddSomeClick(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall AvailableDatasetsClick(System::TObject* Sender);
	void __fastcall OKClick(System::TObject* Sender);
	void __fastcall CancelClick(System::TObject* Sender);
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall ValidateBtnClick(System::TObject* Sender);
	void __fastcall InsertVariableBtnClick(System::TObject* Sender);
	void __fastcall VariableOKBtnClick(System::TObject* Sender);
	void __fastcall VariableCancelBtnClick(System::TObject* Sender);
	void __fastcall AvailableVariablesClick(System::TObject* Sender);
	void __fastcall ModifyVariablesClick(System::TObject* Sender);
	
private:
	Stdctrls::TEdit* Expr;
	int FFuncParamsResult;
	int FFuncResult;
	int FDatafieldResult;
	int FExprResult;
	Forms::TCustomForm* FDatasetForm;
	int FVariableResult;
	Qrexpr::TQREvEnvironment* FLocalEnvironment;
	void __fastcall GetParamExprClick(System::TObject* Sender);
	void __fastcall GetFunctionsCat(int Index);
	void __fastcall SelectFunc(int Index);
	void __fastcall InsertText(AnsiString AText);
	void __fastcall PickDataSets(void);
	void __fastcall PickVariables(void);
	bool __fastcall GetParams(AnsiString ParamList, AnsiString &ParamResult);
	bool __fastcall GetFunc(AnsiString &Func);
	bool __fastcall GetDatafield(AnsiString &Field);
	bool __fastcall GetVariable(AnsiString &Variable);
	
public:
	__property Forms::TCustomForm* DatasetForm = {read=FDatasetForm, write=FDatasetForm};
	__property Qrexpr::TQREvEnvironment* LocalEnvironment = {read=FLocalEnvironment, write=FLocalEnvironment
		};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TQRExpressionBuilder(Classes::TComponent* AOwner
		) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TQRExpressionBuilder(Classes::TComponent* AOwner
		, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TQRExpressionBuilder(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRExpressionBuilder(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall GetExpression(AnsiString ACaption, AnsiString &Value, Forms::TCustomForm* 
	ADataSetForm, Controls::TWinControl* AParentControl, Qrexpr::TQREvEnvironment* ALocalEnvironment);

}	/* namespace Qrexpbld */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Qrexpbld;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRExpbld
