//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ShapeMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShapeForm *ShapeForm;
//---------------------------------------------------------------------------
__fastcall TShapeForm::TShapeForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TShapeForm::OpenButtonClick(TObject *Sender)
{
  const String ConnStr = "Provider=%s;Data Provider=%s;Data Source=%s";
  if (!ADOConnection1->Connected)
    {
      ADOConnection1->ConnectionString = Format (ConnStr, ARRAYOFCONST(((String)Provider->Text,
        (String)DataProvider->Text, (String)DataSource->Text)));
      Customers->Open();
      Orders->Open();
    }

}
//---------------------------------------------------------------------------
