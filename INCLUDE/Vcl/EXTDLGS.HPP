// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ExtDlgs.pas' rev: 5.00

#ifndef ExtDlgsHPP
#define ExtDlgsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Dialogs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Extdlgs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOpenPictureDialog;
class PASCALIMPLEMENTATION TOpenPictureDialog : public Dialogs::TOpenDialog 
{
	typedef Dialogs::TOpenDialog inherited;
	
private:
	Graphics::TPicture* FPicture;
	Extctrls::TPanel* FPicturePanel;
	Stdctrls::TLabel* FPictureLabel;
	Buttons::TSpeedButton* FPreviewButton;
	Extctrls::TPanel* FPaintPanel;
	Extctrls::TPaintBox* FPaintBox;
	bool __fastcall IsFilterStored(void);
	void __fastcall PaintBoxPaint(System::TObject* Sender);
	void __fastcall PreviewClick(System::TObject* Sender);
	void __fastcall PreviewKeyPress(System::TObject* Sender, char &Key);
	
protected:
	DYNAMIC void __fastcall DoClose(void);
	DYNAMIC void __fastcall DoSelectionChange(void);
	DYNAMIC void __fastcall DoShow(void);
	
__published:
	__property Filter  = {stored=IsFilterStored};
	
public:
	__fastcall virtual TOpenPictureDialog(Classes::TComponent* AOwner);
	__fastcall virtual ~TOpenPictureDialog(void);
	virtual bool __fastcall Execute(void);
};


class DELPHICLASS TSavePictureDialog;
class PASCALIMPLEMENTATION TSavePictureDialog : public TOpenPictureDialog 
{
	typedef TOpenPictureDialog inherited;
	
public:
	virtual bool __fastcall Execute(void);
public:
	#pragma option push -w-inl
	/* TOpenPictureDialog.Create */ inline __fastcall virtual TSavePictureDialog(Classes::TComponent* AOwner
		) : TOpenPictureDialog(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TOpenPictureDialog.Destroy */ inline __fastcall virtual ~TSavePictureDialog(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Extdlgs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Extdlgs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ExtDlgs
