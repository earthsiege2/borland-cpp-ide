//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
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
class TFmAboutBox : public TForm
{
__published:    // IDE-managed Components 
    TPanel *Panel1;
    TImage *ProgramIcon;
    TLabel *ProductName;
    TLabel *Version;
    TPanel *Panel2;
    TLabel *Label2;
    TImage *Image1;
    TMemo *Memo1;
    TButton *Button1;
private:        // User declarations
public:         // User declarations
    virtual __fastcall TFmAboutBox(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFmAboutBox *FmAboutBox;
//---------------------------------------------------------------------------
#endif
