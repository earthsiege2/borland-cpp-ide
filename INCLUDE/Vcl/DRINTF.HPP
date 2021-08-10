// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DRIntf.pas' rev: 5.00

#ifndef DRIntfHPP
#define DRIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Drintf
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 1)
struct TID
{
	Byte Reserved[6];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TDatabaseID
{
	Byte Reserved[6];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TTableID
{
	Byte Reserved[6];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TFieldID
{
	Byte Reserved[6];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TAttrID
{
	Byte Reserved[6];
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TID NullID;
extern PACKAGE TAttrID NullAttrID;
extern PACKAGE TDatabaseID NullDatabaseID;
extern PACKAGE TTableID NullTableID;
extern PACKAGE TFieldID NullFieldID;
extern PACKAGE AnsiString __fastcall QualifyTableName(Dbtables::TDatabase* Database, const AnsiString 
	TableName);
extern PACKAGE AnsiString __fastcall QualifyTableNameByName(const AnsiString SessionName, const AnsiString 
	DatabaseName, const AnsiString TableName);
extern PACKAGE Bde::hDBIDR __fastcall CurrentDictionary(void);
extern PACKAGE bool __fastcall IsNullID(const void *ID);
extern PACKAGE void __fastcall DictionaryDeactivate(void);
extern PACKAGE bool __fastcall DictionaryActive(void);
extern PACKAGE TDatabaseID __fastcall FindDatabaseID(const AnsiString Database);
extern PACKAGE TTableID __fastcall FindTableID(const TDatabaseID &Database, const AnsiString Table);
	
extern PACKAGE TFieldID __fastcall FindFieldID(const TTableID &Table, const AnsiString Field);
extern PACKAGE TAttrID __fastcall GetAttrID(const TFieldID &FieldID);
extern PACKAGE TAttrID __fastcall FindAttrID(const AnsiString AttrName);
extern PACKAGE AnsiString __fastcall GetAttrName(const TAttrID &AttrID);
extern PACKAGE void __fastcall GetAttrNames(Classes::TGetStrProc Proc);
extern PACKAGE void __fastcall AssociateAttr(const TAttrID &AttrID, const TFieldID &FieldID);
extern PACKAGE void __fastcall UnassociateAttr(const TFieldID &FieldID);
extern PACKAGE TAttrID __fastcall NewAttr(Db::TField* Field, const TFieldID &FieldID, const AnsiString 
	AttrName, const TAttrID &Parent);
extern PACKAGE void __fastcall UpdateAttr(Db::TField* Field, const TFieldID &FieldID, const TAttrID 
	&AttrID);
extern PACKAGE void __fastcall UpdateField(Db::TField* Field, const TFieldID &FieldID, const TAttrID 
	&AttrID);
extern PACKAGE Db::TField* __fastcall CreateField(Classes::TComponent* Owner, Db::TDataSet* Dataset, 
	const AnsiString FullName, const AnsiString Origin, const TFieldID &FieldID, const TAttrID &AttrID)
	;
extern PACKAGE AnsiString __fastcall GetControlClass(const TAttrID &AttrID);
extern PACKAGE bool __fastcall HasConstraints(Dbtables::TDBDataSet* Dataset);
extern PACKAGE void __fastcall UpdateConstraints(Dbtables::TDBDataSet* Dataset, Db::TCheckConstraints* 
	Constraints);
extern PACKAGE void __fastcall UpdateDataset(Dbtables::TDBDataSet* Dataset);

}	/* namespace Drintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Drintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DRIntf
