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
  ::CLSIDFromString(WideString("{37E10676-3359-4F60-BE94-2099F7B73FFA}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "CountryReport", "C++Builder WebBroker Application - 'CountryReport'");
}
#pragma startup initFunc 31

 