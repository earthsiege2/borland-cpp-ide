// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QCheckLst.pas' rev: 6.00

#ifndef QCheckLstHPP
#define QCheckLstHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QMenus.hpp>	// Pascal unit
#include <QImgList.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qchecklst
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCheckListBox;
class PASCALIMPLEMENTATION TCheckListBox : public Qstdctrls::TCustomListBox 
{
	typedef Qstdctrls::TCustomListBox inherited;
	
private:
	bool FAllowGrayed;
	bool FFlat;
	Classes::TNotifyEvent FOnClickCheck;
	Classes::TList* FSaveStates;
	void __fastcall ResetItemHeight(void);
	void __fastcall SetChecked(int Index, bool AChecked);
	bool __fastcall GetChecked(int Index);
	void __fastcall SetState(int Index, Qstdctrls::TCheckBoxState AState);
	Qstdctrls::TCheckBoxState __fastcall GetState(int Index);
	void __fastcall ToggleClickCheck(int Index);
	void __fastcall InvalidateCheck(int Index);
	System::TObject* __fastcall CreateWrapper(int Index);
	System::TObject* __fastcall ExtractWrapper(int Index);
	System::TObject* __fastcall GetWrapper(int Index);
	bool __fastcall HaveWrapper(int Index);
	void __fastcall SetFlat(bool Value);
	bool __fastcall GetItemEnabled(int Index);
	void __fastcall SetItemEnabled(int Index, const bool Value);
	
protected:
	DYNAMIC void __fastcall ClickCheck(void);
	virtual void __fastcall CreateWidget(void);
	DYNAMIC void __fastcall DeleteString(int Index);
	virtual void __fastcall DrawCheck(const Types::TRect &R, Qstdctrls::TCheckBoxState AState, bool AEnabled);
	virtual bool __fastcall DrawItem(int Index, const Types::TRect &Rect, Qstdctrls::TOwnerDrawState State);
	virtual int __fastcall GetCheckWidth(void);
	DYNAMIC int __fastcall GetItemData(int Index);
	DYNAMIC void __fastcall KeyPress(char &Key);
	virtual void __fastcall MeasureItem(Qcontrols::TWidgetControl* Control, int Index, int &Height, int &Width);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall ResetContent(void);
	DYNAMIC void __fastcall SetItemData(int Index, int AData);
	virtual void __fastcall SaveWidgetState(void);
	
public:
	__fastcall virtual TCheckListBox(Classes::TComponent* AOwner);
	__fastcall virtual ~TCheckListBox(void);
	__property bool Checked[int Index] = {read=GetChecked, write=SetChecked};
	__property bool ItemEnabled[int Index] = {read=GetItemEnabled, write=SetItemEnabled};
	__property Qstdctrls::TCheckBoxState State[int Index] = {read=GetState, write=SetState};
	
__published:
	__property Style  = {default=0};
	__property Align  = {default=0};
	__property bool AllowGrayed = {read=FAllowGrayed, write=FAllowGrayed, default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=6};
	__property Color  = {default=-10};
	__property Columns  = {default=1};
	__property ColumnLayout  = {default=0};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property bool Flat = {read=FFlat, write=SetFlat, default=1};
	__property Font ;
	__property ItemHeight  = {default=16};
	__property Items ;
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property RowLayout  = {default=2};
	__property Rows  = {default=1};
	__property ShowHint ;
	__property Sorted  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property Classes::TNotifyEvent OnClickCheck = {read=FOnClickCheck, write=FOnClickCheck};
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
	/* TWidgetControl.CreateParented */ inline __fastcall TCheckListBox(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomListBox(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qchecklst */
using namespace Qchecklst;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QCheckLst
