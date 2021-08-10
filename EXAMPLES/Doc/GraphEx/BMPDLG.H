//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef BmpdlgH
#define BmpdlgH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TNewBMPForm : public TForm
{
__published:
        TButton *OKBtn;
        TButton *CancelBtn;
        TBevel *Bevel1;
        TLabel *Label1;
        TEdit *WidthEdit;
        TLabel *Label2;
        TEdit *HeightEdit;

private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TNewBMPForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TNewBMPForm *NewBMPForm;
//---------------------------------------------------------------------------
#endif
