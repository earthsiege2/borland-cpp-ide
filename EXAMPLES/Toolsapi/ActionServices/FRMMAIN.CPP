//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "frmmain.h"
#include "toolsapi.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

/* file-scoped constants */
const AnsiString sNewGroup = "Create a new group?";

//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::UpdateFileNames(void)
{
  int Count;
  int i;
  _di_IOTAModuleServices Temp;
  HRESULT hr;

  ListBox1->Items->Clear();
  hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAModuleServices), (void **) &Temp);
  if (FAILED(hr))
    return;
  Count = Temp->ModuleCount;
  for (i = 0; i < Count; i++)
    ListBox1->Items->Add(Temp->Modules[i]->FileName);

  ListBox1->ItemIndex = 0;
};
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButton1Click(TObject *Sender)
{
  TOpenDialog *Dialog = new TOpenDialog(NULL);
  _di_IOTAActionServices Temp;
  HRESULT hr;

  Dialog->Filter = "C++Builder files|*.bpk;*.bpr;*.cpp;*.h;*.hpp;*.c|All Files(*.*)|*.*";
  if (Dialog->Execute())
  {
    hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices), (void **) &Temp);
    if (SUCCEEDED(hr))
    {
      Temp->OpenFile(Dialog->FileName);
      UpdateFileNames();
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButton2Click(TObject *Sender)
{
  _di_IOTAActionServices Temp;
  HRESULT hr;

  hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices), (void **) &Temp);
  if (SUCCEEDED(hr))
  {
    Temp->CloseFile(ListBox1->Items->Strings[ListBox1->ItemIndex]);
    UpdateFileNames();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButton3Click(TObject *Sender)
{
  _di_IOTAActionServices Temp;
  HRESULT hr;

  hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices), (void **) &Temp);
  if (SUCCEEDED(hr))
  {
    Temp->SaveFile(ListBox1->Items->Strings[ListBox1->ItemIndex]);
    UpdateFileNames();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButton4Click(TObject *Sender)
{
  _di_IOTAActionServices Temp;
  HRESULT hr;

  hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices), (void **) &Temp);
  if (SUCCEEDED(hr))
  {
    Temp->ReloadFile(ListBox1->Items->Strings[ListBox1->ItemIndex]);
    UpdateFileNames();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToolButton5Click(TObject *Sender)
{
  bool NewGroup = false;
  TOpenDialog *Dialog = new TOpenDialog(NULL);
  _di_IOTAActionServices Temp;
  TMsgDlgButtons Buttons;
  HRESULT hr;

  Dialog->Filter = "C++Builder files|*.bpk;*.bpr;*.cpp;*.h;*.hpp;*.c|All Files(*.*)|*.*";
  if (Dialog->Execute())
  {
    Buttons << mbYes << mbNo;
    if (MessageDlg(sNewGroup, mtInformation, Buttons, 0) == mrYes)
      NewGroup = true;
    hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices), (void **) &Temp);
    if (SUCCEEDED(hr))
    {
      Temp->OpenProject(Dialog->FileName, NewGroup);
      UpdateFileNames();
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ListBox1DblClick(TObject *Sender)
{
  _di_IOTAActionServices Temp;
  HRESULT hr;

  hr = BorlandIDEServices->QueryInterface(__uuidof(IOTAActionServices), (void **) &Temp);
  if (SUCCEEDED(hr))
  {
    Temp->OpenFile(ListBox1->Items->Strings[ListBox1->ItemIndex]);
    UpdateFileNames();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormShow(TObject *Sender)
{
  UpdateFileNames();        
}
//---------------------------------------------------------------------------
