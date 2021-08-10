//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// SaveQAs.hpp - dcc32 generated hdr (DO NOT EDIT) rev: 0
// From: SaveQAs.pas
//----------------------------------------------------------------------------
#ifndef SaveQAsHPP
#define SaveQAsHPP
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
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
//-- type declarations -------------------------------------------------------
class TSaveQueryAs : public TForm
{
	typedef TForm inherited;
	
__published:
	TEdit* NameEdit;
	TLabel* Label1;
	TBevel* Bevel1;
	TButton* OKBtn;
	TButton* CancelBtn;
	void __fastcall NameEditChange(TObject* Sender);
public:
	__fastcall virtual TSaveQueryAs(TComponent* AOwner);
	__fastcall virtual ~TSaveQueryAs(void);
};

//-- var, const, procedure ---------------------------------------------------
extern bool __fastcall GetNewName( AnsiString &QueryName);
//-- end unit ----------------------------------------------------------------
#endif	// SaveQAs
