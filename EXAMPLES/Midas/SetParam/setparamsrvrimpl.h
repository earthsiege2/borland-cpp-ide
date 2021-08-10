// SETPARAMSRVRIMPL.H : Declaration of the SetParamSrvr

#ifndef __SETPARAMSRVRIMPL_H_
#define __SETPARAMSRVRIMPL_H_

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "SPrmSrvr_TLB.H"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>

// Forward ref. of IAppServer implementor
//---------------------------------------------------------------------------
class TSetParamSrvr : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TQuery *Events;
        TDataSetProvider *EventsProvider;
        void __fastcall CRemoteDataModuleCreate(TObject *Sender);
        void __fastcall CRemoteDataModuleDestroy(TObject *Sender);
        void __fastcall EventsAfterOpen(TDataSet *DataSet);
        void __fastcall EventsAfterClose(TDataSet *DataSet);
private:      // User declarations
public:       // User declarations
  __fastcall TSetParamSrvr(TComponent* Owner);

__published:
};
//---------------------------------------------------------------------------
extern PACKAGE TSetParamSrvr *SetParamSrvr;
//---------------------------------------------------------------------------
// TSetParamSrvrImpl     Implements ISetParamSrvr, default interface of SetParamSrvr
// ThreadingModel : Neutral
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : SPrmSrvr.SetParamSrvr
// Description    :
//---------------------------------------------------------------------------
class ATL_NO_VTABLE TSetParamSrvrImpl: REMOTEDATAMODULE_IMPL(TSetParamSrvrImpl, SetParamSrvr, TSetParamSrvr, ISetParamSrvr)
{
public:

BEGIN_COM_MAP(TSetParamSrvrImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ISetParamSrvr)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_PROGID("SPrmSrvr.SetParamSrvr");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TRemoteDataModuleRegistrar regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    // Disable these flags in order to disable use by socket or web connections.
    // Also set other flags to configure the behavior of your application server.
    // For more information, see atlmod.h and atlvcl.cpp.
    regObj.Singleton = false;
    regObj.EnableWeb = true;
    regObj.EnableSocket = true;
    return regObj.UpdateRegistry(bRegister);
  }


// ISetParamSrvr
protected:
};

#endif  // __SETPARAMSRVRIMPL_H_ 

