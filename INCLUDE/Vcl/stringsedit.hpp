// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StringsEdit.pas' rev: 6.00

#ifndef StringsEditHPP
#define StringsEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StrEdit.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stringsedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStringsEditDlg;
class PASCALIMPLEMENTATION TStringsEditDlg : public Stredit::TStrEditDlg 
{
	typedef Stredit::TStrEditDlg inherited;
	
__published:
	Stdctrls::TLabel* LineCount;
	Extctrls::TBevel* Bevel1;
	Comctrls::TRichEdit* Memo;
	void __fastcall Memo1KeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall UpdateStatus(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	AnsiString SingleLine;
	AnsiString MultipleLines;
	
protected:
	virtual Classes::TStrings* __fastcall GetLines(void);
	virtual void __fastcall SetLines(const Classes::TStrings* Value);
	virtual Controls::TWinControl* __fastcall GetLinesControl(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TStringsEditDlg(Classes::TComponent* AOwner) : Stredit::TStrEditDlg(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TStringsEditDlg(Classes::TComponent* AOwner, int Dummy) : Stredit::TStrEditDlg(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TStringsEditDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStringsEditDlg(HWND ParentWindow) : Stredit::TStrEditDlg(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Stringsedit */
using namespace Stringsedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StringsEdit
