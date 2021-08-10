//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormClrDlg : public TForm
{
__published:	// IDE-managed Components 
    TColorDialog *ColorDialog;
    TButton *Button;
    TPanel *Panel1;
    void __fastcall ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual __fastcall TFormClrDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormClrDlg *FormClrDlg;
//---------------------------------------------------------------------------
#endif
