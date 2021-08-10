#include <vcl.h>
#pragma hdrstop

#include "ServData.h"
#include "ServMain.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"

/////////////////////////////////////////////////////////////////////////////
// Global instance of TEmpServer_BCBImpl 
/////////////////////////////////////////////////////////////////////////////
TEmpServer_BCB *EmpServer_BCB;


/////////////////////////////////////////////////////////////////////////////
// TEmpServer_BCB::TEmpServer_BCB
/////////////////////////////////////////////////////////////////////////////
__fastcall TEmpServer_BCB::TEmpServer_BCB(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}
//---------------------------------------------------------------------------
// The rest of this code just demonstrates how you might monitor client
// activity from the server.  None of this is required to develop an
// application server.
//

void __fastcall TEmpServer_BCB::CRemoteDataModuleCreate(TObject *Sender)
{
  // Update the client counter
  MainForm->UpdateClientCount(1);
}
//---------------------------------------------------------------------------

void __fastcall TEmpServer_BCB::CRemoteDataModuleDestroy(TObject *Sender)
{
  // Update the client counter
  MainForm->UpdateClientCount(-1);
}
//---------------------------------------------------------------------------

void __fastcall TEmpServer_BCB::EmpQueryAfterOpen(TDataSet *DataSet)
{
  // Update the query counter
  MainForm->IncQueryCount();
}
//---------------------------------------------------------------------------

