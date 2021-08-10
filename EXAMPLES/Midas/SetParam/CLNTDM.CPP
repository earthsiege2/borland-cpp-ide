//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClntDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
__fastcall TDataModule1::TDataModule1(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDataModule1::FetchData(System::TDateTime StartDate, System::TDateTime EndDate)
{
/*
  The query on the server looks like this:

     select * from events where
       Event_Date >= :Start_Date and
       Event_Date <= :End_Date;

  The cdsEvents ClientDataSet has the parameters from the server set up in the
  Params property.  At design time, you can right click on a ClientDataSet and
  select "Fetch Params" to initialize the params from a TQuery or TStoredProc
  on the server.  At run-time you can call TClientDataSet.FetchParams to
  initialize the params from the server.  Or you can set the params up manually
  by adding them yourself.

*/

  cdsEvents->Close();
  cdsEvents->Params->ParamByName("Start_Date")->AsDate = StartDate;
  cdsEvents->Params->ParamByName("End_Date")->AsDate = EndDate;
  cdsEvents->Open();
};
//---------------------------------------------------------------------------

