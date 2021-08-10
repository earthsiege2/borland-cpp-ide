//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef GridFormH
#define GridFormH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "GdsData.h"
#include <Db.hpp>
#include <Graphics.hpp>
#include "gdsdata.h"
//---------------------------------------------------------------------------
class TGridViewForm : public TStdDataForm
{
__published:
    TDBGrid *DBGrid1;
    void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TGridViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TGridViewForm *GridViewForm;
//---------------------------------------------------------------------------
#endif
