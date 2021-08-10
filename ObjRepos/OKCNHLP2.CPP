//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "OKCNHLP2.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOKHelpRightDlg *OKHelpRightDlg;
//--------------------------------------------------------------------- 
__fastcall TOKHelpRightDlg::TOKHelpRightDlg(TComponent* AOwner)
	: TOKRightDlg(AOwner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TOKHelpRightDlg::HelpBtnClick(TObject *Sender)
{
	Application->HelpContext(HelpContext);
}
//--------------------------------------------------------------------- 
