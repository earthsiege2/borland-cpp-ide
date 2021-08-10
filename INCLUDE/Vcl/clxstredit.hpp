// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxStrEdit.pas' rev: 6.00

#ifndef ClxStrEditHPP
#define ClxStrEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QTypes.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QComCtrls.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QButtons.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxstredit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClxStrEditDlg;
class PASCALIMPLEMENTATION TClxStrEditDlg : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TLabel* LineCount;
	Qdialogs::TOpenDialog* OpenDialog;
	Qdialogs::TSaveDialog* SaveDialog;
	Qstdctrls::TButton* HelpButton;
	Qstdctrls::TButton* OKButton;
	Qstdctrls::TButton* CancelButton;
	Qstdctrls::TMemo* Memo;
	Qmenus::TPopupMenu* PopupMenu1;
	Qmenus::TMenuItem* Load1;
	Qmenus::TMenuItem* Save1;
	Qmenus::TMenuItem* Clear1;
	void __fastcall FileOpen(System::TObject* Sender);
	void __fastcall FileSave(System::TObject* Sender);
	void __fastcall UpdateStatus(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall Memo1KeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall CodeWndBtnClick(System::TObject* Sender);
	void __fastcall Clear1Click(System::TObject* Sender);
	
private:
	AnsiString SingleLine;
	AnsiString MultipleLines;
	bool FModified;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxStrEditDlg(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxStrEditDlg(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxStrEditDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxStrEditDlg(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TStringListProperty;
class PASCALIMPLEMENTATION TStringListProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall Edit(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TStringListProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TStringListProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Clxstredit */
using namespace Clxstredit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxStrEdit
