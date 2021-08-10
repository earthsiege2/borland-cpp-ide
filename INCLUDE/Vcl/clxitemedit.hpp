// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxItemEdit.pas' rev: 6.00

#ifndef ClxItemEditHPP
#define ClxItemEditHPP

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

namespace Clxitemedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TItemInfo;
class PASCALIMPLEMENTATION TItemInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStringList* FSubItems;
	Classes::TList* FSubItemImages;
	AnsiString FCaption;
	int FImageIndex;
	int FStateIndex;
	
public:
	__fastcall TItemInfo(Qcomctrls::TListItem* Item);
	__fastcall virtual ~TItemInfo(void);
};


class DELPHICLASS TClxListViewItems;
class PASCALIMPLEMENTATION TClxListViewItems : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TGroupBox* GroupBox1;
	Qstdctrls::TGroupBox* PropGroupBox;
	Qstdctrls::TButton* New;
	Qstdctrls::TButton* Delete;
	Qstdctrls::TLabel* Label1;
	Qstdctrls::TLabel* Label2;
	Qstdctrls::TLabel* Label3;
	Qcomctrls::TTreeView* TreeView;
	Qstdctrls::TButton* NewSub;
	Qstdctrls::TEdit* Text;
	Qstdctrls::TEdit* Image;
	Qstdctrls::TEdit* StateImage;
	Qstdctrls::TButton* Button4;
	Qstdctrls::TButton* Cancel;
	Qstdctrls::TButton* Apply;
	Qstdctrls::TButton* Button7;
	void __fastcall NewClick(System::TObject* Sender);
	void __fastcall NewSubClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ValueChange(System::TObject* Sender);
	void __fastcall TextExit(System::TObject* Sender);
	void __fastcall ImageExit(System::TObject* Sender);
	void __fastcall StateImageExit(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall ApplyClick(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Qcomctrls::TTreeNode* Node);
	void __fastcall TreeViewChanging(System::TObject* Sender, Qcomctrls::TTreeNode* Node, bool &AllowChange);
	void __fastcall TreeViewDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Qcontrols::TDragState State, bool &Accept);
	void __fastcall TreeViewDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall TreeViewEdited(System::TObject* Sender, Qcomctrls::TTreeNode* Node, WideString &S);
	void __fastcall Button7Click(System::TObject* Sender);
	void __fastcall TreeViewKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall TreeViewEditing(System::TObject* Sender, Qcomctrls::TTreeNode* Node, bool &AllowEdit);
	
private:
	Qcomctrls::TListItems* FItems;
	bool FDropping;
	void __fastcall FlushControls(void);
	void __fastcall GetItem(TItemInfo* ItemInfo, Qcomctrls::TListItem* Value);
	void __fastcall SetItem(TItemInfo* Value);
	void __fastcall SetStates(void);
	void __fastcall SetSubItem(const AnsiString S, int ImageIndex);
	
public:
	__property Qcomctrls::TListItems* Items = {read=FItems};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxListViewItems(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxListViewItems(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxListViewItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxListViewItems(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TEditInvoker;
class PASCALIMPLEMENTATION TEditInvoker : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Designintf::_di_IDesigner FDesigner;
	Classes::TComponent* FComponent;
	void __fastcall InvokeEdit(void);
	
public:
	__fastcall TEditInvoker(Designintf::_di_IDesigner ADesigner, Classes::TComponent* AComponent);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEditInvoker(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListViewEditor;
class PASCALIMPLEMENTATION TListViewEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TListViewEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TListViewEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListViewColumnsProperty;
class PASCALIMPLEMENTATION TListViewColumnsProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TListViewColumnsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TListViewColumnsProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TListViewItemsProperty;
class PASCALIMPLEMENTATION TListViewItemsProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TListViewItemsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TListViewItemsProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditListViewItems(Qcomctrls::TListItems* AItems);

}	/* namespace Clxitemedit */
using namespace Clxitemedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxItemEdit
