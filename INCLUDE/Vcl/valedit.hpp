// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ValEdit.pas' rev: 6.00

#ifndef ValEditHPP
#define ValEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
class DELPHICLASS TItemProp;

namespace Valedit
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDisplayOption { doColumnTitles, doAutoColResize, doKeyColFixed };
#pragma option pop

typedef Set<TDisplayOption, doColumnTitles, doKeyColFixed>  TDisplayOptions;

#pragma option push -b-
enum TKeyOption { keyEdit, keyAdd, keyDelete, keyUnique };
#pragma option pop

typedef Set<TKeyOption, keyEdit, keyUnique>  TKeyOptions;

typedef void __fastcall (__closure *TGetPickListEvent)(System::TObject* Sender, const AnsiString KeyName, Classes::TStrings* Values);

typedef void __fastcall (__closure *TOnValidateEvent)(System::TObject* Sender, int ACol, int ARow, const AnsiString KeyName, const AnsiString KeyValue);

class DELPHICLASS TValueListEditor;
class DELPHICLASS TValueListStrings;
typedef DynamicArray<TItemProp* >  TItemProps;

class DELPHICLASS TItemProp;
class PASCALIMPLEMENTATION TValueListStrings : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	DynamicArray<TItemProp* >  FItemProps;
	TValueListEditor* FEditor;
	TItemProp* __fastcall GetItemProp(const Variant &KeyOrIndex);
	void __fastcall PutItemProp(const Variant &KeyOrIndex, const TItemProp* Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall Changing(void);
	TItemProp* __fastcall FindItemProp(const Variant &KeyOrIndex, bool Create = false);
	virtual void __fastcall InsertItem(int Index, const AnsiString S, System::TObject* AObject);
	virtual void __fastcall Put(int Index, const AnsiString S);
	
public:
	__fastcall TValueListStrings(TValueListEditor* AEditor);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	bool __fastcall KeyIsValid(const AnsiString Key, bool RaiseError = true);
	virtual void __fastcall Clear(void);
	virtual void __fastcall CustomSort(Classes::TStringListSortCompare Compare);
	virtual void __fastcall Delete(int Index);
	virtual void __fastcall Exchange(int Index1, int Index2);
	__property TItemProp* ItemProps[Variant KeyOrIndex] = {read=GetItemProp, write=PutItemProp};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TValueListStrings(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TValueListEditor : public Grids::TCustomDrawGrid 
{
	typedef Grids::TCustomDrawGrid inherited;
	
private:
	Classes::TStrings* FTitleCaptions;
	TValueListStrings* FStrings;
	TKeyOptions FKeyOptions;
	TDisplayOptions FDisplayOptions;
	int FDropDownRows;
	AnsiString FDupKeySave;
	bool FDeleting;
	bool FAdjustingColWidths;
	int FEditUpdate;
	int FCountSave;
	Grids::TInplaceEditList* FEditList;
	TGetPickListEvent FOnGetPickList;
	Classes::TNotifyEvent FOnEditButtonClick;
	TOnValidateEvent FOnValidate;
	void __fastcall DisableEditUpdate(void);
	void __fastcall EnableEditUpdate(void);
	TItemProp* __fastcall GetItemProp(const Variant &KeyOrIndex);
	AnsiString __fastcall GetKey(int Index);
	AnsiString __fastcall GetValue(const AnsiString Key);
	Classes::TNotifyEvent __fastcall GetOnStringsChange();
	Classes::TNotifyEvent __fastcall GetOnStringsChanging();
	Classes::TStrings* __fastcall GetStrings(void);
	void __fastcall PutItemProp(const Variant &KeyOrIndex, const TItemProp* Value);
	void __fastcall SetDisplayOptions(const TDisplayOptions Value);
	void __fastcall SetDropDownRows(const int Value);
	void __fastcall SetKey(int Index, const AnsiString Value);
	void __fastcall SetKeyOptions(TKeyOptions Value);
	void __fastcall SetTitleCaptions(const Classes::TStrings* Value);
	void __fastcall SetValue(const AnsiString Key, const AnsiString Value);
	void __fastcall SetOnStringsChange(const Classes::TNotifyEvent Value);
	void __fastcall SetOnStringsChanging(const Classes::TNotifyEvent Value);
	void __fastcall SetOnEditButtonClick(const Classes::TNotifyEvent Value);
	Grids::TGridOptions __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetOptions(const Grids::TGridOptions Value);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall AdjustColWidths(void);
	virtual void __fastcall AdjustRowCount(void);
	DYNAMIC void __fastcall ColWidthsChanged(void);
	DYNAMIC bool __fastcall CanEditModify(void);
	virtual Grids::TInplaceEdit* __fastcall CreateEditor(void);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	virtual void __fastcall DoOnValidate(void);
	void __fastcall EditListGetItems(int ACol, int ARow, Classes::TStrings* Items);
	virtual AnsiString __fastcall GetCell(int ACol, int ARow);
	int __fastcall GetColCount(void);
	DYNAMIC AnsiString __fastcall GetEditMask(int ACol, int ARow);
	DYNAMIC Grids::TEditStyle __fastcall GetEditStyle(int ACol, int ARow);
	DYNAMIC AnsiString __fastcall GetEditText(int ACol, int ARow);
	bool __fastcall GetPickList(Classes::TStrings* Values, bool ClearFirst = true);
	int __fastcall GetRowCount(void);
	bool __fastcall IsEmptyRow(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall Resize(void);
	DYNAMIC void __fastcall RowMoved(int FromIndex, int ToIndex);
	virtual bool __fastcall SelectCell(int ACol, int ARow);
	virtual void __fastcall SetCell(int ACol, int ARow, const AnsiString Value);
	DYNAMIC void __fastcall SetEditText(int ACol, int ARow, const AnsiString Value);
	virtual void __fastcall SetStrings(const Classes::TStrings* Value);
	DYNAMIC void __fastcall StringsChanging(void);
	bool __fastcall TitleCaptionsStored(void);
	__property Grids::TInplaceEditList* EditList = {read=FEditList};
	
public:
	__fastcall virtual TValueListEditor(Classes::TComponent* AOwner);
	__fastcall virtual ~TValueListEditor(void);
	virtual void __fastcall DeleteRow(int ARow);
	bool __fastcall FindRow(const AnsiString KeyName, int &Row);
	int __fastcall InsertRow(const AnsiString KeyName, const AnsiString Value, bool Append);
	HIDESBASE void __fastcall Refresh(void);
	bool __fastcall RestoreCurrentRow(void);
	__property AnsiString Cells[int ACol][int ARow] = {read=GetCell, write=SetCell};
	__property ColCount  = {read=GetColCount, default=5};
	__property TItemProp* ItemProps[Variant KeyOrIndex] = {read=GetItemProp, write=PutItemProp};
	__property AnsiString Keys[int Index] = {read=GetKey, write=SetKey};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property AnsiString Values[AnsiString Key] = {read=GetValue, write=SetValue};
	__property VisibleColCount ;
	__property VisibleRowCount ;
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BiDiMode ;
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DefaultColWidth  = {default=150};
	__property DefaultDrawing  = {default=1};
	__property DefaultRowHeight  = {default=18};
	__property TDisplayOptions DisplayOptions = {read=FDisplayOptions, write=SetDisplayOptions, default=7};
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property int DropDownRows = {read=FDropDownRows, write=SetDropDownRows, default=8};
	__property Enabled  = {default=1};
	__property FixedColor  = {default=-2147483633};
	__property FixedCols  = {default=0};
	__property Font ;
	__property GridLineWidth  = {default=1};
	__property TKeyOptions KeyOptions = {read=FKeyOptions, write=SetKeyOptions, default=0};
	__property Grids::TGridOptions Options = {read=GetOptions, write=SetOptions, default=25743};
	__property ParentBiDiMode  = {default=1};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property ShowHint ;
	__property Classes::TStrings* Strings = {read=GetStrings, write=SetStrings};
	__property TabOrder  = {default=-1};
	__property Classes::TStrings* TitleCaptions = {read=FTitleCaptions, write=SetTitleCaptions, stored=TitleCaptionsStored};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawCell ;
	__property Classes::TNotifyEvent OnEditButtonClick = {read=FOnEditButtonClick, write=SetOnEditButtonClick};
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnGetEditMask ;
	__property OnGetEditText ;
	__property TGetPickListEvent OnGetPickList = {read=FOnGetPickList, write=FOnGetPickList};
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnMouseWheelDown ;
	__property OnMouseWheelUp ;
	__property OnRowMoved ;
	__property OnSelectCell ;
	__property OnSetEditText ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property Classes::TNotifyEvent OnStringsChange = {read=GetOnStringsChange, write=SetOnStringsChange};
	__property Classes::TNotifyEvent OnStringsChanging = {read=GetOnStringsChanging, write=SetOnStringsChanging};
	__property OnTopLeftChanged ;
	__property TOnValidateEvent OnValidate = {read=FOnValidate, write=FOnValidate};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TValueListEditor(HWND ParentWindow) : Grids::TCustomDrawGrid(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TItemProp : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TValueListEditor* FEditor;
	AnsiString FEditMask;
	Grids::TEditStyle FEditStyle;
	Classes::TStrings* FPickList;
	int FMaxLength;
	bool FReadOnly;
	AnsiString FKeyDesc;
	Classes::TStrings* __fastcall GetPickList(void);
	void __fastcall PickListChange(System::TObject* Sender);
	void __fastcall SetEditMask(const AnsiString Value);
	void __fastcall SetMaxLength(const int Value);
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetEditStyle(const Grids::TEditStyle Value);
	void __fastcall SetPickList(const Classes::TStrings* Value);
	void __fastcall SetKeyDesc(const AnsiString Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall UpdateEdit(void);
	
public:
	__fastcall TItemProp(TValueListEditor* AEditor);
	__fastcall virtual ~TItemProp(void);
	bool __fastcall HasPickList(void);
	
__published:
	__property AnsiString EditMask = {read=FEditMask, write=SetEditMask};
	__property Grids::TEditStyle EditStyle = {read=FEditStyle, write=SetEditStyle, nodefault};
	__property AnsiString KeyDesc = {read=FKeyDesc, write=SetKeyDesc};
	__property Classes::TStrings* PickList = {read=GetPickList, write=SetPickList};
	__property int MaxLength = {read=FMaxLength, write=SetMaxLength, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Valedit */
using namespace Valedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ValEdit
