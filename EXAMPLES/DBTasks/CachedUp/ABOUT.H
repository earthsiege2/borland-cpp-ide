//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef aboutH
#define aboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
void __fastcall ShowAboutDialog();

class TAboutDialog : public TForm
{
__published:    // IDE-managed Components 
    TPanel *Panel1;
    TImage *ProgramIcon;
    TLabel *ProductName;
    TLabel *Version;
    TMemo *AboutMemo;
    TButton *OKButton;
private:        // User declarations
public:         // User declarations
    virtual __fastcall TAboutDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TAboutDialog *AboutDialog;
//---------------------------------------------------------------------------
#endif
