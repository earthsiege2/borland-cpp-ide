//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------
// Dlg.hpp - dcc32 generated hdr (DO NOT EDIT) rev: 0
// From: Dlg.pas
//---------------------------------------------------------------
#ifndef DlgHPP
#define DlgHPP
//---------------------------------------------------------------
#include <ComCtrls.hpp>
#include <ToolIntf.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <System.hpp>

#include "exconst.h"

//-- type declarations ------------------------------------------
enum TDlgAttr { daNothing, daMultPg, daBtnsH, daBtnsV };

typedef Set<TDlgAttr, daNothing, daBtnsV>  TDlgAttrs;

/////////////////////////////////////////// TDlgExpert //////////
__declspec(delphiclass) class TDlgExpert;
class TDlgExpert : public TForm
{
	typedef TForm inherited;

__published:
	TPaintBox* Sample;
	TButton* CancelBtn;
	TButton* PrevButton;
	TButton* NextButton;
	TPageControl* PageControl;
	TTabSheet* Style;
	TLabel* Label1;
	TRadioButton* rbSinglePage;
	TRadioButton* rbMultPg;
	TTabSheet* Pages;
	TLabel* Label3;
	TMemo* PageNames;
	TTabSheet* Buttons;
	TLabel* Label2;
	TRadioButton* RadioButton1;
	TRadioButton* rbBtnsV;
	TRadioButton* rbBtnsH;
	void __fastcall SamplePaint(TObject* Sender);
	void __fastcall FormCreate(TObject* Sender);
	void __fastcall FormDestroy(TObject* Sender);
	void __fastcall StyleClick(TObject* Sender);
	void __fastcall BtnClick(TObject* Sender);
	void __fastcall CancelClick(TObject* Sender);
	void __fastcall PrevClick(TObject* Sender);
	void __fastcall NextClick(TObject* Sender);

private:
  String FormName;
	TDlgAttrs Definition;
	Graphics::TBitmap* DrawBitmap;
	char *SourceBuffer;
	void __fastcall RefreshButtons(void);
	void __fastcall FmtWrite(TStream* Stream, char * Fmt,
                           const TVarRec *Args, const int Args_Size);
	TForm* __fastcall DoFormCreation(const AnsiString FormIdent);

public:
	TMemoryStream* __fastcall CreateHdrSource(const AnsiString UnitIdent, const AnsiString FormIdent);
	TMemoryStream* __fastcall CreateSource(const AnsiString UnitIdent, const AnsiString FormIdent);
	TMemoryStream* __fastcall CreateForm(const String FormID);

	 __fastcall TDlgExpert(TComponent* AOwner);
	 __fastcall TDlgExpert(HWND ParentWindow);
	 __fastcall TDlgExpert(TComponent* AOwner, int Dummy);
	 __fastcall virtual ~TDlgExpert(void);
};

//-- var, const, procedure --------------------------------------
extern TDlgExpert *DlgExpert;

extern void __stdcall DialogExpert(TIToolServices* ToolServices);
String MakeStr(const TVarRec &Args);

//-- end unit ---------------------------------------------------
#endif	// DlgHPP
