//---------------------------------------------------------------------------
//      Example Program:  Briefcase
//      File:  BriefCaseMain.h
//      Description:  Declaration file for the Briefcase example
//      Copyright (c) 1987, 1999-2002 Borland International Inc. All Rights Reserved.
//---------------------------------------------------------------------------
#ifndef BriefCaseMainH
#define BriefCaseMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <DB.hpp>
#include <String>


//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlPanel;
        TDBGrid *dbgrdDataDisplay;
        TADOConnection *adocnctnConnection;
        TButton *btnUpdateButton;
        TButton *btnRefreshButton;
        TButton *btnSaveButton;
        TCheckBox *ckbxConnectionInd;
        TADODataSet *adodsEmployees;
        TDataSource *dsEmpSource;
        void __fastcall ckbxConnectionIndClick(TObject *Sender);
        void __fastcall btnUpdateButtonClick(TObject *Sender);
        void __fastcall btnRefreshButtonClick(TObject *Sender);
        void __fastcall btnSaveButtonClick(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
        String DataFileName;
        String BaseFileName;
public:		// User declarations
        __fastcall TfrmMain(TComponent* Owner);
        void __fastcall LoadData();
        void __fastcall UpdateData();
        void __fastcall SaveData();

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
