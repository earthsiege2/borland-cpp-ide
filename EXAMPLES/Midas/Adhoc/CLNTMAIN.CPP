//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "clntmain.h"

#include "adhcsrvr_TLB.h"
#include "comobj.hpp"
#include "axctrls.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::BtnFetchDataClick(TObject *Sender)
{
  IAdHcDMDisp AdhcServ;
  _di_IStrings Temp;
  IStringsPtr *Value = new IStringsPtr();
  int i;

  __try
  {
    if (!DCOMConnection1->Connected)
      DCOMConnection1->Connected = true;
    AdhcServ.Bind(DCOMConnection1->GetServer());
    __try
    {
      cmbAlias->Items->Clear();
      GetOleStrings(cmbAlias->Items, Temp);
      *Value = Temp;
      AdhcServ->GetDBNames(Value);
      if (cmbAlias->Items->Count > -1)
        cmbAlias->ItemIndex = 0;
    }
    __finally
    {
      if (Value)
        delete Value;
    }
  }
  __finally
  {
    if (AdhcServ.IsBound())
      AdhcServ.Unbind();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::cmbAliasChange(TObject *Sender)
{
  IAdHcDMDisp AdhcServ;
  _di_IStrings Temp;
  IStringsPtr *Value = new IStringsPtr();
  int i;

  __try
  {
    if (!DCOMConnection1->Connected)
      DCOMConnection1->Connected = true;
    AdhcServ.Bind(DCOMConnection1->GetServer());
    __try
    {
      cmbTables->Items->Clear();
      GetOleStrings(cmbTables->Items, Temp);
      *Value = Temp;
      AdhcServ->GetTableNames(WideString(cmbAlias->Items->Strings[cmbAlias->ItemIndex]),
                              Value);
    }
    __finally
    {
      if (Value)
        delete Value;
    }
  }
  __finally
  {
    if (AdhcServ.IsBound())
      AdhcServ.Unbind();
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormMain::cmbTablesChange(TObject *Sender)
{
  IAdHcDMDisp AdhcServ;

  __try
  {
    if (!DCOMConnection1->Connected)
      DCOMConnection1->Connected = true;
    AdhcServ.Bind(DCOMConnection1->GetServer());
    ClientDataSet1->Close();
    AdhcServ->SetTable(WideString(cmbAlias->Items->Strings[cmbAlias->ItemIndex]),
                       WideString(cmbTables->Items->Strings[cmbTables->ItemIndex]));
    ClientDataSet1->Open();
  }
  __finally
  {
    if (AdhcServ.IsBound())
      AdhcServ.Unbind();
  }
}
//---------------------------------------------------------------------------

