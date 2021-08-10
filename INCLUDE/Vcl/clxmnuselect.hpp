// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxMnuSelect.pas' rev: 6.00

#ifndef ClxMnuSelectHPP
#define ClxMnuSelectHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QStdCtrls.hpp>	// Pascal unit
#include <QButtons.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxmnuselect
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClxMenuSelectDialog;
class PASCALIMPLEMENTATION TClxMenuSelectDialog : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TListBox* SelectionBox;
	Qstdctrls::TButton* OKButton;
	Qstdctrls::TButton* CancelButton;
	Qstdctrls::TButton* HelpButton;
	void __fastcall GetData(Classes::TComponent* &AComponent);
	void __fastcall SetData(Classes::TComponent* AComponent);
	void __fastcall HelpButtonClick(System::TObject* Sender);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxMenuSelectDialog(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxMenuSelectDialog(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxMenuSelectDialog(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxMenuSelectDialog(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Clxmnuselect */
using namespace Clxmnuselect;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxMnuSelect
