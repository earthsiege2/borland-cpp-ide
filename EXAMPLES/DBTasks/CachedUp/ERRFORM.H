//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef errformH
#define errformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <System.hpp>
#include <Db.hpp>
#include <Dbtables.hpp>
//---------------------------------------------------------------------------
class TUpdateErrorForm : public TForm
{
__published:    // IDE-managed Components 
    TLabel *Label1;
    TLabel *UpdateType;
    TLabel *Label3;
    TLabel *ErrorText;
    TStringGrid *UpdateData;
    TButton *RetryButton;
    TButton *SkipButton;
    TButton *AbortButton;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall UpdateDataSetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value);
    void __fastcall FormCreate(TObject *Sender);
private:        // User declarations
    TStringList *FDataFields;
    void __fastcall GetFieldValues(TDataSet *DataSet);
    void __fastcall SetFieldValues(TDataSet *DataSet);
public:         // User declarations
    virtual __fastcall TUpdateErrorForm(TComponent* Owner);
    TUpdateAction __fastcall HandleError(TDataSet *DataSet, EDatabaseError *E,
      TUpdateKind UpdateKind);
};
//---------------------------------------------------------------------------
extern TUpdateErrorForm *UpdateErrorForm;
//---------------------------------------------------------------------------
#endif
