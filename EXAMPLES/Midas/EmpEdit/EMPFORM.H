//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef EmpFormH
#define EmpFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <MConnect.hpp>
#include <MidasCon.hpp>
//---------------------------------------------------------------------------
class TEmployeeForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TDBText *DBText1;
        TDBEdit *FirstName;
        TDBEdit *LastName;
        TDBEdit *PhoneExt;
        TDBEdit *HireDate;
        TDBEdit *Salary;
        TButton *QueryButton;
        TDBNavigator *DBNavigator1;
        TButton *UpdateButton;
        TButton *UndoButton;
        TStatusBar *StatusBar1;
        TDataSource *EmpData;
        TClientDataSet *Employees;
        TDCOMConnection *DCOMConnection1;
        void __fastcall QueryButtonClick(TObject *Sender);
        void __fastcall UpdateButtonClick(TObject *Sender);
        void __fastcall UndoButtonClick(TObject *Sender);
        void __fastcall EmpDataDataChange(TObject *Sender, TField *Field);
    void __fastcall EmployeesReconcileError(TClientDataSet *DataSet,
          EReconcileError *E, TUpdateKind UpdateKind,
          TReconcileAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TEmployeeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TEmployeeForm *EmployeeForm;
//---------------------------------------------------------------------------
#endif
    