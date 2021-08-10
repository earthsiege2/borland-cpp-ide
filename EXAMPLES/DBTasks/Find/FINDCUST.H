//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FindCustH
#define FindCustH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfmFindCust : public TForm
{
__published:
    TDBGrid* DBGrid1;
    TComboBox* ComboBox1;
    TEdit* Edit1;
    TLabel* Label1;
    TLabel* Label2;
    TBevel* Bevel1;
    TCheckBox* cbUseFilter;
    TButton* Button1;
    TButton* Button2;
    void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TfmFindCust(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmFindCust *fmFindCust;
//---------------------------------------------------------------------------
#endif
