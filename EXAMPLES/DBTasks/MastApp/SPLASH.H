//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef splashH
#define splashH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TSplashForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TImage *Image1;
	TLabel *Label3;
	TBevel *Bevel1;
	TLabel *Label1;
private:	// User declarations
public:		// User declarations
	virtual __fastcall TSplashForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TSplashForm *SplashForm;
//---------------------------------------------------------------------------
#endif
