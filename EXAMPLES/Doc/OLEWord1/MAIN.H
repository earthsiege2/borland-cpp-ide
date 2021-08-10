//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
    TImage *Image1;
    TBitBtn *TalkToWord;
    void __fastcall TalkToWordClick(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
