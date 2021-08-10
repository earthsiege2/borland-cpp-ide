// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxNodeEdit.pas' rev: 6.00

#ifndef ClxNodeEditHPP
#define ClxNodeEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QComCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <Consts.hpp>	// Pascal unit
#include <LibHelp.hpp>	// Pascal unit
#include <DsnConst.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxnodeedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClxTreeViewItems;
class PASCALIMPLEMENTATION TClxTreeViewItems : public Qforms::TForm 
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
	Qstdctrls::TButton* NewSub;
	Qstdctrls::TEdit* Text;
	Qstdctrls::TEdit* Image;
	Qstdctrls::TButton* Button4;
	Qstdctrls::TButton* Cancel;
	Qstdctrls::TButton* Apply;
	Qstdctrls::TButton* Help;
	Qstdctrls::TEdit* SelectedIndex;
	Qstdctrls::TLabel* Label4;
	Qstdctrls::TButton* Load;
	Qdialogs::TOpenDialog* OpenDialog1;
	Qstdctrls::TGroupBox* gbSubItems;
	Qstdctrls::TListBox* lbSubItems;
	Qstdctrls::TButton* btnAddSub;
	Qstdctrls::TButton* btnDelSub;
	Qstdctrls::TGroupBox* gbSubItemProps;
	Qstdctrls::TLabel* lblSubText;
	Qstdctrls::TEdit* edtSubText;
	Qstdctrls::TLabel* lblSubImgIndex;
	Qstdctrls::TEdit* edtSubImgIndex;
	void __fastcall NewClick(System::TObject* Sender);
	void __fastcall NewSubClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ValueChange(System::TObject* Sender);
	void __fastcall TextExit(System::TObject* Sender);
	void __fastcall ImageExit(System::TObject* Sender);
	void __fastcall ApplyClick(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Qcomctrls::TTreeNode* Node);
	void __fastcall TreeViewChanging(System::TObject* Sender, Qcomctrls::TTreeNode* Node, bool &AllowChange);
	void __fastcall SelectedIndexExit(System::TObject* Sender);
	void __fastcall LoadClick(System::TObject* Sender);
	void __fastcall TreeViewDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Qcontrols::TDragState State, bool &Accept);
	void __fastcall TreeViewDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall TreeViewEdited(System::TObject* Sender, Qcomctrls::TTreeNode* Node, WideString &S);
	void __fastcall HelpClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall edtSubTextExit(System::TObject* Sender);
	void __fastcall edtSubImgIndexExit(System::TObject* Sender);
	void __fastcall btnAddSubClick(System::TObject* Sender);
	void __fastcall btnDelSubClick(System::TObject* Sender);
	void __fastcall lbSubItemsClick(System::TObject* Sender);
	void __fastcall edtSubTextChange(System::TObject* Sender);
	
private:
	Qcomctrls::TTreeNodes* FItems;
	bool FDropping;
	bool FPutting;
	void __fastcall FlushControls(void);
	void __fastcall SetItem(Qcomctrls::TTreeNode* Value);
	void __fastcall SetStates(void);
	bool __fastcall SubItemsShouldBeDisabled(void);
	void __fastcall PutSubItemText(const AnsiString Str);
	
public:
	__property Qcomctrls::TTreeNodes* Items = {read=FItems};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxTreeViewItems(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxTreeViewItems(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxTreeViewItems(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxTreeViewItems(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
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


class DELPHICLASS TTreeViewEditor;
class PASCALIMPLEMENTATION TTreeViewEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TTreeViewEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TTreeViewEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTreeViewItemsProperty;
class PASCALIMPLEMENTATION TTreeViewItemsProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTreeViewItemsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTreeViewItemsProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTreeViewColumnsProperty;
class PASCALIMPLEMENTATION TTreeViewColumnsProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTreeViewColumnsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTreeViewColumnsProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditTreeViewItems(Qcomctrls::TTreeNodes* AItems);

}	/* namespace Clxnodeedit */
using namespace Clxnodeedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxNodeEdit
