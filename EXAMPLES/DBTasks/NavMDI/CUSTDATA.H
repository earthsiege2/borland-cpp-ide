//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef CustDataH
#define CustDataH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfmCustomer : public TForm
{
__published:    // IDE-managed Components 
    TDBGrid *DBGrid1;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfmCustomer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmCustomer *fmCustomer;
//---------------------------------------------------------------------------
#endif
