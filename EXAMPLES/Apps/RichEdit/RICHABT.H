//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// _RichAbt.hpp - dcc32 generated hdr (DO NOT EDIT) rev: -10
// From: _RichAbt.pas
//----------------------------------------------------------------------------
#ifndef RichAbtH
#define RichAbtH
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
//----------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:
	TImage *ProgramIcon;
	TLabel *Label1;
	TBevel *Bevel1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *PhysMem;
	TLabel *Label4;
	TLabel *FreeRes;
	TButton *OKButton;
	void __fastcall FormShow(TObject *Sender);
public:
    virtual __fastcall TForm2(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TForm2 *Form2;
//----------------------------------------------------------------------------
#endif	
