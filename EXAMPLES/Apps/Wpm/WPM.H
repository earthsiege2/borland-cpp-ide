//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef wpmH
#define wpmH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
    TTimer *Timer1;
    TRichEdit *RichEdit1;
    TLabel *Label1;
    TProgressBar *ProgressBar1;
    TButton *Button1;
    TButton *Button2;
    TLabel *Label2;
    void __fastcall IncrementBar(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    int __fastcall CalculateWPM(void);
    void __fastcall StartTimer(TObject *Sender, Word &Key,
      TShiftState Shift);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
