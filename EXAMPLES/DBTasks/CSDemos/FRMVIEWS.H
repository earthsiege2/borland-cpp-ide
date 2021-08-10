//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FrmviewsHPP
#define FrmviewsHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>
#pragma hdrstop
//---------------------------------------------------------------------------
#ifndef WindowsHPP
#include <windows.hpp>
#endif

#ifndef MessagesHPP
#include <messages.hpp>
#endif

#ifndef SysUtilsHPP
#include <sysutils.hpp>
#endif

#ifndef ClassesHPP
#include <classes.hpp>
#endif

#ifndef GraphicsHPP
#include <graphics.hpp>
#endif

#ifndef ControlsHPP
#include <controls.hpp>
#endif

#ifndef FormsHPP
#include <forms.hpp>
#endif

#ifndef DialogsHPP
#include <dialogs.hpp>
#endif

#ifndef StdCtrlsHPP
#include <stdctrls.hpp>
#endif

#ifndef ExtCtrlsHPP
#include <extctrls.hpp>
#endif

#ifndef DBCtrlsHPP
#include <dbctrls.hpp>
#endif

#ifndef ButtonsHPP
#include <buttons.hpp>
#endif

#ifndef DBGridsHPP
#include <dbgrids.hpp>
#endif

#ifndef GridsHPP
#include <grids.hpp>
#endif

#ifndef DBTablesHPP
#include <dbtables.hpp>
#endif

#ifndef DBHPP
#include <db.hpp>
#endif
//---------------------------------------------------------------------------
class TFrmViewDemo : public TForm
{
__published:
    TPanel *Panel1;
    TDBNavigator *DBNavigator;
    TSpeedButton *BtnShowEmployee;
    TSpeedButton *BtnShowPhoneList;
    TBitBtn *BitBtn1;
    TDataSource *VaryingTableSource;
    TTable *VaryingTable;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    void __fastcall BtnShowEmployeeClick(TObject *Sender);
    void __fastcall BtnShowPhoneListClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:        // private user declarations
    void ShowTable(char *);
public:         // public user declarations
    virtual __fastcall TFrmViewDemo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrmViewDemo *FrmViewDemo;
//---------------------------------------------------------------------------
#endif
