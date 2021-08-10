// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DbOleCtl.pas' rev: 5.00

#ifndef DbOleCtlHPP
#define DbOleCtlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <OleCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbolectl
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDataBindItem;
class DELPHICLASS TDataBindings;
class DELPHICLASS TDBOleControl;
class PASCALIMPLEMENTATION TDBOleControl : public Olectrls::TOleControl 
{
	typedef Olectrls::TOleControl inherited;
	
private:
	TDataBindings* FDataBindings;
	bool FDataChanging;
	Db::TDataSource* FDataSource;
	void __fastcall SetDataSource(Db::TDataSource* Value);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	virtual HRESULT __stdcall OnChanged(int dispid);
	virtual HRESULT __stdcall OnRequestEdit(int dispid);
	
public:
	__fastcall virtual TDBOleControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TDBOleControl(void);
	
__published:
	__property Db::TDataSource* DataSource = {read=FDataSource, write=SetDataSource};
	__property TDataBindings* DataBindings = {read=FDataBindings, write=FDataBindings};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDBOleControl(HWND ParentWindow) : Olectrls::TOleControl(
		ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDataBindings : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
private:
	TDBOleControl* FDBOleControl;
	HIDESBASE TDataBindItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TDataBindItem* Value);
	
public:
	__fastcall TDataBindings(TDBOleControl* DBOleControl);
	HIDESBASE TDataBindItem* __fastcall Add(void);
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	TDataBindItem* __fastcall GetItemByDispID(int ADispID);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	__property TDataBindItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TDataBindings(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TDataBindItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	TDataBindings* FOwner;
	Dbctrls::TFieldDataLink* FDataLink;
	int FDispId;
	void __fastcall DataChange(System::TObject* Sender);
	AnsiString __fastcall GetDataField();
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDispID(int Value);
	void __fastcall UpdateData(System::TObject* Sender);
	
public:
	__fastcall virtual TDataBindItem(Classes::TCollection* Collection);
	__fastcall virtual ~TDataBindItem(void);
	
__published:
	__property AnsiString DataField = {read=GetDataField, write=SetDataField};
	__property int DispID = {read=FDispId, write=SetDispID, nodefault};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbolectl */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dbolectl;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DbOleCtl
