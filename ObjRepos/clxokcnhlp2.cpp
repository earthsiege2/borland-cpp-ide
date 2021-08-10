//---------------------------------------------------------------------
#include <clx.h>
#pragma hdrstop

#include "ClxOKCNHLP2.h"
//---------------------------------------------------------------------
#pragma resource "*.xfm"
TOKHelpRightDlg *OKHelpRightDlg;
//--------------------------------------------------------------------- 
__fastcall TOKHelpRightDlg::TOKHelpRightDlg(TComponent* AOwner)
	: TOKRightDlg(AOwner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TOKHelpRightDlg::HelpBtnClick(TObject *Sender)
{
	Application->HelpContext = HelpContext;
}
//--------------------------------------------------------------------- 
