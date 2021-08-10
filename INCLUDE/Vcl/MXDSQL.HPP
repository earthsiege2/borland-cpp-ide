// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxdsql.pas' rev: 5.00

#ifndef mxdsqlHPP
#define mxdsqlHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StdCtrls.hpp>	// Pascal unit
#include <DBGrids.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
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

namespace Mxdsql
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TSQLWindow;
class PASCALIMPLEMENTATION TSQLWindow : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Dbgrids::TDBGrid* DBGrid1;
	Dbtables::TQuery* Query1;
	Db::TDataSource* DataSource1;
	Stdctrls::TMemo* Memo1;
	
public:
	bool __fastcall SInitialize(AnsiString DataBaseName, AnsiString SQL);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TSQLWindow(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TSQLWindow(Classes::TComponent* AOwner, int Dummy
		) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TSQLWindow(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TSQLWindow(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TSQLWindow* Form2;
extern PACKAGE void __fastcall ShowSQLWindow(AnsiString DataBaseName, AnsiString SQL);

}	/* namespace Mxdsql */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxdsql;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxdsql
