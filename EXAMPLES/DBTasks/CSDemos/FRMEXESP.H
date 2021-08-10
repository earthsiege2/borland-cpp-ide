//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FrmexespHPP
#define FrmexespHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
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

#ifndef ButtonsHPP
#include <buttons.hpp>
#endif

#ifndef DBCtrlsHPP
#include <dbctrls.hpp>
#endif

#ifndef StdCtrlsHPP
#include <stdctrls.hpp>
#endif

#ifndef MaskHPP
#include <mask.hpp>
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
//---------------------------------------------------------------------------
class TFrmExecProc : public TForm
{
__published:
    TPanel *Panel1;
    TSpeedButton *BtnShipOrder;
    TDBNavigator *DBNavigator;
    TBitBtn *BitBtn1;
    TPanel *Panel3;
    TScrollBox *ScrollBox;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label6;
    TLabel *Label4;
    TDBEdit *EditCUST_NO;
    TDBEdit *EditCUSTOMER;
    TDBEdit *EditCONTACT_FIRST;
    TDBEdit *EditCONTACT_LAST;
    TDBEdit *EditPHONE_NO;
    TDBEdit *EditADDRESS_LINE;
    TDBEdit *EditADDRESS_LINE2;
    TDBEdit *EditCITY;
    TDBEdit *EditSTATE_PROVINCE;
    TDBEdit *EditCOUNTRY;
    TDBEdit *EditPOSTAL_CODE;
    TDBCheckBox *DBCheckBox1;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    TDataSource *SalesSource;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall SalesSourceDataChange(TObject *Sender, TField *Field);
    void __fastcall BtnShipOrderClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFrmExecProc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrmExecProc *FrmExecProc;
//---------------------------------------------------------------------------
#endif
