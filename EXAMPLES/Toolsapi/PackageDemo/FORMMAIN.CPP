//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <toolsapi.hpp>

#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TPackageForm::TPackageForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int GetPackageIndex(const AnsiString Name, TStrings* TS)
{
  int i;

  for (i = 0; i < TS->Count; i++)
    if (TS->Strings[i] == Name)
      return i;

  return -1;
};
//---------------------------------------------------------------------------
void __fastcall TPackageForm::ListBox1Click(TObject *Sender)
{
  TStringList *TS = new TStringList();
  _di_IOTAPackageServices Temp;
  HRESULT hr;
  int CompCount;
  int PackageIndex;
  int i;

  if (BorlandIDEServices != NULL)
  {
    __try
    {
      hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAPackageServices), (void **)&Temp);
      if (SUCCEEDED(hr))
      {
        for (i = 0; i < Temp->PackageCount; i++)
          TS->Add(Temp->PackageNames[i]);

        ListBox2->Clear();

        PackageIndex = GetPackageIndex(ListBox1->Items->Strings[ListBox1->ItemIndex], TS);
        CompCount = Temp->GetComponentCount(PackageIndex);

        if (CompCount > 0)
        {
          for (i = 0; i < CompCount; i++)
            ListBox2->Items->Add(Temp->GetComponentName(PackageIndex, i));
        }
        else
          ListBox2->Items->Add("<No Components>");
      }
    }
    __finally
    {
    delete TS;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TPackageForm::CheckBox1Click(TObject *Sender)
{
  int i;
  _di_IOTAPackageServices Temp;
  HRESULT hr;

  if (BorlandIDEServices != NULL)
  {
    ListBox1->Clear();

    hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAPackageServices), (void **)&Temp);
    if (SUCCEEDED(hr))
    {
      if (CheckBox1->Checked)
      {
        for (i = 0; i < Temp->PackageCount; i++)
          if (Temp->ComponentCount[i] > 0)
            ListBox1->Items->Add(Temp->PackageNames[i]);
      }
      else
      {
        for (i = 0; i < Temp->PackageCount; i++)
          ListBox1->Items->Add(Temp->PackageNames[i]);
      }
    }
  }
}
//---------------------------------------------------------------------------
