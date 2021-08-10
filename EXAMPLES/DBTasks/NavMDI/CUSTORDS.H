//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef CustOrdsH
#define CustOrdsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfmCustOrd : public TForm
{
__published:    // IDE-managed Components 
    TDBGrid *DBGrid1;
        TPanel *Panel1;
        TDBEdit *DBEdit1;
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall DBGrid1Enter(TObject *Sender);
    
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfmCustOrd(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmCustOrd *fmCustOrd;
//---------------------------------------------------------------------------
#endif
