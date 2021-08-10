//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <shellapi.h>
#pragma hdrstop

#include "traymain.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::DrawItem(TMessage& Msg)
{
     IconDrawItem((LPDRAWITEMSTRUCT)Msg.LParam);
     TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::MyNotify(TMessage& Msg)
{
    POINT MousePos;

    switch(Msg.LParam)
    {
        case WM_RBUTTONUP:
            if (GetCursorPos(&MousePos))
            {
                PopupMenu1->PopupComponent = FormMain;
                SetForegroundWindow(Handle);
                PopupMenu1->Popup(MousePos.x, MousePos.y);
            }
            else
                Show();
            break;
        case WM_LBUTTONUP:
            ToggleState();
            break;
        default:
            break;
    }
    TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
	TrayMessage(NIM_DELETE);
}
//---------------------------------------------------------------------------
bool __fastcall TFormMain::TrayMessage(DWORD dwMessage)
{
   NOTIFYICONDATA tnd;
   PSTR pszTip;

   pszTip = TipText();

   tnd.cbSize          = sizeof(NOTIFYICONDATA);
   tnd.hWnd            = Handle;
   tnd.uID             = IDC_MYICON;
   tnd.uFlags          = NIF_MESSAGE | NIF_ICON | NIF_TIP;
   tnd.uCallbackMessage	= MYWM_NOTIFY;

   if (dwMessage == NIM_MODIFY)
    {
        tnd.hIcon		= (HICON)IconHandle();
        if (pszTip)
           lstrcpyn(tnd.szTip, pszTip, sizeof(tnd.szTip));
	    else
        tnd.szTip[0] = '\0';
    }
   else
    {
        tnd.hIcon = NULL;
        tnd.szTip[0] = '\0';
    }

   return (Shell_NotifyIcon(dwMessage, &tnd));
}
//---------------------------------------------------------------------------
HICON __fastcall TFormMain::IconHandle(void)
{
    if (RadioButton1->Checked)
        return (Image1->Picture->Icon->Handle);
    else
        return (Image2->Picture->Icon->Handle);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToggleState(void)
{
    if (RadioButton1->Checked)
    {
        RadioButton1->Checked = false;
        RadioButton2->Checked = true;
    }
    else
    {
        RadioButton2->Checked = false;
        RadioButton1->Checked = true;
    }
    TrayMessage(NIM_MODIFY);
}
//---------------------------------------------------------------------------
PSTR __fastcall TFormMain::TipText(void)
{
    if (RadioButton1->Checked)
        return (Edit1->Text.c_str());
    else
        return (Edit2->Text.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
    {
    	TrayMessage(NIM_ADD);
        TrayMessage(NIM_MODIFY);
    }
	else
    	TrayMessage(NIM_DELETE);

    Button1->Enabled = CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Button1Click(TObject *Sender)
{
    Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::RadioButtonClick(TObject *Sender)
{
    if (!CheckBox1->Checked)
        return;

    TrayMessage(NIM_MODIFY);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::EditKeyUp(TObject *Sender, WORD &Key,
    TShiftState Shift)
{
    if (!CheckBox1->Checked)
        return;

    TrayMessage(NIM_MODIFY);
}
//---------------------------------------------------------------------------
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi)
{
	HICON hIcon;

	hIcon = (HICON)LoadImage(g_hinst, MAKEINTRESOURCE(lpdi->CtlID), IMAGE_ICON,
		16, 16, 0);
	if (!hIcon)
		return(FALSE);

	DrawIconEx(lpdi->hDC, lpdi->rcItem.left, lpdi->rcItem.top, hIcon,
		16, 16, 0, NULL, DI_NORMAL);

	return(TRUE);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Properties1Click(TObject *Sender)
{
    Show();    
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ToggleState1Click(TObject *Sender)
{
    ToggleState();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::Shutdown1Click(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------
