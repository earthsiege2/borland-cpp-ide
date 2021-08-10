// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ValueEdit.pas' rev: 6.00

#ifndef ValueEditHPP
#define ValueEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ValEdit.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
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

namespace Valueedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TValueEditDlg;
class PASCALIMPLEMENTATION TValueEditDlg : public Stredit::TStrEditDlg 
{
	typedef Stredit::TStrEditDlg inherited;
	
__published:
	Valedit::TValueListEditor* ValueListEditor1;
	void __fastcall ValueListEditor1StringsChange(System::TObject* Sender);
	void __fastcall ValueListEditor1KeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	
protected:
	virtual Classes::TStrings* __fastcall GetLines(void);
	virtual void __fastcall SetLines(const Classes::TStrings* Value);
	virtual Controls::TWinControl* __fastcall GetLinesControl(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TValueEditDlg(Classes::TComponent* AOwner) : Stredit::TStrEditDlg(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TValueEditDlg(Classes::TComponent* AOwner, int Dummy) : Stredit::TStrEditDlg(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TValueEditDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TValueEditDlg(HWND ParentWindow) : Stredit::TStrEditDlg(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Valueedit */
using namespace Valueedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ValueEdit
