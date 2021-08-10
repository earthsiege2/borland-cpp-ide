//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 2000-2002 Borland Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAppEventForm *AppEventForm;
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsActionExecute(
      TBasicAction *Action, bool &Handled)
{
    lbOther->Items->Add("Event OnActionExecute");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsActionUpdate(
      TBasicAction *Action, bool &Handled)
{
     lbActionUpdate->Items->Add("Event OnActionUpdate");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsActivate(TObject *Sender)
{
     lbOther->Items->Add("Event OnActivate");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsDeactivate(TObject *Sender)
{
    lbOther->Items->Add("Event OnDeactivate");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsException(TObject *Sender,
      Exception *E)
{
    lbOther->Items->Add("Event OnException: " + E->Message);
}
//---------------------------------------------------------------------------

bool __fastcall TAppEventForm::ApplicationEventsHelp(WORD Command, int Data,
      bool &CallHelp)
{
    lbOther->Items->Add("Event OnHelp");
    return false;
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsHint(TObject *Sender)
{
    lbOther->Items->Add("Event OnHint");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsIdle(TObject *Sender,
      bool &Done)
{
    lbIdle->Items->Add("Event OnIdle");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsMessage(tagMSG &Msg,
      bool &Handled)
{
    lbOnMessage->Items->Add("X:=" + IntToStr(Msg.pt.x) + "|Y:=" + IntToStr(Msg.pt.y));
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsMinimize(TObject *Sender)
{
  lbOther->Items->Add("Event OnMinimize");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsShortCut(TWMKey &Msg,
      bool &Handled)
{
  lbOther->Items->Add("Event OnShortCut");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsRestore(TObject *Sender)
{

  lbOther->Items->Add("Event OnRestore");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ApplicationEventsShowHint(AnsiString &HintStr,
      bool &CanShow, THintInfo &HintInfo)
{
    lbOther->Items->Add("Event OnShowHint");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::MenuActionClick(TObject *Sender)
{
    ShowMessage("Action executed");
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::MenuExceptionClick(TObject *Sender)
{
    char *sExceptionRaised = "This is an exception";
    throw Exception(sExceptionRaised);
}
//---------------------------------------------------------------------------

void __fastcall TAppEventForm::ActionExecute(TObject *Sender)
{
    ShowMessage("Action executed");
}
//---------------------------------------------------------------------------
__fastcall TAppEventForm::TAppEventForm( TComponent *Owner) : TForm(Owner)
{

}


