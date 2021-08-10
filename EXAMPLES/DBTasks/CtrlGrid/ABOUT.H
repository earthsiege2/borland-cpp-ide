//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFMAboutBox : public TForm
{
__published:
    TPanel *Panel1;
    TImage *ProgramIcon;
    TLabel *ProductName;
    TLabel *Version;
    TMemo *Memo1;
    TButton *OKButton;
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFMAboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFMAboutBox *FMAboutBox;
//---------------------------------------------------------------------------
#endif
