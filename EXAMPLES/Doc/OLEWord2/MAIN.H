//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TOleWordForm : public TForm
{
__published:
    TImage *Image1;
    TButton *TalkToWord;
    void __fastcall TalkToWordClick(TObject *Sender);
private:        // private user declarations
	Variant V;
public:         // public user declarations
    virtual __fastcall TOleWordForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TOleWordForm *OleWordForm;
//---------------------------------------------------------------------------
#endif
