//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef UFilAttrH
#define UFilAttrH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFileAttrDlg : public TForm
{
__published:	// IDE-managed Components 
	TBevel *Bevel1;
	TLabel *FileDirName;
	TLabel *FilePathName;
	TLabel *ChangeDate;
	TButton *OKBtn;
	TGroupBox *GroupBox1;
	TCheckBox *ReadOnly;
	TCheckBox *Archive;
	TCheckBox *System;
	TCheckBox *Hidden;
	TButton *Button1;
private:	// User declarations
public:		// User declarations
	virtual __fastcall TFileAttrDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFileAttrDlg *FileAttrDlg;
//---------------------------------------------------------------------------
#endif
