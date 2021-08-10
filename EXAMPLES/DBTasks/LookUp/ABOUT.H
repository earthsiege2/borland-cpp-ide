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
//---------------------------------------------------------------------------
class TfmAbout : public TForm
{
__published:    // IDE-managed Components 
    TMemo *Memo1;
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfmAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfmAbout *fmAbout;
//---------------------------------------------------------------------------
#endif
