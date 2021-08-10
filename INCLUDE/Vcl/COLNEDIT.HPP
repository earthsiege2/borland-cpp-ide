// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ColnEdit.pas' rev: 5.00

#ifndef ColnEditHPP
#define ColnEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ToolWnds.hpp>	// Pascal unit
#include <ToolWin.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <DsgnWnds.hpp>	// Pascal unit
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

namespace Colnedit
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TColOption { coAdd, coDelete, coMove };
#pragma option pop

typedef Set<TColOption, coAdd, coMove>  TColOptions;

class DELPHICLASS TCollectionEditor;
class PASCALIMPLEMENTATION TCollectionEditor : public Toolwnds::TToolbarDesignWindow 
{
	typedef Toolwnds::TToolbarDesignWindow inherited;
	
__published:
	Extctrls::TPanel* Panel3;
	Comctrls::TListView* ListView1;
	Controls::TImageList* ImageList1;
	Comctrls::TToolButton* ToolButton1;
	Comctrls::TToolButton* ToolButton2;
	Comctrls::TToolButton* ToolButton3;
	Comctrls::TToolButton* ToolButton4;
	Comctrls::TToolButton* ToolButton5;
	Actnlist::TAction* AddCmd;
	Actnlist::TAction* DeleteCmd;
	Actnlist::TAction* MoveUpCmd;
	Actnlist::TAction* MoveDownCmd;
	Actnlist::TAction* SelectAllCmd;
	Menus::TMenuItem* N2;
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ListView1Click(System::TObject* Sender);
	void __fastcall FormKeyPress(System::TObject* Sender, char &Key);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall MoveUpClick(System::TObject* Sender);
	void __fastcall ListView1DragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState 
		State, bool &Accept);
	void __fastcall ListView1DragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall MoveDownClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall ListView1Change(System::TObject* Sender, Comctrls::TListItem* Item, Comctrls::TItemChange 
		Change);
	void __fastcall SelectAll1Click(System::TObject* Sender);
	void __fastcall SelectAllCommandUpdate(System::TObject* Sender);
	void __fastcall SelectionUpdate(System::TObject* Sender);
	void __fastcall ListView1KeyPress(System::TObject* Sender, char &Key);
	
private:
	AnsiString FCollectionPropertyName;
	int FStateLock;
	Classes::TList* FItemIDList;
	AnsiString FCollectionClassName;
	bool FSelectionError;
	TColOptions FColOptions;
	AnsiString __fastcall GetRegKey();
	void __fastcall SetCollectionPropertyName(const AnsiString Value);
	MESSAGE void __fastcall AMDeferUpdate(void *Msg);
	void __fastcall SetColOptions(TColOptions Value);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	virtual bool __fastcall CanAdd(int Index);
	void __fastcall LockState(void);
	void __fastcall UnlockState(void);
	__property int StateLock = {read=FStateLock, nodefault};
	void __fastcall SelectAll(bool DoUpdate);
	void __fastcall SelectNone(bool DoUpdate);
	
public:
	Classes::TCollection* Collection;
	Classes::TComponent* Component;
	__property TColOptions Options = {read=FColOptions, write=SetColOptions, nodefault};
	virtual void __fastcall ComponentDeleted(Dsgnintf::_di_IPersistent Component);
	virtual void __fastcall FormClosed(Forms::TCustomForm* AForm);
	virtual void __fastcall FormModified(void);
	AnsiString __fastcall GetItemName(int Index, int ItemIndex);
	void __fastcall GetSelection(void);
	virtual void __fastcall SelectionChanged(Dsgnintf::TDesignerSelectionList* ASelection)/* overload */
		;
	HIDESBASE void __fastcall SetSelection(void);
	void __fastcall UpdateListbox(void);
	__property AnsiString CollectionPropertyName = {read=FCollectionPropertyName, write=SetCollectionPropertyName
		};
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TCollectionEditor(Classes::TComponent* AOwner)
		 : Toolwnds::TToolbarDesignWindow(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TCollectionEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TCollectionEditor(Classes::TComponent* AOwner
		, int Dummy) : Toolwnds::TToolbarDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCollectionEditor(HWND ParentWindow) : Toolwnds::TToolbarDesignWindow(
		ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TCollectionEditorClass;

class DELPHICLASS TCollectionProperty;
class PASCALIMPLEMENTATION TCollectionProperty : public Dsgnintf::TClassProperty 
{
	typedef Dsgnintf::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual TMetaClass* __fastcall GetEditorClass(void);
	virtual TColOptions __fastcall GetColOptions(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCollectionProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCollectionProperty(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word AM_DeferUpdate = 0x464;
extern PACKAGE TCollectionEditor* __fastcall ShowCollectionEditorClass(Forms::_di_IDesigner ADesigner
	, TMetaClass* CollectionEditorClass, Classes::TComponent* AComponent, Classes::TCollection* ACollection
	, const AnsiString PropertyName, TColOptions ColOptions);
extern PACKAGE void __fastcall ShowCollectionEditor(Forms::_di_IDesigner ADesigner, Classes::TComponent* 
	AComponent, Classes::TCollection* ACollection, const AnsiString PropertyName);

}	/* namespace Colnedit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Colnedit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ColnEdit
