//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Tabs.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <Printers.hpp>
#include <cstring.h>

//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components 
        TTabSet *TabSet1;
        TPanel *Panel1;
        TMemo *Memo1;
        TPrintDialog *PrintDialog1;
        TSpeedButton *PrintBtn;
        void __fastcall PrintBtnClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall TabSet1Click(TObject *Sender);
        void __fastcall TabSet1Change(TObject *Sender, int NewTab,
      bool &AllowChange);
private:	// User declarations
        TStringList *pages[5];  // will contain the text for each page
        int currentpage;
        void __fastcall PrintPage(int page);
public:		// User declarations
        virtual __fastcall TFormMain(TComponent* Owner);
        virtual __fastcall ~TFormMain(void);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
