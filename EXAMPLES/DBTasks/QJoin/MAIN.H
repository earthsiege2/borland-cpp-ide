//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
    TDBGrid *DBGrid1;
    TQuery *Query1;
    TDataSource *DataSource1;
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
