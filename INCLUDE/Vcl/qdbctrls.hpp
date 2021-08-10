// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QDBCtrls.pas' rev: 6.00

#ifndef QDBCtrlsHPP
#define QDBCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DB.hpp>	// Pascal unit
#include <QMask.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QButtons.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QComCtrls.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

/* automatically link to qdblogdlg.obj so that the login dialog is automatically shown */
#pragma link "qdblogdlg.obj"
/* automatically link to dbrtl and visualdbclx as well */
#ifdef USEPACKAGES
#pragma link "dbrtl.bpi"
#pragma link "visualdbclx.bpi"
#else
#pragma link "dbrtl.lib"
#pragma link "visualdbclx.lib"
#endif


namespace Qdbctrls
{
//-- type declarations -------------------------------------------------------
typedef int HWnd;

class DELPHICLASS TFieldDataLink;
class PASCALIMPLEMENTATION TFieldDataLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	Db::TField* FField;
	AnsiString FFieldName;
	Classes::TComponent* FControl;
	bool FEditing;
	bool FModified;
	Classes::TNotifyEvent FOnDataChange;
	Classes::TNotifyEvent FOnEditingChange;
	Classes::TNotifyEvent FOnUpdateData;
	Classes::TNotifyEvent FOnActiveChange;
	bool __fastcall GetCanModify(void);
	HIDESBASE void __fastcall SetEditing(bool Value);
	void __fastcall SetField(Db::TField* Value);
	void __fastcall SetFieldName(const AnsiString Value);
	void __fastcall UpdateField(void);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall FocusControl(Db::TFieldRef Field);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	
public:
	__fastcall TFieldDataLink(void);
	HIDESBASE bool __fastcall Edit(void);
	void __fastcall Modified(void);
	void __fastcall Reset(void);
	__property bool CanModify = {read=GetCanModify, nodefault};
	__property Classes::TComponent* Control = {read=FControl, write=FControl};
	__property bool Editing = {read=FEditing, nodefault};
	__property Db::TField* Field = {read=FField};
	__property AnsiString FieldName = {read=FFieldName, write=SetFieldName};
	__property Classes::TNotifyEvent OnDataChange = {read=FOnDataChange, write=FOnDataChange};
	__property Classes::TNotifyEvent OnEditingChange = {read=FOnEditingChange, write=FOnEditingChange};
	__property Classes::TNotifyEvent OnUpdateData = {read=FOnUpdateData, write=FOnUpdateData};
	__property Classes::TNotifyEvent OnActiveChange = {read=FOnActiveChange, write=FOnActiveChange};
public:
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TFieldDataLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDBEdit;
class PASCALIMPLEMENTATION TDBEdit : public Qmask::TCustomMaskEdit 
{
	typedef Qmask::TCustomMaskEdit inherited;
	
private:
	TFieldDataLink* FDataLink;
	bool FTextLocked;
	bool FDatasetLocked;
	void __fastcall DataChange(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	HIDESBASE bool __fastcall GetReadOnly(void);
	void __fastcall Restore(void);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	HIDESBASE void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	
protected:
	virtual void __fastcall Change(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual bool __fastcall EditCanModify(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Reset(void);
	
public:
	__fastcall virtual TDBEdit(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBEdit(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Anchors  = {default=3};
	__property AutoSelect  = {default=1};
	__property AutoSize  = {default=1};
	__property BorderStyle  = {default=1};
	__property CharCase  = {default=0};
	__property Color  = {default=-10};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property MaxLength  = {default=-1};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBEdit(Qt::QWidgetH* ParentWidget) : Qmask::TCustomMaskEdit(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBText;
class PASCALIMPLEMENTATION TDBText : public Qstdctrls::TCustomLabel 
{
	typedef Qstdctrls::TCustomLabel inherited;
	
private:
	TFieldDataLink* FDataLink;
	void __fastcall DataChange(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	AnsiString __fastcall GetFieldText();
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	
protected:
	virtual WideString __fastcall GetLabelText();
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetAutoSize(bool Value);
	
public:
	__fastcall virtual TDBText(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBText(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property AutoSize  = {default=0};
	__property Color  = {default=-10};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property Transparent  = {default=0};
	__property ShowHint  = {default=0};
	__property Visible  = {default=1};
	__property WordWrap  = {default=0};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBText(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomLabel(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBCheckBox;
class PASCALIMPLEMENTATION TDBCheckBox : public Qstdctrls::TCustomCheckBox 
{
	typedef Qstdctrls::TCustomCheckBox inherited;
	
private:
	TFieldDataLink* FDataLink;
	AnsiString FValueCheck;
	AnsiString FValueUncheck;
	bool FUpdating;
	void __fastcall DataChange(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	Qstdctrls::TCheckBoxState __fastcall GetFieldState(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetValueCheck(const AnsiString Value);
	void __fastcall SetValueUncheck(const AnsiString Value);
	void __fastcall UpdateData(System::TObject* Sender);
	bool __fastcall ValueMatch(const AnsiString ValueList, const AnsiString Value);
	
protected:
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DoExit(void);
	
public:
	__fastcall virtual TDBCheckBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBCheckBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Checked  = {default=0};
	__property Db::TField* Field = {read=GetField};
	__property State  = {default=0};
	
__published:
	__property Action ;
	__property AllowGrayed  = {default=0};
	__property Anchors  = {default=3};
	__property Caption ;
	__property Color  = {default=-10};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property AnsiString ValueChecked = {read=FValueCheck, write=SetValueCheck};
	__property AnsiString ValueUnchecked = {read=FValueUncheck, write=SetValueUncheck};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBCheckBox(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomCheckBox(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBComboBox;
class PASCALIMPLEMENTATION TDBComboBox : public Qstdctrls::TCustomComboBox 
{
	typedef Qstdctrls::TCustomComboBox inherited;
	
private:
	TFieldDataLink* FDataLink;
	bool FTextLocked;
	bool FDatasetLocked;
	void __fastcall DataChange(System::TObject* Sender);
	AnsiString __fastcall GetComboText();
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetComboText(const AnsiString Value);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	HIDESBASE void __fastcall SetItems(Classes::TStrings* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall SetStyle(Qstdctrls::TComboBoxStyle Value);
	virtual void __fastcall SetText(const WideString Value);
	
public:
	__fastcall virtual TDBComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBComboBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	__property Text ;
	
__published:
	__property Style  = {default=0};
	__property Anchors  = {default=3};
	__property Color  = {default=-10};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property DropDownCount  = {default=8};
	__property Enabled  = {default=1};
	__property Font ;
	__property ItemHeight  = {default=16};
	__property Items  = {write=SetItems};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint ;
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnDropDown ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBComboBox(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomComboBox(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBListBox;
class PASCALIMPLEMENTATION TDBListBox : public Qstdctrls::TCustomListBox 
{
	typedef Qstdctrls::TCustomListBox inherited;
	
private:
	TFieldDataLink* FDataLink;
	bool FTextLocked;
	bool FDatasetLocked;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall UpdateData(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	HIDESBASE void __fastcall SetItems(Classes::TStrings* Value);
	
protected:
	virtual void __fastcall Changed(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall DoExit(void);
	
public:
	__fastcall virtual TDBListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBListBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property ColumnLayout  = {default=0};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ItemHeight  = {default=16};
	__property Items  = {write=SetItems};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property RowLayout  = {default=2};
	__property Rows  = {default=1};
	__property ShowHint ;
	__property Style  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMeasureItem ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBListBox(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomListBox(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBRadioGroup;
class PASCALIMPLEMENTATION TDBRadioGroup : public Qextctrls::TCustomRadioGroup 
{
	typedef Qextctrls::TCustomRadioGroup inherited;
	
private:
	TFieldDataLink* FDataLink;
	AnsiString FValue;
	Classes::TStrings* FValues;
	bool FInSetValue;
	Classes::TNotifyEvent FOnChange;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall UpdateData(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	AnsiString __fastcall GetButtonValue(int Index);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetValue(const AnsiString Value);
	HIDESBASE void __fastcall SetItems(Classes::TStrings* Value);
	void __fastcall SetValues(Classes::TStrings* Value);
	
protected:
	virtual bool __fastcall CanModify(void);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	__property TFieldDataLink* DataLink = {read=FDataLink};
	
public:
	__fastcall virtual TDBRadioGroup(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBRadioGroup(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	__property ItemIndex  = {default=-1};
	__property AnsiString Value = {read=FValue, write=SetValue};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Caption ;
	__property Color  = {default=-10};
	__property Columns  = {default=1};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Items  = {write=SetItems};
	__property ParentColor  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Classes::TStrings* Values = {read=FValues, write=SetValues};
	__property Visible  = {default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBRadioGroup(Qt::QWidgetH* ParentWidget) : Qextctrls::TCustomRadioGroup(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBMemo;
class PASCALIMPLEMENTATION TDBMemo : public Qstdctrls::TCustomMemo 
{
	typedef Qstdctrls::TCustomMemo inherited;
	
private:
	TFieldDataLink* FDataLink;
	bool FAutoDisplay;
	bool FFocused;
	bool FMemoLoaded;
	bool FTextLocked;
	bool FDatasetLocked;
	void __fastcall DataChange(System::TObject* Sender);
	void __fastcall EditingChange(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	HIDESBASE bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetAutoDisplay(bool Value);
	void __fastcall SetFocused(bool Value);
	HIDESBASE void __fastcall SetReadOnly(const bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	
protected:
	virtual void __fastcall Change(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	__fastcall virtual TDBMemo(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBMemo(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	virtual void __fastcall LoadMemo(void);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	
__published:
	__property Align  = {default=0};
	__property Alignment  = {default=0};
	__property Anchors  = {default=3};
	__property bool AutoDisplay = {read=FAutoDisplay, write=SetAutoDisplay, default=1};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property MaxLength  = {default=-1};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ScrollBars  = {default=0};
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property WantTabs  = {default=0};
	__property WordWrap  = {default=1};
	__property WrapBreak  = {default=0};
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBMemo(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomMemo(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TDBImage;
class PASCALIMPLEMENTATION TDBImage : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	TFieldDataLink* FDataLink;
	Qgraphics::TPicture* FPicture;
	Qcontrols::TBorderStyle FBorderStyle;
	bool FAutoDisplay;
	bool FStretch;
	bool FCenter;
	bool FPictureLoaded;
	void __fastcall DataChange(System::TObject* Sender);
	int __fastcall GetBorderSize(void);
	AnsiString __fastcall GetDataField();
	Db::TDataSource* __fastcall GetDataSource(void);
	Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetAutoDisplay(bool Value);
	void __fastcall SetBorderStyle(Qcontrols::TControlBorderStyle Value);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetPicture(Qgraphics::TPicture* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetStretch(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual Types::TRect __fastcall GetClientRect();
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall TextChanged(void);
	__property int BorderSize = {read=GetBorderSize, nodefault};
	
public:
	__fastcall virtual TDBImage(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBImage(void);
	void __fastcall CopyToClipboard(void);
	void __fastcall CutToClipboard(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	void __fastcall LoadPicture(void);
	void __fastcall PasteFromClipboard(void);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=GetField};
	__property Qgraphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property bool AutoDisplay = {read=FAutoDisplay, write=SetAutoDisplay, default=1};
	__property Qcontrols::TControlBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property bool Center = {read=FCenter, write=SetCenter, default=1};
	__property Color  = {default=-10};
	__property Constraints ;
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property ShowHint ;
	__property bool Stretch = {read=FStretch, write=SetStretch, default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBImage(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TNavGlyph { ngEnabled, ngDisabled };
#pragma option pop

#pragma option push -b-
enum TNavigateBtn { nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbEdit, nbPost, nbCancel, nbRefresh };
#pragma option pop

typedef Set<TNavigateBtn, nbFirst, nbRefresh>  TButtonSet;

#pragma option push -b-
enum QDBCtrls__01 { nsAllowTimer, nsFocusRect };
#pragma option pop

typedef Set<QDBCtrls__01, nsAllowTimer, nsFocusRect>  TNavButtonStyle;

typedef void __fastcall (__closure *ENavClick)(System::TObject* Sender, TNavigateBtn Button);

class DELPHICLASS TDBNavigator;
class DELPHICLASS TNavDataLink;
class PASCALIMPLEMENTATION TNavDataLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TDBNavigator* FNavigator;
	
protected:
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall ActiveChanged(void);
	
public:
	__fastcall TNavDataLink(TDBNavigator* ANav);
	__fastcall virtual ~TNavDataLink(void);
};


class DELPHICLASS TNavButton;
class PASCALIMPLEMENTATION TDBNavigator : public Qextctrls::TCustomPanel 
{
	typedef Qextctrls::TCustomPanel inherited;
	
private:
	TNavDataLink* FDataLink;
	TButtonSet FVisibleButtons;
	Classes::TStrings* FHints;
	Classes::TStrings* FDefHints;
	int ButtonWidth;
	#pragma pack(push, 1)
	Types::TPoint MinBtnSize;
	#pragma pack(pop)
	
	ENavClick FOnNavClick;
	ENavClick FBeforeAction;
	TNavigateBtn FocusedButton;
	bool FConfirmDelete;
	bool FFlat;
	void __fastcall BtnMouseDown(System::TObject* Sender, Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ClickHandler(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMKeyDown(Qcontrols::TCMKeyDown &Msg);
	Db::TDataSource* __fastcall GetDataSource(void);
	Classes::TStrings* __fastcall GetHints(void);
	void __fastcall HintsChanged(System::TObject* Sender);
	void __fastcall InitButtons(void);
	void __fastcall InitHints(void);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetFlat(bool Value);
	void __fastcall SetHints(Classes::TStrings* Value);
	void __fastcall SetSize(int &W, int &H);
	HIDESBASE void __fastcall SetVisible(TButtonSet Value);
	
protected:
	TNavButton* Buttons[10];
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall ChangeBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall DataChanged(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	void __fastcall EditingChanged(void);
	DYNAMIC void __fastcall EnabledChanged(void);
	void __fastcall ActiveChanged(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	void __fastcall CalcMinSize(int &W, int &H);
	
public:
	__fastcall virtual TDBNavigator(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBNavigator(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall BtnClick(TNavigateBtn Index);
	
__published:
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property TButtonSet VisibleButtons = {read=FVisibleButtons, write=SetVisible, default=1023};
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property bool Flat = {read=FFlat, write=SetFlat, default=0};
	__property Classes::TStrings* Hints = {read=GetHints, write=SetHints};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property bool ConfirmDelete = {read=FConfirmDelete, write=FConfirmDelete, default=1};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=0};
	__property Visible  = {default=1};
	__property ENavClick BeforeAction = {read=FBeforeAction, write=FBeforeAction};
	__property ENavClick OnClick = {read=FOnNavClick, write=FOnNavClick};
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnResize ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBNavigator(Qt::QWidgetH* ParentWidget) : Qextctrls::TCustomPanel(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TNavButton : public Qbuttons::TSpeedButton 
{
	typedef Qbuttons::TSpeedButton inherited;
	
private:
	TNavigateBtn FIndex;
	TNavButtonStyle FNavStyle;
	Qextctrls::TTimer* FRepeatTimer;
	void __fastcall TimerExpired(System::TObject* Sender);
	
protected:
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	
public:
	__fastcall virtual ~TNavButton(void);
	__property TNavButtonStyle NavStyle = {read=FNavStyle, write=FNavStyle, nodefault};
	__property TNavigateBtn Index = {read=FIndex, write=FIndex, nodefault};
public:
	#pragma option push -w-inl
	/* TSpeedButton.Create */ inline __fastcall virtual TNavButton(Classes::TComponent* AOwner) : Qbuttons::TSpeedButton(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSourceLink;
class DELPHICLASS TDBLookupControl;
class DELPHICLASS TListSourceLink;
class PASCALIMPLEMENTATION TListSourceLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TDBLookupControl* FDBLookupControl;
	int FLock;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall LayoutChanged(void);
	
public:
	__fastcall TListSourceLink(void);
public:
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TListSourceLink(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDBLookupControl : public Qcontrols::TCustomControl 
{
	typedef Qcontrols::TCustomControl inherited;
	
private:
	Db::TDataSource* FLookupSource;
	TDataSourceLink* FDataLink;
	TListSourceLink* FListLink;
	AnsiString FDataFieldName;
	AnsiString FKeyFieldName;
	AnsiString FListFieldName;
	int FListFieldIndex;
	Db::TField* FDataField;
	Db::TField* FMasterField;
	Db::TField* FKeyField;
	Db::TField* FListField;
	Classes::TList* FListFields;
	Variant FKeyValue;
	AnsiString FSearchText;
	bool FLookupMode;
	bool FListActive;
	bool FHasFocus;
	Qextctrls::TTimer* FTimer;
	void __fastcall CheckNotCircular(void);
	void __fastcall CheckNotLookup(void);
	HIDESBASE MESSAGE void __fastcall CMKeyDown(Qcontrols::TCMKeyDown &Msg);
	void __fastcall DataLinkRecordChanged(Db::TField* Field);
	Db::TDataSource* __fastcall GetDataSource(void);
	AnsiString __fastcall GetKeyFieldName();
	Db::TDataSource* __fastcall GetListSource(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataFieldName(const AnsiString Value);
	void __fastcall SetDataSource(Db::TDataSource* Value);
	void __fastcall SetKeyFieldName(const AnsiString Value);
	void __fastcall SetKeyValue(const Variant &Value);
	void __fastcall SetListFieldName(const AnsiString Value);
	void __fastcall SetListSource(Db::TDataSource* Value);
	void __fastcall SetLookupMode(bool Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall TimerEvent(System::TObject* Sender);
	
protected:
	virtual bool __fastcall CanModify(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual int __fastcall GetTextHeight(void);
	virtual void __fastcall KeyValueChanged(void);
	virtual void __fastcall ListLinkDataChanged(void);
	virtual bool __fastcall LocateKey(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall ProcessSearchKey(char Key);
	virtual void __fastcall SelectKeyValue(const Variant &Value);
	virtual void __fastcall UpdateDataFields(void);
	virtual void __fastcall UpdateListFields(void);
	__property Color  = {default=16777215};
	__property AnsiString DataField = {read=FDataFieldName, write=SetDataFieldName};
	__property Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property AnsiString KeyField = {read=GetKeyFieldName, write=SetKeyFieldName};
	__property Variant KeyValue = {read=FKeyValue, write=SetKeyValue};
	__property bool ListActive = {read=FListActive, nodefault};
	__property AnsiString ListField = {read=FListFieldName, write=SetListFieldName};
	__property int ListFieldIndex = {read=FListFieldIndex, write=FListFieldIndex, default=0};
	__property Classes::TList* ListFields = {read=FListFields};
	__property TListSourceLink* ListLink = {read=FListLink};
	__property Db::TDataSource* ListSource = {read=GetListSource, write=SetListSource};
	__property ParentColor  = {default=0};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property AnsiString SearchText = {read=FSearchText, write=FSearchText};
	__property TabStop  = {default=1};
	
public:
	__fastcall virtual TDBLookupControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBLookupControl(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property Db::TField* Field = {read=FDataField};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBLookupControl(Qt::QWidgetH* ParentWidget) : Qcontrols::TCustomControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDataSourceLink : public Db::TDataLink 
{
	typedef Db::TDataLink inherited;
	
private:
	TDBLookupControl* FDBLookupControl;
	
protected:
	virtual void __fastcall FocusControl(Db::TFieldRef Field);
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Db::TField* Field);
	
public:
	__fastcall TDataSourceLink(void);
public:
	#pragma option push -w-inl
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDataSourceLink(void) { }
	#pragma option pop
	
};


class DELPHICLASS TLookupListBoxScrollBar;
class DELPHICLASS TDBLookupListBox;
class PASCALIMPLEMENTATION TDBLookupListBox : public TDBLookupControl 
{
	typedef TDBLookupControl inherited;
	
private:
	Qcontrols::TBorderStyle FBorderStyle;
	bool FKeySelected;
	bool FLockPosition;
	int FMousePos;
	bool FPopup;
	int FRecordCount;
	int FRecordIndex;
	int FRowCount;
	TLookupListBoxScrollBar* FScrollBar;
	AnsiString FSelectedItem;
	bool FTracking;
	Qextctrls::TTimer* FTimer;
	void __fastcall CalcScrollBarLayout(void);
	int __fastcall GetKeyIndex(void);
	void __fastcall SelectCurrent(void);
	void __fastcall SelectItemAt(int X, int Y);
	void __fastcall SetBorderStyle(Qcontrols::TControlBorderStyle Value);
	void __fastcall SetRowCount(int Value);
	void __fastcall StopTracking(void);
	void __fastcall TimerScroll(void);
	void __fastcall UpdateScrollBar(void);
	void __fastcall ScrollEvent(System::TObject* Sender, Qstdctrls::TScrollCode ScrollCode, int &ScrollPos);
	HIDESBASE void __fastcall TimerEvent(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall BoundsChanged(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual int __fastcall GetBorderSize(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall KeyValueChanged(void);
	virtual void __fastcall ListLinkDataChanged(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall UpdateListFields(void);
	
public:
	__fastcall virtual TDBLookupListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBLookupListBox(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property KeyValue ;
	__property AnsiString SelectedItem = {read=FSelectedItem};
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property Qcontrols::TControlBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property Color  = {default=16777215};
	__property Constraints ;
	__property DataField ;
	__property DataSource ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property KeyField ;
	__property ListField ;
	__property ListFieldIndex  = {default=0};
	__property ListSource ;
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property int RowCount = {read=FRowCount, write=SetRowCount, stored=false, nodefault};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBLookupListBox(Qt::QWidgetH* ParentWidget) : TDBLookupControl(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TLookupListBoxScrollBar : public Qstdctrls::TScrollBar 
{
	typedef Qstdctrls::TScrollBar inherited;
	
private:
	TDBLookupListBox* FDBLookupListBox;
	bool __fastcall GetVisible(void);
	HIDESBASE void __fastcall SetVisible(bool Value);
	
protected:
	virtual void __fastcall InitWidget(void);
	DYNAMIC void __fastcall WidgetDestroyed(void);
	
public:
	__fastcall virtual TLookupListBoxScrollBar(Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall CanFocus(void);
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TLookupListBoxScrollBar(Qt::QWidgetH* ParentWidget) : Qstdctrls::TScrollBar(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TLookupListBoxScrollBar(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPopupDataList;
class PASCALIMPLEMENTATION TPopupDataList : public TDBLookupListBox 
{
	typedef TDBLookupListBox inherited;
	
protected:
	virtual void __fastcall InitWidget(void);
	virtual int __fastcall WidgetFlags(void);
	
public:
	__fastcall TPopupDataList(Qt::QWidgetH* ParentWidget);
public:
	#pragma option push -w-inl
	/* TDBLookupListBox.Create */ inline __fastcall virtual TPopupDataList(Classes::TComponent* AOwner) : TDBLookupListBox(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDBLookupListBox.Destroy */ inline __fastcall virtual ~TPopupDataList(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TDropDownAlign { daLeft, daRight, daCenter };
#pragma option pop

class DELPHICLASS TDBLookupComboBox;
class PASCALIMPLEMENTATION TDBLookupComboBox : public TDBLookupControl 
{
	typedef TDBLookupControl inherited;
	
private:
	TPopupDataList* FDataList;
	int FButtonWidth;
	AnsiString FText;
	int FDropDownRows;
	int FDropDownWidth;
	TDropDownAlign FDropDownAlign;
	bool FListVisible;
	bool FPressed;
	bool FTracking;
	Classes::TAlignment FAlignment;
	bool FLookupMode;
	Classes::TNotifyEvent FOnDropDown;
	Classes::TNotifyEvent FOnCloseUp;
	void __fastcall ListKeypress(System::TObject* Sender, char &Key);
	void __fastcall ListMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ListMouseUp(System::TObject* Sender, Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall TrackButton(int X, int Y);
	
protected:
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall KeyValueChanged(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall UpdateListFields(void);
	
public:
	__fastcall virtual TDBLookupComboBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBLookupComboBox(void);
	virtual void __fastcall CloseUp(bool Accept);
	virtual void __fastcall DropDown(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property KeyValue ;
	__property bool ListVisible = {read=FListVisible, nodefault};
	__property AnsiString Text = {read=FText};
	
__published:
	__property Anchors  = {default=3};
	__property Color  = {default=16777215};
	__property Constraints ;
	__property DataField ;
	__property DataSource ;
	__property DragMode  = {default=0};
	__property TDropDownAlign DropDownAlign = {read=FDropDownAlign, write=FDropDownAlign, default=0};
	__property int DropDownRows = {read=FDropDownRows, write=FDropDownRows, default=7};
	__property int DropDownWidth = {read=FDropDownWidth, write=FDropDownWidth, default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property KeyField ;
	__property ListField ;
	__property ListFieldIndex  = {default=0};
	__property ListSource ;
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property OnContextPopup ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDBLookupComboBox(Qt::QWidgetH* ParentWidget) : TDBLookupControl(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word InitRepeatPause = 0x190;
static const Shortint RepeatPause = 0x64;
static const Shortint SpaceSize = 0x5;
extern PACKAGE bool __fastcall OkToChangeFieldAlignment(Db::TField* AField, Classes::TAlignment Alignment);

}	/* namespace Qdbctrls */
using namespace Qdbctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QDBCtrls
