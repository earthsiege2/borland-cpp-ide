//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MDIFrameH
#define MDIFrameH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFrameForm : public TForm
{
__published:	// IDE-managed Components 
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *N1;
    TMenuItem *Exit1;
    TMenuItem *Window1;
    TMenuItem *Tile1;
    TMenuItem *Cascade1;
    TMenuItem *Arrangeicons1;
    TOpenDialog *OpenFileDialog;
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Tile1Click(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall Arrangeicons1Click(TObject *Sender);
    
    
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    virtual __fastcall TFrameForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrameForm *FrameForm;
//---------------------------------------------------------------------------
#endif
