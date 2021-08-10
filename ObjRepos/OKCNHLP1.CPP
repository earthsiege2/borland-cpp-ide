//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "OKCNHLP1.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOKHelpBottomDlg *OKHelpBottomDlg;
//--------------------------------------------------------------------- 
__fastcall TOKHelpBottomDlg::TOKHelpBottomDlg(TComponent* AOwner)
	: TOKBottomDlg(AOwner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TOKHelpBottomDlg::HelpBtnClick(TObject *Sender)
{
	Application->HelpContext(HelpContext);
}
//--------------------------------------------------------------------- 
