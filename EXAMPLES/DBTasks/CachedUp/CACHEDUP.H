//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef cachedupH
#define cachedupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dbtables.hpp>
//---------------------------------------------------------------------------
class TCacheDemoForm : public TForm
{
__published:    // IDE-managed Components 
    TDBGrid *DBGrid1;
    TDBNavigator *DBNavigator1;
    TGroupBox *GroupBox1;
    TCheckBox *UnModifiedCB;
    TCheckBox *ModifiedCB;
    TCheckBox *InsertedCB;
    TCheckBox *DeletedCB;
    TPanel *Panel1;
    TCheckBox *CachedUpdates;
    TCheckBox *UseUpdateSQL;
    TPanel *Panel2;
    TButton *ApplyUpdatesBtn;
    TButton *CancelUpdatesBtn;
    TButton *RevertRecordBtn;
    TButton *ReExecuteButton;
    TMainMenu *MainMenu1;
    TMenuItem *miAbout;
    void __fastcall ReExecuteButtonClick(TObject *Sender);
    void __fastcall ToggleUpdateMode(TObject *Sender);
    void __fastcall UseUpdateSQLClick(TObject *Sender);
    void __fastcall ApplyUpdatesBtnClick(TObject *Sender);
    void __fastcall CancelUpdatesBtnClick(TObject *Sender);
    void __fastcall RevertRecordBtnClick(TObject *Sender);
    void __fastcall UpdateRecordsToShow(TObject *Sender);
    void __fastcall miAboutClick(TObject *Sender);
private:        // User declarations
    TDBDataSet *FDataSet;
    void __fastcall SetControlStates(BOOL Enabled);
public:         // User declarations
    virtual __fastcall TCacheDemoForm(TComponent* Owner);
    void __fastcall SetDataSet(TDataSet *DataSet);
};
//---------------------------------------------------------------------------
extern TCacheDemoForm *CacheDemoForm;
//---------------------------------------------------------------------------
#endif
