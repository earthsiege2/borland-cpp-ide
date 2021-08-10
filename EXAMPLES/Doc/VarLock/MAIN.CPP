//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "main.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TLockingVariantForm *LockingVariantForm;

//---------------------------------------------------------------------------
__fastcall TLockingVariantForm::TLockingVariantForm(TComponent* Owner)
  : TForm(Owner),HighVal(14)
{
}
//---------------------------------------------------------------------------
Variant __fastcall TLockingVariantForm::GetArray(){
//	Variant V;
	int I, J;
//    Integer* p = new int(HighVal * HighVal);
//	V = VarArrayCreate(p, HighVal * HighVal, varInteger);

    Variant V(OPENARRAY(int,(0,HighVal,0,HighVal)),varInteger);
	for (I = 0; I < HighVal; I++){
		for (J = 0; J < HighVal; J++){
			V.PutElement(I+J,I,J);
                }
        }

	return V;
}

void __fastcall TLockingVariantForm::bLockAryClick(TObject *Sender)
{
//  TData = array[0..HighVal, 0..HighVal] of Integer;

  int I, J;
  Variant V;
  int* Data;

  V = GetArray();

  Data = (int*) V.ArrayLock();

  try{
    for (I = 0; I < HighVal; I++){
      for (J = 0; J < HighVal; J++){
        Grid->Cells[I][J] = IntToStr(Data[I+J]);
      }
    }
  }
  catch(...){
	V.ArrayUnlock();
  }
 V.ArrayUnlock();
}
//---------------------------------------------------------------------

