#include <vcl.h>
#pragma hdrstop

#include "MDAPPSERVERIMPL.H"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"

//---------------------------------------------------------------------------
// Global instance of TMDAppServerImpl
//---------------------------------------------------------------------------
TMDAppServer *MDAppServer;
//---------------------------------------------------------------------------
// TMDAppServer::TMDAppServer
//---------------------------------------------------------------------------
__fastcall TMDAppServer::TMDAppServer(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}
//---------------------------------------------------------------------------



