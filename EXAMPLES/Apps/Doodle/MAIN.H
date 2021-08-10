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
#include <ExtCtrls.hpp>
// constants for custom cursors
const int crFill  = 5;
const int crPlus  = 6;
const int crDraw  = 7;
const int crErase = 8;
//---------------------------------------------------------------------------
class TDoodleForm : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
    int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y);
    void __fastcall FormActivate(TObject *Sender);
   void __fastcall FormShow(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    int InitialX;
    int InitialY;
    TImage *TmpImage;
    void __fastcall DrawShape(int X, int Y);
public:		// User declarations
    virtual __fastcall TDoodleForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDoodleForm *DoodleForm;
//---------------------------------------------------------------------------
#endif
 