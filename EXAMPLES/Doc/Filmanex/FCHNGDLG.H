//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef UchngdlgH
#define UchngdlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TChangeDlg : public TForm
{
__published:	// IDE-managed Components 
	TBevel *Bevel1;
	TLabel *CurrentDir;
	TLabel *Label1;
	TLabel *Label2;
	TButton *OKBtn;
	TButton *CanBtn;
	TEdit *ToFileName;
	TEdit *FromFileName;

private:	// User declarations
public:		// User declarations
	virtual __fastcall TChangeDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TChangeDlg *ChangeDlg;
//---------------------------------------------------------------------------
#endif
