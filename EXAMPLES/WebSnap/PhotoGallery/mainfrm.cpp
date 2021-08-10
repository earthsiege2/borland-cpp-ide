//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include "MainFrm.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void initFunc()
{
  GUID appGuid;
  ::CLSIDFromString(WideString("{8ABD623E-DB5C-421A-AEF8-3D2C54AE8572}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "Photos", "C++Builder WebBroker Application - 'Photos'");
}
#pragma startup initFunc 31

