//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FrmqryspHPP
#define FrmqryspHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
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

#ifndef ExtCtrlsHPP
#include <extctrls.hpp>
#endif

#ifndef DBCtrlsHPP
#include <dbctrls.hpp>
#endif

#ifndef ButtonsHPP
#include <buttons.hpp>
#endif

#ifndef StdCtrlsHPP
#include <stdctrls.hpp>
#endif

#ifndef DBGridsHPP
#include <dbgrids.hpp>
#endif

#ifndef GridsHPP
#include <grids.hpp>
#endif

#ifndef DBHPP
#include <db.hpp>
#endif

#ifndef DBTablesHPP
#include <dbtables.hpp>
#endif

#ifndef ComCtrlsHPP
#include <comctrls.hpp>
#endif
//---------------------------------------------------------------------------
class TFrmQueryProc : public TForm
{
__published:
    TPanel *Panel1;
    TDBNavigator *DBNavigator;
    TBitBtn *BitBtn1;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    TPanel *Panel3;
    TDBGrid *DBGrid2;
    TDataSource *EmployeeSource;
    TQuery *EmployeeProjectsQuery;
    TDataSource *EmployeeProjectsSource;
    TStatusBar *StatusBar1;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall EmployeeSourceDataChange(TObject *Sender,
      TField *Field);
    void __fastcall FormShow(TObject *Sender);
private:        // private user declarations
    void WriteMsg(char *szWrite);
public:         // public user declarations
    virtual __fastcall TFrmQueryProc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrmQueryProc *FrmQueryProc;
//---------------------------------------------------------------------------
#endif
