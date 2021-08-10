// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSDesign.pas' rev: 6.00

#ifndef DSDesignHPP
#define DSDesignHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DrpCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <DsnDBCst.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsdesign
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TSelectionProc)(Db::TField* Field);

typedef TMetaClass*TDSDesignerClass;

class DELPHICLASS TFieldsEditor;
class DELPHICLASS TDSDesigner;
class PASCALIMPLEMENTATION TDSDesigner : public Db::TDataSetDesigner 
{
	typedef Db::TDataSetDesigner inherited;
	
private:
	TFieldsEditor* FFieldsEditor;
	
public:
	__fastcall virtual ~TDSDesigner(void);
	virtual void __fastcall DataEvent(Db::TDataEvent Event, int Info);
	virtual void __fastcall BeginCreateFields(void);
	virtual void __fastcall BeginUpdateFieldDefs(void);
	virtual Db::TField* __fastcall DoCreateField(const AnsiString FieldName, AnsiString Origin);
	virtual void __fastcall EndCreateFields(void);
	virtual void __fastcall EndUpdateFieldDefs(void);
	virtual AnsiString __fastcall GetControlClass(Db::TField* Field);
	virtual void __fastcall InitializeMenu(Menus::TPopupMenu* Menu);
	virtual bool __fastcall SupportsAggregates(void);
	virtual bool __fastcall SupportsInternalCalc(void);
	virtual void __fastcall UpdateMenus(Menus::TPopupMenu* Menu, Designintf::TEditState EditState);
	__property TFieldsEditor* FieldsEditor = {read=FFieldsEditor};
public:
	#pragma option push -w-inl
	/* TDataSetDesigner.Create */ inline __fastcall TDSDesigner(Db::TDataSet* DataSet) : Db::TDataSetDesigner(DataSet) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TFieldsEditor : public Designwindows::TDesignWindow 
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Db::TDataSource* DataSource;
	Menus::TPopupMenu* LocalMenu;
	Menus::TMenuItem* AddItem;
	Menus::TMenuItem* NewItem;
	Menus::TMenuItem* N1;
	Menus::TMenuItem* CutItem;
	Menus::TMenuItem* CopyItem;
	Menus::TMenuItem* PasteItem;
	Menus::TMenuItem* DeleteItem;
	Menus::TMenuItem* SelectAllItem;
	Stdctrls::TListBox* FieldListBox;
	Dbctrls::TDBNavigator* DBNavigator;
	Menus::TMenuItem* Addallfields1;
	Stdctrls::TListBox* AggListBox;
	Extctrls::TSplitter* Splitter1;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall AddItemClick(System::TObject* Sender);
	void __fastcall DeleteItemClick(System::TObject* Sender);
	void __fastcall FieldListBoxDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState State, bool &Accept);
	void __fastcall FieldListBoxDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall AListBoxKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall NewItemClick(System::TObject* Sender);
	void __fastcall SelectTable(System::TObject* Sender);
	void __fastcall AListBoxClick(System::TObject* Sender);
	void __fastcall AListBoxKeyPress(System::TObject* Sender, char &Key);
	void __fastcall ClearAllClick(System::TObject* Sender);
	void __fastcall FieldListBoxStartDrag(System::TObject* Sender, Controls::TDragObject* &DragObject);
	void __fastcall SelectAllItemClick(System::TObject* Sender);
	void __fastcall CutItemClick(System::TObject* Sender);
	void __fastcall CopyItemClick(System::TObject* Sender);
	void __fastcall PasteItemClick(System::TObject* Sender);
	void __fastcall LocalMenuPopup(System::TObject* Sender);
	void __fastcall AddAllFields(System::TObject* Sender);
	
private:
	TMetaClass*FDSDesignerClass;
	Controls::TDragObject* FDragObject;
	TDSDesigner* FDSDesigner;
	Db::TDataSet* FDataset;
	int FFocusRectItem;
	int FMinWidth;
	int FMinHeight;
	void __fastcall AddFields(bool All);
	void __fastcall Copy(void);
	Db::TField* __fastcall CreateFields(Stdctrls::TListBox* FieldsList);
	void __fastcall Cut(void);
	void __fastcall MoveFields(int MoveOffset);
	void __fastcall Paste(void);
	void __fastcall RemoveFields(Stdctrls::TListBox* Listbox);
	void __fastcall SelectAll(void);
	void __fastcall RestoreSelection(Stdctrls::TListBox* List, Classes::TStringList* &Selection, int ItemIndex, int TopIndex, bool RestoreUpdate);
	void __fastcall SaveSelection(Stdctrls::TListBox* List, Classes::TStringList* &Selection, int &ItemIndex, int &TopIndex, bool NoUpdate);
	void __fastcall SetDataset(Db::TDataSet* Value);
	void __fastcall UpdateDisplay(void);
	void __fastcall UpdateCaption(void);
	void __fastcall UpdateFieldList(void);
	void __fastcall UpdateSelection(void);
	HIDESBASE MESSAGE void __fastcall WMGetMinMaxInfo(Messages::TWMGetMinMaxInfo &Message);
	Stdctrls::TListBox* __fastcall GetActiveListbox(void);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	void __fastcall CheckFieldDelete(void);
	void __fastcall CheckFieldAdd(void);
	virtual AnsiString __fastcall UniqueName(Classes::TComponent* Component);
	
public:
	__fastcall virtual ~TFieldsEditor(void);
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, Classes::TPersistent* AItem);
	virtual Designintf::TEditState __fastcall GetEditState(void);
	virtual bool __fastcall EditAction(Designintf::TEditAction Action);
	bool __fastcall ForEachSelection(TSelectionProc Proc);
	virtual void __fastcall ItemsModified(const Designintf::_di_IDesigner Designer);
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
	Db::TField* __fastcall DoNewField(void);
	Db::TField* __fastcall DoNewLookupField(const AnsiString ADataSet, const AnsiString AKey, const AnsiString ALookup, const AnsiString AResult, const AnsiString AType, Word ASize);
	Db::TField* __fastcall DoAddFields(bool All);
	__property Db::TDataSet* Dataset = {read=FDataset, write=SetDataset};
	__property TMetaClass* DSDesignerClass = {read=FDSDesignerClass, write=FDSDesignerClass};
	__property TDSDesigner* DSDesigner = {read=FDSDesigner};
public:
	#pragma option push -w-inl
	/* TDesignWindow.Create */ inline __fastcall virtual TFieldsEditor(Classes::TComponent* AOwner) : Designwindows::TDesignWindow(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFieldsEditor(Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFieldsEditor(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int DesignerCount;
extern PACKAGE void __fastcall ShowFieldsEditor(Designintf::_di_IDesigner Designer, Db::TDataSet* ADataset, TMetaClass* DesignerClass);
extern PACKAGE TFieldsEditor* __fastcall CreateFieldsEditor(Designintf::_di_IDesigner Designer, Db::TDataSet* ADataset, TMetaClass* DesignerClass, bool &Shared);
extern PACKAGE AnsiString __fastcall CreateUniqueName(Db::TDataSet* Dataset, const AnsiString FieldName, TMetaClass* FieldClass, Classes::TComponent* Component);

}	/* namespace Dsdesign */
using namespace Dsdesign;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSDesign
