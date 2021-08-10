//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef AboutH
#define AboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TfmAboutBox : public TForm
{
__published:    // IDE-managed Components 
    TPanel *Panel1;
    TLabel *ProductName;
    TLabel *Version;
    TMemo *Memo1;
    TButton *OKButton;
    TImage *ProgramIcon;
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfmAboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmAboutBox *fmAboutBox;
//---------------------------------------------------------------------------
#endif
