//---------------------------------------------------------------------
#include <clx.h>
#pragma hdrstop

#include "ClxEmployee.h"
//--------------------------------------------------------------------- 
#pragma resource "*.xfm"
TEmployeeDM *EmployeeDM;
//---------------------------------------------------------------------
__fastcall TEmployeeDM::TEmployeeDM(TComponent* AOwner)
	: TDataModule(AOwner)
{
}
//--------------------------------------------------------------------- 