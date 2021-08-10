#include <vcl.h>
#pragma hdrstop

#include "SETPARAMSRVRIMPL.H"

#include "FormMain.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"

//---------------------------------------------------------------------------
// Global instance of TSetParamSrvrImpl
//---------------------------------------------------------------------------
TSetParamSrvr *SetParamSrvr;
//---------------------------------------------------------------------------
// TSetParamSrvr::TSetParamSrvr
//---------------------------------------------------------------------------
__fastcall TSetParamSrvr::TSetParamSrvr(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSetParamSrvr::CRemoteDataModuleCreate(TObject *Sender)
{
  // Update the client counter
  MainForm->IncClientCount();
}
//---------------------------------------------------------------------------

void __fastcall TSetParamSrvr::CRemoteDataModuleDestroy(TObject *Sender)
{
  // Update the client counter
  MainForm->DecClientCount();
}
//---------------------------------------------------------------------------

void __fastcall TSetParamSrvr::EventsAfterOpen(TDataSet *DataSet)
{
  // Update the query counter
  MainForm->IncQueryCount();        
}
//---------------------------------------------------------------------------

void __fastcall TSetParamSrvr::EventsAfterClose(TDataSet *DataSet)
{
  // Update the query counter
  MainForm->DecQueryCount();
}
//---------------------------------------------------------------------------

