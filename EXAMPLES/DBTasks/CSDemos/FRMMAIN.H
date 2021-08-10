//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef frmmainHPP
#define frmmainHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Controls.hpp>
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
//---------------------------------------------------------------------------
class TFrmLauncher : public TForm
{
__published:
    TButton *BtnViews;
    TButton *BtnTrigg;
    TButton *BtnQrySP;
    TButton *BtnExecSP;
    TButton *BtnTrans;
    TButton *BtnClose;
    void __fastcall BtnCloseClick(TObject *Sender);
    void __fastcall BtnTriggClick(TObject *Sender);
    void __fastcall BtnQrySPClick(TObject *Sender);
    void __fastcall BtnExecSPClick(TObject *Sender);
    void __fastcall BtnTransClick(TObject *Sender);
    void __fastcall BtnViewsClick(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TFrmLauncher(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFrmLauncher *FrmLauncher;
//---------------------------------------------------------------------------
#endif
