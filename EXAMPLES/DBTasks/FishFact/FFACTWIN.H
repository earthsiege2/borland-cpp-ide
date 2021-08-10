//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// Ffactwin.hpp - dcc32 generated hdr (DO NOT EDIT) rev: -4
// From: Ffactwin.pas
//----------------------------------------------------------------------------
#ifndef FfactwinHPP
#define FfactwinHPP
//----------------------------------------------------------------------------
#ifndef ExtCtrlsHPP
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <DBCtrls.hpp>
#include <StdCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Dialogs.hpp>
#include <Db.hpp>
#endif

#ifndef GridsHPP
#include <Grids.hpp>
#endif

#ifndef ButtonsHPP
#include <Buttons.hpp>
#endif

#ifndef DBTablesHPP
#include <DBTables.hpp>
#endif

#ifndef DBHPP
#include <DB.hpp>
#endif

#ifndef DBGridsHPP
#include <DBGrids.hpp>
#endif

#ifndef DBCtrlsHPP
#include <DBCtrls.hpp>
#endif

#ifndef StdCtrlsHPP
#include <StdCtrls.hpp>
#endif

#ifndef FormsHPP
#include <Forms.hpp>
#endif

#ifndef ControlsHPP
#include <Controls.hpp>
#endif

#ifndef GraphicsHPP
#include <Graphics.hpp>
#endif

#ifndef ClassesHPP
#include <Classes.hpp>
#endif

#ifndef MessagesHPP
#include <Messages.hpp>
#endif

#ifndef WindowsHPP
#include <Windows.hpp>
#endif

#ifndef SysUtilsHPP
#include <SysUtils.hpp>
#endif

#ifndef SystemHPP
#include <System.hpp>
#endif

//-- type declarations -------------------------------------------------------
class __declspec(delphiclass) TFormFacts;
class TFormFacts : public TForm
{
	typedef TFormFacts ThisClass;
	typedef TForm inherited;
	
__published:
	TPanel *Panel1;
	TLabel *Label1;
	TDBImage *DBImage1;
	TDBText *DBLabel1;
	TDBMemo *DBMemo1;
	TDataSource *DataSource1;
	TTable *Table1;
	TStringField *Table1Common_Name;
	TBlobField *Table1Graphic;
	TDBGrid *DBGrid1;
    TBitBtn *ExitButton;
	TStringField *Table1Category;
	TStringField *Table1SpeciesName;
	TFloatField *Table1Lengthcm;
	TFloatField *Table1Length_In;
	TMemoField *Table1Notes;

    TSaveDialog *SaveDialog1;
    TBitBtn *SaveButton;
    void __fastcall SaveClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
public:
	__fastcall virtual TFormFacts(TComponent*);
};

//-- var, const, procedure ---------------------------------------------------
extern TFormFacts *FormFacts;
//-- end unit ----------------------------------------------------------------
#endif	// Ffactwin
