//---------------------------------------------------------------------
#include <clx.h>
#pragma hdrstop

#include "ClxChildWin.h"
//--------------------------------------------------------------------- 
#pragma resource "*.xfm"
//--------------------------------------------------------------------- 
__fastcall TMDIChild::TMDIChild(TComponent *Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------- 
void __fastcall TMDIChild::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//--------------------------------------------------------------------- 
