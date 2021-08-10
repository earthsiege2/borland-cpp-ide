//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "frmmain.h"
#include "frmviews.h"
#include "frmtrigg.h"
#include "Frmqrysp.h"
#include "Frmexesp.h"
#include "DmCSDemo.h"
#include "Frmtrans.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFrmLauncher *FrmLauncher;
//---------------------------------------------------------------------------
__fastcall TFrmLauncher::TFrmLauncher(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmLauncher::BtnCloseClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------
void __fastcall TFrmLauncher::BtnViewsClick(TObject *Sender)
{
   FrmViewDemo->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TFrmLauncher::BtnTriggClick(TObject *Sender)
{
   FrmTriggerDemo->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TFrmLauncher::BtnQrySPClick(TObject *Sender)
{
   FrmQueryProc->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TFrmLauncher::BtnExecSPClick(TObject *Sender)
{
   FrmExecProc->ShowModal();
}
//---------------------------------------------------------------------
void __fastcall TFrmLauncher::BtnTransClick(TObject *Sender)
{
   FrmTransDemo->ShowModal();
}
//---------------------------------------------------------------------
