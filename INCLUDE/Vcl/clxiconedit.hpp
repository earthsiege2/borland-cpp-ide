// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxIconEdit.pas' rev: 6.00

#ifndef ClxIconEditHPP
#define ClxIconEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QControls.hpp>	// Pascal unit
#include <QComCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <DsnConst.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <LibHelp.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxiconedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TItemInfo;
class PASCALIMPLEMENTATION TItemInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	AnsiString FCaption;
	int FImageIndex;
	
public:
	__fastcall TItemInfo(Qcomctrls::TIconViewItem* Item);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TItemInfo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TClxIconViewItemsEditor;
class PASCALIMPLEMENTATION TClxIconViewItemsEditor : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TGroupBox* GroupBox1;
	Qstdctrls::TGroupBox* PropGroupBox;
	Qstdctrls::TButton* New;
	Qstdctrls::TButton* Delete;
	Qstdctrls::TLabel* Label1;
	Qstdctrls::TLabel* Label2;
	Qcomctrls::TTreeView* TreeView;
	Qstdctrls::TEdit* Text;
	Qstdctrls::TEdit* Image;
	Qstdctrls::TButton* Button4;
	Qstdctrls::TButton* Cancel;
	Qstdctrls::TButton* Apply;
	Qstdctrls::TButton* Button7;
	void __fastcall NewClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ValueChange(System::TObject* Sender);
	void __fastcall TextExit(System::TObject* Sender);
	void __fastcall ImageExit(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ApplyClick(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Qcomctrls::TTreeNode* Node);
	void __fastcall TreeViewEdited(System::TObject* Sender, Qcomctrls::TTreeNode* Node, AnsiString &S);
	void __fastcall Button7Click(System::TObject* Sender);
	void __fastcall TreeViewKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall TreeViewEditing(System::TObject* Sender, Qcomctrls::TTreeNode* Node, bool &AllowEdit);
	
private:
	Qcomctrls::TIconViewItems* FItems;
	void __fastcall FlushControls(void);
	void __fastcall GetItem(TItemInfo* ItemInfo, Qcomctrls::TIconViewItem* Value);
	void __fastcall SetItem(TItemInfo* Value);
	void __fastcall SetStates(void);
	
public:
	__property Qcomctrls::TIconViewItems* Items = {read=FItems};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxIconViewItemsEditor(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxIconViewItemsEditor(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxIconViewItemsEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxIconViewItemsEditor(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TIconViewEditor;
class PASCALIMPLEMENTATION TIconViewEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TIconViewEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIconViewEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIconViewItemsProperty;
class PASCALIMPLEMENTATION TIconViewItemsProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TIconViewItemsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TIconViewItemsProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditIconViewItems(Qcomctrls::TIconViewItems* AItems);

}	/* namespace Clxiconedit */
using namespace Clxiconedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxIconEdit
