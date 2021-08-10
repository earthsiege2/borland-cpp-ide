//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef lookupH
#define lookupH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Menus.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfmLookup : public TForm
{
__published:    // IDE-managed Components 
    TPanel *Panel1;
    TDBNavigator *DBNavigator1;
    TMainMenu *MainMenu1;
    TMenuItem *About1;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    void __fastcall About1Click(TObject *Sender);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfmLookup(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmLookup *fmLookup;
//---------------------------------------------------------------------------
#endif
