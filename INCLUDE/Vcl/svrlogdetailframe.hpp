// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrLogDetailFrame.pas' rev: 6.00

#ifndef SvrLogDetailFrameHPP
#define SvrLogDetailFrameHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ImgList.hpp>	// Pascal unit
#include <StdActns.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Registry.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svrlogdetailframe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLogDetailFrame;
class PASCALIMPLEMENTATION TLogDetailFrame : public Forms::TFrame 
{
	typedef Forms::TFrame inherited;
	
__published:
	Stdctrls::TMemo* Memo1;
	Stdctrls::TCheckBox* cbTranslateText;
	Stdctrls::TCheckBox* cbWrapText;
	Actnlist::TActionList* ActionList1;
	Controls::TImageList* ImageList1;
	Stdactns::TFontEdit* FontEdit1;
	Menus::TPopupMenu* PopupMenu1;
	Menus::TMenuItem* SelectFont1;
	Stdactns::TEditCut* EditCut1;
	Stdactns::TEditCopy* EditCopy1;
	Stdactns::TEditPaste* EditPaste1;
	Stdactns::TEditSelectAll* EditSelectAll1;
	Stdactns::TEditUndo* EditUndo1;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* Cut1;
	Menus::TMenuItem* Cut2;
	Menus::TMenuItem* Paste1;
	Menus::TMenuItem* SelectAll1;
	Menus::TMenuItem* N2;
	Menus::TMenuItem* Undo1;
	void __fastcall cbTranslateTextClick(System::TObject* Sender);
	void __fastcall cbWrapTextClick(System::TObject* Sender);
	void __fastcall FontEdit1Accept(System::TObject* Sender);
	
private:
	AnsiString FRawText;
	HIDESBASE void __fastcall SetText(const AnsiString Value);
	AnsiString __fastcall GetTranslatedText();
	void __fastcall UpdateText(void);
	bool __fastcall GetTranslateText(void);
	void __fastcall SetTranslateText(const bool Value);
	bool __fastcall GetWrapText(void);
	void __fastcall SetWrapText(const bool Value);
	void __fastcall UpdateWrap(void);
	
public:
	void __fastcall Load(Registry::TRegIniFile* Reg, const AnsiString Section);
	void __fastcall Save(Registry::TRegIniFile* Reg, const AnsiString Section);
	void __fastcall Clear(void);
	__property AnsiString Text = {write=SetText};
	__property bool TranslateText = {read=GetTranslateText, write=SetTranslateText, nodefault};
	__property bool WrapText = {read=GetWrapText, write=SetWrapText, nodefault};
public:
	#pragma option push -w-inl
	/* TCustomFrame.Create */ inline __fastcall virtual TLogDetailFrame(Classes::TComponent* AOwner) : Forms::TFrame(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TLogDetailFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLogDetailFrame(HWND ParentWindow) : Forms::TFrame(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Svrlogdetailframe */
using namespace Svrlogdetailframe;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrLogDetailFrame
