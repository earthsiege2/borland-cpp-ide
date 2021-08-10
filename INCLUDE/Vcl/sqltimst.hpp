// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SqlTimSt.pas' rev: 6.00

#ifndef SqlTimStHPP
#define SqlTimStHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Sqltimst
{
//-- type declarations -------------------------------------------------------
struct TSQLTimeStamp;
typedef TSQLTimeStamp *PSQLTimeStamp;

#pragma pack(push, 1)
struct TSQLTimeStamp
{
	short Year;
	Word Month;
	Word Day;
	Word Hour;
	Word Minute;
	Word Second;
	unsigned Fractions;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TSQLTimeStamp NullSQLTimeStamp;
extern PACKAGE Variant __fastcall VarSQLTimeStampCreate(const AnsiString AValue)/* overload */;
extern PACKAGE Variant __fastcall VarSQLTimeStampCreate(const System::TDateTime AValue)/* overload */;
extern PACKAGE void __fastcall VarSQLTimeStampCreate(Variant &aDest, const TSQLTimeStamp &ASQLTimeStamp)/* overload */;
extern PACKAGE Variant __fastcall VarSQLTimeStampCreate()/* overload */;
extern PACKAGE Variant __fastcall VarSQLTimeStampCreate(const TSQLTimeStamp &ASQLTimeStamp)/* overload */;
extern PACKAGE Word __fastcall VarSQLTimeStamp(void);
extern PACKAGE bool __fastcall VarIsSQLTimeStamp(const Variant &aValue)/* overload */;
extern PACKAGE TSQLTimeStamp __fastcall VarToSQLTimeStamp(const Variant &aValue);
extern PACKAGE AnsiString __fastcall SQLTimeStampToStr(const AnsiString Format, const TSQLTimeStamp &DateTime);
extern PACKAGE bool __fastcall TryStrToSQLTimeStamp(const AnsiString S, TSQLTimeStamp &TimeStamp);
extern PACKAGE TSQLTimeStamp __fastcall StrToSQLTimeStamp(const AnsiString S);
extern PACKAGE TSQLTimeStamp __fastcall DateTimeToSQLTimeStamp(const System::TDateTime DateTime);
extern PACKAGE System::TDateTime __fastcall SQLTimeStampToDateTime(const TSQLTimeStamp &DateTime);
extern PACKAGE int __fastcall SQLDayOfWeek(const TSQLTimeStamp &DateTime);
extern PACKAGE void __fastcall CheckSqlTimeStamp(const TSQLTimeStamp &ASQLTimeStamp);

}	/* namespace Sqltimst */
using namespace Sqltimst;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SqlTimSt
