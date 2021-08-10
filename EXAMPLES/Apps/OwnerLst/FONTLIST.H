//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FontListH
#define FontListH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
    TListBox *ListBox1;
    TLabel *Label1;
    TLabel *FontLabel;
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall DrawItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State);
    void __fastcall ListBox1MeasureItem(TWinControl *Control,
      int Index, int &Height);
    void __fastcall FormCreate(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
