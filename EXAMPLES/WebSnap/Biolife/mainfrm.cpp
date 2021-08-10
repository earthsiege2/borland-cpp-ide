//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include "MainFrm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)               
{
}

void initFunc()
{
  GUID appGuid;
  ::CLSIDFromString(WideString("{48C77D46-2DAD-4842-849D-9B7A081D756F}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "Biolife", "C++Builder WebBroker Application - 'Biolife'");
}
#pragma startup initFunc 31


