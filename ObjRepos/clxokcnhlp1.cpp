//---------------------------------------------------------------------
#include <clx.h>
#pragma hdrstop

#include "ClxOKCNHLP1.h"
//---------------------------------------------------------------------
#pragma resource "*.xfm"
TOKHelpBottomDlg *OKHelpBottomDlg;
//--------------------------------------------------------------------- 
__fastcall TOKHelpBottomDlg::TOKHelpBottomDlg(TComponent* AOwner)
	: TOKBottomDlg(AOwner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TOKHelpBottomDlg::HelpBtnClick(TObject *Sender)
{
	Application->HelpContext = HelpContext;
}
//--------------------------------------------------------------------- 
