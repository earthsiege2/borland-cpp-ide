//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef QueryFrmH
#define QueryFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <IniFiles.hpp>
#include "ResltFrm.h"
#include "SaveQAs.h"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TAdhocForm : public TForm
{
__published:    // IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TBevel *Bevel1;
    TComboBox *AliasCombo;
    TEdit *NameEdit;
    TEdit *PasswordEdit;
    TButton *ExecuteBtn;
    TButton *CloseBtn;
    TComboBox *SavedQueryCombo;
    TButton *SaveBtn;
    TButton *SaveAsBtn;
    TButton *NewBtn;
	TRichEdit *QueryEdit;
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ExecuteBtnClick(TObject *Sender);
	void __fastcall NewBtnClick(TObject *Sender);
	void __fastcall SaveBtnClick(TObject *Sender);
	void __fastcall SaveAsBtnClick(TObject *Sender);
	void __fastcall CloseBtnClick(TObject *Sender);
	void __fastcall SavedQueryComboChange(TObject *Sender);
private:        // User declarations
    AnsiString QueryName, OldAlias;
    TIniFile* SavedQueries;
    bool Unnamed;
    bool __fastcall IsModified(void);
	bool __fastcall CheckModified(void);
    void __fastcall Unmodify(void);
    void __fastcall ReadQuery(void);
    void __fastcall SaveQuery(void);
    void __fastcall SaveQueryAs(void);
    void __fastcall CreateInitialIni();
    AnsiString __fastcall UniqueName();

public:         // User declarations
    virtual __fastcall TAdhocForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TAdhocForm *AdhocForm;
//---------------------------------------------------------------------------
#endif
