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
  ::CLSIDFromString(WideString("{ADB5F52F-1D2F-4670-985F-6142E313F0E8}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "StreamImageTest", "C++Builder WebBroker Application - 'StreamImageTest'");
}
#pragma startup initFunc 31

 