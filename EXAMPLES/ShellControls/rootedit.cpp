//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RootEdit.h"
#include "ShellCtrls.h"
#include "FileCtrl.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
const String SPickRootPath = "Please select a root path";
const String SEditRoot = "E&dit Root";

enum NTFolders { rfCommonDesktopDirectory, rfCommonPrograms, rfCommonStartMenu, rfCommonStartup };

bool PathIsCSIDL(String Value)
{
    return Shellctrls::GetEnumValue(Value) >= 0;
}

String RootPathEditor(String Value)
{
    String Result = Value;
    TRootPathEditDlg *RootPathEditDlg = new TRootPathEditDlg(Application);

    RootPathEditDlg->rbUseFolder->Checked = PathIsCSIDL(Result);
    RootPathEditDlg->rbUsePath->Checked = !RootPathEditDlg->rbUseFolder->Checked;

    if(!PathIsCSIDL(Result))
    {
        RootPathEditDlg->cbFolderType->ItemIndex = 0;
        RootPathEditDlg->ePath->Text = Result;
    }
    else
        RootPathEditDlg->cbFolderType->ItemIndex = RootPathEditDlg->cbFolderType->Items->IndexOf(Result);

    RootPathEditDlg->UpdateState();
    RootPathEditDlg->ShowModal();

    if(RootPathEditDlg->ModalResult == mrOk)
        if(RootPathEditDlg->rbUsePath->Checked)
            Result = RootPathEditDlg->ePath->Text;
        else
            Result = RootPathEditDlg->cbFolderType->Items->Strings[RootPathEditDlg->cbFolderType->ItemIndex];

    return Result;
}
//---------------------------------------------------------------------------
TRootPathEditDlg *RootPathEditDlg;
//---------------------------------------------------------------------------
__fastcall TRootPathEditDlg::TRootPathEditDlg(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRootPathEditDlg::FormCreate(TObject *Sender)
{
    for(int RFIndex = 0; RFIndex <= rfTemplates; RFIndex++)
        cbFolderType->Items->Add(Shellctrls::GetEnumName((TRootFolder)RFIndex));
}
//---------------------------------------------------------------------------
void __fastcall TRootPathEditDlg::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TRootPathEditDlg::Button2Click(TObject *Sender)
{
    ModalResult = mrCancel;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TRootPathEditDlg::rbUseFolderClick(TObject *Sender)
{
    rbUsePath->Checked = !rbUseFolder->Checked;
    UpdateState();
}
//---------------------------------------------------------------------------

void __fastcall TRootPathEditDlg::rbUsePathClick(TObject *Sender)
{
    rbUseFolder->Checked = !rbUsePath->Checked;
    UpdateState();
}
//---------------------------------------------------------------------------

void __fastcall TRootPathEditDlg::Button1Click(TObject *Sender)
{
    ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TRootPathEditDlg::btnBrowseClick(TObject *Sender)
{
    String Dir = ePath->Text;

    if( SelectDirectory( SPickRootPath, "", Dir))
        ePath->Text = Dir;
}
//---------------------------------------------------------------------------

void __fastcall TRootPathEditDlg::UpdateState(void)
{
  cbFolderType->Enabled = rbUseFolder->Checked;
  ePath->Enabled = !rbUseFolder->Checked;
  btnBrowse->Enabled = ePath->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TRootProperty::Edit(void)
{
    SetStrValue(RootPathEditor(GetStrValue()));
}
//---------------------------------------------------------------------------

TPropertyAttributes __fastcall TRootProperty::GetAttributes(void)
{
    return TPropertyAttributes() << paDialog;
}
//---------------------------------------------------------------------------

void __fastcall TRootEditor::ExecuteVerb(int Index)
{
    if(Index == 0)
    {
        const String SRoot = "root";
        String Path = RootPathEditor(GetPropValue(Component, SRoot, True));
        SetPropValue(Component, SRoot, Path);
        Designer->Modified();
    }
}

//---------------------------------------------------------------------------

String __fastcall TRootEditor::GetVerb(int Index)
{
    if(Index == 0)
        return SEditRoot;

    return "";
}
//---------------------------------------------------------------------------

int __fastcall TRootEditor::GetVerbCount(void)
{
    return 1;
}
//---------------------------------------------------------------------------
