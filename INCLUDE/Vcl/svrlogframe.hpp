// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrLogFrame.pas' rev: 6.00

#ifndef SvrLogFrameHPP
#define SvrLogFrameHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Registry.hpp>	// Pascal unit
#include <SvrLog.hpp>	// Pascal unit
#include <SvrLogDetailFrame.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
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

namespace Svrlogframe
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TColumnInfo
{
	bool Visible;
	int Width;
	int ColumnPosition;
	int SubItemPosition;
	AnsiString Caption;
} ;
#pragma pack(pop)

typedef Svrlog::TLogColumn TLogColumnOrder[9];

typedef TColumnInfo SvrLogFrame__2[9];

class DELPHICLASS TLogFrame;
class PASCALIMPLEMENTATION TLogFrame : public Forms::TFrame 
{
	typedef Forms::TFrame inherited;
	
__published:
	Comctrls::TListView* lvLog;
	Menus::TPopupMenu* PopupMenu2;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* ClearAction;
	Menus::TMenuItem* Clear1;
	Actnlist::TAction* DetailAction;
	Menus::TMenuItem* DetailAction1;
	void __fastcall ClearActionExecute(System::TObject* Sender);
	void __fastcall ClearActionUpdate(System::TObject* Sender);
	void __fastcall DetailActionExecute(System::TObject* Sender);
	void __fastcall lvLogDblClick(System::TObject* Sender);
	void __fastcall lvLogColumnClick(System::TObject* Sender, Comctrls::TListColumn* Column);
	void __fastcall lvLogCompare(System::TObject* Sender, Comctrls::TListItem* Item1, Comctrls::TListItem* Item2, int Data, int &Compare);
	void __fastcall lvLogColumnDragged(System::TObject* Sender);
	
private:
	bool FShowingDetail;
	int FColumnToSort;
	bool FSortDescending;
	bool FSorted;
	TColumnInfo FColumnInfo[9];
	int FLogMax;
	int FLogDelete;
	int __fastcall GetCount(void);
	int __fastcall GetIndex(void);
	Svrlog::TTransactionLogEntry* __fastcall GetCurrent(void);
	void __fastcall ConstrainLog(void);
	bool __fastcall GetColumnVisible(Svrlog::TLogColumn I);
	int __fastcall GetColumnWidth(Svrlog::TLogColumn I);
	void __fastcall SetColumnVisible(Svrlog::TLogColumn I, const bool Value);
	void __fastcall SetColumnWidth(Svrlog::TLogColumn I, const int Value);
	AnsiString __fastcall GetColumnCaption(Svrlog::TLogColumn I);
	int __fastcall GetColumnPosition(Svrlog::TLogColumn I);
	void __fastcall SetColumnPosition(Svrlog::TLogColumn I, const int Value);
	int __fastcall GetSubItemPosition(Svrlog::TLogColumn I);
	void __fastcall SetSubItemPosition(Svrlog::TLogColumn I, const int Value);
	Comctrls::TListColumn* __fastcall GetColumn(Svrlog::TLogColumn ALogColumn);
	void __fastcall SetCurrent(Comctrls::TListItem* AItem);
	int __fastcall GetItemCount(void);
	void __fastcall SetLogDelete(const int Value);
	void __fastcall SetLogMax(const int Value);
	
public:
	__fastcall virtual TLogFrame(Classes::TComponent* AOwner);
	__fastcall virtual ~TLogFrame(void);
	void __fastcall SynchColumnInfo(void);
	void __fastcall Add(Svrlog::TTransactionLogEntry* Transaction);
	void __fastcall Next(void);
	void __fastcall Previous(void);
	void __fastcall Clear(void);
	__property int Count = {read=GetCount, nodefault};
	void __fastcall ShowDetail(Svrlogdetailframe::TLogDetailFrame* Details);
	void __fastcall RefreshColumns(void);
	void __fastcall RefreshSubItems(void);
	void __fastcall Save(Registry::TRegIniFile* Reg, const AnsiString Section);
	void __fastcall Load(Registry::TRegIniFile* Reg, const AnsiString Section);
	void __fastcall GetSubItemOrder(Svrlog::TLogColumn * Positions);
	void __fastcall GetColumnOrder(Svrlog::TLogColumn * Positions);
	__property int Index = {read=GetIndex, nodefault};
	__property Svrlog::TTransactionLogEntry* Current = {read=GetCurrent};
	__property int LogMax = {read=FLogMax, write=SetLogMax, nodefault};
	__property int LogDelete = {read=FLogDelete, write=SetLogDelete, nodefault};
	__property AnsiString ColumnCaption[Svrlog::TLogColumn I] = {read=GetColumnCaption};
	__property int ColumnWidth[Svrlog::TLogColumn I] = {read=GetColumnWidth, write=SetColumnWidth};
	__property bool ColumnVisible[Svrlog::TLogColumn I] = {read=GetColumnVisible, write=SetColumnVisible};
	__property int ColumnPosition[Svrlog::TLogColumn I] = {read=GetColumnPosition, write=SetColumnPosition};
	__property int SubItemPosition[Svrlog::TLogColumn I] = {read=GetSubItemPosition, write=SetSubItemPosition};
	__property Comctrls::TListColumn* Columns[Svrlog::TLogColumn I] = {read=GetColumn};
	__property int ItemCount = {read=GetItemCount, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLogFrame(HWND ParentWindow) : Forms::TFrame(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Svrlogframe */
using namespace Svrlogframe;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrLogFrame
