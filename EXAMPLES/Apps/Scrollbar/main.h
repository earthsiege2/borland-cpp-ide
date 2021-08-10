//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
    TScrollBar *ScrollBar1;
    TLabel *Label2;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TEdit *PosEdit;
    TButton *Button1;
    TLabel *Label3;
    TEdit *MinEdit;
    TLabel *Label4;
    TEdit *MaxEdit;
    TLabel *Label5;
    TEdit *LargeEdit;
    TLabel *Label6;
    TEdit *SmallEdit;
    void __fastcall ScrollBar1Scroll(TObject *Sender, TScrollCode ScrollCode,
    int &ScrollPos);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    
    void __fastcall EnableButton(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
