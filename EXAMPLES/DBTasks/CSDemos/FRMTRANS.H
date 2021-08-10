//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FrmtransHPP
#define FrmtransHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
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

#ifndef ButtonsHPP
#include <buttons.hpp>
#endif

#ifndef DBCtrlsHPP
#include <dbctrls.hpp>
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
//---------------------------------------------------------------------------
class TFrmTransDemo : public TForm
{
__published:
    TPanel *Panel1;
    TSpeedButton *BtnUndoEdits;
    TSpeedButton *BtnCommitEdits;
    TDBNavigator *DBNavigator;
    TBitBtn *BitBtn1;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    void __fastcall FormHide(TObject *Sender);
    void __fastcall BtnCommitEditsClick(TObject *Sender);
    void __fastcall BtnUndoEditsClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFrmTransDemo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrmTransDemo *FrmTransDemo;
//---------------------------------------------------------------------------
#endif
