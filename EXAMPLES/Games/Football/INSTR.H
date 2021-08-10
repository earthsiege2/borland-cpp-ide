//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef instrH
#define instrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAbout : public TForm
{
__published:    // IDE-managed Components 
    TMemo *Memo1;
    TLabel *Label1;
    TButton *Button1;
private:        // User declarations
public:         // User declarations
    virtual __fastcall TAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TAbout *About;
//---------------------------------------------------------------------------
#endif
