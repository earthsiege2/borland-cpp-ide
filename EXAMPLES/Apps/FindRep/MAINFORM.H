//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit1;
	TFindDialog *FindDialog1;
	TReplaceDialog *ReplaceDialog1;
	TMainMenu *MainMenu1;
	TMenuItem *Edit1;
	TMenuItem *Find1;
	TMenuItem *Replace1;
	void __fastcall Find1Click(TObject *Sender);
    void __fastcall Replace1Click(TObject *Sender);
    void __fastcall Find(TObject *Sender);
    void __fastcall Replace(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
