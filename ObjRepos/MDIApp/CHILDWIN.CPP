//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ChildWin.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
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
