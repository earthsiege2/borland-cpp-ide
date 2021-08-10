//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//-----------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//-----------------------------------------------------------------------
#ifndef MainH
#define MainH
//-----------------------------------------------------------------------
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>
//-----------------------------------------------------------------------
class TVariantArrayForm : public TForm
{
__published:
  TButton *bOneDim;
  TButton *bTwoDim;
  void __fastcall bOneDimClick(TObject* Sender);
  void __fastcall bTwoDimClick(TObject* Sender);
private:
public:
  virtual __fastcall TVariantArrayForm(TComponent* AOwner);
  virtual __fastcall ~TVariantArrayForm(void);

};

//-----------------------------------------------------------------------
extern TVariantArrayForm *VariantArrayForm;
//-----------------------------------------------------------------------
#endif

