//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 2000 Inprise Corp. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <Menus.hpp>
#include <Classes.hpp>
#include <Grids.hpp>
#include <Controls.hpp>
//---------------------------------------------------------------------------
class TLockingVariantForm : public TForm
{
__published:
    TMainMenu *MainMenu1;
    TMenuItem *UseLockedArray1;
    TStringGrid *Grid;
    void __fastcall bLockAryClick(TObject *Sender);
private:        // private user declarations
	const int HighVal;
	Variant __fastcall TLockingVariantForm::GetArray();

public:         // public user declarations
    virtual __fastcall TLockingVariantForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TLockingVariantForm *LockingVariantForm;
//---------------------------------------------------------------------------
#endif
