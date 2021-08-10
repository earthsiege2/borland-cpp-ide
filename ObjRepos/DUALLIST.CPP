//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DualList.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TDualListDlg *DualListDlg;
//--------------------------------------------------------------------- 
__fastcall TDualListDlg::TDualListDlg(TComponent* AOwner)
	: TForm(AOwner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TDualListDlg::IncludeBtnClick(TObject *Sender)
{
	int Index;

	Index = GetFirstSelection(SrcList);
	MoveSelected(SrcList, DstList->Items);
	SetItem(SrcList, Index);
}
//--------------------------------------------------------------------- 
void __fastcall TDualListDlg::ExcludeBtnClick(TObject *Sender)
{
	int Index;

	Index = GetFirstSelection(DstList);
	MoveSelected(DstList, SrcList->Items);
	SetItem(DstList, Index);
}
//---------------------------------------------------------------------
void __fastcall TDualListDlg::IncAllBtnClick(TObject *Sender)
{
	int i;

	for (i=0; i < SrcList->Items->Count; i++)
		DstList->Items->AddObject(SrcList->Items->Strings[i], SrcList->Items->Objects[i]);
	SrcList->Items->Clear();
	SetItem(SrcList, 0);
}
//---------------------------------------------------------------------
void __fastcall TDualListDlg::ExcAllBtnClick(TObject *Sender)
{
	int i;

	for (i=0; i < DstList->Items->Count; i++)
		SrcList->Items->AddObject(DstList->Items->Strings[i], DstList->Items->Objects[i]);

	DstList->Items->Clear();
	SetItem(DstList, 0);
}
//---------------------------------------------------------------------
void __fastcall TDualListDlg::MoveSelected(TCustomListBox *List, TStrings *Items)
{
	int i;

	for (i=List->Items->Count-1; i >= 0; i--)
	{
		if (List->Selected[i])
		{
			Items->AddObject(List->Items->Strings[i], List->Items->Objects[i]);
			List->Items->Delete(i);
		}
	}
}
//---------------------------------------------------------------------
void __fastcall TDualListDlg::SetButtons()
{
	bool SrcEmpty, DstEmpty;

	SrcEmpty = (SrcList->Items->Count == 0);
	DstEmpty = (DstList->Items->Count == 0);
	IncludeBtn->Enabled = (! SrcEmpty);
	IncAllBtn->Enabled = (! SrcEmpty);
	ExcludeBtn->Enabled = (! DstEmpty);
	ExAllBtn->Enabled = (! DstEmpty);
}
//---------------------------------------------------------------------
int __fastcall TDualListDlg::GetFirstSelection(TCustomListBox *List)
{
	int i;

	for (i=0; i < List->Items->Count; i++)
	{
		if (List->Selected[i])
			return i;
	}

	return LB_ERR;
}
//---------------------------------------------------------------------
void __fastcall TDualListDlg::SetItem(TListBox *List, int Index)
{
	int MaxIndex;

	List->SetFocus();
	MaxIndex = List->Items->Count - 1;

	if (Index == LB_ERR) 
		Index = 0;
	else if (Index > MaxIndex)
		Index = MaxIndex;
	List->Selected[Index] = true;

	SetButtons();
}
//---------------------------------------------------------------------
