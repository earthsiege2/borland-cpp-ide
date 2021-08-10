//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef ndxrebuH
#define ndxrebuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:    // IDE-managed Components 
    TLabel *Label1;
    TLabel *Label2;
    TComboBox *cbAlias;
    TComboBox *cbTable;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TStatusBar *StatusBar1;
    TTable *tblIndex;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall cbAliasChange(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    
    
private:        // User declarations
public:         // User declarations
    virtual __fastcall TFormMain(TComponent* Owner);
    void __fastcall HandleExceptions(TObject *Sender, Exception *E);
    bool __fastcall RebuildIndexes(AnsiString strAlias, AnsiString strTable,
    AnsiString& strError);
    void __fastcall WriteMsg(AnsiString strWrite);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
